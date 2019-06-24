#ifndef UIFormaSpiskaSprDocKlientH
#define UIFormaSpiskaSprDocKlientH
#include "IMainInterface.h"
#include "IDMSprDocKlient.h"
class __declspec(uuid("{4E0A1129-9E4F-434E-B70E-93C78444CDC1}")) IFormaSpiskaSprDocKlient : public IMainInterface
{
public:
   __property IDMSprDocKlient * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDocKlient * get_DM(void)=0;
   virtual void set_DM(IDMSprDocKlient * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprDocKlient __uuidof(IFormaSpiskaSprDocKlient)
#endif
