//---------------------------------------------------------------------------

#ifndef UFormaElementaSprAddressViborH
#define UFormaElementaSprAddressViborH
//---------------------------------------------------------------------------
#include "IDMSprAddressRegion.h"
#include "IDMSprAddressRayon.h"
#include "IDMSprAddressNasPunkt.h"
#include "IDMSprAddressStreet.h"
#include "IDMSprAddressDom.h"
#include "IDMSprAddressStroen.h"
#include "IDMSprAddressKV.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaElementaSprAddressRegion.h"
#include "IFormaElementaSprAddressRayon.h"
#include "IFormaElementaSprAddressNasPunkt.h"
#include "IFormaElementaSprAddressStreet.h"
#include "IFormaElementaSprAddressDom.h"
#include "IFormaElementaSprAddressStroen.h"
#include "IFormaElementaSprAddressKV.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxCheckBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprAddressVibor : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxLookupComboBox *RegioncxLookupComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TcxLookupComboBox *RayoncxLookupComboBox;
	TcxLookupComboBox *NasPunktcxLookupComboBox;
	TcxLookupComboBox *StreetcxLookupComboBox;
	TcxLookupComboBox *DomcxLookupComboBox;
	TcxLookupComboBox *StroencxLookupComboBox;
	TcxLookupComboBox *KVcxLookupComboBox;
	TButton *ButtonInsRegion;
	TButton *ButtonUpdRegion;
	TButton *ButtonDelRegion;
	TButton *ButtonInsRayon;
	TButton *ButtonUpdRayon;
	TButton *ButtonDelRayon;
	TButton *ButtonInsNasPunkt;
	TButton *ButtonUpdNasPunkt;
	TButton *ButtonDelNasPunkt;
	TButton *ButtonInsStreet;
	TButton *ButtonUpdStreet;
	TButton *ButtonDelStreet;
	TButton *ButtonAddDom;
	TButton *ButtonUpdDom;
	TButton *ButtonDelDom;
	TButton *ButtonInsStroen;
	TButton *ButtonUpdStroen;
	TButton *ButtonDelStroen;
	TButton *ButtonInsKV;
	TButton *ButtonUpdKV;
	TButton *ButtonDelKV;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ButtonInsRegionClick(TObject *Sender);
	void __fastcall ButtonUpdRegionClick(TObject *Sender);
	void __fastcall RegioncxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonDelRegionClick(TObject *Sender);
	void __fastcall ButtonInsRayonClick(TObject *Sender);
	void __fastcall ButtonUpdRayonClick(TObject *Sender);
	void __fastcall ButtonDelRayonClick(TObject *Sender);
	void __fastcall RayoncxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonInsNasPunktClick(TObject *Sender);
	void __fastcall ButtonUpdNasPunktClick(TObject *Sender);
	void __fastcall ButtonDelNasPunktClick(TObject *Sender);
	void __fastcall NasPunktcxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonInsStreetClick(TObject *Sender);
	void __fastcall ButtonUpdStreetClick(TObject *Sender);
	void __fastcall ButtonDelStreetClick(TObject *Sender);
	void __fastcall StreetcxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonAddDomClick(TObject *Sender);
	void __fastcall ButtonUpdDomClick(TObject *Sender);
	void __fastcall ButtonDelDomClick(TObject *Sender);
	void __fastcall DomcxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonInsStroenClick(TObject *Sender);
	void __fastcall ButtonUpdStroenClick(TObject *Sender);
	void __fastcall ButtonDelStroenClick(TObject *Sender);
	void __fastcall StroencxLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ButtonInsKVClick(TObject *Sender);
	void __fastcall ButtonUpdKVClick(TObject *Sender);
	void __fastcall ButtonDelKVClick(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		enum  {ER_NoRekv,
						ER_UpdateRegion,
						 ER_UpdateRayon,
						 ER_UpdateNasPunkt,
						 ER_UpdateStreet,
						 ER_UpdateDom,
						 ER_UpdateStroen,
						 ER_UpdateKV} EditRekvisit;


public:		// User declarations
		__fastcall TFormaElementaSprAddressVibor(TComponent* Owner);

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
		IDMSprAddressRegion * DM_Region;
		IDMSprAddressRayon * DM_Rayon;
		IDMSprAddressNasPunkt * DM_NasPunkt;
		IDMSprAddressStreet * DM_Street;
		IDMSprAddressDom * DM_Dom;
		IDMSprAddressStroen * DM_Stroen;
		IDMSprAddressKV * DM_KV;
		void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprAddressVibor *FormaElementaSprAddressVibor;
//---------------------------------------------------------------------------
#endif
