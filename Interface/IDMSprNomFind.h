#ifndef UIDMSprNomFindH
#define UIDMSprNomFindH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomFind)) IDMSprNomFind : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBDataSet * SpTPrice = {read = get_SpTPrice , write = set_SpTPrice};
   virtual TpFIBDataSet * get_SpTPrice(void)=0;
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice)=0;

   __property TFIBLargeIntField * TableIDNOM = {read = get_TableIDNOM , write = set_TableIDNOM};
   virtual TFIBLargeIntField * get_TableIDNOM(void)=0;
   virtual void set_TableIDNOM(TFIBLargeIntField * TableIDNOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBSmallIntField * TableTNOM = {read = get_TableTNOM , write = set_TableTNOM};
   virtual TFIBSmallIntField * get_TableTNOM(void)=0;
   virtual void set_TableTNOM(TFIBSmallIntField * TableTNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TFIBLargeIntField * TableIDGRPNOM = {read = get_TableIDGRPNOM , write = set_TableIDGRPNOM};
   virtual TFIBLargeIntField * get_TableIDGRPNOM(void)=0;
   virtual void set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM)=0;

   __property TFIBBCDField * TableSUMKOL = {read = get_TableSUMKOL , write = set_TableSUMKOL};
   virtual TFIBBCDField * get_TableSUMKOL(void)=0;
   virtual void set_TableSUMKOL(TFIBBCDField * TableSUMKOL)=0;

   __property TDataSource * DataSourceTPrice = {read = get_DataSourceTPrice , write = set_DataSourceTPrice};
   virtual TDataSource * get_DataSourceTPrice(void)=0;
   virtual void set_DataSourceTPrice(TDataSource * DataSourceTPrice)=0;

   __property TFIBLargeIntField * SpTPriceID_TPRICE = {read = get_SpTPriceID_TPRICE , write = set_SpTPriceID_TPRICE};
   virtual TFIBLargeIntField * get_SpTPriceID_TPRICE(void)=0;
   virtual void set_SpTPriceID_TPRICE(TFIBLargeIntField * SpTPriceID_TPRICE)=0;

   __property TFIBWideStringField * SpTPriceNAME_TPRICE = {read = get_SpTPriceNAME_TPRICE , write = set_SpTPriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void)=0;
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)=0;

   __property TFIBWideStringField * TableNAMEGN = {read = get_TableNAMEGN , write = set_TableNAMEGN};
   virtual TFIBWideStringField * get_TableNAMEGN(void)=0;
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property TFIBBCDField * TableREM_OST = {read = get_TableREM_OST , write = set_TableREM_OST};
   virtual TFIBBCDField * get_TableREM_OST(void)=0;
   virtual void set_TableREM_OST(TFIBBCDField * TableREM_OST)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   virtual bool SetTextQuery(UnicodeString text)=0;
   virtual bool SetIntegerParam(UnicodeString name_param, int value_param)=0;
   virtual bool SetInt64Param(UnicodeString name_param, __int64 value_param)=0;
   virtual bool SetStringParam(UnicodeString name_param, UnicodeString value_param)=0;
   virtual bool OpenTableResult(void)=0;
};
#define IID_IDMSprNomFind __uuidof(IDMSprNomFind)
#endif
