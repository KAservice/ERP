//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UREM_DMDocRemont.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMTableNumberDoc.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "UkanFile.h"
#include "UkanTxtFile.h"
#include "IDMSprNom.h"
#include "IDMSprNachisl.h"
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
__fastcall TREM_DMDocRemont::TREM_DMDocRemont(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;
}
//---------------------------------------------------------------------------

bool TREM_DMDocRemont::Init(void)
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
TypeNom->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;

NumDoc->Database=DM_Connection->pFIBData;

pFIBQ->Database=DM_Connection->pFIBData;

QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMDocRemont::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocRemont::DataModuleDestroy(TObject *Sender)
{

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

bool TREM_DMDocRemont::NewDoc(void)
{
bool result=false;
try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->Active=true;
	Doc->Active=true;
	TypeNom->Active=true;
	DocT->Active=true;

	DocAll->Append();
	Doc->Append();

	IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);

	//получим номер документа
	NumDoc->Active=false;
	IDMTableNumberDoc * dm_num;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
	dm_num->Init(InterfaceMainObject,0);
	NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMONT");
	NumDoc->Open();
	DocAllNUM_REM_GALLDOC->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
	dm_num->kanRelease();
	NumDoc->Active=false;

	DocAllPOS_REM_GALLDOC->AsDateTime=Now();
	DocAllTDOC_REM_GALLDOC->AsString="REMONT";
	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
		{
		DocAllIDUSER_REM_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
		DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
		{
		DocAllIDFIRM_REM_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
		DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
		{
		DocAllIDSKLAD_REM_GALLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
		DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
		}
	if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
		{
		DocAllIDBASE_REM_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
		DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
		}
	DocAll->Post();

	Doc->Edit();
	if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
		{
		DocIDTPRICE_REM_DREMONT->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;
		}
	Doc->Post();

	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;

	}
	
return result;
}
//---------------------------------------------------------------------------
bool TREM_DMDocRemont::OpenDoc(__int64 id)
{
bool result=false;

try
	{
	DocAll->Active=false;
	Doc->Active=false;
	DocT->Active=false;

	DocAll->ParamByName("PARAM_IDDOC")->AsInt64=id;
	Doc->ParamByName("PARAM_IDDOC")->AsInt64=id;
	DocAll->Active=true;
	Doc->Active=true;

    TypeNom->Active=true;
	DocT->ParamByName("PARAM_IDDOC")->AsInt64=id;
	//DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE->AsInt64;
	DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
	Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

	DocAllIDBASE_REM_GALLDOC->ReadOnly=true;

	IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
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
void TREM_DMDocRemont::TableAppend()
{
DocT->Append();
}
//---------------------------------------------------------------------------
void TREM_DMDocRemont::TableDelete(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TREM_DMDocRemont::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return Res;
		}
		
if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="Ќельз€ редактировать чужие документы!";
		return Res;
		}
	}

try
        {
		IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
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
bool TREM_DMDocRemont::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
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
bool TREM_DMDocRemont::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
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

bool TREM_DMDocRemont::DeleteDoc(__int64 id)
{
bool res=false;

BeforeDeleteDoc();


OpenDoc(id);
if (Prosmotr==true)
		{
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
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
void __fastcall TREM_DMDocRemont::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DREMONT->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DREMONT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_DMDocRemont::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DREMONTT->AsString=DocAllID_REM_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_REM_DREMONTT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewSummaStr=0;
NewSummaMexStr=0;
NewSummaMexStr=0;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_REM_DREMONTT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocTKOL_REM_DREMONTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DREMONTT->AsFloat;

DocTSUM_REM_DREMONTT->AsFloat=NewSummaStr=DocTKOL_REM_DREMONTT->AsFloat*
											DocTPRICE_REM_DREMONTT->AsFloat;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocTPRICE_REM_DREMONTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REM_DREMONTT->AsFloat;


DocTSUM_REM_DREMONTT->AsFloat=NewSummaStr=DocTKOL_REM_DREMONTT->AsFloat*
											DocTPRICE_REM_DREMONTT->AsFloat;


DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocRemont::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocRemont::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)
{
	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_REM_DREMONT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		Doc->Post();
		}

	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_DREMONTT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
}
//---------------------------------------------------------------------------
void TREM_DMDocRemont::BeforeDeleteDoc(void)
{
bool fl_add_text=false;
__int64 id_user;
int fl_save_doc;
UnicodeString catalog_name="";

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);

DMSetup->OpenElement(410);    //пользователь
id_user=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);

if (id_user !=0)
	{
	if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString) == id_user)
		{
		DMSetup->OpenElement(411);
		if (DMSetup->ElementVALUE_SETUP->AsString=="1")
			{
			DMSetup->OpenElement(412);
			catalog_name=DMSetup->ElementVALUE_SETUP->AsString;
			if (DirectoryExists(catalog_name)==true)
				{
				fl_add_text=true;
				}
			else
				{
				fl_add_text=false;
				}
			}
		}
	}
DMSetup->kanRelease();

UnicodeString file_name=catalog_name+"\\"+Trim(DocAllIDUSER_REM_GALLDOC->AsString)+".txt";
UnicodeString str="";


if (fl_add_text==true)
	{
	IDMSprNom * dm_nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													 (void**)&dm_nom);
	dm_nom->Init(InterfaceMainObject,InterfaceImpl);


	IDMSprNachisl * dm_nachisl;
	InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNachisl,IID_IDMSprNachisl,
													 (void**)&dm_nachisl);
	dm_nachisl->Init(InterfaceMainObject,InterfaceImpl);


	TkanTxtFile * f=new TkanTxtFile;
	DocT->First();
	while(!DocT->Eof)
		{
		dm_nom->OpenElement(glStrToInt64(DocTIDNOM_REM_DREMONTT->AsString));
		if (dm_nom->ElementTNOM->AsInteger==1) //услуга
			{
			dm_nachisl->FindElement(1,glStrToInt64(DocTIDNOM_REM_DREMONTT->AsString));
			str="";
			str=str+glDopStrR(DocIDZ_REM_DREMONT->AsString," ", 20);
			str=str+glDopStrR(DocNUM_REM_Z->AsString," ", 10);

			str=str+glDopStrR(DocAllPOS_REM_GALLDOC->AsString," ", 30);
			str=str+glDopStrR(DocMODEL_REM_Z->AsString," ", 50);
			str=str+glDopStrR(DocSERNUM_REM_Z->AsString," ", 30);

			str=str+glDopStrR(dm_nom->ElementCODENOM->AsString," ", 10);
			if (dm_nom->ElementNAMENOM->AsString.Length() >= 100)
				{
				str=str+dm_nom->ElementNAMENOM->AsString.SetLength(100);
				}
			else
				{
				str=str+glDopStrR(dm_nom->ElementNAMENOM->AsString," ", 100);
				}
            str=str+glDopStrL(FloatToStrF(DocTSUM_REM_DREMONTT->AsFloat,ffFixed,10,2), " ", 20);
			str=str+glDopStrL(FloatToStrF(dm_nachisl->ElementVALUE_SNACHISL->AsFloat,ffFixed,10,2), " ", 20);


			f->AddString(file_name,str);
			}
		DocT->Next();
		}
	delete f;
	dm_nom->kanRelease();
	dm_nachisl->kanRelease();
	}



}
//----------------------------------------------------------------------------

