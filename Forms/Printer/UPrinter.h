//---------------------------------------------------------------------------

#ifndef UPrinterH
#define UPrinterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UShtrih500.h"
//---------------------------------------------------------------------------
class TCheckPrinter : public TForm
{
__published:	// IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCheckPrinter(TComponent* Owner);

        TShtrih500 * Shtrih500;

        String ComName;
        String BaudRate;
        String Password;
        String TypePrinter;

        String Str;
        bool Girn;
        int Alignment;  //0- лево 1-право




        bool Connect(void);
        bool Disconnect(void);
        void GetSostPrinter(void);
        bool ProvVosmPrint(void);


        bool PrintString(String str);
        bool PrintLine(void);

        bool Cut(int TypeCut);








};
//---------------------------------------------------------------------------
extern PACKAGE TCheckPrinter *CheckPrinter;
//---------------------------------------------------------------------------
#endif
