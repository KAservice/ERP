//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMDocInv.h"
#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
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
__fastcall TDMDocInv::TDMDocInv(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocInv::DataModuleCreate(TObject *Sender)
{
NoEdit=false;
Prosmotr=false;
IdGrpNom=0;
ChangeTable=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocInv::Init(void)
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

NumDoc->Database=DM_Connection->pFIBData;
DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;

pFIBQ->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;
GoodsDataSet->Database=DM_Connection->pFIBData;
OstatkiDataSet->Database=DM_Connection->pFIBData;
IBQPoGrp->Database=DM_Connection->pFIBData;

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
int TDMDocInv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocInv::DataModuleDestroy(TObject *Sender)
{

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;
IBQPoGrp->Active=false;
IBQ->Active=false;
GoodsDataSet->Active=false;
OstatkiDataSet->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMDocInv::NewDoc(void)
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
DocIDDOC_INV->AsString=IdDoc;

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="INV";
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRMDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
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
//---------------------------------------------------------------------------
int TDMDocInv::GetNumberNewDoc(void)
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
AnsiString TDMDocInv::GetTextZaprosDocT(void)
{
AnsiString result="";
result=result+" select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, snom.codenom, snom.artnom, DINVT.*, sed.nameed, sed.shed ";
result=result+" from DINVT ";
result=result+" LEFT OUTER JOIN SNOM  ON IDNOM_INVT=IDNOM";
result=result+" left outer join SED  on  IDED_INVT=IDED";
result=result+" left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom ";
result=result+" where IDDOC_INVT=:PARAM_IDDOC ";

if (IdGrpNom!=0)
        {
        result=result+" and sgrpnom.idgn="+IntToStr(IdGrpNom);
		}


return result;
}
//---------------------------------------------------------------------------
void TDMDocInv::OpenDoc(__int64 id_doc)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_IDDOC")->AsInt64=id_doc;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=id_doc;
DocAll->Active=true;
Doc->Active=true;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);

DocT->SelectSQL->Clear() ;
DocT->SelectSQL->Add(GetTextZaprosDocT());
DocT->ParamByName("PARAM_IDDOC")->AsInt64=id_doc;
DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;

ChangeTable=false;

}
//-----------------------------------------------------------------------------
void TDMDocInv::AddDocNewString()
{
DocT->Append();
ChangeTable=true;
}
//---------------------------------------------------------------------------
void TDMDocInv::DeleteStringDoc(void)
{
DocT->Delete();
ChangeTable=true;
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------
double TDMDocInv::Summa(void)
{
bool enabled=DataSourceDocT->Enabled;

	TBookmark BM;
	DataSourceDocT->Enabled=false;
	BM=DocT->GetBookmark();
double SummaFDoc=0;



DocT->First();
while (!DocT->Eof)
        {
        SummaFDoc=SummaFDoc+DocTSUMF_INVT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=enabled;

return SummaFDoc;
}
//----------------------------------------------------------------------------
bool TDMDocInv::SaveDoc(void)
{
bool Res=false;

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
// ShowMessage("Количество строк "+IntToStr(DocT->RecordCount));
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

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
bool TDMDocInv::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}



DataSourceDocT->Enabled=false;
TBookmark BM;
BM=DocT->GetBookmark();


if (CancelDvRegDoc()!=true)
        {
		result=false;
		return result;
		}

//надо проверку оставить!!!!!!!!!!!!!!!!!!!!!!!
//именно в этом месте а не при записи, чтобы можно было записать большой документ
//проверим на повторяющиеся строки

	TStringList *s=new TStringList();
	s->Add("IDNOM_INVT");
	s->Add("PRICE_INVT");
	bool  b[1]={true};
	DocT->DoSortEx(s, b,100);
	delete s;

__int64 tec_id=0;
double tec_price=0;

DocT->First();
while(!DocT->Eof)
	{
	double r_price=tec_price-DocTPRICE_INVT->AsFloat;
	if (r_price<0) r_price=-r_price;

	if (tec_id==glStrToInt64(DocTIDNOM_INVT->AsString) && r_price < 0.01)
		{

		TextError="Одинаковые номенклатуры в табличной части: "+DocTNAMENOM->AsString;
		result=false;
		DocT->GotoBookmark(BM);
		DocT->FreeBookmark(BM);
		DataSourceDocT->Enabled=true;
		return result;
		}
	else
		{
		tec_id=glStrToInt64(DocTIDNOM_INVT->AsString);
		tec_price=DocTPRICE_INVT->AsFloat;
		}
	DocT->Next();
	}

	s=new TStringList();
	s->Add("ID_INVT");
	DocT->DoSortEx(s, b,100);
	delete s;

SaveDoc();

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

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
bool TDMDocInv::CancelDvRegDoc(void)
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


bool TDMDocInv::DeleteDoc(__int64 id)
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
      //  if (CancelDvRegDoc()!=true)
      //          {
      //          res=false;
      //          return res;
      //          }

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocT->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocAll->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocT->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocAll->CommitUpdToCach();



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


__int64 TDMDocInv::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='INV'");
				pFIBQ->SQL->Add(" and CAST(POSDOC AS DATE)=:PARAM_DATE");
				pFIBQ->ParamByName("PARAM_NUMDOC")->AsInteger=number_doc;
				pFIBQ->ParamByName("PARAM_DATE")->AsDate=date_doc;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("IDDOC")->AsInt64;
                        }
                else res=0;
                pFIBQ->Close();

return res;
}
//---------------------------------------------------------------------------



void __fastcall TDMDocInv::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
ChangeTable=true;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMF_INVT->AsFloat;
ChangeTable=true;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_INVT->AsString=DocAllIDDOC->AsString;
if( glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocTIDBASE_DINVT->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
ChangeTable=true;	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocInv::DocTKOLFAKT_INVTChange(TField *Sender)
{
OldSummaStr=DocTSUMF_INVT->AsFloat;

DocTSUMF_INVT->AsFloat=NewSummaStr=DocTKOLFAKT_INVT->AsFloat*DocTPRICE_INVT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
ChangeTable=true;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocTPRICE_INVTChange(TField *Sender)
{
OldSummaStr=DocTSUMF_INVT->AsFloat;

DocTSUMF_INVT->AsFloat=NewSummaStr=DocTKOLFAKT_INVT->AsFloat*DocTPRICE_INVT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
ChangeTable=true;	
}
//---------------------------------------------------------------------------
void TDMDocInv::AddDataRev(void)
{
GoodsDataSet->Active=false;
GoodsDataSet->ParamByName("PARAM_IDINV")->AsInt64=glStrToInt64(DocIDINV_INV->AsString);
GoodsDataSet->Active=true;

DocT->First();
while(!DocT->Eof)
	{
	DocT->Delete();
	}

GoodsDataSet->First();
while(!GoodsDataSet->Eof)
	{
	DocT->Append();
	DocTIDNOM_INVT->AsString=GoodsDataSetIDNOM_DREVT->AsString;
	DocTIDED_INVT->AsString=GoodsDataSetIDED_DREVT->AsString;
	DocTNAMENOM->AsString=GoodsDataSetNAMENOM->AsString;
	DocTNAMEED->AsString=GoodsDataSetNAMEED->AsString;
	DocTCODENOM->AsInteger=GoodsDataSetCODENOM->AsInteger;
	DocTKF_INVT->AsFloat=1;
	if (GoodsDataSetSUMKOL->AsFloat>0)
		{
		DocTPRICE_INVT->AsFloat=GoodsDataSetRSUM->AsFloat/GoodsDataSetSUMKOL->AsFloat;
		}
	else
		{
        DocTPRICE_INVT->AsFloat=0;
		}
	DocTKOLFAKT_INVT->AsFloat=GoodsDataSetSUMKOL->AsFloat;
	DocTSUMF_INVT->AsFloat=GoodsDataSetRSUM->AsFloat;
    DocT->Post();
	GoodsDataSet->Next();
	}

GoodsDataSet->Active=false;
}
//----------------------------------------------------------------------------
bool TDMDocInv::SearchStringPoNom(__int64 id_nom)
{
bool result=false;

TLocateOptions SearchOptions;
if(DocT->Locate("IDNOM_INVT",id_nom,SearchOptions)==true)
	{
	result=true;
	}
else
	{
	result=false;
	}

return result;
}
//----------------------------------------------------------------------------



void __fastcall TDMDocInv::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_INV->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DINV->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------


void __fastcall TDMDocInv::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DINV->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DINVT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocInv::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocInv::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

