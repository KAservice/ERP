//---------------------------------------------------------------------------

#ifndef UFormaArmKassir2H
#define UFormaArmKassir2H
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaViborBVNom.h"
#include "IDMSprNom.h"
#include "IFormaViborSprEd.h"
#include "IFormaViborSprNom.h"
#include "IFormaInputCode.h"
#include "IFormaInputText.h"
#include "IDMSprOborud.h"
#include "IDMSprARM.h"
#include "IFormaGurDocCheckKKM2.h"
#include "IDMDocCheck.h"
#include "UDM.h"
#include "IFormaInputDiscountCard.h"
#include "IDMSprDiscountCard.h"
#include "IDMSprDiscountAuto.h"
#include "IFiskReg.h"
#include "IFormaViborOborud.h"
#include "IDisplayPok.h"
#include "UFormaViborOplat_ARM2.h"
#include "IObjectBarCode.h"
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
	   bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	   bool Prosmotr;
	   __int64 IdDoc;
	   __int64 IdDocOsn;

		//TDMDocCheck *DMDocCheck;
		IDMSprARM *  DMSprARM;
		IDMSprOborud * DMSprOborud;
		IDMSprNom * DMSprNom;
		IDMSprEd *DMSprEd;
		IDMSprDiscountCard * DMSprDiscountCard;
		IDMSprDiscountAuto  * DMSprDiscountAuto;
		IObjectBarCode * ObBar;



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
		void __fastcall EndViborCheckForVosvratIsGurnala(void);

		//����� �� ����������� �������� ������
		IFormaViborBVNom *SprBV;
		void OpenFormViborSprBVNom(void);
		void __fastcall EndViborNomIsSprBV(void);
		//����� �� ����������� ������������
		IFormaViborSprNom  *FormaViborSprNom;
		void OpenFormViborSprNom(void);
		void __fastcall EndViborNomIsSprNom(void);
		//����� ������� ���������
		IFormaViborSprEd *SpisokEd;
		void OpenFormViborSprEd(void);
		void __fastcall EndViborEdinica(void);
		//���� ���� �������� ������
		IFormaInputCode *FormaInputCode;
		void OpenFormInputCodeNomBV(void);
		void __fastcall EndInputCodeBV(void);
		//���� ���� ������������
		void __fastcall EndInputCodeNom(void);
		void OpenFormInputCodeNom(void);
		//��������� �����
		IFormaInputText *FormaInputText;
		void OpenFormAddSvobSumm(void);
		void __fastcall EndAddSvobSum(void);
		//������
		void OpenFormSnatie(void);
		void __fastcall EndInputSumSnatie(void);
		void __fastcall EndViborOborudSnatie(void);
		void SnatSummu(float sum);
		//��������
		void OpenFormVnesenie(void);
		void __fastcall EndInputSumVnesenie(void);
		void __fastcall EndViborOborudVnesenie(void);
		void VnestiSummu(float sum);

		IFormaGurDocCheckKKM2 *FormaGurDocCheckKKM2;
		void OpenGurnalCheckVibor(void);
		void __fastcall EndViborDocCheck(void);
		//������ ���� ����� ����
		void OpenFormInputBarCode(void);
		void __fastcall EndInputBarCode(void);




		// X - �����
		IFormaViborOborud *FormaViborOborud;
		void OpenFormViborOborudXReport(void);
		void __fastcall EndViborOborudXReport(void);
		void PrintXReport(void);

		// Z - �����
		void OpenFormViborOborudZReport(void);
		void __fastcall EndViborOborudZReport(void);
		void PrintZReport(void);


        bool CheckSave;
		bool CheckPrint;
		bool CheckProveden;

		UnicodeString StrPrint;

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

		int x, y;
		bool PrintGoodsCheckOnFR(void);

		//����� ���������� �����
		IFormaInputDiscountCard * FormaInputDiscountCard;
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		void UpdateValuesDiscount(void);
		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
//		double NakoplSumma;
		//double ProcentSkidkiPoDiscountCard;

		bool NoOtrOstatok;
		void ValidateOstatok(double treb_kol);
		void RaschetTekSumStroki(int number_string);

		IFiskReg* GetFR(void);

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
		IDisplayPok * DisplayPok;
		void ConnectDisplay(void);


		AnsiString VesPrefiksBarCode;
		int VesTypeBarCode;
		int VesTypeSearch;



		//����� ������� �������
		void OpenFormViborOborudForReportTecProdagi(void);
		void __fastcall EndViborOborudForReportTecProdagi(void);
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

		enum {ER_NoRekv,ER_VosvratViborIsGur, ER_ViborNomIsSprBV,ER_ViborNomIsSprNom,
		ER_ViborEd, ER_InputCodeBV, ER_InputCodeNom, ER_SvobSum,
		ER_SumSnatie, ER_OborudSnatie,
		ER_SumVnesenie, ER_OborudVnesenie,
		ER_ViborIsGur, ER_InputBarCode,
		ER_ViborOborudXReport, ER_ViborOborudZReport,
		ER_ViborDiscountCard, ER_ViborOborudForReportTecProdagi,  ER_No} EditRekvisit;
public:		// User declarations
		__fastcall TFormaARMKassir2(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//�� ���� ����� ������� ������ ��� ������
		//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
		int ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������

        void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaARMKassir2 *FormaARMKassir2;
//---------------------------------------------------------------------------
#endif
