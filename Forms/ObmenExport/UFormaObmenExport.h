//---------------------------------------------------------------------------

#ifndef UFormaObmenExportH
#define UFormaObmenExportH
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
class TFormaObmenExport : public TForm
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
        TButton *ButtonCreateData;
        TButton *ButtonClose;
        TIBTransaction *IBTr;
        TIBQuery *IBQ;
        TIBTransaction *IBTr1;
        TIBQuery *IBQ2;
        TLabel *LabelFileNameOut;
        TIBTransaction *IBTr2;
        TIBQuery *TableFields;
        TIBQuery *TableFK;
        TIBTransaction *IBTrSys;
        TDataSource *DataSource1;
        TIBStringField *TableFieldsRDBFIELD_NAME;
        TIBStringField *TableFieldsRDBRELATION_NAME;
        TIBStringField *TableFieldsRDBFIELD_SOURCE;
        TSmallintField *TableFieldsRDBFIELD_SCALE;
        TIBQuery *TablePK;
        TIBStringField *TablePKFIELD_NAME;
        TIBStringField *TablePKTABLE_NAME;
        TIBDataSet *TableDataOut;
        TButton *ButtonStrBase;
        TIBStringField *TableFKRDBFIELD_NAME;
        TIBStringField *TableFKRDBFIELD_SOURCE;
        TIBStringField *TableFKRDBFIELD_NAME3;
        TIBStringField *TableFKRDBRELATION_NAME2;
        TButton *Button1;
        TSmallintField *TableFieldsRDBFIELD_TYPE;
        TIBQuery *DocAll;
        TIBQuery *Doc;
        TIBStringField *DocAllTDOC;
        TIntegerField *DocAllIDSKLDOC;
        TIBQuery *DocT;
        TIntegerField *TableDataOutID_XDATA_OUT;
        TIBStringField *TableDataOutGID_XDATA_OUT;
        TIntegerField *TableDataOutIDTISM_XDATA_OUT;
        TIntegerField *TableDataOutIDBASE_XDATA_OUT;
        TIntegerField *TableDataOutIDMESSAGE_XDATA_OUT;
        TIntegerField *TableDataOutID_XTISM;
        TIBStringField *TableDataOutGID_XTISM;
        TDateTimeField *TableDataOutPOS_XTISM;
        TIBStringField *TableDataOutNAMETAB_XTISM;
        TIntegerField *TableDataOutIDREC_XTISM;
        TIntegerField *TableDataOutTYPEOB_XTISM;
        TIntegerField *TableDataOutIDUSER_XTISM;
        TIBStringField *TableDataOutPRBASE_XTISM;
        TIntegerField *TableDataOutOPER_XTISM;
        TCheckBox *CheckBoxOutProtocol;
        TLabel *LabelTotalIsm;
        TLabel *LabelZagrIsm;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonVigrClick(TObject *Sender);
        void __fastcall ButtonViborBaseClick(TObject *Sender);
        void __fastcall ButtonCreateDataClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ButtonStrBaseClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFormaObmenExport(TComponent* Owner);

        String FileNameXML;
        String CatalogFile;

        String FloatToStringComma(double value);
        double StringToFloatComma(String value);

        //заполение таблицы выходных данных ----------------------------
        TDMXTableIsm *TableIsm;
        TDMXDataOut * DataOut;
        TDMSprObmenTypeDoc * DMTypeDoc;
        TDMSprObmenSklad  * DMSprObmenSklad;
        void CreateDataOutTable(int id_base);

        bool CheckDocForTypeDoc(String type_doc);
        bool CheckDocForSklad(int id_sklad);


        bool CheckGALLDOC(void);
        bool CheckDPER(void);
        bool CheckDPERT(void);
        bool CheckDCHK(void);
        bool CheckDCHKT(void);



        void AddDocInDataTable(void);
        void AddSprInDataTable(void);


        void SaveFileXML(String str);
        String FormatForXML(String s);

        //создание XML файла -------------------------------------------
        void CreateXMLDoc(int id_base);

        void OutputSprInXMLFile(String table_name, int id_record);
        void OutputDocInXMLFile(String table_name, int id_record);
        void OutputTableInXMLFile(String table_name, int id_record );
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
        int StartIDTableIsm;
        String PrefiksBase;
        String FileNameOut;
        String CatalogObmena;


        TDMXTableBase *DMXTableBase;
        TDMXFieldBase *DMXFieldBase;

        bool CheckFieldForOutput(String name_field, String name_table);
        
        void OutProtocol(String str);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaObmenExport *FormaObmenExport;
//---------------------------------------------------------------------------
#endif
