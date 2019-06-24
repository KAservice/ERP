//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("K:\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("K:\Forms\ViborBase\UFormaViborBaseTouch.cpp", FormaViborBaseTouch);
USEFORM("UArmOf.cpp", ArmOf);
USEFORM("K:\Forms\ViborBase\UKalkulator.cpp", Kalkulator);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->Title = "Арм официанта (бармена)";
		Application->CreateForm(__classid(TArmOf), &ArmOf);
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
