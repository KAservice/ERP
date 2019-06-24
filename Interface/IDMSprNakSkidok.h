#ifndef UIDMSprNakSkidokH
#define UIDMSprNakSkidokH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{F20FC6EF-51AB-4097-A9DD-7794D33A9FBD}")) IDMSprNakSkidok : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableSUM_SNAK_SKIDOK = {read = get_TableSUM_SNAK_SKIDOK , write = set_TableSUM_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableSUM_SNAK_SKIDOK(void)=0;
   virtual void set_TableSUM_SNAK_SKIDOK(TFIBBCDField * TableSUM_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TablePROCENT_SNAK_SKIDOK = {read = get_TablePROCENT_SNAK_SKIDOK , write = set_TablePROCENT_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TablePROCENT_SNAK_SKIDOK(void)=0;
   virtual void set_TablePROCENT_SNAK_SKIDOK(TFIBBCDField * TablePROCENT_SNAK_SKIDOK)=0;

   __property TFIBSmallIntField * TablePERIOD_SNAK_SKIDOK = {read = get_TablePERIOD_SNAK_SKIDOK , write = set_TablePERIOD_SNAK_SKIDOK};
   virtual TFIBSmallIntField * get_TablePERIOD_SNAK_SKIDOK(void)=0;
   virtual void set_TablePERIOD_SNAK_SKIDOK(TFIBSmallIntField * TablePERIOD_SNAK_SKIDOK)=0;

   __property TFIBBCDField * ElementSUM_SNAK_SKIDOK = {read = get_ElementSUM_SNAK_SKIDOK , write = set_ElementSUM_SNAK_SKIDOK};
   virtual TFIBBCDField * get_ElementSUM_SNAK_SKIDOK(void)=0;
   virtual void set_ElementSUM_SNAK_SKIDOK(TFIBBCDField * ElementSUM_SNAK_SKIDOK)=0;

   __property TFIBBCDField * ElementPROCENT_SNAK_SKIDOK = {read = get_ElementPROCENT_SNAK_SKIDOK , write = set_ElementPROCENT_SNAK_SKIDOK};
   virtual TFIBBCDField * get_ElementPROCENT_SNAK_SKIDOK(void)=0;
   virtual void set_ElementPROCENT_SNAK_SKIDOK(TFIBBCDField * ElementPROCENT_SNAK_SKIDOK)=0;

   __property TFIBSmallIntField * ElementPERIOD_SNAK_SKIDOK = {read = get_ElementPERIOD_SNAK_SKIDOK , write = set_ElementPERIOD_SNAK_SKIDOK};
   virtual TFIBSmallIntField * get_ElementPERIOD_SNAK_SKIDOK(void)=0;
   virtual void set_ElementPERIOD_SNAK_SKIDOK(TFIBSmallIntField * ElementPERIOD_SNAK_SKIDOK)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBBCDField * TableID_SNAK_SKIDOK = {read = get_TableID_SNAK_SKIDOK , write = set_TableID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableID_SNAK_SKIDOK(void)=0;
   virtual void set_TableID_SNAK_SKIDOK(TFIBBCDField * TableID_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableIDSKLAD_SNAK_SKIDOK = {read = get_TableIDSKLAD_SNAK_SKIDOK , write = set_TableIDSKLAD_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableIDSKLAD_SNAK_SKIDOK(void)=0;
   virtual void set_TableIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableIDSKLAD_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableIDVID_SNAK_SKIDOK = {read = get_TableIDVID_SNAK_SKIDOK , write = set_TableIDVID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableIDVID_SNAK_SKIDOK(void)=0;
   virtual void set_TableIDVID_SNAK_SKIDOK(TFIBBCDField * TableIDVID_SNAK_SKIDOK)=0;

   __property TFIBBCDField * ElementID_SNAK_SKIDOK = {read = get_ElementID_SNAK_SKIDOK , write = set_ElementID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_ElementID_SNAK_SKIDOK(void)=0;
   virtual void set_ElementID_SNAK_SKIDOK(TFIBBCDField * ElementID_SNAK_SKIDOK)=0;

   __property TFIBBCDField * ElementIDSKLAD_SNAK_SKIDOK = {read = get_ElementIDSKLAD_SNAK_SKIDOK , write = set_ElementIDSKLAD_SNAK_SKIDOK};
   virtual TFIBBCDField * get_ElementIDSKLAD_SNAK_SKIDOK(void)=0;
   virtual void set_ElementIDSKLAD_SNAK_SKIDOK(TFIBBCDField * ElementIDSKLAD_SNAK_SKIDOK)=0;

   __property TFIBBCDField * ElementIDVID_SNAK_SKIDOK = {read = get_ElementIDVID_SNAK_SKIDOK , write = set_ElementIDVID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_ElementIDVID_SNAK_SKIDOK(void)=0;
   virtual void set_ElementIDVID_SNAK_SKIDOK(TFIBBCDField * ElementIDVID_SNAK_SKIDOK)=0;

   __property TpFIBDataSet * TableNakSkidok = {read = get_TableNakSkidok , write = set_TableNakSkidok};
   virtual TpFIBDataSet * get_TableNakSkidok(void)=0;
   virtual void set_TableNakSkidok(TpFIBDataSet * TableNakSkidok)=0;

   __property TFIBBCDField * TableNakSkidokID_SNAK_SKIDOK = {read = get_TableNakSkidokID_SNAK_SKIDOK , write = set_TableNakSkidokID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableNakSkidokID_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokID_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableNakSkidokIDSKLAD_SNAK_SKIDOK = {read = get_TableNakSkidokIDSKLAD_SNAK_SKIDOK , write = set_TableNakSkidokIDSKLAD_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableNakSkidokIDSKLAD_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDSKLAD_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableNakSkidokIDVID_SNAK_SKIDOK = {read = get_TableNakSkidokIDVID_SNAK_SKIDOK , write = set_TableNakSkidokIDVID_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableNakSkidokIDVID_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokIDVID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDVID_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableNakSkidokSUM_SNAK_SKIDOK = {read = get_TableNakSkidokSUM_SNAK_SKIDOK , write = set_TableNakSkidokSUM_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableNakSkidokSUM_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokSUM_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokSUM_SNAK_SKIDOK)=0;

   __property TFIBBCDField * TableNakSkidokPROCENT_SNAK_SKIDOK = {read = get_TableNakSkidokPROCENT_SNAK_SKIDOK , write = set_TableNakSkidokPROCENT_SNAK_SKIDOK};
   virtual TFIBBCDField * get_TableNakSkidokPROCENT_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokPROCENT_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokPROCENT_SNAK_SKIDOK)=0;

   __property TFIBSmallIntField * TableNakSkidokPERIOD_SNAK_SKIDOK = {read = get_TableNakSkidokPERIOD_SNAK_SKIDOK , write = set_TableNakSkidokPERIOD_SNAK_SKIDOK};
   virtual TFIBSmallIntField * get_TableNakSkidokPERIOD_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokPERIOD_SNAK_SKIDOK(TFIBSmallIntField * TableNakSkidokPERIOD_SNAK_SKIDOK)=0;

   __property TFIBWideStringField * TableGID_SNAK_SKIDOK = {read = get_TableGID_SNAK_SKIDOK , write = set_TableGID_SNAK_SKIDOK};
   virtual TFIBWideStringField * get_TableGID_SNAK_SKIDOK(void)=0;
   virtual void set_TableGID_SNAK_SKIDOK(TFIBWideStringField * TableGID_SNAK_SKIDOK)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAME_SVID_DCARD = {read = get_TableNAME_SVID_DCARD , write = set_TableNAME_SVID_DCARD};
   virtual TFIBWideStringField * get_TableNAME_SVID_DCARD(void)=0;
   virtual void set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD)=0;

   __property TFIBWideStringField * ElementGID_SNAK_SKIDOK = {read = get_ElementGID_SNAK_SKIDOK , write = set_ElementGID_SNAK_SKIDOK};
   virtual TFIBWideStringField * get_ElementGID_SNAK_SKIDOK(void)=0;
   virtual void set_ElementGID_SNAK_SKIDOK(TFIBWideStringField * ElementGID_SNAK_SKIDOK)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAME_SVID_DCARD = {read = get_ElementNAME_SVID_DCARD , write = set_ElementNAME_SVID_DCARD};
   virtual TFIBWideStringField * get_ElementNAME_SVID_DCARD(void)=0;
   virtual void set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD)=0;

   __property TFIBWideStringField * TableNakSkidokGID_SNAK_SKIDOK = {read = get_TableNakSkidokGID_SNAK_SKIDOK , write = set_TableNakSkidokGID_SNAK_SKIDOK};
   virtual TFIBWideStringField * get_TableNakSkidokGID_SNAK_SKIDOK(void)=0;
   virtual void set_TableNakSkidokGID_SNAK_SKIDOK(TFIBWideStringField * TableNakSkidokGID_SNAK_SKIDOK)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual void GetSpisokSkidok(__int64 id_vid, __int64 id_sklad)=0;
   virtual void OpenTableNakSkidok(__int64 id_vid,__int64 id_sklad)=0;
};
#define IID_IDMSprNakSkidok __uuidof(IDMSprNakSkidok)
#endif
