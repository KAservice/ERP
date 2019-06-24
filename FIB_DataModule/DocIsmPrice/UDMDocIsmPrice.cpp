//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMDocIsmPrice.h"
#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
#include "IDMSetup.h"

#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMTableNumberDoc.h"
#include "IDMSprPrice.h"
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
__fastcall TDMDocIsmPrice::TDMDocIsmPrice(TComponent* Owner)
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
void __fastcall TDMDocIsmPrice::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;


EnableDvReg=false;
IsmPrice=false;
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocIsmPrice::Init(void)
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

NumDoc->Database=DM_Connection->pFIBData;
DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;


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
int TDMDocIsmPrice::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocIsmPrice::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocIsmPrice::NewDoc(void)
{
flGetNumberDoc=false;
DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOC_DISMPRICE->AsString=IdDoc;

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="ISMPRICE";
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
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
//----------------------------------------------------------------------------
int TDMDocIsmPrice::GetNumberNewDoc(void)
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
void TDMDocIsmPrice::OpenDoc(__int64 Id)
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
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}
//----------------------------------------------------------------------------
void TDMDocIsmPrice::ValidateProsmotr(void)
{
Prosmotr=false;    //только просмотр
ProsmotrText="";

//позици€ запрета редактировани€
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
ProsmotrText="ѕозици€ документа меньше позиции запрета редактировани€!";
DMSetup->kanRelease();

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Prosmotr=true;
		ProsmotrText="Ќельз€ редактировать чужие документы!";
		}
	}
}

//----------------------------------------------------------------------------
void TDMDocIsmPrice::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocIsmPrice::SaveDoc(void)
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

//изменим цены в справочнике, только новый тип цен
if (IsmPrice==true)
	{
	IDMSprPrice * spr_price;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&spr_price);
	spr_price->Init(InterfaceMainObject,InterfaceOwnerObject);
	DocT->First();
	while (!DocT->Eof)
		{
				if (glStrToInt64(DocIDNEWTPRICE_DISMPRICE->AsString)!=0 && DocTNEWPRICE_DISMPRICET->AsFloat!=0)
					{
					//изменим розничную цену в справочнике
					if (spr_price->FindElement(glStrToInt64(DocIDNEWTPRICE_DISMPRICE->AsString),
								glStrToInt64(DocTIDNOM_DISMPRICET->AsString))==0)
						{
						spr_price->IdNom=glStrToInt64(DocTIDNOM_DISMPRICET->AsString);
						spr_price->IdTypePrice=glStrToInt64(DocIDNEWTPRICE_DISMPRICE->AsString);
						spr_price->NewElement();
						}  
					spr_price->Element->Edit();
					spr_price->ElementZNACH_PRICE->AsFloat=DocTNEWPRICE_DISMPRICET->AsFloat/DocTKF_DISMPRICET->AsFloat;
					spr_price->Element->Post();
					spr_price->SaveElement();
					}
		DocT->Next();
		}
	spr_price->kanRelease();
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


bool TDMDocIsmPrice::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
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
				TextError=exception.Message;
				res=false;
				}
return res;

}
//-----------------------------------------------------------------------------
void TDMDocIsmPrice::AddDocNewString(void)
{
DocT->Append();
DocTIDDOC_DISMPRICET->AsString=DocAllIDDOC->AsString;
DocT->Post();

}
//-----------------------------------------------------------------------------
void TDMDocIsmPrice::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TDMDocIsmPrice::DvRegDoc(void)
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
//
//
//if (CancelDvRegDoc()!=true)
//		{
//		Res=false;
//		return Res;
//		}
//try
//		{
//		DocT->First();
//		while (!DocT->Eof)
//			{
//			//по регистру товары
//			DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//			DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
//			DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInteger;
//			DMRegGoods->IdSklad=DocAllIDSKLDOC->AsInteger;
//			DMRegGoods->IdNom=DocTIDNOM_DISMPRICET->AsInteger;
//			DMRegGoods->RPrice=DocTOLDPRICE_DISMPRICET->AsFloat;
//			DMRegGoods->Kol=DocTKOL_DISMPRICET->AsFloat*DocTKF_DISMPRICET->AsFloat;
//			DMRegGoods->Operation=11;
//			DMRegGoods->Type=1;    //0-внешнеее перемещение , 1- внутреннее
//			DMRegGoods->AddRecordRashod();
//
//			DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//			DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
//			DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInteger;
//			DMRegGoods->IdSklad=DocAllIDSKLDOC->AsInteger;
//			DMRegGoods->IdNom=DocTIDNOM_DISMPRICET->AsInteger;
//			DMRegGoods->RPrice=DocTNEWPRICE_DISMPRICET->AsFloat;
//			DMRegGoods->Kol=DocTKOL_DISMPRICET->AsFloat*DocTKF_DISMPRICET->AsFloat;
//			DMRegGoods->Operation=11;
//			DMRegGoods->Type=1;    //0-внешнеее перемещение , 1- внутреннее
//			DMRegGoods->AddRecordPrihod();
//
//						
//			DocT->Next();
//			}
//
//
//		Doc2->Active=false;
//		Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//		Doc2->Active=true;
//		Doc2->Edit();
//        Doc2PRDOC->AsInteger=1;
//		Doc2->Post();
//
//        IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//       DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//       Res=true;
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
//--------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool TDMDocIsmPrice::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
		return result;
		}

