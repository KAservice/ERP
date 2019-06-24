//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprModelDetalH
#define UREM_FormaElementaSprModelDetalH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprModelDetal.h"
#include "UDM.h"
#include "IFormaSpiskaSprNom.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
#include "IFormaSpiskaSprProducerNom.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtonEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprModelDetal : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *KolcxDBTextEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBTextEdit *PartNumbercxDBTextEdit;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxDBButtonEdit *NameNomcxDBButtonEdit;
	TcxDBButtonEdit *NameProducerNomcxDBButtonEdit;
	TcxDBLabel *ArtikulNomcxDBLabel;
	TcxDBLabel *CodeNomcxDBLabel;
	TcxDBLabel *CodePrNomcxDBLabel;
	TcxDBLabel *ArtikulPrNomcxDBLabel;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TcxDBButtonEdit *NameTypUslacxDBButtonEdit;
	TLabel *Label7;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameTypUslacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProducerNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		enum {NO, VR_ViborNom, VR_ViborProducerNom, VR_ViborNomProducer,VR_ViborTypUsla} ViborRekv;


		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//����� �������� ����
		IREM_FormaSpiskaSprTypUslov * FormaSpiskaSprTypUslov;
		void ViborTypUsla(void);
		void __fastcall EndViborTypUsla(void);

		//����� ������������   �������������
		IFormaSpiskaSprProducerNom * FormaSpiskaSprProducerNom;
		void ViborProducerNom(void);
		void __fastcall EndViborProducerNom(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprModelDetal(TComponent* Owner);

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
        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IREM_DMSprModelDetal * DM;



		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprModelDetal *REM_FormaElementaSprModelDetal;
//---------------------------------------------------------------------------
#endif
