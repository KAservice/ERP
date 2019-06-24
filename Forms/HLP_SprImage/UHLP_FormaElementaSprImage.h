//---------------------------------------------------------------------------

#ifndef UHLP_FormaElementaSprImageH
#define UHLP_FormaElementaSprImageH
//---------------------------------------------------------------------------
#include "IHLP_DMSprImage.h"
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
#include "cxDBRichEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxImage.hpp"
#include "cxSpinEdit.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THLP_FormaElementaSprImage : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBImage *ImagecxDBImage;
	TPanel *Panel1;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TPanel *Panel2;
	TLabel *NameGrpLabel;
	TLabel *Label1;
	TcxDBTextEdit *NamecxDBTextEdit;
	TLabel *Label2;
	TcxDBTextEdit *GuidcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	enum  {ER_NoRekv, ER_ViborVidImage} ER_Rekvisit;


public:		// User declarations
		__fastcall THLP_FormaElementaSprImage(TComponent* Owner);

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
		IHLP_DMSprImage * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

	   void UpdateForm(void);

		__int64 IdGrpPage;
		UnicodeString NameGrp;
};
//---------------------------------------------------------------------------
extern PACKAGE THLP_FormaElementaSprImage *HLP_FormaElementaSprImage;
//---------------------------------------------------------------------------
#endif
