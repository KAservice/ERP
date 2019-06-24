//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprNeisprModelH
#define UREM_FormaElementaSprNeisprModelH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprNeisprModel.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprNeispr.h"
#include "IREM_FormaSpiskaSprDefectModelNeispr.h"
#include "IREM_FormaSpiskaSprModel.h"
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
class TREM_FormaElementaSprNeisprModel : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameNeisprcxDBButtonEdit;
	TLabel *Label3;
	TcxButton *cxButtonDefect;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TLabel *Label2;
	TcxDBButtonEdit *NameModelNeisprcxDBButtonEdit;
	TLabel *Label4;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonDefectClick(TObject *Sender);
	void __fastcall NameModelNeisprcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		enum {NO, VR_ViborNeispr, VR_ViborDefectModelNeispr,VR_Model} ViborRekv;


		//����� ������������
		IREM_FormaSpiskaSprNeispr * FormaSpiskaSprNeispr;
		void ViborNeispr(void);
		void __fastcall EndViborNeispr(void);

		//����� ������������
		IREM_FormaSpiskaSprDefectModelNeispr * FormaSpiskaSprDefectModelNeispr;
		void ViborDefectModelNeispr(void);
		void __fastcall EndViborDefectModelNeispr(void);


				//����� ������
		IREM_FormaSpiskaSprModel * FormaSpiskaSprModel;
		void ViborModel(void);
		void __fastcall EndViborModel(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprNeisprModel(TComponent* Owner);

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

		IREM_DMSprNeisprModel * DM;



		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprNeisprModel *REM_FormaElementaSprNeisprModel;
//---------------------------------------------------------------------------
#endif
