//---------------------------------------------------------------------------

#ifndef UFormaElementaSprCodeTelH
#define UFormaElementaSprCodeTelH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMSprCodeTel.h"
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprCodeTel : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label11;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameComcxDBButtonEdit;
	TcxDBButtonEdit *NameNomcxDBButtonEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *CodeOpercxDBTextEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBCalcEdit *ProcentComissioncxDBCalcEdit;
	TLabel *Label5;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameComcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

        IFormaSpiskaSprNom * FormaSpiskaSprNom;

		enum {NO,ViborNom, ViborNomCommission} ViborRekv;

		void __fastcall EndVibor(TObject *Sender);
		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprNomCommission(void);
public:		// User declarations
		__fastcall TFormaElementaSprCodeTel(TComponent* Owner);

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������
		IDMSprCodeTel * DM;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprCodeTel *FormaElementaSprCodeTel;
//---------------------------------------------------------------------------
#endif
