//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UREM_FormaElementaSprTypeRemontImpl.h"
#include "UREM_FormaElementaSprTypeRemontCF.h"
#include "UREM_FormaSpiskaSprTypeRemontImpl.h"
#include "UREM_FormaSpiskaSprTypeRemontCF.h"
#include "UREM_FormaElementaSprSostImpl.h"
#include "UREM_FormaElementaSprSostCF.h"
#include "UREM_FormaSpiskaSprSostImpl.h"
#include "UREM_FormaSpiskaSprSostCF.h"
#include "UREM_FormaElementaSprGrpNeisprImpl.h"
#include "UREM_FormaElementaSprGrpNeisprCF.h"
#include "UREM_FormaElementaSprNeisprImpl.h"
#include "UREM_FormaElementaSprNeisprCF.h"
#include "UREM_FormaSpiskaSprNeisprImpl.h"
#include "UREM_FormaSpiskaSprNeisprCF.h"
#include "UREM_FormaElementaSprGrpModelImpl.h"
#include "UREM_FormaElementaSprGrpModelCF.h"
#include "UREM_FormaElementaSprKomplModelImpl.h"
#include "UREM_FormaElementaSprKomplModelCF.h"
#include "UREM_FormaSpiskaSprKomplModelImpl.h"
#include "UREM_FormaSpiskaSprKomplModelCF.h"
#include "UREM_FormaElementaSprModelImpl.h"
#include "UREM_FormaElementaSprModelCF.h"
#include "UREM_FormaSpiskaSprModelImpl.h"
#include "UREM_FormaSpiskaSprModelCF.h"
#include "UREM_FormaElementaSprGrpKKTImpl.h"
#include "UREM_FormaElementaSprGrpKKTCF.h"
#include "UREM_FormaSpiskaSprKKTDvImpl.h"
#include "UREM_FormaSpiskaSprKKTDvCF.h"
#include "UREM_FormaElementaSprKKTImpl.h"
#include "UREM_FormaElementaSprKKTCF.h"
#include "UREM_FormaSpiskaSprKKTImpl.h"
#include "UREM_FormaSpiskaSprKKTCF.h"
#include "UREM_FormaElementaSprGrpHardwareImpl.h"
#include "UREM_FormaElementaSprGrpHardwareCF.h"
#include "UREM_FormaElementaSprHardwareImpl.h"
#include "UREM_FormaElementaSprHardwareCF.h"
#include "UREM_FormaSpiskaSprHardwareImpl.h"
#include "UREM_FormaSpiskaSprHardwareCF.h"


#include "UREM_FormaElementaSprProducerModelGrpImpl.h"
#include "UREM_FormaElementaSprProducerModelGrpCF.h"
#include "UREM_FormaElementaSprProducerModelImpl.h"
#include "UREM_FormaElementaSprProducerModelCF.h"
#include "UREM_FormaSpiskaSprProducerModelImpl.h"
#include "UREM_FormaSpiskaSprProducerModelCF.h"


#include "UREM_FormaElementaSprProducerNeisprGrpImpl.h"
#include "UREM_FormaElementaSprProducerNeisprGrpCF.h"
#include "UREM_FormaElementaSprProducerNeisprImpl.h"
#include "UREM_FormaElementaSprProducerNeisprCF.h"
#include "UREM_FormaSpiskaSprProducerNeisprImpl.h"
#include "UREM_FormaSpiskaSprProducerNeisprCF.h"


#include "UREM_FormaElementaSprTypDefectGrpImpl.h"
#include "UREM_FormaElementaSprTypDefectGrpCF.h"
#include "UREM_FormaElementaSprTypDefectImpl.h"
#include "UREM_FormaElementaSprTypDefectCF.h"
#include "UREM_FormaSpiskaSprTypDefectImpl.h"
#include "UREM_FormaSpiskaSprTypDefectCF.h"

