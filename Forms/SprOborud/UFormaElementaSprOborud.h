//---------------------------------------------------------------------------

#ifndef UFormaElementaSprOborudH
#define UFormaElementaSprOborudH
//---------------------------------------------------------------------------

#include "UDM.h"
#include "IDMSprOborud.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxButtons.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "cxPC.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprOborud : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBMemo *StrParcxDBMemo;
	TcxDBCheckBox *OnStartcxDBCheckBox;
	TcxComboBox *TypeOborudComboBox;
	TcxComboBox *ModelComboBox;
	TLabel *Label5;
	TLabel *Label6;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *CompNamecxDBTextEdit;
	TcxDBComboBox *ComPortcxDBComboBox;
	TcxDBComboBox *BaudRatecxDBComboBox;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label7;
	TLabel *Label3;
	TLabel *Label4;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBComboBox *ModulcxDBComboBox;
	TcxDBComboBox *cxDBComboBoxPROGID_SOBORUD;
	TLabel *Label8;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall TypeOborudComboBox_Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall TypeOborudComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CompNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ModulcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnStartcxDBCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		void UpdateModel(void);
        void UpdateModul(void);
		bool ObrabatChangeTypeOborud;
public:		// User declarations
		__fastcall TFormaElementaSprOborud(TComponent* Owner);
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс
		IDMSprOborud * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprOborud *FormaElementaSprOborud;
//---------------------------------------------------------------------------
#endif
