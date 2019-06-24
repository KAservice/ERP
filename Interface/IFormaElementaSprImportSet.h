#ifndef UIFormaElementaSprImportSetH
#define UIFormaElementaSprImportSetH
#include "IMainInterface.h"
#include "IDMSprImportSet.h"
class __declspec(uuid("{F93E7945-9DDE-45D8-9487-748C2FC75684}")) IFormaElementaSprImportSet : public IMainInterface
{
public:
   __property IDMSprImportSet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprImportSet * get_DM(void)=0;
   virtual void set_DM(IDMSprImportSet * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprImportSet __uuidof(IFormaElementaSprImportSet)
#endif
