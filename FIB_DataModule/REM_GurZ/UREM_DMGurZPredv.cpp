//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMGurZPredv.h"
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
__fastcall TREM_DMGurZPredv::TREM_DMGurZPredv(TComponent* Owner)
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

bool TREM_DMGurZPredv::Init(void)
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
int TREM_DMGurZPredv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurZPredv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TREM_DMGurZPredv::OpenTable()
{
Table->Active=false;

//UnicodeString text_query="select *                                \
//							from rem_z_get_table(0,:PARAM_DATE_NACH,:PARAM_DATE_CON,0,' ',0)";
//
//							// поиск, текст, int64
//							// 0- нет поиска
//							// 1 - поиск по сер номеру 1
//							// 2 - поиск по сер. номеру 2
//							// 3 - поиск по клиенту
//							// 4 - поиск по модели
//							// 5 - поиск по IdOborud
//							// 6 - поиск по номеру гар. документа
//
//
//Table->SelectSQL->Clear();
//Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;
}
//---------------------------------------------------------------------------
void TREM_DMGurZPredv::UpdateTable(void)
{
IdZ=glStrToInt64(TableID_REM_Z2->AsString);
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_REM_Z2",IntToStr(IdZ),Opt);

DataSourceTable->Enabled=true;
}
//-----------------------------------------------------------------------
UnicodeString TREM_DMGurZPredv::GetNachaloZapros(void)
{
UnicodeString result="select rem_z.*,     \
	sinfbase_obmen.name_sinfbase_obmen,     \
	sfirm.namefirm,                           \
	rem_smodel.name_rem_smodel,               \
	sklad_pr.namesklad as name_sklad_pr,      \
	sklient.nameklient,                       \
	diler.nameklient as namediler,            \
	rem_stremont.name_stremont,               \
	rem_ssost.name_remssost,                  \
	sklad_tec.namesklad as name_sklad_tec,    \
	suser.name_user  ,                         \
	sbrand.name_sbrand                         \
from rem_z                                    \
left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obmen=rem_z.idbase_rem_z    \
left outer join sfirm on sfirm.idfirm=rem_z.idfirm_rem_z                           \
left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z.idmodel_rem_z         \
left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z.idsklpr_rem_z         \
left outer join sklient on sklient.idklient=rem_z.idklient_rem_z                   \
left outer join sklient as diler on diler.idklient=rem_z.iddiler_rem_z             \
left outer join rem_stremont on rem_stremont.id_stremont=rem_z.idtyperem_rem_z     \
left outer join rem_ssost on rem_ssost.id_remssost=rem_z.idsost_rem_z              \
left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z.idtecskl_rem_z      \
left outer join suser on suser.id_user=rem_z.iduser_rem_z                          \
left outer join sbrand on rem_z.idbrand_rem_z=sbrand.id_sbrand                     \
where (POS_REM_Z between  :PARAM_DATE_NACH and :PARAM_DATE_CON)";

return result;

}
//-----------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoSerNum1(UnicodeString ser_num)
{
UnicodeString text_query;

//text_query=text_query+" and upper(rem_z.sernum_rem_z) like upper('%"+
//						   ser_num+"%')";
//text_query=text_query+"order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=1;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosCon-1000;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=ser_num;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();

}
//------------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoSerNum2(UnicodeString ser_num)
{
UnicodeString text_query;

//text_query=text_query+" and upper(rem_z.sernum2_rem_z) like upper('%"+
//						   ser_num+"%')";
//text_query=text_query+"order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=2;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosCon-1000;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=ser_num;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();

}
//-------------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoKlient(UnicodeString value)
{
UnicodeString text_query;

//text_query=text_query+" and upper(rem_z.klient_name_rem_z) like upper('%"+
//						   value+"%')";
//text_query=text_query+"order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

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
//-------------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoModel(UnicodeString value)
{
UnicodeString text_query;

//text_query=text_query+" and upper(rem_z.model_rem_z) like upper('%"+
//						   value+"%')";
//text_query=text_query+"order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=4;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=value;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();

}
//-------------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoIdHardware(__int64 id_hw)
{
UnicodeString text_query;

//text_query=text_query+" and rem_z.idhw_rem_z= :PARAM_IDHW";
//text_query=text_query+" order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=5;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString="";
Table->ParamByName("PARAM_INT64")->AsString=id_hw;
Table->Open();

}
//-------------------------------------------------------------------------
void TREM_DMGurZPredv::PoiskPoNumGarDoc(UnicodeString num_gar_doc)
{
UnicodeString text_query;

//text_query=text_query+" and upper(rem_z.num_gardoc_rem_z) like upper('%"+
//						   num_gar_doc+"%')";
//text_query=text_query+"order by   rem_z.pos_rem_z";

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=6;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosCon-1000;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_STR")->AsString=num_gar_doc;
Table->ParamByName("PARAM_INT64")->AsString=0;
Table->Open();

}
//-------------------------------------------------------------------------
void TREM_DMGurZPredv::OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value)
{
UnicodeString text_query;

text_query="select *                                \
							from rem_z_get_table(:PARAM_IDUSER,:PARAM_DATE_NACH,:PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)";

							// поиск, текст, int64
							// 0- нет поиска
							// 1 - поиск по сер номеру 1
							// 2 - поиск по сер. номеру 2
							// 3 - поиск по клиенту
							// 4 - поиск по модели
							// 5 - поиск по IdOborud
							// 6 - поиск по номеру гар. документа

Table->Close();
Table->SelectSQL->Clear();
Table->SelectSQL->Add(text_query);
Table->ParamByName("PARAM_IDUSER")->AsString=0;
Table->ParamByName("PARAM_POISK")->AsInteger=poisk;
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=pos_start;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=pos_end;
Table->ParamByName("PARAM_STR")->AsString=str_value;
Table->ParamByName("PARAM_INT64")->AsString=int64_value;
Table->Open();

}
//------------------------------------------------------------------------------
