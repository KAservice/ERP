//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDiscountAutoH
#define UFormaElementaSprDiscountAutoH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprVidNom.h"
#include "IDMSprDiscountAuto.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprGrpNom.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTimeEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "UDM.h"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprDiscountAuto : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBCheckBox *ActcxDBCheckBox;
	TcxDBDateEdit *NachcxDBDateEdit;
	TcxDBDateEdit *ConcxDBDateEdit;
	TcxDBCalcEdit *PrSkcxDBCalcEdit;
	TcxDBCalcEdit *SummacxDBCalcEdit;
	TcxDBSpinEdit *DaycxDBSpinEdit;
	TcxDBTimeEdit *TimeNachcxDBTimeEdit;
	TcxDBTimeEdit *TimeConcxDBTimeEdit;
	TcxDBButtonEdit *NameVidNomcxDBButtonEdit;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TLabel *Label12;
	TcxDBRadioGroup *NumSkidkicxDBRadioGroup;
	TAction *ActionClose;
	TAction *ActionOK;
	TLabel *Label13;
	TLabel *Label14;
	TcxDBButtonEdit *NameGrpNomcxDBButtonEdit;
	TcxDBImageComboBox *TypeActioncxDBImageComboBox;
	TcxDBTextEdit *MessagecxDBTextEdit;
	TLabel *Label15;
	TLabel *Label16;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameVidNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameGrpNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		//����� ���� ������������
		IFormaSpiskaSprVidNom * FormaSpiskaSprVidNom;
		void ViborVidNom(void);
		void __fastcall EndViborVidNom(void);

		//����� ������
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);

		enum  {ER_NoRekv,ER_Sklad,ER_VidNom,ER_GrpNom, ER_NO} EditRekvisit;


		IFormaSpiskaSprGrpNom * FormaSpiskaSprGrpNom;
		void OpenFormSpiskaSprGrpNom(void);
		void EndViborGrpNom(void);


public:		// User declarations
		__fastcall TFormaElementaSprDiscountAuto(TComponent* Owner);

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������

		IDMSprDiscountAuto * DM;

		void UpdateForm(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprDiscountAuto *FormaElementaSprDiscountAuto;
//---------------------------------------------------------------------------
#endif
