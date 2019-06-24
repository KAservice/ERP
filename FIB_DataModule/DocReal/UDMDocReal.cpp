//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMDocReal.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMSprSostProd.h"
#include "IDMSprNomRest.h"
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
__fastcall TDMDocReal::TDMDocReal(TComponent* Owner)
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
void __fastcall TDMDocReal::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocReal::Init(void)
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
//----------------------------------------------------------------------------
int TDMDocReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocReal::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
//NumDoc->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocReal::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="REA";
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
if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
	{
	DocIDTPRICEREA->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
	} 
if (glStrToInt64(DM_Connection->UserInfoIDBSCHET_USER->AsString)!=0)
	{
	DocIDBSCHETREA->AsString=DM_Connection->UserInfoIDBSCHET_USER->AsString;
	}
DocNAMEBSCHET->AsString=DM_Connection->UserInfoNAMEBSCHET->AsString;
Doc->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocReal::GetNumberNewDoc(void)
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

	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
	Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
	DMSetup->kanRelease();


        if (GetIDDocSchetFact()>0)
                {
                NoEdit=true;
                }



DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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
		DocT->CommitUpdToCach();;

        OpenDoc(IdDoc);
        Res=true;
		}
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
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
				TextError=exception.Message;
				res=false;
				}
return res;

}
//-----------------------------------------------------------------------------
void TDMDocReal::AddDocNewString(void)
{
DocT->Append();


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
		TextError="Позиция документа меньше позиции запрета редактирования!";
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
//                        //движение по регистру реализация
//                        if (DocTTNOM->AsInteger==0)  //товар
//                                {
//								Operation=1;
//                                IdSklad=DocAllIDSKLDOC->AsInteger;
//                                SpisatNomSoSklada(DocTIDNOMREAT->AsInteger,
//                                        DocTKOLREAT->AsFloat*DocTKFREAT->AsFloat);
//                                //движение по регистру реализация
//								DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//                                DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//                                DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//								DMRegReal->Operation=3;  //оптовая торговля
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
//                                //движение по регистру реализация
//                                DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//								DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//                                DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//								DMRegReal->Operation=3;  //оптовая торговля
//								DMRegReal->SumReal=DocTSUMREAT->AsFloat;
//                                DMRegReal->SebReal=0;
//                                DMRegReal->ResReal=DocTSUMREAT->AsFloat;
//                                DMRegReal->KolReal=DocTKFREAT->AsFloat*DocTKOLREAT->AsFloat;
//                                DMRegReal->KolOtrReal=0;
//								DMRegReal->AddReal();
//                                }
//
//                        if (DocTTNOM->AsInteger==2)  //продукция
//                                {
//								Operation=3;
//                                IdSklad=DocAllIDSKLDOC->AsInteger;
//                                SpisatProdSoSklada();
//
//
//								//движение по регистру реализация
//                                DMRegReal->IdDoc=DocAllIDDOC->AsInteger;
//                                DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
//                                DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                                DMRegReal->IdSklad=DocAllIDSKLDOC->AsInteger;
//								DMRegReal->IdNom=DocTIDNOMREAT->AsInteger;
//                                DMRegReal->SumReal=DocTSUMREAT->AsFloat;
//								DMRegReal->Operation=3; //оптовая торговля
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
//---------------------------------------------------------------------------


void __fastcall TDMDocReal::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCREA->AsString=glStrToInt64(DocAllIDDOC->AsString);

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DREA->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCREAT->AsString=glStrToInt64(DocAllIDDOC->AsString);

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocTIDBASE_DREAT->AsString=DocAllIDBASE_GALLDOC->AsString;
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
	IDMSetup * DMSetup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
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
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DREA->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DREAT->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
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
void __fastcall TDMDocReal::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocReal::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

