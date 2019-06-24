//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprPrice.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern bool gl_add_table_ism;
//---------------------------------------------------------------------------
__fastcall TDMSprPrice::TDMSprPrice(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
IdBasEd=0;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprPrice::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
SpisokEd->Close();
Element->Close();
TPrice->Close();
}
//---------------------------------------------------------------------------
void TDMSprPrice::OpenTable(__int64 Nom)
{
IdNom=Nom;
UpdateSpisokEd(Nom);

Table->Active=false;
Table->ParamByName("IDNOM")->AsInt64=IdNom;
Table->Active=true;


}
//----------------------------------------------------------------------------
bool TDMSprPrice::SaveIsmen(void)
{
bool result=false;
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdNom);
		result=true;
        }
	catch(Exception &exception)
		{
		result=false;
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
		}
	}
return result;
}
//----------------------------------------------------------------------------

void  TDMSprPrice::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();
}
//---------------------------------------------------------------------------

int TDMSprPrice::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool TDMSprPrice::SaveElement()
{
bool result=false;

__int64 Id=ElementID_PRICE->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
		result=true;
        }
catch(Exception &exception)
		{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
		
return result;
}
//----------------------------------------------------------------------------
void TDMSprPrice::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------
void TDMSprPrice::DeleteElement(__int64 Id)
{
OpenElement(Id);
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
                IBTrUpdate->Commit();
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------
__int64 TDMSprPrice::FindElement(__int64 idTypePrice, __int64 idNom)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select ID_PRICE from SPRICE ");
		pFIBQ->SQL->Add(" where IDNOM_PRICE=:PARAM_IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE ");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=idNom;
		pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=idTypePrice;
		pFIBQ->ExecQuery();
		result=pFIBQ->RecordCount;
		OpenElement(pFIBQ->FieldByName("ID_PRICE")->AsInt64);
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprPrice::FindElementPoEd(__int64 idTypePrice, __int64 idNom, __int64 id_ed)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_PRICE from SPRICE ");
pFIBQ->SQL->Add(" where IDNOM_PRICE=:PARAM_IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE and IDED_SPRICE=:PARAM_IDED");
pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=idNom;
pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=idTypePrice;
pFIBQ->ParamByName("PARAM_IDED")->AsInt64=id_ed;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_PRICE")->AsInt64;
pFIBQ->Close();
return result;

}
//---------------------------------------------------------------------------
double TDMSprPrice::GetValuePrice(__int64 id_type_price,
							__int64 id_nom,
							__int64 id_ed,
							double kf_ed,
							__int64 id_bas_ed)
{
double result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ZNACH_PRICE from SPRICE ");
pFIBQ->SQL->Add(" where IDNOM_PRICE=:PARAM_IDNOM ");
pFIBQ->SQL->Add("     and IDTYPE_PRICE=:PARAM_IDTYPE ");
pFIBQ->SQL->Add("     and IDED_SPRICE=:PARAM_IDED ");
pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=id_type_price;
pFIBQ->ParamByName("PARAM_IDED")->AsInt64=id_ed;
pFIBQ->ExecQuery();

if (pFIBQ->RecordCount>0)
	{
	result=pFIBQ->FieldByName("ZNACH_PRICE")->AsFloat;
	}
else
	{ //не найдена цена для указанной единицы измерения
	// ищем цену за базовую единицу измерения
	if (id_bas_ed==0)
		{//не задана базовая единица измерения, ищем базовую единицу
		pFIBQ->Close();
		pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDBASEDNOM from SNOM ");
		pFIBQ->SQL->Add(" where IDNOM=:PARAM_IDNOM");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
		pFIBQ->ExecQuery();
		id_bas_ed=pFIBQ->FieldByName("IDBASEDNOM")->AsInt64;
		}

	pFIBQ->Close();
	pFIBQ->SQL->Clear();
	pFIBQ->SQL->Add("select ZNACH_PRICE from SPRICE ");
	pFIBQ->SQL->Add(" where IDNOM_PRICE=:PARAM_IDNOM ");
	pFIBQ->SQL->Add("     and IDTYPE_PRICE=:PARAM_IDTYPE ");
	pFIBQ->SQL->Add("     and IDED_SPRICE=:PARAM_IDED ");
	pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
	pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=id_type_price;
	pFIBQ->ParamByName("PARAM_IDED")->AsInt64=id_bas_ed;
	pFIBQ->ExecQuery();
	
	if (pFIBQ->RecordCount>0)
		{
		result=pFIBQ->FieldByName("ZNACH_PRICE")->AsFloat*kf_ed;
		}
	else //не нашли цену за базовую единицу
		{//ищем цену за единицу is null
		pFIBQ->Close();
		pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select ZNACH_PRICE from SPRICE ");
		pFIBQ->SQL->Add(" where IDNOM_PRICE=:PARAM_IDNOM ");
		pFIBQ->SQL->Add("     and IDTYPE_PRICE=:PARAM_IDTYPE ");
		pFIBQ->SQL->Add("     and IDED_SPRICE is null ");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
		pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=id_type_price;
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("ZNACH_PRICE")->AsFloat*kf_ed;
		}
	}
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprPrice::TableAfterInsert(TDataSet *DataSet)
{
TableIDNOM_PRICE->AsString=IdNom;
UpdateSpisokEd(IdNom);
}
//---------------------------------------------------------------------------
void __fastcall TDMSprPrice::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_PRICE->AsString=IdNom;
if (IdBasEd>0)
	{
	TableIDED_SPRICE->AsString=IdBasEd;
	}
else
	{//получим базовую единицу
		pFIBQ->Close();
		pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDBASEDNOM from SNOM ");
		pFIBQ->SQL->Add(" where IDNOM=:PARAM_IDNOM ");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsString=TableIDNOM_PRICE->AsString;
		pFIBQ->ExecQuery();
		IdBasEd=glStrToInt64(pFIBQ->FieldByName("IDBASEDNOM")->AsString);
        pFIBQ->Close();
	if (IdBasEd>0)
		{
		TableIDED_SPRICE->AsString=IdBasEd;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprPrice::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNOM_PRICE->AsInt64=IdNom;
ElementIDTYPE_PRICE->AsInt64=IdTypePrice;

if (IdBasEd>0)
	{
	ElementIDED_SPRICE->AsString=IdBasEd;
	}
else
	{//получим базовую единицу
		pFIBQ->Close();
		pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDBASEDNOM from SNOM ");
		pFIBQ->SQL->Add(" where IDNOM=:PARAM_IDNOM ");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=ElementIDNOM_PRICE->AsInt64;
		pFIBQ->ExecQuery();
		IdBasEd=glStrToInt64(pFIBQ->FieldByName("IDBASEDNOM")->AsString);
        pFIBQ->Close();
	if (IdBasEd>0)
		{
		ElementIDED_SPRICE->AsString=IdBasEd;
		}
	}

}
//---------------------------------------------------------------------------
void TDMSprPrice::UpdateSpisokEd(__int64 id_nom)
{
SpisokEd->Active=false;
SpisokEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
SpisokEd->Active=true;
}
//----------------------------------------------------------------------------






