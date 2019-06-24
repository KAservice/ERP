//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocOtchetPost.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMDocOtchetPost::TDMDocOtchetPost(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
IsmPrice=false;
IsmSum=true;
Prosmotr=false;
SkladRozn=false;

flGetNumberDoc=true;
}
//---------------------------------------------------------------------------

bool TDMDocOtchetPost::Init(void)
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
int TDMDocOtchetPost::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocOtchetPost::DataModuleDestroy(TObject *Sender)
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

void TDMDocOtchetPost::NewDoc(void)
{

flGetNumberDoc=false;


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
DocAllTDOC->AsString="OTCHPOST";
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
if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsInt64)!=0)
	{
	DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
DocAll->Post();

Doc->Edit();
//IDMSetup * DMSetup;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//DMSetup->Init(InterfaceMainObject,0);
//DMSetup->OpenElement(30);
//if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
//		{
//		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
//			{
//			DocIDTPRICE->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
//			}
//		}
//else
//		{
//		if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
//			{
//			DocIDTPRICE->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
//			}
//		}
//
//DMSetup->OpenElement(31);
//if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
//		{
//		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
//			{
//			DocIDRTPRICE_DPRN->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
//			}
//		}
//else
//		{
//		if( glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
//			{
//			DocIDRTPRICE_DPRN->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
//			}
//		}
//DMSetup->kanRelease();

Doc->Post();



flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------
int TDMDocOtchetPost::GetNumberNewDoc(void)
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
void TDMDocOtchetPost::CopyDoc(__int64 id_doc)
{
//IDMDocPrihNakl * doc;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
//													(void**)&doc);
//doc->Init(InterfaceMainObject,0);
//doc->OpenDoc(id_doc);
//NewDoc();
//DocAll->Edit();
//DocAllIDBASE_GALLDOC->AsString=doc->DocAllIDBASE_GALLDOC->AsString;
//DocAllNAME_SINFBASE_OBMEN->AsString=doc->DocAllNAME_SINFBASE_OBMEN->AsString;
//DocAllIDFIRMDOC->AsString=doc->DocAllIDFIRMDOC->AsString;
//DocAllNAMEFIRM->AsString=doc->DocAllNAMEFIRM->AsString;
//DocAllIDSKLDOC->AsString=doc->DocAllIDSKLDOC->AsString;
//DocAllNAMESKLAD->AsString=doc->DocAllNAMESKLAD->AsString;
//DocAllIDKLDOC->AsString=doc->DocAllIDKLDOC->AsString;
//DocAllNAMEKLIENT->AsString=doc->DocAllNAMEKLIENT->AsString;
//DocAll->Post();
//
//Doc->Edit();
//DocIDRTPRICE_DPRN->AsString=doc->DocIDRTPRICE_DPRN->AsString;
//DocIDTPRICE->AsString=doc->DocIDTPRICE->AsString;
//Doc->Post();
//
//doc->DocT->First();
//while (!doc->DocT->Eof)
//	{
//	DocT->Append();
//	DocT->Edit();
//	DocTIDNOMPRNT->AsString=doc->DocTIDNOMPRNT->AsString;
//	DocTNAMENOM->AsString=doc->DocTNAMENOM->AsString;
//	DocTIDEDPRNT->AsString=doc->DocTIDEDPRNT->AsString;
//	DocTNAMEED->AsString=doc->DocTNAMEED->AsString;
//	DocTKFPRNT->AsFloat=doc->DocTKFPRNT->AsFloat;
//	DocTKOLPRNT->AsFloat=doc->DocTKOLPRNT->AsFloat;
//	DocTNAC_DPRNT->AsFloat=doc->DocTNAC_DPRNT->AsFloat;
//	DocTPRICEPRNT->AsFloat=doc->DocTPRICEPRNT->AsFloat;
//	DocTRPRICE_DPRNT->AsFloat=doc->DocTRPRICE_DPRNT->AsFloat;
//	DocTTNOM->AsInteger=doc->DocTTNOM->AsInteger;
//	DocT->Post();
//	doc->DocT->Next();
//	}
//doc->kanRelease();
}
//---------------------------------------------------------------------------
void TDMDocOtchetPost::OpenDoc(__int64 id)
{
IdDoc=id;
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=IdDoc;
Doc->ParamByName("ID")->AsInt64=IdDoc;
DocAll->Active=true;
Doc->Active=true;


DocT->ParamByName("ID")->AsInt64=IdDoc;
//DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE->AsInt64;
DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;





}
//-----------------------------------------------------------------------------
void TDMDocOtchetPost::AddDocNewString()
{
DocT->Append();
//DocT->FieldByName("IDDOCPRNT")->AsInteger=DocAll->FieldByName("IDDOC")->AsInteger;
//DocT->Post();

//DocIDTPRICE->ReadOnly=true;
}
//---------------------------------------------------------------------------
void TDMDocOtchetPost::DeleteStringDoc(void)
{
DocT->Delete();
//if (DocT->RecordCount==0)
//        {
//        DocIDTPRICE->ReadOnly=false;
//        }
}
//---------------------------------------------------------------------------
bool TDMDocOtchetPost::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
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

Summa();
DocAll->Edit();
DocAllSUMDOC->AsFloat=SummaDoc;
DocAll->Post();

//собственно сохраняем документ
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



//---------------------------------------------------------------------------
bool TDMDocOtchetPost::DvRegDoc(void)
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
bool TDMDocOtchetPost::CancelDvRegDoc(void)
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
double TDMDocOtchetPost::Summa()
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocTSUM_DOTCHPOSTT->AsFloat;
		DocT->Next();
		}
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;


