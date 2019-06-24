//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMDocViezd.h"
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
__fastcall THOT_DMDocViezd::THOT_DMDocViezd(TComponent* Owner)
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
bool THOT_DMDocViezd::Init(void)
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
Doc->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int THOT_DMDocViezd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMDocViezd::DataModuleDestroy(TObject *Sender)
{


DocAll->Close();
Doc->Close();
NumDoc->Close();
DocT->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void THOT_DMDocViezd::NewDoc(void)
{
DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDocH=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
DocIDDOCH_HOT_DVIESD->AsString=IdDocH;
Doc->Post();

DocAllPOS_HOT_GALLDOC->AsDateTime=Now();
DocAllTDOC_HOT_GALLDOC->AsString="VIEZD";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSER_HOT_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_HOT_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRM_HOT_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}

//получим номер документа
NumDoc->Active=false;
IDMTableNumberDoc * dm_num;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
dm_num->Init(InterfaceMainObject,0);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("VIEZD");
NumDoc->Open();
DocAllNUMBER_HOT_GALLDOC->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;
DocAll->Post();


}
//----------------------------------------------------------------------------
void THOT_DMDocViezd::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
		DocT->Active=false;

		DocAll->ParamByName("PARAM_ID")->AsInt64=Id;
		Doc->ParamByName("PARAM_IDDOC")->AsInt64=Id;
		DocAll->Open();
		Doc->Open();

		DocT->ParamByName("PARAM_IDDOCH")->AsInt64=Id;
		DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();

//DocAllPREFIKSDOC->ReadOnly=true;

}

//----------------------------------------------------------------------------
void THOT_DMDocViezd::CloseDoc(void)
{
        DocAll->CancelUpdates();
		Doc->CancelUpdates();
		DocT->CancelUpdates();
        IBTr->Rollback();
}
//----------------------------------------------------------------------------
bool THOT_DMDocViezd::SaveDoc(void)
{
bool result=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
        {
//        if (CancelDvRegDoc()==true)
//                {
		IdDocH=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
		DocAll->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		Doc->ApplyUpdToBase();

		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		DocT->CommitUpdToCach();
		Doc->CommitUpdToCach();


                OpenDoc(IdDocH);
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
//----------------------------------------------------------------------------
bool THOT_DMDocViezd::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOCH")->AsInt64=
						glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
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
bool THOT_DMDocViezd::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
		{     
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOCH")->AsInt64=
						glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
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

bool THOT_DMDocViezd::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
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


void __fastcall THOT_DMDocViezd::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------



void __fastcall THOT_DMDocViezd::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCH_HOT_DVIESDT->AsString=DocAllID_HOT_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_HOT_DVIESDT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		}
}

//---------------------------------------------------------------------------
void THOT_DMDocViezd::AddString(void)
{
DocT->Append();
}
//----------------------------------------------------------------------------
void THOT_DMDocViezd::DeleteString(void)
{
DocT->Delete();
}
//----------------------------------------------------------------------------
void __fastcall THOT_DMDocViezd::DocAllIDBASE_HOT_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_HOT_DVIESD->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_HOT_DVIESDT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocViezd::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCH_HOT_DVIESD->AsString=DocAllID_HOT_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	DocIDBASE_HOT_DVIESD->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

