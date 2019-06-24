//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocVosvratPost.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMDocVosvratPost::TDMDocVosvratPost(TComponent* Owner)
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
void __fastcall TDMDocVosvratPost::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocVosvratPost::Init(void)
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
int TDMDocVosvratPost::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVosvratPost::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocVosvratPost::NewDoc(void)
{

flGetNumberDoc=false;

        DocAll->Open();
        Doc->Open();
		DocAll->Append();
		Doc->Append();
		DocT->Open();

		IdDoc=glStrToInt64(DocAllIDDOC->AsString);

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="VPO";

SkladRozn=false;

if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
    {
	DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
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

DocAll->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocVosvratPost::GetNumberNewDoc(void)
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
void TDMDocVosvratPost::OpenDoc(__int64 Id)
{

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("ID")->AsInt64=Id;
Doc->ParamByName("ID")->AsInt64=Id;
DocT->ParamByName("ID")->AsInt64=Id;

DocAll->Open();
Doc->Open();
DocT->Open();


IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
DocAllIDBASE_GALLDOC->ReadOnly=true;

IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,InterfaceOwnerObject);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}
q->kanRelease();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}

//----------------------------------------------------------------------------
void TDMDocVosvratPost::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocVosvratPost::SaveDoc(void)
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

bool TDMDocVosvratPost::DeleteDoc(__int64 id)
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
void TDMDocVosvratPost::AddDocNewString(void)
{
DocT->Append();
}
//-----------------------------------------------------------------------------
void TDMDocVosvratPost::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocVosvratPost::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;


BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUMVPOT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
bool TDMDocVosvratPost::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return result;
		}

//if (CancelDvRegDoc()!=true)
//		{
//        Res=false;
//		return Res;
//        }
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
//       DocT->First();
//        while (!DocT->Eof)
//                {
//				if (DocTTNOM->AsInteger==0)  //товар
//						{
//						double KolSpis=DocTKOLVPOT->AsFloat*DocTKFVPOT->AsFloat;
//						//по регистру товары
//						DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//						DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
//						DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInteger;
//						DMRegGoods->IdSklad=DocAllIDSKLDOC->AsInteger;
//						DMRegGoods->IdNom=DocTIDNOMVPOT->AsInteger;
//						DMRegGoods->SkladRozn=SkladRozn;
//						DMRegGoods->RPrice=0;
//						DMRegGoods->Kol=KolSpis;
//						DMRegGoods->Operation=7;
//						DMRegGoods->Type=0;    //0-внешнеее перемещение , 1- внутреннее
//						DMRegGoods->AddRecordRashod();
//
//
//                        //получить таблицу партий
//						TablePart->Active=false;
//						TablePart->ParamByName("IDFIRM")->AsInteger=DocAllIDFIRMDOC->AsInteger;
//						TablePart->ParamByName("IDSKL")->AsInteger=DocAllIDSKLDOC->AsInteger;
//						TablePart->ParamByName("IDNOM")->AsInteger=DocTIDNOMVPOT->AsInteger;
//						TablePart->Active=true;
//
//
//						TablePart->First();
//                        while ((!TablePart->Eof)&&(KolSpis>0))
//								{
//                                 if (TablePartKOLOSTNOM->AsFloat<=KolSpis)
//                                        {
//                                        //полность списывем партию
//                                        SpisatPartSoSklada(TablePartKOLOSTNOM->AsFloat, TablePartSUMOSTNOM->AsFloat);
//										KolSpis=KolSpis-TablePartKOLOSTNOM->AsFloat;
//                                        }
//                                 else
//                                        {
//                                        //частично списываем партию
//										SpisatPartSoSklada(KolSpis,TablePartSUMOSTNOM->AsFloat*KolSpis/TablePartKOLOSTNOM->AsFloat);
//                                        KolSpis=0;
//                                        }
//
//                                TablePart->Next();
//								}
//
//
//						if (KolSpis>0)
//							{
//							if (NoOtrOstatok==true)
//								{
//								AnsiString text_error="Недостаточно товара на  складе (недостаточно ингредиентов для приготовления продукции)!";
//								text_error=text_error+" Строка документа №"+IntToStr(DocT->RecNo);
//								text_error=text_error+", Номенклатура (продукция) "+DocTNAMENOM->AsString;
//								throw Exception(text_error,0);
//								}
//							DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
//							DMRegOstNom->PosDoc=DocAllPOSDOC->AsDateTime;
//							DMRegOstNom->IdFirm=DocAllIDFIRMDOC->AsInteger;
//							DMRegOstNom->IdSklad=DocAllIDSKLDOC->AsInteger;
//							DMRegOstNom->IdNom=DocTIDNOMVPOT->AsInteger;
//							DMRegOstNom->IdPart=0;
//
//							DMRegOstNom->IdStr=DocTIDVPOT->AsInteger;
//							DMRegOstNom->Sum=0;
//							DMRegOstNom->Kol=KolSpis;
//							DMRegOstNom->Operation=0;
//							DMRegOstNom->AddRecordRashod();
//							}
//					   }
//                DocT->Next();
//                }
//
//
//		Doc2->Active=false;
//        Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//        Doc2->Active=true;
//		Doc2->Edit();
//        Doc2PRDOC->AsInteger=1;
//        Doc2->Post();
//
//		IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//	   Res=true;
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Res=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//
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
bool TDMDocVosvratPost::CancelDvRegDoc(void)
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
////DMRegOtrSpisNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру остатки товаров
//DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//
//
//
//try
//		{
//		if (DMRegOstNom->CancelDvReg()==true &&
//				DMRegGoods->CancelDvReg()==true )
//                {
//                Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//                Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//				IBTrDvReg->Commit();
//
//                TDMSetup * DMSetup=new TDMSetup(Application);
//                DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
//				result=true;
//				}
//        }
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
void __fastcall TDMDocVosvratPost::DocNewRecord(TDataSet *DataSet)
{
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOCVPO->AsString=IdDoc;

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DVPO->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMVPOT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCVPOT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DVPOT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVosvratPost::DocTKOLVPOTChange(TField *Sender)
{
OldSummaStr=DocTSUMVPOT->AsFloat;
DocTSUMVPOT->AsFloat=NewSummaStr=DocTKOLVPOT->AsFloat*DocTPRICEVPOT->AsFloat;

DocTRSUM_DVPOT->AsFloat=DocTKOLVPOT->AsFloat*DocTRPRICE_DVPOT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocTPRICEVPOTChange(TField *Sender)
{
OldSummaStr=DocTSUMVPOT->AsFloat;
DocTSUMVPOT->AsFloat=NewSummaStr=DocTKOLVPOT->AsFloat*DocTPRICEVPOT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVosvratPost::DocAllIDSKLDOCChange(TField *Sender)
{
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,InterfaceOwnerObject);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}
q->kanRelease();

GetNumberNewDoc();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocVosvratPost::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DVPO->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DVPOT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVosvratPost::DocTRPRICE_DVPOTChange(TField *Sender)
{
DocTRSUM_DVPOT->AsFloat=DocTKOLVPOT->AsFloat*DocTRPRICE_DVPOT->AsFloat;
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVosvratPost::DocAllTDOC_OSNGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (glStrToInt64(DocAllIDDOCOSNDOC->AsString)!=0)
	{
	Text=glGetNameDoc(DocAllTDOC_OSN->AsString)+
			" №"+DocAllNUMDOC_OSN->AsString+
			" от "+DocAllPOSDOC_OSN->AsString;
	}
}
//---------------------------------------------------------------------------





void __fastcall TDMDocVosvratPost::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