#include "UREM_FormaElementaSprTypRabotGrpImpl.h"
#include "UREM_FormaElementaSprTypRabotGrpCF.h"
#include "UREM_FormaElementaSprTypRabotImpl.h"
#include "UREM_FormaElementaSprTypRabotCF.h"
#include "UREM_FormaSpiskaSprTypRabotImpl.h"
#include "UREM_FormaSpiskaSprTypRabotCF.h"

#include "UREM_FormaElementaSprTypUslovGrpImpl.h"
#include "UREM_FormaElementaSprTypUslovGrpCF.h"
#include "UREM_FormaElementaSprTypUslovImpl.h"
#include "UREM_FormaElementaSprTypUslovCF.h"
#include "UREM_FormaSpiskaSprTypUslovImpl.h"
#include "UREM_FormaSpiskaSprTypUslovCF.h"

#include "UREM_FormaElementaSprModelDetalImpl.h"
#include "UREM_FormaElementaSprModelDetalCF.h"
#include "UREM_FormaSpiskaSprModelDetalImpl.h"
#include "UREM_FormaSpiskaSprModelDetalCF.h"

#include "UREM_FormaElementaSprTrebRabotImpl.h"
#include "UREM_FormaElementaSprTrebRabotCF.h"
#include "UREM_FormaSpiskaSprTrebRabotImpl.h"
#include "UREM_FormaSpiskaSprTrebRabotCF.h"

#include "UREM_FormaElementaSprTrebUslovImpl.h"
#include "UREM_FormaElementaSprTrebUslovCF.h"
#include "UREM_FormaSpiskaSprTrebUslovImpl.h"
#include "UREM_FormaSpiskaSprTrebUslovCF.h"

#include "UREM_FormaElementaSprDefectModelNeisprImpl.h"
#include "UREM_FormaElementaSprDefectModelNeisprCF.h"
#include "UREM_FormaSpiskaSprDefectModelNeisprImpl.h"
#include "UREM_FormaSpiskaSprDefectModelNeisprCF.h"

#include "UREM_FormaElementaSprNeisprModelImpl.h"
#include "UREM_FormaElementaSprNeisprModelCF.h"
#include "UREM_FormaSpiskaSprNeisprModelImpl.h"
#include "UREM_FormaSpiskaSprNeisprModelCF.h"

#include "UREM_FormaElementaSprTypeDeviceImpl.h"
#include "UREM_FormaElementaSprTypeDeviceCF.h"
#include "UREM_FormaSpiskaSprTypeDeviceImpl.h"
#include "UREM_FormaSpiskaSprTypeDeviceCF.h"

#include "UREM_FormaElementaSprModel2GrpImpl.h"
#include "UREM_FormaElementaSprModel2GrpCF.h"
#include "UREM_FormaSpiskaSprModel2Impl.h"
#include "UREM_FormaSpiskaSprModel2CF.h"

#include "UREM_FormaElementaSprProducerDefectGrpImpl.h"
#include "UREM_FormaElementaSprProducerDefectGrpCF.h"
#include "UREM_FormaElementaSprProducerDefectImpl.h"
#include "UREM_FormaElementaSprProducerDefectCF.h"
#include "UREM_FormaSpiskaSprProducerDefectImpl.h"
#include "UREM_FormaSpiskaSprProducerDefectCF.h"


#include "UREM_FormaElementaSprHardwareIspImpl.h"
#include "UREM_FormaElementaSprHardwareIspCF.h"
#include "UREM_FormaSpiskaSprHardwareIspImpl.h"
#include "UREM_FormaSpiskaSprHardwareIspCF.h"




#include "UREM_FormaSpiskaSprProducerModelPropertiesValueImpl.h"
#include "UREM_FormaSpiskaSprProducerModelPropertiesValueCF.h"
#include "UREM_FormaElementaSprProducerModelPropertiesValueImpl.h"
#include "UREM_FormaElementaSprProducerModelPropertiesValueCF.h"

#include "UREM_FormaSpiskaSprProducerModelInfBlockImpl.h"
#include "UREM_FormaSpiskaSprProducerModelInfBlockCF.h"
#include "UREM_FormaElementaSprProducerModelInfBlockImpl.h"
#include "UREM_FormaElementaSprProducerModelInfBlockCF.h"



