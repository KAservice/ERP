//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprOborud.h"
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
__fastcall TDMSprOborud::TDMSprOborud(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
}

//---------------------------------------------------------------------------
bool TDMSprOborud::Init(void)
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

	DM_Connection->GetPrivDM(GCPRIV_DM_SprOborud);
	ExecPriv=DM_Connection->ExecPriv;
	InsertPriv=DM_Connection->InsertPriv;
	EditPriv=DM_Connection->EditPriv;
	DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMSprOborud::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprOborud::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprOborud::OpenTable(__int64 id_kkm)
{
IdKKM=id_kkm;
Table->Active=false;
Table->ParamByName("PARAM_IDARM")->AsInt64=id_kkm;
Table->Open();
}
//--------------------------------------------------------------------------
void TDMSprOborud::OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud)
{
IdKKM=id_kkm;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add("select  SOBORUD.* from SOBORUD");
Table->SelectSQL->Add(" where IDARM_SOBORUD=:PARAM_IDARM and TYPE_OBORUD=:PARAM_TYPE");
Table->ParamByName("PARAM_IDARM")->AsInt64=id_kkm;
Table->ParamByName("PARAM_TYPE")->AsString=type_oborud;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprOborud::NewElement(__int64 id_kkm)
{
IdKKM=id_kkm;
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprOborud::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID_OBORUD")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprOborud::SaveElement()
{
bool res=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        res=true;
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				CodeError=1;
				TextError=exception.Message;
				}
return res;
}
//---------------------------------------------------------------------------
void TDMSprOborud::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID_OBORUD")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				CodeError=1;
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------
UnicodeString TDMSprOborud::GetParameter(UnicodeString parameter)
{
UnicodeString str_parameter=ElementSTRPAR_SOBORUD->AsString;
UnicodeString result="";
int position=0;
position=str_parameter.Pos(parameter);
if (position!=0)
        {
        str_parameter.Delete(1,position+parameter.Length());
        for(int i=1; i<=str_parameter.Length();i++)
                {
                if (str_parameter[i]==';')
                        {
                         break;
                        }
                else
                        {
                         result=result+str_parameter[i];
                        }
                }
        }
return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprOborud::ElementNewRecord(TDataSet *DataSet)
{
ElementIDARM_SOBORUD->AsString=IdKKM;
}
//---------------------------------------------------------------------------
UnicodeString TDMSprOborud::GetParameterPoTable(UnicodeString parameter)
{
UnicodeString str_parameter=TableSTRPAR_SOBORUD->AsString;
UnicodeString result="";
int position=0;
position=str_parameter.Pos(parameter);
if (position!=0)
        {
        str_parameter.Delete(1,position+parameter.Length());
        for(int i=1; i<=str_parameter.Length();i++)
                {
                if (str_parameter[i]==';')
                        {
                         break;
                        }
                else
                        {
                         result=result+str_parameter[i];
                        }
                }
        }
return result;
}
//-----------------------------------------------------------------------------


