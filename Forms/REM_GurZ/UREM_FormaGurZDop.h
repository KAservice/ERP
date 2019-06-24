//---------------------------------------------------------------------------

#ifndef UREM_FormaGurZDopH
#define UREM_FormaGurZDopH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurZ.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
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
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxButtonEdit.hpp"
#include "cxMaskEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurZDop : public TForm
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
	TcxTextEdit *SerNumcxTextEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonPoiskPoSerNum;
	TcxTextEdit *SerNum2cxTextEdit;
	TcxTextEdit *KlientNamecxTextEdit;
	TcxTextEdit *ModelcxTextEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxButton *cxButtonPoiskPoSerNum2;
	TcxButton *cxButtonPoiskPoModel;
	TcxButton *cxButtonPoiskPoKlientu;
	TcxButtonEdit *NameHardwarecxButtonEdit;
	TcxLabel *cxLabel5;
	TcxButton *cxButtonPoiskPoHardware;
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
	void __fastcall cxButtonPoiskPoSerNumClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxButtonPoiskPoSerNum2Click(TObject *Sender);
	void __fastcall cxButtonPoiskPoModelClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoKlientuClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoHardwareClick(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv,ER_ViborHardware} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;

		void OpenFormDoc();
		void DeleteDoc(void);

		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);
		__int64 IdVibHardware;

public:		// User declarations
		__fastcall TREM_FormaGurZDop(TComponent* Owner);

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

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurZDop *REM_FormaGurZDop;
//---------------------------------------------------------------------------
#endif
