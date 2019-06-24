//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprHardwareIspH
#define UREM_FormaElementaSprHardwareIspH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprHardwareIsp.h"
#include "UDM.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
#include "IREM_FormaGurZ.h"
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
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMemo.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprHardwareIsp : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TLabel *Label5;
	TcxDBButtonEdit *NameTypUslacxDBButtonEdit;
	TcxDBButtonEdit *ZayavkacxDBButtonEdit;
	TcxDBLabel *ModelZcxDBLabel;
	TcxDBLabel *PosZcxDBLabel;
	TcxDBLabel *PrefikscxDBLabel;
	TcxDBLabel *NumZcxDBLabel;
	TcxDBLabel *SerNumcxDBLabel;
	TcxLabel *cxLabel20;
	TLabel *Label1;
	TcxDBCheckBox *OtchitanocxDBCheckBox;
	TcxDBCheckBox *RealnoIspolsovanocxDBCheckBox;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxDBMemo *DescrcxDBMemo;
	TcxDBCalcEdit *KolcxDBCalcEdit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionSaveElement;
	TAction *ActionCloseElement;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameTypUslacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseElementExecute(TObject *Sender);
	void __fastcall ZayavkacxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		enum {NO, VR_ViborNom, VR_ViborProducerNom, VR_ViborNomProducer,VR_ViborTypUsla,
									ER_ViborZ} ViborRekv;



		//����� �������� ����
		IREM_FormaSpiskaSprTypUslov * FormaSpiskaSprTypUslov;
		void ViborTypUsla(void);
		void __fastcall EndViborTypUsla(void);

 		IREM_FormaGurZ * FormaGurZ;
		void ViborZ(void);
		void EndViborZ(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprHardwareIsp(TComponent* Owner);

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

		IREM_DMSprHardwareIsp * DM;



		void UpdateForm(void);
		UnicodeString TextMessage;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprHardwareIsp *REM_FormaElementaSprHardwareIsp;
//---------------------------------------------------------------------------
#endif
