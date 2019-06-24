//---------------------------------------------------------------------------

#ifndef UGlobalConstantH
#define UGlobalConstantH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>


//ƒÀﬂ √À¿¬ÕŒ√Œ Ã≈Õﬁ
#define GC_FormaSpiskaInterfMainMenu 1
#define GC_FormaSpiskaSprUser 2

#define GC_REM_FormaSpiskaSprNeispr 3
#define GC_REM_FormaSpiskaSprModel  4
#define GC_REM_FormaSpiskaSprTypeRemont  5
#define GC_REM_FormaSpiskaSprSost  6
#define GC_REM_FormaGurZ  7
#define GC_REM_FormaGurAllDoc  8
#define GC_REM_FormaDocRemont  9
#define GC_REM_FormaDocRemontHW 10
#define GC_REM_FormaSpiskaSprKKT  11
#define GC_REM_FormaDocRemontKKT 12
#define GC_REM_FormaDocKM1 13
#define GC_REM_FormaDocKM2 14
#define GC_REM_FormaDocSetServKKT 15
#define GC_REM_FormaDocSetServHW  16
#define GC_REM_FormaSpiskaSprHardware  18
#define GC_FormaSpiskaSprFirm 19
#define GC_FormaSpiskaSprSklad 20
#define GC_FormaSpiskaSprKKM 21
#define GC_FormaSpiskaSprKlient 22
#define GC_FormaSpiskaSprNom 23
#define GC_FormaGurAllDoc 24
#define GC_FormaDocPrihNakl 25
#define GC_FormaDocCheck 26
#define GC_FormaDocSchet 27
#define GC_FormaDocOstNom 28
#define GC_FormaDocPer 29
#define GC_FormaDocReal 30
#define GC_FormaDocSpisNom 31
#define GC_FormaDocVosvratPost 32
#define GC_FormaDocPKO 33
#define GC_FormaDocRKO 34
#define GC_FormaDocPlatPor 35
#define GC_FormaDocPostNaSchet 36
#define GC_FormaSpiskaSprPodr 37
#define GC_FormaSpiskaSprBVNom 38
#define GC_FormaSpiskaSprStrObject 39
#define GC_FormaReportOCBRegGoods 40
#define GC_FormaSpiskaSprTypePrice 41
#define GC_FormaSpiskaSprMPrig 42
#define GC_FormaSpiskaSprCodeTel 43
#define GC_FormaDialogaReportSaleCheck 44
#define GC_FormaGurDocPrihNakl 45
#define GC_FormaGurDocCheckKKM  46
#define GC_FormaGurDocPer 47
#define GC_FormaReportOCBRegVSRasch 48
#define GC_FormaDocInv 49
#define GC_FormaDialogaReportResultReal 50
#define GC_FormaReportVipuskProd 51
#define GC_FormaReportKartTovara 52
#define GC_FormaSpiskaSetup 53
#define GC_FormaReportKartKlient 54
#define GC_FormaSpiskaSprInfBase 55
#define GC_FormaDocRepKKM 56
#define GC_FormaReportKalkKarta 57
#define GC_FormaReportOCBRegOstNom 58
#define GC_FormaReportRashodProduct 59
#define GC_FormaSpiskaSprARM 100
#define GC_FormaSpiskaSprVesNom 60
#define GC_FormaDocOstVs 61
#define GC_SheetEditor 62
#define GC_FormaDocRealRozn 63
#define GC_FormaDocPKORozn  64
#define GC_FormaDocRKORozn 65
#define GC_FormaReportOCBPaySale 66
#define GC_FormaReportKassa 67
#define GC_FormaReportBank  68
#define GC_FormaPrintPriceA  69
#define GC_FormaSpiskaSprInv 70
#define GC_FormaDocVosvratPok 71
#define GC_FormaDocSpOtrOst 72
#define GC_FormaDocIsmPrice 73
#define GC_FormaDocRev 74
#define GC_FormaReportDiscountDocCheck 75
#define GC_FormaReportGoodsReport 76
#define GC_FormaGurLog 77
#define GC_FormaSpiskaSprVidKlient 78
#define GC_FormaSpiskaSprVidNom 79
#define GC_FormaSpiskaSprDiscountAuto 80
#define GC_FormaSpiskaSprVidDiscountCard 81
#define GC_FormaSpiskaTableNumberDoc 82
#define GC_FormaSpiskaSprNakSkidok  83
#define GC_FormaGurOperDiscountCard 84
#define GC_FormaSpiskaXSetupObmen 85
#define GC_FormaSpiskaSprImportSet 86
#define GC_FormaDocVipuskProd 87
#define GC_FormaImportDocPrihNakl 88
#define GC_FormaExportDoc 89
#define GC_FormaSpiskaSprScale 90
#define GC_FormaSpiskaSprProject 91
#define GC_FormaDialogaReportPoProject 92
#define GC_FormaSpiskaExtModule 93
#define GC_FormaSpiskaTableExtPrintForm 94
#define GC_FormaDocSborkaKompl 95
#define GC_FormaDocRasborkaKompl 96
#define GC_FormaDocZamena 97
#define GC_FormaDocKorrVs  98
#define GC_FormaDocVipBanka  99
#define GC_FormaSpiskaSprDiscountCard1  101

#define GC_FormaDocRegAdvCust 102
#define GC_FormaDocRegBank 103
#define GC_FormaDocRegGoods 104
#define GC_FormaDocRegOstNom  105
#define GC_FormaDocRegKassa  106
#define GC_FormaDocRegPaySale 107
#define GC_FormaDocRegVsRasch 108
#define GC_FormaDocRegCardBal 109

#define GC_FormaReportOCBCardBalance 110
#define GC_FormaSpiskaSprBrand 111

//¿–Ã Í‡ÒÒË‡
#define GC_FormaARMKas1 112
#define GC_FormaARMKas2 113
#define GC_FormaPriemPlat 114
#define GC_FormaViborSprNom 115
#define GC_FormaViborSprBVNom 116
#define GC_FormaDocRealRoznForCashiers 117
#define GC_FormaDocPKORoznForCashiers 118
#define GC_FormaDocRKORoznForCashiers 119
#define GC_FormaVosvratPokForCashiers 120

#define GC_FormaGurPlat 121
#define GC_FormaGurCheckForCashiers 122
#define GC_FormaGurRoznDocForCashiers 123

#define GC_FormaReportSaleForCashiers 124
#define GC_FormaReportDiscountForCashiers 125

#define GC_FormaPrintPriceForCashiers 126

//„ÓÒÚËÌËˆ‡
#define GC_HOT_FormaDocBron 127
#define GC_HOT_FormaDocOtmenaBron 128
#define GC_HOT_FormaDocRaschet 129
#define GC_HOT_FormaDocRasm 130
#define GC_HOT_FormaDocReal 131
#define GC_HOT_FormaDocViesd 132

#define GC_HOT_GurAllDoc 133

#define GC_HOT_FormaReportDvNomFonda 134
#define GC_HOT_FormaReportRasm 135
#define GC_HOT_FormaReportRasmK_S 136
#define GC_HOT_FormaReportSostNF 137
#define GC_HOT_FormaReportSvobodNF 138

#define GC_HOT_FormaSprCatNom 139
#define GC_HOT_FormaSprCelPriesda 140
#define GC_HOT_FormaSprNF 141
#define GC_HOT_FormaSprObject 142
#define GC_HOT_FormaSprPrOsnUsl 143
#define GC_HOT_FormaSprSostNom 144
#define GC_HOT_FormaSprTypePos 145
#define GC_HOT_FormaTableSostNF 146

#define GC_HOT_FormaKKTOperation 147

#define GC_FormaSpiskaInterfToolBar 148

#define GC_FormaSpiskaObjectBasePriv 149


#define GC_FormaOperCreditCard 150
#define GC_FormaOperPlatCard 151

//ƒÀﬂ œ–»¬≈À≈√»…
#define GCPRIV_DM_SprFirm 1

#define GCPRIV_WEBForm_ReportKartKlient 2
#define GCPRIV_DM_SprGrpKlient 3
#define GCPRIV_DM_SprKlient 4
#define GCPRIV_WEBForm_ARM_1 5
#define GCPRIV_WEBForm_ViborSprNom  6
#define GCPRIV_WEBForm_ViborSprBVNom   7
#define GCPRIV_WEBForm_GurCheckForCashiers  8
#define GCPRIV_WEBForm_ReportSaleForCashiers    9
#define GCPRIV_WEBForm_ReportDiscountForCashiers    10
#define GCPRIV_DM_GurDocCheckKKM2 11
#define GCPRIV_DM_DocCheckKKM 12
#define GCPRIV_WEBForm_DocCheckKKMForCashiers 13
#define GCPRIV_DM_Setup 14
#define GCPRIV_DM_TableNumberDoc 15
#define GCPRIV_DM_GurOperDiscountCard 16
#define GCPRIV_DM_SprDiscountCard 17
#define GCPRIV_DM_SprOborud 18

#define GCPRIV_FormaDocCheck 19
#define GCPRIV_DM_SprTypePrice 20
#define GCPRIV_DM_ExtModule 21
#define GCPRIV_DM_SprPrice 22
#define GCPRIV_DM_SprSklad 23

#define GCPRIV_DM_NoModule 24




//“»œ€ œÓ„‡ÏÏÌ˚ı ÏÓ‰ÛÎÂÈ
#define GC_TypeProgMod_MainModul 1
#define GC_TypeProgMod_Remont 2
#define GC_TypeProgMod_ArmKas 3
#define GC_TypeProgMod_WebArmKas 4
#define GC_TypeProgMod_AdmHotel 5

//“»œ€ œ–»ÀŒ∆≈Õ»…
#define GC_TypeApplication_Ob 1
#define GC_TypeApplication_Web 2

//“»œ€  ¿–“
#define GC_TypeCard_Fiksir 1
#define GC_TypeCard_Nakop 2
#define GC_TypeCard_SpecTypePrice 3
#define GC_TypeCard_SkidkaNom1 4
#define GC_TypeCard_SkidkaNom2 5
#define GC_TypeCard_SkidkaNom3 6


//ÚËÔ˚ ‰ÂÈÒÚ‚ËÈ ‰Îˇ ‡‚ÚÓÏ‡ÚË˜ÂÒÍËı ÒÍË‰ÓÍ
#define GC_DiscountAutoTypeAction_NoAction 0
#define GC_DiscountAutoTypeAction_AddDiscount 1
#define GC_DiscountAutoTypeAction_NoDiscount 2
#define GC_DiscountAutoTypeAction_ShowMessage 3


//“»œ€ œÓ‰ÒËÒÚÂÏ
#define GC_TypeSubSystem_MainModul 1
#define GC_TypeSubSystem_Remont 2
#define GC_TypeSubSystem_AdmHotel 3


        struct TElementSpiskaPrintPrice
				{
				__int64 Id;
				UnicodeString Name;
				__int64 IdEd;
				UnicodeString NameEd;
				bool Grp; //˝ÚÓ „ÛÔÔ‡
				int Kol;// ÓÎË˜ÂÒÚ‚Ó
				};

		struct TElementSpiskaPerObject
				{
				UnicodeString name;
				UnicodeString value;
				};




#define ProgId_DMFibConnection "Oberon.DMFibConnection.1"
#define Global_CLSID_TDMFibConnectionImpl "{E64DC15B-A7FA-4430-A76B-29372F501BDF}"
#define Global_IID_IDMFibConnection "{80391F4A-FA49-40C9-B427-E093A5D14B9A}"





//—Ô‡‚Ó˜ÌËÍ "œÓ„‡ÏÏÌ˚Â ÏÓ‰ÛÎË"
#define ProgId_DMSprProgramModule "Kas.DMSprProgramModule.1"
#define Global_CLSID_TDMSprProgramModuleImpl "F9723891-28E2-488D-975A-87BAFE847629"
#define Global_IID_IDMSprProgramModule "8087AB67-F3E4-42D6-8FCC-8A9E53D4862C"

#define ProgId_FormaElementaSprProgramModule "Kas.FormaElSprProgramModule.1"
#define Global_CLSID_TFormaElementaSprProgramModuleImpl "6D28A670-C069-43A6-ADB7-DC835CBE3A84"
#define Global_IID_IFormaElementaSprProgramModule "5EAA9B03-CAA4-43EE-ACCD-27213D928421"

#define ProgId_FormaSpiskaSprProgramModule "Kas.FormaSpSprProgramModule.1"
#define Global_CLSID_TFormaSpiskaSprProgramModuleImpl "67D29F02-30A2-4057-96C3-E9805DFB4198"
#define Global_IID_IFormaSpiskaSprProgramModule  "06006FA9-B4C9-4C46-ADAD-D32B94C34ACD"


//—Ô‡‚Ó˜ÌËÍ »ÌÚÂÙÂÈÒ: √Î‡‚ÌÓÂ ÏÂÌ˛
#define ProgId_DMInterfMainMenu "Oberon.DMInterfMainMenu.1"
#define Global_CLSID_TDMInterfMainMenuImpl "41C82E9E-D5B3-4181-8498-9D13564A8316"
#define Global_IID_IDMInterfMainMenu "59857341-AC0D-4B52-98BF-7C979810D578"

#define ProgId_FormaSpiskaInterfMainMenu "Oberon.FormaSpiskaInterfMainMenu.1"
#define Global_CLSID_TFormaSpiskaInterfMainMenuImpl "{36EFFB12-61BB-4CBB-8D20-33068A39DC6F}"
#define Global_IID_IFormaSpiskaInterfMainMenu  "{95ABFB34-13D4-4F96-BC73-B0AE77734EF9}"

//—Ô‡‚Ó˜ÌËÍ »ÌÚÂÙÂÈÒ: √ÛÔÔ˚ „Î‡‚ÌÓÂ ÏÂÌ˛
#define ProgId_DMInterfMainMenuGrp "Oberon.DMInterfMainMenuGrp.1"
#define Global_CLSID_TDMInterfMainMenuGrpImpl "C0ADAA47-C171-4FF7-B954-4890D8007BC9"
#define Global_IID_IDMInterfMainMenuGrp "9B0E11BA-0747-4784-AD96-06AF0EDF3464"

#define ProgId_FormaElementaInterfMainMenuGrp "Oberon.FormaElInterfMainMenuGrp.1"
#define Global_CLSID_TFormaElementaInterfMainMenuGrpImpl "{5D1990FF-6078-429D-84AD-6666759DAE53}"
#define Global_IID_IFormaElementaInterfMainMenuGrp "{F128740B-0AA3-412D-B52E-09A373CD5E3F}"


//¬ÌÂ¯ÌËÂ ÏÓ‰ÛÎË
#define ProgId_DMTableExtPrintForm  "Oberon.DMTableExtPrintForm.1"
#define Global_CLSID_TDMTableExtPrintFormImpl   "{F4A20E9E-1887-4032-A1DC-1EDA6199EFA9}"
#define Global_IID_IDMTableExtPrintForm "{DFAC6A70-977A-4B36-B5A5-4F07537CF90D}"


#define ProgId_FormaSpiskaTableExtPrintForm "Oberon.FormaSpiskaTableExtPrintForm.1"
#define Global_CLSID_TFormaSpiskaTableExtPrintFormImpl "{2B8E35A2-6B59-44D6-B255-51EB3D7149BD}"
#define Global_IID_IFormaSpiskaTableExtPrintForm "{91B9110B-4710-4A84-B36F-A40D9100F694}"

#define ProgId_FormaSpiskaExtModule  "Oberon.FormaSpiskaExtModule.1"
#define Global_CLSID_TFormaSpiskaExtModuleImpl "{FF9BB91D-C77B-467F-9CEA-0ED52E36F06C}"
#define Global_IID_IFormaSpiskaExtModule "{49125090-3F0E-4E7A-B45E-4ADD5A7C9F9B}"

//—Ô‡‚Ó˜ÌËÍ »ÌÚÂÙÂÈÒ: Ô‡ÌÂÎ¸ ÍÌÓÔÓÍ
#define ProgId_DMInterfToolBar "Oberon.DMInterfToolBar.1"
#define Global_CLSID_TDMInterfToolBarImpl   "911723E2-6B8D-44DF-A28B-3A16C8623F54"
#define Global_IID_IDMInterfToolBar "1F607385-3126-41FE-8617-51B2C23561F1"


//œË‚ÂÎÂ„ËË Ì‡ Ó·˙ÂÍÚ˚ ·‡Á˚/ÔÓ„‡ÏÏ˚
#define ProgId_FormaSpiskaObjectBasePriv "Oberon.FormaSpiskaObjectBasePriv.1"
#define Global_CLSID_TFormaSpiskaObjectBasePrivImpl "{72C6C2F8-8C4A-40C0-9DA0-02DEF458DB5D}"
#define Global_IID_IFormaSpiskaObjectBasePriv "{E32898CF-592D-44F5-B560-40CB5DFE0B7F}"


#define ProgId_DMObjectBaseGrp "Oberon.DMObjectBaseGrp.1"
#define Global_CLSID_TDMObjectBaseGrpImpl "{4AD5B95A-9181-43FC-9C24-5BE36B97D4CB}"
#define Global_IID_IDMObjectBaseGrp  "{4292B6DD-1506-4F96-8E94-5D08C460C920}"


#define ProgId_DMObjectBasePriv   "Oberon.DMObjectBasePriv.1"
#define Global_CLSID_TDMObjectBasePrivImpl "{D1B2FC5A-8F39-45D1-BF2F-D88F9146F853}"
#define Global_IID_IDMObjectBasePriv "{B0982DB0-0D64-49DD-BA24-C2227697DA12}"



//—œ–¿¬Œ◊Õ»  ¡»«Õ≈— Œœ≈–¿÷»»
#define ProgId_DMSprGrpBusinessOper  "Kas.DMSprGrpBusinessOper.1"
#define Global_CLSID_TDMSprGrpBusinessOperImpl "{83046BE2-23C0-4F1C-8C1C-9EB75D1C7B81}"
#define Global_IID_IDMSprGrpBusinessOper "{62AD3FD6-D0BF-43E1-BF26-55DB0FD8BD16}"

#define ProgId_DMSprBusinessOper  "Kas.DMSprBusinessOper.1"
#define Global_CLSID_TDMSprBusinessOperImpl "{C0C93F0E-1347-4A5E-BD13-229D3BB0C026}"
#define Global_IID_IDMSprBusinessOper "{D962D2E5-76ED-4163-8D9A-A84807E23772}"

#define ProgId_FormaElementaSprGrpBusinessOper  "Kas.FormaElementaSprGrpBusinessOper.1"
#define Global_CLSID_TFormaElementaSprGrpBusinessOperImpl "{53E81AB8-CA43-4B3D-B207-E21EC7C6FCDF}"
#define Global_IID_IFormaElementaSprGrpBusinessOper "{F8D27896-3BC8-43DD-B160-CECBE9D2231A}"

#define ProgId_FormaElementaSprBusinessOper  "Kas.FormaElementaSprBusinessOper.1"
#define Global_CLSID_TFormaElementaSprBusinessOperImpl  "{6F6E33F1-23EB-4798-8EEC-A64560D4B4A5}"
#define Global_IID_IFormaElementaSprBusinessOper "{4ACCCA18-A897-4A7B-A414-16E645FDB827}"

#define ProgId_FormaSpiskaSprBusinessOper  "Kas.FormaSpiskaSprBusinessOper.1"
#define Global_CLSID_TFormaSpiskaSprBusinessOperImpl "{7125E25E-4DD1-4032-B7EF-535AA07AD258}"
#define Global_IID_IFormaSpiskaSprBusinessOper "{48CF1BAE-242A-4035-B9B5-7379C8A182E2}"




#define ProgId_DMSprBankSchet  "Oberon.DMSprBankSchet.1"
#define Global_CLSID_TDMSprBankSchetImpl "{78898816-1D6E-430D-BA6B-3CFC1B62E376}"
#define Global_IID_IDMSprBankSchet "{C69D7754-FC16-4DB3-8428-70D582C8F060}"

#define ProgId_FormaSpiskaSprBankSchet  "Oberon.FormaSpiskaSprBankSchet.1"
#define Global_CLSID_TFormaSpiskaSprBankSchetImpl "{3B1BF17B-AF3B-4713-9D1C-10D5BEE2FE4D}"
#define Global_IID_IFormaSpiskaSprBankSchet "{35AE1B47-550E-484B-9F60-0FF3403842BE}"





#define ProgId_FormaSpiskaSprUser  "Oberon.FormaSpiskaSprUser.1"
#define Global_CLSID_TFormaSpiskaSprUserImpl  "{8D39C5C4-4359-4D0C-A2DA-95570BC6922F}"
#define Global_IID_IFormaSpiskaSprUser  "{D2FD1538-A080-4136-A309-2E57B5F55792}"


#define ProgId_FormaElementaSprUser  "Oberon.FormaElementaSprUser.1"
#define Global_CLSID_TFormaElementaSprUserImpl "{3518BDC5-6CB6-4836-8622-8048AAA6C769}"
#define Global_IID_IFormaElementaSprUser "{F5B586F6-82B7-4DFA-BF0F-807E64C23CCF}"



#define ProgId_DMSprUser  "Oberon.DMSprUser.1"
#define Global_CLSID_TDMSprUserImpl  "{27D83FBD-DD8A-4049-9D10-C04FA1F70E5F}"
#define Global_IID_IDMSprUser "{AD7E1FAB-D578-4FAD-8F86-D0D6B7A20C41}"


#define ProgId_REM_FormaSpiskaSprNeispr  "Oberon.REM_FormaSpSprNeispr.1"
#define Global_CLSID_TREM_FormaSpiskaSprNeisprImpl  "{845759BA-00D7-45D0-A431-C76F6C18AE2E}"
#define Global_IID_IREM_FormaSpiskaSprNeispr  "{53870596-39E4-4CF0-8FB6-23761FA13244}"


#define ProgId_REM_FormaElementaSprNeispr  "Oberon.REM_FormaElSprNeispr.1"
#define Global_CLSID_TREM_FormaElementaSprNeisprImpl "{61763F3C-0B9C-4A41-81BB-BEE5A5206DA9}"
#define Global_IID_IREM_FormaElementaSprNeispr "{6E74AD38-7A6F-4DF8-B8BA-9B19E6F12884}"


#define ProgId_REM_FormaElementaSprGrpNeispr  "Oberon.REM_FormaElGrpSprNeispr.1"
#define Global_CLSID_TREM_FormaElementaSprGrpNeisprImpl "{F64734AD-6C0F-4E14-ABDA-25065F00FD9C}"
#define Global_IID_IREM_FormaElementaSprGrpNeispr "{A1AF757E-FD0C-443A-9715-09E8261CEBEB}"



#define ProgId_REM_DMSprNeispr  "Oberon.REM_DMSprNeispr.1"
#define Global_CLSID_TREM_DMSprNeisprImpl "{7FDD9326-8155-4F2D-BC8E-6CE5FCE44157}"
#define Global_IID_IREM_DMSprNeispr "{29ED0E11-DFE4-4909-9390-233B6E31984D}"


#define ProgId_REM_DMSprGrpNeispr  "Oberon.REM_DMGrpSprNeispr.1"
#define Global_CLSID_TREM_DMSprGrpNeisprImpl "{9F589B61-ECD5-476F-9F0A-62F13C796D81}"
#define Global_IID_IREM_DMSprGrpNeispr "{B5D8F4E9-21E3-4C87-BE8F-1CC55979E6F6}"




#define ProgId_REM_FormaSpiskaSprModel  "Oberon.REM_FormaSpSprModel.1"
#define Global_CLSID_TREM_FormaSpiskaSprModelImpl "{DC927A56-FF35-4E40-B396-7FD4D532E215}"
#define Global_IID_IREM_FormaSpiskaSprModel     "{5EE481D9-2AA5-4C4D-9BCB-4A7CBF4BDC8B}"

#define ProgId_REM_DMSprGrpModel  "Oberon.REM_DMSprGrpModel.1"
#define Global_CLSID_TREM_DMSprGrpModelImpl "{111497AA-F4ED-4877-A1C7-DD4163DD4281}"
#define Global_IID_IREM_DMSprGrpModel "{1D956242-3957-4B4B-8A22-4FE694E0411A}"

#define ProgId_REM_DMSprModel  "Oberon.REM_DMSprModel.1"
#define Global_CLSID_TREM_DMSprModelImpl "{5E9A1C7E-2863-49A7-B6E0-DD0D4EAB8E34}"
#define Global_IID_IREM_DMSprModel "{F258C85F-75EC-4865-88B6-7274ABDBE861}"


#define ProgId_REM_FormaSpiskaSprTypeRemont  "Oberon.REM_FormaSpSprTypeRemont.1"
#define Global_CLSID_TREM_FormaSpiskaSprTypeRemontImpl  "{58CB1609-CEBB-48B5-B91A-0F7226014E1A}"
#define Global_IID_IREM_FormaSpiskaSprTypeRemont   "{D5E8EAB9-7D7A-454A-91AE-1CFEC87164A6}"

#define ProgId_REM_FormaSpiskaSprSost  "Oberon.REM_FormaSpSprSost.1"
#define Global_CLSID_TREM_FormaSpiskaSprSostImpl   "{962B6F79-AC97-4F4D-BD08-FAE0B279DC7F}"
#define Global_IID_IREM_FormaSpiskaSprSost    "{5EA90C93-DAE3-421F-ABC3-D8881F7C94AF}"

#define ProgId_REM_FormaGurZ    "Oberon.REM_FormaGurZ.1"
#define Global_CLSID_TREM_FormaGurZImpl  "{B20A2E1F-DED7-4F4C-B857-D768F3ECC6E1}"
#define Global_IID_IREM_FormaGurZ  "{CDADE51A-3D6E-4956-9951-5CC1037A2E6C}"

#define ProgId_REM_DMGurZ "Oberon.REM_DMGurZ.1"
#define Global_CLSID_TREM_DMGurZImpl  "{8190A783-D5DA-4249-9F3D-E8FE02AE6313}"
#define Global_IID_IREM_DMGurZ  "{FFD87EFA-7D7C-453D-8442-532E4DBB31AE}"


#define ProgId_REM_FormaGurZDop    "Kas.REM_FormaGurZDop.1"
#define Global_CLSID_TREM_FormaGurZDopImpl "{044737F7-1BF5-49DC-97E1-1326F2B0580A}"
#define Global_IID_IREM_FormaGurZDop "{D111A56C-A172-43D2-82C2-E2DD0642BFC1}"




#define ProgId_REM_FormaZayavka "Oberon.REM_FormaZayavka.1"
#define Global_CLSID_TREM_FormaZayavkaImpl "{0042B50C-A941-46F1-B9C5-ED3BCA0DEE30}"
#define Global_IID_IREM_FormaZayavka "{22AF3018-452B-47E4-B0B5-0F2904BEB1CD}"

#define ProgId_REM_DMZayavka "Oberon.REM_DMZayavka.1"
#define Global_CLSID_TREM_DMZayavkaImpl "{6F4CE37C-8A82-4A3B-A64E-6693CC80832A}"
#define Global_IID_IREM_DMZayavka "{0E1586CA-8CAD-4AD7-9DDD-D131048CF614}"

//---------------------
#define ProgId_REM_DMZayavkaDv "Oberon.REM_DMZayavkaDv.1"
#define Global_CLSID_TREM_DMZayavkaDvImpl "{A622D85C-23C0-4B39-AC10-CF71B520697D}"
#define Global_IID_IREM_DMZayavkaDv "{07871069-1617-49E8-8B02-309EDF27C924}"
//--------------------------------------------

#define ProgId_REM_FormaGurAllDoc    "Oberon.REM_FormaGurAllDoc.1"
#define Global_CLSID_TREM_FormaGurAllDocImpl  "{73D601A0-E278-48E5-9382-73B3C98FA393}"
#define Global_IID_IREM_FormaGurAllDoc  "{9B7B0B6F-85DF-4918-B166-1DFCBC4C0CBC}"

#define ProgId_REM_DMGurAllDoc "Oberon.REM_DMGurAllDoc.1"
#define Global_CLSID_TREM_DMGurAllDocImpl "{55C00FE6-F56C-4BF0-845C-481222A2EE5E}"
#define Global_IID_IREM_DMGurAllDoc "{FFB30E09-A30D-4C03-A3D1-03F68A8BD6A7}"


#define ProgId_REM_FormaDocRemont  "Oberon.REM_FormaDocRemont.1"
#define Global_CLSID_TREM_FormaDocRemontImpl "{41CCEF73-8053-4BD0-8BE8-70F0A9420E43}"
#define Global_IID_IREM_FormaDocRemont "{8F0F66CD-5184-4333-90B4-EEEA99A2C60F}"

#define ProgId_REM_DMDocRemont "Oberon.REM_DMDocRemont.1"
#define Global_CLSID_TREM_DMDocRemontImpl "{F96D69DC-CE8F-4DCB-9FB1-8551A7203800}"
#define Global_IID_IREM_DMDocRemont "{0982CA6F-4C31-4964-8BF6-62FC848D703C}"


#define ProgId_REM_FormaDocRemontHW "Oberon.REM_FormaDocRemontHW.1"
#define Global_CLSID_TREM_FormaDocRemontHWImpl "{DA32F5F4-885B-44AD-989E-AFDA3BDF1FC1}"
#define Global_IID_IREM_FormaDocRemontHW  "{22D95321-70FC-46B3-B15F-BB197CB0AA5B}"

#define ProgId_REM_DMDocRemontHW "Oberon.REM_DMDocRemontHW.1"
#define Global_CLSID_TREM_DMDocRemontHWImpl "{031470EB-2DA5-4A3B-8FBE-803DEF7C8BD4}"
#define Global_IID_IREM_DMDocRemontHW "{07175EEB-E22B-4504-9931-13CB67E5FF15}"


#define ProgId_REM_FormaSpiskaSprKKT "Oberon.REM_FormaSpSprKKT.1"
#define Global_CLSID_TREM_FormaSpiskaSprKKTImpl  "{ACC9E6E6-CB43-4CAB-B096-742DCB9289B8}"
#define Global_IID_IREM_FormaSpiskaSprKKT "{84B40935-55F6-409A-A167-B0EE5177DBD4}"

#define ProgId_REM_FormaDocRemontKKT  "Oberon.REM_FormaDocRemontKKT.1"
#define Global_CLSID_TREM_FormaDocRemontKKTImpl "{567454D3-E78F-425E-8E2B-94B38AF4C13F}"
#define Global_IID_IREM_FormaDocRemontKKT "{6BC289C3-128C-476F-BEA2-588A77BA3C7C}"

#define ProgId_REM_FormaDocKM1 "Oberon.REM_FormaDocKM1.1"
#define Global_CLSID_TREM_FormaDocKM1Impl "{E551BC5E-FE6D-4760-BBB9-C9679D7A86AD}"
#define Global_IID_IREM_FormaDocKM1 "{6544D37D-5CF9-4838-8E64-887C5C75E6AA}"

#define ProgId_REM_FormaDocKM2   "Oberon.REM_FormaDocKM2.1"
#define Global_CLSID_TREM_FormaDocKM2Impl "{D443EE74-C75E-4604-9A21-79B0FBCCB56E}"
#define Global_IID_IREM_FormaDocKM2  "{2A218207-6CCC-4E47-BC3C-67015BA3A268}"

#define ProgId_REM_FormaDocSetServKKT  "Oberon.REM_FormaDocSetServKKT.1"
#define Global_CLSID_TREM_FormaDocSetServKKTImpl  "{67DA09A1-A025-4603-9D23-EEAB263A0AFF}"
#define Global_IID_IREM_FormaDocSetServKKT  "{E0CF0B14-96BD-4B69-A63E-B1ECD5826CBA}"

#define ProgId_REM_FormaDocSetServHW  "Oberon.REM_FormaDocSetServHW.1"
#define Global_CLSID_TREM_FormaDocSetServHWImpl "{D6F78D4A-AEAD-4041-9415-D18704C79FD3}"
#define Global_IID_IREM_FormaDocSetServHW "{55DC39FE-1A74-4D40-8627-80991DD653CA}"



#define ProgId_REM_FormaSpiskaSprHardware  "Oberon.REM_FormaSpSprHardware.1"
#define Global_CLSID_TREM_FormaSpiskaSprHardwareImpl  "{C3C25263-A4E7-440B-A88F-4BAD314C7D88}"
#define Global_IID_IREM_FormaSpiskaSprHardware "{0C6BD958-4547-42FF-BA02-6C7ABEF0AE6E}"

#define ProgId_REM_FormaElementaSprHardware  "Oberon.REM_FormaElSprHardware.1"
#define Global_CLSID_TREM_FormaElementaSprHardwareImpl "{F668A8F5-3E3F-448B-ACC8-FC6BB87335B8}"
#define Global_IID_IREM_FormaElementaSprHardware "{803D6505-6040-4CBE-BE42-B19EC6C80180}"

