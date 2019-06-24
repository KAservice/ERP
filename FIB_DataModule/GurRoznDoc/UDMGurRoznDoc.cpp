//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurRoznDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
__fastcall TDMGurRoznDoc::TDMGurRoznDoc(TComponent* Owner)
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

void __fastcall TDMGurRoznDoc::DataModuleCreate(TObject *Sender)
{
OtborVkl=false;
OtborPoFirm=false;
OtborPoKlient=false;
OtborPoSklad=false;
OtborPoTypeDoc=false;
StringFullTypeDoc="'CHK','REAL_REST', 'REPKKM','REALROZN','PKOROZN','RKOROZN','VPOK'";
StringTypeDoc="";
}

//---------------------------------------------------------------------------
bool TDMGurRoznDoc::Init(void)
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

IBQ->Database=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMGurRoznDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMGurRoznDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
IBQ->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMGurRoznDoc::OpenTable()
{
Table->Active=false;
AnsiString zapros="select GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER ";
zapros=zapros+" from GALLDOC";
zapros=zapros+" LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM";
zapros=zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD";
zapros=zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
zapros=zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";

zapros=zapros+" where IDBASE_GALLDOC=:PARAM_IDBASE and POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";
//zapros=zapros+" where  POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";
if (StringTypeDoc!="" && OtborVkl==true)
        {
        zapros=zapros+" AND TDOC in ("+StringTypeDoc+" ) ";
        }
else
        {
        zapros=zapros+" AND TDOC in ("+StringFullTypeDoc+" ) ";
        }


//        zapros=zapros+" AND IDFIRMDOC="+IntToStr(IdFirm);


if (IdKlient>0 && OtborVkl==true)
        {
        zapros=zapros+" AND IDKLDOC="+IntToStr(IdKlient);
        }

zapros=zapros+" order by POSDOC";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_IDBASE")->AsInt64=IdBase;
Table->Active=true;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TDMGurRoznDoc::UpdateTable(void)
{
IdDoc=TableIDDOC->AsInt64;
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("IDDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

int TDMGurRoznDoc::FindDocPoIdDog(__int64 iddogovor)
{
int result=0;
IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add("select IDDOC , TDOC from GALLDOC where IDDOGDOC=:PARAM_IDDOG");
IBQ->ParamByName("PARAM_IDDOG")->AsInt64=iddogovor;
IBQ->Active=true;
result=IBQ->RecordCount;
return result;
}
//-----------------------------------------------------------------------




