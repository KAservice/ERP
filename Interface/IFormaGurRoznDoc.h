#ifndef UIFormaGurRoznDocH
#define UIFormaGurRoznDocH
#include "IMainInterface.h"
#include "IDMGurRoznDoc.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaGurRoznDoc))IFormaGurRoznDoc : public IMainInterface
{
public:
   __property IDMGurRoznDoc * DM = {read = get_DM , write = set_DM};
   virtual IDMGurRoznDoc * get_DM(void)=0;
   virtual void set_DM(IDMGurRoznDoc * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

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

   __property UnicodeString StringTypeDoc = {read = get_StringTypeDoc , write = set_StringTypeDoc};
   virtual UnicodeString get_StringTypeDoc(void)=0;
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc)=0;

   __property UnicodeString NameTypeDoc = {read = get_NameTypeDoc , write = set_NameTypeDoc};
   virtual UnicodeString get_NameTypeDoc(void)=0;
   virtual void set_NameTypeDoc(UnicodeString NameTypeDoc)=0;

   __property UnicodeString StringFullTypeDoc = {read = get_StringFullTypeDoc , write = set_StringFullTypeDoc};
   virtual UnicodeString get_StringFullTypeDoc(void)=0;
   virtual void set_StringFullTypeDoc(UnicodeString StringFullTypeDoc)=0;

   __property bool OtborPoKlientu = {read = get_OtborPoKlientu , write = set_OtborPoKlientu};
   virtual bool get_OtborPoKlientu(void)=0;
   virtual void set_OtborPoKlientu(bool OtborPoKlientu)=0;

   __property bool OtborPoTypeDoc = {read = get_OtborPoTypeDoc , write = set_OtborPoTypeDoc};
   virtual bool get_OtborPoTypeDoc(void)=0;
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc)=0;

};
#define IID_IFormaGurRoznDoc __uuidof(IFormaGurRoznDoc)
#endif
