//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportPriceH
#define UFormaDialogaReportPriceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprPodr.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//#include "UPrintFormAll.h"
#include "USheetEditor.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDialogaReportPrice : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label4;
	TpFIBDataSet *GrpBV;
	TpFIBDataSet *NomBV;
	TpFIBDataSet *Ed;
	TpFIBTransaction *IBTr;
	TFIBStringField *GrpBVNAME_GBVNOM;
	TFIBStringField *NomBVFNAMENOM;
	TFIBStringField *EdNAMEED;
	TFIBBCDField *EdKFED;
	TFIBBCDField *EdZNACH_PRICE;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButtonEdit *NamePodrEdit;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonCreate;
	TFIBBCDField *GrpBVID_GBVNOM;
	TFIBBCDField *GrpBVIDGRP_GBVNOM;
	TFIBBCDField *GrpBVIDPOD_GBVNOM;
	TFIBBCDField *NomBVIDNOM;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NamePodrEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaDialogaReportPrice(TComponent* Owner);
	   __int64 IdPodr;
	   __int64 IdTypePrice;
        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborPodr, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
        __int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

        TFormaSpiskaSprPodr * SpisokPodr;
        void OpenFormSpiskaSprPodr(void);


        void OutputStringGrp(TSheetEditor *prForm);
        void OutputStringNom(TSheetEditor *prForm);
        void OutputStringEd(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);
        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportPrice *FormaDialogaReportPrice;
//---------------------------------------------------------------------------
#endif
