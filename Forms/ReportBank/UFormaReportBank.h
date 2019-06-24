//---------------------------------------------------------------------------

#ifndef UFormaReportBankH
#define UFormaReportBankH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IDMTableExtPrintForm.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
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
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaReportBank : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQ;
	TpFIBDataSet *Dv;
	TFIBBCDField *IBQPRIHODSUM;
	TFIBBCDField *IBQRASHODSUM;
	TFIBBCDField *IBQPR_DOCON_SUM;
	TFIBBCDField *IBQRAS_DOCON_SUM;
	TFIBBCDField *IBQOSTSUM;
	TFIBBCDField *IBQNACHOSTSUM;
	TFIBBCDField *IBQCONOSTSUM;
	TFIBDateTimeField *DvPOSDOC_RGBANK_DV;
	TFIBSmallIntField *DvTDV_RGBANK_DV;
	TFIBBCDField *DvSUM_RGBANK_DV;
	TFIBIntegerField *DvOPER_RGBANK_DV;
	TFIBIntegerField *DvNUMDOC;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxComboBox *OperationComboBox;
	TcxCheckBox *OnlyOperationCheckBox;
	TcxButtonEdit *NameBSchetEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxButton *cxButtonOCB;
	TcxButton *cxButtonDv;
	TcxButton *cxButtonClose;
	TFIBBCDField *IBQIDFIRM_PROC;
	TFIBBCDField *IBQIDBSCHET_PROC;
	TFIBBCDField *DvID_RGBANK_DV;
	TFIBBCDField *DvIDDOC_RGBANK_DV;
	TFIBBCDField *DvIDFIRM_RGBANK_DV;
	TFIBBCDField *DvIDBSCHET_RGBANK_DV;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButton1;
	TAction *ActionClose;
	TFIBWideStringField *IBQNAMEFIRM_PROC;
	TFIBWideStringField *IBQNAMEBSCHET_PROC;
	TFIBWideStringField *DvTDOC;
	TLabel *Label10;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameBSchetEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonOCBClick(TObject *Sender);
	void __fastcall cxButtonDvClick(TObject *Sender);
	void __fastcall DateNachKeyPress(TObject *Sender, char &Key);
	void __fastcall DateConKeyPress(TObject *Sender, char &Key);

				//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		IFormaSpiskaSprFirm *SpisokFirm;
        IFormaSpiskaSprBankSchet * SpisokBSchet;


        void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprBSchet(void);


		void NewCreateReport(void);
        void NewOutputZagolovokReport(TSheetEditor *prForm);
        void NewOutputStringDv(TSheetEditor *prForm);
		void NewOutputPodavalReport(TSheetEditor *prForm);

        int numRow;
		int numCol;
        int porNumStr;

		__int64 IdFirm;
		__int64 IdBSchet;
		__int64 IdBusinessOper;
		__int64 IdProject;

		double TekOstSum;
        double AllSumPrihod;
        double AllSumRashod;


		__int64 IdTecFirm;
		__int64 IdTecGrpKlient;
		__int64 IdTecKlient;
		__int64 IdTecDogovor;
		__int64 IdTecDoc;


		void CreateReportOCB( TSheetEditor *prForm);
		void OutputZagolovokReportOCB(TSheetEditor *prForm);
		void OutputStringFirmOCB(TSheetEditor *prForm);
		int num_row_firm;
		void OutputStringItogiFirmOCB(TSheetEditor *prForm);
		void OutputStringOCB(TSheetEditor *prForm);
		void OutputPodavalReportOCB(TSheetEditor *prForm);


		float AllNachOst;
		float AllPrihod;
		float AllRashod;
		float AllConOst;

		float sum_nach_ost_firm;
		float sum_prihod_firm;
		float sum_rashod_firm;
		float sum_con_ost_firm;
		enum  {ER_NoRekv,ViborFirm, ViborBSchet,
		ER_ViborBusinessOper, ER_ViborProject, NO} EditRekvisit;

			IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void  EndViborProject(void);
public:		// User declarations
        __fastcall TFormaReportBank(TComponent* Owner);

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




//        bool NewElement;  // ����� �������
//		bool Prosmotr;    //������ ��������
//		bool Vibor;       //��� ������
//		__int64 IdDoc;           //������������� ������� ������
//		__int64 IdGrp;        // ������������ ������
//		__int64 IdElementaMaster;  //������������� �������� �����������-���������



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportBank *FormaReportBank;
//---------------------------------------------------------------------------
#endif
