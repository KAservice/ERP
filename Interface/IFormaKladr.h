#ifndef UIFormaKladrH
#define UIFormaKladrH
#include "IMainInterface.h"
class __declspec(uuid("{4824B134-5F78-40D1-8165-DD72BE960FBA}")) IFormaKladr : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property AnsiString KladrPatch = {read = get_KladrPatch , write = set_KladrPatch};
   virtual AnsiString get_KladrPatch(void)=0;
   virtual void set_KladrPatch(AnsiString KladrPatch)=0;

   __property AnsiString NameRegion = {read = get_NameRegion , write = set_NameRegion};
   virtual AnsiString get_NameRegion(void)=0;
   virtual void set_NameRegion(AnsiString NameRegion)=0;

   __property AnsiString NameRayon = {read = get_NameRayon , write = set_NameRayon};
   virtual AnsiString get_NameRayon(void)=0;
   virtual void set_NameRayon(AnsiString NameRayon)=0;

   __property AnsiString NameGorod = {read = get_NameGorod , write = set_NameGorod};
   virtual AnsiString get_NameGorod(void)=0;
   virtual void set_NameGorod(AnsiString NameGorod)=0;

   __property AnsiString NameNasPunkt = {read = get_NameNasPunkt , write = set_NameNasPunkt};
   virtual AnsiString get_NameNasPunkt(void)=0;
   virtual void set_NameNasPunkt(AnsiString NameNasPunkt)=0;

};
#define IID_IFormaKladr __uuidof(IFormaKladr)
#endif
