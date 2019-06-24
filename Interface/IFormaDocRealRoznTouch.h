#ifndef UIFormaDocRealRoznTouchH
#define UIFormaDocRealRoznTouchH
#include "IMainInterface.h"
#include "IDMDocRealRozn.h"
class __declspec(uuid("{42635283-D569-4628-8FC0-3591A35D0FC7}"))IFormaDocRealRoznTouch : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property IDMDocRealRozn * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRealRozn * get_DM(void)=0;
   virtual void set_DM(IDMDocRealRozn * DM)=0;

   __property UnicodeString NameFirm = {read = get_NameFirm , write = set_NameFirm};
   virtual UnicodeString get_NameFirm(void)=0;
   virtual void set_NameFirm(UnicodeString NameFirm)=0;

   __property UnicodeString NameSklad = {read = get_NameSklad , write = set_NameSklad};
   virtual UnicodeString get_NameSklad(void)=0;
   virtual void set_NameSklad(UnicodeString NameSklad)=0;

   __property UnicodeString NameKlient = {read = get_NameKlient , write = set_NameKlient};
   virtual UnicodeString get_NameKlient(void)=0;
   virtual void set_NameKlient(UnicodeString NameKlient)=0;

   __property UnicodeString NameDoc = {read = get_NameDoc , write = set_NameDoc};
   virtual UnicodeString get_NameDoc(void)=0;
   virtual void set_NameDoc(UnicodeString NameDoc)=0;

   __property UnicodeString Prim = {read = get_Prim , write = set_Prim};
   virtual UnicodeString get_Prim(void)=0;
   virtual void set_Prim(UnicodeString Prim)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocRealRoznTouch __uuidof(IFormaDocRealRoznTouch)
#endif
