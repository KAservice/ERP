//---------------------------------------------------------------------------

#ifndef UHOT_FormaElementaSprPrOsnUslugH
#define UHOT_FormaElementaSprPrOsnUslugH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IFormaSpiskaSprNom.h"
#include "IHOT_DMSprPrOsnUslug.h"
#include "IFormaSpiskaSprTypePrice.h"
//-----------------------------------------------------------------------------
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
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaElementaSprPrOsnUslug : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel1;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TPanel *Panel2;
	TcxDBButtonEdit *NameCatcxDBButtonEdit;
	TLabel *Label3;
	TLabel *Label2;
	TcxDBButtonEdit *NameTypePosNomcxDBButtonEdit;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TcxDBButtonEdit *NameNomPrcxDBButtonEdit;
	TcxDBButtonEdit *NameNomBrcxDBButtonEdit;
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TcxButton *cxButtonSave;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameCatcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTypePosNomcxDBButtonEditPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall NameNomPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomBrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		//выбор категории
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//выбор типа поселения
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);

		//выбор номенклатуры проживания
		IFormaSpiskaSprNom * FormaSpiskaSprNomPr;
		void ViborNomPr(void);
		void __fastcall EndViborNomPr(void);

		//выбор номенклатуры бронирования
		IFormaSpiskaSprNom * FormaSpiskaSprNomBr;
		void ViborNomBr(void);
		void __fastcall EndViborNomBr(void);

		enum {ER_NoRekv,ER_Cat,ER_TypePosel,ER_NomProg,ER_NomBron,ER_No} EditRekvisit;

		__int64 IdNom;
public:		// User declarations
		__fastcall THOT_FormaElementaSprPrOsnUslug(TComponent* Owner);

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
		IHOT_DMSprPrOsnUslug * DM;
		void UpdateForm(void);
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме






};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaElementaSprPrOsnUslug *HOT_FormaElementaSprPrOsnUslug;
//---------------------------------------------------------------------------
#endif
