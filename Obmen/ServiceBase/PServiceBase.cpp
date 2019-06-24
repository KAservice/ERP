//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("FormaXTableBase\UFormaXTableBase.cpp", FormaXTableBase);
USEFORM("FormaTableXDataOut\UFormaTableXDataOut.cpp", FormaTableXDataOut);
USEFORM("DocRegGoods\UFormaDocRegGoods.cpp", FormaDocRegGoods);
USEFORM("..\Forms\FormaSetNachValues\UFormaSetNachValues.cpp", FormaSetNachValues);
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("FormaTableIsm\UFormaTableIsm.cpp", FormaTableIsm);
USEFORM("UMainForm.cpp", MainForm);
USEFORM("FormaCreateTriggerLog\UFormaCreateTriggerLog.cpp", FormaCreateTriggerLog);
USEFORM("FormaAddDataInNewBase\UFormaAddDataInNewBase.cpp", FormaAddDataInNewBase);
USEFORM("DataModuleMain\UDataModuleMain.cpp", DataModuleMain); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Серсвисная программа для работы с базой данных";
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
