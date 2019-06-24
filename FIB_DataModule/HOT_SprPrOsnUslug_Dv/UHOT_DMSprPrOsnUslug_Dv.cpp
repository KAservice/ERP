//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_DMSprPrOsnUslug_Dv.h"
#include "UDM.h"
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
__fastcall THOT_DMSprPrOsnUslug_Dv::THOT_DMSprPrOsnUslug_Dv(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMSprPrOsnUslug_Dv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  THOT_DMSprPrOsnUslug_Dv::OpenTable()
{
Table->Active=false;
Table->Open();

}
//---------------------------------------------------------------------------

void  THOT_DMSprPrOsnUslug_Dv::UpdateTable()
{
//Table->Active=false;
//Table->Open();
//
//int id=TableID_HOT_SPROSNUSL->AsInteger;
//DataSourceTable->Enabled=false;
//
//OpenTable();
//TLocateOptions Opt;
//Opt<<loCaseInsensitive;
//Table->Locate("ID_HOT_GALLDOC",IntToStr(IdDocH),Opt);
//
//DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------

bool  THOT_DMSprPrOsnUslug_Dv::NewElement()
{
bool result=false;
try
	{
	Element->Active=false;
	Element->Open();
	Element->Append();
	ElementPOSIN_HOT_SNF->AsDateTime=Now();
	ElementPOSOUT_HOT_SNF->AsDateTime=ElementPOSIN_HOT_SNF->AsDateTime+100000;
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------

int THOT_DMSprPrOsnUslug_Dv::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  THOT_DMSprPrOsnUslug_Dv::SaveElement()
{
bool result;
try
		{
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
		result=true;

        }
catch(Exception &exception)
		{
		IBTrUpdate->Rollback();
		Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

void  THOT_DMSprPrOsnUslug_Dv::CloseElement()
{

Element->CancelUpdates();

}
//---------------------------------------------------------------------------
bool THOT_DMSprPrOsnUslug_Dv::DeleteElement(__int64 Id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
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

//---------------------------------------------------------------------------
void __fastcall THOT_DMSprPrOsnUslug_Dv::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int THOT_DMSprPrOsnUslug_Dv::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableID_HOT_SNF->AsInt64==id)
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
