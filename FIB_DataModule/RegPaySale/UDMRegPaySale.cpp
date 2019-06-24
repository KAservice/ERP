//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMRegPaySale.h"
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
__fastcall TDMRegPaySale::TDMRegPaySale(TComponent* Owner)
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
void __fastcall TDMRegPaySale::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMRegPaySale::Init(void)
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
int TDMRegPaySale::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegPaySale::DataModuleDestroy(TObject *Sender)
{
RegOst->Active=false;
DvRegOst->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
bool TDMRegPaySale::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGPAYSALE_DV->AsInt64=IdDoc;
DvRegOstPOS_RGPAYSALE_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64=IdKlient;
if (IdDogovor>0) DvRegOstIDDOG_RGPAYSALE_DV->AsInt64=IdDogovor;
if (IdDocSale) DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64=IdDocSale;
DvRegOstDATE_RGPAYSALE_DV->AsDateTime=DatePay;
DvRegOstTDV_RGPAYSALE_DV->AsInteger=0; //поступление

DvRegOstSUM_RGPAYSALE_DV->AsFloat=Sum;

DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegPaySale::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGPAYSALE_DV->AsInt64=IdDoc;
DvRegOstPOS_RGPAYSALE_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64=IdKlient;
if (IdDogovor>0) DvRegOstIDDOG_RGPAYSALE_DV->AsInt64=IdDogovor;
if (IdDocSale) DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64=IdDocSale;
DvRegOstDATE_RGPAYSALE_DV->AsDateTime=DatePay;
DvRegOstTDV_RGPAYSALE_DV->AsInteger=1; //списание

DvRegOstSUM_RGPAYSALE_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegPaySale::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGPAYSALE where";
		if (DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGPAYSALE='"+DvRegOstIDFIRM_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKLIENT_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKLIENT_RGPAYSALE='"+DvRegOstIDKLIENT_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDDOG_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDDOG_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDDOG_RGPAYSALE='"+DvRegOstIDDOG_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDDOCSALE_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDDOCSALE_RGPAYSALE='"+DvRegOstIDDOCSALE_RGPAYSALE_DV->AsString+"'";
                }


        Zapros=Zapros+" and DATE_RGPAYSALE='"+DvRegOstDATE_RGPAYSALE_DV->AsString+"'";






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
				if(DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGPAYSALE->AsInt64=DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDKLIENT_RGPAYSALE->AsInt64=DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDDOG_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDDOG_RGPAYSALE->AsInt64=DvRegOstIDDOG_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDDOCSALE_RGPAYSALE->AsInt64=DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64;
                        }

                RegOstDATE_RGPAYSALE->AsDateTime=DvRegOstDATE_RGPAYSALE_DV->AsDateTime;

                }

		if (DvRegOstTDV_RGPAYSALE_DV->AsInteger==0)
                {
                RegOstSUM_RGPAYSALE->AsFloat=RegOstSUM_RGPAYSALE->AsFloat+DvRegOstSUM_RGPAYSALE_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGPAYSALE->AsFloat=RegOstSUM_RGPAYSALE->AsFloat-DvRegOstSUM_RGPAYSALE_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGPAYSALE->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegPaySale::CancelDvReg(void)
{
bool result=false;
        RegOst->Active=false;
		DvRegOst->ParamByName("IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        RegOst->Active=false;
        String Zapros="";
        Zapros=Zapros+" select * from RGPAYSALE where";
		if (DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGPAYSALE='"+DvRegOstIDFIRM_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKLIENT_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKLIENT_RGPAYSALE='"+DvRegOstIDKLIENT_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDDOG_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDDOG_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDDOG_RGPAYSALE='"+DvRegOstIDDOG_RGPAYSALE_DV->AsString+"'";
                }

		if (DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDDOCSALE_RGPAYSALE IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDDOCSALE_RGPAYSALE='"+DvRegOstIDDOCSALE_RGPAYSALE_DV->AsString+"'";
                }


                Zapros=Zapros+" and DATE_RGPAYSALE='"+DvRegOstDATE_RGPAYSALE_DV->AsString+"'";


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
				if(DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGPAYSALE->AsInt64=DvRegOstIDFIRM_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDKLIENT_RGPAYSALE->AsInt64=DvRegOstIDKLIENT_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDDOG_RGPAYSALE_DV->AsInt64!=0)
                        {
						RegOstIDDOG_RGPAYSALE->AsInt64=DvRegOstIDDOG_RGPAYSALE_DV->AsInt64;
                        }
				if(DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64!=0)
                        {
                        RegOstIDDOCSALE_RGPAYSALE->AsInt64=DvRegOstIDDOCSALE_RGPAYSALE_DV->AsInt64;
                        }

                RegOstDATE_RGPAYSALE->AsDateTime=DvRegOstDATE_RGPAYSALE_DV->AsDateTime;

                }

        if (DvRegOstTDV_RGPAYSALE_DV->AsInteger==0)
                {
                RegOstSUM_RGPAYSALE->AsFloat=RegOstSUM_RGPAYSALE->AsFloat-DvRegOstSUM_RGPAYSALE_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGPAYSALE->AsFloat=RegOstSUM_RGPAYSALE->AsFloat+DvRegOstSUM_RGPAYSALE_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGPAYSALE->AsFloat==0)
                {
                RegOst->Delete();
                }
                
        DvRegOst->Delete();
        }


result=true;
return result;
}
//----------------------------------------------------------------------------------

