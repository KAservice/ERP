//---------------------------------------------------------------------------
#ifndef UModifyFormSheetEditorH
#define UModifyFormSheetEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxSSCtrls.hpp"
#include <ExtCtrls.hpp>
#include <cxSSCtrls.hpp>
#include <cxSSTypes.hpp>
#include <cxSSRes.hpp>
//---------------------------------------------------------------------------
class TControlAccess : public TControl {
public:
	__property Caption;
};

class TModifyFormSheetEditor : public TForm
{
__published:	// IDE-managed Components
  TButton *btnOk;
  TButton *btnCancel;
  TPanel *gpPanel;
  TRadioButton *rbShiftCol;
  TRadioButton *rbShiftRw;
  TRadioButton *rbRw;
  TRadioButton *rbCol;
  void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
  TcxSSCellsModify FModifySheet;
  void __fastcall SetCaptions(AnsiString ACaptions[8]);
public:		// User declarations
  __fastcall TModifyFormSheetEditor(TComponent* Owner);
  bool __fastcall Execute(TcxSSModifyType AModifySheet);
  __property TcxSSCellsModify Modify = {read = FModifySheet, write = FModifySheet};
};
//---------------------------------------------------------------------------
extern PACKAGE TModifyFormSheetEditor *ModifyFormSheetEditor;
//---------------------------------------------------------------------------
#endif
  