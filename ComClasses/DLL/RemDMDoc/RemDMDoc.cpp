//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UREM_DMDocKM1Impl.h"
#include "UREM_DMDocKM1CF.h"
#include "UREM_DMDocKM2Impl.h"
#include "UREM_DMDocKM2CF.h"
#include "UREM_DMDocRemontImpl.h"
#include "UREM_DMDocRemontCF.h"
#include "UREM_DMDocRemontHWImpl.h"
#include "UREM_DMDocRemontHWCF.h"
#include "UREM_DMDocRemontKKTImpl.h"
#include "UREM_DMDocRemontKKTCF.h"
#include "UREM_DMDocSetServHWImpl.h"
#include "UREM_DMDocSetServHWCF.h"
#include "UREM_DMDocSetServKKTImpl.h"
#include "UREM_DMDocSetServKKTCF.h"
#include "UREM_DMDocPrihNaklImpl.h"
#include "UREM_DMDocPrihNaklCF.h"
#include "UREM_DMDocRealImpl.h"
#include "UREM_DMDocRealCF.h"
#include "UREM_DMDocOstNomImpl.h"
#include "UREM_DMDocOstNomCF.h"
#include "UREM_DMDocSborkaKomplImpl.h"
#include "UREM_DMDocSborkaKomplCF.h"

#include "UREM_DMDocPerServCentrImpl.h"
#include "UREM_DMDocPerServCentrCF.h"
#include "UREM_DMDocPostOtDileraImpl.h"
#include "UREM_DMDocPostOtDileraCF.h"
#include "UREM_DMDocVosvratIsSCImpl.h"
#include "UREM_DMDocVosvratIsSCCF.h"
#include "UREM_DMDocVosvratDileruImpl.h"
#include "UREM_DMDocVosvratDileruCF.h"
#include "UREM_DMDocVosvratPokImpl.h"
#include "UREM_DMDocVosvratPokCF.h"

#include "UREM_DMDocAktImpl.h"
#include "UREM_DMDocAktCF.h"
#include "UREM_DMDocPerImpl.h"
#include "UREM_DMDocPerCF.h"

#include "UREM_DMDocZAktPrImpl.h"
#include "UREM_DMDocZAktPrCF.h"
#include "UREM_DMDocZEndImpl.h"
#include "UREM_DMDocZEndCF.h"
#include "UREM_DMDocZOperImpl.h"
#include "UREM_DMDocZOperCF.h"
#include "UREM_DMDocZPerImpl.h"
#include "UREM_DMDocZPerCF.h"
#include "UREM_DMDocZPostImpl.h"
#include "UREM_DMDocZPostCF.h"
#include "UREM_DMDocZStartImpl.h"
#include "UREM_DMDocZStartCF.h"
#include "UREM_DMDocZTrebImpl.h"
#include "UREM_DMDocZTrebCF.h"
#include "UREM_DMDocZVidImpl.h"
#include "UREM_DMDocZVidCF.h"
#include "UREM_DMDocZVosvrZapImpl.h"
#include "UREM_DMDocZVosvrZapCF.h"


#include "UREM_DMDocSpisNomImpl.h"
#include "UREM_DMDocSpisNomCF.h"

#include "UREM_DMDocRegOtchetPostImpl.h"
#include "UREM_DMDocRegOtchetPostCF.h"

#include "UREM_DMDocVidachaHWImpl.h"
#include "UREM_DMDocVidachaHWCF.h"

#include "UREM_DMDocVosvratHWImpl.h"
#include "UREM_DMDocVosvratHWCF.h"

#include "UREM_DMDocProverkaImpl.h"
#include "UREM_DMDocProverkaCF.h"
#include "UREM_DMDocVigruskaImpl.h"
#include "UREM_DMDocVigruskaCF.h"


#include "UREM_DMDocZakazPostImpl.h"
#include "UREM_DMDocZakazPostCF.h"
#include "UREM_DMDocOtprPostImpl.h"
#include "UREM_DMDocOtprPostCF.h"


