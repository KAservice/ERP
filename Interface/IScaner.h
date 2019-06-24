#ifndef UIScanerH
#define UIScanerH
#include "IMainInterface.h"
class __declspec(uuid("{98C0D910-73A8-4849-B867-7E04C59E34BB}")) IScaner : public IMainInterface
{
public:
   __property int Number = {read = get_Number , write = set_Number};
   virtual int get_Number(void)=0;
   virtual void set_Number(int Number)=0;

   __property AnsiString Modul = {read = get_Modul , write = set_Modul};
   virtual AnsiString get_Modul(void)=0;
   virtual void set_Modul(AnsiString Modul)=0;

   __property UnicodeString NameScaner = {read = get_NameScaner , write = set_NameScaner};
   virtual UnicodeString get_NameScaner(void)=0;
   virtual void set_NameScaner(UnicodeString NameScaner)=0;

   __property bool ConnectScaner = {read = get_ConnectScaner , write = set_ConnectScaner};
   virtual bool get_ConnectScaner(void)=0;
   virtual void set_ConnectScaner(bool ConnectScaner)=0;

   virtual bool InitDevice()=0;
   virtual UnicodeString ReadShtrihCod(void)=0;
   virtual bool  Connect(UnicodeString port ,UnicodeString baud_rate)=0;
   virtual void Disconnect(void)=0;
   virtual UnicodeString GetTextError(void)=0;
};
#define IID_IScaner __uuidof(IScaner)
#endif
