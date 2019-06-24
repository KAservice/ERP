#ifndef UIFormaSpiskaTableExtPrintFormH
#define UIFormaSpiskaTableExtPrintFormH
#include "IMainInterface.h"
#include "IDMTableExtPrintForm.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaTableExtPrintForm)) IFormaSpiskaTableExtPrintForm : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMTableExtPrintForm * DM = {read = get_DM , write = set_DM};
   virtual IDMTableExtPrintForm * get_DM(void)=0;
   virtual void set_DM(IDMTableExtPrintForm * DM)=0;

};
#define IID_IFormaSpiskaTableExtPrintForm __uuidof(IFormaSpiskaTableExtPrintForm)
#endif
