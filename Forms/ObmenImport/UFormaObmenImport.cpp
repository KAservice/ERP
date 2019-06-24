//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaObmenImport.h"
#include "UDM.h"
#include "UDMSetup.h" 
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "UDMXMessageObmen.h"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TFormaObmenImport::TFormaObmenImport(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TFormaObmenImport::FormCreate(TObject *Sender)
{
RichEdit1->Clear();

        try
                {

                }
        catch (...)
                {

                }
}
//---------------------------------------------------------------------------
void __fastcall TFormaObmenImport::FormClose(TObject *Sender, TCloseAction &Action)
{

Action=caFree;
}
//----------------------------------------------------------------------------
void __fastcall TFormaObmenImport::EndEdit(TObject *Sender)
{
if (ViborRekvisit==ViborBase)
        {

        if (SpisokBase->OutReady==true)
                {
                IdBase=SpisokBase->DM->TableID_SINFBASE_OBMEN->AsInteger;
                NameBaseLabel->Caption=SpisokBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                }
        }
ViborRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaObmenImport::ButtonOpenFileClick(TObject *Sender)
{
if (OpenDialog1->Execute())
        {
        try
                {
                FileNameXML=OpenDialog1->FileName;
                LabelFileName->Caption=FileNameXML;

                //�� �������� ����� ������� GID ��������� �  ������� ���� ���������
                String name_file=ExtractFileName(FileNameXML);
                String prefiks_priemnik=name_file;
                prefiks_priemnik=Trim(prefiks_priemnik.SetLength(2));
                String gid_message=name_file;
                gid_message=Trim(name_file.Delete(1,3));
                int kol=gid_message.Length();
                gid_message=Trim(gid_message.SetLength(kol-4));

                LabelPrefiksPriemnik->Caption="�������: "+prefiks_priemnik;
                LabelGID->Caption="���������: '"+gid_message+"'";

                if(prefiks_priemnik!=gl_prefiks_ib)
                        {
                        ShowMessage("��������! ��������� ���� �� ������������ ��� �������� � ������� �������������� ����!");

                        }

                TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
                int id_message=DMMessage->GetIDElement(gid_message);

                delete DMMessage;

                //�������� ��� �� ��� ������ ���������
                if(id_message!=0)
                        {
                        ShowMessage("��������! ������ ��������� ���� ��������� �����!");
                        }


                }
        catch (...)
                {

                }


        }
}


//----------------------------------------------------------------------------------
String TFormaObmenImport::CommaToPixel(String value)
{
String result="";
String StrValue=value;

for(int i=1;i<=StrValue.Length();i++)
        {
        if (StrValue[i]==',')
                {
                result=result+".";

                }
        else
                {
                result=result+StrValue[i];
                }
        }
return result;
}
//----------------------------------------------------------------------------------
double TFormaObmenImport::StringToFloatComma(String value)
{
double res=0;
String result="";
String StrValue=value;

for(int i=1;i<=StrValue.Length();i++)
        {
        if (StrValue[i]=='.')
                {
                result=result+",";

                }
        else
                {
                result=result+StrValue[i];
                }
        }

res=StrToFloat(result);
return res;
}
//-----------------------------------------------------

void __fastcall TFormaObmenImport::ButtonVigrClick(TObject *Sender)
{

UpdateDataInfBase(IdBase);

}

//-------------------------------------------------------------------------------------
void __fastcall TFormaObmenImport::ButtonViborBaseClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------
void TFormaObmenImport::OpenFormSpiskaSprInfBase(void)
{
if (IdDochForm==NULL)
        {
        SpisokBase=new TFormaSpiskaSprInfBase(Application);
        if (!SpisokBase) return;
        SpisokBase->IdRodForm=Handle;
        SpisokBase->Vibor=true;
        IdDochForm=SpisokBase->Handle;
        ViborRekvisit=ViborBase;
        SpisokBase->Show();
        SpisokBase->FOnCloseForm=EndEdit;
        }  
}

//-----------------------------------------------------------------------------
void __fastcall TFormaObmenImport::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void TFormaObmenImport::UpdateDataInfBase(int id_base)
{
IdBase=id_base;
if (IdBase==0) return;

                //�� �������� ����� ������� GID ��������� �  ������� ���� ���������
                String name_file=ExtractFileName(FileNameXML);
                String prefiks_priemnik=name_file;
                prefiks_priemnik=Trim(prefiks_priemnik.SetLength(2));
                String gid_message=name_file;
                gid_message=Trim(name_file.Delete(1,3));
                int kol=gid_message.Length();
                gid_message=Trim(gid_message.SetLength(kol-4));

                if(prefiks_priemnik!=gl_prefiks_ib)
                        {
                        String V="��������! ��������� ���� �� ������������ ��� �������� � ������� �������������� ����! ����������?";
                        String Z="������������� ���������� ����";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                return;
                                }
                         }
                         
                TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
                int id_message=DMMessage->GetIDElement(gid_message);
                //�������� ��� �� ��� ������ ���������
                if(id_message==0)
                        {
                        DMMessage->NewElement(IdBase);
                        DMMessage->ElementGID_XMESSAGE_OBMEN->AsString=gid_message;
                        DMMessage->ElementOUT_XMESSAGE_OBMEN->AsInteger=2;
                        DMMessage->SaveElement();
                        }
                else
                        {
                        String V="������ ��������� ���� ��������� �����! ����������?";
                        String Z="������������� ���������� ����";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                return;
                                }
                        }

DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);


