//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprSostH
#define UREM_FormaElementaSprSostH
//---------------------------------------------------------------------------
#include "IREM_DMSprSost.h"
#include "UDM.h"
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprSost : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBLabel *IdcxDBLabel;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonOKClick(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


public:		// User declarations
		__fastcall TREM_FormaElementaSprSost(TComponent* Owner);

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
        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IREM_DMSprSost * DM;
        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprSost *REM_FormaElementaSprSost;
//---------------------------------------------------------------------------
#endif
