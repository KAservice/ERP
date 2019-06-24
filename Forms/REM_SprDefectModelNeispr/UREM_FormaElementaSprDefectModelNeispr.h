//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprDefectModelNeisprH
#define UREM_FormaElementaSprDefectModelNeisprH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprDefectModelNeispr.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprTypDefect.h"
#include "IREM_FormaSpiskaSprTrebRabot.h"
#include "IREM_FormaSpiskaSprTrebUslov.h"
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
class TREM_FormaElementaSprDefectModelNeispr : public TForm
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
	TcxDBButtonEdit *NameTypDefectcxDBButtonEdit;
	TLabel *Label3;
	TcxDBLabel *CodeTypDefectcxDBLabel;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxButton *cxButtonTrebUslov;
	TcxButton *cxButtonTrebRabot;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonTrebUslovClick(TObject *Sender);
	void __fastcall cxButtonTrebRabotClick(TObject *Sender);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		enum {NO, VR_ViborTypDefect, VR_ViborTrebRabot,VR_ViborTrebUslov} ViborRekv;


		//����� ������������
		IREM_FormaSpiskaSprTypDefect * FormaSpiskaSprTypDefect;
		void ViborTypDefect(void);
		void __fastcall EndViborTypDefect(void);

		//����� ��������� �����
		IREM_FormaSpiskaSprTrebUslov * FormaSpiskaSprTrebUslov;
		void ViborTrebUslov(void);
		void __fastcall EndViborTrebUslov(void);

		//����� ��������� �����
		IREM_FormaSpiskaSprTrebRabot * FormaSpiskaSprTrebRabot;
		void ViborTrebRabot(void);
		void __fastcall EndViborTrebRabot(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprDefectModelNeispr(TComponent* Owner);

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

		IREM_DMSprDefectModelNeispr * DM;

		__int64 IdModelNeispr;

		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprDefectModelNeispr *REM_FormaElementaSprDefectModelNeispr;
//---------------------------------------------------------------------------
#endif
