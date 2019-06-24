//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocOstVs.h"

#include "IDMSetup.h"
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
__fastcall TDMDocOstVs::TDMDocOstVs(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//--------------------------------------------------------------------------
void __fastcall TDMDocOstVs::DataModuleCreate(TObject *Sender)
{
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocOstVs::Init(void)
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
NumDoc->Database=DM_Connection->pFIBData;

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
int TDMDocOstVs::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocOstVs::DataModuleDestroy(TObject *Sender)
{

DocAll->Close();
Doc->Close();
NumDoc->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocOstVs::NewDoc(void)
{

flGetNumberDoc=false;
DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOC_DOSTVS->AsString=IdDoc;
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="OSTVS";
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
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
int TDMDocOstVs::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;
//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocOstVs::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();


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
void TDMDocOstVs::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        IBTr->Rollback();
}
//----------------------------------------------------------------------------
bool TDMDocOstVs::SaveDoc(void)
{
bool result=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Нельзя редактировать чужие документы!";
		return result;
		}
	}

try
        {
		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();

                OpenDoc(IdDoc);
                result=true;
		}
catch(Exception &exception)
				{
			   	IBTrUpdate->Rollback();
				result=false;
				TextError=exception.Message;
				}
return result;
}

//---------------------------------------------------------------------------
bool TDMDocOstVs::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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



        Doc->Delete();
        DocAll->Delete();

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
bool TDMDocOstVs::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
        }

//try
//        {
//        if (CancelDvRegDoc()==true)
//                {
//				//по регистру взаиморасчеты
//				if (DocRASHOD_DOSTVS->AsFloat!=0)
//					{
//					IdDoc=DocAllIDDOC->AsInteger;
//					DMRegVsRasch->IdDoc=IdDoc;
//					DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//					DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//					DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//					DMRegVsRasch->Sum=DocRASHOD_DOSTVS->AsFloat;
//					DMRegVsRasch->AddRecordRashod(); //уменьшение задолженности
//					}
//
//				if (DocPRIHOD_DOSTVS->AsFloat!=0)
//					{
//					DMRegVsRasch->IdDoc=IdDoc;
//					DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//					DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//					DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//					DMRegVsRasch->Sum=DocPRIHOD_DOSTVS->AsFloat;
//					DMRegVsRasch->AddRecordPrihod(); //увеличение задолженности
//                    }
//                //по регистру кредитов
//				DvRegDocOnRegPaySale();
//
//                Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//                Doc2->Edit();
//                Doc2PRDOC->AsInteger=1;
//                Doc2->Post();
//                IBTrDvReg->Commit();
//
//                TDMSetup * DMSetup=new TDMSetup(Application);
//                DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
//
//                result=true;
//                }
//        }
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//return result;



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
bool TDMDocOstVs::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//try
//        {
//        IdDoc=DocAllIDDOC->AsInteger;
//		DMRegVsRasch->IdDoc=IdDoc;
//
//        //оплата продаж
//        DMRegPaySale->IdDoc=DocAllIDDOC->AsInteger;
//        //авансы покупателей
//		DMRegAdvanceCustomer->IdDoc=DocAllIDDOC->AsInteger;
//
//		if ( DMRegVsRasch->CancelDvReg()==true &&
//						DMRegPaySale->CancelDvReg()==true &&
//						DMRegAdvanceCustomer->CancelDvReg()==true)
//				{
//				Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//				Doc2->Edit();
//				Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//                IBTrDvReg->Commit();
//
//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
//
//				result=true;
//				}
//		}
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



void __fastcall TDMDocOstVs::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocOstVs::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DOSTVS->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DOSTVS->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstVs::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DOSTVS->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstVs::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

