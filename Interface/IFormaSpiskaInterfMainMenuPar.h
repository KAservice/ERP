#ifndef UIFormaSpiskaInterfMainMenuParH
#define UIFormaSpiskaInterfMainMenuParH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMInterfMainMenuPar.h"
class __declspec(uuid(Global_IID_IFormaSpiskaInterfMainMenuPar)) IFormaSpiskaInterfMainMenuPar : public IMainInterface
{
public:
   __property IDMInterfMainMenuPar* DM = {read = get_DM , write = set_DM};
   virtual IDMInterfMainMenuPar* get_DM(void)=0;
   virtual void set_DM(IDMInterfMainMenuPar* DM)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property UnicodeString TextHeader = {read = get_TextHeader , write = set_TextHeader};
   virtual UnicodeString get_TextHeader(void)=0;
   virtual void set_TextHeader(UnicodeString TextHeader)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaInterfMainMenuPar __uuidof(IFormaSpiskaInterfMainMenuPar)
#endif
