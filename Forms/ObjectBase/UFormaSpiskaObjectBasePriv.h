//---------------------------------------------------------------------------

#ifndef UFormaSpiskaObjectBasePrivH
#define UFormaSpiskaObjectBasePrivH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMObjectBasePriv.h"
#include "IDMObjectBaseGrp.h"
#include "IFormaElementaObjectBaseGrp.h"
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
#include "cxCheckBox.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaObjectBasePriv : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNewScale;
        TToolButton *ToolButtonEdiScale;
        TToolButton *ToolButtonDeleteScale;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxTreeView *cxTreeView1;
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
	TToolButton *ToolButton5;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TToolButton *ToolButton6;
	TAction *ActionCreateFullStandartMainMenu;
	TcxImageComboBox *ApplicationcxImageComboBox;
	TcxLabel *cxLabel2;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1INS_OBJECT_BASE_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1EDIT_OBJECT_BASE_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1DEL_OBJECT_BASE_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1EXEC_OBJECT_BASE_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1NUMBER_OBJECT_BASE_PRIV;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_PROGRAM_MODULE;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewScaleClick(TObject *Sender);
        void __fastcall ToolButtonEdiScaleClick(TObject *Sender);
        void __fastcall ToolButtonDeleteScaleClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxTreeView1KeyPress(TObject *Sender, char &Key);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
          TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionCreateFullStandartMainMenuExecute(TObject *Sender);
	void __fastcall ApplicationcxImageComboBoxPropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);



private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		void UpdateDerevo(void);


		//редактирование групп
		IFormaElementaObjectBaseGrp * FormaGrpElementa;
		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();


		void DeleteElement();

		void CreateFullStandartPriv(int application, __int64 id_grp_user);
		void CreateFullStandartPriv_Appl(__int64 id_grp_user);
		void CreateFullStandartPriv_WebAppl(__int64 id_grp_user);
		bool ClearPriv(int application,__int64 id_grp_user);
		__int64 InsertGrpObject(__int64 id_grp, UnicodeString name_grp);
		void InsertItemPriv(int application, __int64 id_grp_user,
									__int64 id_grp,
									int number_object);

		IDMSprGrpUser *DMGrpUser;


		IFormaSpiskaSprProgramModule * SpisokProgramModule;
		void ViborProgramModule(void);
		void EndViborProgramModule(void);

		enum {ER_NoRekv,ER_ProgramModule,ER_Grp, No} EditRekvisit;

public:		// User declarations
		__fastcall TFormaSpiskaObjectBasePriv(TComponent* Owner);

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
		IDMObjectBasePriv * DM;
		IDMObjectBaseGrp * DMGrp;



		__int64 IdGrpUser;
		__int64 IdGrp;  //текущая группа
		int NumApplication;
		__int64 IdElement;
        bool AllElement;

		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaObjectBasePriv *FormaSpiskaObjectBasePriv;
//---------------------------------------------------------------------------
#endif
