//---------------------------------------------------------------------------


#pragma hdrstop

#include "UObjectCheckDiscount.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "IDMGurOperDiscountCard.h"
#include "IDMSprVidDiscountCard.h"
#include "IDMSprNakSkidok.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSprKlient.h"
#include "IDMSprNom.h"


#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>

#pragma package(smart_init)
extern int glCompareDoubleValue(double v1, double v2, int pogr);
//----------------------------------------------------------------------------
TObjectCheckDiscount::TObjectCheckDiscount()
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
List=new TList;
IdDiscountCard=0;
}

//-----------------------------------------------------------------------------
TObjectCheckDiscount::~TObjectCheckDiscount()
{

for (int i=0;i<List->Count;i++)
	{
	StringDoc=(TStringDoc*) List->Items[i];
	delete StringDoc;
	}
delete List;
}
//---------------------------------------------------------------------------
bool TObjectCheckDiscount::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
												 (void**)&DMSprDiscountCard);
DMSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);



result=true;

return result;
}
//----------------------------------------------------------------------------
int TObjectCheckDiscount::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TObjectCheckDiscount::ClearList(void)
{
for (int i=0;i<List->Count;i++)
	{
	StringDoc=(TStringDoc*) List->Items[i];
	delete StringDoc;
	}

List->Clear();

TextMessage="";
TextMessageAtention="";

IdDiscountCard=0;
NameDiscountCard="";
IdTypePrice=0;
NameTypePrice="";
IdSklad=0;
IdKlient=0;
NameKlient="";
SummaDoc=0;
}
//----------------------------------------------------------------------------
bool TObjectCheckDiscount::FindCardPoCodu(UnicodeString code)
{
bool result=false;

				AnsiString s=code;
				if (s.Length()>13) {s.SetLength(13);}
				if (s.Length()>6)
					{ //ищем карту по штрих коду
					IdDiscountCard=DMSprDiscountCard->PoiskPoShCodu(s);
					}
				else
					{ //ищем карту по коду
					IdDiscountCard=DMSprDiscountCard->PoiskPoCodu(s);
					}

				if (IdDiscountCard > 0 )
					{
					DMSprDiscountCard->OpenElement(IdDiscountCard);
					if (DMSprDiscountCard->ElementACT_SDISCOUNT_CARD->AsInteger==1)
						{   //карта активна
						result=true;
						IdKlient=glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString);
						NameKlient=DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						NameDiscountCard=DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;
						}
					else
						{
						IdDiscountCard=0;
						NameDiscountCard="";
						IdKlient=0;
						NameKlient="";
						result=false;
                        DMSprDiscountCard->Element->Active=false;
						TextMessageAtention="Карта не активна!";
						}
					}
			else
					{
					IdDiscountCard=0;
					NameDiscountCard="";
					IdKlient=0;
					NameKlient="";
					result=false;
					TextMessageAtention="Карта не найдена!";
					}


return result;
}
//---------------------------------------------------------------------------

