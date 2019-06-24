//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprNomH
#define UFormaSpiskaSprNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprFirm.h"
#include "IDMSprSklad.h"
#include "IDMSprInetCatalog.h"
#include "UDM.h"
#include "IDMSprNom.h"
#include "IDMSprGrpNom.h"
#include "IFormaPodboraNom.h"
#include "IDMSprPodr.h"
#include <Menus.hpp>
#include "IDMSprGrpBVNom.h"
#include "ISheetEditor.h"
#include "IDMSprScale.h"

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
//---------------------------------------------------------------------------
class TFormaSpiskaSprNom : public TForm
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
        TToolButton *ToolButtonAddSprBV;
        TPopupMenu *PopupMenuSprBV;
        TToolButton *ToolButtonAddSprScale;
        TPopupMenu *PopupMenuSprScale;
	TToolButton *ToolButtonPrint;
	TToolButton *ToolButton5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonCheckOnlyChange;
	TToolButton *ToolButtonClearChange;
	TToolButton *ToolButtonOpenSprNacenka;
	TToolButton *ToolButtonOnlyOstatok;
	TToolButton *ToolButtonPriceSklad;
	TLabel *RegimLabel;
	TPopupMenu *PopupMenuSprFirm;
	TToolButton *ToolButtonViborFirm;
	TToolButton *ToolButtonViborSklad;
	TPopupMenu *PopupMenuSprSklad;
	TcxTreeView *cxTreeView1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1SUMKOL;
	TcxButton *cxButtonClose;
	TcxComboBox *SpisokTypePrice;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonCopyRecord;
	TToolButton *ToolButton7;
	TAction *ActionClose;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM;
	TcxButton *cxButtonVibor;
	TcxGridDBColumn *cxGrid1DBTableView1ID_SNOMINETCAT;
	TToolButton *ToolButton8;
	TPopupMenu *PopupMenuSprInetCatalog;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_STNOM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_PRICE_SKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_MHRAN;
	TcxComboBox *cxComboBoxTypeOst;
	TcxGridDBColumn *cxGrid1DBTableView1REM_OST;
	TLabel *LabelFirma;
	TLabel *LabelSklad;
	TLabel *LabelInetCatalog;
	TToolButton *ToolButtonDelInetCatalog;
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
		//������� �����
		void __fastcall PopupMenuSprBVClick(TObject *Sender);
		void __fastcall PopupMenuSprBVClickSubMenu(TObject *Sender);
		void __fastcall PopupMenuSprBVPopup(TObject *Sender);
		//������� �����
		void __fastcall PopupMenuSprScaleClick(TObject *Sender);
		void __fastcall PopupMenuSprScaleClickSubMenu(TObject *Sender);
		void __fastcall PopupMenuSprScalePopup(TObject *Sender);
	void __fastcall ToolButtonPrintClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonCheckOnlyChangeClick(TObject *Sender);
	void __fastcall ToolButtonClearChangeClick(TObject *Sender);
	void __fastcall ToolButtonOpenSprNacenkaClick(TObject *Sender);
	void __fastcall ToolButtonOnlyOstatokClick(TObject *Sender);
	void __fastcall ToolButtonPriceSkladClick(TObject *Sender);
	//���������� ����
	void __fastcall PopupMenuSprFirmPopup(TObject *Sender);
	void __fastcall PopupMenuSprFirmClick(TObject *Sender);

	//���������� �������
	void __fastcall PopupMenuSprSkladPopup(TObject *Sender);
	void __fastcall PopupMenuSprSkladClick(TObject *Sender);

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
	//���������� �������� �������
	void __fastcall PopupMenuSprInetCatalogPopup(TObject *Sender);
	void __fastcall PopupMenuSprInetCatalogClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1ID_SNOMINETCATCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxComboBoxTypeOstPropertiesChange(TObject *Sender);
	void __fastcall ToolButtonDelInetCatalogClick(TObject *Sender);

private:	// User declarations

IDMTableExtPrintForm * DMTableExtPrintForm;
void RunExternalModule(__int64 id_module, int type_module);


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IDMSprGrpBVNom * DMSprGrpBVNom;
		IDMSprFirm * DMSprFirm;
		IDMSprSklad * DMSprSklad;
		IDMSprInetCatalog * DMSprInetCatalog;

		bool NoUpdateForm;
		void OpenFormElement();
		void OpenFormNewElement();
		void OpenFormNewCopyElement();
		void DeleteElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(void);

		void OpenFormPodboraNom(void);




		int FlagOstatok;
		bool OnlyChange;
		bool OnlyOstatok;
		bool PriceSklad;


		void OpenPrintForm(void);
		void OpenPrintFormOnlyGrp(void);
		void CreateReport(ISheetEditor *prForm, __int64 id_grp);
		void OutputZagolovokReport(ISheetEditor *prForm);
		void OutputStringGrp(ISheetEditor *prForm,
							AnsiString name_grp);
		void OutputString(ISheetEditor *prForm,
							AnsiString code_nom,
							AnsiString name_nom,
							AnsiString name_ed,
							AnsiString price);
		void OutputPodavalReport(ISheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		IDMSprScale * DMSprScale;

		void SaveFormSetup(void);
		void LoadFormSetup(void);

public:		// User declarations
		__fastcall TFormaSpiskaSprNom(TComponent* Owner);

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
        IFormaPodboraNom * FormaPodboraNom;
		IDMSprNom* DM;
		IDMSprGrpNom *DMGrp;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		__int64 IdGrp;      //������� ������
		__int64 IdNom;       //������� �������
		__int64 IdFirm;//����� ��� ��������
		AnsiString NameFirm;
		__int64 IdSklad;//����� ��� ��������
		AnsiString NameSklad;
		__int64 IdInetCatalog;
		UnicodeString NameInetCatalog;

        bool AllElement;//������� �������� ��� �������� ��� ���
		bool Podbor;
		__int64 IdTypePrice;


		void UpdateForm(void);
        void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprNom *FormaSpiskaSprNom;
//---------------------------------------------------------------------------
#endif
