//---------------------------------------------------------------------------

#ifndef UFormaReportResultRealH
#define UFormaReportResultRealH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
#include "USheetEditor.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
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
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxDBEdit.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaDialogaReportResultReal : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *TypePrice;
	TpFIBDataSet *IBQ;
	TFIBIntegerField *IBQTNOM;
	TFIBBCDField *IBQSUMREAL;
	TFIBBCDField *IBQSEBREAL;
	TFIBBCDField *IBQRESREAL;
	TFIBBCDField *IBQKOLREAL;
	TFIBBCDField *IBQKOLOTRREAL;
	TpFIBDataSet *IBQDoc;
	TFIBBCDField *IBQDocKOL_RGREAL_DV;
	TFIBBCDField *IBQDocSUMREAL_RGREAL_DV;
	TFIBBCDField *IBQDocSEBREAL_RGREAL_DV;
	TFIBBCDField *IBQDocRESREAL_RGREAL_DV;
	TFIBBCDField *IBQDocKOLOTR_RGREAL_DV;
	TFIBDateTimeField *IBQDocPOSDOC;
	TFIBIntegerField *IBQDocNUMDOC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxButtonEdit *NameFirmEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameNomEdit;
	TcxCheckBox *OnlyCheckBox;
	TcxComboBox *TypeNomComboBox;
	TcxCheckBox *OnlyOperationCheckBox;
	TcxComboBox *OperationComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxCheckBox *DocCheckBox;
	TcxButton *cxButtonCreateReport;
	TcxButton *cxButtonClose;
	TcxCheckBox *cxCheckBoxVisibleOtrOst;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *IBQIDFIRM;
	TFIBBCDField *IBQIDSKLAD;
	TFIBBCDField *IBQIDGN;
	TFIBBCDField *IBQIDNOM;
	TcxButton *cxButtonCreateReportGrid;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TFIBWideStringField *IBQDocTDOC;
	TFIBWideStringField *IBQNAMEFIRM;
	TFIBWideStringField *IBQNAMESKLAD;
	TFIBWideStringField *IBQNAMEGN;
	TFIBWideStringField *IBQNAMENOM;
	TFIBWideStringField *IBQNAMEED;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TLabel *Label10;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateReportClick(TObject *Sender);
	void __fastcall DateNachKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DateConKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall OnlyCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnlyOperationCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DocCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypeNomComboBoxPropertiesChange(TObject *Sender);
	void __fastcall OperationComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxCheckBoxVisibleOtrOstKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxButtonCreateReportGridClick(TObject *Sender);

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
		__fastcall TFormaDialogaReportResultReal(TComponent* Owner);

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


		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom,
					ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи

		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double SumRealReport;
        double SebRealReport;
        double ResRealReport;
        double OtrSebRealReport;

		__int64 IdTypePrice;

        double SumOtrSebRealGrp;
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

        void NewCreateReport(void);
        AnsiString GetTextQuery(void);
        void NewCreateReportResultReal( TSheetEditor *prForm);

        void NewOutputZagolovokReport(TSheetEditor *prForm);

        void NewOutputStringFirm(TSheetEditor *prForm);
        int num_row_firm;
        double SumRealFirm;
        double SebRealFirm;
        double ResRealFirm;
        double OtrSebRealFirm;
        void NewOutputStringItogiFirm(TSheetEditor *prForm);

        void NewOutputStringSklad(TSheetEditor *prForm);
        int num_row_sklad;
        double SumRealSklad;
        double SebRealSklad;
        double ResRealSklad;
        double OtrSebRealSklad;
        void NewOutputStringItogiSklad(TSheetEditor *prForm);

        void NewOutputStringGrpNom(TSheetEditor *prForm);
        int num_row_grp_nom;
        double SumRealGrpNom;
        double SebRealGrpNom;
        double ResRealGrpNom;
        double OtrSebRealGrpNom;
        void NewOutputStringItogiGrpNom(TSheetEditor *prForm);

        void NewOutputStringNom(TSheetEditor *prForm);

        void NewOutputPodavalReport(TSheetEditor *prForm);

        AnsiString GetTextZaprosDoc(void);
        void CreateReportDoc(TSheetEditor *prForm);
        void NewOutputStringDoc(TSheetEditor *prForm);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportResultReal *FormaDialogaReportResultReal;
//---------------------------------------------------------------------------
#endif