#define ProgId_REM_DMSprHardware  "Oberon.REM_DMSprHardware.1"
#define Global_CLSID_TREM_DMSprHardwareImpl "{D0B4A267-F833-4892-95CA-14BD6F9D2222}"
#define Global_IID_IREM_DMSprHardware "{3298EA19-2B26-4520-9C25-F2264D8F1877}"







#define ProgId_REM_DMSprHardwareIsp  "Kas.REM_DMSprHardwareIsp.1"
#define Global_CLSID_TREM_DMSprHardwareIspImpl "{FFC4A737-551C-4E60-85EE-45D57750E789}"
#define Global_IID_IREM_DMSprHardwareIsp "{668D0FBE-3C50-4842-AE5A-470FCE546C99}"

#define ProgId_REM_FormaSpiskaSprHardwareIsp  "Kas.REM_FormaSpSprHardwareIsp.1"
#define Global_CLSID_TREM_FormaSpiskaSprHardwareIspImpl "{916D5463-4AB2-4149-91F4-5B7CE04F7034}"
#define Global_IID_IREM_FormaSpiskaSprHardwareIsp "{E3F76149-EF26-4FBF-A2E3-961A2DFF4EA5}"

#define ProgId_REM_FormaElementaSprHardwareIsp  "Kas.REM_FormaElSprHardwareIsp.1"
#define Global_CLSID_TREM_FormaElementaSprHardwareIspImpl "{E792A646-3BC0-4173-953D-01DCA327C1D6}"
#define Global_IID_IREM_FormaElementaSprHardwareIsp "{9ECFC6B3-5D23-439B-BBEB-A801E1A510E5}"





#define ProgId_FormaSpiskaSprFirm  "Oberon.FormaSpiskaSprFirm.1"
#define Global_CLSID_TFormaSpiskaSprFirmImpl "{AF42D961-9A70-4D9D-8A71-416CC6A20627}"
#define Global_IID_IFormaSpiskaSprFirm "{FEC34AD2-C80E-48F8-9F10-A94B9F064DA1}"

#define ProgId_DMSprFirm  "Oberon.DMSprFirm.1"
#define Global_CLSID_TDMSprFirmImpl "{9C2A5FB1-B855-4E41-9623-A66EDF14A28F}"
#define Global_IID_IDMSprFirm "{27133826-BB0B-4D4C-8E69-9C4C580E3277}"



#define ProgId_FormaSpiskaSprSklad "Oberon.FormaElementaSprSklad.1"
#define Global_CLSID_TFormaSpiskaSprSkladImpl "{0EDA1B30-C4B1-4743-B43C-8024640FE075}"
#define Global_IID_IFormaSpiskaSprSklad "{77BA6EDB-46BB-464E-BF43-F6CEB26E4D61}"

#define ProgId_DMSprSklad "Oberon.DMSprSklad.1"
#define Global_CLSID_TDMSprSkladImpl  "{F8E14A2C-2A1A-453A-B80B-FFB55D12FE6A}"
#define Global_IID_IDMSprSklad "{2C5B2108-DAE8-4C19-B395-D642C6C23BF2}"


#define ProgId_FormaSpiskaSprKKM  "Oberon.FormaSpiskaSprKKM.1"
#define Global_CLSID_TFormaSpiskaSprKKMImpl "{CF56C07D-9408-4E1E-ACB5-A1B51F7F5E59}"
#define Global_IID_IFormaSpiskaSprKKM "{5475D494-4173-44E2-A70F-01154B2BFE35}"


#define ProgId_DMSprKKM  "Oberon.DMSprKKM.1"
#define Global_CLSID_TDMSprKKMImpl "{32239EEB-2567-42D7-BD3D-1E104C93C3D3}"
#define Global_IID_IDMSprKKM "{A1E670FB-5995-4D83-968C-45EB324149EB}"


#define ProgId_FormaSpiskaSprKlient   "Oberon.FormaSpiskaSprKlient.1"
#define Global_CLSID_TFormaSpiskaSprKlientImpl "{FE7E446C-2C46-4B2C-8583-58DB32AC234F}"
#define Global_IID_IFormaSpiskaSprKlient "{AE67C487-8DFA-44C5-993D-AD8346E334F3}"


#define ProgId_FormaElementaSprKlient   "Oberon.FormaElementaSprKlient.1"
#define Global_CLSID_TFormaElementaSprKlientImpl "{A419FD6B-535B-4D4D-A8F9-7969F4B429D7}"
#define Global_IID_IFormaElementaSprKlient "{C01D7B72-E8B5-40CC-BA69-5838FB153E4C}"

#define ProgId_DMSprKlient   "Oberon.DMSprKlient.1"
#define Global_CLSID_TDMSprKlientImpl "{5F0A1609-9B0C-4F29-8679-B22CB7D981EE}"
#define Global_IID_IDMSprKlient "{1A5F2AC4-0BB3-4854-A678-818CF5EB7FF1}"




#define ProgId_FormaSpiskaSprNom "Oberon.FormaSpiskaSprNom.1"
#define Global_CLSID_TFormaSpiskaSprNomImpl "{44A0D565-0051-4DD0-A981-2D0C4544763B}"
#define Global_IID_IFormaSpiskaSprNom "{47717387-98AD-473D-8E25-17BCA57274D5}"


#define ProgId_DMSprNomFind "Kas.DMSprNomFind.1"
#define Global_CLSID_TDMSprNomFindImpl "{586FE084-D9E5-475C-8D61-0AA3FAA10234}"
#define Global_IID_IDMSprNomFind "{583E5A99-A4AB-44E0-B28B-71B4BE9C7385}"

#define ProgId_FormaSprNomFind "Kas.FormaSprNomFind.1"
#define Global_CLSID_TFormaSprNomFindImpl "{2A0CDC43-92D0-46E7-AC31-32985566C212}"
#define Global_IID_IFormaSprNomFind "{6A9DAE66-7724-437A-9BD7-D8CF55B51C60}"

#define ProgId_DMSprNom "Oberon.DMSprNom.1"
#define Global_CLSID_TDMSprNomImpl "{85692269-A978-43EE-9990-395080DBA989}"
#define Global_IID_IDMSprNom "{B17C061E-52AB-4C1B-B54C-C6080A6EB0C7}"

#define ProgId_DMSprGrpNom "Oberon.DMSprGrpNom.1"
#define Global_CLSID_TDMSprGrpNomImpl "{FEE44601-CD22-4E68-AE58-BD111924F8F1}"
#define Global_IID_IDMSprGrpNom "{460BEF8E-370F-492D-8A46-D2DE19E4B3EA}"


#define ProgId_FormaGurAllDoc "Oberon.FormaGurAllDoc.1"
#define Global_CLSID_TFormaGurAllDocImpl  "{31FC8663-D7FC-4323-8EC9-EF8A78ED264A}"
#define Global_IID_IFormaGurAllDoc "{9BE14E58-4D17-4664-9E45-71CFEAE5D531}"

#define ProgId_DMGurAllDoc "Oberon.DMGurAllDoc.1"
#define Global_CLSID_TDMGurAllDocImpl  "{471309CD-AF29-4BAE-ADA2-50B0740DF951}"
#define Global_IID_IDMGurAllDoc "{5B7891AE-775A-4CCE-A4C6-1793FC9E7B92}"

//ƒŒ ”Ã≈Õ“ œ–»’ŒƒÕ¿ﬂ Õ¿ À¿ƒÕ¿ﬂ
#define ProgId_FormaDocPrihNakl  "Oberon.FormaDocPrihNakl.1"
#define Global_CLSID_TFormaDocPrihNaklImpl "{A0DF1507-D933-4A14-8411-4A0E605BA54A}"
#define Global_IID_IFormaDocPrihNakl "{A4B51D84-CF62-49A1-AA63-0623F6524151}"

#define ProgId_DMDocPrihNakl "Oberon.DMDocPrihNakl.1"
#define Global_CLSID_TDMDocPrihNaklImpl "{1B7C9FA4-8C80-4E6E-99C7-0593103578FB}"
#define Global_IID_IDMDocPrihNakl "{3B154FBB-FDE6-4D68-BFFD-F927313BB2BD}"


//‰ÓÍÛÏÂÌÚ ◊ÂÍ   Ã
#define ProgId_FormaDocCheck "Oberon.FormaDocCheck.1"
#define Global_CLSID_TFormaDocCheckImpl  "{922FEA06-CF74-45E7-B3F2-ACCA0A506504}"
#define Global_IID_IFormaDocCheck "{421DBE75-13E8-41E9-AB64-8F059259FC5E}"

#define ProgId_DMDocCheck "Oberon.DMDocCheck.1"
#define Global_CLSID_TDMDocCheckImpl "{25A6DC01-003D-49EC-9D97-77053441A7D1}"
#define Global_IID_IDMDocCheck  "{5C427322-86CA-4C36-9D5C-C0C9481ABD0B}"


//ƒŒ ”Ã≈Õ —◊≈“
#define ProgId_FormaDocSchet "Oberon.FormaDocSchet.1"
#define Global_CLSID_TFormaDocSchetImpl "{57CAC008-A2F6-403F-803F-8345DE2F3EAB}"
#define Global_IID_IFormaDocSchet "{F9F01ADE-8EA4-4C27-9849-0A3DE93DD79A}"

#define ProgId_DMDocSchet  "Oberon.DMDocSchet.1"
#define Global_CLSID_TDMDocSchetImpl  "{C03C12AE-2AA6-4A18-AE76-C9FC6EF25543}"
#define Global_IID_IDMDocSchet "{293795AE-0395-4E8E-824A-AE2C6F1B3F41}"



//ƒŒ ”Ã≈Õ“ Œ—“¿“ » ÕŒÃ≈ À¿“”–€
#define ProgId_FormaDocOstNom "Oberon.FormaDocOstNom.1"
#define Global_CLSID_TFormaDocOstNomImpl  "{D60906D0-FAFF-4136-93A6-586D75BB2EC4}"
#define Global_IID_IFormaDocOstNom "{F840D2FF-F140-4654-A09D-B78178A3F66B}"

#define ProgId_DMDocOstNom "Oberon.DMDocOstNom.1"
#define Global_CLSID_TDMDocOstNomImpl "{8813DFEC-008C-4F1D-8AFC-7B2E6BE2B456}"
#define Global_IID_IDMDocOstNom  "{8300CEE1-49B1-4AB1-8C3A-67D1007190EA}"






//ƒŒ ”Ã≈Õ“ œ≈–≈Ã≈Ÿ≈Õ»≈
#define ProgId_FormaDocPer "Oberon.FormaDocPer.1"
#define Global_CLSID_TFormaDocPerImpl "{D09A0549-4F36-4C98-8003-B0E92AB0AE1D}"
#define Global_IID_IFormaDocPer "{6B3D5938-8177-48F7-8488-535228DEF176}"

#define ProgId_DMDocPer "Oberon.DMDocPer.1"
#define Global_CLSID_TDMDocPerImpl "{AC35AEDE-9F04-4557-8E03-9641E6BA9EAC}"
#define Global_IID_IDMDocPer "{4BCCB733-D17B-408D-8715-EF1EECC801B7}"




//ƒŒ ”Ã≈Õ“ –≈¿À»«¿÷»ﬂ
#define ProgId_FormaDocReal "Oberon.FormaDocReal.1"
#define Global_CLSID_TFormaDocRealImpl   "{97ED344A-6745-493F-8E67-F912D014732D}"
#define Global_IID_IFormaDocReal "{CEEC5FFD-B7A9-4F27-9AB5-605D11771540}"

#define ProgId_DMDocReal "Oberon.DMDocReal.1"
#define Global_CLSID_TDMDocRealImpl "{3FA8B90B-270C-4CA9-8E74-36A83FBE9670}"
#define Global_IID_IDMDocReal "{304E8408-7C7D-412C-AF16-8DB2DD210E65}"


//—œ»—¿Õ»≈ ÕŒÃ≈Õ À¿“”–€
#define ProgId_FormaDocSpisNom "Oberon.FormaDocSpisNom.1"
#define Global_CLSID_TFormaDocSpisNomImpl "{4815091B-33ED-43A0-8EC1-E00409939F9D}"
#define Global_IID_IFormaDocSpisNom "{BEF0FCB4-45D7-41F9-9093-CD347CBEF3CE}"

#define ProgId_DMDocSpisNom "Oberon.DMDocSpisNom.1"
#define Global_CLSID_TDMDocSpisNomImpl "{89B4C2E5-F1FB-4125-AC39-3218C364CD9C}"
#define Global_IID_IDMDocSpisNom "{699A47DE-E8E0-4658-A97F-E5C94ED2352E}"


//¬Œ«¬–¿“ œŒ—“¿¬Ÿ» ”
#define ProgId_FormaDocVosvratPost  "Oberon.FormaDocVosvratPost.1"
#define Global_CLSID_TFormaDocVosvratPostImpl "{17A2C93E-D16F-4908-B82D-E3ED24588CD9}"
#define Global_IID_IFormaDocVosvratPost "{CB269849-118E-4F12-A3F0-ADA377712C6B}"

#define ProgId_DMDocVosvratPost "Oberon.DMDocVosvratPost.1"
#define Global_CLSID_TDMDocVosvratPostImpl  "{085ACDFF-48FC-4CD2-BC5F-DF1BD8B87F20}"
#define Global_IID_IDMDocVosvratPost  "{9DCEF3D6-CC7A-4C65-8634-D434BFC2C1A3}"



//ƒŒ ”Ã≈Õ“ œ Œ
#define ProgId_FormaDocPKO  "Oberon.FormaDocPKO.1"
#define Global_CLSID_TFormaDocPKOImpl "{9150941D-0601-4FE3-BA7B-1D97E868131B}"
#define Global_IID_IFormaDocPKO "{6BF51B11-76E4-48B6-B225-8B600556A15A}"

#define ProgId_DMDocPKO "Oberon.DMDocPKO.1"
#define Global_CLSID_TDMDocPKOImpl "{BDD55B32-A37F-41B6-A679-4764E488C4EB}"
#define Global_IID_IDMDocPKO "{606B4AB0-9738-4D89-9400-BCEE4A9135F2}"



//–¿—’ŒƒÕ€…  ¿——Œ¬€… Œ–ƒ≈–
#define ProgId_FormaDocRKO "Oberon.FormaDocRKO.1"
#define Global_CLSID_TFormaDocRKOImpl "{E3D0E9C9-1526-49FC-A383-9136CCA7F593}"
#define Global_IID_IFormaDocRKO  "{FF52A248-A20D-457F-B37D-CA9C45CC38FA}"

#define ProgId_DMDocRKO "Oberon.DMDocRKO.1"
#define Global_CLSID_TDMDocRKOImpl  "{98D8B01A-8FBC-4A0E-B9C0-D465943F48B4}"
#define Global_IID_IDMDocRKO "{8D3AC761-5445-488E-BCC9-718ACA0D474C}"




//œÀ¿“≈∆ÕŒ≈ œŒ–”◊≈Õ»≈
#define ProgId_FormaDocPlatPor "Oberon.FormaDocPlatPor.1"
#define Global_CLSID_TFormaDocPlatPorImpl "{859775DB-E3B5-4763-A76A-68DC708365F7}"
#define Global_IID_IFormaDocPlatPor "{32D561F0-9BDD-44B3-9A40-3A9C202EAF43}"

#define ProgId_DMDocPlP "Oberon.DMDocPLP.1"
#define Global_CLSID_TDMDocPlPImpl "{4C8F9421-687E-45D0-833A-450DE080C30F}"
#define Global_IID_IDMDocPlP "{41C13E35-93D9-453B-9581-F9E973DA85D7}"


//œŒ—“”œÀ≈Õ»≈ Õ¿ —◊≈“
#define ProgId_FormaDocPostNaSchet "Oberon.FormaDocPostNaSchet.1"
#define Global_CLSID_TFormaDocPostNaSchetImpl  "{BFA65ACF-ED7A-4BBB-8BBC-D68250BFC92E}"
#define Global_IID_IFormaDocPostNaSchet "{44D76D07-2FD1-40B3-AC85-D27BDCCBAFF4}"

#define ProgId_DMDocPostNaSchet "Oberon.DMDocPostNaSchet.1"
#define Global_CLSID_TDMDocPostNaSchetImpl "{042D4BDF-BA6B-4C7A-A25B-4C30DC59FE1A}"
#define Global_IID_IDMDocPostNaSchet "{B553CC39-9D8C-4474-8FC6-F955EBCEB86B}"






 //—◊≈“_‘¿ “”–¿
#define ProgId_FormaDocSchetFact "Oberon.FormaDocSchetFact.1"
#define Global_CLSID_TFormaDocSchetFactImpl  "{9B73309B-6F3E-4D37-AC89-C85C1E29DC11}"
#define Global_IID_IFormaDocSchetFact "{7D5E6A5A-B77E-4B4F-95DA-94781796BB5C}"

#define ProgId_DMDocSchetFact  "Oberon.DMDocSchetFact.1"
#define Global_CLSID_TDMDocSchetFactImpl   "{16421833-89F0-4EA0-BBBF-3FC9E669A8B6}"
#define Global_IID_IDMDocSchetFact "{92569D35-305D-4F61-BAA8-7DFD05E2A496}"




#define ProgId_FormaSpiskaSprPodr "Oberon.FormaSpiskaSprPodr.1"
#define Global_CLSID_TFormaSpiskaSprPodrImpl "{577ED7D8-919B-4AAB-8A7E-AD37FE4C7573}"
#define Global_IID_IFormaSpiskaSprPodr "{93E32B80-2001-4E8C-9553-1A558082E118}"

#define ProgId_FormaSpiskaSprBVNom "Oberon.FormaSpiskaSprBVNom.1"
#define Global_CLSID_TFormaSpiskaSprBVNomImpl  "{B78A9460-44D3-4B03-BF25-374EB7B08E3D}"
#define Global_IID_IFormaSpiskaSprBVNom "{B68F6AC7-7B4C-48C9-B87E-0848F107A034}"

#define ProgId_FormaSpiskaSprStrObject "Oberon.FormaElementaSprStrObject.1"
#define Global_CLSID_TFormaSpiskaSprStrObjectImpl "{FB46EC70-2EBE-43DF-B18E-11D032C5EFDA}"
#define Global_IID_IFormaSpiskaSprStrObject "{94C9A8B8-93DD-47AA-8818-5A553AF8B6D5}"

#define ProgId_FormaReportOCBRegGoods "Oberon.FormaReportOCBRegGoods.1"
#define Global_CLSID_TFormaReportOCBRegGoodsImpl "{B516E64B-C264-4801-A1AC-777FBE1B1AD5}"
//#define Global_IID_IFormaReportOCBRegGoods

#define ProgId_FormaSpiskaSprTypePrice  "Oberon.FormaSpiskaSprTypePrice.1"
#define Global_CLSID_TFormaSpiskaSprTypePriceImpl "{62D41FAE-C76D-4134-BCB2-979A0EF6B212}"
#define Global_IID_IFormaSpiskaSprTypePrice  "{D3C8CDBD-6DD2-4EB0-958A-222FC962C6E2}"

#define ProgId_FormaElementaSprTypePrice  "Oberon.FormaElementaSprTypePrice.1"
#define Global_CLSID_TFormaElementaSprTypePriceImpl "{9DBDF3D2-9ECF-4192-B44B-8B7A7038EE89}"
#define Global_IID_IFormaElementaSprTypePrice  "{D30E8E64-7979-49E4-B37B-21EA77050912}"

#define ProgId_FormaSpiskaSprMPrig "Oberon.FormaSpiskaSprMPrig.1"
#define Global_CLSID_TFormaSpiskaSprMPrigImpl "{C429C1FE-9CC0-488E-B9C8-F5876E901809}"
#define Global_IID_IFormaSpiskaSprMPrig  "{451E6010-865D-4E75-BA43-629FA4413B1E}"

#define ProgId_FormaSpiskaSprCodeTel "Oberon.FormaSpiskaSprCodeTel.1"
#define Global_CLSID_TFormaSpiskaSprCodeTelImpl "{B811786B-8978-42EA-B9A3-0F37F48E131A}"
#define Global_IID_IFormaSpiskaSprCodeTel  "{C2CAD302-9509-4DB8-BBBF-0A527159588E}"

#define ProgId_DMSprCodeTel "Kas.DMSprCodeTel.1"
#define Global_CLSID_TDMSprCodeTelImpl "{AE0B0E13-CBBD-46E9-B85D-F9F73E34B382}"
#define Global_IID_IDMSprCodeTel "{F3AA0520-7C0E-4647-A3E5-D081388E21F1}"

#define ProgId_FormaElementaSprCodeTel "Kas.FormaElementaSprCodeTel.1"
#define Global_CLSID_TFormaElementaSprCodeTelImpl "{06DAE354-0BAE-4AC8-A654-3E313B85F185}"
#define Global_IID_IFormaElementaSprCodeTel "{012EB0B8-7E7D-4498-8E5E-249ED9462595}"


#define ProgId_FormaDialogaReportSaleCheck "Oberon.FormaDialogaRepSaleCheck.1"
#define Global_CLSID_TFormaDialogaReportSaleCheckImpl "{0EEFE497-7872-4249-8769-61D879FB6D0B}"
//#define Global_IID_IFormaDialogaReportSaleCheck


//∆”–Õ¿À œ–»’ŒƒÕ¿ﬂ Õ¿ À¿ƒÕ¿ﬂ
#define ProgId_FormaGurDocPrihNakl  "Oberon.FormaGurDocPrihNakl.1"
#define Global_CLSID_TFormaGurDocPrihNaklImpl "{8E2FB7A4-6C4E-43CA-845E-10516E634498}"
#define Global_IID_IFormaGurDocPrihNakl "{E6F08C85-8C0F-4BC4-8C0E-B6FF626F23BB}"






#define ProgId_FormaGurDocCheckKKM "Oberon.FormaGurDocCheckKKM.1"
#define Global_CLSID_TFormaGurDocCheckKKMImpl "{74B02907-36B4-441F-BA9F-028555C36CA7}"
#define Global_IID_IFormaGurDocCheckKKM "{790D01DB-2EFA-4833-A094-629461B233EF}"

#define ProgId_DMGurDocCheckKKM   "Oberon.DMGurDocCheckKKM.1"
#define Global_CLSID_TDMGurDocCheckKKMImpl "{73CC49BA-9D43-4A43-82B6-E6A7076D679F}"
#define Global_IID_IDMGurDocCheckKKM  "{256F6057-24D8-495C-BB48-8700ABE2C195}"


#define ProgId_FormaGurDocPer "Oberon.FormaGurDocPer.1"
#define Global_CLSID_TFormaGurDocPerImpl "{36C85699-5CE5-4F9B-A4F4-F0F7919CE2BF}"
#define Global_IID_IFormaGurDocPer "{DE72BB0C-6765-47E1-9E87-E3DF59E15CF7}"

#define ProgId_FormaReportOCBRegVSRasch "Oberon.FormaRepOCBRegVSRasch.1"
#define Global_CLSID_TFormaReportOCBRegVSRaschImpl "{8B2035F1-9A20-4D24-B1D2-797F8DC43091}"
//#define Global_IID_IFormaReportOCBRegVSRasch


//ƒŒ ”Ã≈Õ“ »Õ¬≈Õ“¿–»«¿÷»ﬂ
#define ProgId_FormaDocInv "Oberon.FormaDocInv.1"
#define Global_CLSID_TFormaDocInvImpl "{60B51F66-0A59-481C-8B8C-20F59E514512}"
#define Global_IID_IFormaDocInv "{697585F5-42EC-4C38-9A24-DD70950AB5E2}"

#define ProgId_DMDocInv "Oberon.DMDocInv.1"
#define Global_CLSID_TDMDocInvImpl  "{50E81966-968E-4920-BB1E-18643BF3D062}"
#define Global_IID_IDMDocInv "{FFC1B43D-2528-479A-8EA4-99D21BD79325}"







#define ProgId_FormaDialogaReportResultReal  "Oberon.FormaReportResultReal.1"
#define Global_CLSID_TFormaDialogaReportResultRealImpl "{DF76AB2D-27D6-4357-B076-48ECCE3011F6}"
//#define Global_IID_IFormaDialogaReportResultReal

#define ProgId_FormaReportVipuskProd "Oberon.FormaReportVipuskProd.1"
#define Global_CLSID_TFormaReportVipuskProdImpl   "{D27C13AD-48A9-43AA-9F09-28625E9AD86E}"
//#define Global_IID_IFormaReportVipuskProd

#define ProgId_FormaReportKartTovara "Oberon.FormaReportKartTovara.1"
#define Global_CLSID_TFormaReportKartTovaraImpl "{BDDC2893-1232-4C7F-AAB8-65F6C931B9B2}"
//#define Global_IID_IFormaReportKartTovara

#define ProgId_FormaSpiskaSetup "Oberon.FormaSpiskaSetup.1"
#define Global_CLSID_TFormaSpiskaSetupImpl "{28142A93-D868-4EA9-97C2-C7B4E8E4734B}"
#define Global_IID_IFormaSpiskaSetup "{47C3C43C-F1CE-45CA-B42D-30A844E6FD12}"

#define ProgId_DMSetup "Oberon.DMSetup.1"
#define Global_CLSID_TDMSetupImpl "{6B5390B1-B20D-41F3-8813-A55416D6C620}"
#define Global_IID_IDMSetup "{29947225-A7D6-4EA1-A1A8-0D74CBDE3A4D}"


#define ProgId_FormaReportKartKlient  "Oberon.FormaReportKartKlient.1"
#define Global_CLSID_TFormaReportKartKlientImpl "{4D33D9C5-51BB-451E-B34D-C64E45D70553}"
//#define Global_IID_IFormaReportKartKlient

#define ProgId_FormaSpiskaSprInfBase "Oberon.FormaElementaSprInfBase.1"
#define Global_CLSID_TFormaSpiskaSprInfBaseImpl "{F55FEE6D-0F47-45F1-A8A9-B04D4677D3B4}"
#define Global_IID_IFormaSpiskaSprInfBase "{42FDC31F-4E0C-4B8C-8988-EABBA4A897BE}"

#define ProgId_DMSprInfBase "Oberon.DMSprInfBase.1"
#define Global_CLSID_TDMSprInfBaseImpl "{9A67DF5D-BD13-4CBA-92BE-F2F4103FEF13}"
#define Global_IID_IDMSprInfBase "{EBFE9DC8-2C99-4059-9103-622A2D390F0A}"

//ƒŒ ”Ã≈Õ“ Œ“◊≈“   Ã
#define ProgId_FormaDocRepKKM  "Oberon.FormaDocRepKKM.1"
#define Global_CLSID_TFormaDocRepKKMImpl  "{EFBDAC01-0B3A-4FA6-B961-BEAF7FDCB2B8}"
#define Global_IID_IFormaDocRepKKM  "{375771DC-28E1-4417-8EDB-B8F5A884B03A}"

#define ProgId_DMDocRepKKM "Oberon.DMDocRepKKM.1"
#define Global_CLSID_TDMDocRepKKMImpl  "{53D329B9-1AC5-44B9-975F-68B77E8E8845}"
#define Global_IID_IDMDocRepKKM  "{224C454D-CF75-4C72-B207-64394535B70E}"



#define ProgId_FormaReportKalkKarta "Oberon.FormaReportKalkKarta.1"
#define Global_CLSID_TFormaReportKalkKartaImpl "{C7EA90BD-D8D6-4851-9670-D35DACD14359}"
//#define Global_IID_IFormaReportKalkKarta

#define ProgId_FormaReportOCBRegOstNom  "Oberon.FormaReportOCBRegOstNom.1"
#define Global_CLSID_TFormaReportOCBRegOstNomImpl "{F23C0907-4256-4F65-B534-43BE2C0A338E}"
//#define Global_IID_IFormaReportOCBRegOstNom

#define ProgId_FormaReportRashodProduct  "Oberon.FormaReportRashodProduct.1"
#define Global_CLSID_TFormaReportRashodProductImpl "{818BBB8A-D227-4625-BE73-7EAF650FABE8}"
//#define Global_IID_IFormaReportRashodProduct



#define ProgId_FormaSpiskaSprARM "Oberon.FormaSpiskaSprARM.1"
#define Global_CLSID_TFormaSpiskaSprARMImpl "{6FD30349-25F5-4F51-ADCF-73F1B0D2C214}"
#define Global_IID_IFormaSpiskaSprARM  "{E310989F-AF31-4933-9991-80FB8EE56347}"

#define ProgId_FormaElementaSprARM "Oberon.FormaElementaSprARM.1"
#define Global_CLSID_TFormaElementaSprARMImpl "{794975C8-D189-42A6-9418-2A1700B09D8C}"
#define Global_IID_IFormaElementaSprARM  "{73B4F4D2-44CC-4924-A001-CD5A5F64C56F}"

#define ProgId_DMSprARM "Oberon.DMSprARM.1"
#define Global_CLSID_TDMSprARMImpl "{1FF136F2-05FD-4CE8-BDC5-184A835696FC}"
#define Global_IID_IDMSprARM "{EAA165B1-16C0-4D1C-A655-A0F7C87DA2D7}"



#define ProgId_FormaSpiskaSprOborud "Oberon.FormaSpiskaSprOborud.1"
#define Global_CLSID_TFormaSpiskaSprOborudImpl "{CD836196-9296-4996-95F8-52BF92E39ABE}"
#define Global_IID_IFormaSpiskaSprOborud "{F2E5F742-225F-40A1-BADC-07115130DDA0}"

#define ProgId_FormaElementaSprOborud "Oberon.FormaElementaSprOborud.1"
#define Global_CLSID_TFormaElementaSprOborudImpl  "{1B52D859-E3EB-4986-B88D-7F8E60C9765E}"
#define Global_IID_IFormaElementaSprOborud "{0A9B12C2-740C-4E3A-AA71-7E2C936DEC57}"

#define ProgId_DMSprOborud "Oberon.DMSprOborud.1"
#define Global_CLSID_TDMSprOborudImpl "{E055A7FF-D362-4209-AA5D-FE1179D05EFE}"
#define Global_IID_IDMSprOborud "{86137E3F-A800-4863-AB2B-610F3BA44AF5}"

#define ProgId_DMSprOborudParam "Oberon.DMSprOborudParam.1"
#define Global_CLSID_TDMSprOborudParamImpl "{DD35645B-4AFB-46B6-959D-A43548D166EF}"

#define ProgId_FormaSpiskaSprOborudParam "Oberon.FormaSpiskaSprOborudParam.1"
#define Global_CLSID_TFormaSpiskaSprOborudParamImpl "{6E82EE4C-5BAD-44F1-9953-E203F72D6F93}"




#define ProgId_FormaSpiskaSprVesNom  "Oberon.FormaSpiskaSprVesNom.1"
#define Global_CLSID_TFormaSpiskaSprVesNomImpl "{41967D49-408C-4B49-944C-FA4DD67C0C50}"
#define Global_IID_IFormaSpiskaSprVesNom "{92F0D063-DF06-4B2F-A626-802741056D79}"

//ƒŒ ”Ã≈Õ“ Œ—“¿“ » ¬«¿»ÃŒ–¿—◊≈“Œ¬
#define ProgId_FormaDocOstVs "Oberon.FormaDocRegVsRasch.1"
#define Global_CLSID_TFormaDocOstVsImpl "{C3FB2ED0-4510-4908-BDC2-DB8F76B33C75}"
#define Global_IID_IFormaDocOstVs "{14087F63-7E5F-43CC-AD64-7B280B9D5DE3}"

#define ProgId_DMDocOstVs "Oberon.DMDocOstVs.1"
#define Global_CLSID_TDMDocOstVsImpl "{A081CC1A-7466-4C9E-B54B-C723D205008B}"
#define Global_IID_IDMDocOstVs "{05C06371-7684-46E5-9E3E-CB07BABC3D7A}"







#define ProgId_SheetEditor "Oberon.SheetEditor.1"
#define Global_CLSID_TSheetEditorImpl "{AB572E8D-6EEF-46FD-BE0A-014A21EE3C38}"
#define Global_IID_ISheetEditor "{99B6B914-2212-4B32-855B-0C064BD8E122}"


//ƒŒ ”Ã≈Õ“ –≈¿À»«¿÷»ﬂ –Œ«Õ»÷¿
#define ProgId_FormaDocRealRozn "Oberon.FormaDocRealRozn.1"
#define Global_CLSID_TFormaDocRealRoznImpl  "{13D9D5CD-AADB-444D-B2CF-8BB6692F42E2}"
#define Global_IID_IFormaDocRealRozn "{240147F1-036B-4428-AD06-F9B7B6AE68AD}"

