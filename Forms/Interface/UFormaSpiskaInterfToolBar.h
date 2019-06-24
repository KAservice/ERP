//---------------------------------------------------------------------------

#ifndef UFormaSpiskaInterfToolBarH
#define UFormaSpiskaInterfToolBarH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMInterfToolBar.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprGrpUser.h"
#include "IFormaSpiskaSprProgramModule.h"
//----------------------------------------------------------------------------
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
#include "cxButtonEdit.hpp"
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
#include <Menus.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLabel.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaInterfToolBar : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton4;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxLookupComboBox *NameGrpUsercxLookupComboBox;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxImageComboBox *NameModulcxImageComboBox;
	TToolButton *ToolButton5;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TToolButton *ToolButton6;
	TAction *ActionCreateFullStandartMainMenu;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1MODUL_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1HINT_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1IMAGEINDEX_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1PATCH_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1GUIDMOD_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1IDEL_INTERF_TOOLBAR;
	TcxGridDBColumn *cxGrid1DBTableView1FL_OPEN_EL_INTERF_TOOLBAR;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall NameModulcxImageComboBoxPropertiesEditValueChanged(
          TObject *Sender);
	void __fastcall NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
          TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionCreateFullStandartMainMenuExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);
	IDMSprGrpUser *DMGrpUser;

		void DeleteElement();

		void CreateFullStandartToolBar(int application, __int64 id_grp_user);
		void CreateFullStandartToolBar_PAdmin(__int64 id_grp_user);
		void CreateFullStandartToolBar_ARMKas(__int64 id_grp_user);
		bool ClearToolBar(int application, __int64 id_grp_user);
		void InsertItemToolBar(int application, __int64 id_grp_user,
									UnicodeString name_tool_bar,
									UnicodeString str_guid,
									UnicodeString hint,
									int image_index,
									int index_sort);

		IFormaSpiskaSprProgramModule * SpisokProgramModule;
		void ViborProgramModule(void);
		void EndViborProgramModule(void);

		enum {ER_NoRekv,ER_ProgramModule, No} EditRekvisit;
public:		// User declarations
		__fastcall TFormaSpiskaInterfToolBar(TComponent* Owner);

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

		IDMInterfToolBar * DM;




		__int64 IdGrpUser;
		int NumApplication;
		__int64 IdElement;

		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaInterfToolBar *FormaSpiskaInterfToolBar;
//---------------------------------------------------------------------------
#endif
