//---------------------------------------------------------------------------

#ifndef UFormaDocCheckTouchH
#define UFormaDocCheckTouchH
//---------------------------------------------------------------------------
#include "IKalkulator.h"
#include "IFormaSpiskaSprBVNomTouch.h"
#include "IFormaSpiskaSprEdTouch.h"
#include "UFormaPanelButtonTouch.h"
#include "IDMSprARM.h"
#include "IDMSprNom.h"
#include "IDMDocCheck.h"
#include "UDM.h"
#include "IDMSprDiscountCard.h"
#include "IDMSprNakSkidok.h"
#include "IDMSprDiscountAuto.h"
#include "IDMFibConnection.h"
#include "IDisplayPok.h"
#include "IScaner.h"
#include "IFiskReg.h"
#include "IDMSprEd.h"
#include "IObjectBarCode.h"
//--------------------------------------------------------------------------
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
#include "cxContainer.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TFormaDocCheckTouch : public TForm
{
__published:	// IDE-managed Components
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TPanel *Panel1;
	TLabel *NameDoc;
	TLabel *UchLabel;
	TDBText *NumDocDBText;
	TLabel *NamePriceLabel;
	TLabel *Label4;
	TDBText *NameKlientDBText;
	TLabel *Label1;
	TPanel *Panel8;
	TDBText *DBText1;
	TLabel *Label5;
	TPanel *Panel11;
	TLabel *Label7;
	TDBText *DBText3;
	TPanel *Panel12;
	TLabel *Label8;
	TDBText *DBText4;
	TPanel *Panel13;
	TLabel *Label6;
	TDBText *DBText2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtnAddSprBVNom;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TBitBtn *BitBtn7;
	TBitBtn *BitBtnAddGoodsPoCodu;
	TBitBtn *BitBtnPodbor;
	TBitBtn *BitBtnInputDiscountCard;
	TcxDBLabel *NameDiscountCardcxDBLabel;
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
	TcxGridDBColumn *cxGrid1DBTableView1SKCHKT;
	TcxGridLevel *cxGrid1Level1;
	TPanel *Panel3;
	TDBText *NameKlientDopDBText;
	TDBText *NameCardDopDBText;
	TLabel *Label17;
	TLabel *Label18;
	TGroupBox *GroupBox14;
	TPanel *Panel4;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn8;
	TBitBtn *BitBtn9;
	TBitBtn *BitBtn10;
	TcxGrid *cxGrid2;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid2DBTableView1SUMPLAT_DCHK_OPL;
	TcxGridDBColumn *cxGrid2DBTableView1SUMCREDIT_DCHK_OPL;
	TcxGridLevel *cxGrid2Level1;
	TPanel *Panel7;
	TPanel *Panel9;
	TPanel *Panel10;
	TGroupBox *GroupBox15;
	TcxDBLabel *AllOplPlatCardcxDBLabel;
	TGroupBox *GroupBox16;
	TcxDBLabel *AllOplCreditCardcxDBLabel;
	TStatusBar *StatusBar;
	TPanel *Panel2;
	TBitBtn *BitBtn11;
	TBitBtn *BitBtn14;
	TBitBtn *PrintCheckBitBtn;
	TBitBtn *BitBtn17;
	TGroupBox *GroupBox5;
	TDBText *SumDocDBText;
	TGroupBox *GroupBox7;
	TDBText *SdachaDBText;
	TGroupBox *GroupBox6;
	TDBText *AllOplDBText;
	TGroupBox *GroupBox8;
	TDBText *OplataBankCardDBText;
	TGroupBox *GroupBox9;
	TDBText *NalChkDBText;
	TDBText *Oper;
	TLabel *Prim;
	TPanel *Panel5;
	TDBText *KrNameNomDBText;
	TPanel *Panel14;
	TGroupBox *GroupBox13;
	TGroupBox *GroupBox11;
	TDBText *OplataPlatCardDBText;
	TBitBtn *InputSumOsnPlatCardBitBtn;
	TGroupBox *GroupBox12;
	TDBText *OplataCreditCardDBText;
	TBitBtn *InputSumOsnCreditCardBitBtn;
	TPanel *Panel6;
	TBitBtn *BitBtn16;
	TGroupBox *GroupBox1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtnAddSprBVNomClick(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtnPodborClick(TObject *Sender);
	void __fastcall BitBtnInputDiscountCardClick(TObject *Sender);
	void __fastcall BitBtnAddGoodsPoCoduClick(TObject *Sender);
	void __fastcall BitBtn11Click(TObject *Sender);
	void __fastcall BitBtn14Click(TObject *Sender);
	void __fastcall PrintCheckBitBtnClick(TObject *Sender);
	void __fastcall BitBtn17Click(TObject *Sender);
	void __fastcall InputSumOsnPlatCardBitBtnClick(TObject *Sender);
	void __fastcall InputSumOsnCreditCardBitBtnClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);

private:	// User declarations

		void __fastcall EndEdit(TObject *Sender);

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		//выбор дисконтной карты
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		IDMSprDiscountCard * DMSprDiscountCard;
		IDMSprDiscountAuto  * DMSprDiscountAuto;

		void UpdateValuesDiscount(void);
		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);

		//ввод кода быстрого вызова
		void OpenFormInputCodeNomBV(void);
		void __fastcall EndInputCodeBV(void);

		IKalkulator *Kalkulator;


		enum  {ER_NoRekv,EditNomBVTouch,EditEdinica,EditKol, EditNal,
			EditOplataPC, EditPanelButton, MnViborNom, InputCodeBV,
			ViborCard, NO,
			ER_InputSumOsnPlatCard, ER_InputSumOsnCreditCard,
			ER_InputSumProchee,
			ER_AddDopPlatCard, ER_InputSumDopPlatCard, ER_InputSumDopCreditCard} EditRekvisit;

         enum  { aoNO,aoAddNewString} ActionOperation;
		IFormaSpiskaSprBVNomTouch *SpisokBVTouch;
        void OpenFormSpiskaSprBVNom(void);
        void OpenFormMnViborSpiskaSprBVNom(void);


		IFormaSpiskaSprEdTouch  * SpisokEd;
        void OpenFormSpiskaSprEd(void);

        TFormaPanelButtonTouch  *PanelButton;
		void OpenPanelButton();

		void OpenFormSpiskaBVNomTouch(void);

		bool PrintCheck(void);
		bool PrintStandartFiscalCheck(void);
		bool PrintStandartNoFiscalCheck(void);
		bool PrintPoFirmFiscalCheck(__int64 id_firm_for_fiscal_check);
		bool PrintPoFirmNoFiscalCheck(__int64 id_firm_for_fiscal_check);

		bool PrintPoFirmNoFiscalCheck_Header(__int64 id_firm);
		bool PrintPoFirmNoFiscalCheck_Footer(__int64 id_firm, double sum);

		void UpdateSetup(void);

		IDMSprNom *Nom;
		IDMSprEd * Ed;
		IObjectBarCode * ObBar;

		IDMSprARM *ARM;

		void SummaCheck(void);


	IFiskReg  *glFR;
	IScaner * glScaner;
	IDisplayPok * glDisplayPok;


	void EndInputSumOsnPlatCard(void);
	void EndInputSumOsnCreditCard(void);
	void EndInputSumProchee(void);
	void EndAddDopPlatCard(void);
	void EndInputSumDopPlatCard(void);
	void EndInputSumDopCreditCard(void);

	UnicodeString TextMessage;
	int KolNoFiscalCheck;

	bool CheckOplataBeforePrintCheck(void);
	bool CheckSumPlatCard(void);
	bool CheckSumCreditCard(void);

public:		// User declarations
		__fastcall TFormaDocCheckTouch(TComponent* Owner);

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


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме



		IDMDocCheck *DM;


         


		bool Prosmotr;
		__int64 IdDoc;

        void UpdateForm(void);


        __int64 IdARM;


        bool CheckSave;
        bool CheckPrint;
		bool CheckCreate;

		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocCheckTouch *FormaDocCheckTouch;
//---------------------------------------------------------------------------
#endif
