//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMPriemPlat.h"
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
__fastcall TDMPriemPlat::TDMPriemPlat(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMPriemPlat::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMPriemPlat::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;

IBQNumTel->Database=DM_Connection->pFIBData;
IBQNom->Database=DM_Connection->pFIBData;
IBQCom->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMPriemPlat::DataModuleDestroy(TObject *Sender)
{
IBQNumTel->Active=false;
IBQNom->Active=false;
IBQCom->Active=false;
}
//---------------------------------------------------------------------------
__int64 TDMPriemPlat::GetIDKlientPoNumTel(AnsiString code, AnsiString number)
{
__int64 result=0;
IBQNumTel->Active=false;
IBQNumTel->ParamByName("PARAM_CODE")->AsString=code;
IBQNumTel->ParamByName("PARAM_NUMBER")->AsString=number;
IBQNumTel->Active=true;

result=IBQNumTelIDKLIENT_NUMTEL->AsInt64;
return result;
}
//----------------------------------------------------------------------------
__int64 TDMPriemPlat::OpenNom(__int64 id_el_spr_codetel)
{
__int64 result=0;
IBQNom->Active=false;
IBQNom->ParamByName("PARAM_ID")->AsString=id_el_spr_codetel;
IBQNom->Active=true;
result=IBQNomIDNOM->AsInt64;
return result;
}
//----------------------------------------------------------------------------
__int64 TDMPriemPlat::OpenCom(__int64 id_el_spr_codetel)
{
__int64 result=0;
IBQCom->Active=false;
IBQCom->ParamByName("PARAM_ID")->AsInt64=id_el_spr_codetel;
IBQCom->Active=true;

result=IBQComIDNOM->AsInt64;
return result;
}
//-----------------------------------------------------------------------------
