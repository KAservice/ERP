//---------------------------------------------------------------------------

#ifndef UFormaElementaGurOperDiscountCardH
#define UFormaElementaGurOperDiscountCardH
//---------------------------------------------------------------------------
#include "IDMGurOperDiscountCard.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprDiscountCard.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp> 
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaGurOperDiscountCard : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label5;
	TcxDBButtonEdit *NameCardcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxDBCalcEdit *SumcxDBCalcEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameVidcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);

		IFormaSpiskaSprDiscountCard * FormaSpiskaSprDiscountCard;
		void ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		enum {ER_NoRekv,ER_Klient, ER_Sklad, ER_Card, ER_No} EditRekvisit;
public:		// User declarations
		__fastcall TFormaElementaGurOperDiscountCard(TComponent* Owner);

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
		IDMGurOperDiscountCard * DM;



        void UpdateForm(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaGurOperDiscountCard *FormaElementaGurOperDiscountCard;
//---------------------------------------------------------------------------
#endif
