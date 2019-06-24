//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportOCBOstNomH
#define UFormaDialogaReportOCBOstNomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprSklad.h"
//#include "UPrintFormAll.h"
#include "USheetEditor.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaDialogaReportOCBOstNom : public TForm
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
        TBitBtn *BitBtnConPerioda;
        TBitBtn *BitBtnNachPerioda;
        TLabel *PosNachLabel;
        TLabel *PosConLabel;
        TLabel *GrPosledLabel;
	TpFIBDataSet *IBQSkl;
	TpFIBDataSet *IBQGrp;
	TpFIBDataSet *IBQEl;
	TpFIBTransaction *IBTr;
	TFIBStringField *IBQSklNAMESKLAD;
	TFIBBCDField *IBQSklPRIHODKOL;
	TFIBBCDField *IBQSklPRIHODSUM;
	TFIBBCDField *IBQSklRASHODKOL;
	TFIBBCDField *IBQSklRASHODSUM;
	TFIBBCDField *IBQSklPR_DOCON_KOL;
	TFIBBCDField *IBQSklPR_DOCON_SUM;
	TFIBBCDField *IBQSklRAS_DOCON_KOL;
	TFIBBCDField *IBQSklRAS_DOCON_SUM;
	TFIBBCDField *IBQSklOSTKOL;
	TFIBBCDField *IBQSklOSTSUM;
	TFIBBCDField *IBQSklNACHOSTKOL;
	TFIBBCDField *IBQSklNACHOSTSUM;
	TFIBBCDField *IBQSklCONOSTKOL;
	TFIBBCDField *IBQSklCONOSTSUM;
	TFIBStringField *IBQGrpNAMEGN;
	TFIBBCDField *IBQGrpPRIHODKOL;
	TFIBBCDField *IBQGrpPRIHODSUM;
	TFIBBCDField *IBQGrpRASHODKOL;
	TFIBBCDField *IBQGrpRASHODSUM;
	TFIBBCDField *IBQGrpPR_DOCON_KOL;
	TFIBBCDField *IBQGrpPR_DOCON_SUM;
	TFIBBCDField *IBQGrpRAS_DOCON_KOL;
	TFIBBCDField *IBQGrpRAS_DOCON_SUM;
	TFIBBCDField *IBQGrpOSTKOL;
	TFIBBCDField *IBQGrpOSTSUM;
	TFIBBCDField *IBQGrpNACHOSTKOL;
	TFIBBCDField *IBQGrpNACHOSTSUM;
	TFIBBCDField *IBQGrpCONOSTKOL;
	TFIBBCDField *IBQGrpCONOSTSUM;
	TFIBStringField *IBQElNAME;
	TFIBStringField *IBQElNAMEED;
	TFIBBCDField *IBQElPRIHODKOL;
	TFIBBCDField *IBQElPRIHODSUM;
	TFIBBCDField *IBQElRASHODKOL;
	TFIBBCDField *IBQElRASHODSUM;
	TFIBBCDField *IBQElPR_DOCON_KOL;
	TFIBBCDField *IBQElPR_DOCON_SUM;
	TFIBBCDField *IBQElRAS_DOCON_KOL;
	TFIBBCDField *IBQElRAS_DOCON_SUM;
	TFIBBCDField *IBQElOSTKOL;
	TFIBBCDField *IBQElOSTSUM;
	TFIBBCDField *IBQElNACHOSTKOL;
	TFIBBCDField *IBQElNACHOSTSUM;
	TFIBBCDField *IBQElCONOSTKOL;
	TFIBBCDField *IBQElCONOSTSUM;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TFIBBCDField *IBQSklIDSKLAD;
	TFIBBCDField *IBQGrpIDGN;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall BitBtnNachPeriodaClick(TObject *Sender);
        void __fastcall BitBtnConPeriodaClick(TObject *Sender);
        void __fastcall DateNachChange(TObject *Sender);
        void __fastcall DateConChange(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportOCBOstNom(TComponent* Owner);
       int IdSkl;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborSklad, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

        TFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);

		void ReportSklad(TSheetEditor *prForm, __int64 idSkl, bool allSkl);
		void ReportGrpNom( TSheetEditor *prForm, __int64 idSkl, bool allSkl);
        void ReportNom( TSheetEditor *prForm, __int64 idSkl, bool allSkl, __int64 idGrp);

        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputStringSklad( TSheetEditor *prForm);
        void OutputStringGrp(TSheetEditor *prForm);
        void OutputString(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;

        float AllNachOst;
        float AllPrihod;
        float AllRashod;
        float AllConOst;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportOCBOstNom *FormaDialogaReportOCBOstNom;
//---------------------------------------------------------------------------
#endif
