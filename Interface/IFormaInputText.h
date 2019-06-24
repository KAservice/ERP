#ifndef UIFormaInputTextH
#define UIFormaInputTextH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaInputText)) IFormaInputText : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString InputText = {read = get_InputText , write = set_InputText};
   virtual UnicodeString get_InputText(void)=0;
   virtual void set_InputText(UnicodeString InputText)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaInputText __uuidof(IFormaInputText)
#endif
