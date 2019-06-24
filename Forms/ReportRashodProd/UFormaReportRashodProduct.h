//---------------------------------------------------------------------------

#ifndef UFormaReportRashodProductH
#define UFormaReportRashodProductH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprFirm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMFibConnection.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaRunExternalModule.h"
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
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportRashodProduct : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label5;
	TpFIBDataSet *TypePrice;
	TpFIBDataSet *IBQ;
	TpFIBTransaction *IBTr;
	TFIBBCDField *IBQKOLSUM;
	TFIBBCDField *IBQSUM_SEB;
	TFIBBCDField *IBQKOLSUM_OTR;
	TFIBBCDField *IBQKOL_PROD;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxCheckBox *PoDateCheckBox;
	TcxComboBox *TypePriceComboBox;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *IBQIDGN;
	TFIBBCDField *IBQIDNOM;
	TLabel *Label7;
	TcxButtonEdit *NameFirmEdit;
	TAction *ActionClose;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TFIBWideStringField *IBQNAMEGN;
	TFIBWideStringField *IBQNAMENOM;
	TFIBWideStringField *IBQNAMEED;
	TFIBWideStringField *IBQNAMEED_PROD;
	TFIBWideStringField *IBQNAME_PROD;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
	TcxButton *cxButton1;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);

			  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
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
        __fastcall TFormaReportRashodProduct(TComponent* Owner);

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

		enum  {ER_NoRekv,ViborFirm, ViborSklad, ViborNom,
		ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;

		IFormaSpiskaSprFirm *SpisokFirm;
		void OpenFormSpiskaSprFirm(void);


		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);
        IFormaSpiskaSprNom *Nom;
        void OpenFormSpiskaSprNom(void);



        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double SebProdReport;
		double OtrSebProdReport;

		__int64 IdFirm;
		__int64 IdSkl;
		__int64 IdTypePrice;
		__int64 IdNom;
		__int64 IdBusinessOper;
		__int64 IdProject;

        void CreateReport(TSheetEditor  *PrintForm,TDateTime pos_nach, TDateTime pos_con);
        void OutputStringGrp(TSheetEditor *prForm);
        void OutputStringNom(TSheetEditor *prForm);
        void OutputString(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con);
        void OutputPodavalReport(TSheetEditor *prForm);

        double kol_product;
        double sum_product;
        double kol_otr_product;
        double sum_otr_product;
        double price_product;

        int num_row_nom;

		void OutputItogiNom(TSheetEditor *prForm);
		
		bool flObrabatChangeTypePrice;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportRashodProduct *FormaReportRashodProduct;
//---------------------------------------------------------------------------
#endif
