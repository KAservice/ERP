//---------------------------------------------------------------------------

#ifndef UFormaElementaSprProducerEdH
#define UFormaElementaSprProducerEdH
//---------------------------------------------------------------------------
#include "IDMSprProducerEd.h"
#include "UDM.h"
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
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprProducerEd : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *NameEdcxDBTextEdit;
	TcxDBCalcEdit *KFEdcxDBCalcEdit;
	TcxDBTextEdit *SHcxDBTextEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TLabel *Label6;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameEdcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KFEdcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SHcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		bool flObrabatChangeTypeSH;
	   bool flObrabatChangeNeIsp;

	   bool SaveElement;


public:		// User declarations
		__fastcall TFormaElementaSprProducerEd(TComponent* Owner);

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

         void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//������� ���������
		IDMSprProducerEd * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprProducerEd *FormaElementaSprProducerEd;
//---------------------------------------------------------------------------
#endif
