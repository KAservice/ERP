//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMDocReal.h"
#include "UDM.h"
#include "UDMSetup.h"
#include "UDMSprUser.h"

#include "UDMSprNom.h"
#include "UDMSprEd.h"
#include "UDMSprSostProd.h"
#include "UDMSprNomRest.h"
#include "UDMQueryRead.h"
#include "UDMTableNumberDoc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TDMDocReal::TDMDocReal(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMDocReal::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;

}
//----------------------------------------------------------------------------
void __fastcall TDMDocReal::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
//NumDoc->Close();

}

//----------------------------------------------------------------------------
void TDMDocReal::NewDoc(void)
{
DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=DocAllIDDOC->AsInt64;

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="REA";
if (glUser->ElementID_USER->AsInt64!=0)
	{
	DocAllIDUSERDOC->AsInt64=glUser->ElementID_USER->AsInt64;
	DocAllFNAME_USER->AsString=glUser->ElementFNAME_USER->AsString;
	}
if(glUser->ElementIDFIRM_USER->AsInt64!=0)
	{
	DocAllIDFIRMDOC->AsInt64=glUser->ElementIDFIRM_USER->AsInt64;
	DocAllNAMEFIRM->AsString=glUser->ElementNAMEFIRM->AsString;
	}
if (glUser->ElementIDSKLAD_USER->AsInt64!=0)
	{
	DocAllIDSKLDOC->AsInt64=glUser->ElementIDSKLAD_USER->AsInt64;
	DocAllNAMESKLAD->AsString=glUser->ElementNAMESKLAD->AsString;
	}
if (glUser->ElementIDBASE_SUSER->AsInt64!=0)
	{
	DocAllIDBASE_GALLDOC->AsInt64=glUser->ElementIDBASE_SUSER->AsInt64;
	DocAllNAME_SINFBASE_OBMEN->AsString=glUser->ElementNAME_SINFBASE_OBMEN->AsString;
	}
//получим номер документа
NumDoc->Active=false;
TDMTableNumberDoc * dm_num=new TDMTableNumberDoc(Application);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REA");
NumDoc->Open();
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
delete dm_num;
NumDoc->Active=false;
DocAll->Post();

Doc->Edit();
DocIDDOCREA->AsInteger=IdDoc;
if (glUser->ElementIDTPRICE_USER->AsInt64!=0)
	{
	DocIDTPRICEREA->AsInt64=glUser->ElementIDTPRICE_USER->AsInt64;
	} 
if (glUser->ElementIDBSCHET_USER->AsInt64!=0)
	{
	DocIDBSCHETREA->AsInt64=glUser->ElementIDBSCHET_USER->AsInt64;
	}
DocNAMEBSCHET->AsString=glUser->ElementNAMEBSCHET->AsString;
Doc->Post();


}
//----------------------------------------------------------------------------
void TDMDocReal::OpenDoc(__int64 Id)
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

TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;


        if (GetIDDocSchetFact()>0)
                {
                NoEdit=true;
                }



DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=DocAllIDDOC->AsInt64;
}

//----------------------------------------------------------------------------
void TDMDocReal::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocReal::SaveDoc(void)
{

bool Res=false;

TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return Res;
		}

if (glUser->ElementID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (glUser->ElementEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Error=true;
		TextError="Ќельз€ редактировать чужие документы!";
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
		DocT->CommitUpdToCach();;

        OpenDoc(IdDoc);
        Res=true;
		}
catch(Exception &exception)
				{
			  	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				Res=false;
				}
return Res;
}
//-----------------------------------------------------------------------------


bool TDMDocReal::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}

if (glUser->ElementID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (glUser->ElementDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Error=true;
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
				Error=true;
				TextError=exception.Message;
				res=false;
				}
return res;

}
//-----------------------------------------------------------------------------
void TDMDocReal::AddDocNewString(void)
{
DocT->Append();
DocTIDDOCREAT->AsInt64=DocAllIDDOC->AsInt64;
DocT->Post();

}
//-----------------------------------------------------------------------------
void TDMDocReal::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocReal::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUMREAT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TDMDocReal::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		Error=true;
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
        }

if (EnableDvReg==false)
		{
		try
				{
				TDMSetup * DMSetup=new TDMSetup(Application);
				DMSetup->OpenElement(14);
				if (DMSetup->ElementVALUE_SETUP->AsString=="1")
						{
						result=true;
						return result;
						}
				delete DMSetup;
				}
		catch(...)
				{
				}
		}

