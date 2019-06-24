//---------------------------------------------------------------------------

#ifndef UART_FormaElementaSprNaborInfBlockH
#define UART_FormaElementaSprNaborInfBlockH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IART_DMSprNaborInfBlock.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtonEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
//---------------------------------------------------------------------------
class TART_FormaElementaSprNaborInfBlock : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label1;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		enum {NO, EditKomplModel, VR_Nom, VR_ModelDetal, VR_NeisprModel, VR_InfBlock} ViborRekv;


public:		// User declarations
		__fastcall TART_FormaElementaSprNaborInfBlock(TComponent* Owner);

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

		IART_DMSprNaborInfBlock * DM;


		void UpdateForm(void) ;
		bool SaveElement;
};
//---------------------------------------------------------------------------
extern PACKAGE TART_FormaElementaSprNaborInfBlock *ART_FormaElementaSprNaborInfBlock;
//---------------------------------------------------------------------------
#endif
