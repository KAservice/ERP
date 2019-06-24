//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop
//#include <vcl.h>
//#include <DB.hpp>
//#include <IBDatabase.hpp>
//#include <IBCustomDataSet.hpp>
//#include <IBQuery.hpp>
//#include <pFIBDatabase.hpp>
//#include <pFIBDataSet.hpp>
//#include <Dbctrls.hpp>
//---------------------------------------------------------------------------

#include "UHOT_DMRegSostNF.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_DMRegSostNF::THOT_DMRegSostNF(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMRegSostNF::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool THOT_DMRegSostNF::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;


DvRegOst->Database=DM_Connection->pFIBData;
RegOst->Database=DM_Connection->pFIBData;
Dv->Database=DM_Connection->pFIBData;
Ostatok->Database=DM_Connection->pFIBData;



DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMRegSostNF::DataModuleDestroy(TObject *Sender)
{
Ostatok->Active=false;
Dv->Active=false;
DvRegOst->Active=false;
RegOst->Active=false;

}
//---------------------------------------------------------------------------
int THOT_DMRegSostNF::GetOstatok(void)
{

//int result=0;
//Ostatok->Active=false;
//String TextZaprosa="";
//TextZaprosa="select  SUM(SUM_RGKASSA)  AS SUMOST ";
//TextZaprosa=TextZaprosa+"from RGKASSA ";
//TextZaprosa=TextZaprosa+" where  ";
//
//if (IdKKM>0)
//        {
//        TextZaprosa=TextZaprosa+" IDKKM_RGKASSA=='"+IntToStr(IdKKM)+"' ";
//        }
//else
//        {
//        TextZaprosa=TextZaprosa+" IDKKM_RGKASSA= IS NULL ";
//        }
//
//TextZaprosa=TextZaprosa+" group by IDKKM_RGKASSA ";
//
//
//Ostatok->SelectSQL->Clear();
//Ostatok->SelectSQL->Add(TextZaprosa);
//Ostatok->Active=true;
//result=Ostatok->RecordCount;
//
//return result;

}
//---------------------------------------------------------------------------
bool THOT_DMRegSostNF::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOCH_HOT_RGSOSTNF_DV->AsInt64=IdDocH;
DvRegOstPOS_HOT_RGSOSTNF_DV->AsDateTime=PosDoc;
DvRegOstIDSOST_HOT_RGSOSTNF_DV->AsInt64=IdSost;
DvRegOstTDV_HOT_RGSOSTNF_DV->AsInteger=0; //поступление
DvRegOstOPER_HOT_RGSOSTNF_DV->AsInteger=Operation;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool THOT_DMRegSostNF::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOCH_HOT_RGSOSTNF_DV->AsInt64=IdDocH;
DvRegOstPOS_HOT_RGSOSTNF_DV->AsDateTime=PosDoc;
DvRegOstIDSOST_HOT_RGSOSTNF_DV->AsInt64=IdSost;
DvRegOstTDV_HOT_RGSOSTNF_DV->AsInteger=1; //списание
DvRegOstOPER_HOT_RGSOSTNF_DV->AsInteger=Operation;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool THOT_DMRegSostNF::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
		Zapros=Zapros+" select * from HOT_RGSOSTNF where";
		Zapros=Zapros+" IDSOST_HOT_RGSOSTNF='"+DvRegOstIDSOST_HOT_RGSOSTNF_DV->AsString+"'";


        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

        if (RegOst->RecordCount>0)
				{
				//Исключение
                }
        else
                {
                RegOst->Insert();
				RegOstIDSOST_HOT_RGSOSTNF->AsInt64=DvRegOstIDSOST_HOT_RGSOSTNF_DV->AsInt64;

				}
				
        RegOst->Post();

result=true;
return result;

}
//----------------------------------------------------------------------------
bool THOT_DMRegSostNF::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("PARAM_IDDOCH")->AsInt64=IdDocH;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        RegOst->Active=false;

        String Zapros="";
		Zapros=Zapros+" select * from HOT_RGSOSTNF where";

		Zapros=Zapros+" IDSOST_HOT_RGSOSTNF='"+DvRegOstIDSOST_HOT_RGSOSTNF_DV->AsString+"'";

        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

		if (RegOst->RecordCount>0)
                {
				RegOst->Delete();
                }
        else
                {
				 //Exeption

                }

        DvRegOst->Delete();
        }
        
result=true;
return result;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

bool THOT_DMRegSostNF::GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa)
{
//bool  result=false;
//SumOstNa=0;
//Ostatok->Active=false;
//Ostatok->ParamByName("PARAM_IDFIRM")->AsInteger=id_firm;
//Ostatok->ParamByName("PARAM_IDKASSA")->AsInteger=id_kassa;
//Ostatok->Active=true;
//SumOstNa=OstatokSUMOST->AsFloat;
////получим приход
//Dv->Active=false;
//Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
//Dv->ParamByName("PARAM_IDFIRM")->AsInteger=id_firm;
//Dv->ParamByName("PARAM_IDKASSA")->AsInteger=id_kassa;
//Dv->ParamByName("PARAM_TDV")->AsInteger=0;
//Dv->Active=true;
//SumOstNa=SumOstNa-DvSUMDV->AsFloat;
////получим расход
//Dv->Active=false;
//Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
//Dv->ParamByName("PARAM_IDFIRM")->AsInteger=id_firm;
//Dv->ParamByName("PARAM_IDKASSA")->AsInteger=id_kassa;
//Dv->ParamByName("PARAM_TDV")->AsInteger=1;
//Dv->Active=true;
//SumOstNa=SumOstNa+DvSUMDV->AsFloat;
//
//
//result=true;
//
//return result;

}
//------------------------------------------------------------------------------
