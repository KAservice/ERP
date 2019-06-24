//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocVipuskProd.h"
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
__fastcall TDMDocVipuskProd::TDMDocVipuskProd(TComponent* Owner)
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

void __fastcall TDMDocVipuskProd::DataModuleCreate(TObject *Sender)
{

//DMSprPrice=new TDMSprPrice(Application);
//IsmPrice=false;
//IsmSum=true;
Prosmotr=false;
SkladRozn=false;
flGetNumberDoc=true;

}
//---------------------------------------------------------------------------
bool TDMDocVipuskProd::Init(void)
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
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMDocVipuskProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocVipuskProd::DataModuleDestroy(TObject *Sender)
{
Part->kanRelease();
//delete DMSprPrice;
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

bool TDMDocVipuskProd::NewDoc(void)
{
bool result=false;
flGetNumberDoc=false;
try
	{
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
	DocAllTDOC->AsString="VIPPROD";
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
	if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
		{
		DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
		DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
		}
	DocAll->Post();

	Doc->Edit();
	if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
		{
		DocIDRTPRICE_DVIPPROD->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
		}
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

	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
return result;
}
//---------------------------------------------------------------------------
int TDMDocVipuskProd::GetNumberNewDoc(void)
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
bool TDMDocVipuskProd::OpenDoc(__int64 id)
{
bool result=false;

try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->ParamByName("ID")->AsInt64=id;
	Doc->ParamByName("ID")->AsInt64=id;
	DocAll->Active=true;
	Doc->Active=true;


	DocT->ParamByName("ID")->AsInt64=id;
	//DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE->AsInt64;
	DocT->Active=true;

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

	IdDoc=glStrToInt64(DocAllIDDOC->AsString);
	result=false;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
	
return result;
}
//-----------------------------------------------------------------------------
void TDMDocVipuskProd::TableAppend()
{
DocT->Append();
//DocT->FieldByName("IDDOCPRNT")->AsInteger=DocAll->FieldByName("IDDOC")->AsInteger;
//DocT->Post();

//DocIDTPRICE->ReadOnly=true;
}
//---------------------------------------------------------------------------
void TDMDocVipuskProd::TableDelete(void)
{
DocT->Delete();
//if (DocT->RecordCount==0)
//        {
//        DocIDTPRICE->ReadOnly=false;
//        }
}
//---------------------------------------------------------------------------
bool TDMDocVipuskProd::SaveDoc(void)
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

//запишем партии
DocT->First();
while (!DocT->Eof)
        {

		if (glStrToInt64(DocTIDPART_DVIPPRODT->AsString)==0)
                { //создаем нову пратию
                CreateNewPart();
                DocT->Edit();
				DocTIDPART_DVIPPRODT->AsString=Part->ElementIDPART->AsString;
                //ShowMessage(IntToStr(Part->ElementIDPART->AsInteger));
                DocT->Post();

				}
        else
                {
				Part->OpenElement(glStrToInt64(DocTIDPART_DVIPPRODT->AsString));
				if ((glStrToInt64(Part->ElementIDDOCPART->AsString)==glStrToInt64(DocAllIDDOC->AsString))
						&&(glStrToInt64(Part->ElementIDNOMPART->AsString)==glStrToInt64(DocTIDNOM_DVIPPRODT->AsString)))
                        {
                        }
                else
                        {
                        CreateNewPart();
                        DocT->Edit();
						DocTIDPART_DVIPPRODT->AsString=Part->ElementIDPART->AsString;
                        DocT->Post();
                        }

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
				Res=false;
				TextError=exception.Message;
				}

return Res;
}
//---------------------------------------------------------------------------

void TDMDocVipuskProd::CreateNewPart(void)
{
Part->NewElement(glStrToInt64(DocTIDNOM_DVIPPRODT->AsString));
Part->Element->Edit();

if(glStrToInt64(DocAllIDDOC->AsString)>0){Part->ElementIDDOCPART->AsString=DocAllIDDOC->AsString;}
if(glStrToInt64(DocAllIDFIRMDOC->AsString)>0){Part->ElementIDFIRMPART->AsString=DocAllIDFIRMDOC->AsString;}

Part->ElementDOCPART->AsString="Выпуск продукции "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsString;
Part->Element->Post();
Part->SaveElement();
}

//---------------------------------------------------------------------------
bool TDMDocVipuskProd::DvRegDoc(void)
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
bool TDMDocVipuskProd::CancelDvRegDoc(void)
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


bool TDMDocVipuskProd::DeleteDoc(__int64 id)
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

__int64 TDMDocVipuskProd::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='VIPPROD'");
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




void __fastcall TDMDocVipuskProd::DocTAfterDelete(TDataSet *DataSet)
{

NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocTBeforeDelete(TDataSet *DataSet)
{
OldRSummaStr=DocTRSUM_DVIPPRODT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DVIPPRODT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DVIPPRODT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVipuskProd::DocAllIDSKLDOCChange(TField *Sender)
{
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
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

void __fastcall TDMDocVipuskProd::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocVipuskProd::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DVIPPROD->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DVIPPROD->AsString=DocAllIDBASE_GALLDOC->AsString;
	} 
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DVIPPROD->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}   

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DVIPPRODT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocTKOL_DVIPPRODTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DVIPPRODT->AsFloat;
DocTRSUM_DVIPPRODT->AsFloat=NewRSummaStr=DocTKOL_DVIPPRODT->AsFloat*DocTRPRICE_DVIPPRODT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocTRPRICE_DVIPPRODTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DVIPPRODT->AsFloat;
DocTRSUM_DVIPPRODT->AsFloat=NewRSummaStr=DocTKOL_DVIPPRODT->AsFloat*DocTRPRICE_DVIPPRODT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocVipuskProd::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