#define ProgId_DMDocRealRozn "Oberon.DMDocRealRozn.1"
#define Global_CLSID_TDMDocRealRoznImpl "{DA6FB049-86B2-4F0C-A94F-BB4DCA43F61C}"
#define Global_IID_IDMDocRealRozn "{F6C01097-4C39-4926-9B54-28BE560CF008}"



//ƒŒ ”Ã≈Õ“ œ Œ ÓÁÌË˜Ì˚È
#define ProgId_FormaDocPKORozn "Oberon.FormaDocPKORozn.1"
#define Global_CLSID_TFormaDocPKORoznImpl "{59470AE6-36C5-4FA9-AEB1-FC8AF123BA79}"
#define Global_IID_IFormaDocPKORozn "{748243AD-AC56-453F-ACDA-2B47053539FB}"

#define ProgId_DMDocPKORozn  "Oberon.DMDocPKORozn.1"
#define Global_CLSID_TDMDocPKORoznImpl "{A47A0550-D90F-469C-A35C-CA779DC75B9A}"
#define Global_IID_IDMDocPKORozn "{2109301A-0DD7-4410-A582-1D32E8EE4A23}"


//– Œ –Œ«Õ»◊Õ€…
#define ProgId_FormaDocRKORozn "Oberon.FormaDocRKORozn.1"
#define Global_CLSID_TFormaDocRKORoznImpl "{F7F2E192-3908-458F-AF30-23A19F86D43B}"
#define Global_IID_IFormaDocRKORozn  "{A487131A-EB0E-43F1-8976-0214FF467790}"

#define ProgId_DMDocRKORozn  "Oberon.DMDocRKORozn.1"
#define Global_CLSID_TDMDocRKORoznImpl "{5CEB5AD8-D619-4963-9629-8BE0CAF87AAA}"
#define Global_IID_IDMDocRKORozn "{BAA4417C-DFE5-4B80-9141-4144A0E2654A}"


#define ProgId_FormaReportOCBPaySale "Oberon.FormaReportOCBPaySale.1"
#define Global_CLSID_TFormaReportOCBPaySaleImpl  "{30162966-9A80-4C28-AE32-F6A259CCD95E}"
//#define Global_IID_IFormaReportOCBPaySale

#define ProgId_FormaReportKassa "Oberon.FormaReportKassa.1"
#define Global_CLSID_TFormaReportKassaImpl "{B22467E1-CE68-4FA4-B311-56CCCC79DA66}"
//#define Global_IID_IFormaReportKassa

#define ProgId_FormaReportBank "Oberon.FormaReportBank.1"
#define Global_CLSID_TFormaReportBankImpl "{57775B82-4482-402D-B26A-792F5922D73D}"
#define Global_IID_IFormaReportBank

#define ProgId_FormaPrintPriceA "Oberon.FormaPrintPriceA.1"
#define Global_CLSID_TFormaPrintPriceAImpl "{66F77B8C-0D09-4299-85CF-61829F128E34}"
//#define Global_IID_IFormaPrintPriceA

#define ProgId_FormaSpiskaSprInv "Oberon.FormaSpiskaSprInv.1"
#define Global_CLSID_TFormaSpiskaSprInvImpl "{2515E7A8-AD94-47B9-B605-600BE94C8CE7}"
#define Global_IID_IFormaSpiskaSprInv  "{33113C6E-489F-4C6D-86E8-E162CEDFB44C}"

#define ProgId_FormaDocVosvratPok "Oberon.FormaDocVosvratPok.1"
#define Global_CLSID_TFormaDocVosvratPokImpl  "{38C2E806-E76E-407F-9D9D-93712A11A3AC}"
#define Global_IID_IFormaDocVosvratPok "{CEFAB327-03AD-494D-9F6C-F2C40DEBD998}"


//—œ»—¿Õ»≈ Œ“–»÷¿“≈À‹Õ€’ Œ—“¿“ Œ¬

#define ProgId_FormaDocSpOtrOst "Oberon.FormaDocSpOtrOst.1"
#define Global_CLSID_TFormaDocSpOtrOstImpl  "{63102B15-066E-4B97-A51B-CC5A489DD768}"
#define Global_IID_IFormaDocSpOtrOst  "{213BA0AA-DA76-41F9-B4E9-DD6402349946}"

#define ProgId_DMDocSpOtrOst  "Oberon.DMDocSpOtrOst.1"
#define Global_CLSID_TDMDocSpOtrOstImpl  "{35F742C5-5125-4233-8461-97286E05079D}"
#define Global_IID_IDMDocSpOtrOst "{FE71E9BE-D0D9-46EF-A4D8-E6981446DACE}"



//ƒŒ ”Ã≈Õ“ œ≈–≈Œ÷≈Õ ¿
#define ProgId_FormaDocIsmPrice "Oberon.FormaDocIsmPrice.1"
#define Global_CLSID_TFormaDocIsmPriceImpl "{B7CA417E-5DBC-4187-A411-251A60DC775F}"
#define Global_IID_IFormaDocIsmPrice "{C9C2EAC1-CFEE-41F0-8F9F-6455867C1583}"

#define ProgId_DMDocIsmPrice "Oberon.DMDocIsmPrice.1"
#define Global_CLSID_TDMDocIsmPriceImpl "{CAF42D09-91C3-466E-BC28-43FA47A2E192}"
#define Global_IID_IDMDocIsmPrice "{7386068D-7094-4D28-84D1-02A54AD646C1}"



//ƒŒ ”Ã≈Õ“ –≈¬»«»ﬂ
#define ProgId_FormaDocRev "Oberon.FormaDocRev.1"
#define Global_CLSID_TFormaDocRevImpl  "{212FBECB-BAFE-4231-A187-EE0FF1CAC189}"
#define Global_IID_IFormaDocRev "{BC42C1A1-E682-4915-8E86-6BB73E806FBC}"

#define ProgId_DMDocRev "Oberon.DMDocRev.1"
#define Global_CLSID_TDMDocRevImpl  "{79AD85CB-24D6-450C-A46A-A149CEE3BFE0}"
#define Global_IID_IDMDocRev  "{E4E9FDBD-1954-4EBB-8BE3-C380FA822F4B}"



#define ProgId_FormaReportDiscountDocCheck "Oberon.FormaReportDiscountDocCheck.1"
#define Global_CLSID_TFormaReportDiscountDocCheckImpl "{425AAC37-B574-4341-ABCE-5609A944ECD3}"
//#define Global_IID_IFormaReportDiscountDocCheck

#define ProgId_FormaReportGoodsReport "Oberon.FormaReportGoodsReport.1"
#define Global_CLSID_TFormaReportGoodsReportImpl  "{7E2473BC-419E-4183-A966-731CE73D1791}"
//#define Global_IID_IFormaReportGoodsReport

#define ProgId_FormaGurLog "Oberon.FormaGurLog.1"
#define Global_CLSID_TFormaGurLogImpl "{6A133FCD-1D64-471B-809C-CAA9BCB3FBD9}"
#define Global_IID_IFormaGurLog "{E28A3E75-6913-48D6-B2D9-C6D223E0005E}"

#define ProgId_FormaSpiskaSprVidKlient "Oberon.FormaSpiskaSprVidKlient.1"
#define Global_CLSID_TFormaSpiskaSprVidKlientImpl "{AE1E2CFD-2CA5-4921-B847-BCC838F23C5A}"
#define Global_IID_IFormaSpiskaSprVidKlient "{D3A8442B-FFE3-4355-9DAC-3E81BC0B08ED}"

#define ProgId_FormaSpiskaSprVidNom "Oberon.FormaSpiskaSprVidNom.1"
#define Global_CLSID_TFormaSpiskaSprVidNomImpl "{5AAC6507-4BE5-49CF-8BDC-8C1C1E365EC3}"
#define Global_IID_IFormaSpiskaSprVidNom "{76F7294F-27FE-425E-972D-4E46D146EA44}"


//—œ–¿¬Œ◊Õ»  ¿¬“ŒÃ¿“»◊≈— »≈ — »ƒ »
#define ProgId_FormaSpiskaSprDiscountAuto "Oberon.FormaSpiskaSprDiscountAuto.1"
#define Global_CLSID_TFormaSpiskaSprDiscountAutoImpl "{1EF36F28-216D-43FE-8CF2-C7DBD9FDFD32}"
#define Global_IID_IFormaSpiskaSprDiscountAuto "{719CFA3A-4021-478F-83AD-1BB58E776633}"

#define ProgId_DMSprDiscountAuto "Oberon.DMSprDiscountAuto.1"
#define Global_CLSID_TDMSprDiscountAutoImpl "{A5C8CA88-5402-4054-B8E1-EC760AE382FE}"
#define Global_IID_IDMSprDiscountAuto "{11293307-9A1B-4B0C-9C7C-736D9EF715D8}"


#define ProgId_FormaSpiskaSprVidDiscountCard "Oberon.FormaSpiskaSprVidDiscountCard.1"
#define Global_CLSID_TFormaSpiskaSprVidDiscountCardImpl "{29D50B3D-0880-46EF-883F-2F705EE60850}"
#define Global_IID_IFormaSpiskaSprVidDiscountCard "{231E4165-1052-46E8-BF91-37CB55041159}"

#define ProgId_FormaSpiskaTableNumberDoc "Oberon.FormaSpiskaTableNumberDoc.1"
#define Global_CLSID_TFormaSpiskaTableNumberDocImpl "{D113C48E-BC72-4490-8DB2-2B8E660B6BAC}"
#define Global_IID_IFormaSpiskaTableNumberDoc  "{39CB0857-C1B2-4AB7-8A68-0A06B517EF96}"

#define ProgId_FormaSpiskaSprNakSkidok  "Oberon.FormaSpiskaSprNakSkidok.1"
#define Global_CLSID_TFormaSpiskaSprNakSkidokImpl "{196689EF-8DCB-4EE0-89C1-D7D6CA28E23D}"
#define Global_IID_IFormaSpiskaSprNakSkidok "{461D87EE-13D2-414B-992F-E12E349701E5}"

#define ProgId_FormaGurOperDiscountCard "Oberon.FormaGurOperDiscountCard.1"
#define Global_CLSID_TFormaGurOperDiscountCardImpl "{B87A2F02-83AE-4A06-8FB5-46D0BCE70D58}"
#define Global_IID_IFormaGurOperDiscountCard "{F4A8F217-BBB5-4EE2-86B3-9AAF8BEB525F}"

//‘Œ–Ã¿ Ã¿——Œ¬Œ√Œ —Œ«ƒ¿Õ»ﬂ  ¿–“
#define ProgId_FormaCreateCard "Kas.FormaCreateCard.1"
#define Global_CLSID_TFormaCreateCardImpl "{208ECB16-718E-4E09-A68D-1014EFC7FF4D}"





#define ProgId_FormaSpiskaXSetupObmen "Oberon.FormaSpiskaXSetupObmen.1"
#define Global_CLSID_TFormaSpiskaXSetupObmenImpl "{5332BAED-0C69-41D0-BF52-A6595A4C2ED0}"
#define Global_IID_IFormaSpiskaXSetupObmen "{1FEE8A5D-5A8D-4825-B8DC-55774F3B2662}"

#define ProgId_FormaSpiskaSprImportSet  "Oberon.FormaSpiskaSprImportSet.1"
#define Global_CLSID_TFormaSpiskaSprImportSetImpl  "{D26F4F9F-ADEA-431A-A3AA-CBAAC002F0F9}"
#define Global_IID_IFormaSpiskaSprImportSet "{B2F10AA7-4717-4835-8BB2-2C20FD24860A}"


//¬€œ”—  œ–Œƒ” ÷»»
#define ProgId_FormaDocVipuskProd "Oberon.FormaDocVipuskProd.1"
#define Global_CLSID_TFormaDocVipuskProdImpl "{09A26DE5-2FF9-40D1-9322-FFE6F6D98361}"
#define Global_IID_IFormaDocVipuskProd "{BF07785D-AB9D-4132-9E73-0F9B7938C008}"

#define ProgId_DMDocVipuskProd  "Oberon.DMDocVipuskProd.1"
#define Global_CLSID_TDMDocVipuskProdImpl  "{38C2E6A1-6E5D-43BF-A4F6-4B3D08E20FEC}"
#define Global_IID_IDMDocVipuskProd "{F9478B5C-CFD4-4BA1-87E2-C5BC56CEB5FA}"



#define ProgId_FormaImportDocPrihNakl "Oberon.FormaImportDocPrihNakl.1"
#define Global_CLSID_TFormaImportDocPrihNaklImpl "{E684E08A-4D74-40A2-97EA-CF92D9564DC7}"
#define Global_IID_IFormaImportDocPrihNakl "{8F887195-981E-4014-821E-7118AD3093A8}"

#define ProgId_FormaExportDoc "Oberon.FormaExportDoc.1"
#define Global_CLSID_TFormaExportDocImpl "{A1B4E13E-800E-4F94-8F15-6DE7614C025B}"
//#define Global_IID_IFormaExportDoc

#define ProgId_FormaSpiskaSprScale "Oberon.FormaSpiskaSprScale.1"
#define Global_CLSID_TFormaSpiskaSprScaleImpl "{A7815DBA-3C0F-4066-9E07-B6726594A539}"
#define Global_IID_IFormaSpiskaSprScale "{BB170C24-3167-4273-A60C-97A5B93FEFD7}"

#define ProgId_FormaSpiskaSprProject "Oberon.FormaSpiskaSprProject.1"
#define Global_CLSID_TFormaSpiskaSprProjectImpl  "{72E54A62-AF7A-4FB3-9272-3A59B2AA1B11}"
#define Global_IID_IFormaSpiskaSprProject "{D3ADEE1F-258D-465E-8227-723774EA2D67}"

#define ProgId_FormaDialogaReportPoProject "Oberon.FormaDialogaReportPoProject.1"
#define Global_CLSID_TFormaDialogaReportPoProjectImpl "{8CE310AC-3592-44EE-A564-C3A9DF7AAF21}"
//#define Global_IID_IFormaDialogaReportPoProject




//—¡Œ– ¿  ŒÃœÀ≈ “¿
#define ProgId_FormaDocSborkaKompl "Oberon.FormaDocSborkaKompl.1"
#define Global_CLSID_TFormaDocSborkaKomplImpl "{A31277F4-06B8-4D48-8266-5AA0BA9B6EFC}"
#define Global_IID_IFormaDocSborkaKompl "{445D6DD2-13EF-42AF-B5F9-B1EEFF10F8D7}"

#define ProgId_DMDocSborkaKompl "Oberon.DMDocSborkaKompl.1"
#define Global_CLSID_TDMDocSborkaKomplImpl   "{F3B0828B-CE8F-4E5D-BA7F-B7457B65E9AA}"
#define Global_IID_IDMDocSborkaKompl "{458B9BF3-3C85-4758-A309-27FDE545D543}"

//ƒŒ ”Ã≈Õ“ –¿«¡Œ– ¿  ŒÃœÀ≈ “¿
#define ProgId_FormaDocRasborkaKompl "Oberon.FormaDocRasborkaKompl.1"
#define Global_CLSID_TFormaDocRasborkaKomplImpl "{6E249C88-F194-4F38-A061-EE910B6B812C}"
#define Global_IID_IFormaDocRasborkaKompl "{64C9E7AC-738E-4256-A4A8-DA646E272193}"

#define ProgId_DMDocRasborkaKompl "Oberon.DMDocRasborkaKompl.1"
#define Global_CLSID_TDMDocRasborkaKomplImpl "{B929733B-200B-4813-BA77-016E9ED8F0FF}"
#define Global_IID_IDMDocRasborkaKompl "{E656F3B1-47C6-434B-A8BE-B949B5BBD1FC}"



//ƒŒ ”Ã≈Õ“ «¿Ã≈Õ¿
#define ProgId_FormaDocZamena "Oberon.FormaDocZamena.1"
#define Global_CLSID_TFormaDocZamenaImpl "{2D193C9E-2AB7-4DEA-AB51-0830F42A772B}"
#define Global_IID_IFormaDocZamena "{F409ABB0-A0CB-45FA-AFF7-53E7754FF612}"

#define ProgId_DMDocZamena "Oberon.DMDocZamena.1"
#define Global_CLSID_TDMDocZamenaImpl "{29DA6160-09D9-4265-B71A-8E5F7213DD5E}"
#define Global_IID_IDMDocZamena  "{FE0BDBFD-5586-448E-82DA-4D723822C715}"



//ƒŒ ”Ã≈Õ“  Œ––≈ “»–Œ¬ ¿ ¬«¿»ÃŒ–¿—◊≈“Œ¬
#define ProgId_FormaDocKorrVs "Oberon.FormaDocKorrVS.1"
#define Global_CLSID_TFormaDocKorrVsImpl "{59394A39-1BF6-495A-A2FF-49F9F21D238A}"
#define Global_IID_IFormaDocKorrVs "{4576FAB5-D7AB-43BB-8978-86F3B4BEBD72}"

#define ProgId_DMDocKorrVs "Oberon.DMDocKorrVS.1"
#define Global_CLSID_TDMDocKorrVsImpl "{1223170A-EC5C-4E72-A72E-E3E5945D3ABA}"
#define Global_IID_IDMDocKorrVs "{863663CB-01C9-4B33-A1EC-8662082D06BC}"




//¬€œ»— ¿ ¡¿Õ ¿
#define ProgId_FormaDocVipBanka "Oberon.FormaDocVipBanka.1"
#define Global_CLSID_TFormaDocVipBankaImpl "{54C9044C-473F-445E-B436-F94FAF647C8E}"
#define Global_IID_IFormaDocVipBanka "{F3386850-6C81-4993-9B31-9BC025645352}"

#define ProgId_DMDocVipBanka "Oberon.DMDocVipBanka.1"
#define Global_CLSID_TDMDocVipBankaImpl "{9853C190-DFFC-43FA-AFB0-33AB57DD119A}"
#define Global_IID_IDMDocVipBanka "{E3B9540A-DBB3-4461-B8B4-5C77AE840C5B}"



//—œ–¿¬Œ◊Õ»  ƒ»— ŒÕ“Õ€≈  ¿–“€
#define ProgId_FormaSpiskaSprDiscountCard1   "Oberon.FormaSpiskaSprDiscountCard_1.1"
#define Global_CLSID_TFormaSpiskaSprDiscountCard1Impl "{F950C38A-35F7-452F-A055-02FA49F44529}"
#define Global_IID_IFormaSpiskaSprDiscountCard1 "{29EB5CD9-7FD3-49F6-AF52-E255B36AAFAA}"

#define ProgId_DMSprDiscountCard1 "Oberon.DMSprDiscountCard_1.1"
#define Global_CLSID_TDMSprDiscountCard_1Impl  "{BCBF70E7-1B42-4C35-8680-977E937071FE}"
#define Global_IID_IDMSprDiscountCard_1 "{D96D8704-E816-43AB-A63E-23D1BF39FE7B}"

#define ProgId_FormaSpiskaSprDiscountCard "Oberon.FormaSpiskaSprDiscountCard.1"
#define Global_CLSID_TFormaSpiskaSprDiscountCardImpl "{46C215D4-69EC-4736-9AFB-9761ED231160}"
#define Global_IID_IFormaSpiskaSprDiscountCard "{4AE7322E-58BA-479D-A81D-0862831BD841}"

#define ProgId_DMSprDiscountCard "Oberon.DMSprDiscountCard.1"
#define Global_CLSID_TDMSprDiscountCardImpl "{4ABAAF94-60AD-4B34-AEFA-9C66BBBB50A1}"
#define Global_IID_IDMSprDiscountCard  "{EF9B5A30-450E-4F78-ABE8-1B37770F306E}"



//—À”∆≈¡Õ€≈ ƒŒ ”≈Õ“€
#define ProgId_FormaDocRegAdvCust "Oberon.FormaDocRegAdvCust.1"
#define Global_CLSID_TFormaDocRegAdvCustImpl "{506698E7-F8E6-4E07-A02E-DE3F45C39232}"
#define Global_IID_IFormaDocRegAdvCust "{0CEB0F37-7991-4B65-8952-C573994AEFA8}"

#define ProgId_DMDocRegAdvCust "Oberon.DMDocRegAdvCust.1"
#define Global_CLSID_TDMDocRegAdvCustImpl "{F5C1DBB7-3C63-4378-B548-0270A44CF121}"
#define Global_IID_IDMDocRegAdvCust "{BAE36A90-8A30-4A3C-B0D9-D7F67CCCABE3}"


#define ProgId_FormaDocRegBank "Oberon.FormaDocRegBank.1"
#define Global_CLSID_TFormaDocRegBankImpl "{FFF055DE-6A53-4DD6-A948-F6AA49FD52C8}"
#define Global_IID_IFormaDocRegBank "{FFCD508A-353B-4F70-8F5F-6EE8E16DA98C}"

#define ProgId_DMDocRegBank "Oberon.DMDocRegBank.1"
#define Global_CLSID_TDMDocRegBankImpl  "{FDAD3096-28D3-4685-B17B-8997449392BA}"
#define Global_IID_IDMDocRegBank  "{33B6E336-4BC8-476B-A410-BE610AB976C5}"



#define ProgId_FormaDocRegCardBal "Oberon.FormaDocRegCardBalance.1"
#define Global_CLSID_TFormaDocRegCardBalImpl  "{080A1EF2-4337-4A55-AC0E-75A7827748D3}"
#define Global_IID_IFormaDocRegCardBal "{6B405E51-5399-46E2-AEF4-7074A380DA6C}"

#define ProgId_DMDocRegCardBal  "Oberon.DMDocRegCardBalance.1"
#define Global_CLSID_TDMDocRegCardBalanceImpl  "{A81C0FF1-6C75-4B9A-8CB4-C83341E5928F}"
#define Global_IID_IDMDocRegCardBalance "{EFE98E6C-39C4-4AE5-AFF9-2E8DA86337A5}"


#define ProgId_FormaDocRegGoods "Oberon.FormaDocRegGoods.1"
#define Global_CLSID_TFormaDocRegGoodsImpl "{9429F9FA-D2FF-44F5-9364-8104849CFB19}"
#define Global_IID_IFormaDocRegGoods "{F033DAB1-E1DB-46CC-87BF-D5B567F14DAA}"

#define ProgId_DMDocRegGoods "Oberon.DMDocRegGoods.1"
#define Global_CLSID_TDMDocRegGoodsImpl "{8183AA96-B203-4362-B0FF-547D0EE1B78C}"
#define Global_IID_IDMDocRegGoods "{5E0CE973-E684-4159-BB92-77BB1E0CA0F0}"



#define ProgId_FormaDocRegOstNom "Oberon.FormaDocRegOstNom.1"
#define Global_CLSID_TFormaDocRegOstNomImpl  "{81E030CB-5ABF-407B-80F6-AEEE06DCCB88}"
#define Global_IID_IFormaDocRegOstNom "{33D4F0CB-251C-47C4-8392-25F85954116F}"

#define ProgId_DMDocRegOstNom "Oberon.DMDocRegOstNom.1"
#define Global_CLSID_TDMDocRegOstNomImpl  "{567A0EEE-90D8-487A-8B4B-C239035AC36F}"
#define Global_IID_IDMDocRegOstNom  "{CB906DBC-C3B9-48AC-811C-F41ED8A0ED7B}"




#define ProgId_FormaDocRegKassa "Oberon.FormaDocRegKassa.1"
#define Global_CLSID_TFormaDocRegKassaImpl  "{966BA190-71A2-4CF1-978D-47FC0621D3DE}"
#define Global_IID_IFormaDocRegKassa "{5AA7B182-A1B2-4E8E-AC25-1D7E96007862}"

#define ProgId_DMDocRegKassa  "Oberon.DMDocRegKassa.1"
#define Global_CLSID_TDMDocRegKassaImpl  "{4BFD2867-40A8-4CE7-A827-52610A78AB2B}"
#define Global_IID_IDMDocRegKassa "{E5EFF8A6-D369-4B5C-B494-6912D3625777}"




#define ProgId_FormaDocRegPaySale  "Oberon.FormaDocRegPaySale.1"
#define Global_CLSID_TFormaDocRegPaySaleImpl "{0B98FBA6-43E8-4CE1-94A1-BCB85573D532}"
#define Global_IID_IFormaDocRegPaySale  "{6E02A3FE-DEA4-424D-BCC0-60AB6D29C90A}"

#define ProgId_DMDocRegPaySale "Oberon.DMDocRegPaySale.1"
#define Global_CLSID_TDMDocRegPaySaleImpl  "{5F84D9D4-E012-4CF9-B0CE-1754CACDF4FF}"
#define Global_IID_IDMDocRegPaySale  "{816B4F57-C554-42D5-897A-D052C313B838}"




#define ProgId_FormaDocRegVsRasch "Oberon.FormaDocRegVsRasch.1"
#define Global_CLSID_TFormaDocRegVsRaschImpl "{CFFB7B63-0175-485C-9F9E-D3B4FC5DBC5C}"
#define Global_IID_IFormaDocRegVsRasch  "{D8896318-EC68-4E7E-AFB8-82686DA1B08E}"

#define ProgId_DMDocRegVsRasch  "Oberon.DMDocRegVsRasch.1"
#define Global_CLSID_TDMDocRegVsRaschImpl  "{B66E3420-74B4-4E96-B03F-DEF3A2152F59}"
#define Global_IID_IDMDocRegVsRasch "{FA01DFF1-89FF-4257-A6EE-08538594DA6C}"





#define ProgId_FormaReportOCBCardBalance "Oberon.FormaReportOCBRegCardBalance.1"
#define Global_CLSID_TFormaReportOCBCardBalanceImpl "{76193C1F-A659-4E89-85FE-F51999E89236}"
//#define Global_IID_IFormaReportOCBCardBalance

#define ProgId_FormaSpiskaSprBrand "Oberon.FormaSpiskaSprBrand.1"
#define Global_CLSID_TFormaSpiskaSprBrandImpl "{D59B5CF6-C962-4658-B509-521D3217765A}"
#define Global_IID_IFormaSpiskaSprBrand "{2F89E652-36F1-4297-AB74-511E9A5315E3}"



#define ProgId_FormaSpiskaSprEd "Oberon.FormaSpiskaSprEd.1"
#define Global_CLSID_TFormaSpiskaSprEdImpl "{B2B051B5-6B4C-48D2-86F3-253F01BE2AF3}"
#define Global_IID_IFormaSpiskaSprEd "{D234C229-B823-48F3-BD67-F6963F38F848}"


//¿–Ã Í‡ÒÒË‡
#define ProgId_FormaArmKassir  "Oberon.ArmKas1.1"
#define Global_CLSID_TFormaArmKassirImpl  "{CEAD35B9-DF60-4912-BEC5-D908E5CACCB9}"
#define Global_IID_IFormaArmKassir "{49841ACF-050B-47A9-98E7-AF360E66D664}"


#define ProgId_FormaARMKas2 "Oberon.ArmKas2.1"
#define Global_CLSID_TFormaARMKas2Impl "{34DC9654-4FF4-438E-9B93-24E70CC85C9B}"
//#define Global_IID_IFormaARMKas2

#define ProgId_FormaPriemPlat "Oberon.PriemPlat.1"
#define Global_CLSID_TFormaPriemPlatImpl "{F975B1D5-8C90-4202-B1D4-762034AA3CC1}"
//#define Global_IID_IFormaPriemPlat

#define ProgId_FormaViborSprNom  "Oberon.FormaViborSprNom.1"
#define Global_CLSID_TFormaViborSprNomImpl   "{DF484DBA-3894-4C57-BAA1-C44AF3BDCEB8}"
#define Global_IID_IFormaViborSprNom  "{B4EBE0D5-46FF-4B5A-8ACF-861A00FEBC65}"

#define ProgId_FormaViborSprBVNom  "Oberon.FormaViborBVNom.1"
#define Global_CLSID_TFormaViborSprBVNomImpl "{B6F22D1A-84FA-4395-B801-824CC856803C}"
#define Global_IID_IFormaViborSprBVNom "{604FCDE0-13B7-4CE6-B903-2E12E1AFA014}"

#define ProgId_FormaDocRealRoznForCashiers  "Oberon.FormaDocRealRoznForC.1"
#define Global_CLSID_TFormaDocRealRoznForCashiersImpl  "{4B158C12-B93F-4253-A21A-97BBB483175D}"
#define Global_IID_IFormaDocRealRoznForCashiers "{46F3642E-209E-4B32-900B-44F70B21E3DB}"

#define ProgId_FormaDocPKORoznForCashiers "Oberon.FormaDocPKORoznForC.1"
#define Global_CLSID_TFormaDocPKORoznForCashiersImpl  "{63EF0547-BF24-4DF8-84AE-7D86BB482104}"
#define Global_IID_IFormaDocPKORoznForCashiers "{1C1DAFAE-D6C8-4F88-B7B9-0B45C0CFDF35}"

#define ProgId_FormaDocRKORoznForCashiers "Oberon.FormaDocRKORoznForC.1"
#define Global_CLSID_TFormaDocRKORoznForCashiersImpl  "{79824512-59F9-47E1-B866-A3402D47D3ED}"
#define Global_IID_IFormaDocRKORoznForCashiers "{AD465A4A-D679-43C6-B075-653C141328AA}"



//¬Œ«¬–¿“ Œ“ œŒ ”œ¿“≈Àﬂ
#define ProgId_FormaVosvratPokForCashiers   "Oberon.FormaDocVosvratPokForC.1"
#define Global_CLSID_TFormaVosvratPokForCashiersImpl "{F527E633-F082-4436-965B-ED24AB3DA3E8}"
#define Global_IID_IFormaVosvratPokForCashiers "{F79207FB-5962-4DBF-A40B-F679CF438C5A}"

#define ProgId_DMDocVosvratPok "Oberon.DMDocVosvratPok.1"
#define Global_CLSID_TDMDocVosvratPokImpl "{75A7E1CD-4D41-400E-9F82-9A5EF3CAC3E8}"
#define Global_IID_IDMDocVosvratPok "{4C31E399-53D7-4D43-839F-F71D3CD7120B}"




#define ProgId_FormaGurPlat "Oberon.FormaGurPlat.1"
#define Global_CLSID_TFormaGurPlatImpl "{58B8BC64-08F6-4446-88AB-37E4E489FA04}"
#define Global_IID_IFormaGurPlat "{38CF2B65-2433-41FF-AC89-CA2FF480F3EE}"

#define ProgId_FormaGurCheckKKM2  "Oberon.FormaGurDocCheckKKM2.1"
#define Global_CLSID_TFormaGurCheckKKM2Impl "{EA8E09C6-01A7-4654-B1A6-363A2ECC066A}"
#define Global_IID_IFormaGurCheckKKM2   "{09933230-1166-4882-B7B7-E99AE5FDC0DF}"

#define ProgId_FormaGurRoznDoc "Oberon.FormaGurRoznDoc.1"
#define Global_CLSID_TFormaGurRoznDocImpl  "{101953A4-D278-402B-9EF1-84F75E372C58}"
#define Global_IID_IFormaGurRoznDoc "{BDB09A34-7353-4830-81ED-25386172BB42}"

#define ProgId_FormaReportSaleForCashiers "Oberon.FormaReportReal.1"
#define Global_CLSID_TFormaReportSaleForCashiersImpl "{E8D257EA-2E40-46CF-AC77-E83CF03D3339}"
//#define Global_IID_IFormaReportSaleForCashiers
//
#define ProgId_FormaReportDiscountForCashiers "Oberon.FormaRepDiscDocCheckForC.1"
#define Global_CLSID_TFormaReportDiscountForCashiersImpl "{6458FD40-B948-4F84-9590-D364AAF36D3A}"
//#define Global_IID_IFormaReportDiscountForCashiers
//
//#define ProgId_FormaPrintPriceForCashiers
//#define Global_CLSID_TFormaPrintPriceForCashiersImpl
//#define Global_IID_IFormaPrintPriceForCashiers

//„ÓÒÚËÌËˆ‡
#define ProgId_HOT_FormaDocBron "Oberon.HOT_FormaDocBron.1"
#define Global_CLSID_THOT_FormaDocBronImpl  "{F42C48D5-934D-40C2-9720-C75CDAFF7C47}"
#define Global_IID_IHOT_FormaDocBron  "{C1C8BDFE-EFF7-44E4-8E8F-4AA34E63F658}"

#define ProgId_HOT_FormaDocOtmenaBron "Oberon.HOT_FormaDocOtmenaBron.1"
#define Global_CLSID_THOT_FormaDocOtmenaBronImpl  "{E5C9519E-D23D-4DB5-92CD-49C9475021D7}"
#define Global_IID_IHOT_FormaDocOtmenaBron "{D745D2F9-ABBF-4ED2-92C4-0AA8F31BE58C}"

