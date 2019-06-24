

#include <vcl.h>
#include <windows.h>


//---------------------------------------------------------------------------
//#include <Classes.hpp>
//#include <Controls.hpp>
//#include <StdCtrls.hpp>
//#include <Forms.hpp>

#include "MercFPrtX_TLB.h"


#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
extern "C" char * __declspec (dllexport) GetTextError(void);

extern "C" bool __declspec (dllexport) Connect(int number_port,
                                                char* baud_rate,
                                                char* password);
extern "C" void __declspec (dllexport) Disconnect(void);

extern "C" bool __declspec (dllexport) GetSostKKM(void);
extern "C" bool __declspec (dllexport) ProvVosmPrintCheck(void);
extern "C" int __declspec (dllexport) GetNumberCheck(void);
extern "C" int __declspec (dllexport) GetNumberKL(void);
extern "C" char* __declspec (dllexport) GetSerialNumberKKM(void); 

extern "C" void __declspec (dllexport)  OpenNoFiscalCheck(void);
extern "C" bool __declspec (dllexport)  CloseNoFiscalCheck(void);
extern "C" bool __declspec (dllexport) PrintString(char* str,
                                                int size_font,       //1234
                                                int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
                                                int alignment,       //0 лево 1 центр 2 право
                                                bool ch_lenta,       //на чековой ленте
                                                bool kontr_lenta);   //на контрольной ленте

extern "C" bool __declspec (dllexport) PrintLine(void);


extern "C" bool __declspec (dllexport) PrintFiscalCheck(double sum,
                                                        int department,
                                                        double oplata_nal,
                                                        double oplata_plat_card,
                                                        int operation);    //0 продажа 1 возврат

extern "C" bool __declspec (dllexport) PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
                                double oplata_plat_card,
                                int operation);    //0 продажа 1 возврат

extern "C" bool __declspec (dllexport) PrintXReport(void);
extern "C" bool __declspec (dllexport) PrintZReport(void);
extern "C" bool __declspec (dllexport) PrintPoOtdelamReport(void);

extern "C" bool __declspec (dllexport) Cut(int TypeCut);

extern "C" bool __declspec (dllexport) Vnesenie(double sum);
extern "C" bool __declspec (dllexport) Snatie(double sum);

AnsiString TextError;

bool ConnectFR=false;
bool NoPrint;
bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

IMercuryFPrt *Merc;
String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);

//------------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}

//---------------------------------------------------------------------------
char *  GetTextError(void)
{
char * result="";
result=TextError.c_str();
return result;
}
//---------------------------------------------------------------------------


bool  Connect(int number_port,
                char* baud_rate,
                char* password)
{

bool result=false;
NoPrint=false;
UseJournalRibbon=true;
UseReceiptRibbon=true;
OpenNoFiscalDoc=false;

        CLSID clsid;
        IClassFactory* pCF;
        IUnknown* pUnk;

        
        CoInitialize(0);

        HRESULT hr = ::CLSIDFromProgID( L"Incotex.MercuryFPrtCOM", &clsid );

        if ( FAILED( hr ))
        {
	        TextError="Не Получили CLSID";
	        //return ;
        }
        else
                {
                //ShowMessage("Получили CKSID");
                }
//------------------------------------------------------------

        hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF );
        if ( FAILED( hr ))
        {
        TextError="Не Соединились с объектом";
        }
        else
                {
                //ShowMessage("Соединились с объектом");
                }

//------------------------------------------------------

        hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk );
        pCF->Release();
        if ( FAILED( hr ))
        {
	TextError="Не Создали интерфейс";
        }
        else
                {
                //ShowMessage("Создали интерфейс");
                 }

//--------------------------------------------------
        Merc = NULL;


        hr = pUnk->QueryInterface( IID_IMercuryFPrt7, (void**) &Merc);
        pUnk->Release();


        if ( FAILED( hr ))
        {
	TextError="Не Создали рабочий интерфейс";
        }
        else
                {
                //ShowMessage("Создали рабочий интерфейс");
                }

