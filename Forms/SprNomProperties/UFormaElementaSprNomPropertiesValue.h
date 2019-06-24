//---------------------------------------------------------------------------

#ifndef UFormaElementaSprNomPropertiesValueH
#define UFormaElementaSprNomPropertiesValueH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprProperties.h"
#include "IFormaSpiskaSprPropertiesValuesList.h"
#include "IDMSprNomPropertiesValue.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBRichEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprNomPropertiesValue : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NamePropValueListcxDBButtonEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBMemo *ValueTextcxDBMemo;
	TcxDBButtonEdit *NamePropcxDBButtonEdit;
	TLabel *Label1;
	TLabel *Label2;
	TcxDBSpinEdit *IndexcxDBSpinEdit;
	TcxDBCheckBox *Add1cxDBCheckBox;
	TcxDBCheckBox *Add2cxDBCheckBox;
	TcxDBCheckBox *Add3cxDBCheckBox;
	TcxDBCheckBox *Add4cxDBCheckBox;
	TcxDBCheckBox *Add5cxDBCheckBox;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NamePropcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NamePropValueListcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	IFormaSpiskaSprProperties * FormaSpiskaSprProperties;
	IFormaSpiskaSprPropertiesValuesList *FormaSpiskaSprPropertiesValuesList;

	void OpenFormaSpiskaSprProperties(void);
	void  EndViborProperties(void);
	void OpenFormaSpiskaSprPropertiesValuesList(void);
	void  EndViborPropertiesValue(void);


	enum  {ER_NoRekv, ER_ViborProperties, ER_ViborPropertiesValue} ER_Rekvisit;


public:		// User declarations
		__fastcall TFormaElementaSprNomPropertiesValue(TComponent* Owner);

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

         void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//������� ���������
		IDMSprNomPropertiesValue * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprNomPropertiesValue *FormaElementaSprNomPropertiesValue;
//---------------------------------------------------------------------------
#endif
