//---------------------------------------------------------------------------

#ifndef UREM_FormaSpiskaSprHardwareIspH
#define UREM_FormaSpiskaSprHardwareIspH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprHardwareIsp.h"
#include "UDM.h"
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
#include <ActnList.hpp>
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
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaSpiskaSprHardwareIsp : public TForm
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
	TLabel *LabelModel;
        TToolButton *ToolButton2;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1FL_OTCH_PR_REM_SHARDWARE_ISP;
	TcxGridDBColumn *cxGrid1DBTableView1FL_REAL_ISP_REM_SHARDWARE_ISP;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_SHARDWARE_ISP;
	TAction *ActionClose;
	TcxButton *cxButton1;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_SHARDWARE_ISP;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_STYPUSLOV;
	TcxGridDBColumn *cxGrid1DBTableView1DESCR_REM_SHARDWARE_ISP;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_SHARDWARE_ISP;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1PREFIKS_NUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_STR_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

        void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();

public:		// User declarations
		__fastcall TREM_FormaSpiskaSprHardwareIsp(TComponent* Owner);

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
        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IREM_DMSprHardwareIsp * DM;
		__int64 IdOwner;

		UnicodeString TextMessage;


        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaSpiskaSprHardwareIsp *REM_FormaSpiskaSprHardwareIsp;
//---------------------------------------------------------------------------
#endif
