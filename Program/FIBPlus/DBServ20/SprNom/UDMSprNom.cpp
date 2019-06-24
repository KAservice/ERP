//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprNom.h"
#include "UDM.h"
#include "UDMSetup.h"
#include "UDMQueryUpdate.h"
#include "UDMSprEd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern bool gl_add_table_ism;
extern AnsiString glPrefiksKolShtrihCoda;
extern AnsiString glPrefiksLokShtrihCoda;
extern int glMinCodNom;
extern int glMaxCodNom;
extern bool glError;
//---------------------------------------------------------------------------

__fastcall TDMSprNom::TDMSprNom(TComponent* Owner)
        : TDataModule(Owner)
{
CheckOst=false;
OnlyChange=false;
IdFirm=0;
IdSklad=0;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
BasEd->Active=false;
OsnEd->Active=false;
FisEd->Active=false;
SpTPrice->Active=false;
SprScaleAndGrpVesNom->Active=false;
IBQSprGrpBV->Active=false;
SpisokEd->Active=false;
}
//---------------------------------------------------------------------------
AnsiString TDMSprNom::GetTextQuery(__int64 id_grp, bool all, bool check_ost,
					__int64 id_firm, __int64 id_sklad, __int64 id_type_price, bool only_ostatok,
					 bool price_sklad, bool only_change)
{
AnsiString result="";
if(all==true)
		{//без групп
		if (check_ost==false)   //без остатков
				{
				if (only_ostatok==false)
					{
					if (price_sklad==false)
						{//без иерархиии//без остатков  //все товары, не только остатки  //цены из справочника
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
						result=result+" from SNOM";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED";
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM";
						}
					else
						{//без иерархии//без остатков//все товары, не только остатки //цены склада
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+"	ORDER BY NAMENOM";
						}
					}
				else //только остатки
					{
					if (price_sklad==false)
						{//без иерархиии//без остатков  //только остатки  //цены из справочника
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";

						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					else
						{//без иерархии//без остатков// только остатки //цены склада
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";

						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					}
				}
		else     //с остатками
				{
				if (only_ostatok==false)
					{
					if (PriceSklad==false)
						{//без иерархиии//c остатками  //все товары, не только остатки  //цены из справочника
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+"	ORDER BY NAMENOM";
						}
					else
						{ //без иерархиии//с остаткми  //все товары, не только остатки  //цены со склада
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+"	ORDER BY NAMENOM";

						}
					}
				else //только остатки
					{
					if (price_sklad==false)
						{//без иерархиии//с остатками  //только остатки  //цены из справочника
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";

						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					else
						{//без иерархии//с остатками// только остатки //цены склада
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
						result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";

						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					}
				}
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				if (check_ost==false)  //корневой каталог // без остатков
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//иерархия корневая группа//без остатков  //все товары, не только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
								result=result+" from SNOM";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED";
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM";
								}
							else
								{//иерархия корневая группа//без остатков//все товары, не только остатки //цены склада
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							}
						else //только остатки
							{
							if (price_sklad==false)
								{//иерархия корневая группа//без остатков  //только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//иерархия корневая группа//без остатков// только остатки //цены склада
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							}
//						result=result+" select IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
//                        result=result+" from SNOM ";
//                        result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
//                        result=result+" left outer join SED on IDBASEDNOM=IDED";
//						result=result+" where IDGRPNOM IS NULL";
//						if (OnlyChange==true) result=result+" and FL_CHANGE_NOM=1";
//                        result=result+" ORDER BY NAMENOM";
						}
				else     //корневой каталог//с остатками
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//иерархия корневой каталог//c остатками  //все товары, не только остатки  //цены из справочника
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							else
								{ //иерархия корневой каталог//с остаткми  //все товары, не только остатки  //цены со склада
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";

								}
							}
						else //только остатки
							{
							if (price_sklad==false)
								{//иерархия корневой каталог//с остатками  //только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
							   //	if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//иерархия корневой каталог//с остатками// только остатки //цены склада
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							}
						}

//						result=result+" select IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, sum(rgostnom.kolostnom) AS SUMKOL";
//                        result=result+" from SNOM";
//                        result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
//                        result=result+" left outer join SED on IDBASEDNOM=IDED";
//                        result=result+" left outer join rgostnom on snom.idnom=rgostnom.idnomostnom";
//                        result=result+" and rgostnom.idfirmostnom="+IntToStr(id_firm)+ " and rgostnom.idsklostnom="+IntToStr(id_sklad);
//						result=result+" where IDGRPNOM IS NULL";
//						if (OnlyChange==true) result=result+" and FL_CHANGE_NOM=1";
//						result=result+" group by IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM";
//                        result=result+" ORDER BY NAMENOM";
//						}
				}
		else    //задана группа
				{

				if (check_ost==false)  //задана группа // без остатков
						{
						if (only_ostatok==false)
							{
							if (PriceSklad==false)
								{//иерархия задана группа//без остатков  //все товары, не только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
								result=result+" from SNOM";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED";
								result=result+" where IDGRPNOM="+IntToStr(id_grp);
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM";
								}
							else
								{//иерархия задана группа//без остатков//все товары, не только остатки //цены склада
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" where IDGRPNOM"+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							}
						else //только остатки
							{
							if (price_sklad==false)
								{//иерархия задана группа//без остатков  //только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(IdGrp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//иерархия задана группа//без остатков// только остатки //цены склада
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							}
						}
				else     //задана группа//с остатками
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//иерархия задана группа//c остатками  //все товары, не только остатки  //цены из справочника
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" where IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							else
								{ //иерархия задана группа//с остаткми  //все товары, не только остатки  //цены со склада
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" where IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";

								}
							}
						else //только остатки
							{
							if (price_sklad==false)
								{//иерархия задана группа//с остатками  //только остатки  //цены из справочника
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(IdGrp);
							   //	if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//иерархия задана группа//с остатками// только остатки //цены склада
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, rggoods.kol_rggoods AS SUMKOL ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";

								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(id_grp);
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							}
						}
                }
//				if (check_ost==false)    //задана группа//без остатков
//						{
//						result=result+" select IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
//						result=result+" from SNOM";
//						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
//						result=result+" left outer join SED on IDBASEDNOM=IDED";
//						result=result+" where IDGRPNOM="+IntToStr(id_grp);
//						if (OnlyChange==true) result=result+" and FL_CHANGE_NOM=1";
//						result=result+" ORDER BY NAMENOM";
//						}
//				else   //задана группа //с остатками
//						{
//						result=result+" select IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, sum(rgostnom.kolostnom) AS SUMKOL";
//						result=result+" from SNOM";
//						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
//						result=result+" left outer join SED on IDBASEDNOM=IDED";
//						result=result+" left outer join rgostnom on snom.idnom=rgostnom.idnomostnom";
//						result=result+" and rgostnom.idfirmostnom="+IntToStr(id_firm)+ " and rgostnom.idsklostnom="+IntToStr(id_sklad);
//						result=result+" where IDGRPNOM="+IntToStr(id_grp);
//						if (OnlyChange==true) result=result+" and FL_CHANGE_NOM=1";
//						result=result+" group by IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM";
//						result=result+" ORDER BY NAMENOM";
//						}
//				}
        }


return result;
}
//---------------------------------------------------------------------------
void  TDMSprNom::OpenTable(__int64 Grp,bool All)
{
IdGrp=Grp;
AllElement=All;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(Grp,All,CheckOst,IdFirm,IdSklad,IdTypePrice,OnlyOstatok,PriceSklad,OnlyChange));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprNom::NewElement(__int64 IdGrp)
{
bool result=false;
Element->Active=false;
Code->Active=false;

if(glError==false)
        {
//        Code->ParamByName("PARAM_CODEMIN")->AsInteger=glMinCodNom;
//		Code->ParamByName("PARAM_CODEMAX")->AsInteger=glMaxCodNom;
//		Code->Active=true;
		int code=GetCodeNom();
//		if (code==0) code=glMinCodNom;
//		if ( (code+1)<glMaxCodNom)

		if (code!=0)
				{
				Element->Open();
				Element->Insert();
				if (IdGrp!=0)
						{
						ElementIDGRPNOM->AsString=IdGrp;
						}
				ElementCODENOM->AsInteger=code+1;
				ElementNAMENOM->AsString="Номенклатура №"+ElementCODENOM->AsString;
				ElementFNAMENOM->AsString=ElementNAMENOM->AsString;
				ElementKRNAMENOM->AsString=ElementNAMENOM->AsString;
				ElementTNOM->AsInteger=0;
				Element->Post();
				if (SaveElement()==true)
					{
					TDMSprEd * ed=new TDMSprEd(Application);
					if (ed->NewElement(glStrToInt64(ElementIDNOM->AsString))==true)
						{
						ed->ElementNAMEED->AsString="шт.";
						ed->Element->Post();
						if (ed->SaveElement()==true)
							{
							Element->Edit();
							ElementIDBASEDNOM->AsString=ed->ElementIDED->AsString;
							ElementIDOSNEDNOM->AsString=ed->ElementIDED->AsString;
                            ElementIDFISED_SNOM->AsString=ed->ElementIDED->AsString;
							Element->Post();
							if (SaveElement()==true)
								{
								result=true;
								}
							else
								{
								Error=true;
								result=false;
								TextError="Не удалось записать элемент после создания базовой единицы! "+TextError;
								}
							}
						else
							{
							Error=true;
							result=false;
							TextError="Не удалось записать базовую единицу измерения! "+ed->TextError;
							}
						}
					else
						{
						Error=true;
						result=false;
						TextError="Не удалось создать базовую единицу измерения! "+ed->TextError;
						}

					delete ed;

					}
				else
					{
					Error=true;
					result=false;
					TextError="Не удалось записать новый элемент! "+TextError;
					}

				}
		else
				{
				Error=true;
				result=false;
				TextError="Не удалось сформировать код элемента! \n Превышено максимальное значение кода!";

				}
//        Code->Active=false;
        }
else
        {
        Error=true;
        result=false;
		TextError="Не удалось создать новый элемент! Ошибки в настройках программы!";

        }
return result;
}
//---------------------------------------------------------------------------

int TDMSprNom::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=IdTypePrice;
Element->Active=true;

BasEd->Active=false;
BasEd->ParamByName("IDBASED")->AsInt64=glStrToInt64(ElementIDBASEDNOM->AsString);
BasEd->Active=true;


OsnEd->Active=false;
OsnEd->ParamByName("IDOSNED")->AsInt64=glStrToInt64(ElementIDOSNEDNOM->AsString);
OsnEd->Active=true;

FisEd->Active=false;
FisEd->ParamByName("IDFISED")->AsInt64=glStrToInt64(ElementIDFISED_SNOM->AsString);
FisEd->Active=true;

OpenSpisokEd(Id);

if (glStrToInt64(ElementIDBASEDNOM->AsString)>0)
        {
        ElementIDBASEDNOM->ReadOnly=true;
        }

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
__int64 TDMSprNom::FindPoCodu(int Code)
{

__int64 Res=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
		pFIBQuery->SQL->Add("select IDNOM from SNOM where CODENOM=:CODE");
		pFIBQuery->ParamByName("CODE")->AsInteger=Code;
		pFIBQuery->ExecQuery();
		Res=OpenElement(pFIBQuery->FieldByName("IDNOM")->AsInt64);
pFIBQuery->Close();
return Res;


}
//----------------------------------------------------------------------------
__int64 TDMSprNom::GetIdBasEd(__int64 id_nom)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDBASEDNOM from SNOM where IDNOM=:PARAM_ID");
pFIBQuery->ParamByName("PARAM_ID")->AsString=IntToStr(id_nom);
pFIBQuery->ExecQuery();
result=glStrToInt64(pFIBQuery->FieldByName("IDBASEDNOM")->AsInt64);
pFIBQuery->Close();
return result;

}
//----------------------------------------------------------------------------
__int64 TDMSprNom::FindPoName(AnsiString name)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOM from SNOM where NAMENOM=:PARAM_NAME");
pFIBQuery->ParamByName("PARAM_NAME")->AsString=name;
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
pFIBQuery->Close();
return result;


}
//---------------------------------------------------------------------------
bool  TDMSprNom::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementIDNOM->AsString);

