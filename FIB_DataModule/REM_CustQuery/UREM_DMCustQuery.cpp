//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMCustQuery.h"

#include "IDMSprUser.h"
#include "IDMSetup.h"
#include "IREM_DMCustQueryDv.h"
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
__fastcall TREM_DMCustQuery::TREM_DMCustQuery(TComponent* Owner)
		: TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;
}
//-----------------------------------------------------------------
void __fastcall TREM_DMCustQuery::DataModuleCreate(TObject *Sender)
{
//
Prosmotr=false;
flChangeData=false;
}
//----------------------------------------------------------------------------
bool TREM_DMCustQuery::Init(void)
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

Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TREM_DMCustQuery::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMCustQuery::DataModuleDestroy(TObject *Sender)
{
Doc->Close();
DocT->Close();
NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TREM_DMCustQuery::NewDoc(void)
{
       // OpenDoc(0);
		Doc->Active=false;
		DocT->Active=false;

		NumDoc->Active=false;

		Doc->Open();
		Doc->Append();

		IdCQ=glStrToInt64(DocID_REM_CQUERY->AsString);
		DocPOS_REM_CQUERY->AsDateTime=Now();



		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0) DocIDUSER_REM_CQUERY->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;

		DocIDBASE_REM_CQUERY->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
		DocNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;

		DocIDUSER_REM_CQUERY->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;

		DocIDFIRM_REM_CQUERY->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
		DocNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;

		DocIDSKLAD_REM_CQUERY->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
		DocNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;

        //получим номер документа
		NumDoc->Active=false;
        NumDoc->Open();
		DocNUM_REM_CQUERY->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;

		Doc->Post();

		DocT->ParamByName("PARAM_IDCQ")->AsString=IdCQ;
		DocT->Open();



}
//----------------------------------------------------------------------------
void TREM_DMCustQuery::OpenDoc(__int64 id)
{

		Doc->Active=false;
		DocT->Active=false;

		Doc->ParamByName("PARAM_ID")->AsString=id;
		DocT->ParamByName("PARAM_IDCQ")->AsString=id;

		Doc->Open();
		DocT->Open();

		DocIDBASE_REM_CQUERY->ReadOnly=true;
}

//----------------------------------------------------------------------------
void TREM_DMCustQuery::CloseDoc(void)
{
		Doc->CancelUpdates();
		DocT->CancelUpdates();


		Doc->Active=false;
		DocT->Active=false;

}
//----------------------------------------------------------------------------
bool TREM_DMCustQuery::SaveDoc(void)
{
bool Res=false;


try
		{
		IdCQ=glStrToInt64(DocID_REM_CQUERY->AsString);
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();
		OpenDoc(IdCQ);

		AddNewRecordDv();


		Res=true;
		}
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				Res=false;
				}
return Res;
}
//---------------------------------------------------------------------------
bool TREM_DMCustQuery::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);


try
        {

		DocT->First();
		while(!DocT->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				DocT->Delete();
				}

		Doc->Delete();

		DocT->ApplyUpdates();
		Doc->ApplyUpdates();

		IBTrUpdate->Commit();
        res=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				res=false;
				}


return res;

}
//-----------------------------------------------------------------------------




void __fastcall TREM_DMCustQuery::DocTNewRecord(TDataSet *DataSet)
{
DocTIDCQ_REM_CQUERYT->AsString=DocID_REM_CQUERY->AsString;
DocTIDBASE_REM_CQUERYT->AsString=DocIDBASE_REM_CQUERY->AsString ;
}
//---------------------------------------------------------------------------



void __fastcall TREM_DMCustQuery::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------

void TREM_DMCustQuery::AddNewRecordDv(void)
{
if (flChangeData==false) return;

		IREM_DMCustQueryDv * REM_DMCustQueryDv;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQueryDv,IID_IREM_DMCustQueryDv,
													(void**)&REM_DMCustQueryDv);
		REM_DMCustQueryDv->Init(InterfaceMainObject,0);

DocT->First();
while(!DocT->Eof)
	{
	REM_DMCustQueryDv->AddRecordDv(Now(),
						glStrToInt64(DocTID_REM_CQUERYT->AsString),
						glStrToInt64(DocTIDSOST_REM_CQUERYT->AsString),
						glStrToInt64(DM_Connection->UserInfoID_USER->AsString),
						DocTRUN_REM_CQUERYT->AsInteger,
						DocTACT_REM_CQUERYT->AsInteger
						);
	DocT->Next();
	}
	REM_DMCustQueryDv->kanRelease();

}
//установим флаг изменения
//-------------------------------------------------------------------------






void __fastcall TREM_DMCustQuery::DocIDBASE_REM_CQUERYChange(TField *Sender)
{
if(DocT->Active==true)
	{
		DocT->First();
		while(!DocT->Eof)
				{
				DocT->Edit();
				DocTIDBASE_REM_CQUERYT->AsString=DocIDBASE_REM_CQUERY->AsString ;
				DocT->Post();
				DocT->Next();
				}
	}


}
//---------------------------------------------------------------------------

void __fastcall TREM_DMCustQuery::DocTIDSOST_REM_CQUERYTChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMCustQuery::DocTACT_REM_CQUERYTChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMCustQuery::DocTRUN_REM_CQUERYTChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMCustQuery::DocTSROK_POST_REM_CQUERYTChange(TField *Sender)

{
DocTPOS_POST_REM_CQUERYT->AsDateTime=DocPOS_REM_CQUERY->AsDateTime+
									DocTSROK_POST_REM_CQUERYT->AsInteger;
}
//---------------------------------------------------------------------------

