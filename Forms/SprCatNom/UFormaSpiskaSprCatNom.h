//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprCatNomH
#define UFormaSpiskaSprCatNomH
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
#include "UDMSprCatNom.h"
//---------------------------------------------------------------------------
class TFormaSpiskaSprCatNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TDBGrid *DBGrid1;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TButton *ButtonClose;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprCatNom(TComponent* Owner);

        HANDLE IdRodForm;
        TDMSprCatNom * DM;
        bool Vibor;
        bool OutReady;
        
        TNotifyEvent FOnCloseForm;
        void __fastcall CloseElementSpr(TObject *Sender);

        void OpenFormElement();
        void OpenFormNewElement();
        void DeleteElement();



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprCatNom *FormaSpiskaSprCatNom;
//---------------------------------------------------------------------------
#endif
