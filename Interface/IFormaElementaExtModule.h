#ifndef UIFormaElementaExtModuleH
#define UIFormaElementaExtModuleH
#include "IMainInterface.h"
#include "IDMExtModule.h"
#include "IDMExtModulePriv.h"
class __declspec(uuid("{0AA8CCD4-F0BA-4497-8A5C-90A93770277A}")) IFormaElementaExtModule : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMExtModule* DM = {read = get_DM , write = set_DM};
   virtual IDMExtModule* get_DM(void)=0;
   virtual void set_DM(IDMExtModule* DM)=0;

   __property IDMExtModulePriv * DMPriv = {read = get_DMPriv , write = set_DMPriv};
   virtual IDMExtModulePriv * get_DMPriv(void)=0;
   virtual void set_DMPriv(IDMExtModulePriv * DMPriv)=0;

   __property __int64 IdModule = {read = get_IdModule , write = set_IdModule};
   virtual __int64 get_IdModule(void)=0;
   virtual void set_IdModule(__int64 IdModule)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaExtModule __uuidof(IFormaElementaExtModule)
#endif
