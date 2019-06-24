//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocVosvratPok.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNom.h"
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
__fastcall TDMDocVosvratPok::TDMDocVosvratPok(TComponent* Owner)
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

void __fastcall TDMDocVosvratPok::DataModuleCreate(TObject *Sender)
{

IsmPrice=false;
IsmSum=true;
Prosmotr=false;
flGetNumberDoc=true;

}
//---------------------------------------------------------------------------
bool TDMDocVosvratPok::Init(void)
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
DocOsn->Database=DM_Connection->pFIBData;

NumDoc->Database=DM_Connection->pFIBData;

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPart.1",IID_IDMSprPart,
													(void**)&Part);
Part->Init(InterfaceMainObject,InterfaceOwnerObject);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
DMSprPrice->Init(InterfaceMainObject,InterfaceOwnerObject);


result=true;
return result;
}
//---------------------------------------------------------------------------
int TDMDocVosvratPok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Active=false;
DocT->Active=false;

Part->kanRelease();
DMSprPrice->kanRelease();


}
//---------------------------------------------------------------------------

void TDMDocVosvratPok::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=0;
Doc->ParamByName("ID")->AsInt64=0;

DocAll->Active=true;
Doc->Active=true;

OpenDocOsn();

DocAll->Append();
Doc->Append();
IdDoc=glStrToInt64(DocAllIDDOC->AsString);

DocT->ParamByName("ID")->AsInt64=IdDoc;
DocT->Active=true;

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="VPOK";
if (DM_Connection->UserInfoID_USER->AsInt64!=0)
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

Doc->Edit();
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
//закупочный тип цен
DMSetup->OpenElement(30);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		DocIDTPRICE_DVPOK->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
		}
else
		{
		if (DM_Connection->UserInfoIDTPRICE_USER->AsString!="")
			{
			DocIDTPRICE_DVPOK->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
			}
		}
//тип цен реализации
DMSetup->OpenElement(31);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		DocIDRTPRICE_DVPOK->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
		}
else
		{
		if (DM_Connection->UserInfoIDTPRICE_USER->AsString!="")
			{
			DocIDRTPRICE_DVPOK->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
            }
		}

DMSetup->kanRelease();
Doc->Post();


flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------
int TDMDocVosvratPok::GetNumberNewDoc(void)
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
void TDMDocVosvratPok::OpenDoc(__int64 IdDoc)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=IdDoc;
Doc->ParamByName("ID")->AsInt64=IdDoc;
DocAll->Active=true;
Doc->Active=true;

DocT->ParamByName("ID")->AsInt64=IdDoc;
DocT->Active=true;


DocAllIDBASE_GALLDOC->ReadOnly=true;
OpenDocOsn();


IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}
//-----------------------------------------------------------------------------
void TDMDocVosvratPok::AddDocNewString()
{
DocT->Append();

}
//---------------------------------------------------------------------------
void TDMDocVosvratPok::DeleteStringDoc(void)
{
DocT->Delete();

}
//---------------------------------------------------------------------------
bool TDMDocVosvratPok::SaveDoc(void)
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

Summa();

//запишем партии
if (glStrToInt64(DocAllIDDOCOSNDOC->AsString) == 0)
	{
	DocT->First();
	while (!DocT->Eof)
        {

		if (glStrToInt64(DocTIDPART_DVPOKT->AsString)==0)
				{ //создаем нову пратию
				CreateNewPart();
				DocT->Edit();
				DocTIDPART_DVPOKT->AsString=Part->ElementIDPART->AsString;
				//ShowMessage(IntToStr(Part->ElementIDPART->AsInteger));
				DocT->Post();

                }
		else
                {
				Part->OpenElement(glStrToInt64(DocTIDPART_DVPOKT->AsString));
				if ((glStrToInt64(Part->ElementIDDOCPART->AsString)==glStrToInt64(DocAllIDDOC->AsString))
						&&(glStrToInt64(Part->ElementIDNOMPART->AsString)==glStrToInt64(DocTIDNOM_DVPOKT->AsString)))
                        {
                        }
				else
                        {
                        CreateNewPart();
                        DocT->Edit();
						DocTIDPART_DVPOKT->AsString=Part->ElementIDPART->AsString;
						DocT->Post();
                        }

                }

		DocT->Next();
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

void TDMDocVosvratPok::CreateNewPart(void)
{
Part->NewElement(glStrToInt64(DocTIDNOM_DVPOKT->AsString));
Part->Element->Edit();

if(glStrToInt64(DocAllIDDOC->AsString)>0){Part->ElementIDDOCPART->AsString=DocAllIDDOC->AsString;}
if(glStrToInt64(DocAllIDFIRMDOC->AsString)>0){Part->ElementIDFIRMPART->AsString=DocAllIDFIRMDOC->AsString;}
if(glStrToInt64(DocAllIDKLDOC->AsString)>0){Part->ElementIDKLPART->AsString=DocAllIDKLDOC->AsString;}

Part->ElementPRICEZPART->AsFloat=DocTPRICE_DVPOKT->AsFloat;
Part->ElementDOCPART->AsString="Возврат "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsString;
Part->Element->Post();
Part->SaveElement();
}

//---------------------------------------------------------------------------
bool TDMDocVosvratPok::DvRegDoc(void)
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
bool TDMDocVosvratPok::CancelDvRegDoc(void)
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
double TDMDocVosvratPok::Summa()
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
double sum_doc=0;
double rozn_sum_doc=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocTRSUM_DVPOKT->AsFloat;
		sum_doc=sum_doc+DocTSUM_DVPOKT->AsFloat;
		rozn_sum_doc=rozn_sum_doc+DocTRSUM_DVPOKT->AsFloat;
		DocT->Next();
		}

DocAll->Edit();
DocAllSUMDOC->AsFloat=rozn_sum_doc;
DocAll->Post();

Doc->Edit();
DocSUM_DVPOK->AsFloat=sum_doc;
Doc->Post();

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}


