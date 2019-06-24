//---------------------------------------------------------------------------

#ifndef UFormaInputCodeH
#define UFormaInputCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaInputCode : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *NameSprLabel;
        TLabel *Label2;
	TcxTextEdit *CodeEdit;
	TcxCalcEdit *KolEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CodeEditKeyPress(TObject *Sender, char &Key);
	void __fastcall KolEditKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaInputCode(TComponent* Owner);


        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TNotifyEvent FOnCloseForm;
        
        bool Vibor;
        bool OutReady;
        int IdPod;    //подразделение
        int ViborIdNom;  //выбранная номенклатура

        int Code;
        float Kol;
        
        bool AllElement;//текущее значение все элементы или нет
        bool Prosmotr;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaInputCode *FormaInputCode;
//---------------------------------------------------------------------------
#endif
