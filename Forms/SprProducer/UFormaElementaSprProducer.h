//---------------------------------------------------------------------------

#ifndef UFormaElementaSprProducerH
#define UFormaElementaSprProducerH
//---------------------------------------------------------------------------
#include "IDMSprProducer.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprInetCatalog.h"
//---------------------------------------------------------------------------
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
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprProducer : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TDBText *IdDBText;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *NamecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *PostZipcxDBButtonEdit;
	TLabel *Label3;
	TLabel *Label4;
	TcxDBDateEdit *PosZagrNomcxDBDateEdit;
	TLabel *Label5;
	TcxDBButtonEdit *UslNameInetCatalogcxDBButtonEdit;
	TcxDBButtonEdit *UslNameGrpInetcatalogcxDBButtonEdit;
	TcxDBImageComboBox *TypePoiskcxDBImageComboBox;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall PostZipcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall UslNameInetCatalogcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

				//����� �������
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		void ViborPostZIP(void);
		void __fastcall EndViborPostZIP(void);


				enum {ER_NoRekv,ER_No,ER_Klient,
						ER_Post_ZIP, ER_ViborInetCatalog} EDitRekvisit;

						IFormaSpiskaSprInetCatalog *SpisokInetCatalog;
						void OpenFormSpiskaSprInetCatalog();

public:		// User declarations
		__fastcall TFormaElementaSprProducer(TComponent* Owner);

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
        IDMSprProducer * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����




};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprProducer *FormaElementaSprProducer;
//---------------------------------------------------------------------------
#endif
