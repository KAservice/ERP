//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "AddInLib_TLB.h"

#pragma argsused
extern "C" char * __declspec (dllexport) GetTextError(void);

extern "C" bool __declspec (dllexport) Connect(int port,   //порт,  1,2,3,
												int baud_rate);//скорость 57600,9600 и др.
//настройка принтера и этикеток
extern "C" bool __declspec (dllexport) SetSetup(char*);


extern "C" void __declspec (dllexport) Disconnect(void);

extern "C" bool __declspec (dllexport) GetSostPrinter(void);
extern "C" bool __declspec (dllexport) ProvVosmPrint(void);

extern "C" bool __declspec (dllexport)  OpenDoc(void);
extern "C" bool __declspec (dllexport)  CloseDoc(void);

extern "C" bool __declspec (dllexport) PrintString(char* string_print,
												int size_font,      //размер шрифта 1,2,3,4
												int style,           // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												char * name_font,
												bool word_wrap);


extern "C" bool __declspec (dllexport) PrintLine(void);

extern "C" bool __declspec (dllexport) PrintBarCode(char* bar_code, //штрих-код
														int otstup,         //отступ слева
														int type_bar_code,  //тип штрих кода
														int size_font_bar_code,  //размер штрих кода
														int height); 		//высота




AnsiString TextError;

String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);
ILanguageExtender *Prn;
HINSTANCE dllIn;

typedef void (__import  DllOpenPortType(char *));
DllOpenPortType * DllOpenPort;

typedef void (__import  DllClosePortType(void));
DllClosePortType * DllClosePort;

typedef int (__import  DllIsReadyType(void));
DllIsReadyType * DllIsReady;

typedef void (__import  DllForwardType(char *));
DllForwardType * DllForward;

typedef void (__import  DllPrintBarType(char *,char *,char *,char *,char *,char *,char *));
DllPrintBarType * DllPrintBar;

//Напечатать внутренним шрифтом
typedef void (__import  DllPrintFontType(char *,         //a: (string) отступ слева
											char *,      //b: (string)увеличить по горизонтали в 1  7 раз
											char *,      //c: (string) увеличить по вертикали в 1  4 раза
											char*));    //d: (string) данные
DllPrintFontType * DllPrintFont;

//Напечатать шрифтом WINDOWS
typedef void (__import  DllTextOutType(int,           //a: (integer) отступ слева в точках
										int,      //b: (integer) высота текста
										char*,   //c: (string) имя шрифта
										char*)); //d: (string) данные
DllTextOutType * DllTextOut;


//Описание: Перевод страницы
typedef void (__import  DllFormFeedType(void));
DllFormFeedType * DllFormFeed;

//Описание: Установить параметры принтера EZ-2/4
//Команда: setup(a,b,c,d,e,f)
typedef void (__import  DllSetSetupType(int,   // a: (integer) размер этикетки (в мм.)
										int,   //b: (integer) яркость печати (0~7)
										int,   //c: (integer) скорость печати (1~2)
										int,   //d: (integer) тип этикетки:
														//0: этикетки со светлым промежутком
														//1: Этикетки с черным промежутком
														//2: Лента
										int,   //e: (integer) промежуток между этикетками (в мм.)
										int)); //f: (integer) отступ от черной метки для этикеток с черным промежутком
DllSetSetupType * DllSetSetup;




AnsiString StrParameter;
AnsiString GetParameter(AnsiString parameter);
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


