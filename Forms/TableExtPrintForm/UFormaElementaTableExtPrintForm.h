//---------------------------------------------------------------------------

#ifndef UFormaElementaTableExtPrintFormH
#define UFormaElementaTableExtPrintFormH
//---------------------------------------------------------------------------

#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprProgramModule.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
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
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxLabel.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxCheckGroup.hpp"
#include "cxDBCheckGroup.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaTableExtPrintForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TOpenDialog *OpenDialog1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBImageComboBox *TypeModulecxDBImageComboBox;
	TcxLabel *cxLabel1;
	TcxDBImageComboBox *ObjectcxDBImageComboBox;
	TcxButton *cxButtonFileInBlob;
	TcxDBRadioGroup *cxDBRadioGroupResidence;
	TcxDBButtonEdit *FileNamecxDBButtonEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxButton *cxButtonBlobInFile;
	TSaveDialog *SaveDialog1;
	TcxDBButtonEdit *NameModulecxDBButtonEdit;
	TLabel *Label2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FileNamecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonFileInBlobClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall cxButtonBlobInFileClick(TObject *Sender);
	void __fastcall NameModulecxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprProgramModule * SpisokProgramModule;
		void ViborProgramModule(void);
		void EndViborProgramModule(void);

		enum {ER_NoRekv,ER_ProgramModule, No} EditRekvisit;
public:		// User declarations
		__fastcall TFormaElementaTableExtPrintForm(TComponent* Owner);

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
        IDMTableExtPrintForm * DM;


        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaTableExtPrintForm *FormaElementaTableExtPrintForm;
//---------------------------------------------------------------------------
#endif
