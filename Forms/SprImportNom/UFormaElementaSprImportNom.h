//---------------------------------------------------------------------------

#ifndef UFormaElementaSprImportNomH
#define UFormaElementaSprImportNomH
//---------------------------------------------------------------------------
#include "IDMSprImportNom.h"
#include "UDM.h"
#include "IFormaSpiskaSprKlient.h"
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
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprImportNom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *NameEdcxDBTextEdit;
	TcxDBTextEdit *ArtikulcxDBTextEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TLabel *Label6;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall CodecxDBTextEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NameEdcxDBTextEditKeyPress(TObject *Sender, char &Key);
	void __fastcall ArtikulcxDBTextEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		IFormaSpiskaSprKlient *FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
		__fastcall TFormaElementaSprImportNom(TComponent* Owner);

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
		IDMSprImportNom * DM;

	    void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprImportNom *FormaElementaSprImportNom;
//---------------------------------------------------------------------------
#endif
