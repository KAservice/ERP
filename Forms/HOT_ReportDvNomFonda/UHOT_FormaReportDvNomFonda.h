//---------------------------------------------------------------------------

#ifndef UHOT_FormaReportDvNomFondaH
#define UHOT_FormaReportDvNomFondaH
//---------------------------------------------------------------------------
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "UDM.h"
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
#include <ExtCtrls.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "dxBkgnd.hpp"
#include "dxPrnDev.hpp"
#include "dxPrnPg.hpp"
#include "dxPSCompsProvider.hpp"
#include "dxPSCore.hpp"
#include "dxPScxCommon.hpp"
#include "dxPScxGrid6Lnk.hpp"
#include "dxPSEdgePatterns.hpp"
#include "dxPSEngn.hpp"
#include "dxPSFillPatterns.hpp"
#include "dxPSGlbl.hpp"
#include "dxPSUtl.hpp"
#include "dxWrap.hpp"
#include "dxPSContainerLnk.hpp"
#include "cxButtonEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaReportDvNomFonda : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TpFIBDataSet *Table;
	TpFIBTransaction *pFIBTr;
	TDataSource *DataSource1;
	TFIBDateTimeField *TablePOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *TablePOSCON_HOT_SOSTNF;
	TFIBDateTimeField *TablePOS_HOT_RGSOSTNF_DV;
	TFIBIntegerField *TableTDV_HOT_RGSOSTNF_DV;
	TFIBIntegerField *TableOPER_HOT_RGSOSTNF_DV;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SOBJECT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SCATNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SNF;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1POSNACH_HOT_SOSTNF;
	TcxGridDBColumn *cxGrid1DBTableView1POSCON_HOT_SOSTNF;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SSOSTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1POS_HOT_RGSOSTNF_DV;
	TcxGridDBColumn *cxGrid1DBTableView1TDV_HOT_RGSOSTNF_DV;
	TcxGridDBColumn *cxGrid1DBTableView1OPER_HOT_RGSOSTNF_DV;
	TcxDateEdit *PosNach;
	TcxDateEdit *PosCon;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonUpdate;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TdxComponentPrinter *dxComponentPrinter1;
	TcxButton *cxButtonPrint;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TcxButtonEdit *NameSostcxButtonEdit;
	TcxLabel *cxLabel4;
	TFIBWideStringField *TableNAME_HOT_SOBJECT;
	TFIBWideStringField *TableNAME_HOT_SCATNOM;
	TFIBWideStringField *TableNAME_HOT_SNF;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_HOT_SSOSTNOM;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall TableTDV_HOT_RGSOSTNF_DVGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
	void __fastcall cxButtonPrintClick(TObject *Sender);
	void __fastcall NameSostcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


					//выбор состояния
		IHOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSost(void);
		void __fastcall EndViborSost(void);
		__int64 IdSost;

       enum {ER_NoRekv,ER_Sost} EitRekvisit;
public:		// User declarations
	__fastcall THOT_FormaReportDvNomFonda(TComponent* Owner);

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


};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaReportDvNomFonda *HOT_FormaReportDvNomFonda;
//---------------------------------------------------------------------------
#endif
