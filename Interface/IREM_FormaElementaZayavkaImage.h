#ifndef UIREM_FormaElementaZayavkaImageH
#define UIREM_FormaElementaZayavkaImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMZayavkaImage.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaZayavkaImage)) IREM_FormaElementaZayavkaImage : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMZayavkaImage* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMZayavkaImage* get_DM(void)=0;
   virtual void set_DM(IREM_DMZayavkaImage* DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaZayavkaImage __uuidof(IREM_FormaElementaZayavkaImage)
#endif