#define ProgId_HOT_FormaDocRaschet "Oberon.HOT_FormaDocRaschet.1"
#define Global_CLSID_THOT_FormaDocRaschetImpl  "{396C18A4-333F-4B61-887B-5A3F830B0597}"
#define Global_IID_IHOT_FormaDocRaschet  "{43B3A684-E66F-4DAA-AA81-8DFD3E313617}"

#define ProgId_HOT_FormaDocRasm "Oberon.HOT_FormaDocRasm.1"
#define Global_CLSID_THOT_FormaDocRasmImpl "{DB55F7AD-0E25-4A40-BD9C-6FFAA2355E66}"
#define Global_IID_IHOT_FormaDocRasm "{83B3F73A-B4B7-4D46-83B0-C45B38E3BE11}"

#define ProgId_HOT_FormaDocReal "Oberon.HOT_FormaDocReal.1"
#define Global_CLSID_THOT_FormaDocRealImpl "{1A7BB452-2EFC-448A-A381-082C507DB5EC}"
#define Global_IID_IHOT_FormaDocReal "{E01A5A02-CFE7-41B1-84BB-D531A594C544}"

#define ProgId_HOT_FormaDocViesd "Oberon.HOT_FormaDocViezd.1"
#define Global_CLSID_THOT_FormaDocViesdImpl "{7EAAA989-4956-44AC-8992-D62FEBAB9AB2}"
#define Global_IID_IHOT_FormaDocViesd "{7EF03F8F-5533-486D-B3F2-0B2A14EA22C8}"

#define ProgId_HOT_GurAllDoc "Oberon.HOT_DMGurAllDoc.1"
#define Global_CLSID_THOT_GurAllDocImpl "{70726380-880C-4900-8287-D9D21352D771}"
#define Global_IID_IHOT_GurAllDoc "{BD7BBD8A-C080-448D-9D63-5EEF72E022D3}"

#define ProgId_HOT_FormaReportDvNomFonda "Oberon.HOT_FormaRepDvNomFonda.1"
#define Global_CLSID_THOT_FormaReportDvNomFondaImpl  "{ABB38118-4287-4746-AB7A-6B5B1A53D78C}"
//#define Global_IID_IHOT_FormaReportDvNomFonda

#define ProgId_HOT_FormaReportRasm "Oberon.HOT_FormaRepRasm.1"
#define Global_CLSID_THOT_FormaReportRasmImpl  "{A91BFC34-7AA2-48AB-8C8F-8F576A4E4C30}"
//#define Global_IID_IHOT_FormaReportRasm

#define ProgId_HOT_FormaReportRasmK_S "Oberon.HOT_FormaRepRasmK_S.1"
#define Global_CLSID_THOT_FormaReportRasmK_SImpl "{841E2124-7B46-4BE7-8293-C719EF44FAD3}"
//#define Global_IID_IHOT_FormaReportRasmK_S

#define ProgId_HOT_FormaReportSostNF "Oberon.HOT_FormaRepSostNF.1"
#define Global_CLSID_THOT_FormaReportSostNFImpl   "{73F6BD28-8F90-4782-A531-B2573EE4FB53}"
//#define Global_IID_IHOT_FormaReportSostNF

#define ProgId_HOT_FormaReportSvobodNF "Oberon.HOT_FormaRepSvobodNF.1"
#define Global_CLSID_THOT_FormaReportSvobodNFImpl "{61354251-6F03-4954-8CA4-C253419B559F}"
//#define Global_IID_IHOT_FormaReportSvobodNF

#define ProgId_HOT_FormaSpiskaSprCatNom "Oberon.HOT_FormaElSprCatNom.1"
#define Global_CLSID_THOT_FormaSpiskaSprCatNomImpl "{2AF2017F-6C30-4163-8EE5-552CCDA9D31E}"
#define Global_IID_IHOT_FormaSpiskaSprCatNom "{AA662F04-E6BD-41C0-802A-9D1A5AE560B9}"

#define ProgId_HOT_FormaSpiskaSprCelPriesda  "Oberon.HOT_FormaSpSprCelPriesda.1"
#define Global_CLSID_THOT_FormaSpiskaSprCelPriesdaImpl  "{7AD7B150-2DE1-44FD-9F58-7B2CBAFC3F3B}"
#define Global_IID_IHOT_FormaSpiskaSprCelPriesda  "{01E6F297-2234-46F3-A4DA-7BEC77511731}"

#define ProgId_HOT_FormaSpiskaSprNF  "Oberon.HOT_FormaSpSprNF.1"
#define Global_CLSID_THOT_FormaSpiskaSprNFImpl  "{11602D9E-A666-4BF1-A58C-39CC600D6931}"
#define Global_IID_IHOT_FormaSpiskaSprNF "{2664B8AB-50CB-43BD-A237-05AE3F6A3137}"

#define ProgId_HOT_FormaSpiskaSprObject "Oberon.HOT_FormaSpSprObject.1"
#define Global_CLSID_THOT_FormaSpiskaSprObjectImpl "{70865CD7-E154-4EDF-9E00-EFD392FC4573}"
#define Global_IID_IHOT_FormaSpiskaSprObject "{4650CFBC-7E5A-4134-B058-6857BD77260A}"

#define ProgId_HOT_FormaSpiskaSprPrOsnUsl "Oberon.HOT_FormaSpSprPrOsnUslug.1"
#define Global_CLSID_THOT_FormaSpiskaSprPrOsnUslImpl   "{D6A7A8F9-1781-47C0-8FE9-7FDA79973407}"
#define Global_IID_IHOT_FormaSpiskaSprPrOsnUsl  "{98B1C9F6-FF38-479D-A3CC-CECF365A4588}"

#define ProgId_HOT_FormaSpiskaSprSostNom "Oberon.HOT_FormaSpSprSostNom.1"
#define Global_CLSID_THOT_FormaSpiskaSprSostNomImpl "{0ACABF0C-D842-4651-B930-DA20BB55F486}"
#define Global_IID_IHOT_FormaSpiskaSprSostNom   "{75B6EF3A-F94F-4919-AF76-A6929DC69386}"

#define ProgId_HOT_FormaSpiskaSprTypePos "Oberon.HOT_FormaSpSprTypePosel.1"
#define Global_CLSID_THOT_FormaSpiskaSprTypePosImpl "{3405BCFE-BFEC-414C-9B5E-C3DA21FB926A}"
#define Global_IID_IHOT_FormaSpiskaSprTypePos "{C6F41696-D36E-47A4-90A3-1102E2390F62}"

#define ProgId_HOT_FormaTableSostNF  "Oberon.HOT_FormaSpTableSostNF.1"
#define Global_CLSID_THOT_FormaTableSostNFImpl  "{B94013A6-1194-4895-80FB-1F5AD3102330}"
#define Global_IID_IHOT_FormaTableSostNF "{803357EA-C387-44F5-82C1-DDFB846144B6}"

#define ProgId_HOT_FormaKKTOperation "Oberon.FormaKKTOperation.1"
#define Global_CLSID_THOT_FormaKKTOperationImpl "{47412707-E6D6-4703-8B27-FC8646BC5CE2}"
//#define Global_IID_IHOT_FormaKKTOperation

#define ProgId_FormaSpiskaInterfToolBar "Oberon.FormaSpiskaInterfToolBar.1"
#define Global_CLSID_TFormaSpiskaInterfToolBarImpl "{2C8F4C88-F510-4DE2-87A4-1F70C8AB3E93}"
#define Global_IID_IFormaSpiskaInterfToolBar "{4E116652-E8F4-40D5-BEF6-4218AB72E23D}"



#define ProgId_FormaOperCreditCard "Oberon.FormaOperCreditCard.1"
#define Global_CLSID_TFormaOperCreditCardImpl "{8EDAAA56-5614-44EF-B442-D0730BCBC9BB}"
//#define Global_IID_IFormaOperCreditCard

#define ProgId_FormaOperPlatCard
#define Global_CLSID_TFormaOperPlatCardImpl
#define Global_IID_IFormaOperPlatCard


#define ProgId_ObjectCheckDiscount "Kas.ObjectCheckDiscount.1"
#define Global_CLSID_TObjectCheckDiscountImpl "{79DCAEB2-7ECF-429E-B504-E8418915FBCE}"
#define Global_IID_IObjectCheckDiscount "{76D83F3D-242C-45B0-9D73-E0BFE23C655F}"




#define ProgId_REM_DMSprSostCustQuery  "Kas.REM_DMSprSostCustQuery.1"
#define Global_CLSID_TREM_DMSprSostCustQueryImpl "{C0ED7458-CBEE-4CC5-8C76-BE405296ECB9}"
#define Global_IID_IREM_DMSprSostCustQuery "{9EBD41F6-9FFE-457D-8AF6-44970B4E83D0}"

#define ProgId_REM_FormaElementaSprSostCustQuery  "Kas.REM_FormaElSprSostCustQuery.1"
#define Global_CLSID_TREM_FormaElementaSprSostCustQueryImpl "{EF0139B9-A8B5-42BE-B5D7-D1BAF9CF7637}"
#define Global_IID_IREM_FormaElementaSprSostCustQuery "{341A99EF-4525-4A92-A5D5-2058A72B4F42}"

#define ProgId_REM_FormaSpiskaSprSostCustQuery  "Kas.REM_FormaSpSprSostCustQuery.1"
#define Global_CLSID_TREM_FormaSpiskaSprSostCustQueryImpl "{9B893A15-9667-44C9-9CDE-9DF2379E5973}"
#define Global_IID_IREM_FormaSpiskaSprSostCustQuery "{D1E81C4C-6DF8-495F-B1AA-F465D84B969D}"





#define ProgId_REM_DMGurCustQuery  "Kas.REM_DMGurCustQuery.1"
#define Global_CLSID_TREM_DMGurCustQueryImpl "{FF4ADB52-965E-4D97-8756-0B65AEA1DF38}"
#define Global_IID_IREM_DMGurCustQuery "{136AF1DB-B603-492D-B46F-2246B6C74E0F}"

#define ProgId_REM_FormaGurCustQuery  "Kas.REM_FormaGurCustQuery.1"
#define Global_CLSID_TREM_FormaGurCustQueryImpl "{57B763B3-9F62-4C67-A1CD-7070573C9287}"
#define Global_IID_IREM_FormaGurCustQuery "{38611015-39F6-480C-8D89-F5C0A1CBF914}"


#define ProgId_REM_DMGurCustQueryDetal  "Kas.REM_DMGurCustQueryDetal.1"
#define Global_CLSID_TREM_DMGurCustQueryDetalImpl "{4ED6F9C5-5D02-4731-84B6-66B05BD961A8}"
#define Global_IID_IREM_DMGurCustQueryDetal "{3975AFE3-3A0E-4F03-AA13-8674239E5251}"

#define ProgId_REM_FormaGurCustQueryDetal  "Kas.REM_FormaGurCustQueryDetal.1"
#define Global_CLSID_TREM_FormaGurCustQueryDetalImpl "{9BAF01D1-BEC7-4B1F-85A5-8AD7CB32014F}"
#define Global_IID_IREM_FormaGurCustQueryDetal "{BC71211E-3331-4267-9581-949B2B47A2DF}"





#define ProgId_REM_DMCustQuery  "Kas.REM_DMCustQuery.1"
#define Global_CLSID_TREM_DMCustQueryImpl "{1D97BBC0-BE10-4D6D-B3D6-1FA08D397F97}"
#define Global_IID_IREM_DMCustQuery  "{3C4592BE-4210-4E37-B3D8-E0AE4BECA327}"

#define ProgId_REM_FormaCustQuery  "Kas.REM_FormaCustQuery.1"
#define Global_CLSID_TREM_FormaCustQueryImpl "{07E17C9F-BB6C-4F10-B9CB-07E91A1D8954}"
#define Global_IID_IREM_FormaCustQuery "{A5A4DB40-036A-4F5A-B5F6-28359F2A2EB8}"



#define ProgId_REM_DMCustQueryDv  "Kas.REM_DMCustQueryDv.1"
#define Global_CLSID_TREM_DMCustQueryDvImpl "{3263A5CC-5D2B-4713-B6E7-AF40013AC218}"
#define Global_IID_IREM_DMCustQueryDv "{86880685-8EF0-42EB-93E1-E01C6E060537}"

#define ProgId_REM_FormaCustQueryDv  "Kas.REM_FormaCustQueryDv.1"
#define Global_CLSID_TREM_FormaCustQueryDvImpl "{00355895-0776-4EE8-978F-3A3252F9A9A8}"
#define Global_IID_IREM_FormaCustQueryDv "{AFBA51D7-FEF4-4E11-9114-B9C6B83CD42B}"


#define ProgId_DMSprFactor  "Kas.DMSprFactor.1"
#define Global_CLSID_TDMSprFactorImpl "{37F7FE6C-6802-45D7-8CF9-EE82840BE694}"
#define Global_IID_IDMSprFactor "{264B47F5-61DA-4BE2-97BA-08D6F275F073}"

#define ProgId_FormaElementaSprFactor  "Kas.FormaElementaSprFactor.1"
#define Global_CLSID_TFormaElementaSprFactorImpl "{75897E17-DA9E-4B8D-885D-4BFAEB452AA7}"
#define Global_IID_IFormaElementaSprFactor "{D3B8B606-A77C-4EA1-8D08-7825C6DD8C3F}"

#define ProgId_FormaSpiskaSprFactor  "Kas.FormaSpiskaSprFactor.1"
#define Global_CLSID_TFormaSpiskaSprFactorImpl "{A06C2006-CCBC-4468-8FF3-66149161D66A}"
#define Global_IID_IFormaSpiskaSprFactor  "{2F7B63E7-868E-4A7F-AD3B-B656F870E7A1}"






#define ProgId_DMSprFactorValue  "Kas.DMSprFactorValue.1"
#define Global_CLSID_TDMSprFactorValueImpl "{8301C94A-276D-49C2-9C0D-D1A8CC8D724E}"
#define Global_IID_IDMSprFactorValue  "{00D30D2C-E777-46EF-8AE3-1B807F34A6C7}"

#define ProgId_DMSprGrpProduce  "Kas.DMSprGrpProduce.1"
#define Global_CLSID_TDMSprGrpProduceImpl "{FB8055FD-A4A3-4D47-9AF6-F00D77832D15}"
#define Global_IID_IDMSprGrpProduce  "{B3500FC9-4DEE-4AE5-A870-704C0C2D5C4A}"

#define ProgId_FormaElementaSprGrpProduce  "Kas.FormaElementaSprGrpProduce.1"
#define Global_CLSID_TFormaElementaSprGrpProduceImpl "{6B6A2401-B707-4368-A0AF-D46DCA6F90E8}"
#define Global_IID_IFormaElementaSprGrpProduce  "{55B74BF3-B3AA-4DB3-8819-D07DB544C55D}"

#define ProgId_FormaElementaSprProduce  "Kas.FormaElementaSprProduce.1"
#define Global_CLSID_TFormaElementaSprProduceImpl "{B8CAA918-6F4C-4AB6-945A-45F62171DC4C}"
#define Global_IID_IFormaElementaSprProduce "{C7969B98-9219-46CB-A97A-A758E4089F30}"

#define ProgId_FormaSpiskaSprProduce  "Kas.FormaSpiskaSprProduce.1"
#define Global_CLSID_TFormaSpiskaSprProduceImpl "{7881FA03-DFC4-4A63-A2D0-1508D0B3F633}"
#define Global_IID_IFormaSpiskaSprProduce "{C9739A1B-C8EB-4E20-98D7-9DF2B0A0A823}"


#define ProgId_DMSprProduce  "Kas.DMSprProduce.1"
#define Global_CLSID_TDMSprProduceImpl "{1C020711-2C88-4223-B702-771AF965975F}"
#define Global_IID_IDMSprProduce "{7396A59F-6332-4BD5-9369-4EA22A548069}"



#define ProgId_DMSprGrpLossFactor "Kas.DMSprGrpLossFactor.1"
#define Global_CLSID_TDMSprGrpLossFactorImpl  "{D6B2B3EA-32B2-45E5-A956-6650C54C0A07}"
#define Global_IID_IDMSprGrpLossFactor  "{67DCF652-592D-4FA6-A397-719A1EAD01CB}"

#define ProgId_FormaElementaSprGrpLossFactor "Kas.FormaElementaSprGrpLossFactor.1"
#define Global_CLSID_TFormaElementaSprGrpLossFactorImpl "{3C71568B-8A49-4120-8CAD-7815EAC0C73F}"
#define Global_IID_IFormaElementaSprGrpLossFactor "{D6146EE6-17CF-4DC2-A012-7AC867A76ED2}"

#define ProgId_FormaElementaSprLossFactor "Kas.FormaElementaSprLossFactor.1"
#define Global_CLSID_TFormaElementaSprLossFactorImpl "{C7504955-258D-4D70-9337-7C5416BD4E6C}"
#define Global_IID_IFormaElementaSprLossFactor "{C9BB3273-0029-423E-ADC6-C446879246ED}"

#define ProgId_FormaSpiskaSprLossFactor "Kas.FormaSpiskaSprLossFactor.1"
#define Global_CLSID_TFormaSpiskaSprLossFactorImpl "{0A43B8C6-9D91-4D81-A485-038583A980F6}"
#define Global_IID_IFormaSpiskaSprLossFactor "{EEE3457A-7D2D-49EC-9FA2-159964DDF842}"

#define ProgId_DMSprLossFactor "Kas.DMSprLossFactor.1"
#define Global_CLSID_TDMSprLossFactorImpl  "{CC4203A1-6A5E-4DAB-90D7-4311D726A37D}"
#define Global_IID_IDMSprLossFactor "{A5D9342E-5935-4008-90D5-E28FE80297C3}"

#define ProgId_DMSprLossFactorValue "Kas.DMSprLossFactorValue.1"
#define Global_CLSID_TDMSprLossFactorValueImpl "{E31131DC-F33E-495F-8FD4-8912293E1AD8}"
#define Global_IID_IDMSprLossFactorValue "{7B124865-6F76-4649-A758-F2BB67634DF3}"


#define ProgId_DMSprNomRest "Oberon.DMSprNomRest.1"
#define Global_CLSID_TDMSprNomRestImpl "{E4AA6A5C-748C-4C43-9BB5-8B2DE8CBE322}"
#define Global_IID_IDMSprNomRest  "{04E88D35-23CC-4C9B-9DE0-2AAEC09C63A8}"

#define ProgId_FormaSpiskaSprNomRest "Oberon.FormaSpiskaSprNomRest.1"
#define Global_CLSID_TFormaSpiskaSprNomRestImpl "{D270DF29-BDD7-49A8-A359-E2C4345ED316}"
#define Global_IID_IFormaSpiskaSprNomRest  "{22C128BC-B17D-4860-A9ED-0FAFE1C22ECE}"


#define ProgId_DMSprSostProd "Oberon.DMSprSostProd.1"
#define Global_CLSID_TDMSprSostProdImpl  "{1D1B39F1-B518-4E2B-80D4-6EA61BFFAE88}"
#define Global_IID_IDMSprSostProd "{76988DB8-BFCB-4238-A62D-D06A6A5F408F}"









#define ProgId_REM_DMDocPrihNakl  "Kas.REM_DMDocPrihNakl.1"
#define Global_CLSID_TREM_DMDocPrihNaklImpl "{1AC078EC-9D57-4EA7-8F1E-1F135658D0BC}"
#define Global_IID_IREM_DMDocPrihNakl "{689CCE33-A846-494E-BE14-DD4A2EA463D2}"

#define ProgId_REM_FormaDocPrihNakl  "Kas.REM_FormaDocPrihNakl.1"
#define Global_CLSID_TREM_FormaDocPrihNaklImpl "{4A204D37-7180-4ADD-B359-2CABAA1EFF29}"
#define Global_IID_IREM_FormaDocPrihNakl "{43FD83EA-0427-4EBA-88A6-296BA4E8C850}"


#define ProgId_REM_DMDocReal  "Kas.REM_DMDocReal.1"
#define Global_CLSID_TREM_DMDocRealImpl "{235FC59F-1293-409B-88AC-341028D62B2A}"
#define Global_IID_IREM_DMDocReal "{F5842FEB-5A72-403E-8F3A-2931EC03BAA2}"

#define ProgId_REM_FormaDocReal  "Kas.REM_FormaDocReal.1"
#define Global_CLSID_TREM_FormaDocRealImpl "{67C5FC7F-B3E2-46BF-9842-DE737F9B85E4}"
#define Global_IID_IREM_FormaDocReal "{180E7B2B-488F-4A39-AD5C-DB153A0CC095}"



#define ProgId_REM_FormaStandartReport  "Kas.REM_FormaStandartReport.1"
#define Global_CLSID_TREM_FormaStandartReportImpl "{4D8BC45D-81C7-4A75-9D16-AC917A606072}"


#define ProgId_FormaInputText "Oberon.FormaInputText.1"
#define Global_CLSID_TFormaInputTextImpl "{3686A1EF-8DAB-4CD9-B4AF-09C3A5EDCD10}"
#define Global_IID_IFormaInputText "{BAC10129-30F3-4224-858B-AB0EA9CA1638}"


//-------------------------------------------------------------------------------
//ƒÓÍÛÏÂÌÚ ¬‚Ó‰ ÓÒÚ‡ÚÍÓ‚ (–ÂÏÓÌÚ)
#define ProgId_REM_DMDocOstNom  "Kas.REM_DMDocOstNom.1"
#define Global_CLSID_TREM_DMDocOstNomImpl "{E4CCB676-2F61-4908-8C26-38CE8E2B129A}"
#define Global_IID_IREM_DMDocOstNom "{5AEAD3E5-CABE-4A83-84A1-226708F8DEAE}"

#define ProgId_REM_FormaDocOstNom  "Kas.REM_FormaDocOstNom.1"
#define Global_CLSID_TREM_FormaDocOstNomImpl  "{E0CFA0D9-388A-428E-8BC8-2BB74E767A51}"
#define Global_IID_IREM_FormaDocOstNom "{8E7BA9BB-2134-4E83-B121-396F289AE2F4}"


//-----------------------------------------------------------------------------
#define ProgId_REM_DMZayavkaImage  "Kas.REM_DMZayvkaImage.1"
#define Global_CLSID_TREM_DMZayavkaImageImpl  "{A4604915-E4AA-431A-93D8-20C24DD8CB56}"
#define Global_IID_IREM_DMZayavkaImage "{515B7631-70B0-451E-A625-05FBFE956BF1}"


#define ProgId_REM_FormaElementaZayavkaImage  "Kas.REM_FormaElZayvkaImage.1"
#define Global_CLSID_TREM_FormaElementaZayavkaImageImpl "{E5FE5508-5198-475A-AFA8-67FC936F68C5}"
#define Global_IID_IREM_FormaElementaZayavkaImage "{F4B8E8CB-761F-4827-8B25-E1EFFA235E23}"

#define ProgId_REM_FormaSpiskaZayavkaImage  "Kas.REM_FormaSpZayvkaImage.1"
#define Global_CLSID_TREM_FormaSpiskaZayavkaImageImpl  "{75EDC4ED-1240-41F0-9799-334A8E5BD68F}"
#define Global_IID_IREM_FormaSpiskaZayavkaImage "{7B751E67-7B3F-4682-80AF-0C37E43E13B3}"


//-----------------------------------------------------------------------------
#define ProgId_REM_DMDocSborkaKompl  "Kas.REM_DMDocSborkaKompl.1"
#define Global_CLSID_TREM_DMDocSborkaKomplImpl "{4710D415-A13B-49B6-A3DD-D607B0B97224}"
#define Global_IID_IREM_DMDocSborkaKompl "{559686EA-89C0-43D6-AF1E-590F43AE7B5D}"

#define ProgId_REM_FormaDocSborkaKompl  "Kas.REM_FormaDocSborkaKompl.1"
#define Global_CLSID_TREM_FormaDocSborkaKomplImpl "{F463AFB3-9C2F-457D-A504-30C264FE48BD}"
#define Global_IID_IREM_FormaDocSborkaKompl "{1A4974F4-1110-46A3-B2CE-EB12265F0C9A}"
//------------------------------------------------------------------------------

#define ProgId_DMSprInetCatalog  "Kas.DMSprInetCatalog.1"
#define Global_CLSID_TDMSprInetCatalogImpl "{14CEB72A-7EEB-40A9-A56A-9AC03D7C9653}"
#define Global_IID_IDMSprInetCatalog "{BB62D91E-9AF3-4EA1-B768-E46CDDFAFDE9}"

#define ProgId_FormaElementaSprInetCatalog  "Kas.FormaElSprInetCatalog.1"
#define Global_CLSID_TFormaElementaSprInetCatalogImpl "{AA6F449F-4DFF-4005-BE42-53CACC57251C}"
#define Global_IID_IFormaElementaSprInetCatalog "{56554A46-F2E6-4CB2-862C-996FC42B6E29}"

#define ProgId_FormaSpiskaSprInetCatalog  "Kas.FormaSpSprInetCatalog.1"
#define Global_CLSID_TFormaSpiskaSprInetCatalogImpl "{DC55BD00-3726-4D4D-9D0B-4A0948D5C0F5}"
#define Global_IID_IFormaSpiskaSprInetCatalog "{1F745F01-82C6-4854-9FE4-EC21A9DAF7C7}"

//------------------------------------------------------------------------------

#define ProgId_DMSprGrpNomInetCatalog  "Kas.DMSprGrpNomInetCatalog.1"
#define Global_CLSID_TDMSprGrpNomInetCatalogImpl "{10CAF60C-4302-4A65-98EF-2C47500E796E}"
#define Global_IID_IDMSprGrpNomInetCatalog "{FE9E03A6-1429-4B0A-9EDA-FA5BF5EE5D94}"


#define ProgId_FormaElementaSprGrpNomInetCatalog  "Kas.FormaElSprGrpNomInetCatalog.1"
#define Global_CLSID_TFormaElementaSprGrpNomInetCatalogImpl "{8EEB7BEF-9CEE-4A0C-9223-DC41035BF941}"
#define Global_IID_IFormaElementaSprGrpNomInetCatalog "{5387EBB2-9B69-4A16-96D9-794ACCDCA24D}"

#define ProgId_FormaSpiskaSprGrpNomInetCatalog  "Kas.FormaSpSprGrpNomInetCatalog.1"
#define Global_CLSID_TFormaSpiskaSprGrpNomInetCatalogImpl "{1189F6D0-1C4D-406D-875F-72D96E397B87}"
#define Global_IID_IFormaSpiskaSprGrpNomInetCatalog "{F1693A5F-B680-4984-867C-F196958E6235}"

//------------------------------------------------------------------------------

#define ProgId_DMSprNomInetCatalog  "Kas.DMSprNomInetCatalog.1"
#define Global_CLSID_TDMSprNomInetCatalogImpl "{7984C959-BD96-4AFE-82E2-02A663D368E7}"
#define Global_IID_IDMSprNomInetCatalog "{5938E0C3-7FEC-403F-8DED-1F0DA318C959}"

#define ProgId_FormaSpiskaSprNomInetCatalog  "Kas.FormaSpSprNomInetCatalog.1"
#define Global_CLSID_TFormaSpiskaSprNomInetCatalogImpl "{AB1E59C3-0ED4-4F49-B404-CD0CAE09540E}"
#define Global_IID_IFormaSpiskaSprNomInetCatalog "{7A0C1BB2-23F6-4A86-A87B-E14A616ACF0A}"

//------------------------------------------------------------------------------

#define ProgId_DMSprPropertiesGrp  "Kas.DMSprPropertiesGrp.1"
#define Global_CLSID_TDMSprPropertiesGrpImpl "{F7C1015C-9401-45F9-ADDC-525ECB05DB76}"
#define Global_IID_IDMSprPropertiesGrp "{8E8A700B-0653-468F-8ECE-0206591AD55F}"

#define ProgId_FormaElementaSprPropertiesGrp  "Kas.FormaElSprPropertiesGrp.1"
#define Global_CLSID_TFormaElementaSprPropertiesGrpImpl "{E2F31647-1E50-47AA-8FFE-E494BB7913E1}"
#define Global_IID_IFormaElementaSprPropertiesGrp "{34F3410D-378E-42CC-AD65-61380BAE455C}"
//------------------------------------------------------------------------------

#define ProgId_DMSprProperties  "Kas.DMSprProperties.1"
#define Global_CLSID_TDMSprPropertiesImpl "{E602E01F-FD17-4726-ADBA-2E2EB728796E}"
#define Global_IID_IDMSprProperties "{330B2D6D-A4BA-46B2-A651-D45061700489}"

#define ProgId_FormaElementaSprProperties  "Kas.FormaElSprProperties.1"
#define Global_CLSID_TFormaElementaSprPropertiesImpl "{2B22DE60-4E04-49A5-89C8-36DB074D1069}"
#define Global_IID_IFormaElementaSprProperties "{6FCEF771-7FDA-40D4-937E-AAA1632C9DE4}"

#define ProgId_FormaSpiskaSprProperties  "Kas.FormaSpSprProperties.1"
#define Global_CLSID_TFormaSpiskaSprPropertiesImpl "{EA7A6AA2-0E53-4E5A-8796-71292FD093B7}"
#define Global_IID_IFormaSpiskaSprProperties "{172F365A-4D5B-44F3-B7CC-D68B94D1C21C}"
//------------------------------------------------------------------------------

#define ProgId_DMSprPropertiesValuesList  "Kas.DMSprPropertiesValuesList.1"
#define Global_CLSID_TDMSprPropertiesValuesListImpl "{3222963A-DF9A-470B-98C1-5437BB9BC23B}"
#define Global_IID_IDMSprPropertiesValuesList "{A8D7E831-54D7-48D8-AEDE-1952D17795C5}"

#define ProgId_FormaElementaSprPropertiesValuesList  "Kas.FormaElSprPropertiesValuesList.1"
#define Global_CLSID_TFormaElementaSprPropertiesValuesListImpl "{B65F34E2-52D8-4E67-AD69-D7BD110A9600}"
#define Global_IID_IFormaElementaSprPropertiesValuesList "{2B1C171D-C50A-422C-A05F-E443263EB6C1}"


#define ProgId_FormaSpiskaSprPropertiesValuesList  "Kas.FormaSpSprPropertiesValuesList.1"
#define Global_CLSID_TFormaSpiskaSprPropertiesValuesListImpl "{F7D88D63-6819-4691-82A0-2B7B5B8C6FF5}"
#define Global_IID_IFormaSpiskaSprPropertiesValuesList "{3AB20549-2328-45F0-B32E-0E8721F9CF00}"

//------------------------------------------------------------------------------

#define ProgId_DMSprNomPropertiesValue  "Kas.DMSprNomPropertiesValue.1"
#define Global_CLSID_TDMSprNomPropertiesValueImpl "{C6E36C38-CA72-4CE5-ACE8-EF8ABF814B7F}"
#define Global_IID_IDMSprNomPropertiesValue  "{2956A168-30E0-4B88-8501-D72099A58390}"

#define ProgId_FormaElementaSprNomPropertiesValue  "Kas.FormaElSprNomPropertiesValue.1"
#define Global_CLSID_TFormaElementaSprNomPropertiesValueImpl "{9D66C772-8A03-4BA7-BBBB-1E0CF14086A5}"
#define Global_IID_IFormaElementaSprNomPropertiesValue "{CB6476A7-E197-403B-B399-E40C70676515}"

#define ProgId_FormaSpiskaSprNomPropertiesValue  "Kas.FormaSpSprNomPropertiesValue.1"
#define Global_CLSID_TFormaSpiskaSprNomPropertiesValueImpl "{15D42D4E-D0F3-46B4-9461-1AFBCC9A0530}"
#define Global_IID_IFormaSpiskaSprNomPropertiesValue "{A8C1008C-C3C0-4AC4-A654-38ECB60266FB}"
//------------------------------------------------------------------------------

#define ProgId_DMSprVidImageGrp  "Kas.DMSprVidImageGrp.1"
#define Global_CLSID_TDMSprVidImageGrpImpl "{B1A7C09C-829C-4F22-BCC3-A296143984E6}"
#define Global_IID_IDMSprVidImageGrp  "{75F2AF54-337E-4089-98FF-C87B8DD34710}"

#define ProgId_FormaElementaSprVidImageGrp  "Kas.FormaElSprVidImageGrp.1"
#define Global_CLSID_TFormaElementaSprVidImageGrpImpl "{1366A6E0-73B3-4706-9592-85973D31B7D2}"
#define Global_IID_IFormaElementaSprVidImageGrp "{D7C5421F-0DC0-469C-BB33-72DDCECEB14A}"


//------------------------------------------------------------------------------

