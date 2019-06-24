#ifndef UFormaArmKassirImplH
#define UFormaArmKassirImplH
#include "IFormaArmKassir.h"
#include "UFormaArmKassir.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaArmKassirImpl)) TFormaArmKassirImpl :
			public IFormaArmKassir,IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaArmKassirImpl();
   ~TFormaArmKassirImpl();
   TFormaARMKassir * Object;
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
	virtual int kanExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);

   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IFormaArmKassir
   virtual IDMDocCheck * get_DM(void);
   virtual void set_DM(IDMDocCheck * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_VibTovarId(void);
   virtual void set_VibTovarId(__int64 VibTovarId);

   virtual __int64 get_VibTovarIdGrp(void);
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp);

   virtual bool get_OutReady(void);
   virtual void set_OutReady(bool OutReady);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual AnsiString get_NameTypePrice(void);
   virtual void set_NameTypePrice(AnsiString NameTypePrice);

   virtual bool get_CheckSave(void);
   virtual void set_CheckSave(bool CheckSave);

   virtual bool get_CheckPrint(void);
   virtual void set_CheckPrint(bool CheckPrint);

   virtual bool get_CheckProveden(void);
   virtual void set_CheckProveden(bool CheckProveden);

   virtual String get_StrPrint(void);
   virtual void set_StrPrint(String StrPrint);

   virtual bool get_CheckCreate(void);
   virtual void set_CheckCreate(bool CheckCreate);

   virtual __int64 get_IdARM(void);
   virtual void set_IdARM(__int64 IdARM);

   virtual bool get_ExternalCreateCheck(void);
   virtual void set_ExternalCreateCheck(bool ExternalCreateCheck);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual bool BeforeEditCheck(void);
   virtual bool BeforeCreateNewCheck(void);
   virtual void CreateNewDocCheck(void);
   virtual void CreateNewDocCheckVosvrat(void);
   virtual bool PrintCheck(bool povtor);
   virtual bool SaveCheck(void);
   virtual void UpdateForm(void);
   virtual void UpdateSetup(void);
   virtual void UpdateParameterFR(void);
   virtual void PrintDocCheck(void);
   virtual void UpdateValuesDiscount(void);
   virtual void ValidateOstatok(double treb_kol);
   virtual bool CreateCheckNaOsnRealRemont(__int64 id_doc_real_remont);
};
#define CLSID_TFormaArmKassirImpl __uuidof(TFormaArmKassirImpl)
#endif