try
        {


        Merc->PortNum=number_port;
        Merc->BaudRate=StrToInt(baud_rate);
        Merc->ExternalTimeout=30000;
        Merc->InternalTimeout=500;
        AnsiString pass=password;
        //Merc->Password=WideString("0000").c_bstr();


        Merc->Open();

      //  Merc->OpenDay(1, WideString("0000").c_bstr(), false, Merc->Protocol);




        if (Merc->ErrCodeEx!= 0)
                {

                result=false;
                TextError="Не удалось подключиться к ФР! Ошибка: "+WideCharToString(Merc->ErrMessage) ;
                //ShowMessage(TextError);
                }
        else
                {
                //ShowMessage("Ошибок нет");
                result=true;
                ConnectFR=true;
                }
        }
catch (...)
        {
        result=false;
        TextError="Не удалось подключиться к ФР! Ошибка: "+WideCharToString(Merc->ErrMessage);
        ConnectFR=false;
        }
return result;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{

Merc->Close(true);
ConnectFR=false;
CoUninitialize();

}
//---------------------------------------------------------------------------

bool  GetSostKKM(void)
{
bool result=true;

Merc->QueryLastDocInfo();
Merc->QueryResourceInfo(false);



return result;
}
//---------------------------------------------------------------------------
bool  ProvVosmPrintCheck(void)
{
bool result=true;

GetSostKKM();
//ShowMessage(IntToStr(Merc->DevStatus));
switch (Merc->DevStatus)
        {
        case MERC_DS_OPENED_COVER :      //идет печать предыдущей команды
                {
                ShowMessage("Открыта крышка принтера! MERC_DS_OPENED_COVER");
                result=false;
                return result;
                }

        case MERC_DS_PRINTER_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка принтера! MERC_DS_PRINTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_MECHANICAL_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка  механики принтера! MERC_DS_MECHANICAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_CUTTER_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка  отрезчика! MERC_DS_CUTTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_FATAL_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Критическая ошибка принтера! MERC_DS_FATAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_OVERHEATING :      //идет печать предыдущей команды
                {
                ShowMessage("Перегрев печатающей головки! MERC_DS_OVERHEATING ");
                result=false;
                return result;
                }

        case MERC_DS_JOURNAL_OUT :      //идет печать предыдущей команды
                {
                ShowMessage("Нет контрольной ленты! MERC_DS_JOURNAL_OUT");
                result=false;
                return result;
                }

        case MERC_DS_RECEIPT_OUT :      //идет печать предыдущей команды
                {
                ShowMessage("Нет чековой ленты! MERC_DS_RECEIPT_OUT");
                result=false;
                return result;
                } 

        default :
                {


                } break;

        }

if (Merc->DocStatus!=mdsClosed)
        {
        Merc->CancelFiscalDoc(false);
        }


return result;

}
//---------------------------------------------------------------------------
int GetNumberCheck(void)
{
int result=0;

result=Merc->LastRecNumber+1;




return result;

}
//---------------------------------------------------------------------------
int  GetNumberKL(void)
{
int result=0;

result=Merc->LastDayClosing+1;



return result;

}
//---------------------------------------------------------------------------
char*  GetSerialNumberKKM(void)
{
char* result="";
AnsiString num=Merc->SerialNumber;
result=num.c_str();


return result;

}
//---------------------------------------------------------------------------

