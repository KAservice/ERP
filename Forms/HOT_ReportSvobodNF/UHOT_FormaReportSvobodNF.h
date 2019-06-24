//---------------------------------------------------------------------------

#ifndef UHOT_FormaReportSvobodNFH
#define UHOT_FormaReportSvobodNFH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UHOT_DMReportSvobodNF.h"
#include "UDM.h"
#include "IFormaSpiskaSprFirm.h"
#include "USheetEditor.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxPC.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
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
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class THOT_FormaReportSvobodNF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxLabel *cxLabel1;
	TcxDateEdit *PosNachcxDateEdit;
	TcxDateEdit *PosConcxDateEdit;
	TcxLabel *cxLabel3;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameFirmcxButtonEdit;
	TcxLabel *cxLabel2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxButton *cxButtonCreate;
	TdxComponentPrinter *dxComponentPrinter1;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TcxButton *cxButtonPrint;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_OBJECT;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_CAT;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAME_NOM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_MEST_ALL;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_MEST_SVOB;
	TActionList *ActionList;
	TAction *ActionClose;
	TAction *ActionPrint;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameFirmcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
private:	// User declarations

	  bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		THOT_DMReportSvobodNF *DM;

		__int64 IdFirm;
		IFormaSpiskaSprFirm *FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);
		enum {ER_NoRekv,ER_Firm} EitRekvisit;
public:		// User declarations
	__fastcall THOT_FormaReportSvobodNF(TComponent* Owner);

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
extern PACKAGE THOT_FormaReportSvobodNF *HOT_FormaReportSvobodNF;
//---------------------------------------------------------------------------
#endif
