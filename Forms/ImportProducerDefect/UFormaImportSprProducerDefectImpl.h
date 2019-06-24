#ifndef UFormaImportSprProducerDefectImplH
#define UFormaImportSprProducerDefectImplH
#include "IFormaImportSprProducerDefect.h"
#include "UFormaImportSprProducerDefect.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaImportSprProducerDefectImpl)) TFormaImportSprProducerDefectImpl : public IFormaImportSprProducerDefect, IkanCallBack
{
public:
   TFormaImportSprProducerDefectImpl();
   ~TFormaImportSprProducerDefectImpl();
   TFormaImportSprProducerDefect * Object;
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

//IFormaImportSprProducerDefect
   virtual __int64 get_IdInfBase(void);
   virtual void set_IdInfBase(__int64 IdInfBase);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual __int64 get_IdProducer(void);
   virtual void set_IdProducer(__int64 IdProducer);

   virtual __int64 get_IdImportSet(void);
   virtual void set_IdImportSet(__int64 IdImportSet);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaImportSprProducerDefectImpl __uuidof(TFormaImportSprProducerDefectImpl)
#endif
