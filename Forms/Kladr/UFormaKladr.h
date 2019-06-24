//---------------------------------------------------------------------------

#ifndef UFormaKladrH
#define UFormaKladrH
//---------------------------------------------------------------------------
#include "UFormaKladrViborRegion.h"
#include "UFormaKladrViborStreet.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaKladr : public TForm
{
__published:	// IDE-managed Components
	TcxButtonEdit *RegioncxButtonEdit;
	TcxButtonEdit *RayoncxButtonEdit;
	TcxButtonEdit *GorodcxButtonEdit;
	TcxButtonEdit *NasPunktcxButtonEdit;
	TcxButtonEdit *StreetcxButtonEdit;
	TcxTextEdit *DomcxTextEdit;
	TcxTextEdit *KorpuscxTextEdit;
	TcxTextEdit *KvartcxTextEdit;
	TcxTextEdit *IndexcxTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TActionList *ActionList;
	TAction *ActionClose;
	TAction *ActionOK;
	void __fastcall RegioncxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RayoncxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall GorodcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NasPunktcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall StreetcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IkanCallBack * InterfaceCallBackImpl;//��������� ���������� �������� ������
											 //��� �������� � ����� ������

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	TFormaKladrViborRegion *FormaKladrViborRegion;
	void ViborRegion(void);
	void __fastcall EndViborRegion(TObject *Sender);

	void ViborRayon(void);
	void __fastcall EndViborRayon(TObject *Sender);

	void ViborGorod(void);
	void __fastcall EndViborGorod(TObject *Sender);

	void ViborNasPunkt(void);
	void __fastcall EndViborNasPunkt(TObject *Sender);

	TFormaKladrViborStreet *FormaKladrViborStreet;
	void ViborStreet(void);
	void __fastcall EndViborStreet(TObject *Sender);
	bool NoKladr;
public:		// User declarations
	__fastcall TFormaKladr(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

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
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//������� ���������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		IkanCallBack * InterfaceCallBack;  //���� ���� ������� ������� ������

	AnsiString KladrPatch;
	AnsiString NameRegion;
	AnsiString NameRayon;
	AnsiString NameGorod;
	AnsiString NameNasPunkt;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaKladr *FormaKladr;
//---------------------------------------------------------------------------
#endif
