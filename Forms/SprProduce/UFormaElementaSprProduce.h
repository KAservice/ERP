//---------------------------------------------------------------------------

#ifndef UFormaElementaSprProduceH
#define UFormaElementaSprProduceH
//---------------------------------------------------------------------------

#include "UDM.h"
#include "IDMSprProduce.h"
#include "IDMSprFactorValue.h"
#include "IDMFibConnection.h"
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
class TFormaElementaSprProduce : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
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
	TGroupBox *GroupBox1;
	TToolBar *ToolBar4;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonAddPrice;
	TToolButton *ToolButtonDeletePrice;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1IDFACTOR_SFACTOR_VAL;
	TcxGridDBColumn *cxGrid1DBTableView1VALUE_SFACTOR_VAL;
	TcxGridLevel *cxGrid1Level1;
	TcxDBTextEdit *NameNomcxDBTextEdit;
	TLabel *Label2;
	TcxDBTextEdit *CodecxDBTextEdit;
	TLabel *Label1;
	TcxDBMemo *CommentcxDBMemo;
	TLabel *Label3;
	TcxDBCalcEdit *BelkicxDBCalcEdit;
	TcxDBCalcEdit *GiricxDBCalcEdit;
	TcxDBCalcEdit *UglcxDBCalcEdit;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *NameGrpLabel;
	TToolButton *ToolButtonAddAllFactors;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ToolButtonAddPriceClick(TObject *Sender);
	void __fastcall ToolButtonDeletePriceClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ToolButtonAddAllFactorsClick(TObject *Sender);






private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����




public:		// User declarations
		__fastcall TFormaElementaSprProduce(TComponent* Owner);

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
		IDMSprProduce * DM;
		IDMSprFactorValue * DMSprFactorValue;


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		void UpdateForm(void);

		__int64 IdGrp;
		UnicodeString NameGrp;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprProduce *FormaElementaSprProduce;
//---------------------------------------------------------------------------
#endif
