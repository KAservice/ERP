//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainForm.cpp", MainForm);
USEFORM("K:\FIB_DataModule\DocCheckKKM\UDMDocCheck.cpp", DMDocCheck); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprEd\UDMSprEd.cpp", DMSprEd); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprNom\UDMSprNom.cpp", DMSprNom); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprKKM\UDMSprKKM.cpp", DMSprKKM); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprPrice\UDMSprPrice.cpp", DMSprPrice); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprOborud\UDMSprOborud.cpp", DMSprOborud); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprARM\UDMSprARM.cpp", DMSprARM); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprSostProd\UDMSprSostProd.cpp", DMSprSostProd); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprNomRest\UDMSprNomRest.cpp", DMSprNomRest); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\DMQuery\UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\TableNumberDoc\UDMTableNumberDoc.cpp", DMTableNumberDoc); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\GurOperDiscountCard\UDMGurOperDiscountCard.cpp", DMGurOperDiscountCard); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprDiscountCard\UDMSprDiscountCard.cpp", DMSprDiscountCard); /* TDataModule: File Type */
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
//---------------------------------------------------------------------------
String ComandString;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR S, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		ComandString=S;
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
