//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDogovorH
#define UFormaElementaSprDogovorH
//---------------------------------------------------------------------------

#include "IDMSprDogovor.h"
#include "IFormaSpiskaSprGrafikPlat.h"
#include "IDMSprTypePrice.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
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
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprDogovor : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonGrafikPlat;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCalcEdit *MaxSumCreditcxDBCalcEdit;
	TcxDBTextEdit *SrokcxDBTextEdit;
	TcxDBDateEdit *DocxDBDateEdit;
	TcxComboBox *TypePriceComboBox;
	TcxComboBox *WayPayComboBox;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBDateEdit *DatecxDBDateEdit;
	TcxDBTextEdit *NumcxDBTextEdit;
	TcxDBTextEdit *IDcxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonGrafikPlatClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall WayPayComboBoxPropertiesChange(TObject *Sender);
	void __fastcall DatecxDBDateEditExit(TObject *Sender);
	void __fastcall NumcxDBTextEditExit(TObject *Sender);
	void __fastcall NumcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DatecxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DocxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SrokcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall MaxSumCreditcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprGrafikPlat * FormaSpiskaSprGrafikPlat;

		IDMSprTypePrice *DMSprTypePrice;

		bool flObrabatChangeTypePrice;
		bool flObrabatSpPogCredita;
public:		// User declarations
		__fastcall TFormaElementaSprDogovor(TComponent* Owner);

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
		IDMSprDogovor * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����



        void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprDogovor *FormaElementaSprDogovor;
//---------------------------------------------------------------------------
#endif
