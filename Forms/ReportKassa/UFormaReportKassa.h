//---------------------------------------------------------------------------

#ifndef UFormaReportKassaH
#define UFormaReportKassaH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKKM.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "USheetEditor.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportKassa : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQ;
	TpFIBDataSet *Dv;
	TFIBBCDField *IBQPRIHODSUM;
	TFIBBCDField *IBQRASHODSUM;
	TFIBBCDField *IBQPR_DOCON_SUM;
	TFIBBCDField *IBQRAS_DOCON_SUM;
	TFIBBCDField *IBQOSTSUM;
	TFIBBCDField *IBQNACHOSTSUM;
	TFIBBCDField *IBQCONOSTSUM;
	TFIBDateTimeField *DvPOSDOC_RGKASSA_DV;
	TFIBSmallIntField *DvTDV_RGKASSA_DV;
	TFIBBCDField *DvSUM_RGKASSA_DV;
	TFIBIntegerField *DvOPER_RGKASSA_DV;
	TFIBIntegerField *DvNUMDOC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOCB;
	TcxButton *cxButtonDV;
	TcxButton *cxButtonClose;
	TcxComboBox *OperationComboBox;
	TcxCheckBox *OnlyOperationCheckBox;
	TcxButtonEdit *NameKassaEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *IBQIDFIRM_PROC;
	TFIBBCDField *IBQIDKASSA_PROC;
	TFIBBCDField *DvID_RGKASSA_DV;
	TFIBBCDField *DvIDDOC_RGKASSA_DV;
	TFIBBCDField *DvIDFIRM_RGKASSA_DV;
	TFIBBCDField *DvIDKKM_RGKASSA_DV;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *IBQNAMEFIRM_PROC;
	TFIBWideStringField *IBQNAMEKASSA_PROC;
	TFIBWideStringField *DvTDOC;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonOCBClick(TObject *Sender);
	void __fastcall cxButtonDVClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall NameKassaEditPropertiesButtonClick(TObject *Sender,
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
        __fastcall TFormaReportKassa(TComponent* Owner);

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

        enum  {ER_NoRekv,ViborFirm, ViborKassa,ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;


		IFormaSpiskaSprFirm *SpisokFirm;
        IFormaSpiskaSprKKM * SpisokKKM;


        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprKassa(void);


        void NewCreateReport(void);
        void NewOutputZagolovokReport(TSheetEditor *prForm);
        void NewOutputStringDv(TSheetEditor *prForm);
        void NewOutputPodavalReport(TSheetEditor *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        
		__int64 IdFirm;
		__int64 IdKassa;
		__int64 IdBusinessOper;
		__int64 IdProject;

        double TekOstSum;
        double AllSumPrihod;
        double AllSumRashod;


		__int64 IdTecFirm;
		__int64 IdTecGrpKlient;
		__int64 IdTecKlient;
		__int64 IdTecDogovor;
        __int64 IdTecDoc;


        void CreateReportOCB( TSheetEditor *prForm);
        void OutputZagolovokReportOCB(TSheetEditor *prForm);
        void OutputStringFirmOCB(TSheetEditor *prForm);
        int num_row_firm;
        void OutputStringItogiFirmOCB(TSheetEditor *prForm);
        void OutputStringOCB(TSheetEditor *prForm);
        void OutputPodavalReportOCB(TSheetEditor *prForm);


        float AllNachOst;
        float AllPrihod;
        float AllRashod;
        float AllConOst;

        float sum_nach_ost_firm;
        float sum_prihod_firm;
        float sum_rashod_firm;
        float sum_con_ost_firm;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportKassa *FormaReportKassa;
//---------------------------------------------------------------------------
#endif
