//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UREM_FormaDocKM1Impl.h"
#include "UREM_FormaDocKM1CF.h"
#include "UREM_FormaDocKM2Impl.h"
#include "UREM_FormaDocKM2CF.h"
#include "UREM_FormaDocRemontImpl.h"
#include "UREM_FormaDocRemontCF.h"
#include "UREM_FormaDocRemontHWImpl.h"
#include "UREM_FormaDocRemontHWCF.h"
#include "UREM_FormaDocRemontKKTImpl.h"
#include "UREM_FormaDocRemontKKTCF.h"
#include "UREM_FormaDocSetServHWImpl.h"
#include "UREM_FormaDocSetServHWCF.h"
#include "UREM_FormaDocSetServKKTImpl.h"
#include "UREM_FormaDocSetServKKTCF.h"
#include "UREM_FormaDocPrihNaklImpl.h"
#include "UREM_FormaDocPrihNaklCF.h"
#include "UREM_FormaDocRealImpl.h"
#include "UREM_FormaDocRealCF.h"
#include "UREM_FormaDocOstNomImpl.h"
#include "UREM_FormaDocOstNomCF.h"
#include "UREM_FormaDocSborkaKomplImpl.h"
#include "UREM_FormaDocSborkaKomplCF.h"

#include "UREM_FormaDocPostOtDileraImpl.h"
#include "UREM_FormaDocPostOtDileraCF.h"
#include "UREM_FormaDocVosvratDileruImpl.h"
#include "UREM_FormaDocVosvratDileruCF.h"
#include "UREM_FormaDocPerServCentrImpl.h"
#include "UREM_FormaDocPerServCentrCF.h"
#include "UREM_FormaDocVosvratIsSCImpl.h"
#include "UREM_FormaDocVosvratIsSCCF.h"

#include "UREM_FormaDocVosvratPokImpl.h"
#include "UREM_FormaDocVosvratPokCF.h"

#include "UREM_FormaDocAktImpl.h"
#include "UREM_FormaDocAktCF.h"
#include "UREM_FormaDocPerImpl.h"
#include "UREM_FormaDocPerCF.h"

#include "UREM_FormaDocZPostImpl.h"
#include "UREM_FormaDocZPostCF.h"
#include "UREM_FormaDocZVidImpl.h"
#include "UREM_FormaDocZVidCF.h"
#include "UREM_FormaDocZPerImpl.h"
#include "UREM_FormaDocZPerCF.h"
#include "UREM_FormaDocZStartImpl.h"
#include "UREM_FormaDocZStartCF.h"
#include "UREM_FormaDocZEndImpl.h"
#include "UREM_FormaDocZEndCF.h"
#include "UREM_FormaDocZOperImpl.h"
#include "UREM_FormaDocZOperCF.h"
#include "UREM_FormaDocZTrebImpl.h"
#include "UREM_FormaDocZTrebCF.h"
#include "UREM_FormaDocZAktPrImpl.h"
#include "UREM_FormaDocZAktPrCF.h"
#include "UREM_FormaDocZVosvrZapImpl.h"
#include "UREM_FormaDocZVosvrZapCF.h"

#include "UREM_FormaDocSpisNomImpl.h"
#include "UREM_FormaDocSpisNomCF.h"

#include "UREM_FormaDocRegOtchetPostImpl.h"
#include "UREM_FormaDocRegOtchetPostCF.h"

#include "UREM_FormaDocVidachaHWImpl.h"
#include "UREM_FormaDocVidachaHWCF.h"
#include "UREM_FormaDocVosvratHWImpl.h"
#include "UREM_FormaDocVosvratHWCF.h"

#include "UREM_FormaDocProverkaImpl.h"
#include "UREM_FormaDocProverkaCF.h"
#include "UREM_FormaDocVigruskaImpl.h"
#include "UREM_FormaDocVigruskaCF.h"

#include "UREM_FormaDocZakazPostImpl.h"
#include "UREM_FormaDocZakazPostCF.h"
#include "UREM_FormaDocOtprPostImpl.h"
#include "UREM_FormaDocOtprPostCF.h"


#include "UREM_FormaDocVZipPerImpl.h"
#include "UREM_FormaDocVZipPerCF.h"
#include "UREM_FormaDocVZipVosvratPostImpl.h"
#include "UREM_FormaDocVZipVosvratPostCF.h"
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

