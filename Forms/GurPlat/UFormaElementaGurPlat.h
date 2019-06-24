//---------------------------------------------------------------------------

#ifndef UFormaElementaGurPlatH
#define UFormaElementaGurPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMGurPlat.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprCodeTel.h"

//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBLabel.hpp"
//---------------------------------------------------------------------------
class TFormaElementaGurPlat : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label8;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCheckBox *OutcxDBCheckBox;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameUsercxDBButtonEdit;
	TcxDBCalcEdit *SummKlientcxDBCalcEdit;
	TcxDBCalcEdit *ProcentcxDBCalcEdit;
	TcxDBCalcEdit *SumcxDBCalcEdit;
	TcxDBTextEdit *NumTelcxDBTextEdit;
	TcxDBTextEdit *CodeTelcxDBTextEdit;
	TcxDBTextEdit *NumKvcxDBTextEdit;
	TcxDBTextEdit *CodeOpercxDBTextEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxLabel *cxLabel1;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameCodeTelcxDBButtonEdit;
	TLabel *Label9;
	TcxDBLabel *CodeOperatorcxDBLabel;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameCodeTelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		IFormaSpiskaSprKlient * SpisokKlient;
		 void OpenFormSpiskaSprKlient(void);

		enum  {ER_NoRekv,ViborKlient, ViborCodeTel, NO} EditRekvisit;


		IFormaSpiskaSprCodeTel * SpisokCodeTel;
		 void OpenFormSpiskaSprCodeTel(void);

public:		// User declarations
		__fastcall TFormaElementaGurPlat(TComponent* Owner);

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



        void UpdateForm(void);
        IDMGurPlat * DM;


		bool Prosmotr;    //������ ��������
		bool Vibor;       //��� ������
        int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaGurPlat *FormaElementaGurPlat;
//---------------------------------------------------------------------------
#endif
