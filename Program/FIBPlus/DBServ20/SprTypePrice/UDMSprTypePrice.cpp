//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprTypePrice.h"
#include "UDM.h"
//#include "UDMXTableIsm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern bool gl_add_table_ism;
//---------------------------------------------------------------------------
__fastcall TDMSprTypePrice::TDMSprTypePrice(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
}
//---------------------------------------------------------------------------
void __fastcall TDMSprTypePrice::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TDMSprTypePrice::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprTypePrice::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprTypePrice::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprTypePrice::SaveElement()
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
			  //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprTypePrice::CloseElement()
{

        Element->CancelUpdates();
		IBTr->Rollback();
}
//---------------------------------------------------------------------------
void TDMSprTypePrice::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
        }
}
//-----------------------------------------------------------------------------
__int64 TDMSprTypePrice::GetIDTypePrice(String name)
{
int result=0;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
if(Table->Locate("NAME_TPRICE",name,Opt)==true)
        {
		result=TableID_TPRICE->AsInt64;
        }

return result;
}
//-----------------------------------------------------------------------------
__int64 TDMSprTypePrice::GetIDElement(String gid)
{
__int64 res=0;
pFIBQ->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_TPRICE from STPRICE where GID_STPRICE=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("ID_TPRICE")->AsInt64;
                        }
                else res=0;
                }
pFIBQ->Close();

return res;
}
//-----------------------------------------------------------------------------
AnsiString TDMSprTypePrice::GetGIDElement(__int64 id)
{
AnsiString res="";
pFIBQ->Close();

				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select GID_STPRICE from STPRICE where ID_TPRICE=:PARAM_ID");
				pFIBQ->ParamByName("PARAM_ID")->AsString=id;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("GID_STPRICE")->AsString;
						}
				else res="";

pFIBQ->Close();

return res;
}
//----------------------------------------------------------------------------
int TDMSprTypePrice::GetIndexTypePricePoId(__int64 id_type_price)
{
int result=0;
Table->First();
while (!Table->Eof)
        {
        result=result+1;
        if (id_type_price==TableID_TPRICE->AsInt64)
                {
                return result;
                }
        Table->Next();
        }

return 0;
}
//---------------------------------------------------------------------------

