//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UDMDocCheck.h"
#include "IDMSetup.h"
#include "IDMTableNumberDoc.h"
#include "IDMGurOperDiscountCard.h"
#include "IDMSprDiscountCard.h"
#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
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
__fastcall TDMDocCheck::TDMDocCheck(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//-----------------------------------------------------------------
void __fastcall TDMDocCheck::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
AutoRaschet=false;
EnableDvReg=false;
flGetNumberDoc=true;
}
//-----------------------------------------------------------------------
bool TDMDocCheck::Init(void)
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

NumDoc->Database=DM_Connection->pFIBData;
SpisokTypePrice->Database=DM_Connection->pFIBData;
DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
DocOsn->Database=DM_Connection->pFIBData;
DocOpl->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_DocCheckKKM);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TDMDocCheck::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
DocOsn->Active=false;
DocOpl->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocCheck::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
DocOpl->Active=false;
SpisokTypePrice->Active=false;
NumDoc->Active=false;
DocOsn->Active=false;


DocAll->ParamByName("ID")->AsInt64=0;
Doc->ParamByName("ID")->AsInt64=0;
DocT->ParamByName("ID")->AsInt64=0;
DocOpl->ParamByName("IDDOC")->AsString=0;

DocAll->Open();
Doc->Open();
DocT->Open();
DocOpl->Open();

OpenDocOsn();

DocAll->Append();
Doc->Append(); 

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
DocIDDOCCHK->AsString=IdDoc;
DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="CHK";
DocAllSUMDOC->AsFloat=0;
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;
	}

if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
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

Doc->Edit();
DocOPERCHK->AsInteger=0;
DocNALCHK->AsFloat=0;
DocOPLNALCHK->AsFloat=0;
DocOPLPCCHK->AsFloat=0;

if(glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
	{
	DocIDTPRICE->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
	}

if (IdTypePrice!=0)
	{
	DocIDTPRICE->AsString=IdTypePrice;
	}
if (glStrToInt64(DM_Connection->UserInfoIDKASSA_USER->AsString)!=0)
	{
	DocIDKKMCHK->AsString=DM_Connection->UserInfoIDKASSA_USER->AsString;
	DocNAMEKKM->AsString=DM_Connection->UserInfoNAMEKKM->AsString;
	}
Doc->Post();



SummaDoc=0;
SummaSkidok=0;
SummaNadbavok=0;
SummaDocFull=0;
SummaTable=0;
TekSummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
OldSummaSkidokStr=0;
NewSummaSkidokStr=0;
OldSummaNadbavokStr=0;
NewSummaNadbavokStr=0;
OldSummaFullStr=0;
NewSummaFullStr=0;




flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocCheck::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=DocAllIDSKLDOC->AsString;
NumDoc->ParamByName("PARAM_IDKASSA")->AsString=DocIDKKMCHK->AsString;

NumDoc->Open();
if (DocAll->Active==true)
	{
	DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
	DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
	}
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
bool TDMDocCheck::OpenDoc(__int64 Id)
{
bool result=false;
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
DocOpl->Active=false;

DocAll->ParamByName("ID")->AsInt64=Id;
Doc->ParamByName("ID")->AsInt64=Id;
DocT->ParamByName("ID")->AsInt64=Id;
DocOpl->ParamByName("IDDOC")->AsString=Id;

DocAll->Open();
Doc->Open();
DocT->Open();
DocOpl->Open();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);

Summa();
DocAllIDBASE_GALLDOC->ReadOnly=true;
OpenDocOsn();


ValidateProsmotr();
result=true;
return result;
}
//---------------------------------------------------------------------------

void TDMDocCheck::ValidateProsmotr(void)
{
Prosmotr=false;    //только просмотр
ProsmotrText="";

//позиция запрета редактирования
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
if (Prosmotr==true)
	{
    ProsmotrText="Позиция документа меньше позиции запрета редактирования!";
	}

DMSetup->kanRelease();

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Prosmotr=true;
		ProsmotrText="Нельзя редактировать чужие документы!";
		}
	}
}
//----------------------------------------------------------------------------
void TDMDocCheck::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
		DocOpl->CancelUpdates();

        DocAll->Active=false;
		Doc->Active=false;
		DocT->Active=false;
        DocOpl->Active=false;
}
//----------------------------------------------------------------------------
bool TDMDocCheck::SaveDoc(void)
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

DocAll->Edit();
DocAllSUMDOC->AsFloat=Summa();
DocAll->Post();

AdddRecordInGurOperDiscountCard();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);

