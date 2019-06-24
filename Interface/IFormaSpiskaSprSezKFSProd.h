#ifndef UIFormaSpiskaSprSezKFSProdH
#define UIFormaSpiskaSprSezKFSProdH
#include "IMainInterface.h"
#include "IDMSprSezKFSProd.h"
class __declspec(uuid("{AD4EEED2-8077-4EB8-B495-B2BADCCCE814}"))IFormaSpiskaSprSezKFSProd : public IMainInterface
{
public:
   __property IDMSprSezKFSProd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprSezKFSProd * get_DM(void)=0;
   virtual void set_DM(IDMSprSezKFSProd * DM)=0;

   __property __int64 IdSProd = {read = get_IdSProd , write = set_IdSProd};
   virtual __int64 get_IdSProd(void)=0;
   virtual void set_IdSProd(__int64 IdSProd)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprSezKFSProd __uuidof(IFormaSpiskaSprSezKFSProd)
#endif
