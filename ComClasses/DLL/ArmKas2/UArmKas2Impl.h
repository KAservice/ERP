//---------------------------------------------------------------------------

#ifndef UArmKas2ImplH
#define UArmKas2ImplH
//---------------------------------------------------------------------------

#include "IMainInterface.h"
#include "IAsyncExternalEvent.h"
#include "UFormaArmKassir2.h"
//---------------------------------------------------------------------------

class __declspec(uuid(Global_CLSID_TFormaARMKas2Impl)) TArmKas2Impl
		: public IMainInterface,IkanCallBack,IAsyncExternalEvent
{
public:
   TArmKas2Impl();
   ~TArmKas2Impl();
   bool flDeleteObject;
   void DeleteImpl(void);

	TFormaARMKassir2 * Object;
	int NumRefs;

	//IUnknown
	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
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

};

#define CLSID_TArmKas2Impl __uuidof(TArmKas2Impl)
#endif
