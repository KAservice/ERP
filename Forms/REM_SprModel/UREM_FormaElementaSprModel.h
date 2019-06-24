//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprModelH
#define UREM_FormaElementaSprModelH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IREM_DMSprModel.h"
#include "IREM_FormaSpiskaSprKomplModel.h"
#include "IREM_FormaSpiskaSprModelDetal.h"
#include "IREM_FormaSpiskaSprNeisprModel.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprNom.h"
#include "IREM_FormaSpiskaSprModelPropertiesValue.h"
#include "IREM_FormaSpiskaSprModelInfBlock.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaSpiskaSprProducer.h"
#include "IREM_FormaSpiskaSprTypeDevice.h"
#include "IREM_FormaSpiskaSprActCategory.h"
#include "IREM_FormaSpiskaSprModelTypRabot.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtonEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprModel : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label1;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxButton *cxButtonKolmpl;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxDBButtonEdit *NameNomcxDBButtonEdit;
	TcxDBTextEdit *StrCodeModelcxDBTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxButton *cxButtonOpenSprModelDetal;
	TcxButton *cxButtonNeispr;
	TcxDBButtonEdit *NameModelNeisprcxDBButtonEdit;
	TLabel *Label2;
	TcxButton *cxButtonOpenProperties;
	TcxButton *cxButtonOpenInfBlock;
	TcxDBButtonEdit *NameProducercxDBButtonEdit;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBrandcxDBButtonEdit;
	TcxDBButtonEdit *NameTypeDevicecxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxDBButtonEdit *NameActivecategorycxDBButtonEdit;
	TcxButton *cxButtonTypRabot;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonKolmplClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonOpenSprModelDetalClick(TObject *Sender);
	void __fastcall cxButtonNeisprClick(TObject *Sender);
	void __fastcall NameModelNeisprcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonOpenPropertiesClick(TObject *Sender);
	void __fastcall cxButtonOpenInfBlockClick(TObject *Sender);
	void __fastcall NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTypeDevicecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonTypRabotClick(TObject *Sender);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IREM_FormaSpiskaSprKomplModel * REM_FormaSpiskaSprKomplModel;
		IREM_FormaSpiskaSprModelDetal * REM_FormaSpiskaSprModelDetal;
		IREM_FormaSpiskaSprNeisprModel * REM_FormaSpiskaSprNeisprModel;
		IREM_FormaSpiskaSprModelPropertiesValue * REM_FormaSpiskaSprModelPropertiesValue;
		IREM_FormaSpiskaSprModelInfBlock * REM_FormaSpiskaSprModelInfBlock;
		IREM_FormaSpiskaSprModelTypRabot * REM_FormaSpiskaSprModelTypRabot;

		enum {NO, EditKomplModel, VR_Nom, VR_ModelDetal, VR_NeisprModel, VR_Model,
						VR_ModelPropertiesValue, VR_ModelInfBlock, VR_ModelTypRabot,
						ER_ViborBrand,
						ER_ViborProducer,
						ER_ViborTypeDevice,
						ER_ViborActCategory} ViborRekv;

		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//����� ������
		IREM_FormaSpiskaSprModel * FormaSpiskaSprModel;
		void ViborModel(void);
		void __fastcall EndViborModel(void);


				//�����
		IFormaSpiskaSprBrand * SpisokBrand;
		void ViborBrand(void);
		void __fastcall EndViborBrand(void);

		IFormaSpiskaSprProducer * FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EventEndEditProdcer(void);

		IREM_FormaSpiskaSprTypeDevice * REM_FormaSpiskaSprTypeDevice;
		void ViborTypeDevice(void);
		void EndViborTypeDevice(void);

		IREM_FormaSpiskaSprActCategory * REM_FormaSpiskaSprActCategory;
		void ViborActCategory(void);
		void EndViborActCategory(void);

public:		// User declarations
		__fastcall TREM_FormaElementaSprModel(TComponent* Owner);

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
        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IREM_DMSprModel * DM;


		void UpdateForm(void) ;
		bool SaveElement;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprModel *REM_FormaElementaSprModel;
//---------------------------------------------------------------------------
#endif
