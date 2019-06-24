//---------------------------------------------------------------------------

#ifndef UFormaGurDocCheckKKMH
#define UFormaGurDocCheckKKMH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMGurDocCheckKKM.h"
#include "IFormaViborPerioda.h"
#include "ISheetEditor.h"
#include "IFormaSpiskaSprKKM.h"
#include "IDMTableExtPrintForm.h"

//-----------------------------------------------------------------------------
#include "cxClasses.hpp"
#include "cxContainer.hpp"
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
#include "cxLookAndFeels.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <Menus.hpp>
#include "UDM.h"
//---------------------------------------------------------------------------

class TFormaGurDocCheckKKM : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonNewDoc;
        TToolButton *ToolButton2;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonPrint;
        TToolButton *ToolButton5;
        TToolButton *ToolButtonOtbor;
        TLabel *Label2;
        TButton *ButtonViborKKM;
        TLabel *NameKKMLabel;
        TToolButton *ToolButtonCreateDocRepKKM;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonrefresh;
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
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxTextEdit *NumberKLEdit;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1OPLNALCHK;
	TcxGridDBColumn *cxGrid1DBTableView1OPLPCCHK;
	TcxGridDBColumn *cxGrid1DBTableView1OPLPLATCARDD_ALL;
	TcxGridDBColumn *cxGrid1DBTableView1OPLCREDIRCARD_ALL_DCHK;
	TcxGridDBColumn *cxGrid1DBTableView1OPL_OTHER_DCHK;
	TcxGridDBColumn *cxGrid1DBTableView1OPERCHK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonNewDocClick(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButtonPrintClick(TObject *Sender);
        void __fastcall ButtonViborKKMClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonCreateDocRepKKMClick(TObject *Sender);
	void __fastcall ToolButtonrefreshClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1PRDOCCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall NumberKLEditKeyPress(TObject *Sender, char &Key);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);

			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1OPERCHKCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		enum {NO,ViborPerioda, ViborKKM} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;

		IFormaSpiskaSprKKM * FormaSpiskaSprKKM;
		void OpenFormSpiskaSprKKM(void);

		void OpenFormDoc();
		void DeleteDoc(void);
		void CanceDvRegDoc(void);

				void OpenPrintForm(void);
		void OutputString(ISheetEditor *prForm);
		void OutputZagolovokReport(ISheetEditor *prForm);
		void OutputPodavalReport(ISheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		double SumReport;
public:		// User declarations
        __fastcall TFormaGurDocCheckKKM(TComponent* Owner);
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		//Текущий интерфейс
		IDMGurDocCheckKKM * DM;

		__int64 IdDoc;
        __int64 IdKKM;
        bool Otbor;



        TDateTime PosNach;
		TDateTime PosCon;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurDocCheckKKM *FormaGurDocCheckKKM;
//---------------------------------------------------------------------------
#endif
