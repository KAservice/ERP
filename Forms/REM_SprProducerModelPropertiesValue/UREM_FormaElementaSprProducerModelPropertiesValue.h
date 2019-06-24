//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprProducerModelPropertiesValueH
#define UREM_FormaElementaSprProducerModelPropertiesValueH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprProperties.h"
#include "IFormaSpiskaSprPropertiesValuesList.h"
#include "IREM_DMSprProducerModelPropertiesValue.h"
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
#include "cxDBRichEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCalendar.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprProducerModelPropertiesValue : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NamePropValueListcxDBButtonEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBMemo *ValueTextcxDBMemo;
	TcxDBButtonEdit *NamePropcxDBButtonEdit;
	TLabel *Label1;
	TcxDBDateEdit *IsmcxDBDateEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NamePropcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NamePropValueListcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	IFormaSpiskaSprProperties * FormaSpiskaSprProperties;
	IFormaSpiskaSprPropertiesValuesList *FormaSpiskaSprPropertiesValuesList;

	void OpenFormaSpiskaSprProperties(void);
	void  EndViborProperties(void);
	void OpenFormaSpiskaSprPropertiesValuesList(void);
	void  EndViborPropertiesValue(void);


	enum  {ER_NoRekv, ER_ViborProperties, ER_ViborPropertiesValue} ER_Rekvisit;


public:		// User declarations
		__fastcall TREM_FormaElementaSprProducerModelPropertiesValue(TComponent* Owner);

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
		IREM_DMSprProducerModelPropertiesValue * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprProducerModelPropertiesValue *REM_FormaElementaSprProducerModelPropertiesValue;
//---------------------------------------------------------------------------
#endif
