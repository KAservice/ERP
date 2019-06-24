//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprBVNom.h"
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
__fastcall TDMSprBVNom::TDMSprBVNom(TComponent* Owner)
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
bool TDMSprBVNom::Init(void)
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
Element->Database=DM_Connection->pFIBData;
Podr->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprBVNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprBVNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Podr->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprBVNom::OpenTable(__int64 Pod, __int64 Grp, bool All)
{
NumberAddElement=0;
IdPod=Pod;
IdGrp=Grp;
AllElement=All;
Podr->Active=false;
Podr->ParamByName("PARAM_IDPOD")->AsInt64=IdPod;
Podr->Active=true;
IdTypePrice=PodrIDTPRICEPOD->AsInt64;

Table->Active=false;
Table->SelectSQL->Clear();
if(All==true)
        {
        Table->SelectSQL->Add("select SBVNOM.*,  NAMENOM, ZNACH_PRICE, NAMEED");
        Table->SelectSQL->Add(" from SBVNOM left outer join SNOM on IDNOM_BVNOM=IDNOM ");
        Table->SelectSQL->Add("left outer join SPRICE on IDNOM_PRICE=IDNOM_BVNOM");
		Table->SelectSQL->Add(" AND IDTYPE_PRICE=:PARAM_IDTYPE_PRICE");
		Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
        Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
        Table->SelectSQL->Add("where IDPOD_BVNOM="+IntToStr(IdPod));
        Table->SelectSQL->Add("ORDER BY NAMENOM");
        }
else
        {
        if (IdGrp==0)
                {
                Table->SelectSQL->Add("select SBVNOM.*,  NAMENOM, ZNACH_PRICE, NAMEED");
                Table->SelectSQL->Add(" from SBVNOM left outer join SNOM on IDNOM_BVNOM=IDNOM");
                Table->SelectSQL->Add("left outer join SPRICE on IDNOM_PRICE=IDNOM_BVNOM");
				Table->SelectSQL->Add(" AND IDTYPE_PRICE=:PARAM_IDTYPE_PRICE");
				Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
                Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
                Table->SelectSQL->Add("where IDPOD_BVNOM="+IntToStr(IdPod));
                Table->SelectSQL->Add("AND IDGRP_BVNOM IS NULL");
                Table->SelectSQL->Add("ORDER BY NAMENOM");
                }
        else
                {
                Table->SelectSQL->Add("select SBVNOM.*,  NAMENOM, ZNACH_PRICE, NAMEED");
                Table->SelectSQL->Add(" from SBVNOM left outer join SNOM on IDNOM_BVNOM=IDNOM");
                Table->SelectSQL->Add("left outer join SPRICE on IDNOM_PRICE=IDNOM_BVNOM");
				Table->SelectSQL->Add(" AND IDTYPE_PRICE=:PARAM_IDTYPE_PRICE");
				Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
                Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
                Table->SelectSQL->Add("where IDPOD_BVNOM="+IntToStr(IdPod));
                Table->SelectSQL->Add("AND IDGRP_BVNOM="+IntToStr(IdGrp));
                Table->SelectSQL->Add("ORDER BY NAMENOM");
                }
        }
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=IdTypePrice;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprBVNom::NewElement(__int64 Pod, __int64 Grp)
{
IdPod=Pod;
IdGrp=Grp;
Table->Append();
}
//---------------------------------------------------------------------------
void TDMSprBVNom::InsertElement(__int64 Pod, __int64 Grp, __int64 id_nom)
{

try
        {
        IdPod=Pod;
        IdGrp=Grp;
        Table->Active=true;
        Table->Insert();
		TableIDNOM_BVNOM->AsInt64=id_nom;
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        Table->Active=false;
        }
catch(Exception &exception)
		{
		Table->CancelUpdates();
		IBTrUpdate->Rollback();
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------
void  TDMSprBVNom::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable(IdPod,IdGrp,AllElement);
        }
catch(Exception &exception)
        {
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprBVNom::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
	   // IBTrUpdate->Commit();
        OpenTable(IdPod,IdGrp,AllElement);
        }
catch(Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		}
}
//---------------------------------------------------------------------------
void TDMSprBVNom::DeleteElement()
{
Table->Delete();
}
//----------------------------------------------------------------------------
void TDMSprBVNom::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_BVNOM->AsInt64=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(IdPod,IdGrp,AllElement);
}
//----------------------------------------------------------------------------

int TDMSprBVNom::FindPoCoduBV(int codeBV)
{
IdNomBV=0;
int Res=0;

TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select IDNOM_BVNOM from SBVNOM where IDPOD_BVNOM=:PARAM_IDPOD_BVNOM");
		query->SQL->Add(" and CODE_BVNOM=:PARAM_CODE_BVNOM");
		query->ParamByName("PARAM_CODE_BVNOM")->AsInt64=codeBV;
		query->ParamByName("PARAM_IDPOD_BVNOM")->AsInt64=IdPod;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		IdNomBV=query->FieldByName("IDNOM_BVNOM")->AsInt64;
		Res=query->RecordCount;
	}
__finally
	{
	delete query;
	}

return Res;

}
//----------------------------------------------------------------------------
bool TDMSprBVNom::OpenElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        result=true;
        }
return result;
}
//----------------------------------------------------------------------------
bool TDMSprBVNom::FindPoPodrAndNom(__int64 id_podr, __int64 id_nom)
{
bool result=false;

TpFIBQuery * query=new TpFIBQuery(0);
try {  
		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select ID_BVNOM from SBVNOM where IDPOD_BVNOM=:PARAM_IDPOD");
		query->SQL->Add(" and IDNOM_BVNOM=:PARAM_IDNOM");
		query->ParamByName("PARAM_IDPOD")->AsInt64=id_podr;
		query->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		if(OpenElement(query->FieldByName("ID_BVNOM")->AsInt64)==true)
			{
			result=true;
			}
	}
__finally
	{
	delete query;
	}
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TDMSprBVNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;   	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprBVNom::TableNewRecord(TDataSet *DataSet)
{
TableIDPOD_BVNOM->AsInt64=IdPod;
TableIDGRP_BVNOM->AsInt64=IdGrp;

TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select max (CODE_BVNOM)  AS MAXCODE from SBVNOM where IDPOD_BVNOM=:PARAM_IDPOD_BVNOM");
		query->ParamByName("PARAM_IDPOD_BVNOM")->AsInt64=IdPod;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		TableCODE_BVNOM->AsInteger=query->FieldByName("MAXCODE")->AsInteger+1+NumberAddElement;
	}
__finally
	{
	delete query;
	}
NumberAddElement++;


}
//---------------------------------------------------------------------------

