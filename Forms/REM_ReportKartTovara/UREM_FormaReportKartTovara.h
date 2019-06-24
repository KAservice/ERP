//---------------------------------------------------------------------------

#ifndef UREM_FormaReportKartTovaraH
#define UREM_FormaReportKartTovaraH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
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
#include <ExtCtrls.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TREM_FormaReportKartTovara : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenuExtModule;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxCheckBox *DocDvcxCheckBox;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxButton *cxButton1;
	TpFIBTransaction *pFIBTransaction;
	TpFIBDataSet *pFIBDataSet;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TDataSource *DataSource;
	TcxButton *cxButtonUpdate;
	TFIBDateTimeField *pFIBDataSetOUT_POS;
	TFIBWideStringField *pFIBDataSetOUT_TDOC;
	TFIBIntegerField *pFIBDataSetOUT_NUM;
	TFIBSmallIntField *pFIBDataSetOUT_TDV;
	TFIBBCDField *pFIBDataSetOUT_KOL_PRIHOD;
	TFIBBCDField *pFIBDataSetOUT_KOL_RASHOD;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_POS;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_TDOC;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NUM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_TDV;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_PRIHOD;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_RASHOD;
	TpFIBDataSet *OstNaNach;
	TpFIBDataSet *OstNaCon;
	TFIBBCDField *OstNaNachOUT_KOL;
	TFIBBCDField *OstNaConOUT_KOL;
	TcxLabel *cxLabel1;
	TcxLabel *OstNaNachcxLabel;
	TcxLabel *cxLabel3;
	TcxLabel *OstNaConcxLabel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
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
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall pFIBDataSetOUT_TDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall OstNaNachOUT_KOLGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall OstNaConOUT_KOLGetText(TField *Sender, UnicodeString &Text, bool DisplayText);


				  
private:	// User declarations

    bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

public:		// User declarations
		__fastcall TREM_FormaReportKartTovara(TComponent* Owner);

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




		void __fastcall EndEdit(TObject *Sender);

		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprGrpNom(void);


		__int64 IdFirm;
		__int64 IdSkl;
		__int64 IdGrpNom;
		__int64 IdNom;
		TDateTime PosStart;
		TDateTime PosEnd;
		UnicodeString NameFirm;
		UnicodeString NameSklad;
		UnicodeString NameNom;

		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaReportKartTovara *REM_FormaReportKartTovara;
//---------------------------------------------------------------------------
#endif
