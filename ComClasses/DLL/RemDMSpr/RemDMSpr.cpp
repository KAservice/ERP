//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UREM_DMSprGrpHardwareImpl.h"
#include "UREM_DMSprGrpHardwareCF.h"
#include "UREM_DMSprHardwareImpl.h"
#include "UREM_DMSprHardwareCF.h"
#include "UREM_DMSprGrpKKTImpl.h"
#include "UREM_DMSprGrpKKTCF.h"
#include "UREM_DMSprKKTImpl.h"
#include "UREM_DMSprKKTCF.h"
#include "UREM_DMSprKKTDvImpl.h"
#include "UREM_DMSprKKTDvCF.h"
#include "UREM_DMSprKomplModelImpl.h"
#include "UREM_DMSprKomplModelCF.h"
#include "UREM_DMSprGrpModelImpl.h"
#include "UREM_DMSprGrpModelCF.h"
#include "UREM_DMSprModelImpl.h"
#include "UREM_DMSprModelCF.h"
#include "UREM_DMSprGrpNeisprImpl.h"
#include "UREM_DMSprGrpNeisprCF.h"
#include "UREM_DMSprNeisprImpl.h"
#include "UREM_DMSprNeisprCF.h"
#include "UREM_DMSprSostImpl.h"
#include "UREM_DMSprSostCF.h"
#include "UREM_DMSprTypeRemontImpl.h"
#include "UREM_DMSprTypeRemontCF.h"

#include "UREM_DMSprProducerModelGrpImpl.h"
#include "UREM_DMSprProducerModelGrpCF.h"
#include "UREM_DMSprProducerModelImpl.h"
#include "UREM_DMSprProducerModelCF.h"
#include "UREM_DMSprProducerNeisprGrpImpl.h"
#include "UREM_DMSprProducerNeisprGrpCF.h"
#include "UREM_DMSprProducerNeisprImpl.h"
#include "UREM_DMSprProducerNeisprCF.h"

#include "UREM_DMSprGrpTypUslovImpl.h"
#include "UREM_DMSprGrpTypUslovCF.h"
#include "UREM_DMSprTypUslovImpl.h"
#include "UREM_DMSprTypUslovCF.h"

#include "UREM_DMSprGrpTypDefectImpl.h"
#include "UREM_DMSprGrpTypDefectCF.h"
#include "UREM_DMSprTypDefectImpl.h"
#include "UREM_DMSprTypDefectCF.h"
#include "UREM_DMSprGrpTypRabotImpl.h"
#include "UREM_DMSprGrpTypRabotCF.h"
#include "UREM_DMSprTypRabotImpl.h"
#include "UREM_DMSprTypRabotCF.h"

#include "UREM_DMSprNeisprModelImpl.h"
#include "UREM_DMSprNeisprModelCF.h"

#include "UREM_DMSprDefectModelNeisprImpl.h"
#include "UREM_DMSprDefectModelNeisprCF.h"

#include "UREM_DMSprTrebRabotImpl.h"
#include "UREM_DMSprTrebRabotCF.h"
#include "UREM_DMSprTrebUslovImpl.h"
#include "UREM_DMSprTrebUslovCF.h"

#include "UREM_DMSprModelDetalImpl.h"
#include "UREM_DMSprModelDetalCF.h"

#include "UREM_DMSprModel2Impl.h"
#include "UREM_DMSprModel2CF.h"
#include "UREM_DMSprModel2GrpImpl.h"
#include "UREM_DMSprModel2GrpCF.h"

#include "UREM_DMSprTypeDeviceImpl.h"
#include "UREM_DMSprTypeDeviceCF.h"

#include "UREM_DMSprProducerDefectImpl.h"
#include "UREM_DMSprProducerDefectCF.h"
#include "UREM_DMSprProducerDefectGrpImpl.h"
#include "UREM_DMSprProducerDefectGrpCF.h"

#include "UREM_DMSprHardwareIspImpl.h"
#include "UREM_DMSprHardwareIspCF.h"


#include "UREM_DMSprModelInfBlockImpl.h"
#include "UREM_DMSprModelInfBlockCF.h"

