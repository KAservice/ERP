#ifndef UIFormaElementaSprVidImageH
#define UIFormaElementaSprVidImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprVidImage.h"
class __declspec(uuid(Global_IID_IFormaElementaSprVidImage)) IFormaElementaSprVidImage : public IMainInterface
{
public:
   __property IDMSprVidImage * DM = {read = get_DM , write = set_DM};
   virtual IDMSprVidImage * get_DM(void)=0;
   virtual void set_DM(IDMSprVidImage * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};
   virtual UnicodeString get_NameGrp(void)=0;
   virtual void set_NameGrp(UnicodeString NameGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprVidImage __uuidof(IFormaElementaSprVidImage)
#endif
