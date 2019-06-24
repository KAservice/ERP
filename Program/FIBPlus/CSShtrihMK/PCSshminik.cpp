//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UF.cpp", F);
USEFORM("..\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\DocCheckKKM\UDMDocCheck.cpp", DMDocCheck); /* TDataModule: File Type */
USEFORM("..\SprEd\UDMSprEd.cpp", DMSprEd); /* TDataModule: File Type */
USEFORM("..\SprKKM\UDMSprKKM.cpp", DMSprKKM); /* TDataModule: File Type */
USEFORM("..\SprSklad\UDMSprSklad.cpp", DMSprSklad); /* TDataModule: File Type */
USEFORM("..\SprNom\UDMSprNom.cpp", DMSprNom); /* TDataModule: File Type */
USEFORM("..\SprPrice\UDMSprPrice.cpp", DMSprPrice); /* TDataModule: File Type */
USEFORM("..\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("..\RegOstNom\UDMRegOstNom.cpp", DMRegOstNom); /* TDataModule: File Type */
USEFORM("..\RegOtrSpisNom\UDMRegOtrSpisNom.cpp", DMRegOtrSpisNom); /* TDataModule: File Type */
USEFORM("..\RegReal\UDMRegReal.cpp", DMRegReal); /* TDataModule: File Type */
USEFORM("..\RegSebProd\UDMRegSebProd.cpp", DMRegSebProd); /* TDataModule: File Type */
USEFORM("..\RegVipuskProd\UDMRegVipuskProd.cpp", DMRegVipuskProd); /* TDataModule: File Type */
USEFORM("..\RegVsRasch\UDMRegVsRasch.cpp", DMRegVsRasch); /* TDataModule: File Type */
USEFORM("..\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("..\SprSostProd\UDMSostProd.cpp", DMSprSostProd); /* TDataModule: File Type */
USEFORM("..\SprNomRest\UDMSprNomRest.cpp", DMSprNomRest); /* TDataModule: File Type */
USEFORM("..\DMXTableIsm\UDMXTableIsm.cpp", DMXTableIsm); /* TDataModule: File Type */
USEFORM("..\ViborBase\UFormaEditBase.cpp", FormaEditBase);
USEFORM("..\ViborBase\UFormaViborBase.cpp", FormaViborBase);
USEFORM("..\RegKassa\UDMRegKassa.cpp", DMRegKassa); /* TDataModule: File Type */
USEFORM("..\SprARM\UDMSprARM.cpp", DMSprARM); /* TDataModule: File Type */
USEFORM("..\SprOborud\UDMSprOborud.cpp", DMSprOborud); /* TDataModule: File Type */
USEFORM("..\SFirm\UDMSprFirm.cpp", DMSprFirm); /* TDataModule: File Type */
//---------------------------------------------------------------------------
String ComandString;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR S, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TF), &F);
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
