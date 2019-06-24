#ifndef UIFormaSpiskaSprNomPropertiesValueH
#define UIFormaSpiskaSprNomPropertiesValueH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprNomPropertiesValue.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprNomPropertiesValue)) IFormaSpiskaSprNomPropertiesValue : public IMainInterface
{
public:
   __property IDMSprNomPropertiesValue * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNomPropertiesValue * get_DM(void)=0;
   virtual void set_DM(IDMSprNomPropertiesValue * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprNomPropertiesValue __uuidof(IFormaSpiskaSprNomPropertiesValue)
#endif
