#ifndef UDMSprRaschSchetImplH
#define UDMSprRaschSchetImplH
#include "IDMSprRaschSchet.h"
#include "UDMSprRaschSchet.h"
//---------------------------------------------------------------
class __declspec(uuid("{040F45AE-55C5-4DBE-A91A-19C5656BCBD1}"))TDMSprRaschSchetImpl : public IDMSprRaschSchet
{
public:
   TDMSprRaschSchetImpl();
   ~TDMSprRaschSchetImpl();
   TDMSprRaschSchet * Object;
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

//IDMSprRaschSchet
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

   virtual TFIBBCDField * get_TableIDRSCHET(void);
   virtual void set_TableIDRSCHET(TFIBBCDField * TableIDRSCHET);

   virtual TFIBBCDField * get_TableIDKLRSCHET(void);
   virtual void set_TableIDKLRSCHET(TFIBBCDField * TableIDKLRSCHET);

   virtual TFIBBCDField * get_TableIDBANKRSCHET(void);
   virtual void set_TableIDBANKRSCHET(TFIBBCDField * TableIDBANKRSCHET);

   virtual TFIBBCDField * get_TableIDBANK(void);
   virtual void set_TableIDBANK(TFIBBCDField * TableIDBANK);

   virtual TFIBBCDField * get_ElementIDRSCHET(void);
   virtual void set_ElementIDRSCHET(TFIBBCDField * ElementIDRSCHET);

   virtual TFIBBCDField * get_ElementIDKLRSCHET(void);
   virtual void set_ElementIDKLRSCHET(TFIBBCDField * ElementIDKLRSCHET);

   virtual TFIBBCDField * get_ElementIDBANKRSCHET(void);
   virtual void set_ElementIDBANKRSCHET(TFIBBCDField * ElementIDBANKRSCHET);

   virtual TFIBBCDField * get_ElementIDBANK(void);
   virtual void set_ElementIDBANK(TFIBBCDField * ElementIDBANK);

   virtual TFIBWideStringField * get_TableNAMERSCHET(void);
   virtual void set_TableNAMERSCHET(TFIBWideStringField * TableNAMERSCHET);

   virtual TFIBWideStringField * get_TableNUMRSCHET(void);
   virtual void set_TableNUMRSCHET(TFIBWideStringField * TableNUMRSCHET);

   virtual TFIBWideStringField * get_TableGID_SRSCHET(void);
   virtual void set_TableGID_SRSCHET(TFIBWideStringField * TableGID_SRSCHET);

   virtual TFIBWideStringField * get_TableNAMEBANK(void);
   virtual void set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK);

   virtual TFIBWideStringField * get_TableBIKBANK(void);
   virtual void set_TableBIKBANK(TFIBWideStringField * TableBIKBANK);

   virtual TFIBWideStringField * get_TableGORBANK(void);
   virtual void set_TableGORBANK(TFIBWideStringField * TableGORBANK);

   virtual TFIBWideStringField * get_TableKSBANK(void);
   virtual void set_TableKSBANK(TFIBWideStringField * TableKSBANK);

   virtual TFIBWideStringField * get_ElementNAMERSCHET(void);
   virtual void set_ElementNAMERSCHET(TFIBWideStringField * ElementNAMERSCHET);

   virtual TFIBWideStringField * get_ElementNUMRSCHET(void);
   virtual void set_ElementNUMRSCHET(TFIBWideStringField * ElementNUMRSCHET);

   virtual TFIBWideStringField * get_ElementGID_SRSCHET(void);
   virtual void set_ElementGID_SRSCHET(TFIBWideStringField * ElementGID_SRSCHET);

   virtual TFIBWideStringField * get_ElementNAMEBANK(void);
   virtual void set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK);

   virtual TFIBWideStringField * get_ElementBIKBANK(void);
   virtual void set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK);

   virtual TFIBWideStringField * get_ElementGORBANK(void);
   virtual void set_ElementGORBANK(TFIBWideStringField * ElementGORBANK);

   virtual TFIBWideStringField * get_ElementKSBANK(void);
   virtual void set_ElementKSBANK(TFIBWideStringField * ElementKSBANK);

   virtual void OpenTable(__int64 IdKlient);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdKlient);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprRaschSchetImpl __uuidof(TDMSprRaschSchetImpl)
#endif
