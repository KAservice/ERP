#ifndef UIFormaElementaSprProducerNomH
#define UIFormaElementaSprProducerNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProducerNom.h"
class __declspec(uuid(Global_IID_IFormaElementaSprProducerNom)) IFormaElementaSprProducerNom : public IMainInterface
{
public:
   __property IDMSprProducerNom * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProducerNom * get_DM(void)=0;
   virtual void set_DM(IDMSprProducerNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdProducerTypePrice = {read = get_IdProducerTypePrice , write = set_IdProducerTypePrice};
   virtual __int64 get_IdProducerTypePrice(void)=0;
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property UnicodeString NameGrpNom = {read = get_NameGrpNom , write = set_NameGrpNom};
   virtual UnicodeString get_NameGrpNom(void)=0;
   virtual void set_NameGrpNom(UnicodeString NameGrpNom)=0;

   __property __int64 IdProducer = {read = get_IdProducer , write = set_IdProducer};
   virtual __int64 get_IdProducer(void)=0;
   virtual void set_IdProducer(__int64 IdProducer)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprProducerNom __uuidof(IFormaElementaSprProducerNom)
#endif
