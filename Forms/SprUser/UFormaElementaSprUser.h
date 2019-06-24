//---------------------------------------------------------------------------

#ifndef UFormaElementaSprUserH
#define UFormaElementaSprUserH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IFormaSpiskaSprPodr.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprKKM.h"
#include "IDMSprUser.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IREM_FormaSpiskaSprActCategory.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "IB_Services.hpp"
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxSpinEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprUser : public TForm
{
__published:	// IDE-managed Components
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TPanel *Panel1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TLabel *Label13;
	TLabel *Label12;
	TLabel *Label1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label14;
	TLabel *Label15;
	TDBText *IdDBText;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameKassacxDBButtonEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *Name2cxDBTextEdit;
	TcxDBTextEdit *FNamecxDBTextEdit;
	TcxDBButtonEdit *NameInfcxDBButtonEdit;
	TcxDBButtonEdit *NamePodcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameTPricecxDBButtonEdit;
	TcxButtonEdit *NameTPrice1Edit;
	TcxButtonEdit *NameTPrice2Edit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBRadioGroup *TPosGournalcxDBRadioGroup;
	TcxDBRadioGroup *TPosReportcxDBRadioGroup;
	TcxDBSpinEdit *KolDayGurcxDBSpinEdit;
	TcxDBSpinEdit *KolDayRepcxDBSpinEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxDBCheckBox *ReOpenSprcxDBCheckBox;
	TcxDBCheckBox *ReOpenGurcxDBCheckBox;
	TcxDBCheckBox *EditChugDoccxDBCheckBox;
	TcxDBCheckBox *DelChugDoccxDBCheckBox;
	TcxDBCheckBox *ShowLogcxDBCheckBox;
	TcxDBCheckBox *DetailedLogcxDBCheckBox;
	TcxDBCheckBox *SaveNamecxDBCheckBox;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameActivecategorycxDBButtonEdit;
	TcxLabel *cxLabel4;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameKassacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NamePodcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTPricecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTPrice1EditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTPrice2EditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Name2cxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		IFormaSpiskaSprTypePrice * FormaSpiskaSprTypePrice;
		IFormaSpiskaSprPodr * FormaSpiskaSprPodr;

		IFormaSpiskaSprInfBase *FormaSpiskaSprInfBase;
		void OpenFormaSpiskaSprInfBase(void);

		IFormaSpiskaSprBankSchet * FormSpiskaSprBSchet;
		void OpenFormSpiskaSprBSchet(void);



		enum {NO,ViborFirm, ViborSklad, ViborTPrice,
		 ViborPodr, ViborPrice1, ViborPrice2, ViborInfBase, ViborBankSchet, ViborKassaRekv,
						ER_ViborActCategory} ViborRekv;

		IFormaSpiskaSprKKM * FormaSpiskaSprKKM;
		void ViborKassa(void);
		void __fastcall EndViborKassa(void);


		IREM_FormaSpiskaSprActCategory * REM_FormaSpiskaSprActCategory;
		void ViborActCategory(void);
		void EndViborActCategory(void);

public:		// User declarations
		__fastcall TFormaElementaSprUser(TComponent* Owner);
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
		IDMSprUser * DM;


		void UpdateForm(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprUser *FormaElementaSprUser;
//---------------------------------------------------------------------------
#endif
