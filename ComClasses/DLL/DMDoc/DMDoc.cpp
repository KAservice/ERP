//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UDMDocPrihNaklImpl.h"
#include "UDMDocPrihNaklCF.h"
#include "UDMDocCheckImpl.h"
#include "UDMDocCheckCF.h"
#include "UDMDocInvImpl.h"
#include "UDMDocInvCF.h"
#include "UDMDocIsmPriceImpl.h"
#include "UDMDocIsmPriceCF.h"
#include "UDMDocKorrVsImpl.h"
#include "UDMDocKorrVsCF.h"
#include "UDMDocOstNomImpl.h"
#include "UDMDocOstNomCF.h"
#include "UDMDocOstVsImpl.h"
#include "UDMDocOstVsCF.h"
#include "UDMDocPerImpl.h"
#include "UDMDocPerCF.h"
#include "UDMDocPKOImpl.h"
#include "UDMDocPKOCF.h"
#include "UDMDocPKORoznImpl.h"
#include "UDMDocPKORoznCF.h"
#include "UDMDocPLPImpl.h"
#include "UDMDocPLPCF.h"
#include "UDMDocPostNaSchetImpl.h"
#include "UDMDocPostNaSchetCF.h"
#include "UDMDocRasborkaKomplImpl.h"
#include "UDMDocRasborkaKomplCF.h"
#include "UDMDocRealImpl.h"
#include "UDMDocRealCF.h"
#include "UDMDocRealRoznImpl.h"
#include "UDMDocRealRoznCF.h"
#include "UDMDocRegAdvCustImpl.h"
#include "UDMDocRegAdvCustCF.h"
#include "UDMDocRegBankImpl.h"
#include "UDMDocRegBankCF.h"
#include "UDMDocRegCardBalanceImpl.h"
#include "UDMDocRegCardBalanceCF.h"
#include "UDMDocRegGoodsImpl.h"
#include "UDMDocRegGoodsCF.h"
#include "UDMDocRegKassaImpl.h"
#include "UDMDocRegKassaCF.h"
#include "UDMDocRegOstNomImpl.h"
#include "UDMDocRegOstNomCF.h"
#include "UDMDocRegPaySaleImpl.h"
#include "UDMDocRegPaySaleCF.h"
#include "UDMDocRegVsRaschImpl.h"
#include "UDMDocRegVsRaschCF.h"
#include "UDMDocRepKKMImpl.h"
#include "UDMDocRepKKMCF.h"
#include "UDMDocRevImpl.h"
#include "UDMDocRevCF.h"
#include "UDMDocRKOImpl.h"
#include "UDMDocRKOCF.h"
#include "UDMDocRKORoznImpl.h"
#include "UDMDocRKORoznCF.h"
#include "UDMDocSborkaKomplImpl.h"
#include "UDMDocSborkaKomplCF.h"
#include "UDMDocSchetFactImpl.h"
#include "UDMDocSchetFactCF.h"
#include "UDMDocSchetImpl.h"
#include "UDMDocSchetCF.h"
#include "UDMDocSpisNomImpl.h"
#include "UDMDocSpisNomCF.h"
#include "UDMDocSpOtrOstImpl.h"
#include "UDMDocSpOtrOstCF.h"
#include "UDMDocVipBankaImpl.h"
#include "UDMDocVipBankaCF.h"
#include "UDMDocVipuskProdImpl.h"
#include "UDMDocVipuskProdCF.h"
#include "UDMDocVosvratPokImpl.h"
#include "UDMDocVosvratPokCF.h"
#include "UDMDocVosvratPostImpl.h"
#include "UDMDocVosvratPostCF.h"
#include "UDMDocZamenaImpl.h"
#include "UDMDocZamenaCF.h"

#include "UDMDocOtchetPostImpl.h"
#include "UDMDocOtchetPostCF.h"

