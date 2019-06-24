#ifndef UREM_FormaElementaZayavkaImageImplH
#define UREM_FormaElementaZayavkaImageImplH
#include "IREM_FormaElementaZayavkaImage.h"
#include "UREM_FormaElementaZayavkaImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaZayavkaImageImpl)) TREM_FormaElementaZayavkaImageImpl : public IREM_FormaElementaZayavkaImage
{
public:
   TREM_FormaElementaZayavkaImageImpl();
   ~TREM_FormaElementaZayavkaImageImpl();
   TREM_FormaElementaZayavkaImage * Object;
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

//IREM_FormaElementaZayavkaImage
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMZayavkaImage* get_DM(void);
   virtual void set_DM(IREM_DMZayavkaImage* DM);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaZayavkaImageImpl __uuidof(TREM_FormaElementaZayavkaImageImpl)
#endif
