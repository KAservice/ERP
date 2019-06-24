//---------------------------------------------------------------------------

#ifndef UFormaPrintPriceH
#define UFormaPrintPriceH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UFormaViborSprNom.h"
#include "UFormaViborGrpNomSpr.h"
#include "UFormaInputText.h"


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

#include <ActnList.hpp>
//---------------------------------------------------------------------------


                
class TFormaPrintPrice : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TStringGrid *StringGrid1;
        TToolBar *ToolBar1;
        TToolButton *AddNomToolButton;
        TToolButton *ToolButton2;
        TToolButton *AddGrpToolButton;
        TToolButton *DelNomToolButton;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonPrintNumber2;
        TToolButton *ToolButtonPrintNumber3;
        TToolButton *ToolButtonPrintNumber4;
        TToolBar *ToolBar2;
        TToolButton *ToolButton5;
        TToolButton *ToolButtonPrintBarCode1;
        TToolButton *ToolButton7;
        TToolButton *ToolButtonEditKol;
	TActionList *ActionList1;
	TAction *OpenHelp;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddNomToolButtonClick(TObject *Sender);
        void __fastcall DelNomToolButtonClick(TObject *Sender);
        void __fastcall AddGrpToolButtonClick(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber2Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber3Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber4Click(TObject *Sender);
        void __fastcall ToolButtonEditKolClick(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaPrintPrice(TComponent* Owner);


	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;

        void UpdateGrid(void);

        void __fastcall EndEdit(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        enum  {ViborNom, ViborGrpNom, ViborEd, InputKol, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TFormaInputText * FormaInputText;

        TFormaViborSprNom  *FormaViborSprNom;
        void OpenFormViborSprNom(void);

        TFormaViborGrpNomSpr * FormaViborGrpNomSpr;
        void OpenFormViborGrpNom(void);
        void DeleteString(int num_str);



};



//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintPrice *FormaPrintPrice;
//---------------------------------------------------------------------------
#endif