try
        {
		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		DocOpl->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();
		DocOpl->CommitUpdToCach();
		OpenDoc(IdDoc);
		AfterSaveDoc();
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
bool TDMDocCheck::BeforeSaveDoc(void)
{
bool result=true;


return result;
}
//-----------------------------------------------------------------------------
bool TDMDocCheck::AfterSaveDoc(void)
{
bool result=true;

//сбросим одноразовую карту
if (glStrToInt64(DocIDDCARDCHK->AsString) > 0)
	{
	IDMSprDiscountCard * dm_spr_discount_card;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
													(void**)&dm_spr_discount_card);

	dm_spr_discount_card->Init(InterfaceMainObject,0);
	dm_spr_discount_card->OpenElement(glStrToInt64(DocIDDCARDCHK->AsString));

	if (dm_spr_discount_card->ElementSINGLE_SDISCOUNT_CARD->AsInteger==1)
		{//если карта одноразовая сбросим флаг активности
		if (dm_spr_discount_card->ElementACT_SDISCOUNT_CARD->AsInteger==1)
			{
			dm_spr_discount_card->Element->Edit();
			dm_spr_discount_card->ElementACT_SDISCOUNT_CARD->AsInteger=0;
			dm_spr_discount_card->Element->Post();
			dm_spr_discount_card->SaveElement();
			}
		}
    dm_spr_discount_card->kanRelease();
	}

return result;
}
//-----------------------------------------------------------------------------

void TDMDocCheck::AdddRecordInGurOperDiscountCard(void)
{
if (glStrToInt64(DocIDDCARDCHK->AsString)==0) return;

//проверить накопительная ли карта
IDMSprDiscountCard * dm_spr_discount_card;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
													(void**)&dm_spr_discount_card);

dm_spr_discount_card->Init(InterfaceMainObject,0);
dm_spr_discount_card->OpenElement(glStrToInt64(DocIDDCARDCHK->AsString));
if (dm_spr_discount_card->ElementTYPE_SDISCOUNT_CARD->AsInteger==2)  //накопительная
	{
	//добавим запись об использованной накопительной дисконтной карте в журнал
	IDMGurOperDiscountCard * dm_gur_oper;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard,
													(void**)&dm_gur_oper);
	dm_gur_oper->Init(InterfaceMainObject,0);
	__int64 code_doc=glStrToInt64(DocAllIDDOC->AsString);
	__int64 id_rec=dm_gur_oper->PoiskPoCoduDoc(code_doc);

	if (id_rec==0)
		{ //вставляем запись
		dm_gur_oper->NewElement();
		}
	else
		{
		dm_gur_oper->OpenElement(id_rec);
		}

	dm_gur_oper->Element->Edit();
	dm_gur_oper->ElementIDDOC_GUROPER_DCARD->AsString=code_doc;
	if (glStrToInt64(DocAllIDKLDOC->AsString)!=0)
		{
		dm_gur_oper->ElementIDKLIENT_GUROPER_DCARD->AsString=DocAllIDKLDOC->AsString;
		}
	if (glStrToInt64(DocAllIDSKLDOC->AsString)!=0)
		{
		dm_gur_oper->ElementIDSKLAD_GUROPER_DCARD->AsString=DocAllIDSKLDOC->AsString;
		}
	dm_gur_oper->ElementIDCARD_GUROPER_DCARD->AsString=DocIDDCARDCHK->AsString;
	dm_gur_oper->ElementPOS_GUROPER_DCARD->AsDateTime=DocAllPOSDOC->AsDateTime;
	dm_gur_oper->ElementSUM_GUROPER_DCARD->AsFloat=DocAllSUMDOC->AsFloat;
	dm_gur_oper->Element->Post();
	dm_gur_oper->SaveElement();
	dm_gur_oper->kanRelease();
	}

dm_spr_discount_card->kanRelease();

}
//-----------------------------------------------------------------------------
void TDMDocCheck::AddDocNewString(void)
{
DocT->Append();

}
//-----------------------------------------------------------------------------
void TDMDocCheck::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocCheck::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

SummaDocFull=0;
SummaSkidok=0;
SummaNadbavok=0;
SummaTable=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocT->FieldByName("SUMCHKT")->AsFloat;
		SummaDocFull=SummaDocFull+DocTPRICECHKT->AsFloat*DocTKOLCHKT->AsFloat;
		SummaSkidok=SummaSkidok+DocTSKCHKT->AsFloat;
		SummaNadbavok=SummaNadbavok+DocTNADCHKT->AsFloat;
		SummaTable=SummaTable+DocT->FieldByName("SUMCHKT")->AsFloat;
		DocT->Next();
		}

