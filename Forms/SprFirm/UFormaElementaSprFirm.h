//---------------------------------------------------------------------------

#ifndef UFormaElementaSprFirmH
#define UFormaElementaSprFirmH
//---------------------------------------------------------------------------

#include "IDMSprFirm.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include <ExtCtrls.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprFirm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
	TActionList *ActionList;
	TcxButton *cxButtonBankSch;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxDBTextEdit *TelcxDBTextEdit;
	TcxDBTextEdit *OKPOcxDBTextEdit;
	TcxDBTextEdit *OKDPcxDBTextEdit;
	TcxDBTextEdit *NumDocRegcxDBTextEdit;
	TcxDBTextEdit *DateDocRegcxDBTextEdit;
	TcxDBTextEdit *KPPcxDBTextEdit;
	TcxDBTextEdit *INNcxDBTextEdit;
	TcxDBTextEdit *KassircxDBTextEdit;
	TcxDBTextEdit *BuhcxDBTextEdit;
	TcxDBTextEdit *DircxDBTextEdit;
	TcxDBTextEdit *PAdrcxDBTextEdit;
	TcxDBTextEdit *UAdrcxDBTextEdit;
	TcxDBTextEdit *FNamecxDBTextEdit;
	TcxDBTextEdit *NamefirmcxDBTextEdit;
	TcxComboBox *TypeComboBox;
	TcxDBLabel *IdFirmcxDBLabel;
	TcxLabel *cxLabel1;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *KrNamecxDBTextEdit;
	TLabel *Label17;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TLabel *Label3;
	TcxDBTextEdit *PrefiksNumDoccxDBTextEdit;
	TLabel *Label5;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonBankSchClick(TObject *Sender);
	void __fastcall TypeComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NamefirmcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall UAdrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PAdrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DircxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall BuhcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KassircxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall INNcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KPPcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumDocRegcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DateDocRegcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OKPOcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OKDPcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TelcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		bool flObrabatChangeType;
public:		// User declarations
		__fastcall TFormaElementaSprFirm(TComponent* Owner);

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

       IDMSprFirm *DM;
       __int64 IdFirm;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
	   void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprFirm *FormaElementaSprFirm;
//---------------------------------------------------------------------------
#endif
