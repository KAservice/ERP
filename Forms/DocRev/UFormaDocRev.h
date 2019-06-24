//---------------------------------------------------------------------------

#ifndef UFormaDocRevH
#define UFormaDocRevH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <IBDatabase.hpp>
#include <Mask.hpp>

//-----------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMDocRev.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprInv.h"
#include "USheetEditor.h"
#include "IFormaInputCode.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprGrpNom.h"
//--------------------------------------------------------------------
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
#include "UDM.h"


//---------------------------------------------------------------------------
class TFormaDocRev : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *NameUserDBText;
        TToolButton *ToolButton2;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TLabel *Label4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label8;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEGN;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonPoGrp;
	TcxButton *cxButtonFaktOst;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxComboBox *TypePriceComboBox;
	TcxDBButtonEdit *NameInvcxDBButtonEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonAddOstatkiNom;
	TToolButton *ToolButtonAddNomPoCodu;
	TAction *ActionAddNomPoCodu;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonAddOstatkiPoGrp;
	TcxGridDBColumn *cxGrid1DBTableView1UCH_KOL_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1UCH_RSUM_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1UCH_SUM_DREVT;
	TToolButton *ToolButtonAddAllNomIsGrp;
	TToolButton *ToolButtonSetKolNull;
	TToolButton *ToolButtonMoveInDocPer;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM_DREVT;
	TcxGridDBColumn *cxGrid1DBTableView1IDED_DREVT;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddNewStringClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonPoGrpClick(TObject *Sender);
	void __fastcall cxButtonFaktOstClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameInvcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DescrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButtonAddOstatkiNomClick(TObject *Sender);
	void __fastcall ActionAddNomPoCoduExecute(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ToolButtonAddOstatkiPoGrpClick(TObject *Sender);
	void __fastcall ToolButtonAddAllNomIsGrpClick(TObject *Sender);
	void __fastcall ToolButtonSetKolNullClick(TObject *Sender);
	void __fastcall ToolButtonMoveInDocPerClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


         int * SpisokGrp;

		void NewDoc(void);
		void OpenDoc(void);
		bool SaveDoc(void);
		bool DvRegDoc(void);
		bool CancelDvDoc(void);


		void OpenFSSprNom(void);
		void OpenFSSprEd(void);
		IFormaSpiskaSprNom * Nom;

		enum  {ER_NoRekv,Tovar,Edinica,FirmaRekvisit,SkladRekvisit,
				ViborTypePrice, ViborInfBase, InvRekvisit, InputCodeNom,ViborGrpNom,
				ER_AddAllNomIsGrp,NO} EditRekvisit;
		 enum  {aoNO,aoAddNewString} ActionOperation;
        
		IDMSprPrice* DMSprPrice;

		bool flObrabatChangeTypePrice;
		IDMSprTypePrice *DMSprTypePrice;

		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
        void  OpenFormSpiskaSprFirm(void);
        void  OpenFormSpiskaSprSklad(void);

        void OpenFormSpiskaSprInfBase(void);
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;

		IFormaSpiskaSprInv  * FormaSpiskaSprInv;
		void OpenFormSpiskaSprInv(void);

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
        void OpenPrintForm(void) ;
		void OutputString(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		double SumDoc;

        void OpenPrintFormPrice(void) ;
        void OutputStringPrice(TSheetEditor *prForm);
        void OutputZagolovokReportPrice(TSheetEditor *prForm);
		void OutputPodavalReportPrice(TSheetEditor *prForm);

        void OpenPrintFormPoGrp(void) ;
		void OutputStringReportPoGrp(TSheetEditor *prForm);
		void OutputStringGroupReportPoGrp(TSheetEditor *prForm);
		void OutputPodavalReportGrp(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		int IdTypePrice;
		double SummaReport;


		//ввод кода номенклатуры
		IFormaInputCode *FormaInputCode;
		void __fastcall EndInputCodeNom(void);
		void OpenFormInputCodeNom(void);

		IFormaSpiskaSprGrpNom * FormaViborGrpNomSpr;
		void OpenFormViborGrpNom(void);
		void EndViborGrpNom(void);
		void OpenFormViborGrpNomForAddAllNom(void);
		void EndViborGrpNomForAddAllNom(void);

public:		// User declarations
		__fastcall TFormaDocRev(TComponent* Owner);

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

       void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		//Текущий интерфейс

		bool Prosmotr;    //только просмотр
        bool ObjectSave;
        bool NoEdit;




		IDMDocRev * DM;


		__int64 IdDoc;           //идентификатор текущей записи




		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRev *FormaDocRev;
//---------------------------------------------------------------------------
#endif
