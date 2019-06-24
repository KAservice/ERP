//---------------------------------------------------------------------------

#ifndef UFormaReportKartTovaraH
#define UFormaReportKartTovaraH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprFirm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMFibConnection.h"
#include "IDMTableExtPrintForm.h"
//---------------------------------------------------------------------------

#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
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
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportKartTovara : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label5;
        TLabel *NameBasEdLabel;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Dv;
	TFIBDateTimeField *DvPOSDOC_OSTNOMDV;
	TFIBSmallIntField *DvTDV_OSTNOMDV;
	TFIBBCDField *DvSUM_OSTNOMDV;
	TFIBBCDField *DvKOL_OSTNOMDV;
	TFIBIntegerField *DvOPER_OSTNOMDV;
	TFIBBCDField *DvSUM2_OSTNOMDV;
	TFIBIntegerField *DvNUMDOC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *DvID_OSTNOMDV;
	TFIBBCDField *DvIDDOC_OSTNOMDV;
	TFIBBCDField *DvIDFIRM_OSTNOMDV;
	TFIBBCDField *DvIDSKL_OSTNOMDV;
	TFIBBCDField *DvIDNOM_OSTNOMDV;
	TFIBBCDField *DvIDPART_OSTNOMDV;
	TFIBBCDField *DvIDSTRDOC_OSTNOMDV;
	TcxButtonEdit *NameFirmcxButtonEdit;
	TcxLabel *cxLabel2;
	TcxButton *cxButton1;
	TpFIBDataSet *DvRegGoods;
	TFIBBCDField *DvRegGoodsID_RGGOODS_DV;
	TFIBDateTimeField *DvRegGoodsPOSDOC_RGGOODS_DV;
	TFIBSmallIntField *DvRegGoodsTDV_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDFIRM_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDSKLAD_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDNOM_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsRPRICE_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsKOL_RGGOODS_DV;
	TFIBIntegerField *DvRegGoodsOPER_RGGOODS_DV;
	TFIBIntegerField *DvRegGoodsTYPE_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDBASE_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDEXT_DOUT_RGGOODS_DV;
	TFIBBCDField *DvRegGoodsIDEXT_BASE_RGGOODS_DV;
	TFIBIntegerField *DvRegGoodsNUMDOC;
	TcxCalcEdit *RoznPricecxCalcEdit;
	TLabel *Label7;
	TcxCheckBox *AllPricecxCheckBox;
	TAction *ActionClose;
	TFIBWideStringField *DvTDOC;
	TFIBBCDField *DvRegGoodsIDDOC_RGGOODS_DV;
	TFIBWideStringField *DvRegGoodsTDOC;
	TcxButton *cxButton2;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);

		//внешние формы и скрипты
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



		IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

public:		// User declarations
        __fastcall TFormaReportKartTovara(TComponent* Owner);

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

        enum  {ER_NoRekv,ViborSklad, ViborNom, ER_ViborFirm, NO} EditRekvisit;



		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);
		IFormaSpiskaSprNom *Nom;
        void OpenFormSpiskaSprNom(void);

		void NewCreateReport(void);
		void NewOutputZagolovokReport(TSheetEditor *prForm);
		void NewOutputStringDv(TSheetEditor *prForm);
		void NewOutputPodavalReport(TSheetEditor *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        
		__int64 IdSklad;
		bool RoznSklad;
        __int64 IdNom;
        float TekOstKol;
        float AllKolPrihod;
        float AllKolRashod;

        float TekOstSum;
        float AllSumPrihod;
		float AllSumRashod;

		__int64 IdFirm;
		IFormaSpiskaSprFirm *FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);


        double RoznPrice;
		void RegistrGoodsCreateReport(void);
		void RegistrGoodsOutputZagolovokReport(TSheetEditor *prForm);
		void RegistrGoodsOutputStringDv(TSheetEditor *prForm);
		void RegistrGoodsOutputPodavalReport(TSheetEditor *prForm);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportKartTovara *FormaReportKartTovara;
//---------------------------------------------------------------------------
#endif
