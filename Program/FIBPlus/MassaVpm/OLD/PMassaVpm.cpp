//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("K:\Forms\About\UAbout.cpp", FormAbout);
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("K:\FIB_DataModule\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprVesNom\UDMSprVesNomForScale.cpp", DMSprVesNomForScale); /* TDataModule: File Type */
USEFORM("SetupScale\UFormaSetupScale.cpp", FormSetupScale);
USEFORM("UMainForm.cpp", MainForm);
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("K:\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\DMQuery\UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprScale\UDMSprScale.cpp", DMSprScale); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprTypePrice\UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprARM\UDMSprARM.cpp", DMSprARM); /* TDataModule: File Type */
USEFORM("K:\FIB_DataModule\SprOborud\UDMSprOborud.cpp", DMSprOborud); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->CreateForm(__classid(TMainForm), &MainForm);
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
