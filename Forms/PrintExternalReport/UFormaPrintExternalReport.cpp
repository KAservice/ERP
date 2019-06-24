//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaPrintExternalReport.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaPrintExternalReport::TFormaPrintExternalReport(TComponent* Owner)
        : TForm(Owner)
{
}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintExternalReport::FormCreate(TObject *Sender)
{
List=new TList;
TableList=new TList;
}
//-----------------------------------------------------------------------
bool TFormaPrintExternalReport::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintExternalReport::FormClose(TObject *Sender,
      TCloseAction &Action)
{
for(int i=0;i<List->Count;i++)
        {
        TElementSpiskaPerObject * ElementSpiska=(TElementSpiskaPerObject*) List->Items[i];
        delete ElementSpiska;
        }
delete List;

for(int i=0;i<TableList->Count;i++)
        {
        TElementSpiskaPerObject * ElementSpiska=(TElementSpiskaPerObject*) TableList->Items[i];
        delete ElementSpiska;
        }
delete TableList;

Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintExternalReport::Timer1Timer(TObject *Sender)
{
Timer1->Interval=0;
// �������� ���� ���� ��������� ����
if(FileExists(template_file_name)==false)
        {
        ShowMessage("�� ������ ����: "+template_file_name);
        Close();
        return;
        }

PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

PrintForm->SS->BeginUpdate();

PrintForm->SS->LoadFromFile(template_file_name);
PrintForm->SS->Pages[0]->Caption = "������";
PrintForm->SS->AddSheetPage("������");
PrintForm->SS->RowsAutoHeight=false;
PrintForm->SS->ShowGrid=false;
SizeHeader();

bool end_x=false;
bool end_y=false;
y=0;y1=0;
while (y<150 && end_y==false)
        {
        PrintForm->SS->Pages[1]->Rows->Size[y1]=PrintForm->SS->Pages[0]->Rows->Size[y];
        x=0;x1=0; end_x=false;
        while(x<20 && end_x==false)
                {
                cell_template = PrintForm->SS->Pages[0]->GetCellObject(x,y);
                cell_report =  PrintForm->SS->Pages[1]->GetCellObject(x1,y1);
                CopyFormatCell(cell_template, cell_report);
                AnsiString text_template= cell_template->Text;
                if(text_template=="END_DOC")
                        {
                        end_x=true;
                        end_y=true;
                        }

                if(text_template=="END_STR")
                        {
                        end_x=true;
                        }

                if (end_x==false && end_y==false)
                        {
                        if (text_template.Length()>=2)
                                {
                                if (text_template[1]=='[' &&
                                                text_template[2]=='#')
                                        { //��������� ������
                                        RunTableZapros(text_template);

                                        }
                                else
                                        {

                                        cell_report->Text=GetTextTemplate(text_template);
                                        }
                                }
                        else
                                {

                                cell_report->Text=GetTextTemplate(text_template);

                                }

                        }
                x++;x1++;
                }
        y++; y1++;
        }


PrintForm->SS->ActivePage = 1;
PrintForm->SS->EndUpdate();
PrintForm->Show();
Close();
}
//---------------------------------------------------------------------------
AnsiString TFormaPrintExternalReport::GetTextTemplate(AnsiString text)
{
AnsiString result="";
AnsiString value="";
AnsiString zapros="";
bool v=false;
bool z=false;
for(int i=1; i<=text.Length();i++)
        {
        if (text[i]=='[')
                {  //������ //�������� ��������� ������
                if (text[i+1]=='$') {z=true;v=false;}
                else
                        {
                        if (text[i+1]==':'){z=false;v=true; }
                        else {z=false;v=false;}
                        }
                }

        if (text[i]==']')
                {  //�����
                if (z==true)
                        { //���������� ��������� ������
                        //ShowMessage("������: "+zapros);
                        result=result+RunZapros(zapros);
                        zapros="";
                        }
                if(v==true)
                        {//���������� �������� �������� ����������
                        //ShowMessage("����������: "+value);
                        result=result+FindPerem(value);
                        }

                v=false;
                z=false;
                }

        if(z==true && text[i]!='[' && text[i]!='$')
                {
                zapros=zapros+text[i];
                }

        if (v==true&& text[i]!='[' && text[i]!=':')
                {
                value=value+text[i];
                }

        if ( z==false && v==false && text[i]!=']')
                {
                result=result+text[i];
                }
        }


return result;
}
//----------------------------------------------------------------------------
AnsiString TFormaPrintExternalReport::FindPerem(AnsiString text)
{
AnsiString result="";
for(int i=0;i<List->Count;i++)
        {
        TElementSpiskaPerObject *ElementSpiska=(TElementSpiskaPerObject*) List->Items[i];
        //ShowMessage("����������: "+ElementSpiska->name+" ��������:"+ElementSpiska->value);
        if (ElementSpiska->name==text)
                {
                result=ElementSpiska->value;
                }
        }

return result;
}
//------------------------------------------------------------------------------
AnsiString TFormaPrintExternalReport::RunZapros(AnsiString zapros)
{
AnsiString result="";
//���������� ������ ��������� �������� ����������


IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(zapros);

bool new_parameter=false;
AnsiString name_parameter="";

for(int i=1; i<=zapros.Length();i++)
        {
        if (zapros[i]==':')
                {  //��������
                new_parameter=true;
                }

        if (new_parameter==true && zapros[i]!=':' )
                {
                name_parameter=name_parameter+zapros[i];
                }

         if ((zapros[i]==' ' || zapros[i]==',') && new_parameter==true)
                {
                //�������� ��������� ��� ���������
                IBQ->ParamByName(Trim(name_parameter))->AsString=FindPerem(Trim(name_parameter));
                new_parameter=false;
                name_parameter="";
                }
         }
         
if(new_parameter==true)
        {
        IBQ->ParamByName(Trim(name_parameter))->AsString=FindPerem(name_parameter);
        }


//int num_col=x;
//int num_row=y;

//ShowMessage(zapros);

        try
                {
                IBQ->Active=true;
                }
        catch (Exception &exception)
                {
                ShowMessage("������ ��� ������������ ������ \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"������ ������� :"+IntToStr(x)+"-"+IntToStr(y));
                }

for (int i=0;i<IBQ->FieldCount;i++)
        {
        result=result+" "+IBQ->Fields->Fields[i]->AsString;
        }



//x=num_col;
//x1=num_col;
return result;
}
//------------------------------------------------------------------------------
void TFormaPrintExternalReport::RunTableZapros(AnsiString zapros)
{

        TcxSSCellObject *cell_template1;
        TcxSSCellObject *cell_report1;
//���� ������ ������� [#]
AnsiString new_zapros="";
for(int i=1; i<=zapros.Length();i++)
        {
        if (zapros[i]=='[' || zapros[i]==']'  || zapros[i]=='#' || zapros[i]=='$')
                {
                new_zapros=new_zapros+' ';
                }
        else
                {
                new_zapros=new_zapros+zapros[i] ;
                }
        }

zapros=new_zapros;
//���������� ������ ��������� �������� ����������
IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(zapros);

bool new_parameter=false;
AnsiString name_parameter="";


for(int i=1; i<=zapros.Length();i++)
        {
        if (zapros[i]==':')
                {  //��������
                new_parameter=true;
                }

        if (new_parameter==true && zapros[i]!=':' )
                {
                name_parameter=name_parameter+zapros[i];
                }

         if ((zapros[i]==' ' || zapros[i]==',') && new_parameter==true)
                {
                //�������� ��������� ��� ���������
                IBQ->ParamByName(Trim(name_parameter))->AsString=FindPerem(Trim(name_parameter));
                new_parameter=false;
                name_parameter="";
                }
         }
         
if(new_parameter==true)
        {
        IBQ->ParamByName(Trim(name_parameter))->AsString=FindPerem(Trim(name_parameter));
        }


int num_col=x;
//int num_row=y;

//ShowMessage(zapros);

        try
                {
                IBQ->Active=true;
                }
        catch (Exception &exception)
                {
                ShowMessage("������ ��� ������������ ������ \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"������ ������� :"+IntToStr(x)+"-"+IntToStr(y));
                }


        //������ ��������� � ������ �������  �������� �� ���������
        y++;

IBQ->First();
while(!IBQ->Eof)
        {
        PrintForm->SS->Pages[1]->Rows->Size[y1]=PrintForm->SS->Pages[0]->Rows->Size[y];
        //ShowMessage("����� ������ :"+IntToStr(x)+"-"+IntToStr(y));
        //�������� ������ ����������
        for(int i=0;i<TableList->Count;i++)
                {
                TElementSpiskaPerObject * ElementSpiska=(TElementSpiskaPerObject*) TableList->Items[i];
                delete ElementSpiska;
                }
        TableList->Clear();
        for (int i=0;i<IBQ->FieldCount;i++)
                {
                TElementSpiskaPerObject* el=new TElementSpiskaPerObject;
                el->name=Trim(IBQ->Fields->Fields[i]->FieldName);
                el->value=Trim(IBQ->Fields->Fields[i]->AsString);
                TableList->Add(el);
                }
//--------------------------------------------------------------------------------
//        x1=num_col; x=num_col;
//        for (int i=0;i<IBQ->FieldCount;i++)
//                {
//                cell_template = PrintForm->SS->Pages[0]->GetCellObject(x,y);
//                cell_report =  PrintForm->SS->Pages[1]->GetCellObject(x1,y1);
//                cell_report->Text=IBQ->Fields->Fields[i]->AsString;
//                //ShowMessage("�������� ������� "+ IBQ->Fields->Fields[i]->AsString);
//                x1++; x++;
//                }
//----------------------------------------------------------------------------------
        //������ ��������� �� �������� ������� ������ (��������� �� �������� )
        bool end_x=false;
        x1=num_col; x=num_col;
        while(x<20 && end_x==false)
                {
                //ShowMessage("������ ������� :"+IntToStr(x)+"-"+IntToStr(y));
                //TcxSSCellStyle * style;
                cell_template1 = PrintForm->SS->Pages[0]->GetCellObject(x,y);
               // style=cell_template1->Style;;
                cell_report1 =  PrintForm->SS->Pages[1]->GetCellObject(x1,y1);
                AnsiString text_template= cell_template1->Text;
                if(text_template=="END_STR")
                        {
                        end_x=true;
                        }

                if (end_x==false)
                        {
                        //if (text_template.Length()>=2)
                       //         {
                               // if (text_template[1]=='[' &&
                                //                text_template[2]=='#')
                       //                 { //��������� ������
                                        //RunTableZapros(text_template);

                                //        }
                                //else
                       //                 {
                       //                 cell_report->Text=TableGetTextTemplate(text_template);
                                //        }
                        //        }
                       // else
                        //        {
                                CopyFormatCell(cell_template1, cell_report1);
                                cell_report1->Text=TableGetTextTemplate(text_template);

                        //        }
                        }
                x++;x1++;
                }

        y1++;
        IBQ->Next();
        }

x=num_col;
x1=num_col;
y++;

}
//------------------------------------------------------------------------------
AnsiString TFormaPrintExternalReport::TableFindPerem(AnsiString text)
{
AnsiString result="";
for(int i=0;i<TableList->Count;i++)
        {
        TElementSpiskaPerObject *ElementSpiska=(TElementSpiskaPerObject*) TableList->Items[i];
        //ShowMessage("����������: "+ElementSpiska->name+" ��������:"+ElementSpiska->value);
        if (ElementSpiska->name==text)
                {
                result=ElementSpiska->value;
                }
        }

return result;
}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
AnsiString TFormaPrintExternalReport::TableGetTextTemplate(AnsiString text)
{
AnsiString result="";
AnsiString value="";
AnsiString zapros="";
bool v=false;
bool z=false;
for(int i=1; i<=text.Length();i++)
        {
        if (text[i]=='[')
                {  //������ //�������� ��������� ������
                if (text[i+1]=='$') {z=true;v=false;}
                else
                        {
                        if (text[i+1]==':'){z=false;v=true; }
                        else {z=false;v=false;}
                        }
                }

        if (text[i]==']')
                {  //�����
                if (z==true)
                        { //���������� ��������� ������
                        //ShowMessage("������: "+zapros);
                        result=RunZapros(zapros);
                        }
                if(v==true)
                        {//���������� �������� �������� ����������
                        //ShowMessage("����������: "+value);
                        result=result+TableFindPerem(value);
                        }

                v=false;
                z=false;
                }

        if(z==true && text[i]!='[' && text[i]!='$')
                {
                zapros=zapros+text[i];
                }

        if (v==true&& text[i]!='[' && text[i]!=':')
                {
                value=value+text[i];
                }

        if ( z==false && v==false && text[i]!=']')
                {
                result=result+text[i];
                }
        }


return result;
}
//------------------------------------------------------------------------------
void TFormaPrintExternalReport::CopyFormatCell(TcxSSCellObject *cell_templ, TcxSSCellObject *cell_rep)
{
//cell_report->Style=cell_template->Style;
cell_rep->Style->Borders=cell_templ->Style->Borders;
cell_rep->Style->Font=cell_templ->Style->Font;
cell_rep->Style->WordBreak = cell_templ->Style->WordBreak;
cell_rep->Style->Brush=cell_templ->Style->Brush;
cell_rep->Style->HorzTextAlign = cell_templ->Style->HorzTextAlign;
cell_rep->Style->VertTextAlign = cell_templ->Style->VertTextAlign;
}
//------------------------------------------------------------------------------
void TFormaPrintExternalReport::SizeHeader(void)
{
        TcxSSHeader *cHeader_report;
        TcxSSHeader *cHeader_template;
        cHeader_template = PrintForm->SS->Pages[0]->Cols;
        cHeader_report = PrintForm->SS->Pages[1]->Cols;

for(int i=0; i<20;i++)
        {
        cHeader_report->Size[i] = cHeader_template->Size[i];
        }

}
//------------------------------------------------------------------------------
