//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprImportSet.h"
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
__fastcall TDMSprImportSet::TDMSprImportSet(TComponent* Owner)
        : TDataModule(Owner)
{
TypeObr=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprImportSet::Init(void)
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
int TDMSprImportSet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprImportSet::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprImportSet::OpenTable()
{
Table->Active=false;
if (TypeObr!=0)
	{
	Table->SelectSQL->Clear();
	Table->SelectSQL->Add("select  * from SIMPORTSET");
	Table->SelectSQL->Add(" where TYPE_OBR_SIMPORTSET="+IntToStr(TypeObr));
	} 
Table->Open();

}

//---------------------------------------------------------------------------

bool  TDMSprImportSet::NewElement()
{
bool result=false;
try
	{
	Element->Active=false;
	Element->Open();
	Element->Append();
	if (TypeObr!=0)
		{
		ElementTYPE_OBR_SIMPORTSET->AsInteger=TypeObr;
		Element->Post();
		}

	}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------

int TDMSprImportSet::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprImportSet::SaveElement()
{
bool result;
try
		{
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;

		}
		catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprImportSet::CloseElement()
{

        Element->CancelUpdates();
        IBTr->Rollback();   
}
//---------------------------------------------------------------------------
bool TDMSprImportSet::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
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
				Error=true;
				TextError=exception.Message;
				result=false;
				}
		}
		
return result;
}
//---------------------------------------------------------------------------

__int64 TDMSprImportSet::GetIDElement(String gid)
{
int res=0;

//		if (gid!="" || gid!=" " )
//				{
//				pFIBQ->Close();
//				pFIBQ->SQL->Clear();
//				pFIBQ->SQL->Add("select IDSKLAD from SSKLAD where GID_SSKLAD=:PARAM_GID");
//				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
//				pFIBQ->ExecQuery();
//				if (pFIBQ->RecordCount==1)
//						{
//						res=pFIBQ->FieldByName("IDSKLAD")->AsInt64;
//						}
//				else res=0;
//				}
//				pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprImportSet::GetGIDElement(__int64 id)
{
AnsiString res=0;

//		if (id!=0 )
//				{
//				pFIBQ->Close();
//				pFIBQ->SQL->Clear();
//				pFIBQ->SQL->Add("select GID_SSKLAD from SSKLAD where IDSKLAD=:PARAM_ID");
//				pFIBQ->ParamByName("PARAM_ID")->AsInt64=id;
//				pFIBQ->ExecQuery();
//				if (pFIBQ->RecordCount==1)
//						{
//						res=Trim(pFIBQ->FieldByName("GID_SSKLAD")->AsString);
//						}
//				else res="";
//				pFIBQ->Close();
//				}



return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprImportSet::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int TDMSprImportSet::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
//int index=0;
//Table->First();
//while(!Table->Eof)
//	{
//	if(TableIDSKLAD->AsInteger==id)
//		{
//		result=index+1;
//		break;
//		}
//	index++;
//	Table->Next();
//	}
return result;
}
//----------------------------------------------------------------------------
AnsiString TDMSprImportSet::GetParameter(AnsiString parameter)
{
AnsiString str_parameter=ElementSTRPAR_SIMPORTSET->AsString;
AnsiString result="";
int position=0;
position=str_parameter.AnsiPos(parameter);
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