//---------------------------------------------------------------------------


bool TDMDocVosvratPok::DeleteDoc(__int64 id)
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

__int64 TDMDocVosvratPok::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
int res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {

				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='VPOK'");
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
	}

return res;
}
//---------------------------------------------------------------------------





void __fastcall TDMDocVosvratPok::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DVPOKT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DVPOKT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------
 void __fastcall TDMDocVosvratPok::DocTPRICE_DVPOKTChange(TField *Sender)
{
if (IsmSum==true)
		{
		DocTSUM_DVPOKT->AsFloat=DocTKOL_DVPOKT->AsFloat*DocTPRICE_DVPOKT->AsFloat;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocTRPRICE_DVPOKTChange(TField *Sender)
{
DocTRSUM_DVPOKT->AsFloat=DocTRPRICE_DVPOKT->AsFloat*DocTKOL_DVPOKT->AsFloat;	
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DocTKOL_DVPOKTChange(TField *Sender)
{
if (IsmSum==true)
	{
	DocTRSUM_DVPOKT->AsFloat=DocTKOL_DVPOKT->AsFloat*DocTRPRICE_DVPOKT->AsFloat;
	DocTSUM_DVPOKT->AsFloat=DocTKOL_DVPOKT->AsFloat*DocTPRICE_DVPOKT->AsFloat;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocTKF_DVPOKTChange(TField *Sender)
{
IDMSprPrice * dm_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
dm_price->Init(InterfaceMainObject,InterfaceOwnerObject);
dm_price->FindElement(glStrToInt64(DocIDRTPRICE_DVPOK->AsString), glStrToInt64(DocTIDNOM_DVPOKT->AsString));
DocTRPRICE_DVPOKT->AsFloat=dm_price->ElementZNACH_PRICE->AsFloat
							*DocTKF_DVPOKT->AsFloat;
dm_price->FindElement(glStrToInt64(DocIDTPRICE_DVPOK->AsString), glStrToInt64(DocTIDNOM_DVPOKT->AsString));
DocTPRICE_DVPOKT->AsFloat=dm_price->ElementZNACH_PRICE->AsFloat
								*DocTKF_DVPOKT->AsFloat;
dm_price->kanRelease();
}

//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocTBeforeEdit(TDataSet *DataSet)
{
OldRSum=DocAllSUMDOC->AsFloat-DocTRSUM_DVPOKT->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DocTRSUM_DVPOKTChange(TField *Sender)
{
DocAll->Edit();
DocAllSUMDOC->AsFloat=OldRSum+DocTRSUM_DVPOKT->AsFloat;
DocAll->Post();
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DocTAfterInsert(TDataSet *DataSet)
{
OldRSum=DocAllSUMDOC->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DocTBeforeDelete(TDataSet *DataSet)
{
OldRSummaStr=DocTRSUM_DVPOKT->AsFloat;
OldSummaStr=DocTSUM_DVPOKT->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPok::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------
void TDMDocVosvratPok::AddZakPrice(void)
{
bool save=false;
DocT->First();
while (!DocT->Eof)
	{
	 if (DocTPRICE_DVPOKT->AsFloat==0)
		{
		IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
dm_price->Init(InterfaceMainObject,InterfaceOwnerObject);
		dm_price->FindElement(glStrToInt64(DocIDTPRICE_DVPOK->AsString), glStrToInt64(DocTIDNOM_DVPOKT->AsString));
		DocT->Edit();
		DocTPRICE_DVPOKT->AsFloat=dm_price->ElementZNACH_PRICE->AsFloat
								*DocTKF_DVPOKT->AsFloat;
		DocT->Post();
		dm_price->kanRelease();
		save=true;
		}
	DocT->Next();
	}

if (save==true) SaveDoc(); 
}
//---------------------------------------------------------------------------



void __fastcall TDMDocVosvratPok::DocNewRecord(TDataSet *DataSet)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DVPOK->AsString=DocAllIDBASE_GALLDOC->AsString;
	}

DocIDDOC_DVPOK->AsString=DocAllIDDOC->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DVPOK->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DVPOKT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVosvratPok::DocOsnTDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (glStrToInt64(DocAllIDDOCOSNDOC->AsString)!=0)
	{
	Text=glGetNameDoc(DocOsnTDOC->AsString)+
			" №"+DocOsnNUMDOC->AsString+
			" от "+DocOsnPOSDOC->AsString;
	}
}
//---------------------------------------------------------------------------
void TDMDocVosvratPok::OpenDocOsn(void)
{
DocOsn->Active=false;
DocOsn->ParamByName("PARAM_IDDOC")->AsString=glStrToInt64(DocAllIDDOCOSNDOC->AsString);
DocOsn->Active=true;

}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPok::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

