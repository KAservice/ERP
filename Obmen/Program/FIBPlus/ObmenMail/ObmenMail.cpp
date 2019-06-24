//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("..\..\..\FIB_DataModule\XDataOut\UDMXDataOut.cpp", DMXDataOut); /* TDataModule: File Type */
USEFORM("..\..\..\FIB_DataModule\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\..\..\FIB_DataModule\DMUribOut\UDMUribOut.cpp", DMUribOut); /* TDataModule: File Type */
USEFORM("..\..\..\Forms\FormaSetupObmen\UFormaSetupObmen.cpp", FormaSetupObmen);
USEFORM("UMainForm.cpp", MainForm);
USEFORM("..\..\..\FIB_DataModule\DMUribIn\UDMUribIn.cpp", DMUribIn); /* TDataModule: File Type */
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
