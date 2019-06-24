//---------------------------------------------------------------------------

#ifndef UREM_FormaGurAllDocH
#define UREM_FormaGurAllDocH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IREM_DMGurAllDoc.h"
#include "IFormaViborPerioda.h"
#include "IREM_FormaSetupOtbor.h"
#include "ISheetEditor.h"
#include "UFormIndicator.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaGurAllDoc.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IREM_FormaGurZ.h"
//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
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
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurAllDoc : public TForm
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
        TToolButton *ToolButtonOpenDvDoc;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButtonAllCancelDvReg;
        TToolButton *ToolButtonDvRegDoc;
        TToolButton *ToolButtonReportOtrSpis;
        TToolButton *ToolButtonDelAllDoc;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonParamOtbor;
        TToolButton *ToolButtonOtbor;
        TLabel *StrOtborLabel;
        TToolButton *ToolButtonNoCheck;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonRefresh;
	TToolButton *ToolButton5;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1PRDOC;
	TcxGridDBColumn *cxGrid1DBTableView1TDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1SUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButton6;
	TPopupMenu *PopupMenuDoc;
	TMenuItem *NewDocPrihNakl;
	TMenuItem *NewDocReal;
	TMenuItem *NewDocOstNom;
	TMenuItem *NewDocSborkaKompl;
	TMenuItem *NewDocPostOtDilera;
	TMenuItem *NewDocVosvratDileru;
	TMenuItem *NewDocPerServCentr;
	TMenuItem *NewDocVosvrstIsSC;
	TMenuItem *NewDocVosvratPok;
	TMenuItem *CreateNewDocAktPopupMenu;
	TMenuItem *CreateNewDocPerPopupMenu;
	TToolButton *ToolButtonCopyDoc;
	TPopupMenu *PopupMenuCopyDoc;
	TMenuItem *PMCopyDocPer;
	TMenuItem *CreateNewDocSpisNomPopupMenu;
	TPopupMenu *PopupMenuCreateNaOsn;
	TMenuItem *PopupMenuCreateNaOsnDocPer;
	TMenuItem *PopupMenuCreateNaOsnDocOstNom;
	TToolButton *ToolButtonCreateNaOsn;
	TPanel *Panel5;
	TcxButtonEdit *NameZayavkacxButtonEdit;
	TcxButtonEdit *NameHardwarecxButtonEdit;
	TcxButton *cxButtonOtborPoZayavka;
	TcxButton *cxButtonOtborPoHardware;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *NameKlientcxLabel;
	TcxLabel *NameModelcxLabel;
	TcxLabel *SerNumcxLabel;
	TcxLabel *SerNum2cxLabel;
	TcxLabel *NameModelHwcxLabel;
	TcxLabel *SerNumHwcxLabel;
	TcxLabel *SerNum2HwcxLabel;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1PREFIKS_NUM_REM_GALLDOC;
	TMenuItem *CreateNewDocRegOtchetPostPopupMenu;
	TMenuItem *PMCopyAktInAkt;
	TMenuItem *CreateNewDocVidachaHWPopupMenu;
	TMenuItem *CreateNewDocVosvratHWPopupMenu;
	TcxGridDBColumn *cxGrid1DBTableView1RES_REM_GUR_PROV;
	TcxGridDBColumn *cxGrid1DBTableView1IDDOC_REM_GUR_VIGRT;
	TToolButton *ToolButton7;
	TToolButton *ToolButtonCreateDocProverka;
	TMenuItem *CreateDocZakazPost;
	TToolButton *ToolButtonCreateDocVigr;
	TMenuItem *N1;
	TMenuItem *N2;
	TToolButton *ToolButtonZapolnPoNZ;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonOpenDvDocClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
        void __fastcall ToolButtonAllCancelDvRegClick(TObject *Sender);
        void __fastcall ToolButtonDvRegDocClick(TObject *Sender);
        void __fastcall ToolButtonDelAllDocClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonParamOtborClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1PRDOCCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall NewDocPrihNaklClick(TObject *Sender);
	void __fastcall NewDocRealClick(TObject *Sender);
	void __fastcall NewDocOstNomClick(TObject *Sender);
	void __fastcall NewDocSborkaKomplClick(TObject *Sender);
	void __fastcall NewDocPostOtDileraClick(TObject *Sender);
	void __fastcall NewDocVosvratDileruClick(TObject *Sender);
	void __fastcall NewDocPerServCentrClick(TObject *Sender);
	void __fastcall NewDocVosvrstIsSCClick(TObject *Sender);
	void __fastcall NewDocVosvratPokClick(TObject *Sender);
	void __fastcall CreateNewDocAktPopupMenuClick(TObject *Sender);
	void __fastcall CreateNewDocPerPopupMenuClick(TObject *Sender);
	void __fastcall PMCopyDocPerClick(TObject *Sender);
	void __fastcall CreateNewDocSpisNomPopupMenuClick(TObject *Sender);
	void __fastcall PopupMenuCreateNaOsnDocPerClick(TObject *Sender);
	void __fastcall PopupMenuCreateNaOsnDocOstNomClick(TObject *Sender);
	void __fastcall NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonOtborPoZayavkaClick(TObject *Sender);
	void __fastcall cxButtonOtborPoHardwareClick(TObject *Sender);
	void __fastcall CreateNewDocRegOtchetPostPopupMenuClick(TObject *Sender);
	void __fastcall PMCopyAktInAktClick(TObject *Sender);
	void __fastcall CreateNewDocVidachaHWPopupMenuClick(TObject *Sender);
	void __fastcall CreateNewDocVosvratHWPopupMenuClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1IDDOC_REM_GUR_VIGRTCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall ToolButtonCreateDocProverkaClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1RES_REM_GUR_PROVCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall CreateDocZakazPostClick(TObject *Sender);
	void __fastcall ToolButtonCreateDocVigrClick(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ToolButtonZapolnPoNZClick(TObject *Sender);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv, ER_GurAllDoc,
				ER_ViborHardware, ER_Zayavka} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;
		IREM_FormaSetupOtbor * FormaSetupOtbor;

		void OpenFormDoc();
		void DeleteDoc(void);

		//void CanceDvRegDoc(void);
		//bool DvRegAllDoc(void);
		double SumReport;

		//печать реестра
		void OpenPrintForm(void);
		void OutputString(ISheetEditor *prForm);
		void OutputZagolovokReport(ISheetEditor *prForm);
		void OutputPodavalReport(ISheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
//		double SumReport;

	void DeleteAllDoc(void);


			//выбор документа из полного журнала
		IFormaGurAllDoc *FormaGurAllDoc;
		void ViborDocGurAllDoc(void);
		void __fastcall EndViborDocGurAllDoc(void);
		UnicodeString TypeDoc;


		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);


			//выбор заявки
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

		void UpdateTableAfterCloseDoc(void);


		bool NoUpdateTable;


public:		// User declarations
		__fastcall TREM_FormaGurAllDoc(TComponent* Owner);

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

		IREM_DMGurAllDoc * DM;

        __int64 IdDoc;


        TDateTime PosNach;
        TDateTime PosCon;





		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdSklad;
		UnicodeString NameSklad;
        __int64 IdFirm;
		UnicodeString NameFirm;
		UnicodeString   StringTypeDoc;
        UnicodeString NameTypeDoc;


        bool OtborPoKlientu;
        bool OtborPoFirm;
        bool OtborPoSklad;
		bool OtborPoTypeDoc;

		void UpdateForm(void);
		void OpenTable(void);
		__int64 IdVibHardware;
		__int64 IdVibZayavka;

		UnicodeString Zayavka_NameKlient;
		UnicodeString Zayavka_NameModel;
		UnicodeString Zayavka_SerNum;
		UnicodeString Zayavka_SerNum2;
		UnicodeString Zayavka_Name;
		UnicodeString Hardware_NameModel;
		UnicodeString Hardware_SerNum;
		UnicodeString Hardware_SerNum2;
        UnicodeString Hardware_Name;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurAllDoc *REM_FormaGurAllDoc;
//---------------------------------------------------------------------------
#endif
