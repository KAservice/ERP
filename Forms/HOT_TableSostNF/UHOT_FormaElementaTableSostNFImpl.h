#ifndef UHOT_FormaElementaTableSostNFImplH
#define UHOT_FormaElementaTableSostNFImplH
#include "IHOT_FormaElementaTableSostNF.h"
#include "UHOT_FormaElementaTableSostNF.h"
//---------------------------------------------------------------
class __declspec(uuid("{2611F718-16D2-4369-84E7-3B6AEFB258A5}")) THOT_FormaElementaTableSostNFImpl : public IHOT_FormaElementaTableSostNF, IkanCallBack
{
public:
   THOT_FormaElementaTableSostNFImpl();
   ~THOT_FormaElementaTableSostNFImpl();
   THOT_FormaElementaTableSostNF * Object;
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

   //IkanCallBack  
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

//IHOT_FormaElementaTableSostNF
   virtual IHOT_DMTableSostNF * get_DM(void);
   virtual void set_DM(IHOT_DMTableSostNF * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaTableSostNFImpl __uuidof(THOT_FormaElementaTableSostNFImpl)
#endif
