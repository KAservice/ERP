#ifndef UIDisplayPokH
#define UIDisplayPokH
#include "IMainInterface.h"
class __declspec(uuid("{58E76C7E-1BBB-4CCE-8930-156C68F8B6E7}")) IDisplayPok : public IMainInterface
{
public:
   __property AnsiString Modul = {read = get_Modul , write = set_Modul};
   virtual AnsiString get_Modul(void)=0;
   virtual void set_Modul(AnsiString Modul)=0;

   virtual bool InitDevice()=0;
   virtual bool Connect(int port, int baud_rate)=0;
   virtual void Disconnect(void)=0;
   virtual bool ShowString1(UnicodeString str, int size_font,int style_font,int alignment)=0;
   virtual bool ShowString2(UnicodeString str, int size_font,int style_font,int alignment)=0;
   virtual bool ShowText(UnicodeString str, int size_font,	int style_font,	int alignment, bool word_wrap)=0;
};
#define IID_IDisplayPok __uuidof(IDisplayPok)
#endif
