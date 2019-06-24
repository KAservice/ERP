//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDepartmentH
#define UFormaElementaSprDepartmentH
//---------------------------------------------------------------------------
#include "IDMInterfMainMenuPar.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IkasDMSpr.h"

//----------------------------------------------------------------------------
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TFormaElementaSprDepartment : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
	TLabel *LabelHeader;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TAction *ActionClose;
	TAction *ActionOK;
	TPanel *Panel5;
	TcxDBTextEdit *cxDBTextEditNAME_SDEPARTMENT;
	TcxDBCalcEdit *cxDBCalcEditNUMOTDKKT_SDEPARTMENT;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
		__fastcall TFormaElementaSprDepartment(TComponent* Owner);

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
extern PACKAGE TFormaElementaSprDepartment *FormaElementaSprDepartment;
//---------------------------------------------------------------------------
#endif
