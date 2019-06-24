//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMRegOtrSpisNom.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMRegOtrSpisNom::TDMRegOtrSpisNom(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMRegOtrSpisNom::DataModuleDestroy(TObject *Sender)
{
DvRegOst->Active=false;
}
//---------------------------------------------------------------------------
void TDMRegOtrSpisNom::AddNom(void)
{
        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGOTRSPIS_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGOTRSPIS_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGOTRSPIS_DV->AsInteger=0; //поступление


		if(IdFirm>0) DvRegOstIDFIRM_RGOTRSPIS_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKL_RGOTRSPIS_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGOTRSPIS_DV->AsInt64=IdNom;
		if(IdStrDoc>0) DvRegOstIDSTRDOC_RGOTRSPIS_DV->AsInt64=IdStrDoc;

        DvRegOstKOL_RGOTRSPIS_DV->AsFloat=Kol;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
void TDMRegOtrSpisNom::SpisatNom(void)
{

        DvRegOst->Active=true;
        DvRegOst->Insert();

		DvRegOstIDDOC_RGOTRSPIS_DV->AsInt64=IdDoc;
        DvRegOstPOSDOC_RGOTRSPIS_DV->AsDateTime=PosDoc;
        DvRegOstTDV_RGOTRSPIS_DV->AsInteger=1; //списание


		if(IdFirm>0) DvRegOstIDFIRM_RGOTRSPIS_DV->AsInt64=IdFirm;
		if(IdSklad>0) DvRegOstIDSKL_RGOTRSPIS_DV->AsInt64=IdSklad;
		if(IdNom>0) DvRegOstIDNOM_RGOTRSPIS_DV->AsInt64=IdNom;

        DvRegOstKOL_RGOTRSPIS_DV->AsFloat=Kol;

        DvRegOst->Post();


}
//---------------------------------------------------------------------------
bool TDMRegOtrSpisNom::CancelDvReg(void)
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

