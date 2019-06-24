//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprSezKF.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
__fastcall TDMSprSezKF::TDMSprSezKF(TComponent* Owner)
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
bool TDMSprSezKF::Init(void)
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
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;


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
int TDMSprSezKF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprSezKF::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprSezKF::OpenTable(__int64 Nom)
{
IdNom=Nom;
Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=Nom;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprSezKF::NewElement(__int64 Nom)
{
IdNom=Nom;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprSezKF::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		if (IBTrUpdate->Active==true) IBTrUpdate->Commit();
		OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
			  //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSprSezKF::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMSprSezKF::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------


void __fastcall TDMSprSezKF::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_SSEZKF->AsInt64=IdNom;
}
//---------------------------------------------------------------------------