#include "UREM_FormaSpiskaSprModelPropertiesValueImpl.h"
#include "UREM_FormaSpiskaSprModelPropertiesValueCF.h"
#include "UREM_FormaElementaSprModelPropertiesValueImpl.h"
#include "UREM_FormaElementaSprModelPropertiesValueCF.h"

#include "UREM_FormaSpiskaSprModelInfBlockImpl.h"
#include "UREM_FormaSpiskaSprModelInfBlockCF.h"
#include "UREM_FormaElementaSprModelInfBlockImpl.h"
#include "UREM_FormaElementaSprModelInfBlockCF.h"

#include "UREM_FormaElementaSprActCategoryImpl.h"
#include "UREM_FormaElementaSprActCategoryCF.h"
#include "UREM_FormaSpiskaSprActCategoryImpl.h"
#include "UREM_FormaSpiskaSprActCategoryCF.h"


#include "UREM_FormaSpiskaSprProducerRabotaImpl.h"
#include "UREM_FormaSpiskaSprproducerRabotaCF.h"
#include "UREM_FormaElementaSprProducerRabotaImpl.h"
#include "UREM_FormaElementaSprproducerRabotaCF.h"
#include "UREM_FormaElementaSprProducerRabotaGrpImpl.h"
#include "UREM_FormaElementaSprproducerRabotaGrpCF.h"


#include "UREM_FormaSpiskaSprModelTypRabotImpl.h"
#include "UREM_FormaSpiskaSprModelTypRabotCF.h"
#include "UREM_FormaElementaSprModelTypRabotImpl.h"
#include "UREM_FormaElementaSprModelTypRabotCF.h"

#include "UREM_FormaSpiskaSprProducerSectionImpl.h"
#include "UREM_FormaSpiskaSprProducerSectionCF.h"
#include "UREM_FormaElementaSprProducerSectionImpl.h"
#include "UREM_FormaElementaSprProducerSectionCF.h"
#include "UREM_FormaElementaSprProducerSectionGrpImpl.h"
#include "UREM_FormaElementaSprProducerSectionGrpCF.h"

#include "UREM_FormaSpiskaSprProducerConditionImpl.h"
#include "UREM_FormaSpiskaSprProducerConditionCF.h"
#include "UREM_FormaElementaSprProducerConditionImpl.h"
#include "UREM_FormaElementaSprProducerConditionCF.h"
#include "UREM_FormaElementaSprProducerConditionGrpImpl.h"
#include "UREM_FormaElementaSprProducerConditionGrpCF.h"


#include "UREM_FormaSpiskaSprHardwareVZipImpl.h"
#include "UREM_FormaSpiskaSprHardwareVZipCF.h"
//---------------------------------------------------------------------------
extern "C" int __declspec (dllexport) kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);


extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" int __declspec (dllexport) kanRegisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanUnregisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
extern "C" void __declspec (dllexport) kanInit(void);
extern "C" void __declspec (dllexport) kanDone(void);
//---------------------------------------------------------------------------
int NumObject=0;
TApplication * glApp=0;
TApplication * dllApp=0;

TDM *DM=0;



#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{


	return 1;
}
//---------------------------------------------------------------------------
int kanSendApplication(TApplication * app)
{
int result=0;
if (app!=0)
	{
	glApp=app;
	dllApp=Application;
	Application=glApp;
	}


return result;
}
//-----------------------------------------------------------------------------
void kanInit(void)
{
DM=new TDM(Application);

}
//---------------------------------------------------------------------------
void kanDone(void)
{
if(DM) delete DM;
if (dllApp!=0) Application=dllApp;
}

//---------------------------------------------------------------------------
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;

