//---------------------------------------------------------------------------

#ifndef UFormaOperCreditCardH
#define UFormaOperCreditCardH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDisplayPok.h"
#include "IScaner.h"
#include "IFiskReg.h"
#include "IDMSprDiscountCard.h"
#include "IFormaInputDiscountCard.h"
//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaOperCreditCard : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *NameKlientLabel;
	TLabel *NameCardLabel;
	TLabel *TecDolgLabel;
	TLabel *MaxDolgLabel;
	TcxCalcEdit *SummacxCalcEdit;
	TLabel *Label6;
	TcxButton *cxButton1;
	TActionList *ActionList1;
	TAction *ActionViborCardPoCodu;
	TLabel *Label2;
	TLabel *LabelMessage;
	TLabel *Label5;
	TLabel *Label7;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionViborCardPoCoduExecute(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
	IFiskReg  *glFR;
	IScaner * glScaner;
	IDisplayPok * glDisplayPok;

	//выбор карты
	IFormaInputDiscountCard * FormaInputDiscountCard;
	void  ViborCard(void);
	void __fastcall EndViborDiscountCard(void);
	IDMSprDiscountCard * DMSprDiscountCard;


	bool DocPrint;
	bool DocSave;
	bool Oplatit(void);
	bool CreateDoc(void);
	bool PrintCheck(void);
	bool PrintFiscalCheck(void);
    bool PrintNoFiscalCheck(void);
public:		// User declarations
	__fastcall TFormaOperCreditCard(TComponent* Owner);


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




};
//---------------------------------------------------------------------------
extern PACKAGE TFormaOperCreditCard *FormaOperCreditCard;
//---------------------------------------------------------------------------
#endif
