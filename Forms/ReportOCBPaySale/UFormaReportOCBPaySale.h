//---------------------------------------------------------------------------

#ifndef UFormaReportOCBPaySaleH
#define UFormaReportOCBPaySaleH
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpKlient.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportOCBPaySale : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label6;
        TLabel *Label4;
        TLabel *Label14;
        TLabel *Label5;
	TpFIBDataSet *IBQ;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *IBQNUMDOC_PROC;
	TFIBDateTimeField *IBQPOSDOC_PROC;
	TFIBDateField *IBQDATE_PROC;
	TFIBBCDField *IBQNACHOST_PROC;
	TFIBBCDField *IBQPRIHOD_PROC;
	TFIBBCDField *IBQRASHOD_PROC;
	TFIBBCDField *IBQCONOST_PROC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameDogovorEdit;
	TcxButtonEdit *NameKlientEdit;
	TcxButtonEdit *NameGrpKlientEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *IBQIDFIRM_PROC;
	TFIBBCDField *IBQIDGRP_PROC;
	TFIBBCDField *IBQIDKLIENT_PROC;
	TFIBBCDField *IBQIDDOGOVOR_PROC;
	TFIBBCDField *IBQIDDOC_PROC;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *IBQNAMEFIRM_PROC;
	TFIBWideStringField *IBQNAMEGRP_PROC;
	TFIBWideStringField *IBQNAMEKLIENT_PROC;
	TFIBWideStringField *IBQNAMEDOGOVOR_PROC;
	TFIBWideStringField *IBQTDOC_PROC;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameDogovorEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

	//внешние формы и скрипты
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void  EndViborProject(void);

public:		// User declarations
        __fastcall TFormaReportOCBPaySale(TComponent* Owner);

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

		__int64 IdFirm;
		__int64 IdGrpKlient;
		__int64 IdKlient;
		__int64 IdDogovor;
		__int64 IdBusinessOper;
		__int64 IdProject;


		 IFormaSpiskaSprFirm *SpisokFirm;
         void OpenFormSpiskaSprFirm(void);
		 IFormaSpiskaSprGrpKlient * SpisokGrpKlient;
         void OpenFormSpiskaSprGrpKlient(void);

		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;

        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprDogovor(void);


		enum  {ER_NoRekv,ViborFirm, ViborGrpKlient, ViborKlient,
		 ViborDogovor,ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;


		__int64 IdTecFirm;
		__int64 IdTecGrpKlient;
		__int64 IdTecKlient;
		__int64 IdTecDogovor;
        __int64 IdTecDoc;

        void CreateReportPaySale( TSheetEditor *prForm);

        void OutputZagolovokReport(TSheetEditor *prForm);

        void OutputStringFirm(TSheetEditor *prForm);
        int num_row_firm;
        void OutputStringItogiFirm(TSheetEditor *prForm);

        void OutputStringGrpKlient(TSheetEditor *prForm);
        int num_row_grp_klient;
        void OutputStringItogiGrpKlient(TSheetEditor *prForm);

        void OutputStringKlient(TSheetEditor *prForm);
        int num_row_klient;
        void OutputStringItogiKlient(TSheetEditor *prForm);

        void OutputStringDogovor(TSheetEditor *prForm);
        int num_row_dogovor;
        void OutputStringItogiDogovor(TSheetEditor *prForm);

        void OutputStringDoc(TSheetEditor *prForm);
        int num_row_doc;
        void OutputStringItogiDoc(TSheetEditor *prForm);


        void OutputStringDate(TSheetEditor *prForm);

        void OutputPodavalReport(TSheetEditor *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        int porNumKlient;

        float AllNachOst;
        float AllPrihod;
        float AllRashod;
        float AllConOst;

        float sum_nach_ost_firm;
        float sum_prihod_firm;
        float sum_rashod_firm;
        float sum_con_ost_firm;

        float sum_nach_ost_grp;
        float sum_prihod_grp;
        float sum_rashod_grp;
        float sum_con_ost_grp;

        float sum_nach_ost_klient;
        float sum_prihod_klient;
        float sum_rashod_klient;
        float sum_con_ost_klient;

        float sum_nach_ost_dogovor;
        float sum_prihod_dogovor;
        float sum_rashod_dogovor;
        float sum_con_ost_dogovor;

        float sum_nach_ost_doc;
        float sum_prihod_doc;
        float sum_rashod_doc;
        float sum_con_ost_doc;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportOCBPaySale *FormaReportOCBPaySale;
//---------------------------------------------------------------------------
#endif
