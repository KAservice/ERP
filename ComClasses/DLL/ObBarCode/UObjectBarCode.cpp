//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UObjectBarCode.h"
#include "math.h"
#include "IDMSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TObjectBarCode::TObjectBarCode()
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

Prefiks1=20;  //обычный локальный шк, поиск по шк единицы
Prefiks2=23; //колич. поиск по коду номенклатуры,  код в первой половине
Prefiks3=24; //колич. поиск по коду номенклатуры, код во второй половине
Prefiks4=25; //колич. поиск по шк единицы, вес в первой половине
Prefiks5=26; //колич. поиск по шк единицы, вес во второй половине
Kol=1;
OutReady=false;
}

//-----------------------------------------------------------------------------
TObjectBarCode::~TObjectBarCode()
{


}
//---------------------------------------------------------------------------
bool TObjectBarCode::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

result=true;

return result;
}
//----------------------------------------------------------------------------
int TObjectBarCode::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
UnicodeString TObjectBarCode::AddEAN13(UnicodeString cod)
{
UnicodeString ShCod="";

if (cod.Length()!=12)
        {
		return ShCod=cod+"-";
        }

//длина Cod 12 символов обязательно

double Ch=0;
double NeCh=0;
double E13=0;

for (int i=1;i<7;i++)
        {
		Ch=Ch+(int)StrToFloat(cod[2*i]);
        NeCh=NeCh+(int)StrToFloat(cod[2*i-1]);
        }

Ch=Ch*3;
E13=((Ch+NeCh)/10)-(floor((Ch+NeCh)/10));
E13=10-floor(E13*10);
if (E13==10){E13=0;}

ShCod=cod+IntToStr((int)E13);
return ShCod;
}
//----------------------------------------------------------------------------
void  TObjectBarCode::ObrabotatShtrihCod(UnicodeString sh)
{
UnicodeString s=sh;
UnicodeString barcode_for_poisk="";
Kol=1;
OutReady=false;

for (int i=1;i<=s.Length();i++)
	{
	if (s[i]=='0' ||  s[i]=='1' || s[i]=='2' ||	 s[i]=='3' || s[i]=='4' ||
	   s[i]=='5' || s[i]=='6' ||  s[i]=='7' ||  s[i]=='8' || s[i]=='9' )
		{
		barcode_for_poisk=barcode_for_poisk+s[i];
		}
	else
		{
		if (barcode_for_poisk.Length()!=0)
			{
            break;
			}
		}
	}

DM_Connection->glSaveProtocol("Код для поиска:"+barcode_for_poisk);
bool obrab=false;
if (barcode_for_poisk.Length()==13)
	{
	UnicodeString prefiks_coda=barcode_for_poisk.SubString(1,2);

	if ( prefiks_coda==Prefiks2)
		{ //колич. поиск по коду номенклатуры,  код в первой половине
		ObrabotatPrefiks2(barcode_for_poisk);
		obrab=true;
		}   

	if ( prefiks_coda==Prefiks3)
		{ //колич. поиск по коду номенклатуры, код во второй половине
		ObrabotatPrefiks3(barcode_for_poisk);
		obrab=true;
		}

	if ( prefiks_coda==Prefiks4)
		{ //колич. поиск по шк единицы, вес в первой половине
		ObrabotatPrefiks4(barcode_for_poisk);
		obrab=true;
		}

	if ( prefiks_coda==Prefiks5)
		{//колич. поиск по шк единицы, вес во второй половине
		ObrabotatPrefiks5(barcode_for_poisk);
		obrab=true;
		}
	}


if (obrab==false)//не обработан штрих код
	{///обычный короткий либо полный штрихкодштрих код
	DM_Connection->glSaveProtocol("Ищем по штучному коду:"+barcode_for_poisk);
	if (SprEd->FindEdPoSh(barcode_for_poisk)>0)
		{
		SprNom->IdTypePrice=IdTypePrice;
		SprNom->OpenElement(glStrToInt64(SprEd->ElementIDNOMED->AsString));
		OutReady=true;
		}
	else
		{
		OutReady=false;
		TextError="Не найден товар с штрих-кодом "+barcode_for_poisk+"!";

		}

	}

}
//----------------------------------------------------------------------------
void TObjectBarCode::ObrabotatPrefiks2(UnicodeString bar_code)
{
//колич. поиск по коду номенклатуры,  код в первой половине
//ППКККККВВВВВ  
UnicodeString code_for_poisk=UnicodeString(bar_code[3])+
					UnicodeString(bar_code[4])+
					UnicodeString(bar_code[5])+
					UnicodeString(bar_code[6])+
					UnicodeString(bar_code[7]);

Kol=StrToFloat(UnicodeString(bar_code[8])+
					UnicodeString(bar_code[9])+
					UnicodeString(bar_code[10])+
					UnicodeString(bar_code[11])+
					UnicodeString(bar_code[12]))/1000;
//	ShowMessage("Получен вес товара"+FloatToStr(ves));


				SprNom->IdTypePrice=IdTypePrice;
				if (SprNom->FindPoCodu(StrToInt(code_for_poisk))>0) //открывает элемент
					{
					SprEd->OpenElement(glStrToInt64(SprNom->ElementIDBASEDNOM->AsString));
					OutReady=true;
					}
				else
					{
					OutReady=false;
					TextError="Не найден весовой товар с кодом номенклатуры "+code_for_poisk+"!";
					}

}
//----------------------------------------------------------------------------
void TObjectBarCode::ObrabotatPrefiks3(UnicodeString bar_code)
{
//ППВВВВВККККК
//колич. поиск по коду номенклатуры, код во второй половине

Kol=StrToFloat(UnicodeString(bar_code[3])+
					UnicodeString(bar_code[4])+
					UnicodeString(bar_code[5])+
					UnicodeString(bar_code[6])+
					UnicodeString(bar_code[7]))/1000;
				//	ShowMessage("Получен вес товара"+FloatToStr(ves));

UnicodeString code_for_poisk=UnicodeString(bar_code[8])+
					UnicodeString(bar_code[9])+
					UnicodeString(bar_code[10])+
					UnicodeString(bar_code[11])+
					UnicodeString(bar_code[12]);

				SprNom->IdTypePrice=IdTypePrice;
				if (SprNom->FindPoCodu(StrToInt(code_for_poisk))>0) //открывает элемент
					{
					SprEd->OpenElement(glStrToInt64(SprNom->ElementIDBASEDNOM->AsString));
					OutReady=true;
					}
				else
					{
					OutReady=false;
					TextError="Не найден весовой товар с кодом номенклатуры "+code_for_poisk+"!";
					}

}
//-----------------------------------------------------------------------------
void TObjectBarCode::ObrabotatPrefiks4(UnicodeString bar_code)
{ //колич. поиск по шк единицы, вес в первой половине

Kol=StrToFloat(UnicodeString(bar_code[3])+
					UnicodeString(bar_code[4])+
					UnicodeString(bar_code[5])+
					UnicodeString(bar_code[6])+
					UnicodeString(bar_code[7]))/1000;
				//	ShowMessage("Получен вес товара"+FloatToStr(ves));

UnicodeString barcode_for_poisk=UnicodeString(bar_code[1])+
									UnicodeString(bar_code[2])+
									L"00000"+
									UnicodeString(bar_code[8])+
									UnicodeString(bar_code[9])+
									UnicodeString(bar_code[10])+
									UnicodeString(bar_code[11])+
									UnicodeString(bar_code[12]);

barcode_for_poisk=AddEAN13(barcode_for_poisk.SetLength(12));

				if (SprEd->FindEdPoSh(barcode_for_poisk)>0)
					{
					SprNom->IdTypePrice=IdTypePrice;
					SprNom->OpenElement(glStrToInt64(SprEd->ElementIDNOMED->AsString));
					OutReady=true;
					}
				else
					{
					OutReady=false;
					TextError="Не найден весовой товар с штрих-кодом единицы"+barcode_for_poisk+"!";
					}
}
//----------------------------------------------------------------------------
void TObjectBarCode::ObrabotatPrefiks5(UnicodeString bar_code)
{ //колич. поиск по шк единицы, вес во второй половине

UnicodeString barcode_for_poisk=UnicodeString(bar_code[1])+
									UnicodeString(bar_code[2])+
									UnicodeString(bar_code[3])+
									UnicodeString(bar_code[4])+
									UnicodeString(bar_code[5])+
									UnicodeString(bar_code[6])+
									UnicodeString(bar_code[7])+
									L"00000";

Kol=StrToFloat(UnicodeString(bar_code[8])+
					UnicodeString(bar_code[9])+
					UnicodeString(bar_code[10])+
					UnicodeString(bar_code[11])+
					UnicodeString(bar_code[12]))/1000;
				//	ShowMessage("Получен вес товара"+FloatToStr(ves));


barcode_for_poisk=AddEAN13(barcode_for_poisk.SetLength(12));
				if (SprEd->FindEdPoSh(barcode_for_poisk)>0)
					{
					SprNom->IdTypePrice=IdTypePrice;
					SprNom->OpenElement(glStrToInt64(SprEd->ElementIDNOMED->AsString));
					OutReady=true;
					}
				else
					{
					OutReady=false;
					TextError="Не найден весовой товар с штрих-кодом единицы"+barcode_for_poisk+"!";
					}

}
//---------------------------------------------------------------------------
UnicodeString TObjectBarCode::GetNewBarCode(UnicodeString code, int type_bar_code)
{
UnicodeString result="";

UnicodeString sh=code;
sh=glDopStrL(sh,"0",5);

//обычный локальный шк, поиск по шк единицы
if (type_bar_code==0)
	{
	sh=Prefiks1+L"00000"+sh;
	}
//колич. поиск по коду номенклатуры,  код в первой половине
if (type_bar_code==1)
	{
	sh=Prefiks2+sh+L"00000";
	}
//колич. поиск по коду номенклатуры, код во второй половине
if (type_bar_code==2)
	{
	sh=Prefiks3+L"00000"+sh;
	}
//колич. поиск по шк единицы, вес в первой половине
if (type_bar_code==3)
	{
	sh=Prefiks4+L"00000"+sh;
	}
//колич. поиск по шк единицы, вес во второй половине
if (type_bar_code==4)
	{
	sh=Prefiks5+sh+L"00000";
	}

result=AddEAN13(sh);

return result;
}
//----------------------------------------------------------------------------
void TObjectBarCode::GetValuePrefiksBarCode(void)
{
IDMSetup *setup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&setup);
setup->Init(InterfaceMainObject,0);

//обычный локальный шк, поиск по шк единицы
setup->OpenElement(20);
UnicodeString value=setup->ElementVALUE_SETUP->AsString;
if (value!="")
	{
	Prefiks1=value;
	}

//колич. поиск по коду номенклатуры,  код в первой половине
setup->OpenElement(21);
value=setup->ElementVALUE_SETUP->AsString;
if (value!="")
	{
	Prefiks2=value;
	}

//колич. поиск по коду номенклатуры, код во второй половине
setup->OpenElement(23);
value=setup->ElementVALUE_SETUP->AsString;
if (value!="")
	{
	Prefiks3=value;
	}

//колич. поиск по шк единицы, вес в первой половине
setup->OpenElement(24);
value=setup->ElementVALUE_SETUP->AsString;
if (value!="")
	{
	Prefiks4=value;
	}

//колич. поиск по шк единицы, вес во второй половине
setup->OpenElement(25);
value=setup->ElementVALUE_SETUP->AsString;
if (value!="")
	{
	Prefiks5=value;
	}
setup->kanRelease();
}
//----------------------------------------------------------------------------
