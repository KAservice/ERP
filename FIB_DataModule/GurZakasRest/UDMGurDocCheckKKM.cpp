//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMGurDocCheckKKM.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDMGurZakRest *DMGurZakRest;
//---------------------------------------------------------------------------
__fastcall TDMGurZakRest::TDMGurZakRest(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMGurZakRest::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
}
//---------------------------------------------------------------------------
void TDMGurZakRest::OpenTable()
{
Table->Active=false;
String Zapros="";
Zapros=Zapros+" select  ";
Zapros=Zapros+" NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,";
Zapros=Zapros+" NAMEKKM, NAMEFIRM, NAMESKLAD, NAMEKLIENT,   NAME_USER  ";
Zapros=Zapros+" from  DCHK ";
Zapros=Zapros+" left outer join SKKM on IDKKMCHK=IDKKM ";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHK=IDDOC";
Zapros=Zapros+" left outer join SFIRM on IDFIRMDOC=IDFIRM";
Zapros=Zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD ";
Zapros=Zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
Zapros=Zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";
Zapros=Zapros+" where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";
Zapros=Zapros+" order by POSDOC ";
Table->SQL->Clear();
Table->SQL->Add(Zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurZakRest::UpdateTable(void)
{
IdDoc=TableIDDOC->AsInteger;
DataSourceTable->Enabled=false;

Table->Active=false;
String Zapros="";
Zapros=Zapros+" select  ";
Zapros=Zapros+" NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,";
Zapros=Zapros+" NAMEKKM, NAMEFIRM, NAMESKLAD, NAMEKLIENT,   NAME_USER  ";
Zapros=Zapros+" from  DCHK ";
Zapros=Zapros+" left outer join SKKM on IDKKMCHK=IDKKM ";
Zapros=Zapros+" left outer join GALLDOC on IDDOCCHK=IDDOC";
Zapros=Zapros+" left outer join SFIRM on IDFIRMDOC=IDFIRM";
Zapros=Zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD ";
Zapros=Zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
Zapros=Zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";
Zapros=Zapros+" where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";

if (IdKKM!=0 && NumberKL==0)
        {
        Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);
        }

if (IdKKM!=0 && NumberKL!=0)
        {
        Zapros=Zapros+" and IDKKMCHK="+IntToStr(IdKKM);
        Zapros=Zapros+" and NKLCHK="+IntToStr(NumberKL);
        }

Zapros=Zapros+" order by POSDOC ";


Table->SQL->Clear();
Table->SQL->Add(Zapros);
//ShowMessage(DateTimeToStr(PosNach)+"   "+DateTimeToStr(PosCon));
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon;
Table->Active=true;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("IDDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

