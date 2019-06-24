#ifndef UIFormaSpiskaTableNumberDocH
#define UIFormaSpiskaTableNumberDocH
#include "IMainInterface.h"
#include "IDMTableNumberDoc.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaTableNumberDoc))IFormaSpiskaTableNumberDoc : public IMainInterface
{
public:
   __property IDMTableNumberDoc * DM = {read = get_DM , write = set_DM};
   virtual IDMTableNumberDoc * get_DM(void)=0;
   virtual void set_DM(IDMTableNumberDoc * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaTableNumberDoc __uuidof(IFormaSpiskaTableNumberDoc)
#endif
