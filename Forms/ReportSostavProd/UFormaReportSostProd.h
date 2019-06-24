//---------------------------------------------------------------------------

#ifndef UFormaReportSostProdH
#define UFormaReportSostProdH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprNom.h"
#include "UDM.h"
#include "USheetEditor.h"
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
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
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportSostProd : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TDataSource *DataSourceNom;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *TypePrice;
	TpFIBDataSet *IBQNom;
	TpFIBDataSet *IBQNomRest;
	TFIBIntegerField *IBQNomTNOM;
	TFIBIntegerField *IBQNomCODENOM;
	TFIBDateTimeField *IBQNomRestPOS_NOMREST;
	TFIBBCDField *IBQNomRestKOLEDPROD_NOMREST;
	TpFIBDataSet *BasEd;
	TpFIBDataSet *OsnEd;
	TpFIBDataSet *EdProd;
	TFIBBCDField *BasEdKFED;
	TFIBIntegerField *BasEdTSHED;
	TFIBSmallIntField *BasEdNEISPED;
	TFIBBCDField *OsnEdKFED;
	TFIBIntegerField *OsnEdTSHED;
	TFIBSmallIntField *OsnEdNEISPED;
	TFIBBCDField *EdProdKFED;
	TFIBIntegerField *EdProdTSHED;
	TFIBSmallIntField *EdProdNEISPED;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxComboBox *TypePriceComboBox;
	TcxButtonEdit *NameNomDBEdit;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *IBQNomIDNOM;
	TFIBBCDField *IBQNomIDBASEDNOM;
	TFIBBCDField *IBQNomIDOSNEDNOM;
	TFIBBCDField *IBQNomIDGRPNOM;
	TFIBBCDField *IBQNomIDFIRMNOM;
	TFIBBCDField *IBQNomIDCOUNTRYNOM;
	TFIBBCDField *IBQNomRestID_NOMREST;
	TFIBBCDField *IBQNomRestIDNOM_NOMREST;
	TFIBBCDField *IBQNomRestIDMPRIG_NOMREST;
	TFIBBCDField *IBQNomRestIDEDPROD_NOMREST;
	TFIBBCDField *BasEdIDED;
	TFIBBCDField *BasEdIDNOMED;
	TFIBBCDField *BasEdIDOKEIED;
	TFIBBCDField *OsnEdIDED;
	TFIBBCDField *OsnEdIDNOMED;
	TFIBBCDField *OsnEdIDOKEIED;
	TFIBBCDField *EdProdIDED;
	TFIBBCDField *EdProdIDNOMED;
	TFIBBCDField *EdProdIDOKEIED;
	TAction *ActionClose;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TFIBWideStringField *IBQNomNAMENOM;
	TFIBWideStringField *IBQNomFNAMENOM;
	TFIBWideStringField *IBQNomKRNAMENOM;
	TFIBWideStringField *IBQNomARTNOM;
	TFIBWideStringField *IBQNomDESCR_SNOM;
	TFIBWideStringField *BasEdNAMEED;
	TFIBWideStringField *BasEdSHED;
	TFIBWideStringField *BasEdGID_SED;
	TFIBWideStringField *OsnEdNAMEED;
	TFIBWideStringField *EdProdNAMEED;
	TFIBWideStringField *IBQNomRestSOST_NOMREST;
	TFIBWideStringField *IBQNomRestTEHN_NOMREST;
	TFIBWideStringField *IBQNomRestVIH_NOMREST;
	TFIBWideStringField *IBQNomRestSROK_NOMREST;
	TFIBWideStringField *IBQNomRestNOMER_NOMREST;
	TFIBWideStringField *IBQNomRestNAME_NOMREST;
	TFIBWideStringField *IBQNomRestGID_SNOMREST;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameNomDBEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		void OpenFormSpiskaSprNom(void);
		void OutputZagolovokTable(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		float Sum;
		float SumNaOsnEd;
		float SumNaBasEd;
		float SostavNaBasEd;
		float SumStr;
		float SumStrNaOsnEd;
		float SumStrNaBasEd;
		void OutputSostav(__int64 idnom,__int64 id_nom_rest, float K, float K2,TSheetEditor *prForm);
		bool flObrabatChangeTypePrice;

		        HANDLE IdRodForm;
		HANDLE IdDochForm;
		IFormaSpiskaSprNom *Nom;


		enum  {ER_NoRekv,Tovar, NO} EditRekvisit;

public:		// User declarations

		__fastcall TFormaReportSostProd(TComponent* Owner);
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

		__int64 IdNom;
		__int64 IdNomRest;
		__int64 IdTypePrice;
		UnicodeString NameNom;
		UnicodeString NameTypePrice;

		void UpdateForm();


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportSostProd *FormaReportSostProd;
//---------------------------------------------------------------------------
#endif
