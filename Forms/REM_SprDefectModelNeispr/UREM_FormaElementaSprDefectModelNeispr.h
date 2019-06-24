//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprDefectModelNeisprH
#define UREM_FormaElementaSprDefectModelNeisprH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprDefectModelNeispr.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprTypDefect.h"
#include "IREM_FormaSpiskaSprTrebRabot.h"
#include "IREM_FormaSpiskaSprTrebUslov.h"
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
class TREM_FormaElementaSprDefectModelNeispr : public TForm
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
	TcxDBButtonEdit *NameTypDefectcxDBButtonEdit;
	TLabel *Label3;
	TcxDBLabel *CodeTypDefectcxDBLabel;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxButton *cxButtonTrebUslov;
	TcxButton *cxButtonTrebRabot;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonTrebUslovClick(TObject *Sender);
	void __fastcall cxButtonTrebRabotClick(TObject *Sender);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		enum {NO, VR_ViborTypDefect, VR_ViborTrebRabot,VR_ViborTrebUslov} ViborRekv;


		//выбор номенклатуры
		IREM_FormaSpiskaSprTypDefect * FormaSpiskaSprTypDefect;
		void ViborTypDefect(void);
		void __fastcall EndViborTypDefect(void);

		//выбор требуемых узлов
		IREM_FormaSpiskaSprTrebUslov * FormaSpiskaSprTrebUslov;
		void ViborTrebUslov(void);
		void __fastcall EndViborTrebUslov(void);

		//выбор требуемых работ
		IREM_FormaSpiskaSprTrebRabot * FormaSpiskaSprTrebRabot;
		void ViborTrebRabot(void);
		void __fastcall EndViborTrebRabot(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprDefectModelNeispr(TComponent* Owner);

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

		IREM_DMSprDefectModelNeispr * DM;

		__int64 IdModelNeispr;

		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprDefectModelNeispr *REM_FormaElementaSprDefectModelNeispr;
//---------------------------------------------------------------------------
#endif
