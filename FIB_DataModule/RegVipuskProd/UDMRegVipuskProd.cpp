//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMRegVipuskProd.h"

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
__fastcall TDMRegVipuskProd::TDMRegVipuskProd(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
bool TDMRegVipuskProd::Init(void)
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
void __fastcall TDMRegVipuskProd::DataModuleDestroy(TObject *Sender)
{
DvRegOst->Active=false;
}
//---------------------------------------------------------------------------
void TDMRegVipuskProd::AddRecordPrihod(void)
{
        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGVIPPROD_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGVIPPROD_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGVIPPROD_DV->AsInteger=0; //поступление


		if(IdFirm>0) DvRegOstIDFIRM_RGVIPPROD_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGVIPPROD_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGVIPPROD_DV->AsInt64=IdNom;

        DvRegOstSEB_RGVIPPROD_DV->AsFloat=SebProd;
        DvRegOstKOL_RGVIPPROD_DV->AsFloat=KolProd;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
void TDMRegVipuskProd::AddRecordRashod(void)
{

        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGVIPPROD_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGVIPPROD_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGVIPPROD_DV->AsInteger=1; //списание


		if(IdFirm>0) DvRegOstIDFIRM_RGVIPPROD_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKLAD_RGVIPPROD_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGVIPPROD_DV->AsInt64=IdNom;

        DvRegOstSEB_RGVIPPROD_DV->AsFloat=SebProd;
        DvRegOstKOL_RGVIPPROD_DV->AsFloat=KolProd;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
bool TDMRegVipuskProd::CancelDvReg(void)
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

