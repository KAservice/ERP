//---------------------------------------------------------------------------

#ifndef UFormaReportSagrHotelH
#define UFormaReportSagrHotelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Mask.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprCatNom.h"
#include "UPrintFormReportSagrHotel.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormaReportSagrHotel : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonClose;
        TButton *ButtonCreate;
        TDateTimePicker *DateNach;
        TDateTimePicker *DateCon;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TIBTransaction *IBTr;
        TIBQuery *IBQCatNom;
        TIntegerField *IBQCatNomID_CATNOM;
        TIntegerField *IBQCatNomIDNOM_CATNOM;
        TIBStringField *IBQCatNomNAME_CATNOM;
        TIntegerField *IBQCatNomKOL_CATNOM;
        TLabel *Label4;
        TDBEdit *NameCatNomDBEdit;
        TDataSource *DataSourceCatNom;
        TButton *ButtonOpenCatNom;
        TIBQuery *IBQNom;
        TDataSource *DataSource1;
        TIntegerField *IBQNomID_NOMHOT;
        TIntegerField *IBQNomIDCAT_NOMHOT;
        TIBStringField *IBQNomNAME_NOMHOT;
        TIntegerField *IBQNomKOLM_NOMHOT;
        TIBStringField *IBQNomNAME_CATNOM;
        TIBQuery *CatNom;
        TIntegerField *CatNomID_CATNOM;
        TIntegerField *CatNomIDNOM_CATNOM;
        TIBStringField *CatNomNAME_CATNOM;
        TIntegerField *CatNomKOL_CATNOM;
        TIBQuery *RegBron;
        TIntegerField *RegBronID_RGBRON;
        TIntegerField *RegBronIDZBRON_RGBRON;
        TIntegerField *RegBronIDPLAT_RGBRON;
        TIntegerField *RegBronIDGOST_RGBRON;
        TIntegerField *RegBronIDNOMER_RGBRON;
        TDateTimeField *RegBronPOSNACH_RGBRON;
        TDateTimeField *RegBronPOSCON_RGBRON;
        TSmallintField *RegBronKOLMEST_RGBRON;
        TSmallintField *RegBronACTIVE_RGBRON;
        TIBQuery *RegRasm;
        TIntegerField *RegRasmID_RGRASM;
        TIntegerField *RegRasmIDZRASM_RGRASM;
        TIntegerField *RegRasmIDPLAT_RGRASM;
        TIntegerField *RegRasmIDGOST_RGRASM;
        TIntegerField *RegRasmIDNOMER_RGRASM;
        TDateTimeField *RegRasmPOSNACH_RGRASM;
        TDateTimeField *RegRasmPOSCON_RGRASM;
        TSmallintField *RegRasmKOLMEST_RGRASM;
        TSmallintField *RegRasmACTIVE_RGRASM;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonOpenCatNomClick(TObject *Sender);
        void __fastcall ButtonCreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaReportSagrHotel(TComponent* Owner);


        int IdCatNom;
        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TFormaSpiskaSprCatNom *SpisokCatNom;

        TNotifyEvent FOnCloseForm;
        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborCatNom, NO} EditRekvisit;
        void UpdateForm();
        void OpenFormSpiskaSprCatNom(void);

        int numRow;
        int numCol;
        int porNumStr;
        double Sum;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportSagrHotel *FormaReportSagrHotel;
//---------------------------------------------------------------------------
#endif