void TObjectCheckDiscount::AddString(
				__int64 id_string,
				__int64 id_nom,
				__int64 id_ed,
				__int64 id_grp,
				__int64 id_vid_nom,
				double price,
				double kol,
				double kf,
				double sum,
				double sum_discount,
				double procent_discount,
				double procent_discount_auto,
				double procent_discount_card,
				double procent_discount_hand,
				bool no_discount
							)
{
StringDoc=new TStringDoc;

StringDoc->IdString=id_string;
StringDoc->IdNom=id_nom;
StringDoc->IdEd=id_ed;
StringDoc->IdGrp=id_grp;
StringDoc->IdVidNom=id_vid_nom;
StringDoc->Price=price;
StringDoc->Kol=kol;
StringDoc->KF=kf;
StringDoc->Sum=sum;
StringDoc->SumDiscount=sum_discount;
StringDoc->ProcentDiscount=procent_discount;
StringDoc->ProcentDiscountAuto=procent_discount_auto;
StringDoc->ProcentDiscountCard=procent_discount_card;
StringDoc->ProcentDiscountHand=procent_discount_hand;
StringDoc->NoDiscount=no_discount;

List->Add(StringDoc);
}
//------------------------------------------------------------------------------
bool TObjectCheckDiscount::GetString(void)   //получаем строку, если есть строка то true
{
bool result=false;
NumberTecString++;

if (NumberTecString <= List->Count)
	{
	StringDoc=(TStringDoc*) List->Items[NumberTecString-1];
	result=true;
	}

return result;
}
//----------------------------------------------------------------------------
void TObjectCheckDiscount::CheckDiscount(void) //переходим на первую строку
{
//расчитаем суму документа
SummaDoc=0;

for (int i=0;i<List->Count;i++)
	{
	StringDoc=(TStringDoc*) List->Items[i];
	SummaDoc=SummaDoc+StringDoc->Price*StringDoc->Kol;
	}


GetProcentPoDiscountCard();
GetProcentAuto(SummaDoc);

//расставляем проценты скидок

for (int i=0;i<List->Count;i++)
	{
	StringDoc=(TStringDoc*) List->Items[i];
	if (StringDoc->ProcentDiscountHand > 0.01)
		{// если задана ручная скидка то скидки вообще не начисляем
		//надо начислять так как может быть запрет на скидку
		//или не надо раз ручная оператору виднее
		StringDoc->ProcentDiscount=StringDoc->ProcentDiscountHand;
		}
	else
		{ //ручная скидка не задана
		if(StringDoc->NoDiscount==true)
			{
			StringDoc->ProcentDiscount=0;
			}
		else
			{
			if (glCompareDoubleValue(StringDoc->ProcentDiscountCard, StringDoc->ProcentDiscountAuto, 3) == 1 )  //
				{
				StringDoc->ProcentDiscount=StringDoc->ProcentDiscountCard;
				}
			else
				{
				StringDoc->ProcentDiscount=StringDoc->ProcentDiscountAuto;
				}
			}
		}
	}


//обнулим текущую строку
NumberTecString=0;
}
//----------------------------------------------------------------------------
void TObjectCheckDiscount::GetProcentPoDiscountCard(void)
{

//*****************************************************************************
//карта не задана или не активна, просто обнулим процент скидки по карте
if (IdDiscountCard==0)
	{
	for (int i=0;i<List->Count;i++)
		{
		StringDoc=(TStringDoc*) List->Items[i];
		StringDoc->ProcentDiscountCard = 0;
		}
	return;
	}
else
	{ //откроем карту
      //пока не будем так как карту уже нашли

	}



//****************************************************************************
//фиксированная------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger == GC_TypeCard_Fiksir)
	{
	for (int i=0;i<List->Count;i++)
		{
		StringDoc=(TStringDoc*) List->Items[i];
		StringDoc->ProcentDiscountCard = DMSprDiscountCard->ElementPRSK_SDISCOUNT_CARD->AsFloat;
		}
	}
//****************************************************************************
//накопительная------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger == GC_TypeCard_Nakop)
	{
	double proc=0;
		IDMSprNakSkidok * dm_snak_skidok;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNakSkidok.1",IID_IDMSprNakSkidok,
												 (void**)&dm_snak_skidok);
		dm_snak_skidok->Init(InterfaceMainObject,InterfaceImpl);

		IDMGurOperDiscountCard * gur_oper;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard,
												 (void**)&gur_oper);
		gur_oper->Init(InterfaceMainObject,InterfaceImpl);

		dm_snak_skidok->GetSpisokSkidok( glStrToInt64(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsString),
									 IdSklad);

		AnsiString text_descr="";
		AnsiString text_descr_next="";
		double min_summa=10000000;


		while(!dm_snak_skidok->Query->Eof)
			{
			int kol_day=dm_snak_skidok->Query->FieldByName("PERIOD_SNAK_SKIDOK")->AsInteger;
			//получим сумму покупок
			TDateTime pos_nach=Now()-kol_day;
			double sum_pokupok=gur_oper->GetSumPokupok(glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString),pos_nach)
														+SummaDoc;
			double tek_procent=0;
			double tek_rasnica=0;
			if (sum_pokupok >= dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)
				{
				tek_procent=dm_snak_skidok->Query->FieldByName("PROCENT_SNAK_SKIDOK")->AsFloat;
				}
			else
				{  //определяем разницу
				tek_rasnica=dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat-sum_pokupok;
				}

			if (proc<tek_procent)
				{
				proc=tek_procent;
				text_descr="Накопленная сумма за "+IntToStr(kol_day)+" дней :"+FloatToStr(sum_pokupok);
				}

			if (min_summa > tek_rasnica && tek_rasnica > 0.001 )
				{
				min_summa=tek_rasnica;
				text_descr_next="\nДля след. скидки надо за "+IntToStr(kol_day)+
									" дней :"+FloatToStr(dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)+
									" Не хватает "+FloatToStr(dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat-
													sum_pokupok);
				}

			dm_snak_skidok->Query->Next();
			}

		dm_snak_skidok->kanRelease();
		gur_oper->kanRelease();
		TextMessage=TextMessage+text_descr+text_descr_next;

	for (int i=0;i<List->Count;i++)
		{
		StringDoc=(TStringDoc*) List->Items[i];
		StringDoc->ProcentDiscountCard = proc;
		}
	}
