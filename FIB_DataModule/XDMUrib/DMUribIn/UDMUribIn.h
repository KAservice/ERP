//---------------------------------------------------------------------------

#ifndef UDMUribInH
#define UDMUribInH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include "UDMXTableIsm.h"
#include "UDMXDataOut.h"
#include "UDMXFieldBase.h"
#include "UDMXTableBase.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <oxmldom.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMUribIn : public TDataModule
{
__published:	// IDE-managed Components
        TXMLDocument *xml;
	TIBQuery *IBQ122;
	TIBTransaction *IBTr22;
	TIBTransaction *IBTr122;
	TIBQuery *IBQ222;
	TIBQuery *IBQ322;
	TIBQuery *IBQ422;
	TpFIBQuery *IBQ1;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTr1;
	TpFIBQuery *IBQ2;
	TpFIBQuery *IBQ3;
	TpFIBQuery *IBQ4;
	TpFIBDataSet *TableDoc;
	TDateTimeField *TableDocPOSDOC;
	TIntegerField *TableDocIDDOC;
	TStringField *TableDocTDOC;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMUribIn(TComponent* Owner);

        int IdBase;
        int IdMessage;
        AnsiString GIDMessage;
        AnsiString NameBase;
        AnsiString PrefiksBase;
        //String FileNameXML;
        //String CatalogFile;

        AnsiString NameUser;
        AnsiString PasswordUser;

        int kol_rec;
		bool EnableOutProtocol;
		
        TNotifyEvent EventNextRecord;
        TNotifyEvent EventFirstRecord;
        int *lpKolRecord;

        String CommaToPixel(String value);
        double StringToFloatComma(String value);




        //загрузка из XML файла -------------------------------------------
        void UpdateDataInfBase(AnsiString full_name_file_xml);
        void UpdateInfBase(AnsiString text_xml);
        _di_IXMLNode xml_base;

        void InsertRecord(_di_IXMLNode xml_rec);
        void EditRecord(_di_IXMLNode xml_rec);
        void DeleteRecord(_di_IXMLNode xml_rec);

        int GetValueFieldID(String name_field_id,
                                 String name_table,
                                 String name_field_gid,
                                 String value_field_gid) ;

        bool CheckFK(String name_field);
        bool CheckDrob(String name_field);
        String GetIDFK(String name_field, String gid, _di_IXMLNode xml_field);
        String CreateTextZaprosInsert(_di_IXMLNode xml_rec);
        String CreateTextZaprosEdit(_di_IXMLNode xml_rec, String name_field_gid, String value_field_gid);
        void OutProtocol(String str);
        bool CheckFieldForEdit(String name_field);
        bool CheckFieldForInsert(String name_field);


        TDMXTableBase *DMXTableBase;
        TDMXFieldBase *DMXFieldBase;

        void ProveritPosledProvDoc(_di_IXMLNode xml_rec);

        int NumberRecord;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribIn *DMUribIn;
//---------------------------------------------------------------------------
#endif
