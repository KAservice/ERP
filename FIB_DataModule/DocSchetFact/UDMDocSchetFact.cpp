//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocSchetFact.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
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
__fastcall TDMDocSchetFact::TDMDocSchetFact(TComponent* Owner)
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
void __fastcall TDMDocSchetFact::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocSchetFact::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


result=true;

return result;
}
//----------------------------------------------------------------------------
int TDMDocSchetFact::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSchetFact::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
pFIBQ->Close();

IBQ->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocSchetFact::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=DocAllIDDOC->AsInt64;
DocIDDOC_DSCHFACT->AsInt64=IdDoc;
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="SCHFACT";
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
//----------------------------------------------------------------------------
int TDMDocSchetFact::GetNumberNewDoc(void)
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
void TDMDocSchetFact::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;
		DocT->ParamByName("ID")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
        DocT->Open();

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=DocAllIDDOC->AsInt64;
}

//----------------------------------------------------------------------------
void TDMDocSchetFact::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocSchetFact::SaveDoc(void)
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

DocAll->Edit();
DocAllSUMDOC->AsFloat=Summa();
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
        OpenDoc(IdDoc);
        Res=true;
        }

catch(Exception &exception)
				{
			 	IBTrUpdate->Rollback();
				Res=false;
				TextError=exception.Message;
				}
return Res;
}
//-----------------------------------------------------------------------------


bool TDMDocSchetFact::DeleteDoc(__int64 id)
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
void TDMDocSchetFact::AddDocNewString(void)
{
DocT->Append();
DocTIDDOC_DSCHFACTT->AsInt64=DocAllIDDOC->AsInt64;
DocT->Post();

}
//-----------------------------------------------------------------------------
void TDMDocSchetFact::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocSchetFact::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_DSCHFACTT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TDMDocSchetFact::DvRegDoc(void)
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
				DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
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

//
//if (CancelDvRegDoc()!=true)
//        {
//        Res=false;
//        return Res;
//		}
//try
//        {
//
//		Doc2->Active=false;
//        Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//        Doc2->Active=true;
//        Doc2->Edit();
//		Doc2PRDOC->AsInteger=1;
//        Doc2->Post();
//
//        IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//       DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//       delete DMSetup;
//
//       Res=true;
//        }
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

//-----------------------------------------------------------------------------
bool TDMDocSchetFact::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//try
//		{
//
//                Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//                Doc2->Edit();
//				Doc2PRDOC->AsInteger=0;
//                Doc2->Post();
//				IBTrDvReg->Commit();
//
//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;
//
//                result=true;
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
//---------------------------------------------------------------------------






void __fastcall TDMDocSchetFact::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------






void __fastcall TDMDocSchetFact::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DSCHFACT->AsInt64=DocAllIDDOC->AsInt64;

if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DSCHFACT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_DSCHFACTT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DSCHFACTT->AsInt64=DocAllIDDOC->AsInt64;

	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocTIDBASE_DSCHFACTT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTKOL_DSCHFACTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DSCHFACTT->AsFloat;

DocTSUM_DSCHFACTT->AsFloat=NewSummaStr=DocTKOL_DSCHFACTT->AsFloat*DocTPRICE_DSCHFACTT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();  	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocTPRICE_DSCHFACTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DSCHFACTT->AsFloat;

DocTSUM_DSCHFACTT->AsFloat=NewSummaStr=DocTKOL_DSCHFACTT->AsFloat*DocTPRICE_DSCHFACTT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSchetFact::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	Doc->Edit();
	DocIDBASE_DSCHFACT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocT->Edit();
		DocTIDBASE_DSCHFACTT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSchetFact::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