#define ProgId_DMSprVidImage  "Kas.DMSprVidImage.1"
#define Global_CLSID_TDMSprVidImageImpl "{1118E988-0B44-4F05-BF9B-B26A472B23F3}"
#define Global_IID_IDMSprVidImage "{B81E9AA7-98B9-48BA-A74F-868E5124C898}"

#define ProgId_FormaElementaSprVidImage  "Kas.FormaElSprVidImage.1"
#define Global_CLSID_TFormaElementaSprVidImageImpl "{3A7A74AE-E9E4-47EF-92BD-931EBD802AB3}"
#define Global_IID_IFormaElementaSprVidImage "{E9EC2D0F-9CA9-4FB9-805A-523089C48A61}"

#define ProgId_FormaSpiskaSprVidImage  "Kas.FormaSpSprVidImage.1"
#define Global_CLSID_TFormaSpiskaSprVidImageImpl "{C2A4DDE4-12D0-44F0-9FF5-783FFC5AD674}"
#define Global_IID_IFormaSpiskaSprVidImage "{4D06B975-39DC-4195-B8D7-6F2F6348F68D}"
//------------------------------------------------------------------------------

#define ProgId_DMSprNomImage  "Kas.DMSprNomImage.1"
#define Global_CLSID_TDMSprNomImageImpl "{DBD63A33-669C-413A-9E75-791B10B6BEB4}"
#define Global_IID_IDMSprNomImage "{6F5F9400-B087-4B73-BF3C-B6BD8D8FEB14}"

#define ProgId_FormaElementaSprNomImage  "Kas.FormaElSprNomImage.1"
#define Global_CLSID_TFormaElementaSprNomImageImpl "{70D262AF-0C96-46BD-B24C-069A9F765D9F}"
#define Global_IID_IFormaElementaSprNomImage "{5F7977D3-E9DF-47D0-A0DC-0E35BCEE16F8}"


#define ProgId_FormaSpiskaSprNomImage  "Kas.FormaSpSprNomImage.1"
#define Global_CLSID_TFormaSpiskaSprNomImageImpl "{0720F4EA-C127-421C-A43A-607C3171219F}"
#define Global_IID_IFormaSpiskaSprNomImage "{CAECDBA8-83FB-4ADA-B6BA-810F079EEB25}"


//------------------------------------------------------------------------------

#define ProgId_DMSprPropertiesNabor  "Kas.DMSprPropertiesNabor.1"
#define Global_CLSID_TDMSprPropertiesNaborImpl "{7CC1AE88-651D-44EC-AB87-CBBBE01A2999}"
#define Global_IID_IDMSprPropertiesNabor "{547E5A76-8842-4899-AD05-E9D4A937FC75}"

#define ProgId_FormaElementaSprPropertiesNabor  "Kas.FormaElSprPropertiesNabor.1"
#define Global_CLSID_TFormaElementaSprPropertiesNaborImpl "{E2BBC0FB-B5D6-48F8-9C5B-D9D749803125}"
#define Global_IID_IFormaElementaSprPropertiesNabor "{A1242E01-131E-44C8-B635-B5F2A061E846}"

#define ProgId_FormaSpiskaSprPropertiesNabor  "Kas.FormaSpSprPropertiesNabor.1"
#define Global_CLSID_TFormaSpiskaSprPropertiesNaborImpl "{2A013DD8-054E-4ABB-8EBB-49211C17E5D6}"
#define Global_IID_IFormaSpiskaSprPropertiesNabor "{814EF1CA-6B98-4F9B-8D9D-28BE05D6DF57}"

//------------------------------------------------------------------------------

#define ProgId_DMSprPropertiesNaborGrp  "Kas.DMSprPropertiesNaborGrp.1"
#define Global_CLSID_TDMSprPropertiesNaborGrpImpl  "{4CD3E489-5107-4F2D-B45A-27D774FEC903}"
#define Global_IID_IDMSprPropertiesNaborGrp "{60A9862A-6512-4F56-91E2-F73E8315F1E4}"

#define ProgId_FormaElementaSprPropertiesNaborGrp  "Kas.FormaElSprPropNaborGrp.1"
#define Global_CLSID_TFormaElementaSprPropertiesNaborGrpImpl "{44C60DD9-62BF-4BAE-99F8-0C1E46E530A7}"
#define Global_IID_IFormaElementaSprPropertiesNaborGrp "{A02F0913-65D0-4A3A-911F-03B4B9FF7707}"


//------------------------------------------------------------------------------

#define ProgId_DMSprPropertiesNaborSostav  "Kas.DMSprPropertiesNaborSostav.1"
#define Global_CLSID_TDMSprPropertiesNaborSostavImpl "{1763E492-7A9C-45F8-A61F-81B1012CF187}"
#define Global_IID_IDMSprPropertiesNaborSostav "{3F36E27D-D69D-4623-9F39-7ECD54423834}"

#define ProgId_FormaElementaSprPropertiesNaborSostav  "Kas.FormaElSprPropNaborSost.1"
#define Global_CLSID_TFormaElementaSprPropertiesNaborSostavImpl "{C625EC5A-2530-4BE4-A3C7-825D0747BE7C}"
#define Global_IID_IFormaElementaSprPropertiesNaborSostav "{7C2F534C-DA61-4744-A055-367BAE84B0D2}"

#define ProgId_FormaSpiskaSprPropertiesNaborSostav  "Kas.FormaSpSprPropNaborSost.1"
#define Global_CLSID_TFormaSpiskaSprPropertiesNaborSostavImpl "{EA038445-E92A-4631-8B10-7C5F8ED99D3B}"
#define Global_IID_IFormaSpiskaSprPropertiesNaborSostav "{27743FEF-6F04-49E6-9FF1-394D17C73543}"
//------------------------------------------------------------------------------

#define ProgId_REM_DMDocPostOtDilera  "Kas.REM_DMDocPostOtDilera.1"
#define Global_CLSID_TREM_DMDocPostOtDileraImpl "{29C8E422-396B-4FF2-A99A-7967AFC2F3F1}"
#define Global_IID_IREM_DMDocPostOtDilera "{8129DCEE-C39F-4AFF-A287-E57963A38E52}"

#define ProgId_REM_FormaDocPostOtDilera  "Kas.REM_FormaDocPostOtDilera.1"
#define Global_CLSID_TREM_FormaDocPostOtDileraImpl "{A96FB0D6-A7A2-4202-B518-974D3A486290}"
#define Global_IID_IREM_FormaDocPostOtDilera "{2ACA4D90-FC24-4116-81B4-8B758B80A85A}"

//------------------------------------------------------------------------------

#define ProgId_REM_DMDocVosvratDileru  "Kas.REM_DMDocVosvratDileru.1"
#define Global_CLSID_TREM_DMDocVosvratDileruImpl "{6F29E25F-59A9-4DD4-8624-01CF1318D405}"
#define Global_IID_IREM_DMDocVosvratDileru "{0EAA1AB1-A0A9-4B2C-A61E-1784DDC04943}"

#define ProgId_REM_FormaDocVosvratDileru  "Kas.REM_FormaDocVosvratDileru.1"
#define Global_CLSID_TREM_FormaDocVosvratDileruImpl "{B96564DE-3543-4C4A-BE2D-754B5B2CDFCE}"
#define Global_IID_IREM_FormaDocVosvratDileru "{C3515659-AA2F-490B-84E7-62B766E7FB93}"

//------------------------------------------------------------------------------

#define ProgId_REM_DMDocPerServCentr  "Kas.REM_DMDocPerServCentr.1"
#define Global_CLSID_TREM_DMDocPerServCentrImpl "{4C57F9FA-5A7E-49FA-88E8-1955165FACF0}"
#define Global_IID_IREM_DMDocPerServCentr "{BC6539BA-D656-4A9C-BFC2-53BFB5B3647A}"

#define ProgId_REM_FormaDocPerServCentr  "Kas.REM_FormaDocPerServCentr.1"
#define Global_CLSID_TREM_FormaDocPerServCentrImpl "{D7AE1D4A-7545-43D0-8D34-E4E7D5DB95F0}"
#define Global_IID_IREM_FormaDocPerServCentr  "{3CDCF932-DF6B-4E56-9BD4-01B4572EC35C}"


//------------------------------------------------------------------------------

#define ProgId_REM_DMDocVosvratIsSC  "Kas.REM_DMDocVosvratIsSC.1"
#define Global_CLSID_TREM_DMDocVosvratIsSCImpl "{19C2E546-066B-4B09-9824-E150A1AB77CF}"
#define Global_IID_IREM_DMDocVosvratIsSC  "{8A3F7EDA-EDBA-4E13-A77A-F36319EF0C83}"

#define ProgId_REM_FormaDocVosvratIsSC  "Kas.REM_FormaDocVosvratIsSC.1"
#define Global_CLSID_TREM_FormaDocVosvratIsSCImpl "{2908AFEE-641F-41FE-B639-D5DCE2F8E8FB}"
#define Global_IID_IREM_FormaDocVosvratIsSC "{D8CABE5B-0F8A-471C-930C-FF09521CC8A3}"


//------------------------------------------------------------------------------
#define ProgId_REM_DMDocVosvratPok  "Kas.REM_DMDocVosvratPok.1"
#define Global_CLSID_TREM_DMDocVosvratPokImpl "{4C10CF81-AF19-4ABD-A98D-05F0BFB35722}"
#define Global_IID_IREM_DMDocVosvratPok "{EC1EAD5A-ED59-4250-B293-ADD155B2AA62}"

#define ProgId_REM_FormaDocVosvratPok  "Kas.REM_FormaDocVosvratPok.1"
#define Global_CLSID_TREM_FormaDocVosvratPokImpl "{66A18438-9BDF-451F-BB0D-D0F33251B563}"
#define Global_IID_IREM_FormaDocVosvratPok  "{B21B06A0-2B7C-468B-948B-304D8E7D57CA}"
//-------------------------------------------------------------------------------




#define ProgId_REM_DMDocAkt  "Kas.REM_DMDocAkt.1"
#define Global_CLSID_TREM_DMDocAktImpl "{BC871D67-0400-49C2-8954-8B7EBEFB6676}"
#define Global_IID_IREM_DMDocAkt "{B9168E30-0F57-47B3-BD0D-B774E50DAA75}"

#define ProgId_REM_FormaDocAkt  "Kas.REM_FormaDocAkt.1"
#define Global_CLSID_TREM_FormaDocAktImpl "{061AC534-95BB-4C28-82FB-63635F6BFE61}"
#define Global_IID_IREM_FormaDocAkt "{33D9EBCA-35B2-4754-81D2-19B7DDC39DC8}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocPer  "Kas.REM_DMDocPer.1"
#define Global_CLSID_TREM_DMDocPerImpl "{E4251EE3-4174-4B65-8E5E-3B2E4D6DC2A9}"
#define Global_IID_IREM_DMDocPer "{3FCD2EBF-2368-4EB5-9A40-10B3516F0275}"

#define ProgId_REM_FormaDocPer  "Kas.REM_FormaDocPer.1"
#define Global_CLSID_TREM_FormaDocPerImpl "{545D8BCD-3A0D-4938-8644-D6FE1951AB8C}"
#define Global_IID_IREM_FormaDocPer "{47F29580-EE88-445E-8D12-CB60E20D03D8}"
//-------------------------------------------------------------------------------

#define ProgId_ClassCopyDoc  "Kas.ClassCopyDoc.1"
#define Global_CLSID_TClassCopyDocImpl "{EE7CA149-651A-41E2-8593-029CFC4DF815}"
#define Global_IID_IClassCopyDoc "{8E661591-116B-4945-B1AA-00E8A1011B27}"


//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZPost  "Kas.REM_DMDocZPost.1"
#define Global_CLSID_TREM_DMDocZPostImpl "{38B1238E-2119-4F5E-8400-8C972AE3A72B}"
#define Global_IID_IREM_DMDocZPost "{BFC389A3-F459-483B-A289-18BB242C0B17}"

#define ProgId_REM_FormaDocZPost  "Kas.REM_FormaDocZPost.1"
#define Global_CLSID_TREM_FormaDocZPostImpl "{FD28CAC8-702E-43D5-B591-0445134D5DC5}"
#define Global_IID_IREM_FormaDocZPost "{44E114A3-215A-4E33-9C1E-626ECCEC6235}"
//-------------------------------------------------------------------------------
#define ProgId_REM_DMDocZVid "Kas.REM_DMDocZVid.1"
#define Global_CLSID_TREM_DMDocZVidImpl "{8A065949-2D6C-4A74-8539-85F760F0CE05}"
#define Global_IID_IREM_DMDocZVid "{268F31D3-CBB5-4469-AEFB-44F4C8D9C429}"

#define ProgId_REM_FormaDocZVid  "Kas.REM_FormaDocZVid.1"
#define Global_CLSID_TREM_FormaDocZVidImpl "{659CA306-49E8-4010-A488-6E399EB289AC}"
#define Global_IID_IREM_FormaDocZVid "{897F1C0A-9854-4692-9CF9-5D0398665BF0}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZPer  "Kas.REM_DMDocZPer.1"
#define Global_CLSID_TREM_DMDocZPerImpl "{B57DE43F-32DB-49D8-AAA1-68CE3855D15C}"
#define Global_IID_IREM_DMDocZPer "{AD7F04EA-3C0F-499D-8AE3-B79D149CD895}"

#define ProgId_REM_FormaDocZPer  "Kas.REM_FormaDocZPer.1"
#define Global_CLSID_TREM_FormaDocZPerImpl "{44B9DD69-593A-4BD7-9A3B-7B5299B6FBF7}"
#define Global_IID_IREM_FormaDocZPer "{EBE815B4-A18D-4204-9991-767D834F6EA6}"
//-------------------------------------------------------------------------------
#define ProgId_REM_DMDocZStart "Kas.REM_DMDocZStart.1"
#define Global_CLSID_TREM_DMDocZStartImpl "{686D286A-D164-4FAE-83D9-948AFEB7CCDC}"
#define Global_IID_IREM_DMDocZStart "{101EEB79-1903-4459-B585-57E408608005}"

#define ProgId_REM_FormaDocZStart  "Kas.REM_FormaDocZStart.1"
#define Global_CLSID_TREM_FormaDocZStartImpl "{838F9125-2910-4710-9ECB-1F98427ED72E}"
#define Global_IID_IREM_FormaDocZStart  "{EFA34348-0032-4D92-852F-D2C9A0B56414}"
//-------------------------------------------------------------------------------
#define ProgId_REM_DMDocZEnd "Kas.REM_DMDocZEnd.1"
#define Global_CLSID_TREM_DMDocZEndImpl "{83D0AEC9-11B4-42EF-9445-B14B8A4F6E80}"
#define Global_IID_IREM_DMDocZEnd "{FB71475D-951C-4985-8B4C-5F08ECA9807F}"

#define ProgId_REM_FormaDocZEnd  "Kas.REM_FormaDocZEnd.1"
#define Global_CLSID_TREM_FormaDocZEndImpl "{99573D40-9781-4B56-AC6D-401F9F99C4CB}"
#define Global_IID_IREM_FormaDocZEnd "{9D0EC6AB-3561-43CE-9DDA-5459129DCB88}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZOper "Kas.REM_DMDocZOper.1"
#define Global_CLSID_TREM_DMDocZOperImpl "{7BDC84E6-17F3-45AA-AD8E-8A960C478178}"
#define Global_IID_IREM_DMDocZOper "{62F9968B-6CF3-4AF3-857B-42023FA4DD23}"

#define ProgId_REM_FormaDocZOper  "Kas.REM_FormaDocZOper.1"
#define Global_CLSID_TREM_FormaDocZOperImpl "{BBE17385-ED0E-48B1-B5F6-808983B9A665}"
#define Global_IID_IREM_FormaDocZOper "{A679482A-F061-42E0-9D92-D719DD461B38}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZTreb "Kas.REM_DMDocZTreb.1"
#define Global_CLSID_TREM_DMDocZTrebImpl "{535D7D53-9950-47B5-A7C6-BEBBFC3F442C}"
#define Global_IID_IREM_DMDocZTreb "{D6C814EE-AFBE-4BB9-8039-641C81FEB9D1}"

#define ProgId_REM_FormaDocZTreb  "Kas.REM_FormaDocZTreb.1"
#define Global_CLSID_TREM_FormaDocZTrebImpl "{5AD6AF28-A29E-4AA4-BF4D-2AA354259F5A}"
#define Global_IID_IREM_FormaDocZTreb "{8B3DBD19-527E-424E-94DB-F637FCDA05A7}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZAktPr "Kas.REM_DMDocZAktPr.1"
#define Global_CLSID_TREM_DMDocZAktPrImpl "{F4BA4032-B467-48C1-AC25-FA8EE1145393}"
#define Global_IID_IREM_DMDocZAktPr "{AB556F2F-3ECB-4330-8016-2A24060CB293}"

#define ProgId_REM_FormaDocZAktPr  "Kas.REM_FormaDocZAktPr.1"
#define Global_CLSID_TREM_FormaDocZAktPrImpl "{7A9321E1-6215-4B05-B145-77694DBFEACB}"
#define Global_IID_IREM_FormaDocZAktPr "{F499C056-8591-4ED3-A870-038D75C26563}"
//-------------------------------------------------------------------------------

#define ProgId_REM_DMDocZVosvrZap "Kas.REM_DMDocZVosvrZap.1"
#define Global_CLSID_TREM_DMDocZVosvrZapImpl "{9B9F7969-63F7-4CD4-8939-CF1D9EFBCD16}"
#define Global_IID_IREM_DMDocZVosvrZap "{7F94522C-4F22-49BF-B338-7F5680351A7B}"

#define ProgId_REM_FormaDocZVosvrZap  "Kas.REM_FormaDocZVosvrZap.1"
#define Global_CLSID_TREM_FormaDocZVosvrZapImpl "{45EEC13F-C856-4AE0-9F5F-30EE2DF8C0EE}"
#define Global_IID_IREM_FormaDocZVosvrZap "{3C8E86A3-DFBB-46DA-9A18-B2403E545115}"
//-------------------------------------------------------------------------------


#define ProgId_REM_DMDocSpisNom "Kas.REM_DMDocSpisNom.1"
#define Global_CLSID_TREM_DMDocSpisNomImpl "{3D235146-4B72-4C19-8426-B9C4EEDA3313}"
#define Global_IID_IREM_DMDocSpisNom "{6CA4BDA5-E8B0-412E-B667-92705DC94F83}"

#define ProgId_REM_FormaDocSpisNom  "Kas.REM_FormaDocSpisNom.1"
#define Global_CLSID_TREM_FormaDocSpisNomImpl "{96988CAD-94CA-43AF-9A1F-E23DA22B47A0}"
#define Global_IID_IREM_FormaDocSpisNom "{9BA24ACE-30FB-4701-AEE6-870FAA52C76C}"
//-------------------------------------------------------------------------------

#define ProgId_SR_FormaOstatkiTovarov  "Kas.SR_FormaOstatkiTovarov.1"
#define Global_CLSID_TSR_FormaOstatkiTovarovImpl "{26B0437B-6A04-4B33-AC94-39AB36DBCC35}"
#define Global_IID_ISR_FormaOstatkiTovarov "{7A93CC5C-B3E1-4D58-BD06-5C3493DAB1BB}"
//-------------------------------------------------------------------------------

#define ProgId_REM_FormaReportKartTovara  "Kas.REM_FormaReportKartTovara.1"
#define Global_CLSID_TREM_FormaReportKartTovaraImpl "{E21DF16B-F610-4674-989A-E93C77FAB195}"
#define Global_IID_IREM_FormaReportKartTovara "{4C56B2C0-C9F5-453F-AF00-E4DC4F0E4FFF}"
//-------------------------------------------------------------------------------


#define ProgId_DMSprTypeNachisl  "Kas.DMSprTypeNachisl.1"
#define Global_CLSID_TDMSprTypeNachislImpl "{FA62F0E0-455F-4853-A823-93D7E6041E26}"
#define Global_IID_IDMSprTypeNachisl "{AF9A13AD-6918-4D30-A240-509505A70B3A}"

#define ProgId_FormaElementaSprTypeNachisl  "Kas.FormaElementaSprTypeNachisl.1"
#define Global_CLSID_TFormaElementaSprTypeNachislImpl "{78FFA893-7A95-4733-8911-B9718BCD7C33}"
#define Global_IID_IFormaElementaSprTypeNachisl "{EDB8E661-D045-4768-A050-44AD7C9C051F}"

#define ProgId_FormaSpiskaSprTypeNachisl  "Kas.FormaSpiskaSprTypeNachisl.1"
#define Global_CLSID_TFormaSpiskaSprTypeNachislImpl "{27D124FF-3968-417E-BDAE-B9DA39DD1FB3}"
#define Global_IID_IFormaSpiskaSprTypeNachisl "{3C7D2969-720F-4538-94FF-EC7D3C7B54C8}"

//----------------------------------------------------------------------------

#define ProgId_DMSprNachisl  "Kas.DMSprNachisl.1"
#define Global_CLSID_TDMSprNachislImpl "{C7E00D61-3F99-49C2-9BBE-6293FCFEB2F2}"
#define Global_IID_IDMSprNachisl "{7CA94181-D8EA-4811-B7D5-46637485EABC}"

#define ProgId_FormaElementaSprNachisl  "Kas.FormaElementaSprNachisl.1"
#define Global_CLSID_TFormaElementaSprNachislImpl "{00CFA85F-724A-4759-8F2A-C210CD00AE42}"
#define Global_IID_IFormaElementaSprNachisl "{A3F9DF74-DE36-4A0B-A132-2BAC27365890}"

#define ProgId_FormaSpiskaSprNachisl  "Kas.FormaSpiskaSprNachisl.1"
#define Global_CLSID_TFormaSpiskaSprNachislImpl "{BB80541C-9EF3-4DBD-BF95-96D70A398DAC}"
#define Global_IID_IFormaSpiskaSprNachisl "{7AFDEB43-1A31-49B9-87BB-DB90B991DBCD}"

//----------------------------------------------------------------------------

#define ProgId_DMSprProducerNomGrp  "Kas.DMSprProducerNomGrp.1"
#define Global_CLSID_TDMSprProducerNomGrpImpl "{36ECE8AD-8101-4FA5-ADD3-617CAE424314}"
#define Global_IID_IDMSprProducerNomGrp "{5A5A3E70-DF04-4DC1-BDBB-C787E7E951AD}"

#define ProgId_FormaElementaSprProducerNomGrp  "Kas.FormaElementaSprProducerNomGrp.1"
#define Global_CLSID_TFormaElementaSprProducerNomGrpImpl "{5149EB2A-FC34-468F-9546-56794A62C632}"
#define Global_IID_IFormaElementaSprProducerNomGrp "{0ADB889F-438D-4C06-9B90-019AF818F989}"

//----------------------------------------------------------------------------


#define ProgId_DMSprProducerNom  "Kas.DMSprProducerNom.1"
#define Global_CLSID_TDMSprProducerNomImpl "{58E76206-FD74-4AD0-99A0-9DF786CF5386}"
#define Global_IID_IDMSprProducerNom "{4A5C6A91-4C4A-4ED3-AFC0-CACDD2AA1220}"

#define ProgId_FormaElementaSprProducerNom  "Kas.FormaElementaSprProducerNom.1"
#define Global_CLSID_TFormaElementaSprProducerNomImpl "{E9460DE5-827C-4B55-87E9-CE7358328451}"
#define Global_IID_IFormaElementaSprProducerNom "{2F7ADD07-7A60-4C09-AA74-16370F3ABD30}"

#define ProgId_FormaSpiskaSprProducerNom  "Kas.FormaSpiskaSprProducerNom.1"
#define Global_CLSID_TFormaSpiskaSprProducerNomImpl "{9843D4B9-02EE-42DD-BDEF-0DE4210C3C75}"
#define Global_IID_IFormaSpiskaSprProducerNom "{EDF8FF4C-3D4F-4BC6-A68B-981CA48EB434}"

//----------------------------------------------------------------------------


#define ProgId_DMSprProducerPrice  "Kas.DMSprProducerPrice.1"
#define Global_CLSID_TDMSprProducerPriceImpl "{9DD286B0-798C-4F10-B297-4411505BE45E}"
#define Global_IID_IDMSprProducerPrice "{EC8EA73F-1579-40C6-9D72-17567847C7C6}"

#define ProgId_FormaElementaSprProducerPrice  "Kas.FormaElementaSprProducerPrice.1"
#define Global_CLSID_TFormaElementaSprProducerPriceImpl "{F5A25D50-ADC1-46B1-8E5D-2E5728F8D044}"
#define Global_IID_IFormaElementaSprProducerPrice "{F507684F-38FC-4171-BEB3-654855D988EE}"

#define ProgId_FormaSpiskaSprProducerPrice  "Kas.FormaSpiskaSprProducerPrice.1"
#define Global_CLSID_TFormaSpiskaSprProducerPriceImpl  "{AAF8631B-AAF4-4E72-97E0-9A19C8251CCB}"
#define Global_IID_IFormaSpiskaSprProducerPrice "{EF8A04A7-C51B-490B-BB64-E36DB61EFBAB}"


//----------------------------------------------------------------------------

#define ProgId_DMSprProducerEd  "Kas.DMSprProducerEd.1"
#define Global_CLSID_TDMSprProducerEdImpl "{31EA6AF7-75D0-432B-8659-7ED0D26675D6}"
#define Global_IID_IDMSprProducerEd "{CDB0B671-C576-4824-8609-B7CBDB0071E4}"

#define ProgId_FormaElementaSprProducerEd  "Kas.FormaElementaSprProducerEd.1"
#define Global_CLSID_TFormaElementaSprProducerEdImpl "{778458FB-E2E8-4554-A7BD-F0093709E093}"
#define Global_IID_IFormaElementaSprProducerEd "{A782C036-8503-41B7-A9A0-6BF2D7C7848B}"

#define ProgId_FormaSpiskaSprProducerEd  "Kas.FormaSpiskaSprProducerEd.1"
#define Global_CLSID_TFormaSpiskaSprProducerEdImpl "{86DE77DB-9229-461A-8425-68656264985B}"
#define Global_IID_IFormaSpiskaSprProducerEd "{238E699E-513F-4BCC-BDCE-19E280B7C4FF}"

//----------------------------------------------------------------------------


#define ProgId_REM_DMSprProducerModelGrp  "Kas.REM_DMSprProducerModelGrp.1"
#define Global_CLSID_TREM_DMSprProducerModelGrpImpl "{D7C20A0C-8A99-43D3-9B56-24C3592B5058}"
#define Global_IID_IREM_DMSprProducerModelGrp "{C9651FAA-A16B-41B8-BD6F-3BE1D39CF4F0}"

#define ProgId_REM_FormaElementaSprProducerModelGrp  "Kas.REM_FormaElSprProducerModelGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerModelGrpImpl "{76ADAE5C-8852-49DB-ABBC-0D9FEE1B07EB}"
#define Global_IID_IREM_FormaElementaSprProducerModelGrp "{3AAC3C4D-CA38-43AD-9AFE-807B7803E113}"



//----------------------------------------------------------------------------

#define ProgId_REM_DMSprProducerModel  "Kas.REM_DMSprProducerModel.1"
#define Global_CLSID_TREM_DMSprProducerModelImpl "{1A6627A9-B188-4DE2-BE76-81F6E3DF9C21}"
#define Global_IID_IREM_DMSprProducerModel "{39D77E67-7350-4DCC-8C95-0CFC4F56264A}"

#define ProgId_REM_FormaElementaSprProducerModel  "Kas.REM_FormaElSprProducerModel.1"
#define Global_CLSID_TREM_FormaElementaSprProducerModelImpl "{2F4DC614-11A7-4259-B65A-9E0756E4B00F}"
#define Global_IID_IREM_FormaElementaSprProducerModel "{9F03AC9E-7609-4CD7-A2BD-CAB681C78311}"

#define ProgId_REM_FormaSpiskaSprProducerModel  "Kas.REM_FormaSpSprProducerModel.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerModelImpl "{B2B36285-8EAF-40D0-8EBA-9F93DF35CE9B}"
#define Global_IID_IREM_FormaSpiskaSprProducerModel "{D1E75EC8-0F56-468C-BCCA-286A75088160}"
//----------------------------------------------------------------------------

#define ProgId_REM_DMSprProducerNeisprGrp  "Kas.REM_DMSprProducerNeisprGrp.1"
#define Global_CLSID_TREM_DMSprProducerNeisprGrpImpl "{8EDE3DF1-8104-4885-AD55-0960F17E7EF0}"
#define Global_IID_IREM_DMSprProducerNeisprGrp "{5D451588-9EAA-4693-8E85-CD0BF0EA7D3D}"

#define ProgId_REM_FormaElementaSprProducerNeisprGrp  "Kas.REM_FormaElSprProducerNeisprGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerNeisprGrpImpl "{0D09B966-8E74-43D0-ABBF-825C11D615B4}"
#define Global_IID_IREM_FormaElementaSprProducerNeisprGrp "{B943C278-ABC4-467E-A8AC-4E93C4F864EA}"

//----------------------------------------------------------------------------


#define ProgId_REM_DMSprProducerNeispr  "Kas.REM_DMSprProducerNeispr.1"
#define Global_CLSID_TREM_DMSprProducerNeisprImpl  "{BC7973AE-B409-4038-B0F6-20B40FE7786E}"
#define Global_IID_IREM_DMSprProducerNeispr "{1C26106A-125D-49DC-AD98-3D42F5F49F67}"

#define ProgId_REM_FormaElementaSprProducerNeispr  "Kas.REM_FormaElSprProducerNeispr.1"
#define Global_CLSID_TREM_FormaElementaSprProducerNeisprImpl "{47103F91-C560-4255-8DC8-FB0479B969C2}"
#define Global_IID_IREM_FormaElementaSprProducerNeispr "{4E7B414D-C87D-483F-BF32-7BA85FB4199C}"

#define ProgId_REM_FormaSpiskaSprProducerNeispr  "Kas.REM_FormaSpSprProducerNeispr.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerNeisprImpl "{F2116828-D4D8-437C-BC51-6458FC8503FD}"
#define Global_IID_IREM_FormaSpiskaSprProducerNeispr "{390330F8-67CA-4972-8552-A5F94E919DE5}"

//----------------------------------------------------------------------------
#define ProgId_DMSprProducerTypePrice  "Kas.DMSprProducerTypePrice.1"
#define Global_CLSID_TDMSprProducerTypePriceImpl  "{E20B52BF-DFBF-4F80-8253-1A70287AAA29}"
#define Global_IID_IDMSprProducerTypePrice "{919B9B63-8B88-49CC-B93C-FF480F6148A3}"

#define ProgId_FormaElementaSprProducerTypePrice  "Kas.FormaElSprProducerTypePrice.1"
#define Global_CLSID_TFormaElementaSprProducerTypePriceImpl "{EE0040FD-EAFA-4DE9-BBDD-BC0154C646D0}"
#define Global_IID_IFormaElementaSprProducerTypePrice "{66897A34-AFA0-47DD-AFB0-200F621C4E00}"

#define ProgId_FormaSpiskaSprProducerTypePrice  "Kas.FormaSpSprProducerTypePrice.1"
#define Global_CLSID_TFormaSpiskaSprProducerTypePriceImpl "{5A96C7AC-7053-4959-A148-E427EEECD6AE}"
#define Global_IID_IFormaSpiskaSprProducerTypePrice  "{EAE6864E-A484-40FE-9CE9-BFAB29C2B8A3}"

//----------------------------------------------------------------------------
#define ProgId_DMSprProducer  "Kas.DMSprProducer.1"
#define Global_CLSID_TDMSprProducerImpl "{B340B0EB-06A8-499D-BFA2-68F6FFE179F8}"
#define Global_IID_IDMSprProducer "{BC66EC43-B102-4636-9122-E2369D7AAADC}"

#define ProgId_FormaElementaSprProducer  "Kas.FormaElementaSprProducer.1"
#define Global_CLSID_TFormaElementaSprProducerImpl "{A12C542B-EDD5-4CA9-A8F6-9F6ED6134F8E}"
#define Global_IID_IFormaElementaSprProducer "{72A5B4BD-0B9D-4286-9BED-3BE16B29D4BF}"

#define ProgId_FormaSpiskaSprProducer  "Kas.FormaSpiskaSprProducer.1"
#define Global_CLSID_TFormaSpiskaSprProducerImpl "{D7EB43FD-C06C-4B06-838F-F101528A68CE}"
#define Global_IID_IFormaSpiskaSprProducer "{67FF3D34-0355-48D6-9157-A596773C987E}"

//-----------------------------------------------------------------------------