#include "UDMDocRegOtchetPostImpl.h"
#include "UDMDocRegOtchetPostCF.h"
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
if (id_class==CLSID_TDMDocPrihNaklImpl)
	{
	TDMDocPrihNaklCF * ob=new TDMDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocCheckImpl)
	{
	TDMDocCheckCF * ob=new TDMDocCheckCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocInvImpl)
	{
	TDMDocInvCF * ob=new TDMDocInvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocIsmPriceImpl)
	{
	TDMDocIsmPriceCF * ob=new TDMDocIsmPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocKorrVsImpl)
	{
	TDMDocKorrVsCF * ob=new TDMDocKorrVsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocOstNomImpl)
	{
	TDMDocOstNomCF * ob=new TDMDocOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocOstVsImpl)
	{
	TDMDocOstVsCF * ob=new TDMDocOstVsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocPerImpl)
	{
	TDMDocPerCF * ob=new TDMDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocPKOImpl)
	{
	TDMDocPKOCF * ob=new TDMDocPKOCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocPKORoznImpl)
	{
	TDMDocPKORoznCF * ob=new TDMDocPKORoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocPlPImpl)
	{
	TDMDocPlPCF * ob=new TDMDocPlPCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocPostNaSchetImpl)
	{
	TDMDocPostNaSchetCF * ob=new TDMDocPostNaSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRasborkaKomplImpl)
	{
	TDMDocRasborkaKomplCF * ob=new TDMDocRasborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRealImpl)
	{
	TDMDocRealCF * ob=new TDMDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRealRoznImpl)
	{
	TDMDocRealRoznCF * ob=new TDMDocRealRoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegAdvCustImpl)
	{
	TDMDocRegAdvCustCF * ob=new TDMDocRegAdvCustCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegBankImpl)
	{
	TDMDocRegBankCF * ob=new TDMDocRegBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegCardBalanceImpl)
	{
	TDMDocRegCardBalanceCF * ob=new TDMDocRegCardBalanceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegGoodsImpl)
	{
	TDMDocRegGoodsCF * ob=new TDMDocRegGoodsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegKassaImpl)
	{
	TDMDocRegKassaCF * ob=new TDMDocRegKassaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegOstNomImpl)
	{
	TDMDocRegOstNomCF * ob=new TDMDocRegOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegPaySaleImpl)
	{
	TDMDocRegPaySaleCF * ob=new TDMDocRegPaySaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegVsRaschImpl)
	{
	TDMDocRegVsRaschCF * ob=new TDMDocRegVsRaschCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRepKKMImpl)
	{
	TDMDocRepKKMCF * ob=new TDMDocRepKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRevImpl)
	{
	TDMDocRevCF * ob=new TDMDocRevCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRKOImpl)
	{
	TDMDocRKOCF * ob=new TDMDocRKOCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRKORoznImpl)
	{
	TDMDocRKORoznCF * ob=new TDMDocRKORoznCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocSborkaKomplImpl)
	{
	TDMDocSborkaKomplCF * ob=new TDMDocSborkaKomplCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocSchetFactImpl)
	{
	TDMDocSchetFactCF * ob=new TDMDocSchetFactCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocSchetImpl)
	{
	TDMDocSchetCF * ob=new TDMDocSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocSpisNomImpl)
	{
	TDMDocSpisNomCF * ob=new TDMDocSpisNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocSpOtrOstImpl)
	{
	TDMDocSpOtrOstCF * ob=new TDMDocSpOtrOstCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocVipBankaImpl)
	{
	TDMDocVipBankaCF * ob=new TDMDocVipBankaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocVipuskProdImpl)
	{
	TDMDocVipuskProdCF * ob=new TDMDocVipuskProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocVosvratPokImpl)
	{
	TDMDocVosvratPokCF * ob=new TDMDocVosvratPokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocVosvratPostImpl)
	{
	TDMDocVosvratPostCF * ob=new TDMDocVosvratPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocZamenaImpl)
	{
	TDMDocZamenaCF * ob=new TDMDocZamenaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocOtchetPostImpl)
	{
	TDMDocOtchetPostCF * ob=new TDMDocOtchetPostCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMDocRegOtchetPostImpl)
	{
	TDMDocRegOtchetPostCF * ob=new TDMDocRegOtchetPostCF();
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

if (icom->kanAddClass(CLSID_TDMDocPrihNaklImpl,ProgId_DMDocPrihNakl,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocPrihNakl)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocCheckImpl,ProgId_DMDocCheck,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocCheck)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocInvImpl,ProgId_DMDocInv,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocInv)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocIsmPriceImpl,ProgId_DMDocIsmPrice,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocIsmPrice)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocKorrVsImpl,ProgId_DMDocKorrVs,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocKorrVs)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocOstNomImpl,ProgId_DMDocOstNom,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocOstNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocOstVsImpl,ProgId_DMDocOstVs,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocOstVs)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocPerImpl,ProgId_DMDocPer,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocPer)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocPKOImpl,ProgId_DMDocPKO,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocPKO)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocPKORoznImpl,ProgId_DMDocPKORozn,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocPKORozn)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocPlPImpl,ProgId_DMDocPlP,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocPlP)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocPostNaSchetImpl,ProgId_DMDocPostNaSchet,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocPostNaSchet)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRasborkaKomplImpl,ProgId_DMDocRasborkaKompl,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRasborkaKompl)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRealImpl,ProgId_DMDocReal,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocReal)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRealRoznImpl,ProgId_DMDocRealRozn,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRealRozn)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegAdvCustImpl,ProgId_DMDocRegAdvCust,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegAdvCust)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegBankImpl,ProgId_DMDocRegBank,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegBank)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegCardBalanceImpl,ProgId_DMDocRegCardBal,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegCardBal)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegGoodsImpl,ProgId_DMDocRegGoods,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegGoods)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegKassaImpl,ProgId_DMDocRegKassa,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegKassa)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegOstNomImpl,ProgId_DMDocRegOstNom,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegOstNom)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegPaySaleImpl,ProgId_DMDocRegPaySale,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocRegPaySale)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRegVsRaschImpl,ProgId_DMDocRegVsRasch,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegVsRasch)+" !");
	}


