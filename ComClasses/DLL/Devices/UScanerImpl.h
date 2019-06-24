#ifndef UScanerImplH
#define UScanerImplH
#include "IScaner.h"
#include "UScaner.h"
//---------------------------------------------------------------
class __declspec(uuid("{5F58FEBE-83C7-43A3-92E0-C022928F9C31}")) TScanerImpl : public IScaner
{
public:
   TScanerImpl();
   ~TScanerImpl();
   TScaner * Object;
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

//IScaner
   virtual int get_Number(void);
   virtual void set_Number(int Number);

   virtual AnsiString get_Modul(void);
   virtual void set_Modul(AnsiString Modul);

   virtual UnicodeString get_NameScaner(void);
   virtual void set_NameScaner(UnicodeString NameScaner);

   virtual bool get_ConnectScaner(void);
   virtual void set_ConnectScaner(bool ConnectScaner);

   virtual bool InitDevice();
   virtual UnicodeString ReadShtrihCod(void);
   virtual bool  Connect(UnicodeString port ,UnicodeString baud_rate);
   virtual void Disconnect(void);
   virtual UnicodeString GetTextError(void);
};
#define CLSID_TScanerImpl __uuidof(TScanerImpl)
#endif
