//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprNomPropertiesValueH
#define UFormaSpiskaSprNomPropertiesValueH
//---------------------------------------------------------------------------

#include "IDMSprNomPropertiesValue.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprNom.h"
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
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaSprNomPropertiesValue : public TForm
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
        TLabel *LabelNom;
        TToolButton *ToolButton2;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPROPVALUELIST;
	TcxGridDBColumn *cxGrid1DBTableView1VALTEXT_SNOMPROPVALUE;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPROP;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonClose;
	TToolButton *ToolButton3;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_SNOMPROPVALUE;
	TToolButton *ToolButton4;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFOR_PRINT_SPROP;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPROP_GRP;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_FOR_PRINT_SPROP_GRP;
	TcxGridDBColumn *cxGrid1DBTableView1Column1;
	TcxGridDBColumn *cxGrid1DBTableView1Column2;
	TcxGridDBColumn *cxGrid1DBTableView1Column3;
	TcxGridDBColumn *cxGrid1DBTableView1Column4;
	TcxGridDBColumn *cxGrid1DBTableView1Column5;
	TToolButton *ToolButtonCopy;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

		  		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall ToolButtonCopyClick(TObject *Sender);

private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

			bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		        void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();


		IFormaSpiskaSprNom *FormaSpiskaSprNom;
		void OpenFormSpiskaSprNom(void);
		void EndViborCopyNom(void);

		enum  {ER_NoRekv,ER_Nom,ER_Element, NO} EditRekvisit;

public:		// User declarations
		__fastcall TFormaSpiskaSprNomPropertiesValue(TComponent* Owner);

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
		IDMSprNomPropertiesValue * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		__int64 IdNom;
		UnicodeString HeaderText;

        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprNomPropertiesValue *FormaSpiskaSprNomPropertiesValue;
//---------------------------------------------------------------------------
#endif
