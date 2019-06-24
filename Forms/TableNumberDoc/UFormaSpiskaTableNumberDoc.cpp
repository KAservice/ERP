//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaTableNumberDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMQueryRead.h"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckGroup"
#pragma link "cxRadioGroup"
#pragma link "cxDropDownEdit"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaTableNumberDoc::TFormaSpiskaTableNumberDoc(TComponent* Owner)
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
bool TFormaSpiskaTableNumberDoc::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;



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
int TFormaSpiskaTableNumberDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaTableNumberDoc::FormClose(TObject *Sender,
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

void __fastcall TFormaSpiskaTableNumberDoc::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table->Delete();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaTableNumberDoc::ToolButtonNewClick(TObject *Sender)
{
DM->Table->Insert();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaTableNumberDoc::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
        Close();
        }
else
        {
        }	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaTableNumberDoc::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaTableNumberDoc::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaTableNumberDoc::ActionSaveExecute(TObject *Sender)
{
DM->SaveIsmen();
}
//---------------------------------------------------------------------------
int TFormaSpiskaTableNumberDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaTableNumberDoc::DeleteElement()
{



}
 //--------------------------------------------------------------------------

void __fastcall TFormaSpiskaTableNumberDoc::ToolButtonAddAllDocClick(TObject *Sender)

{


AddDocInTable("CHK");
AddDocInTable("PRN");
AddDocInTable("SCH");
AddDocInTable("OSN");
AddDocInTable("PER");
AddDocInTable("REA");
AddDocInTable("SPN");
AddDocInTable("VPO");
AddDocInTable("PKO");
AddDocInTable("RKO");
AddDocInTable("PLP");
AddDocInTable("PNS");
AddDocInTable("REAL_REST");
AddDocInTable("INV");
AddDocInTable("REPKKM");
AddDocInTable("OSTVS");
AddDocInTable("SCHFACT");
AddDocInTable("REALROZN");
AddDocInTable("PKOROZN");
AddDocInTable("RKOROZN");
AddDocInTable("REC_KDR");
AddDocInTable("VPOK");
AddDocInTable("ISMPRICE");
AddDocInTable("SPOTROST");
AddDocInTable("REV");
AddDocInTable("VIPPROD");
AddDocInTable("SBKOMPL");
AddDocInTable("RASBKOMPL");
AddDocInTable("ZAMENA");
AddDocInTable("KORRVS");
AddDocInTable("VIPBANK");
AddDocInTable("OTCHPOST");

//СЛУЖБНЫЕ ДОКУМЕНТЫ
AddDocInTable("RG_ADVCUST");
AddDocInTable("RG_BANK");
AddDocInTable("RG_GOODS");
AddDocInTable("RG_KASSA");
AddDocInTable("RG_OSTNOM");
AddDocInTable("RG_PAYSALE");
AddDocInTable("RG_VSRASCH");
AddDocInTable("RG_CARDBAL");
AddDocInTable("RG_OTCHPOST");

AddDocInTable("REMONT");
AddDocInTable("REMONTHW");
AddDocInTable("REMONTKKT");
AddDocInTable("KM1");
AddDocInTable("KM2");
AddDocInTable("SETSERVKKT");
AddDocInTable("SETSERVHW");
AddDocInTable("REMPRN");
AddDocInTable("REMREAL");
AddDocInTable("REMOSN");
AddDocInTable("REMSBKOMPL");
AddDocInTable("POSTOTDIL");
AddDocInTable("VOSDILERU");
AddDocInTable("PERSC");
AddDocInTable("VOSVISSC");
AddDocInTable("REMVPOK");
AddDocInTable("REMAKT");
AddDocInTable("REMPER");


AddDocInTable("REMZPOST");
AddDocInTable("REMZVID");
AddDocInTable("REMZPER");
AddDocInTable("REMZSTART");
AddDocInTable("REMZEND");
AddDocInTable("REMZOPER");
AddDocInTable("REMZTREB");
AddDocInTable("REMZAKTPR");
AddDocInTable("REMZVZAP");

AddDocInTable("REMSPN");

AddDocInTable("REM_RGOTCHPOST");

AddDocInTable("REM_VIDACHA_HW");
AddDocInTable("REM_VOSVRAT_HW");
AddDocInTable("REM_ZAKPOST");
AddDocInTable("REM_OTPRPOST");



AddDocInTable("REM_VZPER");
AddDocInTable("REM_VZVPO");


DM->OpenTable();
}
//---------------------------------------------------------------------------
void TFormaSpiskaTableNumberDoc::AddDocInTable(UnicodeString type_doc)
{
UnicodeString zapros="select  tnum_doc.id_tnum_doc                         \
							from tnum_doc                                  \
							where tnum_doc.doc_tnum_doc=:PARAM_TDOC";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_TDOC")->AsString=type_doc;
DMQueryRead->pFIBQ->ExecQuery();
__int64 id_rec=0;
id_rec=glStrToInt64(DMQueryRead->pFIBQ->FieldByName("id_tnum_doc")->AsString);
DMQueryRead->kanRelease();

if (id_rec ==0)
	{
	DM->NewElement();
	DM->Element->Edit();
	DM->ElementDOC_TNUM_DOC->AsString=type_doc;
	DM->ElementTYPE_TNUM_DOC->AsInteger=1;
	DM->SaveElement();
	}
}
//-----------------------------------------------------------------------------
