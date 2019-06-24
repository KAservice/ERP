//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaGurPlat.h"
#include "IDMSprARM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include <fstream.h>
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaGurPlat::TFormaGurPlat(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaGurPlat::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}


InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
NameKlientDBText->DataSource=DM->DataSourceTable;

PosNach=0;
PosCon=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
PosCon.DecodeDate(&Year,&Month,&Day);
PosNach=PosCon;
PosCon++;
DM->PosNach=PosNach;
DM->PosCon=PosCon;
DM->OpenTable();
Summa();
DM->Table->Last();
Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);

NoOnlyOut=false;
CodeTel="";

 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaGurPlat::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurPlat::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaInputText)FormaInputText->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}
DM->kanRelease();;
Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaGurPlat::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{



		if (number_procedure_end==ViborPerioda)
                {
				if(type_event==1)
                        {
						PosNach=FormaViborPerioda->PosNach;
                        PosCon=FormaViborPerioda->PosCon;
						DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        DM->UpdateTable();
                        }
                FormaViborPerioda=0;
                }

		if (number_procedure_end==CodMegafonRekv)
                {
                if(type_event==1)
                        {
                        CreateFileExportMegafon(FormaInputText->InputText);
                        }
                FormaInputText=0;
                }

		if (number_procedure_end==ElementRekv)
                {
                FormaElementaGurPlat=0;
                }





DM->CodeTel=CodeTel;
DM->NoOnlyOut=NoOnlyOut;
DM->UpdateTable();
Summa();

ViborRekv=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaGurPlat::Summa(void)
{
DM->DataSourceTable->Enabled=false;
TBookmark BM;
double summa_all_plat=0;
double summa_out_plat=0;
double summa_no_out_plat=0;

int kol_out_plat=0;
int kol_no_out_plat=0;

BM=DM->Table->GetBookmark();

DM->Table->First();
while (!DM->Table->Eof)
        {
        summa_all_plat=summa_all_plat+DM->TableSUM_GURNALPLAT->AsFloat;
        if (DM->TableOUT_GURNALPLAT->AsInteger==0)
                {
                summa_no_out_plat=summa_no_out_plat+DM->TableSUM_GURNALPLAT->AsFloat;
                kol_no_out_plat++;
                }
        else
                {
                summa_out_plat=summa_out_plat+DM->TableSUM_GURNALPLAT->AsFloat;
                kol_out_plat++;
                }
        DM->Table->Next();
        }


DM->Table->GotoBookmark(BM);
DM->Table->FreeBookmark(BM);
DM->DataSourceTable->Enabled=true;

KolStrLabel->Caption="Количество платежей:"+IntToStr(DM->Table->RecordCount);
KolOutLabel->Caption="Количество пров. платежей:"+IntToStr(kol_out_plat);
KolNoOutLabel->Caption="Количество непров. платежей:"+IntToStr(kol_no_out_plat);
SumNoOutPlatLabel->Caption="Сумма непроведенных платежей: "+FloatToStrF(summa_no_out_plat,ffFixed,10,2);
SumOutPlatLabel->Caption="Сумма проведенных платежей: "+FloatToStrF(summa_out_plat,ffFixed,10,2);
SumAllPlatLabel->Caption="Сумма всех платежей: "+FloatToStrF(summa_all_plat,ffFixed,10,2);

if (kol_no_out_plat>0)
        {
        KolNoOutLabel->Font->Color=clRed;
        SumNoOutPlatLabel->Font->Color=clRed;
        }
else
        {
        KolNoOutLabel->Font->Color=clWindowText;
        SumNoOutPlatLabel->Font->Color=clWindowText;
        }




}
//---------------------------------------------------------------------------
void __fastcall TFormaGurPlat::ToolButtonViborPeriodaClick(
      TObject *Sender)
{
if (FormaViborPerioda==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",IID_IFormaViborPerioda,
													(void**)&FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborPerioda->NumberProcVibor=ViborPerioda;
		FormaViborPerioda->PosNach=PosNach;
		FormaViborPerioda->PosCon=PosCon;
		}
}
//---------------------------------------------------------------------------



void TFormaGurPlat::OpenFormElement(void)
{
if (FormaElementaGurPlat==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaGurPlat.1",IID_IFormaElementaGurPlat,
													(void**)&FormaElementaGurPlat);
		FormaElementaGurPlat->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaGurPlat->NumberProcVibor=ElementRekv;
		FormaElementaGurPlat->DM->OpenElement(glStrToInt64(DM->TableID_GURNALPLAT->AsString));
		FormaElementaGurPlat->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaGurPlat::OpenFormNewElement(void)
{
if (FormaElementaGurPlat==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaGurPlat.1",IID_IFormaElementaGurPlat,
													(void**)&FormaElementaGurPlat);
		FormaElementaGurPlat->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaGurPlat->NumberProcVibor=ElementRekv;
        FormaElementaGurPlat->DM->NewElement();
		FormaElementaGurPlat->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaGurPlat::DeleteElement(void)
{
DM->DeleteElement(glStrToInt64(DM->TableID_GURNALPLAT->AsString));
DM->OpenTable();
}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurPlat::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurPlat::ToolButtonAddClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPlat::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
AnsiString TFormaGurPlat::FloatToStringComma(double value)
{
AnsiString result="";
AnsiString StrValue=FloatToStrF(value,ffFixed,10,2);

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
//---------------------------------------------------------------------------
void TFormaGurPlat::CreateFileExportMegafon(AnsiString code)
{
AnsiString FileName="";
AnsiString RashFile=DM_Connection->Arm_GetParameter("file_plat_"+code);
AnsiString Pach=DM_Connection->Arm_GetParameter("catalog_plat_"+code);

IDMGurPlat * DMGurPlat;
InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat,
													(void**)&DMGurPlat);
DMGurPlat->Init(InterfaceMainObject,InterfaceImpl);
DMGurPlat->CodeTel=code;
DMGurPlat->NoOnlyOut=true;
DMGurPlat->PosNach=PosNach;
DMGurPlat->PosCon=PosCon;
DMGurPlat->OpenTable();
if (DMGurPlat->Table->RecordCount==0)
        {
        ShowMessage("Нет непроведенных платежей!");
        DMGurPlat->kanRelease();
		return;
		}

DMGurPlat->Table->First();
FileName=Pach+"\\"+IntToStr(DMGurPlat->TableNUMKV_GURNALPLAT->AsInteger);
DMGurPlat->Table->Last();
FileName=FileName+"_"+IntToStr(DMGurPlat->TableNUMKV_GURNALPLAT->AsInteger)+RashFile;

// проверим если есть указанный файл то его удалим
if(FileExists(FileName)==true)
		{
		DeleteFile(FileName);
		}

const char *fileName=FileName.c_str();
ofstream outfile(fileName,ios::out);  //||ios::app

if (!outfile)
        {
         return;
        }
AnsiString str="";
DMGurPlat->Table->First();
while(!DMGurPlat->Table->Eof)
        {
        if (DMGurPlat->TableOUT_GURNALPLAT->AsInteger==1) continue;
        str=DMGurPlat->TableCODE_GURNALPLAT->AsString
                +DMGurPlat->TableNUMTEL_GURNALPLAT->AsString+" "
                +FloatToStringComma(DMGurPlat->TableSUM_GURNALPLAT->AsFloat)+" "
                +IntToStr(DMGurPlat->TableNUMKV_GURNALPLAT->AsInteger)
                +"\n";
        outfile<<str.c_str();
        DMGurPlat->Table->Next();
        }

str="END\n";
outfile<<str.c_str();


outfile.close();


// проверим если есть указанный файл
if(FileExists(FileName)==true)
        {
		IDMGurPlat * dm;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat,
													(void**)&dm);
		dm->Init(InterfaceMainObject,InterfaceImpl);
		DMGurPlat->Table->First();
		while(!DMGurPlat->Table->Eof)
                {
                dm->OpenElement(DMGurPlat->TableID_GURNALPLAT->AsInteger);
                dm->Element->Edit();
                dm->ElementOUT_GURNALPLAT->AsInteger=1;
                dm->Element->Post();
                dm->SaveElement();
                DMGurPlat->Table->Next();
                }
        dm->kanRelease();
        ShowMessage ("Файл сформирован! Имя файла: "+FileName);
        }
else
        {
        ShowMessage ("Файл не сформирован! Имя файла: "+FileName);
        }
DMGurPlat->kanRelease();

}

//---------------------------------------------------------------------------
void __fastcall TFormaGurPlat::ToolButtonCreateFileClick(TObject *Sender)
{

if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=CodMegafonRekv;
		//FormaInputText->NameLabel->Caption="Введите код:";
        //FormaInputText->Caption="Код номера";

        }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaGurPlat::CreateFileExportCiberplat(void)
{
AnsiString FileName="";
AnsiString RashFile=".txt";
AnsiString Pach=DM_Connection->Arm_GetParameter("catalog_ciberplat");
AnsiString point_id=DM_Connection->Arm_GetParameter("ciberplat_point_id");
AnsiString user_id=DM_Connection->Arm_GetParameter("ciberplat_user_id");

if (Trim(point_id)=="")
        {
        ShowMessage("Не задан код точки! Формирование файла невозможно!");
        return;
        }

if (Trim(point_id)=="")
        {
        ShowMessage("Не задан код пользователя! Формирование файла невозможно!");
        return;
        }

IDMGurPlat * DMGurPlat;
InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat,
													(void**)&DMGurPlat);
DMGurPlat->Init(InterfaceMainObject,InterfaceImpl);
DMGurPlat->CodeTel="";
DMGurPlat->NoOnlyOut=true;
DMGurPlat->PosNach=PosNach;
DMGurPlat->PosCon=PosCon;
DMGurPlat->OpenTable();
if (DMGurPlat->Table->RecordCount==0)
        {
        ShowMessage("Нет непроведенных платежей!");
		DMGurPlat->kanRelease();
        return;
        }



DMGurPlat->Table->First();
FileName=Pach+"\\"+IntToStr(DMGurPlat->TableNUMKV_GURNALPLAT->AsInteger);
DMGurPlat->Table->Last();
FileName=FileName+"_"+IntToStr(DMGurPlat->TableNUMKV_GURNALPLAT->AsInteger)+RashFile;

// проверим если есть указанный файл то его удалим
if(FileExists(FileName)==true)
        {
        DeleteFile(FileName);
		}

//const char *fileName=FileName.c_str();
//ofstream outfile(fileName,ios::out); //||ios::app

//if (!outfile)
//        {
//		 return;
//		}
TStringList * list=new TStringList();
//нельзя использовать ofstream   ошибки AV при закрытии програмы
AnsiString str="op_num;phone;amount;dop_kom;account;comment;point_id;user_id\n";
//outfile<<str.c_str();
list->Add(str);
str="";
DMGurPlat->Table->First();
while(!DMGurPlat->Table->Eof)
		{
		if (DMGurPlat->TableOUT_GURNALPLAT->AsInteger==1) continue;
		str= DMGurPlat->TableCODOPER_GURNALPLAT->AsString+";'"
				+DMGurPlat->TableCODE_GURNALPLAT->AsString
				+DMGurPlat->TableNUMTEL_GURNALPLAT->AsString+"';"
				+FloatToStringComma(DMGurPlat->TableSUMKL_GURNALPLAT->AsFloat)+";"
				+FloatToStringComma(DMGurPlat->TableSUM_GURNALPLAT->AsFloat)+";"
				+";"                 //account
				+"'comment';"
				+ point_id+";"
				+user_id;
		//outfile<<str.c_str();
		list->Add(str);
		DMGurPlat->Table->Next();
		}




//outfile.close();
list->SaveToFile(FileName,TEncoding::ASCII) ;
delete list;

// проверим если есть указанный файл
if(FileExists(FileName)==true)
        {
		IDMGurPlat * dm;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat,
													(void**)&dm);
		dm->Init(InterfaceMainObject,InterfaceImpl);
        DMGurPlat->Table->First();
        while(!DMGurPlat->Table->Eof)
				{
				dm->OpenElement(glStrToInt64(DMGurPlat->TableID_GURNALPLAT->AsString));
				dm->Element->Edit();
				dm->ElementOUT_GURNALPLAT->AsInteger=1;
				dm->Element->Post();
				dm->SaveElement();
				DMGurPlat->Table->Next();
				}
		dm->kanRelease();
		ShowMessage ("Файл сформирован! Имя файла: "+FileName);
		}
else
		{
		ShowMessage ("Файл не сформирован! Имя файла: "+FileName);
		}
DMGurPlat->kanRelease();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurPlat::ToolButton3Click(TObject *Sender)
{
CreateFileExportCiberplat();
DM->CodeTel=CodeTel;
DM->NoOnlyOut=NoOnlyOut;
DM->UpdateTable();
Summa();
}
//---------------------------------------------------------------------------



void __fastcall TFormaGurPlat::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPlat::cxButtonClearClick(TObject *Sender)
{
        String V="Вы действительно хотите очистить журнал платежей?";
        String Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

        V="Оставить последнюю запись для сохранения нумерации квитанций?";
        Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                DM->DeleteAllElement(true);
                }
        else
                {
                DM->DeleteAllElement(false);
                }
                
DM->UpdateTable();
ShowMessage("Очистка журнала платежей завершена!");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurPlat::cxGrid1DBTableView1OUT_GURNALPLATCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (ATextToDraw==1)
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;		
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPlat::cxGrid1DBTableView1DblClick(TObject *Sender)
{
OpenFormElement();  	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPlat::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurPlat");
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPlat::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

