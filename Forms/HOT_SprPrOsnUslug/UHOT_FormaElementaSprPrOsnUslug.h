//---------------------------------------------------------------------------

#ifndef UHOT_FormaElementaSprPrOsnUslugH
#define UHOT_FormaElementaSprPrOsnUslugH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IFormaSpiskaSprNom.h"
#include "IHOT_DMSprPrOsnUslug.h"
#include "IFormaSpiskaSprTypePrice.h"
//-----------------------------------------------------------------------------
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
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaElementaSprPrOsnUslug : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel1;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TPanel *Panel2;
	TcxDBButtonEdit *NameCatcxDBButtonEdit;
	TLabel *Label3;
	TLabel *Label2;
	TcxDBButtonEdit *NameTypePosNomcxDBButtonEdit;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TcxDBButtonEdit *NameNomPrcxDBButtonEdit;
	TcxDBButtonEdit *NameNomBrcxDBButtonEdit;
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TcxButton *cxButtonSave;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameCatcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTypePosNomcxDBButtonEditPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall NameNomPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomBrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		//����� ���������
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//����� ���� ���������
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);

		//����� ������������ ����������
		IFormaSpiskaSprNom * FormaSpiskaSprNomPr;
		void ViborNomPr(void);
		void __fastcall EndViborNomPr(void);

		//����� ������������ ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNomBr;
		void ViborNomBr(void);
		void __fastcall EndViborNomBr(void);

		enum {ER_NoRekv,ER_Cat,ER_TypePosel,ER_NomProg,ER_NomBron,ER_No} EditRekvisit;

		__int64 IdNom;
public:		// User declarations
		__fastcall THOT_FormaElementaSprPrOsnUslug(TComponent* Owner);

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
		IHOT_DMSprPrOsnUslug * DM;
		void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����






};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaElementaSprPrOsnUslug *HOT_FormaElementaSprPrOsnUslug;
//---------------------------------------------------------------------------
#endif
