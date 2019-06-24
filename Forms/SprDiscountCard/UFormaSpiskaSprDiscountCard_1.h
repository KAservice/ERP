//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprDiscountCard_1H
#define UFormaSpiskaSprDiscountCard_1H
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMSprDiscountCard_1.h"
#include "IDMSprGrpKlient.h"
#include "IDMTableExtPrintForm.h"





//-----------------------------------------------------------------------------
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
#include "cxContainer.hpp"
#include "cxTreeView.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCheckBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaSprDiscountCard_1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *LabelNameGrp;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxTreeView *cxTreeView1;
	TPanel *Panel6;
	TcxButton *cxButtonClose;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1SHCODE_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1NACH_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1CON_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1PRSK_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1ACT_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SVID_DCARD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1ID_SDISCOUNT_CARD;
	TToolBar *ToolBar3;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonNewGrp;
	TToolButton *ToolButtonEditGrp;
	TToolButton *ToolButtonDelGrp;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButtonNew;
	TToolButton *ToolButtonEdit;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton4;
	TToolButton *ToolButtonAllElement;
	TToolButton *ToolButtonUpdateForm;
	TToolButton *ToolButtonExtModule;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1SINGLE_SDISCOUNT_CARD;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEditGrpClick(TObject *Sender);
        void __fastcall ToolButtonDelGrpClick(TObject *Sender);
        void __fastcall ToolButtonAllElementClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxTreeView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButtonUpdateFormClick(TObject *Sender);

		//������� ����� � �������
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

			bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

				void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(void);
public:		// User declarations
		__fastcall TFormaSpiskaSprDiscountCard_1(TComponent* Owner);

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
		IDMSprDiscountCard_1* DM;
		IDMSprGrpKlient *DMGrp;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		__int64 IdGrpKlient;    //������� ������
		__int64 IdDiscountCard;
		
		bool AllElement;//������� �������� ��� �������� ��� ���

		void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprDiscountCard_1 *FormaSpiskaSprDiscountCard_1;
//---------------------------------------------------------------------------
#endif
