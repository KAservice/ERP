//---------------------------------------------------------------------------

#ifndef UREM_FormaDocVZipPerH
#define UREM_FormaDocVZipPerH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprInfBase.h"
#include "UDM.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IREM_DMDocVZipPer.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprTypeNom.h"
#include "IFormaSpiskaSprStorageLocation.h"
#include "IREM_FormaSpiskaSprHardwareVZip.h"

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
class TREM_FormaDocVZipPer : public TForm
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
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label4;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM2_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1KLIENT_NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_DVZPERT;
	TcxLabel *cxLabel2;
	TcxDBButtonEdit *NameSkladPolcxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TcxDBImageComboBox *OperationDoccxDBImageComboBox;
	TLabel *Label7;
	TToolButton *ToolButtonCreatePost;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_STNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_STVZIP;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SPRMODEL;
	TToolButton *ToolButtonAddAllOstatki;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN_OTPR;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN_POL;
	TToolButton *ToolButtonViborOborud;
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
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

					//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall NumDocKlientcxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PosDocKlientcxDBDateEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladPolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreatePostClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_STNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddAllOstatkiClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_SMHRAN_OTPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_SMHRAN_POLPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonViborOborudClick(TObject *Sender);



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

		void ViborSkladPol(void);
		void __fastcall EndViborSkladPol(void);

		//����� �������
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		//����� ������
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

		enum  { aoNO,aoAddNewString} ActionOperation;
		enum {ER_NoRekv,ER_No, ER_InfBase,ER_Firm,ER_Sklad,ER_Klient,
						ER_Zayavka,ER_Nom,ER_Ed, ER_Hardware,ER_CreateCheck,
						ER_SkladPol,ER_BusinessOper, ER_Project,
						ER_TypeNom,
						ER_TypeVZip,
						ER_KlientProducer,
						ER_ViborStorageLocationOtpr,
						ER_ViborStorageLocationPol,
						ER_ViborHWIsSprVosvrZip} EditRekvisit;

		void BeforeSaveDoc(void);

		void AfterSaveDoc(void);

		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void EndViborProject(void);

	void ViborKlientProducer(void);
	void EndViborKlientProducer(void);

	IFormaSpiskaSprTypeNom *SpisokTypeNom;
	void OpenFormSpiskaSprTypeNom(void);
	void EndViborTypeNom(void);

	IFormaSpiskaSprNom *SpisokNom;
	void OpenFormSpiskaSprNom(void);
	void EndViborNom(void);

	IREM_FormaSpiskaSprHardware *SpisokHardware;
	void OpenFormSpiskaSprHardware(void);
	void EndViborHardware(void);


		IFormaSpiskaSprStorageLocation* FormaSpiskaSprStorageLocation;
		void ViborStorageLocationOtpr(void);
		void EndViborStorageLocationOtpr(void);
		void ViborStorageLocationPol(void);
		void EndViborStorageLocationPol(void);



	IREM_FormaSpiskaSprHardwareVZip *SpisokHardwareVZip;
	void OpenFormSpiskaSprHardwareVZip(void);
	void EndViborHardwareVZip(void);


public:		// User declarations
		__fastcall TREM_FormaDocVZipPer(TComponent* Owner);
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

		IREM_DMDocVZipPer * DM;

		bool Prosmotr;    //������ ��������

		__int64 IdDoc;           //������������� ������� ������


		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocVZipPer *REM_FormaDocVZipPer;
//---------------------------------------------------------------------------
#endif