#include "UREM_DMSprProducerModelInfBlockImpl.h"
#include "UREM_DMSprProducerModelInfBlockCF.h"

#include "UREM_DMSprModelPropertiesValueImpl.h"
#include "UREM_DMSprModelPropertiesValueCF.h"
#include "UREM_DMSprProducerModelPropertiesValueImpl.h"
#include "UREM_DMSprProducerModelPropertiesValueCF.h"

#include "UREM_DMSprActCategoryImpl.h"
#include "UREM_DMSprActCategoryCF.h"

#include "UREM_DMSprProducerRabotaImpl.h"
#include "UREM_DMSprProducerRabotaCF.h"
#include "UREM_DMSprProducerRabotaGrpImpl.h"
#include "UREM_DMSprProducerRabotaGrpCF.h"

#include "UREM_DMSprModelTypRabotImpl.h"
#include "UREM_DMSprModelTypRabotCF.h"


#include "UREM_DMSprProducerConditionGrpImpl.h"
#include "UREM_DMSprProducerConditionGrpCF.h"
#include "UREM_DMSprProducerConditionImpl.h"
#include "UREM_DMSprProducerConditionCF.h"
#include "UREM_DMSprProducerSectionGrpImpl.h"
#include "UREM_DMSprProducerSectionGrpCF.h"
#include "UREM_DMSprProducerSectionImpl.h"
#include "UREM_DMSprProducerSectionCF.h"