#define ProgId_FormaImageEditor  "Kas.FormaImageEditor.1"
#define Global_CLSID_TFormaImageEditorImpl "{453CF1E2-D659-4FE2-9375-7A7468F207C7}"
#define Global_IID_IFormaImageEditor "{E51DB8C5-784A-4CEF-A0DF-2A21072709D4}"

//-----------------------------------------------------------------------------


#define ProgId_REM_DMDocKM1 "Oberon.REM_DMDocKM1.1"
#define Global_CLSID_TREM_DMDocKM1Impl "{F786F567-A6E6-45CA-9948-4A955E285CD5}"
#define Global_IID_IREM_DMDocKM1  "{3ABBF1E6-2941-4428-8330-A88710019BD2}"

//-----------------------------------------------------------------------------


#define ProgId_REM_DMDocKM2 "Oberon.REM_DMDocKM2.1"
#define Global_CLSID_TREM_DMDocKM2Impl "{AB03C615-1C3E-4965-8D69-07805CB9F665}"
#define Global_IID_IREM_DMDocKM2  "{D9FFA9DE-BC85-4C2B-8F50-C17D075FB916}"

//-----------------------------------------------------------------------------


#define ProgId_REM_DMDocRemontKKT "Oberon.REM_DMDocRemontKKT.1"
#define Global_CLSID_TREM_DMDocRemontKKTImpl "{19A1CA68-E7AA-416B-B678-8E09D3A12967}"
#define Global_IID_IREM_DMDocRemontKKT "{09279C20-35A9-45B2-84E3-F764532622DE}"

//-----------------------------------------------------------------------------


#define ProgId_REM_DMDocSetServHW "Oberon.REM_DMDocSetServHW.1"
#define Global_CLSID_TREM_DMDocSetServHWImpl "{C55578CA-7655-46D0-811F-2AB45A6499B3}"
#define Global_IID_IREM_DMDocSetServHW  "{C7FE782E-2E65-4323-ADDB-5C1A83EACA0F}"


//-----------------------------------------------------------------------------


#define ProgId_REM_DMDocSetServKKT "Oberon.REM_DMDocSetServKKT.1"
#define Global_CLSID_TREM_DMDocSetServKKTImpl "{E291C3D1-6CDB-492C-9CF3-BA212E7708DD}"
#define Global_IID_IREM_DMDocSetServKKT "{F8CFF953-172F-4F93-A7EC-5E1D8F1BF0A5}"



//-----------------------------------------------------------------------------


#define ProgId_DMProgramSetup "Kas.DMProgramSetup.1"
#define Global_CLSID_TDMProgramSetupImpl "{6E976096-B673-476A-9F7D-FC13FEB25423}"
#define Global_IID_IDMProgramSetup "{E840699B-107D-4B0D-9DB9-9CEFCEEFE3A8}"

//----------------------------------------------------------------------------
#define ProgId_REM_DMSprGrpTypUslov  "Kas.REM_DMSprGrpTypUslov.1"
#define Global_CLSID_TREM_DMSprGrpTypUslovImpl "{8BCA91BC-399D-47FB-9A67-A82C9CF7AB70}"
#define Global_IID_IREM_DMSprGrpTypUslov "{3E3BCD09-36DF-436E-A640-74727AA1D33D}"


#define ProgId_REM_DMSprTypUslov  "Kas.REM_DMSprTypUslov.1"
#define Global_CLSID_TREM_DMSprTypUslovImpl "{90A7AC23-5071-4AD8-970A-6E8DB212BF4C}"
#define Global_IID_IREM_DMSprTypUslov "{1B58A049-4FE8-44C0-9B90-ABC7E35F122B}"

#define ProgId_REM_FormaElementaSprTypUslovGrp  "Kas.REM_FormaElementaSprTypUslovGrp.1"
#define Global_CLSID_TREM_FormaElementaSprTypUslovGrpImpl "{8F8FA1C1-8B70-4525-A832-FB3DBA460030}"
#define Global_IID_IREM_FormaElementaSprTypUslovGrp "{FF56BB97-D502-46F4-8FB4-D61DA754E151}"

#define ProgId_REM_FormaElementaSprTypUslov  "Kas.REM_FormaElementaSprTypUslov.1"
#define Global_CLSID_TREM_FormaElementaSprTypUslovImpl "{4B9916C5-FED5-4BA2-A0F4-5037D4F8F1B0}"
#define Global_IID_IREM_FormaElementaSprTypUslov "{34F90AED-3DC1-430C-8199-39A1EE3F4539}"

#define ProgId_REM_FormaSpiskaSprTypUslov  "Kas.REM_FormaSpiskaSprTypUslov.1"
#define Global_CLSID_TREM_FormaSpiskaSprTypUslovImpl "{BBD81587-54F2-41F9-9C90-85B3CBC938DB}"
#define Global_IID_IREM_FormaSpiskaSprTypUslov  "{259A7AE5-6E7D-4B99-A9BF-5DD3BD31E7B4}"


#define ProgId_REM_DMSprKomplModel  "Kas.REM_DMSprKomplModel.1"
#define Global_CLSID_TREM_DMSprKomplModelImpl "{AAA5F853-9D0D-4F38-8D7D-9354A332C88F}"
#define Global_IID_IREM_DMSprKomplModel "{BC4A3553-CBD5-4623-8F77-BE7A7B524E2F}"



#define ProgId_REM_DMSprGrpTypDefect  "Kas.REM_DMSprGrpTypDefect.1"
#define Global_CLSID_TREM_DMSprGrpTypDefectImpl "{A5186558-3393-49DB-A8C9-8FC376A298E9}"
#define Global_IID_IREM_DMSprGrpTypDefect "{1FAA0E89-2F86-41A6-A8FC-3AD7C5C2C914}"

#define ProgId_REM_FormaElementaSprTypDefectGrp  "Kas.REM_FormaElementaSprTypDefectGrp.1"
#define Global_CLSID_TREM_FormaElementaSprTypDefectGrpImpl "{416B7A98-3D34-4754-A50B-94311F0B5586}"
#define Global_IID_IREM_FormaElementaSprTypDefectGrp "{BE12C0D8-31E0-4ED7-9F63-3A597C99EDC8}"



#define ProgId_REM_DMSprTypDefect  "Kas.REM_DMSprTypDefect.1"
#define Global_CLSID_TREM_DMSprTypDefectImpl "{01A754F6-B8D9-49E4-95ED-5593322E9E54}"
#define Global_IID_IREM_DMSprTypDefect "{6971D212-CAFA-4ECC-9DAE-41B4A640880B}"


#define ProgId_REM_FormaElementaSprTypDefect  "Kas.REM_FormaElementaSprTypDefect.1"
#define Global_CLSID_TREM_FormaElementaSprTypDefectImpl "{43E9A549-7F1D-414D-BAEF-CF5853E7703A}"
#define Global_IID_IREM_FormaElementaSprTypDefect "{ABA12A20-4B65-4EC9-B326-99AF7D880F0A}"


#define ProgId_REM_FormaSpiskaSprTypDefect  "Kas.REM_FormaSpiskaSprTypDefect.1"
#define Global_CLSID_TREM_FormaSpiskaSprTypDefectImpl "{E3311ADA-5ADA-4F83-853E-0D8DC5B7DF14}"
#define Global_IID_IREM_FormaSpiskaSprTypDefect "{A59BDEBE-5C4E-41FC-A1E5-F91D8C69BB35}"

#define ProgId_REM_DMSprGrpTypRabot  "Kas.REM_DMSprGrpTypRabot.1"
#define Global_CLSID_TREM_DMSprGrpTypRabotImpl "{A5ADC073-A3FF-48BD-8128-3D5BCAFD6040}"
#define Global_IID_IREM_DMSprGrpTypRabot "{A2876BB8-FA27-4822-AFFB-4A325A163BE9}"

#define ProgId_REM_FormaElementaSprTypRabotGrp  "Kas.REM_FormaElementaSprTypRabotGrp.1"
#define Global_CLSID_TREM_FormaElementaSprTypRabotGrpImpl "{7A4EC8A4-A162-45CB-BDD3-AF0DCFB3F725}"
#define Global_IID_IREM_FormaElementaSprTypRabotGrp "{F8288293-73BE-4A4F-8EE4-964329C37D52}"


#define ProgId_REM_DMSprTypRabot  "Kas.REM_DMSprTypRabot.1"
#define Global_CLSID_TREM_DMSprTypRabotImpl "{DAE59173-4E40-4E08-8B2B-4D3C3368C516}"
#define Global_IID_IREM_DMSprTypRabot "{7058A09E-2283-44DE-B0D7-7A3DED9CAC61}"

#define ProgId_REM_FormaElementaSprTypRabot  "Kas.REM_FormaElementaSprTypRabot.1"
#define Global_CLSID_TREM_FormaElementaSprTypRabotImpl  "{681B1F1F-0BEA-46CB-B8D7-ED50522086FC}"
#define Global_IID_IREM_FormaElementaSprTypRabot "{960DA9D5-1953-4016-A7C4-4D0D14DE3F81}"

#define ProgId_REM_FormaSpiskaSprTypRabot  "Kas.REM_FormaSpiskaSprTypRabot.1"
#define Global_CLSID_TREM_FormaSpiskaSprTypRabotImpl  "{E4A924D8-547D-48F7-95A9-15ADF9039769}"
#define Global_IID_IREM_FormaSpiskaSprTypRabot "{CC960551-42AE-4120-B569-F5BC8DC54999}"












#define ProgId_REM_DMSprNeisprModel "Kas.REM_DMSprNeisprModel.1"
#define Global_CLSID_TREM_DMSprNeisprModelImpl "{EE008107-90B1-4D74-BCC7-227CEF0D78A2}"
#define Global_IID_IREM_DMSprNeisprModel "{007579BD-A0C4-4C2C-8207-ACDF75FF83AD}"

#define ProgId_REM_FormaElementaSprNeisprModel  "Kas.REM_FormaElSprNeisprModel.1"
#define Global_CLSID_TREM_FormaElementaSprNeisprModelImpl "{72CB3E85-ABDA-43D3-A2D1-DFAE34667169}"
#define Global_IID_IREM_FormaElementaSprNeisprModel  "{B2240CFC-064D-4B57-AB0A-F2BFC4565E63}"

#define ProgId_REM_FormaSpiskaSprNeisprModel   "Kas.REM_FormaSpSprNeisprModel.1"
#define Global_CLSID_TREM_FormaSpiskaSprNeisprModelImpl "{A6C25993-8EC3-4646-A130-147B1FB69B2A}"
#define Global_IID_IREM_FormaSpiskaSprNeisprModel  "{A58F09B2-D6F2-4FC6-BF7D-AE1F40F27C58}"





#define ProgId_REM_DMSprDefectModelNeispr "Kas.REM_DMSprDefectModelNeispr.1"
#define Global_CLSID_TREM_DMSprDefectModelNeisprImpl "{05A5E7E2-33F3-4850-A83D-B1663674ABC5}"
#define Global_IID_IREM_DMSprDefectModelNeispr "{DF375068-7EE2-43CC-AC01-095B5AD795C7}"

#define ProgId_REM_FormaElementaSprDefectModelNeispr  "Kas.REM_FormaElSprDefectModelNeispr.1"
#define Global_CLSID_TREM_FormaElementaSprDefectModelNeisprImpl "{E587FE81-1636-4EA4-81BA-15714D1B06D9}"
#define Global_IID_IREM_FormaElementaSprDefectModelNeispr "{9C7410D3-8937-42CF-BA47-B398F78CDD8B}"

#define ProgId_REM_FormaSpiskaSprDefectModelNeispr   "Kas.REM_FormaSpSprDefectModelNeispr.1"
#define Global_CLSID_TREM_FormaSpiskaSprDefectModelNeisprImpl "{FCAA9D24-DCE2-46E4-9D94-AA3EAE3D7246}"
#define Global_IID_IREM_FormaSpiskaSprDefectModelNeispr "{3A637062-22F7-42BD-8B12-F69BAE78F576}"





#define ProgId_REM_DMSprTrebRabot "Kas.REM_DMSprTrebRabot.1"
#define Global_CLSID_TREM_DMSprTrebRabotImpl "{2A801BA0-9E16-4FFC-873E-2BE4C8A941DF}"
#define Global_IID_IREM_DMSprTrebRabot "{37DC709B-DAB2-486A-BD00-EB59E3D5F876}"

#define ProgId_REM_FormaElementaSprTrebRabot  "Kas.REM_FormaElementaSprTrebRabot.1"
#define Global_CLSID_TREM_FormaElementaSprTrebRabotImpl "{56227251-36FD-4FD9-970F-8E112C55CF36}"
#define Global_IID_IREM_FormaElementaSprTrebRabot  "{C1718430-3886-4264-99F5-9C2ED36CBDC8}"

#define ProgId_REM_FormaSpiskaSprTrebRabot  "Kas.REM_FormaSpiskaSprTrebRabot.1"
#define Global_CLSID_TREM_FormaSpiskaSprTrebRabotImpl "{96DFBADE-0B34-449E-9197-1B8C4F752CF3}"
#define Global_IID_IREM_FormaSpiskaSprTrebRabot "{BEBE5505-A5BC-4642-810B-ED8D76D6182B}"




#define ProgId_REM_DMSprTrebUslov "Kas.REM_DMSprTrebUslov.1"
#define Global_CLSID_TREM_DMSprTrebUslovImpl "{E444693C-C298-483F-9FB4-B9D9FA680E30}"
#define Global_IID_IREM_DMSprTrebUslov "{18AC23DA-8736-4A51-B829-D4CB0461CD18}"

#define ProgId_REM_FormaElementaSprTrebUslov  "Kas.REM_FormaElementaSprTrebUslov.1"
#define Global_CLSID_TREM_FormaElementaSprTrebUslovImpl "{A9730F02-7BAE-4B88-8608-9308D0ABAA22}"
#define Global_IID_IREM_FormaElementaSprTrebUslov  "{491BD592-AFCD-436A-B61F-20355EFD281C}"

#define ProgId_REM_FormaSpiskaSprTrebUslov  "Kas.REM_FormaSpiskaSprTrebUslov.1"
#define Global_CLSID_TREM_FormaSpiskaSprTrebUslovImpl  "{22303513-8E85-420C-8516-F8E2B6BDEAAD}"
#define Global_IID_IREM_FormaSpiskaSprTrebUslov  "{F9778C20-9B76-4EE3-8857-1AE123B42F70}"




#define ProgId_REM_DMSprModelDetal "Kas.REM_DMSprModelDetal.1"
#define Global_CLSID_TREM_DMSprModelDetalImpl "{BE929856-F183-420E-AB3D-9B8AD780F11F}"
#define Global_IID_IREM_DMSprModelDetal "{444CA0FE-CA50-4B90-8678-6465DD30D443}"

#define ProgId_REM_FormaElementaSprModelDetal  "Kas.REM_FormaElementaSprModelDetal.1"
#define Global_CLSID_TREM_FormaElementaSprModelDetalImpl  "{1AA31065-5376-43FD-B0C0-22E6F6371F3C}"
#define Global_IID_IREM_FormaElementaSprModelDetal "{DF001374-CC2D-4F30-8E32-F4B288D3A9A3}"

#define ProgId_REM_FormaSpiskaSprModelDetal   "Kas.REM_FormaSpiskaSprModelDetal.1"
#define Global_CLSID_TREM_FormaSpiskaSprModelDetalImpl  "{A3FF97AF-52AD-4B25-B5FE-21507DBE7CAC}"
#define Global_IID_IREM_FormaSpiskaSprModelDetal "{DA169DE0-8445-4773-895C-D3154891CA24}"



#define ProgId_REM_DMSprTypeDevice "Kas.REM_DMSprTypeDevice.1"
#define Global_CLSID_TREM_DMSprTypeDeviceImpl "{D9CFDBDB-23AF-48F8-935F-D0A5D18E5C8E}"
#define Global_IID_IREM_DMSprTypeDevice "{B5FB9098-976E-4014-A94B-73B373DB8117}"

#define ProgId_REM_FormaElementaSprTypeDevice  "Kas.REM_FormaElementaSprTypeDevice.1"
#define Global_CLSID_TREM_FormaElementaSprTypeDeviceImpl "{7DC67AC0-36B3-48D3-AC08-9CA06B79B1DA}"
#define Global_IID_IREM_FormaElementaSprTypeDevice "{ADBD4BA5-EB3D-4581-83D3-F5B6D9B4EBB2}"

#define ProgId_REM_FormaSpiskaSprTypeDevice   "Kas.REM_FormaSpiskaSprTypeDevice.1"
#define Global_CLSID_TREM_FormaSpiskaSprTypeDeviceImpl "{05CCCF04-7AA5-4542-8517-826BC8583D80}"
#define Global_IID_IREM_FormaSpiskaSprTypeDevice "{8E1981C5-E282-4995-9BD8-4BA06342DDDE}"




#define ProgId_REM_DMSprModel2Grp "Kas.REM_DMSprModel2Grp.1"
#define Global_CLSID_TREM_DMSprModel2GrpImpl "{39326A87-CF7E-479F-84B0-A06F79027278}"
#define Global_IID_IREM_DMSprModel2Grp "{2DD718C6-1E63-4A40-B82F-F5871E407E90}"

#define ProgId_REM_DMSprModel2 "Kas.REM_DMSprModel2.1"
#define Global_CLSID_TREM_DMSprModel2Impl "{AA1B2C71-35EE-4220-9203-76CA98525CA3}"
#define Global_IID_IREM_DMSprModel2 "{F3A3F506-86A3-4333-9F8F-584415F31E23}"

#define ProgId_REM_FormaElementaSprModel2  "Kas.REM_FormaElementaSprModel2.1"
#define Global_CLSID_TREM_FormaElementaSprModel2Impl "{27EB1417-F4FA-4267-91F3-3877DE8DC28F}"
#define Global_IID_IREM_FormaElementaSprModel2 "{628A5E97-1491-4E9E-8540-FA40A8EE2082}"

#define ProgId_REM_FormaSpiskaSprModel2   "Kas.REM_FormaSpiskaSprModel2.1"
#define Global_CLSID_TREM_FormaSpiskaSprModel2Impl "{A9321EDD-2790-4ED3-98E8-96892C5636A9}"
#define Global_IID_IREM_FormaSpiskaSprModel2 "{2BA84D33-7E10-476E-8F20-8E896A6F2D59}"

#define ProgId_REM_FormaElementaSprModel2Grp  "Kas.REM_FormaElementaSprModel2Grp.1"
#define Global_CLSID_TREM_FormaElementaSprModel2GrpImpl   "{826D5919-0533-4C80-BA1B-4A37E6D619F9}"
#define Global_IID_IREM_FormaElementaSprModel2Grp "{8531F007-C4F1-412E-BDE3-1255F65450BE}"



#define ProgId_DMSprTypeAnalog "Kas.DMSprTypeAnalog.1"
#define Global_CLSID_TDMSprTypeAnalogImpl  "{649BAC90-6A51-4EC8-91AE-FE5580C3A8CB}"
#define Global_IID_IDMSprTypeAnalog "{92715B54-AFAE-493F-A4FB-EF3BBD709B7C}"


#define ProgId_DMSprNomAnalog "Kas.DMSprNomAnalog.1"
#define Global_CLSID_TDMSprNomAnalogImpl "{7F0E6399-D1F5-46BF-A3EB-2D38A13563B2}"
#define Global_IID_IDMSprNomAnalog "{CA546818-D624-4DEC-B203-A46F73506811}"

#define ProgId_FormaSpiskaSprTypeAnalog   "Kas.FormaSpiskaSprTypeAnalog.1"
#define Global_CLSID_TFormaSpiskaSprTypeAnalogImpl "{62E5C74C-E5C1-48D7-987D-F79D561306B0}"
#define Global_IID_IFormaSpiskaSprTypeAnalog  "{819282F8-DDCB-4E31-AAE3-16C93AEF95D4}"

#define ProgId_FormaSpiskaSprNomAnalog   "Kas.FormaSpiskaSprNomAnalog.1"
#define Global_CLSID_TFormaSpiskaSprNomAnalogImpl "{298EA907-73B3-498F-847E-3F4469A50F4F}"
#define Global_IID_IFormaSpiskaSprNomAnalog "{E5F17077-389F-49EB-ABEB-534E95253047}"


#define ProgId_REM_DMSprProducerDefect  "Kas.REM_DMSprProducerDefect.1"
#define Global_CLSID_TREM_DMSprProducerDefectImpl "{9E759E15-F5E1-4EE4-92EC-9676152C1D95}"
#define Global_IID_IREM_DMSprProducerDefect "{98A1F2BC-350C-474A-87FB-2E0B6AA8C313}"

#define ProgId_REM_DMSprProducerDefectGrp  "Kas.REM_DMSprProducerDefectGrp.1"
#define Global_CLSID_TREM_DMSprProducerDefectGrpImpl "{D33DBECC-FBE5-41FC-A6FE-D34AE30FC64B}"
#define Global_IID_IREM_DMSprProducerDefectGrp "{B49FCA97-5865-43E3-9C3C-2779D0234A02}"


#define ProgId_REM_FormaElementaSprProducerDefect  "Kas.REM_FormaElSprProducerDefect.1"
#define Global_CLSID_TREM_FormaElementaSprProducerDefectImpl "{1DFDF211-E957-47D8-958E-11D7B2949978}"
#define Global_IID_IREM_FormaElementaSprProducerDefect "{7A6B576D-CFD7-4D77-8029-134A6BC6530F}"

#define ProgId_REM_FormaElementaSprProducerDefectGrp  "Kas.REM_FormaElSprProducerDefectGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerDefectGrpImpl "{6DB36545-F32C-4E87-9D7F-CD2AFC57A20B}"
#define Global_IID_IREM_FormaElementaSprProducerDefectGrp  "{4F286213-C8F9-4D12-8360-0130BD086455}"


#define ProgId_REM_FormaSpiskaSprProducerDefect  "Kas.REM_FormaSpiskaSprProducerDefect.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerDefectImpl "{B215DACB-F88B-48B9-8F60-995E4370F3F2}"
#define Global_IID_IREM_FormaSpiskaSprProducerDefect "{CBFF6829-B981-4461-8DC2-4A1B599ECDF1}"




#define ProgId_FormaSpiskaStSpr1   "Kas.FormaSpiskaStSpr1.1"
#define Global_CLSID_TFormaSpiskaStSpr1Impl "{5EAEFCEB-B894-458D-8A9C-515EA55B5A96}"
#define Global_IID_IFormaSpiskaStSpr1  "{C3F41029-3211-4B19-AFEF-D8FC0AD40824}"


#define ProgId_DMStSpr1   "Kas.DMStSpr1.1"
#define Global_CLSID_TDMStSpr1Impl "{76D9859B-9FEA-45B9-AC23-200A60C46C5F}"
#define Global_IID_IDMStSpr1 "{82805B00-D719-42FF-B5AE-FA9EC9F293CD}"


#define ProgId_FormaImportSprProducerNom   "Kas.FormaImportSprProducerNom.1"
#define Global_CLSID_TFormaImportSprProducerNomImpl "{7CB5EE55-60C0-4368-836F-A967F08BF231}"
#define Global_IID_IFormaImportSprProducerNom "{5B896C84-3D9B-4EF6-91F8-AC672F6E17C8}"



#define ProgId_REM_DMGurZAktPr   "Kas.REM_DMGurZAktPr.1"
#define Global_CLSID_TREM_DMGurZAktPrImpl "{54239A7E-9AB1-41E7-BBAE-B781E6D88D0F}"
#define Global_IID_IREM_DMGurZAktPr "{E9AC96C7-2CB6-4710-A7E8-2D75E9F2C845}"

#define ProgId_REM_FormaGurZAktPr   "Kas.REM_FormaGurZAktPr.1"
#define Global_CLSID_TREM_FormaGurZAktPrImpl "{CA2F5EC9-C1A1-4239-AD55-F55BBB33E3A5}"
#define Global_IID_IREM_FormaGurZAktPr "{8BFAD75D-C329-494F-98DB-0CE253DFA8CD}"



#define ProgId_DMDocOtchetPost "Kas.REM_DMDocOtchetPost.1"
#define Global_CLSID_TDMDocOtchetPostImpl  "{2C0C96B8-8B85-4436-ABD8-66A256B4E811}"
#define Global_IID_IDMDocOtchetPost  "{B1C000DA-4719-4C6D-98E9-C44C99640989}"

#define ProgId_FormaDocOtchetPost  "Kas.REM_FormaDocOtchetPost.1"
#define Global_CLSID_TFormaDocOtchetPostImpl "{0382A977-34FF-45DC-83B4-3BBFBB2076EC}"
#define Global_IID_IFormaDocOtchetPost "{A59C6F2A-555F-46C5-B69A-693CB3BC5E02}"



#define ProgId_DMGurPlat  "Kas.DMGurPlat.1"
#define Global_CLSID_TDMGurPlatImpl "{88E10AF4-66D0-4D9E-BB11-306058A7EB13}"
#define Global_IID_IDMGurPlat "{7D9E86A8-80C5-45DB-A72A-680B66DF44A8}"


#define ProgId_FormaElementaGurPlat  "Kas.FormaElementaGurPlat.1"
#define Global_CLSID_TFormaElementaGurPlatImpl "{87C57299-9677-4748-9C75-7406AA9A6B7D}"
#define Global_IID_IFormaElementaGurPlat "{BC2B3455-9CAD-48BD-B37A-B2DF4F5E2C81}"


#define ProgId_REM_DMDocRegOtchetPost "Kas.REM_DMDocRegOtchetPost.1"
#define Global_CLSID_TREM_DMDocRegOtchetPostImpl "{DCA6F8E2-5D3A-4C51-B017-66A4FD6CD083}"
#define Global_IID_IREM_DMDocRegOtchetPost "{C927D5D5-10C9-4474-9379-2C2F605C700F}"

#define ProgId_REM_FormaDocRegOtchetPost  "Kas.REM_FormaDocRegOtchetPost.1"
#define Global_CLSID_TREM_FormaDocRegOtchetPostImpl "{54D3494C-937C-45E6-BE1F-6633E608F8EE}"
#define Global_IID_IREM_FormaDocRegOtchetPost "{B92112B4-7FEE-4D55-AEBF-047B06990AC1}"


#define ProgId_DMDocRegOtchetPost "Kas.DMDocRegOtchetPost.1"
#define Global_CLSID_TDMDocRegOtchetPostImpl "{6687654C-E75F-4AEE-B858-F62904281367}"
#define Global_IID_IDMDocRegOtchetPost "{F04C7919-22F8-46D9-B375-0F1CCCDD4AC4}"

#define ProgId_FormaDocRegOtchetPost  "Kas.FormaDocRegOtchetPost.1"
#define Global_CLSID_TFormaDocRegOtchetPostImpl  "{C5674ED2-11A3-491B-8B2E-C92E98AB0BEF}"
#define Global_IID_IFormaDocRegOtchetPost "{05C56BBE-07AD-4B81-800B-3E33B39FBC49}"



#define ProgId_ART_DMSprInfBlock "Kas.ART_DMSprInfBlock.1"
#define Global_CLSID_TART_DMSprInfBlockImpl "{88D354D8-9FE8-4A35-9D84-3316C7D23DFC}"
#define Global_IID_IART_DMSprInfBlock "{3FC94A9B-BC34-471F-B1C9-B6C898AC90EA}"

#define ProgId_ART_DMSprInfBlockGrp "Kas.ART_DMSprInfBlockGrp.1"
#define Global_CLSID_TART_DMSprInfBlockGrpImpl "{C3F89985-8893-41C9-B2DF-2B539A8F7132}"
#define Global_IID_IART_DMSprInfBlockGrp "{6CB9BAB7-1C38-400A-89CF-9D6E0A6BD576}"


#define ProgId_ART_DMSprInfBlockSostav "Kas.ART_DMSprInfBlockSostav.1"
#define Global_CLSID_TART_DMSprInfBlockSostavImpl  "{036C6EA6-F203-4BF2-A273-5FB87428D312}"
#define Global_IID_IART_DMSprInfBlockSostav "{15118961-3B0F-4BD6-AC29-965A1BAF499C}"


#define ProgId_ART_DMSprImage "Kas.ART_DMSprImage.1"
#define Global_CLSID_TART_DMSprImageImpl "{2D0B5B4C-6D9D-4FAC-8494-86F6C93624C0}"
#define Global_IID_IART_DMSprImage "{D05D5EDA-B391-452B-B082-DF324426DB22}"

#define ProgId_ART_DMSprImageGrp "Kas.ART_DMSprImageGrp.1"
#define Global_CLSID_TART_DMSprImageGrpImpl "{F839010D-466F-43FB-A4E3-39914E7BF458}"
#define Global_IID_IART_DMSprImageGrp "{2AF5B86F-48CF-430E-A497-EF8BEFEF3265}"

#define ProgId_ART_DMSprNaborInfBlock "Kas.ART_DMSprNaborInfBlock.1"
#define Global_CLSID_TART_DMSprNaborInfBlockImpl "{4EB08B47-17FA-4F4E-A01C-D336E927A820}"
#define Global_IID_IART_DMSprNaborInfBlock "{4677162C-0EE8-470A-8265-F82F0D4746E9}"

#define ProgId_ART_DMSprNaborInfBlockGrp "Kas.ART_DMSprNaborInfBlockGrp.1"
#define Global_CLSID_TART_DMSprNaborInfBlockGrpImpl "{1F7D4EC7-BC8F-4C0D-B9D3-DE2E5AF77EC5}"
#define Global_IID_IART_DMSprNaborInfBlockGrp  "{FFFF7C4C-509C-46D6-95AE-94A0DA865752}"

#define ProgId_ART_DMSprNaborInfBlockSostav "Kas.ART_DMSprNaborInfBlockSostav.1"
#define Global_CLSID_TART_DMSprNaborInfBlockSostavImpl "{01F106DC-AFB5-49E6-ACEB-17255CC3862C}"
#define Global_IID_IART_DMSprNaborInfBlockSostav  "{6AA04332-7A05-4B3E-AD77-F2BA06D5F504}"

#define ProgId_ART_DMSprNaborInfBlockSostavGrp "Kas.ART_DMSprNaborInfBlockSostavGrp.1"
#define Global_CLSID_TART_DMSprNaborInfBlockSostavGrpImpl  "{3E02E773-4D67-4781-BAA7-76F6FFD8CEC5}"
#define Global_IID_IART_DMSprNaborInfBlockSostavGrp "{29F2A372-67E3-4E7F-BF39-50B34588CAAA}"





#define ProgId_ART_FormaElementaSprInfBlock "Kas.ART_FormaElSprInfBlock.1"
#define Global_CLSID_TART_FormaElementaSprInfBlockImpl "{B402D6A6-4C31-40B0-8B19-DEB71837A1CB}"
#define Global_IID_IART_FormaElementaSprInfBlock "{5914FBFE-7884-4545-BB34-0EC44799CC67}"

#define ProgId_ART_FormaSpiskaSprInfBlock "Kas.ART_FormaSpSprInfBlock.1"
#define Global_CLSID_TART_FormaSpiskaSprInfBlockImpl "{9E0EC048-A15C-4FE1-91D3-A68D8D03A20C}"
#define Global_IID_IART_FormaSpiskaSprInfBlock "{27021484-28B9-4EBE-B15B-56A217011D7D}"

#define ProgId_ART_FormaElementaSprInfBlockGrp "Kas.ART_FormaElSprInfBlockGrp.1"
#define Global_CLSID_TART_FormaElementaSprInfBlockGrpImpl  "{42E349D3-9F1E-4979-B7C9-85BD75E9030C}"
#define Global_IID_IART_FormaElementaSprInfBlockGrp  "{71565394-264F-49BF-A8F0-C5789E337A91}"


#define ProgId_ART_FormaElementaSprInfBlockSostav "Kas.ART_FormaElSprInfBlockSost.1"
#define Global_CLSID_TART_FormaElementaSprInfBlockSostavImpl  "{91216189-7DF1-44FC-82F2-5863E437D439}"
#define Global_IID_IART_FormaElementaSprInfBlockSostav  "{93815163-3DCE-4DA4-B982-5F9B1A099817}"

#define ProgId_ART_FormaSpiskaSprInfBlockSostav "Kas.ART_FormaSpSprInfBlockSost.1"
#define Global_CLSID_TART_FormaSpiskaSprInfBlockSostavImpl "{2040D30A-B29F-4213-AB43-DD6D380AFF83}"
#define Global_IID_IART_FormaSpiskaSprInfBlockSostav "{87EBBF11-E973-42FE-8B1D-98009B542E9B}"




