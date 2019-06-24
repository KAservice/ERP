//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UREM_DMDocProverka.h"
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
__fastcall TREM_DMDocProverka::TREM_DMDocProverka(TComponent* Owner)
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

bool TREM_DMDocProverka::Init(void)
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
int TREM_DMDocProverka::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocProverka::DataModuleDestroy(TObject *Sender)
{

DocAll->Active=false;

NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

bool TREM_DMDocProverka::NewDoc(void)
{
bool result=false;
try
	{
	DocAll->Active=false;


	DocAll->Active=true;


	DocAll->Append();


	IdDoc=glStrToInt64(DocAllID_REM_GUR_PROV->AsString);

	//получим номер документа
	NumDoc->Active=false;
	//IDMTableNumberDoc * dm_num;
	//InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
	//												(void**)&dm_num);
	//dm_num->Init(InterfaceMainObject,0);
	//NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMPROV");
	NumDoc->Open();
	DocAllNUM_REM_GUR_PROV->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
	//dm_num->kanRelease();
	NumDoc->Active=false;

	DocAllPOS_REM_GUR_PROV->AsDateTime=Now();

	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
		{
		DocAllIDUSER_REM_GUR_PROV->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocAllNAME_USER_PROV->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
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
int TREM_DMDocProverka::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
	DocAllNUM_REM_GUR_PROV->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
	//dm_num->kanRelease();
	NumDoc->Active=false;

//NumDoc->Active=false;
//NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_REM_GUR_PROV->AsString;

//NumDoc->Open();
//DocAllPREFIKS_NUM_REM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
//DocAllNUM_REM_GUR_PROV->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
//NumDoc->Close();
result=DocAllNUM_REM_GUR_PROV->AsInteger;
return result;
}
//----------------------------------------------------------------------------

bool TREM_DMDocProverka::OpenDoc(__int64 id)
{
bool result=false;

try
	{
	DocAll->Active=false;
	DocAll->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocAll->Active=true;



IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
	Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GUR_PROV->AsDateTime);
DMSetup->kanRelease();

	DocAllIDBASE_REM_GUR_PROV->ReadOnly=true;

	IdDoc=glStrToInt64(DocAllID_REM_GUR_PROV->AsString);
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
bool TREM_DMDocProverka::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GUR_PROV->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return Res;
		}
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GUR_PROV->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ редактировать чужие документы!";
		return Res;
		}
	}

try
        {
		IdDoc=glStrToInt64(DocAllID_REM_GUR_PROV->AsString);
		DocAll->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
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
bool TREM_DMDocProverka::DvRegDoc(void)
{
bool result=false;
//if (Prosmotr==true)
//		{
//		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
//		return result;
//		}
//
//
//try
//		{
//        if (CancelDvRegDoc()==true)
//                {
//				QueryDvReg->Close();
//				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
//				QueryDvReg->ExecProc();
//				IBTrDvReg->Commit();
//
//				result=true;
//				}
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				}
//
//
//QueryDvReg->Close();
return result;
}

//---------------------------------------------------------------------------
bool TREM_DMDocProverka::CancelDvRegDoc(void)
{
bool result=false;
//if (Prosmotr==true)
//		{
//		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
//		return result;
//		}
//try
//		{
//				QueryCancelDvReg->Close();
//				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
//				QueryCancelDvReg->ExecProc();
//				IBTrDvReg->Commit();
//
////				TDMSetup * DMSetup=new TDMSetup(Application);
////				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
////				delete DMSetup;
//
//				result=true;
//
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				}
//
//QueryCancelDvReg->Close();
return result;
}

//---------------------------------------------------------------------------

bool TREM_DMDocProverka::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GUR_PROV->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ удал€ть чужие документы!";
		return res;
		}
	}

try
        {
//        if (CancelDvRegDoc()!=true)
//				{
//				res=false;
//				return res;
//				}


        DocAll->Delete();

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





void __fastcall TREM_DMDocProverka::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GUR_PROV->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------



void __fastcall TREM_DMDocProverka::DocAllTDOC_REM_GALLDOCGetText(TField *Sender,
          UnicodeString &Text, bool DisplayText)
{
Text=glGetNameDocRemont(DocAllTDOC_REM_GALLDOC->AsString);
}
//---------------------------------------------------------------------------

