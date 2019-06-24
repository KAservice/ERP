//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UDMDocSborkaKompl.h"
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
__fastcall TDMDocSborkaKompl::TDMDocSborkaKompl(TComponent* Owner)
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

void __fastcall TDMDocSborkaKompl::DataModuleCreate(TObject *Sender)
{


Prosmotr=false;
SkladRozn=false;
flGetNumberDoc=true;

}
//---------------------------------------------------------------------------
bool TDMDocSborkaKompl::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;

NumDoc->Database=DM_Connection->pFIBData;

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPart.1",IID_IDMSprPart,
													(void**)&Part);
Part->Init(InterfaceMainObject,InterfaceOwnerObject);

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMDocSborkaKompl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSborkaKompl::DataModuleDestroy(TObject *Sender)
{
Part->kanRelease();

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

bool TDMDocSborkaKompl::NewDoc(void)
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

	IdDoc=DocAllIDDOC->AsInt64;

	DocAllPOSDOC->AsDateTime=Now();
	DocAllTDOC->AsString="SBKOMPL";
	if (DM_Connection->UserInfoID_USER->AsInt64!=0)
		{
		DocAllIDUSERDOC->AsInt64=DM_Connection->UserInfoID_USER->AsInt64;
		DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
		}
	if (DM_Connection->UserInfoIDFIRM_USER->AsInt64!=0)
		{
		DocAllIDFIRMDOC->AsInt64=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
		DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
		}
	if (DM_Connection->UserInfoIDSKLAD_USER->AsInt64!=0)
		{
		DocAllIDSKLDOC->AsInt64=DM_Connection->UserInfoIDSKLAD_USER->AsInt64;
		DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
		}
	if (DM_Connection->UserInfoIDBASE_SUSER->AsInt64!=0)
		{
		DocAllIDBASE_GALLDOC->AsInt64=DM_Connection->UserInfoIDBASE_SUSER->AsInt64;
		DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
		}
	DocAll->Post();

	Doc->Edit();
	if (DM_Connection->UserInfoIDTPRICE_USER->AsInt64!=0)
		{
		DocIDRTPRICE_DSBKOMPL->AsInt64=DM_Connection->UserInfoIDTPRICE_USER->AsInt64;
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
int TDMDocSborkaKompl::GetNumberNewDoc(void)
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
bool TDMDocSborkaKompl::OpenDoc(__int64 id)
{
bool result=false;
try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->ParamByName("ID")->AsInt64=id;
	Doc->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocAll->Active=true;
	Doc->Active=true;


	DocT->ParamByName("PARAM_IDDOC")->AsInt64=id;
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

	IdDoc=DocAllIDDOC->AsInt64;
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
void TDMDocSborkaKompl::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TDMDocSborkaKompl::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TDMDocSborkaKompl::SaveDoc(void)
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

		if (DocIDPART_DSBKOMPL->AsInt64==0)
                { //создаем нову пратию
                CreateNewPart();
				Doc->Edit();
				DocIDPART_DSBKOMPL->AsInt64=Part->ElementIDPART->AsInt64;
                //ShowMessage(IntToStr(Part->ElementIDPART->AsInteger));
				Doc->Post();

				}
        else
                {
				Part->OpenElement(DocIDPART_DSBKOMPL->AsInt64);
				if ((Part->ElementIDDOCPART->AsInt64==DocAllIDDOC->AsInt64)
						&&(Part->ElementIDNOMPART->AsInt64==DocIDNOM_DSBKOMPL->AsInt64))
                        {
						}
                else
                        {
                        CreateNewPart();
						Doc->Edit();
						DocIDPART_DSBKOMPL->AsInt64=Part->ElementIDPART->AsInt64;
						Doc->Post();
                        }

                }



try
        {
        IdDoc=DocAllIDDOC->AsInt64;
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

void TDMDocSborkaKompl::CreateNewPart(void)
{
Part->NewElement(DocIDNOM_DSBKOMPL->AsInt64);
Part->Element->Edit();

if(DocAllIDDOC->AsInt64>0)
	{
	Part->ElementIDDOCPART->AsInt64=DocAllIDDOC->AsInt64;
	}
if(DocAllIDFIRMDOC->AsInt64>0)
	{
	Part->ElementIDFIRMPART->AsInt64=DocAllIDFIRMDOC->AsInt64;
	}

Part->ElementDOCPART->AsString="Сборка комплекта "+DocAllNUMDOC->AsString+" от " +DocAllPOSDOC->AsString;
Part->Element->Post();
Part->SaveElement();
}

//---------------------------------------------------------------------------
bool TDMDocSborkaKompl::DvRegDoc(void)
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
bool TDMDocSborkaKompl::CancelDvRegDoc(void)
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
void __fastcall TDMDocSborkaKompl::DocT1CalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;
}

//---------------------------------------------------------------------------


bool TDMDocSborkaKompl::DeleteDoc(__int64 id)
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

__int64 TDMDocSborkaKompl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
pFIBQ->Close();

pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='SBKOMPL'");
pFIBQ->SQL->Add(" and CAST(POSDOC AS DATE)=:PARAM_DATE");
pFIBQ->ParamByName("PARAM_NUMDOC")->AsInteger=number_doc;
pFIBQ->ParamByName("PARAM_DATE")->AsDate=date_doc;
pFIBQ->ExecQuery();

if (pFIBQ->RecordCount > 0)
	{
	res=pFIBQ->FieldByName("IDDOC")->AsInt64;
	}
else res=0;
pFIBQ->Close();

return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSborkaKompl::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DSBKOMPL->AsInt64=DocAllIDDOC->AsInt64;
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DSBKOMPL->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocSborkaKompl::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DSBKOMPLT->AsInt64=DocAllIDDOC->AsInt64;

	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		DocTIDBASE_DSBKOMPLT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocAllIDSKLDOCChange(TField *Sender)
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

void __fastcall TDMDocSborkaKompl::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (DocAllIDBASE_GALLDOC->AsInt64!=0)
		{
		Doc->Edit();
		DocIDBASE_DSBKOMPL->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
		Doc->Post();
		}   

	DocT->First();
	while (!DocT->Eof)
		{
		if (DocAllIDBASE_GALLDOC->AsInt64!=0)
			{
			DocT->Edit();
			DocTIDBASE_DSBKOMPLT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
			DocT->Post();
			}
		DocT->Next();
		}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------
void __fastcall TDMDocSborkaKompl::DocTAfterDelete(TDataSet *DataSet)
{

NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocTBeforeDelete(TDataSet *DataSet)
{
OldRSummaStr=DocTRSUM_DSBKOMPLT->AsFloat;
}
//----------------------------------------------------------------------------
void __fastcall TDMDocSborkaKompl::DocTKOL_DSBKOMPLTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DSBKOMPLT->AsFloat;
DocTRSUM_DSBKOMPLT->AsFloat=NewRSummaStr=DocTKOL_DSBKOMPLT->AsFloat*DocTRPRICE_DSBKOMPLT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocTRPRICE_DSBKOMPLTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DSBKOMPLT->AsFloat;
DocTRSUM_DSBKOMPLT->AsFloat=NewRSummaStr=DocTKOL_DSBKOMPLT->AsFloat*DocTRPRICE_DSBKOMPLT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocSborkaKompl::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

