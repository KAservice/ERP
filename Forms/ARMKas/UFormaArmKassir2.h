//---------------------------------------------------------------------------

#ifndef UFormaArmKassir2H
#define UFormaArmKassir2H
//---------------------------------------------------------------------------
#include "UFormaViborBVNom.h"
#include "UDMSprNom.h"
#include "UFormaViborSprEd.h"
#include "UFormaViborSprNom.h"
#include "UFormaInputCode.h"
#include "UFormaInputText.h"
#include "UDMSprOborud.h"
#include "UDMSprARM.h"
#include "UFormaGurDocCheckKKM2.h"
#include "USheetEditor.h"
#include "UDMDocCheck.h"
#include "UDM.h"
#include "UFormaInputDiscountCard.h"
#include "UDMSprDiscountCard.h"
#include "UDMSprDiscountAuto.h"
#include "UFiskReg.h"
#include "UFormaViborOborud.h"
#include "UDisplayPok.h"
#include "UFormaViborOplat_ARM2.h"
#include "UObjectBarCode.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <Menus.hpp> 
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include <ActnList.hpp>
#include <ImgList.hpp>
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaARMKassir2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel5;
        TLabel *Prim;
        TGroupBox *GroupBoxSum;
        TGroupBox *GroupBoxSdacha;
        TGroupBox *GroupBoxPC;
        TGroupBox *GroupBoxNal;
        TPanel *Panel1;
        TPanel *PanelName;
        TLabel *Label5;
        TPanel *PanelKF;
        TLabel *Label7;
        TPanel *PanelPrice;
        TLabel *Label8;
        TPanel *PanelKol;
        TLabel *Label6;
        TDBText *Oper;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N4;
        TMenuItem *MenuInputCodeBV;
        TMenuItem *MenuInputCodeNom;
        TMenuItem *N8;
        TMenuItem *MenuPrintCheck;
        TMenuItem *N12;
        TMenuItem *NewCheckSale;
        TMenuItem *NewCheckReturnSale;
        TMenuItem *N9;
        TMenuItem *N10;
        TLabel *NameKKMLabel;
        TLabel *TypePriceLabel;
        TMenuItem *DeleteString;
        TLabel *UchLabel;
        TMenuItem *N7;
        TMenuItem *PrintXreport;
        TMenuItem *PrintZreport;
        TMenuItem *N11;
        TMenuItem *N14;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N15;
        TMenuItem *AddSvobSum;
        TMenuItem *Vnesenie;
        TMenuItem *Snatie;
	TMenuItem *SaveCheckMainMenu;
        TMenuItem *OpenCheck;
        TMenuItem *CloseDoc;
        TMenuItem *mmPrintCoodsCheckOnFR;
	TMenuItem *PoBarCode;
	TcxButton *ButtonPrint;
	TcxButton *ButtonClose;
	TMenuItem *N6;
	TMenuItem *ViborDiscCardMainmenu;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *cxGrid1TableView1NAMENOM;
	TcxGridColumn *cxGrid1TableView1IDNOM;
	TcxGridColumn *cxGrid1TableView1KOL;
	TcxGridColumn *cxGrid1TableView1PRICE;
	TcxGridColumn *cxGrid1TableView1NAMEED;
	TcxGridColumn *cxGrid1TableView1IDED;
	TcxGridColumn *cxGrid1TableView1KFED;
	TcxGridColumn *cxGrid1TableView1SUM;
	TcxGridColumn *cxGrid1TableView1IDFIRM;
	TcxGridColumn *cxGrid1TableView1NAMEFIRM;
	TLabel *NameKlientLabel;
	TLabel *NameDiscountCardLabel;
	TLabel *KolLabel;
	TLabel *KFLabel;
	TLabel *PriceLabel;
	TLabel *NameNomLabel;
	TLabel *SumDocLabel;
	TLabel *SdachaLabel;
	TcxGridColumn *cxGrid1TableView1PRSK;
	TcxGridColumn *cxGrid1TableView1SKIDKA;
	TcxGridColumn *cxGrid1TableView1PRSK_CARD;
	TcxGridColumn *cxGrid1TableView1PRSK_AUTO;
	TcxGridColumn *cxGrid1TableView1RECNO;
	TcxGridColumn *cxGrid1TableView1TNOM;
	TcxGridColumn *cxGrid1TableView1KRNAMENOM;
	TcxCalcEdit *NalcxCalcEdit;
	TcxCalcEdit *OplCardcxCalcEdit;
	TLabel *NameFirmLabel;
	TMenuItem *OpenCheckForVosvratMainMenu;
	TcxGridColumn *cxGrid1TableView1FL_PRINT;
	TImageList *ImageList1;
	TMenuItem *ReportTecProdagiMainMenu;
	TMenuItem *OpalataPoFirmMainMenu;
	TAction *ActionClose;
	TAction *ActionPrint;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonInsertClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall MenuInputCodeNomClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall MenuPrintCheckClick(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall NewCheckReturnSaleClick(TObject *Sender);
        void __fastcall PrintZreportClick(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall MenuInputCodeBVClick(TObject *Sender);
        void __fastcall AddSvobSumClick(TObject *Sender);
        void __fastcall VnesenieClick(TObject *Sender);
        void __fastcall SnatieClick(TObject *Sender);
        void __fastcall SaveCheckMainMenuClick(TObject *Sender);
        void __fastcall OpenCheckClick(TObject *Sender);
        void __fastcall CloseDocClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall mmPrintCoodsCheckOnFRClick(TObject *Sender);
	void __fastcall PoBarCodeClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ViborDiscCardMainmenuClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KOLCHKTPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxGrid1Exit(TObject *Sender);
	void __fastcall NalcxCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OplCardcxCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NewCheckSaleClick(TObject *Sender);
	void __fastcall cxGrid1TableView1NAMENOMGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          AnsiString &AText);
	void __fastcall cxGrid1TableView1KOLGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          AnsiString &AText);
	void __fastcall cxGrid1TableView1KFEDGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          AnsiString &AText);
	void __fastcall cxGrid1TableView1PRICEGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          AnsiString &AText);
	void __fastcall cxGrid1TableView1TcxGridDataControllerTcxDataSummaryFooterSummaryItems0GetText(
          TcxDataSummaryItem *Sender, const Variant &AValue, bool AIsFooter,
          AnsiString &AText);
	void __fastcall cxGrid1TableView1DataControllerAfterPost(
          TcxCustomDataController *ADataController);
	void __fastcall NalcxCalcEditPropertiesEditValueChanged(TObject *Sender);
	void __fastcall OplCardcxCalcEditPropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxGrid1TableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NalcxCalcEditExit(TObject *Sender);
	void __fastcall OpenCheckForVosvratMainMenuClick(TObject *Sender);
	void __fastcall cxGrid1TableView1FL_PRINTCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall ReportTecProdagiMainMenuClick(TObject *Sender);
	void __fastcall PrintXreportClick(TObject *Sender);
	void __fastcall OpalataPoFirmMainMenuClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