return SummaDoc;
}


//---------------------------------------------------------------------------
void __fastcall TDMDocOtchetPost::DocT1CalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}

//---------------------------------------------------------------------------


bool TDMDocOtchetPost::DeleteDoc(__int64 id)
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

__int64 TDMDocOtchetPost::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
//pFIBQ->Close();
//				pFIBQ->SQL->Clear();
//				pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='PRN'");
//				pFIBQ->SQL->Add(" and CAST(POSDOC AS DATE)=:PARAM_DATE");
//				pFIBQ->ParamByName("PARAM_NUMDOC")->AsInteger=number_doc;
//				pFIBQ->ParamByName("PARAM_DATE")->AsDate=date_doc;
//				pFIBQ->ExecQuery();
//				if (pFIBQ->RecordCount==1)
//						{
//						res=pFIBQ->FieldByName("IDDOC")->AsInt64;
//						}
//				else res=0;
//pFIBQ->Close();

return res;
}
//---------------------------------------------------------------------------




void __fastcall TDMDocOtchetPost::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_DOTCHPOSTT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DOTCHPOSTT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DOTCHPOSTT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

bool TDMDocOtchetPost::UpdatePrice(void)
{
//DataSourceDocT->Enabled=false;
//TBookmark BM;
//SummaDoc=0;
//BM=DocT->GetBookmark();
//IDMSprNacenka *dm_nac;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNacenka.1",IID_IDMSprNacenka,
//													(void**)&dm_nac);
//dm_nac->Init(InterfaceMainObject,0);
//
//IDMSprNom *dm_nom;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
//													(void**)&dm_nom);
//dm_nom->Init(InterfaceMainObject,0);
//
//IDMSprPrice *dm_price;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
//													(void**)&dm_price);
//dm_price->Init(InterfaceMainObject,0);
//
//DocT->First();
//while (!DocT->Eof)
//		{
//		dm_nom->OpenElement(glStrToInt64(DocTIDNOMPRNT->AsString));
//		__int64 id_grp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);
//		dm_nac->OpenTable(id_grp);
//		dm_nac->Table->First();
//		while(!dm_nac->Table->Eof)
//			{
//			if(dm_price->FindElementPoEd(glStrToInt64(dm_nac->TableIDTPRICE_SNACENKA->AsString),
//									glStrToInt64(DocTIDNOMPRNT->AsString),
//									glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString))>0)
//				{
//				dm_price->Element->Edit();
//				}
//			else
//				{
//				dm_price->IdNom=glStrToInt64(DocTIDNOMPRNT->AsString);
//				dm_price->IdTypePrice=glStrToInt64(dm_nac->TableIDTPRICE_SNACENKA->AsString);
//				dm_price->IdBasEd=glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString);
//                dm_price->NewElement();
//				}
//			dm_price->ElementZNACH_PRICE->AsFloat=glRoundValue((DocTPRICEPRNT->AsFloat
//										/DocTKFPRNT->AsFloat)
//										*((dm_nac->TableVALUE_SNACENKA->AsFloat+100)/100),
//										dm_nac->TableOKR_SNACENKA->AsInteger);
//			dm_price->Element->Post();
//			dm_price->SaveElement();
//
//			dm_nac->Table->Next();
//			}
//
//		DocT->Edit();
//		if (SkladRozn==true)
//			{
//			DocTRPRICE_DPRNT->AsFloat=
//							dm_price->GetValuePrice(glStrToInt64(DocIDRTPRICE_DPRN->AsString), //тип цен
//											glStrToInt64(DocTIDNOMPRNT->AsString),            //номенклатура
//											glStrToInt64(DocTIDEDPRNT->AsString),             //единица
//											DocTKFPRNT->AsFloat,                              //коэффициент
//											glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));            //базовая единица
//			}
//		else
//			{
//			DocTRPRICE_DPRNT->AsFloat=0;
//			}
//		DocT->Post();
//
//
//		DocT->Next();
//		}
//DocT->GotoBookmark(BM);
//DocT->FreeBookmark(BM);
//DataSourceDocT->Enabled=true;
//
//dm_price->kanRelease();
//dm_nac->kanRelease();
//dm_nom->kanRelease();

return true;
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocOtchetPost::DocAllIDSKLDOCChange(TField *Sender)
{

GetNumberNewDoc();
}
//---------------------------------------------------------------------------




void __fastcall TDMDocOtchetPost::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;


}
//---------------------------------------------------------------------------


void __fastcall TDMDocOtchetPost::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DOTCHPOST->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DOTCHPOST->AsString=DocAllIDBASE_GALLDOC->AsString;
	} 
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DOTCHPOST->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}


	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DOTCHPOSTT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocOtchetPost::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocTKOL_DOTCHPOSTTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUM_DOTCHPOSTT->AsFloat;

DocTSUM_DOTCHPOSTT->AsFloat=NewSummaStr=DocTKOL_DOTCHPOSTT->AsFloat*DocTPRICE_DOTCHPOSTT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocOtchetPost::DocTPRICE_DOTCHPOSTTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUM_DOTCHPOSTT->AsFloat;

DocTSUM_DOTCHPOSTT->AsFloat=NewSummaStr=DocTKOL_DOTCHPOSTT->AsFloat*DocTPRICE_DOTCHPOSTT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
		}
}
//---------------------------------------------------------------------------

