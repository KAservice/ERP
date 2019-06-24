//---------------------------------------------------------------------------

#ifndef UFormaDocVosvratPokH
#define UFormaDocVosvratPokH
//---------------------------------------------------------------------------
#include "IDMTableExtPrintForm.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IDMDocVosvratPok.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaGurAllDoc.h"
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
//---------------------------------------------------------------------------
class TFormaDocVosvratPok : public TForm
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
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBTextFNameUser;
        TLabel *Label7;
        TToolButton *ToolButtonPodbor;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label11;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxComboBox *OperComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxComboBox *TypeRPriceComboBox;
	TcxDBButtonEdit *NameDogcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonCreateRKORozn;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonextModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxDBTextEdit *KlientNameStrcxDBTextEdit;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxDBTextEdit *KlientAdrcxDBTextEdit;
	TcxDBTextEdit *KlientPhonecxDBTextEdit;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel11;
	TcxDBTextEdit *PassportcxDBTextEdit;
	TcxDBTextEdit *PrichinacxDBTextEdit;
	TcxLabel *cxLabel10;
	TcxDBTextEdit *NumDocSalecxDBTextEdit;
	TcxDBDateEdit *PosDocSalecxDBDateEdit;
	TcxLabel *cxLabel4;
	TcxDBTextEdit *NumDocKlientcxDBTextEdit;
	TcxLabel *cxLabel2;
	TcxDBDateEdit *PosDocKlientcxDBDateEdit;
	TcxDBButtonEdit *DocOsncxDBButtonEdit;
	TLabel *Label22;
	TToolButton *ToolButtonNewDocRKO;
	TToolButton *ToolButtonCreateDocRKO;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonPodborClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DescrDBEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall OperComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameDogcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NmaeInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateRKORoznClick(TObject *Sender);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OperComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DescrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

			//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall DocOsncxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonCreateDocRKOClick(TObject *Sender);
	void __fastcall PrefiksNumcxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);


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
        void OpenFSSprNom(void);
        void OpenFSSprEd(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


		enum  {ER_NoRekv,Tovar,Edinica,FirmaRekvisit,KlientRekvisit,
		SkladRekvisit, PodborNom, ViborInfBase,ViborDogovor,ER_BusinessOper,
		ER_Project,ER_ViborDocOsn, NO} EditRekvisit;

         enum  {aoNO,aoAddNewString} ActionOperation;


		IFormaSpiskaSprEd * Ed;
		IFormaSpiskaSprNom * Nom;
		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
		IFormaSpiskaSprKlient * Klient;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;
		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
		 double SummaDoc;

		void  OpenFormSpiskaSprFirm(void);
		void  OpenFormSpiskaSprSklad(void);
		void  OpenFormSpiskaSprKlient(void);
		void OpenFormSpiskaSprDogovor(void);

		void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		IDMSprTypePrice *DMSprTypePrice;
		IDMSprTypePrice *DMSprRTypePrice;

		bool flObrabatChangeTypePrice;
		bool flObrabatChangeRoznTypePrice;
		bool flObrabatChangeOperation;

		void CreateDocRashodNal(void);

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);


        IFormaGurAllDoc * FormaGurAllDoc;
		void ViborDocOsn(void);
		void EndViborDocOsn(void);

public:		// User declarations
		__fastcall TFormaDocVosvratPok(TComponent* Owner);

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
		IDMDocVosvratPok * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		bool Prosmotr;    //������ ��������
        bool ObjectSave;



		__int64 IdDoc;           //������������� ������� ������



        void UpdateForm(void);


		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocVosvratPok *FormaDocVosvratPok;
//---------------------------------------------------------------------------
#endif
