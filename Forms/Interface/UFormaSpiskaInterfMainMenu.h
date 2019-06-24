//---------------------------------------------------------------------------

#ifndef UFormaSpiskaInterfMainMenuH
#define UFormaSpiskaInterfMainMenuH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMInterfMainMenu.h"
#include "IDMInterfMainMenuGrp.h"
#include "IFormaElementaInterfMainMenuGrp.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprGrpUser.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprProgramModule.h"
#include "IFormaSpiskaInterfMainMenuPar.h"
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
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "UDM.h"

//---------------------------------------------------------------------------
class TFormaSpiskaInterfMainMenu : public TForm
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
	TcxLabel *cxLabel2;
	TcxImageComboBox *NameModulcxImageComboBox;
	TToolButton *ToolButton5;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TToolButton *ToolButton6;
	TAction *ActionCreateFullStandartMainMenu;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_INTERF_MAINMENU;
	TcxGridDBColumn *cxGrid1DBTableView1SHORTCUT_INTERF_MAINMENU;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_INTERF_MAINMENU;
	TToolButton *ToolButtonClearMenu;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1FL_OPEN_EL_INTERF_MAINMENU;
	TcxGridDBColumn *cxGrid1DBTableView1IDEL_INTERF_MAINMENU;
	TToolButton *ToolButtonOpenSpisokParam;
	TcxGridDBColumn *cxGrid1DBTableView1GUIDMOD_INTERF_MAINMENU;
	TcxGridDBColumn *cxGrid1DBTableView1TYPEMOD_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1PATCH_PROGRAM_MODULE;
        void __fastcall FormCreate(TObject *Sender);
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

		//������� ����� � �������
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
	void __fastcall ToolButtonClearMenuClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonOpenSpisokParamClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

	IDMSprGrpUser *DMGrpUser;
		void UpdateDerevo(void);


		//�������������� �����
		IFormaElementaInterfMainMenuGrp * FormaGrpElementa;
		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();


		void DeleteElement();

		void CreateFullStandartMainMenu(int application, __int64 id_grp_user);
		void CreateFullStandartMainMenu_PAdmin(__int64 id_grp_user);
		void CreateFullStandartMainMenu_ARMKas(__int64 id_grp_user);
		void CreateFullStandartMainMenu_WebARMKas(__int64 id_grp_user);
		void CreateFullStandartMainMenu_AdmHotel(__int64 id_grp_user);
		void CreateFullStandartMainMenu_Remont(__int64 id_grp_user);
		bool ClearMainMenu(int application, __int64 id_grp_user);
		__int64 InsertGrpMainMenu(int application, __int64 id_grp_user,
									__int64 id_grp, UnicodeString name_main_menu);
		void InsertItemMainMenu(int application, __int64 id_grp_user,
									__int64 id_grp, UnicodeString name_main_menu,
									GUID guid_module);

		IFormaSpiskaSprProgramModule * SpisokProgramModule;
		void ViborProgramModule(void);
		void EndViborProgramModule(void);

		enum {ER_NoRekv,ER_ProgramModule,ER_Grp, ER_SpisokParameter, No} EditRekvisit;


		IFormaSpiskaInterfMainMenuPar * SpisokParameter;
		void ViborSpisokParameter(void);
		void EndViborSpisokParameter(void);

public:		// User declarations
		__fastcall TFormaSpiskaInterfMainMenu(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//�� ���� ����� ������� ������ ��� ������
		//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
		int ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������

		IDMInterfMainMenu * DM;
		IDMInterfMainMenuGrp * DMGrp;

		void UpdateForm(void);

		__int64 IdGrpUser;
		__int64 IdGrp;  //������� ������
		int NumApplication;
		__int64 IdElement;
		bool AllElement;//������� �������� ��� �������� ��� ���



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaInterfMainMenu *FormaSpiskaInterfMainMenu;
//---------------------------------------------------------------------------
#endif
