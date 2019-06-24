//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMGurDocRecKDR.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMGurDocRecKDR::TDMGurDocRecKDR(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMGurDocRecKDR::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
}
//---------------------------------------------------------------------------
void TDMGurDocRecKDR::OpenTable()
{
Table->Active=false;
//ShowMessage(DateTimeToStr(PosNach)+"   "+DateTimeToStr(PosCon+1));
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurDocRecKDR::UpdateTable(void)
{
IdDoc=TableIDDOC->AsInteger;
DataSourceTable->Enabled=false;

Table->Active=false;
//ShowMessage(DateTimeToStr(PosNach)+"   "+DateTimeToStr(PosCon));
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("IDDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