if (icom->kanAddClass(CLSID_TDMDocRepKKMImpl,ProgId_DMDocRepKKM,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRepKKM)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocRevImpl,ProgId_DMDocRev,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocRev)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRKOImpl,ProgId_DMDocRKO,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocRKO)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocRKORoznImpl,ProgId_DMDocRKORozn,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRKORozn)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocSborkaKomplImpl,ProgId_DMDocSborkaKompl,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocSborkaKompl)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocSchetFactImpl,ProgId_DMDocSchetFact,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocSchetFact)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocSchetImpl,ProgId_DMDocSchet,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocSchet)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocSpisNomImpl,ProgId_DMDocSpisNom,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocSpisNom)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocSpOtrOstImpl,ProgId_DMDocSpOtrOst,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocSpOtrOst)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocVipBankaImpl,ProgId_DMDocVipBanka,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocVipBanka)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMDocVipuskProdImpl,ProgId_DMDocVipuskProd,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMDocVipuskProd)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocVosvratPokImpl,ProgId_DMDocVosvratPok,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocVosvratPok)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocVosvratPostImpl,ProgId_DMDocVosvratPost,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocVosvratPost)+" !");
	}
if (icom->kanAddClass(CLSID_TDMDocZamenaImpl,ProgId_DMDocZamena,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocZamena)+" !");
	}


if (icom->kanAddClass(CLSID_TDMDocOtchetPostImpl,ProgId_DMDocOtchetPost,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocOtchetPost)+" !");
	}

if (icom->kanAddClass(CLSID_TDMDocRegOtchetPostImpl,ProgId_DMDocRegOtchetPost,"DMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDocRegOtchetPost)+" !");
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

