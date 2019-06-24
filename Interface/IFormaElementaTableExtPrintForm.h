#ifndef UIFormaElementaTableExtPrintFormH
#define UIFormaElementaTableExtPrintFormH
#include "IMainInterface.h"
#include "IDMTableExtPrintForm.h"
class __declspec(uuid("{6A682568-8AAC-4FA3-9FE7-CE3172FDEEFC}")) IFormaElementaTableExtPrintForm : public IMainInterface
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

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaTableExtPrintForm __uuidof(IFormaElementaTableExtPrintForm)
#endif
