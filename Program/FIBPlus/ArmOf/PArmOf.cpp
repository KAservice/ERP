//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("..\..\..\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\..\..\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("..\..\..\Forms\ViborBase\UFormaViborBaseTouch.cpp", FormaViborBaseTouch);
USEFORM("UArmOf.cpp", ArmOf);
USEFORM("..\..\..\Forms\ViborBase\UKalkulator.cpp", Kalkulator);
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
