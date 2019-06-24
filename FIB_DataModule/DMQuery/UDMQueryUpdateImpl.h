#ifndef UDMQueryUpdateImplH
#define UDMQueryUpdateImplH
#include "IDMQueryUpdate.h"
#include "UDMQueryUpdate.h"
//---------------------------------------------------------------
class __declspec(uuid("{56E5484E-3F19-4CED-AF0B-A382AC0EE93D}")) TDMQueryUpdateImpl : public IDMQueryUpdate
{
public:
   TDMQueryUpdateImpl();
   ~TDMQueryUpdateImpl();
   TDMQueryUpdate * Object;
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

//IDMQueryUpdate
   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBTransaction * get_pFIBTr(void);
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr);

};
#define CLSID_TDMQueryUpdateImpl __uuidof(TDMQueryUpdateImpl)
#endif
