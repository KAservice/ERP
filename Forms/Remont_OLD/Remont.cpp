//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UMainForm.cpp", MainForm);
USEFORM("..\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("..\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("..\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("..\DMQuery\UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("..\About\UAbout.cpp", FormAbout);
USEFORM("..\REM_SprNeispr\UREM_DMSprGrpNeispr.cpp", REM_DMSprGrpNeispr); /* TDataModule: File Type */
USEFORM("..\REM_SprNeispr\UREM_DMSprNeispr.cpp", REM_DMSprNeispr); /* TDataModule: File Type */
USEFORM("..\REM_SprNeispr\UREM_FormaElementaSprGrpNeispr.cpp", REM_FormaElementaSprGrpNeispr);
USEFORM("..\REM_SprNeispr\UREM_FormaElementaSprNeispr.cpp", REM_FormaElementaSprNeispr);
USEFORM("..\REM_SprNeispr\UREM_FormaSpiskaSprNeispr.cpp", REM_FormaSpiskaSprNeispr);
USEFORM("..\REM_SprModel\UREM_DMSprGrpModel.cpp", REM_DMSprGrpModel); /* TDataModule: File Type */
USEFORM("..\REM_SprModel\UREM_DMSprModel.cpp", REM_DMSprModel); /* TDataModule: File Type */
USEFORM("..\REM_SprModel\UREM_FormaElementaSprGrpModel.cpp", REM_FormaElementaSprGrpModel);
USEFORM("..\REM_SprModel\UREM_FormaElementaSprModel.cpp", REM_FormaElementaSprModel);
USEFORM("..\REM_SprModel\UREM_FormaSpiskaSprModel.cpp", REM_FormaSpiskaSprModel);
USEFORM("..\REM_SprKomplModel\UREM_DMSprKomplModel.cpp", REM_DMSprKomplModel); /* TDataModule: File Type */
USEFORM("..\REM_SprKomplModel\UREM_FormaElementaSprKomplModel.cpp", REM_FormaElementaSprKomplModel);
USEFORM("..\REM_SprKomplModel\UREM_FormaSpiskaSprKomplModel.cpp", REM_FormaSpiskaSprKomplModel);
USEFORM("..\REM_SprTypeRemont\UREM_DMSprTypeRemont.cpp", REM_DMSprTypeRemont); /* TDataModule: File Type */
USEFORM("..\REM_SprTypeRemont\UREM_FormaElementaSprTypeRemont.cpp", REM_FormaElementaSprTypeRemont);
USEFORM("..\REM_SprTypeRemont\UREM_FormaSpiskaSprTypeRem.cpp", REM_FormaSpiskaSprTypeRemont);
USEFORM("..\REM_SprSost\UREM_DMSprSost.cpp", REM_DMSprSost); /* TDataModule: File Type */
USEFORM("..\REM_SprSost\UREM_FormaElementaSprSost.cpp", REM_FormaElementaSprSost);
USEFORM("..\REM_SprSost\UREM_FormaSpiskaSprSost.cpp", REM_FormaSpiskaSprSost);
USEFORM("..\REM_GurZ\UREM_DMGurZ.cpp", REM_DMGurZ); /* TDataModule: File Type */
USEFORM("..\REM_GurZ\UREM_FormaGurZ.cpp", REM_FormaGurZ);
USEFORM("..\REM_GurZ\UREM_DMZayavka.cpp", REM_DMZayavka); /* TDataModule: File Type */
USEFORM("..\REM_GurZ\UREM_FormaZayavka.cpp", REM_FormaZayavka);
USEFORM("..\REM_GurZ\UREM_DMZayavkaDv.cpp", REM_DMZayavkaDv); /* TDataModule: File Type */
USEFORM("..\REM_GurZ\UREM_FormaZayavkaDv.cpp", REM_FormaZayavkaDv);
USEFORM("..\ViborPerioda\UFormaViborPerioda.cpp", FormaViborPerioda);
USEFORM("..\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("..\SFirm\UFormaSpiskaSprFirm.cpp", FormaSpiskaSprFirm);
USEFORM("..\SFirm\UDMSprFirm.cpp", DMSprFirm); /* TDataModule: File Type */
USEFORM("..\SFirm\UFormaElementaSprFirm.cpp", FormaElementaSprFirm);
USEFORM("..\SprInfBase\UFormaSpiskaSprInfBaseVibor.cpp", FormaSpiskaSprInfBaseVibor);
USEFORM("..\SprInfBase\UDMSprInfBase.cpp", DMSprInfBase); /* TDataModule: File Type */
USEFORM("..\SprSklad\UFormaSpiskaSprSklad.cpp", FormaSpiskaSprSklad);
USEFORM("..\SprSklad\UDMSprSklad.cpp", DMSprSklad); /* TDataModule: File Type */
USEFORM("..\SprSklad\UFormaElementaSprSklad.cpp", FormaElementaSprSklad);
USEFORM("..\SprKlient\UFormaSpiskaSprKlient.cpp", FormaSpiskaSprKlient);
USEFORM("..\SprKlient\UDMSprGrpKlient.cpp", DMSprGrpKlient); /* TDataModule: File Type */
USEFORM("..\SprKlient\UDMSprKlient.cpp", DMSprKlient); /* TDataModule: File Type */
USEFORM("..\SprKlient\UFormaElementaSprGrpKlient.cpp", FormaElementaSprGrpKlient);
USEFORM("..\SprKlient\UFormaElementaSprKlient.cpp", FormaElementaSprKlient);
USEFORM("..\SprKlientDopFisL\UFormaElementaSprKlientDopFisL.cpp", FormaElementaSprKlientDopFisL);
USEFORM("..\SprKlientDopFisL\UDMSprKlientDopFisL.cpp", DMSprKlientDopFisL); /* TDataModule: File Type */
USEFORM("..\SprKlientDopUrL\UDMSprKlientDopUrL.cpp", DMSprKlientDopUrL); /* TDataModule: File Type */
USEFORM("..\SprKlientDopUrL\UFormaElementaSprKlientDopUrL.cpp", FormaElementaSprKlientDopUrL);
USEFORM("..\DMXTableIsm\UDMXTableIsm.cpp", DMXTableIsm); /* TDataModule: File Type */
USEFORM("..\SBSchet\UDMSprBSchet.cpp", DMSprBSchet); /* TDataModule: File Type */
USEFORM("..\SBSchet\UFormaElementaSprBSchet.cpp", FormaElementaSprBSchet);
USEFORM("..\SBSchet\UFormaSpiskaSprBSchet.cpp", FormaSpiskaSprBSchet);
USEFORM("..\SprBank\UDMSprBank.cpp", DMSprBank); /* TDataModule: File Type */
USEFORM("..\SprBank\UFormaElementaSprBank.cpp", FormaElementaSprBank);
USEFORM("..\SprBank\UFormaSpiskaSprBank.cpp", FormaSpiskaSprBank);
USEFORM("..\SRSchet\UDMSprRaschSchet.cpp", DMSprRaschSchet); /* TDataModule: File Type */
USEFORM("..\SRSchet\UFormaElementaSprRaschSchet.cpp", FormaElementaSprRaschSchet);
USEFORM("..\SRSchet\UFormaSpiskaSprRaschSchet.cpp", FormaSpiskaSprRaschSchet);
USEFORM("..\SprNumTel\UDMSprNumTel.cpp", DMSprNumTel); /* TDataModule: File Type */
USEFORM("..\SprNumTel\UFormaElementaSprNumTel.cpp", FormaElementaSprNumTel);
USEFORM("..\SprNumTel\UFormaSpiskaSprNumTel.cpp", FormaSpiskaSprNumTel);
USEFORM("..\SprDogovor\UDMSprDogovor.cpp", DMSprDogovor); /* TDataModule: File Type */
USEFORM("..\SprDogovor\UFormaElementaSprDogovor.cpp", FormaElementaSprDogovor);
USEFORM("..\SprDogovor\UFormaSpiskaSprDogovor.cpp", FormaSpiskaSprDogovor);
USEFORM("..\SprDogovor\UFormaViborSprDogovor.cpp", FormaViborSprDogovor);
USEFORM("..\SprDocKlient\UDMSprDocKlient.cpp", DMSprDocKlient); /* TDataModule: File Type */
USEFORM("..\SprDocKlient\UFormaElementaSprDocKlient.cpp", FormaElementaSprDocKlient);
USEFORM("..\SprDocKlient\UFormaSpiskaSprDocKlient.cpp", FormaSpiskaSprDocKlient);
USEFORM("..\SprGrafikPlat\UDMSprGrafikPlat.cpp", DMSprGrafikPlat); /* TDataModule: File Type */
USEFORM("..\SprGrafikPlat\UFormaSpiskaSprGrafikPlat.cpp", FormaSpiskaSprGrafikPlat);
USEFORM("..\SprTypePrice\UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("..\SprTypePrice\UFormaElementaSprTypePrice.cpp", FormaElementaSprTypePrice);
USEFORM("..\SprTypePrice\UFormaSpiskaSprTypePrice.cpp", FormaSpiskaSprTypePrice);
USEFORM("..\SprVidKlient\UDMSprVidKlient.cpp", DMSprVidKlient); /* TDataModule: File Type */
USEFORM("..\SprVidKlient\UFormaSpiskaSprVidKlient.cpp", FormaSpiskaSprVidKlient);
USEFORM("..\SprCountry\UDMSprCountry.cpp", DMSprCountry); /* TDataModule: File Type */
USEFORM("..\SprCountry\UFormaElementaSprCountry.cpp", FormaElementaSprCountry);
USEFORM("..\SprCountry\UFormaSpiskaSprCountry.cpp", FormaSpiskaSprCountry);
USEFORM("..\Kladr\UFormaKladr.cpp", FormaKladr);
USEFORM("..\Kladr\UFormaKladrViborRegion.cpp", FormaKladrViborRegion);
USEFORM("..\Kladr\UFormaKladrViborStreet.cpp", FormaKladrViborStreet);
USEFORM("..\SprDiscountCard\UDMSprDiscountCard.cpp", DMSprDiscountCard); /* TDataModule: File Type */
USEFORM("..\SprDiscountCard\UFormaElementaSprDiscountCard.cpp", FormaElementaSprDiscountCard);
USEFORM("..\SprDiscountCard\UFormaSpiskaSprDiscountCard.cpp", FormaSpiskaSprDiscountCard);
USEFORM("..\SprVidDiscountCard\UDMSprVidDiscountCard.cpp", DMSprVidDiscountCard); /* TDataModule: File Type */
USEFORM("..\SprVidDiscountCard\UFormaElementaSprVidDiscountCard.cpp", FormaElementaSprVidDiscountCard);
USEFORM("..\SprVidDiscountCard\UFormaSpiskaSprVidDiscountCard.cpp", FormaSpiskaSprVidDiscountCard);
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
