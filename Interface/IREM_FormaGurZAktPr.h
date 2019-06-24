#ifndef UIREM_FormaGurZAktPrH
#define UIREM_FormaGurZAktPrH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMGurZAktPr.h"
class __declspec(uuid(Global_IID_IREM_FormaGurZAktPr)) IREM_FormaGurZAktPr : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMGurZAktPr * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMGurZAktPr * get_DM(void)=0;
   virtual void set_DM(IREM_DMGurZAktPr * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdVibHardware = {read = get_IdVibHardware , write = set_IdVibHardware};
   virtual __int64 get_IdVibHardware(void)=0;
   virtual void set_IdVibHardware(__int64 IdVibHardware)=0;

   __property __int64 IdVibZayavka = {read = get_IdVibZayavka , write = set_IdVibZayavka};
   virtual __int64 get_IdVibZayavka(void)=0;
   virtual void set_IdVibZayavka(__int64 IdVibZayavka)=0;

   virtual void UpdateForm(void)=0;
   virtual void OpenTable(void)=0;
};
#define IID_IREM_FormaGurZAktPr __uuidof(IREM_FormaGurZAktPr)
#endif
