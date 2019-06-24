//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMTableExtPrintForm.h"

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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMTableExtPrintForm::TDMTableExtPrintForm(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMTableExtPrintForm::Init(void)
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


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_ExtModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMTableExtPrintForm::Done(void)
{

return -1;
}
//--------------------------------------------------------------------------------
void __fastcall TDMTableExtPrintForm::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TDMTableExtPrintForm::OpenTable(REFIID guid, bool all)
{
Table->Active=false;
Table->SelectSQL->Clear();
if (all==true)
		{
		UnicodeString zapros="select  EXTPRINT_FORM.*,               \
								program_module.name_program_module,   \
								program_module.progid_program_module,\
								program_module.patch_program_module  \
								from  EXTPRINT_FORM                  \
								left outer join program_module on extprint_form.guid_ob_extprint_form=program_module.guid_program_module   \
								order by program_module.name_program_module,EXTPRINT_FORM.name_extprint_form  ";
        Table->SelectSQL->Add(zapros);
        }
else
		{
		UnicodeString zapros="select  EXTPRINT_FORM.*,               \
								program_module.name_program_module,   \
								program_module.progid_program_module,\
								program_module.patch_program_module  \
								from  EXTPRINT_FORM                  \
								left outer join program_module on extprint_form.guid_ob_extprint_form=program_module.guid_program_module  \
								where  EXTPRINT_FORM.guid_ob_extprint_form=:PARAM_GUID      \
								order by program_module.name_program_module,EXTPRINT_FORM.name_extprint_form";
		Table->SelectSQL->Add(zapros);
		Table->ParamByName("PARAM_GUID")->AsString=GUIDToString(guid);
        }
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMTableExtPrintForm::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMTableExtPrintForm::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMTableExtPrintForm::SaveElement()
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

				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------

void  TDMTableExtPrintForm::CloseElement()
{

        Element->CancelUpdates();
        IBTr->Rollback();   
}
//---------------------------------------------------------------------------
void TDMTableExtPrintForm::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
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
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------

__int64 TDMTableExtPrintForm::GetIDElement(String gid)
{
__int64 res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {
        if (gid!="" || gid!=" " )
                {
				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select ID_EXTPRINT_FORM from EXTPRINT_FORM where GID_EXTPRINT_FORM=:PARAM_GID");
				query->ParamByName("PARAM_GID")->AsString=Trim(gid);
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=query->FieldByName("ID_EXTPRINT_FORM")->AsInt64;
                        }
                else res=0;
				}
        }
__finally
	{
	delete query;
	}

return res;
}
//---------------------------------------------------------------------------
AnsiString TDMTableExtPrintForm::GetGIDElement(__int64 id)
{
AnsiString res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {
        if (id!=0 )
                {
				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select GID_EXTPRINT_FORM from SCOUNTRY where ID_EXTPRINT_FORM=:PARAM_ID");
				query->ParamByName("PARAM_ID")->AsInt64=id;
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=Trim(query->FieldByName("GID_EXTPRINT_FORM")->AsString);
                        }
                else res="";
                }
        }
__finally
	{
	delete query;
	}

return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMTableExtPrintForm::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

