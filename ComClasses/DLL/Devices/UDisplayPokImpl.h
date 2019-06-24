#ifndef UDisplayPokImplH
#define UDisplayPokImplH
#include "IDisplayPok.h"
#include "UDisplayPok.h"
//---------------------------------------------------------------
class __declspec(uuid("{0A9FC39E-7129-4C09-9183-8C4CDB439395}")) TDisplayPokImpl : public IDisplayPok
{
public:
   TDisplayPokImpl();
   ~TDisplayPokImpl();
   TDisplayPok * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDisplayPok
   virtual AnsiString get_Modul(void);
   virtual void set_Modul(AnsiString Modul);

   virtual bool InitDevice();
   virtual bool Connect(int port, int baud_rate);
   virtual void Disconnect(void);
   virtual bool ShowString1(UnicodeString str, int size_font,int style_font,int alignment);
   virtual bool ShowString2(UnicodeString str, int size_font,int style_font,int alignment);
   virtual bool ShowText(UnicodeString str, int size_font,	int style_font,	int alignment, bool word_wrap);
};
#define CLSID_TDisplayPokImpl __uuidof(TDisplayPokImpl)
#endif
