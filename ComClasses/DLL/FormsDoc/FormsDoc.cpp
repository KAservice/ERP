//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UFormaDocIsmPriceImpl.h"
#include "UFormaDocIsmPriceCF.h"
#include "UFormaDocPrihNaklImpl.h"
#include "UFormaDocPrihNaklCF.h"
#include "UFormaDocCheckImpl.h"
#include "UFormaDocCheckCF.h"
#include "UFormaDocCheckProsmotrImpl.h"
#include "UFormaDocCheckProsmotrCF.h"
#include "UFormaDocKorrVSImpl.h"
#include "UFormaDocKorrVSCF.h"
#include "UFormaDocOstNomImpl.h"
#include "UFormaDocOstNomCF.h"
#include "UFormaDocPerImpl.h"
#include "UFormaDocPerCF.h"
#include "UFormaDocPKOImpl.h"
#include "UFormaDocPKOCF.h"
#include "UFormaDocPKORoznImpl.h"
#include "UFormaDocPKORoznCF.h"
#include "UFormaDocPlatPorImpl.h"
#include "UFormaDocPlatPorCF.h"
#include "UFormaDocPostNaSchetImpl.h"
#include "UFormaDocPostNaSchetCF.h"
#include "UFormaDocRasborkaKomplImpl.h"
#include "UFormaDocRasborkaKomplCF.h"
#include "UFormaDocRealImpl.h"
#include "UFormaDocRealCF.h"
#include "UFormaDocRealRoznImpl.h"
#include "UFormaDocRealRoznCF.h"
#include "UFormaDocRegAdvCustImpl.h"
#include "UFormaDocRegAdvCustCF.h"
#include "UFormaDocRegBankImpl.h"
#include "UFormaDocRegBankCF.h"
#include "UFormaDocRegCardBalanceImpl.h"
#include "UFormaDocRegCardBalanceCF.h"
#include "UFormaDocRegGoodsImpl.h"
#include "UFormaDocRegGoodsCF.h"
#include "UFormaDocRegKassaImpl.h"
#include "UFormaDocRegKassaCF.h"
#include "UFormaDocRegOstNomImpl.h"
#include "UFormaDocRegOstNomCF.h"
#include "UFormaDocRegPaySaleImpl.h"
#include "UFormaDocRegPaySaleCF.h"
#include "UFormaDocRegVsRaschImpl.h"
#include "UFormaDocRegVsRaschCF.h"
#include "UFormaDocRepKKMImpl.h"
#include "UFormaDocRepKKMCF.h"
#include "UFormaDocRevImpl.h"
#include "UFormaDocRevCF.h"
#include "UFormaDocRKOImpl.h"
#include "UFormaDocRKOCF.h"
#include "UFormaDocRKORoznImpl.h"
#include "UFormaDocRKORoznCF.h"
#include "UFormaDocSborkaKomplImpl.h"
#include "UFormaDocSborkaKomplCF.h"
#include "UFormaDocSchetFactImpl.h"
#include "UFormaDocSchetFactCF.h"
#include "UFormaDocSchetImpl.h"
#include "UFormaDocSchetCF.h"
#include "UFormaDocSpisNomImpl.h"
#include "UFormaDocSpisNomCF.h"
#include "UFormaDocSpOtrOstImpl.h"
#include "UFormaDocSpOtrOstCF.h"
#include "UFormaDocVipBankaImpl.h"
#include "UFormaDocVipBankaCF.h"
#include "UFormaDocVipuskProdImpl.h"
#include "UFormaDocVipuskProdCF.h"
#include "UFormaDocVosvratPokImpl.h"
#include "UFormaDocVosvratPokCF.h"
#include "UFormaDocVosvratPostImpl.h"
#include "UFormaDocVosvratPostCF.h"
#include "UFormaDocZamenaImpl.h"
#include "UFormaDocZamenaCF.h"
#include "UFormaDocInvImpl.h"
#include "UFormaDocInvCF.h"
#include "UFormaDocOstVsImpl.h"
#include "UFormaDocOstVsCF.h"
#include "UFormaDocRealRoznForCashierImpl.h"
#include "UFormaDocRealRoznForCashierCF.h"
#include "UFormaDocRKORoznForCashierImpl.h"
#include "UFormaDocRKORoznForCashierCF.h"
#include "UFormaDocPKORoznForCashierImpl.h"
#include "UFormaDocPKORoznForCashierCF.h"
#include "UFormaDocVosvratPokForCashierImpl.h"
#include "UFormaDocVosvratPokForCashierCF.h"

#include "UFormaDocOtchetPostImpl.h"
#include "UFormaDocOtchetPostCF.h"

