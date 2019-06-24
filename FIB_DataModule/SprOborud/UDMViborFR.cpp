//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMViborFR.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMViborFR::TDMViborFR(TComponent* Owner)
        : TDataModule(Owner)
{
//Error=false;
//TextError="Ошибок нет!";
}
//---------------------------------------------------------------------------
bool TDMViborFR::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;


Table->Database=DM_Connection->pFIBData;


	DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
	ExecPriv=DM_Connection->ExecPriv;
	InsertPriv=DM_Connection->InsertPriv;
	EditPriv=DM_Connection->EditPriv;
	DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMViborFR::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}
//---------------------------------------------------------------------------
 void  TDMViborFR::OpenTable(__int64 id_arm)
{
IdArm=id_arm;
Table->Active=false;
Table->ParamByName("PARAM_IDARM")->AsInt64=id_arm;
Table->Open();
}
//----------------------------------------------------------------------------

