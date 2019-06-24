//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaPrintZakaz.h"
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
void TFormaPrintZakaz::UpdateForm(void)
{
IPLabel->Caption="IP: "+IP;
PortLabel->Caption="Порт: "+IntToStr(Port);

}
//--------------------------------------------------------------------------
void TFormaPrintZakaz::PrintZakaz(void)
{
ConnectPrintServer();
}
//---------------------------------------------------------------------------
void TFormaPrintZakaz::ConnectPrintServer(void)
{
//устанавливаем соединение с сервером
try
        {
        ClientSocket1->Address=IP;
        ClientSocket1->Port=Port;
        ClientSocket1->Open();
        }
catch(...)
        {
        Error=true;
        TextError="Не удалось соединиться с сервером печати!";
        EndPrintZakaz();
        }
}

//----------------------------------------------------------------------------
void TFormaPrintZakaz::DisconnectPrintServer(void)
{
try
        {
        ClientSocket1->Close();
        }
catch (...)
        {

        }
}
//----------------------------------------------------------------------------

void __fastcall TFormaPrintZakaz::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
ClientSocket1->Socket->SendText("print_zakaz=start="+IntToStr(IdZakaz));

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintZakaz::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString StrComand=Socket->ReceiveText();
        AnsiString Operation=StrComand.SubString(0,StrComand.Pos("=")-1);
        StrComand=StrComand.SubString(StrComand.Pos("=")+1,StrComand.Length());
        AnsiString Comand=StrComand.SubString(0,StrComand.Pos("=")-1);
        AnsiString Value=StrComand.SubString(StrComand.Pos("=")+1,StrComand.Length());

        if (Operation=="print_zakaz")
                {
                if(Comand=="result")
                        {
                        if(Value=="OK")
                                {
                                Error=false;
                                TextError="";
                                EndPrintZakaz();
                                }
                        if(Value=="ERROR")
                                {
                                Error=true;
                                Socket->SendText("print_zakaz=get_text_error=");
                                }
                        }

                if(Comand=="text_error")
                        {
                        Error=true;
                        TextError=Value;
                        EndPrintZakaz();
                        }

                }
}
//---------------------------------------------------------------------------
void TFormaPrintZakaz::EndPrintZakaz(void)
{
DisconnectPrintServer();
try {if(EventEndPrint) EventEndPrint(this); } catch (...){};

}
//-------------------------------------------------------------------------
void __fastcall TFormaPrintZakaz::Timer1Timer(TObject *Sender)
{
Error=true;
TextError="Истекло время печати!";
EndPrintZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintZakaz::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        ErrorCode=0;
        Error=true;
        TextError="Ошибка соединения с сервером печати!";
        EndPrintZakaz();
}
//---------------------------------------------------------------------------