//**************************************************************************
//заданный тип цен---------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SpecTypePrice)
	{
	__int64 new_id_type_price=0;
	for (int i=0;i<List->Count;i++)
		{
		StringDoc=(TStringDoc*) List->Items[i];
		StringDoc->ProcentDiscountCard = 0;
		}

		//получим тип цен

		IDMSprKlient * dm_spr_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
												 (void**)&dm_spr_klient);
		dm_spr_klient->Init(InterfaceMainObject,InterfaceImpl);

		dm_spr_klient->OpenElement(glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString));

		new_id_type_price=glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString);
		dm_spr_klient->kanRelease();

		if (new_id_type_price!=0)
			{

			//получим название типа цен
			IDMSprTypePrice * dm_spr_type_price;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&dm_spr_type_price);
			dm_spr_type_price->Init(InterfaceMainObject,InterfaceImpl);
			dm_spr_type_price->OpenElement(new_id_type_price);
			NameTypePrice = dm_spr_type_price->ElementNAME_TPRICE->AsString;
			dm_spr_type_price->kanRelease();

			//проверим есть ли строки
			if(List->Count > 0)
				{
				//проставим новые цены
						IDMSprPrice * DMSprPrice;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&DMSprPrice);
						DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						for (int i=0;i<List->Count;i++)
							{
							StringDoc=(TStringDoc*) List->Items[i];

								DMSprPrice->FindElement(new_id_type_price,StringDoc->IdNom);
								//если цена по новому типу не задана, возьмем по старому
								if(DMSprPrice->ElementZNACH_PRICE->AsFloat==0)
									{
									DMSprPrice->FindElement(IdTypePrice,StringDoc->IdNom);
									}

								StringDoc->Price=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														StringDoc->KF;

							}
						DMSprPrice->kanRelease();
				}

			}
	IdTypePrice=new_id_type_price;
	}

//**************************************************************************
//скидка из справочника Номенклатура  --------------------------------------

if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom1
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom2
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom3)
	{
	IDMSprNom * spr_nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
	spr_nom->Init(InterfaceMainObject,InterfaceImpl);
	for (int i=0;i<List->Count;i++)
		{
		StringDoc=(TStringDoc*) List->Items[i];
		spr_nom->OpenElement(StringDoc->IdNom);
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom1)
			{
			StringDoc->ProcentDiscountCard=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom2)
			{
			StringDoc->ProcentDiscountCard=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger== GC_TypeCard_SkidkaNom3)
			{
			StringDoc->ProcentDiscountCard=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
			}
		}
	spr_nom->kanRelease();
	}


}
//----------------------------------------------------------------------------
void TObjectCheckDiscount::GetProcentAuto(double sum_doc)
{

IDMSprDiscountAuto  * DMSprDiscountAuto;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountAuto.1",IID_IDMSprDiscountAuto,
												 (void**)&DMSprDiscountAuto);
