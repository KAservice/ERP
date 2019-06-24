//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportOCBRegVSRaschH
#define UFormaDialogaReportOCBRegVSRaschH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprKlient.h"
#include "UPrintFormAll.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormaDialogaReportOCBVSRasch : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonRun;
        TLabel *Label1;
        TDateTimePicker *DateNach;
        TDateTimePicker *DateCon;
        TLabel *Label2;
        TLabel *Label3;
        TButton *ButtonClose;
        TEdit *NameKlientEdit;
        TButton *ButtonViborSklad;
        TLabel *Label4;
        TIBTransaction *IBTr;
        TIBQuery *IBQKl;
        TIBQuery *IBQDoc;
        TIBStringField *IBQKlNAMEKLIENT_PROC;
        TIntegerField *IBQKlIDKLIENT_PROC;
        TIBBCDField *IBQKlPRIHODSUM;
        TIBBCDField *IBQKlRASHODSUM;
        TIBBCDField *IBQKlNACHOSTSUM;
        TIBBCDField *IBQKlCONOSTSUM;
        TDateTimeField *IBQDocPOSDOC_VSRASCH_DV;
        TIBBCDField *IBQDocSUM_VSRASCH_DV;
        TIntegerField *IBQDocNUMDOC;
        TIBStringField *IBQDocTDOC;
        TSmallintField *IBQDocTDV_VSRASCH_DV;
        TBitBtn *BitBtnNachPerioda;
        TBitBtn *BitBtnConPerioda;
        TLabel *PosNachLabel;
        TLabel *PosConLabel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall DateNachChange(TObject *Sender);
        void __fastcall DateConChange(TObject *Sender);
        void __fastcall BitBtnNachPeriodaClick(TObject *Sender);
        void __fastcall BitBtnConPeriodaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportOCBVSRasch(TComponent* Owner);
       int IdKlient;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborKlient, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца

        TFormaSpiskaSprKlient * FormaSpiskaSprKlient;
        void OpenFormSpiskaSprKlient(void);

        void ReportKlient(TPrintFormAll *prForm, int idKlient);
        void ReportDoc( TPrintFormAll *prForm, int idKlient);

        void OutputZagolovokReport(TPrintFormAll *prForm);
        void OutputStringKlient( TPrintFormAll *prForm);
        void OutputStringDoc(TPrintFormAll *prForm);
        void OutputPodavalReport(TPrintFormAll *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double AllNachOst;
        double AllPrihod;
        double AllRashod;
        double AllConOst;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportOCBVSRasch *FormaDialogaReportOCBVSRasch;
//---------------------------------------------------------------------------
#endif
