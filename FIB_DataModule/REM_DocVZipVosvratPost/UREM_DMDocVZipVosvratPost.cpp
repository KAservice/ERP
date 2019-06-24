//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UREM_DMDocVZipVosvratPost.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMTableNumberDoc.h"
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
__fastcall TREM_DMDocVZipVosvratPost::TREM_DMDocVZipVosvratPost(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------

bool TREM_DMDocVZipVosvratPost::Init(void)
{
bool result=false;


if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы дл€ создани€ новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;
IBTrDvReg->DefaultDatabase=DM_Connection->pFIBData;

DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;

NumDoc->Database=DM_Connection->pFIBData;

pFIBQ->Database=DM_Connection->pFIBData;

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMDocVZipVosvratPost::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocVZipVosvratPost::DataModuleDestroy(TObject *Sender)
{

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

bool TREM_DMDocVZipVosvratPost::NewDoc(void)
{
bool result=false;
flGetNumberDoc=false;

try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->Active=true;
	Doc->Active=true;
	DocT->Active=true;

	DocAll->Append();
	Doc->Append();

	IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);



	DocAllPOS_REM_GALLDOC->AsDateTime=Now();
	DocAllTDOC_REM_GALLDOC->AsString="REM_VZVPO";
	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
		{
		DocAllIDUSER_REM_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
		{
		DocAllIDFIRM_REM_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
		DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
		{
		DocAllIDSKLAD_REM_GALLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
		DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
		{
		DocAllIDBASE_REM_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
		DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
		}


	DocAll->Post();

    flGetNumberDoc=true;
	DocAll->Edit();
	GetNumberNewDoc();
	DocAll->Post();


	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;

	}
	
return result;
}
//---------------------------------------------------------------------------
int TREM_DMDocVZipVosvratPost::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRM_REM_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=DocAllIDSKLAD_REM_GALLDOC->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_REM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUM_REM_GALLDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUM_REM_GALLDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
bool TREM_DMDocVZipVosvratPost::OpenDoc(__int64 id)
{
bool result=false;

try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->ParamByName("PARAM_IDDOC")->AsInt64=id;
	Doc->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocAll->Active=true;
	Doc->Active=true;


	DocT->ParamByName("PARAM_IDDOC")->AsInt64=id;
	//DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE->AsInt64;
	DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
	Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

	DocAllIDBASE_REM_GALLDOC->ReadOnly=true;

	IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
	result=false;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
	
return result;
}
//-----------------------------------------------------------------------------
void TREM_DMDocVZipVosvratPost::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TREM_DMDocVZipVosvratPost::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TREM_DMDocVZipVosvratPost::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return Res;
		}
		


try
        {
		IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();
        Res=true;
        OpenDoc(IdDoc);
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Res=false;
				TextError=exception.Message;
				}

return Res;
}

//---------------------------------------------------------------------------
bool TREM_DMDocVZipVosvratPost::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
		}


try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryDvReg->ExecProc();
				IBTrDvReg->Commit();

                result=true;
                }
        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}


QueryDvReg->Close();
return result;
}

//---------------------------------------------------------------------------
bool TREM_DMDocVZipVosvratPost::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
		}
try
		{
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryCancelDvReg->ExecProc();
				IBTrDvReg->Commit();

//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;

				result=true;

		}
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}
				
QueryCancelDvReg->Close();
return result;
}

//---------------------------------------------------------------------------

bool TREM_DMDocVZipVosvratPost::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}



try
        {
        if (CancelDvRegDoc()!=true)
                {
                res=false;
                return res;
                }

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

        DocT->ApplyUpdates();
        Doc->ApplyUpdates();
        DocAll->ApplyUpdates();
		IBTrUpdate->Commit();
        res=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				res=false;
				TextError=exception.Message;
				}
return res;

}

//---------------------------------------------------------------------------
void __fastcall TREM_DMDocVZipVosvratPost::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DVZVPO->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DVZVPO->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_DMDocVZipVosvratPost::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DVZVPOT->AsString=DocAllID_REM_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_REM_DVZVPOT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocVZipVosvratPost::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------




void __fastcall TREM_DMDocVZipVosvratPost::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocVZipVosvratPost::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)
{
	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_REM_DVZVPO->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		Doc->Post();
		}

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_DVZVPOT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
}
//---------------------------------------------------------------------------


