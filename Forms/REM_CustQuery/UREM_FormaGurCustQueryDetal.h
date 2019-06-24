//---------------------------------------------------------------------------

#ifndef UREM_FormaGurCustQueryDetalH
#define UREM_FormaGurCustQueryDetalH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMGurCustQueryDetal.h"
#include "UDM.h"
#include "IFormaViborPerioda.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprProducer.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp> 
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "UREM_DMGurCustQuery.h"
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurCustQueryDetal : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonParamOtbor;
        TToolButton *ToolButtonOtbor;
        TLabel *StrOtborLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonRefresh;
	TToolButton *ToolButtonAddNewZ;
	TToolButton *ToolButton3;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1RUN_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SBRAND;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRODUCER;
	TcxTextEdit *ModelcxTextEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel3;
	TcxButton *cxButtonPoiskPoModel;
	TcxButton *cxButtonPoiskPoKlientu;
	TcxTextEdit *KlientNamecxTextEdit;
	TcxButtonEdit *NameZayavkacxButtonEdit;
	TcxLabel *cxLabel2;
	TcxLabel *NameKlientcxLabel;
	TcxLabel *NameModelcxLabel;
	TcxLabel *SerNumcxLabel;
	TcxLabel *SerNum2cxLabel;
	TcxButton *cxButtonOtborPoZayavka;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_ZAKAZA_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1DATE_ZAKAZA_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_REM_CQUERY;
	TLabel *Label27;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel5;
	TcxButtonEdit *NameProducercxButtonEdit;
	TcxSpinEdit *NumberZakazcxSpinEdit;
	TcxDateEdit *DateZakazcxDateEdit;
	TToolButton *ToolButtonOpenTrebZakaz;
	TToolButton *ToolButtonOpenPoNumberZakaz;
	TToolButton *ToolButtonSetNumberDateZakaza;
	TToolButton *ToolButtonSetPredvZakazano;
	TToolButton *ToolButtonSetVipolneno;
	TToolButton *ToolButtonSetOtpravleno;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_CQUERYT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_CQUERYT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_REM_CQUERYT;
	TcxGridDBColumn *cxGrid1DBTableView1NOM_SUM_STR;
	TcxGridDBColumn *cxGrid1DBTableView1FL_DOSTUPNO_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_ZAKUP_SPRNOM;
	TcxGridDBColumn *cxGrid1DBTableView1PRNOM_SUM_STR;
	TcxGridDBColumn *cxGrid1DBTableView1PRODAVEC_NAME;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_STR_ZAK_POST_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_STR_ZAK_SPROV_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOCTK_REM_CQUERY;
	TToolButton *ToolButton5;
	TToolButton *ToolButtonOpenGurAllDocPoZ;
	TToolButton *ToolButtonOpenZ;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall ToolButtonAddNewZClick(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
					//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1RUN_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall cxButtonPoiskPoModelClick(TObject *Sender);
	void __fastcall cxButtonPoiskPoKlientuClick(TObject *Sender);
	void __fastcall cxButtonOtborPoZayavkaClick(TObject *Sender);
	void __fastcall NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);
	void __fastcall NameProducercxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonOpenTrebZakazClick(TObject *Sender);
	void __fastcall ToolButtonOpenPoNumberZakazClick(TObject *Sender);
	void __fastcall ToolButtonSetNumberDateZakazaClick(TObject *Sender);
	void __fastcall ToolButtonSetPredvZakazanoClick(TObject *Sender);
	void __fastcall ToolButtonSetVipolnenoClick(TObject *Sender);
	void __fastcall ToolButtonSetOtpravlenoClick(TObject *Sender);
	void __fastcall ToolButtonOpenGurAllDocPoZClick(TObject *Sender);
	void __fastcall ToolButtonOpenZClick(TObject *Sender);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

			//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv,
		ER_ViborHardware, ER_Zayavka, ER_ViborProducer} ViborRekv;

		IFormaViborPerioda *FormaViborPerioda;

		void OpenFormDoc();
		void DeleteDoc(void);


					//����� ������
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

				IFormaSpiskaSprProducer* FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EndViborProducer(void);

		__int64 IdVibProducer;

public:		// User declarations
		__fastcall TREM_FormaGurCustQueryDetal(TComponent* Owner);

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

		IREM_DMGurCustQueryDetal * DM;

		__int64 IdDoc;

        TDateTime PosNach;
		TDateTime PosCon;

		void UpdateForm(void);

		__int64 IdVibZayavka;

		UnicodeString Zayavka_NameKlient;
		UnicodeString Zayavka_NameModel;
		UnicodeString Zayavka_SerNum;
		UnicodeString Zayavka_SerNum2;
		UnicodeString Zayavka_Name;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurCustQueryDetal *REM_FormaGurCustQueryDetal;
//---------------------------------------------------------------------------
#endif
