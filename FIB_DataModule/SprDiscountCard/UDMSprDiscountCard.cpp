//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprDiscountCard.h"
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

//extern String AddEAN13(String Cod);
//extern String DopStrL(String Str, String Symbol, int Len);
//---------------------------------------------------------------------------
__fastcall TDMSprDiscountCard::TDMSprDiscountCard(TComponent* Owner)
        : TDataModule(Owner)
{
elSave=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
}
//---------------------------------------------------------------------------
int TDMSprDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
bool TDMSprDiscountCard::Init(void)
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
Query->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}

//----------------------------------------------------------------------------
void __fastcall TDMSprDiscountCard::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMSprDiscountCard::OpenTable(__int64 id_klient)
{
IdKlient=id_klient;
Table->Active=false;
Table->ParamByName("PARAM_IDKLIENT")->AsInt64=id_klient;
Table->Active=true;


}
//---------------------------------------------------------------------------

int TDMSprDiscountCard::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

if (Res>0) elSave=true;
return Res;
}
//----------------------------------------------------------------------------

bool TDMSprDiscountCard::NewElement(__int64 id_klient)
{
bool result=false;
elSave=false;
IdKlient=id_klient;

int code=GetCodeCard();
if (code!=0)
	{
	Element->Open();
	Element->Append();

	ElementCODE_SDISCOUNT_CARD->AsInteger=code;
	//получим штрих код
	UnicodeString ShtrihCod=IntToStr(ElementCODE_SDISCOUNT_CARD->AsInteger);
	ShtrihCod=glDopStrL(ShtrihCod,"0",10);
	ShtrihCod="21"+ShtrihCod;
	ElementSHCODE_SDISCOUNT_CARD->AsString=glAddEAN13(ShtrihCod);
	result=true;
	}
else
	{
	result=false;
	TextError="Не удалось сформировать код элемента! \n Превышено максимальное значение кода!";

	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprDiscountCard::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_SDISCOUNT_CARD->AsString);

//проверить код на уникальность
if (CheckCode(id,ElementCODE_SDISCOUNT_CARD->AsInteger)==true)
	{
	result=false;
	TextError="Код дисконтной карты не уникальный!";
	return result;
	}

//проверить штрих код на уникальность
if (CheckBarCode(id,ElementSHCODE_SDISCOUNT_CARD->AsString)==true)
	{
	result=false;
	TextError="Штрих код дисконтной карты не уникальный!";
	return result;
	}

try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
        elSave=true;
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
		{
		IBTrUpdate->Rollback();
		TextError=exception.Message;
		result=false;
		}
return result;
}
//----------------------------------------------------------------------------

void TDMSprDiscountCard::DeleteElement(__int64 Id)
{
elSave=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
                TextError=exception.Message;
                }
        }
}
//----------------------------------------------------------------------------
void __fastcall TDMSprDiscountCard::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprDiscountCard::ElementNewRecord(TDataSet *DataSet)
{
ElementIDKLIENT_SDISCOUNT_CARD->AsString=IntToStr(IdKlient);
//ElementCODE_SDISCOUNT_CARD->AsInteger=ElementID_SDISCOUNT_CARD->AsInt64;


}
//---------------------------------------------------------------------------


__int64 TDMSprDiscountCard::PoiskPoCodu(AnsiString code)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SDISCOUNT_CARD from SDISCOUNT_CARD where CODE_SDISCOUNT_CARD=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsString=code;
Query->ExecQuery();
result=Query->FieldByName("ID_SDISCOUNT_CARD")->AsInt64;
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprDiscountCard::PoiskPoShCodu(AnsiString sh_code)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SDISCOUNT_CARD from SDISCOUNT_CARD where SHCODE_SDISCOUNT_CARD=:PARAM_SHCODE");
Query->ParamByName("PARAM_SHCODE")->AsString=sh_code;
Query->ExecQuery();
result=Query->FieldByName("ID_SDISCOUNT_CARD")->AsInt64;
return result;
}
//---------------------------------------------------------------------------
int TDMSprDiscountCard::GetCodeCard(void)
{
int result=0;
int max_code=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("SELECT GEN_ID(GEN_SDISCOUNT_CARD_CODE,1) FROM RDB$DATABASE");
Query->ExecQuery();
result=Query->FieldByName("GEN_ID")->AsInteger;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("SELECT VALUE_SETUP FROM SETUP WHERE ID_SETUP=203");
Query->ExecQuery();
max_code=Query->FieldByName("VALUE_SETUP")->AsInteger;
Query->Close();

if (max_code!=0)
	{
	if (result>max_code)
		{
        result=0;
		}
	}

return result;
}
//---------------------------------------------------------------------------

bool TDMSprDiscountCard::CheckBarCode(__int64 id_card, AnsiString sh)
{
//возвращает true если штрих код не уникальный
bool result=false;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SDISCOUNT_CARD");
Query->SQL->Add(" from SDISCOUNT_CARD");
Query->SQL->Add(" where SHCODE_SDISCOUNT_CARD=:PARAM_SHCODE");
Query->ParamByName("PARAM_SHCODE")->AsString=sh;
Query->ExecQuery();
		while(!Query->Eof)
			{
			if (id_card!=Query->FieldByName("ID_SDISCOUNT_CARD")->AsInt64)
				{
				result=true;
				}
			Query->Next();
			}
Query->Close();
return result;


}
//-----------------------------------------------------------------------------
bool TDMSprDiscountCard::CheckCode(__int64 id_card, int code)
{
//возвращает true если штрих код не уникальный
bool result=false;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SDISCOUNT_CARD");
Query->SQL->Add(" from SDISCOUNT_CARD");
Query->SQL->Add(" where CODE_SDISCOUNT_CARD=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsInteger=code;
Query->ExecQuery();
		while(!Query->Eof)
			{
			if (id_card!=Query->FieldByName("ID_SDISCOUNT_CARD")->AsInt64)
				{
				result=true;
				}
			Query->Next();
			}
Query->Close();
return result;

}
//---------------------------------------------------------------------------




