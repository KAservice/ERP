//---------------------------------------------------------------------------

#ifndef UFormaReportRealH
#define UFormaReportRealH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDMReportSale.h"
#include "USheetEditor.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>


#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportReal : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *LabelNameFirm;
        TLabel *LabelNameSklad;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		enum  {ER_NoRekv,ViborSklad, ViborFirm, NO} EditRekvisit;



		__int64 IdTecFirm;
		__int64 IdTecSklad;
		__int64 IdTecGrpNom;
        __int64 IdTecNom;

		void CreateReport( TSheetEditor *prForm);

        void OutputZagolovokReport(TSheetEditor *prForm);

        void OutputStringFirm(TSheetEditor *prForm);
		int num_row_firm;
        void OutputStringItogiFirm(TSheetEditor *prForm);

        void OutputStringSklad(TSheetEditor *prForm);
        int num_row_sklad;
		void OutputStringItogiSklad(TSheetEditor *prForm);

		void OutputStringGrpNom(TSheetEditor *prForm);
		int num_row_grp_nom;
		void OutputStringItogiGrpNom(TSheetEditor *prForm);

		void OutputStringNom(TSheetEditor *prForm);
		int num_row_nom;
		void OutputStringItogiNom(TSheetEditor *prForm);


		void OutputPodavalReport(TSheetEditor *prForm);

		int numRow;
        int numCol;
		int porNumStr;
		int porNumStrGrp;

		float SumAll;
		float SumFirm;
		float SumSklad;
		float SumGrpNom;

		__int64 IdFirm;
		__int64 IdSklad;




	   TDMReportSale * DM;
public:		// User declarations
		__fastcall TFormaReportReal(TComponent* Owner);

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
extern PACKAGE TFormaReportReal *FormaReportReal;
//---------------------------------------------------------------------------
#endif
