#ifndef UIDMDataSetH
#define UIDMDataSetH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDataSet)) IDMDataSet : public IMainInterface
{
public:
   __property TpFIBTransaction * Transaction = {read = get_Transaction , write = set_Transaction};
   virtual TpFIBTransaction * get_Transaction(void)=0;
   virtual void set_Transaction(TpFIBTransaction * Transaction)=0;

   __property TpFIBDataSet * DataSet = {read = get_DataSet , write = set_DataSet};
   virtual TpFIBDataSet * get_DataSet(void)=0;
   virtual void set_DataSet(TpFIBDataSet * DataSet)=0;

   __property TDataSource * DataSource = {read = get_DataSource , write = set_DataSource};
   virtual TDataSource * get_DataSource(void)=0;
   virtual void set_DataSource(TDataSource * DataSource)=0;

};
#define IID_IDMDataSet __uuidof(IDMDataSet)
#endif
