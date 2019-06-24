//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMViborOborud.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMViborOborud::TDMViborOborud(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMViborOborud::Init(void)
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


	DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
	ExecPriv=DM_Connection->ExecPriv;
	InsertPriv=DM_Connection->InsertPriv;
	EditPriv=DM_Connection->EditPriv;
	DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMViborOborud::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMViborOborud::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
 void  TDMViborOborud::OpenTable(__int64 id_arm, AnsiString type_oborud)
{
IdArm=id_arm;
Table->Active=false;
Table->ParamByName("PARAM_IDARM")->AsInt64=id_arm;
Table->ParamByName("PARAM_TYPE")->AsString=type_oborud;
Table->Open();
}
//----------------------------------------------------------------------------

