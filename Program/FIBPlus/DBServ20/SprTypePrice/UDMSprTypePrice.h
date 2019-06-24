//---------------------------------------------------------------------------

#ifndef UDMSprTypePriceH
#define UDMSprTypePriceH
//---------------------------------------------------------------------------
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
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprTypePrice : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAME_TPRICE;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAME_TPRICE;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_TPRICE;
	TFIBBCDField *ElementID_TPRICE;
	TFIBStringField *TableGID_STPRICE;
	TFIBStringField *ElementGID_STPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprTypePrice(TComponent* Owner);

        void OpenTable();
		int  OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement();
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

		__int64 GetIDTypePrice(String   name);
		int GetIndexTypePricePoId(__int64 id_type_price);

        __int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
        String TextError;
        bool Error;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprTypePrice *DMSprTypePrice;
//---------------------------------------------------------------------------
#endif