#define ProgId_ART_FormaElementaSprImage "Kas.ART_FormaElementaSprImage.1"
#define Global_CLSID_TART_FormaElementaSprImageImpl "{3558B79F-8534-4416-8A71-057CBE3586F3}"
#define Global_IID_IART_FormaElementaSprImage "{22E1D118-1CE7-4F80-BE48-ABA57DC70310}"

#define ProgId_ART_FormaSpiskaSprImage "Kas.ART_FormaSpiskaSprImage.1"
#define Global_CLSID_TART_FormaSpiskaSprImageImpl "{4DDE7207-D8D4-450D-A614-39D4738467AE}"
#define Global_IID_IART_FormaSpiskaSprImage  "{520F7455-0675-4133-B201-AFBF3B1DF479}"

#define ProgId_ART_FormaElementaSprImageGrp "Kas.ART_FormaElementaSprImageGrp.1"
#define Global_CLSID_TART_FormaElementaSprImageGrpImpl "{755F7E29-8C1A-4C50-9C21-4401B0FD2558}"
#define Global_IID_IART_FormaElementaSprImageGrp  "{5B3A6105-DDF1-4850-9342-30BABD91AAE2}"



#define ProgId_ART_FormaElementaSprNaborInfBlock "Kas.ART_FormaElSprNaborInfBlock.1"
#define Global_CLSID_TART_FormaElementaSprNaborInfBlockImpl "{93583A31-9DC2-449C-93F7-3C0B173B6965}"
#define Global_IID_IART_FormaElementaSprNaborInfBlock "{3F15365C-6297-4711-BD7D-68DA84FEED35}"

#define ProgId_ART_FormaElementaSprNaborInfBlockGrp "Kas.ART_FormaElSprNaborInfBlockGrp.1"
#define Global_CLSID_TART_FormaElementaSprNaborInfBlockGrpImpl "{11FE5594-643D-4CB8-901D-C73ED651AE08}"
#define Global_IID_IART_FormaElementaSprNaborInfBlockGrp  "{0D200451-03DA-40C0-8A39-A639C6D3FD80}"

#define ProgId_ART_FormaSpiskaSprNaborInfBlock "Kas.ART_FormaSpSprNaborInfBlock.1"
#define Global_CLSID_TART_FormaSpiskaSprNaborInfBlockImpl  "{9F804210-528C-41B3-A5AD-F00898B462BF}"
#define Global_IID_IART_FormaSpiskaSprNaborInfBlock  "{5BDC14D7-65C0-41E6-B8B1-AFFFB5B92712}"



#define ProgId_ART_FormaElementaSprNaborInfBlockSostav "Kas.ART_FormaElSprNaborInfBlSost.1"
#define Global_CLSID_TART_FormaElementaSprNaborInfBlockSostavImpl "{091951B9-A86C-46CF-9F57-097AD09B6BD2}"
#define Global_IID_IART_FormaElementaSprNaborInfBlockSostav "{D53BACE1-674E-4961-B454-882141A71389}"

#define ProgId_ART_FormaSpiskaSprNaborInfBlockSostav "Kas.ART_FormaSpSprNaborInfBlSost.1"
#define Global_CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl "{C99C2C41-1305-47F6-909E-90FA812C9F9C}"
#define Global_IID_IART_FormaSpiskaSprNaborInfBlockSostav "{30D08543-2EFF-4794-88E5-D63FD6E86744}"

#define ProgId_ART_FormaElementaSprNaborInfBlockSostavGrp "Kas.ART_FormaElSprNaborInfBlSostGrp.1"
#define Global_CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl "{8FB59C5B-5923-492E-B826-F5DB29769CB4}"
#define Global_IID_IART_FormaElementaSprNaborInfBlockSostavGrp "{C29335DD-EDD2-4327-8066-7E4B9FD4CFD5}"

#define ProgId_ART_DMSprInfBlockPriv "Kas.ART_DMSprInfBlockPriv.1"
#define Global_CLSID_TART_DMSprInfBlockPrivImpl "{4661E828-A17E-4F6E-988B-1FFC458C7DDE}"
#define Global_IID_IART_DMSprInfBlockPriv "{7323211F-86C6-49AF-AC7A-F1D3804FEEB4}"





#define ProgId_DMInterfMainMenuPar "Kas.DMInterfMainMenuPar.1"
#define Global_CLSID_TDMInterfMainMenuParImpl "{BCF39E66-99E9-420E-9ED2-0D81D25501FE}"
#define Global_IID_IDMInterfMainMenuPar "{8E1A4B59-2B2C-4173-8575-3F3B4CAB9CA5}"

#define ProgId_FormaSpiskaInterfMainMenuPar "Kas.FormaSpiskaInterfMainMenuPar.1"
#define Global_CLSID_TFormaSpiskaInterfMainMenuParImpl "{2DF876EC-9108-4FC3-B9F4-D19C811AC8D0}"
#define Global_IID_IFormaSpiskaInterfMainMenuPar "{2749C4E4-D3CC-4CD5-A965-4206BFE73811}"





#define ProgId_DMSprCustomerAccountGrp "Kas.DMSprCustomerAccountGrp.1"
#define Global_CLSID_TDMSprCustomerAccountGrpImpl "{200B470F-01EF-4301-93E7-FDF65A05CE9A}"
#define Global_IID_IDMSprCustomerAccountGrp "{CB8942C2-34C9-43DA-BD2C-0BAD06F70D63}"

#define ProgId_DMSprCustomerAccount "Kas.DMSprCustomerAccount.1"
#define Global_CLSID_TDMSprCustomerAccountImpl "{F02DF61F-072C-4E11-94A2-46832D5994A7}"
#define Global_IID_IDMSprCustomerAccount "{B72A0107-44B5-473D-B578-D5524F67978F}"


#define ProgId_FormaElementaSprCustomerAccountGrp "Kas.FormaElSprCustomerAccountGrp.1"
#define Global_CLSID_TFormaElementaSprCustomerAccountGrpImpl "{C9D53425-058C-4FE4-907F-B8D90DC4F961}"
#define Global_IID_IFormaElementaSprCustomerAccountGrp "{049D6F50-A8F5-406D-87C9-901175C689CB}"

#define ProgId_FormaElementaSprCustomerAccount "Kas.FormaElSprCustomerAccount.1"
#define Global_CLSID_TFormaElementaSprCustomerAccountImpl "{C4C85BA9-C80B-4F92-87FC-F95F4E20BE43}"
#define Global_IID_IFormaElementaSprCustomerAccount "{323638FE-E18A-4A6D-AABB-136678414644}"


#define ProgId_FormaSpiskaSprCustomerAccount "Kas.FormaSpSprCustomerAccount.1"
#define Global_CLSID_TFormaSpiskaSprCustomerAccountImpl  "{F40CF5D9-3420-407A-BA10-324D22879A4A}"
#define Global_IID_IFormaSpiskaSprCustomerAccount "{DD391EC3-1546-44AB-A5FA-21F98677C44D}"



//----------------------------------
#define ProgId_DMSprCustomerKlient "Kas.DMSprCustomerKLient.1"
#define Global_CLSID_TDMSprCustomerKlientImpl "{994A17F8-ADEB-4AA3-8F09-B18AE7467F63}"
#define Global_IID_IDMSprCustomerKlient "{3E77A004-0FF7-47D5-A9CB-B9E442235154}"


#define ProgId_FormaSpiskaSprCustomerKlient "Kas.FormaSpSprCustomerKlient.1"
#define Global_CLSID_TFormaSpiskaSprCustomerKlientImpl "{0121A2D4-8E2C-4307-8C0A-7FFA4F26A521}"
#define Global_IID_IFormaSpiskaSprCustomerKlient "{7032A727-3B5D-41CC-9B1F-9BB98C84A7FD}"

//-----------------------------------



#define ProgId_DMSprCustomerMainMenuGrp "Kas.DMSprCustomerMainMenuGrp.1"
#define Global_CLSID_TDMSprCustomerMainMenuGrpImpl  "{4783D242-6D45-44E0-8EBA-A31B2D9DFDDA}"
#define Global_IID_IDMSprCustomerMainMenuGrp "{87DA6F78-0C78-4EBB-987E-D3E162951F83}"

#define ProgId_DMSprCustomerMainMenu "Kas.DMSprCustomerMainMenu.1"
#define Global_CLSID_TDMSprCustomerMainMenuImpl "{D82A6CC2-40F5-4810-A477-B7DB4AF6C291}"
#define Global_IID_IDMSprCustomerMainMenu  "{2F65E120-A15E-4FE6-8469-BC14CB8E4D74}"


#define ProgId_FormaElementaSprCustomerMainMenuGrp "Kas.FormaElSprCustomerMainMenuGrp.1"
#define Global_CLSID_TFormaElementaSprCustomerMainMenuGrpImpl "{E2147775-9646-4574-9C86-EA818176611F}"
#define Global_IID_IFormaElementaSprCustomerMainMenuGrp  "{450C3119-AF36-4B7A-AE41-FC05E89EA56D}"

#define ProgId_FormaElementaSprCustomerMainMenu "Kas.FormaElSprCustomerMainMenu.1"
#define Global_CLSID_TFormaElementaSprCustomerMainMenuImpl "{C98AE2CC-EC44-45BE-B936-07B6190764D8}"
#define Global_IID_IFormaElementaSprCustomerMainMenu  "{9D227B0B-D0A0-44B4-B98E-D5375F7901B0}"


#define ProgId_FormaSpiskaSprCustomerMainMenu "Kas.FormaSpSprCustomerMainMenu.1"
#define Global_CLSID_TFormaSpiskaSprCustomerMainMenuImpl  "{8A9FFC90-0F92-43B5-B48C-5A9F2B88E7D3}"
#define Global_IID_IFormaSpiskaSprCustomerMainMenu "{0F1504A7-CB00-4ABE-98EA-D2CCE7EE7299}"

//-------------------------------------------

#define ProgId_DMSprCustomerUserGrp "Kas.DMSprCustomerUserGrp.1"
#define Global_CLSID_TDMSprCustomerUserGrpImpl "{80DC756D-C719-4571-BAE7-515A320C137A}"
#define Global_IID_IDMSprCustomerUserGrp  "{B9FB4D9B-818C-4AC5-AA0B-BC12E069040A}"

#define ProgId_DMSprCustomerUser "Kas.DMSprCustomerUser.1"
#define Global_CLSID_TDMSprCustomerUserImpl "{A4F877D4-92FF-4548-B872-205B4CC4782A}"
#define Global_IID_IDMSprCustomerUser "{DFADC86D-A086-411D-9703-10DE3365ABA5}"


#define ProgId_FormaElementaSprCustomerUserGrp "Kas.FormaElSprCustomerUserGrp.1"
#define Global_CLSID_TFormaElementaSprCustomerUserGrpImpl  "{FFE80045-6FDE-4A08-A00A-F2DCF739DD1F}"
#define Global_IID_IFormaElementaSprCustomerUserGrp "{893C48EA-44F3-43A6-8D99-AD49C7B8604E}"

#define ProgId_FormaElementaSprCustomerUser "Kas.FormaElSprCustomerUser.1"
#define Global_CLSID_TFormaElementaSprCustomerUserImpl "{BD1AE16E-6C78-4335-8E85-8C9DA89752E9}"
#define Global_IID_IFormaElementaSprCustomerUser "{9D0EC654-12A7-45A8-91FD-BF0B89D5463D}"


#define ProgId_FormaSpiskaSprCustomerUser "Kas.FormaSpSprCustomerUser.1"
#define Global_CLSID_TFormaSpiskaSprCustomerUserImpl "{DA1A3A38-E2E4-486C-8024-526A8B47459C}"
#define Global_IID_IFormaSpiskaSprCustomerUser "{1E9CD4B4-C6F8-491E-A79D-63B5BC00060D}"




#define ProgId_DMXVipolnObmen "Kas.DMXVipolnObmen.1"
#define Global_CLSID_TDMXVipolnObmenImpl "{D254F29A-4D39-4FD6-8805-529E3E059CFF}"
#define Global_IID_IDMXVipolnObmen  "{6C68D0DA-06A6-4161-AF6B-55B743C7EBBF}"


#define ProgId_FormaElementaXVipolnObmen "Kas.FormaElXVipolnObmen.1"
#define Global_CLSID_TFormaElementaXVipolnObmenImpl "{ADD738C8-7AAD-4FD0-892C-03445CCCE1B8}"
#define Global_IID_IFormaElementaXVipolnObmen "{1C70269D-FB37-441E-8B93-C290CDDC06AF}"



#define ProgId_FormaSpiskaXVipolnObmen "Kas.FormaSpXVipolnObmen.1"
#define Global_CLSID_TFormaSpiskaXVipolnObmenImpl "{65B4922E-ED67-4FD3-952A-121AAA0A5129}"
#define Global_IID_IFormaSpiskaXVipolnObmen "{4EB7D8F9-A786-4617-9311-5356C5828C87}"




#define ProgId_REM_DMDocVidachaHW "Kas.REM_DMDocVidachaHW.1"
#define Global_CLSID_TREM_DMDocVidachaHWImpl "{470511F4-D22C-4AFF-BE74-87A02B17C272}"
#define Global_IID_IREM_DMDocVidachaHW "{53B7C7B4-4BFC-487F-9F75-BA9B3DC7FD8C}"

#define ProgId_REM_FormaDocVidachaHW  "Kas.REM_FormaDocVidachaHW.1"
#define Global_CLSID_TREM_FormaDocVidachaHWImpl "{29F51D79-1C38-4F77-9EB2-D9B4970C8258}"
#define Global_IID_IREM_FormaDocVidachaHW "{35561D31-0A63-4248-BF39-1011FEDFBC78}"


#define ProgId_REM_DMDocVosvratHW "Kas.REM_DMDocVosvratHW.1"
#define Global_CLSID_TREM_DMDocVosvratHWImpl "{A73CD0AE-F587-49CA-B387-7D6A75BD63CC}"
#define Global_IID_IREM_DMDocVosvratHW "{7F7E996D-49A0-4455-B73E-FAA5FCEC7E9C}"

#define ProgId_REM_FormaDocVosvratHW  "Kas.REM_FormaDocVosvratHW.1"
#define Global_CLSID_TREM_FormaDocVosvratHWImpl "{7EFA5D72-F751-4853-A551-CA1EF26C2B4B}"
#define Global_IID_IREM_FormaDocVosvratHW "{2FAE5899-5932-437B-A642-DDB1C5E3C529}"





#define ProgId_REM_DMSprModelInfBlock "Kas.REM_DMSprModelInfBlock.1"
#define Global_CLSID_TREM_DMSprModelInfBlockImpl "{C8FA6827-BBE5-4CA3-9B76-4CEF8FDA5CA0}"
#define Global_IID_IREM_DMSprModelInfBlock "{3890132A-4CC3-46B6-B08F-A2B92CCA1861}"

#define ProgId_REM_FormaElementaSprModelInfBlock "Kas.REM_FormaElSprModelInfBlock.1"
#define Global_CLSID_TREM_FormaElementaSprModelInfBlockImpl "{D0CD7DC2-9146-49B8-A579-AE78EA2FB813}"
#define Global_IID_IREM_FormaElementaSprModelInfBlock "{1C9449E1-7914-44E3-AD31-0F0DA034DFF7}"

#define ProgId_REM_FormaSpiskaSprModelInfBlock "Kas.REM_FormaSpSprModelInfBlock.1"
#define Global_CLSID_TREM_FormaSpiskaSprModelInfBlockImpl "{E87388F0-B04D-4604-A6FA-182CFEB5523D}"
#define Global_IID_IREM_FormaSpiskaSprModelInfBlock "{97B7B8BB-8C90-4D98-8057-7F55FDC878A3}"



#define ProgId_REM_DMSprProducerModelInfBlock "Kas.REM_DMSprPrModelInfBlock.1"
#define Global_CLSID_TREM_DMSprProducerModelInfBlockImpl "{0E569630-F78B-41B9-A276-18EF6C40F818}"
#define Global_IID_IREM_DMSprProducerModelInfBlock "{DB2FAC50-C213-47A9-8BB9-827DBEA526AE}"

#define ProgId_REM_FormaElementaSprProducerModelInfBlock "Kas.REM_FormaElSprPrModelInfBlock.1"
#define Global_CLSID_TREM_FormaElementaSprProducerModelInfBlockImpl "{2B2D97DF-000C-4AF1-9FC6-B94DA9EFCCE6}"
#define Global_IID_IREM_FormaElementaSprProducerModelInfBlock "{6472AE6F-7BC7-45DA-ADE2-8923E42D3433}"

#define ProgId_REM_FormaSpiskaSprProducerModelInfBlock "Kas.REM_FormaSpSprPrModelInfBlock.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerModelInfBlockImpl "{4600C9EC-949D-4113-8E3F-AF1BFC9BE21B}"
#define Global_IID_IREM_FormaSpiskaSprProducerModelInfBlock "{CF80053A-9819-45BA-B769-4B5AEC2302BC}"




#define ProgId_REM_DMSprProducerModelPropertiesValue "Kas.REM_DMSprPrModelPropValue.1"
#define Global_CLSID_TREM_DMSprProducerModelPropertiesValueImpl  "{CDCD22F5-ADFC-4296-9489-7CDC32B57E62}"
#define Global_IID_IREM_DMSprProducerModelPropertiesValue  "{1CE6C168-9987-43EF-870B-4D4D0788F80A}"

#define ProgId_REM_FormaElementaSprProducerModelPropertiesValue "Kas.REM_FormaElSprPrModelPropValue.1"
#define Global_CLSID_TREM_FormaElementaSprProducerModelPropertiesValueImpl "{BD94EE69-36FB-49D2-A6D8-EC64023D6D09}"
#define Global_IID_IREM_FormaElementaSprProducerModelPropertiesValue  "{44E13A63-3BA3-48EA-A16C-DF2758228665}"

#define ProgId_REM_FormaSpiskaSprProducerModelPropertiesValue "Kas.REM_FormaSpSprPrModelPropValue.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerModelPropertiesValueImpl "{B91C996D-4006-49EE-9B99-65BA744C6B3E}"
#define Global_IID_IREM_FormaSpiskaSprProducerModelPropertiesValue "{676B3D40-A6F1-42B3-B123-E7A863C7AA83}"


#define ProgId_REM_DMSprModelPropertiesValue "Kas.REM_DMSprModelPropValue.1"
#define Global_CLSID_TREM_DMSprModelPropertiesValueImpl "{F046E686-FFEE-4668-AC06-B3EC19FD09B8}"
#define Global_IID_IREM_DMSprModelPropertiesValue "{AF2CC5B8-1387-406B-900E-2067B759E32F}"

#define ProgId_REM_FormaElementaSprModelPropertiesValue "Kas.REM_FormaElSprModelPropValue.1"
#define Global_CLSID_TREM_FormaElementaSprModelPropertiesValueImpl "{FADE4601-323E-4116-8073-30921771097F}"
#define Global_IID_IREM_FormaElementaSprModelPropertiesValue "{75C07092-6143-41D2-90E4-9DCBB449D869}"

#define ProgId_REM_FormaSpiskaSprModelPropertiesValue "Kas.REM_FormaSpSprModelPropValue.1"
#define Global_CLSID_TREM_FormaSpiskaSprModelPropertiesValueImpl "{E4E838EE-1ECE-4E27-8B9A-77DE9B78C244}"
#define Global_IID_IREM_FormaSpiskaSprModelPropertiesValue "{CB29A80F-2478-4CA5-B754-013DBD9899C3}"


#define ProgId_REM_FormaInfoPriem "Kas.REM_FormaInfoPriem.1"
#define Global_CLSID_TREM_FormaInfoPriemImpl  "{CBA9A6D8-CD0C-408B-A5E4-CEE8D3384A18}"
#define Global_IID_IREM_FormaInfoPriem "{4CE6D8B1-EBB1-4E1B-8E13-DBC899AFD5B5}"


#define ProgId_DMSprSeller "Kas.DMSprSeller.1"
#define Global_CLSID_TDMSprSellerImpl "{DB23E743-8CBB-405E-9A32-472BF155B1F5}"
#define Global_IID_IDMSprSeller "{92D2DB91-A0FC-4DEA-A427-332E52C06243}"

#define ProgId_FormaElementaSprSeller  "Kas.FormaElementaSprSeller.1"
#define Global_CLSID_TFormaElementaSprSellerImpl "{3DA35B24-E300-4917-8800-69349256AA2C}"
#define Global_IID_IFormaElementaSprSeller "{DE121D1F-12A9-4745-8D99-1AA21AA54B33}"

#define ProgId_FormaSpiskaSprSeller "Kas.FormaSpiskaSprSeller.1"
#define Global_CLSID_TFormaSpiskaSprSellerImpl "{1221ABBC-4AA9-4549-9B87-7CAECE07FEE7}"
#define Global_IID_IFormaSpiskaSprSeller "{263B644F-EE94-422E-89ED-8008BEC11CBE}"



#define ProgId_REM_DMGurProverok "Kas.REM_DMGurProverok.1"
#define Global_CLSID_TREM_DMGurProverokImpl "{BFC58BF7-CC56-49C3-9D10-5C8A067DD287}"
#define Global_IID_IREM_DMGurProverok "{18F589FB-55B8-4D8A-9594-2B7BA757837E}"

#define ProgId_REM_FormaGurProverok "Kas.REM_FormaGurProverok.1"
#define Global_CLSID_TREM_FormaGurProverokImpl "{11E6034C-BA80-4DDA-9085-3207EC3086CF}"
#define Global_IID_IREM_FormaGurProverok  "{B442D548-FD7C-459A-80E6-16D175263AB5}"


#define ProgId_REM_DMDocProverka "Kas.REM_DMDocProverka.1"
#define Global_CLSID_TREM_DMDocProverkaImpl "{C08BC1F6-78D9-4A77-A986-E56D632CE404}"
#define Global_IID_IREM_DMDocProverka "{B721C93B-44D3-46DC-A64D-6D09A3ADE2B7}"

#define ProgId_REM_FormaDocProverka "Kas.REM_FormaDocProverka.1"
#define Global_CLSID_TREM_FormaDocProverkaImpl "{AF865A00-86EC-43A3-8EEA-404B97297083}"
#define Global_IID_IREM_FormaDocProverka "{B5410C2C-1A7B-4D75-9719-2F559B159DA2}"



#define ProgId_REM_DMGurVigrusok "Kas.REM_DMGurVigrusok.1"
#define Global_CLSID_TREM_DMGurVigrusokImpl "{38168D2E-7C71-4ADE-B225-227DC5E5D181}"
#define Global_IID_IREM_DMGurVigrusok "{1677EF3E-377C-42ED-BF18-000369CC8A06}"

#define ProgId_REM_FormaGurVigrusok "Kas.REM_FormaGurVigrusok.1"
#define Global_CLSID_TREM_FormaGurVigrusokImpl "{C18498CC-61AE-41BD-84F9-E956A3117169}"
#define Global_IID_IREM_FormaGurVigrusok "{AB8C0C8A-B642-4DE0-881F-01BFE42D2EB4}"


#define ProgId_REM_DMDocVigruska "Kas.REM_DMDocVigruska.1"
#define Global_CLSID_TREM_DMDocVigruskaImpl "{2D88BEC8-27B8-4532-AF9C-B7D8F8F369FB}"
#define Global_IID_IREM_DMDocVigruska "{83053ACD-395B-4E04-B46C-A1E52CD90254}"

#define ProgId_REM_FormaDocVigruska "Kas.REM_FormaDocVigruska.1"
#define Global_CLSID_TREM_FormaDocVigruskaImpl "{1024C2B7-1363-483B-949F-15E78BAE24E6}"
#define Global_IID_IREM_FormaDocVigruska "{39BC2330-B611-4F5C-8AAF-23A738E755E8}"


#define ProgId_DMSprAdressRegion "Kas.DMSprAdressRegion.1"
#define Global_CLSID_TDMSprAdressRegionImpl  "{91A9947C-1349-4E4A-83B8-FED23E06B32F}"
#define Global_IID_IDMSprAdressRegion "{3AE044F7-7505-4707-8FAC-B7797973027A}"

#define ProgId_DMSprAdressRayon "Kas.DMSprAdressRayon.1"
#define Global_CLSID_TDMSprAdressRayonImpl "{8CF571F5-487C-4AD9-885D-33E1FE041D16}"
#define Global_IID_IDMSprAdressRayon "{00548C5A-AB21-4916-867C-F70AF9E093DE}"

#define ProgId_DMSprAdressNasPunkt "Kas.DMSprAdressNasPunkt.1"
#define Global_CLSID_TDMSprAdressNasPunktImpl "{F1C885C1-D3B9-4CFD-A3A5-7D67D7D3FA13}"
#define Global_IID_IDMSprAdressNasPunkt "{218F0E75-0319-45A2-9570-CDE374845EDE}"

#define ProgId_DMSprAdressStreet "Kas.DMSprAdressStreet.1"
#define Global_CLSID_TDMSprAdressStreetImpl "{436915EA-9B99-4F24-90BB-743EF2F1711E}"
#define Global_IID_IDMSprAdressStreet "{D355B7AA-AB84-48DA-8BA0-95CFF16FD16D}"

#define ProgId_DMSprAdressDom "Kas.DMSprAdressDom.1"
#define Global_CLSID_TDMSprAdressDomImpl "{24A8A41D-8864-4388-ACAB-3964A9D31D61}"
#define Global_IID_IDMSprAdressDom "{E7A2051D-86D9-4EAB-83C8-4C5C025E31AB}"

#define ProgId_DMSprAdressKv "Kas.DMSprAdressKv.1"
#define Global_CLSID_TDMSprAdressKvImpl "{383696AC-F442-4234-8448-99885B09F29B}"
#define Global_IID_IDMSprAdressKv "{9D417140-337E-40CC-A991-1CE3B6B73BDE}"

#define ProgId_FormaElementaSprAdress "Kas.FormaElementaSprAdress.1"
#define Global_CLSID_TFormaElementaSprAdressImpl "{9F8F0B7D-89E1-44B4-A04F-0594B7269A85}"
#define Global_IID_IFormaElementaSprAdress "{FC9B2582-13C6-4D2A-B4AA-953AD897B751}"


#define ProgId_REM_FormaGurZPredv  "Kas.REM_FormaGurZPredv.1"
#define Global_CLSID_TREM_FormaGurZPredvImpl "{529C1EA4-B1C4-4D14-996B-E3A226D4F44C}"
#define Global_IID_IREM_FormaGurZPredv "{828964B5-972D-462F-AF31-665E2C393F35}"

#define ProgId_REM_DMGurZPredv "Kas.REM_DMGurZPredv.1"
#define Global_CLSID_TREM_DMGurZPredvImpl "{41A7D335-65D9-4307-803B-B8C96F744350}"
#define Global_IID_IREM_DMGurZPredv "{7F259E49-A61B-4AF4-BBF6-ABF042FE5241}"

#define ProgId_REM_FormaZayavkaPredv "Kas.REM_FormaZayavkaPredv.1"
#define Global_CLSID_TREM_FormaZayavkaPredvImpl "{7D8778C3-B87F-4EA3-AC12-8A8AE9C0C468}"
#define Global_IID_IREM_FormaZayavkaPredv "{FD28B9C7-1EB7-485A-99B9-2107F2C90C18}"

#define ProgId_REM_DMZayavkaPredv "Kas.REM_DMZayavkaPredv.1"
#define Global_CLSID_TREM_DMZayavkaPredvImpl "{63DFE68F-1920-4868-BCF5-5FF7ABA109D5}"
#define Global_IID_IREM_DMZayavkaPredv "{1FC1FD64-E97C-4EE5-9C7F-97028AA70F20}"



#define ProgId_REM_DMSprActCategory "Kas.REM_DMSprActCategory.1"
#define Global_CLSID_TREM_DMSprActCategoryImpl "{BF604130-AE8B-419F-8D1A-4FF9050E1898}"
#define Global_IID_IREM_DMSprActCategory "{DAEB4F55-0125-4DA3-8F98-1FFB83F613EA}"

#define ProgId_REM_FormaElementaSprActCategory  "Kas.REM_FormaElementaSprActCategory.1"
#define Global_CLSID_TREM_FormaElementaSprActCategoryImpl "{E0B169F2-4B9B-46C8-A712-18D760BA706D}"
#define Global_IID_IREM_FormaElementaSprActCategory "{7328B691-A399-4EBF-8B9C-43A5DEFE7D16}"

#define ProgId_REM_FormaSpiskaSprActCategory   "Kas.REM_FormaSpiskaSprActCategory.1"
#define Global_CLSID_TREM_FormaSpiskaSprActCategoryImpl "{E7FA2193-D13C-4E51-A17B-5982237DEF3D}"
#define Global_IID_IREM_FormaSpiskaSprActCategory "{3985B528-8E57-4EB4-9111-F76412879C28}"


#define ProgId_DMDataSet "Kas.REM_DMDataSet.1"
#define Global_CLSID_TDMDataSetImpl "{82BA12EE-56FA-4055-82F4-90449758836B}"
#define Global_IID_IDMDataSet "{9D41467E-2DEF-4360-86F6-E9DB1328ECA8}"


#define ProgId_DMSprAddressRegion "Kas.DMSprAddressRegion.1"
#define Global_CLSID_TDMSprAddressRegionImpl "{A47F5995-3092-4770-864C-6555C48414E9}"
#define Global_IID_IDMSprAddressRegion "{0D79AFD9-85EC-450C-BD44-3AB016F9C363}"


#define ProgId_DMSprAddressRayon "Kas.DMSprAddressRayon.1"
#define Global_CLSID_TDMSprAddressRayonImpl "{DE99DD22-E81F-4718-B9FF-6DEE4A1DD1DB}"
#define Global_IID_IDMSprAddressRayon "{AFE88F76-DC6F-4743-92E3-7CD60D0D47DC}"

#define ProgId_DMSprAddressNasPunkt "Kas.DMSprAddressNasPunkt.1"
#define Global_CLSID_TDMSprAddressNasPunktImpl "{8C8C73B6-34DA-448E-8B83-E1D3D147A6FB}"
#define Global_IID_IDMSprAddressNasPunkt "{DB10FDAA-1388-4795-BE97-420460A8F1F9}"

#define ProgId_DMSprAddressStreet "Kas.DMSprAddressStreet.1"
#define Global_CLSID_TDMSprAddressStreetImpl "{DD54D965-64B5-462A-8D34-DF1B04C9EEB4}"
#define Global_IID_IDMSprAddressStreet "{7BF04C68-ABBB-45B5-A366-D344606AB996}"

#define ProgId_DMSprAddressDom "Kas.DMSprAddressDom.1"
#define Global_CLSID_TDMSprAddressDomImpl "{F0C9C049-9D2E-48A5-B41D-4F85272F5207}"
#define Global_IID_IDMSprAddressDom  "{F77D7E77-1902-4A04-95DC-524731401234}"

#define ProgId_DMSprAddressStroen "Kas.DMSprAddressStroen.1"
#define Global_CLSID_TDMSprAddressStroenImpl "{7833C766-F812-4DE9-839F-4E533C4D8347}"
#define Global_IID_IDMSprAddressStroen  "{5C85B7DA-3FA2-43DD-9949-10B2DAD1CC59}"

#define ProgId_DMSprAddressKV "Kas.DMSprAddressKV.1"
#define Global_CLSID_TDMSprAddressKVImpl "{2CEF44AE-17E1-4F6E-B1B9-07C4700BBFF9}"
#define Global_IID_IDMSprAddressKV "{97B45D19-CD1F-4A43-8025-2729DF41AD64}"





#define ProgId_FormaElementaSprAddressRegion "Kas.FormaElementaSprAddressRegion.1"
#define Global_CLSID_TFormaElementaSprAddressRegionImpl "{5D75429D-0F59-46B9-846D-B39683417D8A}"
#define Global_IID_IFormaElementaSprAddressRegion "{41C490BE-F3FA-45FE-87B6-3E62971465C4}"


#define ProgId_FormaElementaSprAddressRayon "Kas.FormaElementaSprAddressRayon.1"
#define Global_CLSID_TFormaElementaSprAddressRayonImpl "{8718FD02-6556-4814-99E7-10FCC8D6F8F4}"
#define Global_IID_IFormaElementaSprAddressRayon "{C4E18FAA-3CFB-4873-88FC-19BA23AAE737}"

#define ProgId_FormaElementaSprAddressNasPunkt "Kas.FormaElementaSprAddressNasPunkt.1"
#define Global_CLSID_TFormaElementaSprAddressNasPunktImpl "{760C484E-EDBA-40B3-B000-58577A0613DF}"
#define Global_IID_IFormaElementaSprAddressNasPunkt "{BEDFD509-CC3E-4CC7-A94A-57D6772BDABC}"

