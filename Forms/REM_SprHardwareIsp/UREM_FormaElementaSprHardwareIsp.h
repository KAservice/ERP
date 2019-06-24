//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprHardwareIspH
#define UREM_FormaElementaSprHardwareIspH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprHardwareIsp.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
#include "IREM_FormaGurZ.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtonEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMemo.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprHardwareIsp : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TLabel *Label5;
	TcxDBButtonEdit *NameTypUslacxDBButtonEdit;
	TcxDBButtonEdit *ZayavkacxDBButtonEdit;
	TcxDBLabel *ModelZcxDBLabel;
	TcxDBLabel *PosZcxDBLabel;
	TcxDBLabel *PrefikscxDBLabel;
	TcxDBLabel *NumZcxDBLabel;
	TcxDBLabel *SerNumcxDBLabel;
	TcxLabel *cxLabel20;
	TLabel *Label1;
	TcxDBCheckBox *OtchitanocxDBCheckBox;
	TcxDBCheckBox *RealnoIspolsovanocxDBCheckBox;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxDBMemo *DescrcxDBMemo;
	TcxDBCalcEdit *KolcxDBCalcEdit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionSaveElement;
	TAction *ActionCloseElement;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameTypUslacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseElementExecute(TObject *Sender);
	void __fastcall ZayavkacxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		enum {NO, VR_ViborNom, VR_ViborProducerNom, VR_ViborNomProducer,VR_ViborTypUsla,
									ER_ViborZ} ViborRekv;



		//выбор типового узла
		IREM_FormaSpiskaSprTypUslov * FormaSpiskaSprTypUslov;
		void ViborTypUsla(void);
		void __fastcall EndViborTypUsla(void);

 		IREM_FormaGurZ * FormaGurZ;
		void ViborZ(void);
		void EndViborZ(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprHardwareIsp(TComponent* Owner);

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
        bool Prosmotr;    //только просмотр
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		IREM_DMSprHardwareIsp * DM;



		void UpdateForm(void);
		UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprHardwareIsp *REM_FormaElementaSprHardwareIsp;
//---------------------------------------------------------------------------
#endif