xml->Active = true;
xml->LoadFromFile(WideString(FileNameXML));
_di_IXMLNode  xml_base=xml->DocumentElement;


ProgressBar1->Max=xml_base->ChildNodes->Count;
OutProtocol("���������� ���������: "+ IntToStr(xml_base->ChildNodes->Count));
LabelTotalIsm->Caption="����� ���������: "+IntToStr(xml_base->ChildNodes->Count);
LabelTotalIsm->Update();
//ShowMessage(IntToStr(TableDataOut->RecordCount));
ProgressBar1->Step=1;
int kol_rec=0;

  for (int i=0;i<xml_base->ChildNodes->Count;i++)    //1 ������� ����� ����������
        {

        OutProtocol("");

        _di_IXMLNode xml_rec=xml_base->ChildNodes->Get(i);

        int operation=(int)StrToFloat(xml_rec->GetAttribute("oper"));

        switch (operation)
                {

                case 1 :  //�������
                        {
                        InsertRecord(xml_rec);
                        } break;
                case 2 :  //��������������
                        {
                        EditRecord(xml_rec);
                        } break;
                case 3 :  //��������
                        {
                         DeleteRecord(xml_rec);
                        } break;
                default :
                        {

                        } break;
                }

        OutProtocol("");
        kol_rec++;
        LabelZagrIsm->Caption="��������� ���������: "+IntToStr(kol_rec);
        LabelZagrIsm->Update();
        ProgressBar1->StepIt();
        }

xml->Active = false;

delete DMXTableBase;
delete DMXFieldBase;

delete DMMessage;
ShowMessage("�������� ������ ���������!");
}
//-----------------------------------------------------------------------------
void TFormaObmenImport::InsertRecord(_di_IXMLNode xml_rec)
{
String name_table=Trim(xml_rec->NodeName);
DMXTableBase->GetElementPoName(name_table);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

//�������� ������������ GID
String name_field_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_field_gid=xml_rec->GetAttribute("value_gid");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_gid);
OutProtocol("value_gid "+ value_field_gid);

//������� ������� �� ��� GID
IBQ2->Active=false;
IBQ2->SQL->Clear();
String zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_gid+"='"+value_field_gid+"'";
IBQ2->SQL->Add(zapros);
IBQ2->Active=true;


if (IBQ2->RecordCount==0)  //������ �� �������
        {
        OutProtocol("�� ������� ***********************************");
        //���� �������� ������
        ///�������� ����� ������� �������
        String zapros=CreateTextZaprosInsert(xml_rec);
        IBQ1->Active=false;
        IBQ1->SQL->Clear();
        IBQ1->SQL->Add(zapros);
        IBQ1->ExecSQL();
        IBTr->Commit();
        IBQ1->Active=false;
        }
else
        {
        OutProtocol(" �������");
        //���� �������� ������ ������� ��������� ���� �� ���������!!!!!!!!
        String zapros=CreateTextZaprosEdit(xml_rec, name_field_gid, value_field_gid);
        if (zapros!="")
                {
                IBQ1->Active=false;
                IBQ1->SQL->Clear();
                IBQ1->SQL->Add(zapros);
                IBQ1->ExecSQL();
                IBTr->Commit();
                IBQ1->Active=false;
                }
        }