#include "UREM_DMDocVZipPerImpl.h"
#include "UREM_DMDocVZipPerCF.h"
#include "UREM_DMDocVZipVosvratPostImpl.h"
#include "UREM_DMDocVZipVosvratPostCF.h"
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
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TREM_DMDocKM1Impl)
	{
	TREM_DMDocKM1CF * ob=new TREM_DMDocKM1CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocKM2Impl)
	{
	TREM_DMDocKM2CF * ob=new TREM_DMDocKM2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocRemontImpl)
	{
	TREM_DMDocRemontCF * ob=new TREM_DMDocRemontCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocRemontHWImpl)
	{
	TREM_DMDocRemontHWCF * ob=new TREM_DMDocRemontHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocRemontKKTImpl)
	{
	TREM_DMDocRemontKKTCF * ob=new TREM_DMDocRemontKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocSetServHWImpl)
	{
	TREM_DMDocSetServHWCF * ob=new TREM_DMDocSetServHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocSetServKKTImpl)
	{
	TREM_DMDocSetServKKTCF * ob=new TREM_DMDocSetServKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocPrihNaklImpl)
	{
	TREM_DMDocPrihNaklCF * ob=new TREM_DMDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocRealImpl)
	{
	TREM_DMDocRealCF * ob=new TREM_DMDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocOstNomImpl)
	{
	TREM_DMDocOstNomCF * ob=new TREM_DMDocOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocSborkaKomplImpl)
	{
	TREM_DMDocSborkaKomplCF * ob=new TREM_DMDocSborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocPerServCentrImpl)
	{
	TREM_DMDocPerServCentrCF * ob=new TREM_DMDocPerServCentrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocPostOtDileraImpl)
	{
	TREM_DMDocPostOtDileraCF * ob=new TREM_DMDocPostOtDileraCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVosvratIsSCImpl)
	{
	TREM_DMDocVosvratIsSCCF * ob=new TREM_DMDocVosvratIsSCCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVosvratDileruImpl)
	{
	TREM_DMDocVosvratDileruCF * ob=new TREM_DMDocVosvratDileruCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVosvratPokImpl)
	{
	TREM_DMDocVosvratPokCF * ob=new TREM_DMDocVosvratPokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocAktImpl)
	{
	TREM_DMDocAktCF * ob=new TREM_DMDocAktCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocPerImpl)
	{
	TREM_DMDocPerCF * ob=new TREM_DMDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZAktPrImpl)
	{
	TREM_DMDocZAktPrCF * ob=new TREM_DMDocZAktPrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZEndImpl)
	{
	TREM_DMDocZEndCF * ob=new TREM_DMDocZEndCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZOperImpl)
	{
	TREM_DMDocZOperCF * ob=new TREM_DMDocZOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZPerImpl)
	{
	TREM_DMDocZPerCF * ob=new TREM_DMDocZPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZPostImpl)
	{
	TREM_DMDocZPostCF * ob=new TREM_DMDocZPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZStartImpl)
	{
	TREM_DMDocZStartCF * ob=new TREM_DMDocZStartCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZTrebImpl)
	{
	TREM_DMDocZTrebCF * ob=new TREM_DMDocZTrebCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZVidImpl)
	{
	TREM_DMDocZVidCF * ob=new TREM_DMDocZVidCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocZVosvrZapImpl)
	{
	TREM_DMDocZVosvrZapCF * ob=new TREM_DMDocZVosvrZapCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocSpisNomImpl)
	{
	TREM_DMDocSpisNomCF * ob=new TREM_DMDocSpisNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocRegOtchetPostImpl)
	{
	TREM_DMDocRegOtchetPostCF * ob=new TREM_DMDocRegOtchetPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVidachaHWImpl)
	{
	TREM_DMDocVidachaHWCF * ob=new TREM_DMDocVidachaHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVosvratHWImpl)
	{
	TREM_DMDocVosvratHWCF * ob=new TREM_DMDocVosvratHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocProverkaImpl)
	{
	TREM_DMDocProverkaCF * ob=new TREM_DMDocProverkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocVigruskaImpl)
	{
	TREM_DMDocVigruskaCF * ob=new TREM_DMDocVigruskaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMDocZakazPostImpl)
	{
	TREM_DMDocZakazPostCF * ob=new TREM_DMDocZakazPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMDocOtprPostImpl)
	{
	TREM_DMDocOtprPostCF * ob=new TREM_DMDocOtprPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMDocVZipPerImpl)
	{
	TREM_DMDocVZipPerCF * ob=new TREM_DMDocVZipPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMDocVZipVosvratPostImpl)
	{
	TREM_DMDocVZipVosvratPostCF * ob=new TREM_DMDocVZipVosvratPostCF();
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

if (icom->kanAddClass(CLSID_TREM_DMDocKM1Impl,ProgId_REM_DMDocKM1,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMDocKM1.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocKM2Impl,ProgId_REM_DMDocKM2,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMDocKM2.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocRemontImpl,ProgId_REM_DMDocRemont,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocRemont)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocRemontHWImpl,ProgId_REM_DMDocRemontHW,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_REM_DMDocRemontHW)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocRemontKKTImpl,ProgId_REM_DMDocRemontKKT,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMDocRemontKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocSetServHWImpl,ProgId_REM_DMDocSetServHW,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMDocSetServHW.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocSetServKKTImpl,ProgId_REM_DMDocSetServKKT,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_DMDocSetServKKT.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocPrihNaklImpl,ProgId_REM_DMDocPrihNakl,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocPrihNakl)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocRealImpl,ProgId_REM_DMDocReal,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocReal)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocOstNomImpl,ProgId_REM_DMDocOstNom,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocOstNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocSborkaKomplImpl,ProgId_REM_DMDocSborkaKompl,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocSborkaKompl)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_DMDocPerServCentrImpl,ProgId_REM_DMDocPerServCentr,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocPerServCentr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocPostOtDileraImpl,ProgId_REM_DMDocPostOtDilera,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocPostOtDilera)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocVosvratIsSCImpl,ProgId_REM_DMDocVosvratIsSC,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVosvratIsSC)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocVosvratDileruImpl,ProgId_REM_DMDocVosvratDileru,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVosvratDileru)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocVosvratPokImpl,ProgId_REM_DMDocVosvratPok,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVosvratPok)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocAktImpl,ProgId_REM_DMDocAkt,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocAkt)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocPerImpl,ProgId_REM_DMDocPer,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocPer)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocZAktPrImpl,ProgId_REM_DMDocZAktPr,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZAktPr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocZEndImpl,ProgId_REM_DMDocZEnd,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZEnd)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZOperImpl,ProgId_REM_DMDocZOper,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZOper)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZPerImpl,ProgId_REM_DMDocZPer,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZPer)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZPostImpl,ProgId_REM_DMDocZPost,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZPost)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZStartImpl,ProgId_REM_DMDocZStart,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZStart)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZTrebImpl,ProgId_REM_DMDocZTreb,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZTreb)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocZVidImpl,ProgId_REM_DMDocZVid,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZVid)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocZVosvrZapImpl,ProgId_REM_DMDocZVosvrZap,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZVosvrZap)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocSpisNomImpl,ProgId_REM_DMDocSpisNom,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocSpisNom)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocRegOtchetPostImpl,ProgId_REM_DMDocRegOtchetPost,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocRegOtchetPost)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocVidachaHWImpl,ProgId_REM_DMDocVidachaHW,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVidachaHW)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocVosvratHWImpl,ProgId_REM_DMDocVosvratHW,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVosvratHW)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocProverkaImpl,ProgId_REM_DMDocProverka,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocProverka)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocVigruskaImpl,ProgId_REM_DMDocVigruska,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVigruska)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMDocZakazPostImpl,ProgId_REM_DMDocZakazPost,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocZakazPost)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocOtprPostImpl,ProgId_REM_DMDocOtprPost,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocOtprPost)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_DMDocVZipPerImpl,ProgId_REM_DMDocVZipPer,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVZipPer)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMDocVZipVosvratPostImpl,ProgId_REM_DMDocVZipVosvratPost,"RemDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMDocVZipVosvratPost)+"  !");
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