#include "UFormaDocRegOtchetPostImpl.h"
#include "UFormaDocRegOtchetPostCF.h"
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
if (id_class==CLSID_TFormaDocIsmPriceImpl)
	{
	TFormaDocIsmPriceCF * ob=new TFormaDocIsmPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPrihNaklImpl)
	{
	TFormaDocPrihNaklCF * ob=new TFormaDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocCheckImpl)
	{
	TFormaDocCheckCF * ob=new TFormaDocCheckCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocCheckProsmotrImpl)
	{
	TFormaDocCheckProsmotrCF * ob=new TFormaDocCheckProsmotrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocKorrVSImpl)
	{
	TFormaDocKorrVSCF * ob=new TFormaDocKorrVSCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocOstNomImpl)
	{
	TFormaDocOstNomCF * ob=new TFormaDocOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPerImpl)
	{
	TFormaDocPerCF * ob=new TFormaDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPKOImpl)
	{
	TFormaDocPKOCF * ob=new TFormaDocPKOCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPKORoznImpl)
	{
	TFormaDocPKORoznCF * ob=new TFormaDocPKORoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPlatPorImpl)
	{
	TFormaDocPlatPorCF * ob=new TFormaDocPlatPorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPostNaSchetImpl)
	{
	TFormaDocPostNaSchetCF * ob=new TFormaDocPostNaSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRasborkaKomplImpl)
	{
	TFormaDocRasborkaKomplCF * ob=new TFormaDocRasborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRealImpl)
	{
	TFormaDocRealCF * ob=new TFormaDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRealRoznImpl)
	{
	TFormaDocRealRoznCF * ob=new TFormaDocRealRoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegAdvCustImpl)
	{
	TFormaDocRegAdvCustCF * ob=new TFormaDocRegAdvCustCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegBankImpl)
	{
	TFormaDocRegBankCF * ob=new TFormaDocRegBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegCardBalanceImpl)
	{
	TFormaDocRegCardBalanceCF * ob=new TFormaDocRegCardBalanceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegGoodsImpl)
	{
	TFormaDocRegGoodsCF * ob=new TFormaDocRegGoodsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegKassaImpl)
	{
	TFormaDocRegKassaCF * ob=new TFormaDocRegKassaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegOstNomImpl)
	{
	TFormaDocRegOstNomCF * ob=new TFormaDocRegOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegPaySaleImpl)
	{
	TFormaDocRegPaySaleCF * ob=new TFormaDocRegPaySaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRegVsRaschImpl)
	{
	TFormaDocRegVsRaschCF * ob=new TFormaDocRegVsRaschCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRepKKMImpl)
	{
	TFormaDocRepKKMCF * ob=new TFormaDocRepKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRevImpl)
	{
	TFormaDocRevCF * ob=new TFormaDocRevCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRKOImpl)
	{
	TFormaDocRKOCF * ob=new TFormaDocRKOCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRKORoznImpl)
	{
	TFormaDocRKORoznCF * ob=new TFormaDocRKORoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocSborkaKomplImpl)
	{
	TFormaDocSborkaKomplCF * ob=new TFormaDocSborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocSchetFactImpl)
	{
	TFormaDocSchetFactCF * ob=new TFormaDocSchetFactCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocSchetImpl)
	{
	TFormaDocSchetCF * ob=new TFormaDocSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocSpisNomImpl)
	{
	TFormaDocSpisNomCF * ob=new TFormaDocSpisNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocSpOtrOstImpl)
	{
	TFormaDocSpOtrOstCF * ob=new TFormaDocSpOtrOstCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocVipBankaImpl)
	{
	TFormaDocVipBankaCF * ob=new TFormaDocVipBankaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocVipuskProdImpl)
	{
	TFormaDocVipuskProdCF * ob=new TFormaDocVipuskProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocVosvratPokImpl)
	{
	TFormaDocVosvratPokCF * ob=new TFormaDocVosvratPokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocVosvratPostImpl)
	{
	TFormaDocVosvratPostCF * ob=new TFormaDocVosvratPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocZamenaImpl)
	{
	TFormaDocZamenaCF * ob=new TFormaDocZamenaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocInvImpl)
	{
	TFormaDocInvCF * ob=new TFormaDocInvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocOstVsImpl)
	{
	TFormaDocOstVsCF * ob=new TFormaDocOstVsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRealRoznForCashierImpl)
	{
	TFormaDocRealRoznForCashierCF * ob=new TFormaDocRealRoznForCashierCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRKORoznForCashierImpl)
	{
	TFormaDocRKORoznForCashierCF * ob=new TFormaDocRKORoznForCashierCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocPKORoznForCashierImpl)
	{
	TFormaDocPKORoznForCashierCF * ob=new TFormaDocPKORoznForCashierCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocVosvratPokForCashierImpl)
	{
	TFormaDocVosvratPokForCashierCF * ob=new TFormaDocVosvratPokForCashierCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaDocOtchetPostImpl)
	{
	TFormaDocOtchetPostCF * ob=new TFormaDocOtchetPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaDocRegOtchetPostImpl)
	{
	TFormaDocRegOtchetPostCF * ob=new TFormaDocRegOtchetPostCF();
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

if (icom->kanAddClass(CLSID_TFormaDocIsmPriceImpl,ProgId_FormaDocIsmPrice,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocIsmPrice)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPrihNaklImpl,ProgId_FormaDocPrihNakl,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocPrihNakl)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocCheckImpl,ProgId_FormaDocCheck,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocCheck)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocCheckProsmotrImpl,"Oberon.FormaDocCheckProsmotr.1","FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaDocCheckProsmotr.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocKorrVSImpl,ProgId_FormaDocKorrVs,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocKorrVs)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocOstNomImpl,ProgId_FormaDocOstNom,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocOstNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPerImpl,ProgId_FormaDocPer,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocPer)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPKOImpl,ProgId_FormaDocPKO,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocPKO)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPKORoznImpl,ProgId_FormaDocPKORozn,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocPKORozn)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPlatPorImpl,ProgId_FormaDocPlatPor,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocPlatPor)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPostNaSchetImpl,ProgId_FormaDocPostNaSchet,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocPostNaSchet)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRasborkaKomplImpl,ProgId_FormaDocRasborkaKompl,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRasborkaKompl)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRealImpl,ProgId_FormaDocReal,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocReal)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRealRoznImpl,ProgId_FormaDocRealRozn,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRealRozn)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegAdvCustImpl,ProgId_FormaDocRegAdvCust,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegAdvCust)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegBankImpl,ProgId_FormaDocRegBank,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegBank)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegCardBalanceImpl,ProgId_FormaDocRegCardBal,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegCardBal)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegGoodsImpl,ProgId_FormaDocRegGoods,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocRegGoods)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegKassaImpl,ProgId_FormaDocRegKassa,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocRegKassa)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegOstNomImpl,ProgId_FormaDocRegOstNom,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocRegOstNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegPaySaleImpl,ProgId_FormaDocRegPaySale,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegPaySale)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegVsRaschImpl,ProgId_FormaDocRegVsRasch,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegVsRasch)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaDocRegVsRaschImpl,ProgId_FormaDocOstVs,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocOstVs)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRepKKMImpl,ProgId_FormaDocRepKKM,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRepKKM)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRevImpl,ProgId_FormaDocRev,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocRev)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRKOImpl,ProgId_FormaDocRKO,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRKO)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRKORoznImpl,ProgId_FormaDocRKORozn,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRKORozn)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocSborkaKomplImpl,ProgId_FormaDocSborkaKompl,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocSborkaKompl)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocSchetFactImpl,ProgId_FormaDocSchetFact,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocSchetFact)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocSchetImpl,ProgId_FormaDocSchet,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocSchet)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocSpisNomImpl,ProgId_FormaDocSpisNom,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocSpisNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocSpOtrOstImpl,ProgId_FormaDocSpOtrOst,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocSpOtrOst)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocVipBankaImpl,ProgId_FormaDocVipBanka,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocVipBanka)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocVipuskProdImpl,ProgId_FormaDocVipuskProd,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocVipuskProd)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocVosvratPokImpl,ProgId_FormaDocVosvratPok,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocVosvratPok)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocVosvratPostImpl,ProgId_FormaDocVosvratPost,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocVosvratPost)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocZamenaImpl,ProgId_FormaDocZamena,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocZamena)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocInvImpl,ProgId_FormaDocInv,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocInv)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocOstVsImpl,"Oberon.FormaDocOstVs.1","FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaDocOstVs.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRealRoznForCashierImpl,ProgId_FormaDocRealRoznForCashiers,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRealRoznForCashiers)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRKORoznForCashierImpl,ProgId_FormaDocRKORoznForCashiers,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRKORoznForCashiers)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocPKORoznForCashierImpl,ProgId_FormaDocPKORoznForCashiers,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaDocPKORoznForCashiers)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocVosvratPokForCashierImpl,ProgId_FormaVosvratPokForCashiers,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaVosvratPokForCashiers)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaDocOtchetPostImpl,ProgId_FormaDocOtchetPost,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocOtchetPost)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRegOtchetPostImpl,ProgId_FormaDocRegOtchetPost,"FormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDocRegOtchetPost)+" !");
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

