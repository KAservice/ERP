//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaGurAllDoc.h"
#include "IFormaDocPrihNakl.h"
#include "IFormaDocCheck.h"
#include "IFormaDocSchet.h"
#include "IFormaDocOstNom.h"
#include "IFormaDocPer.h"
#include "IFormaDocReal.h"
#include "IFormaDocSpisNom.h"
#include "IFormaDocVosvratPost.h"
#include "IFormaDocPKO.h"
#include "IFormaDocRKO.h"
#include "IFormaDocPlatPor.h"
#include "IFormaDocPostNaSchet.h"
#include "IDMSprUser.h"
#include "IFormaDocInv.h"
#include "IFormaDocRepKKM.h"
#include "IDMSetup.h"
#include "IDMDocOstVs.h"
#include "IFormaDocOstVs.h"
#include "IFormaDocSchetFact.h"
#include "IDMDocSchetFact.h"
#include "IDMDocReal.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocRKORozn.h"
#include "IFormaDocPKORozn.h"
#include "UFormIndicator.h"
//#include "UFormaReportDvDoc.h"
#include "IFormaDocVosvratPok.h"
#include "IFormaDocIsmPrice.h"
#include "IFormaDocRev.h"
#include "IFormaDocSpOtrOst.h"
#include "UReportDvRegDoc.h"
#include "IDMSprUser.h"
#include "IFormaDocVipuskProd.h"
#include "IFormaDocSborkaKompl.h"
#include "IFormaDocRasborkaKompl.h"
#include "IFormaDocZamena.h"
#include "IFormaDocKorrVS.h"
#include "IFormaDocVipBanka.h"
//#include "IDMRegAdvanceCustomer.h"
//#include "UDMRegBank.h"
//#include "UDMRegGoods.h"
#include "IFormaDocRegAdvCust.h"
#include "IFormaDocRegBank.h"
#include "IFormaDocRegGoods.h"
#include "IFormaDocRegKassa.h"
#include "IFormaDocRegOstNom.h"
#include "IFormaDocRegPaySale.h"
#include "IFormaDocRegVsRasch.h"
#include "IFormaDocRegCardBalance.h"
#include "IFormaDocOtchetPost.h"

 #include "IFormaDocRegOtchetPost.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
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
__fastcall TFormaGurAllDoc::TFormaGurAllDoc(TComponent* Owner)
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
void __fastcall TFormaGurAllDoc::FormCreate(TObject *Sender)
{




IdKlient=0;
NameKlient="";
IdSklad=0;
NameSklad="";
IdFirm=0;
NameFirm="";
StringTypeDoc="''";

OtborPoKlientu=false;
OtborPoFirm=false;
OtborPoSklad=false;
OtborPoTypeDoc=false;

//DM->OtborPoKlient=false;
//DM->OtborPoFirm=false;
//DM->OtborPoSklad=false;
//DM->OtborPoTypeDoc=false;
//DM->OpenTable();

StrOtborLabel->Caption="";

Vibor=false;



Vibor=false;
TypeEvent=0;


}
//-----------------------------------------------------------------------
bool TFormaGurAllDoc::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMGurAllDoc.1",IID_IDMGurAllDoc, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;

LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
        {
         ToolButtonAllCancelDvReg->Visible=false;
         ToolButtonDvRegDoc->Visible=false;
         ToolButtonDelAllDoc->Visible=false;
		}


DM->OpenTable();
DM->Table->Last();


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject(ProgId_DMTableExtPrintForm,IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaGurAllDocImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSetupOtbor)FormaSetupOtbor->kanRelease();


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


DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//--------------------------------------------------------------------------
int TFormaGurAllDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Period)
		{

		if (type_event==1)
				{
				 EndViborPerioda();
				}
		FormaViborPerioda=0;
		}

if (number_procedure_end==ER_Otbor)
		{

		if (type_event==1)
				{
				 EndViborParameterOtbor();
				}
		FormaSetupOtbor=0;
		}

if (number_procedure_end==ER_Doc)
		{

		if (type_event==1)
				{
				EndCloseDoc();
				}
		}

return -1;
}

