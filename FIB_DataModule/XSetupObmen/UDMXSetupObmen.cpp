//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMXSetupObmen.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMXTableIsm.h"
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
__fastcall TDMXSetupObmen::TDMXSetupObmen(TComponent* Owner)
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
bool TDMXSetupObmen::Init(void)
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
Element->Database=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
BaseForObmen->Database=DM_Connection->pFIBData;
TypePriceForObmen->Database=DM_Connection->pFIBData;

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
int TDMXSetupObmen::Done(void)
{

return -1;
}
//--------------------------------------------------------------------------------
void __fastcall TDMXSetupObmen::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
BaseForObmen->Active=false;
TypePriceForObmen->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMXSetupObmen::OpenTable(void)
{
Table->Close();
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMXSetupObmen::NewElement(void)
{
Element->Active=true;
Element->Append();
BaseForObmen->Open();
TypePriceForObmen->Open();

}
//--------------------------------------------------------------------------
bool TDMXSetupObmen::OpenElement(__int64 id_base)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
Element->Active=true;

BaseForObmen->Open();
TypePriceForObmen->Open();

return result;
}
//---------------------------------------------------------------------------

bool  TDMXSetupObmen::SaveElement()
{
bool result=false;
__int64 id_base=ElementIDBASE_XSETUP_OBMEN->AsInt64;
try
        {
		Element->ApplyUpdates();
		BaseForObmen->ApplyUpdates();
		TypePriceForObmen->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(id_base);
        result=true;
        }
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}

return result;
}
//---------------------------------------------------------------------------
bool TDMXSetupObmen::DeleteElement(__int64 id_base)
{
bool result=false;
OpenElement(id_base);
try
		{
		Element->Delete();
		Element->ApplyUpdates();
		IBTrUpdate->Commit();
        result=true;
        }
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}

return result;
}

//----------------------------------------------------------------------------


void __fastcall TDMXSetupObmen::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------


void __fastcall TDMXSetupObmen::BaseForObmenNewRecord(TDataSet *DataSet)
{
BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN->AsInt64=
							ElementIDBASE_OBMEN_XSETUP_OBMEN->AsInt64;
}
//---------------------------------------------------------------------------

void __fastcall TDMXSetupObmen::TypePriceForObmenNewRecord(TDataSet *DataSet)
{
TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN->AsInt64=
							ElementIDBASE_OBMEN_XSETUP_OBMEN->AsInt64;
}
//---------------------------------------------------------------------------
bool TDMXSetupObmen::AddBase(__int64 id_base, AnsiString name_base)
{
bool result=false;
try
	{
	BaseForObmen->Append();
	BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN->AsInt64=id_base;
	BaseForObmenNAME_SINFBASE_OBMEN->AsString=name_base;
	BaseForObmen->Post();
	result=true;
	}
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}

return result;
}
//--------------------------------------------------------------------------
bool TDMXSetupObmen::AddTypePrice(__int64 id_type_price, AnsiString name_type_price)
{
bool result=false;
try
	{
	TypePriceForObmen->Append();
	TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN->AsInt64=id_type_price;
	TypePriceForObmenNAME_TPRICE->AsString=name_type_price;
	TypePriceForObmen->Post();
	result=true;
	}
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}

return result;
}
//---------------------------------------------------------------------------
bool TDMXSetupObmen::DeleteBase(void)
{
bool result=false;
try
	{
	BaseForObmen->Delete();
	result=true;
	}
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}
return result;
}
//-------------------------------------------------------------------------
bool TDMXSetupObmen::DeleteTypePrice(void)
{
bool result=false;
try
	{
	TypePriceForObmen->Delete();
	}
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		TextError=exception.Message;
		}
return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMXSetupObmen::ElementNewRecord(TDataSet *DataSet)
{
TDMXTableIsm * DMXTableIsm=new TDMXTableIsm(Application);
DMXTableIsm->DM_Connection=DM_Connection;
DMXTableIsm->Init();

ElementIDTISM_XSETUP_OBMEN->AsInt64=DMXTableIsm->GetMaxID();
delete DMXTableIsm;
}
//---------------------------------------------------------------------------

