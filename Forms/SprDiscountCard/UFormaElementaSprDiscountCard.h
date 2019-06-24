//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDiscountCardH
#define UFormaElementaSprDiscountCardH
//---------------------------------------------------------------------------
#include "IDMSprDiscountCard.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprVidDiscountCard.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp> 
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprDiscountCard : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label9;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBCalcEdit *ProcentcxDBCalcEdit;
	TcxDBCheckBox *ActcxDBCheckBox1;
	TcxDBDateEdit *NachcxDBDateEdit;
	TcxDBDateEdit *ConcxDBDateEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TcxDBTextEdit *SHCodecxDBTextEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label5;
	TcxDBButtonEdit *NameVidcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBCheckBox *FlPlatCardcxDBCheckBox;
	TcxDBCheckBox *FlDiscontcxDBCheckBox;
	TcxDBCheckBox *FlCreditcxDBCheckBox;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TLabel *Label8;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxDBImageComboBox *TypeCardcxDBImageComboBox;
	TcxDBCheckBox *SinglecxDBCheckBox;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameVidcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActcxDBCheckBox1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypecxDBComboBoxPropertiesChange(TObject *Sender);
	void __fastcall SHCodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ProcentcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NachcxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ConcxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		IFormaSpiskaSprVidDiscountCard * FormaSpiskaSprVidDiscountCard;
		void ViborVidDiscountCard(void);
		void __fastcall EndViborVidDiscountCard(void);

		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;
		void ViborDogovor(void);
		void __fastcall EndViborDogovor(void);
public:		// User declarations
		__fastcall TFormaElementaSprDiscountCard(TComponent* Owner);

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
		IDMSprDiscountCard * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprDiscountCard *FormaElementaSprDiscountCard;
//---------------------------------------------------------------------------
#endif