void   OpenNoFiscalCheck(void)
{

Merc->PrintNonFiscal(WideString("").c_bstr(), true,false);
}
//---------------------------------------------------------------------------
bool   CloseNoFiscalCheck(void)
{
bool result=true;

Merc->PrintNonFiscal(WideString("").c_bstr(), false,true);


return result;

}
//---------------------------------------------------------------------------
bool  PrintString(char* str,
                                                int size_font,       //1234
                                                int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
                                                int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
                                                bool kontr_lenta)   //на контрольной ленте
{
bool result=false;
AnsiString s=AnsiString(str);


if (ConnectFR==false){return result;}

        switch ( size_font)
                {
                case  1:
						{
						s=" "+s;
						if(s.Length()>40) s=s.SetLength(40);
                        switch ( alignment)
                                {
								case  0:      //лево
                                        {
										if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  2:
						{
						s=" "+s;
						if(s.Length()>40) s=s.SetLength(40);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  3:
						{
						if(s.Length()>14) s=s.SetLength(14);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }

                        break;
                        }
                case  4:
						{
						if(s.Length()>14) s=s.SetLength(14);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }


                }
        
result=true;


return result;

}
//---------------------------------------------------------------------------
bool  PrintLine(void)
{
bool result=false;


Merc->PrintNonFiscal(WideString("\\1b\\21\\----------------------------------------\\0d\\0a").c_bstr(), false,false);

return result;

}
//---------------------------------------------------------------------------


bool  PrintFiscalCheck(double sum,
                        int department,
                        double oplata_nal,
                        double oplata_plat_card,
                        int operation)    //0 продажа 1 возврат
{
bool result=false;

NoPrint=false;


if (ConnectFR==false){return result;}
if ((oplata_nal+oplata_plat_card)<sum)
        {
        TextError="Сумма оплаты меньше суммы чека!";
        return result;
        }


//проверим открыта ли смена
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
                Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
                }
        catch(...)
                {
                result=false;
                return result;
                }
        }

if (operation==0) // Составной чек на продажу
        {
        Merc->OpenFiscalDoc(motSale);
        }//конец печати чека продажи
else
        {
        Merc->OpenFiscalDoc(motRefund);
        }

  try
  {
    // Счетчик вертикальной координаты
    int IV = 0;
//    MSK->AddCustom("ВСЕГО:", 0, 0, IV); IV++;

     Variant vopl1=oplata_nal ;
     Variant vopl4=oplata_plat_card  ;
    // Добавляем итог
    Merc->AddTotal(0, 0, IV, 0); IV++;


    // Добавляем информацию об оплате
    Merc->AddPay(
      mptCashCard,      // - оплата: наличные + платежная карта
      vopl1,             // - сумма оплаты наличными
      vopl4,               // - сумма оплаты по безналу
      WideString(" ").c_bstr(),               // - дополнительная информация по оплате - игнорируется для комбинированной
                        //   оплаты
      0,
      0,
      IV,
       0); IV++;



    // Добавляем сумму сдачи
    Merc->AddChange(0, 0, IV++, 0);

    
    // Добавляем строки заголовка
    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
    // - наименование товара, как дополнительный реквизит
    Variant vSumCheck=sum;

    Merc->AddItem(
      mitItem,          // - услуга или товар
      vSumCheck,              // - цена товара
      false,            // - товар не является тарой
      1,                // - номер отдела
      0,              // - код товара
      0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
      0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
      0,                // - флаги
      0,                // - смещение по вертикали
      IV,               // - смещение по горизонтали
      0                 // - игнорируется
    ); IV++;

    // Добавляем номер ККМ и номер документа (на одной строке)
    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
    // Добавляем ИНН
    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
    // Добавляем дату / время и номер чека (на одной строке)
    Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
    // Добавляем информацию об операторе
    Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;


    // Закрываем документ
    Merc->CloseFiscalDoc();
    result=true;
  }
  catch(...)            //Exception &E
  {
    // В случае ошибки отменяем открытый документ
    Merc->CancelFiscalDoc(false);
    result=false;
    throw;
  }


return result;

}
//---------------------------------------------------------------------------
bool  PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
                                double oplata_plat_card,
                                int operation)    //0 продажа 1 возврат
{
bool result=false;

NoPrint=false;

if (ConnectFR==false){return result;}

if ((oplata_nal+oplata_plat_card)<sum)
        {
        TextError="Сумма оплаты меньше суммы чека!";
        return result;
        }

Merc->PrintNonFiscal(WideString("------------------------------------\r\n").c_bstr(), true,true);
Merc->PrintNonFiscal(WideString("Учебный чек напечатан!\r\n").c_bstr(), true,true);


for(int i=0;i<20;i++)
        {
        Merc->PrintNonFiscal(WideString(" \r\n").c_bstr(), true,true);
        }
result=true;

return result;

}
//---------------------------------------------------------------------------
bool  PrintXReport(void)
{
bool result=false;

NoPrint=false;
//проверим открыта ли смена
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
                Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
                }
        catch(...)
                {
                result=false;
                return result;
                }
        }
        try
                {
                Merc->XReport(1);
                result=true;
                }
        catch(...)
                {
                result=false;
                ShowMessage("Ошибка при печати отчета");
                }


