//---------------------------------------------------------------------------

#ifndef UFormaGurRoznDocH
#define UFormaGurRoznDocH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
#include "IDMGurRoznDoc.h"
#include "IFormaViborPerioda.h"
#include "IFormaSetupOtborGurRoznDoc.h"
#include "IDMTableExtPrintForm.h"

//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
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
#include <ActnList.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaGurRoznDoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButtonParamOtbor;
        TToolButton *ToolButtonOtbor;
        TLabel *StrOtborLabel;
        TToolButton *ToolButtonPrint;
	TToolButton *ToolButtonRefresh;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TcxGridDBColumn *cxGrid1DBTableView1PRDOC;
	TcxGridDBColumn *cxGrid1DBTableView1TDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1SUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonParamOtborClick(TObject *Sender);
        void __fastcall ToolButtonPrintClick(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1PRDOCCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall OpenHelpExecute(TObject *Sender);

				//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
private:	// User declarations


	//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
        enum {NO,ViborPerioda, SetupOtborRekv} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;
		IFormaSetupOtborGurRoznDoc * FormaSetupOtbor;

		void OpenFormDoc();

        void OpenPrintForm(void);

		void OutputString(ISheetEditor  *prForm);
		void OutputZagolovokReport(ISheetEditor  *prForm);
		void OutputPodavalReport(ISheetEditor  *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		double SumSale;
		double SumReturnSale;
		double SumPay;
		double SumReturnPay;
public:		// User declarations
		__fastcall TFormaGurRoznDoc(TComponent* Owner);

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

		IDMGurRoznDoc * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		__int64 IdDoc;



        TDateTime PosNach;
        TDateTime PosCon;


        __int64 IdKlient;
		UnicodeString NameKlient;
		UnicodeString   StringTypeDoc;
		UnicodeString NameTypeDoc;
		UnicodeString   StringFullTypeDoc;

        bool OtborPoKlientu ;
        bool OtborPoTypeDoc;




};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurRoznDoc *FormaGurRoznDoc;
//---------------------------------------------------------------------------
#endif
