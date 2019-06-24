//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMRegSebProd.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMRegSebProd::TDMRegSebProd(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
bool TDMRegSebProd::Init(void)
{
bool result=false;


IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

DvRegOst->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegSebProd::DataModuleDestroy(TObject *Sender)
{
DvRegOst->Active=false;
}
//---------------------------------------------------------------------------
void TDMRegSebProd::AddRecordPrihod(void)
{
        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGSEBPROD_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGSEBPROD_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGSEBPROD_DV->AsInteger=0; //поступление

		if(IdVipuskProd>0) DvRegOstIDVIPPROD_RGSEBPROD_DV->AsInt64=IdVipuskProd;
		if(IdFirm>0) DvRegOstIDFIRM_RGSEBPROD_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGSEBPROD_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGSEBPROD_DV->AsInt64=IdNom;

        DvRegOstSUM_RGSEBPROD_DV->AsFloat=SumSeb;
        DvRegOstKOL_RGSEBPROD_DV->AsFloat=Kol;
        DvRegOstKOLOTR_RGSEBPROD_DV->AsFloat=KolOtr;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
void TDMRegSebProd::AddRecordRashod(void)
{

        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGSEBPROD_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGSEBPROD_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGSEBPROD_DV->AsInteger=1; //списание

		if(IdVipuskProd>0) DvRegOstIDVIPPROD_RGSEBPROD_DV->AsInt64=IdVipuskProd;
		if(IdFirm>0) DvRegOstIDFIRM_RGSEBPROD_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGSEBPROD_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGSEBPROD_DV->AsInt64=IdNom;

        DvRegOstSUM_RGSEBPROD_DV->AsFloat=SumSeb;
        DvRegOstKOL_RGSEBPROD_DV->AsFloat=Kol;
        DvRegOstKOLOTR_RGSEBPROD_DV->AsFloat=KolOtr;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
bool TDMRegSebProd::CancelDvReg(void)
{
bool result=false;

try
        {
        DvRegOst->Active=false;
        DvRegOst->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;

        DvRegOst->First();

        while (!DvRegOst->Eof)
                {
                DvRegOst->Delete();
                }

        result=true;
        }
catch(...)
        {
         result=false;
        }

return result;
}
//---------------------------------------------------------------------------

