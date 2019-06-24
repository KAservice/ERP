//---------------------------------------------------------------------------

#ifndef UFormaDocRKORoznH
#define UFormaDocRKORoznH
//---------------------------------------------------------------------------

#include "UFormaViborFR.h"
#include "IFormaSpiskaSprDiscountCard.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaRunExternalModule.h"
#include "IDMDocRKORozn.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
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
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxPC.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocRKORozn : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TLabel *Label12;
	TLabel *Label15;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label14;
	TLabel *Label8;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label9;
	TPanel *Panel2;
	TLabel *ProsmotrLabel;
	TDBText *DBTextFNameUser;
	TcxButton *cxButtonprintCheckNaFR;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxDBTextEdit *NCheckcxDBTextEdit;
	TcxDBTextEdit *NKLcxDBTextEdit;
	TcxDBTextEdit *RegNumcxDBTextEdit;
	TcxDBTextEdit *SavNumcxDBTextEdit;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCalcEdit *SumDoccxDBCalcEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBTextEdit *OsncxDBTextEdit;
	TcxDBTextEdit *VidatcxDBTextEdit;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameKassacxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel6;
	TcxDBImageComboBox *OpercxDBImageComboBox;
	TcxDBButtonEdit *NameCardcxDBButtonEdit;
	TLabel *Label1;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButton3;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel7;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonprintCheckNaFRClick(TObject *Sender);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall PosDoccxDBDateEditPropertiesChange(TObject *Sender);
	void __fastcall NameKassacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall VidatcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OsncxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SumDoccxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameCardcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

		  			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprKKM * SpisokKKM;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;

        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprKKM(void);
        void OpenFormSpiskaSprDogovor(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);

		enum  {ER_NoRekv,ViborTovar,ViborEdinica,ViborFirm,ViborSklad, ER_BusinessOper, ER_Project,
		ViborKlient,ViborKKM, ViborInfBase, ViborDogovor, ViborCard_Rekvisit,  NO} EditRekvisit;

		IFormaSpiskaSprDiscountCard * FormaSpiskaSprDiscountCard ;
		void ViborCard(void);
		void __fastcall EndViborCard(void);
		int numRow;
		int numCol;
		TFormaViborFR *FormaViborFR;
		void PrintCheckFR(void);
		void __fastcall EndViborFR(TObject *Sender);

		void PrintDoc(void);
		bool flObrabatChangeOperation;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

public:		// User declarations
		__fastcall TFormaDocRKORozn(TComponent* Owner);

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





		//Текущий интерфейс
		 IDMDocRKORozn *DM;

		__int64 IdDoc;           //идентификатор текущей записи
        bool Prosmotr;    //только просмотр
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRKORozn *FormaDocRKORozn;
//---------------------------------------------------------------------------
#endif
