//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMDataSet.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMDataSet::TDMDataSet(TComponent* Owner)
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
bool TDMDataSet::Init(void)
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

Transaction->DefaultDatabase=DM_Connection->pFIBData;
DataSet->Database=DM_Connection->pFIBData;


result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMDataSet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TDMDataSet::DataModuleDestroy(TObject *Sender)
{
DataSet->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