//------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::EndViborPerioda(void)
{

						PosNach=FormaViborPerioda->PosNach;
                        PosCon=FormaViborPerioda->PosCon;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
						UpdateForm();

}
//---------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::EndViborParameterOtbor(void)
{

						IdKlient=FormaSetupOtbor->IdKlient;
						NameKlient=FormaSetupOtbor->NameKlient;
						IdSklad=FormaSetupOtbor->IdSklad;
						NameSklad=FormaSetupOtbor->NameSklad;
						IdFirm=FormaSetupOtbor->IdFirm;
						NameFirm=FormaSetupOtbor->NameFirm;
						StringTypeDoc=FormaSetupOtbor->StringTypeDoc;
						NameTypeDoc=FormaSetupOtbor->NameTypeDoc;
						UpdateForm();



}
//---------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::EndCloseDoc(void)
{

if (DM_Connection->UserInfoREOPEN_GUR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
}
//--------------------------------------------------------------------------
void TFormaGurAllDoc::UpdateForm(void)
{
		AnsiString s="";
		if (ToolButtonOtbor->Down==true)  // включить отбор
			{
			DM->OtborVkl=true;

			if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
			if (IdFirm>0) s=s+" Фирма: "+NameFirm;
			if (IdSklad>0) s=s+" Склад: "+NameSklad;
			if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
			StrOtborLabel->Caption=s;
			}
		else
			{
			DM->OtborVkl=false;
			StrOtborLabel->Caption=s;
			}

		DM->IdKlient=IdKlient;
		DM->IdSklad=IdSklad;
		DM->IdFirm=IdFirm;
		DM->StringTypeDoc=StringTypeDoc;

DM->UpdateTable();
}
//--------------------------------------------------------------------------
void TFormaGurAllDoc::OpenFormDoc()
{

if(DM->TableTDOC->AsString=="PRN")
        {
		IFormaDocPrihNakl * PrNakl;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPrihNakl.1",IID_IFormaDocPrihNakl,
													(void**)&PrNakl);
		PrNakl->Init(InterfaceMainObject,InterfaceImpl);
        if (!PrNakl) return;
		//PrNakl->IdRodForm=Handle;
        //настройка формы
		PrNakl->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		PrNakl->UpdateForm();
		PrNakl->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="CHK")
        {
		IFormaDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheck.1",IID_IFormaDocCheck,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
        if (!Check) return;
		//Check->IdRodForm=Handle;
        //настройка формы
		Check->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		Check->UpdateForm();
		Check->NumberProcVibor=ER_Doc;
		}


if(DM->TableTDOC->AsString=="REPKKM")
		{
		IFormaDocRepKKM * RepKKM;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRepKKM.1",IID_IFormaDocRepKKM,
													(void**)&RepKKM);
		RepKKM->Init(InterfaceMainObject,InterfaceImpl);
        if (!RepKKM) return;
		//RepKKM->IdRodForm=Handle;
        //настройка формы
		RepKKM->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		RepKKM->UpdateForm();
		//RepKKM->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="SCH")
        {
		IFormaDocSchet * Schet;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSchet.1",IID_IFormaDocSchet,
													(void**)&Schet);
		Schet->Init(InterfaceMainObject,InterfaceImpl);
        if (!Schet) return;
		//Schet->IdRodForm=Handle;
        //настройка формы
		Schet->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		Schet->UpdateForm();
		Schet->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="OSN")
		{
		IFormaDocOstNom * OstNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocOstNom.1",IID_IFormaDocOstNom,
													(void**)&OstNom);
		OstNom->Init(InterfaceMainObject,InterfaceImpl);
        if (!OstNom) return;
		//OstNom->IdRodForm=Handle;
        //настройка формы
		OstNom->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        OstNom->UpdateForm();
		OstNom->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="PER")
        {
		IFormaDocPer * Per;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPer.1",IID_IFormaDocPer,
													(void**)&Per);
		Per->Init(InterfaceMainObject,InterfaceImpl);
        if (!Per) return;
		//Per->IdRodForm=Handle;
        //настройка формы
		Per->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		Per->UpdateForm();
		Per->NumberProcVibor=ER_Doc;
		}


if(DM->TableTDOC->AsString=="REA")
        {
		IFormaDocReal * Real;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocReal.1",IID_IFormaDocReal,
													(void**)&Real);
		Real->Init(InterfaceMainObject,InterfaceImpl);
        if (!Real) return;
		//Real->IdRodForm=Handle;
        //настройка формы
		Real->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        Real->UpdateForm();
		Real->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="SPN")
        {
		IFormaDocSpisNom * SpisNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSpisNom.1",IID_IFormaDocSpisNom,
													(void**)&SpisNom);
		SpisNom->Init(InterfaceMainObject,InterfaceImpl);
        if (!SpisNom) return;
		//SpisNom->IdRodForm=Handle;
        //настройка формы
		SpisNom->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		SpisNom->UpdateForm();
		SpisNom->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="VPO")
        {
		IFormaDocVosvratPost * VosvratPost;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPost.1",IID_IFormaDocVosvratPost,
													(void**)&VosvratPost);
		VosvratPost->Init(InterfaceMainObject,InterfaceImpl);
        if (!VosvratPost) return;
		//VosvratPost->IdRodForm=Handle;
        //настройка формы
		VosvratPost->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        VosvratPost->UpdateForm();
		VosvratPost->NumberProcVibor=ER_Doc;
        }


if(DM->TableTDOC->AsString=="PKO")
        {
		IFormaDocPKO * PKO;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKO.1",IID_IFormaDocPKO,
													(void**)&PKO);
		PKO->Init(InterfaceMainObject,InterfaceImpl);
        if (!PKO) return;
		//PKO->IdRodForm=Handle;
        //настройка формы
		PKO->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		PKO->UpdateForm();
		PKO->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="RKO")
        {
		IFormaDocRKO * RKO;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKO.1",IID_IFormaDocRKO,
													(void**)&RKO);
		RKO->Init(InterfaceMainObject,InterfaceImpl);
        if (!RKO) return;
		//RKO->IdRodForm=Handle;
        //настройка формы
		RKO->DM->OpenDoc(DM->TableIDDOC->AsInt64);

        RKO->UpdateForm();
		//RKO->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="PLP")
        {
		IFormaDocPlatPor * PlPor;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPlatPor.1",IID_IFormaDocPlatPor,
													(void**)&PlPor);
		PlPor->Init(InterfaceMainObject,InterfaceImpl);
        if (!PlPor) return;
		//PlPor->IdRodForm=Handle;
        //настройка формы
		PlPor->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        PlPor->UpdateForm();
		PlPor->NumberProcVibor=ER_Doc;
        }
