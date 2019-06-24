//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocPrihNakl.h"
#include "IDMDocPrihNakl.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
//#include "UDMXTableIsm.h"
#include "IDMSprNacenka.h"
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
__fastcall TDMDocPrihNakl::TDMDocPrihNakl(TComponent* Owner)
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

bool TDMDocPrihNakl::Init(void)
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



InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPart.1",IID_IDMSprPart,
													(void**)&Part);
Part->Init(InterfaceMainObject,InterfaceOwnerObject);

//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
//													(void**)&DMSprPrice);
//DMSprPrice->Init(InterfaceMainObject,InterfaceOwnerObject);

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMDocPrihNakl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocPrihNakl::DataModuleDestroy(TObject *Sender)
{
Part->kanRelease();
//DMSprPrice->kanRelease();

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

void TDMDocPrihNakl::NewDoc(void)
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
DocAllTDOC->AsString="PRN";
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
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
DMSetup->OpenElement(30);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
			{
			DocIDTPRICE->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
			}
		}
else
		{
		if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
			{
			DocIDTPRICE->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
			}
		}

DMSetup->OpenElement(31);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
			{
			DocIDRTPRICE_DPRN->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
			}
		}
else
		{
		if( glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
			{
			DocIDRTPRICE_DPRN->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
			}
		}
DMSetup->kanRelease();

Doc->Post();

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------
int TDMDocPrihNakl::GetNumberNewDoc(void)
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
void TDMDocPrihNakl::CopyDoc(__int64 id_doc)
{
IDMDocPrihNakl * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&doc);
doc->Init(InterfaceMainObject,0);
doc->OpenDoc(id_doc);
NewDoc();
DocAll->Edit();
DocAllIDBASE_GALLDOC->AsString=doc->DocAllIDBASE_GALLDOC->AsString;
DocAllNAME_SINFBASE_OBMEN->AsString=doc->DocAllNAME_SINFBASE_OBMEN->AsString;
DocAllIDFIRMDOC->AsString=doc->DocAllIDFIRMDOC->AsString;
DocAllNAMEFIRM->AsString=doc->DocAllNAMEFIRM->AsString;
DocAllIDSKLDOC->AsString=doc->DocAllIDSKLDOC->AsString;
DocAllNAMESKLAD->AsString=doc->DocAllNAMESKLAD->AsString;
DocAllIDKLDOC->AsString=doc->DocAllIDKLDOC->AsString;
DocAllNAMEKLIENT->AsString=doc->DocAllNAMEKLIENT->AsString;
DocAll->Post();

Doc->Edit();
DocIDRTPRICE_DPRN->AsString=doc->DocIDRTPRICE_DPRN->AsString;
DocIDTPRICE->AsString=doc->DocIDTPRICE->AsString;
Doc->Post();

doc->DocT->First();
while (!doc->DocT->Eof)
	{
	DocT->Append();
	DocT->Edit();
	DocTIDNOMPRNT->AsString=doc->DocTIDNOMPRNT->AsString;
	DocTNAMENOM->AsString=doc->DocTNAMENOM->AsString;
	DocTIDEDPRNT->AsString=doc->DocTIDEDPRNT->AsString;
	DocTNAMEED->AsString=doc->DocTNAMEED->AsString;
	DocTKFPRNT->AsFloat=doc->DocTKFPRNT->AsFloat;
	DocTKOLPRNT->AsFloat=doc->DocTKOLPRNT->AsFloat;
	DocTNAC_DPRNT->AsFloat=doc->DocTNAC_DPRNT->AsFloat;
	DocTPRICEPRNT->AsFloat=doc->DocTPRICEPRNT->AsFloat;
	DocTRPRICE_DPRNT->AsFloat=doc->DocTRPRICE_DPRNT->AsFloat;
    DocTTNOM->AsInteger=doc->DocTTNOM->AsInteger;
	DocT->Post();
	doc->DocT->Next();
    }
doc->kanRelease();
}
//---------------------------------------------------------------------------
void TDMDocPrihNakl::OpenDoc(__int64 id)
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


pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}


}
//-----------------------------------------------------------------------------
void TDMDocPrihNakl::AddDocNewString()
{
DocT->Append();
//DocT->FieldByName("IDDOCPRNT")->AsInteger=DocAll->FieldByName("IDDOC")->AsInteger;
//DocT->Post();

//DocIDTPRICE->ReadOnly=true;
}
//---------------------------------------------------------------------------
void TDMDocPrihNakl::DeleteStringDoc(void)
{
DocT->Delete();
//if (DocT->RecordCount==0)
//        {
//        DocIDTPRICE->ReadOnly=false;
//        }
}
//---------------------------------------------------------------------------
bool TDMDocPrihNakl::SaveDoc(void)
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
//
//
//запишем параметры партии
DocT->First();
while (!DocT->Eof)
		{
		if (glStrToInt64(DocTIDPARTPRNT->AsString)==0)
                { //создаем нову пратию
				CreateNewPart();
                DocT->Edit();
				DocTIDPARTPRNT->AsString=Part->ElementIDPART->AsString;
				DocT->Post();

				}
		else
                {
				Part->OpenElement(glStrToInt64(DocTIDPARTPRNT->AsString));
				if ((glStrToInt64(Part->ElementIDDOCPART->AsString)==glStrToInt64(DocAllIDDOC->AsString))
						&&(glStrToInt64(Part->ElementIDNOMPART->AsString)==glStrToInt64(DocTIDNOMPRNT->AsString)))
						{ //этот же документ и номеклатура
						}
				else
						{  //не совпадает
						CreateNewPart();
						DocT->Edit();
						DocTIDPARTPRNT->AsString=Part->ElementIDPART->AsString;
						DocT->Post();
						}
				}
		//редактируем свойства партии
		Part->Element->Edit();
		if(glStrToInt64(DocAllIDFIRMDOC->AsString)>0){Part->ElementIDFIRMPART->AsString=DocAllIDFIRMDOC->AsString;}
		if(glStrToInt64(DocAllIDKLDOC->AsString)>0){Part->ElementIDKLPART->AsString=DocAllIDKLDOC->AsString;}

		Part->ElementPRICEZPART->AsFloat=DocTPRICEPRNT->AsFloat;
		Part->ElementDOCPART->AsString="Прих. накл. "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsString;
		Part->ElementGTDPART->AsString=DocTGTDPART->AsString;
		Part->ElementSERTPART->AsString=DocTSERTPART->AsString;
		if (DocTSRGODNPART->AsFloat!=0)
			{
			Part->ElementSRGODNPART->AsDateTime=DocTSRGODNPART->AsDateTime;
			}
		Part->Element->Post();
		Part->SaveElement();
		DocT->Next();
        }
//
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

void TDMDocPrihNakl::CreateNewPart(void)
{
Part->NewElement(glStrToInt64(DocTIDNOMPRNT->AsString));
Part->Element->Edit();
if(glStrToInt64(DocAllIDDOC->AsString)>0){Part->ElementIDDOCPART->AsString=DocAllIDDOC->AsString;}
Part->Element->Post();

}

//---------------------------------------------------------------------------
bool TDMDocPrihNakl::DvRegDoc(void)
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
bool TDMDocPrihNakl::CancelDvRegDoc(void)
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
double TDMDocPrihNakl::Summa()
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
double SumRozn=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocTSUMPRNT->AsFloat;
		SumRozn=SumRozn+DocTRSUM_DPRNT->AsFloat;
		DocT->Next();
		}
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

Doc->Edit();
DocRSUM_DPRN->AsFloat=SumRozn;
Doc->Post();

return SummaDoc;
}


//---------------------------------------------------------------------------
void __fastcall TDMDocPrihNakl::DocT1CalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}

//---------------------------------------------------------------------------


bool TDMDocPrihNakl::DeleteDoc(__int64 id)
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

__int64 TDMDocPrihNakl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='PRN'");
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




void __fastcall TDMDocPrihNakl::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocRSUM_DPRN->AsFloat=DocRSUM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMPRNT->AsFloat;
OldRSummaStr=DocTRSUM_DPRNT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCPRNT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DPRNT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPrihNakl::DocTKOLPRNTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUMPRNT->AsFloat;

DocTSUMPRNT->AsFloat=NewSummaStr=DocTKOLPRNT->AsFloat*DocTPRICEPRNT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

		}

OldRSummaStr=DocTRSUM_DPRNT->AsFloat;

DocTRSUM_DPRNT->AsFloat=NewRSummaStr=DocTKOLPRNT->AsFloat*DocTRPRICE_DPRNT->AsFloat;
Doc->Edit();
DocRSUM_DPRN->AsFloat=DocRSUM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPrihNakl::DocTPRICEPRNTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUMPRNT->AsFloat;

