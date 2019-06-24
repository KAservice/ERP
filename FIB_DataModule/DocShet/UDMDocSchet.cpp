//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocSchet.h"
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
__fastcall TDMDocSchet::TDMDocSchet(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocSchet::Init(void)
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

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

pFIBQ->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;
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
int TDMDocSchet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSchet::DataModuleDestroy(TObject *Sender)
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

void TDMDocSchet::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=0;
Doc->ParamByName("ID")->AsInt64=0;
DocT->ParamByName("ID")->AsInt64=0;

DocAll->Active=true;
Doc->Active=true;
DocT->Active=true;

DocAll->Append();
Doc->Append();
IdDoc=DocAllIDDOC->AsInt64;
DocIDDOCSCH->AsInt64=IdDoc;
if (DM_Connection->UserInfoIDBSCHET_USER->AsInt64!=0)
	{
	DocIDBSCHET_DSCH->AsInt64=DM_Connection->UserInfoIDBSCHET_USER->AsInt64;
	DocNAMEBSCHET->AsString=DM_Connection->UserInfoNAMEBSCHET->AsString;
	}
if (DM_Connection->UserInfoIDTPRICE_USER->AsInt64!=0)
	{
	DocIDTPRICESCH->AsInt64=DM_Connection->UserInfoIDTPRICE_USER->AsInt64;
	}
Doc->Post();



DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="SCH";
if (DM_Connection->UserInfoID_USER->AsInt64!=0)
	{
	DocAllIDUSERDOC->AsInt64=DM_Connection->UserInfoID_USER->AsInt64;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (DM_Connection->UserInfoIDFIRM_USER->AsInt64!=0)
	{
	DocAllIDFIRMDOC->AsInt64=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if (DM_Connection->UserInfoIDSKLAD_USER->AsInt64!=0)
	{
	DocAllIDSKLDOC->AsInt64=DM_Connection->UserInfoIDSKLAD_USER->AsInt64;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}
if (DM_Connection->UserInfoIDBASE_SUSER->AsInt64!=0)
	{
	DocAllIDBASE_GALLDOC->AsInt64=DM_Connection->UserInfoIDBASE_SUSER->AsInt64;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
DocAll->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------
int TDMDocSchet::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;
//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=DocAllIDSKLDOC->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocSchet::OpenDoc(__int64 IdDoc)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;


DocAll->ParamByName("ID")->AsInt64=IdDoc;
Doc->ParamByName("ID")->AsInt64=IdDoc;
DocT->ParamByName("ID")->AsInt64=IdDoc;

DocAll->Active=true;
Doc->Active=true;
DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;

IdDoc=DocAllIDDOC->AsInt64;
}
//-----------------------------------------------------------------------------
void TDMDocSchet::AddDocNewString()
{
DocT->Append();
DocTIDDOCSCHT->AsInt64=DocAllIDDOC->AsInt64;
DocT->Post();
}
//---------------------------------------------------------------------------
void TDMDocSchet::DeleteStringDoc(void)
{
DocT->Delete();
}


//---------------------------------------------------------------------------
bool TDMDocSchet::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
        {

        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{

		TextError="Нельзя редактировать чужие документы!";
		return Res;
		}
	}

Summa();
DocAll->Edit();
DocAllSUMDOC->AsFloat=SummaDoc;
DocAll->Post();
try
        {
		IdDoc=DocAllIDDOC->AsInt64;
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
//----------------------------------------------------------------------------
void TDMDocSchet::CloseDoc(void)
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
bool TDMDocSchet::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//if (CancelDvRegDoc()!=true)
//        {
//		Res=false;
//        return Res;
//		}
//
//try
//		{
//
//
//		Doc2->Active=false;
//		Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//		Doc2->Active=true;
//		Doc2->Edit();
//		Doc2PRDOC->AsInteger=1;
//		Doc2->Post();
//
//		IBTrDvReg->Commit();
//
//	   Res=true;
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Res=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//
//return Res;

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
bool TDMDocSchet::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}


//try
//        {
//
//				Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//				Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//				IBTrDvReg->Commit();
//				result=true;
//
//		}
//
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//
//return result;


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
double TDMDocSchet::Summa()
{
SummaDoc=0;

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUMSCHT->AsFloat;
        DocT->Next();
        }
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}

//------------------------------------------------------------------------------










bool TDMDocSchet::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
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
				res=false;
				TextError=exception.Message;
				}
return res;

}
//-----------------------------------------------------------------------------



void __fastcall TDMDocSchet::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMSCHT->AsFloat; 	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSchet::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSchet::DocTKOLSCHTChange(TField *Sender)
{
OldSummaStr=DocTSUMSCHT->AsFloat;

DocTSUMSCHT->AsFloat=NewSummaStr=DocTKOLSCHT->AsFloat*DocTPRICESCHT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocTKFSCHTChange(TField *Sender)
{
OldSummaStr=DocTSUMSCHT->AsFloat;

DocTSUMSCHT->AsFloat=NewSummaStr=DocTKOLSCHT->AsFloat* DocTKFSCHT->AsFloat
						*DocTPRICESCHT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocTPRICESCHTChange(TField *Sender)
{
OldSummaStr=DocTSUMSCHT->AsFloat;

DocTSUMSCHT->AsFloat=NewSummaStr=DocTKOLSCHT->AsFloat*DocTPRICESCHT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSchet::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCSCH->AsString=DocAllIDDOC->AsString;
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DSCH->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCSCHT->AsString=DocAllIDDOC->AsString;
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocTIDBASE_DSCHT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	Doc->Edit();
	DocIDBASE_DSCH->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocT->Edit();
		DocTIDBASE_DSCHT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSchet::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchet::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

