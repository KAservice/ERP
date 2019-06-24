//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocPer.h"
#include "IDMSetup.h"
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
__fastcall TDMDocPer::TDMDocPer(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocPer::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;
SkladOtprRozn=false;
SkladPolRozn=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocPer::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы дл€ создани€ новых объектов
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
Firma->Database=DM_Connection->pFIBData;
Sklad->Database=DM_Connection->pFIBData;
SkladPol->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

//ѕ–»¬≈Ћ≈√»»
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TDMDocPer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocPer::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
Firma->Close();
Sklad->Close();


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}

//----------------------------------------------------------------------------
void TDMDocPer::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocT->Open();
DocAll->Append();
Doc->Append();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOCPER->AsString=IdDoc;
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="PER";
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
//----------------------------------------------------------------------------
int TDMDocPer::GetNumberNewDoc(void)
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
void TDMDocPer::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        Firma->Active=false;
        Sklad->Active=false;
        SkladPol->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;
		DocT->ParamByName("ID")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
        DocT->Open();

		Firma->ParamByName("ID")->AsInt64=glStrToInt64(DocAllIDFIRMDOC->AsString);
		Sklad->ParamByName("ID")->AsInt64=glStrToInt64(DocAllIDSKLDOC->AsString);
		SkladPol->ParamByName("ID")->AsInt64=glStrToInt64(DocIDSKLPOLPER->AsString);

        Firma->Open();
        Sklad->Open();
		SkladPol->Open();

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
	SkladOtprRozn=true;
	}
else
	{
	SkladOtprRozn=false;
	}

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocIDSKLPOLPER->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladPolRozn=true;
	}
else
	{
    SkladPolRozn=false;
	}
pFIBQ->Close();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}

//----------------------------------------------------------------------------
void TDMDocPer::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();

}
//----------------------------------------------------------------------------
bool TDMDocPer::SaveDoc(void)
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
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return Res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ редактировать чужие документы!";
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
void TDMDocPer::AddDocNewString(void)
{
DocT->Append();


}
//-----------------------------------------------------------------------------
void TDMDocPer::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocPer::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;


BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
		SummaDoc=SummaDoc+DocTSUMPERT->AsFloat;
		DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
