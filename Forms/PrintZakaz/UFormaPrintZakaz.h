//---------------------------------------------------------------------------

#ifndef UFormaPrintZakazH
#define UFormaPrintZakazH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormaPrintZakaz : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TClientSocket *ClientSocket1;
        TLabel *IPLabel;
        TLabel *PortLabel;
        TTimer *Timer1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaPrintZakaz(TComponent* Owner);

        TNotifyEvent EventEndPrint;

        void UpdateForm(void);
        void ConnectPrintServer(void);
        void PrintZakaz(void);
        void DisconnectPrintServer(void);
        void EndPrintZakaz(void);

       AnsiString IP;
       int Port;
       __int64 IdZakaz;
       bool Error;
       AnsiString TextError;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintZakaz *FormaPrintZakaz;
//---------------------------------------------------------------------------
#endif
