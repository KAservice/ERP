#ifndef UIDMSprImportNomH
#define UIDMSprImportNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{528929F4-B38A-473B-BC89-C04F54208B3A}")) IDMSprImportNom : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_SIMPORTNOM = {read = get_TableID_SIMPORTNOM , write = set_TableID_SIMPORTNOM};
   virtual TFIBBCDField * get_TableID_SIMPORTNOM(void)=0;
   virtual void set_TableID_SIMPORTNOM(TFIBBCDField * TableID_SIMPORTNOM)=0;

   __property TFIBBCDField * TableIDBASE_SIMPORTNOM = {read = get_TableIDBASE_SIMPORTNOM , write = set_TableIDBASE_SIMPORTNOM};
   virtual TFIBBCDField * get_TableIDBASE_SIMPORTNOM(void)=0;
   virtual void set_TableIDBASE_SIMPORTNOM(TFIBBCDField * TableIDBASE_SIMPORTNOM)=0;

   __property TFIBBCDField * TableIDNOM_SIMPORTNOM = {read = get_TableIDNOM_SIMPORTNOM , write = set_TableIDNOM_SIMPORTNOM};
   virtual TFIBBCDField * get_TableIDNOM_SIMPORTNOM(void)=0;
   virtual void set_TableIDNOM_SIMPORTNOM(TFIBBCDField * TableIDNOM_SIMPORTNOM)=0;

   __property TFIBBCDField * TableIDKLIENT_SIMPORTNOM = {read = get_TableIDKLIENT_SIMPORTNOM , write = set_TableIDKLIENT_SIMPORTNOM};
   virtual TFIBBCDField * get_TableIDKLIENT_SIMPORTNOM(void)=0;
   virtual void set_TableIDKLIENT_SIMPORTNOM(TFIBBCDField * TableIDKLIENT_SIMPORTNOM)=0;

   __property TFIBBCDField * ElementID_SIMPORTNOM = {read = get_ElementID_SIMPORTNOM , write = set_ElementID_SIMPORTNOM};
   virtual TFIBBCDField * get_ElementID_SIMPORTNOM(void)=0;
   virtual void set_ElementID_SIMPORTNOM(TFIBBCDField * ElementID_SIMPORTNOM)=0;

   __property TFIBBCDField * ElementIDBASE_SIMPORTNOM = {read = get_ElementIDBASE_SIMPORTNOM , write = set_ElementIDBASE_SIMPORTNOM};
   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTNOM(void)=0;
   virtual void set_ElementIDBASE_SIMPORTNOM(TFIBBCDField * ElementIDBASE_SIMPORTNOM)=0;

   __property TFIBBCDField * ElementIDNOM_SIMPORTNOM = {read = get_ElementIDNOM_SIMPORTNOM , write = set_ElementIDNOM_SIMPORTNOM};
   virtual TFIBBCDField * get_ElementIDNOM_SIMPORTNOM(void)=0;
   virtual void set_ElementIDNOM_SIMPORTNOM(TFIBBCDField * ElementIDNOM_SIMPORTNOM)=0;

   __property TFIBBCDField * ElementIDKLIENT_SIMPORTNOM = {read = get_ElementIDKLIENT_SIMPORTNOM , write = set_ElementIDKLIENT_SIMPORTNOM};
   virtual TFIBBCDField * get_ElementIDKLIENT_SIMPORTNOM(void)=0;
   virtual void set_ElementIDKLIENT_SIMPORTNOM(TFIBBCDField * ElementIDKLIENT_SIMPORTNOM)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBWideStringField * TableCODE_SIMPORTNOM = {read = get_TableCODE_SIMPORTNOM , write = set_TableCODE_SIMPORTNOM};
   virtual TFIBWideStringField * get_TableCODE_SIMPORTNOM(void)=0;
   virtual void set_TableCODE_SIMPORTNOM(TFIBWideStringField * TableCODE_SIMPORTNOM)=0;

   __property TFIBWideStringField * TableART_SIMPORTNOM = {read = get_TableART_SIMPORTNOM , write = set_TableART_SIMPORTNOM};
   virtual TFIBWideStringField * get_TableART_SIMPORTNOM(void)=0;
   virtual void set_TableART_SIMPORTNOM(TFIBWideStringField * TableART_SIMPORTNOM)=0;

   __property TFIBWideStringField * TableNAME_SIMPORTNOM = {read = get_TableNAME_SIMPORTNOM , write = set_TableNAME_SIMPORTNOM};
   virtual TFIBWideStringField * get_TableNAME_SIMPORTNOM(void)=0;
   virtual void set_TableNAME_SIMPORTNOM(TFIBWideStringField * TableNAME_SIMPORTNOM)=0;

   __property TFIBWideStringField * ElementCODE_SIMPORTNOM = {read = get_ElementCODE_SIMPORTNOM , write = set_ElementCODE_SIMPORTNOM};
   virtual TFIBWideStringField * get_ElementCODE_SIMPORTNOM(void)=0;
   virtual void set_ElementCODE_SIMPORTNOM(TFIBWideStringField * ElementCODE_SIMPORTNOM)=0;

   __property TFIBWideStringField * ElementART_SIMPORTNOM = {read = get_ElementART_SIMPORTNOM , write = set_ElementART_SIMPORTNOM};
   virtual TFIBWideStringField * get_ElementART_SIMPORTNOM(void)=0;
   virtual void set_ElementART_SIMPORTNOM(TFIBWideStringField * ElementART_SIMPORTNOM)=0;

   __property TFIBWideStringField * ElementNAME_SIMPORTNOM = {read = get_ElementNAME_SIMPORTNOM , write = set_ElementNAME_SIMPORTNOM};
   virtual TFIBWideStringField * get_ElementNAME_SIMPORTNOM(void)=0;
   virtual void set_ElementNAME_SIMPORTNOM(TFIBWideStringField * ElementNAME_SIMPORTNOM)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   virtual void OpenTable(__int64 id_nom)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_nom)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindNomPoArtikulu(__int64 id_post, UnicodeString artikul)=0;
   virtual __int64 FindNomPoCodu(__int64 id_post, UnicodeString code)=0;
   virtual __int64 FindNomPoName(__int64 id_post, UnicodeString name)=0;
   virtual __int64 FindElementPoArtikulu(__int64 id_post, UnicodeString artikul)=0;
   virtual __int64 FindElementPoCodu(__int64 id_post, UnicodeString code)=0;
   virtual __int64 FindElementPoName(__int64 id_post, UnicodeString name)=0;
};
#define IID_IDMSprImportNom __uuidof(IDMSprImportNom)
#endif
