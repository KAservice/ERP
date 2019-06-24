//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasViki.h"
#include <math.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
TkasVikiFR::TkasVikiFR()
{
InterfaceMainObject=0;
InterfaceOwnerObject=0;
bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

Modul="";
ConnectFR=false;
TextErrorNoConnect="ККМ не подключена!";

KolSymbolSize1=40;
KolSymbolSize1Girn=40;
KolSymbolSize2=40;
KolSymbolSize2Girn=40;
KolSymbolSize3=14;
KolSymbolSize3Girn=14;
KolSymbolSize4=14;
KolSymbolSize4Girn=14;
}
//-----------------------------------------------------------------------------
TkasVikiFR::~TkasVikiFR()
{
//FreeLibrary(dllIn);
}
//---------------------------------------------------------------------------
int TkasVikiFR::Init()
{


return -1;
}
//----------------------------------------------------------------------------
int TkasVikiFR::Done()
{

return -1;
}

//---------------------------------------------------------------------------


bool  TkasVikiFR::Connect(int number_port,
				UnicodeString baud_rate,
				UnicodeString password)
{



bool result=false;

return result;
}
//--------------------------------------------------------------------------

bool  TkasVikiFR::Disconnect(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------

bool  TkasVikiFR::GetSostKKM(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------
bool  TkasVikiFR::ProvVosmPrintCheck(void)
{
bool result=true;

return result;

}
//----------------------------------------------------------------------------
bool   TkasVikiFR::OpenNoFiscalCheck(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------
bool   TkasVikiFR::CloseNoFiscalCheck(void)
{
bool result=true;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintString(UnicodeString str,
												int size_font,       //1234
												int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintLine(void)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------


bool  TkasVikiFR::PrintFiscalCheck(double sum,
						int department,
						double oplata_nal,
						double oplata_bank_card,
						double oplata_plat_card,
						double oplata_credit_card,
						int operation)    //0 продажа 1 возврат
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
bool TkasVikiFR::PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintNoFiscalCheck(double sum,
								int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation)    //0 продажа 1 возврат
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintXReport(void)
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
bool TkasVikiFR::PrintZReport(void)
{
bool result=false;



return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintPoOtdelamReport(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------

bool  TkasVikiFR::Cut(int TypeCut)
{
bool result=true ;


return result;

}
//---------------------------------------------------------------------------

bool  TkasVikiFR::Vnesenie(double sum)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::Snatie(double sum)
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
UnicodeString TkasVikiFR::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
UnicodeString TkasVikiFR::DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
TTime  TkasVikiFR::GetTime(void)
{
TTime result=0;

return result;

}
//-----------------------------------------------------------------------------
TDate TkasVikiFR::GetDate(void)
{
TDate result=0;

return result;

}
//--------------------------------------------------------------------------
bool  TkasVikiFR::SetTime(TTime time)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
bool  TkasVikiFR::SetDate(TDate date)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
void TkasVikiFR::OpenDrawer(void)
{

}
//-----------------------------------------------------------------------------
int TkasVikiFR::CompareDoubleValue(double v1, double v2, int pogr)
{
int result=0;

if (fabs(v1-v2) < pow(0.1,pogr))
	{
	result=0;
	}
else
	{
	 if (v1 > v2)
		{
		result=1;
		}
	 else
		{
        result=-1;
		}

	}


return result;
}
//---------------------------------------------------------------------------