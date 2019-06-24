//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMDocRecKDR.h"
#include "UDM.h"
#include "UDMSetup.h"
#include "UDMSprUser.h"
#include "UDMTableNumberDoc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TDMDocRecKDR::TDMDocRecKDR(TComponent* Owner)
        : TDataModule(Owner)
{
}
//--------------------------------------------------------------------------
void __fastcall TDMDocRecKDR::DataModuleCreate(TObject *Sender)
{
////
}

//----------------------------------------------------------------------------
void __fastcall TDMDocRecKDR::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
NumDoc->Close();
}

//----------------------------------------------------------------------------
void TDMDocRecKDR::NewDoc(void)
{
        DocAll->Open();
        Doc->Open();
        DocAll->Insert();
        Doc->Insert();

        IdDoc=DocAllIDDOC->AsInteger;
        DocIDDOC_DREC_KDR->AsInteger=IdDoc;
        DocAllPOSDOC->AsDateTime=Now();
        DocAllTDOC->AsString="REC_KDR";
        DocAllIDUSERDOC->AsInteger=glUser->ElementID_USER->AsInteger;
        DocAllFNAME_USER->AsString=glUser->ElementFNAME_USER->AsString;
        DocAllPREFIKSDOC->AsString=glUser->ElementPREFIKS_USER->AsString;
        DocAllNAME_SINFBASE_OBMEN->AsString=glUser->ElementNAME_SINFBASE_OBMEN->AsString;
        //получим номер документа
		NumDoc->Active=false;
		TDMTableNumberDoc * dm_num=new TDMTableNumberDoc(Application);
		NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REC_KDR");
        NumDoc->Open();
        DocAllNUMDOC->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
		delete dm_num;
		NumDoc->Active=false;
		
        DocAll->Post();
        Doc->Post();

}
//----------------------------------------------------------------------------
void TDMDocRecKDR::OpenDoc(int Id)
{

        DocAll->Active=false;
        Doc->Active=false;

        DocAll->ParamByName("PARAM_ID")->AsInteger=Id;
        Doc->ParamByName("PARAM_IDDOC")->AsInteger=Id;

        DocAll->Open();
        Doc->Open();

TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

DocAllPREFIKSDOC->ReadOnly=true;

}

//----------------------------------------------------------------------------
void TDMDocRecKDR::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        IBTr->Rollback();
}
//----------------------------------------------------------------------------
bool TDMDocRecKDR::SaveDoc(void)
{
bool result=false;

TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
        {
//        if (CancelDvRegDoc()==true)
//                {
                IdDoc=DocAllIDDOC->AsInteger;
				DocAll->ApplyUpdToBase();
				Doc->ApplyUpdToBase();
				IBTrUpdate->Commit();
				DocAll->CommitUpdToCach();
				Doc->CommitUpdToCach();
                OpenDoc(IdDoc);
                result=true;
//                }
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				result=false;
				TextError=exception.Message;
				Error=true;
				}
return result;
}
//----------------------------------------------------------------------------
bool TDMDocRecKDR::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
        {
        if (CancelDvRegDoc()==true)
                {
                //по регистру взаиморасчеты
                IdDoc=DocAllIDDOC->AsInteger;
                Doc2->Active=false;
                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
                Doc2->Active=true;
                Doc2->Edit();
                Doc2PRDOC->AsInteger=1;
                Doc2->Post();
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
return result;
}
//-----------------------------------------------------------------------------
bool TDMDocRecKDR::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return result;
        }

try
        {
        IdDoc=DocAllIDDOC->AsInteger;


                Doc2->Active=false;
                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
                Doc2->Active=true;
                Doc2->Edit();
                Doc2PRDOC->AsInteger=0;
                Doc2->Post();
                IBTrDvReg->Commit();
                result=true;

        }

catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				Error=true;
				}

return result;
}
//---------------------------------------------------------------------------



void __fastcall TDMDocRecKDR::DocAllPOSDOCChange(TField *Sender)
{
TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;
}
//---------------------------------------------------------------------------

bool TDMDocRecKDR::DeleteDoc(int id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
        {
        Error=true;
        TextError="ѕозици€ документа меньше позиции запрета редактировани€!";
        return res;
        }

try
        {
        if (CancelDvRegDoc()!=true)
                {
                res=false;
                return res;
                }

        Doc->Delete();
        DocAll->Delete();

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
				Error=true;
				}
return res;

}
//-----------------------------------------------------------------------------

void __fastcall TDMDocRecKDR::DocAllNewRecord(TDataSet *DataSet)
{
DocAllGID_DOC->AsString=
		gl_prefiks_ib+IntToStr(DocAllIDDOC->AsInteger);	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRecKDR::DocNewRecord(TDataSet *DataSet)
{
DocGID_DREC_KDR->AsString=
		gl_prefiks_ib+IntToStr(DocID_DREC_KDR->AsInteger);	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRecKDR::DocAllNAME_SINFBASE_OBMENGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
Text="»нф. база: "+DocAllNAME_SINFBASE_OBMEN->AsString;
}
//---------------------------------------------------------------------------

