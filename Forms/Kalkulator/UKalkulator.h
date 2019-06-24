//---------------------------------------------------------------------------

#ifndef UKalkulatorH
#define UKalkulatorH
//---------------------------------------------------------------------------
#include "IMainInterface.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TKalkulator : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *kn1;
        TEdit *Tablo;
        TBitBtn *kn2;
        TBitBtn *kn3;
        TBitBtn *kn4;
        TBitBtn *kn9;
        TBitBtn *kn5;
        TBitBtn *kn6;
        TBitBtn *kn7;
        TBitBtn *kn8;
        TBitBtn *kn0;
        TBitBtn *knComma;
        TBitBtn *knOK;
        TBitBtn *knC;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall knOKClick(TObject *Sender);
        void __fastcall knCClick(TObject *Sender);
        void __fastcall kn1Click(TObject *Sender);
        void __fastcall kn2Click(TObject *Sender);
        void __fastcall kn3Click(TObject *Sender);
        void __fastcall kn4Click(TObject *Sender);
        void __fastcall kn5Click(TObject *Sender);
        void __fastcall kn6Click(TObject *Sender);
        void __fastcall kn7Click(TObject *Sender);
        void __fastcall kn8Click(TObject *Sender);
        void __fastcall kn9Click(TObject *Sender);
        void __fastcall kn0Click(TObject *Sender);
        void __fastcall knCommaClick(TObject *Sender);
private:	// User declarations
	int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
		__fastcall TKalkulator(TComponent* Owner);


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


        double Result;

};
//---------------------------------------------------------------------------
extern PACKAGE TKalkulator *Kalkulator;
//---------------------------------------------------------------------------
#endif
