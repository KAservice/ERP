//---------------------------------------------------------------------------

#ifndef UFormaPrintCheckKKMH
#define UFormaPrintCheckKKMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDM.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//#include "UShtrihFRK.h"
#include <Buttons.hpp>
#include "UKalkulator.h"
#include "UDMSprARM.h"
//---------------------------------------------------------------------------
class TFormaPrintCheckKKM : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMemo *Memo1;
        TLabel *UchLabel;
        TLabel *Prim;
        TButton *ButtonPrintCheck;
        TButton *ButtonClose;
        TLabel *NameKKMLabel;
        TEdit *SumCheckEdit;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *X1;
        TMenuItem *Z1;
        TMenuItem *N2;
        TEdit *OtdelEdit;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBox;
        TMenuItem *N3;
        TEdit *NalEdit;
        TEdit *PlatCardEdit;
        TLabel *Label3;
        TLabel *Label4;
        TBitBtn *BitBtnOtdel;
        TBitBtn *BitBtnSumma;
        TBitBtn *BitBtnSale;
        TBitBtn *BitBtnReturnSale;
        TBitBtn *BitBtnNal;
        TBitBtn *BitBtnPlatCard;
        TBitBtn *BitBtnPrint;
        TBitBtn *BitBtnClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonPrintCheckClick(TObject *Sender);
        void __fastcall X1Click(TObject *Sender);
        void __fastcall Z1Click(TObject *Sender);
        void __fastcall BitBtnOtdelClick(TObject *Sender);
        void __fastcall BitBtnSummaClick(TObject *Sender);
        void __fastcall BitBtnNalClick(TObject *Sender);
        void __fastcall BitBtnPlatCardClick(TObject *Sender);
        void __fastcall BitBtnSaleClick(TObject *Sender);
        void __fastcall BitBtnReturnSaleClick(TObject *Sender);
        void __fastcall BitBtnPrintClick(TObject *Sender);
        void __fastcall BitBtnCloseClick(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaPrintCheckKKM(TComponent* Owner);

	TDM * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        __int64 IdARM;

        TDMSprARM * DMSprARM;
        bool FrOK;

        bool PrintCheck(void);
        bool PrintFiscalCheck(void);
        bool PrintNoFiscalCheck(void);

//        void SummaCheck(void);
        void UpdateForm(void);
        double SumCheck;

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TKalkulator * Kalk;

        enum  {InputOtdel, InputSumma, InputNal, InputPlatCard,  NO} EditRekvisit;


        void __fastcall EndEdit(TObject *Sender);
        TNotifyEvent FOnCloseForm;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintCheckKKM *FormaPrintCheckKKM;
//---------------------------------------------------------------------------
#endif
