//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UDMDocRasborkaKompl.h"
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
__fastcall TDMDocRasborkaKompl::TDMDocRasborkaKompl(TComponent* Owner)
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

void __fastcall TDMDocRasborkaKompl::DataModuleCreate(TObject *Sender)
{


Prosmotr=false;
SkladRozn=false;
flGetNumberDoc=true;

}
//---------------------------------------------------------------------------
bool TDMDocRasborkaKompl::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
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

//����������
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
int TDMDocRasborkaKompl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocRasborkaKompl::DataModuleDestroy(TObject *Sender)
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

bool TDMDocRasborkaKompl::NewDoc(void)
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
	DocAllTDOC->AsString="RASBKOMPL";
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
		DocIDRTPRICE_DRASBKOMPL->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
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
int TDMDocRasborkaKompl::GetNumberNewDoc(void)
{
int result=0;
//������� ����� ���������
if (flGetNumberDoc==false) return result;

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
bool TDMDocRasborkaKompl::OpenDoc(__int64 id)
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
void TDMDocRasborkaKompl::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TDMDocRasborkaKompl::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TDMDocRasborkaKompl::SaveDoc(void)
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
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return Res;
		}
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������������� ����� ���������!";
		return Res;
		}
	}

//������� ������
DocT->First();
while (!DocT->Eof)
		{
		if (glStrToInt64(DocTIDPART_DRASBKOMPLT->AsString)==0)
                { //������� ���� ������
                CreateNewPart();
				DocT->Edit();
				DocTIDPART_DRASBKOMPLT->AsString=Part->ElementIDPART->AsString;
                //ShowMessage(IntToStr(Part->ElementIDPART->AsInteger));
				DocT->Post();

				}
        else
                {
				Part->OpenElement(glStrToInt64(DocTIDPART_DRASBKOMPLT->AsString));
				if ((glStrToInt64(Part->ElementIDDOCPART->AsString)==glStrToInt64(DocAllIDDOC->AsString))
						&&(glStrToInt64(Part->ElementIDNOMPART->AsString)==glStrToInt64(DocTIDNOM_DRASBKOMPLT->AsString)))
                        {
						}
                else
                        {
                        CreateNewPart();
						Doc->Edit();
						DocTIDPART_DRASBKOMPLT->AsString=Part->ElementIDPART->AsString;
						Doc->Post();
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
				TextError=exception.Message;
				}

return Res;
}
//---------------------------------------------------------------------------

void TDMDocRasborkaKompl::CreateNewPart(void)
{
Part->NewElement(glStrToInt64(DocTIDNOM_DRASBKOMPLT->AsString));
Part->Element->Edit();

if(glStrToInt64(DocAllIDDOC->AsString)>0)
	{
	Part->ElementIDDOCPART->AsString=DocAllIDDOC->AsString;
	}
if(glStrToInt64(DocAllIDFIRMDOC->AsString)>0)
	{
	Part->ElementIDFIRMPART->AsString=DocAllIDFIRMDOC->AsString;
	}

Part->ElementDOCPART->AsString="������ ��������� "+DocAllNUMDOC->AsString+" �� " +DocAllPOSDOC->AsString;
Part->Element->Post();
Part->SaveElement();
}

//---------------------------------------------------------------------------
bool TDMDocRasborkaKompl::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
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
bool TDMDocRasborkaKompl::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
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


bool TDMDocRasborkaKompl::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������� ����� ���������!";
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

__int64 TDMDocRasborkaKompl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;
pFIBQ->Close();

pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDDOC from GALLDOC where NUMDOC=:PARAM_NUMDOC and TDOC='RASBKOMPL'");
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
void __fastcall TDMDocRasborkaKompl::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_DRASBKOMPL->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DRASBKOMPL->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TDMDocRasborkaKompl::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_DRASBKOMPLT->AsString=DocAllIDDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_DRASBKOMPLT->AsString=DocAllIDBASE_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocAllIDSKLDOCChange(TField *Sender)
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

void __fastcall TDMDocRasborkaKompl::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocAllIDBASE_GALLDOCChange(TField *Sender)
{

	if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_DRASBKOMPL->AsString=DocAllIDBASE_GALLDOC->AsString;
		Doc->Post();
		}   

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_DRASBKOMPLT->AsString=DocAllIDBASE_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
GetNumberNewDoc();
}
//---------------------------------------------------------------------------
void __fastcall TDMDocRasborkaKompl::DocTAfterDelete(TDataSet *DataSet)
{

NewRSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocTBeforeDelete(TDataSet *DataSet)
{
OldRSummaStr=DocTRSUM_DRASBKOMPLT->AsFloat;
}
//----------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocTKOL_DRASBKOMPLTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_DRASBKOMPLT->AsFloat;
DocTRSUM_DRASBKOMPLT->AsFloat=NewRSummaStr=DocTKOL_DRASBKOMPLT->AsFloat*DocTRPRICE_DRASBKOMPLT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocTRPRICE_DRASBKOMPLTChange(
      TField *Sender)
{
OldRSummaStr=DocTRSUM_DRASBKOMPLT->AsFloat;
DocTRSUM_DRASBKOMPLT->AsFloat=NewRSummaStr=DocTKOL_DRASBKOMPLT->AsFloat*DocTRPRICE_DRASBKOMPLT->AsFloat;
DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldRSummaStr+NewRSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRasborkaKompl::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

