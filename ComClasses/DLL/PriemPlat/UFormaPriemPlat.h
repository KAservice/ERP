//---------------------------------------------------------------------------

#ifndef UFormaPriemPlatH
#define UFormaPriemPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDMPriemPlat.h"
#include "IDMSprARM.h"
#include "IDMSprKlient.h"
#include "IDMSprNumTel.h"
#include "IDMGurPlat.h"
#include "IDMDocCheck.h"
#include "IDisplayPok.h"
#include "IFiskReg.h"

#include "IDMSprCodeTel.h"
#include "IDMSprOborud.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <oleauto.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCalc.hpp"
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TFormaPriemPlat : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *X1;
        TMenuItem *Z1;
        TMenuItem *N2;
        TMenuItem *N3;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
	TMenuItem *N4;
	TMenuItem *MaimMenuProvestiPlateg;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TcxGridDBTableView *cxGrid1DBTableViewOperators;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TPanel *Panel5;
	TPanel *Panel6;
	TcxGrid *cxGrid2;
	TcxGridLevel *cxGrid2Level1;
	TPanel *Panel4;
	TLabel *NumKvLabel;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label5;
	TLabel *Label2;
	TLabel *KlNaydenLabel;
	TLabel *Prim;
	TLabel *SumKlLabel;
	TcxTextEdit *CodeEdit;
	TcxTextEdit *NumberEdit;
	TcxTextEdit *NameKlientEdit;
	TcxComboBox *ComboBox;
	TcxCalcEdit *SumCheckEdit;
	TcxButton *ButtonPrintCheck;
	TcxButton *ButtonPrintKvitan;
	TcxGridTableView *cxGrid2TableView1;
	TcxGridDBColumn *cxGrid1DBTableViewOperatorsNAME_CODETEL;
	TcxGridDBColumn *cxGrid1DBTableViewOperatorsCODOPER_CODETEL;
	TcxGridDBColumn *cxGrid1DBTableViewOperatorsPRCOMIS_SCODETEL;
	TcxGridColumn *cxGrid2TableView1Column1;
	TcxGridColumn *cxGrid2TableView1Column2;
	TcxGridColumn *cxGrid2TableView1Column3;
	TDBText *DBTextNAME_CODETEL;
	TDBText *DBTextNAMENOM;
	TDBText *DBTextNOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
	TDBText *DBTextNAMENOMCOM;
	TDBText *DBTextCOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
	TDBText *DBTextPRCOMIS_SCODETEL;
	TLabel *NameKKMLabel;
	TLabel *UchLabel;
	TLabel *LabelNameBank;
	TLabel *LabelNumTerminal;
	TLabel *LabelNumDoc;
	TLabel *LabelAdressTerminal;
	TLabel *LabelDateTimePlatega;
	TLabel *LabelNameDomOperator;
	TLabel *LabelCodeAutorization;
	TLabel *LabelLicSchetIsCiberplat;
	TcxTextEdit *cxTextEditLicSchet;
	TLabel *Label1;
	TLabel *LabelMsg;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TLabel *LabelIdTerminal;
	TLabel *LabelZaprosProverkaRekvisitov;
	TLabel *LabelCatalogCiberplat;
	TcxButton *ButtonClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall X1Click(TObject *Sender);
        void __fastcall Z1Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
	void __fastcall ButtonPrintKvitanClick(TObject *Sender);
	void __fastcall ButtonPrintCheckClick(TObject *Sender);
	void __fastcall CodeEditKeyPress(TObject *Sender, char &Key);
	void __fastcall CodeEditExit(TObject *Sender);
	void __fastcall NumberEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NumberEditExit(TObject *Sender);
	void __fastcall NameKlientEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NameKlientEditExit(TObject *Sender);
	void __fastcall OtdelEditKeyPress(TObject *Sender, char &Key);
	void __fastcall SumCheckEditKeyPress(TObject *Sender, char &Key);
	void __fastcall SumCheckEditExit(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall MaimMenuProvestiPlategClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



		__int64 IdARM;
		IDMSprARM * DMSprARM;
		IDMSprOborud *DMSprOborud;
		IDMDocCheck * DMCheck;
		IDMSprKlient * DMKlient;
		IDMSprNumTel *DMSprNumTel;

        TDMPriemPlat *DM;

		bool PrintCheck(void);
		bool PrintFiscalCheck(void);
		bool PrintNoFiscalCheck(void);
		TDateTime PosDoc;
		int NumberDoc;


        bool PrintKvitan(void);
        UnicodeString  StrPrint;

        void SummaCheck(void);
        void UpdateForm(void);
        bool EnablePrintCheck(void);
        double SumCheck;

        bool PoiskKlienta(void);
        bool AddNewKlient(void);
        bool CreateDocCheck(void);
        bool UpdateTextCheck(void);
        bool KlNayden;
        bool UslNayden;
        bool CheckPrint;
        bool CheckSave;

        int NumberKvitan;

        IDMGurPlat * DMGurPlat;

        double SumKlient;



	IFiskReg  *glFR;
	IDisplayPok * glDisplayPok;

	IDMSprCodeTel *DMSprCodeTel;

	__int64 IdVibCodeTel;

	bool flObrabatChangeCodeTel;


	bool ConnectFR(void);
	bool DisconnectFR(void);

	UnicodeString NumberZaprosa;
	UnicodeString NumberTerminalString;
	UnicodeString IdTerminalString;
	UnicodeString CatalogCiberplat;
	UnicodeString CreateZaprosProverki(void);
	void SaveZaprosProverki(void);
	UnicodeString GetNumberZaprosa(void);
	UnicodeString kasDecodeDateTime (TDateTime value);

public:		// User declarations
		__fastcall TFormaPriemPlat(TComponent* Owner);

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

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPriemPlat *FormaPriemPlat;
//---------------------------------------------------------------------------
#endif
