//---------------------------------------------------------------------------

#ifndef UFormaObmenExportAllSprH
#define UFormaObmenExportAllSprH
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
#include "UFormaSpiskaSprInfBase.h"
#include "UDMXTableIsm.h"
#include "UDMXDataOut.h"
#include "UDMXFieldBase.h"
#include "UDMXTableBase.h"
#include "UDMSprObmenTypeDoc.h"
#include "UDMSprObmenSklad.h"
//---------------------------------------------------------------------------
class TFormaObmenExportAllSpr : public TForm
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
        TButton *ButtonVigr;
        TButton *ButtonViborBase;
        TLabel *NameBaseLabel;
        TButton *ButtonClose;
        TIBQuery *IBQ;
        TIBTransaction *IBTr1;
        TIBQuery *IBQ2;
        TLabel *LabelFileNameOut;
        TIBTransaction *IBTr2;
        TCheckBox *CheckBoxOutProtocol;
        TLabel *LabelNameTable;
        TLabel *LabelZagrIsm;
        TLabel *LabelTotalIsm;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonVigrClick(TObject *Sender);
        void __fastcall ButtonViborBaseClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFormaObmenExportAllSpr(TComponent* Owner);

        String FileNameXML;
        String CatalogFile;

        String FloatToStringComma(double value);
        double StringToFloatComma(String value);

        //заполение таблицы выходных данных ----------------------------
        TDMXTableIsm *TableIsm;
        TDMXDataOut * DataOut;
        TDMSprObmenTypeDoc * DMTypeDoc;
        TDMSprObmenSklad  * DMSprObmenSklad;


        void SaveFileXML(String str);
        String FormatForXML(String s);

        //создание XML файла -------------------------------------------
        void CreateXMLDoc(int id_base);
        void OutputTableInXMLFile(String table_name);
        void OutputFKInXMLFile(String name_field, int value_field );

        String GetNameGid(String name_table);

        //--------------------------------------------------------------
        HANDLE IdRodForm;
        HANDLE IdDochForm;

        bool Vibor;
        bool OutReady;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborBase, NO} ViborRekvisit;
        TFormaSpiskaSprInfBase * SpisokBase;
        void OpenFormSpiskaSprInfBase(void);

        int IdBase;
        String PrefiksBase;
        String FileNameOut;
        String CatalogObmena;


        TDMXTableBase *DMXTableBase;
        TDMXFieldBase *DMXFieldBase;

        bool CheckFieldForOutput(String name_field, String name_table);
        
        void OutProtocol(String str);

        void OutputSpr(String name_table);
        bool NoOutputEd;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaObmenExportAllSpr *FormaObmenExportAllSpr;
//---------------------------------------------------------------------------
#endif
