//---------------------------------------------------------------------------

#ifndef UFiskRegH
#define UFiskRegH
#include <vcl.h>

class TFiskReg
        {
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllGetTextErrorType(void));
		typedef bool (__import  DllConnectType(int,WideString,WideString));
        typedef void (__import  DllDisconnectType(void));
		typedef bool (__import  DllPrintStringType(WideString,int,int,int,bool,bool, bool));
		typedef bool (__import  DllPrintFiscalCheckType(double,int,double,double,double,double,int));
		typedef bool (__import  DllPrintNoFiscalCheckType(double,int,double,double,double,double,int));
		typedef bool (__import  DllPrintXReportType(void));
        typedef bool (__import  DllPrintZReportType(void));
        typedef bool (__import  DllPrintPoOtdelamReportType(void));
        typedef bool (__import  DllCutType(int));
        typedef bool (__import  DllVnesenieType(double));
        typedef bool (__import  DllSnatieType(double));
        typedef bool (__import  DllPrintLineType(void));

        typedef bool (__import  DllOpenNoFiscalCheckType(void));
        typedef bool (__import  DllCloseNoFiscalCheckType(void));

        typedef bool (__import  DllGetSostKKMType(void));
        typedef bool (__import  DllProvVosmPrintCheckType(void));

        typedef int (__import  DllGetNumberCheckType(void));
        typedef int (__import  DllGetNumberKLType(void));
		typedef WideString (__import  DllGetSerialNumberKKMType(void));
		typedef WideString (__import  DllGetRegNumberKKMType(void));
		typedef WideString (__import  DllGetModelKKMType(void));


		typedef bool (__import  DllSetTimeKKMType(WideString));
		typedef bool (__import  DllSetDateKKMType(WideString));
		typedef WideString (__import  DllGetTimeKKMType(void));
		typedef WideString (__import  DllGetDateKKMType(void));

        DllGetTextErrorType * DllGetTextError;
        DllConnectType * DllConnect;
        DllDisconnectType * DllDisconnect;
        DllPrintStringType * DllPrintString;
        DllPrintFiscalCheckType * DllPrintFiscalCheck;
        DllPrintNoFiscalCheckType * DllPrintNoFiscalCheck;
        DllPrintXReportType * DllPrintXReport;
        DllPrintZReportType * DllPrintZReport;
        DllPrintPoOtdelamReportType * DllPrintPoOtdelamReport;
        DllCutType * DllCut;
        DllVnesenieType * DllVnesenie;
        DllSnatieType * DllSnatie;
        DllPrintLineType * DllPrintLine;

        DllOpenNoFiscalCheckType * DllOpenNoFiscalCheck;
        DllCloseNoFiscalCheckType * DllCloseNoFiscalCheck;

        DllGetSostKKMType * DllGetSostKKM;
        DllProvVosmPrintCheckType * DllProvVosmPrintCheck;

        DllGetNumberCheckType * DllGetNumberCheck;
        DllGetNumberKLType * DllGetNumberKL;
		DllGetSerialNumberKKMType * DllGetSerialNumberKKM;
		DllGetRegNumberKKMType * DllGetRegNumberKKM;
		DllGetModelKKMType * DllGetModelKKM;

		DllGetTimeKKMType * DllGetTimeKKM;
		DllGetDateKKMType * DllGetDateKKM;
		DllSetTimeKKMType * DllSetTimeKKM;
		DllSetDateKKMType * DllSetDateKKM;
 public:
        TFiskReg();
        ~TFiskReg();


        int Number;
		AnsiString Modul;
		UnicodeString Name;
        bool Error;
		UnicodeString TextError;
		UnicodeString TextErrorNoConnect;
		bool ConnectFR;


        bool Init();

        bool Connect(int number_port,
						UnicodeString baud_rate,
						UnicodeString password);

        bool Disconnect(void);

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
        bool Vnesenie(float sum);
        bool Snatie(float sum);

        bool PrintLine(void);

        bool OpenNoFiscalCheck(void);
        bool CloseNoFiscalCheck(void);

        bool GetSostKKM(void);
        bool ProvVosmPrintCheck(void);

        //параметры   ћ и чека
                int NumberCheck;
                int NumberKL;
				UnicodeString SerialNumberKKM;
				UnicodeString RegNumberKKM;
				UnicodeString ModelKKM;

		//врем€ и дата
		TTime GetTime(void);
		TDate GetDate(void);
		bool SetTime(TTime time);
		bool SetDate(TDate date);


        };
//---------------------------------------------------------------------------
#endif
