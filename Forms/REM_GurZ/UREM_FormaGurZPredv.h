//---------------------------------------------------------------------------

#ifndef UREM_FormaGurZPredvH
#define UREM_FormaGurZPredvH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurZPredv.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprSklad.h"
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
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurZPredv : public TForm
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
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SUMNACHA_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SKLAD_PR;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1KLIENT_NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_STR_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM1_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
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
	TcxGridDBColumn *cxGrid1DBTableView1PREFIKS_NUM_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SBRAND;
	TcxTextEdit *NumGarDoccxTextEdit;
	TcxLabel *cxLabel6;
	TcxButton *cxButtonPoNumGarDoc;
	TToolButton *ToolButtonCopyZayavka;
	TToolButton *ToolButtonCreateNewNaOsnDanForm;
	TToolButton *ToolButtonZapShapkuNaOsnZayavki;
	TToolButton *ToolButtonOpenNew;
	TcxCheckBox *cxCheckBoxIspSprHardware;
	TcxLabel *cxLabelHint;
	TToolButton *ToolButtonCreateNaOsnSprHardware;
	TcxLabel *cxLabelSerNum1;
	TcxLabel *cxLabelSerNum2;
	TToolButton *ToolButtonOpenCQuery;
	TToolButton *ToolButtonOpenGurCQuery;
	TcxButtonEdit *NameSkladcxButtonEdit;
	TcxLabel *cxLabel7;
	TToolButton *ToolButtonOpenOnlySklad;
	TToolButton *ToolButtonOpenVPuti;
	TToolButton *ToolButtonOpenAllSklad;
	TMenuItem *PMCreateDocVidachaHW;
	TMenuItem *PMCreateDocVosvratHW;
	TcxGridDBColumn *cxGrid1DBTableView1RESULT_REM_Z2;
	TcxGridDBColumn *cxGrid1DBTableView1PRICHINA_LIST_REM_Z2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall ToolButtonAddNewZClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ToolButton5Click(TObject *Sender);
					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
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
	void __fastcall NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);


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

public:		// User declarations
		__fastcall TREM_FormaGurZPredv(TComponent* Owner);

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

		IREM_DMGurZPredv * DM;

		__int64 IdDoc;

        TDateTime PosNach;
		TDateTime PosCon;
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		__int64 IdSklad;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurZPredv *REM_FormaGurZPredv;
//---------------------------------------------------------------------------
#endif
