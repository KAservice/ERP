//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMGurDocCheckKKM2.h"
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
__fastcall TDMGurDocCheckKKM2::TDMGurDocCheckKKM2(TComponent* Owner)
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
void __fastcall TDMGurDocCheckKKM2::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//---------------------------------------------------------------------------
bool TDMGurDocCheckKKM2::Init(void)
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


DM_Connection->GetPrivDM(GCPRIV_DM_GurDocCheckKKM2);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMGurDocCheckKKM2::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMGurDocCheckKKM2::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMGurDocCheckKKM2::OpenTable()
{
bool result=false;

Table->Active=false;
String Zapros="";
Zapros=Zapros+" select  ";
Zapros=Zapros+" NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,NCHECKCHK, NKLCHK,OPERCHK,";
Zapros=Zapros+" NAMEKKM, NAMEFIRM, NAMESKLAD, NAMEKLIENT,   NAME_USER  ";
Zapros=Zapros+" from  DCHK ";
Zapros=Zapros+" left outer join SKKM on IDKKMCHK=IDKKM ";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHK=IDDOC";
Zapros=Zapros+" left outer join SFIRM on IDFIRMDOC=IDFIRM";
Zapros=Zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD ";
Zapros=Zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
Zapros=Zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";
Zapros=Zapros+" where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";
Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);
Zapros=Zapros+" order by POSDOC ";
Table->SelectSQL->Clear();
Table->SelectSQL->Add(Zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;
Table->Last();

result=true;
return result;
}
//---------------------------------------------------------------------------
void TDMGurDocCheckKKM2::UpdateTable(void)
{
IdDoc=TableIDDOC->AsInt64;
DataSourceTable->Enabled=false;

Table->Active=false;
String Zapros="";
Zapros=Zapros+" select  ";
Zapros=Zapros+" NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,NCHECKCHK, NKLCHK,OPERCHK,";
Zapros=Zapros+" NAMEKKM, NAMEFIRM, NAMESKLAD, NAMEKLIENT,   NAME_USER  ";
Zapros=Zapros+" from  DCHK ";
Zapros=Zapros+" left outer join SKKM on IDKKMCHK=IDKKM ";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHK=IDDOC";
Zapros=Zapros+" left outer join SFIRM on IDFIRMDOC=IDFIRM";
Zapros=Zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD ";
Zapros=Zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
Zapros=Zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";
Zapros=Zapros+" where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";


Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);


if (NumberKL!=0)
        {
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



void __fastcall TDMGurDocCheckKKM2::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

