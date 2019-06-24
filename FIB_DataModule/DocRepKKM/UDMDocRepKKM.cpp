//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocRepKKM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMSprSostProd.h"
#include "IDMSprNomRest.h"
#include "IDMSetup.h"
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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TDMDocRepKKM::TDMDocRepKKM(TComponent* Owner)
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
void __fastcall TDMDocRepKKM::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
AutoRaschet=false;
EnableDvReg=false;
flGetNumberDoc=true;

}
//---------------------------------------------------------------------------
bool TDMDocRepKKM::Init(void)
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
TableDoc->Database=DM_Connection->pFIBData;
PayDoc->Database=DM_Connection->pFIBData;

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
int TDMDocRepKKM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocRepKKM::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
TableDoc->Active=false;
PayDoc->Active=false;

IBQ->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocRepKKM::NewDoc(void)
{
flGetNumberDoc=false;


DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;

DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);


DocAll->FieldByName("POSDOC")->AsDateTime=Now();
DocAllTDOC->AsString="REPKKM";
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

if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRMDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}

if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}

DocAll->Post();

Doc->Edit();

DocIDDOC_DREPKKM->AsString=IdDoc;

if (glStrToInt64(DM_Connection->UserInfoIDKASSA_USER->AsString)!=0)
	{
	DocIDKKM_DREPKKM->AsString=DM_Connection->UserInfoIDKASSA_USER->AsString;
	DocNAMEKKM->AsString=DM_Connection->UserInfoNAMEKKM->AsString;
	}

Doc->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocRepKKM::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=DocAllIDSKLDOC->AsString;
NumDoc->ParamByName("PARAM_IDKASSA")->AsString=DocIDKKM_DREPKKM->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocRepKKM::OpenDoc(__int64 Id)
{
        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;

		DocAll->ParamByName("PARAM_ID")->AsInt64=Id;
		Doc->ParamByName("PARAM_IDDOC")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
		DocT->ParamByName("PARAM_IDDOC")->AsInt64=Id;
        DocT->Open();
        Summa();

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
void TDMDocRepKKM::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();  

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        NumDoc->Active=false;

}
//----------------------------------------------------------------------------
bool TDMDocRepKKM::SaveDoc(void)
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
void TDMDocRepKKM::AddDocNewString(void)
{
DocT->Append();

}
//-----------------------------------------------------------------------------
void TDMDocRepKKM::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocRepKKM::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

SummaDocFull=0;
SummaSkidok=0;
SummaNadbavok=0;
SummaTable=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_DREPKKMT->AsFloat;
        SummaDocFull=SummaDocFull+DocTPRICEFULL_DREPKKMT->AsFloat
                                * DocTKOL_DREPKKMT->AsFloat
                                * DocTKF_DREPKKMT->AsFloat;
        SummaSkidok=SummaSkidok+DocTSK_DREPKKMT->AsFloat;
        SummaNadbavok=SummaNadbavok+DocTNAD_DREPKKMT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
bool TDMDocRepKKM::DvRegDoc(void)
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
bool TDMDocRepKKM::CancelDvRegDoc(void)
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



bool TDMDocRepKKM::DeleteDoc(__int64 id)
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

