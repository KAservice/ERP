//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UREM_DMDocVigruska.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNom.h"
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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_DMDocVigruska::TREM_DMDocVigruska(TComponent* Owner)
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

void __fastcall TREM_DMDocVigruska::DataModuleCreate(TObject *Sender)
{

Prosmotr=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TREM_DMDocVigruska::Init(void)
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
IBTrDvReg->DefaultDatabase=DM_Connection->pFIBData;

DocAll->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

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
int TREM_DMDocVigruska::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocVigruska::DataModuleDestroy(TObject *Sender)
{

DocAll->Active=false;
DocT->Active=false;
NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

bool TREM_DMDocVigruska::NewDoc(void)
{
bool result=false;
flGetNumberDoc=false;

try
	{
	DocAll->Active=false;
	DocT->Active=false;

	DocAll->Active=true;
	DocT->Active=true;

	DocAll->Append();


	IdDoc=glStrToInt64(DocAllID_REM_GUR_VIGR->AsString);


	DocAllPOS_REM_GUR_VIGR->AsDateTime=Now();

	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
		{
		DocAllIDUSER_REM_GUR_VIGR->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocAllNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
		{
		DocAllIDBASE_REM_GUR_VIGR->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
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

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();

return result;
}
//---------------------------------------------------------------------------
int TREM_DMDocVigruska::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
//NumDoc->Active=false;
//NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_REM_GUR_VIGR->AsString;

//NumDoc->Open();
//DocAllPREFIKS_NUM_REM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
//DocAllNUM_REM_GUR_VIGR->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger;
//NumDoc->Close();

	//получим номер документа
	NumDoc->Active=false;
	//IDMTableNumberDoc * dm_num;
	//InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
	//												(void**)&dm_num);
	//dm_num->Init(InterfaceMainObject,0);
	//NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMPROV");
	NumDoc->Open();
	DocAllNUM_REM_GUR_VIGR->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
	//dm_num->kanRelease();
	NumDoc->Active=false;
result=DocAllNUM_REM_GUR_VIGR->AsInteger;
return result;
}
//----------------------------------------------------------------------------
bool TREM_DMDocVigruska::OpenDoc(__int64 id)
{
bool result=false;
try
	{
	DocAll->Active=false;
	DocT->Active=false;

	DocAll->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocAll->Active=true;


	DocT->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocT->Active=true;

	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
	Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOS_REM_GUR_VIGR->AsDateTime);
	DMSetup->kanRelease();

	DocAllIDBASE_REM_GUR_VIGR->ReadOnly=true;

	IdDoc=glStrToInt64(DocAllID_REM_GUR_VIGR->AsString);
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
	
return result;
}
//-----------------------------------------------------------------------------
void TREM_DMDocVigruska::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TREM_DMDocVigruska::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TREM_DMDocVigruska::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GUR_VIGR->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
		}
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GUR_VIGR->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Нельзя редактировать чужие документы!";
		return Res;
		}
	}

try
        {
		IdDoc=glStrToInt64(DocAllID_REM_GUR_VIGR->AsString);
		DocAll->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
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
bool TREM_DMDocVigruska::DvRegDoc(void)
{
bool result=false;
//if (Prosmotr==true)
//		{
//		TextError="Позиция документа меньше позиции запрета редактирования!";
//		return result;
//		}
//
//
//try
//        {
//        if (CancelDvRegDoc()==true)
//                {
////				QueryDvReg->Close();
////				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
////				QueryDvReg->ExecProc();
////				IBTrDvReg->Commit();
//
//                result=true;
//                }
//        }
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
bool TREM_DMDocVigruska::CancelDvRegDoc(void)
{
bool result=false;
//if (Prosmotr==true)
//		{
//		TextError="Позиция документа меньше позиции запрета редактирования!";
//		return result;
//		}
//try
//		{
////				QueryCancelDvReg->Close();
////				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
////				QueryCancelDvReg->ExecProc();
////				IBTrDvReg->Commit();
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


bool TREM_DMDocVigruska::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GUR_VIGR->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Нельзя удалять чужие документы!";
		return res;
		}
	}

try
        {

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

		DocAll->Delete();
        DocT->ApplyUpdates();
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
void __fastcall TREM_DMDocVigruska::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_GUR_VIGRT->AsString=DocAllID_REM_GUR_VIGR->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GUR_VIGR->AsString)!=0)
		{
		DocTIDBASE_REM_GUR_VIGRT->AsString=DocAllIDBASE_REM_GUR_VIGR->AsString;
		}

}
//---------------------------------------------------------------------------



void __fastcall TREM_DMDocVigruska::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;


}
//---------------------------------------------------------------------------



void __fastcall TREM_DMDocVigruska::DocAllPOS_REM_GUR_VIGRChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GUR_VIGR->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocVigruska::DocAllIDBASE_REM_GUR_VIGRChange(TField *Sender)

{
if (DocT->Active==true)
	{
	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GUR_VIGR->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_GUR_VIGRT->AsString=DocAllIDBASE_REM_GUR_VIGR->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
	}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocVigruska::DocTTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=glGetNameDocRemont(DocTTDOC_REM_GALLDOC->AsString);
}
//---------------------------------------------------------------------------

