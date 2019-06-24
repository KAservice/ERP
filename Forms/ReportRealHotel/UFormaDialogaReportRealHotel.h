//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportRealHotelH
#define UFormaDialogaReportRealHotelH
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
#include "UPrintFormAll.h"
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
        TIBQuery *IBQGrp;
        TIBTransaction *IBTr;
        TIBQuery *IBQEl;
        TIBStringField *IBQGrpNAMEGN;
        TIBBCDField *IBQGrpSUMMA;
        TFloatField *IBQGrpSUMKOL;
        TIntegerField *IBQGrpIDGN;
        TIBStringField *IBQElNAMENOM;
        TIBBCDField *IBQElSUMMA;
        TFloatField *IBQElSUMKOL;
        TIBStringField *IBQElNAMEED;
        TEdit *NameKlientEdit;
        TButton *ButtonViborKlienta;
        TLabel *Label5;
        TIBQuery *IBQSkl;
        TIBQuery *IBQKl;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonViborKlientaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportRealRest(TComponent* Owner);
       int IdSkl;
       int IdKlient;

       BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(MESSAGE_READY, TMessage,EndEdit)
       END_MESSAGE_MAP(TComponent)
        void __fastcall EndEdit(TMessage&Message);

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

        void ReportSklad(TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportKlient( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportGrpNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl);
        void ReportNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl, int idGrp);

        void OutputStringSklad( TPrintFormAll *prForm);
        void OutputStringKlient(TPrintFormAll *prForm);
        void OutputStringGrp(TPrintFormAll *prForm);
        void OutputString(TPrintFormAll *prForm);
        void OutputZagolovokReport(TPrintFormAll *prForm);
        void OutputPodavalReport(TPrintFormAll *prForm);
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
