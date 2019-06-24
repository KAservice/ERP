//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaCheckKKMkPKO.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern bool IspFR;

//---------------------------------------------------------------------------
__fastcall TFormaCheckKKMkPKO::TFormaCheckKKMkPKO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaCheckKKMkPKO::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FrOK==true)
        {
        FR.OleProcedure("Beep");
        FR.OleProcedure("Disconnect");
        }
IspFR=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaCheckKKMkPKO::FormCreate(TObject *Sender)
{
Memo1->Clear();
KKM=new TDMSprKKM(Application);
IspFR=true;
ConnectFR();
}
//---------------------------------------------------------------------------

void TFormaCheckKKMkPKO::UpdateForm(void)
{
KKM->OpenElement(IdKKM);
NameKKMLabel->Caption="ККМ: "+KKM->ElementNAMEKKM->AsString;
SumCheckLabel->Caption="Сумма: "+FloatToStr(SumCheck);
if (KKM->ElementUCHKKM->AsInteger==1) UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

}
//---------------------------------------------------------------------------
bool  TFormaCheckKKMkPKO::ConnectFR(void)
{
FrOK=false;

//попытаемся подключится к ККМ
try
        {
        FR = Variant::CreateObject("AddIn.DrvFR");
        }
catch (...)
        {
        FrOK=false;
        Prim->Caption="Не удалось создать объект фискального регистратора !";
        return FrOK;
        }

        FR.OleProcedure("Connect");
        if(FR.OlePropertyGet("ResultCode")==0)
                {
                FR.OleProcedure("Beep");
                FrOK=true;
                }
        else
                {
                FrOK=false;
                Prim->Caption="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");

                }

return FrOK;

}

//--------------------------------------------------------------------------
bool TFormaCheckKKMkPKO::PrintCheck(void)
{
bool Res=false;
if(FrOK==false)
        {
        Prim->Caption="Фискальный регистратор не подключен!";
        return Res;

        }

for (int i=0;i<Memo1->Lines->Count;i++)
        {
        FR.OlePropertySet("StringForPrinting",Memo1->Lines->Strings[i].c_str());
        FR.OleProcedure("PrintString");

        }

if (KKM->ElementUCHKKM->AsInteger==0) PrintFiscalCheck();
else PrintNoFiscalCheck();

Res=true;

return Res;
}
//-------------------------------------------------------------------------
bool TFormaCheckKKMkPKO::PrintFiscalCheck(void)
{
bool res=false;

FR.OlePropertySet("StringForPrinting"," ");

FR.OlePropertySet("Price",SumCheck);
FR.OlePropertySet("Department",2);
FR.OlePropertySet("Quantity",1);
FR.OleProcedure("Sale");
 //закроем чек

FR.OlePropertySet("Summ1",SumCheck);
FR.OlePropertySet("StringForPrinting","____________________________________");
FR.OleProcedure("CloseCheck");


res=true;
return res;
}
//--------------------------------------------------------------------------
bool TFormaCheckKKMkPKO::PrintNoFiscalCheck(void)
{
bool res=false;

FR.OlePropertySet("StringForPrinting","Учебный чек напечатан!");
FR.OleProcedure("PrintString");

for(int i=0;i<10;i++)
        {
        FR.OlePropertySet("StringForPrinting"," ");
        FR.OleProcedure("PrintString");
        }
        
res=true;
return res;
}
//--------------------------------------------------------------------------
void __fastcall TFormaCheckKKMkPKO::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaCheckKKMkPKO::ButtonPrintCheckClick(TObject *Sender)
{
PrintCheck();
}
//---------------------------------------------------------------------------
