//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMGurZAktPr.h"

//---------------------------------------------------------------------------
#include "IDMSetup.h"


#include "UGlobalFunction.h"
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

//extern AnsiString glGetNameDocRemont(AnsiString str_code_doc);
//---------------------------------------------------------------------------
__fastcall TREM_DMGurZAktPr::TREM_DMGurZAktPr(TComponent* Owner)
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

bool TREM_DMGurZAktPr::Init(void)
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
int TREM_DMGurZAktPr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurZAktPr::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::OpenTable()
{
Table->Active=false;
UnicodeString zapros="    select                                                              \
	rem_dzaktpr.iddoc_rem_dzaktpr,                                                            \
	rem_galldoc.pr_rem_galldoc,                                                               \
	REM_GALLDOC.pos_rem_galldoc,                                                              \
	rem_galldoc.prefiks_num_rem_galldoc,                                                      \
	rem_galldoc.num_rem_galldoc,                                                              \
	rem_galldoc.sum_rem_galldoc,                                                              \
	rem_z.pos_rem_z,                                                                          \
	rem_z.prefiks_num_rem_z,                                                                  \
	rem_z.num_rem_z,                                                                          \
	rem_sprmodel.name_rem_sprmodel,                                                           \
	rem_z.num_gardoc_rem_z,                                                                    \
	rem_dzaktpr.numgartalon_rem_dzaktpr,                                                      \
	rem_z.sernum_rem_z,                                                                       \
	rem_z.sernum2_rem_z,                                                                      \
	NAMEFIRM,                                                                                 \
	NAMESKLAD,                                                                                \
	NAMEKLIENT,                                                                               \
	NAME_USER,                                                                                \
	sinfbase_obmen.name_sinfbase_obmen,                                                       \
	rem_dzaktpr.klient_name_rem_dzaktpr,                                                      \
	rem_dzaktpr.klient_adr_rem_dzaktpr,                                                       \
	rem_dzaktpr.klient_phone_rem_dzaktpr,                                                     \
	rem_dzaktpr.fl_fictiv_rem_dzaktpr,                                                  \
	rem_z.fl_povtor_rem_z,                                                              \
    rem_z.fl_addreport_rem_z,                                                            \
	rem_z.fl_fictiv_rem_z,                                                                \
	rem_z.fl_ne_otch_rem_z,                                                               \
	rem_z.fl_nado_otch_rem_z,                                                              \
	rem_dzaktpr.fl_ne_otch_rem_dzaktpr,                                                        \
	rem_dzaktpr.fl_nado_otch_rem_dzaktpr,                                                         \
	rem_dzaktpr.POSPRIEMA_REM_DZAKTPR                                                         \
from rem_dzaktpr                                                                              \
left outer join rem_galldoc on rem_dzaktpr.iddoc_rem_dzaktpr=rem_galldoc.id_rem_galldoc       \
left outer join rem_z on rem_dzaktpr.idz_rem_dzaktpr=rem_z.id_rem_z                           \
left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC                        \
LEFT OUTER JOIN SFIRM ON IDFIRM_REM_GALLDOC = IDFIRM                                          \
left outer join SSKLAD on IDSKLAD_REM_GALLDOC = IDSKLAD                                       \
left outer join SKLIENT on IDKLIENT_REM_GALLDOC =IDKLIENT                                     \
left outer join SUSER on  IDUSER_REM_GALLDOC = ID_USER                                           \
left outer join rem_sprmodel on rem_dzaktpr.idprmodel_rem_dzaktpr=rem_sprmodel.id_rem_sprmodel   \
where rem_galldoc.pos_rem_galldoc between  :PARAM_POSNACH and :PARAM_POSCON                      \
order by rem_galldoc.pos_rem_galldoc ";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::UpdateTable(void)
{
IdDoc=glStrToInt64(TableIDDOC_REM_DZAKTPR->AsString);
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("iddoc_rem_dzaktpr",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}

//-----------------------------------------------------------------------

//--------------------------------------------------------------------------

//открыть журнал только с выбранным оборудованием
bool TREM_DMGurZAktPr::OpenTableOnlyHardware(__int64 id_hw)
{
bool result=false;
////надо использовать процедуру
//Table->Active=false;
//Table->SelectSQL->Clear();
////Table->Fields->Clear();
//
//UnicodeString zapros="select REM_GALLDOC_GET_TABLE_PO_IDHW.id_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idbase_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idfirm_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idsklad_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idklient_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.iduser_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.pos_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.num_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.pr_rem_galldoc,             \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.tdoc_rem_galldoc,           \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.iddocosn_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.typeextdoc_rem_galldoc,     \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idextdoc_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.sum_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idproject_rem_galldoc,      \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.idbusinop_rem_galldoc,      \
//						REM_GALLDOC_GET_TABLE_PO_IDHW.prefiks_num_rem_galldoc,     \
//			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                                                             \
//			sinfbase_obmen.name_sinfbase_obmen                                     \
//			from REM_GALLDOC_GET_TABLE_PO_IDHW(:PARAM_IDHW,:PARAM_POSNACH,:PARAM_POSCON)                              \
//			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC                                  \
//			LEFT OUTER JOIN SFIRM ON REM_GALLDOC_GET_TABLE_PO_IDHW.idfirm_rem_galldoc = IDFIRM                       \
//			left outer join SSKLAD on REM_GALLDOC_GET_TABLE_PO_IDHW.idsklad_rem_galldoc = IDSKLAD                    \
//			left outer join SKLIENT on REM_GALLDOC_GET_TABLE_PO_IDHW.idklient_rem_galldoc =IDKLIENT                  \
//			left outer join SUSER on  REM_GALLDOC_GET_TABLE_PO_IDHW.iduser_rem_galldoc = ID_USER                     \
//			order by POS_REM_GALLDOC  ";
//Table->SelectSQL->Add(zapros);
//Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
//Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
//Table->ParamByName("PARAM_IDHW")->AsString=id_hw;
//Table->Active=true;
return result;
}
//---------------------------------------------------------------------------

//открыть журнал только с выбранной заявкой
bool TREM_DMGurZAktPr::OpenTableOnlyZayavka(__int64 id_z)
{
bool result=false;
////надо использовать процедуру
//Table->Active=false;
//Table->SelectSQL->Clear();
////Table->Fields->Clear();
//
//UnicodeString zapros="select REM_GALLDOC_GET_TABLE_PO_IDZ.id_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idbase_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idfirm_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idsklad_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idklient_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.iduser_rem_galldoc,         \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.pos_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.num_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.pr_rem_galldoc,             \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.tdoc_rem_galldoc,           \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.iddocosn_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.typeextdoc_rem_galldoc,     \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idextdoc_rem_galldoc,       \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.sum_rem_galldoc,            \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idproject_rem_galldoc,      \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.idbusinop_rem_galldoc,      \
//						REM_GALLDOC_GET_TABLE_PO_IDZ.prefiks_num_rem_galldoc,     \
//			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                                                             \
//			sinfbase_obmen.name_sinfbase_obmen                                   \
//			from REM_GALLDOC_GET_TABLE_PO_IDZ(:PARAM_IDZ,:PARAM_POSNACH,:PARAM_POSCON)                              \
//			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC                                  \
//			LEFT OUTER JOIN SFIRM ON REM_GALLDOC_GET_TABLE_PO_IDZ.idfirm_rem_galldoc = IDFIRM                       \
//			left outer join SSKLAD on REM_GALLDOC_GET_TABLE_PO_IDZ.idsklad_rem_galldoc = IDSKLAD                    \
//			left outer join SKLIENT on REM_GALLDOC_GET_TABLE_PO_IDZ.idklient_rem_galldoc =IDKLIENT                  \
//			left outer join SUSER on  REM_GALLDOC_GET_TABLE_PO_IDZ.iduser_rem_galldoc = ID_USER                     \
//			order by POS_REM_GALLDOC  ";
//Table->SelectSQL->Add(zapros);
//Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
//Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
//Table->ParamByName("PARAM_IDZ")->AsString=id_z;
//Table->Active=true;
return result;
}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::PoiskPoSerNum1(UnicodeString ser_num)
{


}
//---------------------------------------------------------------------------

void TREM_DMGurZAktPr::PoiskPoSerNum2(UnicodeString ser_num)
{


}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::PoiskPoKlient(UnicodeString value)
{


}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::PoiskPoModel(UnicodeString value)
{


}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::PoiskPoIdHardware(__int64 id_hw)
{


}
//---------------------------------------------------------------------------
void TREM_DMGurZAktPr::PoiskPoNumGarDoc(UnicodeString num_gar_doc)
{


}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurZAktPr::TableCalcFields(TDataSet *DataSet)
{
TableSROK_REMONTA->AsInteger=TablePOS_REM_GALLDOC->AsDateTime - TablePOS_REM_Z->AsDateTime+1;
TableSROK_REMONTA_NOW->AsInteger=Now() - TablePOS_REM_Z->AsDateTime+1;
TableSROK_REMONTA_IS_DOC->AsInteger=TablePOS_REM_GALLDOC->AsDateTime - TablePOSPRIEMA_REM_DZAKTPR->AsDateTime+1;
}
//---------------------------------------------------------------------------

