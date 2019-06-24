//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocSpisNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNomRest.h"
#include "IDMSprSostProd.h"
#include "IDMDocInv.h"
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
__fastcall TDMDocSpisNom::TDMDocSpisNom(TComponent* Owner)
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
void __fastcall TDMDocSpisNom::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocSpisNom::Init(void)
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
Grp->Database=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;
DocOsn->Database=DM_Connection->pFIBData;
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
//----------------------------------------------------------------------------
int TDMDocSpisNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSpisNom::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();

DocOsn->Active=false;

 if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocSpisNom::NewDoc(void)
{
flGetNumberDoc=false;

        DocAll->Open();
        Doc->Open();
		DocAll->Append();
		Doc->Append();
		DocT->Open();


IdDoc=DocAllIDDOC->AsInt64;
DocIDDOCSPN->AsInt64=IdDoc;
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="SPN";

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




	IDMQueryRead *q;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
	q->Init(InterfaceMainObject,InterfaceOwnerObject);
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add(" select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
	q->pFIBQ->ExecQuery();
	if (q->pFIBQ->FieldByName("TSKLAD")->AsInteger==1 && q->pFIBQ->RecordCount==1)
		{
		SkladRozn=true;
		}
	else
		{
		SkladRozn=false;
		}
	q->kanRelease();


flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();

}
//----------------------------------------------------------------------------
int TDMDocSpisNom::GetNumberNewDoc(void)
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
void TDMDocSpisNom::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
		DocT->Active=false;
		DocOsn->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;
		DocT->ParamByName("ID")->AsInt64=Id;


        DocAll->Open();
        Doc->Open();
		DocT->Open();

		DocOsn->ParamByName("PARAM_IDDOC")->AsInt64=DocAllIDDOCOSNDOC->AsInt64;
		DocOsn->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}

IdDoc=DocAllIDDOC->AsInt64;
}

//----------------------------------------------------------------------------
void TDMDocSpisNom::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocSpisNom::SaveDoc(void)
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
void TDMDocSpisNom::AddDocNewString(void)
{
DocT->Append();
DocTIDDOCSPNT->AsInt64=DocAllIDDOC->AsInt64;
DocT->Post();

}
//-----------------------------------------------------------------------------
void TDMDocSpisNom::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocSpisNom::Summa(void)
{
bool enabled=DataSourceDocT->Enabled;
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUMSPNT->AsFloat;
        DocT->Next();
        }
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=enabled;

