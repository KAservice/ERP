//---------------------------------------------------------------------------

#ifndef UFormaPanelButtonTouchH
#define UFormaPanelButtonTouchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "UDM.h"
//---------------------------------------------------------------------------
class TFormaPanelButtonTouch : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtnClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnCloseClick(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaPanelButtonTouch(TComponent* Owner);

        TNotifyEvent FOnCloseForm;

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        bool OutReady;
        enum  {ER_NoRekv,DelButton,XButton,ZButton, NO} PressButton;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPanelButtonTouch *FormaPanelButtonTouch;
//---------------------------------------------------------------------------
#endif
