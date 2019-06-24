//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("K:\Forms\About\UAbout.cpp", FormAbout);
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("SetupScale\UFormaSetupScale.cpp", FormSetupScale);
USEFORM("UMainForm.cpp", MainForm);
USEFORM("..\MassaVpm\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprARM.cpp", DMSprARM); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprOborud.cpp", DMSprOborud); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprScale.cpp", DMSprScale); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("..\MassaVpm\UDMSprVesNomForScale.cpp", DMSprVesNomForScale); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->Title = "Панель управления весами ВП (Масса-К)";
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
