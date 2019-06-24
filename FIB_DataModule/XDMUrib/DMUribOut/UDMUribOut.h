//---------------------------------------------------------------------------

#ifndef UDMUribOutH
#define UDMUribOutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//-------------------------------------------------
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include "UDMXTableIsm.h"
#include "UDMXDataOut.h"
#include "UDMXFieldBase.h"
#include "UDMXTableBase.h"
#include "UDMSprObmenTypeDoc.h"
#include "UDMSprObmenSklad.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "UDMSprInfBase.h"
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
	TpFIBQuery *IBQ;
	TpFIBTransaction *IBTr1;
	TpFIBDataSet *TableDataOut;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *TableDataOutID_XDATA_OUT;
	TFIBStringField *TableDataOutGID_XDATA_OUT;
	TFIBIntegerField *TableDataOutIDTISM_XDATA_OUT;
	TFIBIntegerField *TableDataOutIDBASE_XDATA_OUT;
	TFIBIntegerField *TableDataOutIDMESSAGE_XDATA_OUT;
	TFIBIntegerField *TableDataOutID_XTISM;
	TFIBStringField *TableDataOutGID_XTISM;
	TFIBDateTimeField *TableDataOutPOS_XTISM;
	TFIBStringField *TableDataOutNAMETAB_XTISM;
	TFIBIntegerField *TableDataOutIDREC_XTISM;
	TFIBIntegerField *TableDataOutTYPEOB_XTISM;
	TFIBStringField *TableDataOutPRBASE_XTISM;
	TFIBIntegerField *TableDataOutOPER_XTISM;
	TpFIBQuery *DocAll;
	TpFIBQuery *Doc;
	TpFIBQuery *DocT;
	TpFIBQuery *IBQ2;
	TpFIBTransaction *IBTr2;
	TpFIBTransaction *IBTrSys;
	TpFIBDataSet *TableFK;
	TpFIBDataSet *TablePK;
	TpFIBDataSet *TableFields;
	TFIBStringField *TableFKFIELD_NAME;
	TFIBStringField *TableFKFIELD_SOURCE;
	TFIBStringField *TableFKFIELD_FK;
	TFIBStringField *TableFKTABLE_FK;
	TFIBStringField *TablePKFIELD_NAME;
	TFIBStringField *TablePKTABLE_NAME;
	TFIBStringField *TableFieldsRDBFIELD_NAME;
	TFIBStringField *TableFieldsRDBRELATION_NAME;
	TFIBStringField *TableFieldsRDBFIELD_SOURCE;
	TFIBSmallIntField *TableFieldsRDBFIELD_TYPE;
	TFIBSmallIntField *TableFieldsRDBFIELD_SCALE;
	TFIBStringField *TableDataOutGIDREC_XTISM;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMUribOut(TComponent* Owner);

        TNotifyEvent EventNextRecord;
        TNotifyEvent EventFirstRecord;
        int *lpKolRecord;
        //AnsiString TypeMessage;

        //-----------------------
        int IdBase;
        AnsiString NameBase;
        AnsiString PrefiksBase;
        int IdMessage;
        AnsiString GIDMessage;

        AnsiString NameUser;
        AnsiString PasswordUser;


        bool EnableOutProtocol;
        AnsiString FileNameOut;
        //AnsiString CatalogObmena;

        //-------------------------------------------------------------
        String FloatToStringComma(double value);
        double StringToFloatComma(String value);

        //заполение таблицы выходных данных ----------------------------
        AnsiString OutPrefikss;
        TDMXTableIsm *TableIsm;
        TDMXDataOut * DataOut;
        TDMSprObmenTypeDoc * DMTypeDoc;
        TDMSprObmenSklad  * DMSprObmenSklad;

        int StartIDTableIsm;

        void AddDocInDataTable(void);
        void AddSprInDataTable(void);

        int CreateDataOutTable(int id_base);

        bool CheckDocForTypeDoc(String type_doc);
        bool CheckDocForPrefiks(AnsiString prefiks);
		int AllDoc;
		int OutSprNacenka;
		int OutZakPrice;
        //создание XML файла -------------------------------------------
        AnsiString CatalogObmena;
        void CreateXMLDoc(int id_message);
        void OutputSprInXMLFile(String table_name, int id_record);
        void OutputDocInXMLFile(String table_name, int id_record);
        void OutputTableInXMLFile(String table_name, int id_record );
        void OutputFKInXMLFile(String name_field, int value_field );
        String GetNameGid(String name_table);
        bool CheckFieldForOutput(String name_field, String name_table);
        
        void SaveFileXML(String str);
        String FormatForXML(String s);
        //--------------------------------------------------------------
        void  CreateStrBase(void);
        void  DeleteAllDataOut(void);
        void OutProtocol(String str);
        //-------------------------------------------------------------
        TDMXTableBase *DMXTableBase;
		TDMXFieldBase *DMXFieldBase;

		void OutputDeleteRecordInXMLFile(AnsiString table_name);


		bool CheckRecordPoPrefiksu(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribOut *DMUribOut;
//---------------------------------------------------------------------------
#endif
