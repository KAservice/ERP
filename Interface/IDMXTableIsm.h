#ifndef UIDMXTableIsmH
#define UIDMXTableIsmH
#include "IMainInterface.h"
class __declspec(uuid("{4136492D-A837-4295-AA65-F089D598B837}"))IDMXTableIsm : public IMainInterface
{
public:
   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   virtual void OpenTable(__int64 id_max)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual void SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 GetMaxID(void)=0;
};
#define IID_IDMXTableIsm __uuidof(IDMXTableIsm)
#endif
