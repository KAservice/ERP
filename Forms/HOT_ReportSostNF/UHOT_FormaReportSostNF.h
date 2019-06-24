//---------------------------------------------------------------------------

#ifndef UHOT_FormaReportSostNFH
#define UHOT_FormaReportSostNFH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "USheetEditor.h"
#include "UDM.h"
#include "IHOT_FormaSpiskaSprObject.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "IHOT_FormaElementaTableSostNF.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <ExtCtrls.hpp>
#include "cxGridBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaReportSostNF : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel1;
	TcxButton *cxButtonCreateReport;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameObjectcxButtonEdit;
	TLabel *Label4;
	TcxButtonEdit *NameCatcxButtonEdit;
	TcxDateEdit *PosNachcxDateEdit;
	TLabel *Label2;
	TLabel *Label1;
	TcxDateEdit *PosConcxDateEdit;
	TLabel *Label3;
	TLabel *Label7;
	TLabel *Label9;
	TcxButtonEdit *NameSostcxButtonEdit;
	TcxButtonEdit *NameNomercxButtonEdit;
	TLabel *Label6;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TpFIBTransaction *pFIBTr;
	TpFIBDataSet *SostNF;
	TcxGridBandedTableView *cxGrid1BandedTableView1;
	TFIBBCDField *SostNFID_HOT_SOSTNF;
	TFIBBCDField *SostNFID_HOT_SCATNOM;
	TFIBBCDField *SostNFID_HOT_SNF;
	TFIBIntegerField *SostNFKOLM_HOT_SNF;
	TFIBBCDField *SostNFID_HOT_SSOSTNOM;
	TFIBDateTimeField *SostNFPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *SostNFPOSCON_HOT_SOSTNF;
	TFIBIntegerField *SostNFKOLM_HOT_SOSTNF;
	TFIBBCDField *SostNFID_HOT_RGSOSTNF;
	TcxGridBandedColumn *cxGrid1BandedTableView1Column1;
	TFIBIntegerField *SostNFCOLOR_HOT_SSOSTNOM;
	TAction *ActionClose;
	TFIBWideStringField *SostNFNAME_HOT_SCATNOM;
	TFIBWideStringField *SostNFNAME_HOT_SNF;
	TFIBWideStringField *SostNFNAME_HOT_SSOSTNOM;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateReportClick(TObject *Sender);
	void __fastcall NameObjectcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCatcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSostcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1BandedTableView1DblClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxGrid1BandedTableView1CustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		__int64 IdObject;
		__int64 IdCat;
		__int64 IdNomer;
		__int64 IdSost;

		bool NewElement;  // ����� �������
		bool Prosmotr;    //������ ��������
		bool Vibor;       //��� ������
		__int64 IdDoc;           //������������� ������� ������

		__int64 IdElementaMaster;  //������������� �������� �����������-���������

		//����� �������
		IHOT_FormaSpiskaSprObject * HOT_FormaSpiskaSprObject;
		void ViborObject(void);
		void __fastcall EndViborObject(void);

		//����� ��������� ������
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//����� ������
		IHOT_FormaSpiskaSprNF *  HOT_FormaSpiskaSprNF;
		void ViborNF(void);
		void __fastcall EndViborNF(void);

		//����� ��������� ������
		IHOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSostNom(void);
		void __fastcall EndViborSostNom(void);

		AnsiString GetTextQuery(void);
		void OutputSost(int tec_column_left_margin, int num_first_row);
		int GetPosStart(void);
		int GetPosFinish(void);
		void OutputRect(int row, int first_col, int end_col);


		IHOT_FormaElementaTableSostNF * HOT_FormaElementaTableSostNF;
		void __fastcall EndProsmotrSost(void);

		enum {ER_NoRekv,ER_Object,ER_CatNom,ER_SprNF,ER_SostNom,ER_ProsmotrSost} EitRekvisit;

public:		// User declarations
		__fastcall THOT_FormaReportSostNF(TComponent* Owner);

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
extern PACKAGE THOT_FormaReportSostNF *HOT_FormaReportSostNF;
//---------------------------------------------------------------------------
#endif