if (id_class==CLSID_TREM_FormaElementaSprTypeRemontImpl)
	{
	TREM_FormaElementaSprTypeRemontCF * ob=new TREM_FormaElementaSprTypeRemontCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTypeRemontImpl)
	{
	TREM_FormaSpiskaSprTypeRemontCF * ob=new TREM_FormaSpiskaSprTypeRemontCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprSostImpl)
	{
	TREM_FormaElementaSprSostCF * ob=new TREM_FormaElementaSprSostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprSostImpl)
	{
	TREM_FormaSpiskaSprSostCF * ob=new TREM_FormaSpiskaSprSostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprGrpNeisprImpl)
	{
	TREM_FormaElementaSprGrpNeisprCF * ob=new TREM_FormaElementaSprGrpNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprNeisprImpl)
	{
	TREM_FormaElementaSprNeisprCF * ob=new TREM_FormaElementaSprNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprNeisprImpl)
	{
	TREM_FormaSpiskaSprNeisprCF * ob=new TREM_FormaSpiskaSprNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprGrpModelImpl)
	{
	TREM_FormaElementaSprGrpModelCF * ob=new TREM_FormaElementaSprGrpModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprKomplModelImpl)
	{
	TREM_FormaElementaSprKomplModelCF * ob=new TREM_FormaElementaSprKomplModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprKomplModelImpl)
	{
	TREM_FormaSpiskaSprKomplModelCF * ob=new TREM_FormaSpiskaSprKomplModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprModelImpl)
	{
	TREM_FormaElementaSprModelCF * ob=new TREM_FormaElementaSprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprModelImpl)
	{
	TREM_FormaSpiskaSprModelCF * ob=new TREM_FormaSpiskaSprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprGrpKKTImpl)
	{
	TREM_FormaElementaSprGrpKKTCF * ob=new TREM_FormaElementaSprGrpKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprKKTDvImpl)
	{
	TREM_FormaSpiskaSprKKTDvCF * ob=new TREM_FormaSpiskaSprKKTDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprKKTImpl)
	{
	TREM_FormaElementaSprKKTCF * ob=new TREM_FormaElementaSprKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprKKTImpl)
	{
	TREM_FormaSpiskaSprKKTCF * ob=new TREM_FormaSpiskaSprKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprGrpHardwareImpl)
	{
	TREM_FormaElementaSprGrpHardwareCF * ob=new TREM_FormaElementaSprGrpHardwareCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprHardwareImpl)
	{
	TREM_FormaElementaSprHardwareCF * ob=new TREM_FormaElementaSprHardwareCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprHardwareVZipImpl)
	{
	TREM_FormaSpiskaSprHardwareVZipCF * ob=new TREM_FormaSpiskaSprHardwareVZipCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprHardwareImpl)
	{
	TREM_FormaSpiskaSprHardwareCF * ob=new TREM_FormaSpiskaSprHardwareCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprProducerModelGrpImpl)
	{
	TREM_FormaElementaSprProducerModelGrpCF * ob=new TREM_FormaElementaSprProducerModelGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerModelImpl)
	{
	TREM_FormaElementaSprProducerModelCF * ob=new TREM_FormaElementaSprProducerModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprProducerModelImpl)
	{
	TREM_FormaSpiskaSprProducerModelCF * ob=new TREM_FormaSpiskaSprProducerModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerNeisprGrpImpl)
	{
	TREM_FormaElementaSprProducerNeisprGrpCF * ob=new TREM_FormaElementaSprProducerNeisprGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerNeisprImpl)
	{
	TREM_FormaElementaSprProducerNeisprCF * ob=new TREM_FormaElementaSprProducerNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprProducerNeisprImpl)
	{
	TREM_FormaSpiskaSprProducerNeisprCF * ob=new TREM_FormaSpiskaSprProducerNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprTypDefectGrpImpl)
	{
	TREM_FormaElementaSprTypDefectGrpCF * ob=new TREM_FormaElementaSprTypDefectGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTypDefectImpl)
	{
	TREM_FormaElementaSprTypDefectCF * ob=new TREM_FormaElementaSprTypDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTypDefectImpl)
	{
	TREM_FormaSpiskaSprTypDefectCF * ob=new TREM_FormaSpiskaSprTypDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprTypRabotGrpImpl)
	{
	TREM_FormaElementaSprTypRabotGrpCF * ob=new TREM_FormaElementaSprTypRabotGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTypRabotImpl)
	{
	TREM_FormaElementaSprTypRabotCF * ob=new TREM_FormaElementaSprTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTypRabotImpl)
	{
	TREM_FormaSpiskaSprTypRabotCF * ob=new TREM_FormaSpiskaSprTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprTypUslovImpl)
	{
	TREM_FormaSpiskaSprTypUslovCF * ob=new TREM_FormaSpiskaSprTypUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTypUslovImpl)
	{
	TREM_FormaElementaSprTypUslovCF * ob=new TREM_FormaElementaSprTypUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTypUslovGrpImpl)
	{
	TREM_FormaElementaSprTypUslovGrpCF * ob=new TREM_FormaElementaSprTypUslovGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprModelDetalImpl)
	{
	TREM_FormaElementaSprModelDetalCF * ob=new TREM_FormaElementaSprModelDetalCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprModelDetalImpl)
	{
	TREM_FormaSpiskaSprModelDetalCF * ob=new TREM_FormaSpiskaSprModelDetalCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTrebRabotImpl)
	{
	TREM_FormaSpiskaSprTrebRabotCF * ob=new TREM_FormaSpiskaSprTrebRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTrebRabotImpl)
	{
	TREM_FormaElementaSprTrebRabotCF * ob=new TREM_FormaElementaSprTrebRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTrebUslovImpl)
	{
	TREM_FormaSpiskaSprTrebUslovCF * ob=new TREM_FormaSpiskaSprTrebUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTrebUslovImpl)
	{
	TREM_FormaElementaSprTrebUslovCF * ob=new TREM_FormaElementaSprTrebUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprDefectModelNeisprImpl)
	{
	TREM_FormaSpiskaSprDefectModelNeisprCF * ob=new TREM_FormaSpiskaSprDefectModelNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprDefectModelNeisprImpl)
	{
	TREM_FormaElementaSprDefectModelNeisprCF * ob=new TREM_FormaElementaSprDefectModelNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}


