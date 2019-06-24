//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportOtrSpisNomH
#define UFormaDialogaReportOtrSpisNomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprSklad.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//#include "UPrintFormAll.h"
#include "USheetEditor.h"
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaDialogaReportOtrSpis : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonRun;
        TLabel *Label1;
        TDateTimePicker *DateNach;
        TDateTimePicker *DateCon;
        TLabel *Label2;
        TLabel *Label3;
        TButton *ButtonClose;
        TEdit *NameSkladEdit;
        TButton *ButtonViborSklad;
        TLabel *Label4;
        TLabel *LabelDoc;
        TButton *ButtonReportPoDoc;
        TComboBox *TypePriceComboBox;
        TLabel *Label5;
        TBitBtn *BitBtnNachPerioda;
        TBitBtn *BitBtnConPerioda;
        TLabel *PosNachLabel;
        TLabel *PosConLabel;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TpFIBDataSet *Price;
	TpFIBDataSet *TypePrice;
	TFIBStringField *GrpNAMEGN;
	TFIBIntegerField *GrpIDGN;
	TFIBBCDField *GrpSUMKOL;
	TFIBFloatField *GrpSUMM;
	TFIBStringField *ElNAMENOM;
	TFIBStringField *ElNAMEED;
	TFIBBCDField *ElSUMKOL;
	TFIBBCDField *ElZNACH_PRICE;
	TFIBIntegerField *PriceID_PRICE;
	TFIBIntegerField *PriceIDNOM_PRICE;
	TFIBIntegerField *PriceIDTYPE_PRICE;
	TFIBBCDField *PriceZNACH_PRICE;
	TFIBStringField *PriceGID_SPRICE;
	TFIBIntegerField *TypePriceID_TPRICE;
	TFIBStringField *TypePriceNAME_TPRICE;
	TFIBStringField *TypePriceGID_STPRICE;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonReportPoDocClick(TObject *Sender);
        void __fastcall TypePriceComboBoxChange(TObject *Sender);
        void __fastcall DateNachChange(TObject *Sender);
        void __fastcall DateConChange(TObject *Sender);
        void __fastcall BitBtnNachPeriodaClick(TObject *Sender);
        void __fastcall BitBtnConPeriodaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportOtrSpis(TComponent* Owner);
       int IdSkl;
       int IdTypePrice;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborSklad, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца

        TFormaSpiskaSprSklad * SpisokSklad;
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
        

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportOtrSpis *FormaDialogaReportOtrSpis;
//---------------------------------------------------------------------------
#endif
