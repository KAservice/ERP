//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UMainForm.cpp", MainForm);
USEFORM("SetupScale\UFormaSetupScale.cpp", FormSetupScale);
USEFORM("K:\Forms\About\UAbout.cpp", FormAbout);
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("UDMSprARM.cpp", DMSprARM); /* TDataModule: File Type */
USEFORM("UDMSprOborud.cpp", DMSprOborud); /* TDataModule: File Type */
USEFORM("UDMSprScale.cpp", DMSprScale); /* TDataModule: File Type */
USEFORM("UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("UDMSprVesNomForScale.cpp", DMSprVesNomForScale); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
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