bool  Connect(int number_port,	int baud_rate)
{
bool result=false;
dllIn=LoadLibrary("EZNT.dll");

	if(dllIn)
		{
		DllOpenPort=(DllOpenPortType*)GetProcAddress(dllIn,"openport");
		DllClosePort=(DllClosePortType*)GetProcAddress(dllIn,"closeport");
		DllIsReady=(DllIsReadyType*)GetProcAddress(dllIn,"isready");
		DllForward=(DllForwardType*)GetProcAddress(dllIn,"forward");
		DllPrintBar=(DllPrintBarType*)GetProcAddress(dllIn,"printbar");
		DllPrintFont=(DllPrintFontType*)GetProcAddress(dllIn,"printfont");
		DllTextOut=(DllTextOutType*)GetProcAddress(dllIn,"ecTextOut");
		DllFormFeed=(DllFormFeedType*)GetProcAddress(dllIn,"formfeed");
		DllSetSetup=(DllSetSetupType*)GetProcAddress(dllIn,"setup");

		try
			{
			DllOpenPort("0");
			//DllForward("100");
			//DllFormFeed();
			result=true;
			}
		catch(Exception &exception)
			{
			result=false;
			TextError=exception.Message;
			} 
        }
	else
	   {
	   TextError="ошибка загрузки библиотеки: EZNT.dll!";
	   result=false;
	   return result;
	   }

return result;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{
DllFormFeed();
DllClosePort();
FreeLibrary(dllIn); 
}
//---------------------------------------------------------------------------

bool  GetSostPrinter(void)
{
bool result=false;
if (DllIsReady()==1)
	{
	result=true;
	}
else
	{
	result=false;
	}  
return result;
}
//---------------------------------------------------------------------------
bool  ProvVosmPrint(void)
{
bool result=true;
if (DllIsReady()==1)
	{
	result=true;
	}
else
	{
	result=false;
	}
result=true;
return result;
}
//---------------------------------------------------------------------------
bool   OpenDoc(void)
{
bool result=true;

return result;
}
//---------------------------------------------------------------------------
bool   CloseDoc(void)
{
bool result=true;

return result;

}
//---------------------------------------------------------------------------
bool  PrintString(char* string_print,
												int size_font,      //размер шрифта 1,2,3,4
												int style,            // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												char * name_font,    //
												bool word_wrap)   //перенос по словам
{
bool result=true;
//			//Напечатать шрифтом WINDOWS
String otstup=10;
int height_font=30;
AnsiString str_name_font="Arial";


//			DllTextOut(otstup,           //a: (integer) отступ слева в точках
//						height_font,      //b: (integer) высота текста
//						str_name_font,   //c: (string) имя шрифта
//						string_print); //d: (string) данные

			DllTextOut(10,           //a: (integer) отступ слева в точках
						30,      //b: (integer) высота текста
						"Fixedsys",   //c: (string) имя шрифта
						string_print); //d: (string) данные

//			DllPrintFont(otstup.c_str(),         		//a: (string) отступ слева
//							"1",      			//b: (string)увеличить по горизонтали в 1  7 раз
//							"1",      			//c: (string) увеличить по вертикали в 1  4 раза
//							string_print);    //d: (string) данные
return result;
}
//---------------------------------------------------------------------------
bool  PrintLine(void)
{
bool result=true;


return result;

}
//----------------------------------------------------------------------------
bool PrintBarCode(char* bar_code, //штрих-код
					int otstup,         //отступ слева
					int type_bar_code,  //тип штрих кода
					int size_font_bar_code,  //размер штрих кода
					int height		//высота
					)
{
bool result=false;
DllForward("5");

DllPrintBar("10",				//a: (string) отступ слева
					"E",				//b: (string) тип штрих-кода
											//	0 = CODE 128 C/B
											//	1 = CODE 128 B/C
											//	2 = Interleaved 2 of 5
											//	3 = CODE 39
											//		9 = CODE 93
											//		K = CODA bar code
											//		U = UPC A/E, *UPC A/E + add on 2/5
											//		E = EAN 8/13, *EAN 8/13 + add on 2/5
					"3",				//c: (string) размер шрифта ш.к. (1 - 10 точек)
					"30",				//d: (string) плотность к ширине (2 - 30)
					"30",				//e: (string) высота в мм.
					bar_code,		//f: (string) данные
					"1");				//g: (string) дублировать ли данные в читаемом виде
										//под штрих - кодом
										//0 = дублировать
										//1 = нет, только штрих - код


										
//	prn->PrintBarCode(ed->ElementSHED->AsString.c_str(),
//								5,  //отступ слева
//								1,  //тип штрих кода
//								10,  //размер штрих кода
//								30); //высота





result=true;
return result;
}
//----------------------------------------------------------------------------
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
AnsiString GetParameter(AnsiString parameter)
{
AnsiString str_parameter=StrParameter;
AnsiString result="";
int position=0;
position=str_parameter.AnsiPos(parameter);
if (position!=0)
		{
		str_parameter.Delete(1,position+parameter.Length());
		for(int i=1; i<=str_parameter.Length();i++)
				{
				if (str_parameter[i]==';')
						{
						 break;
						}
				else
						{
						 result=result+str_parameter[i];
						}
				}
		}
return result;
}
//----------------------------------------------------------------------------
bool  SetSetup(char* str_parameter)
{
bool result=true;
StrParameter=str_parameter;

//размер этикетки
AnsiString str_size_label=GetParameter("HeightLabel");
int size_label=0;
if (str_size_label=="")
	{
	size_label=30;
	}
else
	{
	size_label=StrToInt(str_size_label);
	}

		//Описание: Установить параметры принтера EZ-2/4
		//Команда: setup(a,b,c,d,e,f)
		DllSetSetup(size_label,   // a: (integer) размер этикетки (в мм.)
							3,   //b: (integer) яркость печати (0~7)
							1,   //c: (integer) скорость печати (1~2)
							0,   //d: (integer) тип этикетки:
														//0: этикетки со светлым промежутком
														//1: Этикетки с черным промежутком
														//2: Лента
							3,   //e: (integer) промежуток между этикетками (в мм.)
							1); //f: (integer) отступ от черной метки для этикеток с черным промежутком


return result;
}
//----------------------------------------------------------------------------


//
//        CLSID clsid;
//        IClassFactory* pCF;
//        IUnknown* pUnk;
//
//        
//        CoInitialize(0);
//
//		HRESULT hr = ::CLSIDFromProgID( L"AddIn.GodexESC", &clsid );
//
//        if ( FAILED( hr ))
//        {
//	        TextError="Не Получили CLSID";
//	        //return ;
//        }
//        else
//                {
//			   //	ShowMessage("Получили CKSID");
//                }
////------------------------------------------------------------
//
//        hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF );
//        if ( FAILED( hr ))
//        {
//        TextError="Не Соединились с объектом";
//        }
//        else
//				{
//			   //	ShowMessage("Соединились с объектом");
//                }
//
////------------------------------------------------------
//
//		hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk );
//        pCF->Release();
//        if ( FAILED( hr ))
//        {
//	TextError="Не Создали интерфейс";
//        }
//        else
//                {
//				//ShowMessage("Создали интерфейс");
//                 }
//
////--------------------------------------------------
//	   // Merc = NULL;
//
//
//		hr = pUnk->QueryInterface( IID_ILanguageExtender, (void**) &Prn);
//		pUnk->Release();
//
//
//		if ( FAILED( hr ))
//			{
//			TextError="Не Создали рабочий интерфейс";
//			}
//		else
//				{
//				//ShowMessage("Создали рабочий интерфейс");
//				}
//
//
//IInitDone *In;
//
//		hr = pUnk->QueryInterface( IID_IInitDone, (void**) &In);
//		pUnk->Release();
//
//
//		if ( FAILED( hr ))
//			{
//			TextError="Не Создали рабочий интерфейс";
//			}
//		else
//				{
//				//ShowMessage("Создали рабочий интерфейс");
//				}
//
//
//IDispatch * disp;
//
//		hr = pUnk->QueryInterface( IID_IDispatch, (void**) &disp);
//		pUnk->Release();
//
//
//		if ( FAILED( hr ))
//			{
//			TextError="Не Создали рабочий интерфейс";
//			}
//		else
//				{
//				//ShowMessage("Создали рабочий интерфейс");
//				}
//
//hr=In->Init(NULL);
//
//long Number;
//AnsiString name_metod="НоваяЭтикетка";
//Prn->FindMethod(WideString(name_metod.c_str()).c_bstr(),&Number);
////ShowMessage("Номер метода Новая этикетка : "+IntToStr(Number));
//
//hr=Prn->CallAsFunc(Number,NULL,NULL);
//		if ( FAILED( hr ))
//			{
//			//ShowMessage("Не выполнили метод");
//			}
//		else
//				{
//				//ShowMessage("Выполнили метод");
//				}
//
//
//
//name_metod="PutBarcode";
//
//Prn->FindMethod(WideString(name_metod.c_str()).c_bstr(),&Number);
//long RetVal;
//hr=Prn->HasRetVal(Number,&RetVal);
//long KolParam=0;
//hr=Prn->GetNParams(Number,&KolParam);
//
//
//
////ShowMessage("Номер метода Print: "+IntToStr(Number));
//
//VARIANT res;
//VariantInit(&res);
////res->vt = VT_EMPTY;
//
//SAFEARRAY * psaiNew;
//psaiNew = SafeArrayCreateVector(VT_VARIANT, 0, 5);
////Variant V(OPENARRAY(Variant,(1)));
//long iVal=1;long i=0; hr = SafeArrayPutElement(psaiNew, &i, &iVal);
//iVal=1;         i=1; hr = SafeArrayPutElement(psaiNew, &i, &iVal);
//iVal=1;         i=2; hr = SafeArrayPutElement(psaiNew, &i, &iVal);
//iVal=1;         i=3; hr = SafeArrayPutElement(psaiNew, &i, &iVal);
//iVal=12;        i=4; hr = SafeArrayPutElement(psaiNew, &i, &iVal);
//
////Prn->CallAsFunc(Number,res,&psaiNew);
//
//hr=Prn->CallAsFunc(Number,&res,&psaiNew);
////SafeArrayDestroy(psaiNew);
//
//
//
//name_metod="Print";
//Prn->FindMethod(WideString(name_metod.c_str()).c_bstr(),&Number);
//
//Prn->HasRetVal(Number,&RetVal);
//
//Prn->GetNParams(Number,&KolParam);
//
//
////Prn->CallAsFunc(Number,res,&psaiNew);
//
//hr=Prn->CallAsFunc(Number,&res,&psaiNew);
