//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMRegOstNom.h"
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
__fastcall TDMRegOstNom::TDMRegOstNom(TComponent* Owner)
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
void __fastcall TDMRegOstNom::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMRegOstNom::Init(void)
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
DvNom->Database=DM_Connection->pFIBData;
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
int TDMRegOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMRegOstNom::DataModuleDestroy(TObject *Sender)
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
int TDMRegOstNom::GetOstatok(void)
{
int result=0;
Ostatok->Active=false;
String TextZaprosa="";
TextZaprosa="select SUM(KOLOSTNOM) AS KOLOST, SUM(SUMOSTNOM) AS SUMOST ";
TextZaprosa=TextZaprosa+"from RGOSTNOM ";
TextZaprosa=TextZaprosa+" where  ";

if (IdFirm>0)
        {
		TextZaprosa=TextZaprosa+" IDFIRMOSTNOM='"+IntToStr(IdFirm)+"' ";
        }
else
        {
		TextZaprosa=TextZaprosa+" IDFIRMOSTNOM IS NULL ";
		}

if (IdSklad>0)
        {
		TextZaprosa=TextZaprosa+" and IDSKLOSTNOM='"+IntToStr(IdSklad)+"' ";
        }
else
        {
        TextZaprosa=TextZaprosa+" and IDSKLOSTNOM IS NULL ";
        }

if (IdNom>0)
        {
        TextZaprosa=TextZaprosa+" and IDNOMOSTNOM='"+IntToStr(IdNom)+"' ";
        }
else
        {
        TextZaprosa=TextZaprosa+" and IDNOMOSTNOM IS NULL ";
        }

TextZaprosa=TextZaprosa+" group by IDNOMOSTNOM ";


Ostatok->SelectSQL->Clear();
Ostatok->SelectSQL->Add(TextZaprosa);
Ostatok->Active=true;
result=Ostatok->RecordCount;
KolOst=OstatokKOLOST->AsFloat;
return result;

}
//---------------------------------------------------------------------------
bool TDMRegOstNom::AddRecordPrihod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_OSTNOMDV->AsInt64=IdDoc;
DvRegOstPOSDOC_OSTNOMDV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_OSTNOMDV->AsInt64=IdFirm;
if(IdSklad>0) DvRegOstIDSKL_OSTNOMDV->AsInt64=IdSklad;
if (IdNom>0) DvRegOstIDNOM_OSTNOMDV->AsInt64=IdNom;
if (IdPart) DvRegOstIDPART_OSTNOMDV->AsInt64=IdPart;
DvRegOstTDV_OSTNOMDV->AsInteger=0; //поступление
DvRegOstIDSTRDOC_OSTNOMDV->AsInt64=IdStr;

DvRegOstSUM_OSTNOMDV->AsFloat=Sum;
DvRegOstKOL_OSTNOMDV->AsFloat=Kol;
DvRegOstOPER_OSTNOMDV->AsInteger=Operation;
DvRegOstSUM2_OSTNOMDV->AsFloat=Sum2;

DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//---------------------------------------------------------------------------
bool TDMRegOstNom::AddRecordRashod(void)
{
bool result=false;
DvRegOst->Active=true;
DvRegOst->Insert();
DvRegOstIDDOC_OSTNOMDV->AsInt64=IdDoc;
DvRegOstPOSDOC_OSTNOMDV->AsDateTime=PosDoc;
if(IdFirm>0) DvRegOstIDFIRM_OSTNOMDV->AsInt64=IdFirm;
if(IdSklad>0) DvRegOstIDSKL_OSTNOMDV->AsInt64=IdSklad;
if (IdNom>0) DvRegOstIDNOM_OSTNOMDV->AsInt64=IdNom;
if (IdPart) DvRegOstIDPART_OSTNOMDV->AsInt64=IdPart;
DvRegOstTDV_OSTNOMDV->AsInteger=1; //списание
DvRegOstIDSTRDOC_OSTNOMDV->AsInt64=IdStr;

DvRegOstSUM_OSTNOMDV->AsFloat=Sum;
DvRegOstKOL_OSTNOMDV->AsFloat=Kol;
DvRegOstOPER_OSTNOMDV->AsInteger=Operation;
DvRegOstSUM2_OSTNOMDV->AsFloat=Sum2;
DvRegOst->Post();
UpdateTableOst();
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMRegOstNom::UpdateTableOst(void)
{
bool result=false;
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGOSTNOM where";
		if (DvRegOstIDFIRM_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRMOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRMOSTNOM='"+DvRegOstIDFIRM_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDSKL_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDSKLOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDSKLOSTNOM='"+DvRegOstIDSKL_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDNOM_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDNOMOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDNOMOSTNOM='"+DvRegOstIDNOM_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDPART_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDPARTOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDPARTOSTNOM='"+DvRegOstIDPART_OSTNOMDV->AsString+"'";
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
				if(DvRegOstIDFIRM_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDFIRMOSTNOM->AsInt64=DvRegOstIDFIRM_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDSKL_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDSKLOSTNOM->AsInt64=DvRegOstIDSKL_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDNOM_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDNOMOSTNOM->AsInt64=DvRegOstIDNOM_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDPART_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDPARTOSTNOM->AsInt64=DvRegOstIDPART_OSTNOMDV->AsInt64;
                        }
                }

        if (DvRegOstTDV_OSTNOMDV->AsInteger==0)
                {
                RegOstKOLOSTNOM->AsFloat=RegOstKOLOSTNOM->AsFloat+DvRegOstKOL_OSTNOMDV->AsFloat;
                RegOstSUMOSTNOM->AsFloat=RegOstSUMOSTNOM->AsFloat+DvRegOstSUM_OSTNOMDV->AsFloat;
                }
        else
                {
                RegOstKOLOSTNOM->AsFloat=RegOstKOLOSTNOM->AsFloat-DvRegOstKOL_OSTNOMDV->AsFloat;
                RegOstSUMOSTNOM->AsFloat=RegOstSUMOSTNOM->AsFloat-DvRegOstSUM_OSTNOMDV->AsFloat;
                }

        RegOst->Post();

        if (RegOstKOLOSTNOM->AsFloat==0 && RegOstSUMOSTNOM->AsFloat==0)
                {
                RegOst->Delete();
                }



result=true;
return result;

}
//----------------------------------------------------------------------------
bool TDMRegOstNom::CancelDvReg(void)
{
bool result=false;
        DvRegOst->Active=false;
		DvRegOst->ParamByName("IDDOC")->AsInt64=IdDoc;
        DvRegOst->Active=true;
        DvRegOst->First();

while (!DvRegOst->Eof)
        {
        RegOst->Active=false;

        String Zapros="";
        Zapros=Zapros+" select * from RGOSTNOM where";
		if (DvRegOstIDFIRM_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" IDFIRMOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" IDFIRMOSTNOM='"+DvRegOstIDFIRM_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDSKL_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDSKLOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDSKLOSTNOM='"+DvRegOstIDSKL_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDNOM_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDNOMOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDNOMOSTNOM='"+DvRegOstIDNOM_OSTNOMDV->AsString+"'";
                }

		if (DvRegOstIDPART_OSTNOMDV->AsInt64==0)
                {
                Zapros=Zapros+" and IDPARTOSTNOM IS NULL";
                }
        else
                {
                Zapros=Zapros+" and IDPARTOSTNOM='"+DvRegOstIDPART_OSTNOMDV->AsString+"'";
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
				if(DvRegOstIDFIRM_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDFIRMOSTNOM->AsInt64=DvRegOstIDFIRM_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDSKL_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDSKLOSTNOM->AsInt64=DvRegOstIDSKL_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDNOM_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDNOMOSTNOM->AsInt64=DvRegOstIDNOM_OSTNOMDV->AsInt64;
                        }
				if(DvRegOstIDPART_OSTNOMDV->AsInt64!=0)
                        {
						RegOstIDPARTOSTNOM->AsInt64=DvRegOstIDPART_OSTNOMDV->AsInt64;
                        }
                }

		if (DvRegOstTDV_OSTNOMDV->AsInteger==0)
                {
                RegOstKOLOSTNOM->AsFloat=RegOstKOLOSTNOM->AsFloat-DvRegOstKOL_OSTNOMDV->AsFloat;
                RegOstSUMOSTNOM->AsFloat=RegOstSUMOSTNOM->AsFloat-DvRegOstSUM_OSTNOMDV->AsFloat;
                }
        else
                {
                RegOstKOLOSTNOM->AsFloat=RegOstKOLOSTNOM->AsFloat+DvRegOstKOL_OSTNOMDV->AsFloat;
                RegOstSUMOSTNOM->AsFloat=RegOstSUMOSTNOM->AsFloat+DvRegOstSUM_OSTNOMDV->AsFloat;
                }
        RegOst->Post();

        if (RegOstKOLOSTNOM->AsFloat==0 && RegOstSUMOSTNOM->AsFloat==0)
                {
                RegOst->Delete();
                }


        DvRegOst->Delete();
        }
        
result=true;
return result;
}
//----------------------------------------------------------------------------------

bool TDMRegOstNom::GetOstatokNa(TDateTime Pos, __int64 idFirm, __int64 idSklad, __int64 idNom)
{
bool  result=false;
SumOstNa=0;
KolOstNa=0;
Ostatok->Active=false;
Ostatok->ParamByName("PARAM_IDNOM")->AsInt64=idNom;
Ostatok->ParamByName("PARAM_IDSKLAD")->AsInt64=idSklad;
Ostatok->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
Ostatok->Active=true;
SumOstNa=OstatokSUMOST->AsFloat;
KolOstNa=OstatokKOLOST->AsFloat;
//получим приход
DvNom->Active=false;
DvNom->ParamByName("PARAM_POS")->AsDateTime=Pos;
DvNom->ParamByName("PARAM_IDNOM")->AsInt64=idNom;
DvNom->ParamByName("PARAM_IDSKLAD")->AsInt64=idSklad;
DvNom->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
DvNom->ParamByName("PARAM_TDV")->AsInteger=0;
DvNom->Active=true;
SumOstNa=SumOstNa-DvNomSUMDV->AsFloat;
KolOstNa=KolOstNa-DvNomKOLDV->AsFloat;
//получим расход
DvNom->Active=false;
DvNom->ParamByName("PARAM_POS")->AsDateTime=Pos;
DvNom->ParamByName("PARAM_IDNOM")->AsInt64=idNom;
DvNom->ParamByName("PARAM_IDSKLAD")->AsInt64=idSklad;
DvNom->ParamByName("PARAM_IDFIRM")->AsInt64=idFirm;
DvNom->ParamByName("PARAM_TDV")->AsInteger=1;
DvNom->Active=true;
SumOstNa=SumOstNa+DvNomSUMDV->AsFloat;
KolOstNa=KolOstNa+DvNomKOLDV->AsFloat;

result=true;

return result;

}
//------------------------------------------------------------------------------
