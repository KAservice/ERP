//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UHOT_RaschetStoimProg.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IHOT_DMSprNF.h"
#include "IHOT_FormaSpiskaSprPrOsnUslug.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMSprPriceSchedule.h"
#include "IDMSetup.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "SysUtils.hpp"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TRaschetStoimProg::TRaschetStoimProg()
{
ResultList=new TList;
NumberTecString=0;
AddBron=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
TRaschetStoimProg::~TRaschetStoimProg()
{

for (int i=0;i<ResultList->Count;i++)
	{
	StringDoc=(TStringDoc*) ResultList->Items[i];
	delete StringDoc;
	}
delete ResultList;
}
//---------------------------------------------------------------------------
bool TRaschetStoimProg::Init(void)
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
//-----------------------------------------------------------------------------
int  TRaschetStoimProg::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TRaschetStoimProg::GetTableDoc(void) //переходим на первую строку
{


//получим категорию номера
IHOT_DMSprNF * nomer;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprNF.1",IID_IHOT_DMSprNF, (void**)&nomer);
nomer->Init(InterfaceMainObject,InterfaceImpl);
nomer->OpenElement(IdNomer);
__int64 id_cat=nomer->ElementIDCAT_HOT_SNF->AsInt64;
AnsiString name_cat=nomer->ElementNAME_HOT_SCATNOM->AsString;
AnsiString name_nomer=nomer->ElementNAME_HOT_SNF->AsString;
nomer->kanRelease();

//получим услугу проживания и бронирования
IHOT_DMSprPrOsnUslug * prescurant;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprPrOsnUslug.1",IID_IHOT_DMSprPrOsnUslug, (void**)&prescurant);
prescurant->Init(InterfaceMainObject,InterfaceImpl);

prescurant->GetNomBronAndProg(id_cat,IdTypePos);
__int64 id_nom_bron=prescurant->IdNomBron;
__int64 id_nom_prog=prescurant->IdNomProg;
prescurant->kanRelease();

IDMSprNom * nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom, (void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);
nom->OpenElement(id_nom_bron);
AnsiString name_nom_bron=nom->ElementNAMENOM->AsString;

IDMSprEd * ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd, (void**)&ed);
ed->Init(InterfaceMainObject,InterfaceImpl);

ed->OpenElement(glStrToInt64(nom->ElementIDBASEDNOM->AsString));
__int64 id_ed_bron=glStrToInt64(nom->ElementIDBASEDNOM->AsString);
AnsiString name_ed_bron=ed->ElementNAMEED->AsString;
double kf_ed_bron=ed->ElementKFED->AsFloat;

nom->OpenElement(id_nom_prog);
AnsiString name_nom_prog=nom->ElementNAMENOM->AsString;
ed->OpenElement(glStrToInt64(nom->ElementIDBASEDNOM->AsString));
__int64 id_ed_prog=glStrToInt64(nom->ElementIDBASEDNOM->AsString);
AnsiString name_ed_prog=ed->ElementNAMEED->AsString;
double kf_ed_prog=ed->ElementKFED->AsFloat;
ed->kanRelease();
nom->kanRelease();

//расчетный час
int int_rasch_hour=12;


IDMSprPriceSchedule * schedule;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPriceSchedule.1",IID_IDMSprPriceSchedule, (void**)&schedule);
schedule->Init(InterfaceMainObject,InterfaceImpl);

///БРОНИРОВАНИЕ

if (AddBron==true)
	{
	//получим количество бронирования
	int KolBron=1;
	IDMSetup *dm_setup;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup, (void**)&dm_setup);
	dm_setup->Init(InterfaceMainObject,InterfaceImpl);
	dm_setup->OpenElement(103);
	if (dm_setup->ElementVALUE_SETUP->AsString!="")
		{
		KolBron=StrToInt(dm_setup->ElementVALUE_SETUP->AsString);
		}
	dm_setup->kanRelease();



	unsigned short year,month,day,hour,min,sec,msec;
	DecodeDateTime(PosNachBron,year,month,day,hour,min,sec,msec);


	TDateTime tek_pos_nach=PosNachBron;
	TDateTime tek_pos;



	tek_pos=EncodeDateTime(year,month,day,int_rasch_hour,0,0,0);
   //	ShowMessage("Начало отсчета:"+DateTimeToStr(tek_pos));

	double tek_kol=0;
	double tek_price=0;


//	int kol_dob_strok=0;
	double new_price=0;


	tek_price=schedule->GetValuePrice(id_nom_bron, IdTypePrice,id_ed_bron, tek_pos+0.01);

	TDateTime pos_con=PosConBron;

	if (tek_pos+1<=pos_con)
		{


	Loop:
			new_price=schedule->GetValuePrice(id_nom_bron, IdTypePrice,id_ed_bron,tek_pos+0.01);

				if (tek_price==new_price)
					{
					tek_kol++;
					}
				else
					{ //создаем новую строку
					//услуга бронирования

						int kol_bron=0;
						if (tek_kol<KolBron)
							{
							kol_bron=tek_kol;
							KolBron=KolBron-tek_kol;
							}
						else
							{
							kol_bron=KolBron;
							KolBron=0;
							}
						if (kol_bron>0 && id_nom_bron>0 )
							{
							AddStringNewReal( tek_pos_nach,	pos_con,
								id_nom_bron, name_nom_bron,
								id_ed_bron,kf_ed_bron,name_ed_bron,
								new_price,
								kol_bron,
								2
								);
							}


					tek_price=new_price;
					tek_pos_nach=tek_pos;
					tek_kol=1;
					}
			 tek_pos++;
			 if (tek_pos+1<=pos_con) goto Loop;

		}

	if (tek_pos<pos_con)
		{
		//необходимо добавить задержку после расчетного часа
	   //	ShowMessage("Рассчитываем задержку между "+DateTimeToStr(tek_pos)+" и "+DateTimeToStr(pos_con));
		int kol_hour=HoursBetween(tek_pos,pos_con);
		if (0<kol_hour && kol_hour<=6)
			{ //почасовая оплата
			tek_kol=tek_kol+(0.04166666666*kol_hour);
			}
		if (6<kol_hour && kol_hour<=12)
			{
			tek_kol=tek_kol+0.5;
			}

		if (12<kol_hour && kol_hour<=18)
			{
			tek_kol=tek_kol+0.75;
			}

		if (18<kol_hour)
			{
			tek_kol=tek_kol+1;
			}
		}

	if (tek_kol<1) tek_kol=1;
	//добавляем последнюю строку
		if (tek_kol!=0)
			{
				int kol_bron=0;
				if (tek_kol<KolBron)
					{
					kol_bron=tek_kol;
					KolBron=KolBron-tek_kol;
					}
				else
					{
					kol_bron=KolBron;
					KolBron=0;
					}
				//услуга бронирования
				if(kol_bron>0 && id_nom_bron>0)
					{
					AddStringNewReal( tek_pos_nach,	pos_con,
							id_nom_bron, name_nom_bron,
							id_ed_bron,kf_ed_bron,name_ed_bron,
							new_price,
							kol_bron,
							2
							);
					}


			}

	}


