//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMDocBron.h"

#include "IDMSetup.h"
#include "IHOT_DMTableSostNF.h"
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
__fastcall THOT_DMDocBron::THOT_DMDocBron(TComponent* Owner)
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
bool THOT_DMDocBron::Init(void)
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
int THOT_DMDocBron::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMDocBron::DataModuleDestroy(TObject *Sender)
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
void THOT_DMDocBron::NewDoc(void)
{
DocAll->Open();
Doc->Open();
DocT->Open();

DocAll->Append();
Doc->Append();
IdDocH=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
DocIDDOCH_HOT_DBRON->AsString=IdDocH;
Doc->Post();

DocAllPOS_HOT_GALLDOC->AsDateTime=Now();
DocAllTDOC_HOT_GALLDOC->AsString="BRON";
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
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("BRON");
NumDoc->Open();
DocAllNUMBER_HOT_GALLDOC->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;
DocAll->Post();

}
//----------------------------------------------------------------------------
void THOT_DMDocBron::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
		Doc->Active=false;
		DocT->Active=false;

		DocAll->ParamByName("PARAM_ID")->AsInt64=Id;
		Doc->ParamByName("PARAM_IDDOC")->AsInt64=Id;
		DocAll->Open();
		Doc->Open();

		DocT->ParamByName("PARAM_IDDOCH")->AsInt64=Id;
		DocT->Open();

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();

//DocAllPREFIKSDOC->ReadOnly=true;

}

//----------------------------------------------------------------------------
void THOT_DMDocBron::CloseDoc(void)
{
		DocT->CancelUpdates();
		Doc->CancelUpdates();
		DocAll->CancelUpdates();

        IBTr->Rollback();
}
//----------------------------------------------------------------------------
bool THOT_DMDocBron::SaveDoc(void)
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
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
		}


//-----------------------
//запишем состояния в таблицу состояний
IHOT_DMTableSostNF * HOT_DMTableSostNF;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMTableSostNF.1",IID_IHOT_DMTableSostNF,
													(void**)&HOT_DMTableSostNF);
HOT_DMTableSostNF->Init(InterfaceMainObject,0);
DocT->First();
while(!DocT->Eof)
	{
	if (glStrToInt64(DocTIDSOST_HOT_DBRONT->AsString)==0)
		{
		HOT_DMTableSostNF->NewElement();
		}
	else
		{
		HOT_DMTableSostNF->OpenElement(glStrToInt64(DocTIDSOST_HOT_DBRONT->AsString));
		}
	HOT_DMTableSostNF->Element->Edit();
	//документ
//	if (DocAllID_HOT_GALLDOC->AsInteger!=0)
//		{
//		HOT_DMTableSostNF->ElementIDDOCH_HOT_SOSTNF->AsInteger=DocAllID_HOT_GALLDOC->AsInteger;
//		}
	//плательщик
	if (glStrToInt64(DocAllIDKL_HOT_GALLDOC->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDPLAT_HOT_SOSTNF->AsString=DocAllIDKL_HOT_GALLDOC->AsString;
		}
	//гость
	if(glStrToInt64(DocTIDGUEST_HOT_SOSTNF->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDGUEST_HOT_SOSTNF->AsString=DocTIDGUEST_HOT_SOSTNF->AsString;
		}
	//номер
	if(glStrToInt64(DocTIDNOMER_HOT_SOSTNF->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDNOMER_HOT_SOSTNF->AsString=DocTIDNOMER_HOT_SOSTNF->AsString;
		}
	//категория
	if (glStrToInt64(DocTIDCAT_HOT_SOSTNF->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDCAT_HOT_SOSTNF->AsString=DocTIDCAT_HOT_SOSTNF->AsString;
		}
	//тип поселения
	if(glStrToInt64(DocTIDTPOS_HOT_SOSTNF->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDTPOS_HOT_SOSTNF->AsString=DocTIDTPOS_HOT_SOSTNF->AsString;
		}
	//состояние
	if(glStrToInt64(DocTIDSOST_HOT_SOSTNF->AsString)!=0)
		{
		HOT_DMTableSostNF->ElementIDSOST_HOT_SOSTNF->AsString=DocTIDSOST_HOT_SOSTNF->AsString;
		}

	HOT_DMTableSostNF->ElementKOLM_HOT_SOSTNF->AsInteger=DocTKOLM_HOT_SOSTNF->AsInteger;
	HOT_DMTableSostNF->ElementPOSNACH_HOT_SOSTNF->AsDateTime=DocTPOSNACH_HOT_SOSTNF->AsDateTime;
	HOT_DMTableSostNF->ElementPOSCON_HOT_SOSTNF->AsDateTime=DocTPOSCON_HOT_SOSTNF->AsDateTime;
	HOT_DMTableSostNF->Element->Post();
	HOT_DMTableSostNF->SaveElement();

	DocT->Edit();
	if (glStrToInt64(HOT_DMTableSostNF->ElementID_HOT_SOSTNF->AsString)!=0)
		{
		DocTIDSOST_HOT_DBRONT->AsString=HOT_DMTableSostNF->ElementID_HOT_SOSTNF->AsString;
		}
	DocT->Post();


	DocT->Next();
	}


HOT_DMTableSostNF->kanRelease();
//-----------------------






try
        {
//        if (CancelDvRegDoc()==true)
//                {
		IdDocH=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();

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
bool THOT_DMDocBron::DvRegDoc(void)
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
bool THOT_DMDocBron::CancelDvRegDoc(void)
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

bool THOT_DMDocBron::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
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


void __fastcall THOT_DMDocBron::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------



void __fastcall THOT_DMDocBron::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCH_HOT_DBRONT->AsString=DocAllID_HOT_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_HOT_DBRONT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		}


}
//---------------------------------------------------------------------------
void THOT_DMDocBron::AddString(void)
{
DocT->Append();
}
//----------------------------------------------------------------------------
void THOT_DMDocBron::DeleteString(void)
{
DocT->Delete();
}
//----------------------------------------------------------------------------

void __fastcall THOT_DMDocBron::DocAllIDBASE_HOT_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_HOT_DBRON->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_HOT_DBRONT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocBron::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCH_HOT_DBRON->AsString=DocAllID_HOT_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	DocIDBASE_HOT_DBRON->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

