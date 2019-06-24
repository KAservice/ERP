//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurLog.h"
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
__fastcall TDMGurLog::TDMGurLog(TComponent* Owner)
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

void __fastcall TDMGurLog::DataModuleCreate(TObject *Sender)
{
OtborVkl=false;
OtborPoUser=false;
OtborPoType=false;
OtborPoObject=false;
OtborPoOper=false;

}
//---------------------------------------------------------------------------
bool TDMGurLog::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;

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
int TDMGurLog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMGurLog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
pFIBQ->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMGurLog::OpenTable()
{
Table->Active=false;
AnsiString zapros="select LOG.*,  NAME_USER ";
zapros=zapros+" from LOG";
zapros=zapros+" left outer join SUSER on  IDUSER_LOG= ID_USER";
zapros=zapros+" where POS_LOG between  :PARAM_DATE_NACH and :PARAM_DATE_CON";

if (IdUser>0 && OtborVkl==true)
        {
		zapros=zapros+" AND IDUSER_LOG="+IntToStr(IdUser);
        }

if (Type>0 && OtborVkl==true)
        {
		zapros=zapros+" AND TYPE_LOG="+IntToStr(Type);
        }

if (ObjectLog>0 && OtborVkl==true)
		{
		zapros=zapros+" AND (OBJECT_LOG="+IntToStr(ObjectLog);
		}

if (Oper>0 && OtborVkl==true)
		{
		zapros=zapros+" AND (OPER_LOG="+IntToStr(Oper);
		}

zapros=zapros+" order by POS_LOG";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon; 
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurLog::UpdateTable(void)
{
__int64 id_rec=TableID_LOG->AsInt64;
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_LOG",IntToStr(id_rec),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

