//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprFirm.h"
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
__fastcall TDMSprFirm::TDMSprFirm(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprFirm::DataModuleCreate(TObject *Sender)
{
Error=false;
}
//----------------------------------------------------------------------------
void __fastcall TDMSprFirm::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------

void  TDMSprFirm::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprFirm::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprFirm::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprFirm::SaveElement()
{
bool result=false;
__int64 id=ElementIDFIRM->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
        {
		Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprFirm::DeleteElement(__int64 Id)
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


//---------------------------------------------------------------------------
AnsiString TDMSprFirm::GetGIDElement(__int64 id)
{
AnsiString res=0;
		if (id!=0 )
                {
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
					pFIBQ->SQL->Add("select GID_SFIRM from SFIRM where IDFIRM=:PARAM_ID");
					pFIBQ->ParamByName("PARAM_ID")->AsInt64=id;
					pFIBQ->ExecQuery();
					if (pFIBQ->RecordCount==1)
						{
						res=Trim(pFIBQ->FieldByName("GID_SFIRM")->AsString);
						}
					else res="";
				pFIBQ->Close();
				} 
return res;
}
//---------------------------------------------------------------------------
__int64 TDMSprFirm::GetIDElement(AnsiString gid)
{
__int64 res=0;
		if (gid!="" )
                {
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDFIRM from SFIRM where GID_SFIRM=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=gid;
				pFIBQ->ExecQuery();
					if (pFIBQ->RecordCount==1)
						{
						res=glStrToInt64(Trim(pFIBQ->FieldByName("GID_SFIRM")->AsString));
						}
					else res=0;
				pFIBQ->Close();
				} 
return res;
}
//---------------------------------------------------------------------------


void __fastcall TDMSprFirm::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
int TDMSprFirm::GetIndexElementaPoID(__int64 id)
{    //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableIDFIRM->AsInt64==id)
		{
		result=index+1;
		break;
		}
	index++;
	Table->Next();
	}
return result;
}
//----------------------------------------------------------------------------


