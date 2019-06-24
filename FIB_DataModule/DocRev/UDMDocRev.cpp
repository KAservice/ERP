//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocRev.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMTableNumberDoc.h"
#include "IDMSprPrice.h"
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
__fastcall TDMDocRev::TDMDocRev(TComponent* Owner)
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
void __fastcall TDMDocRev::DataModuleCreate(TObject *Sender)
{
NoEdit=false;
Prosmotr=false;
IdGrpNom=0;
ChangeTable=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocRev::Init(void)
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
IBQPoGrp->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
Ostatki->Database=DM_Connection->pFIBData;

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
int TDMDocRev::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DataModuleDestroy(TObject *Sender)
{

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;
IBQPoGrp->Active=false;
IBQ->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMDocRev::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_IDDOC")->AsInt64=0;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=0;
DocT->ParamByName("PARAM_IDDOC")->AsInt64=0;
DocAll->Active=true;
Doc->Active=true;
DocT->Active=true;

DocAll->Append();
Doc->Append();
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOC_DREV->AsString=IdDoc;
Doc->Post();


DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="REV";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
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
//---------------------------------------------------------------------------
int TDMDocRev::GetNumberNewDoc(void)
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
AnsiString TDMDocRev::GetTextZaprosDocT(void)
{
AnsiString result="";
result=result+" select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, snom.codenom, DREVT.*, NAMEED ";
result=result+" from DREVT ";
result=result+" LEFT OUTER JOIN SNOM  ON IDNOM_DREVT=IDNOM";
result=result+" left outer join SED  on  IDED_DREVT=IDED";
result=result+" left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom ";
result=result+" where IDDOC_DREVT=:PARAM_IDDOC ";

if (IdGrpNom!=0)
        {
        result=result+" and sgrpnom.idgn="+IntToStr(IdGrpNom);
        }

return result;
}
//---------------------------------------------------------------------------
void TDMDocRev::OpenDoc(__int64 IdDoc)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
DocAll->Active=true;
Doc->Active=true;


DocT->SelectSQL->Clear() ;
DocT->SelectSQL->Add(GetTextZaprosDocT());
DocT->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;

ChangeTable=false;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}
//-----------------------------------------------------------------------------
void TDMDocRev::AddDocNewString()
{
DocT->Append();
ChangeTable=true;
}
//---------------------------------------------------------------------------
void TDMDocRev::DeleteStringDoc(void)
{
DocT->Delete();
ChangeTable=true;
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------
double TDMDocRev::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
double SummaFDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
		SummaFDoc=SummaFDoc+DocTRSUM_DREVT->AsFloat;
        DocT->Next();
		}

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaFDoc;
}
//----------------------------------------------------------------------------
bool TDMDocRev::SaveDoc(void)
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

if (IdGrpNom==0)
        {
        DocAll->Edit();
        DocAllSUMDOC->AsFloat=Summa();
        DocAll->Post();
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
				TextError=exception.Message;
				Res=false;
				}

return Res;
}


//---------------------------------------------------------------------------
bool TDMDocRev::DvRegDoc(void)
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
bool TDMDocRev::CancelDvRegDoc(void)
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


bool TDMDocRev::DeleteDoc(__int64 id)
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
//		if (CancelDvRegDoc()!=true)
//                {
//                res=false;
//                return res;
//				}

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
//---------------------------------------------------------------------------


__int64 TDMDocRev::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {

				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='REV'");
				query->SQL->Add(" and CAST(POSDOC AS DATE)=:PARAM_DATE");
				query->ParamByName("PARAM_NUMDOC")->AsInteger=number_doc;
				query->ParamByName("PARAM_DATE")->AsDate=date_doc;
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=query->FieldByName("IDDOC")->AsInt64;
                        }
                else res=0;
        }
__finally
	{
	delete query;
	res=0;
	}

return res;
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRev::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
ChangeTable=true;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTRSUM_DREVT->AsFloat;
ChangeTable=true;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DREVT->AsString=DocAllIDDOC->AsString;
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DREVT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
ChangeTable=true;	
}
//---------------------------------------------------------------------------

//при изменении кол, цены ChangeTable=true
void __fastcall TDMDocRev::DocTRPRICE_DREVTChange(TField *Sender)
{
ChangeTable=true;
DocTRSUM_DREVT->AsFloat=DocTRPRICE_DREVT->AsFloat*DocTKOL_DREVT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocTKOL_DREVTChange(TField *Sender)
{
ChangeTable=true;
DocTRSUM_DREVT->AsFloat=DocTRPRICE_DREVT->AsFloat*DocTKOL_DREVT->AsFloat;
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRev::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DREV->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DREV->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DREV->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DREVT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------
void TDMDocRev::AddOstatkiNaSklade(__int64 id_firm, __int64 id_sklad)
{
Ostatki->Active=false;
Ostatki->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Ostatki->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
Ostatki->Active=true;

Ostatki->First();
while(!Ostatki->Eof)
		{
		DocT->Append();
		DocT->Edit();

				DocTIDNOM_DREVT->AsString=OstatkiIDNOM->AsString;
				DocTCODENOM->AsInteger=OstatkiCODENOM->AsInteger;
				DocTNAMENOM->AsString=OstatkiNAMENOM->AsString;
				//DM->DocTTNOM->AsInteger=DM->IBQ->FieldByName("TNOM")->AsInteger;

				DocTIDED_DREVT->AsString=OstatkiIDED->AsString;
				DocTNAMEED->AsString=OstatkiNAMEED->AsString;
				DocTKF_DREVT->AsFloat=OstatkiKFED->AsFloat;
				DocTKOL_DREVT->AsFloat=OstatkiSUM->AsFloat;
				DocTUCH_KOL_DREVT->AsFloat=OstatkiSUM->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceOwnerObject);
						DMSprPrice->FindElement(glStrToInt64(DocIDRTPRICE_DREV->AsString),
											 glStrToInt64(DocTIDNOM_DREVT->AsString));
						DocTRPRICE_DREVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DocTKF_DREVT->AsFloat;
				DMSprPrice->kanRelease();



		DocT->Post();
		Ostatki->Next();
		}

Ostatki->Active=false;
}
//----------------------------------------------------------------------------
void __fastcall TDMDocRev::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRev::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

