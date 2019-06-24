//---------------------------------------------------------------------------

#ifndef UART_FormaElementaSprInfBlockH
#define UART_FormaElementaSprInfBlockH
//---------------------------------------------------------------------------
#include "IART_FormaSpiskaSprInfBlockSostav.h"

#include "UDM.h"
#include "IART_DMSprInfBlock.h"
#include "IDMFibConnection.h"
#include "IART_DMSprInfBlockPriv.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
#include "cxPC.hpp"
#include "cxButtonEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxMemo.hpp"
#include "cxImageComboBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxDBLabel.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxSpinEdit.hpp"
#include "cxCurrencyEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TART_FormaElementaSprInfBlock : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonOpenFormaSpiskaElement;
	TcxLabel *cxLabel1;
	TLabel *NameGrpLabel;
	TcxDBTextEdit *KeyWordscxDBTextEdit;
	TcxLabel *cxLabel2;
	TcxDBSpinEdit *IndexcxDBSpinEdit;
	TcxLabel *cxLabel3;
	TcxDBTextEdit *TitlecxDBTextEdit;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxDBTextEdit *GuidcxDBTextEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel9;
	TcxDBTextEdit *WebKeyWordscxDBTextEdit;
	TcxLabel *cxLabel6;
	TcxDBTextEdit *WebTitlecxDBTextEdit;
	TcxDBTextEdit *WebDescrcxDBTextEdit;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxDBCheckBox *cxDBCheckBoxFL_ADD_SITEMAP_ART_IB;
	TBitBtn *BitBtnAdd;
	TBitBtn *BitBtnDel;
	TBitBtn *BitBtnSave;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_GRP_USER_LOOKUP;
	TcxGridDBColumn *cxGrid1DBTableView1SEL_HLP_IB_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1INS_HLP_IB_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1UPD_HLP_IB_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1DEL_HLP_IB_PRIV;
	TcxGridLevel *cxGrid1Level1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonOpenFormaSpiskaElementClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall KeyWordscxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall BitBtnAddClick(TObject *Sender);
	void __fastcall BitBtnDelClick(TObject *Sender);
	void __fastcall BitBtnSaveClick(TObject *Sender);








private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IART_FormaSpiskaSprInfBlockSostav * FormaSpiskaSprInfBlockSostav;
		enum  {ER_NoRekv, ER_EditPageElement} ER_Rekvisit;
public:		// User declarations
		__fastcall TART_FormaElementaSprInfBlock(TComponent* Owner);

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
		IART_DMSprInfBlock * DM;
		IART_DMSprInfBlockPriv * DMPriv;

		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		void UpdateForm(void);

		__int64 IdGrpPage;
		UnicodeString NameGrp;
};
//---------------------------------------------------------------------------
extern PACKAGE TART_FormaElementaSprInfBlock *ART_FormaElementaSprInfBlock;
//---------------------------------------------------------------------------
#endif
