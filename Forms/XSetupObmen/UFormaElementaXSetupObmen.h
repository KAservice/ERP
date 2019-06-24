//---------------------------------------------------------------------------

#ifndef UFormaElementaXSetupObmenH
#define UFormaElementaXSetupObmenH
//---------------------------------------------------------------------------

#include "IDMXSetupObmen.h"
#include "UDM.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
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
#include "cxButtonEdit.hpp"
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
#include "cxMaskEdit.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaXSetupObmen : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameBaseObmencxDBButtonEdit;
	TcxGridDBTableView *cxGrid1DBTableViewBase;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid2DBTableViewTypePrice;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TcxGridDBColumn *cxGrid1DBTableViewBaseNAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid2DBTableViewTypePriceNAME_TPRICE;
	TPopupMenu *InfBasePopupMenu;
	TPopupMenu *TypePricePopupMenu;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TLabel *Label1;
	TcxDBLabel *IdStardIdXTismcxDBLabel;
	TcxDBCheckBox *AllDoccxDBCheckBox;
	TcxDBCheckBox *OutZakPricecxDBCheckBox;
	TcxLabel *cxLabel1;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameBaseObmencxDBButtonEditPropertiesButtonClick(
		  TObject *Sender, int AButtonIndex);


		  void __fastcall InfBasePopupMenuClick(TObject *Sender);
		  void __fastcall TypePricePopupMenuClick(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);
		IDMSprInfBase * DMSprInfBase;
		IDMSprTypePrice * DMSprTypePrice;
public:		// User declarations
		__fastcall TFormaElementaXSetupObmen(TComponent* Owner);

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
		IDMXSetupObmen * DM;
		void UpdateForm(void);
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме







};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaXSetupObmen *FormaElementaXSetupObmen;
//---------------------------------------------------------------------------
#endif
