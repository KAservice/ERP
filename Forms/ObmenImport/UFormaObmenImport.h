//---------------------------------------------------------------------------

#ifndef UFormaObmenImportH
#define UFormaObmenImportH
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
//---------------------------------------------------------------------------
class TFormaObmenImport : public TForm
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
        TButton *ButtonVigr;
        TButton *ButtonViborBase;
        TLabel *NameBaseLabel;
        TButton *ButtonClose;
        TIBTransaction *IBTr;
        TIBQuery *IBQ1;
        TIBTransaction *IBTr1;
        TIBQuery *IBQ2;
        TIBQuery *IBQ3;
        TLabel *LabelPrefiksPriemnik;
        TLabel *LabelGID;
        TIBQuery *IBQ4;
        TLabel *LabelZagrIsm;
        TLabel *LabelTotalIsm;
        TCheckBox *CheckBoxOutProtocol;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonVigrClick(TObject *Sender);
        void __fastcall ButtonViborBaseClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFormaObmenImport(TComponent* Owner);

        String FileNameXML;
        String CatalogFile;

        String CommaToPixel(String value);
        double StringToFloatComma(String value);

        //загрузка из XML файла -------------------------------------------
        void UpdateDataInfBase(int id_base);
        _di_IXMLNode xml_base;

        void InsertRecord(_di_IXMLNode xml_rec);
        void EditRecord(_di_IXMLNode xml_rec);
        void DeleteRecord(_di_IXMLNode xml_rec);
       // String GetNameFieldGid(String name_table);
       // String GetValueFieldGid(String name_field_gid, _di_IXMLNode xml_rec ) ;
      //  String GetNameFieldID(String name_table);
        int GetValueFieldID(String name_field_id,
                                 String name_table,
                                 String name_field_gid,
                                 String value_field_gid) ;

        bool CheckFK(String name_field);
        bool CheckDrob(String name_field);
        String GetIDFK(String name_field, String gid, _di_IXMLNode xml_field);
        String CreateTextZaprosInsert(_di_IXMLNode xml_rec);
        String CreateTextZaprosEdit(_di_IXMLNode xml_rec, String name_field_gid, String value_field_gid);
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

        TDMXTableBase *DMXTableBase;
        TDMXFieldBase *DMXFieldBase;
        void OutProtocol(String str);
        bool CheckFieldForEdit(String name_field);
        bool CheckFieldForInsert(String name_field);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaObmenImport *FormaObmenImport;
//---------------------------------------------------------------------------
#endif
