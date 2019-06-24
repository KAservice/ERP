//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMGurZakRest.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
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
Zapros=Zapros+" RGZAK.*,   NAMEKLIENT, NAME_USER, NAME_STROB, ID_STROB";
Zapros=Zapros+" from   RGZAK ";
Zapros=Zapros+" left outer join SKLIENT on IDKLIENT_ZAK=IDKLIENT ";
Zapros=Zapros+" left outer join SUSER on  IDUSER_ZAK= ID_USER";
Zapros=Zapros+" left outer join SSTROB on IDOB_ZAK=ID_STROB";
if (AllUser==true)
        {
        }
else
        {
        Zapros=Zapros+" where IDUSER_ZAK='"+IntToStr(IdUser)+"'";
        }

Table->SQL->Clear();
Table->SQL->Add(Zapros);
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurZakRest::UpdateTable(void)
{
IdZakaz=TableID_ZAK->AsInteger;
DataSourceTable->Enabled=false;

Table->Active=false;
String Zapros="";
Zapros=Zapros+" select  ";
Zapros=Zapros+" RGZAK.*,   NAMEKLIENT,   NAME_USER, NAME_STROB, ID_STROB";
Zapros=Zapros+" from   RGZAK ";
Zapros=Zapros+" left outer join SKLIENT on IDKLIENT_ZAK=IDKLIENT ";
Zapros=Zapros+" left outer join SUSER on  IDUSER_ZAK= ID_USER";
Zapros=Zapros+" left outer join SSTROB on IDOB_ZAK=ID_STROB";
if (AllUser==true)
        {
        }
else
        {
        Zapros=Zapros+" where IDUSER_ZAK='"+IntToStr(IdUser)+"'";
        }


Table->SQL->Clear();
Table->SQL->Add(Zapros);
Table->Active=true;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_ZAK",IntToStr(IdZakaz),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

