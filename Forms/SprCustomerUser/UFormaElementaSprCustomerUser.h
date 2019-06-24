//---------------------------------------------------------------------------

#ifndef UFormaElementaSprCustomerUserH
#define UFormaElementaSprCustomerUserH
//---------------------------------------------------------------------------


#include "UDM.h"
#include "IDMSprCustomerUser.h"
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
#include "cxPC.hpp"
#include "cxButtonEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxMemo.hpp"
#include "cxImageComboBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxDBLabel.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxSpinEdit.hpp"
#include "cxCurrencyEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprCustomerUser : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxLabel *cxLabel1;
	TLabel *NameGrpLabel;
	TcxDBTextEdit *PasswordcxDBTextEdit;
	TcxDBTextEdit *LogincxDBTextEdit;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxButton *cxButton1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall KeyWordscxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton1Click(TObject *Sender);








private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����





		enum  {ER_NoRekv, ER_EditKlient, ER_EditUser} ER_Rekvisit;



public:		// User declarations
		__fastcall TFormaElementaSprCustomerUser(TComponent* Owner);

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
		IDMSprCustomerUser * DM;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		void UpdateForm(void);

		__int64 IdGrp;
		UnicodeString NameGrp;
		__int64 IdAccount;
		UnicodeString NameAccount;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprCustomerUser *FormaElementaSprCustomerUser;
//---------------------------------------------------------------------------
#endif
