#ifndef UIREM_FormaSpiskaSprTypeDeviceH
#define UIREM_FormaSpiskaSprTypeDeviceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprTypeDevice.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprTypeDevice)) IREM_FormaSpiskaSprTypeDevice : public IMainInterface
{
public:
   __property IREM_DMSprTypeDevice * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprTypeDevice * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprTypeDevice * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString TextHeader = {read = get_TextHeader , write = set_TextHeader};
   virtual UnicodeString get_TextHeader(void)=0;
   virtual void set_TextHeader(UnicodeString TextHeader)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprTypeDevice __uuidof(IREM_FormaSpiskaSprTypeDevice)
#endif