DocTSUMPRNT->AsFloat=NewSummaStr=DocTKOLPRNT->AsFloat*DocTPRICEPRNT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
		}	
}
//---------------------------------------------------------------------------
bool TDMDocPrihNakl::UpdatePrice(void)
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
BM=DocT->GetBookmark();
IDMSprNacenka *dm_nac;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNacenka.1",IID_IDMSprNacenka,
													(void**)&dm_nac);
dm_nac->Init(InterfaceMainObject,0);

IDMSprNom *dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,0);

IDMSprPrice *dm_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
dm_price->Init(InterfaceMainObject,0);

DocT->First();
while (!DocT->Eof)
		{
		dm_nom->OpenElement(glStrToInt64(DocTIDNOMPRNT->AsString));
		__int64 id_grp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);
		dm_nac->OpenTable(id_grp);
		dm_nac->Table->First();
		while(!dm_nac->Table->Eof)
			{
			if(dm_price->FindElementPoEd(glStrToInt64(dm_nac->TableIDTPRICE_SNACENKA->AsString),
									glStrToInt64(DocTIDNOMPRNT->AsString),
									glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString))>0)
				{
				dm_price->Element->Edit();
				}
			else
				{
				dm_price->IdNom=glStrToInt64(DocTIDNOMPRNT->AsString);
				dm_price->IdTypePrice=glStrToInt64(dm_nac->TableIDTPRICE_SNACENKA->AsString);
				dm_price->IdBasEd=glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString);
                dm_price->NewElement();
				}
			dm_price->ElementZNACH_PRICE->AsFloat=glRoundValue((DocTPRICEPRNT->AsFloat
										/DocTKFPRNT->AsFloat)
										*((dm_nac->TableVALUE_SNACENKA->AsFloat+100)/100),
										dm_nac->TableOKR_SNACENKA->AsInteger);
			dm_price->Element->Post();
			dm_price->SaveElement();

			dm_nac->Table->Next();
			}

		DocT->Edit();
		if (SkladRozn==true)
			{
			DocTRPRICE_DPRNT->AsFloat=
							dm_price->GetValuePrice(glStrToInt64(DocIDRTPRICE_DPRN->AsString), //тип цен
											glStrToInt64(DocTIDNOMPRNT->AsString),            //номенклатура
											glStrToInt64(DocTIDEDPRNT->AsString),             //единица
											DocTKFPRNT->AsFloat,                              //коэффициент
											glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));            //базовая единица
			}
		else
			{
			DocTRPRICE_DPRNT->AsFloat=0;
			}
		DocT->Post();


		DocT->Next();
		}
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

dm_price->kanRelease();
dm_nac->kanRelease();
dm_nom->kanRelease();

return true;
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocPrihNakl::DocAllIDSKLDOCChange(TField *Sender)
{
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
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

void __fastcall TDMDocPrihNakl::DocTRPRICE_DPRNTChange(TField *Sender)
{

OldRSummaStr=DocTRSUM_DPRNT->AsFloat;

DocTRSUM_DPRNT->AsFloat=NewRSummaStr=DocTKOLPRNT->AsFloat*DocTRPRICE_DPRNT->AsFloat;
Doc->Edit();
DocRSUM_DPRN->AsFloat=DocRSUM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocTSUMPRNTChange(TField *Sender)
{
if (DocTSUMPRNT->AsFloat>0.001)
	{
	DocTNAC_DPRNT->AsFloat=((DocTRSUM_DPRNT->AsFloat-DocTSUMPRNT->AsFloat)
			/DocTSUMPRNT->AsFloat)*100;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocTRSUM_DPRNTChange(TField *Sender)
{
if (DocTSUMPRNT->AsFloat>0.001)
	{
	DocTNAC_DPRNT->AsFloat=((DocTRSUM_DPRNT->AsFloat-DocTSUMPRNT->AsFloat)
			/DocTSUMPRNT->AsFloat)*100;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;

DocTNAC_SUM_ED->AsFloat=DocTRPRICE_DPRNT->AsFloat-DocTPRICEPRNT->AsFloat;
DocTNAC_SUM->AsFloat=DocTRSUM_DPRNT->AsFloat-DocTSUMPRNT->AsFloat;
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPrihNakl::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCPRN->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DPRN->AsString=DocAllIDBASE_GALLDOC->AsString;
	} 
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPrihNakl::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DPRN->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}


	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DPRNT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocPrihNakl::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

