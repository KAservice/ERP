#ifndef UDMSprMPrigImplH
#define UDMSprMPrigImplH
#include "IDMSprMPrig.h"
#include "UDMSprMPrig.h"
//---------------------------------------------------------------
class __declspec(uuid("{70BDED47-5340-4193-A57E-89792682DF5D}")) TDMSprMPrigImpl : public IDMSprMPrig
{
public:
   TDMSprMPrigImpl();
   ~TDMSprMPrigImpl();
   TDMSprMPrig * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprMPrig
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableID_MPRIG(void);
   virtual void set_TableID_MPRIG(TFIBBCDField * TableID_MPRIG);

   virtual TFIBBCDField * get_TableIDSKLAD_MPRIG(void);
   virtual void set_TableIDSKLAD_MPRIG(TFIBBCDField * TableIDSKLAD_MPRIG);

   virtual TFIBBCDField * get_TableIDOBORUD_MPRIG(void);
   virtual void set_TableIDOBORUD_MPRIG(TFIBBCDField * TableIDOBORUD_MPRIG);

   virtual TFIBBCDField * get_ElementID_MPRIG(void);
   virtual void set_ElementID_MPRIG(TFIBBCDField * ElementID_MPRIG);

   virtual TFIBBCDField * get_ElementIDSKLAD_MPRIG(void);
   virtual void set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG);

   virtual TFIBBCDField * get_ElementIDOBORUD_MPRIG(void);
   virtual void set_ElementIDOBORUD_MPRIG(TFIBBCDField * ElementIDOBORUD_MPRIG);

   virtual TFIBBCDField * get_TableIDBASE_SMPRIG(void);
   virtual void set_TableIDBASE_SMPRIG(TFIBBCDField * TableIDBASE_SMPRIG);

   virtual TFIBBCDField * get_ElementIDBASE_SMPRIG(void);
   virtual void set_ElementIDBASE_SMPRIG(TFIBBCDField * ElementIDBASE_SMPRIG);

   virtual TFIBWideStringField * get_TableNAME_MPRIG(void);
   virtual void set_TableNAME_MPRIG(TFIBWideStringField * TableNAME_MPRIG);

   virtual TFIBWideStringField * get_TableGID_SMPRIG(void);
   virtual void set_TableGID_SMPRIG(TFIBWideStringField * TableGID_SMPRIG);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAME_OBORUD(void);
   virtual void set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD);

   virtual TFIBWideStringField * get_ElementNAME_MPRIG(void);
   virtual void set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG);

   virtual TFIBWideStringField * get_ElementGID_SMPRIG(void);
   virtual void set_ElementGID_SMPRIG(TFIBWideStringField * ElementGID_SMPRIG);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAME_OBORUD(void);
   virtual void set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprMPrigImpl __uuidof(TDMSprMPrigImpl)
#endif
