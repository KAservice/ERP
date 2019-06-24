//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprEd.h"
#include "UDM.h"
#include "UObjectBarCode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

extern String DopStrL(String Str, String Symbol, int Len);
extern String AddEAN13(String Cod);
extern String gl_prefiks_ib;
extern bool gl_add_table_ism;
extern AnsiString glPrefiksKolShtrihCoda;
extern AnsiString glPrefiksLokShtrihCoda;
//---------------------------------------------------------------------------
__fastcall TDMSprEd::TDMSprEd(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprEd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
OKEI->Active=false;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TDMSprEd::OpenTable(__int64 IdNom)
{

Table->Active=false;
Table->ParamByName("IDNOM")->AsInt64=IdNom;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprEd::OpenElement(__int64 Id)  //���������� ���������� ���������
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

OKEI->Active=false;
OKEI->ParamByName("ID")->AsInt64=ElementIDOKEIED->AsInt64;
OKEI->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TDMSprEd::NewElement(__int64 IdNom)
{
bool result=false;
Element->Active=false;


int code=GetCodeEd();
if (code!=0)
	{
	Element->Open();
	Element->Insert();
	ElementIDNOMED->AsInt64=IdNom;
	ElementKFED->AsFloat=1;
	ElementTSHED->AsInteger=0;
	ElementCODE_SED->AsInteger=code;
	result=true;

	//������� ����� ���
	TObjectBarCode * ob_bar=new TObjectBarCode();
	ob_bar->GetValuePrefiksBarCode();
	ElementSHED->AsString=ob_bar->GetNewBarCode(IntToStr(ElementCODE_SED->AsInteger),
													ElementTSHED->AsInteger);
	delete ob_bar;
	}
else
	{
	Error=true;
	result=false;
	TextError="�� ������� ������������ ��� ��������! \n ��������� ������������ �������� ����!";

	}


return result;

}
//-----------------------------------------------------------------------------
void TDMSprEd::NewShtrihCod(void)
{
Element->Edit();
	//������� ����� ���
	TObjectBarCode * ob_bar=new TObjectBarCode();
	ob_bar->GetValuePrefiksBarCode();
	ElementSHED->AsString=ob_bar->GetNewBarCode(IntToStr(ElementCODE_SED->AsInteger),
													ElementTSHED->AsInteger);
	delete ob_bar;
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMSprEd::SaveElement(void)
{
bool result=false;
__int64 Id=ElementIDED->AsInt64;

//��������� ��� �� ������������
if (CheckCode(Id, ElementCODE_SED->AsInteger)==true)
	{
	result=false;
	TextError="��� ������� ��������� �� ����������!";
	return result;
	}

//��������� ����� ��� �� ������������
if (CheckBarCode(Id, ElementSHED->AsString)==true)
	{
	result=false;
	TextError="����� ��� ������� ��������� �� ����������!";
	return result;
	}

try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(Id);
        result=true;
        }
catch(Exception &exception)
        {
		TextError=exception.Message;
        result=false;
        }

return result;
}
//----------------------------------------------------------------------------

bool TDMSprEd::DeleteElement(__int64 Id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
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
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------
__int64 TDMSprEd::FindEdPoSh(String ShtrihCod)
{
__int64 res;
res=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDED");
		pFIBQ->SQL->Add(" from SED");
		pFIBQ->SQL->Add(" where SHED=:PARAM_SHED");
		pFIBQ->ParamByName("PARAM_SHED")->AsString=ShtrihCod;
		pFIBQ->ExecQuery();
		res=OpenElement(pFIBQ->FieldByName("IDED")->AsInt64);
pFIBQ->Close();
return res;
}

//----------------------------------------------------------------------------
__int64 TDMSprEd::FindEdPoCodu(int code)
{
__int64 result;
result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDED");
		pFIBQ->SQL->Add(" from SED");
		pFIBQ->SQL->Add(" where CODE_SED=:PARAM_CODE");
		pFIBQ->ParamByName("PARAM_CODE")->AsInteger=code;
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("IDED")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------

__int64 TDMSprEd::GetIDElement(String gid)
{
__int64 res=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDED from SED where GID_SED=:PARAM_GID");
		pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=pFIBQ->FieldByName("IDED")->AsInt64;
			}
		else res=0;

pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprEd::GetGIDElement(__int64 id)
{
AnsiString res=0;

if (id==0) return res;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select GID_SED from SED where IDED=:PARAM_ID");
		pFIBQ->ParamByName("PARAM_ID")->AsInt64=id;
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=Trim(pFIBQ->FieldByName("GID_SED")->AsString);
			}
		else res="";
pFIBQ->Close();

return res;
}
//---------------------------------------------------------------------------
__int64 TDMSprEd::GetIdNomPoShtrihCodu(AnsiString shtrih_cod)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDNOMED");
		pFIBQ->SQL->Add(" from SED");
		pFIBQ->SQL->Add(" where SHED=:PARAM_SHED");
		pFIBQ->ParamByName("PARAM_SHED")->AsString=shtrih_cod;
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("IDNOMED")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMSprEd::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

bool TDMSprEd::CheckBarCode(__int64 id_ed, AnsiString sh)
{
//���������� true ���� ����� ��� �� ����������
bool result=false;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDED");
		pFIBQ->SQL->Add(" from SED");
		pFIBQ->SQL->Add(" where SHED=:PARAM_SHED");
		pFIBQ->ParamByName("PARAM_SHED")->AsString=sh;
		pFIBQ->ExecQuery();
		while(!pFIBQ->Eof)
			{
			if (id_ed!=pFIBQ->FieldByName("IDED")->AsInt64)
				{
				result=true;
				}
			pFIBQ->Next();
			}
pFIBQ->Close();
return result;


}
//-----------------------------------------------------------------------------
bool TDMSprEd::CheckCode(__int64 id_ed, int code)
{
//���������� true ���� ����� ��� �� ����������
bool result=false;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDED");
		pFIBQ->SQL->Add(" from SED");
		pFIBQ->SQL->Add(" where CODE_SED=:PARAM_CODE");
		pFIBQ->ParamByName("PARAM_CODE")->AsInteger=code;
		pFIBQ->ExecQuery();
		while(!pFIBQ->Eof)
			{
			if (id_ed!=pFIBQ->FieldByName("IDED")->AsInt64)
				{
				result=true;
				}
			pFIBQ->Next();
			}
pFIBQ->Close();
return result;

}
//---------------------------------------------------------------------------
int TDMSprEd::GetCodeEd(void)
{
int result=0;
int max_code_ed=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("SELECT GEN_ID(GEN_SED_CODE,1) FROM RDB$DATABASE");
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("GEN_ID")->AsInteger;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("SELECT VALUE_SETUP FROM SETUP WHERE ID_SETUP=202");
pFIBQ->ExecQuery();
max_code_ed=pFIBQ->FieldByName("VALUE_SETUP")->AsInteger;
pFIBQ->Close();

if (max_code_ed!=0)
	{
	if (result>max_code_ed)
		{
        result=0;
		}
	}

return result;
}
//---------------------------------------------------------------------------

