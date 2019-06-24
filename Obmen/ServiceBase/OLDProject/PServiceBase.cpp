//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UMainForm.cpp", MainForm);
USEFORM("DataModuleMain\UDataModuleMain.cpp", DataModuleMain); /* TDataModule: File Type */
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("FormaTableXDataOut\UFormaTableXDataOut.cpp", FormaTableXDataOut);
USEFORM("FormaTableIsm\UFormaTableIsm.cpp", FormaTableIsm);
USEFORM("FormaAddDataInNewBase\UFormaAddDataInNewBase.cpp", FormaAddDataInNewBase);
USEFORM("FormaCreateTriggerLog\UFormaCreateTriggerLog.cpp", FormaCreateTriggerLog);
USEFORM("FormaXTableBase\UFormaXTableBase.cpp", FormaXTableBase);
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