bool TDMDocRepKKM::CreateReportKKM( __int64 id_sklad,
								__int64 id_kkm,
								__int64 id_firm,
                                int number_kl ,
                                TDateTime NachInterval,
                                TDateTime ConInterval
                                )
{
bool result=false;

String Zapros="select  IDNOM, NAMENOM, IDED, NAMEED, SUM(SUMCHKT)  AS SUMMA, SUM(KFCHKT*KOLCHKT)  AS SUMKOL,";
Zapros=Zapros+" SUM(SKCHKT)  AS SUMSK, SUM(NADCHKT)  AS SUMNAD ";
Zapros=Zapros+" from  DCHKT ";
Zapros=Zapros+" left outer join DCHK on IDDOCCHKT=IDDOCCHK";
Zapros=Zapros+" left outer join SNOM on IDNOMCHKT=IDNOM";
Zapros=Zapros+" left outer join SED on IDBASEDNOM=IDED";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHKT=IDDOC";
Zapros=Zapros+" where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)";

Zapros=Zapros+" and  IDKKMCHK="+IntToStr(id_kkm);
Zapros=Zapros+" and  IDSKLDOC="+IntToStr(id_sklad);
Zapros=Zapros+" and  IDFIRMDOC="+IntToStr(id_firm);
if (number_kl!=0)
        {
        Zapros=Zapros+" and  NKLCHK="+IntToStr(number_kl);
        }
Zapros=Zapros+" and  (OPERCHK=0 or OPERCHK=2)";


Zapros=Zapros+" group by IDNOM, NAMENOM, IDED, NAMEED ";

TableDoc->SelectSQL->Clear();
TableDoc->SelectSQL->Add(Zapros);
TableDoc->ParamByName("PARAM_POSNACH")->AsDateTime=NachInterval;
TableDoc->ParamByName("PARAM_POSCON")->AsDateTime=ConInterval;
TableDoc->Active=true;
if (TableDoc->RecordCount==0)  return result;

result=true;
return result;
}
//-------------------------------------------------------------------------------
void TDMDocRepKKM::GetSumOplata(__int64 id_sklad,
								__int64 id_kkm,
								__int64 id_firm,
                                int number_kl ,
                                TDateTime NachInterval,
                                TDateTime ConInterval
                                )
{
OplataNal=0;
OplataPC=0;
String Zapros="select  SUM(OPLNALCHK)  AS OPLATANAL, SUM(OPLPCCHK)  AS OPLATAPC";
Zapros=Zapros+" from  DCHK ";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHK=IDDOC";
Zapros=Zapros+" where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)";

Zapros=Zapros+" and  IDKKMCHK="+IntToStr(id_kkm);
Zapros=Zapros+" and  IDSKLDOC="+IntToStr(id_sklad);
Zapros=Zapros+" and  IDFIRMDOC="+IntToStr(id_firm);
if (number_kl!=0)
		{
		Zapros=Zapros+" and  NKLCHK="+IntToStr(number_kl);
		}
Zapros=Zapros+" and  (OPERCHK=0 or OPERCHK=2)";


//Zapros=Zapros+" group by IDNOM, NAMENOM, IDED, NAMEED ";

PayDoc->SelectSQL->Clear();
PayDoc->SelectSQL->Add(Zapros);
PayDoc->ParamByName("PARAM_POSNACH")->AsDateTime=NachInterval;
PayDoc->ParamByName("PARAM_POSCON")->AsDateTime=ConInterval;
PayDoc->Active=true;

OplataNal=PayDoc->FieldByName("OPLATANAL")->AsFloat;
OplataPC= PayDoc->FieldByName("OPLATAPC")->AsFloat;

}
//-------------------------------------------------------------------------------




void __fastcall TDMDocRepKKM::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DREPKKM->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DREPKKM->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

		DocAll->Edit();
		DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
		DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_DREPKKMT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DREPKKMT->AsString=DocAllIDDOC->AsString;
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DREPKKMT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRepKKM::DocTKOL_DREPKKMTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREPKKMT->AsFloat;

DocTSUM_DREPKKMT->AsFloat=NewSummaStr=DocTKOL_DREPKKMT->AsFloat*DocTPRICE_DREPKKMT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocTKF_DREPKKMTChange(TField *Sender)
{
DocTPRICE_DREPKKMT->AsFloat=DocTPRICEFULL_DREPKKMT->AsFloat* DocTKF_DREPKKMT->AsFloat;	
}
//---------------------------------------------------------------------------




void __fastcall TDMDocRepKKM::DocTPRICE_DREPKKMTChange(TField *Sender)
{
OldSummaStr=DocTSUM_DREPKKMT->AsFloat;

DocTSUM_DREPKKMT->AsFloat=NewSummaStr=DocTKOL_DREPKKMT->AsFloat
				*DocTPRICE_DREPKKMT->AsFloat;


		DocAll->Edit();
		DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
		DocAll->Post();	
}
//---------------------------------------------------------------------------



void __fastcall TDMDocRepKKM::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DREPKKM->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DREPKKMT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRepKKM::DocIDKKM_DREPKKMChange(TField *Sender)
{
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------