Doc->Edit();



DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TDMDocCheck::DvRegDoc(void)
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
			DMSetup->Init(InterfaceMainObject,0);
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



try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryDvReg->ExecProc();
				IBTrDvReg->Commit();

//                TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//                delete DMSetup;
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
bool TDMDocCheck::CancelDvRegDoc(void)
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

bool TDMDocCheck::DeleteDoc(__int64 id)
{
bool res=false;
IdDoc=id;
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

		DocOpl->First();
		while(!DocOpl->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
				DocOpl->Delete();
				}
				
        Doc->Delete();
        DocAll->Delete();

		DocT->ApplyUpdates();
		DocOpl->ApplyUpdates();
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

//----------------------------------------------------------------------------


void __fastcall TDMDocCheck::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCCHK->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DCHK->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;


DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocNALCHK->AsFloat=DocAllSUMDOC->AsFloat-SummaSkidok+SummaNadbavok;
Doc->Post();

Doc->Edit();
DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
DocOPLPCCHK->AsFloat=0; 
Doc->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUMCHKT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCCHKT->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocTIDBASE_DCHKT->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------








void __fastcall TDMDocCheck::DocTSKCHKTGetText(TField *Sender, AnsiString &Text,
      bool DisplayText)
{
if (DocTSKCHKT->AsFloat==0) {Text="";}
else
		{
		Text=FloatToStrF(DocTSKCHKT->AsFloat,ffFixed,15,2);
		}	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTNADCHKTGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (DocTNADCHKT->AsFloat==0) {Text="";}
else
		{
		Text=FloatToStrF(DocTNADCHKT->AsFloat,ffFixed,15,2);
		}
}
//---------------------------------------------------------------------------


void __fastcall TDMDocCheck::DocTPRICECHKTChange(TField *Sender)
{
DocTNADCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRNADCHKT->AsFloat/100;

DocTSKCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRSKCHKT->AsFloat/100;


OldSummaStr=DocTSUMCHKT->AsFloat;

DocTSUMCHKT->AsFloat=NewSummaStr=DocTKOLCHKT->AsFloat*DocTPRICECHKT->AsFloat
								-DocTSKCHKT->AsFloat+DocTNADCHKT->AsFloat;


DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
Doc->Post();

Doc->Edit();
DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
DocOPLPCCHK->AsFloat=0;
Doc->Post();
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocTKOLCHKTChange(TField *Sender)
{
OldSummaStr=DocTSUMCHKT->AsFloat;

DocTNADCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRNADCHKT->AsFloat/100;
DocTSKCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRSKCHKT->AsFloat/100;

DocTSUMCHKT->AsFloat=NewSummaStr=DocTKOLCHKT->AsFloat*DocTPRICECHKT->AsFloat
				-DocTSKCHKT->AsFloat+DocTNADCHKT->AsFloat;


DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocNALCHK->AsFloat=DocAllSUMDOC->AsFloat-SummaSkidok+SummaNadbavok;
Doc->Post();


Doc->Edit();
DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
DocOPLPCCHK->AsFloat=0;
Doc->Post();
}

//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocTPRSKCHKTChange(TField *Sender)
{
OldSummaStr=DocTSUMCHKT->AsFloat;

DocTNADCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRNADCHKT->AsFloat/100;
DocTSKCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRSKCHKT->AsFloat/100;

DocTSUMCHKT->AsFloat=NewSummaStr=DocTKOLCHKT->AsFloat*DocTPRICECHKT->AsFloat
				-DocTSKCHKT->AsFloat+DocTNADCHKT->AsFloat;


DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocNALCHK->AsFloat=DocAllSUMDOC->AsFloat-SummaSkidok+SummaNadbavok;
Doc->Post();


Doc->Edit();
DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
DocOPLPCCHK->AsFloat=0;
Doc->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocTPRNADCHKTChange(TField *Sender)
{
OldSummaStr=DocTSUMCHKT->AsFloat;

DocTNADCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRNADCHKT->AsFloat/100;
DocTSKCHKT->AsFloat=DocTPRICECHKT->AsFloat
								*DocTKOLCHKT->AsFloat
								*DocTPRSKCHKT->AsFloat/100;

DocTSUMCHKT->AsFloat=NewSummaStr=DocTKOLCHKT->AsFloat*DocTPRICECHKT->AsFloat
				-DocTSKCHKT->AsFloat+DocTNADCHKT->AsFloat;


DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocNALCHK->AsFloat=DocAllSUMDOC->AsFloat-SummaSkidok+SummaNadbavok;
Doc->Post();


Doc->Edit();
DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat;
DocOPLPCCHK->AsFloat=0;
Doc->Post();

}
//---------------------------------------------------------------------------



void __fastcall TDMDocCheck::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (Doc->Active==true)
	{
	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DCHK->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}
	}

if (DocT->Active==true)
	{
	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DCHKT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocOsnTDOCGetText(TField *Sender, AnsiString &Text,
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
void TDMDocCheck::OpenDocOsn(void)
{
DocOsn->Active=false;
DocOsn->ParamByName("PARAM_IDDOC")->AsString=glStrToInt64(DocAllIDDOCOSNDOC->AsString);
DocOsn->Active=true;

}

//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocTSUMCHKTChange(TField *Sender)
{
int nds=glGetRateNDS(DocTNDS_DCHKT->AsInteger);
DocTSUMNDS_DCHKT->AsFloat=
		(DocTSUMCHKT->AsFloat/(100+nds))*nds;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocOplNewRecord(TDataSet *DataSet)
{
DocOplIDDOC_DCHK_OPL->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocOplIDBASE_DCHK_OPL->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocOplCalcFields(TDataSet *DataSet)
{
DocOplRECNO->AsInteger=DocOpl->RecNo;
}
//---------------------------------------------------------------------------
//РАСЧЕТ СДАЧИ
//---------------------------------------------------------------------------

//сумма документа
void __fastcall TDMDocCheck::DocAllSUMDOCChange(TField *Sender)
{
Doc->Edit();
DocSDACHA_DCHK->AsFloat=DocNALCHK->AsFloat+
								DocOPLPCCHK->AsFloat+
								DocOPLPLATCARD_ALL_DCHK->AsFloat+
								DocOPLCREDITCARD_ALL_DCHK->AsFloat+
								DocOPL_OTHER_DCHK->AsFloat-
								DocAllSUMDOC->AsFloat;

DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat-
								DocOPLPCCHK->AsFloat-
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocOPLPLATCARD_ALL_DCHK->AsFloat-
								DocOPL_OTHER_DCHK->AsFloat;
Doc->Post();
}
//----------------------------------------------------------------------------
//получено наличных
void __fastcall TDMDocCheck::DocNALCHKChange(TField *Sender)
{

DocSDACHA_DCHK->AsFloat=DocNALCHK->AsFloat+
								DocOPLPCCHK->AsFloat+
								DocOPLPLATCARD_ALL_DCHK->AsFloat+
								DocOPLCREDITCARD_ALL_DCHK->AsFloat+
								DocOPL_OTHER_DCHK->AsFloat-
								DocAllSUMDOC->AsFloat;

DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat-
								DocOPLPCCHK->AsFloat-
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocOPLPLATCARD_ALL_DCHK->AsFloat-
								DocOPL_OTHER_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
// оплата наличными
//оплата банковской картой
void __fastcall TDMDocCheck::DocOPLPCCHKChange(TField *Sender)
{


DocSDACHA_DCHK->AsFloat=DocNALCHK->AsFloat+
								DocOPLPCCHK->AsFloat+
								DocOPLPLATCARD_ALL_DCHK->AsFloat+
								DocOPLCREDITCARD_ALL_DCHK->AsFloat+
								DocOPL_OTHER_DCHK->AsFloat-
								DocAllSUMDOC->AsFloat;

DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat-
								DocOPLPCCHK->AsFloat-
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocOPLPLATCARD_ALL_DCHK->AsFloat-
								DocOPL_OTHER_DCHK->AsFloat;
}

//---------------------------------------------------------------------------
//оплата кредитными картами
void __fastcall TDMDocCheck::DocOPLCREDITCARD_ALL_DCHKChange(TField *Sender)
{
DocSDACHA_DCHK->AsFloat=DocNALCHK->AsFloat+
								DocOPLPCCHK->AsFloat+
								DocOPLPLATCARD_ALL_DCHK->AsFloat+
								DocOPLCREDITCARD_ALL_DCHK->AsFloat+
								DocOPL_OTHER_DCHK->AsFloat-
								DocAllSUMDOC->AsFloat;

DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat-
								DocOPLPCCHK->AsFloat-
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocOPLPLATCARD_ALL_DCHK->AsFloat-
								DocOPL_OTHER_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
//оплата платежными картами
void __fastcall TDMDocCheck::DocOPLPLATCARD_ALL_DCHKChange(TField *Sender)
{
DocSDACHA_DCHK->AsFloat=DocNALCHK->AsFloat+
								DocOPLPCCHK->AsFloat+
								DocOPLPLATCARD_ALL_DCHK->AsFloat+
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocAllSUMDOC->AsFloat;

DocOPLNALCHK->AsFloat=DocAllSUMDOC->AsFloat-
								DocOPLPCCHK->AsFloat-
								DocOPLCREDITCARD_ALL_DCHK->AsFloat-
								DocOPLPLATCARD_ALL_DCHK->AsFloat-
								DocOPL_OTHER_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
//ОПЛАТА КАРТАМИ ALL
void __fastcall TDMDocCheck::DocBeforeEdit(TDataSet *DataSet)
{
OldSumOplPlatCard=DocOPLPLATCARD_DCHK->AsFloat;
OldSumOplCreditCard=DocOPLCREDITCARD_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocOPLPLATCARD_DCHKChange(TField *Sender)
{
DocOPLPLATCARD_ALL_DCHK->AsFloat=DocOPLPLATCARD_ALL_DCHK->AsFloat-
							OldSumOplPlatCard+
							DocOPLPLATCARD_DCHK->AsFloat;
OldSumOplPlatCard=DocOPLPLATCARD_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocOPLCREDITCARD_DCHKChange(TField *Sender)
{
DocOPLCREDITCARD_ALL_DCHK->AsFloat=DocOPLCREDITCARD_ALL_DCHK->AsFloat-
							OldSumOplCreditCard+
							DocOPLCREDITCARD_DCHK->AsFloat;
OldSumOplCreditCard=DocOPLCREDITCARD_DCHK->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocCheck::DocOplBeforeEdit(TDataSet *DataSet)
{
OldTableSumOplPlatCard=DocOplSUMPLAT_DCHK_OPL->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocOplBeforeDelete(TDataSet *DataSet)
{
OldTableSumOplPlatCard=DocOplSUMPLAT_DCHK_OPL->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocOplAfterDelete(TDataSet *DataSet)
{
Doc->Edit();
DocOPLPLATCARD_ALL_DCHK->AsFloat=DocOPLPLATCARD_ALL_DCHK->AsFloat-
							OldTableSumOplPlatCard;
DocOPLCREDITCARD_ALL_DCHK->AsFloat=DocOPLCREDITCARD_ALL_DCHK->AsFloat-
							OldTableSumOplCreditCard;
Doc->Post();
OldTableSumOplPlatCard=0;
OldTableSumOplCreditCard=0;
}
//---------------------------------------------------------------------------
//платежная карта таблица
void __fastcall TDMDocCheck::DocOplSUMPLAT_DCHK_OPLChange(TField *Sender)
{
Doc->Edit();
DocOPLPLATCARD_ALL_DCHK->AsFloat=DocOPLPLATCARD_ALL_DCHK->AsFloat-
							OldTableSumOplPlatCard+
							DocOplSUMPLAT_DCHK_OPL->AsFloat;
Doc->Post();
OldTableSumOplPlatCard=DocOplSUMPLAT_DCHK_OPL->AsFloat;
}
//---------------------------------------------------------------------------
//кредитная карта таблица 

void __fastcall TDMDocCheck::DocOplSUMCREDIT_DCHK_OPLChange(TField *Sender)
{
Doc->Edit();
DocOPLCREDITCARD_ALL_DCHK->AsFloat=DocOPLCREDITCARD_ALL_DCHK->AsFloat-
							OldTableSumOplCreditCard+
							DocOplSUMCREDIT_DCHK_OPL->AsFloat;
Doc->Post();
OldTableSumOplCreditCard=DocOplSUMCREDIT_DCHK_OPL->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocCalcFields(TDataSet *DataSet)
{
DocALLOPL->AsFloat=DocNALCHK->AsFloat+
					DocOPLPCCHK->AsFloat+
					DocOPLPLATCARD_ALL_DCHK->AsFloat+
					DocOPLCREDITCARD_ALL_DCHK->AsFloat+
					DocOPL_OTHER_DCHK->AsFloat;
}
//---------------------------------------------------------------------------


void __fastcall TDMDocCheck::DocAllNAME_SINFBASE_OBMENGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text="Инф. база: "+DocAllNAME_SINFBASE_OBMEN->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocOPERCHKGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (DocOPERCHK->AsInteger==0){Text="Продажа";}
if (DocOPERCHK->AsInteger==1){Text="Возврат";}
}
//---------------------------------------------------------------------------


void __fastcall TDMDocCheck::DocAllIDSKLDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocCheck::DocIDKKMCHKChange(TField *Sender)
{
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------

