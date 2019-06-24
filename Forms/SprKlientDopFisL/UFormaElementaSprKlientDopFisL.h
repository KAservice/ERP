//---------------------------------------------------------------------------

#ifndef UFormaElementaSprKlientDopFisLH
#define UFormaElementaSprKlientDopFisLH
//---------------------------------------------------------------------------

#include "IDMSprKlientDopFisL.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprKlientDopFisL : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label6;
        TDBText *NameNomDBText;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBComboBox *PolcxDBComboBox;
	TLabel *Label2;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBDateEdit *DateRogcxDBDateEdit;
	TcxDBTextEdit *MestoRogcxDBTextEdit;
	TcxDBTextEdit *DolcxDBTextEdit;
	TcxDBTextEdit *MestoRabcxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall DateRogcxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall MestoRogcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DolcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall MestoRabcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		bool flObrabatChangePol;
public:		// User declarations
		__fastcall TFormaElementaSprKlientDopFisL(TComponent* Owner);

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
		IDMSprKlientDopFisL * DM;

        void UpdateForm(void);
		UnicodeString NameKlient;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprKlientDopFisL *FormaElementaSprKlientDopFisL;
//---------------------------------------------------------------------------
#endif
