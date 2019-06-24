//---------------------------------------------------------------------------

#ifndef UREM_FormaDocOstNomH
#define UREM_FormaDocOstNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMDocOstNom.h"

#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaGurAllDoc.h"
#include "IFormaSpiskaSprObject.h"
#include "IFormaSpiskaSprStorageLocation.h"
//----------------------------------------------------------------------------
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
#include "cxPC.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
#include "UREM_DMDocPrihNakl.h"
#include "cxDBLabel.hpp"
//---------------------------------------------------------------------------
class TREM_FormaDocOstNom : public TForm
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
        TLabel *Label7;
        TPopupMenu *PopupMenu1;
        TMenuItem *AddNewString;
        TMenuItem *DeleteString;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *RTPriceLabel;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypeRPriceComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TcxPageControl *TablecxPageControl;
	TcxTabSheet *MaincxTabSheet;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonOpenNom;
	TToolButton *ToolButtonOpenEd;
	TAction *ActionEditNom;
	TAction *ActionEditEd;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDED_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDHW_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_REM_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TToolButton *ToolButtonLoadNaOsnOstNom;
	TToolButton *ToolButtonAddSprHW;
	TcxGridDBColumn *cxGrid1DBTableView1DVREG_REM_DOSNT;
	TToolButton *ToolButtonOpenOborud;
	TAction *ActionEditOborud;
	TcxDBButtonEdit *NameObjectcxDBButtonEdit;
	TLabel *Label4;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_TYPE_NOM_LOOCUP;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN;
	TToolButton *ToolButtonSetDvRegAll;
	TToolButton *ToolButtonDelDvRegAll;
	TToolButton *ToolButtonSetMestoHran;
	TcxDBLabel *cxDBLabelIDDoc;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddNewStringClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
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
	void __fastcall IsmPriceCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumDocPostcxDBTextEditKeyPress(TObject *Sender, char &Key);
	void __fastcall PosDocPostcxDBDateEditKeyPress(TObject *Sender, char &Key);

				//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionEditNomExecute(TObject *Sender);
	void __fastcall ActionEditEdExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddSprHWClick(TObject *Sender);
	void __fastcall ActionEditOborudExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonSetDvRegAllClick(TObject *Sender);
	void __fastcall ToolButtonDelDvRegAllClick(TObject *Sender);
	void __fastcall ToolButtonSetMestoHranClick(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
	//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


        void InputNewDoc(void);
        void OpenDoc(void);
        bool SaveNewDoc(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
		bool CancelDvDoc(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


		 enum  {aoNO,aoAddNewString} ActionOperation;

		IFormaSpiskaSprEd * Ed;
		IFormaSpiskaSprNom * Nom;
		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
	         double SummaDoc;

		void  OpenFormSpiskaSprFirm(void);
		void  OpenFormSpiskaSprSklad(void);

		IDMSprTypePrice *DMSprTypePrice;
		IDMSprTypePrice *DMSprTypeRPrice;


		bool flObrabatChangeTypePrice;
		bool flObrabatChangeRoznTypePrice;


		void BeforeSaveDoc(void);

		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

		 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Sklad, ER_Klient,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_PodborNom, ER_GrpNom,
					  ER_Ed,ER_Part, ER_ElementNom, ER_ElementEd, ER_Hardware,
					  ER_DocOstNom,ER_ElementHW, ER_GurAllDoc, ER_NO,
					  ER_Object,
						ER_ViborStorageLocation} EditRekvisit;

		 void OpenFSSprNom(void);
		 void OpenFSSprEd(void);


		 //����� ������������
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void EndViborHardware(void);

	IFormaSpiskaSprObject *SpisokObject;
	void OpenFormSpiskaSprObject(void);
	void __fastcall EndViborObject(void);


			IFormaSpiskaSprStorageLocation* FormaSpiskaSprStorageLocation;
		void ViborStorageLocation(void);
		void EndViborStorageLocation(void);

public:		// User declarations
		__fastcall TREM_FormaDocOstNom(TComponent* Owner);

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

		IREM_DMDocOstNom * DM;

		bool ObjectSave;
		bool Prosmotr;    //������ ��������
		__int64 IdDoc;           //������������� ������� ������
		__int64 IdGrp;        // ������������� ������
		__int64 IdElementaMaster;  //������������� �������� �����������-���������


		 __int64 VibTovarId;
         __int64 VibTovarIdGrp;


        void UpdateForm(void);


	void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocOstNom *REM_FormaDocOstNom;
//---------------------------------------------------------------------------
#endif
