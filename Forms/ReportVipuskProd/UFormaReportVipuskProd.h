//---------------------------------------------------------------------------

#ifndef UFormaReportVipuskProdH
#define UFormaReportVipuskProdH
//---------------------------------------------------------------------------


#include "USheetEditor.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IDMTableExtPrintForm.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprSklad.h"
//----------------------------------------------------------------------------
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
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportVipuskProd : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *TypePrice;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TpFIBDataSet *IBQSebProd;
	TFIBBCDField *GrpSEBPROD;
	TFIBBCDField *ElSEBPROD;
	TFIBBCDField *ElKOLPROD;
	TFIBBCDField *IBQSebProdSEBPROD;
	TFIBBCDField *IBQSebProdKOLPROD;
	TFIBBCDField *IBQSebProdKOLOTRPROD;
	TpFIBDataSet *IBQRealGrp;
	TpFIBDataSet *IBQRealEl;
	TFIBBCDField *IBQRealGrpSUMREAL;
	TFIBBCDField *IBQRealGrpSEBREAL;
	TFIBBCDField *IBQRealGrpRESREAL;
	TFIBBCDField *IBQRealGrpKOLREAL;
	TFIBBCDField *IBQRealElSUMREAL;
	TFIBBCDField *IBQRealElSEBREAL;
	TFIBBCDField *IBQRealElRESREAL;
	TFIBBCDField *IBQRealElKOLREAL;
	TFIBBCDField *IBQRealElKOLOTRREAL;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxCheckBox *PoDateCheckBox;
	TcxCheckBox *StrRealCheckBox;
	TcxComboBox *TypePriceComboBox;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *GrpIDGN;
	TFIBBCDField *ElIDNOM;
	TFIBBCDField *IBQSebProdIDNOM;
	TFIBBCDField *IBQRealGrpIDGN;
	TFIBBCDField *IBQRealElIDNOM;
	TLabel *Label7;
	TcxButtonEdit *NameFirmEdit;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TFIBWideStringField *IBQRealGrpNAMEGN;
	TFIBWideStringField *IBQRealElNAMENOM;
	TFIBWideStringField *IBQRealElNAMEED;
	TFIBWideStringField *GrpNAMEGN;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElNAMEED;
	TFIBWideStringField *IBQSebProdNAMENOM;
	TFIBWideStringField *IBQSebProdNAMEED;
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

		  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TFormaReportVipuskProd(TComponent* Owner);

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

        enum  {ER_NoRekv,ViborFirm, ViborSklad, ViborNom, NO} EditRekvisit;



		IFormaSpiskaSprFirm *SpisokFirm;
        void OpenFormSpiskaSprFirm(void);		

		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);
        IFormaSpiskaSprNom *Nom;
        void OpenFormSpiskaSprNom(void);


        void OutputStringGrp(TSheetEditor *prForm);
        void OutputString(TSheetEditor *prForm);
        void OutputStringSebProd(TSheetEditor *prForm);
        void CreateReportPoProd(__int64 idnom, TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con);
        void OutputZagolovokReport(TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con);
        void OutputPodavalReport(TSheetEditor *prForm);
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
        void CreateReport(TSheetEditor  *PrintForm,TDateTime pos_nach, TDateTime pos_con);

		void OutputStringRealGrpProd(TSheetEditor *prForm, __int64 id_grp, __int64 id_sklad, TDateTime pos_nach, TDateTime pos_con);
        void OutputStringRealProd(TSheetEditor *prForm, __int64 id_nom, __int64 id_sklad, TDateTime pos_nach, TDateTime pos_con) ;

        double RegRealSebReal;
        double RegRealSumReal;
        double RegRealResReal;
        void OutputStringRealProdPodval(TSheetEditor *prForm);

        double SumOtrSebRealGrp;
        int NumStrGrp;

        double SumOtrSebRealNom;
		int NumStrNom;
		bool flObrabatChangeTypePrice;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportVipuskProd *FormaReportVipuskProd;
//---------------------------------------------------------------------------
#endif
