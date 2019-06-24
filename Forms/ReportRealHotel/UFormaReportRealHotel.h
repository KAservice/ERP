//---------------------------------------------------------------------------

#ifndef UFormaReportRealHotelH
#define UFormaReportRealHotelH
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
#include "UFormaSpiskaSprGrpNom.h"
//---------------------------------------------------------------------------
class TFormaReportRealHotel : public TForm
{
__published:	// IDE-managed Components
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
        TCheckBox *PoDateCheckBox;
        TCheckBox *AllSkladCheckBox;
        TCheckBox *AllKlientCheckBox;
        TCheckBox *RasvorotSkladCheckBox;
        TCheckBox *RasvorotKlientCheckBox;
        TButton *ButtonCreateReport;
        TIBQuery *IBQ;
        TEdit *NameGrpNomEdit;
        TButton *OpenGrpNomButton;
        TLabel *Label6;
        TLabel *Label7;
        TButton *ClearViborGrpNomButton;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonViborKlientaClick(TObject *Sender);
        void __fastcall ButtonCreateReportClick(TObject *Sender);
        void __fastcall AllSkladCheckBoxClick(TObject *Sender);
        void __fastcall AllKlientCheckBoxClick(TObject *Sender);
        void __fastcall OpenGrpNomButtonClick(TObject *Sender);
        void __fastcall ClearViborGrpNomButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaReportRealHotel(TComponent* Owner);
       int IdSkl;
       int IdKlient;
       int IdGrpNom;

        TNotifyEvent FOnCloseForm;
        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborSklad,ViborKlient, ViborGrpNom, NO} EditRekvisit;

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


        TFormaSpiskaSprGrpNom * SprGrpNom;
        

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
        
        int NumberStrSklad;
        double SumSklad;

        int NumberStrKlient;
        double SumKlient;

        int NumberStrGrp;
        double SumGrp;


        void CreateReport(TPrintFormAll *PrintForm, TDateTime nach, TDateTime con);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportRealHotel *FormaReportRealHotel;
//---------------------------------------------------------------------------
#endif
