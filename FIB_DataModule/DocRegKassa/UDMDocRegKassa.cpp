//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UDMDocRegKassa.h"
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
__fastcall TDMDocRegKassa::TDMDocRegKassa(TComponent* Owner)
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

void __fastcall TDMDocRegKassa::DataModuleCreate(TObject *Sender)
{

Prosmotr=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocRegKassa::Init(void)
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
int TDMDocRegKassa::Done(void)
{

return -1;
}

//---------------------------------------------------------------------------
void __fastcall TDMDocRegKassa::DataModuleDestroy(TObject *Sender)
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

bool TDMDocRegKassa::NewDoc(void)
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

	IdDoc=glStrToInt64(DocAllIDDOC->AsString);


	DocAllPOSDOC->AsDateTime=Now();
	DocAllTDOC->AsString="RG_KASSA";
	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
		{
		DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
		{
		DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
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
int TDMDocRegKassa::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
bool TDMDocRegKassa::OpenDoc(__int64 id)
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
	DocT->Active=true;

	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
	Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
	DMSetup->kanRelease();

	DocAllIDBASE_GALLDOC->ReadOnly=true;

	IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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
void TDMDocRegKassa::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TDMDocRegKassa::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TDMDocRegKassa::SaveDoc(void)
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

try
        {
		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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
bool TDMDocRegKassa::DvRegDoc(void)
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
bool TDMDocRegKassa::CancelDvRegDoc(void)
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


bool TDMDocRegKassa::DeleteDoc(__int64 id)
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

//---------------------------------------------------------------------------
void __fastcall TDMDocRegKassa::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DRG_KASSA->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DRG_KASSA->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocRegKassa::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DRG_KASSAT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DRG_KASSAT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocRegKassa::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRegKassa::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRegKassa::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DRG_KASSA->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}   

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DRG_KASSAT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------