bool TDMDocPer::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
        {

		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
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

//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
//pFIBQ->ExecQuery();
//if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
//	{
//	SkladOtprRozn=true;
//	}
//else
//	{
//	SkladOtprRozn=false;
//	}
//
//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocIDSKLPOLPER->AsString);
//pFIBQ->ExecQuery();
//if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
//	{
//	SkladPolRozn=true;
//	}
//else
//	{
//	SkladPolRozn=false;
//	}
//pFIBQ->Close();


//
//if (CancelDvRegDoc()!=true)
//		{
//		Res=false;
//		return Res;
//		}

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
//        DocT->First();
//		while (!DocT->Eof)
//                {
//				if (DocTTNOM->AsInteger==0)  //товар
//						{
//						double KolSpis=DocTKOLPERT->AsFloat*DocTKFPERT->AsFloat;
//						//по регистру товары
//						//списание
//						DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//						DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
//						DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInteger;
//						DMRegGoods->IdSklad=DocAllIDSKLDOC->AsInteger;
//						DMRegGoods->IdNom=DocTIDNOMPERT->AsInteger;
//						DMRegGoods->SkladRozn=SkladOtprRozn;
//						if (SkladOtprRozn==true)
//							{
//							DMRegGoods->RPrice=DocTPRICEPERT->AsFloat;
//							}
//						else
//							{
//							DMRegGoods->RPrice=0;
//							}
//						DMRegGoods->Kol=KolSpis;
//						DMRegGoods->Operation=2; //перемещение
//						DMRegGoods->Type=0;    //0-внешнеее перемещение , 1- внутреннее
//						DMRegGoods->AddRecordRashod();
//						//поступление
//						DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//						DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
//						DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInteger;
//						DMRegGoods->IdSklad=DocIDSKLPOLPER->AsInteger;
//						DMRegGoods->IdNom=DocTIDNOMPERT->AsInteger;
//						//DMRegGoods->SkladRozn=SkladPolRozn;
//						if (SkladPolRozn==true)
//							{
//							DMRegGoods->RPrice=DocTPRICEPERT->AsFloat;
//							}
//						else
//							{
//							DMRegGoods->RPrice=0;
//							}
//						DMRegGoods->Kol=KolSpis;
//						DMRegGoods->Operation=2;
//						DMRegGoods->Type=0;    //0-внешнеее перемещение , 1- внутреннее
//						DMRegGoods->AddRecordPrihod();
//
//
//						//по регистру остатки партий товаров
//                        //получить таблицу партий
//						TablePart->Active=false;
//						TablePart->ParamByName("IDFIRM")->AsInteger=DocAllIDFIRMDOC->AsInteger;
//                        TablePart->ParamByName("IDSKL")->AsInteger=DocAllIDSKLDOC->AsInteger;
//						TablePart->ParamByName("IDNOM")->AsInteger=DocTIDNOMPERT->AsInteger;
//                        TablePart->Active=true;
//
//
//                        TablePart->First();
//                        while ((!TablePart->Eof)&&(KolSpis>0))
//                                {
//                                 if (TablePartKOLOSTNOM->AsFloat<=KolSpis)
//										{
//                                        //полность списывем партию
//                                        SpisatPartSoSklada(TablePartKOLOSTNOM->AsFloat, TablePartSUMOSTNOM->AsFloat);
//                                        PrihodPartNaSklad(TablePartKOLOSTNOM->AsFloat, TablePartSUMOSTNOM->AsFloat);
//                                        KolSpis=KolSpis-TablePartKOLOSTNOM->AsFloat;
//										}
//                                 else
//                                        {
//                                        //частично списываем партию
//                                        SpisatPartSoSklada(KolSpis,TablePartSUMOSTNOM->AsFloat*KolSpis/TablePartKOLOSTNOM->AsFloat);
//										PrihodPartNaSklad(KolSpis,TablePartSUMOSTNOM->AsFloat*KolSpis/TablePartKOLOSTNOM->AsFloat);
//                                        KolSpis=0;
//                                        }
//
//                                TablePart->Next();
//								}
//
//                                if (KolSpis>0)
//										{
//										if (NoOtrOstatok==true)
//											{
//											AnsiString text_error="Ќедостаточно товара на  складе (недостаточно ингредиентов дл€ приготовлени€ продукции)!";
//											text_error=text_error+" —трока документа є"+IntToStr(DocT->RecNo);
//											text_error=text_error+", Ќоменклатура (продукци€) "+DocTNAMENOM->AsString;
//											throw Exception(text_error,0);
//											}
//										DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
//										DMRegOstNom->PosDoc=DocAllPOSDOC->AsDateTime;
//										DMRegOstNom->IdFirm=DocAllIDFIRMDOC->AsInteger;
//										DMRegOstNom->IdSklad=DocAllIDSKLDOC->AsInteger;
//										DMRegOstNom->IdNom=DocTIDNOMPERT->AsInteger;
//										DMRegOstNom->IdPart=0;
//										DMRegOstNom->IdStr=DocTIDPERT->AsInteger;
//										DMRegOstNom->Sum=0;
//										DMRegOstNom->Kol=KolSpis;
//										DMRegOstNom->Operation=2; //1-реализаци€, 2-перемещение, 3-на выпуск продукции, 4-списание
//										DMRegOstNom->AddRecordRashod();
//
//                                        //приходуем партию на склад
//                                        DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
//										DMRegOstNom->PosDoc=DocAllPOSDOC->AsDateTime;
//
//                                        DMRegOstNom->IdFirm=DocAllIDFIRMDOC->AsInteger;
//										DMRegOstNom->IdSklad=DocIDSKLPOLPER->AsInteger;
//                                        DMRegOstNom->IdNom=DocTIDNOMPERT->AsInteger;
//										DMRegOstNom->IdPart=0;
//
//                                        DMRegOstNom->IdStr=DocTIDPERT->AsInteger;
//                                        DMRegOstNom->Sum=0;
//                                        DMRegOstNom->Kol=KolSpis;
//										DMRegOstNom->Operation=6;
//                                        DMRegOstNom->AddRecordPrihod();
//
//                                        //-----------------------------------------------------------
//                                        }
//					   }
//                DocT->Next();
//                }
//
//
//		Doc2->Active=false;
//        Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//        Doc2->Active=true;
//        Doc2->Edit();
//		Doc2PRDOC->AsInteger=1;
//        Doc2->Post();
//
//		IBTrDvReg->Commit();
//
//	   TDMSetup * DMSetup=new TDMSetup(Application);
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
bool TDMDocPer::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{

		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
		}

//
////по регистру остатки партий товаров
//DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру остатки товаров
//DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
////по регистру отр. списание
//DMRegOtrSpisNom->IdDoc=DocAllIDDOC->AsInteger;
//
//
//
//try
//        {
//		if (DMRegOstNom->CancelDvReg()==true &&
//			DMRegGoods->CancelDvReg()==true &&
//                DMRegOtrSpisNom->CancelDvReg()==true)
//                {
//				Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//				Doc2->Edit();
//                Doc2PRDOC->AsInteger=0;
//                Doc2->Post();
//				IBTrDvReg->Commit();
//
//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;
//
//				result=true;
//				}
//		}
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


bool TDMDocPer::DeleteDoc(__int64 id)
{
bool res=false;
OpenDoc(id);

if (Prosmotr==true)
        {

        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{

		TextError="Ќельз€ удал€ть чужие документы!";
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

//---------------------------------------------------------------------------
__int64 TDMDocPer::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;


pFIBQ->Close();
pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='PER'");
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




void __fastcall TDMDocPer::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
DocTNAC_SUM_ED->AsFloat=DocTPRICEPERT->AsFloat-DocTSEB_PRICE_DPERT->AsFloat;
DocTNAC_SUM->AsFloat=DocTSUMPERT->AsFloat-DocTSEB_SUM_DPERT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMPERT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCPERT->AsString=DocAllIDDOC->AsString;
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DPERT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPer::DocAllIDSKLDOCChange(TField *Sender)
{
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladOtprRozn=true;
	}
else
	{
	SkladOtprRozn=false;
	}


GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocIDSKLPOLPERChange(TField *Sender)
{

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocIDSKLPOLPER->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladPolRozn=true;
	}
else
	{
    SkladPolRozn=false;
	}
pFIBQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTPRICEPERTChange(TField *Sender)
{
OldSummaStr=DocTSUMPERT->AsFloat;

DocTSUMPERT->AsFloat=NewSummaStr=DocTKOLPERT->AsFloat
				*DocTPRICEPERT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTKOLPERTChange(TField *Sender)
{
OldSummaStr=DocTSUMPERT->AsFloat;

DocTSUMPERT->AsFloat=NewSummaStr=DocTKOLPERT->AsFloat
				*DocTPRICEPERT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

DocTSEB_SUM_DPERT->AsFloat=DocTKOLPERT->AsFloat*
								DocTSEB_PRICE_DPERT->AsFloat;
}
//---------------------------------------------------------------------------



void __fastcall TDMDocPer::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCPER->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DPER->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DPER->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DPERT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTSEB_PRICE_DPERTChange(TField *Sender)
{
DocTSEB_SUM_DPERT->AsFloat=DocTKOLPERT->AsFloat*
								DocTSEB_PRICE_DPERT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTSEB_SUM_DPERTChange(TField *Sender)
{
if (DocTSEB_SUM_DPERT->AsFloat>0.001)
	{
	DocTNAC_DPERT->AsFloat=((DocTPRICEPERT->AsFloat
							*DocTKOLPERT->AsFloat
							-DocTSEB_SUM_DPERT->AsFloat)
			/DocTSEB_SUM_DPERT->AsFloat)*100;

	 }
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPer::DocTSUMPERTChange(TField *Sender)
{
if (DocTSEB_SUM_DPERT->AsFloat>0.001)
	{
	DocTNAC_DPERT->AsFloat=((DocTPRICEPERT->AsFloat
							*DocTKOLPERT->AsFloat
							-DocTSEB_SUM_DPERT->AsFloat)
			/DocTSEB_SUM_DPERT->AsFloat)*100;

	 }
}
//---------------------------------------------------------------------------

