//---------------------------------------------------------------------------

#ifndef UDMH
#define UDMH
#define MESSAGE_READY WM_USER
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBDatabase.hpp>
#include <ImgList.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include "pFIBDatabase.hpp"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "cxStyles.hpp"
#include "cxLocalization.hpp"
#include "cxEdit.hpp"
#include "cxEditRepositoryItems.hpp"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
        TImageList *ImageList1;
	TpFIBDatabase *pFIBData;
	TpFIBTransaction *pFIBTr;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *pFIBQLog;
	TpFIBTransaction *pFIBTrLog;
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
	TpFIBQuery *Query;
	TpFIBDataSet *UserInfo;
	TFIBSmallIntField *UserInfoTPOSREPORT_SUSER;
	TFIBSmallIntField *UserInfoTPOSGOURNAL_SUSER;
	TFIBSmallIntField *UserInfoKOLDAYREP_SUSER;
	TFIBSmallIntField *UserInfoKOLDAYGUR_SUSER;
	TFIBBCDField *UserInfoID_USER;
	TFIBBCDField *UserInfoIDPOD_USER;
	TFIBBCDField *UserInfoIDFIRM_USER;
	TFIBBCDField *UserInfoIDSKLAD_USER;
	TFIBBCDField *UserInfoIDTPRICE_USER;
	TFIBBCDField *UserInfoIDTPRICE1_USER;
	TFIBBCDField *UserInfoIDTPRICE2_USER;
	TFIBBCDField *UserInfoIDBSCHET_USER;
	TFIBBCDField *UserInfoIDGRP_USER;
	TFIBBCDField *UserInfoIDKASSA_USER;
	TFIBBCDField *UserInfoIDBASE_SUSER;
	TFIBSmallIntField *UserInfoREOPEN_GUR_SUSER;
	TFIBSmallIntField *UserInfoREOPEN_SPR_SUSER;
	TFIBSmallIntField *UserInfoSPRNOM_OST_SUSER;
	TFIBIntegerField *UserInfoEDIT_CHUG_DOC_SUSER;
	TFIBIntegerField *UserInfoDEL_CHUG_DOC_SUSER;
	TFIBSmallIntField *UserInfoSHOW_LOG_SUSER;
	TFIBSmallIntField *UserInfoDETALIED_LOG_SUSER;
	TFIBSmallIntField *UserInfoSAVENAME_SUSER;
	TFIBWideStringField *UserInfoNAME_USER;
	TFIBWideStringField *UserInfoFNAME_USER;
	TFIBIntegerField *UserInfoINTERF_USER;
	TFIBWideStringField *UserInfoNAMEPOD;
	TFIBWideStringField *UserInfoNAMEFIRM;
	TFIBWideStringField *UserInfoNAMESKLAD;
	TFIBWideStringField *UserInfoNAME_TPRICE;
	TFIBWideStringField *UserInfoNAME_SINFBASE_OBMEN;
	TFIBWideStringField *UserInfoNAMEBSCHET;
	TFIBWideStringField *UserInfoNAMEKKM;
	TFIBWideStringField *UserInfoNAME2_USER;
	TpFIBTransaction *TransactionUserInfo;
	TpFIBTransaction *Transaction;
	TpFIBDataSet *ARMInfo;
	TFIBLargeIntField *ARMInfoID_SARM;
	TFIBWideStringField *ARMInfoNAME_SARM;
	TFIBIntegerField *ARMInfoCODE_SARM;
	TFIBLargeIntField *ARMInfoIDFIRM_SARM;
	TFIBLargeIntField *ARMInfoIDSKLAD_SARM;
	TFIBLargeIntField *ARMInfoIDPODR_SARM;
	TFIBLargeIntField *ARMInfoIDKKM_SARM;
	TFIBWideStringField *ARMInfoSTRPAR_SARM;
	TFIBWideStringField *ARMInfoNAMEFIRM;
	TFIBWideStringField *ARMInfoNAMESKLAD;
	TFIBWideStringField *ARMInfoNAMEKKM;
	TFIBWideStringField *ARMInfoNAMEPOD;
	TFIBLargeIntField *ARMInfoIDTPRICEPOD;
	TFIBWideStringField *ARMInfoNAME_TPRICE;
	TFIBWideStringField *ARMInfoNAME_SINFBASE_OBMEN;
	TpFIBTransaction *TransactionARM;
	TFIBLargeIntField *ARMInfoIDBASE_SARM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDM(TComponent* Owner);

        bool GlobConnect(void);
		bool GlobConnect2(void);
		bool GlobConnect3(void);

		void DisconnectBase(void);

		UnicodeString GetNameServer(UnicodeString connect_string);
		UnicodeString NameServer;
		UnicodeString ConnectString;
		UnicodeString NameUser;
		UnicodeString NameUser2;
		UnicodeString PasswordUser;
		UnicodeString glCatalogProtocol;
		int CodeUser;
        

        bool Error;
		UnicodeString TextError;
		UnicodeString GetVersionBase(void);
		UnicodeString TextVipOper;

		bool CheckEnableStart(UnicodeString role_user);

		int TypeApplication;

		__int64 FindPoName(UnicodeString name_user);
		__int64 FindPoPassword(UnicodeString password);
		__int64 GetIdGrpUser(__int64 id_user);

		TDateTime GetPosNachReport(void);
		TDateTime GetPosNachGurnal(void);

		bool OpenUserInfo(__int64 id);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		bool GetPrivDM(int object);
		//application 1 обычное, 2 WEB
		bool GetPrivForm(int object);
		bool OpenARMInfo(int code_arm);


		void glSaveProtocol(UnicodeString str);
		void AddLog(__int64 id_user,
					int type,
					int object,
					int oper,
					UnicodeString message,
					UnicodeString code_object,
					__int64 id_object,
					int subsystem);

//type
//1 сообщение
//2 предупреждение
//3 ошибка
//4 запрещенное действие
//object
//1 справочник
//2 документ
//3 журнал
//4 отчет
//5 сервис
//oper
//  1 вставка
//  2 редактирование
//  3 удаление



	bool glShowNDS;


    UnicodeString Arm_GetParameter(UnicodeString parameter);

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
//UnicodeString ConvertString(UnicodeString s1, UnicodeString s2, UnicodeString s3);   //«аменить в строке s1 все вхождени€ s2 на s3
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
