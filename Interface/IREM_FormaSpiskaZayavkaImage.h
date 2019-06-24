#ifndef UIREM_FormaSpiskaZayavkaImageH
#define UIREM_FormaSpiskaZayavkaImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMZayavkaImage.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaZayavkaImage)) IREM_FormaSpiskaZayavkaImage : public IMainInterface
{
public:
   __property IREM_DMZayavkaImage * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMZayavkaImage * get_DM(void)=0;
   virtual void set_DM(IREM_DMZayavkaImage * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaZayavkaImage __uuidof(IREM_FormaSpiskaZayavkaImage)
#endif
