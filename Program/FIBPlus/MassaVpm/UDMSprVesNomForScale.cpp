//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprVesNomForScale.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprVesNomForScale::TDMSprVesNomForScale(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprVesNomForScale::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TDMSprVesNomForScale::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------
void  TDMSprVesNomForScale::OpenTable(__int64 id_scale)
{
IdScale=id_scale;
Table->Active=false;
Table->ParamByName("PARAM_IDSCALE")->AsInt64=id_scale;
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=IdTypePrice;
Table->Open();

}
//----------------------------------------------------------------------------