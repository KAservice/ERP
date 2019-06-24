//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprInfBaseViborH
#define UFormaSpiskaSprInfBaseViborH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "UDM.h"
#include "UDMSprInfBase.h"

//---------------------------------------------------------------------------
class TFormaSpiskaSprInfBaseVibor : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TButton *ButtonClose;
        TLabel *HintLabel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaSpiskaSprInfBaseVibor(TComponent* Owner);
		
        TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        TDMSprInfBase * DM;
        bool Vibor;
        bool OutReady;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprInfBaseVibor *FormaSpiskaSprInfBaseVibor;
//---------------------------------------------------------------------------
#endif
