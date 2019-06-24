#ifndef UIHOT_FormaElementaTableSostNFH
#define UIHOT_FormaElementaTableSostNFH
#include "IMainInterface.h"
#include "IHOT_DMTableSostNF.h"
class __declspec(uuid("{53795BCF-FBF0-4C48-AEB0-F8450AFB1BF6}")) IHOT_FormaElementaTableSostNF : public IMainInterface
{
public:
   __property IHOT_DMTableSostNF * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMTableSostNF * get_DM(void)=0;
   virtual void set_DM(IHOT_DMTableSostNF * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaTableSostNF __uuidof(IHOT_FormaElementaTableSostNF)
#endif
