//---------------------------------------------------------------------------

#ifndef UFormaSetupOtborH
#define UFormaSetupOtborH
//---------------------------------------------------------------------------

#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaSetupOtbor : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameKlientEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxImageComboBox *TypeDoccxImageComboBox;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprSklad * SpisokSklad;
		IFormaSpiskaSprKlient * SpisokKlient;
public:		// User declarations
        __fastcall TFormaSetupOtbor(TComponent* Owner);

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


		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdSklad;
		UnicodeString NameSklad;
        __int64 IdFirm;
		UnicodeString NameFirm;
		UnicodeString StringTypeDoc;
		UnicodeString NameTypeDoc;
		UnicodeString StringFullTypeDoc;

        bool OtborPoKlient ;
        bool OtborPoFirm;
        bool OtborPoSklad;
        bool OtborPoTypeDoc;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetupOtbor *FormaSetupOtbor;
//---------------------------------------------------------------------------
#endif
