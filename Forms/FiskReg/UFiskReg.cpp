//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFiskReg.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
TFiskReg::TFiskReg()
{

Modul="";
ConnectFR=false;
TextErrorNoConnect="ККМ не подключена!";
}
//-----------------------------------------------------------------------------
TFiskReg::~TFiskReg()
{
FreeLibrary(dllIn); 
}
//---------------------------------------------------------------------------
bool TFiskReg::Init()
{
bool result=false;
TextError="";
dllIn=LoadLibrary(Modul.c_str());
if(dllIn)
        {

        DllGetTextError=(DllGetTextErrorType*)GetProcAddress(dllIn,"_GetTextError");
        DllConnect=(DllConnectType*)GetProcAddress(dllIn,"_Connect");
        DllDisconnect=(DllDisconnectType*)GetProcAddress(dllIn,"_Disconnect");
        DllPrintString=(DllPrintStringType*)GetProcAddress(dllIn,"_PrintString");
        DllPrintFiscalCheck=(DllPrintFiscalCheckType*)GetProcAddress(dllIn,"_PrintFiscalCheck");
        DllPrintNoFiscalCheck=(DllPrintNoFiscalCheckType*)GetProcAddress(dllIn,"_PrintNoFiscalCheck");
        DllPrintXReport=(DllPrintXReportType*)GetProcAddress(dllIn,"_PrintXReport");
        DllPrintZReport=(DllPrintZReportType*)GetProcAddress(dllIn,"_PrintZReport");
        DllPrintPoOtdelamReport=(DllPrintPoOtdelamReportType*)GetProcAddress(dllIn,"_PrintPoOtdelamReport");
        DllCut=(DllCutType*)GetProcAddress(dllIn,"_Cut");
        DllVnesenie=(DllVnesenieType*)GetProcAddress(dllIn,"_Vnesenie");
        DllSnatie=(DllSnatieType*)GetProcAddress(dllIn,"_Snatie");
        DllPrintLine=(DllPrintLineType*)GetProcAddress(dllIn,"_PrintLine");

        DllOpenNoFiscalCheck=(DllOpenNoFiscalCheckType*)GetProcAddress(dllIn,"_OpenNoFiscalCheck");
        DllCloseNoFiscalCheck=(DllCloseNoFiscalCheckType*)GetProcAddress(dllIn,"_CloseNoFiscalCheck");

        DllGetSostKKM=(DllGetSostKKMType*)GetProcAddress(dllIn,"_GetSostKKM");
        DllProvVosmPrintCheck=(DllProvVosmPrintCheckType*)GetProcAddress(dllIn,"_ProvVosmPrintCheck");

        DllGetNumberCheck=(DllGetNumberCheckType*)GetProcAddress(dllIn,"_GetNumberCheck");
        DllGetNumberKL=(DllGetNumberKLType*)GetProcAddress(dllIn,"_GetNumberKL");
		DllGetSerialNumberKKM=(DllGetSerialNumberKKMType*)GetProcAddress(dllIn,"_GetSerialNumberKKM");
		DllGetRegNumberKKM=(DllGetRegNumberKKMType*)GetProcAddress(dllIn,"_GetRegNumberKKM");
		DllGetModelKKM=(DllGetModelKKMType*)GetProcAddress(dllIn,"_GetModelKKM");

		DllGetTimeKKM=(DllGetTimeKKMType*)GetProcAddress(dllIn,"_GetTimeKKM");
		DllGetDateKKM=(DllGetDateKKMType*)GetProcAddress(dllIn,"_GetDateKKM");
		DllSetTimeKKM=(DllSetTimeKKMType*)GetProcAddress(dllIn,"_SetTimeKKM");
        DllSetDateKKM=(DllSetDateKKMType*)GetProcAddress(dllIn,"_SetDateKKM");
        result=true;
        }
else
       {
        return result;
	   }


return result;
}
//---------------------------------------------------------------------------

