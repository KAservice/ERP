#ifndef UREM_FormaInfoPriemImplH
#define UREM_FormaInfoPriemImplH
#include "IREM_FormaInfoPriem.h"
#include "UREM_FormaInfoPriem.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaInfoPriemImpl)) TREM_FormaInfoPriemImpl : public IREM_FormaInfoPriem, IkanCallBack ,IAsyncExternalEvent
{
public:
   TREM_FormaInfoPriemImpl();
   ~TREM_FormaInfoPriemImpl();
   TREM_FormaInfoPriem * Object;
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


   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IREM_FormaInfoPriem
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

};
#define CLSID_TREM_FormaInfoPriemImpl __uuidof(TREM_FormaInfoPriemImpl)
#endif
