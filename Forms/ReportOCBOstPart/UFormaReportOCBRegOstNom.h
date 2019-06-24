//---------------------------------------------------------------------------

#ifndef UFormaReportOCBRegOstNomH
#define UFormaReportOCBRegOstNomH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMQueryRead.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
#include "USheetEditor.h"
#include "UFormIndicator.h"
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
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportOCBRegOstNom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *TypePrice;
	TpFIBDataSet *IBQ;
	TFIBDateTimeField *IBQPOSDOC_PROC;
	TFIBBCDField *IBQNACHOSTKOL_PROC;
	TFIBBCDField *IBQNACHOSTSUM_PROC;
	TFIBBCDField *IBQPRIHODKOL_PROC;
	TFIBBCDField *IBQPRIHODSUM_PROC;
	TFIBBCDField *IBQRASHODKOL_PROC;
	TFIBBCDField *IBQRASHODSUM_PROC;
	TFIBBCDField *IBQCONOSTKOL_PROC;
	TFIBBCDField *IBQCONOSTSUM_PROC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxComboBox *TypePriceComboBox;
	TcxCheckBox *PriceCheckBox;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *IBQIDFIRM_PROC;
	TFIBBCDField *IBQIDSKLAD_PROC;
	TFIBBCDField *IBQIDGRP_PROC;
	TFIBBCDField *IBQIDNOM_PROC;
	TFIBBCDField *IBQIDPART_PROC;
	TFIBBCDField *IBQIDED_PROC;
	TcxCheckBox *DocDvcxCheckBox;
	TcxButton *cxButton1;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TFIBWideStringField *IBQNAMEFIRM_PROC;
	TFIBWideStringField *IBQNAMESKLAD_PROC;
	TFIBWideStringField *IBQNAMEGRP_PROC;
	TFIBWideStringField *IBQNAMENOM_PROC;
	TFIBWideStringField *IBQNAMEPART_PROC;
	TFIBWideStringField *IBQNAMEED_PROC;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
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
		__fastcall TFormaReportOCBRegOstNom(TComponent* Owner);

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
		__int64 IdSkl;
		__int64 IdGrpNom;
		__int64 IdNom;
		__int64 IdBusinessOper;
		__int64 IdProject;

        void __fastcall EndEdit(TObject *Sender);

		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom,
		ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double NachOstReport;
        double PrihodReport;
        double RashodReport;
        double ConOstReport;

		__int64 IdTypePrice;

        int NumStrGrp;

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprGrpNom(void);

		__int64 IdTecFirm;
		__int64 IdTecSklad;
		__int64 IdTecGrpNom;
        __int64 IdTecNom;

        void CreateReport(void);
        AnsiString GetTextQuery(void);
        void CreateReportOCB( TSheetEditor *prForm);

        void OutputZagolovokReport(TSheetEditor *prForm);

        void OutputStringFirm(TSheetEditor *prForm);
        int num_row_firm;
        double NachOstFirm;
        double PrihodFirm;
        double RashodFirm;
        double ConOstFirm;
        void OutputStringItogiFirm(TSheetEditor *prForm);

        void OutputStringSklad(TSheetEditor *prForm);
        int num_row_sklad;
        double NachOstSklad;
        double PrihodSklad;
        double RashodSklad;
        double ConOstSklad;
        void OutputStringItogiSklad(TSheetEditor *prForm);

        void OutputStringGrpNom(TSheetEditor *prForm);
        int num_row_grp_nom;
        double NachOstGrpNom;
        double PrihodGrpNom;
        double RashodGrpNom;
        double ConOstGrpNom;
        void OutputStringItogiGrpNom(TSheetEditor *prForm);


        void OutputStringNom(TSheetEditor *prForm);
        int num_row_nom;
        double SumNachOstNom;
        double KolNachOstNom;
        double SumPrihodNom;
        double KolPrihodNom;
        double SumRashodNom;
        double KolRashodNom;
        double SumConOstNom;
        double KolConOstNom;
        void OutputStringItogiNom(TSheetEditor *prForm);


        void OutputStringPart(TSheetEditor *prForm);

        void OutputPodavalReport(TSheetEditor *prForm);

	   TFormIndicator * FormIndicator;

	   bool flObrabatChangeTypePrice;

       IDMQueryRead * DMQueryReadDoc;
	   AnsiString GetTextZaprosDoc(void);
		void CreateReportDoc(TSheetEditor *prForm);
		void OutputStringDoc(TSheetEditor *prForm);
		double TecConOstatokPoDocKol;
		double TecConOstatokPoDocSum;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportOCBRegOstNom *FormaReportOCBRegOstNom;
//---------------------------------------------------------------------------
#endif