#include "UREM_DMSprHardwareVZipImpl.h"
#include "UREM_DMSprHardwareVZipCF.h"
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


}
//---------------------------------------------------------------------------
void kanDone(void)
{

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
//----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TREM_DMSprGrpHardwareImpl)
	{
	TREM_DMSprGrpHardwareCF * ob=new TREM_DMSprGrpHardwareCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprHardwareVZipImpl)
	{
	TREM_DMSprHardwareVZipCF * ob=new TREM_DMSprHardwareVZipCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprHardwareImpl)
	{
	TREM_DMSprHardwareCF * ob=new TREM_DMSprHardwareCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpKKTImpl)
	{
	TREM_DMSprGrpKKTCF * ob=new TREM_DMSprGrpKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprKKTImpl)
	{
	TREM_DMSprKKTCF * ob=new TREM_DMSprKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprKKTDvImpl)
	{
	TREM_DMSprKKTDvCF * ob=new TREM_DMSprKKTDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprKomplModelImpl)
	{
	TREM_DMSprKomplModelCF * ob=new TREM_DMSprKomplModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpModelImpl)
	{
	TREM_DMSprGrpModelCF * ob=new TREM_DMSprGrpModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprModelImpl)
	{
	TREM_DMSprModelCF * ob=new TREM_DMSprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpNeisprImpl)
	{
	TREM_DMSprGrpNeisprCF * ob=new TREM_DMSprGrpNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprNeisprImpl)
	{
	TREM_DMSprNeisprCF * ob=new TREM_DMSprNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprSostImpl)
	{
	TREM_DMSprSostCF * ob=new TREM_DMSprSostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprTypeRemontImpl)
	{
	TREM_DMSprTypeRemontCF * ob=new TREM_DMSprTypeRemontCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerModelGrpImpl)
	{
	TREM_DMSprProducerModelGrpCF * ob=new TREM_DMSprProducerModelGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerModelImpl)
	{
	TREM_DMSprProducerModelCF * ob=new TREM_DMSprProducerModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerNeisprGrpImpl)
	{
	TREM_DMSprProducerNeisprGrpCF * ob=new TREM_DMSprProducerNeisprGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpTypUslovImpl)
	{
	TREM_DMSprGrpTypUslovCF * ob=new TREM_DMSprGrpTypUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprTypUslovImpl)
	{
	TREM_DMSprTypUslovCF * ob=new TREM_DMSprTypUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerNeisprImpl)
	{
	TREM_DMSprProducerNeisprCF * ob=new TREM_DMSprProducerNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpTypDefectImpl)
	{
	TREM_DMSprGrpTypDefectCF * ob=new TREM_DMSprGrpTypDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprTypDefectImpl)
	{
	TREM_DMSprTypDefectCF * ob=new TREM_DMSprTypDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprGrpTypRabotImpl)
	{
	TREM_DMSprGrpTypRabotCF * ob=new TREM_DMSprGrpTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprTypRabotImpl)
	{
	TREM_DMSprTypRabotCF * ob=new TREM_DMSprTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprNeisprModelImpl)
	{
	TREM_DMSprNeisprModelCF * ob=new TREM_DMSprNeisprModelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprDefectModelNeisprImpl)
	{
	TREM_DMSprDefectModelNeisprCF * ob=new TREM_DMSprDefectModelNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprTrebRabotImpl)
	{
	TREM_DMSprTrebRabotCF * ob=new TREM_DMSprTrebRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprTrebUslovImpl)
	{
	TREM_DMSprTrebUslovCF * ob=new TREM_DMSprTrebUslovCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprModelDetalImpl)
	{
	TREM_DMSprModelDetalCF * ob=new TREM_DMSprModelDetalCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprModel2Impl)
	{
	TREM_DMSprModel2CF * ob=new TREM_DMSprModel2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprModel2GrpImpl)
	{
	TREM_DMSprModel2GrpCF * ob=new TREM_DMSprModel2GrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprTypeDeviceImpl)
	{
	TREM_DMSprTypeDeviceCF * ob=new TREM_DMSprTypeDeviceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerDefectImpl)
	{
	TREM_DMSprProducerDefectCF * ob=new TREM_DMSprProducerDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerDefectGrpImpl)
	{
	TREM_DMSprProducerDefectGrpCF * ob=new TREM_DMSprProducerDefectGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprHardwareIspImpl)
	{
	TREM_DMSprHardwareIspCF * ob=new TREM_DMSprHardwareIspCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprModelInfBlockImpl)
	{
	TREM_DMSprModelInfBlockCF * ob=new TREM_DMSprModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprProducerModelInfBlockImpl)
	{
	TREM_DMSprProducerModelInfBlockCF * ob=new TREM_DMSprProducerModelInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprModelPropertiesValueImpl)
	{
	TREM_DMSprModelPropertiesValueCF * ob=new TREM_DMSprModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerModelPropertiesValueImpl)
	{
	TREM_DMSprProducerModelPropertiesValueCF * ob=new TREM_DMSprProducerModelPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprActCategoryImpl)
	{
	TREM_DMSprActCategoryCF * ob=new TREM_DMSprActCategoryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprProducerRabotaImpl)
	{
	TREM_DMSprProducerRabotaCF * ob=new TREM_DMSprProducerRabotaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprProducerRabotaGrpImpl)
	{
	TREM_DMSprProducerRabotaGrpCF * ob=new TREM_DMSprProducerRabotaGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprModelTypRabotImpl)
	{
	TREM_DMSprModelTypRabotCF * ob=new TREM_DMSprModelTypRabotCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMSprProducerConditionGrpImpl)
	{
	TREM_DMSprProducerConditionGrpCF * ob=new TREM_DMSprProducerConditionGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerConditionImpl)
	{
	TREM_DMSprProducerConditionCF * ob=new TREM_DMSprProducerConditionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerSectionGrpImpl)
	{
	TREM_DMSprProducerSectionGrpCF * ob=new TREM_DMSprProducerSectionGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprProducerSectionImpl)
	{
	TREM_DMSprProducerSectionCF * ob=new TREM_DMSprProducerSectionCF();
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

if (icom->kanAddClass(CLSID_TREM_DMSprGrpHardwareImpl,"Oberon.REM_DMSprGrpHardware.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprGrpHardware.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprHardwareImpl,ProgId_REM_DMSprHardware,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprHardware)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprHardwareVZipImpl,ProgId_REM_DMSprHardwareVZip,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprHardwareVZip)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprGrpKKTImpl,"Oberon.REM_DMSprGrpKKT.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprGrpKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprKKTImpl,"Oberon.REM_DMSprKKT.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprKKTDvImpl,"Oberon.REM_DMSprKKTDv.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprKKTDv.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprKomplModelImpl,ProgId_REM_DMSprKomplModel,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprKomplModel)+"!");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprGrpModelImpl,ProgId_REM_DMSprGrpModel,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprGrpModel)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprModelImpl,ProgId_REM_DMSprModel,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModel)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprGrpNeisprImpl,ProgId_REM_DMSprGrpNeispr,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprGrpNeispr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprNeisprImpl,ProgId_REM_DMSprNeispr,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - O "+UnicodeString(ProgId_REM_DMSprNeispr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprSostImpl,"Oberon.REM_DMSprSost.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprSost.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprTypeRemontImpl,"Oberon.REM_DMSprTypeRemont.1","RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMSprTypeRemont.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprProducerModelGrpImpl,ProgId_REM_DMSprProducerModelGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerModelGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprProducerModelImpl,ProgId_REM_DMSprProducerModel,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerModel)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprProducerNeisprGrpImpl,ProgId_REM_DMSprProducerNeisprGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerNeisprGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprProducerNeisprImpl,ProgId_REM_DMSprProducerNeispr,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerNeispr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprGrpTypUslovImpl,ProgId_REM_DMSprGrpTypUslov,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprGrpTypUslov)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprTypUslovImpl,ProgId_REM_DMSprTypUslov,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTypUslov)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprGrpTypDefectImpl,ProgId_REM_DMSprGrpTypDefect,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprGrpTypDefect)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprTypDefectImpl,ProgId_REM_DMSprTypDefect,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTypDefect)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprGrpTypRabotImpl,ProgId_REM_DMSprGrpTypRabot,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprGrpTypRabot)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprTypRabotImpl,ProgId_REM_DMSprTypRabot,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTypRabot)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_DMSprNeisprModelImpl,ProgId_REM_DMSprNeisprModel,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprNeisprModel)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprDefectModelNeisprImpl,ProgId_REM_DMSprDefectModelNeispr,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprDefectModelNeispr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprTrebRabotImpl,ProgId_REM_DMSprTrebRabot,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTrebRabot)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprTrebUslovImpl,ProgId_REM_DMSprTrebUslov,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTrebUslov)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_DMSprModelDetalImpl,ProgId_REM_DMSprModelDetal,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModelDetal)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprModel2Impl,ProgId_REM_DMSprModel2,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModel2)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprModel2GrpImpl,ProgId_REM_DMSprModel2Grp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModel2Grp)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprTypeDeviceImpl,ProgId_REM_DMSprTypeDevice,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprTypeDevice)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_DMSprProducerDefectImpl,ProgId_REM_DMSprProducerDefect,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerDefect)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerDefectGrpImpl,ProgId_REM_DMSprProducerDefectGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerDefectGrp)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprHardwareIspImpl,ProgId_REM_DMSprHardwareIsp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprHardwareIsp)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprModelInfBlockImpl,ProgId_REM_DMSprModelInfBlock,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModelInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerModelInfBlockImpl,ProgId_REM_DMSprProducerModelInfBlock,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerModelInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprModelPropertiesValueImpl,ProgId_REM_DMSprModelPropertiesValue,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModelPropertiesValue)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerModelPropertiesValueImpl,ProgId_REM_DMSprProducerModelPropertiesValue,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerModelPropertiesValue)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprActCategoryImpl,ProgId_REM_DMSprActCategory,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprActCategory)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerRabotaImpl,ProgId_REM_DMSprProducerRabota,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerRabota)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerRabotaGrpImpl,ProgId_REM_DMSprProducerRabotaGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerRabotaGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprModelTypRabotImpl,ProgId_REM_DMSprModelTypRabot,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprModelTypRabot)+" !");
	}


if (icom->kanAddClass(CLSID_TREM_DMSprProducerConditionGrpImpl,ProgId_REM_DMSprProducerConditionGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerConditionGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprProducerConditionImpl,ProgId_REM_DMSprProducerCondition,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerCondition)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerSectionGrpImpl,ProgId_REM_DMSprProducerSectionGrp,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerSectionGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_DMSprProducerSectionImpl,ProgId_REM_DMSprProducerSection,"RemDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprProducerSection)+" !");
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