//try
//		{
//		//по регистру остатки товаров
//		DMRegGoods->IdDoc=DocAllIDDOC->AsInteger;
//		if (DMRegGoods->CancelDvReg()==true)
////				DMRegOtrSpisNom->CancelDvReg()==true &&
////				DMRegReal->CancelDvReg()==true &&
////				DMRegSebProd->CancelDvReg()==true &&
////				DMRegVipuskProd->CancelDvReg()==true &&
////				DMRegVsRasch->CancelDvReg()==true)
//				{
//				Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//				Doc2->Edit();
//				Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
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
				}
QueryCancelDvReg->Close();
return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TDMDocIsmPrice::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DISMPRICE->AsString=DocAllIDDOC->AsString;

if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DISMPRICE->AsString=DocAllIDBASE_GALLDOC->AsString;
	}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DISMPRICET->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DISMPRICET->AsString=DocAllIDBASE_GALLDOC->AsString;
		}
}

//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
DocTOLDSUM->AsFloat=DocTKOL_DISMPRICET->AsFloat*DocTOLDPRICE_DISMPRICET->AsFloat;
DocTNEWSUM->AsFloat=DocTKOL_DISMPRICET->AsFloat*DocTNEWPRICE_DISMPRICET->AsFloat;
DocTSUMISM->AsFloat=DocTNEWSUM->AsFloat-DocTOLDSUM->AsFloat;

DocTNAC_SUM_ED->AsFloat=DocTNEWPRICE_DISMPRICET->AsFloat-DocTSEB_PRICE_DISMPRICET->AsFloat;
DocTNAC_SUM->AsFloat=DocTNEWSUM->AsFloat-DocTSEB_SUM_DISMPRICET->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocIsmPrice::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DISMPRICE->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_DISMPRICET->AsString=DocAllIDBASE_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocIsmPrice::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTSEB_SUM_DISMPRICETChange(TField *Sender)
{
if (DocTSEB_SUM_DISMPRICET->AsFloat>0.001)
	{
	DocTNAC_OLD_DISMPRICET->AsFloat=((DocTOLDPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;
	DocTNAC_NEW_DISMPRICET->AsFloat=((DocTNEWPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;

	 }
}
//---------------------------------------------------------------------------



void __fastcall TDMDocIsmPrice::DocTSEB_PRICE_DISMPRICETChange(TField *Sender)
{
DocTSEB_SUM_DISMPRICET->AsFloat=DocTKOL_DISMPRICET->AsFloat*
								DocTSEB_PRICE_DISMPRICET->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTKOL_DISMPRICETChange(TField *Sender)
{
DocTSEB_SUM_DISMPRICET->AsFloat=DocTKOL_DISMPRICET->AsFloat*
								DocTSEB_PRICE_DISMPRICET->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTOLDPRICE_DISMPRICETChange(TField *Sender)
{
if (DocTSEB_SUM_DISMPRICET->AsFloat>0.001)
	{
	DocTNAC_OLD_DISMPRICET->AsFloat=((DocTOLDPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;
	DocTNAC_NEW_DISMPRICET->AsFloat=((DocTNEWPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;

	 }
}
//---------------------------------------------------------------------------

void __fastcall TDMDocIsmPrice::DocTNEWPRICE_DISMPRICETChange(TField *Sender)
{
if (DocTSEB_SUM_DISMPRICET->AsFloat>0.001)
	{
	DocTNAC_OLD_DISMPRICET->AsFloat=((DocTOLDPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;
	DocTNAC_NEW_DISMPRICET->AsFloat=((DocTNEWPRICE_DISMPRICET->AsFloat
							*DocTKOL_DISMPRICET->AsFloat
							-DocTSEB_SUM_DISMPRICET->AsFloat)
			/DocTSEB_SUM_DISMPRICET->AsFloat)*100;

	 }
}
//---------------------------------------------------------------------------

