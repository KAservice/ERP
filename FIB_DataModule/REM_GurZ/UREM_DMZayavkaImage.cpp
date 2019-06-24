//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UREM_DMZayavkaImage.h"

//#include "UDMSetup.h"
//#include "UDMQueryUpdate.h"
#include "IDMQueryRead.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------

__fastcall TREM_DMZayavkaImage::TREM_DMZayavkaImage(TComponent* Owner)
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
bool TREM_DMZayavkaImage::Init(void)
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
Element->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//----------------------------------------------------------------------------
int TREM_DMZayavkaImage::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMZayavkaImage::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_DMZayavkaImage::OpenTable(__int64 id_z)
{
Table->Active=false;
Table->ParamByName("PARAM_IDZ")->AsString=id_z;
Table->Open();
}

//---------------------------------------------------------------------------

bool  TREM_DMZayavkaImage::NewElement(__int64 id_z)
{
bool result=false;
Element->Active=false;


		Element->Open();
		Element->Insert();
		ElementIDZ_REM_ZIMAGE->AsString=id_z;

		result=true;

return result;
}
//---------------------------------------------------------------------------

int TREM_DMZayavkaImage::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int result=0;
result=Element->RecordCount;
return result;
}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool  TREM_DMZayavkaImage::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_REM_ZIMAGE->AsString);

try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(IdElement);
        res=true;
        }
catch(Exception &exception)
        {
		TextError=exception.Message;
		//ShowMessage(TextError);
        }

return res;
}
//---------------------------------------------------------------------------
bool TREM_DMZayavkaImage::DeleteElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------