return result;

}
//---------------------------------------------------------------------------
bool PrintZReport(void)
{
bool result=false;


NoPrint=false;
if (ConnectFR==true)
        {
 //проверим открыта ли смена
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
                Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
                }
        catch(...)
                {
                result=false;
                return result;
                }
        }
        try
                {
                Merc->ZReport(MERC_REPF_NO_ZEROES && MERC_REPF_ACCUMULATE_DEP);
                result=true;
                }
        catch(...)
                {
                result=false;
                ShowMessage("Ошибка при печати отчета");
                }
        }

return result;

}
//---------------------------------------------------------------------------
bool  PrintPoOtdelamReport(void)
{
bool result=false;




return result;

}
//---------------------------------------------------------------------------

bool  Cut(int TypeCut)
{
bool result=true ;

Merc->FeedAndCut(1,true);


return result;

}
//---------------------------------------------------------------------------

bool  Vnesenie(double sum)
{
bool result=false;

if (ConnectFR==true)
        {



  try
  {

        //проверим открыта ли смена
       // if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
       //         {
       //         Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
       //         }



    Merc->OpenFiscalDoc(motCashIn);
    // Счетчик вертикальной координаты
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // Добавляем итог
    Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;



    // Добавляем строки заголовка
    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
    // - наименование товара, как дополнительный реквизит
    Variant vSumCheck=sum;

    Merc->AddItem(
      mitItem,          // - услуга или товар
      vSumCheck,              // - цена товара
      false,            // - товар не является тарой
      1,                // - номер отдела
      0,              // - код товара
      0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
      0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
      0,                // - флаги
      0,                // - смещение по вертикали
      IV,               // - смещение по горизонтали
      0                 // - игнорируется
    ); IV++;

    // Добавляем номер ККМ и номер документа (на одной строке)
    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
    // Добавляем ИНН
    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
    // Добавляем дату / время и номер чека (на одной строке)
    Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
    // Добавляем информацию об операторе
    Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;


    // Закрываем документ
    Merc->CloseFiscalDoc();
    result=true;
  }
  catch(...)            //Exception &E
  {
    // В случае ошибки отменяем открытый документ
    Merc->CancelFiscalDoc(false);
    result=false;
    throw;
  }
        }
return result;

}
//---------------------------------------------------------------------------
bool  Snatie(double sum)
{
bool result=false;

if (ConnectFR==true)
        {



  try
  {
        //проверим открыта ли смена
        //if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        //        {
        //        Merc->OpenDay(1, WideString("Кассир").c_bstr(), false, Merc->Protocol);
        //        }
    Merc->OpenFiscalDoc(motCashOut);

    // Счетчик вертикальной координаты
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // Добавляем итог
    Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;



    // Добавляем строки заголовка
    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
    // - наименование товара, как дополнительный реквизит
    Variant vSumCheck=sum;

    Merc->AddItem(
      mitItem,          // - услуга или товар
      vSumCheck,              // - цена товара
      false,            // - товар не является тарой
      1,                // - номер отдела
      0,              // - код товара
      0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
      0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
      0,                // - флаги
      0,                // - смещение по вертикали
      IV,               // - смещение по горизонтали
      0                 // - игнорируется
    ); IV++;

    // Добавляем номер ККМ и номер документа (на одной строке)
    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
    // Добавляем ИНН
    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
    // Добавляем дату / время и номер чека (на одной строке)
    Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
    // Добавляем информацию об операторе
    Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;


    // Закрываем документ
    Merc->CloseFiscalDoc();
    result=true;
  }
  catch(...)            //Exception &E
  {
    // В случае ошибки отменяем открытый документ
    Merc->CancelFiscalDoc(false);
    result=false;
    throw;
  }
        }


return result;

}
//---------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
String DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
String DopStrR(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