if (id_class==CLSID_TREM_FormaDocKM1Impl)
	{
	TREM_FormaDocKM1CF * ob=new TREM_FormaDocKM1CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocKM2Impl)
	{
	TREM_FormaDocKM2CF * ob=new TREM_FormaDocKM2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocRemontImpl)
	{
	TREM_FormaDocRemontCF * ob=new TREM_FormaDocRemontCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocRemontHWImpl)
	{
	TREM_FormaDocRemontHWCF * ob=new TREM_FormaDocRemontHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocRemontKKTImpl)
	{
	TREM_FormaDocRemontKKTCF * ob=new TREM_FormaDocRemontKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocSetServHWImpl)
	{
	TREM_FormaDocSetServHWCF * ob=new TREM_FormaDocSetServHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocSetServKKTImpl)
	{
	TREM_FormaDocSetServKKTCF * ob=new TREM_FormaDocSetServKKTCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocPrihNaklImpl)
	{
	TREM_FormaDocPrihNaklCF * ob=new TREM_FormaDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocRealImpl)
	{
	TREM_FormaDocRealCF * ob=new TREM_FormaDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocOstNomImpl)
	{
	TREM_FormaDocOstNomCF * ob=new TREM_FormaDocOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocSborkaKomplImpl)
	{
	TREM_FormaDocSborkaKomplCF * ob=new TREM_FormaDocSborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocPostOtDileraImpl)
	{
	TREM_FormaDocPostOtDileraCF * ob=new TREM_FormaDocPostOtDileraCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocVosvratDileruImpl)
	{
	TREM_FormaDocVosvratDileruCF * ob=new TREM_FormaDocVosvratDileruCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocPerServCentrImpl)
	{
	TREM_FormaDocPerServCentrCF * ob=new TREM_FormaDocPerServCentrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocVosvratIsSCImpl)
	{
	TREM_FormaDocVosvratIsSCCF * ob=new TREM_FormaDocVosvratIsSCCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocVosvratPokImpl)
	{
	TREM_FormaDocVosvratPokCF * ob=new TREM_FormaDocVosvratPokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocAktImpl)
	{
	TREM_FormaDocAktCF * ob=new TREM_FormaDocAktCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocPerImpl)
	{
	TREM_FormaDocPerCF * ob=new TREM_FormaDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZPostImpl)
	{
	TREM_FormaDocZPostCF * ob=new TREM_FormaDocZPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZVidImpl)
	{
	TREM_FormaDocZVidCF * ob=new TREM_FormaDocZVidCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZPerImpl)
	{
	TREM_FormaDocZPerCF * ob=new TREM_FormaDocZPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZStartImpl)
	{
	TREM_FormaDocZStartCF * ob=new TREM_FormaDocZStartCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZEndImpl)
	{
	TREM_FormaDocZEndCF * ob=new TREM_FormaDocZEndCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZOperImpl)
	{
	TREM_FormaDocZOperCF * ob=new TREM_FormaDocZOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZTrebImpl)
	{
	TREM_FormaDocZTrebCF * ob=new TREM_FormaDocZTrebCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZAktPrImpl)
	{
	TREM_FormaDocZAktPrCF * ob=new TREM_FormaDocZAktPrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocZVosvrZapImpl)
	{
	TREM_FormaDocZVosvrZapCF * ob=new TREM_FormaDocZVosvrZapCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocSpisNomImpl)
	{
	TREM_FormaDocSpisNomCF * ob=new TREM_FormaDocSpisNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocRegOtchetPostImpl)
	{
	TREM_FormaDocRegOtchetPostCF * ob=new TREM_FormaDocRegOtchetPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocVidachaHWImpl)
	{
	TREM_FormaDocVidachaHWCF * ob=new TREM_FormaDocVidachaHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaDocVosvratHWImpl)
	{
	TREM_FormaDocVosvratHWCF * ob=new TREM_FormaDocVosvratHWCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocProverkaImpl)
	{
	TREM_FormaDocProverkaCF * ob=new TREM_FormaDocProverkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocVigruskaImpl)
	{
	TREM_FormaDocVigruskaCF * ob=new TREM_FormaDocVigruskaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocZakazPostImpl)
	{
	TREM_FormaDocZakazPostCF * ob=new TREM_FormaDocZakazPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocOtprPostImpl)
	{
	TREM_FormaDocOtprPostCF * ob=new TREM_FormaDocOtprPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocVZipPerImpl)
	{
	TREM_FormaDocVZipPerCF * ob=new TREM_FormaDocVZipPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaDocVZipVosvratPostImpl)
	{
	TREM_FormaDocVZipVosvratPostCF * ob=new TREM_FormaDocVZipVosvratPostCF();
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


if (icom->kanAddClass(CLSID_TREM_FormaDocKM1Impl,ProgId_REM_FormaDocKM1,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocKM1)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocKM2Impl,ProgId_REM_FormaDocKM2,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_REM_FormaDocKM2)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocRemontImpl,ProgId_REM_FormaDocRemont,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocRemont)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocRemontHWImpl,ProgId_REM_FormaDocRemontHW,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocRemontHW)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocRemontKKTImpl,ProgId_REM_FormaDocRemontKKT,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_REM_FormaDocRemontKKT)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocSetServHWImpl,ProgId_REM_FormaDocSetServHW,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocSetServHW)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocSetServKKTImpl,ProgId_REM_FormaDocSetServKKT,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocSetServKKT)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocPrihNaklImpl,ProgId_REM_FormaDocPrihNakl,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocPrihNakl)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocRealImpl,ProgId_REM_FormaDocReal,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocReal)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocOstNomImpl,ProgId_REM_FormaDocOstNom,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocOstNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocSborkaKomplImpl,ProgId_REM_FormaDocSborkaKompl,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocSborkaKompl)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaDocPostOtDileraImpl,ProgId_REM_FormaDocPostOtDilera,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocPostOtDilera)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocVosvratDileruImpl,ProgId_REM_FormaDocVosvratDileru,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVosvratDileru)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocPerServCentrImpl,ProgId_REM_FormaDocPerServCentr,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocPerServCentr)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocVosvratIsSCImpl,ProgId_REM_FormaDocVosvratIsSC,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVosvratIsSC)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocVosvratPokImpl,ProgId_REM_FormaDocVosvratPok,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVosvratPok)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocAktImpl,ProgId_REM_FormaDocAkt,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocAkt)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocPerImpl,ProgId_REM_FormaDocPer,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocPer)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaDocZPostImpl,ProgId_REM_FormaDocZPost,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZPost)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZVidImpl,ProgId_REM_FormaDocZVid,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZVid)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZPerImpl,ProgId_REM_FormaDocZPer,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZPer)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZStartImpl,ProgId_REM_FormaDocZStart,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZStart)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZEndImpl,ProgId_REM_FormaDocZEnd,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZEnd)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZOperImpl,ProgId_REM_FormaDocZOper,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZOper)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZTrebImpl,ProgId_REM_FormaDocZTreb,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZTreb)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZAktPrImpl,ProgId_REM_FormaDocZAktPr,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZAktPr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocZVosvrZapImpl,ProgId_REM_FormaDocZVosvrZap,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZVosvrZap)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaDocSpisNomImpl,ProgId_REM_FormaDocSpisNom,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocSpisNom)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaDocRegOtchetPostImpl,ProgId_REM_FormaDocRegOtchetPost,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocRegOtchetPost)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocVidachaHWImpl,ProgId_REM_FormaDocVidachaHW,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVidachaHW)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocVosvratHWImpl,ProgId_REM_FormaDocVosvratHW,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVosvratHW)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaDocProverkaImpl,ProgId_REM_FormaDocProverka,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocProverka)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocVigruskaImpl,ProgId_REM_FormaDocVigruska,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVigruska)+"  !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaDocZakazPostImpl,ProgId_REM_FormaDocZakazPost,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocZakazPost)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocOtprPostImpl,ProgId_REM_FormaDocOtprPost,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocOtprPost)+"  !");
	}



if (icom->kanAddClass(CLSID_TREM_FormaDocVZipPerImpl,ProgId_REM_FormaDocVZipPer,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVZipPer)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaDocVZipVosvratPostImpl,ProgId_REM_FormaDocVZipVosvratPost,"RemFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaDocVZipVosvratPost)+"  !");
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
