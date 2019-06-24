//---------------------------------------------------------------------------

#ifndef UDMUribOutH
#define UDMUribOutH
//---------------------------------------------------------------------------
#include "UDMXDataOut.h"
//-------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TDMUribOut : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBTransaction *Transaction;
	TpFIBDataSet *XSetupObmen;
	TFIBBCDField *XSetupObmenID_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDTISM_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenALLDOC_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenOUTNAC_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenOUTZPRICE_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenNOEDIT_XSETUP_OBMEN;
	TpFIBDataSet *TableTypePriceForObmen;
	TpFIBDataSet *Price;
	TFIBBCDField *PriceIDTYPE_PRICE;
	TpFIBDataSet *TableBaseForObmen;
	TFIBBCDField *TableTypePriceForObmenID_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenID_XBASE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN;
	TpFIBDataSet *TableIsmFields;
	TFIBBCDField *TableIsmFieldsID_XTISM_FIELDS;
	TFIBBCDField *TableIsmFieldsIDXTISM_XTISM_FIELDS;
	TpFIBQuery *Query;
	TpFIBTransaction *TrUpdate;
	TpFIBQuery *KvitanSetOK;
	TpFIBDataSet *TableKvitan;
	TFIBBCDField *TableKvitanID_XDATA_OUT;
	TFIBBCDField *TableKvitanIDTISM_XDATA_OUT;
	TFIBBCDField *TableKvitanIDBASE_XDATA_OUT;
	TFIBSmallIntField *TableKvitanTYPE_XDATA_OUT;
	TFIBSmallIntField *TableKvitanRESULT_XDATA_OUT;
	TFIBBCDField *TableKvitanIDEXT_DOUT_XDATA_OUT;
	TFIBBCDField *TableKvitanIDEXT_BASE_XDATA_OUT;
	TFIBBCDField *TableKvitanIDEXT_DATAOUT_XTISM;
	TpFIBQuery *SetFirstId;
	TpFIBQuery *TableDataOut;
	TpFIBQuery *TableIsm;
	TFIBWideStringField *TableIsmFieldsFIELD_NAME_XTISM_FIELDS;
	TFIBWideStringField *TableIsmFieldsOLD_VALUE_XTISM_FIELDS;
	TFIBWideStringField *TableIsmFieldsNEW_VALUE_XTISM_FIELDS;
	TFIBSmallIntField *TableIsmFieldsTYPE_XTISM_FIELDS;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


UnicodeString GetTextValueFieldBlob(UnicodeString name_table,
								 UnicodeString name_pk,
								 __int64 value_pk,
								 UnicodeString name_field);

UnicodeString GetTextValueFieldLongString(UnicodeString name_table,
								 UnicodeString name_pk,
								 __int64 value_pk,
								 UnicodeString name_field);


public:		// User declarations
        __fastcall TDMUribOut(TComponent* Owner);

        TDMXDataOut * DMXDataOut;

		//-----------------------
		__int64 IdBaseForObmen;  //внешн€€ база дл€ обмена
		__int64 IdTecBase;       //текуща€ база
		UnicodeString FileNameOut;

		//заполение таблицы выходных данных ----------------------------
		__int64 StartIDTableIsm;

		void AddInDataOutTable(void);
		bool CreateDataOutTable(__int64 id_base);
		bool CheckBaseRecordForObmen(__int64 id_base_object);

		//создание XML файла -------------------------------------------
        UnicodeString CatalogObmena;
		bool CreateXMLDoc(__int64 id_base, bool povtor);
		void OutputTableInXMLFile(void);
		bool CheckFieldForOutput(UnicodeString name_field, UnicodeString name_table);
        
		bool SaveFileXML(UnicodeString str);


		void OutputKvitan(__int64 idext_data_out);
		void OutputComandDvReg(void);

		void OutputDeleteRecordInXMLFile(void);


		bool CheckRecordPoPrefiksu(void);

		UnicodeString TextError;

		void SetOKAllKvitan(__int64 id_base);
		void OutputPovtorKvitan(void);

		TNotifyEvent EventNextRecord;
		TNotifyEvent EventFirstRecord;
		int *lpKolRecord;

		int NumberTecRecord;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribOut *DMUribOut;
//---------------------------------------------------------------------------
#endif
