//---------------------------------------------------------------------------

#ifndef UPrintZakazH
#define UPrintZakazH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TFormaPrintZakaz : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TClientSocket *ClientSocket1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaPrintZakaz(TComponent* Owner);

        void ConnectPrintServer(AnsiString ip_adress, int port);
        void PrintZakaz(int id_zakaz);
        void DisconnectPrintServer(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintZakaz *FormaPrintZakaz;
//---------------------------------------------------------------------------
#endif
