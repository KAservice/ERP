//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprTypePrice.h"
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
__fastcall TREM_DMSprTypeRemont::TREM_DMSprTypeRemont(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprTypeRemont::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TREM_DMSprTypeRemont::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TREM_DMSprTypeRemont::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
ElementTSKLAD->AsInteger=0;
}
//---------------------------------------------------------------------------

int TREM_DMSprTypeRemont::OpenElement(int Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInteger=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprTypeRemont::SaveElement()
{
bool result;
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

void  TREM_DMSprTypeRemont::CloseElement()
{

        Element->CancelUpdates();
        IBTr->Rollback();   
}
//---------------------------------------------------------------------------
void TREM_DMSprTypeRemont::DeleteElement(int Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInteger=Id;
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

int TREM_DMSprTypeRemont::GetIDElement(String gid)
{
int res=0;

        if (gid!="" || gid!=" " )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDSKLAD from SSKLAD where GID_SSKLAD=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("IDSKLAD")->AsInteger;
						}
				else res=0;
                }
				pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
AnsiString TREM_DMSprTypeRemont::GetGIDElement(int id)
{
AnsiString res=0;

		if (id!=0 )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select GID_SSKLAD from SSKLAD where IDSKLAD=:PARAM_ID");
				pFIBQ->ParamByName("PARAM_ID")->AsInteger=id;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=Trim(pFIBQ->FieldByName("GID_SSKLAD")->AsString);
                        }
				else res="";
				pFIBQ->Close();
                }



return res;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprTypeRemont::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprTypeRemont::ElementNewRecord(TDataSet *DataSet)
{
ElementGID_SSKLAD->AsString=
		gl_prefiks_ib+IntToStr(ElementIDSKLAD->AsInteger);	
}
//---------------------------------------------------------------------------
int TREM_DMSprTypeRemont::GetIndexElementaPoID(int id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableIDSKLAD->AsInteger==id)
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
