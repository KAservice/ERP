//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocRealRoznTouch.h"
#include "IDMSprARM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaDocRealRoznTouch::TFormaDocRealRoznTouch(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
glFR=0;;
glDisplayPok=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaDocRealRoznTouch::Init(void)
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

    //необходимо получить интерфейсы фискального регистратор и дисплея
	IDevices * i_dev;
	if (InterfaceMainObject->kanQueryInterface(IID_IDevices,(void**)&i_dev)==-1)
		{
		if (i_dev)
			{
			if (i_dev->GetDeviceObject(1, (void**) &glFR)!=-1)
				{
				glFR=0;
				}
			if(	i_dev->GetDeviceObject(2, (void**) &glDisplayPok)!=-1)
				{
                glDisplayPok=0;
				}
			i_dev->kanRelease();
			}
		}
	else
		{
		glFR=0;
        glDisplayPok=0;
		}
	}

EditRekvisit=NO;

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора

//установим DataSource
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameFirmDBText->DataSource=DM->DataSourceDocAll;
NameSkladDBText->DataSource=DM->DataSourceDocAll;
NameKlientDBText->DataSource=DM->DataSourceDocAll;
NumDocDBText->DataSource=DM->DataSourceDocAll;
DateDocDBText->DataSource=DM->DataSourceDocAll;
SumDocDBText->DataSource=DM->DataSourceDocAll;
PrimDBText->DataSource=DM->DataSourceDoc;

TypeEvent=0;;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaDocRealRoznTouch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocRealRoznTouch::UpdateForm(void)
{
//LabelFirm->Caption="Фирма: "+DM->FirmaNAMEFIRM->AsString;
//LabelSklad->Caption="Склад: "+DM->SkladNAMESKLAD->AsString;
//LabelKlient->Caption="Контрагент: "+DM->KlientNAMEKLIENT->AsString;
//LabelNameDoc->Caption="Акт реализации №"+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRoznTouch::ButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRoznTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznTouch::ButtonSaveClick(TObject *Sender)
{
DM->SaveDoc();
}
//---------------------------------------------------------------------------



int TFormaDocRealRoznTouch::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


EditRekvisit=NO;
return -1;

}

//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznTouch::ButtonOKClick(TObject *Sender)
{
if (DM->SaveDoc()==true)
	{
		TypeEvent=1;
        if (DM->DvRegDoc()==true)
                {
                Close();
				}
		else
				{
				ShowMessage("Не удалось провести документ! Ошибка:"+DM->TextError);
				Close();
				}

	}
else
	{
	ShowMessage("Не удалось записать документ! Ошибка:"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznTouch::ButtonPrintClick(TObject *Sender)
{

if (DM->SaveDoc()==true)
        {
        TypeEvent=1;
        }
else
		{
		String V="Не удалось сохранить Акт реализации!"+DM->TextError;
		String Z="Ошибка!";
		Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        return;
        }

if (PrintDocFR()==true)
        {

        }
else
		{
		String V="Не удалось напечатать Акт реализации!";
		String Z="Ошибка!";
		Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        }
}

//---------------------------------------------------------------------------
bool TFormaDocRealRoznTouch::PrintDocFR(void)
{
bool result=false;
if(glFR->ConnectFR==false) return result;
String StrPr="";

glFR->OpenNoFiscalCheck();

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,0,0,true,true, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,0,0,true,true, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,0,0,true,true, false);
        }

glFR->PrintString(" ",1,0,0,true,true, false);
StrPr="    Реализация (розн) №"+DM->DocAllNUMDOC->AsString;

glFR->PrintString(StrPr,1,0,0,true,true, false);
glFR->PrintString("    от "+DM->DocAllPOSDOC->AsString,1,0,0,true,true, false);

glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString(DM->DocPRIM_DREALROZN->AsString,1,0,0,true,true, false);


glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString("Покупатель:",1,0,0,true,true, false);
glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,true, false);
glFR->PrintLine();

DM->DocT->First();
while(!DM->DocT->Eof)
        {
		if (glFR->PrintString(DM->DocTNAMENOM->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if (DM->DocTSUMSK_DREALROZNT->AsFloat>0)
			{  //со скидкой
			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOL_DREALROZNT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat*DM->DocTKOL_DREALROZNT->AsFloat,ffFixed,15,2);
			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			StrPr="-"+FloatToStr(DM->DocTPRSK_DREALROZNT->AsFloat)+" % "
				+FloatToStrF(DM->DocTSUMSK_DREALROZNT->AsFloat,ffFixed,15,2)+
				" = "+FloatToStrF(DM->DocTSUM_DREALROZNT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}
		else
			{//без скидки

			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOL_DREALROZNT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTSUM_DREALROZNT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}



        DM->DocT->Next();
        }

glFR->PrintLine();
glFR->PrintString(" ",1,0,0,true,true, false);

StrPr="Всего: ";
glFR->PrintString(StrPr,1,0,0,true,true, false);
StrPr=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffCurrency,10,2);
glFR->PrintString(StrPr,3,0,2,true,true, false);

glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString(" ",1,0,0,true,true, false);


glFR->PrintString("Кассир: ",1,0,0,true,true, false);
StrPr=DM_Connection->UserInfoFNAME_USER->AsString;
glFR->PrintString(StrPr,1,0,0,true,true, false);
glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString("           _________________ ",1,0,0,true,true, false);

glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString(" ",1,0,0,true,true, false);
glFR->PrintString("Покупатель _________________ ",1,0,0,true,true, false);

for(int i=0;i<7;i++)
        {
        glFR->PrintString(" ",1,0,0,true,true, false);
		}
		
glFR->CloseNoFiscalCheck();

if (glFR->Cut(1)==true)
        {
        result=true;
        }


return result;



}
//---------------------------------------------------------------------------
