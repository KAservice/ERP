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
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDM(TComponent* Owner);

        bool GlobConnect(void);
		bool GlobConnect2(void);
		bool GlobConnect3(void);

		void DisconnectBase(void);

		AnsiString GetNameServer(AnsiString connect_string);
		AnsiString NameServer;
        String ConnectString;
		String NameUser;
		String NameUser2;
        String PasswordUser;
		String glCatalogProtocol;
		int CodeUser;
        

        bool Error;
        AnsiString TextError;
		AnsiString GetVersionBase(void);
		AnsiString GetVersionProgramFile(void);
		AnsiString TextVipOper;

		bool CheckEnableStart(AnsiString role_user);

};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;

String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);
String AddEAN13(String Cod);
void glSaveProtocol(String str);
String glGetNameDoc(String StrCodeDoc);
AnsiString glGetNameDocRemont(AnsiString str_code_doc);
AnsiString glGetNameDocHotel(AnsiString StrCodeDoc);
AnsiString triada(AnsiString in, int tn);
AnsiString ValuePropis(AnsiString in);
String CurrencyPropis(double Value);
String IntegerValuePropis(int Value);
AnsiString CommaToPixel(String value);
AnsiString ConvertString(AnsiString s1, AnsiString s2, AnsiString s3);   //Заменить в строке s1 все вхождения s2 на s3
__int64 glStrToInt64(AnsiString value);
AnsiString glFormatForXML(AnsiString s);
//---------------------------------------------------------------------------
char*
WriteSum (double v,char *buf,bool kop,bool up) ;

//---------------------------------------------------------------------------
float glGetKolProgiv1(TDateTime Nach, TDateTime Con);
//----------------------------------------------------------------------------


        struct TElementSpiskaPrintPrice
                {
				__int64 Id;
                AnsiString Name;
                __int64 IdEd;
                AnsiString NameEd;
                bool Grp; //это группа
                int Kol;//Количество
                };

        struct TElementSpiskaPerObject
                {
                AnsiString name;
                AnsiString value;
                };

AnsiString GetBinareStructEAN13(AnsiString sh_code);

double RoundValue(double value, int  rasr);
void AddLog(__int64 id_user,
					int type,
					int object,
					int oper,
					AnsiString message,
					AnsiString code_object,
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

int GetRateNDS(int code);

int glCompareDoubleValue(double v1, double v2, int pogr);

#endif
