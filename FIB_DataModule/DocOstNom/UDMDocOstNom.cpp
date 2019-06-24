//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocOstNom.h"

#include "IDMSetup.h"
#include "IDMSprTypePrice.h"
#include "IDMDocInv.h"
#include "IDMSprPrice.h"
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
__fastcall TDMDocOstNom::TDMDocOstNom(TComponent* Owner)
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

void __fastcall TDMDocOstNom::DataModuleCreate(TObject *Sender)
{

SkladRozn=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocOstNom::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
DocOsn->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

TypeNom->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPart.1",IID_IDMSprPart,
													(void**)&Part);
Part->Init(InterfaceMainObject,InterfaceOwnerObject);

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMDocOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocOstNom::DataModuleDestroy(TObject *Sender)
{
Part->kanRelease();
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;
Grp->Active=false;
El->Active=false;
IBQ->Active=false;
DocOsn->Active=false;
TypeNom->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMDocOstNom::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=0;
Doc->ParamByName("ID")->AsInt64=0;
DocT->ParamByName("ID")->AsInt64=0;

DocAll->Active=true;
Doc->Active=true;
TypeNom->Active=true;
DocT->Active=true;


DocAll->Append();
Doc->Append();
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOCOSN->AsString=IdDoc;


DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="OSN";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
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

//закупочный тип цен
Doc->Edit();
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
DMSetup->OpenElement(30);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		DocIDTPRICEOSN->AsString=StrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
		}
DMSetup->kanRelease();

IDMSprTypePrice *tp;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
													(void**)&tp);
