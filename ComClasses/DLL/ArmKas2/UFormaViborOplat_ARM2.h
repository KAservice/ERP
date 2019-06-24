//---------------------------------------------------------------------------

#ifndef UFormaViborOplat_ARM2H
#define UFormaViborOplat_ARM2H
//---------------------------------------------------------------------------

#include "UDM.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCalc.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaViborOplat_ARM2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *cxGrid1TableView1IDFIRM;
	TcxGridColumn *cxGrid1TableView1NAMEFIRM;
	TcxGridColumn *cxGrid1TableView1NAL;
	TcxGridColumn *cxGrid1TableView1OPLPLATCARD;
	TcxGridColumn *cxGrid1TableView1SDACHA;
	TcxLabel *cxLabel1;
	TcxGridColumn *cxGrid1TableView1SUMCHECK;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonClose;
	TActionList *ActionList;
	TAction *ActionClose;
	TAction *ActionPrint;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxGrid1TableView1NALPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxGrid1TableView1OPLPLATCARDPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TFormaViborOplat_ARM2(TComponent* Owner);


   void UpdateForm(void);

   bool OutReady;
   TNotifyEvent FOnPrintCheck;
   TNotifyEvent FOnCloseForm;
   
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborOplat_ARM2 *FormaViborOplat_ARM2;
//---------------------------------------------------------------------------
#endif
