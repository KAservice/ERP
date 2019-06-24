//---------------------------------------------------------------------------

#ifndef UFormaPrintPriceAH
#define UFormaPrintPriceAH
//---------------------------------------------------------------------------
#include "UFormaSpiskaSprNom.h"
#include "UFormaSpiskaSprGrpNom.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "UFormaInputText.h"

#include "UDMSprFirm.h"
#include "UDMSprTypePrice.h"
#include "UFormaGurDocPer.h"
#include "UFormaGurDocPrihNakl.h"
#include "UDMSprScale.h"
#include "UDMTableExtPrintForm.h"
#include "UGlobalConstant.h"
//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
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
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Menus.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------


                
class TFormaPrintPriceA : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *AddNomToolButton;
        TToolButton *ToolButton2;
        TToolButton *AddGrpToolButton;
        TToolButton *DelNomToolButton;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonPrintNumber2;
        TToolButton *ToolButtonPrintNumber3;
        TToolButton *ToolButtonPrintNumber4;
        TToolBar *ToolBar2;
        TToolButton *ToolButton5;
        TToolButton *ToolButtonPrintBarCode1;
        TToolButton *ToolButton7;
	TComboBox *FirmaComboBox;
	TComboBox *TypePriceComboBox;
	TLabel *Label1;
	TLabel *Label2;
	TToolButton *ToolButtonPrintPrice5;
	TToolButton *ToolButtonPrintPrice6;
	TToolButton *ToolButtonPrintPrice7;
	TToolButton *ViborPeremToolButton;
	TToolButton *ViborPrihNaklToolButton;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *cxGrid1TableView1IDNOM;
	TcxGridColumn *cxGrid1TableView1NAMENOM;
	TcxGridColumn *cxGrid1TableView1IDED;
	TcxGridColumn *cxGrid1TableView1NAMEED;
	TcxGridColumn *cxGrid1TableView1GRP;
	TcxGridColumn *cxGrid1TableView1KOL;
	TcxGridColumn *cxGrid1TableView1Column1;
	TToolButton *ClearToolButton;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label3;
	TComboBox *ScaleComboBox;
	TToolButton *ToolButton6;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AddNomToolButtonClick(TObject *Sender);
        void __fastcall DelNomToolButtonClick(TObject *Sender);
        void __fastcall AddGrpToolButtonClick(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber2Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber3Click(TObject *Sender);
        void __fastcall ToolButtonPrintNumber4Click(TObject *Sender);
        void __fastcall ToolButtonPrintBarCode1Click(TObject *Sender);
	void __fastcall FirmaComboBoxChange(TObject *Sender);
	void __fastcall TypePriceComboBoxChange(TObject *Sender);
	void __fastcall ToolButtonPrintPrice5Click(TObject *Sender);
	void __fastcall ToolButtonPrintPrice6Click(TObject *Sender);
	void __fastcall ToolButtonPrintPrice7Click(TObject *Sender);
	void __fastcall cxGrid1TableView1GRPCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall ViborPeremToolButtonClick(TObject *Sender);
	void __fastcall ViborPrihNaklToolButtonClick(TObject *Sender);
	void __fastcall ClearToolButtonClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ScaleComboBoxChange(TObject *Sender);

	//внешние формы и скрипты
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);
private:	// User declarations

	TDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);
public:		// User declarations
		__fastcall TFormaPrintPriceA(TComponent* Owner);


	IDMFibConnection * DM_Connection;
	IkanCom * InterfaceGlobalCom;

	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;

        void UpdateGrid(void);

		void __fastcall EndEdit(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        enum  {ViborNom, ViborGrpNom, ViborEd, InputKol, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TFormaInputText * FormaInputText;

		TFormaSpiskaSprNom  *FormaViborSprNom;
        void OpenFormViborSprNom(void);

        TFormaSpiskaSprGrpNom * FormaViborGrpNomSpr;
        void OpenFormViborGrpNom(void);

		TDMSprFirm * DMSprFirm;
		TDMSprTypePrice *  DMSprTypePrice;
		TDMSprScale * DMSprScale;

		//выбор документа перемещени€
		TFormaGurDocPer * FormaGurDocPer;
		void ViborDocPerem(void);
		void __fastcall EndViborDocPerem(TObject *Sender);

		//выбор документа ѕриходна€ накладна€
		TFormaGurDocPrihNakl *FormaGurDocPrihNakl;
		void ViborDocPrihNakl(void);
		void __fastcall EndViborDocPrihNakl(TObject *Sender);

		void ZapolnitList(void);
		void ZapolnitListForExtModule(void);

};



//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintPriceA *FormaPrintPriceA;
//---------------------------------------------------------------------------
#endif
