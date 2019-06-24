//---------------------------------------------------------------------------

#ifndef UFormaArmKassirH
#define UFormaArmKassirH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
#include "UFormaViborBVNom.h"
#include "UDMSprNom.h"
#include "UFormaViborSprEd.h"
#include "UFormaViborSprNom.h"
#include "UFormaInputCode.h"
#include "UFormaViborSprKlient.h"
#include "UFormaViborSprDogovor.h"
#include "UFormaInputText.h"
#include "UDMSprOborud.h"
#include "UDMSprARM.h"
#include "UFormaGurDocCheckKKM2.h"
#include "UDMDocCheck.h"
#include "UFormaInputDiscountCard.h"
#include "UDMSprDiscountCard.h"
#include "UDMSprDiscountAuto.h"
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
#include "cxLookAndFeels.hpp"
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
        TPanel *PanelName;
        TDBText *NameNomDBText;
        TLabel *Label5;
        TPanel *PanelKF;
        TLabel *Label7;
        TDBText *KFDBText;
        TPanel *PanelPrice;
        TLabel *Label8;
	TDBText *PriceDBText;
        TPanel *PanelKol;
        TLabel *Label6;
        TDBText *KolDBText;
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
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1KFCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICECHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRSKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRNADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
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
//	void __fastcall N13Click(TObject *Sender);

private:	// User declarations


	void OpenFormInputArtikul(void);
	void __fastcall EndInputArtikul(TObject *Sender);

public:		// User declarations
		__fastcall TFormaARMKassir(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom * InterfaceGlobalCom;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		TDMDocCheck *DM;
        TDMSprARM *DMSprARM;
		TFormaViborBVNom *SprBV;

		bool BeforeEditCheck(void);
		bool BeforeCreateNewCheck(void);


        void OpenFormViborSprBVNom(void);

	    TFormaViborSprEd *SpisokEd;
		void OpenFormViborSprEd(void);

        TFormaViborSprNom  *FormaViborSprNom;
        void OpenFormViborSprNom(void);

        TFormaInputCode *FormaInputCode;

        void OpenFormInputCodeNom(void);
		void OpenFormInputCodeNomBV(void);


		void OpenFormInputBarCode(void);
		void __fastcall EndInputBarCode(TObject *Sender);

        TFormaViborSprKlient * FormaViborSprKlient;
        void OpenFormViborSprKlient(void);

        TFormaViborSprDogovor * FormaViborSprDogovor;
		void OpenFormViborSprDogovor(void);

		void CreateNewDocCheck(void);
		void CreateNewDocCheckVosvrat(void);

		TFormaGurDocCheckKKM2 *FormaGurDocCheckKKM2;
		void ViborDocCheckForVosvrat(void);
		void __fastcall EndViborDocCheckForVosvrat(TObject *Sender);

		TFormaInputText *FormaInputText;

        void OpenFormAddSvobSumm(void);

        void OpenFormSnatie(void);
        void OpenFormVnesenie(void);

        void VnestiSummu(float sum);
        void SnatSummu(float sum);


		TDMSprNom *Nom;
		TDMSprEd * Ed;
		TObjectBarCode * ObBar;
		
        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
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

		void __fastcall EndEdit(TObject *Sender);
		TNotifyEvent FOnCloseForm;

        enum  {ViborTovarSprBV,ViborNomSpr, ViborEdinica,EditNal, EditOplataPC,
                        InputCodeBV, InputCodeNom, ViborKlientIsSpr,
                         ViborDogovorIsSpr, InputIdDogovor
                         , AddSvobSumRekvisit
						 , VnesenieRekvisit, SnatieRekvisit, ViborDocCheck,
						 InputBarCode, NO} EditRekvisit;

        AnsiString TextError;
		bool PrintCheck(void);

		bool PrintFiscalCheck(void);
		bool PrintNoFiscalCheck(void);

		bool SaveCheck(void);
        bool CheckSave;
		bool CheckPrint;
		bool CheckProveden;

        String StrPrint;

        void SummaCheck(void);
        void UpdateForm(void);
        bool CheckCreate;

		__int64  IdARM;

     //   bool NoPrintCheckFR;
        bool ExternalCreateCheck;


        void UpdateSetup(void);
        void UpdateParameterFR(void);
		void PrintDocCheck(void);

		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		AnsiString PrefiksVesCoda;

        void PrintGoodsCheck(void);


        void PrintGoodsCheck_OutputHeadline(void);
        void PrintGoodsCheck_OutputElement(void);
        void PrintGoodsCheck_OutputPodval(void);

        bool PrintGoodsCheckOnFR(void);

        ISheetEditor * SE;
		int x, y;

		//выбор дисконтной карты
		TFormaInputDiscountCard * FormaInputDiscountCard;
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(TObject *Sender);

		TDMSprDiscountCard * DMSprDiscountCard;
		TDMSprDiscountAuto  * DMSprDiscountAuto;


		void UpdateValuesDiscount(void);
		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
//		double NakoplSumma;
		//double ProcentSkidkiPoDiscountCard;

		bool NoOtrOstatok;
		void ValidateOstatok(double treb_kol);


		enum  {NewCheckSale_Operation,NewCheckReturnSale_Operation,
							OpenCheckSale_Operation,OpenCheckReturnSale_Operation,
							NO_Operation} CheckOperation;



		//выбор проекта
		void  ViborProject(void);
		void __fastcall EndViborProject(TObject *Sender);
		__int64 IdProject;

		void CheckDateTimeFR(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaARMKassir *FormaARMKassir;
//---------------------------------------------------------------------------
#endif
