//---------------------------------------------------------------------------

#ifndef UFormaCheckKKMkPKOH
#define UFormaCheckKKMkPKOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <oleauto.hpp>
#include "UDM.h"
#include "UDMSprKKM.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormaCheckKKMkPKO : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMemo *Memo1;
        TLabel *UchLabel;
        TLabel *Prim;
        TLabel *SumCheckLabel;
        TButton *ButtonPrintCheck;
        TButton *ButtonClose;
        TLabel *NameKKMLabel;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonPrintCheckClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaCheckKKMkPKO(TComponent* Owner);

        int IdKKM;
        TDMSprKKM *KKM;
        Variant  FR;
        bool FrOK;
        bool PrintCheck(void);
        bool PrintFiscalCheck(void);
        bool PrintNoFiscalCheck(void);
        void SummaCheck(void);
        bool ConnectFR(void);
        void UpdateForm(void);
        double SumCheck;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaCheckKKMkPKO *FormaCheckKKMkPKO;
//---------------------------------------------------------------------------
#endif
