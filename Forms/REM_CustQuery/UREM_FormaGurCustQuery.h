//---------------------------------------------------------------------------

#ifndef UREM_FormaGurCustQueryH
#define UREM_FormaGurCustQueryH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurCustQuery.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprProducer.h"
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
#include <Menus.hpp>
#include "UREM_DMGurCustQuery.h"
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxSpinEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurCustQuery : public TForm
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
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1KLIENT_NAME_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1RUN_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_MODEL_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SBRAND;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRODUCER;
	TcxTextEdit *ModelcxTextEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel3;
	TcxButton *cxButtonPoiskPoModel;
	TcxButton *cxButtonPoiskPoKlientu;
	TcxTextEdit *KlientNamecxTextEdit;
	TcxButtonEdit *NameZayavkacxButtonEdit;
	TcxLabel *cxLabel2;
	TcxLabel *NameKlientcxLabel;
	TcxLabel *NameModelcxLabel;
	TcxLabel *SerNumcxLabel;
	TcxLabel *SerNum2cxLabel;
	TcxButton *cxButtonOtborPoZayavka;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_ZAKAZA_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1DATE_ZAKAZA_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_REM_CQUERY;
	TLabel *Label27;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel5;
	TcxButtonEdit *NameProducercxButtonEdit;
	TcxSpinEdit *NumberZakazcxSpinEdit;
	TcxDateEdit *DateZakazcxDateEdit;
	TToolButton *ToolButtonOpenTrebZakaz;
	TToolButton *ToolButtonOpenPoNumberZakaz;
	TToolButton *ToolButtonSetNumberDateZakaza;
	TToolButton *ToolButtonSetPredvZakazano;
	TToolButton *ToolButtonSetVipolneno;
	TToolButton *ToolButtonSetOtpravleno;
	TToolButton *ToolButtonSetTecPostupilo;
	TcxDateEdit *VibDatecxDateEdit;
	TToolButton *ToolButtonSetPlanPostavki;
	TToolButton *ToolButtonSetZakazano;
	TToolButton *ToolButtonSetDateOtpravleno;
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
					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1RUN_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxButtonPoiskPoModelClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoKlientuClick(TObject *Sender);
	void __fastcall cxButtonOtborPoZayavkaClick(TObject *Sender);
	void __fastcall NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall NameProducercxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonOpenTrebZakazClick(TObject *Sender);
	void __fastcall ToolButtonOpenPoNumberZakazClick(TObject *Sender);
	void __fastcall ToolButtonSetNumberDateZakazaClick(TObject *Sender);
	void __fastcall ToolButtonSetPredvZakazanoClick(TObject *Sender);
	void __fastcall ToolButtonSetVipolnenoClick(TObject *Sender);
	void __fastcall ToolButtonSetOtpravlenoClick(TObject *Sender);
	void __fastcall ToolButtonSetTecPostupiloClick(TObject *Sender);
	void __fastcall ToolButtonSetPlanPostavkiClick(TObject *Sender);
	void __fastcall ToolButtonSetZakazanoClick(TObject *Sender);
	void __fastcall ToolButtonSetDateOtpravlenoClick(TObject *Sender);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv,
		ER_ViborHardware, ER_Zayavka, ER_ViborProducer} ViborRekv;

		IFormaViborPerioda *FormaViborPerioda;

		void OpenFormDoc();
		void DeleteDoc(void);


					//выбор заявки
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

				IFormaSpiskaSprProducer* FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EndViborProducer(void);

		__int64 IdVibProducer;

public:		// User declarations
		__fastcall TREM_FormaGurCustQuery(TComponent* Owner);

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

		IREM_DMGurCustQuery * DM;

		__int64 IdDoc;

        TDateTime PosNach;
		TDateTime PosCon;

		void UpdateForm(void);

		__int64 IdVibZayavka;

		UnicodeString Zayavka_NameKlient;
		UnicodeString Zayavka_NameModel;
		UnicodeString Zayavka_SerNum;
		UnicodeString Zayavka_SerNum2;
		UnicodeString Zayavka_Name;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurCustQuery *REM_FormaGurCustQuery;
//---------------------------------------------------------------------------
#endif
