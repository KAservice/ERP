//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMRegReal.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMRegReal::TDMRegReal(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
bool TDMRegReal::Init(void)
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
void __fastcall TDMRegReal::DataModuleDestroy(TObject *Sender)
{
DvRegOst->Active=false;
}
//---------------------------------------------------------------------------
void TDMRegReal::AddReal(void)
{
        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGREAL_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGREAL_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGREAL_DV->AsInteger=0; //поступление


		if(IdFirm>0) DvRegOstIDFIRM_RGREAL_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGREAL_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGREAL_DV->AsInt64=IdNom;
        
        DvRegOstOPER_RGREAL_DV->AsInteger=Operation;

        DvRegOstSUMREAL_RGREAL_DV->AsFloat=SumReal;
        DvRegOstSEBREAL_RGREAL_DV->AsFloat=SebReal;
        DvRegOstRESREAL_RGREAL_DV->AsFloat=ResReal;
        DvRegOstKOL_RGREAL_DV->AsFloat=KolReal;
        DvRegOstKOLOTR_RGREAL_DV->AsFloat=KolOtrReal;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
void TDMRegReal::SpisatReal(void)
{

        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGREAL_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGREAL_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGREAL_DV->AsInteger=1; //списание


		if(IdFirm>0) DvRegOstIDFIRM_RGREAL_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGREAL_DV->AsInt64=IdSklad;
        if(IdNom>0) DvRegOstIDNOM_RGREAL_DV->AsInt64=IdNom;

        DvRegOstOPER_RGREAL_DV->AsInteger=Operation;

        DvRegOstSUMREAL_RGREAL_DV->AsFloat=SumReal;
        DvRegOstSEBREAL_RGREAL_DV->AsFloat=SebReal;
        DvRegOstRESREAL_RGREAL_DV->AsFloat=ResReal;
        DvRegOstKOL_RGREAL_DV->AsFloat=KolReal;
        DvRegOstKOLOTR_RGREAL_DV->AsFloat=KolOtrReal;
        DvRegOst->Post();


}
//---------------------------------------------------------------------------
bool TDMRegReal::CancelDvReg(void)
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

