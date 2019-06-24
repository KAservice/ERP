//---------------------------------------------------------------------------

#ifndef UREM_FormaGurZH
#define UREM_FormaGurZH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurZ.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMUserSetup.h"
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
//---------------------------------------------------------------------------
class TREM_FormaGurZ : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonParamOtbor;
        TToolButton *ToolButtonOtbor;
        TLabel *StrOtborLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonRefresh;
	TToolButton *ToolButtonAddNewZ;
	TToolButton *ToolButton3;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SKLAD_PR;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REMSSOST;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1KLIENT_NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM2_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z;
	TToolButton *ToolButton5;
	TPopupMenu *PopupMenuCreateNewDocRemont;
	TMenuItem *PMCreateDocZPost;
	TMenuItem *PMCreateDocZVid;
	TMenuItem *PMCreateDocZPer;
	TMenuItem *PMCreateDocZStart;
	TMenuItem *PMCreateDocZEnd;
	TMenuItem *PMCreateDocZOper;
	TMenuItem *PMCreateDocZTreb;
	TMenuItem *PMCreateDocZAktPr;
	TMenuItem *PMCreateDocZVosvrZap;
	TToolButton *ToolButtonOpenGurAllDoc;
	TcxLabel *cxLabel4;
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
	TcxButton *cxButtonPoiskPoModel;
	TcxButton *cxButtonPoiskPoKlientu;
	TcxButton *cxButtonPoiskPoHardware;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEDILER;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_STREMONT;
	TcxGridDBColumn *cxGrid1DBTableView1PREFIKS_NUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SBRAND;
	TcxGridDBColumn *cxGrid1DBTableView1FL_POVTOR;
	TcxGridDBColumn *cxGrid1DBTableView1FL_ADDREPORT;
	TcxTextEdit *NumGarDoccxTextEdit;
	TcxLabel *cxLabel6;
	TcxButton *cxButtonPoNumGarDoc;
	TcxGridDBColumn *cxGrid1DBTableView1FL_FICTIV_REM_Z;
	TToolButton *ToolButtonCopyZayavka;
	TToolButton *ToolButtonCreateNewNaOsnDanForm;
	TToolButton *ToolButtonZapShapkuNaOsnZayavki;
	TToolButton *ToolButtonOpenNew;
	TcxCheckBox *cxCheckBoxIspSprHardware;
	TcxLabel *cxLabelHint;
	TToolButton *ToolButtonCreateNaOsnSprHardware;
	TcxLabel *cxLabelSerNum1;
	TcxLabel *cxLabelSerNum2;
	TcxGridDBColumn *cxGrid1DBTableView1FL_NADO_OTCH_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1FL_NE_OTCH_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SOST_CQUERY;
	TToolButton *ToolButtonOpenCQuery;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_CQUERY;
	TToolButton *ToolButtonOpenGurCQuery;
	TcxGridDBColumn *cxGrid1DBTableView1SROK_REMONTA;
	TcxGridDBColumn *cxGrid1DBTableView1SROK_REMONTA_NOW;
	TcxGridDBColumn *cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SKLAD_OST;
	TcxGridDBColumn *cxGrid1DBTableView1IDREC_RGOTPRZ;
	TcxButtonEdit *NameSkladcxButtonEdit;
	TcxLabel *cxLabel7;
	TToolButton *ToolButtonOpenOnlySklad;
	TToolButton *ToolButtonOpenVPuti;
	TToolButton *ToolButtonOpenAllSklad;
	TMenuItem *PMCreateDocVidachaHW;
	TMenuItem *PMCreateDocVosvratHW;
	TcxGridDBColumn *cxGrid1DBTableView1IDDOC_VIDACHA_HW;
	TcxGridDBColumn *cxGrid1DBTableView1IDDOC_VOSVRAT_HW;
	TToolButton *ToolButtonCopyInClipboard;
	TToolButton *ToolButtonSaveUserSetup;
	TToolButton *ToolButtonOpenGarTalon;
	TToolButton *ToolButtonSetNullInCustQuery;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall ToolButtonAddNewZClick(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ToolButton5Click(TObject *Sender);
					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1OUT_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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
	void __fastcall PMCreateDocZPostClick(TObject *Sender);
	void __fastcall PMCreateDocZVidClick(TObject *Sender);
	void __fastcall PMCreateDocZPerClick(TObject *Sender);
	void __fastcall PMCreateDocZStartClick(TObject *Sender);
	void __fastcall PMCreateDocZEndClick(TObject *Sender);
	void __fastcall PMCreateDocZOperClick(TObject *Sender);
	void __fastcall PMCreateDocZTrebClick(TObject *Sender);
	void __fastcall PMCreateDocZAktPrClick(TObject *Sender);
	void __fastcall PMCreateDocZVosvrZapClick(TObject *Sender);
	void __fastcall ToolButtonOpenGurAllDocClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNumClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNum2Click(TObject *Sender);
	void __fastcall cxButtonPoiskPoModelClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoKlientuClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoHardwareClick(TObject *Sender);
	void __fastcall cxButtonPoNumGarDocClick(TObject *Sender);
	void __fastcall ToolButtonCreateNewNaOsnDanFormClick(TObject *Sender);
	void __fastcall ToolButtonCopyZayavkaClick(TObject *Sender);
	void __fastcall ToolButtonZapShapkuNaOsnZayavkiClick(TObject *Sender);
	void __fastcall ToolButtonOpenNewClick(TObject *Sender);
	void __fastcall NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonCreateNaOsnSprHardwareClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1SOST_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall ToolButtonOpenCQueryClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1ID_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall ToolButtonOpenGurCQueryClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1IDREC_RGOTPRZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonOpenOnlySkladClick(TObject *Sender);
	void __fastcall ToolButtonOpenVPutiClick(TObject *Sender);
	void __fastcall ToolButtonOpenAllSkladClick(TObject *Sender);
	void __fastcall PMCreateDocVidachaHWClick(TObject *Sender);
	void __fastcall PMCreateDocVosvratHWClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1IDDOC_VIDACHA_HWCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1IDDOC_VOSVRAT_HWCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxGrid1DBTableView1FL_POVTORCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall ToolButtonCopyInClipboardClick(TObject *Sender);
	void __fastcall ToolButtonSaveUserSetupClick(TObject *Sender);
	void __fastcall ToolButtonOpenGarTalonClick(TObject *Sender);
	void __fastcall ToolButtonSetNullInCustQueryClick(TObject *Sender);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv,ER_ViborHardware,ER_Sklad} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;

		void OpenFormDoc();
		void DeleteDoc(void);

		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);
		__int64 IdVibHardware;

				//выбор склада
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);


		void SaveFormSetup(void);
		void LoadFormSetup(void);

public:		// User declarations
		__fastcall TREM_FormaGurZ(TComponent* Owner);

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

		IREM_DMGurZ * DM;

		__int64 IdDoc;

        TDateTime PosNach;
		TDateTime PosCon;
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		__int64 IdSklad;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurZ *REM_FormaGurZ;
//---------------------------------------------------------------------------
#endif
