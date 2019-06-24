#ifndef UIDMSprNomImageH
#define UIDMSprNomImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomImage)) IDMSprNomImage : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SNOMIMAGE = {read = get_TableID_SNOMIMAGE , write = set_TableID_SNOMIMAGE};
   virtual TFIBLargeIntField * get_TableID_SNOMIMAGE(void)=0;
   virtual void set_TableID_SNOMIMAGE(TFIBLargeIntField * TableID_SNOMIMAGE)=0;

   __property TFIBLargeIntField * TableIDBASE_SNOMIMAGE = {read = get_TableIDBASE_SNOMIMAGE , write = set_TableIDBASE_SNOMIMAGE};
   virtual TFIBLargeIntField * get_TableIDBASE_SNOMIMAGE(void)=0;
   virtual void set_TableIDBASE_SNOMIMAGE(TFIBLargeIntField * TableIDBASE_SNOMIMAGE)=0;

   __property TFIBWideStringField * TableGID_SNOMIMAGE = {read = get_TableGID_SNOMIMAGE , write = set_TableGID_SNOMIMAGE};
   virtual TFIBWideStringField * get_TableGID_SNOMIMAGE(void)=0;
   virtual void set_TableGID_SNOMIMAGE(TFIBWideStringField * TableGID_SNOMIMAGE)=0;

   __property TFIBLargeIntField * TableIDVIDIMAGE_SNOMIMAGE = {read = get_TableIDVIDIMAGE_SNOMIMAGE , write = set_TableIDVIDIMAGE_SNOMIMAGE};
   virtual TFIBLargeIntField * get_TableIDVIDIMAGE_SNOMIMAGE(void)=0;
   virtual void set_TableIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * TableIDVIDIMAGE_SNOMIMAGE)=0;

   __property TFIBLargeIntField * TableIDNOM_SNOMIMAGE = {read = get_TableIDNOM_SNOMIMAGE , write = set_TableIDNOM_SNOMIMAGE};
   virtual TFIBLargeIntField * get_TableIDNOM_SNOMIMAGE(void)=0;
   virtual void set_TableIDNOM_SNOMIMAGE(TFIBLargeIntField * TableIDNOM_SNOMIMAGE)=0;

   __property TFIBWideStringField * TableNAME_SNOMIMAGE = {read = get_TableNAME_SNOMIMAGE , write = set_TableNAME_SNOMIMAGE};
   virtual TFIBWideStringField * get_TableNAME_SNOMIMAGE(void)=0;
   virtual void set_TableNAME_SNOMIMAGE(TFIBWideStringField * TableNAME_SNOMIMAGE)=0;

   __property TFIBBlobField * TableBODY_SNOMIMAGE = {read = get_TableBODY_SNOMIMAGE , write = set_TableBODY_SNOMIMAGE};
   virtual TFIBBlobField * get_TableBODY_SNOMIMAGE(void)=0;
   virtual void set_TableBODY_SNOMIMAGE(TFIBBlobField * TableBODY_SNOMIMAGE)=0;

   __property TFIBBlobField * TableBODY_SMALL_SNOMIMAGE = {read = get_TableBODY_SMALL_SNOMIMAGE , write = set_TableBODY_SMALL_SNOMIMAGE};
   virtual TFIBBlobField * get_TableBODY_SMALL_SNOMIMAGE(void)=0;
   virtual void set_TableBODY_SMALL_SNOMIMAGE(TFIBBlobField * TableBODY_SMALL_SNOMIMAGE)=0;

   __property TFIBLargeIntField * ElementID_SNOMIMAGE = {read = get_ElementID_SNOMIMAGE , write = set_ElementID_SNOMIMAGE};
   virtual TFIBLargeIntField * get_ElementID_SNOMIMAGE(void)=0;
   virtual void set_ElementID_SNOMIMAGE(TFIBLargeIntField * ElementID_SNOMIMAGE)=0;

   __property TFIBLargeIntField * ElementIDBASE_SNOMIMAGE = {read = get_ElementIDBASE_SNOMIMAGE , write = set_ElementIDBASE_SNOMIMAGE};
   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMIMAGE(void)=0;
   virtual void set_ElementIDBASE_SNOMIMAGE(TFIBLargeIntField * ElementIDBASE_SNOMIMAGE)=0;

   __property TFIBWideStringField * ElementGID_SNOMIMAGE = {read = get_ElementGID_SNOMIMAGE , write = set_ElementGID_SNOMIMAGE};
   virtual TFIBWideStringField * get_ElementGID_SNOMIMAGE(void)=0;
   virtual void set_ElementGID_SNOMIMAGE(TFIBWideStringField * ElementGID_SNOMIMAGE)=0;

   __property TFIBLargeIntField * ElementIDVIDIMAGE_SNOMIMAGE = {read = get_ElementIDVIDIMAGE_SNOMIMAGE , write = set_ElementIDVIDIMAGE_SNOMIMAGE};
   virtual TFIBLargeIntField * get_ElementIDVIDIMAGE_SNOMIMAGE(void)=0;
   virtual void set_ElementIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * ElementIDVIDIMAGE_SNOMIMAGE)=0;

   __property TFIBLargeIntField * ElementIDNOM_SNOMIMAGE = {read = get_ElementIDNOM_SNOMIMAGE , write = set_ElementIDNOM_SNOMIMAGE};
   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMIMAGE(void)=0;
   virtual void set_ElementIDNOM_SNOMIMAGE(TFIBLargeIntField * ElementIDNOM_SNOMIMAGE)=0;

   __property TFIBWideStringField * ElementNAME_SNOMIMAGE = {read = get_ElementNAME_SNOMIMAGE , write = set_ElementNAME_SNOMIMAGE};
   virtual TFIBWideStringField * get_ElementNAME_SNOMIMAGE(void)=0;
   virtual void set_ElementNAME_SNOMIMAGE(TFIBWideStringField * ElementNAME_SNOMIMAGE)=0;

   __property TFIBBlobField * ElementBODY_SNOMIMAGE = {read = get_ElementBODY_SNOMIMAGE , write = set_ElementBODY_SNOMIMAGE};
   virtual TFIBBlobField * get_ElementBODY_SNOMIMAGE(void)=0;
   virtual void set_ElementBODY_SNOMIMAGE(TFIBBlobField * ElementBODY_SNOMIMAGE)=0;

   __property TFIBBlobField * ElementBODY_SMALL_SNOMIMAGE = {read = get_ElementBODY_SMALL_SNOMIMAGE , write = set_ElementBODY_SMALL_SNOMIMAGE};
   virtual TFIBBlobField * get_ElementBODY_SMALL_SNOMIMAGE(void)=0;
   virtual void set_ElementBODY_SMALL_SNOMIMAGE(TFIBBlobField * ElementBODY_SMALL_SNOMIMAGE)=0;

   __property TFIBWideStringField * TableNAME_SVIDIMAGE = {read = get_TableNAME_SVIDIMAGE , write = set_TableNAME_SVIDIMAGE};
   virtual TFIBWideStringField * get_TableNAME_SVIDIMAGE(void)=0;
   virtual void set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE)=0;

   __property TFIBWideStringField * ElementNAME_SVIDIMAGE = {read = get_ElementNAME_SVIDIMAGE , write = set_ElementNAME_SVIDIMAGE};
   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE(void)=0;
   virtual void set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE)=0;

   __property TFIBIntegerField * TableINDEX_SNOMIMAGE = {read = get_TableINDEX_SNOMIMAGE , write = set_TableINDEX_SNOMIMAGE};
   virtual TFIBIntegerField * get_TableINDEX_SNOMIMAGE(void)=0;
   virtual void set_TableINDEX_SNOMIMAGE(TFIBIntegerField * TableINDEX_SNOMIMAGE)=0;

   __property TFIBIntegerField * ElementINDEX_SNOMIMAGE = {read = get_ElementINDEX_SNOMIMAGE , write = set_ElementINDEX_SNOMIMAGE};
   virtual TFIBIntegerField * get_ElementINDEX_SNOMIMAGE(void)=0;
   virtual void set_ElementINDEX_SNOMIMAGE(TFIBIntegerField * ElementINDEX_SNOMIMAGE)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_nom)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_nom)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprNomImage __uuidof(IDMSprNomImage)
#endif
