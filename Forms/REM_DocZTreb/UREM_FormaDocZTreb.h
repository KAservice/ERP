//---------------------------------------------------------------------------

#ifndef UREM_FormaDocZTrebH
#define UREM_FormaDocZTrebH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "UDM.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IREM_DMDocZTreb.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
//--------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
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
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaDocZTreb : public TForm
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
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_DZTREBT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_DZTREBT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_REM_DZTREBT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_REM_DZTREBT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameZcxDBButtonEdit;
	TLabel *Label4;
	TLabel *Label7;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonCreateCheck;
	TToolButton *ToolButtonCreateRealRozn;
	TToolButton *ToolButtonCreateReal;
	TcxDBLabel *NameKlientcxDBLabel;
	TcxDBLabel *ModelcxDBLabel;
	TcxDBLabel *PosZcxDBLabel;
	TcxDBLabel *NumZcxDBLabel;
	TcxDBLabel *SerNumcxDBLabel;
	TcxDBLabel *SerNum2cxDBLabel;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1DVREG_REM_DZTREBT;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 //       void __fastcall AddNewStringClick(TObject *Sender);
 //       void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall PosDoccxDBDateEditPropertiesChange(TObject *Sender);
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
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

					//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

			//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		//����� �������������� ����
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//����� �����
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//����� ������
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);

		//����� �������
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		//����� ������
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);


		//����� �������
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		void ViborEd(void);
		void __fastcall EndViborEd(void);

		enum  { aoNO,aoAddNewString} ActionOperation;
		enum {ER_NoRekv,ER_No, ER_InfBase,ER_Firm,ER_Sklad,ER_Klient,
						ER_Zayavka,ER_Nom,ER_Ed, ER_Hardware,ER_CreateCheck} EDitRekvisit;
        
		IDMSprTypePrice *DMSprTypeRPrice;
		void BeforeSaveDoc(void);

		void AfterSaveDoc(void);


public:		// User declarations
		__fastcall TREM_FormaDocZTreb(TComponent* Owner);
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
		IREM_DMDocZTreb * DM;


		bool Prosmotr;    //������ ��������

		__int64 IdDoc;           //������������� ������� ������
		bool OutReady;

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;


		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocZTreb *REM_FormaDocZTreb;
//---------------------------------------------------------------------------
#endif
