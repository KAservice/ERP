#ifndef UIHOT_FormaGurAllDocH
#define UIHOT_FormaGurAllDocH
#include "IMainInterface.h"
#include "IHOT_DMGurAllDoc.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_GurAllDoc))IHOT_FormaGurAllDoc : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IHOT_DMGurAllDoc * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMGurAllDoc * get_DM(void)=0;
   virtual void set_DM(IHOT_DMGurAllDoc * DM)=0;

   __property __int64 IdDocH = {read = get_IdDocH , write = set_IdDocH};
   virtual __int64 get_IdDocH(void)=0;
   virtual void set_IdDocH(__int64 IdDocH)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property UnicodeString NameKlient = {read = get_NameKlient , write = set_NameKlient};
   virtual UnicodeString get_NameKlient(void)=0;
   virtual void set_NameKlient(UnicodeString NameKlient)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property UnicodeString NameSklad = {read = get_NameSklad , write = set_NameSklad};
   virtual UnicodeString get_NameSklad(void)=0;
   virtual void set_NameSklad(UnicodeString NameSklad)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property UnicodeString NameFirm = {read = get_NameFirm , write = set_NameFirm};
   virtual UnicodeString get_NameFirm(void)=0;
   virtual void set_NameFirm(UnicodeString NameFirm)=0;

   __property UnicodeString StringTypeDoc = {read = get_StringTypeDoc , write = set_StringTypeDoc};
   virtual UnicodeString get_StringTypeDoc(void)=0;
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc)=0;

   __property UnicodeString NameTypeDoc = {read = get_NameTypeDoc , write = set_NameTypeDoc};
   virtual UnicodeString get_NameTypeDoc(void)=0;
   virtual void set_NameTypeDoc(UnicodeString NameTypeDoc)=0;

   __property bool OtborPoKlientu = {read = get_OtborPoKlientu , write = set_OtborPoKlientu};
   virtual bool get_OtborPoKlientu(void)=0;
   virtual void set_OtborPoKlientu(bool OtborPoKlientu)=0;

   __property bool OtborPoFirm = {read = get_OtborPoFirm , write = set_OtborPoFirm};
   virtual bool get_OtborPoFirm(void)=0;
   virtual void set_OtborPoFirm(bool OtborPoFirm)=0;

   __property bool OtborPoSklad = {read = get_OtborPoSklad , write = set_OtborPoSklad};
   virtual bool get_OtborPoSklad(void)=0;
   virtual void set_OtborPoSklad(bool OtborPoSklad)=0;

   __property bool OtborPoTypeDoc = {read = get_OtborPoTypeDoc , write = set_OtborPoTypeDoc};
   virtual bool get_OtborPoTypeDoc(void)=0;
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc)=0;

};
#define IID_IHOT_FormaGurAllDoc __uuidof(IHOT_FormaGurAllDoc)
#endif
