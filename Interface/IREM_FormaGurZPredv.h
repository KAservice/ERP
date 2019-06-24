#ifndef UIREM_FormaGurZPredvH
#define UIREM_FormaGurZPredvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMGurZPredv.h"
class __declspec(uuid(Global_IID_IREM_FormaGurZPredv)) IREM_FormaGurZPredv : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMGurZPredv * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMGurZPredv * get_DM(void)=0;
   virtual void set_DM(IREM_DMGurZPredv * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

};
#define IID_IREM_FormaGurZPredv __uuidof(IREM_FormaGurZPredv)
#endif