/////ПРОЖИВАНИЕ
	unsigned short year,month,day,hour,min,sec,msec;
	DecodeDateTime(PosNach,year,month,day,hour,min,sec,msec);


	TDateTime tek_pos_nach=PosNach;
	TDateTime tek_pos=0;



	tek_pos=EncodeDateTime(year,month,day,int_rasch_hour,0,0,0);
   //	ShowMessage("Начало отсчета:"+DateTimeToStr(tek_pos));

	double tek_kol=0;
	double tek_price=0;


//	int kol_dob_strok=0;
	double new_price=0;

	tek_price=schedule->GetValuePrice(id_nom_prog, IdTypePrice,id_ed_prog, tek_pos+0.01);

	TDateTime pos_con=PosCon;

if (tek_pos+1<=pos_con)
	{


	Loop1:
			new_price=schedule->GetValuePrice(id_nom_prog, IdTypePrice,id_ed_prog,tek_pos+0.01);

				if (tek_price==new_price)
					{
					tek_kol++;
					}
				else
					{ //создаем новую строку
					//проживание
					AddStringNewReal( tek_pos_nach, tek_pos,
							id_nom_prog,name_nom_prog,
							id_ed_prog, kf_ed_prog, name_ed_prog,
							new_price,
							tek_kol,
							1
							);
					tek_price=new_price;
					tek_pos_nach=tek_pos;
					tek_kol=1;
					}
			 tek_pos++;
			 if (tek_pos+1<=pos_con) goto Loop1;

	}

	if (tek_pos<pos_con)
		{
		//необходимо добавить задержку после расчетного часа
	   //	ShowMessage("Рассчитываем задержку между "+DateTimeToStr(tek_pos)+" и "+DateTimeToStr(pos_con));
		int kol_hour=HoursBetween(tek_pos,pos_con);
		if (0<kol_hour && kol_hour<=6)
			{ //почасовая оплата
			tek_kol=tek_kol+(0.04166666666*kol_hour);
			}
		if (6<kol_hour && kol_hour<=12)
			{
			tek_kol=tek_kol+0.5;
			}

		if (12<kol_hour && kol_hour<=18)
			{
			tek_kol=tek_kol+0.75;
			}

		if (18<kol_hour)
			{
			tek_kol=tek_kol+1;
			}
		}

if (tek_kol<1) tek_kol=1;
//добавляем последнюю строку
		if (tek_kol!=0)
			{
			//надо получить цену, может жили вообще меньше суток
			if (new_price < 0.01)
				{
				new_price=schedule->GetValuePrice(id_nom_prog, IdTypePrice,id_ed_prog, tek_pos+0.01);
                }
			AddStringNewReal( tek_pos_nach,	pos_con,
							id_nom_prog, name_nom_prog,
							id_ed_prog,kf_ed_prog,name_ed_prog,
							new_price,
							tek_kol,
							1
							)  ;
			}

schedule->kanRelease();

NumberTecString=0;
}
//-----------------------------------------------------------------------------

void TRaschetStoimProg::AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,
							__int64 id_nom, AnsiString name_nom,
							__int64 id_ed, double kf, AnsiString name_ed,
							double price,
							double kol,
							int type_usl
							)
{
StringDoc=new TStringDoc;

StringDoc->TypeUsl=type_usl;
StringDoc->PosNach=pos_nach;
StringDoc->PosCon=pos_con;
StringDoc->IdNom=id_nom;
StringDoc->NameNom=name_nom;
StringDoc->IdEd=id_ed;
StringDoc->NameEd=name_ed;
StringDoc->Kol=kol;
StringDoc->KF=kf;
StringDoc->Price=price;

ResultList->Add(StringDoc);
}
//------------------------------------------------------------------------------
bool TRaschetStoimProg::GetString(void)   //получаем строку, если есть строка то true
{
bool result=false;
NumberTecString++;

if (NumberTecString <= ResultList->Count)
	{
	StringDoc=(TStringDoc*) ResultList->Items[NumberTecString-1];

	result=true;
	}

return result;
}
//----------------------------------------------------------------------------
