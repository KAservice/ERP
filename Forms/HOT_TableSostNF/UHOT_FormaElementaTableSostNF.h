//---------------------------------------------------------------------------

#ifndef UHOT_FormaElementaTableSostNFH
#define UHOT_FormaElementaTableSostNFH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IHOT_DMTableSostNF.h"
#include "UDM.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IFormaSpiskaSprKlient.h"
#include "IHOT_FormaSpiskaSprCelPriesda.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class THOT_FormaElementaTableSostNF : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameCatNomcxDBButtonEdit;
	TcxDBButtonEdit *NameNomercxDBButtonEdit;
	TLabel *Label3;
	TcxDBCalcEdit *KolMestcxDBCalcEdit;
	TLabel *Label4;
	TcxDBDateEdit *PosNachcxDBDateEdit;
	TcxDBDateEdit *PosConcxDBDateEdit;
	TLabel *Label5;
	TLabel *Label6;
	TcxDBButtonEdit *NamePlatcxDBButtonEdit;
	TcxDBButtonEdit *NameGuestcxDBButtonEdit;
	TcxDBButtonEdit *NameSostcxDBButtonEdit;
	TcxDBButtonEdit *TypePoscxDBButtonEdit;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TcxDBButtonEdit *NameCelPrcxDBButtonEdit;
	TLabel *Label10;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NamePlatcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGuestcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypePoscxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSostcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCelPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;

		//выбор плательщика
		void ViborPlat(void);
		void __fastcall EndViborPlat(void);
		//выбор гостя
		void ViborGuest(void);
		void __fastcall EndViborGuest(void);

		//выбор категории
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//выбор типа поселения
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);


		//выбор номера
		IHOT_FormaSpiskaSprNF * HOT_FormaSpiskaSprNF;
		void ViborNomer(void);
		void __fastcall EndViborNomer(void);

		//выбор состояния
		IHOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSost(void);
		void __fastcall EndViborSost(void);

		//выбор цели приезда
		IHOT_FormaSpiskaSprCelPriesda * HOT_FormaSpiskaSprCelPriesda;
		void ViborCelPriesda(void);
		void __fastcall EndViborCelPriesda(void);

		enum {ER_NoRekv,ER_Plat,ER_Guest,ER_Cat,ER_TypePos,ER_Nomer,ER_Sost,ER_Cel} EditRekvisit;
			int KolMest;
public:		// User declarations
		__fastcall THOT_FormaElementaTableSostNF(TComponent* Owner);

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
		IHOT_DMTableSostNF * DM;
		void UpdateForm(void);



		bool Prosmotr;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме




};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaElementaTableSostNF *HOT_FormaElementaTableSostNF;
//---------------------------------------------------------------------------
#endif
