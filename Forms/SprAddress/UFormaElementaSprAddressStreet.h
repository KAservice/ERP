//---------------------------------------------------------------------------

#ifndef UFormaElementaSprAddressStreetH
#define UFormaElementaSprAddressStreetH
//---------------------------------------------------------------------------
#include "IDMSprAddressStreet.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprAddressStreet : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TDBText *DBTextID_SADR_REGION;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *cxDBTextEditNAME_SADR_STREET;
	TAction *ActionClose;
	TAction *ActionOK;
	TDBText *DBTextCODE_SADR_REGION;
	TDBText *DBTextNAME_SADR_REGION;
	TcxDBCheckBox *cxDBCheckBoxFL_GOROD_SADR_NASPUNKT;
	TDBText *DBTextNAME_SADR_RAYON;
	TcxDBTextEdit *cxDBTextEditPOSTCODE_SADR_STREET;
	TDBText *DBTextNAME_SADR_NASPUNKT;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
		__fastcall TFormaElementaSprAddressStreet(TComponent* Owner);

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
		IDMSprAddressStreet * DM;
		void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprAddressStreet *FormaElementaSprAddressStreet;
//---------------------------------------------------------------------------
#endif
