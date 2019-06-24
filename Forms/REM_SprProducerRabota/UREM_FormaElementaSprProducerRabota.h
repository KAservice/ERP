//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprProducerRabotaH
#define UREM_FormaElementaSprProducerRabotaH
//---------------------------------------------------------------------------
#include "IREM_DMSprProducerRabota.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprNom.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
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
#include "cxDropDownEdit.hpp"
#include "cxImageComboBox.hpp"
#include "cxSpinEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprProducerRabota : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *NamecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBLabel *IdcxDBLabel;
	TcxDBButtonEdit *cxDBButtonEditNAMENOM;
	TLabel *Label3;
	TcxDBTextEdit *NameEngcxDBTextEdit;
	TLabel *Label4;
	TcxDBTextEdit *cxDBTextEditCODE_REM_SPRRABOTA;
	TLabel *Label5;
	TcxDBTextEdit *cxDBTextEditLEVEL_STR_REM_SPRRABOTA;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TcxDBImageComboBox *cxDBImageComboBoxTYPECLIENT_REM_SPRRABOTA;
	TcxDBImageComboBox *cxDBImageComboBoxTYPEPRODUCT_REM_SPRRABOTA;
	TcxDBSpinEdit *cxDBSpinEditLEVEL_REM_SPRRABOTA;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall cxDBButtonEditNAMENOMPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
				enum {NO,  VR_Nom} ViborRekv;

		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprProducerRabota(TComponent* Owner);
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
		IREM_DMSprProducerRabota* DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		UnicodeString NameGroupElement;
		__int64 IdGroupElement;     //������������ �������
		UnicodeString NameGroup;
		__int64 IdGrp;              //������ � ������� ��������� �������
		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprProducerRabota *REM_FormaElementaSprProducerRabota;
//---------------------------------------------------------------------------
#endif
