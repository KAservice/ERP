//---------------------------------------------------------------------------

#ifndef UREM_FormaSpiskaSprProducerConditionH
#define UREM_FormaSpiskaSprProducerConditionH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IREM_DMSprProducerCondition.h"
#include "IREM_DMSprProducerConditionGrp.h"
#include "IDMSprProducer.h"
#include "IREM_FormaElementaSprProducerConditionGrp.h"
#include "IREM_FormaElementaSprProducerCondition.h"
#include "IDMTableExtPrintForm.h"
#include "IDMFibConnection.h"
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
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TREM_FormaSpiskaSprProducerCondition : public TForm
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
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SPRCONDITION;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxComboBox *NameGroupElementcxComboBox;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_ENG_REM_SPRCONDITION;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SPRCONDITION;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_SPRCONDITION;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewScaleClick(TObject *Sender);
        void __fastcall ToolButtonEdiScaleClick(TObject *Sender);
        void __fastcall ToolButtonDeleteScaleClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxTreeView1KeyPress(TObject *Sender, char &Key);

		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameGroupElementcxComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ToolButtonNewClick(TObject *Sender);
	void __fastcall ToolButtonEditClick(TObject *Sender);
	void __fastcall ToolButtonDeleteClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IDMTableExtPrintForm * DMTableExtPrintForm;
		void RunExternalModule(__int64 id_module, int type_module);

		IDMSprProducer * DMGroupElement;

 		void UpdateDerevo(void);

		//�������������� �����
		IREM_FormaElementaSprProducerConditionGrp * FormaGrpElementa;
		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();
		void EndEditGrp(void);

		//�������������� ��������
		IREM_FormaElementaSprProducerCondition * FormaElementa;
		void OpenFormElement(void);
		void OpenFormNewElement(void);
		void DeleteElement(void);
		void EndEditElement(void);

		enum{NO,ViborGroupElement,ViborElement, ViborGrp} ViborRekvisit;

public:		// User declarations
		__fastcall TREM_FormaSpiskaSprProducerCondition(TComponent* Owner);
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

		IREM_DMSprProducerCondition* DM;
		IREM_DMSprProducerConditionGrp* DMGrp;
		bool flVibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		bool flPodbor;

		__int64 IdGroupElement;
		UnicodeString NameGroupElement;
		__int64 IdGrp;  //������� ������
        __int64 IdElement;
		bool flAllElement;//������� �������� ��� �������� ��� ���


		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaSpiskaSprProducerCondition *REM_FormaSpiskaSprProducerCondition;
//---------------------------------------------------------------------------
#endif
