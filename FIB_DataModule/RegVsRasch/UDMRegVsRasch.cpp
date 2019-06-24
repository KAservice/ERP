//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMRegVsRasch.h"
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
__fastcall TDMRegVsRasch::TDMRegVsRasch(TComponent* Owner)
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
void __fastcall TDMRegVsRasch::DataModuleCreate(TObject *Sender)
{
//
IdFirm=0;
IdKlient=0;
}
//----------------------------------------------------------------------------
bool TDMRegVsRasch::Init(void)
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
int TDMRegVsRasch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegVsRasch::DataModuleDestroy(TObject *Sender)
{
Ostatok->Active=false;
RegOst->Active=false;
DvRegOst->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
int TDMRegVsRasch::GetOstatok(void)
{
int result=0;
Ostatok->Active=false;
String TextZaprosa="";
TextZaprosa="select SUM(SUM_VSRASCH) AS SUMOST ";
TextZaprosa=TextZaprosa+"from RGVSRASCH ";
TextZaprosa=TextZaprosa+" where  ";

if (IdKlient>0)
        {
        TextZaprosa=TextZaprosa+" IDKLIENT_VSRASCH='"+IntToStr(IdKlient)+"' ";
        }
else
        {
        TextZaprosa=TextZaprosa+" IDKLIENT_VSRASCH IS NULL ";
        }


TextZaprosa=TextZaprosa+" group by IDKLIENT_VSRASCH ";


Ostatok->SelectSQL->Clear();
Ostatok->SelectSQL->Add(TextZaprosa);
Ostatok->Active=true;
result=Ostatok->RecordCount;

return result;

}
//---------------------------------------------------------------------------
bool TDMRegVsRasch::AddRecordPrihod(void)  //увеличение задолженности
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_VSRASCH_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_VSRASCH_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_VSRASCH_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_VSRASCH_DV->AsInt64=IdKlient;

DvRegOstTDV_VSRASCH_DV->AsInteger=0; //поступление

DvRegOstSUM_VSRASCH_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst(true);
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegVsRasch::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_VSRASCH_DV->AsInt64=IdDoc;
DvRegOstPOSDOC_VSRASCH_DV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_VSRASCH_DV->AsInt64=IdFirm;
if(IdKlient>0) DvRegOstIDKLIENT_VSRASCH_DV->AsInt64=IdKlient;
DvRegOstTDV_VSRASCH_DV->AsInteger=1; //списание

DvRegOstSUM_VSRASCH_DV->AsFloat=Sum;
DvRegOst->Post();
UpdateTableOst(true);
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegVsRasch::UpdateTableOst(bool provedenie)
{
bool result=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGVSRASCH where";
		if (DvRegOstIDFIRM_VSRASCH_DV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRM_VSRASCH IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRM_VSRASCH='"+DvRegOstIDFIRM_VSRASCH_DV->AsString+"'";
                }

		if (DvRegOstIDKLIENT_VSRASCH_DV->AsInt64==0)
                {
                Zapros=Zapros+" and IDKLIENT_VSRASCH IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDKLIENT_VSRASCH='"+DvRegOstIDKLIENT_VSRASCH_DV->AsString+"'";
				}
				
		RegOst->Active=false;
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

				if(DvRegOstIDFIRM_VSRASCH_DV->AsInt64!=0)
                        {
						RegOstIDFIRM_VSRASCH->AsInt64=DvRegOstIDFIRM_VSRASCH_DV->AsInt64;
                        }

				if(DvRegOstIDKLIENT_VSRASCH_DV->AsInt64!=0)
                        {
						RegOstIDKLIENT_VSRASCH->AsInt64=DvRegOstIDKLIENT_VSRASCH_DV->AsInt64;
                        }
                }


        if (provedenie==true)
                {  //проведение
                if (DvRegOstTDV_VSRASCH_DV->AsInteger==0)
                        {
                        RegOstSUM_VSRASCH->AsFloat=RegOstSUM_VSRASCH->AsFloat+DvRegOstSUM_VSRASCH_DV->AsFloat;
                        }
                else
                        {
                        RegOstSUM_VSRASCH->AsFloat=RegOstSUM_VSRASCH->AsFloat-DvRegOstSUM_VSRASCH_DV->AsFloat;
                        }
                }
        else      //отмена проведения
                {
                if (DvRegOstTDV_VSRASCH_DV->AsInteger==0)
                        {
                        RegOstSUM_VSRASCH->AsFloat=RegOstSUM_VSRASCH->AsFloat-DvRegOstSUM_VSRASCH_DV->AsFloat;
                        }
                else
                        {
                        RegOstSUM_VSRASCH->AsFloat=RegOstSUM_VSRASCH->AsFloat+DvRegOstSUM_VSRASCH_DV->AsFloat;
                        }
                }

        RegOst->Post();

        if (RegOstSUM_VSRASCH->AsFloat==0)
                {
                RegOst->Delete();
                }


result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegVsRasch::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;

DvRegOst->First();
while (!DvRegOst->Eof)
        {
        UpdateTableOst(false);
        DvRegOst->Delete();
        }
        
result=true;
return result;        
}
//----------------------------------------------------------------------------------

bool TDMRegVsRasch::GetOstatokNa(TDateTime Pos,__int64 idFirm, __int64 idKlient)
{
bool  result=false;
SumOstNa=0;
Ostatok->Active=false;
Ostatok->ParamByName("PARAM_IDKLIENT")->AsInt64=idKlient;
Ostatok->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
Ostatok->Active=true;
SumOstNa=OstatokSUMOST->AsFloat;
//ShowMessage ( "Остаток"+FloatToStr( SumOstNa));
//получим приход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDKLIENT")->AsInt64=idKlient;
Dv->ParamByName("PARAM_TDV")->AsInteger=0;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
Dv->Active=true;
SumOstNa=SumOstNa-DvSUMDV->AsFloat;
//ShowMessage ( "Приход"+FloatToStr( DvSUMDV->AsFloat));
//получим расход
Dv->Active=false;
Dv->ParamByName("PARAM_POS")->AsDateTime=Pos;
Dv->ParamByName("PARAM_IDKLIENT")->AsInt64=idKlient;
Dv->ParamByName("PARAM_TDV")->AsInteger=1;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
Dv->Active=true;
SumOstNa=SumOstNa+DvSUMDV->AsFloat;
//ShowMessage ( "Расход"+FloatToStr( DvSUMDV->AsFloat));
result=true;

return result;

}
//------------------------------------------------------------------------------