IBQ2->Active=false;
}
//-----------------------------------------------------------------------------
void TFormaObmenImport::EditRecord(_di_IXMLNode xml_rec)
{
String name_table=Trim(xml_rec->NodeName);
DMXTableBase->GetElementPoName(name_table);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

//�������� ������������ GID
String name_field_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_field_gid=xml_rec->GetAttribute("value_gid");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_gid);
OutProtocol("value_gid "+ value_field_gid);

//������� ������� �� ��� GID
IBQ2->Active=false;
IBQ2->SQL->Clear();
String zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_gid+"='"+value_field_gid+"'";
IBQ2->SQL->Add(zapros);
IBQ2->Active=true;


if (IBQ2->RecordCount==0)  //������ �� �������
        {
        OutProtocol("�� ������� ***********************************");
        //���� �������� ������
        ///�������� ����� ������� �������
        String zapros=CreateTextZaprosInsert(xml_rec);
        IBQ1->Active=false;
        IBQ1->SQL->Clear();
        IBQ1->SQL->Add(zapros);
        IBQ1->ExecSQL();
        IBTr->Commit();
        IBQ1->Active=false;
        }
else
        {
        OutProtocol(" �������");

        //���� �������� ������ ������� ��������� ���� �� ���������!!!!!!!!
        String zapros=CreateTextZaprosEdit(xml_rec, name_field_gid, value_field_gid);
        if (zapros!="")
                {
                IBQ1->Active=false;
                IBQ1->SQL->Clear();
                IBQ1->SQL->Add(zapros);
                IBQ1->ExecSQL();
                IBTr->Commit();
                IBQ1->Active=false;
                }
        }
IBQ2->Active=false;
}
//---------------------------------------------------------------------------
void TFormaObmenImport::DeleteRecord(_di_IXMLNode xml_rec)
{


}

