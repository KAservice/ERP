//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprSostProd.h"
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
__fastcall TDMSprSostProd::TDMSprSostProd(TComponent* Owner)
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
bool TDMSprSostProd::Init(void)
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

Table->Database=DM_Connection->pFIBData;


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
int TDMSprSostProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprSostProd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprSostProd::OpenTable(__int64 NomRest)
{
WORD Year;
WORD Month;
WORD Day;
DecodeDate(Pos,Year,Month,Day);
IdNomRest=NomRest;
Table->Active=false;
Table->ParamByName("PARAM_IDNOMREST")->AsInt64=NomRest;
Table->ParamByName("PARAM_MONTH")->AsInteger=Month;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprSostProd::NewElement(__int64 NomRest)
{
IdNomRest=NomRest;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprSostProd::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		if (IBTrUpdate->Active==true) IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSprSostProd::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMSprSostProd::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------




void __fastcall TDMSprSostProd::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;

//если значения не заданы то считаем что 1

if (KFEdProd==0){KFEdProd=1;}

if (KolEdProd==0) {KolEdProd=1;}

float KFKompl=TableKF_SPROD->AsFloat;
if(KFKompl==0){KFKompl=1;}

//общий сезонный коэф.
if (TableVALUE_SSEZKF->AsFloat==0)
        {
		TableSEZKF->AsFloat=1;
        }
else
		{
        TableSEZKF->AsFloat=TableVALUE_SSEZKF->AsFloat;
		}

// сезонный к на эту продукцию данного ингридиента
if (TableVALUE_SSEZKF_SPROD->AsFloat==0)
		{
		TableSEZKF_SPROD->AsFloat=1;
		}
else
		{
		TableSEZKF_SPROD->AsFloat=TableVALUE_SSEZKF_SPROD->AsFloat;
		}


TableNABASED->AsFloat=TableSEZKF_SPROD->AsFloat*TableSEZKF->AsFloat
						*TableBKOL_SPROD->AsFloat*KFKompl/(KolEdProd*KFEdProd);

TableNNABASED->AsFloat=TableSEZKF_SPROD->AsFloat*TableSEZKF->AsFloat
						*TableNKOL_SPROD->AsFloat*KFKompl/(KolEdProd*KFEdProd);	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprSostProd::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDNOMREST_SPROD->AsInt64=IdNomRest;
TableSPIS_SPROD->AsInteger=1;

}
//---------------------------------------------------------------------------




void __fastcall TDMSprSostProd::TableSPIS_SPRODGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (TableSPIS_SPROD->AsInteger==1)
		{
		Text="Да";
		}
else
		{
		Text="Нет";
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprSostProd::TableSPIS_SPRODSetText(TField *Sender, const UnicodeString Text)

{
if(Text=="Да")
		{
		TableSPIS_SPROD->AsInteger=1;
		}
else
		{
		TableSPIS_SPROD->AsInteger=0;
		}
}
//---------------------------------------------------------------------------

