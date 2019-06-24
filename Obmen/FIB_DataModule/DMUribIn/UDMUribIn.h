//---------------------------------------------------------------------------

#ifndef UDMUribInH
#define UDMUribInH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//#include <oxmldom.hpp>
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
	TpFIBQuery *QueryRecord;
	TpFIBTransaction *TrRecord;
	TpFIBQuery *QueryUpdateRecord;
	TpFIBTransaction *TrUpdateRecord;
	TpFIBQuery *AddDelRecordInXTism;
	TpFIBTransaction *TrXTism;
	TpFIBQuery *AddRecordInXTism;
	TXMLDocument *xml;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


bool OutputPodrProtokol;

public:		// User declarations
        __fastcall TDMUribIn(TComponent* Owner);

		__int64 IdBase;
		UnicodeString NameBase;

		UnicodeString NameUser;
		UnicodeString PasswordUser;

        int kol_rec;
		bool EnableOutProtocol;
		

        //загрузка из XML файла -------------------------------------------
		void UpdateDataInfBase(UnicodeString full_name_file_xml);
		void UpdateInfBase(UnicodeString text_xml);
        _di_IXMLNode xml_base;

        void InsertRecord(_di_IXMLNode xml_rec);
        void EditRecord(_di_IXMLNode xml_rec);
		void DeleteRecord(_di_IXMLNode xml_rec);
		void InputKvitan(_di_IXMLNode xml_rec);
		void RunComandCancelDvRegDoc(_di_IXMLNode xml_rec);
		void RunComandDvRegDoc(_di_IXMLNode xml_rec);

		UnicodeString GetTypeDoc(_di_IXMLNode xml_rec);
		UnicodeString GetNameProcedureCancelDvReg(UnicodeString type_doc);
		UnicodeString GetNameProcedureDvReg(UnicodeString type_doc);

		UnicodeString GetTypeDocRemontSystem(_di_IXMLNode xml_rec);
		UnicodeString GetNameProcedureCancelDvRegRemontSystem(UnicodeString type_doc);
		UnicodeString GetNameProcedureDvRegRemontSystem(UnicodeString type_doc);

		UnicodeString GetTypeDocHotelSystem(_di_IXMLNode xml_rec);
		UnicodeString GetNameProcedureCancelDvRegHotelSystem(UnicodeString type_doc);
		UnicodeString GetNameProcedureDvRegHotelSystem(UnicodeString type_doc);

//        int GetValueFieldID(String name_field_id,
//								 String name_table,
//								 String name_field_gid,
//								 String value_field_gid) ;

		bool CheckFK(UnicodeString name_field);
		bool CheckDrob(UnicodeString name_field);
//        String GetIDFK(String name_field, String gid, _di_IXMLNode xml_field);
		UnicodeString CreateTextZaprosInsert(_di_IXMLNode xml_rec);
		UnicodeString CreateTextZaprosInsertXTISM(_di_IXMLNode xml_rec);
		UnicodeString CreateTextZaprosEdit(_di_IXMLNode xml_rec);
		void OutProtocol(UnicodeString str);
		bool CheckFieldForEdit(UnicodeString name_field);
        bool CheckFieldForInsert(UnicodeString name_field);




		int NumberRecord;

        TNotifyEvent EventNextRecord;
        TNotifyEvent EventFirstRecord;
        int *lpKolRecord;		

};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribIn *DMUribIn;
//---------------------------------------------------------------------------
#endif