else if (id_class==CLSID_TREM_FormaSpiskaSprNeisprModelImpl)
	{
	TREM_FormaSpiskaSprNeisprModelCF * ob=new TREM_FormaSpiskaSprNeisprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprNeisprModelImpl)
	{
	TREM_FormaElementaSprNeisprModelCF * ob=new TREM_FormaElementaSprNeisprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprTypeDeviceImpl)
	{
	TREM_FormaSpiskaSprTypeDeviceCF * ob=new TREM_FormaSpiskaSprTypeDeviceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprTypeDeviceImpl)
	{
	TREM_FormaElementaSprTypeDeviceCF * ob=new TREM_FormaElementaSprTypeDeviceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}


else if (id_class==CLSID_TREM_FormaSpiskaSprModel2Impl)
	{
	TREM_FormaSpiskaSprModel2CF * ob=new TREM_FormaSpiskaSprModel2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprModel2GrpImpl)
	{
	TREM_FormaElementaSprModel2GrpCF * ob=new TREM_FormaElementaSprModel2GrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerDefectGrpImpl)
	{
	TREM_FormaElementaSprProducerDefectGrpCF * ob=new TREM_FormaElementaSprProducerDefectGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerDefectImpl)
	{
	TREM_FormaElementaSprProducerDefectCF * ob=new TREM_FormaElementaSprProducerDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprProducerDefectImpl)
	{
	TREM_FormaSpiskaSprProducerDefectCF * ob=new TREM_FormaSpiskaSprProducerDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}


