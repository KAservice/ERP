//---------------------------------------------------------------------------

#ifndef UkasVikiH
#define UkasVikiH
//---------------------------------------------------------------------------


#include <vcl.h>
#include "GlobalInterface.h"
class TkasVikiFR
		{
private:


UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len);
void OpenDrawer(void);
int CompareDoubleValue(double v1, double v2, int pogr);

		bool PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 продажа 1 возврат

		bool PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 продажа 1 возврат


		int KolSymbolSize1;
		int KolSymbolSize1Girn;
		int KolSymbolSize2;
		int KolSymbolSize2Girn;
		int KolSymbolSize3;
		int KolSymbolSize3Girn;
		int KolSymbolSize4;
		int KolSymbolSize4Girn;
 public:
		TkasVikiFR();
		~TkasVikiFR();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации



bool NoPrint;
bool UseJournalRibbon;
bool UseReceiptRibbon;
bool OpenNoFiscalDoc;


		int Number;
		AnsiString Modul;
		UnicodeString Name;
		bool Error;
		int CodeError;
		UnicodeString TextError;
		UnicodeString TextErrorNoConnect;
		bool ConnectFR;

		int Init();
		int Done();


		bool Connect(int number_port,
						UnicodeString baud_rate,
						UnicodeString password);

		bool Disconnect(void);

		bool GetSostKKM(void);
		bool ProvVosmPrintCheck(void);


		bool PrintString(UnicodeString str,
                                int size_font,       //1234
                                int girn,            //1-жирный 0 обычный
                                int alignment,      //0 лево 1 центр 2 право
                                bool ch_lenta,       //на чековой ленте
								bool kontr_lenta,   //на контрольной ленте
								bool word_wrap);


        bool PrintFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation);    //0 продажа 1 возврат







		bool PrintNoFiscalCheck(double sum,
                                int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 продажа 1 возврат

        bool PrintXReport(void);
        bool PrintZReport(void);
        bool PrintPoOtdelamReport(void);

        bool Cut(int TypeCut);
		bool Vnesenie(double sum);
        bool Snatie(double sum);

        bool PrintLine(void);

        bool OpenNoFiscalCheck(void);
        bool CloseNoFiscalCheck(void);


        //параметры ККМ и чека
                int NumberCheck;
                int NumberKL;
				UnicodeString SerialNumberKKM;
				UnicodeString RegNumberKKM;
				UnicodeString ModelKKM;

		//время и дата
		TTime GetTime(void);
		TDate GetDate(void);
		bool SetTime(TTime time);
		bool SetDate(TDate date);


		};








#endif
