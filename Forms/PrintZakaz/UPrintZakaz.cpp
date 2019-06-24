//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintZakaz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaPrintZakaz::TFormaPrintZakaz(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintZakaz::FormCreate(TObject *Sender)
{
/////
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintZakaz::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------

void TFormaPrintZakaz::ConnectPrintServer(AnsiString ip_adress, int port)
{
//устанавливаем соединение с сервером
ClientSocket1->Address=ip_adress;
ClientSocket1->Port=port;
ClientSocket1->Open();


}
//--------------------------------------------------------------------------
void TFormaPrintZakaz::PrintZakaz(int id_zakaz)
{



}
//----------------------------------------------------------------------------
void TFormaPrintZakaz::DisconnectPrintServer(void)
{



ClientSocket1->Close();
}
//----------------------------------------------------------------------------

void __fastcall TFormaPrintZakaz::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
ClientSocket1->Socket->SendText("print_zakaz=start=");


}
//---------------------------------------------------------------------------

