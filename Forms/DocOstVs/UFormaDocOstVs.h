//---------------------------------------------------------------------------

#ifndef UFormaDocOstVsH
#define UFormaDocOstVsH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMDocOstVs.h"
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
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocOstVs : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label12;
        TLabel *Label14;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBCalcEdit *PrihodcxDBCalcEdit;
	TcxDBCalcEdit *RashodcxDBCalcEdit;
	TcxDBCheckBox *DvRegPaySalecxDBCheckBox;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameInfbasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall PosDoccxDBDateEditPropertiesChange(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrihodcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall RashodcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DvRegPaySalecxDBCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
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

        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprKlient(void);


		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


        enum  {ER_NoRekv,ViborFirm,
		ViborKlient, ViborInfBase,ER_BusinessOper, ER_Project, NO} EditRekvisit;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

public:		// User declarations
		__fastcall TFormaDocOstVs(TComponent* Owner);

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
		IDMDocOstVs *DM;

        bool Prosmotr;    //������ ��������

		__int64 IdDoc;           //������������� ������� ������

        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocOstVs *FormaDocOstVs;
//---------------------------------------------------------------------------
#endif
