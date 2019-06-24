//---------------------------------------------------------------------------

#ifndef UFormaCreateCardH
#define UFormaCreateCardH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprVidDiscountCard.h"
#include "IFormaSpiskaSprGrpKlient.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxGroupBox.hpp"
#include <Menus.hpp>
#include "cxLabel.hpp"
#include "cxImageComboBox.hpp"
#include "cxCheckGroup.hpp"
#include "cxRadioGroup.hpp"

//---------------------------------------------------------------------------
class TFormaCreateCard : public TForm
{
__published:	// IDE-managed Components
	TcxTextEdit *StartNumbercxTextEdit;
	TcxTextEdit *EndNumbercxTextEdit;
	TcxTextEdit *PrefiksCardcxTextEdit;
	TcxCalcEdit *ProcentcxCalcEdit;
	TcxCheckBox *SingleCardcxCheckBox;
	TcxButtonEdit *NameKlientcxButtonEdit;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxImageComboBox *cxImageComboBoxTypeCard;
	TcxButtonEdit *VidCardcxButtonEdit;
	TcxLabel *cxLabel7;
	TcxButtonEdit *NameGrpKlientcxButtonEdit;
	TcxLabel *cxLabel8;
	TcxTextEdit *NameCardcxTextEdit;
	TcxTextEdit *NameKlientcxTextEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxRadioGroup *cxRadioGroup1;
	TcxRadioButton *ViborKlientcxRadioButton;
	TcxRadioButton *NewKlientcxRadioButton;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall VidCardcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameGrpKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);


private:	// User declarations
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		IFormaSpiskaSprVidDiscountCard * FormaSpiskaSprVidDiscountCard;
		void ViborVidDiscountCard(void);
		void __fastcall EndViborVidDiscountCard(void);

		IFormaSpiskaSprGrpKlient * SpisokGrpKlient;
		void OpenFormSpiskaSprGrpKlient(void);


		enum {ER_NoRekv,ER_ViborKlient, ER_ViborTypeCard, ER_ViborGrpKlient, ER_No} ViborRekvisit;

		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdVidCard;
		UnicodeString NameVidCard;

		__int64 IdGrpKlient;
		UnicodeString NameGrpKlient;

public:		// User declarations
	__fastcall TFormaCreateCard(TComponent* Owner);

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


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaCreateCard *FormaCreateCard;
//---------------------------------------------------------------------------
#endif
