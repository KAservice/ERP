//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprNomVZip.h"
#include "IDMQueryUpdate.h"
#include "IDMSprEd.h"
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

__fastcall TDMSprNomVZip::TDMSprNomVZip(TComponent* Owner)
        : TDataModule(Owner)
{
CheckOst=false;
OnlyChange=false;
IdFirm=0;
IdSklad=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprNomVZip::Init(void)
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

Table->Database=DM_Connection->pFIBData;


pFIBQuery->Database=DM_Connection->pFIBData;
SpTPrice->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNomVZip::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomVZip::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
pFIBQuery->Close();
SpTPrice->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void  TDMSprNomVZip::OpenTable(__int64 Grp,bool All)
{
IdGrp=Grp;
AllElement=All;
Table->Active=false;
Table->ParamByName("PARAM_IDGRP")->AsString=Grp;
if (All==true)
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=0;
	}
Table->ParamByName("PARAM_IDFIRM")->AsString=IdFirm;
Table->ParamByName("PARAM_IDSKLAD")->AsString=IdSklad;
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsString=IdTypePrice;


if (CheckOst==true)
	{
	Table->ParamByName("PARAM_FL_OST")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_OST")->AsInteger=0;
	}



//Table->SelectSQL->Clear();
//Table->SelectSQL->Add(GetTextQuery(Grp,All,CheckOst,IdFirm,IdSklad,IdTypePrice,OnlyOstatok,PriceSklad,OnlyChange,IdInetCatalog));
Table->Open();
}

//---------------------------------------------------------------------------
__int64 TDMSprNomVZip::FindPoCodu(int Code)
{

__int64 Res=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
		pFIBQuery->SQL->Add("select IDNOM from SNOM where CODENOM=:CODE");
		pFIBQuery->ParamByName("CODE")->AsInteger=Code;
		pFIBQuery->ExecQuery();
		//Res=OpenElement(pFIBQuery->FieldByName("IDNOM")->AsInt64);
pFIBQuery->Close();
return Res;


}
//----------------------------------------------------------------------------
__int64 TDMSprNomVZip::GetIdBasEd(__int64 id_nom)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDBASEDNOM from SNOM where IDNOM=:PARAM_ID");
pFIBQuery->ParamByName("PARAM_ID")->AsString=IntToStr(id_nom);
pFIBQuery->ExecQuery();
result=glStrToInt64(pFIBQuery->FieldByName("IDBASEDNOM")->AsInt64);
pFIBQuery->Close();
return result;

}
//----------------------------------------------------------------------------
__int64 TDMSprNomVZip::FindPoName(AnsiString name)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOM from SNOM where NAMENOM=:PARAM_NAME");
pFIBQuery->ParamByName("PARAM_NAME")->AsString=name;
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
pFIBQuery->Close();
return result;


}
//---------------------------------------------------------------------------
__int64 TDMSprNomVZip::FindPoArtikulu(UnicodeString artikul)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOM from SNOM where ARTNOM=:PARAM_ART");
pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
pFIBQuery->Close();
return result;

}
//---------------------------------------------------------------------------

int TDMSprNomVZip::GetIndexTypePrice(void)
{
int res=1;
SpTPrice->First();
while (!SpTPrice->Eof)
        {
		if (IdTypePrice==SpTPriceID_TPRICE->AsInt64)
                {
                return res;
                }
                res=res+1;
        SpTPrice->Next();
        }
return 0;
}
//---------------------------------------------------------------------------


__int64 TDMSprNomVZip::GetIDElement(String gid)
{
__int64 res=0;
pFIBQuery->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select IDNOM from SNOM where GID_SNOM=:PARAM_GID");
				pFIBQuery->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQuery->ExecQuery();

				res=pFIBQuery->FieldByName("IDNOM")->AsInt64;

                }
pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprNomVZip::GetGIDElement(__int64 id)
{
AnsiString res="";
pFIBQuery->Close();
        if (id!=0 )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select GID_SNOM from SNOM where IDNOM=:PARAM_ID");
				pFIBQuery->ParamByName("PARAM_ID")->AsInt64=id;
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=Trim(pFIBQuery->FieldByName("GID_SNOM")->AsString);
                        }
				else res="";
                }
 pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------

__int64 TDMSprNomVZip::FindPoShtrihCodu(AnsiString shtrih_cod)
{
__int64 result=0;

pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOMED from SED where SHED='"+shtrih_cod+"'");
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("IDNOMED")->AsInt64;
pFIBQuery->Close();
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNomVZip::TableAfterScroll(TDataSet *DataSet)
{
PorNumberString=Table->RecNo;
}
//---------------------------------------------------------------------------

__int64 TDMSprNomVZip::GetIdGrpNom(__int64 id_nom)
{
__int64 res;
res=0;
 pFIBQuery->Close();
 pFIBQuery->SQL->Clear();
		pFIBQuery->SQL->Add("select IDGRPNOM from SNOM where IDNOM='"+IntToStr(id_nom)+"'");
		pFIBQuery->ExecQuery();
		res=pFIBQuery->FieldByName("IDGRPNOM")->AsInt64;
 pFIBQuery->Close();
return res;

}
//-----------------------------------------------------------------------------




