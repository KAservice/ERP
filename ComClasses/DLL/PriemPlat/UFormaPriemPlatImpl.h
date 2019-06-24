//---------------------------------------------------------------------------

#ifndef UFormaPriemPlatImplH
#define UFormaPriemPlatImplH
//---------------------------------------------------------------------------


#include "IMainInterface.h"
#include "IDevices.h"
#include "UFormaPriemPlat.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------------------

class __declspec(uuid(Global_CLSID_TFormaPriemPlatImpl)) TFormaPriemPlatImpl
					 : public IMainInterface
{
public:
   TFormaPriemPlatImpl();
   ~TFormaPriemPlatImpl();

   bool flDeleteObject;
   void DeleteImpl(void);

	TFormaPriemPlat * Object;
	int NumRefs;

	//IUnknown
	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);

	//IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);



};

#define CLSID_TFormaPriemPlatImpl __uuidof(TFormaPriemPlatImpl)
#endif
