//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportSaleCheckH
#define UFormaDialogaReportSaleCheckH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "USheetEditor.h"
#include "IDMFibConnection.h"
//-----------------------------------------------------------------------------
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
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDialogaReportSaleCheck : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TpFIBTransaction *IBTr;
	TFIBBCDField *GrpSUMMA;
	TFIBFloatField *GrpSUMKOL;
	TFIBBCDField *ElSUMMA;
	TFIBFloatField *ElSUMKOL;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxButtonEdit *NameSkladEdit;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TFIBBCDField *GrpIDGN;
	TAction *ActionClose;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElNAMEED;
	TFIBWideStringField *GrpNAMEGN;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TFormaDialogaReportSaleCheck(TComponent* Owner);

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

        enum  {ER_NoRekv,ViborSklad, NO} EditRekvisit;


        IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);


         void OutputStringGrp(TSheetEditor *prForm);
        void OutputString(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);
        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double SumReport;
        int IdSkl;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportSaleCheck *FormaDialogaReportSaleCheck;
//---------------------------------------------------------------------------
#endif
