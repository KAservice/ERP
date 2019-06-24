//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMRegGoods.h"
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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMRegGoods::TDMRegGoods(TComponent* Owner)
        : TDataModule(Owner)
{
RPrice=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegGoods::DataModuleCreate(TObject *Sender)
{
//
SkladRozn=false;
NoOtrOstatok=false;
TableOst->Active=false;
}
//---------------------------------------------------------------------------
bool TDMRegGoods::Init(void)
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

DvRegOst->Database=DM_Connection->pFIBData;
RegOst->Database=DM_Connection->pFIBData;
DvNom->Database=DM_Connection->pFIBData;
Ostatok->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;
TableOst->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMRegGoods::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegGoods::DataModuleDestroy(TObject *Sender)
{
Ostatok->Active=false;
RegOst->Active=false;
DvRegOst->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
double TDMRegGoods::GetOstatok(__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
double result=0;
Ostatok->Active=false;
String TextZaprosa="";
TextZaprosa="select SUM(KOL_RGGOODS) AS KOLOST ";
TextZaprosa=TextZaprosa+"from RGGOODS ";
TextZaprosa=TextZaprosa+" where  ";

if (id_firm>0)
        {
		TextZaprosa=TextZaprosa+" IDFIRM_RGGOODS='"+IntToStr(id_firm)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" IDFIRM_RGGOODS IS NULL ";
		}

if (id_sklad>0)
        {
		TextZaprosa=TextZaprosa+" and IDSKLAD_RGGOODS='"+IntToStr(id_sklad)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" and IDSKLAD_RGGOODS IS NULL ";
        }

if (id_nom>0)
        {
		TextZaprosa=TextZaprosa+" and IDNOM_RGGOODS='"+IntToStr(id_nom)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" and IDNOM_RGGOODS IS NULL ";
        }

TextZaprosa=TextZaprosa+" group by IDNOM_RGGOODS ";


Ostatok->SelectSQL->Clear();
Ostatok->SelectSQL->Add(TextZaprosa);
Ostatok->Active=true;
result=OstatokKOLOST->AsFloat;
return result;

}
//---------------------------------------------------------------------------
void TDMRegGoods::GetOstatokPoPrice(__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
TableOst->Active=false;
String TextZaprosa="";
TextZaprosa="select SUM(KOL_RGGOODS) AS KOLOST , rggoods.rprice_rggoods ";
TextZaprosa=TextZaprosa+"from RGGOODS ";
TextZaprosa=TextZaprosa+" where  ";

if (id_firm>0)
        {
		TextZaprosa=TextZaprosa+" IDFIRM_RGGOODS='"+IntToStr(id_firm)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" IDFIRM_RGGOODS IS NULL ";
		}

if (id_sklad>0)
        {
		TextZaprosa=TextZaprosa+" and IDSKLAD_RGGOODS='"+IntToStr(id_sklad)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" and IDSKLAD_RGGOODS IS NULL ";
        }

if (id_nom>0)
        {
		TextZaprosa=TextZaprosa+" and IDNOM_RGGOODS='"+IntToStr(id_nom)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" and IDNOM_RGGOODS IS NULL ";
        }

TextZaprosa=TextZaprosa+" group by IDNOM_RGGOODS , rggoods.rprice_rggoods ";


TableOst->SelectSQL->Clear();
TableOst->SelectSQL->Add(TextZaprosa);
TableOst->Active=true;
}
//---------------------------------------------------------------------------
bool TDMRegGoods::AddRecordPrihod(void)
{
bool result=false;
NoOtrOstatok=false;

DvRegOst->Active=true;
DvRegOst->Append();
DvRegOstIDDOC_RGGOODS_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGGOODS_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGGOODS_DV->AsInt64=IdFirm;
if(IdSklad>0) DvRegOstIDSKLAD_RGGOODS_DV->AsInt64=IdSklad;
if (IdNom>0) DvRegOstIDNOM_RGGOODS_DV->AsInt64=IdNom;
DvRegOstRPRICE_RGGOODS_DV->AsFloat=RPrice;
DvRegOstTDV_RGGOODS_DV->AsInteger=0; //поступление
DvRegOstTYPE_RGGOODS_DV->AsInteger=Type;
DvRegOstKOL_RGGOODS_DV->AsFloat=Kol;
DvRegOstOPER_RGGOODS_DV->AsInteger=Operation;

DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegGoods::AddRecordRashod(void)
{
bool result=false;
if (SkladRozn) NoOtrOstatok=true;
DvRegOst->Active=true;
DvRegOst->Append();
DvRegOstIDDOC_RGGOODS_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGGOODS_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGGOODS_DV->AsInt64=IdFirm;
if(IdSklad>0) DvRegOstIDSKLAD_RGGOODS_DV->AsInt64=IdSklad;
if (IdNom>0) DvRegOstIDNOM_RGGOODS_DV->AsInt64=IdNom;
DvRegOstRPRICE_RGGOODS_DV->AsFloat=RPrice;
DvRegOstTDV_RGGOODS_DV->AsInteger=1; //списание
DvRegOstTYPE_RGGOODS_DV->AsInteger=Type;
DvRegOstKOL_RGGOODS_DV->AsFloat=Kol;
DvRegOstOPER_RGGOODS_DV->AsInteger=Operation;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegGoods::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
		Zapros=Zapros+" select * from RGGOODS where";
		if (DvRegOstIDFIRM_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" IDFIRM_RGGOODS IS NULL";
                }
		else
                {
				Zapros=Zapros+" IDFIRM_RGGOODS='"+DvRegOstIDFIRM_RGGOODS_DV->AsString+"'";
                }

		if (DvRegOstIDSKLAD_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" and IDSKLAD_RGGOODS IS NULL";
                }
        else
                {
				Zapros=Zapros+" and IDSKLAD_RGGOODS='"+DvRegOstIDSKLAD_RGGOODS_DV->AsString+"'";
                }

		if (DvRegOstIDNOM_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" and IDNOM_RGGOODS IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDNOM_RGGOODS='"+DvRegOstIDNOM_RGGOODS_DV->AsString+"'";
				}


		Zapros=Zapros+" and RPRICE_RGGOODS='"+DvRegOstRPRICE_RGGOODS_DV->AsString+"'";



        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

        if (RegOst->RecordCount>0)
                {
                RegOst->Edit();
				}
		else
				{
				if (NoOtrOstatok==true) throw Exception("Недостаточно товара на розничном складе с указанной ценой!",0);
				RegOst->Insert();
				if(DvRegOstIDFIRM_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGGOODS->AsInt64=DvRegOstIDFIRM_RGGOODS_DV->AsInt64;
                        }
				if(DvRegOstIDSKLAD_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDSKLAD_RGGOODS->AsInt64=DvRegOstIDSKLAD_RGGOODS_DV->AsInt64;
                        }
				if(DvRegOstIDNOM_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDNOM_RGGOODS->AsInt64=DvRegOstIDNOM_RGGOODS_DV->AsInt64;
						}
				RegOstRPRICE_RGGOODS->AsFloat=DvRegOstRPRICE_RGGOODS_DV->AsFloat;

                }

        if (DvRegOstTDV_RGGOODS_DV->AsInteger==0)
                {
				RegOstKOL_RGGOODS->AsFloat=RegOstKOL_RGGOODS->AsFloat+DvRegOstKOL_RGGOODS_DV->AsFloat;
				}
        else
				{
				if (NoOtrOstatok==true)
					{
					if(RegOstKOL_RGGOODS->AsFloat-DvRegOstKOL_RGGOODS_DV->AsFloat<0.00001)
						{
						throw Exception("Недостаточно товара на розничном складе с указанной ценой!",0);
						}
					}
				RegOstKOL_RGGOODS->AsFloat=RegOstKOL_RGGOODS->AsFloat-DvRegOstKOL_RGGOODS_DV->AsFloat;
				}

        RegOst->Post();

		if (RegOstKOL_RGGOODS->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegGoods::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        RegOst->Active=false;

        String Zapros="";
		Zapros=Zapros+" select * from RGGOODS where";
		if (DvRegOstIDFIRM_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" IDFIRM_RGGOODS IS NULL";
				}
        else
                {
				Zapros=Zapros+" IDFIRM_RGGOODS='"+DvRegOstIDFIRM_RGGOODS_DV->AsString+"'";
                }

		if (DvRegOstIDSKLAD_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" and IDSKLAD_RGGOODS IS NULL";
                }
        else
                {
				Zapros=Zapros+" and IDSKLAD_RGGOODS='"+DvRegOstIDSKLAD_RGGOODS_DV->AsString+"'";
                }

		if (DvRegOstIDNOM_RGGOODS_DV->AsInt64==0)
                {
				Zapros=Zapros+" and IDNOM_RGGOODS IS NULL";
                }
        else
                {
				Zapros=Zapros+" and IDNOM_RGGOODS='"+DvRegOstIDNOM_RGGOODS_DV->AsString+"'";
                }


		Zapros=Zapros+" and RPRICE_RGGOODS='"+DvRegOstRPRICE_RGGOODS_DV->AsString+"'";



        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

        if (RegOst->RecordCount>0)
                {
                RegOst->Edit();
                }
        else
                {

                RegOst->Insert();
				if(DvRegOstIDFIRM_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGGOODS->AsInt64=DvRegOstIDFIRM_RGGOODS_DV->AsInt64;
                        }
				if(DvRegOstIDSKLAD_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDSKLAD_RGGOODS->AsInt64=DvRegOstIDSKLAD_RGGOODS_DV->AsInt64;
                        }
				if(DvRegOstIDNOM_RGGOODS_DV->AsInt64!=0)
                        {
						RegOstIDNOM_RGGOODS->AsInt64=DvRegOstIDNOM_RGGOODS_DV->AsInt64;
                        }

				RegOstRPRICE_RGGOODS->AsFloat=DvRegOstRPRICE_RGGOODS_DV->AsFloat;

                }

		if (DvRegOstTDV_RGGOODS_DV->AsInteger==0)
                {
				RegOstKOL_RGGOODS->AsFloat=RegOstKOL_RGGOODS->AsFloat-DvRegOstKOL_RGGOODS_DV->AsFloat;
                }
        else
                {
				RegOstKOL_RGGOODS->AsFloat=RegOstKOL_RGGOODS->AsFloat+DvRegOstKOL_RGGOODS_DV->AsFloat;
                }
        RegOst->Post();

        if (RegOstKOL_RGGOODS->AsFloat==0)
                {
                RegOst->Delete();
                }


        DvRegOst->Delete();
        }
        
result=true;
return result;
}
//----------------------------------------------------------------------------------

double TDMRegGoods::GetOstatokNa(TDateTime pos,__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
double  result=0;
Ostatok->Active=false;
Ostatok->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Ostatok->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
Ostatok->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
Ostatok->Active=true;
result=OstatokKOLOST->AsFloat;
//получим приход
DvNom->Active=false;
DvNom->ParamByName("PARAM_POS")->AsDateTime=pos;
DvNom->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
DvNom->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
DvNom->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
DvNom->ParamByName("PARAM_TDV")->AsInteger=0;
DvNom->Active=true;
result=result-DvNomKOLDV->AsFloat;
//получим расход
DvNom->Active=false;
DvNom->ParamByName("PARAM_POS")->AsDateTime=pos;
DvNom->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
DvNom->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
DvNom->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
DvNom->ParamByName("PARAM_TDV")->AsInteger=1;
DvNom->Active=true;
result=result+DvNomKOLDV->AsFloat;

Ostatok->Active=false;
DvNom->Active=false;
return result;

}
//------------------------------------------------------------------------------
double TDMRegGoods::GetOstatokNaRoznSkladeNa(TDateTime pos,
										__int64 id_firm,
										__int64 id_sklad,
										__int64 id_nom,
										bool rozn_sklad,
										double rprice  )
{
double  result=0;

Query->Active=false;
Query->SelectSQL->Clear();
Query->SelectSQL->Add(" select  rggoods.idnom_rggoods, SUM(rggoods.kol_rggoods) AS KOLOST ");
Query->SelectSQL->Add(" from RGGOODS  ");
Query->SelectSQL->Add("  where ");
Query->SelectSQL->Add(" rggoods.idfirm_rggoods="+IntToStr(id_firm));
Query->SelectSQL->Add("  and rggoods.idsklad_rggoods="+IntToStr(id_sklad));
Query->SelectSQL->Add("  and rggoods.idnom_rggoods="+IntToStr(id_nom));
if (rozn_sklad==true)
	{
	Query->SelectSQL->Add("  and (rggoods.rprice_rggoods=:PARAM_RPRICE)");
	}
Query->SelectSQL->Add(" group by  rggoods.idnom_rggoods");

if (rozn_sklad==true)
	{
	Query->SelectSQL->Add(", rggoods.rprice_rggoods ");
	}

if (rozn_sklad==true)
	{
	Query->ParamByName("PARAM_RPRICE")->AsFloat=rprice;
	}
Query->Active=true;
result=Query->FieldByName("KOLOST")->AsFloat;


//получим приход
Query->Active=false;
Query->SelectSQL->Clear();
Query->SelectSQL->Add("select rggoods_dv.idnom_rggoods_dv, SUM(rggoods_dv.kol_rggoods_dv) AS KOLDV ");
Query->SelectSQL->Add("from RGGOODS_DV  ");
Query->SelectSQL->Add(" where   ");
Query->SelectSQL->Add(" rggoods_dv.posdoc_rggoods_dv > :PARAM_POS  ");
Query->SelectSQL->Add(" and rggoods_dv.idfirm_rggoods_dv="+IntToStr(id_firm));
Query->SelectSQL->Add(" and rggoods_dv.idsklad_rggoods_dv="+IntToStr(id_sklad));
Query->SelectSQL->Add(" and rggoods_dv.idnom_rggoods_dv="+IntToStr(id_nom));
Query->SelectSQL->Add(" and rggoods_dv.tdv_rggoods_dv = :PARAM_TDV  ");
if (rozn_sklad==true)
	{
	Query->SelectSQL->Add(" and (rggoods_dv.rprice_rggoods_dv=:PARAM_RPRICE) ");
	}

Query->SelectSQL->Add(" group by rggoods_dv.idnom_rggoods_dv ");

if (rozn_sklad==true)
	{
	Query->ParamByName("PARAM_RPRICE")->AsInteger=rprice;
	}

Query->ParamByName("PARAM_TDV")->AsInteger=0;
Query->ParamByName("PARAM_POS")->AsDateTime=pos;
Query->Active=true;
result=result-Query->FieldByName("KOLDV")->AsFloat;

Query->Active=false;

//получим расход
if (rozn_sklad==true)
	{
	Query->ParamByName("PARAM_RPRICE")->AsInteger=rprice;
	}

Query->ParamByName("PARAM_TDV")->AsInteger=1;
Query->ParamByName("PARAM_POS")->AsDateTime=pos;
Query->Active=true;

result=result+Query->FieldByName("KOLDV")->AsFloat;
Query->Active=false;

return result;
}
//-----------------------------------------------------------------------------