//
//if (CancelDvRegDoc()!=true)
//		{
//		Res=false;
//		return Res;
//		}
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
//		{
//
//                DocT->First();
//                 while (!DocT->Eof)
//                        {
//						SebReal=0;
//                        KolOtrSpisNom=0;
//                        //движение по регистру реализаци€
//                        if (DocTTNOM->AsInteger==0)  //товар
//                                {
//								Operation=1;
//                                IdSklad=DocAllIDSKLDOC->AsInteger;
//                                SpisatNomSoSklada(DocTIDNOMREAT->AsInteger,
//                                        DocTKOLREAT->AsFloat*DocTKFREAT->AsFloat);
//                                //движение по регистру реализаци€
//								DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//                                DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//                                DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//								DMRegReal->Operation=3;  //оптова€ торговл€
//                                DMRegReal->SumReal=DocTSUMREAT->AsFloat;
//                                DMRegReal->SebReal=SebReal;
//                                DMRegReal->ResReal=DocTSUMREAT->AsFloat-SebReal;
//                                DMRegReal->KolReal=DocTKFREAT->AsFloat*DocTKOLREAT->AsFloat;
//								DMRegReal->KolOtrReal=KolOtrSpisNom;
//                                DMRegReal->AddReal();
//                                }
//                        
//                        if (DocTTNOM->AsInteger==1)  //услуга
//								{
//                                Operation=0;
//                                IdSklad=DocAllIDSKLDOC->AsInteger;
//                                //движение по регистру реализаци€
//                                DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//								DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//                                DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//								DMRegReal->Operation=3;  //оптова€ торговл€
//								DMRegReal->SumReal=DocTSUMREAT->AsFloat;
//                                DMRegReal->SebReal=0;
//                                DMRegReal->ResReal=DocTSUMREAT->AsFloat;
//                                DMRegReal->KolReal=DocTKFREAT->AsFloat*DocTKOLREAT->AsFloat;
//                                DMRegReal->KolOtrReal=0;
//								DMRegReal->AddReal();
//                                }
//
//                        if (DocTTNOM->AsInteger==2)  //продукци€
//                                {
//								Operation=3;
//                                IdSklad=DocAllIDSKLDOC->AsInteger;
//                                SpisatProdSoSklada();
//
//
//								//движение по регистру реализаци€
//                                DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//                                DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//								DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//                                DMRegReal->SumReal=DocTSUMREAT->AsFloat;
//								DMRegReal->Operation=3; //оптова€ торговл€
//                                DMRegReal->SebReal=SebReal;
//                                DMRegReal->ResReal=DocTSUMREAT->AsFloat-SebReal;
//								DMRegReal->KolReal=DocTKFREAT->AsFloat*DocTKOLREAT->AsFloat;
//                                DMRegReal->KolOtrReal=0;
//                                DMRegReal->AddReal();
//                                }
//                        
//
//
//                        DocT->Next();
//                        }
//
//				IdDoc=DocAllIDDOC->AsInteger;
//                DMRegVsRasch->IdDoc=IdDoc;
//                DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//                DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//				DMRegVsRasch->Sum=DocAllSUMDOC->AsFloat;
//                DMRegVsRasch->AddRecordPrihod();
//
//
//
//		Doc2->Active=false;
//        Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//        Doc2->Active=true;
//        Doc2->Edit();
//        Doc2PRDOC->AsInteger=1;
//		Doc2->Post();
//
//		IBTrDvReg->Commit();
//
//	   TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//       delete DMSetup;
//
//	   Res=true;
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Error=true;
//				TextError=exception.Message;
//				Res=false;
//				}
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
				Error=true;
				}

QueryDvReg->Close();
return result;
}

//-----------------------------------------------------------------------------
bool TDMDocReal::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		Error=true;
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
		}
//
////по регистру остатки товаров
//DMRegOstNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру остатки товаров
//DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
////по регистру отр. списание
//DMRegOtrSpisNom->IdDoc=DocAllIDDOC->AsInteger;
////по регистру реализаци€
//DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
////по регистру себестоимость продукции
//DMRegSebProd->IdDoc=DocAllIDDOC->AsInteger;
////по регистру выпуск продукции
//DMRegVipuskProd->IdDoc=DocAllIDDOC->AsInteger;
//
//DMRegVsRasch->IdDoc=DocAllIDDOC->AsInteger;
//
//
//try
//        {
//		if (DMRegOstNom->CancelDvReg()==true &&
//				DMRegGoods->CancelDvReg()==true &&
//                DMRegOtrSpisNom->CancelDvReg()==true &&
//                DMRegReal->CancelDvReg()==true &&                 
//				DMRegSebProd->CancelDvReg()==true &&
//                DMRegVipuskProd->CancelDvReg()==true &&
//                DMRegVsRasch->CancelDvReg()==true)
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
//                DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;
//
//                result=true;
//				}
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Error=true;
//				TextError=exception.Message;
//				result=false;
//				}
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
				Error=true;
				}
				
QueryCancelDvReg->Close();
return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TDMDocReal::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCREA->AsInt64=DocAllIDDOC->AsInt64;

if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DREA->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCREAT->AsInt64=DocAllIDDOC->AsInt64;

if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocTIDBASE_DREAT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}

//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMREAT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocReal::DocTKOLREATChange(TField *Sender)
{
OldSummaStr=DocTSUMREAT->AsFloat;

DocTSUMREAT->AsFloat=NewSummaStr=DocTKOLREAT->AsFloat*DocTPRICEREAT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocReal::DocTPRICEREATChange(TField *Sender)
{
OldSummaStr=DocTSUMREAT->AsFloat;

DocTSUMREAT->AsFloat=NewSummaStr=DocTKOLREAT->AsFloat*DocTPRICEREAT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocAllPOSDOCChange(TField *Sender)
{
TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocAllNAME_SINFBASE_OBMENGetText(
      TField *Sender, AnsiString &Text, bool DisplayText)
{
Text="»нф. база: "+DocAllNAME_SINFBASE_OBMEN->AsString;
}
//---------------------------------------------------------------------------
__int64 TDMDocReal::GetIDDocSchetFact(void)
{
int result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='SCHFACT'");
		pFIBQ->SQL->Add(" and IDDOCOSNDOC="+IntToStr(DocAllIDDOC->AsInteger));
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("IDDOC")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMDocReal::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	Doc->Edit();
	DocIDBASE_DREA->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocT->Edit();
		DocTIDBASE_DREAT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------
__int64 TDMDocReal::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;  

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='REAL'");
pFIBQ->SQL->Add(" and CAST(POSDOC AS DATE)=:PARAM_DATE");
pFIBQ->ParamByName("PARAM_NUMDOC")->AsInteger=number_doc;
pFIBQ->ParamByName("PARAM_DATE")->AsDate=date_doc;
pFIBQ->ExecQuery();
res=pFIBQ->FieldByName("IDDOC")->AsInt64;
pFIBQ->Close();

return res;
}
//---------------------------------------------------------------------------
