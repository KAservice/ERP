//---------------------------------------------------------------------------

#ifndef UFormaReportKartKlientH
#define UFormaReportKartKlientH
//---------------------------------------------------------------------------

#include "IFormaSpiskaSprFirm.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprKlient.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IDMTableExtPrintForm.h"
//--------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
class TFormaReportKartKlient : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
	TpFIBDataSet *Dv;
	TpFIBTransaction *IBTr;
	TFIBDateTimeField *DvPOSDOC_VSRASCH_DV;
	TFIBSmallIntField *DvTDV_VSRASCH_DV;
	TFIBBCDField *DvSUM_VSRASCH_DV;
	TFIBIntegerField *DvNUMDOC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameKlientEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *DvID_VSRASCH_DV;
	TFIBBCDField *DvIDDOC_VSRASCH_DV;
	TFIBBCDField *DvIDFIRM_VSRASCH_DV;
	TFIBBCDField *DvIDKLIENT_VSRASCH_DV;
	TFIBBCDField *DvIDDOG_VSRASCH_DV;
	TcxButtonEdit *NameFirmEdit;
	TLabel *Label5;
	TAction *ActionClose;
	TFIBWideStringField *DvTDOC;
	TcxButton *cxButton1;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);


	//внешние формы и скрипты
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);

private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


public:
		__fastcall TFormaReportKartKlient(TComponent* Owner);


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

		enum  {ER_NoRekv,ER_ViborKlient, ER_ViborFirm,  NO} EditRekvisit;



		IFormaSpiskaSprKlient * SpisokKlient;
        void OpenFormSpiskaSprKlient(void);

        void OutputStringDv(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);
        int numRow;
        int numCol;
        int porNumStr;

		__int64 IdKlient;
		__int64 IdFirm;
        float TekOstSum;
        float AllSumPrihod;
		float AllSumRashod;

		IFormaSpiskaSprFirm *SpisokFirm;
		void OpenFormSpiskaSprFirm(void);
		void __fastcall EndViborFirm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportKartKlient *FormaReportKartKlient;
//---------------------------------------------------------------------------
#endif