bool TFiskReg::Connect(int number_port,
						UnicodeString baud_rate,
						UnicodeString password)
{
bool result=false;

if (DllConnect==0)
	{
	TextError="Ошибка при получении адреса функции: DllConnect";
	return result;
	}



ConnectFR=false;
try
        {
		if (DllConnect(number_port,baud_rate,password)==true)
                {
                result=true;
                Error=false;
				TextError="";
				ConnectFR=true;
                }
        else
                {
                result=false;
                Error=true;
				TextError=DllGetTextError();
				ConnectFR=false;
                }
        }
catch (Exception &exception)
		{
		ConnectFR=false;
        result=false;
        Error=true;
        TextError=exception.Message;
        }

return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::Disconnect(void)
{
bool result=true;

if (DllDisconnect==0)
	{
	TextError="Ошибка при получении адреса функции: DllDisconnect";
	return result;
	}


ConnectFR=false;
DllDisconnect();

return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintString(UnicodeString str,
                                int size_font,       //1234
                                int girn,            //1-жирный 0 обычный
                                int alignment,      //0 лево 1 центр 2 право
                                bool ch_lenta,       //на чековой ленте
								bool kontr_lenta,   //на контрольной ленте
								bool word_wrap)
{
bool result=false;

if (DllPrintString==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintString";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllPrintString(str,size_font,girn,alignment,ch_lenta, kontr_lenta, word_wrap)==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
		result=false;
        Error=true;
		TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}

return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::PrintLine(void)
{
bool result=false;

if (DllPrintLine==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintLine";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllPrintLine()==true)
        {
        result=true;
        }
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}

return result;

}
//---------------------------------------------------------------------------
bool TFiskReg::PrintFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation)    //0 продажа 1 возврат
{
bool result=false;

if (DllPrintFiscalCheck==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintFiscalCheck";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}


try
	{
	if (DllPrintFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation)==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}

	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation)    //0 продажа 1 возврат
{
bool result=false;

if (DllPrintNoFiscalCheck==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintNoFiscalCheck";
	return result;
	}


if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
	
try
	{
	if (DllPrintNoFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation)==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
        }
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintXReport(void)
{
bool result=false;

if (DllPrintXReport==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintXReport";
	return result;
	}


if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllPrintXReport()==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}

	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintZReport(void)
{
bool result=false;

if (DllPrintZReport==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintZReport";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
try
	{
	if (DllPrintZReport()==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
bool TFiskReg::PrintPoOtdelamReport(void)
{
bool result=false;

if (DllPrintPoOtdelamReport==0)
	{
	TextError="Ошибка при получении адреса функции: DllPrintPoOtdelamReport";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}


try
	{
	if (DllPrintPoOtdelamReport()==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;

}
//---------------------------------------------------------------------------
bool TFiskReg::Cut(int TypeCut)
{
bool result=false;

if (DllCut==0)
	{
	TextError="Ошибка при получении адреса функции: DllCut";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllCut(TypeCut)==true)
        {
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::GetSostKKM(void)
{
bool result=false;

if (DllGetSostKKM==0)
	{
	TextError="Ошибка при получении адреса функции: DllGetSostKKM";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllGetSostKKM()==true)
        {
        NumberCheck=DllGetNumberCheck();
        NumberKL=DllGetNumberKL();
		SerialNumberKKM=DllGetSerialNumberKKM();
		RegNumberKKM=DllGetRegNumberKKM();
		ModelKKM=DllGetModelKKM();
        
        result=true;
        Error=false;
        TextError="";
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::ProvVosmPrintCheck(void)
{
bool result=false;

if (DllProvVosmPrintCheck==0)
	{
	TextError="Ошибка при получении адреса функции: DllProvVosmPrintCheck";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllProvVosmPrintCheck()==true)
        {
        Error=false;
        TextError="";
        result=true;
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
        }
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TFiskReg::Vnesenie(float sum)
{
bool result=false;

if (DllVnesenie==0)
	{
	TextError="Ошибка при получении адреса функции: DllVnesenie";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
try
	{
	if (DllVnesenie(sum)==true)
        {
        Error=false;
        TextError="";
        result=true;
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;


}
//----------------------------------------------------------------------------
bool TFiskReg::Snatie(float sum)
{
bool result=false;

if (DllSnatie==0)
	{
	TextError="Ошибка при получении адреса функции: DllSnatie";
	return result;
	}


if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

try
	{
	if (DllSnatie(sum)==true)
        {
        Error=false;
        TextError="";
        result=true;
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}

	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;

}
//---------------------------------------------------------------------------
bool TFiskReg::OpenNoFiscalCheck(void)
{
bool result;

if (DllOpenNoFiscalCheck==0)
	{
	TextError="Ошибка при получении адреса функции: DllOpenNoFiscalCheck";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}


try
	{
	if (DllOpenNoFiscalCheck()==true)
        {
        Error=false;
        TextError="";
        result=true;
        }
	else
        {
        result=false;
        Error=true;
        TextError=DllGetTextError();
		}

	}
catch (Exception &exception)
	{
	result=false;
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//----------------------------------------------------------------------------
bool TFiskReg::CloseNoFiscalCheck(void)
{
bool result;

if (DllCloseNoFiscalCheck==0)
	{
	TextError="Ошибка при получении адреса функции: DllCloseNoFiscalCheck";
	return result;
	}


if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
	
try
	{
	if (DllCloseNoFiscalCheck()==true)
		{
		Error=false;
		TextError="";
		result=true;
		}
	else
		{
		result=false;
		Error=true;
		TextError=DllGetTextError();
		}
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
return result;
}
//----------------------------------------------------------------------------
TTime TFiskReg::GetTime(void)
{
TTime result;

if (DllGetTimeKKM==0)
	{
	TextError="Ошибка при получении адреса функции: DllGetTimeKKM";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}

UnicodeString time="";
time=DllGetTimeKKM();
time=Trim(time);
if (time!="")
		{
		Error=false;
		TextError="";
		result=StrToTime(time);
		}
else
		{
		result=0;
		Error=true;
		TextError=DllGetTextError();
		}
return result;
}
//----------------------------------------------------------------------------
TDate TFiskReg::GetDate(void)
{
TDate result;

if (DllGetDateKKM==0)
	{
	TextError="Ошибка при получении адреса функции: DllGetDateKKM";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
UnicodeString date="";


date=DllGetDateKKM();
date=Trim(date);
if (date!="")
		{
		Error=false;
		TextError="";
		result=StrToDate(date);
		}
else
		{
		Error=true;
		TextError=DllGetTextError();
		}
return result;
}
//----------------------------------------------------------------------------
bool TFiskReg::SetTime(TTime time)
{
bool result=false;

if (DllSetTimeKKM==0)
	{
	TextError="Ошибка при получении адреса функции: DllSetTimeKKM";
	return result;
	}

if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
UnicodeString str_time=TimeToStr(time);

if (DllSetTimeKKM(str_time.c_str())==true)
		{
		Error=false;
		TextError="";
		result=true;
		}
else
		{
		result=false;
		Error=true;
		TextError=DllGetTextError();
		}
return result;

}
//----------------------------------------------------------------------------
bool TFiskReg::SetDate(TDate date)
{
bool result;

if (DllSetDateKKM==0)
	{
	TextError="Ошибка при получении адреса функции: DllSetDateKKM";
	return result;
	}


if(ConnectFR==false)
	{
	TextError=TextErrorNoConnect;
	return result;
	}
UnicodeString str_date=DateToStr(date);

if (DllSetDateKKM(str_date.c_str())==true)
		{
		Error=false;
		TextError="";
		result=true;
		}
else
		{
		result=false;
		Error=true;
		TextError=DllGetTextError();
		}
return result;

}
//----------------------------------------------------------------------------
