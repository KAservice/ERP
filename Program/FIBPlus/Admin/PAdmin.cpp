//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\..\..\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("UF1.cpp", F1);
USEFORM("..\..\..\Forms\Indicator\UFormIndicator.cpp", FormIndicator);
USEFORM("..\..\..\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("..\..\..\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("..\..\..\Forms\About\UAbout.cpp", FormAbout);
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
