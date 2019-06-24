//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMGurProverok.h"

//---------------------------------------------------------------------------
#include "IDMSetup.h"


#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//extern AnsiString glGetNameDocRemont(AnsiString str_code_doc);
//---------------------------------------------------------------------------
__fastcall TREM_DMGurProverok::TREM_DMGurProverok(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
OtborVkl=false;
}
//---------------------------------------------------------------------------

bool TREM_DMGurProverok::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMGurProverok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurProverok::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}
//---------------------------------------------------------------------------
void TREM_DMGurProverok::OpenTable()
{
Table->Active=false;

Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TREM_DMGurProverok::UpdateTable(void)
{
IdDoc=glStrToInt64(TableID_REM_GUR_PROV->AsString);
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_REM_GUR_PROV",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}

//-----------------------------------------------------------------------


void __fastcall TREM_DMGurProverok::TableTDOC_REM_GALLDOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
Text=glGetNameDocRemont(TableTDOC_REM_GALLDOC->AsString);
}
//---------------------------------------------------------------------------

