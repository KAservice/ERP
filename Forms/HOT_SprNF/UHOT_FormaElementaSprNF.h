//---------------------------------------------------------------------------

#ifndef UHOT_FormaElementaSprNFH
#define UHOT_FormaElementaSprNFH
//---------------------------------------------------------------------------
#include "IHOT_DMSprNF.h"
#include "UDM.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprObject.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
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
#include "cxButtonEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class THOT_FormaElementaSprNF : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameCatNomcxDBButtonEdit;
	TcxDBButtonEdit *NameObjectcxDBButtonEdit;
	TLabel *Label3;
	TcxDBCalcEdit *KolMestcxDBCalcEdit;
	TLabel *Label4;
	TcxDBDateEdit *PosIncxDBDateEdit;
	TcxDBDateEdit *PosOutcxDBDateEdit;
	TLabel *Label5;
	TLabel *Label6;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameObjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		//����� ���������
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//����� �������
		IHOT_FormaSpiskaSprObject * HOT_FormaSpiskaSprObject;
		void ViborObject(void);
		void __fastcall EndViborObject(void);

		enum {ER_NoRekv,ER_Cat,ER_Object, ER_no} EditRkvisit;
public:		// User declarations
		__fastcall THOT_FormaElementaSprNF(TComponent* Owner);

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
		IHOT_DMSprNF * DM;
		void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����



};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaElementaSprNF *HOT_FormaElementaSprNF;
//---------------------------------------------------------------------------
#endif
