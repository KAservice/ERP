//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMRegZak.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMRegZak::TDMRegZak(TComponent* Owner)
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
bool TDMRegZak::Init(void)
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

Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
Ob->Database=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
IBQPrint->Database=DM_Connection->pFIBData;
IBQMPrig->Database=DM_Connection->pFIBData;
IBQNom->Database=DM_Connection->pFIBData;

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
int TDMRegZak::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegZak::DataModuleDestroy(TObject *Sender)
{

Doc->Active=false;
DocT->Active=false;
IBQPrint->Active=false;
IBQMPrig->Active=false;
IBQNom->Active=false;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void TDMRegZak::NewDoc(__int64 ob)
{
IdOb=ob;
Doc->Active=false;
DocT->Active=false;

Doc->ParamByName("ID")->AsInteger=0;
DocT->ParamByName("IDZAK")->AsInteger=0;
DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInteger=IdTypePrice;

Doc->Active=true;
DocT->Active=true;


Doc->Insert();
IdDoc=DocID_ZAK->AsInteger;
if (IdOb>0)
        {
        DocIDOB_ZAK->AsInteger=IdOb;
        }
Doc->Post();

Ob->Active=false;
Ob->ParamByName("ID")->AsInteger=IdOb;
Ob->Active=true;;

}
//---------------------------------------------------------------------------
void TDMRegZak::OpenDoc(__int64 id)
{
IdDoc=id;
Doc->Active=false;
DocT->Active=false;
Ob->Active=false;

Doc->ParamByName("ID")->AsString=id;
DocT->ParamByName("IDZAK")->AsString=id;
DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsString=IdTypePrice;
Doc->Active=true;
DocT->Active=true;

Ob->ParamByName("ID")->AsString=DocIDOB_ZAK->AsString;
Ob->Active=true;;


}
//-----------------------------------------------------------------------------
void TDMRegZak::AddDocNewString()
{
DocT->Append();
DocTIDZ_ZAKT->AsInteger=DocID_ZAK->AsInteger;
DocT->Post();
}
//---------------------------------------------------------------------------
void TDMRegZak::DeleteStringDoc(void)
{
DocT->Delete();
}
//---------------------------------------------------------------------------
bool TDMRegZak::DeleteDoc(__int64 id)
{
bool Res=false;
OpenDoc(id);
DocT->First();
while (!DocT->Eof)
        {
        DocT->Delete();
        }

Doc->Delete();


try
        {
        DocT->ApplyUpdates();
        Doc->ApplyUpdates();
		IBTrUpdate->Commit();
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

//---------------------------------------------------------------------------
bool TDMRegZak::SaveDoc(void)
{
bool Res=false;

Doc->Edit();
DocSUM_ZAK->AsFloat=Summa();
Doc->Post();
try
        {
        IdDoc=glStrToInt64(DocID_ZAK->AsString);
        Doc->ApplyUpdates();
        DocT->ApplyUpdates();
		IBTrUpdate->Commit();
        Res=true;
        OpenDoc(IdDoc);
        }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				Res=false;
				}

return Res;
}
//----------------------------------------------------------------------------
void TDMRegZak::CloseDoc(void)
{
        Doc->CancelUpdates();
        DocT->CancelUpdates();

        Doc->Active=false;
        DocT->Active=false;
}
//---------------------------------------------------------------------------
double TDMRegZak::Summa()
{
SummaDoc=0;
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_ZAKT->AsFloat;
        DocT->Next();
        }
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}

//------------------------------------------------------------------------------

void TDMRegZak::OpenMPrig(void)
{
IBQNom->Active=false;
IBQNom->ParamByName("PARAM_IDNOM")->AsString=DocTIDNOM_ZAKT->AsString;
IBQNom->Active=true;

}
//---------------------------------------------------------------------------

void __fastcall TDMRegZak::DocCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------
//удаление
void __fastcall TDMRegZak::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
Doc->Edit();
DocSUM_ZAK->AsFloat=DocSUM_ZAK->AsFloat-OldSummaStr+NewSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMRegZak::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_ZAKT->AsFloat;	
}
//---------------------------------------------------------------------------
//количество
void __fastcall TDMRegZak::DocTKOLOT_ZAKTChange(TField *Sender)
{
OldSummaStr=DocTSUM_ZAKT->AsFloat;

DocTSUMNAD_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRNAD_ZAKT->AsFloat/100;
DocTSUMSK_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRSK_ZAKT->AsFloat/100;

DocTSUM_ZAKT->AsFloat=NewSummaStr=DocTKOLOT_ZAKT->AsFloat*DocTPRICE_ZAKT->AsFloat
				-DocTSUMSK_ZAKT->AsFloat+DocTSUMNAD_ZAKT->AsFloat;
Doc->Edit();
DocSUM_ZAK->AsFloat=DocSUM_ZAK->AsFloat-OldSummaStr+NewSummaStr;
Doc->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMRegZak::DocTKF_ZAKTChange(TField *Sender)
{
//DocTPRICE_ZAKT->AsFloat=DocTZNACH_PRICE->AsFloat* DocTKF_ZAKT->AsFloat;
}
//---------------------------------------------------------------------------
//цена
void __fastcall TDMRegZak::DocTPRICE_ZAKTChange(TField *Sender)
{
OldSummaStr=DocTSUM_ZAKT->AsFloat;

DocTSUMNAD_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRNAD_ZAKT->AsFloat/100;

DocTSUMSK_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRSK_ZAKT->AsFloat/100;

DocTSUM_ZAKT->AsFloat=NewSummaStr=DocTKOLOT_ZAKT->AsFloat*DocTPRICE_ZAKT->AsFloat
								-DocTSUMSK_ZAKT->AsFloat+DocTSUMNAD_ZAKT->AsFloat;
Doc->Edit();
DocSUM_ZAK->AsFloat=DocSUM_ZAK->AsFloat-OldSummaStr+NewSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMRegZak::DocTPRSK_ZAKTChange(TField *Sender)
{
OldSummaStr=DocTSUM_ZAKT->AsFloat;

DocTSUMNAD_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRNAD_ZAKT->AsFloat/100;
DocTSUMSK_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRSK_ZAKT->AsFloat/100;

DocTSUM_ZAKT->AsFloat=NewSummaStr=DocTKOLOT_ZAKT->AsFloat*DocTPRICE_ZAKT->AsFloat
				-DocTSUMSK_ZAKT->AsFloat+DocTSUMNAD_ZAKT->AsFloat;


Doc->Edit();
DocSUM_ZAK->AsFloat=DocSUM_ZAK->AsFloat-OldSummaStr+NewSummaStr;
Doc->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDMRegZak::DocTPRNAD_ZAKTChange(TField *Sender)
{
OldSummaStr=DocTSUM_ZAKT->AsFloat;

DocTSUMNAD_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRNAD_ZAKT->AsFloat/100;
DocTSUMSK_ZAKT->AsFloat=DocTPRICE_ZAKT->AsFloat
								*DocTKOLOT_ZAKT->AsFloat
								*DocTPRSK_ZAKT->AsFloat/100;

DocTSUM_ZAKT->AsFloat=NewSummaStr=DocTKOLOT_ZAKT->AsFloat*DocTPRICE_ZAKT->AsFloat
				-DocTSUMSK_ZAKT->AsFloat+DocTSUMNAD_ZAKT->AsFloat;


Doc->Edit();
DocSUM_ZAK->AsFloat=DocSUM_ZAK->AsFloat-OldSummaStr+NewSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