#define ProgId_FormaElementaSprAddressStreet "Kas.FormaElementaSprAddressStreet.1"
#define Global_CLSID_TFormaElementaSprAddressStreetImpl "{B730ED97-0135-4400-9BAA-F9120ADAA589}"
#define Global_IID_IFormaElementaSprAddressStreet "{F0B96666-835A-4740-8C6F-294E64BEAF6B}"

#define ProgId_FormaElementaSprAddressDom "Kas.FormaElementaSprAddressDom.1"
#define Global_CLSID_TFormaElementaSprAddressDomImpl "{EE25C7DE-F152-4863-9587-5596CDA1709C}"
#define Global_IID_IFormaElementaSprAddressDom "{82398C0D-8B99-4150-91F7-C23A06779CFB}"

#define ProgId_FormaElementaSprAddressStroen "Kas.FormaElementaSprAddressStroen.1"
#define Global_CLSID_TFormaElementaSprAddressStroenImpl "{B0D87926-CD5B-4BE1-9DCD-D51674C10BDE}"
#define Global_IID_IFormaElementaSprAddressStroen "{B9C23F4B-6C8C-428C-8E7D-0DC29F7211D0}"

#define ProgId_FormaElementaSprAddressKV "Kas.FormaElementaSprAddressKV.1"
#define Global_CLSID_TFormaElementaSprAddressKVImpl "{E3920D14-BAD1-4DB7-B7A3-5DADFDF9A965}"
#define Global_IID_IFormaElementaSprAddressKV  "{132E256E-CB95-4A2D-B1CC-A7421CC80113}"


#define ProgId_FormaElementaSprAddressVibor "Kas.FormaElementaSprAddressVibor.1"
#define Global_CLSID_TFormaElementaSprAddressViborImpl "{CC04A8C1-4DEB-4EE8-B340-2FAA9A526850}"
#define Global_IID_IFormaElementaSprAddressVibor "{BF98EE77-3833-41CB-B316-57ADC6B65F1E}"





#define ProgId_REM_FormaSpiskaSprProducerRabota  "Kas.REM_FormaSpSprProducerRabota.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerRabotaImpl "{6D6BF635-2FCE-4723-90C0-CE18AFC71462}"
#define Global_IID_IREM_FormaSpiskaSprProducerRabota "{B5E0C0BC-CF4F-4F2F-90D5-663E84F8140A}"


#define ProgId_REM_FormaElementaSprProducerRabota  "Kas.REM_FormaElSprProducerRabota.1"
#define Global_CLSID_TREM_FormaElementaSprProducerRabotaImpl "{E62182F3-9878-413F-971A-41A37E07A1EA}"
#define Global_IID_IREM_FormaElementaSprProducerRabota "{9DBF0D13-6824-4C1B-917B-395932549F0F}"


#define ProgId_REM_FormaElementaSprProducerRabotaGrp  "Kas.REM_FormaElSprProducerRabotaGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerRabotaGrpImpl "{F41CD6B4-6C58-4574-9354-5B59D397B6A4}"
#define Global_IID_IREM_FormaElementaSprProducerRabotaGrp "{381FB54B-A271-4C16-A8DD-75EB83AB6D6F}"



#define ProgId_REM_DMSprProducerRabota  "Kas.REM_DMSprProducerRabota.1"
#define Global_CLSID_TREM_DMSprProducerRabotaImpl  "{F2BF1B8D-4852-4F1E-9A1E-1428E93558F6}"
#define Global_IID_IREM_DMSprProducerRabota "{B4C8A626-15C4-4483-844B-E80B239860FB}"


#define ProgId_REM_DMSprProducerRabotaGrp "Kas.REM_DMSprProducerRabotaGrp.1"
#define Global_CLSID_TREM_DMSprProducerRabotaGrpImpl "{AAADF392-384A-4C48-83E2-BB6B4399E066}"
#define Global_IID_IREM_DMSprProducerRabotaGrp  "{92DD4F2B-06ED-4104-80FB-5B99A7103DAA}"



#define ProgId_FormaImportSprProducerNeispr  "Kas.FormaImportSprProducerNeispr.1"
#define Global_CLSID_TFormaImportSprProducerNeisprImpl "{E1879480-F064-4CDF-B003-AAF9D0FD62B1}"
#define Global_IID_IFormaImportSprProducerNeispr "{DFE0422F-7AE2-4C77-A89C-9654C2C5BE34}"

#define ProgId_FormaImportSprProducerDefect  "Kas.FormaImportSprProducerDefect.1"
#define Global_CLSID_TFormaImportSprProducerDefectImpl "{B73605E3-E8E6-464B-9A0A-A0DC66EB1328}"
#define Global_IID_IFormaImportSprProducerDefect "{96DC425E-FDEE-47D1-9899-43A8A5B2C338}"

#define ProgId_FormaImportSprProducerRabota  "Kas.FormaImportSprProducerRabota.1"
#define Global_CLSID_TFormaImportSprProducerRabotaImpl "{B041CBE9-9B03-4D43-B8B2-3266EBD341D9}"
#define Global_IID_IFormaImportSprProducerRabota "{3D6577E7-E094-4791-87DC-64EBE7FD8802}"

#define ProgId_FormaImportSprProducerCondition  "Kas.FormaImportSprProducerCond.1"
#define Global_CLSID_TFormaImportSprProducerConditionImpl "{4454DAD9-F4C3-48FA-9859-6B134D4A35AD}"
#define Global_IID_IFormaImportSprProducerCondition "{A9AA8A8B-C38D-4C85-9B6E-6633E55EFFE9}"

#define ProgId_FormaImportSprProducerSection "Kas.FormaImportSprProducerSect.1"
#define Global_CLSID_TFormaImportSprProducerSectionImpl "{A42723E6-0637-44B6-AC20-14E20DDA1066}"
#define Global_IID_IFormaImportSprProducerSection "{9B82E0A4-BCDB-4B96-A4B5-EDD0B4DB6A6E}"




#define ProgId_REM_DMDocZakazPost "Kas.REM_DMDocZakazPost.1"
#define Global_CLSID_TREM_DMDocZakazPostImpl "{F6EF9161-176E-4C44-B5EB-A309492FB282}"
#define Global_IID_IREM_DMDocZakazPost "{85EEA076-E07E-48DF-A3EA-F052BE549156}"

#define ProgId_REM_FormaDocZakazPost "Kas.REM_FormaDocZakazPost.1"
#define Global_CLSID_TREM_FormaDocZakazPostImpl "{ABB2D160-B32B-4100-ABF0-19FCA02546E7}"
#define Global_IID_IREM_FormaDocZakazPost "{6A052158-2372-4616-9211-25DA0743BD58}"

#define ProgId_REM_DMDocOtprPost "Kas.REM_DMDocOtprPost.1"
#define Global_CLSID_TREM_DMDocOtprPostImpl "{EA34013E-2BFF-404D-90E2-D7368F91135A}"
#define Global_IID_IREM_DMDocOtprPost "{B4C87B23-4A9A-430F-9499-020E27E3E266}"

#define ProgId_REM_FormaDocOtprPost "Kas.REM_FormaDocOtprPost.1"
#define Global_CLSID_TREM_FormaDocOtprPostImpl "{01E80AE6-4E44-4CD3-B523-9E96AF8B8212}"
#define Global_IID_IREM_FormaDocOtprPost "{1C05AFDC-D860-4502-AC09-BE1FBEB5388D}"




#define ProgId_REM_DMSprModelTypRabot "Kas.REM_DMSprModelTypRabot.1"
#define Global_CLSID_TREM_DMSprModelTypRabotImpl "{315AD0D9-FA25-4B9F-9814-B0E3C69C5EC0}"
#define Global_IID_IREM_DMSprModelTypRabot "{F15306CC-AD42-436B-B01A-0B37A583BD60}"

#define ProgId_REM_FormaElementaSprModelTypRabot "Kas.REM_FormaElSprModelTypRabot.1"
#define Global_CLSID_TREM_FormaElementaSprModelTypRabotImpl "{44855715-237F-4051-83AB-83346A2813A1}"
#define Global_IID_IREM_FormaElementaSprModelTypRabot "{0FB7D2CE-5E87-4A60-A9D4-7E6BAA435274}"

#define ProgId_REM_FormaSpiskaSprModelTypRabot   "Kas.REM_FormaSpSprModelTypRabot.1"
#define Global_CLSID_TREM_FormaSpiskaSprModelTypRabotImpl  "{B3FBA27C-7949-4D08-8B4F-54BF0E4DC0ED}"
#define Global_IID_IREM_FormaSpiskaSprModelTypRabot "{FF19D218-F99B-4EAD-9A2C-3950B6526225}"


#define ProgId_kasMSKFR   "Kas.kasMSKFR.1"
#define Global_CLSID_TkasMSKFRImpl "{66277F7A-DB0B-4973-8FF1-949DB35B83AC}"


#define Global_IID_IFiskReg  "{E3C08359-BA13-4E4E-9036-067A5D4103C5}"
#define Global_IID_IFiskRegOnLine "{88C7C456-A2D6-42EA-831F-5C7C01D22F9F}"


#define ProgId_1COnLineFR   "Kas.1COnLineFR.1"
#define Global_CLSID_T1COnLineFRImpl "{BBD5DFF0-24A4-4699-93D6-E50C783ED7E9}"

#define ProgId_1COnLineFRCOM   "Kas.1COnLineFRCOM.1"
#define Global_CLSID_T1COnLineFRCOMImpl "{8565D182-8B0B-4147-A202-56D4DF5E9B2E}"


#define ProgId_REM_DMSprProducerConditionGrp "Kas.REM_DMSprPrCondGrp.1"
#define Global_CLSID_TREM_DMSprProducerConditionGrpImpl "{BB59C97A-EFE7-4918-B91A-F29CF7A97FA3}"
#define Global_IID_IREM_DMSprProducerConditionGrp "{575F949B-4F40-4138-A6D1-746DF23672A4}"

#define ProgId_REM_FormaElementaSprProducerConditionGrp "Kas.REM_FormaElSprPrCondGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerConditionGrpImpl "{3FA6439A-BEF5-49CC-B3E3-0A5D89D02124}"
#define Global_IID_IREM_FormaElementaSprProducerConditionGrp "{CA5762E0-8BBA-4450-8E66-8BE77324CA35}"

#define ProgId_REM_FormaSpiskaSprProducerConditionGrp   "Kas.REM_FormaSpSprPrCondGrp.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerConditionGrpImpl "{54F4F6D4-FBAD-4231-9409-839BE4B8FBDF}"
#define Global_IID_IREM_FormaSpiskaSprProducerCondtionGrp "{7A86EFC1-7F8D-49A3-9B14-B21C1324385C}"


#define ProgId_REM_DMSprProducerCondition "Kas.REM_DMSprPrCond.1"
#define Global_CLSID_TREM_DMSprProducerConditionImpl "{7AF1BAD0-6844-4E9D-9D32-18865A49A4E3}"
#define Global_IID_IREM_DMSprProducerCondition "{D21688AD-C9CC-49FE-9298-60213EC13F84}"

#define ProgId_REM_FormaElementaSprProducerCondition "Kas.REM_FormaElSprPrCond.1"
#define Global_CLSID_TREM_FormaElementaSprProducerConditionImpl "{F9EFDA28-A587-40F8-A739-21D8AB6C61D0}"
#define Global_IID_IREM_FormaElementaSprProducerCondition  "{958DD2B7-E394-4FBB-98E6-341776117870}"

#define ProgId_REM_FormaSpiskaSprProducerCondition   "Kas.REM_FormaSpSprPrCond.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerConditionImpl "{08BBA945-C7DF-478A-B8EE-928B94BF9F98}"
#define Global_IID_IREM_FormaSpiskaSprProducerCondition "{9DC8E517-AA02-4A70-9F36-5215D4B3AEAF}"


#define ProgId_REM_DMSprProducerSectionGrp "Kas.REM_DMSprPrSectionGrp.1"
#define Global_CLSID_TREM_DMSprProducerSectionGrpImpl "{2050BA1B-074F-416D-88D6-FC8D76F0C8DC}"
#define Global_IID_IREM_DMSprProducerSectionGrp "{FB3FA27E-C4A9-4D1B-A78D-5D524B67D650}"

#define ProgId_REM_FormaElementaSprProducerSectionGrp "Kas.REM_FormaElSprPrSectionGrp.1"
#define Global_CLSID_TREM_FormaElementaSprProducerSectionGrpImpl "{F729C927-7D69-45D3-ADF9-64A7D2AA86D7}"
#define Global_IID_IREM_FormaElementaSprProducerSectionGrp "{5CA9216E-22BD-43CD-99BF-E471D5D80296}"

#define ProgId_REM_FormaSpiskaSprProducerSectionGrp   "Kas.REM_FormaSpSprPrSectionGrp.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerSectionGrpImpl "{B4794D00-53F7-441A-8DD0-72097E78B639}"
#define Global_IID_IREM_FormaSpiskaSprProducerSectionGrp "{3C37A740-EDDB-4CB1-80ED-8358BB0FD91C}"



#define ProgId_REM_DMSprProducerSection "Kas.REM_DMSprPrSection.1"
#define Global_CLSID_TREM_DMSprProducerSectionImpl "{16476ED4-E3C2-44C7-A4BD-B2DFCE14B0DB}"
#define Global_IID_IREM_DMSprProducerSection "{484120B6-86F7-4B9D-AF80-A79E07A3A619}"

#define ProgId_REM_FormaElementaSprProducerSection "Kas.REM_FormaElSprPrSection.1"
#define Global_CLSID_TREM_FormaElementaSprProducerSectionImpl "{26E4EA01-276F-464C-958F-730066671003}"
#define Global_IID_IREM_FormaElementaSprProducerSection "{29114BBE-9789-4E04-8648-197FE6502E71}"

#define ProgId_REM_FormaSpiskaSprProducerSection   "Kas.REM_FormaSpSprPrSection.1"
#define Global_CLSID_TREM_FormaSpiskaSprProducerSectionImpl "{DF1A4E77-5B59-499D-B842-70533D29C9D9}"
#define Global_IID_IREM_FormaSpiskaSprProducerSection  "{E5BFCFBD-9DEE-4B2D-83F4-3B541D1DBCFF}"




#define ProgId_HLP_DMSprInfBlock "Kas.HLP_DMSprInfBlock.1"
#define Global_CLSID_THLP_DMSprInfBlockImpl  "{B2B283EC-4FE4-41A7-A331-80EAF9561C23}"
#define Global_IID_IHLP_DMSprInfBlock  "{60435B82-C3FE-4AE1-919B-04BFAB13E4BB}"

#define ProgId_HLP_DMSprInfBlockGrp "Kas.HLP_DMSprInfBlockGrp.1"
#define Global_CLSID_THLP_DMSprInfBlockGrpImpl "{5B38E1AE-A025-4F63-BB47-5021E178EDA8}"
#define Global_IID_IHLP_DMSprInfBlockGrp "{44394976-BD4C-4533-B693-DE65E6C75E36}"


#define ProgId_HLP_DMSprInfBlockSostav "Kas.HLP_DMSprInfBlockSostav.1"
#define Global_CLSID_THLP_DMSprInfBlockSostavImpl "{2F607C0B-A808-4864-84C4-635BC1A62A48}"
#define Global_IID_IHLP_DMSprInfBlockSostav "{93B1C932-F1E8-49B0-A560-E96A0B8517B2}"


#define ProgId_HLP_DMSprImage "Kas.HLP_DMSprImage.1"
#define Global_CLSID_THLP_DMSprImageImpl "{DD9EFD9C-F1E7-4CAD-8F83-B9DA851748E2}"
#define Global_IID_IHLP_DMSprImage "{E1D33068-94EC-42AC-838A-D0FEC7538A6C}"

#define ProgId_HLP_DMSprImageGrp "Kas.HLP_DMSprImageGrp.1"
#define Global_CLSID_THLP_DMSprImageGrpImpl "{5252885A-CACB-4E75-B8DD-7A83263AD0E4}"
#define Global_IID_IHLP_DMSprImageGrp "{553FC736-EDBB-418B-8ED2-C6FAD48B2600}"

#define ProgId_HLP_DMSprNaborInfBlock "Kas.HLP_DMSprNaborInfBlock.1"
#define Global_CLSID_THLP_DMSprNaborInfBlockImpl "{911611A2-AB0E-4F16-8294-2D8D91FDF2B9}"
#define Global_IID_IHLP_DMSprNaborInfBlock "{3E81A7AD-0226-4CF4-8081-0A1C71C2D7DA}"

#define ProgId_HLP_DMSprNaborInfBlockGrp "Kas.HLP_DMSprNaborInfBlockGrp.1"
#define Global_CLSID_THLP_DMSprNaborInfBlockGrpImpl "{D66E8B36-0132-4F29-9B04-31C497A98AE2}"
#define Global_IID_IHLP_DMSprNaborInfBlockGrp "{CF56368D-516A-4783-8F46-123AF158BC46}"

#define ProgId_HLP_DMSprNaborInfBlockSostav "Kas.HLP_DMSprNaborInfBlockSostav.1"
#define Global_CLSID_THLP_DMSprNaborInfBlockSostavImpl "{C3AC4931-1DD9-4DC1-87C6-AD1BA0B62B9C}"
#define Global_IID_IHLP_DMSprNaborInfBlockSostav "{7A038628-0C9A-4D29-8B20-283344FC4F0B}"

#define ProgId_HLP_DMSprNaborInfBlockSostavGrp "Kas.HLP_DMSprNaborInfBlockSostavGrp.1"
#define Global_CLSID_THLP_DMSprNaborInfBlockSostavGrpImpl "{83F1B75D-8C4F-4D0B-88F1-866E2CF620F2}"
#define Global_IID_IHLP_DMSprNaborInfBlockSostavGrp "{A5341DC1-949A-458B-A203-E02631189FA9}"





#define ProgId_HLP_FormaElementaSprInfBlock "Kas.HLP_FormaElSprInfBlock.1"
#define Global_CLSID_THLP_FormaElementaSprInfBlockImpl "{57482452-9530-4564-8055-3E74A0D6309D}"
#define Global_IID_IHLP_FormaElementaSprInfBlock  "{5C6578E9-4E7D-42F8-85E8-B18DD21A26AA}"

#define ProgId_HLP_FormaSpiskaSprInfBlock "Kas.HLP_FormaSpSprInfBlock.1"
#define Global_CLSID_THLP_FormaSpiskaSprInfBlockImpl "{54176FBB-58E2-4817-B44E-1848CA967255}"
#define Global_IID_IHLP_FormaSpiskaSprInfBlock  "{47FE1294-0516-4B88-A74B-7BE67C3DF7D9}"

#define ProgId_HLP_FormaElementaSprInfBlockGrp "Kas.HLP_FormaElSprInfBlockGrp.1"
#define Global_CLSID_THLP_FormaElementaSprInfBlockGrpImpl "{883714DC-3ADC-4BC6-B1EC-9E6D97CB5940}"
#define Global_IID_IHLP_FormaElementaSprInfBlockGrp "{0F018D7D-9B3D-4D81-9DDA-97D642063781}"


#define ProgId_HLP_FormaElementaSprInfBlockSostav "Kas.HLP_FormaElSprInfBlockSost.1"
#define Global_CLSID_THLP_FormaElementaSprInfBlockSostavImpl "{637C9C31-92EF-4F40-8399-DC93E9AE9FC6}"
#define Global_IID_IHLP_FormaElementaSprInfBlockSostav "{32996A27-0CB4-4573-881C-682F83B6EC94}"

#define ProgId_HLP_FormaSpiskaSprInfBlockSostav "Kas.HLP_FormaSpSprInfBlockSost.1"
#define Global_CLSID_THLP_FormaSpiskaSprInfBlockSostavImpl "{EF89D122-BD98-4612-9398-CFFAC2DD9277}"
#define Global_IID_IHLP_FormaSpiskaSprInfBlockSostav "{F95D3722-772E-4DA2-826E-B509418228ED}"




#define ProgId_HLP_FormaElementaSprImage "Kas.HLP_FormaElementaSprImage.1"
#define Global_CLSID_THLP_FormaElementaSprImageImpl "{BB5B2FC4-17B2-4C4D-88B4-C783BE079EDE}"
#define Global_IID_IHLP_FormaElementaSprImage  "{210B9CD7-BAE6-4B73-8041-1A88D842554A}"

#define ProgId_HLP_FormaSpiskaSprImage "Kas.HLP_FormaSpiskaSprImage.1"
#define Global_CLSID_THLP_FormaSpiskaSprImageImpl "{CFA0C5FF-EDCC-4CB5-9D5C-D1D6B7BE5B7E}"
#define Global_IID_IHLP_FormaSpiskaSprImage "{0C6F4943-BE9B-404E-BD78-474EC6171B0D}"

#define ProgId_HLP_FormaElementaSprImageGrp "Kas.HLP_FormaElementaSprImageGrp.1"
#define Global_CLSID_THLP_FormaElementaSprImageGrpImpl "{835A98E1-ACE0-474C-A16A-32349875F3F5}"
#define Global_IID_IHLP_FormaElementaSprImageGrp "{09AD94FE-3AC1-46DE-A391-CC6D946F0BE9}"



#define ProgId_HLP_FormaElementaSprNaborInfBlock "Kas.HLP_FormaElSprNaborInfBlock.1"
#define Global_CLSID_THLP_FormaElementaSprNaborInfBlockImpl "{4450CF08-9FA8-4A19-A595-E1C67F5ED1CA}"
#define Global_IID_IHLP_FormaElementaSprNaborInfBlock "{DE645506-E659-4E90-A6B3-33B924E5B7E1}"

#define ProgId_HLP_FormaElementaSprNaborInfBlockGrp "Kas.HLP_FormaElSprNaborInfBlockGrp.1"
#define Global_CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl  "{C186C164-ADBF-4D14-A866-E23D5EEAAF4A}"
#define Global_IID_IHLP_FormaElementaSprNaborInfBlockGrp "{8699D00C-F0DC-45BE-B54A-3DB4F6CC0763}"

#define ProgId_HLP_FormaSpiskaSprNaborInfBlock "Kas.HLP_FormaSpSprNaborInfBlock.1"
#define Global_CLSID_THLP_FormaSpiskaSprNaborInfBlockImpl "{EC8186E9-AEA2-49AD-9A5F-CC9C06363B54}"
#define Global_IID_IHLP_FormaSpiskaSprNaborInfBlock  "{4F8C3280-1361-49D2-A660-046D47E8A0F4}"



#define ProgId_HLP_FormaElementaSprNaborInfBlockSostav "Kas.HLP_FormaElSprNaborInfBlSost.1"
#define Global_CLSID_THLP_FormaElementaSprNaborInfBlockSostavImpl "{023B71FB-1E30-440E-BF96-0764905F13A1}"
#define Global_IID_IHLP_FormaElementaSprNaborInfBlockSostav  "{0C05B36C-D12A-45B5-913A-12C35C9BDC75}"

#define ProgId_HLP_FormaSpiskaSprNaborInfBlockSostav "Kas.HLP_FormaSpSprNaborInfBlSost.1"
#define Global_CLSID_THLP_FormaSpiskaSprNaborInfBlockSostavImpl "{CEC203A7-1689-44A7-865E-FB077FF43C55}"
#define Global_IID_IHLP_FormaSpiskaSprNaborInfBlockSostav "{2C5E54B1-F347-4DE8-98C7-69EB4BDC74B4}"

#define ProgId_HLP_FormaElementaSprNaborInfBlockSostavGrp "Kas.HLP_FormaElSprNaborInfBlSostGrp.1"
#define Global_CLSID_THLP_FormaElementaSprNaborInfBlockSostavGrpImpl "{6BB0AF94-DE6F-4FDF-BD61-50B5B8ECA67C}"
#define Global_IID_IHLP_FormaElementaSprNaborInfBlockSostavGrp "{60192E95-B61A-4C3B-855E-2B0F9CA570C2}"

#define ProgId_HLP_DMSprInfBlockPriv"Kas.HLP_DMSprInfBlockPriv.1"
#define Global_CLSID_THLP_DMSprInfBlockPrivImpl "{803D5C81-1050-4653-BD61-667FB5CC518F}"
#define Global_IID_IHLP_DMSprInfBlockPriv  "{7C291A22-4686-4AC9-B071-E5AB5C4EBD90}"


#define ProgId_DMSprObject "Kas.DMSprObject.1"
#define Global_CLSID_TDMSprObjectImpl "{7868E2F4-E9BE-41B6-93CC-C06B0B76E8CA}"
#define Global_IID_IDMSprObject  "{C8C43FB5-7520-4984-BFFC-D3617C298870}"

#define ProgId_FormaElementaSprObject "Kas.FormaElementaSprObject.1"
#define Global_CLSID_TFormaElementaSprObjectImpl "{2DE12859-EA5D-42BC-AAD7-DD8DD5F0B48A}"
#define Global_IID_IFormaElementaSprObject  "{811A31C0-8882-427B-A16E-1F3EB2052041}"

#define ProgId_FormaSpiskaSprObject "Kas.FormaSpiskaSprObject.1"
#define Global_CLSID_TFormaSpiskaSprObjectImpl "{A6F85C1E-01BB-49B6-B39A-868F2FB46773}"
#define Global_IID_IFormaSpiskaSprObject "{E2EFC767-57A3-48E7-B2EF-1EB3635AE9F9}"


#define ProgId_DMSprTypeNom "Kas.DMSprTypeNom.1"
#define Global_CLSID_TDMSprTypeNomImpl "{33D4EEDD-1A70-44F8-BB26-504110F6FB16}"
#define Global_IID_IDMSprTypeNom "{A7B6D309-F63E-47D3-82F1-86A405CE57BF}"

#define ProgId_FormaElementaSprTypeNom "Kas.FormaElementaSprTypeNom.1"
#define Global_CLSID_TFormaElementaSprTypeNomImpl "{8981AAA0-7D53-4266-8726-39F67ED7040F}"
#define Global_IID_IFormaElementaSprTypeNom "{97717D5C-7C73-4E8E-A7B0-1189D62A9E9F}"

#define ProgId_FormaSpiskaSprTypeNom "Kas.FormaSpiskaSprTypeNom.1"
#define Global_CLSID_TFormaSpiskaSprTypeNomImpl "{C7399719-C67B-4B64-8297-D2834862F021}"
#define Global_IID_IFormaSpiskaSprTypeNom "{4280E508-202B-4DD5-B944-35D9F87F33AB}"




#define ProgId_REM_FormaSpiskaSprHardwareVZip  "Kas.REM_FormaSpSprHardwareVZip.1"
#define Global_CLSID_TREM_FormaSpiskaSprHardwareVZipImpl "{42B6864A-B915-4BFB-9D07-979F4AE0F05E}"
#define Global_IID_IREM_FormaSpiskaSprHardwareVZip "{89D8EDC6-AA2B-4363-811C-4D2A8FE89EEF}"


#define ProgId_REM_DMSprHardwareVZip  "Oberon.REM_DMSprHardwareVZip.1"
#define Global_CLSID_TREM_DMSprHardwareVZipImpl "{EDBBCE66-82BE-4758-A8DC-12D8589305D6}"
#define Global_IID_IREM_DMSprHardwareVZip "{E37C0F3C-3C21-4CF3-91A9-4ACDC9E2F454}"





#define ProgId_FormaSpiskaSprNomVZip "Kas.FormaSpiskaSprNomVZip.1"
#define Global_CLSID_TFormaSpiskaSprNomVZipImpl "{AA744A7D-9564-4B56-8638-860991EB46C3}"
#define Global_IID_IFormaSpiskaSprNomVZip "{3058D175-7D08-491C-AEA9-5684EC76F987}"


#define ProgId_DMSprNomVZip "Oberon.DMSprNomVZip.1"
#define Global_CLSID_TDMSprNomVZipImpl "{5D11C41C-6652-47BB-AE01-DEC2B2AF2116}"
#define Global_IID_IDMSprNomVZip "{39E1F63C-FA2C-4F07-AF9D-8467AD755A7D}"





#define ProgId_REM_DMDocVZipPer "Kas.REM_DMDocVZipPer.1"
#define Global_CLSID_TREM_DMDocVZipPerImpl  "{D52F9A08-C649-4A1E-96EA-E25D2148AC60}"
#define Global_IID_IREM_DMDocVZipPer "{70E45E9B-80A1-4F4E-BD2E-AEEEB3D819BF}"

#define ProgId_REM_FormaDocVZipPer "Kas.REM_FormaDocVZipPer.1"
#define Global_CLSID_TREM_FormaDocVZipPerImpl "{B4704956-EC91-4A6D-8FB8-BE221790C2AF}"
#define Global_IID_IREM_FormaDocVZipPer  "{968207F0-E4CB-4306-B6BC-9A4586D9969C}"


#define ProgId_REM_DMDocVZipVosvratPost "Kas.REM_DMDocVZipVosvratPost.1"
#define Global_CLSID_TREM_DMDocVZipVosvratPostImpl "{DF047A04-8FFB-43F8-93B5-B94D7206A16C}"
#define Global_IID_IREM_DMDocVZipVosvratPost "{FF5A538F-1B77-4530-9979-7066C604F687}"

#define ProgId_REM_FormaDocVZipVosvratPost "Kas.REM_FormaDocVZipVosvratPost.1"
#define Global_CLSID_TREM_FormaDocVZipVosvratPostImpl "{5137A767-D29E-4253-934B-892F14C9465B}"
#define Global_IID_IREM_FormaDocVZipVosvratPost "{1342FFC2-B17D-415E-BD6B-D33EE713A3B1}"



#define ProgId_DMSprStorageLocation  "Kas.DMSprStorageLocation.1"
#define Global_CLSID_TDMSprStorageLocationImpl "{8AD6BF03-59BB-45A3-A3A8-03F6F28B5E09}"
#define Global_IID_IDMSprStorageLocation "{9E330804-2889-4C1D-A002-8017C35449BA}"

#define ProgId_FormaElementaSprStorageLocation  "Kas.FormaElSprStorageLocation.1"
#define Global_CLSID_TFormaElementaSprStorageLocationImpl "{1762CB54-2836-4841-8911-7C5B51BA0C35}"
#define Global_IID_IFormaElementaSprStorageLocation  "{923C027C-4CFB-4626-A91B-D945EEAEC9DA}"

#define ProgId_FormaSpiskaSprStorageLocation  "Kas.FormaSpSprStorageLocation.1"
#define Global_CLSID_TFormaSpiskaSprStorageLocationImpl "{F96453A3-0BEF-4D39-BFE6-1917DB26B63D}"
#define Global_IID_IFormaSpiskaSprStorageLocation "{D3A1B165-1936-417B-AF52-4C68B2BBDAB7}"



#define ProgId_DMSprStorageLocationGrp  "Kas.DMSprStorageLocationGrp.1"
#define Global_CLSID_TDMSprStorageLocationGrpImpl  "{156DBB7F-D7E1-43C5-8E0B-81BF948A2AED}"
#define Global_IID_IDMSprStorageLocationGrp  "{0CD89C5B-FF51-4AD2-A9F9-61B385301CFA}"

#define ProgId_FormaElementaSprStorageLocationGrp  "Kas.FormaElSprStorageLocationGrp.1"
#define Global_CLSID_TFormaElementaSprStorageLocationGrpImpl "{780658C2-97A8-4F9D-8C68-E840DD835266}"
#define Global_IID_IFormaElementaSprStorageLocationGrp "{B8E9C3E4-466C-4F5E-A012-5FA4D850BD52}"




#define ProgId_DMRepDataSet  "Kas.DMRepDataSet.1"
#define Global_CLSID_TDMRepDataSetImpl "{F0D370A5-76B9-44B2-80F9-5C30CB50D6D7}"


#define ProgId_FormaUnReport  "Kas.FormaUnReport.1"
#define Global_CLSID_TFormaUnReportImpl "{2D3519E2-0603-4B11-918E-0D2168546117}"


#define Global_IID_IFormaUnReport "{DB3180CF-E0EE-4CD7-80F6-CC99D3B479AD}"


#define ProgId_DMSprDepartment "Kas.DMSprDepartment.1"
#define Global_CLSID_TDMSprDepartmentImpl "{4949069C-60B5-4AE5-8108-2FBC4A0CDD3D}"

#define ProgId_FormaSpiskaSprDepartment "Kas.FormaSpiskaSprDepartment.1"
#define Global_CLSID_TFormaSpiskaSprDepartmentImpl "{B0D49889-8DEA-49A7-B6EA-C5076D6EAB6F}"

#define ProgId_FormaElementaSprDepartment "Kas.FormaElementaSprDepartment.1"
#define Global_CLSID_TFormaElementaSprDepartmentImpl "{AD6DECBC-24CE-4053-84D3-C3D61CFEFBA7}"

#endif
