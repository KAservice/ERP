#ifndef UIFormaSpiskaSprSezKFH
#define UIFormaSpiskaSprSezKFH
#include "IMainInterface.h"
#include "IDMSprSezKF.h"
class __declspec(uuid("{04CE4B0C-BCA2-4F96-8A72-15A902D0F001}")) IFormaSpiskaSprSezKF : public IMainInterface
{
public:
   __property IDMSprSezKF * DM = {read = get_DM , write = set_DM};
   virtual IDMSprSezKF * get_DM(void)=0;
   virtual void set_DM(IDMSprSezKF * DM)=0;

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
#define IID_IFormaSpiskaSprSezKF __uuidof(IFormaSpiskaSprSezKF)
#endif