if(DM->TableTDOC->AsString=="PNS")
        {
		IFormaDocPostNaSchet * Post;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPostNaSchet.1",IID_IFormaDocPostNaSchet,
													(void**)&Post);
		Post->Init(InterfaceMainObject,InterfaceImpl);
        if (!Post) return;
		//Post->IdRodForm=Handle;
        //настройка формы
		Post->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        Post->UpdateForm();
		Post->NumberProcVibor=ER_Doc;
        }



if(DM->TableTDOC->AsString=="INV")
        {
		IFormaDocInv * Inv;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocInv.1",IID_IFormaDocInv,
													(void**)&Inv);
		Inv->Init(InterfaceMainObject,InterfaceImpl);
        if (!Inv) return;
		//Inv->IdRodForm=Handle;
        //настройка формы
		Inv->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		Inv->UpdateForm();
		Inv->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="OSTVS")
        {
		IFormaDocOstVs * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocOstVs.1",IID_IFormaDocOstVs,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
		//doc->IdRodForm=Handle;
        //настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="SCHFACT")
        {
		IFormaDocSchetFact * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSchetFact.1",IID_IFormaDocSchetFact,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
		//doc->IdRodForm=Handle;
        //настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="REALROZN")
		{
		IFormaDocRealRozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRozn.1",IID_IFormaDocRealRozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}


if(DM->TableTDOC->AsString=="PKOROZN")
        {
		IFormaDocPKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKORozn.1",IID_IFormaDocPKORozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
                if (!doc) return;
		//doc->IdRodForm=Handle;
        //настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
        doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
        }

if(DM->TableTDOC->AsString=="RKOROZN")
		{
		IFormaDocRKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKORozn.1",IID_IFormaDocRKORozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="VPOK")
		{
		IFormaDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPok.1",IID_IFormaDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="ISMPRICE")
		{
		IFormaDocIsmPrice * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocIsmPrice.1",IID_IFormaDocIsmPrice,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="SPOTROST")
		{
		IFormaDocSpOtrOst * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSpOtrOst.1",IID_IFormaDocSpOtrOst,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="REV")
		{
		IFormaDocRev * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRev.1",IID_IFormaDocRev,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="VIPPROD")
		{
		IFormaDocVipuskProd * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVipuskProd.1",IID_IFormaDocVipuskProd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="SBKOMPL")
		{
		IFormaDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSborkaKompl.1",IID_IFormaDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RASBKOMPL")
		{
		IFormaDocRasborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRasborkaKompl.1",IID_IFormaDocRasborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="ZAMENA")
		{
		IFormaDocZamena * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocZamena.1",IID_IFormaDocZamena,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="KORRVS")
		{
		IFormaDocKorrVS * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocKorrVS.1",IID_IFormaDocKorrVS,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="VIPBANK")
		{
		IFormaDocVipBanka * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVipBanka.1",IID_IFormaDocVipBanka,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
				if (!doc) return;
//		doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_ADVCUST")
		{
		IFormaDocRegAdvCust * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegAdvCust.1",IID_IFormaDocRegAdvCust,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_BANK")
		{
		IFormaDocRegBank * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegBank.1",IID_IFormaDocRegBank,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
	   //	doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_GOODS")
		{
		IFormaDocRegGoods * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegGoods.1",IID_IFormaDocRegGoods,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		}


if(DM->TableTDOC->AsString=="RG_KASSA")
		{
		IFormaDocRegKassa * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegKassa.1",IID_IFormaDocRegKassa,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_OSTNOM")
		{
		IFormaDocRegOstNom * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegOstNom.1",IID_IFormaDocRegOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_PAYSALE")
		{
		IFormaDocRegPaySale * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegPaySale.1",IID_IFormaDocRegPaySale,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_VSRASCH")
		{
		IFormaDocRegVsRasch * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegVsRasch.1",IID_IFormaDocRegVsRasch,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="RG_CARDBAL")
		{
		IFormaDocRegCardBalance * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegCardBalance.1",IID_IFormaDocRegCardBalance,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}

if(DM->TableTDOC->AsString=="OTCHPOST")
		{
		IFormaDocOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocOtchetPost,IID_IFormaDocOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}


if(DM->TableTDOC->AsString=="RG_OTCHPOST")
		{
		IFormaDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocRegOtchetPost,IID_IFormaDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->UpdateForm();
		//doc->NumberProcVibor=ER_Doc;
		}


}
//----------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::FormResize(TObject *Sender)
{


StrOtborLabel->Left=cxGrid1->Left+cxGrid1->Width-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TFormaGurAllDoc::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TFormaGurAllDoc::DeleteDoc(void)
{

//******************************************************
if(DM->TableTDOC->AsString=="PRN")
        {
		IDMDocPrihNakl * PN;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&PN);
		PN->Init(InterfaceMainObject,InterfaceImpl);
		if (!PN) return;
        //настройка формы
		PN->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Приходная накладная №"
        +PN->DocAllNUMDOC->AsString+" от "+PN->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (PN->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+PN->TextError);
                        }


	PN->kanRelease();
		return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="CHK")
        {
		IDMDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
        if (!Check) return;
        //настройка формы
		Check->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Чек ККМ №"
        +Check->DocAllNUMDOC->AsString+" от "+Check->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (Check->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+Check->TextError);
                        }

		Check->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="PER")
        {
		IDMDocPer * Per;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&Per);
		Per->Init(InterfaceMainObject,InterfaceImpl);
        if (!Per) return;
        //настройка формы
		Per->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Перемещение №"
        +Per->DocAllNUMDOC->AsString+" от "+Per->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (Per->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+Per->TextError);
                        }

		Per->kanRelease();
        return;
        }

//******************************************************
if(DM->TableTDOC->AsString=="INV")
        {
		IDMDocInv * Inv;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv,
													(void**)&Inv);
		Inv->Init(InterfaceMainObject,InterfaceImpl);
        if (!Inv) return;
        //настройка формы
		Inv->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Инвентаризация №"
        +Inv->DocAllNUMDOC->AsString+" от "+Inv->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (Inv->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
                        ShowMessage("Не удалось удалить документ! Ошибка: " +Inv->TextError);
                        }

		Inv->kanRelease();
		return;
		}
//******************************************************
//******************************************************
if(DM->TableTDOC->AsString=="OSN")
        {
		IDMDocOstNom * Ost;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstNom.1",IID_IDMDocOstNom,
													(void**)&Ost);
		Ost->Init(InterfaceMainObject,InterfaceImpl);
        if (!Ost) return;
        //настройка формы
		Ost->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Ввод остатков номенклатуры №"
        +Ost->DocAllNUMDOC->AsString+" от "+Ost->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (Ost->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+Ost->TextError);
                        }

		Ost->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="SPN")
		{
		IDMDocSpisNom * DocSpisNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpisNom.1",IID_IDMDocSpisNom,
													(void**)&DocSpisNom);
		DocSpisNom->Init(InterfaceMainObject,InterfaceImpl);
        if (!DocSpisNom) return;
        //настройка формы
		DocSpisNom->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Акт списания номенклатуры №"
        +DocSpisNom->DocAllNUMDOC->AsString+" от "+DocSpisNom->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (DocSpisNom->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+DocSpisNom->TextError);
                        }

		DocSpisNom->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="REPKKM")
        {
		IDMDocRepKKM * DocRepKKM;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRepKKM.1",IID_IDMDocRepKKM,
													(void**)&DocRepKKM);
		DocRepKKM->Init(InterfaceMainObject,InterfaceImpl);
        if (!DocRepKKM) return;
        //настройка формы
		DocRepKKM->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ отчет ККМ №"
        +DocRepKKM->DocAllNUMDOC->AsString+" от "+DocRepKKM->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (DocRepKKM->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ!Ошибка:"+DocRepKKM->TextError);
                        }

		DocRepKKM->kanRelease();
        return;
        }

//******************************************************
if(DM->TableTDOC->AsString=="OSTVS")
        {
		IDMDocOstVs * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstVs.1",IID_IDMDocOstVs,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ корректировка взаиморасчетов №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ!Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="SCHFACT")
        {
		IDMDocSchetFact * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchetFact.1",IID_IDMDocSchetFact,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ счет -фактура №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ!Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="REALROZN")
        {
		IDMDocRealRozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Реализация розн. №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

 //******************************************************
if(DM->TableTDOC->AsString=="PKOROZN")
        {
		IDMDocPKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Приход нал. №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="RKOROZN")
        {
		IDMDocRKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKORozn.1",IID_IDMDocRKORozn,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Расход нал. №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="RKO")
        {
		IDMDocRKO * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKO.1",IID_IDMDocRKO,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Расходный кассовый ордер №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }
//******************************************************
if(DM->TableTDOC->AsString=="PKO")
        {
		IDMDocPKO * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKO.1",IID_IDMDocPKO,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Приходный кассовый ордер №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
        return;
        }

//******************************************************
if(DM->TableTDOC->AsString=="REA")
        {
		IDMDocReal * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocReal.1",IID_IDMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Реализация №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
                        }

		doc->kanRelease();
		return;
		}
//******************************************************
if(DM->TableTDOC->AsString=="SCH")
		{
		IDMDocSchet * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchet.1",IID_IDMDocSchet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

        String V="Вы действительно хотите удалить документ Счет на оплату №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }

				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

	doc->kanRelease();
		return;
		}


//******************************************************
if(DM->TableTDOC->AsString=="VPOK")
		{
		IDMDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Возврат от покупателя №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }

				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}


//******************************************************
if(DM->TableTDOC->AsString=="VPO")
		{
		IDMDocVosvratPost * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPost.1",IID_IDMDocVosvratPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Возврат поставщику №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}
//******************************************************
if(DM->TableTDOC->AsString=="SPOTROST")
		{
		IDMDocSpOtrOst * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpOtrOst.1",IID_IDMDocSpOtrOst,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Списание отр. остатков №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

	doc->kanRelease();
		return;
		}


		//******************************************************
if(DM->TableTDOC->AsString=="ISMPRICE")
		{
		IDMDocIsmPrice * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocIsmPrice.1",IID_IDMDocIsmPrice,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Переоценка №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }

				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}



//******************************************************
if(DM->TableTDOC->AsString=="REV")
		{
		IDMDocRev * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRev.1",IID_IDMDocRev,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Ревизия №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}



//******************************************************
if(DM->TableTDOC->AsString=="VIPPROD")
		{
		IDMDocVipuskProd * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipuskProd.1",IID_IDMDocVipuskProd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Выпуск продукции №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}


//******************************************************
if(DM->TableTDOC->AsString=="PLP")
		{
		IDMDocPlP * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPLP.1",IID_IDMDocPlP,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Платежное поручение №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************
if(DM->TableTDOC->AsString=="PNS")
		{
		IDMDocPostNaSchet * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPostNaSchet.1",IID_IDMDocPostNaSchet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Поступление на счет №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************
if(DM->TableTDOC->AsString=="SBKOMPL")
		{
		IDMDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSborkaKompl.1",IID_IDMDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

        if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Сборка комплекта №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="RASBKOMPL")
		{
		IDMDocRasborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRasborkaKompl.1",IID_IDMDocRasborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Разборка комплекта №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="ZAMENA")
		{
		IDMDocZamena * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocZamena.1",IID_IDMDocZamena,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Замена №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="KORRVS")
		{
		IDMDocKorrVs * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocKorrVS.1",IID_IDMDocKorrVs,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Корректировка взаиморасчетов №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="VIPBANK")
		{
		IDMDocVipBanka * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipBanka.1",IID_IDMDocVipBanka,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Выписка банка №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
                }


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="RG_ADVCUST")
		{
		IDMDocRegAdvCust * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegAdvCust.1",IID_IDMDocRegAdvCust,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Авансы №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************
if(DM->TableTDOC->AsString=="RG_BANK")
		{
		IDMDocRegBank * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegBank.1",IID_IDMDocRegBank,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Банк №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************
if(DM->TableTDOC->AsString=="RG_GOODS")
		{
		IDMDocRegGoods * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegGoods.1",IID_IDMDocRegGoods,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Остатки товаров №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************
if(DM->TableTDOC->AsString=="RG_KASSA")
		{
		IDMDocRegKassa * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegKassa.1",IID_IDMDocRegKassa,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Касса №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="RG_OSTNOM")
		{
		IDMDocRegOstNom * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegOstNom.1",IID_IDMDocRegOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Остатки партий товаров №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="RG_PAYSALE")
		{
		IDMDocRegPaySale * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegPaySale.1",IID_IDMDocRegPaySale,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Оплата реализации №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************


if(DM->TableTDOC->AsString=="RG_VSRASCH")
		{
		IDMDocRegVsRasch * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegVsRasch.1",IID_IDMDocRegVsRasch,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Взаиморасчеты №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

if(DM->TableTDOC->AsString=="RG_RGBALCARD")
		{
		IDMDocRegCardBalance * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegCardBalance.1",IID_IDMDocRegCardBalance,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движения регистра Средства на картах №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************


//******************************************************************************

if(DM->TableTDOC->AsString=="OTCHPOST")
		{
		IDMDocOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOtchetPost,IID_IDMDocOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Отчет Поставщику №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

//******************************************************************************

if(DM->TableTDOC->AsString=="RG_OTCHPOST")
		{
		IDMDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocRegOtchetPost,IID_IDMDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);

		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Движение регистра Отчет поставщику №"
		+doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}


				if (doc->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}

		doc->kanRelease();
		return;
		}

//******************************************************************************

}

//----------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::ToolButtonOpenDvDocClick(TObject *Sender)
{

TReportDvRegDoc * report=new TReportDvRegDoc();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;
report->Init();
if (!report) return;
report->IdDoc=DM->TableIDDOC->AsInt64;
report->CreateReport();
delete report;

}

//---------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::ToolButton3Click(TObject *Sender)
{
if (DM->CancelDvRegDoc(Trim(DM->TableTDOC->AsString), DM->TableIDDOC->AsInt64)==true)
	{
	DM->UpdateTable();
	}
else
	{
    ShowMessage("Не удалось отменить проведение документа. Ошибка: "+DM->TextError);
	}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::ToolButtonViborPeriodaClick(
      TObject *Sender)
{
if (FormaViborPerioda==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",IID_IFormaViborPerioda,
													(void**)&FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborPerioda->NumberProcVibor=ER_Period;
		FormaViborPerioda->PosNach=PosNach;
		FormaViborPerioda->PosCon=PosCon;
//        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
//		FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurAllDoc::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonAllCancelDvRegClick(
      TObject *Sender)
{
        String V="Вы действительно хотите отменить проведение всех документов?";
        String Z="Подтверждение отмены проведения";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->Last();
TFormIndicator * FormIndicator=new TFormIndicator(Application);
FormIndicator->Max=DM->Table->RecordCount;
FormIndicator->Step=1;
FormIndicator->LabelInfo->Caption="Отмена проведения документов...";
FormIndicator->Start();
FormIndicator->Show();

DM->DataSourceTable->Enabled=false;

DM->Table->First();

while(!DM->Table->Eof)
        {

        try
                {
				if (DM->CancelDvRegDoc(Trim(DM->TableTDOC->AsString), DM->TableIDDOC->AsInt64)!=true)
                        {

                        V="Не удалось отменить проведение документа "+
                                glGetNameDoc(DM->TableTDOC->AsString)+
                                "  №"+DM->TableNUMDOC->AsString+
                                " от "+DM->TablePOSDOC->AsString +" Продолжить?";
                        Z="Ошибка отмены проведения документа!";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                 break;
                                }
                        }
                }
        catch (Exception &exception)
                {

                V="Ошибка при  отмене проведения документа \n"+
                glGetNameDoc(DM->TableTDOC->AsString)+"  №"+DM->TableNUMDOC->AsString+
                " от "+DM->TablePOSDOC->AsString+
                "  "+exception.Message +" Продолжить?";
                Z="Ошибка отмены проведения документа!";
                if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                        {
                        break;
                        }

                }
        FormIndicator->StepIt();
        DM->Table->Next();
        }
DM->DataSourceTable->Enabled=true;


IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceImpl);
DMSetup->OpenElement(15);
if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
else
        {

				if (DMSetup->GetKolProvDoc(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat)==0)
                        {
                        DMSetup->Element->Edit();
						DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsString="";
                        DMSetup->Element->Post();
                        DMSetup->SaveElement();
                        }
        }

DMSetup->kanRelease();
DM->UpdateTable();
delete FormIndicator;
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonDvRegDocClick(TObject *Sender)
{
        String V="Вы действительно хотите провести все документы?";
        String Z="Подтверждение  проведения документов";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->First();
//проверим будет ли восстановлена последовательность
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceImpl);
DMSetup->OpenElement(15);
if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
else
        {
		if (DM->PosNach > DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
                {

                        V= "Граница последовательности меньше позиции начала  журнала! \n";
                        V=V+"Последовательность восстановлена не будет! Продолжить? ";
                        Z="Проведение документов";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                delete DMSetup; return;
                                }
                }
        }
//int kol_prov_doc=DMSetup->GetKolProvDoc(DM->TablePOSDOC->AsDateTime) ;
if (DMSetup->GetKolProvDoc(DM->PosNach)!=0)
        {
        V="Существуют более поздние проведенные документы! Последовательность восстановлена не будет! Продолжить? \n";
        Z="Проведение документов";
		DM->IBQ->Close();
		DM->IBQ->SelectSQL->Clear();
		DM->IBQ->SelectSQL->Add("select TDOC, NUMDOC, POSDOC from GALLDOC where PRDOC>0  AND POSDOC>:PARAM_POSDOC");
		DM->IBQ->SelectSQL->Add(" AND TDOC in ("+glGetStringFullTypeDoc()+" ) ");
        DM->IBQ->ParamByName("PARAM_POSDOC")->AsDateTime=DM->PosNach;
        DM->IBQ->Active=true;
        int kol=0;

        DM->IBQ->First();
        while(!DM->IBQ->Eof && kol<3)
                {
                V=V+glGetNameDoc(Trim(DM->IBQ->FieldByName("TDOC")->AsString))
                        +" №"+DM->IBQ->FieldByName("NUMDOC")->AsString
                        +" от "+DM->IBQ->FieldByName("POSDOC")->AsString+"\n";
                DM->IBQ->Next(); kol++;
                }
        DM->IBQ->Active=false;
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                delete DMSetup; return;
                }
		}
else  //будет восстановлена последовательность
	{ 
	DMSetup->OpenElement(15);
	if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
	else
        {

				if (DMSetup->GetKolProvDoc(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)==0)
                        {
                        DMSetup->Element->Edit();
                        DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsString="";
                        DMSetup->Element->Post();
                        DMSetup->SaveElement();
                        }
		}
	}

DMSetup->kanRelease();

DM->Table->Last();
TFormIndicator * FormIndicator=new TFormIndicator(Application);
FormIndicator->Max=DM->Table->RecordCount;
FormIndicator->Step=1;
FormIndicator->Caption="Проведение документов...";
FormIndicator->Start();
FormIndicator->Show();

DM->DataSourceTable->Enabled=false;

DM->Table->First();
while(!DM->Table->Eof)
        {
        try
                {
				if (DM->DvRegDoc(Trim(DM->TableTDOC->AsString), DM->TableIDDOC->AsInt64)!=true)
                        {

                        V="Не удалось провести документ "+
                                glGetNameDoc(DM->TableTDOC->AsString)+
                                "  №"+DM->TableNUMDOC->AsString+
                                " от "+DM->TablePOSDOC->AsString +" Продолжить?";
                        Z="Ошибка проведения документа!";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                 break;
                                }
                        }
                }
        catch (Exception &exception)
                {

                V="Ошибка при  проведении документа \n"+
                glGetNameDoc(DM->TableTDOC->AsString)+"  №"+DM->TableNUMDOC->AsString+
                " от "+DM->TablePOSDOC->AsString+
                "  "+exception.Message +" Продолжить?";
                Z="Ошибка проведения документа!";
                if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                        {
                        break;
                        }

                }
        FormIndicator->StepIt();
        DM->Table->Next();
        }
        
DM->DataSourceTable->Enabled=true;
DM->UpdateTable();
delete FormIndicator;
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonDelAllDocClick(TObject *Sender)
{
        String V="Вы действительно хотите удалить все документы?";
        String Z="Подтверждение удаления";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->First();
while (!DM->Table->Eof)
        {
        DeleteAllDoc();
        DM->Table->Next();
        }

DM->UpdateTable();
}
//---------------------------------------------------------------------------
void TFormaGurAllDoc::DeleteAllDoc(void)
{
if(DM->TableTDOC->AsString=="PRN")  //приход. накл.
        {
		IDMDocPrihNakl * PN;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl, (void**)&PN);
		PN->Init(InterfaceMainObject,InterfaceImpl);
        if (!PN) return;
        //настройка формы
		PN->OpenDoc(DM->TableIDDOC->AsInt64);
		PN->DeleteDoc(DM->TableIDDOC->AsInt64);
		PN->kanRelease();
        }

if(DM->TableTDOC->AsString=="CHK")   //чек ккм
        {
		IDMDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck, (void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
        if (!Check) return;
        //настройка формы
		Check->OpenDoc(DM->TableIDDOC->AsInt64);
		Check->DeleteDoc(DM->TableIDDOC->AsInt64);
		Check->kanRelease();
        }

if(DM->TableTDOC->AsString=="PER")      //перемещение
        {
		IDMDocPer * Per;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer, (void**)&Per);
		Per->Init(InterfaceMainObject,InterfaceImpl);
        if (!Per) return;
        //настройка формы
		Per->OpenDoc(DM->TableIDDOC->AsInt64);
		Per->DeleteDoc(DM->TableIDDOC->AsInt64);
		Per->kanRelease();
        }

        
if(DM->TableTDOC->AsString=="INV")          //инвентаризация
        {
		IDMDocInv * Inv;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv, (void**)&Inv);
		Inv->Init(InterfaceMainObject,InterfaceImpl);
        if (!Inv) return;
        //настройка формы
		Inv->OpenDoc(DM->TableIDDOC->AsInt64);
		Inv->DeleteDoc(DM->TableIDDOC->AsInt64);
		Inv->kanRelease();
        }


if(DM->TableTDOC->AsString=="OSN")
        {
		IDMDocOstNom * Ost;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstNom.1",IID_IDMDocOstNom, (void**)&Ost);
		Ost->Init(InterfaceMainObject,InterfaceImpl);
        if (!Ost) return;
        //настройка формы
		Ost->OpenDoc(DM->TableIDDOC->AsInt64);
		Ost->DeleteDoc(DM->TableIDDOC->AsInt64);
		Ost->kanRelease();
        }

if(DM->TableTDOC->AsString=="SPN")
        {
		IDMDocSpisNom * DocSpisNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DocSpisNom.1",IID_IDMDocSpisNom, (void**)&DocSpisNom);
		DocSpisNom->Init(InterfaceMainObject,InterfaceImpl);
        if (!DocSpisNom) return;
        //настройка формы
		DocSpisNom->OpenDoc(DM->TableIDDOC->AsInt64);
		DocSpisNom->DeleteDoc(DM->TableIDDOC->AsInt64);

		DocSpisNom->kanRelease();
        }

if(DM->TableTDOC->AsString=="OSTVS")
        {
		IDMDocOstVs * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstVs.1",IID_IDMDocOstVs, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="SCHFACT")
        {
		IDMDocSchetFact * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchetFact.1",IID_IDMDocSchetFact, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
        }


if(DM->TableTDOC->AsString=="REALROZN")
        {
		IDMDocRealRozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="PKOROZN")
        {
		IDMDocPKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        if (!doc) return;
        //настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
        }


if(DM->TableTDOC->AsString=="RKOROZN")
		{
		IDMDocRKORozn * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKORozn.1",IID_IDMDocRKORozn, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="VPOK")
		{
		IDMDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="SPOTROST")
		{
		IDMDocSpOtrOst * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpOtrOst.1",IID_IDMDocSpOtrOst, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="ISMPRICE")
		{
		IDMDocIsmPrice * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocIsmPrice.1",IID_IDMDocIsmPrice, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="REV")
		{
		IDMDocRev * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRev.1",IID_IDMDocRev, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="VIPPROD")
		{
		IDMDocVipuskProd * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipuskProd.1",IID_IDMDocVipuskProd, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="SBKOMPL")
		{
		IDMDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSborkaKompl.1",IID_IDMDocSborkaKompl, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RASBKOMPL")
		{
		IDMDocRasborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRasborkaKompl.1",IID_IDMDocRasborkaKompl, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="ZAMENA")
		{
		IDMDocZamena * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocZamena.1",IID_IDMDocZamena, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="KORRVS")
		{
		IDMDocKorrVs * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocKorrVS.1",IID_IDMDocKorrVs, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);

		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="VIPBANK")
		{
		IDMDocVipBanka * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipBanka.1",IID_IDMDocVipBanka, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);  
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_ADVCUST")
		{
		IDMDocRegAdvCust * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegAdvCust.1",IID_IDMDocRegAdvCust, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_BANK")
		{
		IDMDocRegBank * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegBank.1",IID_IDMDocRegBank, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_GOODS")
		{
		IDMDocRegGoods * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegGoods.1",IID_IDMDocRegGoods, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_KASSA")
		{
		IDMDocRegKassa * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegKassa.1",IID_IDMDocRegKassa, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_OSTNOM")
		{
		IDMDocRegOstNom * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegOstNom.1",IID_IDMDocRegOstNom, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_PAYSALE")
		{
		IDMDocRegPaySale * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegPaySale.1",IID_IDMDocRegPaySale, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_VSRASCH")
		{
		IDMDocRegVsRasch * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegVsRasch.1",IID_IDMDocRegVsRasch, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}

if(DM->TableTDOC->AsString=="RG_CARDBAL")
		{
		IDMDocRegCardBalance * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegCardBalance.1",IID_IDMDocRegCardBalance, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}


if(DM->TableTDOC->AsString=="OTCHPOST")
		{
		IDMDocOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOtchetPost,IID_IDMDocOtchetPost, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}


if(DM->TableTDOC->AsString=="RG_OTCHPOST")
		{
		IDMDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocRegOtchetPost,IID_IDMDocRegOtchetPost, (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableIDDOC->AsInt64);
		doc->DeleteDoc(DM->TableIDDOC->AsInt64);
		doc->kanRelease();
		}


}
//--------------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonOtborClick(TObject *Sender)
{

AnsiString s="";
if (ToolButtonOtbor->Down==true)  // включить отбор
        {
        DM->OtborVkl=true;

                        if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
                        if (IdFirm>0) s=s+" Фирма: "+NameFirm;
                        if (IdSklad>0) s=s+" Склад: "+NameSklad;
                        if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
                        StrOtborLabel->Caption=s;
        }
else
        {
        DM->OtborVkl=false;
        StrOtborLabel->Caption=s;
        }

DM->IdKlient=IdKlient;
DM->IdSklad=IdSklad;
DM->IdFirm=IdFirm;
DM->StringTypeDoc=StringTypeDoc;

//DM->OtborPoKlient=OtborPoKlientu;
//DM->OtborPoFirm=OtborPoFirm;
//DM->OtborPoSklad=OtborPoSklad;
//DM->OtborPoTypeDoc=OtborPoTypeDoc;
UpdateForm();


}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonParamOtborClick(TObject *Sender)
{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSetupOtbor.1",IID_IFormaSetupOtbor,
													(void**)&FormaSetupOtbor);
		FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
        if (!FormaSetupOtbor ) return;
        //FormaSetupOtbor->IdRodForm=Handle;
		//IdDochForm=FormaSetupOtbor ->Handle;
		//ViborRekv=SetupOtborRekv;
		FormaSetupOtbor->NumberProcVibor=ER_Otbor;

}
//---------------------------------------------------------------------------


void __fastcall TFormaGurAllDoc::ToolButtonNoCheckClick(TObject *Sender)
{
if (ToolButtonNoCheck->Down==true)  // без чеков
        {
        DM->NoCheck=true;
        }
else
        {
        DM->NoCheck=false;
        }

DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurAllDoc");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TFormaGurAllDoc::OpenPrintForm(void)
{
ISheetEditor *  PrintForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1", IID_ISheetEditor,
																	(void**)&PrintForm);

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
SumReport=0;
DM->Table->First();
while(!DM->Table->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;
        SumReport=SumReport+DM->TableSUMDOC->AsFloat;
        DM->Table->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();
}
//---------------------------------------------------------------------------
void TFormaGurAllDoc::OutputZagolovokReport(ISheetEditor *prForm)
{
prForm->SetColumnWidth(0,20);
prForm->SetColumnWidth(1,30);
prForm->SetColumnWidth(2,120);
prForm->SetColumnWidth(3,80);
prForm->SetColumnWidth(4,80);
prForm->SetColumnWidth(5,50);
prForm->SetColumnWidth(6,100);
prForm->SetColumnWidth(7,100);
prForm->SetColumnWidth(8,80);
prForm->SetColumnWidth(9,100);


prForm->DefaultFontSize=8;


numRow=1;
numCol=2;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Реестр документов с "+DateTimeToStr(PosNach)+" по "
				+DateTimeToStr(PosCon));
prForm->TecCell_SetFontSize(16);
prForm->TecCell_DeleteObject();
numRow++; numRow++;


//заголовок таблицы
numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("№");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Дата");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Фирма");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Документ");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Номер");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Склад");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Клиент");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Сумма");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Автор");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
}
//------------------------------------------------------------------------------
void TFormaGurAllDoc::OutputString(ISheetEditor *prForm)
{
numCol=1;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(porNumStr);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TablePOSDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMEFIRM->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(glGetNameDoc(DM->TableTDOC->AsString));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNUMDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMESKLAD->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMEKLIENT->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAME_USER->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
}


//------------------------------------------------------------------------------
void TFormaGurAllDoc::OutputPodavalReport(ISheetEditor *prForm)
{
//
numRow++;
numCol=1;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Всего документов :"+IntToStr(porNumStr-1)+" на сумму "
				+FloatToStr(SumReport)+"руб.");
prForm->TecCell_DeleteObject();


}
//----------------------------------------------------------------------------
void __fastcall TFormaGurAllDoc::ToolButton5Click(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurAllDoc::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}
else
	{
	OpenFormDoc();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaGurAllDoc::cxGrid1DBTableView1PRDOCCustomDrawCell(
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

void __fastcall TFormaGurAllDoc::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
			{
			TypeEvent=1;
			Close();
			}
		else
			{
			OpenFormDoc();
			}
		}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaGurAllDoc::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaGurAllDoc::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();

//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableIDDOC->AsString));

module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
