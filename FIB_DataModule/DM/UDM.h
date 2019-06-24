//---------------------------------------------------------------------------

#ifndef UDMH
#define UDMH
#include "cxEdit.hpp"
#include "cxEditRepositoryItems.hpp"
#include "cxLocalization.hpp"
#include "cxStyles.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ImgList.hpp>

//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
        TImageList *ImageList1;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyleHeaderTable;
	TcxStyle *cxStyleFooterSum;
	TcxStyle *cxStyleVidelString;
	TcxStyle *cxStyleVidStringSkyBlue;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyleCaptionReport;
	TcxStyle *cxStyleHeaderReport;
	TcxStyle *cxStyleFooterReport;
	TcxStyle *cxStyleFilterBarReport;
	TcxStyle *cxStyleBandHeadeReportr;
	TcxStyle *cxStyleGroupReport;
	TcxLocalizer *cxLocalizer1;
	TcxStyle *cxStyleGirnFont;
	TcxEditRepository *cxEditRepository1;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxNDS;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTNOM;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeSrokaGodn;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeExtModule;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxObjectExtModule;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeBarCode;
	TcxEditRepositoryImageComboBoxItem *REM_cxEditRepository1ImageComboBoxItemOperDocSetServ;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemBankOperation;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeProgramModule;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemKassaOperation;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeDocForOtbor;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem1TypeDiscountCard;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxGC_Forms;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeApplication;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxGC_ObjectBaseForPriv;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeNumberDoc;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxDiscountAuto_TypeAction;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemSostZayvkiNaRemont;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemSostQueryCust;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeAktRemont;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxKlientUvedomlen;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTrebKonsultKlienta;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxKlientOtvetNaZapros;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeRemont;
	TcxStyle *cxStyleZakPrice;
	TcxStyle *cxStyleProcentNacenka;
	TcxStyle *cxStyleDoxod;
	TcxStyle *cxStyleYellow;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxREM_KemSdano;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeDvReg;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeCustomerQuery;
	TcxStyle *cxStyleclMoneyGreen;
	TcxStyle *cxStyleclSkyBlue;
	TcxStyle *cxStyleclSilver;
	TcxStyle *cxStyleSmallFont;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypePoiskSprNomProducer;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeTextInfBlock;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemGotovoKVidache;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeElementaSprHW;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemOperationRemDocZPer;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_Z_FL_VKL;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_Z_FL_ZIP;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_Z_FL_DEFECT_DEMO;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_Z_KLIENT_PREDUPREGDEN;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_FL_PROBLEM_DEVICE;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_FL_PROBLEM_KLIENT;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItem_REM_FL_POVTOR_REM_Z;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxRES_REM_GUR_PROV;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeKlent;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTypeDevice;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemTYPE_POISK_SKLIENT;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemFlagIspZip;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemRESULT_REM_Z2;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemPRICHINA_LIST_REM_Z2;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxItemOUT_ISTOCHNIK;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxAktFlKompl;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxAktFlMexPovr;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxAktPrichinaAkta;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxAktPrichinaSost;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxAktFlMestonax;
	TcxEditRepositoryImageComboBoxItem *cxEditRepository1ImageComboBoxTypeValue;
private:	// User declarations
public:		// User declarations
        __fastcall TDM(TComponent* Owner);



};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;

//UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
//UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len);
//UnicodeString AddEAN13(UnicodeString Cod);

//UnicodeString glGetNameDoc(UnicodeString StrCodeDoc);
//UnicodeString glGetNameDocRemont(UnicodeString str_code_doc);
//UnicodeString glGetNameDocHotel(UnicodeString StrCodeDoc);
//UnicodeString triada(UnicodeString in, int tn);
//UnicodeString ValuePropis(UnicodeString in);
//UnicodeString CurrencyPropis(double Value);
//UnicodeString IntegerValuePropis(int Value);
//UnicodeString CommaToPixel(UnicodeString value);
//UnicodeString ConvertString(UnicodeString s1, UnicodeString s2, UnicodeString s3);   //Заменить в строке s1 все вхождения s2 на s3
//__int64 glStrToInt64(UnicodeString value);
//UnicodeString glFormatForXML(UnicodeString s);
//---------------------------------------------------------------------------
//char*
//WriteSum (double v,char *buf,bool kop,bool up) ;

//---------------------------------------------------------------------------
//float glGetKolProgiv1(TDateTime Nach, TDateTime Con);
//----------------------------------------------------------------------------




//UnicodeString GetBinareStructEAN13(UnicodeString sh_code);

//double RoundValue(double value, int  rasr);




//int GetRateNDS(int code);

//int glCompareDoubleValue(double v1, double v2, int pogr);

#endif