else if (id_class==CLSID_TREM_FormaElementaSprHardwareIspImpl)
	{
	TREM_FormaElementaSprHardwareIspCF * ob=new TREM_FormaElementaSprHardwareIspCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprHardwareIspImpl)
	{
	TREM_FormaSpiskaSprHardwareIspCF * ob=new TREM_FormaSpiskaSprHardwareIspCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_TREM_FormaSpiskaSprProducerModelPropertiesValueImpl)
	{
	TREM_FormaSpiskaSprProducerModelPropertiesValueCF * ob=new TREM_FormaSpiskaSprProducerModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerModelPropertiesValueImpl)
	{
	TREM_FormaElementaSprProducerModelPropertiesValueCF * ob=new TREM_FormaElementaSprProducerModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprModelPropertiesValueImpl)
	{
	TREM_FormaSpiskaSprModelPropertiesValueCF * ob=new TREM_FormaSpiskaSprModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprModelPropertiesValueImpl)
	{
	TREM_FormaElementaSprModelPropertiesValueCF * ob=new TREM_FormaElementaSprModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}


else if (id_class==CLSID_TREM_FormaSpiskaSprProducerModelInfBlockImpl)
	{
	TREM_FormaSpiskaSprProducerModelInfBlockCF * ob=new TREM_FormaSpiskaSprProducerModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerModelInfBlockImpl)
	{
	TREM_FormaElementaSprProducerModelInfBlockCF * ob=new TREM_FormaElementaSprProducerModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprModelInfBlockImpl)
	{
	TREM_FormaSpiskaSprModelInfBlockCF * ob=new TREM_FormaSpiskaSprModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprModelInfBlockImpl)
	{
	TREM_FormaElementaSprModelInfBlockCF * ob=new TREM_FormaElementaSprModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprActCategoryImpl)
	{
	TREM_FormaElementaSprActCategoryCF * ob=new TREM_FormaElementaSprActCategoryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprActCategoryImpl)
	{
	TREM_FormaSpiskaSprActCategoryCF * ob=new TREM_FormaSpiskaSprActCategoryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprProducerRabotaImpl)
	{
	TREM_FormaSpiskaSprProducerRabotaCF * ob=new TREM_FormaSpiskaSprProducerRabotaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprProducerRabotaImpl)
	{
	TREM_FormaElementaSprProducerRabotaCF * ob=new TREM_FormaElementaSprProducerRabotaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerRabotaGrpImpl)
	{
	TREM_FormaElementaSprProducerRabotaGrpCF * ob=new TREM_FormaElementaSprProducerRabotaGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprModelTypRabotImpl)
	{
	TREM_FormaElementaSprModelTypRabotCF * ob=new TREM_FormaElementaSprModelTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprModelTypRabotImpl)
	{
	TREM_FormaSpiskaSprModelTypRabotCF * ob=new TREM_FormaSpiskaSprModelTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}


else if (id_class==CLSID_TREM_FormaSpiskaSprProducerSectionImpl)
	{
	TREM_FormaSpiskaSprProducerSectionCF * ob=new TREM_FormaSpiskaSprProducerSectionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerSectionImpl)
	{
	TREM_FormaElementaSprProducerSectionCF * ob=new TREM_FormaElementaSprProducerSectionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprProducerSectionGrpImpl)
	{
	TREM_FormaElementaSprProducerSectionGrpCF * ob=new TREM_FormaElementaSprProducerSectionGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaSpiskaSprProducerConditionImpl)
	{
	TREM_FormaSpiskaSprProducerConditionCF * ob=new TREM_FormaSpiskaSprProducerConditionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprProducerConditionImpl)
	{
	TREM_FormaElementaSprProducerConditionCF * ob=new TREM_FormaElementaSprProducerConditionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaElementaSprProducerConditionGrpImpl)
	{
	TREM_FormaElementaSprProducerConditionGrpCF * ob=new TREM_FormaElementaSprProducerConditionGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else
	{
	result=0;
	*ppv=NULL;
	}


return result;
}
//----------------------------------------------------------------------------

