//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprProducerNomH
#define UFormaSpiskaSprProducerNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IDMSprProducerNom.h"
#include "IDMSprProducerNomGrp.h"
#include "IDMSprProducer.h"

#include "IDMFibConnection.h"
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
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaSprProducerNom : public TForm
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
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *RegimLabel;
	TcxTreeView *cxTreeView1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRED;
	TcxGridDBColumn *cxGrid1DBTableView1VALUE_SPRPRICE;
	TcxButton *cxButtonClose;
	TcxComboBox *SpisokTypePrice;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonCopyRecord;
	TToolButton *ToolButton7;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1ID_SPRNOM;
	TcxButton *cxButtonVibor;
	TcxGridDBColumn *cxGrid1DBTableView1ART_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1BARCODE_SPREDED;
	TcxComboBox *NameGroupElementcxComboBox;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1FL_DOSTUPNO_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_ZAKUP_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_ANALOG_STR_SPRNOM;
	TcxTextEdit *InputStrcxTextEdit;
	TcxButton *cxButtonPoisk;
	TLabel *Label1;
	TcxGridDBColumn *cxGrid1DBTableView1ISM_SPRNOM;
	TLabel *LabelObnovleno;
	TToolButton *ToolButtonPoiskPoModel;
	TcxGridDBColumn *cxGrid1DBTableView1ART2_SPRNOM;
	TToolButton *ToolButtonSetDostupno0;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEdiGrpClick(TObject *Sender);
        void __fastcall ToolButtonDeleteGrpClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);

	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxTreeView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButton6Click(TObject *Sender);

		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

	void __fastcall ToolButtonCopyRecordClick(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall SpisokTypePricePropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxButtonViborClick(TObject *Sender);
	void __fastcall NameGroupElementcxComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxButtonPoiskClick(TObject *Sender);
	void __fastcall ToolButtonPoiskPoModelClick(TObject *Sender);
	void __fastcall ToolButtonSetDostupno0Click(TObject *Sender);

private:	// User declarations

IDMTableExtPrintForm * DMTableExtPrintForm;
void RunExternalModule(__int64 id_module, int type_module);


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����



		bool NoUpdateForm;
		void OpenFormElement();
		void OpenFormNewElement();
		void OpenFormNewCopyElement();
		void DeleteElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(void);


		void SaveFormSetup(void);
		void LoadFormSetup(void);

		IDMSprProducer * DMGroupElement;

public:		// User declarations
		__fastcall TFormaSpiskaSprProducerNom(TComponent* Owner);

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
		IDMSprProducerNom* DM;
		IDMSprProducerNomGrp *DMGrp;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		__int64 IdGrp;      //������� ������
		__int64 IdNom;       //������� �������
		__int64 IdGroupElement;

        bool AllElement;//������� �������� ��� �������� ��� ���
		bool Podbor;
		__int64 IdTypePrice;


		void UpdateForm(void);
        void ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprProducerNom *FormaSpiskaSprProducerNom;
//---------------------------------------------------------------------------
#endif
