//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UMainForm.cpp", MainForm);
USEFORM("DataModuleMain\UDataModuleMain.cpp", DataModuleMain); /* TDataModule: File Type */
USEFORM("K:\Forms\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("K:\Forms\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("ImportGrpNom\UFormaImportGrpNom.cpp", FormaImportGrpNom);
USEFORM("ImportNom\UFormaImportNom.cpp", FormaImportNom);
USEFORM("ImportEd\UFormaImportEd.cpp", FormaImportEd);
USEFORM("SetEdNom\UFormaSetEdNom.cpp", FormaSetEdNom);
USEFORM("ImportTypePrice\UFormaImportTypePrice.cpp", FormaImportTypePrice);
USEFORM("ImportPrice\UFormaImportPrice.cpp", FormaImportPrice);
USEFORM("ImportGrpKlient\UFormaImportGrpKlient.cpp", FormaImportGrpKlient);
USEFORM("ImportKlient\UFormaImportKlient.cpp", FormaImportKlient);
USEFORM("ImportGrpKKT\UFormaImportGrpKKT.cpp", FormaImportGrpKKT);
USEFORM("ImportKKT\UFormaImportKKT.cpp", FormaImportKKT);
USEFORM("InportOstTov\UFormaImportOstTov.cpp", FormaImportOstTov);
USEFORM("ImportOstVs\UFormaImportOstVs.cpp", FormaImportOstVs);
USEFORM("ImportGrpMainMenu\UFormaImportGrpMainMenu.cpp", FormaImportGrpMainMenu);
USEFORM("ImportMainMenu\UFormaImportMainMenu.cpp", FormaImportMainMenu);
USEFORM("ImportDiscountCard\UFormaImportDiscountCard.cpp", FormaImportDiscountCard);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->Title = "Загрузка данных из файлов в формате Excel";
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
