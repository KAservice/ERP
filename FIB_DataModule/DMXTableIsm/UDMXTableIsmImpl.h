#ifndef UDMXTableIsmImplH
#define UDMXTableIsmImplH
#include "IDMXTableIsm.h"
#include "UDMXTableIsm.h"
//---------------------------------------------------------------
class __declspec(uuid("{6586EC15-0549-410D-BD21-49F01DE872C0}"))TDMXTableIsmImpl : public IDMXTableIsm
{
public:
   TDMXTableIsmImpl();
   ~TDMXTableIsmImpl();
   TDMXTableIsm * Object;
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

//IDMXTableIsm
   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual void OpenTable(__int64 id_max);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual void SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 GetMaxID(void);
};
#define CLSID_TDMXTableIsmImpl __uuidof(TDMXTableIsmImpl)
#endif
