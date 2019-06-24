//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMXFieldBase.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMXFieldBase::TDMXFieldBase(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMXFieldBase::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;        
}
//---------------------------------------------------------------------------
void  TDMXFieldBase::OpenTable(int id_table)
{
IdTable=id_table;
Table->Active=false;
Table->ParamByName("PARAM_IDTABLE")->AsInteger=id_table;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXFieldBase::NewElement(int id_table)
{
IdTable=id_table;
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMXFieldBase::OpenElement(int id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInteger=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMXFieldBase::SaveElement()
{
Id=ElementID_XFIELD_BASE->AsInteger;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement(Id);
        }
        catch(Exception &exception)
				{
			  //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMXFieldBase::DeleteElement(int id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInteger=id;
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

//void TDMXTableBase::AddRecordDataOut(int id_base, int id_table_ism)
//{
//Element->Active=false;
//Element->Open();
//Element->Insert();

//ElementIDBASE_DATA_OUT->AsInteger=id_base;
//ElementIDTISM_DATA_OUT->AsInteger=id_table_ism;

//SaveElement();
//Element->Active=false;

//}
//---------------------------------------------------------------------------
//int TDMXTableBase::GetIdElement(int id_base, int id_table_ism)
//{
//int result=0;
//IBQ->Active=false;
//IBQ->SQL->Clear();
//IBQ->SQL->Add("select ID_XDATA_OUT from XDATA_OUT");
//IBQ->SQL->Add(" where IDTISM_DATA_OUT=:PARAM_IDTABLE and");
//IBQ->SQL->Add(" IDBASE_DATA_OUT=:PARAM_IDBASE and");
//IBQ->SQL->Add(" (NUM_MESSAGE_DATA_OUT IS NULL or NUM_MESSAGE_DATA_OUT=0)");
//IBQ->ParamByName("PARAM_IDTABLE")->AsInteger=id_table_ism;
//IBQ->ParamByName("PARAM_IDBASE")->AsInteger=id_base;
//IBQ->Active=true;
//result=IBQ->FieldByName("ID_XDATA_OUT")->AsInteger;
//return result;
//}
//---------------------------------------------------------------------------
bool TDMXFieldBase::FindNameField(String name_field)
{
bool result=false;
Table->First();
while(!Table->Eof)
        {
        if(Trim(TableNAME_XFIELD_BASE->AsString)==name_field)
                {
                result=true;
                break;
                }
        Table->Next();
        }
return result;
//ShowMessage("'"+name_field+"'   '"+Trim(TableNAME_XFIELD_BASE->AsString)+"'");
}
//-----------------------------------------------------------------------------
void __fastcall TDMXFieldBase::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMXFieldBase::ElementNewRecord(TDataSet *DataSet)
{
ElementGID_XFIELD_BASE->AsString=
		gl_prefiks_ib+IntToStr(ElementID_XFIELD_BASE->AsInteger);
ElementIDTABLE_XFIELD_BASE->AsInteger=IdTable;	
}
//---------------------------------------------------------------------------

