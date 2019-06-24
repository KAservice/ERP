//---------------------------------------------------------------------------

#ifndef UREM_FormaSpiskaSprHardwareH
#define UREM_FormaSpiskaSprHardwareH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprHardware.h"
#include "IREM_DMSprGrpHardware.h"
#include "IDMTableExtPrintForm.h"
//----------------------------------------------------------------------------
#include <Menus.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxTreeView.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaSpiskaSprHardware : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNewGrp;
        TToolButton *ToolButtonEdiGrp;
        TToolButton *ToolButtonDeleteGrp;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TPanel *Panel6;
	TPanel *Panel7;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_SHARDWARE;
	TcxGridLevel *cxGrid1Level1;
	TLabel *LabelNameGrp;
	TcxTextEdit *SerNumcxTextEdit;
	TcxTextEdit *SerNum2cxTextEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonPoiskPoSerNum;
	TcxButton *cxButtonPoiskPoSerNum2;
	TcxButton *cxButtonPoiskPoSerNumStr;
	TcxGridDBColumn *cxGrid1DBTableView1FL_NECOND_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM2_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SROKWARRANTY_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1FL_REMONT_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1FL_FICT_REMONT_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_ENG_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1ARTIKUL_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1PARTNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_FIRM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_SKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_TYPE_NOM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_OST;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEdiGrpClick(TObject *Sender);
        void __fastcall ToolButtonDeleteGrpClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);

	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxTreeView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButton6Click(TObject *Sender);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNumClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNum2Click(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNumStrClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		void __fastcall EventEndViborGrp(void);
		void __fastcall EventEndViborElement(void);

		void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();

        void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(void);
		enum{NO,ER_ViborGrp,ER_ViborElement, RekvisitPodborNom} ViborRekvisit;
public:		// User declarations
		__fastcall TREM_FormaSpiskaSprHardware(TComponent* Owner);

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
		UnicodeString TextMessage;

		IREM_DMSprHardware* DM;
		IREM_DMSprGrpHardware *DMGrp;

		__int64 IdGrp;      //текущая группа
		__int64 IdHardware;       //текущий элемент

		bool AllElement;//текущее значение все элементы или нет
        bool Podbor;




		void UpdateForm(void);

		UnicodeString SerNumber1;
		UnicodeString SerNumber2;
        void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaSpiskaSprHardware *REM_FormaSpiskaSprHardware;
//---------------------------------------------------------------------------
#endif
