#ifndef UIFormaGurPlatH
#define UIFormaGurPlatH
#include "IMainInterface.h"
#include "IDMGurPlat.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaGurPlat)) IFormaGurPlat : public IMainInterface
{
public:
   __property IDMGurPlat * DM = {read = get_DM , write = set_DM};
   virtual IDMGurPlat * get_DM(void)=0;
   virtual void set_DM(IDMGurPlat * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdPlat = {read = get_IdPlat , write = set_IdPlat};
   virtual __int64 get_IdPlat(void)=0;
   virtual void set_IdPlat(__int64 IdPlat)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property bool NoOnlyOut = {read = get_NoOnlyOut , write = set_NoOnlyOut};
   virtual bool get_NoOnlyOut(void)=0;
   virtual void set_NoOnlyOut(bool NoOnlyOut)=0;

   __property AnsiString CodeTel = {read = get_CodeTel , write = set_CodeTel};
   virtual AnsiString get_CodeTel(void)=0;
   virtual void set_CodeTel(AnsiString CodeTel)=0;

};
#define IID_IFormaGurPlat __uuidof(IFormaGurPlat)
#endif
