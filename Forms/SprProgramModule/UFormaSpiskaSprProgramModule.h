//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprProgramModuleH
#define UFormaSpiskaSprProgramModuleH

#include "IDMSprProgramModule.h"
#include "IDMFibConnection.h"
//--------------------------------------------------------------------------
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
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
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxStyles.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
#include "UDMSprProgramModule.h"
#include "UDM.h"
#include "cxImageComboBox.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaSprProgramModule : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1PROGID_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1MODULE_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1PATCH_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TToolButton *ToolButtonAddAllProgramModule;
	TToolButton *ToolButtonClearSpr;
	TcxGridDBColumn *cxGrid1DBTableView1GUID_PROGRAM_MODULE;
	TcxGridDBColumn *cxGrid1DBTableView1TYPEMOD_PROGRAM_MODULE;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ToolButtonAddAllProgramModuleClick(TObject *Sender);
	void __fastcall ToolButtonClearSprClick(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

public:		// User declarations
		__fastcall TFormaSpiskaSprProgramModule(TComponent* Owner);

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

		//������� ���������
		IDMSprProgramModule * DM;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

        void OpenFormElement();
        void OpenFormNewElement();
		void DeleteElement();


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprProgramModule *FormaSpiskaSprProgramModule;
//---------------------------------------------------------------------------
#endif
