#ifndef UIREM_FormaGurCustQueryH
#define UIREM_FormaGurCustQueryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMGurCustQuery.h"
class __declspec(uuid(Global_IID_IREM_FormaGurCustQuery)) IREM_FormaGurCustQuery : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMGurCustQuery * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMGurCustQuery * get_DM(void)=0;
   virtual void set_DM(IREM_DMGurCustQuery * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdVibZayavka = {read = get_IdVibZayavka , write = set_IdVibZayavka};
   virtual __int64 get_IdVibZayavka(void)=0;
   virtual void set_IdVibZayavka(__int64 IdVibZayavka)=0;

   __property UnicodeString Zayavka_NameKlient = {read = get_Zayavka_NameKlient , write = set_Zayavka_NameKlient};
   virtual UnicodeString get_Zayavka_NameKlient(void)=0;
   virtual void set_Zayavka_NameKlient(UnicodeString Zayavka_NameKlient)=0;

   __property UnicodeString Zayavka_NameModel = {read = get_Zayavka_NameModel , write = set_Zayavka_NameModel};
   virtual UnicodeString get_Zayavka_NameModel(void)=0;
   virtual void set_Zayavka_NameModel(UnicodeString Zayavka_NameModel)=0;

   __property UnicodeString Zayavka_SerNum = {read = get_Zayavka_SerNum , write = set_Zayavka_SerNum};
   virtual UnicodeString get_Zayavka_SerNum(void)=0;
   virtual void set_Zayavka_SerNum(UnicodeString Zayavka_SerNum)=0;

   __property UnicodeString Zayavka_SerNum2 = {read = get_Zayavka_SerNum2 , write = set_Zayavka_SerNum2};
   virtual UnicodeString get_Zayavka_SerNum2(void)=0;
   virtual void set_Zayavka_SerNum2(UnicodeString Zayavka_SerNum2)=0;

   __property UnicodeString Zayavka_Name = {read = get_Zayavka_Name , write = set_Zayavka_Name};
   virtual UnicodeString get_Zayavka_Name(void)=0;
   virtual void set_Zayavka_Name(UnicodeString Zayavka_Name)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaGurCustQuery __uuidof(IREM_FormaGurCustQuery)
#endif
