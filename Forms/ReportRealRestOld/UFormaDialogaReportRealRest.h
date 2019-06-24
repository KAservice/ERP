//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportRealRestH
#define UFormaDialogaReportRealRestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprKlient.h"
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
class TFormaDialogaReportRealRest : public TForm
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
        TEdit *NameKlientEdit;
        TButton *ButtonViborKlienta;
        TLabel *Label5;
        TBitBtn *BitBtnNachPerioda;
        TLabel *PosConLabel;
        TLabel *PosNachLabel;
        TLabel *Label6;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQSkl;
	TpFIBDataSet *IBQKl;
	TpFIBDataSet *IBQGrp;
	TFIBStringField *IBQGrpNAMEGN;
	TFIBIntegerField *IBQGrpIDGN;
	TFIBBCDField *IBQGrpSUMMA;
	TFIBFloatField *IBQGrpSUMKOL;
	TpFIBDataSet *IBQEl;
	TFIBStringField *IBQElNAMENOM;
	TFIBStringField *IBQElNAMEED;
	TFIBBCDField *IBQElSUMMA;
	TFIBFloatField *IBQElSUMKOL;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonViborKlientaClick(TObject *Sender);
        void __fastcall BitBtnNachPeriodaClick(TObject *Sender);
        void __fastcall BitBtnConPeriodaClick(TObject *Sender);
        void __fastcall DateNachChange(TObject *Sender);
        void __fastcall DateConChange(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportRealRest(TComponent* Owner);
       int IdSkl;
       int IdKlient;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborSklad,ViborKlient, NO} EditRekvisit;

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

        TFormaSpiskaSprKlient *FormaSpiskaSprKlient;
        void VibratKlienta(void);

        void ReportSklad(TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportKlient( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportGrpNom( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportNom( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl, int idGrp);

        void OutputStringSklad( TSheetEditor *prForm);
        void OutputStringKlient(TSheetEditor *prForm);
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
extern PACKAGE TFormaDialogaReportRealRest *FormaDialogaReportRealRest;
//---------------------------------------------------------------------------
#endif
