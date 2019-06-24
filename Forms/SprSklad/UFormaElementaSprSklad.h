//---------------------------------------------------------------------------

#ifndef UFormaElementasprSkladH
#define UFormaElementasprSkladH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IDMSprSklad.h"
//----------------------------------------------------------------------------
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------
class TFormaElementaSprSklad : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCheckBox *TypeSkladcxDBCheckBox;
	TcxDBTextEdit *AdrcxDBTextEdit;
	TcxDBTextEdit *MOLcxDBTextEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TLabel *Label4;
	TcxDBTextEdit *PhonecxDBTextEdit;
	TcxDBTextEdit *EMailcxDBTextEdit;
	TLabel *Label5;
	TLabel *Label6;
	TcxDBCheckBox *DblUchetAllNomcxDBCheckBox;
	TcxDBCheckBox *DblUchetcxDBCheckBox;
	TcxDBTextEdit *cxDBTextEditVKONTAKTE_SSKLAD;
	TcxDBTextEdit *cxDBTextEditWEBSITE_SSKLAD;
	TcxDBTextEdit *cxDBTextEditREGIM_RABOTI_SSKLAD;
	TcxDBTextEdit *cxDBTextEditDOPINFO_SSKLAD;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall MOLcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall AdrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypeSkladcxDBCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
		__fastcall TFormaElementaSprSklad(TComponent* Owner);


		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		//форма открыта для выбора
		bool Vibor;
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме



		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		IDMSprSklad * DM;
        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprSklad *FormaElementaSprSklad;
//---------------------------------------------------------------------------
#endif
