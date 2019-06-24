//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UDMObjectBasePrivGrp.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMObjectBasePrivGrp::TDMObjectBasePrivGrp(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMObjectBasePrivGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
MenuTable->Active=false;
}
//---------------------------------------------------------------------------
void  TDMObjectBasePrivGrp::OpenTable(int num_application, __int64 id_grp_user)
{
IdGrpUser=id_grp_user;
NumApplication=num_application;

Table->Active=false;
Table->ParamByName("PARAM_IDGRPUSER")->AsInt64=id_grp_user;
Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
Table->Open();

}

//---------------------------------------------------------------------------
void TDMObjectBasePrivGrp::Table_First(void)
{
Table->First();
}
//---------------------------------------------------------------------------
void TDMObjectBasePrivGrp::Table_Next(void)
{
Table->Next();
}
//----------------------------------------------------------------------------
void  TDMObjectBasePrivGrp::NewElement(int num_application,__int64 id_grp_user, __int64 id_grp)
{
IdGrpUser=id_grp_user;
NumApplication=num_application;
Element->Active=false;
Element->Open();

Element->Insert();
ElementAPPLICATION_INTERF_MAINMENU_GRP->AsInteger=num_application;

if (id_grp_user!=0)
        {
		ElementIDGRPUSER_INTERF_MAINMENU_GRP->AsInt64=id_grp_user;
        }
if(id_grp!=0)
        {
		ElementIDGRP_INTERF_MAINMENU_GRP->AsString=id_grp;
		}
Element->Post();
}
//---------------------------------------------------------------------------

int TDMObjectBasePrivGrp::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
void TDMObjectBasePrivGrp::Element_Edit(void)
{
Element->Edit();
}
//-------------------------------------------------------------------------
void TDMObjectBasePrivGrp::Element_Post(void)
{
Element->Post();
}
//----------------------------------------------------------------------------
bool  TDMObjectBasePrivGrp::SaveElement()
{
bool result=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
        {
		   //		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMObjectBasePrivGrp::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
		catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
                }
		}
return result;
}
//-----------------------------------------------------------------

void __fastcall TDMObjectBasePrivGrp::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void TDMObjectBasePrivGrp::OpenMenuTable(int num_application, __int64 id_grp_user)
{
MenuTable->Active=false;
MenuTable->ParamByName("PARAM_APPLICATION")->AsInteger=num_application;
MenuTable->ParamByName("PARAM_IDGRPUSER")->AsInt64=id_grp_user;
MenuTable->Active=true;
}
//---------------------------------------------------------------------

