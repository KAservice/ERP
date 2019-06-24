//---------------------------------------------------------------------------

#ifndef UFormaReportOCBRegCardBalanceH
#define UFormaReportOCBRegCardBalanceH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprDiscountCard_1.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpKlient.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMQueryRead.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//--------------------------------------------------------------------------
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
#include "cxDBEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportOCBRegCardBalance : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label6;
        TLabel *Label4;
        TLabel *Label14;
	TpFIBDataSet *IBQ;
	TpFIBTransaction *IBTr;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameKlientEdit;
	TcxButtonEdit *NameGrpKlientEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TLabel *Label5;
	TcxButtonEdit *NameCardcxButtonEdit;
	TFIBBCDField *IBQIDFIRM_PROC;
	TFIBBCDField *IBQIDGRP_PROC;
	TFIBBCDField *IBQIDKLIENT_PROC;
	TFIBBCDField *IBQIDCARD_PROC;
	TFIBBCDField *IBQNACHOST_PROC;
	TFIBBCDField *IBQPRIHOD_PROC;
	TFIBBCDField *IBQRASHOD_PROC;
	TFIBBCDField *IBQCONOST_PROC;
	TcxCheckBox *cxCheckBoxSDoc;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *IBQNAMEFIRM_PROC;
	TFIBWideStringField *IBQNAMEGRP_PROC;
	TFIBWideStringField *IBQNAMEKLIENT_PROC;
	TFIBWideStringField *IBQNAMECARD_PROC;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCardcxButtonEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

		  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void  EndViborProject(void);

public:		// User declarations
        __fastcall TFormaReportOCBRegCardBalance(TComponent* Owner);

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
		__int64 IdCard;
		__int64 IdBusinessOper;
		__int64 IdProject;

		 IFormaSpiskaSprFirm *SpisokFirm;
         void OpenFormSpiskaSprFirm(void);
		 IFormaSpiskaSprGrpKlient * SpisokGrpKlient;
         void OpenFormSpiskaSprGrpKlient(void);

		IFormaSpiskaSprKlient * SpisokKlient;


        void OpenFormSpiskaSprKlient(void);



		enum  {ER_NoRekv,ViborFirm, ViborGrpKlient, ViborKlient,
		 ER_ViborCard,ER_ViborBusinessOper, ER_ViborProject,  NO} EditRekvisit;

		IFormaSpiskaSprDiscountCard_1 * SprCard;
		void ViborCard(void);
		void __fastcall EndViborCard(void);


		__int64 IdTecFirm;
		__int64 IdTecGrpKlient;
        __int64 IdTecKlient;
        __int64 IdTecCard;

        void CreateReport( TSheetEditor *prForm);

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

        void OutputStringCard(TSheetEditor *prForm);

		void OutputPodavalReport(TSheetEditor *prForm);

		IDMQueryRead * DMQueryReadDoc;
		void OutputDocDvReport( TSheetEditor *prForm);
		void OutputStringDocDvReport( TSheetEditor *prForm);
		AnsiString GetTextZaprosDoc(void);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        int porNumKlient;
		int porNumCard;

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
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportOCBRegCardBalance *FormaReportOCBRegCardBalance;
//---------------------------------------------------------------------------
#endif