return SummaDoc;
}
//----------------------------------------------------------------------------
bool TDMDocSpisNom::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//DataSourceDocT->Enabled=false;
//TBookmark BM;
//BM=DocT->GetBookmark();
//
//if (CancelDvRegDoc()!=true)
//		{
//		Res=false;
//		return Res;
//		}
//
////заполним данными инвентаризации
//if(DocAllIDDOCOSNDOC->AsInteger!=0)
//	{
//	if (AddDataInv()!=true)
//		{
//		Res=false;
//		return Res;
//		}
//	}
//
//TDMQueryRead *q=new TDMQueryRead(Application);
//q->pFIBQ->Close();
//q->pFIBQ->SQL->Clear();
//q->pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
//q->pFIBQ->ExecQuery();
//if (q->pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
//	{
//	SkladRozn=true;
//	}
//else
//	{
//	SkladRozn=false;
//	}
//delete q;
//
////проверим запрет на отрицательные остатки
//TDMSetup * DMSetup=new TDMSetup(Application);
//DMSetup->OpenElement(12);
//NoOtrOstatok=false;
//if (DMSetup->ElementVALUE_SETUP->AsString=="1")
//	{
//	NoOtrOstatok=true;
//	}
//delete DMSetup;
//
//try
//        {
//
//        
//        DocT->First();
//        while (!DocT->Eof)
//				{
//                if (DocTTNOM->AsInteger==0)  //товар
//						{
//						SebNom=0;
//						IdSklad=DocAllIDSKLDOC->AsInteger;
//						SpisatNomSoSklada(DocTIDNOMSPNT->AsInteger,
//									DocTKOLSPNT->AsFloat*DocTKFSPNT->AsFloat);
//
//						DocT->Edit();
//						if (DocTKOLSPNT->AsFloat!=0)
//							{
//							DocTPRICESPNT->AsFloat=SebNom/DocTKOLSPNT->AsFloat;
//							}
//						DocTSUMSPNT->AsFloat=SebNom;
//						DocT->Post();
//
//						}
//
//
//                if (DocTTNOM->AsInteger==2)  //продукция
//						{
//						SebProd=0;
//                        SpisatProdSoSklada();
//						DocT->Edit();
//						if (DocTKOLSPNT->AsFloat!=0)
//							{
//							DocTPRICESPNT->AsFloat=SebProd/DocTKOLSPNT->AsFloat;
//							}
//						DocTSUMSPNT->AsFloat=SebProd;
//                        DocT->Post();
//                        }
//
//
//
//                DocT->Next();
//                }
//
//
//
////		Doc2->Active=false;
////		Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
////		Doc2->Active=true;
////		Doc2->Edit();
////		Doc2PRDOC->AsInteger=1;
////		Doc2->Post();
//        if(IBTrDvReg->Active==true)
//                {
//                IBTrDvReg->Commit();
//				}
//		DocAll->Edit();
//		DocAllPRDOC->AsInteger=1;
//		DocAll->Post();
//		SaveDoc();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//       DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//
//        Res=true;
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Res=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//
//
//DocT->GotoBookmark(BM);
//DocT->FreeBookmark(BM);
//DataSourceDocT->Enabled=true;
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
bool TDMDocSpisNom::CancelDvRegDoc(void)
{

bool result=false;
if (Prosmotr==true)
		{

		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}
////по регистру остатки товаров
//DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру отр. списание
//DMRegOtrSpisNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру остатки товаров
//DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//
//
//try
//        {
//		if (DMRegOstNom->CancelDvReg()==true &&
//				DMRegGoods->CancelDvReg()==true &&
//                DMRegOtrSpisNom->CancelDvReg()==true)
//				{
//                Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//                Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//                IBTrDvReg->Commit();
//
//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;
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








//---------------------------------------------------------------------------
bool TDMDocSpisNom::DeleteDoc(__int64 id)
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



void __fastcall TDMDocSpisNom::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocRSUM_DSPN->AsFloat=DocRSUM_DSPN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMSPNT->AsFloat;
OldRSummaStr=DocTRSUM_DSPNT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCSPNT->AsInt64=DocAllIDDOC->AsInt64;
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocTIDBASE_DSPNT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

bool TDMDocSpisNom::AddDataInv(void)
{
bool result=false;


try
	{

	IDMDocInv * DMDocInv;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv,
													(void**)&DMDocInv);
DMDocInv->Init(InterfaceMainObject,InterfaceOwnerObject);
	DMDocInv->OpenDoc(glStrToInt64(DocAllIDDOCOSNDOC->AsString));
	//заполним акт списания по инвентаризации

	DMDocInv->DocT->First();
	while(!DMDocInv->DocT->Eof)
		{
			if(DMDocInv->DocTKOLUCH_INVT->AsFloat-DMDocInv->DocTKOLFAKT_INVT->AsFloat>0)
				{
				if (SearchStringPoNom(glStrToInt64(DMDocInv->DocTIDNOM_INVT->AsString))==false)
					{  //добавляем новую строку
					AddDocNewString();
					DocT->Edit();
					DocTIDNOMSPNT->AsInt64=DMDocInv->DocTIDNOM_INVT->AsLargeInt;
					DocTNAMENOM->AsString=DMDocInv->DocTNAMENOM->AsString;
					DocTIDEDSPNT->AsInt64=DMDocInv->DocTIDED_INVT->AsLargeInt;
					DocTNAMEED->AsString=DMDocInv->DocTNAMEED->AsString;
					DocTKFSPNT->AsFloat=DMDocInv->DocTKF_INVT->AsFloat;
					DocT->Post();
					}
				DocT->Edit();
				DocTKOLSPNT->AsFloat=DMDocInv->DocTKOLUCH_INVT->AsFloat-DMDocInv->DocTKOLFAKT_INVT->AsFloat;
				DocT->Post();
				SaveDoc();
				}
		DMDocInv->DocT->Next();
		}



	//удалим строки которые есть в акте списания но нет в инвентаризации
	DocT->First();
	while (!DocT->Eof)
		{
		if (DMDocInv->SearchStringPoNom(DocTIDNOMSPNT->AsInteger)==true)
			{  //нашли строку
				if(DMDocInv->DocTKOLUCH_INVT->AsFloat-DMDocInv->DocTKOLFAKT_INVT->AsFloat>0)
					{  //недостача
					DocT->Next();
					}
				else
					{ //излишек
					DocT->Delete();
					}
			}
		else //не нашли
			{
			DocT->Delete();
			}
		}


	DMDocInv->kanRelease();
	
	if (SaveDoc()==true)
		{
		result=true;
		}
	else
		{
        result=false;
		}
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;

	}



return result;
}
//----------------------------------------------------------------------------
bool TDMDocSpisNom::SearchStringPoNom(__int64 id_nom)
{
bool result=false;

TLocateOptions SearchOptions;
if(DocT->Locate("IDNOMSPNT",id_nom,SearchOptions)==true)
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
void __fastcall TDMDocSpisNom::DocTKOLSPNTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DSPNT->AsFloat;
DocTRSUM_DSPNT->AsFloat=NewRSummaStr=DocTKOLSPNT->AsFloat
						*DocTRPRICE_DSPNT->AsFloat;
Doc->Edit();
DocRSUM_DSPN->AsFloat=DocRSUM_DSPN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocTRPRICE_DSPNTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DSPNT->AsFloat;

DocTRSUM_DSPNT->AsFloat=NewRSummaStr=DocTKOLSPNT->AsFloat
						*DocTRPRICE_DSPNT->AsFloat;
Doc->Edit();
DocRSUM_DSPN->AsFloat=DocRSUM_DSPN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocAllIDSKLDOCChange(TField *Sender)
{
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocSpisNom::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCSPN->AsString=DocAllIDDOC->AsString;
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DSPN->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	Doc->Edit();
	DocIDBASE_DSPN->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocT->Edit();
		DocTIDBASE_DSPNT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSpisNom::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

