//---------------------------------------------------------------------------

#ifndef UFormaDialogaH
#define UFormaDialogaH
//---------------------------------------------------------------------------

#include "UFormaReport.h"
#include "IDMFibConnection.h"
//--------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookupEdit.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDialoga : public TForm
{
__published:	// IDE-managed Components
	TpFIBTransaction *pFIBTransaction1;
	TLabel *Label1;
	TcxButton *cxButtonRun;
	TcxButton *cxButtonClose;
	TcxDateEdit *PosNachcxDateEdit;
	TcxDateEdit *PosConcxDateEdit;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TcxLookupComboBox *cxLookupComboBox1;
	TpFIBDataSet *SpisokGrpNom;
	TDataSource *DataSourceGrpNom;
	TFIBLargeIntField *SpisokGrpNomIDGN;
	TFIBWideStringField *SpisokGrpNomNAMEGN;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonRunClick(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		typedef void (*FOnCloseFormType)(void);
	FOnCloseFormType FOnCloseForm;

	void UpdateForm(void);


	TFormaReport * FormaReport;
	void __fastcall EventCloseFormReport(TObject *Sender);

public:		// User declarations
	__fastcall TFormaDialoga(TComponent* Owner);





		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

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


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialoga *FormaDialoga;
//---------------------------------------------------------------------------
#endif
