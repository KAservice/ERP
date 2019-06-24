//---------------------------------------------------------------------------

#ifndef UForma1CUSNImportH
#define UForma1CUSNImportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//-------------------------------------------------
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include <IBSQL.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TForma1CUSNImport : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TToolBar *ToolBar1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *LabelFileName;
        TButton *ButtonOpenFile;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel6;
        TPanel *Panel2;
        TPageControl *PageControl1;
        TTabSheet *TabSheet2;
        TRichEdit *RichEdit1;
        TProgressBar *ProgressBar1;
        TXMLDocument *xml;
        TButton *ButtonZagr;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonZagrClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForma1CUSNImport(TComponent* Owner);

        String FileNameXML;
        String CatalogFile;

        void ImportSGRPNOM(_di_IXMLNode spr);
        void ImportSTPRICE(_di_IXMLNode spr);
        void ImportSSKLAD(_di_IXMLNode spr);
        void ImportSNOM(_di_IXMLNode spr);
        void ImportSPRICE(_di_IXMLNode spr);


        void ImportDoc(_di_IXMLNode usel_document);
        void ImportDocPRN(_di_IXMLNode usel_doc);
        void ImportDocPER(_di_IXMLNode usel_doc);
        void ImportDocINV(_di_IXMLNode usel_doc);

        String FloatToStringComma(double value);
        double StringToFloatComma(String value);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma1CUSNImport *Forma1CUSNImport;
//---------------------------------------------------------------------------
#endif
