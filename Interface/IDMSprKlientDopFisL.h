#ifndef UIDMSprKlientDopFisLH
#define UIDMSprKlientDopFisLH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{38DF7108-7109-42DC-901F-D4F0F00A5BEE}")) IDMSprKlientDopFisL : public IMainInterface
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

   __property TFIBIntegerField * ElementPOL_SKLIENT_DOPFISL = {read = get_ElementPOL_SKLIENT_DOPFISL , write = set_ElementPOL_SKLIENT_DOPFISL};
   virtual TFIBIntegerField * get_ElementPOL_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementPOL_SKLIENT_DOPFISL(TFIBIntegerField * ElementPOL_SKLIENT_DOPFISL)=0;

   __property TFIBBCDField * ElementID_SKLIENT_DOPFISL = {read = get_ElementID_SKLIENT_DOPFISL , write = set_ElementID_SKLIENT_DOPFISL};
   virtual TFIBBCDField * get_ElementID_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementID_SKLIENT_DOPFISL(TFIBBCDField * ElementID_SKLIENT_DOPFISL)=0;

   __property TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPFISL = {read = get_ElementIDKLIENT_SKLIENT_DOPFISL , write = set_ElementIDKLIENT_SKLIENT_DOPFISL};
   virtual TFIBBCDField * get_ElementIDKLIENT_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementIDKLIENT_SKLIENT_DOPFISL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPFISL)=0;

   __property TFIBDateField * ElementDATEROG_SKLIENT_DOPFISL = {read = get_ElementDATEROG_SKLIENT_DOPFISL , write = set_ElementDATEROG_SKLIENT_DOPFISL};
   virtual TFIBDateField * get_ElementDATEROG_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementDATEROG_SKLIENT_DOPFISL(TFIBDateField * ElementDATEROG_SKLIENT_DOPFISL)=0;

   __property TFIBWideStringField * ElementMESTOROG_SKLIENT_DOPFISL = {read = get_ElementMESTOROG_SKLIENT_DOPFISL , write = set_ElementMESTOROG_SKLIENT_DOPFISL};
   virtual TFIBWideStringField * get_ElementMESTOROG_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementMESTOROG_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTOROG_SKLIENT_DOPFISL)=0;

   __property TFIBWideStringField * ElementDOLRAB_SKLIENT_DOPFISL = {read = get_ElementDOLRAB_SKLIENT_DOPFISL , write = set_ElementDOLRAB_SKLIENT_DOPFISL};
   virtual TFIBWideStringField * get_ElementDOLRAB_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementDOLRAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementDOLRAB_SKLIENT_DOPFISL)=0;

   __property TFIBWideStringField * ElementMESTORAB_SKLIENT_DOPFISL = {read = get_ElementMESTORAB_SKLIENT_DOPFISL , write = set_ElementMESTORAB_SKLIENT_DOPFISL};
   virtual TFIBWideStringField * get_ElementMESTORAB_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementMESTORAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTORAB_SKLIENT_DOPFISL)=0;

   __property TFIBBCDField * ElementIDBASE_SKLIENT_DOPFISL = {read = get_ElementIDBASE_SKLIENT_DOPFISL , write = set_ElementIDBASE_SKLIENT_DOPFISL};
   virtual TFIBBCDField * get_ElementIDBASE_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementIDBASE_SKLIENT_DOPFISL(TFIBBCDField * ElementIDBASE_SKLIENT_DOPFISL)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementGID_SKLIENT_DOPFISL = {read = get_ElementGID_SKLIENT_DOPFISL , write = set_ElementGID_SKLIENT_DOPFISL};
   virtual TFIBWideStringField * get_ElementGID_SKLIENT_DOPFISL(void)=0;
   virtual void set_ElementGID_SKLIENT_DOPFISL(TFIBWideStringField * ElementGID_SKLIENT_DOPFISL)=0;

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
#define IID_IDMSprKlientDopFisL __uuidof(IDMSprKlientDopFisL)
#endif
