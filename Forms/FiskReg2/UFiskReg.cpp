//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFiskReg.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String DopStrL(String Str, String Symbol, int Len);
//---------------------------------------------------------------------------
__fastcall TFiskReg::TFiskReg(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFiskReg::FormCreate(TObject *Sender)
{
UseJournalRibbon=true;
UseReceiptRibbon=true;
Girn=false;
}
//---------------------------------------------------------------------------

void __fastcall TFiskReg::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
bool TFiskReg::Init()
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TFiskReg::Connect(void)
{
bool result=false;
if (TypeKKM==2) //Меркурий-MS-K
        {
        MSK=new TMercuryMSK(Application);
        MSK->ComName=ComName;
        MSK->Password=Password;
        MSK->BaudRate=BaudRate;
        
        if (MSK->ConnectFR()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }

        }
else      //Штрих-ФР-К
        {
        ShtrihFRK=new TShtrihFRK(Application);
        ShtrihFRK->ComName=ComName;
        ShtrihFRK->TypeKKM=TypeKKM;
        if (ShtrihFRK->ConnectFR()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }

return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::Disconnect(void)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->DisconnectFR()==true)
                {
                result=true;
                delete  MSK;
                }
        else
                {
                result=false;
                }
        }
else
        {
        if (ShtrihFRK->DisconnectFR()==true)
                {
                result=true;
                delete  ShtrihFRK;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintString(String str)
{
bool result=false;

switch (TypeKKM)
        {

        case 2 :  //меркурий MSK
                {
                MSK->Girn=Girn;
                MSK->UseJournalRibbon=UseJournalRibbon;
                MSK->UseReceiptRibbon=UseReceiptRibbon;
                if (MSK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;
        case 3 :  //комбо
                {
                ShtrihFRK->Girn=Girn;
                ShtrihFRK->Alignment=Alignment;
                ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
                ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
                if (ShtrihFRK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;


        default :    //штрих-фр-к
                {
                ShtrihFRK->Girn=Girn;
                ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
                ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
                if (ShtrihFRK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;
        }


return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::PrintLine(void)
{
bool result=false;
String str="-";

switch (TypeKKM)
        {

        case 2 :  //меркурий MSK
                {
                MSK->Girn=Girn;
                str="----------------------------------------";
                MSK->UseJournalRibbon=UseJournalRibbon;
                MSK->UseReceiptRibbon=UseReceiptRibbon;
                if (MSK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;
        case 3 :  //комбо
                {
                ShtrihFRK->Girn=Girn;
                str="-";
                str=DopStrL(str, "-", 48);
                ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
                ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
                if (ShtrihFRK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;


        default :    //штрих-фр-к
                {
                ShtrihFRK->Girn=Girn;
                str="-";
                str=DopStrL(str, "-", 36);
                ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
                ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
                if (ShtrihFRK->PrintStringFR(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }
                } break;
        }

return result;

}
//---------------------------------------------------------------------------
bool TFiskReg::PrintFiscalCheck(void)
{
bool result=false;
bool sale;

if (Operation==Sale)
        {
        sale=true;
        }
else
        {
        sale=false;
        }


if (TypeKKM==2)
        {
        MSK->UseJournalRibbon=UseJournalRibbon;
        MSK->UseReceiptRibbon=UseReceiptRibbon;
        if (MSK->PrintFiscalCheck(sale,SumCheck, OplataNal, OplataPlatCard)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
        ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
        ShtrihFRK->Department=Department;
        if (ShtrihFRK->PrintFiscalCheck(sale,SumCheck, OplataNal, OplataPlatCard)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintNoFiscalCheck(void)
{
bool result=false;
if (TypeKKM==2)
        {
        MSK->UseJournalRibbon=UseJournalRibbon;
        MSK->UseReceiptRibbon=UseReceiptRibbon;
        if (MSK->PrintNoFiscalCheck(SumCheck, OplataNal, OplataPlatCard)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        ShtrihFRK->UseJournalRibbon=UseJournalRibbon;
        ShtrihFRK->UseReceiptRibbon=UseReceiptRibbon;
        if (ShtrihFRK->PrintNoFiscalCheck(SumCheck, OplataNal, OplataPlatCard)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintXReport(void)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->PrintXReport()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {

        if (ShtrihFRK->PrintXReport()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintZReport(void)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->PrintZReport()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        if (ShtrihFRK->PrintZReport()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintPoOtdelamReport(void)
{
bool result=false;
if (TypeKKM==2)
        {

        }
else
        {
        if (ShtrihFRK->PrintPoOtdelamReport()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;

}
//---------------------------------------------------------------------------
bool TFiskReg::Cut(int TypeCut)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->Cut(TypeCut)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        if (ShtrihFRK->Cut(TypeCut)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//-----------------------------------------------------------------------------
void TFiskReg::GetSostKKM(void)
{
if (TypeKKM==2)
        {
        MSK->GetSostKKM();
        NumberCheck=MSK->NumberCheck;
        NumberKL=MSK->NumberKL;
        SerialNumberKKM=MSK->SerialNumberKKM;
        }
else
        {
        ShtrihFRK->GetSostKKM();
        NumberCheck=ShtrihFRK->NumberCheck;
        NumberKL=ShtrihFRK->NumberKL;
        SerialNumberKKM=ShtrihFRK->SerialNumberKKM;
        }
}
//-----------------------------------------------------------------------------
bool TFiskReg::ProvVosmPrintCheck(void)
{
bool result=false;


if (TypeKKM==2)
        {
        if (MSK->ProvVosmPrintCheck()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        if (ShtrihFRK->ProvVosmPrintCheck()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::Vnesenie(float sum)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->Vnesenie(sum)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
       // if (ShtrihFRK->Vnesenie()==true)
       //         {
       //         result=true;
       //         }
       // else
       //         {
       //         result=false;
       //         }
        }
return result;


}
//----------------------------------------------------------------------------
bool TFiskReg::Snatie(float sum)
{
bool result=false;
if (TypeKKM==2)
        {
        if (MSK->Snatie(sum)==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }
        }
else
        {
        //if (ShtrihFRK->PrintZReport()==true)
        //        {
       //         result=true;
       //         }
       // else
       //         {
       //         result=false;
       //         }
        }
return result;

}
//---------------------------------------------------------------------------
void TFiskReg::OpenNoFiscalCheck(void)
{
if (TypeKKM==2)
        {
        MSK->OpenNoFiscalCheck();
        }

}
//----------------------------------------------------------------------------
void TFiskReg::CloseNoFiscalCheck(void)
{
if (TypeKKM==2)
        {
        MSK->CloseNoFiscalCheck();
        }
}
//----------------------------------------------------------------------------