int kanRegisterServer(IkanCom * icom)
{
int result=0;


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypeRemontImpl,"Oberon.REM_FormaElSprTypeRemont.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprTypeRemont.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTypeRemontImpl,ProgId_REM_FormaSpiskaSprTypeRemont,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTypeRemont)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprSostImpl,"Oberon.REM_FormaElSprSost.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprSost.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprSostImpl,ProgId_REM_FormaSpiskaSprSost,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_REM_FormaSpiskaSprSost)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprGrpNeisprImpl,"Oberon.REM_FormaElSprGrpNeispr.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprGrpNeispr.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprNeisprImpl,"Oberon.REM_FormaElSprNeispr.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprNeispr.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprNeisprImpl,ProgId_REM_FormaSpiskaSprNeispr,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprNeispr)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprGrpModelImpl,"Oberon.REM_FormaElSprGrpModel.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprGrpModel.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprKomplModelImpl,"Oberon.REM_FormaElSprKomplModel.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprKomplModel.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprKomplModelImpl,"Oberon.REM_FormaSpSprKomplModel.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaSpSprKomplModel.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModelImpl,"Oberon.REM_FormaElSprModel.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprModel.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModelImpl,ProgId_REM_FormaSpiskaSprModel,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModel)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprGrpKKTImpl,"Oberon.REM_FormaElSprGrpKKT.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprGrpKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprKKTDvImpl,"Oberon.REM_FormaSpSprKKTDv.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaSpSprKKTDv.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprKKTImpl,"Oberon.REM_FormaElSprKKT.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprKKTImpl,ProgId_REM_FormaSpiskaSprKKT,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprKKT)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprGrpHardwareImpl,"Oberon.REM_FormaElSprGrpHardware.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprGrpHardware.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprHardwareImpl,"Oberon.REM_FormaElSprHardware.1","RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaElSprHardware.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprHardwareImpl,ProgId_REM_FormaSpiskaSprHardware,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprHardware)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerModelGrpImpl,ProgId_REM_FormaElementaSprProducerModelGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerModelGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerModelImpl,ProgId_REM_FormaElementaSprProducerModel,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerModel)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerModelImpl,ProgId_REM_FormaSpiskaSprProducerModel,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerModel)+"  !");
	}





if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerNeisprGrpImpl,ProgId_REM_FormaElementaSprProducerNeisprGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerNeisprGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerNeisprImpl,ProgId_REM_FormaElementaSprProducerNeispr,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerNeispr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerNeisprImpl,ProgId_REM_FormaSpiskaSprProducerNeispr,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerNeispr)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypDefectGrpImpl,ProgId_REM_FormaElementaSprTypDefectGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypDefectGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypDefectImpl,ProgId_REM_FormaElementaSprTypDefect,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypDefect)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTypDefectImpl,ProgId_REM_FormaSpiskaSprTypDefect,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTypDefect)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypRabotGrpImpl,ProgId_REM_FormaElementaSprTypRabotGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypRabotGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypRabotImpl,ProgId_REM_FormaElementaSprTypRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypRabot)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTypRabotImpl,ProgId_REM_FormaSpiskaSprTypRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTypRabot)+"  !");
	}



