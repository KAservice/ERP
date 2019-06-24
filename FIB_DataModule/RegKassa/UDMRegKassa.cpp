//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMRegKassa.h"
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
__fastcall TDMRegKassa::TDMRegKassa(TComponent* Owner)
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
void __fastcall TDMRegKassa::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMRegKassa::Init(void)
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
int TDMRegKassa::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegKassa::DataModuleDestroy(TObject *Sender)
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
int TDMRegKassa::GetOstatok(void)
{

int result=0;
Ostatok->Active=false;
String TextZaprosa="";
TextZaprosa="select  SUM(SUM_RGKASSA)  AS SUMOST ";
TextZaprosa=TextZaprosa+"from RGKASSA ";
TextZaprosa=TextZaprosa+" where  ";

if (IdKKM>0)
        {
        TextZaprosa=TextZaprosa+" IDKKM_RGKASSA=='"+IntToStr(IdKKM)+"' ";
        }
else
        {
        TextZaprosa=TextZaprosa+" IDKKM_RGKASSA= IS NULL ";
        }

TextZaprosa=TextZaprosa+" group by IDKKM_RGKASSA ";


Ostatok->SelectSQL->Clear();
Ostatok->SelectSQL->Add(TextZaprosa);
Ostatok->Active=true;
result=Ostatok->RecordCount;

return result;

}
//---------------------------------------------------------------------------
bool TDMRegKassa::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGKASSA_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGKASSA_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGKASSA_DV->AsInt64=IdFirm;
if(IdKKM>0) DvRegOstIDKKM_RGKASSA_DV->AsInt64=IdKKM;
DvRegOstTDV_RGKASSA_DV->AsInteger=0; //поступление
DvRegOstSUM_RGKASSA_DV->AsFloat=Sum;
DvRegOstOPER_RGKASSA_DV->AsInteger=Operation;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegKassa::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_RGKASSA_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_RGKASSA_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_RGKASSA_DV->AsInt64=IdFirm;
if(IdKKM>0) DvRegOstIDKKM_RGKASSA_DV->AsInt64=IdKKM;
DvRegOstTDV_RGKASSA_DV->AsInteger=1; //списание
DvRegOstOPER_RGKASSA_DV->AsInteger=Operation;

DvRegOstSUM_RGKASSA_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegKassa::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGKASSA where";
		if (DvRegOstIDFIRM_RGKASSA_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGKASSA IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGKASSA='"+DvRegOstIDFIRM_RGKASSA_DV->AsString+"'";
                }

		if (DvRegOstIDKKM_RGKASSA_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKKM_RGKASSA IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKKM_RGKASSA='"+DvRegOstIDKKM_RGKASSA_DV->AsString+"'";
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
				if(DvRegOstIDFIRM_RGKASSA_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGKASSA->AsInt64=DvRegOstIDFIRM_RGKASSA_DV->AsInt64;
                        }
				if(DvRegOstIDKKM_RGKASSA_DV->AsInt64!=0)
                        {
						RegOstIDKKM_RGKASSA->AsInt64=DvRegOstIDKKM_RGKASSA_DV->AsInt64;
                        }
                }

		if (DvRegOstTDV_RGKASSA_DV->AsInteger==0)
                {
                RegOstSUM_RGKASSA->AsFloat=RegOstSUM_RGKASSA->AsFloat+DvRegOstSUM_RGKASSA_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGKASSA->AsFloat=RegOstSUM_RGKASSA->AsFloat-DvRegOstSUM_RGKASSA_DV->AsFloat;
                }

        RegOst->Post();

        if (RegOstSUM_RGKASSA->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegKassa::CancelDvReg(void)
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
        Zapros=Zapros+" select * from RGKASSA where";
		if (DvRegOstIDFIRM_RGKASSA_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_RGKASSA IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_RGKASSA='"+DvRegOstIDFIRM_RGKASSA_DV->AsString+"'";
                }

        if (DvRegOstIDKKM_RGKASSA_DV->AsInteger==0)
                {
                Zapros=Zapros+" and IDKKM_RGKASSA IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKKM_RGKASSA='"+DvRegOstIDKKM_RGKASSA_DV->AsString+"'";
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
				if(DvRegOstIDFIRM_RGKASSA_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_RGKASSA->AsInt64=DvRegOstIDFIRM_RGKASSA_DV->AsInt64;
                        }
				if(DvRegOstIDKKM_RGKASSA_DV->AsInt64!=0)
                        {
						RegOstIDKKM_RGKASSA->AsInt64=DvRegOstIDKKM_RGKASSA_DV->AsInt64;
                        }
                }

        if (DvRegOstTDV_RGKASSA_DV->AsInteger==0)
                {
                RegOstSUM_RGKASSA->AsFloat=RegOstSUM_RGKASSA->AsFloat-DvRegOstSUM_RGKASSA_DV->AsFloat;
                }
        else
                {
                RegOstSUM_RGKASSA->AsFloat=RegOstSUM_RGKASSA->AsFloat+DvRegOstSUM_RGKASSA_DV->AsFloat;
                }
        RegOst->Post();

        if (RegOstSUM_RGKASSA->AsFloat==0)
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

bool TDMRegKassa::GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa)
{
bool  result=false;
SumOstNa=0;
Ostatok->Active=false;
Ostatok->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Ostatok->ParamByName("PARAM_IDKASSA")->AsInt64=id_kassa;
Ostatok->Active=true;
SumOstNa=OstatokSUMOST->AsFloat;
//получим приход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Dv->ParamByName("PARAM_IDKASSA")->AsInt64=id_kassa;
Dv->ParamByName("PARAM_TDV")->AsInteger=0;
Dv->Active=true;
SumOstNa=SumOstNa-DvSUMDV->AsFloat;
//получим расход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
Dv->ParamByName("PARAM_IDKASSA")->AsInt64=id_kassa;
Dv->ParamByName("PARAM_TDV")->AsInteger=1;
Dv->Active=true;
SumOstNa=SumOstNa+DvSUMDV->AsFloat;


result=true;

return result;

}
//------------------------------------------------------------------------------
