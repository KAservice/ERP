#ifndef UIREM_FormaElementaSprProducerModelH
#define UIREM_FormaElementaSprProducerModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerModel.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerModel)) IREM_FormaElementaSprProducerModel : public IMainInterface
{
public:
   __property IREM_DMSprProducerModel* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerModel* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerModel* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString NameGroupElement = {read = get_NameGroupElement , write = set_NameGroupElement};
   virtual UnicodeString get_NameGroupElement(void)=0;
   virtual void set_NameGroupElement(UnicodeString NameGroupElement)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property UnicodeString NameGroup = {read = get_NameGroup , write = set_NameGroup};
   virtual UnicodeString get_NameGroup(void)=0;
   virtual void set_NameGroup(UnicodeString NameGroup)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool SaveElement = {read = get_SaveElement , write = set_SaveElement};
   virtual bool get_SaveElement(void)=0;
   virtual void set_SaveElement(bool SaveElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprProducerModel __uuidof(IREM_FormaElementaSprProducerModel)
#endif
