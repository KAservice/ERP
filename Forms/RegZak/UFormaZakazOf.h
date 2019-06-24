//---------------------------------------------------------------------------

#ifndef UFormaZakazOfH
#define UFormaZakazOfH
//---------------------------------------------------------------------------


#include "IDMSprDiscountCard.h"
#include "IDMSprNakSkidok.h"
#include "IDMSprDiscountAuto.h"
#include "IDMRegZak.h"
#include "UDM.h"
#include "IFormaSpiskaSprBVNomTouch.h"
#include "IFormaSpiskaSprEdTouch.h"
#include "IDMSprNom.h"
#include "IDMSprKlient.h"
#include "IKalkulator.h"
#include "IFormaDocCheckTouch.h"
#include "IFormaDocRealRoznTouch.h"
#include "UFormaPrintZakaz.h"
#include "IDMFibConnection.h"
#include "IDisplayPok.h"
#include "IFiskReg.h"
#include "IDMSprEd.h"
#include "IObjectBarCode.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>

#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBLabel.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaZakazOf : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TBitBtn *BitBtnNewString;
        TBitBtn *BitBtnEditEd;
        TBitBtn *BitBtnEditKolZak;
        TBitBtn *BitBtnEditKolOtp;
        TBitBtn *BitBtnDeletestring;
        TDBText *NameObjectZak;
        TBitBtn *BitBtnPrintNaKuh;
        TBitBtn *BitBtnSave;
        TBitBtn *BitBtnOK;
        TBitBtn *BitBtnCreateCheck;
        TBitBtn *BitBtnOtpAll;
        TLabel *SostZakaz;
        TBitBtn *BitBtnClose;
        TBitBtn *BitBtnDelZak;
        TBitBtn *BitBtn4;
        TGroupBox *GroupBox1;
        TDBText *SumDoc;
        TDBText *KrNameNomDBText;
        TLabel *Label2;
        TDBText *MPrigDBText;
        TLabel *Label3;
        TBitBtn *BitBtnPodbop;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtnPrintSchet;
        TBitBtn *BitBtnNewDocReal;
        TBitBtn *BitBtnViborKlient;
        TLabel *Label4;
        TDBText *NameKlientDBText;
        TDBText *NameUserDBText;
        TLabel *Label5;
        TLabel *ProsmotrLabel;
        TDBText *IDZakDBText;
	TcxDBLabel *NameTypePricecxDBLabel;
	TcxDBLabel *NameDiscountCardcxDBLabel;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLPR_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1KOLOT_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1KOLZ_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1OTKAZ_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1PRSK_ZAKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMSK_ZAKT;
	TBitBtn *BitBtnInputDiscountCard;
	TLabel *Label6;
	TLabel *LabelDescr;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall BitBtnCloseClick(TObject *Sender);
        void __fastcall BitBtnNewStringClick(TObject *Sender);
        void __fastcall BitBtnOKClick(TObject *Sender);
        void __fastcall BitBtnSaveClick(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtnDeletestringClick(TObject *Sender);
        void __fastcall BitBtnEditEdClick(TObject *Sender);
        void __fastcall BitBtnEditKolZakClick(TObject *Sender);
        void __fastcall BitBtnEditKolOtpClick(TObject *Sender);
        void __fastcall BitBtnOtpAllClick(TObject *Sender);
        void __fastcall BitBtnCreateCheckClick(TObject *Sender);
        void __fastcall BitBtnDelZakClick(TObject *Sender);
        void __fastcall BitBtnPrintNaKuhClick(TObject *Sender);
        void __fastcall BitBtnPodbopClick(TObject *Sender);
        void __fastcall BitBtnPrintSchetClick(TObject *Sender);
        void __fastcall BitBtnNewDocRealClick(TObject *Sender);
        void __fastcall BitBtnViborKlientClick(TObject *Sender);
	void __fastcall BitBtnInputDiscountCardClick(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		IDMSprDiscountCard * DMSprDiscountCard;
//		TDMSprNakSkidok * DMSprNakSkidok;
		IDMSprDiscountAuto  * DMSprDiscountAuto;


		void UpdateValuesDiscount(void);
		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
//		double NakoplSumma;
	   //	double ProcentSkidkiPoDiscountCard;

			//ввод кода быстрого вызова
		void OpenFormInputCodeNomBV(void);
		void __fastcall EndInputCodeBV(void);

		IFormaSpiskaSprBVNomTouch *SpisokBVTouch;
		IFormaSpiskaSprEdTouch  * SpisokEd;
		IFormaDocCheckTouch *Check;
		IDMSprNom *Nom;
		IDMSprKlient *DMKlient;
		IKalkulator *Kalkulator;
		IFormaDocRealRoznTouch * DocReal;
//        void OpenFormSpiskaSprBVNom(void);
//        void OpenFormSpiskaSprEd(void);
		void OpenFormSpiskaBVNomTouch(void);
		void OpenFormMnViborSpiskaSprBVNom(void);
		void VibratKlienta(void);
		void CreateCheckKKM(void);
		void CreateDocRealRest(void);


		bool PrintZakaz(void);
		bool PrintSchet(void);



		TFormaPrintZakaz *  FormaPrintZakaz;
		void __fastcall EndPrintZakaz(TObject *Sender);

		enum  {ER_NoRekv,EditNomBVTouch,Tovar,MnViborNom,Edinica,ZakazKol,OtkazKol,OtpKol,
								CreateRealRest,ViborKlient, EditCheck,ViborCard,InputCodeBV, NO} EditRekvisit;

		enum  { aoNO,aoAddNewString} ActionOperation;
		void UpdateSetup(void);


		//выбор дисконтной карты
		void  ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
		 double SummaDoc;

	IFiskReg  *glFR;
	IDisplayPok * glDisplayPok;

		IDMSprEd * Ed;
		IObjectBarCode * ObBar;

        bool CreateDocSchet(void);
public:		// User declarations
		__fastcall TFormaZakazOf(TComponent* Owner);

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


		//Текущий интерфейс
		IDMRegZak * DM;


		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdPod;       //подразделение





		bool Prosmotr;    //только просмотр

		bool ObjectSave;
		void ObnovitForm(void);
		void UpdateForm(void);
		void OpenZakaz(void);




	__int64 IdTypePrice;
	UnicodeString NameTypePrice;

	UnicodeString NameObjectZakaza;
    void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaZakazOf *FormaZakazOf;
//---------------------------------------------------------------------------
#endif
