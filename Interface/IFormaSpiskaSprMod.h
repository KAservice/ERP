#ifndef UIFormaSpiskaSprModH
#define UIFormaSpiskaSprModH
#include "IMainInterface.h"
#include "IDMSprMod.h"
class __declspec(uuid("{9955837F-BBF1-4449-9E29-45C253870741}")) IFormaSpiskaSprMod : public IMainInterface
{
public:
   __property IDMSprMod * DM = {read = get_DM , write = set_DM};
   virtual IDMSprMod * get_DM(void)=0;
   virtual void set_DM(IDMSprMod * DM)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprMod __uuidof(IFormaSpiskaSprMod)
#endif
