//---------------------------------------------------------------------------

#ifndef UFormaElementaSprNakSkidokH
#define UFormaElementaSprNakSkidokH
//---------------------------------------------------------------------------
#include "IDMSprNakSkidok.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprVidDiscountCard.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp> 
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxLabel.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxSpinEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprNakSkidok : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxDBButtonEdit *NAmeSkladcxDBButtonEdit;
	TLabel *Label5;
	TcxDBButtonEdit *NameVidcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBCalcEdit *SumcxDBCalcEdit;
	TcxDBCalcEdit *ProcentcxDBCalcEdit;
	TcxDBSpinEdit *PeriodcxDBSpinEdit;
	TcxLabel *cxLabel2;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameVidcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprSklad * FormaSpiskaSprSklad ;
		void ViborSklad (void);
		void __fastcall EndViborSklad (void);

		IFormaSpiskaSprVidDiscountCard * FormaSpiskaSprVidDiscountCard;
		void ViborVidDiscountCard(void);
		void __fastcall EndViborVidDiscountCard(void);

		enum  {ER_NoRekv,ER_Sklad, ER_VidCard, ER_NO} EditRekvisit;

public:		// User declarations
		__fastcall TFormaElementaSprNakSkidok(TComponent* Owner);

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


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		//Текущий интерфейс
		IDMSprNakSkidok * DM;




        void UpdateForm(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprNakSkidok *FormaElementaSprNakSkidok;
//---------------------------------------------------------------------------
#endif
