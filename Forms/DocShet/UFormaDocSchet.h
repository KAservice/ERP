//---------------------------------------------------------------------------

#ifndef UFormaDocSchetH
#define UFormaDocSchetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "IDMDocSchet.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "USheetEditor.h"
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
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocSchet : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *ProsmotrLabel;
        TDBText *DBTextFNameUser;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *Label8;
        TLabel *Label9;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLSCHT;
	TcxGridDBColumn *cxGrid1DBTableView1KFSCHT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICESCHT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMSCHT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonReal;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypePriceComboBox;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonCreateReal;
	TToolButton *ToolButtonCreateRealRozn;
	TToolButton *ToolButtonCreateCheck;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonRealClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

			//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ToolButtonCreateRealClick(TObject *Sender);
	void __fastcall ToolButtonCreateRealRoznClick(TObject *Sender);
	void __fastcall ToolButtonCreateCheckClick(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
	//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		IFormaSpiskaSprEd * Ed;
		IFormaSpiskaSprNom * Nom;
		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
		IFormaSpiskaSprKlient * Klient;

		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprEd(void);
		void  OpenFormSpiskaSprFirm(void);
		void  OpenFormSpiskaSprSklad(void);
		void  OpenFormSpiskaSprKlient(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);

		IFormaSpiskaSprBankSchet * FormSpiskaSprBSchet;
		void OpenFormSpiskaSprBSchet(void);
		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
		 double SummaDoc;

		enum  {ER_NoRekv,Tovar,Edinica,FirmaRekvisit,KlientRekvisit,SkladRekvisit,
						ViborInfBase, ViborBankSchet,  NO} EditRekvisit;

		 enum  {aoNO,aoAddNewString} ActionOperation;
	   IDMSprTypePrice *DMSprTypePrice;
	   bool NoEdit;

		void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		bool flObrabatChangeTypePrice;
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);


public:		// User declarations
		__fastcall TFormaDocSchet(TComponent* Owner);

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

        //������� ���������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����



		IDMDocSchet * DM;
		__int64 IdDoc;           //������������� ������� ������
        bool Prosmotr;    //������ ��������
		void UpdateForm(void);





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocSchet *FormaDocSchet;
//---------------------------------------------------------------------------
#endif
