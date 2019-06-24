//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocRKORozn.h"
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
__fastcall TDMDocRKORozn::TDMDocRKORozn(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}

//----------------------------------------------------------------------------
void __fastcall TDMDocRKORozn::DataModuleCreate(TObject *Sender)
{
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocRKORozn::Init(void)
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
//---------------------------------------------------------------------------
int TDMDocRKORozn::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocRKORozn::DataModuleDestroy(TObject *Sender)
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
void TDMDocRKORozn::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Insert();
Doc->Insert();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOC_DRKOROZN->AsString=DocAllIDDOC->AsString;
Doc->Post();

DocAllTDOC->AsString="RKOROZN";


DocAllPOSDOC->AsDateTime=Now();

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
			{
			DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
			DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
			}
		DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
		DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
		if ( glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
			{
			DocAllIDFIRMDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
			DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
			}

DocAll->Post();

	   Doc->Edit();
	   DocOPERATION_DRKOROZN->AsInteger=1;
	   if (glStrToInt64(DM_Connection->UserInfoIDKASSA_USER->AsString)!=0)
			{
			DocIDKKM_DRKOROZN->AsString=DM_Connection->UserInfoIDKASSA_USER->AsString;
			DocNAMEKKM->AsString=DM_Connection->UserInfoNAMEKKM->AsString;
			}
		Doc->Post();



flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();

}
//----------------------------------------------------------------------------
int TDMDocRKORozn::GetNumberNewDoc(void)
{
int result=0;

if (flGetNumberDoc==false) return result;
//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDKASSA")->AsString=DocIDKKM_DRKOROZN->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocRKORozn::OpenDoc(__int64 Id)
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
void TDMDocRKORozn::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocRKORozn::SaveDoc(void)
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
//        if (CancelDvRegDoc()==true)
//                {
				IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
                OpenDoc(IdDoc);
                result=true;
//                }
        }
catch(Exception &exception)
				{
			   	IBTrUpdate->Rollback();
				result=false;
				TextError=exception.Message;
				}
return result;
}
//-----------------------------------------------------------------------------


bool TDMDocRKORozn::DeleteDoc(__int64 id)
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
bool TDMDocRKORozn::DvRegDoc(void)
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
//				if (DocOPERATION_DRKOROZN->AsInteger==1   ||    //с контрагентами
//						DocOPERATION_DRKOROZN->AsInteger==4)    //возврат кредита
//                        {
//                        //по регистру взаиморасчеты
//						IdDoc=DocAllIDDOC->AsInteger;
//                        DMRegVsRasch->IdDoc=IdDoc;
//                        DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//                        DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//						DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//                        DMRegVsRasch->Sum=DocAllSUMDOC->AsFloat;
//						DMRegVsRasch->AddRecordPrihod();
//
//						//спишем аванс
//						pFIBQAdvance->Active=false;
//						pFIBQAdvance->ParamByName("PARAM_IDFIRM")->AsInteger=DocAllIDFIRMDOC->AsInteger;
//						pFIBQAdvance->ParamByName("PARAM_IDKLIENT")->AsInteger=DocAllIDKLDOC->AsInteger;
//						pFIBQAdvance->Active=true;
//
//						if (pFIBQAdvanceSUM_RGADVCUST->AsFloat>0)
//							{
//							if (pFIBQAdvanceSUM_RGADVCUST->AsFloat>=DocAllSUMDOC->AsFloat)
//								{
//								DMRegAdvanceCustomer->Sum=DocAllSUMDOC->AsFloat;
//								}
//							else
//								{
//								DMRegAdvanceCustomer->Sum=pFIBQAdvanceSUM_RGADVCUST->AsFloat;
//								}
//							pFIBQAdvance->Active=false;
//
//							DMRegAdvanceCustomer->IdDoc=DocAllIDDOC->AsInteger;
//							DMRegAdvanceCustomer->PosDoc=DocAllPOSDOC->AsDateTime;
//							DMRegAdvanceCustomer->IdFirm=DocAllIDFIRMDOC->AsInteger;
//							DMRegAdvanceCustomer->IdKlient=DocAllIDKLDOC->AsInteger;
//							DMRegAdvanceCustomer->AddRecordRashod();
//							}
//						}
//
//                //по регистру касса
//				DMRegKassa->IdDoc=DocAllIDDOC->AsInteger;
//				DMRegKassa->PosDoc=DocAllPOSDOC->AsDateTime;
//                DMRegKassa->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                DMRegKassa->IdKKM=DocIDKKM_DRKOROZN->AsInteger;
//                DMRegKassa->Operation =DocOPERATION_DRKOROZN->AsInteger;
//				DMRegKassa->Sum=DocAllSUMDOC->AsFloat;
//				DMRegKassa->AddRecordRashod();
//
//                Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//                Doc2->Edit();
//				Doc2PRDOC->AsInteger=1;
//                Doc2->Post();
//				IBTrDvReg->Commit();
//
//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;
//
//                result=true;
//				}
//		}
//
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
bool TDMDocRKORozn::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//try
//		{
//		DMRegVsRasch->IdDoc=DocAllIDDOC->AsInteger;
//		//авансы покупателей
//		DMRegAdvanceCustomer->IdDoc=DocAllIDDOC->AsInteger;
//		DMRegKassa->IdDoc=DocAllIDDOC->AsInteger;
//		if (DMRegVsRasch->CancelDvReg()==true &&
//					DMRegAdvanceCustomer->CancelDvReg()==true &&
//					DMRegKassa->CancelDvReg()==true)
//                {
//				Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//				Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//                Doc2->Post();
//				IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//       delete DMSetup;
//
//				result=true;
//				}
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


void __fastcall TDMDocRKORozn::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------




void __fastcall TDMDocRKORozn::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DRKOROZN->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DRKOROZN->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKORozn::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DRKOROZN->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKORozn::DocIDKKM_DRKOROZNChange(TField *Sender)
{
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKORozn::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

