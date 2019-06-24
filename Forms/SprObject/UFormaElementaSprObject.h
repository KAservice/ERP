//---------------------------------------------------------------------------

#ifndef UFormaElementaSprObjectH
#define UFormaElementaSprObjectH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMSprObject.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprPodr.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "cxPC.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprObject : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBButtonEdit *NamePodcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameKKMcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TLabel *Label4;
	TLabel *Label3;
	TLabel *Label7;
	TLabel *Label6;
	TLabel *Label11;
	TLabel *Label1;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NamePodcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKKMcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		IFormaSpiskaSprPodr * FormaSpiskaSprPodr;
		IFormaSpiskaSprKKM *FormaSpiskaSprKKM;

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);

				enum {NO, EditKomplModel, VR_Nom, VR_ModelDetal, VR_NeisprModel, VR_Model,
						VR_ModelPropertiesValue, VR_ModelInfBlock,
						ER_ViborBrand,
						ER_ViborProducer,
						ER_ViborTypeDevice,
						ER_ViborActCategory} ViborRekv;




public:		// User declarations
		__fastcall TFormaElementaSprObject(TComponent* Owner);

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
		IDMSprObject * DM;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprObject *FormaElementaSprObject;
//---------------------------------------------------------------------------
#endif
