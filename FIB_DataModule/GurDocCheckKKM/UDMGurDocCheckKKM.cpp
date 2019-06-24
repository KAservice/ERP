//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurDocCheckKKM.h"

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
__fastcall TDMGurDocCheckKKM::TDMGurDocCheckKKM(TComponent* Owner)
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
bool TDMGurDocCheckKKM::Init(void)
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

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMGurDocCheckKKM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMGurDocCheckKKM::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMGurDocCheckKKM::OpenTable()
{
Table->Active=false;
String Zapros="";
Zapros=" select  \
  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,          \
  dchk.NCHECKCHK,                                \
  dchk.NKLCHK,                                   \
  dchk.OPERCHK,                                  \
  NAMEKKM,                                       \
  NAMEFIRM,                                      \
  NAMESKLAD,                                     \
  NAMEKLIENT,                                    \
NAME_USER,                                       \
dchk.oplnalchk,                                  \
dchk.oplpcchk,                                   \
dchk.oplplatcard_all_dchk,                       \
dchk.oplcreditcard_all_dchk,                     \
dchk.opl_other_dchk                              \
from  DCHK                                       \
left outer join SKKM on IDKKMCHK=IDKKM           \
left outer join GALLDOC on IDDOCCHK=IDDOC        \
left outer join SFIRM on IDFIRMDOC=IDFIRM        \
left outer join SSKLAD on IDSKLDOC=IDSKLAD       \
left outer join SKLIENT on IDKLDOC=IDKLIENT      \
left outer join SUSER on  IDUSERDOC= ID_USER     \
where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON   \
order by POSDOC ";
Table->SelectSQL->Clear();
Table->SelectSQL->Add(Zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurDocCheckKKM::UpdateTable(void)
{
IdDoc=glStrToInt64(TableIDDOC->AsString);
DataSourceTable->Enabled=false;

Table->Active=false;
UnicodeString Zapros=" select  \
  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,          \
  dchk.NCHECKCHK,                                \
  dchk.NKLCHK,                                   \
  dchk.OPERCHK,                                  \
  NAMEKKM,                                       \
  NAMEFIRM,                                      \
  NAMESKLAD,                                     \
  NAMEKLIENT,                                    \
NAME_USER,                                       \
dchk.oplnalchk,                                  \
dchk.oplpcchk,                                   \
dchk.oplplatcard_all_dchk,                       \
dchk.oplcreditcard_all_dchk,                     \
dchk.opl_other_dchk                              \
from  DCHK                                       \
left outer join SKKM on IDKKMCHK=IDKKM                             \
left outer join GALLDOC on IDDOCCHK=IDDOC                          \
left outer join SFIRM on IDFIRMDOC=IDFIRM                          \
left outer join SSKLAD on IDSKLDOC=IDSKLAD                         \
left outer join SKLIENT on IDKLDOC=IDKLIENT                        \
left outer join SUSER on  IDUSERDOC= ID_USER                       \
 where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";

if (IdKKM!=0 && NumberKL==0)
        {
        Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);
        }

if (IdKKM!=0 && NumberKL!=0)
        {
        Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);
        Zapros=Zapros+" and NKLCHK="+IntToStr(NumberKL);
        }

Zapros=Zapros+" order by POSDOC ";


Table->SelectSQL->Clear();
Table->SelectSQL->Add(Zapros);
//ShowMessage(DateTimeToStr(PosNach)+"   "+DateTimeToStr(PosCon));
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("IDDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

