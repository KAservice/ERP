#ifndef UIFormaElementaSprGrpKlientH
#define UIFormaElementaSprGrpKlientH
#include "IMainInterface.h"
#include "IDMSprGrpKlient.h"
class __declspec(uuid("{2B6578F0-C18D-404B-896F-4CB3E878F3F9}")) IFormaElementaSprGrpKlient : public IMainInterface
{
public:
   __property IDMSprGrpKlient* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpKlient* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpKlient* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprGrpKlient __uuidof(IFormaElementaSprGrpKlient)
#endif
