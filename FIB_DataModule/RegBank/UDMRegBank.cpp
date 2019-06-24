//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMRegBank.h"
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
__fastcall TDMRegBank::TDMRegBank(TComponent* Owner)
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
void __fastcall TDMRegBank::DataModuleCreate(TObject *Sender)
{
//
}
//--------------------------------------------------------------------------
bool TDMRegBank::Init(void)
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
Dv->Database=DM_Connection->pFIBData;
Ostatok->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMRegBank::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMRegBank::DataModuleDestroy(TObject *Sender)
{
Ostatok->Active=false;
Dv->Active=false;
DvRegOst->Active=false;
RegOst->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
int TDMRegBank::GetOstatok(void)
{

int result=0;
Ostatok->Active=false;
String TextZaprosa="";
TextZaprosa="select SUM(SUM_RGBANK) AS SUMOST ";
TextZaprosa=TextZaprosa+" from RGBANK ";
TextZaprosa=TextZaprosa+" where  ";

if (IdBSchet>0)
        {
        TextZaprosa=TextZaprosa+" IDBSCHET_RGBANK='"+IntToStr(IdBSchet)+"' ";
        }
else
        {
        TextZaprosa=TextZaprosa+" IDBSCHET_RGBANK IS NULL ";
        }


TextZaprosa=TextZaprosa+" group by IDBSCHET_RGBANK ";


Ostatok->SelectSQL->Clear();
Ostatok->SelectSQL->Add(TextZaprosa);
Ostatok->Active=true;
result=Ostatok->RecordCount;

return result;

}
//---------------------------------------------------------------------------
bool TDMRegBank::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGBANK_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGBANK_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGBANK_DV->AsInt64=IdFirm;
if(IdBSchet>0) DvRegOstIDBSCHET_RGBANK_DV->AsInt64=IdBSchet;
DvRegOstTDV_RGBANK_DV->AsInteger=0; //поступление
DvRegOstOPER_RGBANK_DV->AsInteger=Operation;

DvRegOstSUM_RGBANK_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegBank::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGBANK_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGBANK_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGBANK_DV->AsInt64=IdFirm;
if(IdBSchet>0) DvRegOstIDBSCHET_RGBANK_DV->AsInt64=IdBSchet;
DvRegOstTDV_RGBANK_DV->AsInteger=1; //списание

DvRegOstOPER_RGBANK_DV->AsInteger=Operation;

DvRegOstSUM_RGBANK_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegBank::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGBANK where";

		if (DvRegOstIDFIRM_RGBANK_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGBANK IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGBANK='"+DvRegOstIDFIRM_RGBANK_DV->AsString+"'";
                }

		if (DvRegOstIDBSCHET_RGBANK_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDBSCHET_RGBANK IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDBSCHET_RGBANK='"+DvRegOstIDBSCHET_RGBANK_DV->AsString+"'";
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
				RegOstIDFIRM_RGBANK->AsInt64=DvRegOstIDFIRM_RGBANK_DV->AsInt64;
				RegOstIDBSCHET_RGBANK->AsInt64=DvRegOstIDBSCHET_RGBANK_DV->AsInt64;

				if(DvRegOstIDFIRM_RGBANK_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGBANK->AsInt64=DvRegOstIDFIRM_RGBANK_DV->AsInt64;
                        }
				if(DvRegOstIDBSCHET_RGBANK_DV->AsInt64!=0)
                        {
						RegOstIDBSCHET_RGBANK->AsInt64=DvRegOstIDBSCHET_RGBANK_DV->AsInt64;
                        }
                }

        if (DvRegOstTDV_RGBANK_DV->AsInteger==0)
                {
                RegOstSUM_RGBANK->AsFloat=RegOstSUM_RGBANK->AsFloat+DvRegOstSUM_RGBANK_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGBANK->AsFloat=RegOstSUM_RGBANK->AsFloat-DvRegOstSUM_RGBANK_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGBANK->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegBank::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGBANK where";
		if (DvRegOstIDFIRM_RGBANK_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGBANK IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGBANK='"+DvRegOstIDFIRM_RGBANK_DV->AsString+"'";
                }

		if (DvRegOstIDBSCHET_RGBANK_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDBSCHET_RGBANK IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDBSCHET_RGBANK='"+DvRegOstIDBSCHET_RGBANK_DV->AsString+"'";
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
				if(DvRegOstIDFIRM_RGBANK_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGBANK->AsInt64=DvRegOstIDFIRM_RGBANK_DV->AsInt64;
                        }
				if(DvRegOstIDBSCHET_RGBANK_DV->AsInt64!=0)
                        {
						RegOstIDBSCHET_RGBANK->AsInt64=DvRegOstIDBSCHET_RGBANK_DV->AsInt64;
                        }
                }

        if (DvRegOstTDV_RGBANK_DV->AsInteger==0)
                {
                RegOstSUM_RGBANK->AsFloat=RegOstSUM_RGBANK->AsFloat-DvRegOstSUM_RGBANK_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGBANK->AsFloat=RegOstSUM_RGBANK->AsFloat+DvRegOstSUM_RGBANK_DV->AsFloat;
                }
        RegOst->Post();

        if (RegOstSUM_RGBANK->AsFloat==0)
                {
                RegOst->Delete();
                }


        DvRegOst->Delete();
        }
        
result=true;
return result;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

bool TDMRegBank::GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_bschet)
{
bool  result=false;
SumOstNa=0;
Ostatok->Active=false;
Ostatok->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Ostatok->ParamByName("PARAM_IDBSCHET")->AsInt64=id_bschet;
Ostatok->Active=true;
SumOstNa=OstatokSUMOST->AsFloat;
//получим приход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Dv->ParamByName("PARAM_IDBSCHET")->AsInt64=id_bschet;
Dv->ParamByName("PARAM_TDV")->AsInteger=0;
Dv->Active=true;
SumOstNa=SumOstNa-DvSUMDV->AsFloat;
//получим расход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Dv->ParamByName("PARAM_IDBSCHET")->AsInt64=id_bschet;
Dv->ParamByName("PARAM_TDV")->AsInteger=1;
Dv->Active=true;
SumOstNa=SumOstNa+DvSUMDV->AsFloat;


result=true;

return result;

}
//------------------------------------------------------------------------------
