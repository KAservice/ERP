//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprDepartmentH
#define UFormaSpiskaSprDepartmentH
//---------------------------------------------------------------------------
#include "IDMInterfMainMenuPar.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IkasDMSpr.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>

#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include "cxImageComboBox.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaSprDepartment : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonDelete;
	TLabel *LabelHeader;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxGridDBColumn *cxGrid1DBTableView1ID_SDEPARTMENT;
	TcxGridDBColumn *cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SDEPARTMENT;
	TToolButton *ToolButtonEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ToolButtonEditClick(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����



		void OpenFormNewElement(void);
		void OpenFormElement(void);
		void DeleteElement(void);



public:		// User declarations
		__fastcall TFormaSpiskaSprDepartment(TComponent* Owner);

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
	   // IDMInterfMainMenuPar* DM;
	   //	__int64 IdOwner;
	   //	UnicodeString TextHeader;
	  //	bool Vibor;                        //����� ������� ��� ������
	   //	int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
	   // void UpdateForm(void);
	   //	void DeleteElement();




       //IkasForm
	void UpdateForm(void);
	bool Vibor;
	int NumberProcVibor;
	   //IkasFormSpr

	__int64 IdGroupEl1;
	UnicodeString NameGroupEl1;

	__int64 IdGroupEl2;
	UnicodeString NameGroupEl2;

	__int64 IdOwner;
	UnicodeString NameOwner;

	__int64 IdGrp;
	UnicodeString NameGrp;

	__int64 IdEl;
	UnicodeString NameEl;

	bool All;


	IkasDMSpr * DM;





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprDepartment *FormaSpiskaSprDepartment;
//---------------------------------------------------------------------------
#endif