//-----------------------------------------------------------------------------
String TFormaObmenImport::GetIDFK(String name_field, String value_gid, _di_IXMLNode xml_field)
{
//�������� ��������� �������� ID ���� �������� ����� �� ������� �������


String result="";
        String name_table_fk=Trim(DMXFieldBase->TableTABLEFK_XFIELD_BASE->AsString);  //������� �� ������� ��������� ����
        String name_field_fk=Trim(DMXFieldBase->TableFIELDFK_XFIELD_BASE->AsString);    //��� ���� �� ������� ��������� ����
        String name_field_gid_fk=Trim(DMXFieldBase->TableGIDFK_XFIELD_BASE->AsString);   //��� ���� ������� �������� GID ��

                //������� �������� ID

                String name_field_id=name_field_fk;

                IBQ3->Active=false;
                IBQ3->SQL->Clear();
                String zapros="";
                zapros=zapros+"select "+name_field_id;
                zapros=zapros+" from "+name_table_fk;
                zapros=zapros+" where "+name_field_gid_fk+"='"+value_gid+"'";
                IBQ3->SQL->Add(zapros);

                IBQ3->Active=true;
                if (IBQ3->RecordCount==1)
                        {
                        result=Trim(IBQ3->FieldByName(name_field_id)->AsString);
                        }

                OutProtocol("id "+ result);
                //-------------------------------------------------------------------------

return result;

}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------
void __fastcall TFormaObmenImport::FormResize(TObject *Sender)
{
 ProgressBar1->Width=PageControl1->Width;
}
//---------------------------------------------------------------------------
String TFormaObmenImport::CreateTextZaprosInsert(_di_IXMLNode xml_rec)
{
String result="";
String fields="";
String values="";
String name_table=Trim(xml_rec->NodeName);
        bool comma=false;
        for (int i=0;i<xml_rec->ChildNodes->Count;i++)
                {
                _di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
                String name_field=xml_field->NodeName;
                if (CheckFieldForInsert(name_field)==false) continue; //�������� ����



                DMXFieldBase->FindNameField(name_field);
                String value_field="";
                //String xml_fk=xml_field->GetAttribute("fk");
                bool fk=false;
                if (DMXFieldBase->TableFK_XFIELD_BASE->AsInteger==1){fk=true;}



                if (fk==true)
                        { //����� �� Gid �������� ID
                        String value_gid=xml_field->GetAttribute("gid_fk");
                        if (value_gid!="" && value_gid!=0)
                                {
                                value_field=GetIDFK(name_field,value_gid, xml_field);
                                }
                        }
                else
                        {
                        value_field=xml_field->GetAttribute("v");
                        //���� ����� � ������� ����������
                        //�������� �� ����� � ������
                        if(CheckDrob(name_field)==true)
                                {
                                value_field=CommaToPixel(value_field);
                                }
                        }

                        if(value_field!="")
                                {
                                if (comma==false)
                                        {
                                        fields=name_field;
                                        values="'"+value_field+"'";
                                        comma=true;
                                        }
                                else
                                        {
                                        fields=fields+", "+name_field;
                                        values=values+", "+"'"+value_field+"'";
                                        }
                                 }
                }
result=result+"insert into "+name_table+" ("+fields+")";
result=result+" values ("+values+")";


OutProtocol("****************������ ���������� ************************");
OutProtocol("");
OutProtocol(result);
OutProtocol("");
OutProtocol("****************������ ���������� ************************");
return result;


}
//---------------------------------------------------------------------------
String TFormaObmenImport::CreateTextZaprosEdit(_di_IXMLNode xml_rec, String name_field_gid, String value_field_gid)
{
String result="";
String fields="";
String name_table=Trim(xml_rec->NodeName);
bool comma=false;
bool run_query=false;


        for (int i=0;i<xml_rec->ChildNodes->Count;i++)
                {
                _di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
                String name_field=xml_field->NodeName;
                if(CheckFieldForEdit(name_field)==false) continue;   //���� �� ��������� ������ ����

                if(DMXFieldBase->FindNameField(name_field)==false)
                        {
                        ShowMessage("�� ������� ����: '"+name_field+"' !");
                        }
                
                String value_field="";
                bool fk=false;
                if (DMXFieldBase->TableFK_XFIELD_BASE->AsInteger==1){fk=true;}



                if (fk==true)
                        { //����� �� Gid �������� ID
                        String value_gid=xml_field->GetAttribute("gid_fk");
                        OutProtocol("������� ���� value_gid"+value_gid );
                        if (value_gid!="" && value_gid!=0)
                                {
                                value_field=GetIDFK(name_field,value_gid, xml_field);
                                }



                        }
                else
                        {
                        value_field=xml_field->GetAttribute("v");
                        }




                        if (Trim(value_field)!=Trim(IBQ2->FieldByName(name_field)->AsString))
                                {

                                run_query=true;
                                OutProtocol("++++++++++ ��������� ������:"+name_field +", �������� � ����� '"+value_field +"'");
                                OutProtocol(" � ����:  '"+Trim(IBQ2->FieldByName(name_field)->AsString)+"'");
                                }
                                
                        ///���� ����� � �������
                        //�� �������� ������� �� �����
                        if(CheckDrob(name_field)==true)
                                {
                                value_field=CommaToPixel(value_field);
                                }

                        if(value_field!="")
                                {
                                if (comma==false)
                                        {
                                        fields=name_field+"='"+value_field+"'";
                                        comma=true;
                                        }
                                else
                                        {
                                        fields=fields+", "+name_field+"='"+value_field+"'";
                                        }
                                 }

                  OutProtocol("***��� ����"+name_field +": ��������"+value_field);
                  OutProtocol("�� ������� "+Trim(IBQ2->FieldByName(name_field)->AsString));

                }

                
result=result+" update "+name_table+" set "+fields+" where "+
        name_field_gid+"='"+value_field_gid+"'";

if (run_query==false)result="";

OutProtocol("****************������ ���������� ************************");
OutProtocol("");
OutProtocol(result);
OutProtocol("");
OutProtocol("****************������ ���������� ************************");

return result;


}
//----------------------------------------------------------------------------
bool TFormaObmenImport::CheckFieldForEdit(String name_field)
{
bool result=false;
if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
if (name_field==Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString))return result;
if (name_field=="PRDOC") return result;
if (name_field=="PRICEZPART") return result;
if (name_field=="IDPARTPERT") return result;
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TFormaObmenImport::CheckFieldForInsert(String name_field)
{
bool result=false;
if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
if (name_field=="PRDOC") return result;
if (name_field=="PRICEZPART") return result;
if (name_field=="IDPARTPERT") return result;
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TFormaObmenImport::CheckDrob(String name_field)
{
bool result=false;


if(DMXFieldBase->TableSCALE_XFIELD_BASE->AsInteger<0)
        {
        result=true;
        }

return result;


}
//---------------------------------------------------------------------------
void TFormaObmenImport::OutProtocol(String str)
{
if (CheckBoxOutProtocol->Checked==true)
        {
        RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------
