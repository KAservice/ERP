#ifndef UIDMSprKlientDopUrLH
#define UIDMSprKlientDopUrLH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{86CFFA6F-F6F4-4053-BC10-F0841099A160}")) IDMSprKlientDopUrL : public IMainInterface
{
public:
   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBBCDField * ElementID_SKLIENT_DOPURL = {read = get_ElementID_SKLIENT_DOPURL , write = set_ElementID_SKLIENT_DOPURL};
   virtual TFIBBCDField * get_ElementID_SKLIENT_DOPURL(void)=0;
   virtual void set_ElementID_SKLIENT_DOPURL(TFIBBCDField * ElementID_SKLIENT_DOPURL)=0;

   __property TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPURL = {read = get_ElementIDKLIENT_SKLIENT_DOPURL , write = set_ElementIDKLIENT_SKLIENT_DOPURL};
   virtual TFIBBCDField * get_ElementIDKLIENT_SKLIENT_DOPURL(void)=0;
   virtual void set_ElementIDKLIENT_SKLIENT_DOPURL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPURL)=0;

   __property TFIBWideStringField * ElementGID_SKLIENT_DOPURL = {read = get_ElementGID_SKLIENT_DOPURL , write = set_ElementGID_SKLIENT_DOPURL};
   virtual TFIBWideStringField * get_ElementGID_SKLIENT_DOPURL(void)=0;
   virtual void set_ElementGID_SKLIENT_DOPURL(TFIBWideStringField * ElementGID_SKLIENT_DOPURL)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   virtual int OpenElement(void)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(void)=0;
};
#define IID_IDMSprKlientDopUrL __uuidof(IDMSprKlientDopUrL)
#endif
