//---------------------------------------------------------------------------

#ifndef UREM_FormaInfoPriemH
#define UREM_FormaInfoPriemH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurZ.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMSprProducer.h"
#include "IDMSprBrand.h"
#include "IREM_DMSprProducerModelGrp.h"
#include "IREM_DMSprProducerModel.h"
#include "IREM_DMSprProducerModelPropertiesValue.h"
#include "IREM_DMSprProducerModelInfBlock.h"

#include "IREM_DMSprTypeDevice.h"
#include "IREM_DMSprModel2Grp.h"
#include "IREM_DMSprModel2.h"
#include "IREM_DMSprModelPropertiesValue.h"
#include "IREM_DMSprModelInfBlock.h"
#include "IDMDataSet.h"
#include "IART_FormaSpiskaSprInfBlockSostav.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
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
#include "UREM_FormaZayavka.h"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxPC.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxMemo.hpp"
//---------------------------------------------------------------------------
class TREM_FormaInfoPriem : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButton4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonAddNewZ;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonOpenGurAllDoc;
	TcxTextEdit *ModelcxTextEdit;
	TcxTextEdit *SerNumcxTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *SerNum2cxTextEdit;
	TcxButtonEdit *NameHardwarecxButtonEdit;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel3;
	TcxTextEdit *KlientNamecxTextEdit;
	TcxButton *cxButtonPoiskPoSerNum;
	TcxButton *cxButtonPoiskPoSerNum2;
	TcxTextEdit *NumGarDoccxTextEdit;
	TcxLabel *cxLabel6;
	TcxButton *cxButtonPoNumGarDoc;
	TToolButton *ToolButtonCopyZayavka;
	TToolButton *ToolButtonZapShapkuNaOsnZayavki;
	TcxCheckBox *cxCheckBoxIspSprHardware;
	TcxLabel *cxLabelHint;
	TToolButton *ToolButtonCreateNaOsnSprHardware;
	TcxLabel *cxLabelSerNum1;
	TcxLabel *cxLabelSerNum2;
	TcxButtonEdit *NameSkladcxButtonEdit;
	TcxLabel *cxLabel7;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label16;
	TcxLookupComboBox *ProducercxLookupComboBox;
	TcxLookupComboBox *BrandcxLookupComboBox;
	TLabel *Label2;
	TcxLookupComboBox *GroupcxLookupComboBox;
	TcxLookupComboBox *PrModelcxLookupComboBox;
	TcxLabel *cxLabel4;
	TcxLookupComboBox *TypeDevice2cxLookupComboBox;
	TcxLookupComboBox *GroupModel2cxLookupComboBox;
	TcxLookupComboBox *Model2cxLookupComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_FL_POVTOR;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_SBRAND;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_STREMONT;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_PREFIKS_NUM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NUM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_POS;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_REM_SMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_MODEL;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SERNUM1;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SERNUM2;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_REMSSOST;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SUM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KLIENT_NAME;
	TcxGridLevel *cxGrid1Level1;
	TcxTabSheet *cxTabSheet3;
	TPanel *Panel8;
	TcxButton *cxButtonUpdateInfblock;
	TcxGrid *cxGrid5;
	TcxGridDBTableView *InfocxGridDBTableView;
	TcxGridLevel *cxGridLevel3;
	TcxTabSheet *cxTabSheet5;
	TPanel *Panel6;
	TcxButton *cxButtonUpdatePrInfBlock;
	TcxGrid *cxGrid3;
	TcxGridDBTableView *ZipcxGrid3DBTableView;
	TcxGridLevel *cxGrid3Level1;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_ISTOCHNIK;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_NAME_MODEL;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_NAME_PRMODEL;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_NAME_GRP_INFO;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_NAME;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_INFO_VALUE_IS_SPR;
	TcxGridDBColumn *InfocxGridDBTableViewOUT_INFO_TEXT;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_ISTOCHNIC;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_NAME_MODEL;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_NAME_PRMODEL;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_DOSTUPNO;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_NAME;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_TYPE_TABLE;
	TToolButton *ToolButtonCreateZayavkaPredv;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_SKLAD;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_OSTATOK;
	TcxGridDBColumn *ZipcxGrid3DBTableViewOUT_NAME_NOM;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonAddNewZClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ToolButton5Click(TObject *Sender);
					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1OUT_OUTCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1FL_TREB_KONS_KL_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxButtonPoiskPoSerNumClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNum2Click(TObject *Sender);
	void __fastcall ToolButtonCopyZayavkaClick(TObject *Sender);
	void __fastcall ToolButtonZapShapkuNaOsnZayavkiClick(TObject *Sender);
	void __fastcall NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonCreateNaOsnSprHardwareClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1SOST_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ProducercxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall GroupcxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypeDevice2cxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall GroupModel2cxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxButtonUpdateInfblockClick(TObject *Sender);
	void __fastcall InfocxGridDBTableViewDblClick(TObject *Sender);
	void __fastcall cxButtonUpdatePrInfBlockClick(TObject *Sender);
	void __fastcall ToolButtonCreateZayavkaPredvClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxButtonPoNumGarDocClick(TObject *Sender);
	void __fastcall ToolButtonOpenGurAllDocClick(TObject *Sender);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv,ER_ViborHardware,ER_Sklad, ER_ShowPage} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;

		void OpenFormDoc();

		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);
		__int64 IdVibHardware;

				//выбор склада
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);


		IDMSprProducer * DMSprProducer;
		IDMSprBrand * DMSprBrand;
		IREM_DMSprProducerModelGrp * REM_DMSprProducerModelGrp;
		IREM_DMSprProducerModel * REM_DMSprProducerModel;

		IREM_DMSprTypeDevice * REM_DMSprTypeDevice;
		IREM_DMSprModel2Grp * REM_DMSprModel2Grp;
		IREM_DMSprModel2 * REM_DMSprModel2;




		IDMDataSet * DMInfo;
		IDMDataSet * DMZip;
		IDMDataSet * DMGurZ;
		IART_FormaSpiskaSprInfBlockSostav * FormaSpiskaSprInfBlockSostav;
	   void EndCloseFormShow(void);
	   void ShowPage();

public:		// User declarations
		__fastcall TREM_FormaInfoPriem(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		__int64 IdDoc;

        TDateTime PosNach;
		TDateTime PosCon;
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		__int64 IdSklad;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaInfoPriem *REM_FormaInfoPriem;
//---------------------------------------------------------------------------
#endif