//	void __fastcall N13Click(TObject *Sender);

private:	// User declarations



public:		// User declarations
		__fastcall TFormaARMKassir2(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		//TDMDocCheck *DMDocCheck;
		TDMSprARM *  DMSprARM;
		TDMSprOborud * DMSprOborud;
		TDMSprNom * DMSprNom;
		TDMSprEd *DMSprEd;
		TDMSprDiscountCard * DMSprDiscountCard;
		TDMSprDiscountAuto  * DMSprDiscountAuto;
		TObjectBarCode * ObBar;
		TNotifyEvent FOnCloseForm;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // ����� �������
        bool Prosmotr;    //������ ��������
		bool Vibor;       //��� ������
		AnsiString TextError;

		__int64 IdDoc;           //������������� ������� ������
		__int64 IdDocOsn;
		__int64 IdGrp;        // ������������ ������
		__int64 IdElementaMaster;  //������������� �������� �����������-���������
		__int64 VibTovarId;
		__int64 VibTovarIdGrp;
		__int64  IdARM;
		bool OutReady;
		__int64 IdTypePrice;
		AnsiString NameTypePrice;
		double SummaDoc;
		double Sdacha;
		double Oplata;
		void CreateNewDocCheckSale(void);
		void CreateNewDocCheckReturnSale(void);

		void CreateNewDocCheckReturnSaleNaOsnSaleGurnal(void);
		void __fastcall EndViborCheckForVosvratIsGurnala(TObject *Sender);

		//����� �� ����������� �������� ������
		TFormaViborBVNom *SprBV;
		void OpenFormViborSprBVNom(void);
		void __fastcall EndViborNomIsSprBV(TObject *Sender);
		//����� �� ����������� ������������
		TFormaViborSprNom  *FormaViborSprNom;
		void OpenFormViborSprNom(void);
		void __fastcall EndViborNomIsSprNom(TObject *Sender);
		//����� ������� ���������
	    TFormaViborSprEd *SpisokEd;
		void OpenFormViborSprEd(void);
		void __fastcall EndViborEdinica(TObject *Sender);
		//���� ���� �������� ������
		TFormaInputCode *FormaInputCode;
		void OpenFormInputCodeNomBV(void);
		void __fastcall EndInputCodeBV(TObject *Sender);
		//���� ���� ������������
		void __fastcall EndInputCodeNom(TObject *Sender);
		void OpenFormInputCodeNom(void);
		//��������� �����
		TFormaInputText *FormaInputText;
		void OpenFormAddSvobSumm(void);
		void __fastcall EndAddSvobSum(TObject *Sender);
		//������
		void OpenFormSnatie(void);
		void __fastcall EndInputSumSnatie(TObject *Sender);
		void __fastcall EndViborOborudSnatie(TObject *Sender);
		void SnatSummu(float sum);
		//��������
		void OpenFormVnesenie(void);
		void __fastcall EndInputSumVnesenie(TObject *Sender);
		void __fastcall EndViborOborudVnesenie(TObject *Sender);
		void VnestiSummu(float sum);

		TFormaGurDocCheckKKM2 *FormaGurDocCheckKKM2;
		void OpenGurnalCheckVibor(void);
		void __fastcall EndViborDocCheck(TObject *Sender);
		//������ ���� ����� ����
		void OpenFormInputBarCode(void);
		void __fastcall EndInputBarCode(TObject *Sender);

		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		
		// X - �����
		TFormaViborOborud *FormaViborOborud;
		void OpenFormViborOborudXReport(void);
		void __fastcall EndViborOborudXReport(TObject *Sender);
        void PrintXReport(void);

		// Z - �����
		void OpenFormViborOborudZReport(void);
		void __fastcall EndViborOborudZReport(TObject *Sender);
		void PrintZReport(void);


        bool CheckSave;
		bool CheckPrint;
		bool CheckProveden;

        String StrPrint;

        void SummaCheck(void);
        void UpdateForm(void);
        bool CheckCreate;



		bool ExternalCreateCheck;


        void UpdateSetup(void);
        void UpdateParameterFR(void);
		void PrintDocCheck(void);


		//������ ��������� ����
		void PrintGoodsCheck(void);
        void PrintGoodsCheck_OutputHeadline(void);
        void PrintGoodsCheck_OutputElement(void);
        void PrintGoodsCheck_OutputPodval(void);

        TSheetEditor * SE;
		int x, y;
		bool PrintGoodsCheckOnFR(void);

		//����� ���������� �����
		TFormaInputDiscountCard * FormaInputDiscountCard;
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(TObject *Sender);

		void UpdateValuesDiscount(void);
		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
//		double NakoplSumma;
		//double ProcentSkidkiPoDiscountCard;

		bool NoOtrOstatok;
		void ValidateOstatok(double treb_kol);
		void RaschetTekSumStroki(int number_string);

		TFiskReg* GetFR(void);

		void PrintCheckNaTecFR(TList * list);
		bool PrintFiscalCheck(TList * list,__int64 id_firm);
		bool PrintNoFiscalCheck(TList * list,__int64 id_firm);
		bool SaveCheck(TList * list,__int64 id_firm);

		void ClearList(TList *list);

		int OperationCheck; //�������� ���� //0 ������� 1 �������

		int NumberKL;
		int NumberCheck;
		AnsiString RegNumberKKM;
		AnsiString SerialNumberKKM;
		AnsiString ModelKKM;
		int NumberDoc;
		TDateTime PosDoc;



		//������� ����������
		TDisplayPok * DisplayPok;
		void ConnectDisplay(void);


		AnsiString VesPrefiksBarCode;
		int VesTypeBarCode;
		int VesTypeSearch;



		//����� ������� �������
		void OpenFormViborOborudForReportTecProdagi(void);
		void __fastcall EndViborOborudForReportTecProdagi(TObject *Sender);
        void PrintReportTecProdagi(void);

	    TFormaViborOplat_ARM2 * FormaViborOplat_ARM2;
		void __fastcall PrintCheckEvent(TObject *Sender);
		void __fastcall CloseFormInOplEvent(TObject *Sender);


		void OutProtocol(AnsiString s);
		void ShowPrim(AnsiString s, bool add);

		void CheckDateTimeFR(void);


		AnsiString BarCodePrefiks1;  //������� ��������� ��, ����� �� �� �������
		AnsiString BarCodePrefiks2; //�����. ����� �� ���� ������������,  ��� � ������ ��������
		AnsiString BarCodePrefiks3; //�����. ����� �� ���� ������������, ��� �� ������ ��������
		AnsiString BarCodePrefiks4; //�����. ����� �� �� �������, ��� � ������ ��������
		AnsiString BarCodePrefiks5; //�����. ����� �� �� �������, ��� �� ������ ��������
		
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaARMKassir2 *FormaARMKassir2;
//---------------------------------------------------------------------------
#endif
