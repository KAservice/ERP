//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_DMDocOstNom.h"

#include "IDMSetup.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMTableNumberDoc.h"
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
__fastcall TREM_DMDocOstNom::TREM_DMDocOstNom(TComponent* Owner)
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

bool TREM_DMDocOstNom::Init(void)
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
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;
DocOsn->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
TypeNom->Database=DM_Connection->pFIBData;

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
int TREM_DMDocOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocOstNom::DataModuleDestroy(TObject *Sender)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;
DocOsn->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TREM_DMDocOstNom::NewDoc(void)
{
DocAll->Active=false;
Doc->Active=false;
TypeNom->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_IDDOC")->AsInt64=0;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=0;
DocT->ParamByName("PARAM_IDDOC")->AsInt64=0;

DocAll->Active=true;
Doc->Active=true;
TypeNom->Active=true;
DocT->Active=true;

DocAll->Append();
Doc->Append();
IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
DocIDDOC_REM_DOSN->AsString=IdDoc;

//получим номер документа
NumDoc->Active=false;
IDMTableNumberDoc * dm_num;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
dm_num->Init(InterfaceMainObject,InterfaceOwnerObject);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMOSN");
NumDoc->Open();
DocAllNUM_REM_GALLDOC->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;

DocAllPOS_REM_GALLDOC->AsDateTime=Now();
DocAllTDOC_REM_GALLDOC->AsString="REMOSN";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSER_REM_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRM_REM_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLAD_REM_GALLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_REM_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
DocAll->Post();

//закупочный тип цен
Doc->Edit();
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
DMSetup->OpenElement(30);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		DocIDTPRICE_REM_DOSN->AsString=StrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
		}
DMSetup->kanRelease();

}
//---------------------------------------------------------------------------
void TREM_DMDocOstNom::OpenDoc(__int64 id_doc)
{
IdDoc=id_doc;
DocAll->Active=false;
Doc->Active=false;
TypeNom->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
DocT->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;

DocAll->Active=true;
Doc->Active=true;
TypeNom->Active=true;
DocT->Active=true;

DocOsn->ParamByName("PARAM_IDDOC_OSN")->AsInt64=glStrToInt64(DocAllIDDOCOSN_REM_GALLDOC->AsString);
DocOsn->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_REM_GALLDOC->ReadOnly=true;

}
//-----------------------------------------------------------------------------
void TREM_DMDocOstNom::AddDocNewString()
{
DocT->Append();
DocTIDDOC_REM_DOSNT->AsString=DocAllID_REM_GALLDOC->AsString;
DocT->Post();
}
//---------------------------------------------------------------------------
void TREM_DMDocOstNom::DeleteStringDoc(void)
{
DocT->Delete();
}


//---------------------------------------------------------------------------
bool TREM_DMDocOstNom::SaveDoc(void)
{
bool Res=false;
IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Нельзя редактировать чужие документы!";
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

				TextError=exception.Message;
				Res=false;
				}

return Res;
}
//----------------------------------------------------------------------------
void TREM_DMDocOstNom::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();


        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        NumDoc->Active=false;

}

//---------------------------------------------------------------------------
bool TREM_DMDocOstNom::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
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
bool TREM_DMDocOstNom::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

try
		{
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryCancelDvReg->ExecProc();
				IBTrDvReg->Commit();

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

bool TREM_DMDocOstNom::DeleteDoc(__int64 id)
{
bool res=false;

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return res;
		}
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Нельзя удалять чужие документы!";
		return res;
		}
	}


OpenDoc(id);

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
//----------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocRSUM_REM_DOSN->AsFloat=DocRSUM_REM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_REM_DOSNT->AsFloat;
OldRSummaStr=DocTRSUM_REM_DOSNT->AsFloat;
}
//---------------------------------------------------------------------------










void __fastcall TREM_DMDocOstNom::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DOSN->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DOSN->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DOSNT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_REM_DOSNT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocOstNom::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTKOL_REM_DOSNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DOSNT->AsFloat;
DocTSUM_REM_DOSNT->AsFloat=NewSummaStr=DocTKOL_REM_DOSNT->AsFloat
						*DocTPRICE_REM_DOSNT->AsFloat;
DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

OldRSummaStr=DocTRSUM_REM_DOSNT->AsFloat;
DocTRSUM_REM_DOSNT->AsFloat=NewRSummaStr=DocTKOL_REM_DOSNT->AsFloat
						*DocTRPRICE_REM_DOSNT->AsFloat;
Doc->Edit();
DocRSUM_REM_DOSN->AsFloat=DocRSUM_REM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTPRICE_REM_DOSNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DOSNT->AsFloat;

DocTSUM_REM_DOSNT->AsFloat=NewSummaStr=DocTKOL_REM_DOSNT->AsFloat
						*DocTPRICE_REM_DOSNT->AsFloat;
DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocOstNom::DocTRPRICE_REM_DOSNTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_REM_DOSNT->AsFloat;

DocTRSUM_REM_DOSNT->AsFloat=NewRSummaStr=DocTKOL_REM_DOSNT->AsFloat
						*DocTRPRICE_REM_DOSNT->AsFloat;
Doc->Edit();
DocRSUM_REM_DOSN->AsFloat=DocRSUM_REM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------



void __fastcall TREM_DMDocOstNom::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_REM_DOSN->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_REM_DOSNT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------

