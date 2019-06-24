//---------------------------------------------------------------------------

#ifndef UFormaReportKalkKartaH
#define UFormaReportKalkKartaH
//---------------------------------------------------------------------------


#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMFibConnection.h"
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportKalkKarta : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
	TpFIBDataSet *El1;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *TypePrice;
	TFIBBCDField *El1SUMREAL;
	TFIBBCDField *El1SEBREAL;
	TFIBBCDField *El1RESREAL;
	TFIBBCDField *El1KOLREAL;
	TFIBBCDField *El1KOLOTRREAL;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TpFIBDataSet *IBQSebProd;
	TFIBBCDField *GrpSEBPROD;
	TFIBBCDField *ElSEBPROD;
	TFIBBCDField *ElKOLPROD;
	TFIBBCDField *IBQSebProdSEBPROD;
	TFIBBCDField *IBQSebProdKOLPROD;
	TFIBBCDField *IBQSebProdKOLOTRPROD;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxComboBox *TypePriceComboBox;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TFIBBCDField *TypePriceID_TPRICE;
	TFIBBCDField *GrpIDGN;
	TFIBBCDField *ElIDNOM;
	TFIBBCDField *IBQSebProdIDNOM;
	TFIBBCDField *El1IDNOM;
	TAction *ActionClose;
	TFIBWideStringField *TypePriceNAME_TPRICE;
	TFIBWideStringField *GrpNAMEGN;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElNAMEED;
	TFIBWideStringField *IBQSebProdNAMENOM;
	TFIBWideStringField *IBQSebProdNAMEED;
	TFIBWideStringField *El1NAMENOM;
	TFIBWideStringField *El1NAMEED;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TFormaReportKalkKarta(TComponent* Owner);

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

        enum  {ER_NoRekv,ViborSklad, ViborNom, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);
		IFormaSpiskaSprNom *Nom;
		void OpenFormSpiskaSprNom(void);

		void OutputStringSebProd(TSheetEditor *prForm);
		void CreateReportPoProd(__int64 idnom, TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		int porNumStrGrp;
		double SebProdReport;
		double OtrSebProdReport;


		__int64 IdSkl;
		__int64 IdTypePrice;
		__int64 IdNom;
		AnsiString NameNom;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportKalkKarta *FormaReportKalkKarta;
//---------------------------------------------------------------------------
#endif
