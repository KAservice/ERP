//---------------------------------------------------------------------------

#ifndef UFormaDocPostNaSchetH
#define UFormaDocPostNaSchetH
//---------------------------------------------------------------------------

#include "IDMDocPostNaSchet.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprRaschSchet.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IDMTableExtPrintForm.h"
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
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocPostNaSchet : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label17;
        TLabel *Label11;
        TLabel *Label16;
        TLabel *Label10;
        TLabel *Label9;
        TLabel *Label13;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label23;
        TLabel *Label21;
        TLabel *Label1;
        TLabel *ProsmotrLabel;
        TDBText *DBTextFNameUser;
        TLabel *Label3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxDBTextEdit *NumcxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameRSchetcxDBButtonEdit;
	TcxDBDateEdit *DatePPcxDBDateEdit;
	TcxDBTextEdit *NumPPcxDBTextEdit;
	TcxDBTextEdit *NasnPlatcxDBTextEdit;
	TcxDBCalcEdit *SumDoccxDBCalcEdit;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBImageComboBox *OpercxDBImageComboBox;
	TToolBar *ToolBar2;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameRSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NumcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DatePPcxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumPPcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NasnPlatcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SumDoccxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

			//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
	//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprBankSchet * SpisokBSchet;
		IFormaSpiskaSprRaschSchet * SpisokRSchet;

        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprBSchet(void);
        void OpenFormSpiskaSprRSchet(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);

		bool flObrabatChangeOperation;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

		 enum  {ER_NoRekv,ER_InfBase, ER_Firm,ER_BSchet, ER_Klient, ER_KlientRSchet,
					 ER_BusinessOper, ER_Project, ER_NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaDocPostNaSchet(TComponent* Owner);

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
		IDMDocPostNaSchet *DM;
		void UpdateForm(void);

        bool Prosmotr;    //������ ��������
		bool Vibor;       //��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		__int64 IdDoc;           //������������� ������� ������



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocPostNaSchet *FormaDocPostNaSchet;
//---------------------------------------------------------------------------
#endif
