#ifndef UDMGurDocPerImplH
#define UDMGurDocPerImplH
#include "IDMGurDocPer.h"
#include "UDMGurDocPer.h"
//---------------------------------------------------------------
class __declspec(uuid("{AC364804-BCC6-4AA4-ADCA-042043A40DA3}")) TDMGurDocPerImpl : public IDMGurDocPer
{
public:
   TDMGurDocPerImpl();
   ~TDMGurDocPerImpl();
   TDMGurDocPer * Object;
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

//IDMGurDocPer
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBIntegerField * get_TableNUMDOC(void);
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC);

   virtual TFIBDateTimeField * get_TablePOSDOC(void);
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC);

   virtual TFIBSmallIntField * get_TablePRDOC(void);
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC);

   virtual TFIBBCDField * get_TableSUMDOC(void);
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC);

   virtual TFIBBCDField * get_TableIDDOC(void);
   virtual void set_TableIDDOC(TFIBBCDField * TableIDDOC);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMESKLADPOL(void);
   virtual void set_TableNAMESKLADPOL(TFIBWideStringField * TableNAMESKLADPOL);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TablePRIMPER(void);
   virtual void set_TablePRIMPER(TFIBWideStringField * TablePRIMPER);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
};
#define CLSID_TDMGurDocPerImpl __uuidof(TDMGurDocPerImpl)
#endif
