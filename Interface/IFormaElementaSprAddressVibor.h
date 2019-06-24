#ifndef UIFormaElementaSprAddressViborH
#define UIFormaElementaSprAddressViborH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressRegion.h"
#include "IDMSprAddressRayon.h"
#include "IDMSprAddressNasPunkt.h"
#include "IDMSprAddressStreet.h"
#include "IDMSprAddressDom.h"
#include "IDMSprAddressStroen.h"
#include "IDMSprAddressKV.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressVibor)) IFormaElementaSprAddressVibor : public IMainInterface
{
public:
   __property IDMSprAddressRegion * DM_Region = {read = get_DM_Region , write = set_DM_Region};
   virtual IDMSprAddressRegion * get_DM_Region(void)=0;
   virtual void set_DM_Region(IDMSprAddressRegion * DM_Region)=0;

   __property IDMSprAddressRayon * DM_Rayon = {read = get_DM_Rayon , write = set_DM_Rayon};
   virtual IDMSprAddressRayon * get_DM_Rayon(void)=0;
   virtual void set_DM_Rayon(IDMSprAddressRayon * DM_Rayon)=0;

   __property IDMSprAddressNasPunkt * DM_NasPunkt = {read = get_DM_NasPunkt , write = set_DM_NasPunkt};
   virtual IDMSprAddressNasPunkt * get_DM_NasPunkt(void)=0;
   virtual void set_DM_NasPunkt(IDMSprAddressNasPunkt * DM_NasPunkt)=0;

   __property IDMSprAddressStreet * DM_Street = {read = get_DM_Street , write = set_DM_Street};
   virtual IDMSprAddressStreet * get_DM_Street(void)=0;
   virtual void set_DM_Street(IDMSprAddressStreet * DM_Street)=0;

   __property IDMSprAddressDom * DM_Dom = {read = get_DM_Dom , write = set_DM_Dom};
   virtual IDMSprAddressDom * get_DM_Dom(void)=0;
   virtual void set_DM_Dom(IDMSprAddressDom * DM_Dom)=0;

   __property IDMSprAddressStroen * DM_Stroen = {read = get_DM_Stroen , write = set_DM_Stroen};
   virtual IDMSprAddressStroen * get_DM_Stroen(void)=0;
   virtual void set_DM_Stroen(IDMSprAddressStroen * DM_Stroen)=0;

   __property IDMSprAddressKV * DM_KV = {read = get_DM_KV , write = set_DM_KV};
   virtual IDMSprAddressKV * get_DM_KV(void)=0;
   virtual void set_DM_KV(IDMSprAddressKV * DM_KV)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressVibor __uuidof(IFormaElementaSprAddressVibor)
#endif
