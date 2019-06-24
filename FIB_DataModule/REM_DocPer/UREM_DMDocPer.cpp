//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UREM_DMDocPer.h"
#include "IDMSetup.h"
#include "IDMTableNumberDoc.h"
#include "UGlobalFunction.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_DMDocPer::TREM_DMDocPer(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//-----------------------------------------------------------------
void __fastcall TREM_DMDocPer::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
AutoRaschet=false;
EnableDvReg=false;

}
//-----------------------------------------------------------------------
bool TREM_DMDocPer::Init(void)
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

NumDoc->Database=DM_Connection->pFIBData;
SpisokTypePrice->Database=DM_Connection->pFIBData;
DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
DocOsn->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_DocCheckKKM);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TREM_DMDocPer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocPer::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
DocOsn->Active=false;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TREM_DMDocPer::NewDoc(void)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
SpisokTypePrice->Active=false;
NumDoc->Active=false;
DocOsn->Active=false;


DocAll->ParamByName("PARAM_ID")->AsInt64=0;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=0;
DocT->ParamByName("PARAM_IDDOC")->AsInt64=0;

DocAll->Open();
Doc->Open();
DocT->Open();


OpenDocOsn();

DocAll->Append();
Doc->Append(); 

IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
DocIDDOC_REM_DPER->AsString=IdDoc;
DocAllPOS_REM_GALLDOC->AsDateTime=Now();
DocAllTDOC_REM_GALLDOC->AsString="REMPER";
DocAllSUM_REM_GALLDOC->AsFloat=0;
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSER_REM_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;
	}

if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_REM_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
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

//получим номер документа
DocAllNUM_REM_GALLDOC->AsInteger=GetNumberNewDoc();

DocAll->Post();

Doc->Edit();

if(glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
	{
	DocIDRTPRICE_REM_DPER->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
	}

Doc->Post();


SummaDoc=0;
//SummaSkidok=0;
//SummaNadbavok=0;
//SummaDocFull=0;
//SummaTable=0;
//TekSummaDoc=0;
//OldSummaStr=0;
//NewSummaStr=0;
//OldSummaSkidokStr=0;
//NewSummaSkidokStr=0;
//OldSummaNadbavokStr=0;
//NewSummaNadbavokStr=0;
//OldSummaFullStr=0;
//NewSummaFullStr=0;

}
//----------------------------------------------------------------------------
int TREM_DMDocPer::GetNumberNewDoc(void)
{
int result=0;
//получим номер документа
NumDoc->Active=false;
IDMTableNumberDoc * dm_num;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
dm_num->Init(InterfaceMainObject,0);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMPER");
NumDoc->Open();
result=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;

return result;
}
//----------------------------------------------------------------------------
bool TREM_DMDocPer::OpenDoc(__int64 Id)
{
bool result=false;
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_ID")->AsInt64=Id;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=Id;
DocT->ParamByName("PARAM_IDDOC")->AsInt64=Id;

DocAll->Open();
Doc->Open();
DocT->Open();

IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);

Summa();
DocAllIDBASE_REM_GALLDOC->ReadOnly=true;
OpenDocOsn();


ValidateProsmotr();
result=true;
return result;
}
//---------------------------------------------------------------------------

void TREM_DMDocPer::ValidateProsmotr(void)
{
Prosmotr=false;    //только просмотр
ProsmotrText="";

//позиция запрета редактирования
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
if (Prosmotr==true)
	{
    ProsmotrText="Позиция документа меньше позиции запрета редактирования!";
	}

DMSetup->kanRelease();

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Prosmotr=true;
		ProsmotrText="Нельзя редактировать чужие документы!";
		}
	}
}
//----------------------------------------------------------------------------
void TREM_DMDocPer::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
		DocT->CancelUpdates();

        DocAll->Active=false;
		Doc->Active=false;
		DocT->Active=false;
}
//----------------------------------------------------------------------------
bool TREM_DMDocPer::SaveDoc(void)
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

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=Summa();
DocAll->Post();


IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);

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
		OpenDoc(IdDoc);
		AfterSaveDoc();
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
//-----------------------------------------------------------------------------
bool TREM_DMDocPer::BeforeSaveDoc(void)
{
bool result=true;


return result;
}
//-----------------------------------------------------------------------------
bool TREM_DMDocPer::AfterSaveDoc(void)
{
bool result=true;



return result;
}

//-----------------------------------------------------------------------------
void TREM_DMDocPer::AddDocNewString(void)
{
DocT->Append();

}
//-----------------------------------------------------------------------------
void TREM_DMDocPer::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TREM_DMDocPer::Summa(void)
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;


BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocTRSUM_REM_DPERT->AsFloat;
		DocT->Next();
		}

Doc->Edit();

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TREM_DMDocPer::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
		}

if (EnableDvReg==false)
        {
        try
                {
			IDMSetup * DMSetup;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
			DMSetup->Init(InterfaceMainObject,0);
                DMSetup->OpenElement(14);
                if (DMSetup->ElementVALUE_SETUP->AsString=="1")
                        {
						result=true;
                        return result;
                        }
                DMSetup->kanRelease();
                }
        catch(...)
                {
                }
        }



try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryDvReg->ExecProc();
				IBTrDvReg->Commit();

//                TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
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
//-----------------------------------------------------------------------------
bool TREM_DMDocPer::CancelDvRegDoc(void)
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

bool TREM_DMDocPer::DeleteDoc(__int64 id)
{
bool res=false;
IdDoc=id;
OpenDoc(id);

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
				TextError=exception.Message;
				res=false;
				}


return res;

}

//----------------------------------------------------------------------------


void __fastcall TREM_DMDocPer::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DPER->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllID_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DPER->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;


DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTRSUM_REM_DPERT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DPERT->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocTIDBASE_REM_DPERT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void TREM_DMDocPer::OpenDocOsn(void)
{
DocOsn->Active=false;
DocOsn->ParamByName("PARAM_IDDOC")->AsString=glStrToInt64(DocAllIDDOCOSN_REM_GALLDOC->AsString);
DocOsn->Active=true;

}

//---------------------------------------------------------------------------


void __fastcall TREM_DMDocPer::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------




void __fastcall TREM_DMDocPer::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)
{
if (Doc->Active==true)
	{
	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_REM_DPER->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		Doc->Post();
		}
	}

if (DocT->Active==true)
	{
	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_DPERT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocOsnTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (glStrToInt64(DocAllIDDOCOSN_REM_GALLDOC->AsString)!=0)
	{
	Text=glGetNameDoc(DocOsnTDOC_REM_GALLDOC->AsString)+
			" №"+DocOsnNUM_REM_GALLDOC->AsString+
			" от "+DocOsnPOS_REM_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocPer::DocTRPRICE_REM_DPERTChange(TField *Sender)
{
OldSummaStr=DocTRSUM_REM_DPERT->AsFloat;

DocTRSUM_REM_DPERT->AsFloat=NewSummaStr=DocTKOL_REM_DPERT->AsFloat*DocTRPRICE_REM_DPERT->AsFloat;


DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPer::DocTKOL_REM_DPERTChange(TField *Sender)
{
OldSummaStr=DocTRSUM_REM_DPERT->AsFloat;

DocTRSUM_REM_DPERT->AsFloat=NewSummaStr=DocTKOL_REM_DPERT->AsFloat*DocTRPRICE_REM_DPERT->AsFloat;


DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

