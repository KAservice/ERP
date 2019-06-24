//---------------------------------------------------------------------------

#ifndef UFormaElementaSprOborudH
#define UFormaElementaSprOborudH
//---------------------------------------------------------------------------

#include "UDM.h"
#include "IDMSprOborud.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxButtons.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "cxPC.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprOborud : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBMemo *StrParcxDBMemo;
	TcxDBCheckBox *OnStartcxDBCheckBox;
	TcxComboBox *TypeOborudComboBox;
	TcxComboBox *ModelComboBox;
	TLabel *Label5;
	TLabel *Label6;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *CompNamecxDBTextEdit;
	TcxDBComboBox *ComPortcxDBComboBox;
	TcxDBComboBox *BaudRatecxDBComboBox;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label7;
	TLabel *Label3;
	TLabel *Label4;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBComboBox *ModulcxDBComboBox;
	TcxDBComboBox *cxDBComboBoxPROGID_SOBORUD;
	TLabel *Label8;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall TypeOborudComboBox_Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall TypeOborudComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CompNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ModulcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnStartcxDBCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		void UpdateModel(void);
        void UpdateModul(void);
		bool ObrabatChangeTypeOborud;
public:		// User declarations
		__fastcall TFormaElementaSprOborud(TComponent* Owner);
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
		IDMSprOborud * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprOborud *FormaElementaSprOborud;
//---------------------------------------------------------------------------
#endif
