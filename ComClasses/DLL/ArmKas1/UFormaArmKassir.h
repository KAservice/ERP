//---------------------------------------------------------------------------

#ifndef UFormaArmKassirH
#define UFormaArmKassirH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
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
#include "IFormaInputDiscountCard.h"
#include "IDMSprDiscountCard.h"
#include "IDMSprDiscountAuto.h"
#include "IObjectBarCode.h"

#include "IDisplayPok.h"
#include "IScaner.h"
#include "IFiskReg.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"

#include "UCheckDiscount_StringDoc.h"
#include "IObjectCheckDiscount.h"
#include "IDMSprOborud.h"
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
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
//---------------------------------------------------------------------------
class TFormaARMKassir : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel5;
        TLabel *Prim;
        TGroupBox *GroupBoxSum;
	TDBText *SumDoc;
        TGroupBox *GroupBoxSdacha;
	TDBText *Sdacha;
        TGroupBox *GroupBoxPC;
        TGroupBox *GroupBoxNal;
        TPanel *Panel1;
        TLabel *NameDoc;
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
        TStatusBar *StatusBar;
        TMenuItem *N7;
        TMenuItem *PrintXreport;
        TMenuItem *PrintZreport;
        TDBText *NumberDocDBText;
        TMenuItem *N11;
        TMenuItem *N14;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N15;
        TDBText *NameKlientDBText;
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
	TcxDBCalcEdit *Nal;
	TcxDBCalcEdit *OplataPC;
	TcxDBLabel *NameDCardcxDBLabel;
	TMenuItem *N6;
	TMenuItem *ViborDiscCardMainmenu;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TMenuItem *OpenCheckForVosvratMainMenu;
	TMenuItem *VibratProjectMainMenu;
	TAction *ActionClose;
	TAction *ActionPrint;
	TMenuItem *PoArtikulu;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TPanel *Panel2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KOLCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1KFCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICECHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRSKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRNADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NADCHKT;
	TcxGridLevel *cxGrid1Level1;
	TPanel *PanelName;
	TDBText *NameNomDBText;
	TLabel *Label5;
	TPanel *PanelKol;
	TLabel *Label6;
	TDBText *KolDBText;
	TPanel *PanelKF;
	TLabel *Label7;
	TDBText *KFDBText;
	TPanel *PanelPrice;
	TLabel *Label8;
	TDBText *PriceDBText;
	TDBText *Oper;
	TGroupBox *GroupBoxAllOplata;
	TDBText *AllOplataDBText;
	TGroupBox *GroupBox14;
	TcxGrid *cxGrid2;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid2DBTableView1SUMPLAT_DCHK_OPL;
	TcxGridDBColumn *cxGrid2DBTableView1SUMCREDIT_DCHK_OPL;
	TcxGridLevel *cxGrid2Level1;
	TPanel *Panel10;
	TGroupBox *GroupBox15;
	TcxDBLabel *AllOplPlatCardcxDBLabel;
	TGroupBox *GroupBox16;
	TcxDBLabel *AllOplCreditCardcxDBLabel;
	TPanel *Panel7;
	TToolBar *ToolBar4;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonAddPrice;
	TToolButton *ToolButtonDeletePrice;
	TPanel *Panel3;
	TGroupBox *GroupBox13;
	TGroupBox *GroupBox11;
	TcxDBCalcEdit *OplataPlatCardcxDBCalcEdit;
	TGroupBox *GroupBox12;
	TcxDBCalcEdit *OplataCreditCardcxDBCalcEdit;
	TGroupBox *GroupBox1;
	TAction *ActionSetMainTabScheet;
	TAction *ActionSetOplataTabScheet;
	TMenuItem *PrintPovtorCheckOnFR;
	TcxGridDBColumn *cxGrid1DBTableView1CodeNom;
	TcxGridDBColumn *cxGrid1DBTableView1ArtNom;
	TcxGridDBColumn *cxGrid1DBTableView1BarCode;
	TMenuItem *MainMenuExtModule;
	TMenuItem *N5;
	TMenuItem *N13;
	TcxGridDBColumn *cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SDEPARTMENT;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall NewCheckSaleClick(TObject *Sender);
        void __fastcall MenuInputCodeNomClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall MenuPrintCheckClick(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall NewCheckReturnSaleClick(TObject *Sender);
        void __fastcall PrintXreportClick(TObject *Sender);
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
	void __fastcall NalKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall OplataPCKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ViborDiscCardMainmenuClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KOLCHKTPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxGrid1Exit(TObject *Sender);
	void __fastcall OpenCheckForVosvratMainMenuClick(TObject *Sender);
	void __fastcall VibratProjectMainMenuClick(TObject *Sender);
	void __fastcall NalExit(TObject *Sender);
	void __fastcall OplataPCExit(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall PoArtikuluClick(TObject *Sender);
	void __fastcall ActionSetMainTabScheetExecute(TObject *Sender);
	void __fastcall ActionSetOplataTabScheetExecute(TObject *Sender);
	void __fastcall PrintPovtorCheckOnFRClick(TObject *Sender);
	void __fastcall OplataPlatCardcxDBCalcEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall OplataCreditCardcxDBCalcEditKeyPress(TObject *Sender, wchar_t &Key);


		//внешние формы и скрипты
		void __fastcall MainMenuExtModuleClick(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	void OpenFormInputArtikul(void);
	void __fastcall EndInputArtikul(void);


		IDMSprARM *DMSprARM;
		IDMSprOborud *DMSprOborud;
		IFormaViborBVNom *SprBV;




		void OpenFormViborSprBVNom(void);

		IFormaViborSprEd *SpisokEd;
		void OpenFormViborSprEd(void);

		IFormaViborSprNom  *FormaViborSprNom;
		void OpenFormViborSprNom(void);

		IFormaInputCode *FormaInputCode;

		void OpenFormInputCodeNom(void);
		void OpenFormInputCodeNomBV(void);


		void OpenFormInputBarCode(void);
		void __fastcall EndInputBarCode(void);



		IFormaGurDocCheckKKM2 *FormaGurDocCheckKKM2;
		void ViborDocCheckForVosvrat(void);
		void __fastcall EndViborDocCheckForVosvrat(void);

		IFormaInputText *FormaInputText;

		void OpenFormAddSvobSumm(void);

		void OpenFormSnatie(void);
		void OpenFormVnesenie(void);

		void VnestiSummu(float sum);
		void SnatSummu(float sum);


		IDMSprNom *Nom;
		IDMSprEd * Ed;
		IObjectBarCode * ObBar;





		bool PrintFiscalCheck(bool povtor);
		bool PrintNoFiscalCheck(bool povtor);




		AnsiString PrefiksVesCoda;

        void PrintGoodsCheck(void);


        void PrintGoodsCheck_OutputHeadline(void);
        void PrintGoodsCheck_OutputElement(void);
		void PrintGoodsCheck_OutputPodval(void);

        bool PrintGoodsCheckOnFR(void);

		ISheetEditor * SE;
		int x, y;

		//выбор дисконтной карты
		IFormaInputDiscountCard * FormaInputDiscountCard;
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		IDMSprDiscountCard * DMSprDiscountCard;
		IDMSprDiscountAuto  * DMSprDiscountAuto;

		IObjectCheckDiscount * ObCheckDiscount;



		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
//		double NakoplSumma;
		//double ProcentSkidkiPoDiscountCard;




		enum  {ER_NoRekv,NewCheckSale_Operation,NewCheckReturnSale_Operation,
							OpenCheckSale_Operation,OpenCheckReturnSale_Operation,
							NO_Operation} CheckOperation;



		//выбор проекта
		void  ViborProject(void);
		void __fastcall EndViborProject(void);
		__int64 IdProject;

		void CheckDateTimeFR(void);

	IFiskReg  *glFR;
	IScaner * glScaner;
	IDisplayPok * glDisplayPok;


	bool CheckOplataBeforePrintCheck(void);
	bool CheckSumPlatCard(void);
	bool CheckSumCreditCard(void);

		bool PrintStandartFiscalCheck(bool povtor);
		bool PrintStandartNoFiscalCheck(bool povtor);
		bool PrintCheckForNoFiscalOplat(bool povtor);
		bool PrintFiscalCheckForKombOplat(bool povtor);
		bool PrintNoFiscalCheckForKombOplat(bool povtor);


	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


	__int64 GetIdOperSale(void);
	__int64 GetIdOperReturnSale(void);

	bool ConnectFR(void);
	bool DisconnectFR(void);


	void SaveFormSetup(void);
	void LoadFormSetup(void);

public:		// User declarations
		__fastcall TFormaARMKassir(TComponent* Owner);



		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

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



        //AsyncExternalEvent
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		//Текущий интерфейс
		IDMDocCheck *DM;
		bool BeforeEditCheck(void);
		bool BeforeCreateNewCheck(void);
		void CreateNewDocCheck(void);
		void CreateNewDocCheckVosvrat(void);
		bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца
		__int64 VibTovarId;
		__int64 VibTovarIdGrp;
		bool OutReady;
		__int64 IdTypePrice;
		AnsiString NameTypePrice;


		bool PrintCheck(bool povtor);
		bool SaveCheck(void);
		bool CheckSave;
		bool CheckPrint;
		bool CheckProveden;

		String StrPrint;

	   //	void SummaCheck(void);
		void UpdateForm(void);
		bool CheckCreate;

		__int64  IdARM;

	 //   bool NoPrintCheckFR;
		bool ExternalCreateCheck;


		void UpdateSetup(void);
		void UpdateParameterFR(void);
		void PrintDocCheck(void);
		void UpdateValuesDiscount(void);
		bool NoOtrOstatok;
		void ValidateOstatok(double treb_kol);

		bool CreateCheckNaOsnRealRemont(__int64 id_doc_real_remont);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaARMKassir *FormaARMKassir;
//---------------------------------------------------------------------------
#endif
