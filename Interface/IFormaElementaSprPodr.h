#ifndef UIFormaElementaSprPodrH
#define UIFormaElementaSprPodrH
#include "IMainInterface.h"
#include "IDMSprPodr.h"
class __declspec(uuid("{D71631A2-7F6A-4CC3-B4EC-F3897377F4E3}"))IFormaElementaSprPodr : public IMainInterface
{
public:
   __property IDMSprPodr * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPodr * get_DM(void)=0;
   virtual void set_DM(IDMSprPodr * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprPodr __uuidof(IFormaElementaSprPodr)
#endif
