//---------------------------------------------------------------------------

#ifndef UFormaExportDocH
#define UFormaExportDocH
//---------------------------------------------------------------------------
#include "UDMExportDoc.h"

//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaExportDoc : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TcxDateEdit *NachcxDateEdit;
	TLabel *Label4;
	TcxDateEdit *ConcxDateEdit;
	TcxButtonEdit *PatchcxButtonEdit;
	TLabel *Label6;
	TcxCheckBox *PoDatecxCheckBox;
	TSaveDialog *SaveDialog1;
	TcxButton *ExportAllDoccxButton;
	TcxButton *SprcxButton;
	TcxButton *cxButtonClose;
	TLabel *Label7;
	TcxButtonEdit *FileNamecxButtonEdit;
	TLabel *Label8;
	TOpenDialog *OpenDialog1;
	TcxButton *cxButtonImport;
	void __fastcall PatchcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ExportAllDoccxButtonClick(TObject *Sender);
	void __fastcall SprcxButtonClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations



		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


public:		// User declarations
	__fastcall TFormaExportDoc(TComponent* Owner);


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

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaExportDoc *FormaExportDoc;
//---------------------------------------------------------------------------
#endif
