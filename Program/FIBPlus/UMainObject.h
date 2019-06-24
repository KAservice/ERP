//---------------------------------------------------------------------------

#ifndef UMainObjectH
#define UMainObjectH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
#include "IMainInterface.h"
#include "IConnectionInterface.h"
#include "IMainCOMInterface.h"
#include "IDevices.h"
#include "IAsyncExternalEvent.h"
#include "IScaner.h"
#include "IFiskReg.h"
#include "IDisplayPok.h"
//---------------------------------------------------------------
class __declspec(uuid("{8C0718FB-B75F-49EB-ADC4-C67474AE516B}")) TMainObject
			 : public IMainInterface, IConnectionInterface,IMainCOMInterface, IAsyncExternalEvent, IDevices
{
public:
   TMainObject();
   ~TMainObject();
   int NumRefs;

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

   //IConnectionInterface
   virtual IDMFibConnection * GetFibConnection(void);

   //IMainCOMInterface
   virtual IkanCom * GetCOM(void);

	//IAsyncExternalEvent
	virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);
	virtual int AsyncExternalEvent(char * object, char* event, char* data);

	//IDevices
	virtual int  GetDeviceObject(int type_interface_device, void** ppv);


		IFiskReg * glFR;
		IDisplayPok * glDisplayPok;




	int CodeError;
	UnicodeString TextError;

	//Подключение
	IDMFibConnection * DM_Connection;

	//global COM
	IkanCom * InterfaceGlobalCom;

	//Внешние события
	IAsyncExternalEvent * InterfaceForExternalEvent; //куда переправить внешнее событие
};
#define CLSID_TMainObject __uuidof(TMainObject)
#endif
