//---------------------------------------------------------------------------

#ifndef UFormaElementaSprEdH
#define UFormaElementaSprEdH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprImportEd.h"
#include "IFormaSpiskaSprOKEI.h"
#include "IDMSprEd.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprEd : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonNewSH;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameOkeicxDBButtonEdit;
	TcxDBTextEdit *NameEdcxDBTextEdit;
	TcxDBCalcEdit *KFEdcxDBCalcEdit;
	TcxDBTextEdit *SHcxDBTextEdit;
	TcxComboBox *NeIspEdComboBox;
	TcxDBTextEdit *CodecxDBTextEdit;
	TLabel *Label6;
	TcxButton *cxButtonOpenFormSpiskaImportEd;
	TcxDBCalcEdit *KF2cxDBCalcEdit;
	TcxDBCalcEdit *VescxDBCalcEdit;
	TLabel *Label7;
	TLabel *Label8;
	TcxDBImageComboBox *cxDBImageComboBoxTypeBarCode;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonNewSHClick(TObject *Sender);
	void __fastcall NameOkeicxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NeIspEdComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameEdcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KFEdcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SHcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxButtonOpenFormSpiskaImportEdClick(TObject *Sender);
	void __fastcall KF2cxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall VescxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxDBImageComboBoxTypeBarCodeKeyPress(TObject *Sender,
          char &Key);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		IFormaSpiskaSprOKEI *FormaSpiskaSprOKEI;
		IFormaSpiskaSprImportEd *FormaSpiskaSprImportEd;
		bool flObrabatChangeTypeSH;
	   bool flObrabatChangeNeIsp;

	   bool SaveElement;

	   bool CheckBarCode(void);
	   void __fastcall EndViborImportEd(TObject *Sender);
public:		// User declarations
		__fastcall TFormaElementaSprEd(TComponent* Owner);

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

         void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс
		IDMSprEd * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprEd *FormaElementaSprEd;
//---------------------------------------------------------------------------
#endif
