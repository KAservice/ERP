//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprNeisprModelH
#define UREM_FormaElementaSprNeisprModelH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprNeisprModel.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprNeispr.h"
#include "IREM_FormaSpiskaSprDefectModelNeispr.h"
#include "IREM_FormaSpiskaSprModel.h"
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
//---------------------------------------------------------------------------
class TREM_FormaElementaSprNeisprModel : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameNeisprcxDBButtonEdit;
	TLabel *Label3;
	TcxButton *cxButtonDefect;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TLabel *Label2;
	TcxDBButtonEdit *NameModelNeisprcxDBButtonEdit;
	TLabel *Label4;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonDefectClick(TObject *Sender);
	void __fastcall NameModelNeisprcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		enum {NO, VR_ViborNeispr, VR_ViborDefectModelNeispr,VR_Model} ViborRekv;


		//выбор номенклатуры
		IREM_FormaSpiskaSprNeispr * FormaSpiskaSprNeispr;
		void ViborNeispr(void);
		void __fastcall EndViborNeispr(void);

		//выбор номенклатуры
		IREM_FormaSpiskaSprDefectModelNeispr * FormaSpiskaSprDefectModelNeispr;
		void ViborDefectModelNeispr(void);
		void __fastcall EndViborDefectModelNeispr(void);


				//выбор модели
		IREM_FormaSpiskaSprModel * FormaSpiskaSprModel;
		void ViborModel(void);
		void __fastcall EndViborModel(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprNeisprModel(TComponent* Owner);

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

		IREM_DMSprNeisprModel * DM;



		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprNeisprModel *REM_FormaElementaSprNeisprModel;
//---------------------------------------------------------------------------
#endif
