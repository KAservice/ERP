//---------------------------------------------------------------------------

#ifndef UFormaElementaSprGrpNomH
#define UFormaElementaSprGrpNomH
//---------------------------------------------------------------------------
#include "IDMSprGrpNom.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprPropertiesNabor.h"
//----------------------------------------------------------------------------
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
#include "cxMaskEdit.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprGrpNom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TDBText *IdGnDBText;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonNac;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NamePropertiesNaborcxDBButtonEdit;
	TcxDBButtonEdit *NameVidImageNaborcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonNacClick(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NamePropertiesNaborcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		IFormaSpiskaSprPropertiesNabor * FormaSpiskaSprPropertiesNabor;
		void ViborPropertiesNabor(void);
		void EndViborPropertiesNabor(void);

		enum{ER_NoRekv,ER_ViborPropNabor} EditRekvisit;

public:		// User declarations
		__fastcall TFormaElementaSprGrpNom(TComponent* Owner);
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
		IDMSprGrpNom* DM;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprGrpNom *FormaElementaSprGrpNom;
//---------------------------------------------------------------------------
#endif
