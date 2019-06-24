//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UREM_DMDocZTreb.h"
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
__fastcall TREM_DMDocZTreb::TREM_DMDocZTreb(TComponent* Owner)
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
//---------------------------------------------------------------------------

bool TREM_DMDocZTreb::Init(void)
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
int TREM_DMDocZTreb::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocZTreb::DataModuleDestroy(TObject *Sender)
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

bool TREM_DMDocZTreb::NewDoc(void)
{
bool result=false;
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

	//получим номер документа
	NumDoc->Active=false;
	IDMTableNumberDoc * dm_num;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
	dm_num->Init(InterfaceMainObject,0);
	NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMZTREB");
	NumDoc->Open();
	DocAllNUM_REM_GALLDOC->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
	dm_num->kanRelease();
	NumDoc->Active=false;

	DocAllPOS_REM_GALLDOC->AsDateTime=Now();
	DocAllTDOC_REM_GALLDOC->AsString="REMZTREB";
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
bool TREM_DMDocZTreb::OpenDoc(__int64 id)
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
void TREM_DMDocZTreb::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TREM_DMDocZTreb::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TREM_DMDocZTreb::SaveDoc(void)
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
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ редактировать чужие документы!";
		return Res;
		}
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
bool TREM_DMDocZTreb::DvRegDoc(void)
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
bool TREM_DMDocZTreb::CancelDvRegDoc(void)
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

bool TREM_DMDocZTreb::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ удал€ть чужие документы!";
		return res;
		}
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
void __fastcall TREM_DMDocZTreb::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DZTREB->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DZTREB->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_DMDocZTreb::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DZTREBT->AsString=DocAllID_REM_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_REM_DZTREBT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocZTreb::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocZTreb::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewSummaStr=0;
NewSummaMexStr=0;
NewSummaMexStr=0;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocZTreb::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_REM_DZTREBT->AsFloat;
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocZTreb::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocZTreb::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)
{
	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_REM_DZTREB->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		Doc->Post();
		}

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_DZTREBT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocZTreb::DocTKOL_REM_DZTREBTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DZTREBT->AsFloat;

DocTSUM_REM_DZTREBT->AsFloat=NewSummaStr=DocTKOL_REM_DZTREBT->AsFloat*
											DocTPRICE_REM_DZTREBT->AsFloat;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocZTreb::DocTPRICE_REM_DZTREBTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DZTREBT->AsFloat;


DocTSUM_REM_DZTREBT->AsFloat=NewSummaStr=DocTKOL_REM_DZTREBT->AsFloat*
											DocTPRICE_REM_DZTREBT->AsFloat;


DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

