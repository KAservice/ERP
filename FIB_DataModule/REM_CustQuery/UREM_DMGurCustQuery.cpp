//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMGurCustQuery.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------

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
__fastcall TREM_DMGurCustQuery::TREM_DMGurCustQuery(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;
}
//---------------------------------------------------------------------------

bool TREM_DMGurCustQuery::Init(void)
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

Table->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMGurCustQuery::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurCustQuery::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TREM_DMGurCustQuery::OpenTable()
{
Table->Active=false;
UnicodeString text_query;

text_query="select *                                \
			from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=0;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString="";
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();
}
//---------------------------------------------------------------------------
void TREM_DMGurCustQuery::UpdateTable(void)
{
IdCustQuery=glStrToInt64(TableID_REM_CQUERY->AsString);
DataSourceTable->Enabled=false;


UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=0;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString="";
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_REM_CQUERY",IntToStr(IdCustQuery),Opt);

DataSourceTable->Enabled=true;
}
//-----------------------------------------------------------------------
bool TREM_DMGurCustQuery::OpenTableOnlyZayavka(__int64 id_z)
{
bool result=true;
UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=1;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString="";
Table->ParamByName("PARAM_INT64")->AsString=id_z;
Table->Open();

return result;
}
//-----------------------------------------------------------------------

void TREM_DMGurCustQuery::PoiskPoKlient(UnicodeString value)
{
UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=2;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=value;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();
}
//-----------------------------------------------------------------------
void TREM_DMGurCustQuery::PoiskPoModel(UnicodeString value)
{
UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=3;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=value;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();
}
//-----------------------------------------------------------------------
void TREM_DMGurCustQuery::OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64)
{
UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по IdZ
							// 2 - поиск по клиенту
							// 3 - поиск по модели


Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=id_user;
Table->ParamByName("PARAM_POISK")->AsInteger=poisk;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=pos_nach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=pos_con;
Table->ParamByName("PARAM_STR")->AsString=value_str;
Table->ParamByName("PARAM_INT64")->AsString=value_int64;
Table->Open();

}
//-----------------------------------------------------------------------
void TREM_DMGurCustQuery::OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza )
{
UnicodeString text_query;

text_query="select *                                \
							from rem_cquery_get_table_only_zakaz(:PARAM_IDUSER,:PARAM_IDPRODUCER,:PARAM_NUMBER_ZAKAZA,:PARAM_DATE_ZAKAZA)";




Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=id_user;
Table->ParamByName("PARAM_IDPRODUCER")->AsString=id_producer;
Table->ParamByName("PARAM_NUMBER_ZAKAZA")->AsInteger=number_zakaza;
Table->ParamByName("PARAM_DATE_ZAKAZA")->AsDateTime=date_zakaza;


Table->Open();

}
