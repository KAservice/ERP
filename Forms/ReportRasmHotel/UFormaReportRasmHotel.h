//---------------------------------------------------------------------------

#ifndef UFormaReportRasmHotelH
#define UFormaReportRasmHotelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UPrintFormAll.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormaReportRasmHotel : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonRun;
        TLabel *Label1;
        TDateTimePicker *DateNach;
        TDateTimePicker *DateCon;
        TLabel *Label2;
        TLabel *Label3;
        TButton *ButtonClose;
        TIBTransaction *IBTr;
        TIBQuery *IBQRegRasm;
        TIntegerField *IBQRegRasmID_RGRASM;
        TIntegerField *IBQRegRasmIDZRASM_RGRASM;
        TIntegerField *IBQRegRasmIDPLAT_RGRASM;
        TIntegerField *IBQRegRasmIDGOST_RGRASM;
        TIntegerField *IBQRegRasmIDNOMER_RGRASM;
        TDateTimeField *IBQRegRasmPOSCON_RGRASM;
        TSmallintField *IBQRegRasmKOLMEST_RGRASM;
        TSmallintField *IBQRegRasmACTIVE_RGRASM;
        TIBStringField *IBQRegRasmNAME_NOMHOT;
        TIntegerField *IBQRegRasmKOLM_NOMHOT;
        TIBStringField *IBQRegRasmNAMEKLIENT;
        TIBStringField *IBQRegRasmNAME_ZRASM;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonRunClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaReportRasmHotel(TComponent* Owner);

        TNotifyEvent FOnCloseForm;
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


        void ReportPoNomeramHotel(TPrintFormAll *prForm);

        void OutputZagolovokReport(TPrintFormAll *prForm);
        void OutputStringNomer( TPrintFormAll *prForm);
        void OutputStringGost(TPrintFormAll *prForm);
        void OutputPodavalReport(TPrintFormAll *prForm);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportRasmHotel *FormaReportRasmHotel;
//---------------------------------------------------------------------------
#endif
