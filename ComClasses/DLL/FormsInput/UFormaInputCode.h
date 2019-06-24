//---------------------------------------------------------------------------

#ifndef UFormaInputCodeH
#define UFormaInputCodeH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaInputCode : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *NameSprLabel;
        TLabel *Label2;
	TcxTextEdit *CodeEdit;
	TcxCalcEdit *KolEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CodeEditKeyPress(TObject *Sender, char &Key);
	void __fastcall KolEditKeyPress(TObject *Sender, char &Key);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
        __fastcall TFormaInputCode(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

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
		bool Vibor;
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		int Code;
        float Kol;
        



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaInputCode *FormaInputCode;
//---------------------------------------------------------------------------
#endif
