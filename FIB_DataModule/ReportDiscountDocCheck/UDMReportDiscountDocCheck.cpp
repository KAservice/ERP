//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMReportDiscountDocCheck.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMReportDiscountDocCheck::TDMReportDiscountDocCheck(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMReportDiscountDocCheck::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDMReportDiscountDocCheck::Init(void)
{
bool result=false;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;



InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DM);
DM->Init(InterfaceMainObject,0);
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,0);

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMReportDiscountDocCheck::DataModuleDestroy(TObject *Sender)
{
DMDoc->kanRelease();
DM->kanRelease();
}
//----------------------------------------------------------------------------
AnsiString TDMReportDiscountDocCheck::GetTextQuery(__int64 id_firm, __int64 id_sklad,
											__int64 id_grp, __int64 id_nom,
											bool only_type, int type_nom)
{
AnsiString zapros=" select";
zapros=zapros+" sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" snom.namenom, snom.tnom, snom.idnom,";
zapros=zapros+" sed.nameed,";
zapros=zapros+" sum(dchkt.kolchkt * dchkt.kfchkt) as SUMKOL,";
zapros=zapros+" sum(dchkt.sumchkt) as SUMREAL,";
zapros=zapros+" sum(dchkt.skchkt) as SUMSK";
zapros=zapros+" from dchkt";
zapros=zapros+" left outer join galldoc on dchkt.iddocchkt=galldoc.iddoc";
zapros=zapros+" left outer join dchk on  dchk.iddocchk=dchkt.iddocchkt         ";
zapros=zapros+" left outer join sfirm on galldoc.idfirmdoc=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on galldoc.idskldoc=ssklad.idsklad";
zapros=zapros+" left outer join snom on dchkt.idnomchkt=snom.idnom";
zapros=zapros+" left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn";
zapros=zapros+" left outer join sed on snom.idbasednom=sed.ided";
zapros=zapros+" where dchkt.skchkt!=0 and dchk.operchk=0  ";
zapros=zapros+" and galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON";
		if (id_firm!=0)
                {
				zapros=zapros+" and  sfirm.idfirm="+IntToStr(id_firm);
                }

		if (id_sklad!=0)
                {
				zapros=zapros+" and  ssklad.idsklad="+IntToStr(id_sklad);
                }

		if (id_grp!=0)
                {
				zapros=zapros+" and  sgrpnom.idgn="+IntToStr(id_grp);;
                }

		if (id_nom!=0)
                {
				zapros=zapros+" and  dchkt.idnomchkt="+IntToStr(id_nom);
                }

		if (only_type==true)
                {
				zapros=zapros+" and  snom.tnom="+IntToStr(type_nom);
                }

zapros=zapros+" group by ";
zapros=zapros+" sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" snom.namenom,snom.tnom,snom.idnom,";
zapros=zapros+" sed.nameed";
return zapros;
}

//---------------------------------------------------------------------------
void TDMReportDiscountDocCheck::OpenReport(TDateTime pos_nach, TDateTime pos_con,
											__int64 id_firm, __int64 id_sklad,
											__int64 id_grp, __int64 id_nom,
											bool only_type, int type_nom)
{
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add(GetTextQuery(id_firm,  id_sklad,
											 id_grp,  id_nom,
											 only_type, type_nom));
DM->pFIBQ->Params->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
DM->pFIBQ->Params->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
DM->pFIBQ->ExecQuery();
}
//-----------------------------------------------------------------------
AnsiString TDMReportDiscountDocCheck::GetTextZaprosDoc(__int64 id_firm,
													__int64 id_sklad,
													__int64 id_nom)
{
AnsiString zapros=" select";
zapros=zapros+" galldoc.posdoc,galldoc.iddoc, galldoc.tdoc, galldoc.numdoc, ";
zapros=zapros+" snom.namenom, snom.tnom,";
zapros=zapros+" sed.nameed,";
zapros=zapros+" sum(dchkt.kolchkt * dchkt.kfchkt) as SUMKOL,";
zapros=zapros+" sum(dchkt.sumchkt) as SUMREAL,";
zapros=zapros+" sum(dchkt.skchkt) as SUMSK";
zapros=zapros+" from dchkt";
zapros=zapros+" left outer join galldoc on dchkt.iddocchkt=galldoc.iddoc";
zapros=zapros+" left outer join sfirm on galldoc.idfirmdoc=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on galldoc.idskldoc=ssklad.idsklad";
zapros=zapros+" left outer join snom on dchkt.idnomchkt=snom.idnom";
zapros=zapros+" left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn";
zapros=zapros+" left outer join sed on snom.idbasednom=sed.ided";
zapros=zapros+" where dchkt.skchkt!=0  and galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON";

zapros=zapros+" and  sfirm.idfirm="+IntToStr(id_firm);
zapros=zapros+" and  ssklad.idsklad="+IntToStr(id_sklad);
zapros=zapros+" and  dchkt.idnomchkt="+IntToStr(id_nom);

zapros=zapros+" group by ";
zapros=zapros+" galldoc.posdoc,galldoc.iddoc, galldoc.tdoc, galldoc.numdoc,";
zapros=zapros+" snom.namenom, snom.tnom,";
zapros=zapros+" sed.nameed";
return zapros;
}
//----------------------------------------------------------------------------
void TDMReportDiscountDocCheck::OpenReportDoc(TDateTime pos_nach, TDateTime pos_con,
													__int64 id_firm,
													__int64 id_sklad,
													__int64 id_nom)
{
DMDoc->pFIBQ->Close();
DMDoc->pFIBQ->SQL->Clear();
DMDoc->pFIBQ->SQL->Add(GetTextZaprosDoc(id_firm,id_sklad,id_nom));
DMDoc->pFIBQ->Params->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
DMDoc->pFIBQ->Params->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
DMDoc->pFIBQ->ExecQuery();

}
//----------------------------------------------------------------------------
