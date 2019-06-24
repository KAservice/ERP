//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprKlient.h"

#include "UDMSprKlientDopFisL.h"
#include "UDMSprKlientDopUrL.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprKlient::TDMSprKlient(TComponent* Owner)
        : TDataModule(Owner)
{
elSave=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
void __fastcall TDMSprKlient::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//----------------------------------------------------------------------------
bool TDMSprKlient::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_SprKlient);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMSprKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprKlient::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMSprKlient::OpenTable(__int64 id_grp,bool all)
{
bool result=false;
if (ExecPriv==false)
	{
	TextError="Ошибка: Справочник Контрагенты! Недостаточно прав доступа для выполнения операции!";
    return result;
	}

IdGroup=id_grp;
AllElement=all;
Table->Active=false;
if(all==true)
        {
		Table->SelectSQL->Clear();
		Table->SelectSQL->Add("select IDKLIENT, IDGRPKLIENT, NAMEKLIENT, INNKLIENT,");
		Table->SelectSQL->Add("TELKLIENT, ADRKLIENT from SKLIENT");
		Table->SelectSQL->Add("ORDER BY NAMEKLIENT");
        }
else
        {
		if (id_grp==0)
                {
				Table->SelectSQL->Clear();
				Table->SelectSQL->Add("select IDKLIENT, IDGRPKLIENT, NAMEKLIENT, INNKLIENT,");
				Table->SelectSQL->Add("TELKLIENT, ADRKLIENT  from SKLIENT");
				Table->SelectSQL->Add("where IDGRPKLIENT IS NULL");
				Table->SelectSQL->Add("ORDER BY NAMEKLIENT");
                }
        else
                {
				Table->SelectSQL->Clear();
				Table->SelectSQL->Add("select IDKLIENT, IDGRPKLIENT, NAMEKLIENT, INNKLIENT,");
				Table->SelectSQL->Add("TELKLIENT, ADRKLIENT  from SKLIENT");
				Table->SelectSQL->Add("where IDGRPKLIENT="+IntToStr(id_grp));
				Table->SelectSQL->Add("ORDER BY NAMEKLIENT");
                }
        }
Table->Open();
result=true;
return result;
}

//---------------------------------------------------------------------------

void  TDMSprKlient::NewElement(__int64 id_grp)
{
elSave=false;
Element->Active=false;
Element->Open();
Element->Insert();
if (id_grp!=0)
        {
		ElementIDGRPKLIENT->AsInt64=id_grp;
        }
}
//---------------------------------------------------------------------------

int TDMSprKlient::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
if (Res>0) elSave=true;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprKlient::SaveElement()
{
bool result=false;
Id=ElementIDKLIENT->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(Id);
		result=true;
		elSave=true;
        }
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprKlient::DeleteElement(__int64 id)
{
bool result=true;
elSave=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
		{
		//необходимо сначала удалить Доп. сведения
		TextError="";

		TDMSprKlientDopFisL * dop_fl=new TDMSprKlientDopFisL(Application);
		dop_fl->IdKlient=id;
		if (dop_fl->DeleteElement()==false)
			{
			TextError="Ошибка при удалении доп. сведений о физ. лице: "+dop_fl->TextError;
			result=false;
			}
		delete dop_fl;

		TDMSprKlientDopUrL * dop_ul=new TDMSprKlientDopUrL(Application);
		dop_ul->IdKlient=id;
		if (dop_ul->DeleteElement()==false)
			{
			TextError=TextError+" "+"Ошибка при удалении доп. сведений о юр. лице: "+dop_ul->TextError;
			result=false;
			}
		delete dop_ul;

		if (result==true)
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
				TextError=exception.Message;
				result=false;
				}
			}
		}
		
return result;
}
//---------------------------------------------------------------------------
void TDMSprKlient::ChancheGrp(__int64 new_grp)
{
OpenElement(TableIDKLIENT->AsInt64);
Element->Edit();
ElementIDGRPKLIENT->AsInt64=new_grp;
Element->Post();
SaveElement();
OpenTable(IdGroup,AllElement);
}

//-----------------------------------------------------------------------
__int64 TDMSprKlient::FindPoName(String Name)
{
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add("select * from SKLIENT where NAMEKLIENT like '%"+Name
                        +"%' order by NAMEKLIENT");
Table->Active=true;
return Table->RecordCount;
}
//----------------------------------------------------------------------------

void __fastcall TDMSprKlient::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

__int64 TDMSprKlient::GetIDKlientPoName(AnsiString name)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDKLIENT from SKLIENT ");
		pFIBQ->SQL->Add(" where NAMEKLIENT=:PARAM_NAMEKLIENT");
		pFIBQ->ParamByName("PARAM_NAMEKLIENT")->AsString=name;
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("IDKLIENT")->AsInt64;
pFIBQ->Close();
return result;

}
//----------------------------------------------------------------------------
__int64 TDMSprKlient::GetIdGrpKlient(__int64 id_klient)
{
__int64 res;
res=0;
 pFIBQ->Close();
 pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDGRPKLIENT from SKLIENT where IDKLIENT='"+IntToStr(id_klient)+"'");
		pFIBQ->ExecQuery();
		res=pFIBQ->FieldByName("IDGRPKLIENT")->AsInt64;
 pFIBQ->Close();
return res;

}
//-----------------------------------------------------------------------------