tp->Init(InterfaceMainObject,InterfaceOwnerObject);
tp->OpenElement(glStrToInt64(DocIDTPRICEOSN->AsString));
DocNAME_TPRICE->AsString=tp->ElementNAME_TPRICE->AsString;
tp->kanRelease();
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
int TDMDocOstNom::GetNumberNewDoc(void)
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
void TDMDocOstNom::OpenDoc(__int64 id_doc)
{
IdDoc=id_doc;
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=IdDoc;
Doc->ParamByName("ID")->AsInt64=IdDoc;
DocT->ParamByName("ID")->AsInt64=IdDoc;

DocAll->Active=true;
Doc->Active=true;
TypeNom->Active=true;
DocT->Active=true;


DocOsn->ParamByName("PARAM_IDDOC")->AsInt64=glStrToInt64(DocAllIDDOCOSNDOC->AsString);
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
void TDMDocOstNom::AddDocNewString()
{
DocT->Append();
DocTIDDOCOSNT->AsString=DocAllIDDOC->AsString;
DocT->Post();
}
//---------------------------------------------------------------------------
void TDMDocOstNom::DeleteStringDoc(void)
{
DocT->Delete();
}


//---------------------------------------------------------------------------
bool TDMDocOstNom::SaveDoc(void)
{
bool Res=false;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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

//запишем партии
DocT->First();
while (!DocT->Eof)
        {
        if (DocTTNOM->AsInteger==0)   //создаем партии только для товаров
                {
				if (glStrToInt64(DocTIDPARTOSNT->AsString)==0)
					{ //создаем нову пратию
					CreateNewPart();
					DocT->Edit();
					DocTIDPARTOSNT->AsString=Part->ElementIDPART->AsString;
					DocT->Post();

					}
				else
					{
					Part->OpenElement(glStrToInt64(DocTIDPARTOSNT->AsString));
					if ((glStrToInt64(Part->ElementIDDOCPART->AsString)==glStrToInt64(DocAllIDDOC->AsString))
						&&(glStrToInt64(Part->ElementIDNOMPART->AsString)==glStrToInt64(DocTIDNOMOSNT->AsString)))
						{ //этот же документ и номеклатура
						}
					else
						{  //не совпадает
						CreateNewPart();
						DocT->Edit();
						DocTIDPARTOSNT->AsString=Part->ElementIDPART->AsString;
						DocT->Post();
						}
					}
				//редактируем свойства партии
				Part->Element->Edit();
				if(glStrToInt64(DocAllIDFIRMDOC->AsString)>0){Part->ElementIDFIRMPART->AsString=DocAllIDFIRMDOC->AsString;}
				if(glStrToInt64(DocAllIDKLDOC->AsString)>0){Part->ElementIDKLPART->AsString=DocAllIDKLDOC->AsString;}

				Part->ElementPRICEZPART->AsFloat=DocTPRICEOSNT->AsFloat;
				Part->ElementDOCPART->AsString="Ввод остатков "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsString;
				Part->ElementGTDPART->AsString=DocTGTDPART->AsString;
				Part->ElementSERTPART->AsString=DocTSERTPART->AsString;
				if (DocTSRGODNPART->AsFloat!=0)
					{
					Part->ElementSRGODNPART->AsDateTime=DocTSRGODNPART->AsDateTime;
					}
				Part->Element->Post();
				Part->SaveElement(); 
				}
        DocT->Next();
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
//----------------------------------------------------------------------------
void TDMDocOstNom::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();


        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        NumDoc->Active=false;

}
//---------------------------------------------------------------------------

void TDMDocOstNom::CreateNewPart(void)
{

Part->NewElement(glStrToInt64(DocTIDNOMOSNT->AsString));
Part->Element->Edit();
if(glStrToInt64(DocAllIDDOC->AsString)>0){Part->ElementIDDOCPART->AsString=DocAllIDDOC->AsString;}
Part->Element->Post();

//Part->NewElement(DocTIDNOMOSNT->AsInt64);
//Part->Element->Edit();
//Part->ElementIDDOCPART->AsInt64=DocAllIDDOC->AsInt64;
//Part->ElementIDFIRMPART->AsInt64=DocAllIDFIRMDOC->AsInt64;
////Part->ElementIDKLPART->AsInteger=DocAllIDKLDOC->AsInteger;
//Part->ElementPRICEZPART->AsFloat=DocTPRICEOSNT->AsFloat;
//Part->ElementDOCPART->AsString="Ввод остатков "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsDateTime;
//Part->Element->Post();
//Part->SaveElement();
}

//---------------------------------------------------------------------------
bool TDMDocOstNom::DvRegDoc(void)
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
//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
//pFIBQ->ExecQuery();
//if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
//	{
//	SkladRozn=true;
//	}
//else
//	{
//	SkladRozn=false;
//	}
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
//try
//		{
//
//	   DocT->First();
//        while (!DocT->Eof)
//				{
//                if (DocTTNOM->AsInteger==0)  //товар
//						{
//						TovarNaSklad();
//						}
//                DocT->Next();
//				}
//
//
//        Doc2->Active=false;
//		Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//        Doc2->Active=true;
//		Doc2->Edit();
//		Doc2PRDOC->AsInteger=1;
//		Doc2->Post();
//
//		IBTrDvReg->Commit();
//
//	   TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//
//	   Res=true;
//		}
//
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Error=true;
//				TextError=exception.Message;
//				Res=false;
//				}
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

//---------------------------------------------------------------------------
bool TDMDocOstNom::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
        {
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
        }

////по регистру остатки товаров
//DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру остатки товаров
//DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//try
//        {
//		if (DMRegOstNom->CancelDvReg()==true &&
//					DMRegGoods->CancelDvReg()==true)
//                {
//                Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//                Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//                Doc2->Post();
//                IBTrDvReg->Commit();
//
//                TDMSetup * DMSetup=new TDMSetup(Application);
//                DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
//                result=true;
//                }
//		}
//
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Error=true;
//				TextError=exception.Message;
//				result=false;
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
double TDMDocOstNom::Summa()
{
SummaDoc=0;
bool enabled=DataSourceDocT->Enabled;
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUMOSNT->AsFloat;
        DocT->Next();
        }
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=enabled;

return SummaDoc;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

bool TDMDocOstNom::DeleteDoc(__int64 id)
{
bool res=false;

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


OpenDoc(id);

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
//----------------------------------------------------------------------------


__int64 TDMDocOstNom::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;

		pFIBQ->Close();
        pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='OSN'");
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




void __fastcall TDMDocOstNom::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocRSUM_DOSN->AsFloat=DocRSUM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMOSNT->AsFloat;
OldRSummaStr=DocTRSUM_DOSNT->AsFloat;	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocOstNom::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocOstNom::DocTKOLOSNTChange(TField *Sender)
{
OldSummaStr=DocTSUMOSNT->AsFloat;
DocTSUMOSNT->AsFloat=NewSummaStr=DocTKOLOSNT->AsFloat
                        *DocTPRICEOSNT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

OldRSummaStr=DocTRSUM_DOSNT->AsFloat; 
DocTRSUM_DOSNT->AsFloat=NewRSummaStr=DocTKOLOSNT->AsFloat
						*DocTRPRICE_DOSNT->AsFloat;
Doc->Edit();
DocRSUM_DOSN->AsFloat=DocRSUM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTPRICEOSNTChange(TField *Sender)
{
OldSummaStr=DocTSUMOSNT->AsFloat;

DocTSUMOSNT->AsFloat=NewSummaStr=DocTKOLOSNT->AsFloat
						*DocTPRICEOSNT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------
bool TDMDocOstNom::AddDataInv(void)
{
bool result=false;
//DataSourceDocT->Enabled=false;
//TBookmark BM;
//BM=DocT->GetBookmark();

try
	{
	//заполним акт списания по инвентаризации
	IDMDocInv * DMDocInv;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv,
													(void**)&DMDocInv);
	DMDocInv->Init(InterfaceMainObject,InterfaceOwnerObject);
	DMDocInv->OpenDoc(glStrToInt64(DocAllIDDOCOSNDOC->AsString));
	DMDocInv->DocT->First();
	while(!DMDocInv->DocT->Eof)
		{
		if(DMDocInv->DocTKOLFAKT_INVT->AsFloat-DMDocInv->DocTKOLUCH_INVT->AsFloat>0)
			{
			if (SearchStringPoNom(glStrToInt64(DMDocInv->DocTIDNOM_INVT->AsString))==false)
				{  //добавляем новую строку
				AddDocNewString();
				DocT->Edit();
				DocTIDNOMOSNT->AsString=DMDocInv->DocTIDNOM_INVT->AsString;
				DocTNAMENOM->AsString=DMDocInv->DocTNAMENOM->AsString;
				DocTIDEDOSNT->AsString=DMDocInv->DocTIDED_INVT->AsString;
				DocTNAMEED->AsString=DMDocInv->DocTNAMEED->AsString;
				DocTKFOSNT->AsFloat=DMDocInv->DocTKF_INVT->AsFloat;
				IDMSprPrice * dm_price;

				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceOwnerObject);
						dm_price->FindElement(glStrToInt64(DocIDTPRICEOSN->AsString),
											 glStrToInt64(DocTIDNOMOSNT->AsString));
						DocTPRICEOSNT->AsFloat=dm_price->ElementZNACH_PRICE->AsFloat*DocTKFOSNT->AsFloat;
				dm_price->kanRelease();
				DocT->Post();
				}
			DocT->Edit();
			DocTKOLOSNT->AsFloat=DMDocInv->DocTKOLFAKT_INVT->AsFloat-DMDocInv->DocTKOLUCH_INVT->AsFloat;
			DocT->Post();
			SaveDoc();
			}
		DMDocInv->DocT->Next();
		}



	DocT->First();
	while (!DocT->Eof)
		{
//		ShowMessage("текущая строка : "+IntToStr(DocT->RecNo));
//		if (DocT->RecNo==121)
//			{
//			ShowMessage("");
//			}

		if (DMDocInv->SearchStringPoNom(glStrToInt64(DocTIDNOMOSNT->AsString))==true)
			{
			if(DMDocInv->DocTKOLFAKT_INVT->AsFloat-DMDocInv->DocTKOLUCH_INVT->AsFloat>0)
				{
				DocT->Next();
				}
			else
				{
				DocT->Delete();
//				DocT->Edit();
//				DocTKOLOSNT->AsFloat=0;
//				DocT->Post();
//				DocT->Next();
				}
			}
		else
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
	TextError=exception.Message + " Текущая строка: "+IntToStr(DocT->RecNo)
		+"  "+DocTNAMENOM->AsString;
	}



return result;
}
//----------------------------------------------------------------------------
bool TDMDocOstNom::SearchStringPoNom(__int64 id_nom)
{
bool result=false;

TLocateOptions SearchOptions;
if(DocT->Locate("IDNOMOSNT",id_nom,SearchOptions)==true)
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
void __fastcall TDMDocOstNom::DocAllIDSKLDOCChange(TField *Sender)
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

void __fastcall TDMDocOstNom::DocTRPRICE_DOSNTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DOSNT->AsFloat;

DocTRSUM_DOSNT->AsFloat=NewRSummaStr=DocTKOLOSNT->AsFloat
						*DocTRPRICE_DOSNT->AsFloat;
Doc->Edit();
DocRSUM_DOSN->AsFloat=DocRSUM_DOSN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTSUMOSNTChange(TField *Sender)
{
if (DocTSUMOSNT->AsFloat>0.001)
	{
	DocTNAC_DOSNT->AsFloat=((DocTRSUM_DOSNT->AsFloat-DocTSUMOSNT->AsFloat)
			/DocTSUMOSNT->AsFloat)*100;
	 }

int nds=glGetRateNDS(DocTNDS_DOSNT->AsInteger);
DocTSUMNDS_DOSNT->AsFloat=
		(DocTSUMOSNT->AsFloat/(100+nds))*nds;

}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTRSUM_DOSNTChange(TField *Sender)
{
if (DocTSUMOSNT->AsFloat>0.001)
	{
	DocTNAC_DOSNT->AsFloat=((DocTRSUM_DOSNT->AsFloat-DocTSUMOSNT->AsFloat)
			/DocTSUMOSNT->AsFloat)*100;
	 }
}
//---------------------------------------------------------------------------


void __fastcall TDMDocOstNom::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCOSN->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DOSN->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCOSNT->AsString=DocAllIDBASE_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DOSNT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DOSN->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DOSNT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocOstNom::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

