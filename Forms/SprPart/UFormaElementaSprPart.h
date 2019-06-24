//---------------------------------------------------------------------------

#ifndef UFormaElementaSprPartH
#define UFormaElementaSprPartH
//---------------------------------------------------------------------------

#include "IDMSprPart.h"
#include "UDM.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxCalendar.hpp"
#include "cxButtonEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprPart : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TDBText *NameNom;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *CodePart;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *GTDcxDBTextEdit;
	TcxDBTextEdit *SertcxDBTextEdit;
	TcxDBCalcEdit *PricecxDBCalcEdit;
	TcxGroupBox *cxGroupBox1;
	TDBText *FirmPart;
	TLabel *Label7;
	TLabel *Label8;
	TDBText *DocPart;
	TLabel *Label9;
	TcxDBDateEdit *SrokGodncxDBDateEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall GTDcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SertcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SrokGodncxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PricecxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		//�������������� ���������� � �������������
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborSupplier(void);
		void __fastcall EndViborSupplier(void);
public:		// User declarations
		__fastcall TFormaElementaSprPart(TComponent* Owner);

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
		IDMSprPart * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprPart *FormaElementaSprPart;
//---------------------------------------------------------------------------
#endif
