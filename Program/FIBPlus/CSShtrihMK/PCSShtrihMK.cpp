//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UF.cpp", F);
USEFORM("Форма запуска\UZapusk.cpp", FZapusk);
USEFORM("Форма запуска\UChanche.cpp", FChanche);
USEFORM("..\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\DocCheckKKM\UDMDocCheck.cpp", DMDocCheck); /* TDataModule: File Type */
USEFORM("..\SFirm\UDMSFirm.cpp", DMSFirm); /* TDataModule: File Type */
USEFORM("..\SprEd\UDMSprEd.cpp", DMSprEd); /* TDataModule: File Type */
USEFORM("..\SprKKM\UDMSprKKM.cpp", DMSprKKM); /* TDataModule: File Type */
USEFORM("..\SprSklad\UDMSprSklad.cpp", DMSprSklad); /* TDataModule: File Type */
USEFORM("..\SprNom\UDMSprNom.cpp", DMSprNom); /* TDataModule: File Type */
USEFORM("..\SprPrice\UDMSprPrice.cpp", DMSprPrice); /* TDataModule: File Type */
USEFORM("..\RegOtrSpisNom\UDMRegOtrSpisNom.cpp", DMRegOtrSpisNom); /* TDataModule: File Type */
USEFORM("..\RegReal\UDMRegReal.cpp", DMRegReal); /* TDataModule: File Type */
USEFORM("..\RegSebProd\UDMRegSebProd.cpp", DMRegSebProd); /* TDataModule: File Type */
USEFORM("..\RegVipuskProd\UDMRegVipuskProd.cpp", DMRegVipuskProd); /* TDataModule: File Type */
USEFORM("..\RegOstNom\UDMRegOstNom.cpp", DMRegOstNom); /* TDataModule: File Type */
USEFORM("..\RegVsRasch\UDMRegVsRasch.cpp", DMRegVsRasch); /* TDataModule: File Type */
USEFORM("..\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("..\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("..\SprSostProd\UDMSostProd.cpp", DMSprSostProd); /* TDataModule: File Type */
USEFORM("..\SprNomRest\UDMSprNomRest.cpp", DMSprNomRest); /* TDataModule: File Type */
USEFORM("..\DMXTableIsm\UDMXTableIsm.cpp", DMXTableIsm); /* TDataModule: File Type */
//---------------------------------------------------------------------------
String ComandString;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR S, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TF), &F);
                 Application->CreateForm(__classid(TFZapusk), &FZapusk);
                 ComandString=S;
                 //Application->ShowMainForm=false;
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
