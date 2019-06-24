#ifndef UIDMSprGrpNomH
#define UIDMSprGrpNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprGrpNom)) IDMSprGrpNom : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableIDGN = {read = get_TableIDGN , write = set_TableIDGN};
   virtual TFIBBCDField * get_TableIDGN(void)=0;
   virtual void set_TableIDGN(TFIBBCDField * TableIDGN)=0;

   __property TFIBBCDField * TableIDGRPGN = {read = get_TableIDGRPGN , write = set_TableIDGRPGN};
   virtual TFIBBCDField * get_TableIDGRPGN(void)=0;
   virtual void set_TableIDGRPGN(TFIBBCDField * TableIDGRPGN)=0;

   __property TFIBBCDField * ElementIDGN = {read = get_ElementIDGN , write = set_ElementIDGN};
   virtual TFIBBCDField * get_ElementIDGN(void)=0;
   virtual void set_ElementIDGN(TFIBBCDField * ElementIDGN)=0;

   __property TFIBBCDField * ElementIDGRPGN = {read = get_ElementIDGRPGN , write = set_ElementIDGRPGN};
   virtual TFIBBCDField * get_ElementIDGRPGN(void)=0;
   virtual void set_ElementIDGRPGN(TFIBBCDField * ElementIDGRPGN)=0;

   __property TFIBWideStringField * TableNAMEGN = {read = get_TableNAMEGN , write = set_TableNAMEGN};
   virtual TFIBWideStringField * get_TableNAMEGN(void)=0;
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)=0;

   __property TFIBWideStringField * TableGID_SGRPNOM = {read = get_TableGID_SGRPNOM , write = set_TableGID_SGRPNOM};
   virtual TFIBWideStringField * get_TableGID_SGRPNOM(void)=0;
   virtual void set_TableGID_SGRPNOM(TFIBWideStringField * TableGID_SGRPNOM)=0;

   __property TFIBWideStringField * ElementNAMEGN = {read = get_ElementNAMEGN , write = set_ElementNAMEGN};
   virtual TFIBWideStringField * get_ElementNAMEGN(void)=0;
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)=0;

   __property TFIBWideStringField * ElementGID_SGRPNOM = {read = get_ElementGID_SGRPNOM , write = set_ElementGID_SGRPNOM};
   virtual TFIBWideStringField * get_ElementGID_SGRPNOM(void)=0;
   virtual void set_ElementGID_SGRPNOM(TFIBWideStringField * ElementGID_SGRPNOM)=0;

   __property TFIBBCDField * ElementIDVIDIMAGENABOR_SGRPNOM = {read = get_ElementIDVIDIMAGENABOR_SGRPNOM , write = set_ElementIDVIDIMAGENABOR_SGRPNOM};
   virtual TFIBBCDField * get_ElementIDVIDIMAGENABOR_SGRPNOM(void)=0;
   virtual void set_ElementIDVIDIMAGENABOR_SGRPNOM(TFIBBCDField * ElementIDVIDIMAGENABOR_SGRPNOM)=0;

   __property TFIBBCDField * ElementIDPROPNABOR_SGRPNOM = {read = get_ElementIDPROPNABOR_SGRPNOM , write = set_ElementIDPROPNABOR_SGRPNOM};
   virtual TFIBBCDField * get_ElementIDPROPNABOR_SGRPNOM(void)=0;
   virtual void set_ElementIDPROPNABOR_SGRPNOM(TFIBBCDField * ElementIDPROPNABOR_SGRPNOM)=0;

   __property TFIBWideStringField * ElementNAME_SPROPNABOR = {read = get_ElementNAME_SPROPNABOR , write = set_ElementNAME_SPROPNABOR};
   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR(void)=0;
   virtual void set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)=0;

   __property TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR = {read = get_ElementNAME_SVIDIMAGE_NABOR , write = set_ElementNAME_SVIDIMAGE_NABOR};
   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE_NABOR(void)=0;
   virtual void set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdGrp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
};
#define IID_IDMSprGrpNom __uuidof(IDMSprGrpNom)
#endif
