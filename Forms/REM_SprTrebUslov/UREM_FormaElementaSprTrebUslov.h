//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprTrebUslovH
#define UREM_FormaElementaSprTrebUslovH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprTrebUslov.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
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
class TREM_FormaElementaSprTrebUslov : public TForm
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
	TcxDBButtonEdit *NameTypUslovcxDBButtonEdit;
	TLabel *Label3;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		enum {NO, VR_ViborTypUslov, VR_ViborNomProducer} ViborRekv;


		//����� ������������
		IREM_FormaSpiskaSprTypUslov * FormaSpiskaSprTypUslov;
		void ViborTypUslov(void);
		void __fastcall EndViborTypUslov(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprTrebUslov(TComponent* Owner);

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

		IREM_DMSprTrebUslov * DM;



		void UpdateForm(void);
        UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprTrebUslov *REM_FormaElementaSprTrebUslov;
//---------------------------------------------------------------------------
#endif
