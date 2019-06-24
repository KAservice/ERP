//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMRegAdvanceCustomer.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMRegAdvanceCustomer::TDMRegAdvanceCustomer(TComponent* Owner)
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
void __fastcall TDMRegAdvanceCustomer::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMRegAdvanceCustomer::Init(void)
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

DvRegOst->Database=DM_Connection->pFIBData;
RegOst->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMRegAdvanceCustomer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegAdvanceCustomer::DataModuleDestroy(TObject *Sender)
{
RegOst->Active=false;
DvRegOst->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMRegAdvanceCustomer::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGADVCUST_DV->AsInt64=IdDoc;
DvRegOstPOS_RGADVCUST_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGADVCUST_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64=IdKlient;

DvRegOstTDV_RGADVCUST_DV->AsInteger=0; //поступление

DvRegOstSUM_RGADVCUST_DV->AsFloat=Sum;


DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegAdvanceCustomer::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGADVCUST_DV->AsInt64=IdDoc;
DvRegOstPOS_RGADVCUST_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGADVCUST_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64=IdKlient;

DvRegOstTDV_RGADVCUST_DV->AsInteger=1; //списание

DvRegOstSUM_RGADVCUST_DV->AsFloat=Sum;

DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegAdvanceCustomer::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGADVCUST where";
		if (DvRegOstIDFIRM_RGADVCUST_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGADVCUST IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGADVCUST='"+DvRegOstIDFIRM_RGADVCUST_DV->AsString+"'";
                }

		if (DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKLIENT_RGADVCUST IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKLIENT_RGADVCUST='"+DvRegOstIDKLIENT_RGADVCUST_DV->AsString+"'";
                }




        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

        if (RegOst->RecordCount>0)
                {
                RegOst->Edit();
                }
        else
                {
                RegOst->Insert();
				if(DvRegOstIDFIRM_RGADVCUST_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGADVCUST->AsInt64=DvRegOstIDFIRM_RGADVCUST_DV->AsInt64;
                        }
                if(DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64!=0)
                        {
                        RegOstIDKLIENT_RGADVCUST->AsInt64=DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64;
                        }
                }

        if (DvRegOstTDV_RGADVCUST_DV->AsInteger==0)
                {
                RegOstSUM_RGADVCUST->AsFloat=RegOstSUM_RGADVCUST->AsFloat+DvRegOstSUM_RGADVCUST_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGADVCUST->AsFloat=RegOstSUM_RGADVCUST->AsFloat-DvRegOstSUM_RGADVCUST_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGADVCUST->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegAdvanceCustomer::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        String Zapros="";
        Zapros=Zapros+" select * from RGADVCUST where";
		if (DvRegOstIDFIRM_RGADVCUST_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGADVCUST IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGADVCUST='"+DvRegOstIDFIRM_RGADVCUST_DV->AsString+"'";
                }

		if (DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKLIENT_RGADVCUST IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKLIENT_RGADVCUST='"+DvRegOstIDKLIENT_RGADVCUST_DV->AsString+"'";
                }




        RegOst->SelectSQL->Clear();
        RegOst->SelectSQL->Add(Zapros);
        RegOst->Active=true;

        if (RegOst->RecordCount>0)
                {
                RegOst->Edit();
                }
        else
                {
                RegOst->Insert();
				if(DvRegOstIDFIRM_RGADVCUST_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGADVCUST->AsInt64=DvRegOstIDFIRM_RGADVCUST_DV->AsInt64;
                        }
				if(DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64!=0)
                        {
                        RegOstIDKLIENT_RGADVCUST->AsInt64=DvRegOstIDKLIENT_RGADVCUST_DV->AsInt64;
                        }
                }

        if (DvRegOstTDV_RGADVCUST_DV->AsInteger==0)
                {
                RegOstSUM_RGADVCUST->AsFloat=RegOstSUM_RGADVCUST->AsFloat-DvRegOstSUM_RGADVCUST_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGADVCUST->AsFloat=RegOstSUM_RGADVCUST->AsFloat+DvRegOstSUM_RGADVCUST_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGADVCUST->AsFloat==0)
                {
                RegOst->Delete();
                }

        DvRegOst->Delete();
        }

result=true;
return result;
}
//--------------------------------------------------------------------------------
double TDMRegAdvanceCustomer::GetOstatokAdvance(__int64 id_firm,__int64 id_klient)
{
double result=0;

TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add(" select SUM_RGADVCUST from RGADVCUST");
		query->SQL->Add(" where IDFIRM_RGADVCUST="+IntToStr(id_firm));
		query->SQL->Add(" and IDKLIENT_RGADVCUST="+IntToStr(id_klient));
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		result=query->FieldByName("SUM_RGADVCUST")->AsFloat;
		query->Close();
	}
__finally
	{
	delete query;
	}
return result;
}
//----------------------------------------------------------------------------
