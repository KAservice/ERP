//---------------------------------------------------------------------------

#ifndef UGlobalFunctionH
#define UGlobalFunctionH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------


__int64 glStrToInt64(UnicodeString value);

UnicodeString glGetNameDoc(UnicodeString StrCodeDoc);
UnicodeString glGetNameDocRemont(UnicodeString str_code_doc);
UnicodeString glGetNameDocHotel(UnicodeString StrCodeDoc);

UnicodeString glFloatToStringComma(double value);
double glStringToFloatComma(UnicodeString value);
UnicodeString glDopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
UnicodeString glDopStrR(UnicodeString Str, UnicodeString Symbol, int Len);

UnicodeString triada(UnicodeString in, int tn);
UnicodeString ValuePropis(UnicodeString in);
UnicodeString glCurrencyPropis(double Value);
UnicodeString glIntegerValuePropis(int Value);

UnicodeString glAddEAN13(UnicodeString Cod);

int glGetRateNDS(int code);

int glCompareDoubleValue(double v1, double v2, int pogr);

double glRoundValue(double value, int  rasr);

UnicodeString glGetStringFullTypeDoc(void);
UnicodeString glGetStringFullTypeDocNoCheck(void);

UnicodeString glCommaToPixel(UnicodeString value);
UnicodeString glConvertString(UnicodeString s1, UnicodeString s2, UnicodeString s3);   //Заменить в строке s1 все вхождения s2 на s3


UnicodeString glGetVersionProgramFile(void);

UnicodeString glGetNameProcedureCancelDvReg(UnicodeString type_doc);
UnicodeString glGetNameProcedureDvReg(UnicodeString type_doc);

UnicodeString glGetNameProcedureCancelDvRegHotelSystem(UnicodeString type_doc);
UnicodeString glGetNameProcedureDvRegHotelSystem(UnicodeString type_doc);

UnicodeString glGetNameProcedureCancelDvRegRemontSystem(UnicodeString type_doc);
UnicodeString glGetNameProcedureDvRegRemontSystem(UnicodeString type_doc);

UnicodeString glDelSymbolOfBarCode(UnicodeString bar_code);

UnicodeString glDelSymbolOfDoubleValue (UnicodeString value);

#endif
