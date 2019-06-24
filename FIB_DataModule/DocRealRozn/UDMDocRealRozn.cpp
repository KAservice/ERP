//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocRealRozn.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMSprSostProd.h"
#include "IDMSprNomRest.h"
#include "IDMQueryRead.h"
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
__fastcall TDMDocRealRozn::TDMDocRealRozn(TComponent* Owner)
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
void __fastcall TDMDocRealRozn::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocRealRozn::Init(void)
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
Pay->Database=DM_Connection->pFIBData;

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
//----------------------------------------------------------------------------
int TDMDocRealRozn::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocRealRozn::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
Pay->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}

//----------------------------------------------------------------------------
void TDMDocRealRozn::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();
Pay->Open();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOC_DREALROZN->AsString=IdDoc;
if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
	{
	DocIDTPRICE_DREALROZN->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
	}
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="REALROZN";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRMDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}

DocAll->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocRealRozn::GetNumberNewDoc(void)
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
void TDMDocRealRozn::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        Pay->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;
		DocT->ParamByName("ID")->AsInt64=Id;
		Pay->ParamByName("PARAM_IDDOC")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
        DocT->Open();
        Pay->Open();

	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
	Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
	DMSetup->kanRelease();


DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}

//----------------------------------------------------------------------------
void TDMDocRealRozn::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
        Pay->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocRealRozn::SaveDoc(void)
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
		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		Pay->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();
		Pay->CommitUpdToCach();
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


bool TDMDocRealRozn::DeleteDoc(__int64 id)
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

        Pay->First();
        while(!Pay->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                Pay->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

        Pay->ApplyUpdates();
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
void TDMDocRealRozn::AddDocNewString(void)
{
DocT->Append();
DocTIDDOC_DREALROZNT->AsString=DocAllIDDOC->AsString;
DocT->Post();

}
//-----------------------------------------------------------------------------
void TDMDocRealRozn::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocRealRozn::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_DREALROZNT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TDMDocRealRozn::DvRegDoc(void)
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
bool TDMDocRealRozn::CancelDvRegDoc(void)
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

void __fastcall TDMDocRealRozn::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DREALROZN->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DREALROZN->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_DREALROZNT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DREALROZNT->AsString=DocAllIDDOC->AsString;
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DREALROZNT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::PayCalcFields(TDataSet *DataSet)
{
PayRECNO->AsInteger=Pay->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::PayNewRecord(TDataSet *DataSet)
{
PayIDDOC_DREALROZN_PAY->AsString=DocAllIDDOC->AsString;

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	PayIDBASE_DREALROZN_PAY->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocAllPOSDOCChange(TField *Sender)
{
	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRealRozn::DocTKOL_DREALROZNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREALROZNT->AsFloat;

DocTSUMNAD_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRNAD_DREALROZNT->AsFloat/100;
DocTSUMSK_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRSK_DREALROZNT->AsFloat/100;

DocTSUM_DREALROZNT->AsFloat=NewSummaStr=DocTKOL_DREALROZNT->AsFloat*DocTPRICE_DREALROZNT->AsFloat
				-DocTSUMSK_DREALROZNT->AsFloat+DocTSUMNAD_DREALROZNT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTPRICE_DREALROZNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREALROZNT->AsFloat;

DocTSUMNAD_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRNAD_DREALROZNT->AsFloat/100;
DocTSUMSK_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRSK_DREALROZNT->AsFloat/100;

DocTSUM_DREALROZNT->AsFloat=NewSummaStr=DocTKOL_DREALROZNT->AsFloat*DocTPRICE_DREALROZNT->AsFloat
				-DocTSUMSK_DREALROZNT->AsFloat+DocTSUMNAD_DREALROZNT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTPRSK_DREALROZNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREALROZNT->AsFloat;

DocTSUMNAD_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRNAD_DREALROZNT->AsFloat/100;
DocTSUMSK_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRSK_DREALROZNT->AsFloat/100;

DocTSUM_DREALROZNT->AsFloat=NewSummaStr=DocTKOL_DREALROZNT->AsFloat*DocTPRICE_DREALROZNT->AsFloat
				-DocTSUMSK_DREALROZNT->AsFloat+DocTSUMNAD_DREALROZNT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocTPRNAD_DREALROZNTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREALROZNT->AsFloat;

DocTSUMNAD_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRNAD_DREALROZNT->AsFloat/100;
DocTSUMSK_DREALROZNT->AsFloat=DocTPRICE_DREALROZNT->AsFloat
								*DocTKOL_DREALROZNT->AsFloat
								*DocTPRSK_DREALROZNT->AsFloat/100;

DocTSUM_DREALROZNT->AsFloat=NewSummaStr=DocTKOL_DREALROZNT->AsFloat*DocTPRICE_DREALROZNT->AsFloat
				-DocTSUMSK_DREALROZNT->AsFloat+DocTSUMNAD_DREALROZNT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRealRozn::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DREALROZN->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Pay->Edit();
	PayIDBASE_DREALROZN_PAY->AsString=DocAllIDBASE_GALLDOC->AsString;
	Pay->Post();
	}


DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DREALROZNT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRozn::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

