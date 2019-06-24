//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("K:\Forms\About\UAbout.cpp", FormAbout);
USEFORM("UF1.cpp", F1);
USEFORM("K:\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("K:\Forms\Indicator\UFormIndicator.cpp", FormIndicator);
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Основной модуль";
		Application->CreateForm(__classid(TF1), &F1);
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
