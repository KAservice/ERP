//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMXMessageObmen.h"
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
//---------------------------------------------------------------------------
__fastcall TDMXMessageObmen::TDMXMessageObmen(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMXMessageObmen::DataModuleCreate(TObject *Sender)
{
Sort=PoDate;
}
//---------------------------------------------------------------------------

void __fastcall TDMXMessageObmen::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;        
}
//---------------------------------------------------------------------------
void  TDMXMessageObmen::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->Active=false;
AnsiString zapros="";
zapros=zapros+" select * ";
zapros=zapros+" from  XMESSAGE_OBMEN  ";
zapros=zapros+" left outer join SINFBASE_OBMEN on IDBASE_XMESSAGE_OBMEN= ID_SINFBASE_OBMEN";
zapros=zapros+" where POS_XMESSAGE_OBMEN between  :PARAM_DATE_NACH and :PARAM_DATE_CON";
if (id_base!=0)
        {
        zapros=zapros+" and IDBASE_XMESSAGE_OBMEN="+IntToStr(id_base);
        }
if(Sort==PoDate)
        {
        zapros=zapros+" ORDER BY POS_XMESSAGE_OBMEN";
        }

if (Sort==PoGid)
        {
        zapros=zapros+" ORDER BY GID_XMESSAGE_OBMEN";
        }

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
//Table->ParamByName( "PARAM_IDBASE")->AsInteger=id_base;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXMessageObmen::NewElement(__int64 id_base)
{
IdBase=id_base;
Element->Active=false;
Element->Open();
Element->Insert();


}
//---------------------------------------------------------------------------

int TDMXMessageObmen::OpenElement(__int64 id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMXMessageObmen::SaveElement()
{
Id=ElementID_XMESSAGE_OBMEN->AsInt64;
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
void TDMXMessageObmen::DeleteElement(__int64 id)
{
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

//---------------------------------------------------------------------------
__int64 TDMXMessageObmen::GetIDElement(String gid)
{
int res=0;
        if (gid!="" || gid!=" " )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_XMESSAGE_OBMEN from XMESSAGE_OBMEN where GID_XMESSAGE_OBMEN=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				res=pFIBQ->FieldByName("ID_XMESSAGE_OBMEN")->AsInt64;
				pFIBQ->Close();
                }
return res;
}
//---------------------------------------------------------------------------
int TDMXMessageObmen::GetCountUpdateRecord(__int64 id_message)
{
int result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("SELECT COUNT(*) AS COUNT_REC FROM XDATA_OUT WHERE IDMESSAGE_XDATA_OUT="
						+IntToStr(id_message));
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("COUNT_REC")->AsInteger;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMXMessageObmen::ElementCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMXMessageObmen::ElementNewRecord(TDataSet *DataSet)
{
ElementIDBASE_XMESSAGE_OBMEN->AsInt64=IdBase;

ElementPOS_XMESSAGE_OBMEN->AsDateTime=Now();
}
//---------------------------------------------------------------------------