DMSprDiscountAuto->Init(InterfaceMainObject,InterfaceImpl);
DMSprDiscountAuto->OpenTableDiscountAuto(IdSklad);
for (int i=0;i<List->Count;i++)
	{
	double tek_skidka=0;
	bool flNoDiscount=false;
	StringDoc=(TStringDoc*) List->Items[i];
	DMSprDiscountAuto->TableDiscountAuto->First();
	while (!DMSprDiscountAuto->TableDiscountAuto->Eof)
		{
		bool  ok=true;
		if (DMSprDiscountAuto->TableDiscountAutoACT_SDISCOUNT_AUTO->AsInteger==1)
			{
			//период активности начало
			if (DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsFloat > 1000)
				{
				if (Now()<DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//период активности конец
			if (DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsFloat>1000)
				{
				if (Now()>DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//сумма
			if (DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (SummaDoc < DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat)
					{
					ok=false;
					}
				}

			//день недели
			if (DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger>0)
				{
				//if (DayOfTheWeek(Now())!=DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger)
				//	{
					//ShowMessage(DayOfTheWeek(Now()));
				//	ok=false;
				//	}
				}

			//время действия начало
			if (DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()<DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//время действия конец
			if (DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()>DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//тип номенклатуры
			if (glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString)>0)
				{
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
				spr_nom->Init(InterfaceMainObject,InterfaceImpl);
				spr_nom->OpenElement(StringDoc->IdNom);
				if (glStrToInt64(spr_nom->ElementIDVID_SNOM->AsString)!=
						glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString))
					{
					ok=false;
					}
				spr_nom->kanRelease();
				}


 			//группа номенклатуры
			if (glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO->AsString)>0)
				{
				if (StringDoc->IdGrp==0)
					{//группа не задана, необходимо сначала получить группу
					IDMSprNom *spr_nom;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
					spr_nom->Init(InterfaceMainObject,InterfaceImpl);
					spr_nom->OpenElement(StringDoc->IdNom);
					if (glStrToInt64(spr_nom->ElementIDGRPNOM->AsString)!=
									glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO->AsString))
						{
						ok=false;
						}
					spr_nom->kanRelease();
					}
				else
					{//группа задана, можно не получать
					if (StringDoc->IdGrp!=
									glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO->AsString))
						{
						ok=false;
						}
					}

				}



			} //активность


		double proc_tec_skidki_auto=0;
		if (ok==true)
			{
			 //возможны варианты
			 //начислить скидку - 1
			 //
			if (DMSprDiscountAuto->TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO->AsInteger == GC_DiscountAutoTypeAction_AddDiscount)
				{//начислить скидку

				//необходимо определить процент скидки по текущей позиции
				//скидка одинаковая на все позиции

				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==0)
					{
					proc_tec_skidki_auto=DMSprDiscountAuto->TableDiscountAutoPRSK_SDISCOUNT_AUTO->AsFloat;
					}

				//скидка разная на позиции (из справочника Номенклатура)
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger>0)
					{
					IDMSprNom *spr_nom;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
					spr_nom->Init(InterfaceMainObject,InterfaceImpl);
					spr_nom->OpenElement(StringDoc->IdNom);
					//скидка 1
					if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==1)
						{
						proc_tec_skidki_auto=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
						}
					//скидка 2
					if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==2)
						{
						proc_tec_skidki_auto=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
						}
					//скидка 3
					if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==3)
						{
						proc_tec_skidki_auto=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
						}
					spr_nom->kanRelease();
					}

				if (glCompareDoubleValue(proc_tec_skidki_auto,tek_skidka,3) == 1)
					{
					tek_skidka=proc_tec_skidki_auto;
					}

				}//конец начисления скидок
			else if (DMSprDiscountAuto->TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO->AsInteger == GC_DiscountAutoTypeAction_NoDiscount)
				{//запретить скидку
				flNoDiscount=true;
				}
			else if (DMSprDiscountAuto->TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO->AsInteger == GC_DiscountAutoTypeAction_ShowMessage)
				{//сообщение
				TextMessage=DMSprDiscountAuto->TableDiscountAutoMESSAGE_SDISCOUNT_AUTO->AsString;
				}

			}



		DMSprDiscountAuto->TableDiscountAuto->Next();
		}

	StringDoc->ProcentDiscountAuto=tek_skidka;
	if (flNoDiscount==true)
		{
		StringDoc->NoDiscount=true;
		}
	else
		{
		StringDoc->NoDiscount=false;
		}

	}






}
//----------------------------------------------------------------------------
