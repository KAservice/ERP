//---------------------------------------------------------------------------

#ifndef UFormaGurDocCheckKKM2H
#define UFormaGurDocCheckKKM2H
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
#include "IDMGurDocCheckKKM2.h"
#include "IFormaViborPerioda.h"
#include "UDM.h"
#include "IDMTableExtPrintForm.h"
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
#include "cxButtons.hpp"
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
#include "cxLookAndFeelPainters.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaGurDocCheckKKM2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonPrint;
        TToolButton *ToolButtonOtbor;
        TLabel *Label2;
        TLabel *NameKKMLabel;
	TToolButton *ToolButtonRefresh;
	TcxButton *cxButtonClose;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TcxGridDBColumn *cxGrid1DBTableView1PRDOC;
	TcxGridDBColumn *cxGrid1DBTableView1SUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NCHECKCHK;
	TcxGridDBColumn *cxGrid1DBTableView1NKLCHK;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKKM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxTextEdit *NumberKLEdit;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonPrintClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1PRDOCCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall NumberKLEditKeyPress(TObject *Sender, char &Key);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);


				//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


			//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;


	IFormaViborPerioda *FormaViborPerioda;
		void OpenPrintForm(void);
		void OutputString(ISheetEditor *prForm);
		void OutputZagolovokReport(ISheetEditor *prForm);
		void OutputPodavalReport(ISheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		double SumReport;

		void OpenFormDoc(void);
public:		// User declarations
		__fastcall TFormaGurDocCheckKKM2(TComponent* Owner);

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������



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
		IDMGurDocCheckKKM2 * DM;
		bool Vibor;
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		__int64 IdDoc;
        __int64 IdKKM;
		bool Otbor;


		TDateTime PosNach;
		TDateTime PosCon;

        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurDocCheckKKM2 *FormaGurDocCheckKKM2;
//---------------------------------------------------------------------------
#endif
