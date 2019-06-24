//---------------------------------------------------------------------------

#ifndef UFormaElementaSprProgramModuleH
#define UFormaElementaSprProgramModuleH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IDMSprProgramModule.h"
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
#include "UDM.h"
#include "cxMemo.hpp"
#include "cxDropDownEdit.hpp"
#include "cxImageComboBox.hpp"
#include "cxMaskEdit.hpp"

//---------------------------------------------------------------------------
class TFormaElementaSprProgramModule : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *ModulecxDBTextEdit;
	TcxDBTextEdit *GuidcxDBTextEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBTextEdit *PatchcxDBTextEdit;
	TcxDBMemo *DescrcxDBMemo;
	TLabel *Label4;
	TLabel *Label5;
	TcxDBTextEdit *ProgIdcxDBTextEdit;
	TLabel *Label6;
	TcxDBImageComboBox *TypeAppliccxDBImageComboBox;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall GuidcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ModulecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PatchcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DescrcxDBMemoKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ProgIdcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
		__fastcall TFormaElementaSprProgramModule(TComponent* Owner);


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


		IDMSprProgramModule * DM;
        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprProgramModule *FormaElementaSprProgramModule;
//---------------------------------------------------------------------------
#endif
