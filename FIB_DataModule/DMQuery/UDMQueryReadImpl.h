#ifndef UDMQueryReadImplH
#define UDMQueryReadImplH
#include "IDMQueryRead.h"
#include "UDMQueryRead.h"
//---------------------------------------------------------------
class __declspec(uuid("{8F15ED0D-CAA4-4178-A2EF-F4F9610D2D41}")) TDMQueryReadImpl : public IDMQueryRead
{
public:
   TDMQueryReadImpl();
   ~TDMQueryReadImpl();
   TDMQueryRead * Object;
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

//IDMQueryRead
   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBTransaction * get_pFIBTr(void);
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TpFIBTransaction * get_Transaction(void);
   virtual void set_Transaction(TpFIBTransaction * Transaction);

};
#define CLSID_TDMQueryReadImpl __uuidof(TDMQueryReadImpl)
#endif
