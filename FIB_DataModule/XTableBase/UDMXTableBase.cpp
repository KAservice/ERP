//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMXTableBase.h"
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
__fastcall TDMXTableBase::TDMXTableBase(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMXTableBase::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;        
}
//---------------------------------------------------------------------------
void  TDMXTableBase::OpenTable(void)
{

Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXTableBase::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMXTableBase::OpenElement(int id)
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

void  TDMXTableBase::SaveElement()
{
Id=ElementID_XTABLE_BASE->AsInteger;
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
void TDMXTableBase::DeleteElement(int id)
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
int TDMXTableBase::GetElementPoName(String name_table)
{
int result=0;
TpFIBQuery * query=new TpFIBQuery(0);
query->Database=DM->pFIBData;
query->Transaction=IBTr;
query->SQL->Add("select ID_XTABLE_BASE from XTABLE_BASE");
query->SQL->Add(" where NAMETAB_XTABLE_BASE=:PARAM_NAMETABLE");
query->ParamByName("PARAM_NAMETABLE")->AsString=name_table;
if (IBTr->Active==false) IBTr->StartTransaction();
query->ExecQuery();
result=OpenElement(query->FieldByName("ID_XTABLE_BASE")->AsInteger);
delete query;
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMXTableBase::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMXTableBase::ElementNewRecord(TDataSet *DataSet)
{
ElementGID_XTABLE_BASE->AsString=
		gl_prefiks_ib+IntToStr(ElementID_XTABLE_BASE->AsInteger);
}
//---------------------------------------------------------------------------