if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypUslovGrpImpl,ProgId_REM_FormaElementaSprTypUslovGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypUslovGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypUslovImpl,ProgId_REM_FormaElementaSprTypUslov,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypUslov)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTypUslovImpl,ProgId_REM_FormaSpiskaSprTypUslov,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTypUslov)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModelDetalImpl,ProgId_REM_FormaElementaSprModelDetal,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprModelDetal)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModelDetalImpl,ProgId_REM_FormaSpiskaSprModelDetal,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModelDetal)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTrebRabotImpl,ProgId_REM_FormaElementaSprTrebRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTrebRabot)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTrebRabotImpl,ProgId_REM_FormaSpiskaSprTrebRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTrebRabot)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTrebUslovImpl,ProgId_REM_FormaElementaSprTrebUslov,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTrebUslov)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTrebUslovImpl,ProgId_REM_FormaSpiskaSprTrebUslov,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTrebUslov)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprDefectModelNeisprImpl,ProgId_REM_FormaElementaSprDefectModelNeispr,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprDefectModelNeispr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprDefectModelNeisprImpl,ProgId_REM_FormaSpiskaSprDefectModelNeispr,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprDefectModelNeispr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprNeisprModelImpl,ProgId_REM_FormaElementaSprNeisprModel,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprNeisprModel)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprNeisprModelImpl,ProgId_REM_FormaSpiskaSprNeisprModel,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprNeisprModel)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprTypeDeviceImpl,ProgId_REM_FormaElementaSprTypeDevice,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprTypeDevice)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprTypeDeviceImpl,ProgId_REM_FormaSpiskaSprTypeDevice,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprTypeDevice)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModel2GrpImpl,ProgId_REM_FormaElementaSprModel2Grp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprModel2Grp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModel2Impl,ProgId_REM_FormaSpiskaSprModel2,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModel2)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerDefectGrpImpl,ProgId_REM_FormaElementaSprProducerDefectGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerDefectGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerDefectImpl,ProgId_REM_FormaElementaSprProducerDefect,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerDefect)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerDefectImpl,ProgId_REM_FormaSpiskaSprProducerDefect,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerDefect)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprHardwareIspImpl,ProgId_REM_FormaElementaSprHardwareIsp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprHardwareIsp)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprHardwareIspImpl,ProgId_REM_FormaSpiskaSprHardwareIsp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprHardwareIsp)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerModelPropertiesValueImpl,ProgId_REM_FormaSpiskaSprProducerModelPropertiesValue,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerModelPropertiesValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerModelPropertiesValueImpl,ProgId_REM_FormaElementaSprProducerModelPropertiesValue,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerModelPropertiesValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerModelInfBlockImpl,ProgId_REM_FormaSpiskaSprProducerModelInfBlock,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerModelInfBlock)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerModelInfBlockImpl,ProgId_REM_FormaElementaSprProducerModelInfBlock,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerModelInfBlock)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModelPropertiesValueImpl,ProgId_REM_FormaSpiskaSprModelPropertiesValue,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModelPropertiesValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModelPropertiesValueImpl,ProgId_REM_FormaElementaSprModelPropertiesValue,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprModelPropertiesValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModelInfBlockImpl,ProgId_REM_FormaSpiskaSprModelInfBlock,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModelInfBlock)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModelInfBlockImpl,ProgId_REM_FormaElementaSprModelInfBlock,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprModelInfBlock)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprActCategoryImpl,ProgId_REM_FormaElementaSprActCategory,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprActCategory)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprActCategoryImpl,ProgId_REM_FormaSpiskaSprActCategory,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprActCategory)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerRabotaImpl,ProgId_REM_FormaSpiskaSprProducerRabota,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerRabota)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerRabotaImpl,ProgId_REM_FormaElementaSprProducerRabota,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerRabota)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerRabotaGrpImpl,ProgId_REM_FormaElementaSprProducerRabotaGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerRabotaGrp)+"  !");
	}




if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprModelTypRabotImpl,ProgId_REM_FormaSpiskaSprModelTypRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprModelTypRabot)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprModelTypRabotImpl,ProgId_REM_FormaElementaSprModelTypRabot,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprModelTypRabot)+"  !");
	}




if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerSectionImpl,ProgId_REM_FormaElementaSprProducerSection,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerSection)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerSectionGrpImpl,ProgId_REM_FormaElementaSprProducerSectionGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerSectionGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerSectionImpl,ProgId_REM_FormaSpiskaSprProducerSection,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerSection)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerConditionImpl,ProgId_REM_FormaElementaSprProducerCondition,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerCondition)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprProducerConditionGrpImpl,ProgId_REM_FormaElementaSprProducerConditionGrp,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprProducerConditionGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprProducerConditionImpl,ProgId_REM_FormaSpiskaSprProducerCondition,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprProducerCondition)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprHardwareVZipImpl,ProgId_REM_FormaSpiskaSprHardwareVZip,"RemFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprHardwareVZip)+"  !");
	}


return result;
}
//-----------------------------------------------------------------------------
int kanUnregisterServer(IkanCom * icom)
{
int result=0;

return result;
}
//-----------------------------------------------------------------------------