//проверить код на уникальность
if (CheckCode(glStrToInt64(ElementIDNOM->AsString),
			 ElementCODENOM->AsInteger)==true)
	{
	res=false;
	TextError="Код товара не уникальный !";
	return res;
	}



try
        {
		if (glStrToInt64(ElementIDOSNEDNOM->AsString)==0)
                {
				if (glStrToInt64(ElementIDBASEDNOM->AsString)!=0)
                        {
                        Element->Edit();
						ElementIDOSNEDNOM->AsString=ElementIDBASEDNOM->AsString;
                        Element->Post();
                        }
				}


        Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(IdElement);
        res=true;
        }
catch(Exception &exception)
        {
        Error=true;
		TextError=exception.Message;
		//ShowMessage(TextError);
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMSprNom::DeleteElement(__int64 Id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------
void TDMSprNom::ChancheGrp(__int64 NewGrp)
{
OpenElement(TableIDNOM->AsInt64);
Element->Edit();
ElementIDGRPNOM->AsString=NewGrp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------
int TDMSprNom::GetIndexTypePrice(void)
{
int res=1;
SpTPrice->First();
while (!SpTPrice->Eof)
        {
		if (IdTypePrice==SpTPriceID_TPRICE->AsInt64)
                {
                return res;
                }
                res=res+1;
        SpTPrice->Next();
        }
return 0;
}
//---------------------------------------------------------------------------


__int64 TDMSprNom::GetIDElement(String gid)
{
__int64 res=0;
pFIBQuery->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select IDNOM from SNOM where GID_SNOM=:PARAM_GID");
				pFIBQuery->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQuery->ExecQuery();

				res=pFIBQuery->FieldByName("IDNOM")->AsInt64;

                }
pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprNom::GetGIDElement(__int64 id)
{
AnsiString res="";
pFIBQuery->Close();
        if (id!=0 )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select GID_SNOM from SNOM where IDNOM=:PARAM_ID");
				pFIBQuery->ParamByName("PARAM_ID")->AsInt64=id;
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=Trim(pFIBQuery->FieldByName("GID_SNOM")->AsString);
                        }
				else res="";
                }
 pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------

__int64 TDMSprNom::FindPoShtrihCodu(AnsiString shtrih_cod)
{
__int64 result=0;

pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOMED from SED where SHED='"+shtrih_cod+"'");
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("IDNOMED")->AsInt64;
pFIBQuery->Close();
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNom::TableAfterScroll(TDataSet *DataSet)
{
PorNumberString=Table->RecNo;	
}
//---------------------------------------------------------------------------

__int64 TDMSprNom::GetIdGrpNom(__int64 id_nom)
{
__int64 res;
res=0;
 pFIBQuery->Close();
 pFIBQuery->SQL->Clear();
		pFIBQuery->SQL->Add("select IDGRPNOM from SNOM where IDNOM='"+IntToStr(id_nom)+"'");
		pFIBQuery->ExecQuery();
		res=pFIBQuery->FieldByName("IDGRPNOM")->AsInt64;
 pFIBQuery->Close();
return res;

}
//-----------------------------------------------------------------------------
bool TDMSprNom::ClearFlagChange(void)
{
bool  result=false;

try {
	pFIBQuery->Close();
	pFIBQuery->Transaction=pFIBTrUpdate;
	pFIBQuery->SQL->Clear();
	pFIBQuery->SQL->Add("update SNOM set FL_CHANGE_NOM=0 where FL_CHANGE_NOM>0 ");
   //	if (pFIBTrUpdate->Active==false) IBTr->StartTransaction();
	pFIBQuery->ExecQuery();
	pFIBQuery->Close();

	pFIBQuery->SQL->Clear();
	pFIBQuery->SQL->Add("update SPRICE set FL_CHANGE_PRICE=0 where FL_CHANGE_PRICE>0");
	pFIBQuery->ExecQuery();
	pFIBTrUpdate->Commit();
	pFIBQuery->Close();
	result=true;
	}
catch(Exception &exception)
				{
				pFIBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprNom::DeleteNom(__int64 id_nom)
{
bool result=false;
TDMQueryUpdate * dm=new TDMQueryUpdate(Application);
try {
	//удалим сезонные коэффициенты
	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SSEZKF where IDNOM_SSEZKF="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//модификаторов
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SMOD where IDNOM_MOD="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//сезонные коэффициенты на состав

	//состав

	//доп. сведения


	//партии
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SPART where IDNOMPART="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//цены
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SPRICE where IDNOM_PRICE="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//установим в NULL основную и базовую единицы
	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("update SNOM set");
	dm->pFIBQ->SQL->Add("  IDBASEDNOM = NULL, ");
	dm->pFIBQ->SQL->Add("  IDOSNEDNOM =  NULL, ");
	dm->pFIBQ->SQL->Add("  IDFISED_SNOM =  NULL ");
	dm->pFIBQ->SQL->Add("where   IDNOM = "+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//удалим единицы
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SED where IDNOMED="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//собственно сам элемент
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SNOM where IDNOM="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();


	
	dm->pFIBTr->Commit();
	result=true;
	}
catch(Exception &exception)
				{
				dm->pFIBTr->Rollback();
				TextError=exception.Message;
				result=false;
				}

delete dm;
return result;
}
//------------------------------------------------------------------------------
int TDMSprNom::GetCodeNom(void)
{
int result=0;
int max_code_nom=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("SELECT GEN_ID(GEN_SNOM_CODE,1) FROM RDB$DATABASE");
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("GEN_ID")->AsInteger;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("SELECT VALUE_SETUP FROM SETUP WHERE ID_SETUP=201");
pFIBQuery->ExecQuery();
max_code_nom=pFIBQuery->FieldByName("VALUE_SETUP")->AsInteger;
pFIBQuery->Close();

if (max_code_nom!=0)
	{
	if (result>max_code_nom)
		{
        result=0;
		}
	}

return result;
}
//---------------------------------------------------------------------------
bool TDMSprNom::CheckCode(__int64 id_nom, int code)
{
//возвращает true если штрих код не уникальный
bool result=false;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
		pFIBQuery->SQL->Add("select IDNOM");
		pFIBQuery->SQL->Add(" from SNOM");
		pFIBQuery->SQL->Add(" where CODENOM=:PARAM_CODENOM");
		pFIBQuery->ParamByName("PARAM_CODENOM")->AsString=code;
		pFIBQuery->ExecQuery();
		while(!pFIBQuery->Eof)
			{
			if (id_nom!=glStrToInt64(pFIBQuery->FieldByName("IDNOM")->AsString))
				{
				result=true;
				}
			pFIBQuery->Next();
			}
pFIBQuery->Close();
return result;
}
//----------------------------------------------------------------------------

void TDMSprNom::OpenSpisokEd(__int64 id_nom)
{
SpisokEd->Active=false;
SpisokEd->ParamByName("PARAM_IDNOM")->AsString=id_nom;
SpisokEd->Active=true;
}
//---------------------------------------------------------------------------
void TDMSprNom::OpenEd(void)
{
BasEd->Active=false;
BasEd->ParamByName("IDBASED")->AsInt64=glStrToInt64(ElementIDBASEDNOM->AsString);
BasEd->Active=true;

OsnEd->Active=false;
OsnEd->ParamByName("IDOSNED")->AsInt64=glStrToInt64(ElementIDOSNEDNOM->AsString);
OsnEd->Active=true;

FisEd->Active=false;
FisEd->ParamByName("IDFISED")->AsInt64=glStrToInt64(ElementIDFISED_SNOM->AsString);
FisEd->Active=true;

}
//-----------------------------------------------------------------------------
void TDMSprNom::OpenBasEd(void)
{
BasEd->Active=false;
BasEd->ParamByName("IDBASED")->AsInt64=glStrToInt64(ElementIDBASEDNOM->AsString);
BasEd->Active=true;
}
//-----------------------------------------------------------------------------
void TDMSprNom::OpenOsnEd(void)
{
OsnEd->Active=false;
OsnEd->ParamByName("IDOSNED")->AsInt64=glStrToInt64(ElementIDOSNEDNOM->AsString);
OsnEd->Active=true;
}
//-----------------------------------------------------------------------------
void TDMSprNom::OpenFisEd(void)
{
FisEd->Active=false;
FisEd->ParamByName("IDFISED")->AsInt64=glStrToInt64(ElementIDFISED_SNOM->AsString);
FisEd->Active=true;
}
//-----------------------------------------------------------------------------
