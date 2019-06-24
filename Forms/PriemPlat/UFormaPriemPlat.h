//---------------------------------------------------------------------------

#ifndef UFormaPriemPlatH
#define UFormaPriemPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDMPriemPlat.h"
#include "UDMSprARM.h"
#include "UDMSprKlient.h"
#include "UDMSprNumTel.h"
#include "UDMGurPlat.h"
#include "UDMDocCheck.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <oleauto.hpp>

#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>

#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCalc.hpp"
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaPriemPlat : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *X1;
        TMenuItem *Z1;
        TMenuItem *N2;
        TMenuItem *N3;
        TLabel *Prim;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *UchLabel;
        TLabel *NameKKMLabel;
        TRichEdit *TextCheck;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *KlNaydenLabel;
        TLabel *NumKvLabel;
        TLabel *NameOperatorLabel;
        TLabel *CodOperLabel;
        TLabel *ProcentLabel;
        TLabel *SumKlLabel;
        TLabel *NameNomCommissionLabel;
	TcxButton *ButtonPrintKvitan;
	TcxButton *ButtonPrintCheck;
	TcxButton *ButtonClose;
	TcxTextEdit *CodeEdit;
	TcxTextEdit *NumberEdit;
	TcxTextEdit *NameKlientEdit;
	TcxComboBox *ComboBox;
	TcxSpinEdit *OtdelEdit;
	TcxCalcEdit *SumCheckEdit;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall X1Click(TObject *Sender);
        void __fastcall Z1Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
	void __fastcall ButtonPrintKvitanClick(TObject *Sender);
	void __fastcall ButtonPrintCheckClick(TObject *Sender);
	void __fastcall CodeEditKeyPress(TObject *Sender, char &Key);
	void __fastcall CodeEditExit(TObject *Sender);
	void __fastcall NumberEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NumberEditExit(TObject *Sender);
	void __fastcall NameKlientEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NameKlientEditExit(TObject *Sender);
	void __fastcall ComboBoxKeyPress(TObject *Sender, char &Key);
	void __fastcall OtdelEditKeyPress(TObject *Sender, char &Key);
	void __fastcall SumCheckEditKeyPress(TObject *Sender, char &Key);
	void __fastcall SumCheckEditExit(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaPriemPlat(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        TNotifyEvent FOnCloseForm;

		__int64 IdARM;
        TDMSprARM * DMSprARM;
        TDMDocCheck * DMCheck;
        TDMSprKlient * DMKlient;
        TDMSprNumTel *DMSprNumTel;

        TDMPriemPlat *DM;

		bool PrintCheck(void);
		bool PrintFiscalCheck(void);
		bool PrintNoFiscalCheck(void);
		TDateTime PosDoc;
		int NumberDoc;


        bool PrintKvitan(void);
        String  StrPrint;

        void SummaCheck(void);
        void UpdateForm(void);
        bool EnablePrintCheck(void);
        double SumCheck;

        bool PoiskKlienta(void);
        bool PoiskUslugi(void);
        bool AddNewKlient(void);
        bool CreateDocCheck(void);
        bool UpdateTextCheck(void);
        bool KlNayden;
        bool UslNayden;
        bool CheckPrint;
        bool CheckSave;

        int NumberKvitan;

        TDMGurPlat * DMGurPlat;

        AnsiString CodOperator;
        double ProcentCommission;
        __int64 IdNomCommission;
        double SumKlient;

        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPriemPlat *FormaPriemPlat;
//---------------------------------------------------------------------------
#endif
