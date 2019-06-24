//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprNom.h"
#include "IDMQueryUpdate.h"
#include "IDMSprEd.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

__fastcall TDMSprNom::TDMSprNom(TComponent* Owner)
        : TDataModule(Owner)
{
CheckOst=false;
OnlyChange=false;
IdFirm=0;
IdSklad=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprNom::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;
pFIBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;
pFIBTr->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;

BasEd->Database=DM_Connection->pFIBData;
OsnEd->Database=DM_Connection->pFIBData;
IBQSprGrpBV->Database=DM_Connection->pFIBData;
SpTPrice->Database=DM_Connection->pFIBData;
Code->Database=DM_Connection->pFIBData;

pFIBQuery->Database=DM_Connection->pFIBData;
SprScaleAndGrpVesNom->Database=DM_Connection->pFIBData;
FisEd->Database=DM_Connection->pFIBData;

SpisokEd->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNom::Done(void)
{

return -1;
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
pFIBQuery->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMSprNom::GetTextQuery(__int64 id_grp, bool all, bool check_ost,
					__int64 id_firm, __int64 id_sklad, __int64 id_type_price, bool only_ostatok,
					 bool price_sklad, bool only_change, __int64 id_inet_catalog)
{
UnicodeString result="";
if(all==true)
		{//��� �����
		if (check_ost==false)   //��� ��������
				{
				if (only_ostatok==false)
					{
					if (price_sklad==false)
						{//��� ���������//��� ��������  //��� ������, �� ������ �������  //���� �� �����������
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED, ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 AS REM_OST";
						result=result+" from SNOM";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM";
						}
					else
						{//��� ��������//��� ��������//��� ������, �� ������ ������� //���� ������
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 AS REM_OST ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						result=result+"	ORDER BY NAMENOM";
						}
					}
				else //������ �������
					{
					if (price_sklad==false)
						{//��� ���������//��� ��������  //������ �������  //���� �� �����������
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 as REM_OST";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					else
						{//��� ��������//��� ��������// ������ ������� //���� ������
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 as REM_OST ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					}
				}
		else     //� ���������
				{
				if (only_ostatok==false)
					{
					if (PriceSklad==false)
						{//��� ���������//c ���������  //��� ������, �� ������ �������  //���� �� �����������
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);

						result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
						result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);

                     	result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+"	ORDER BY NAMENOM";
						}
					else
						{ //��� ���������//� ��������  //��� ������, �� ������ �������  //���� �� ������
						result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
						result=result+"from SNOM  ";
						result=result+"left outer join SED on IDBASEDNOM=IDED ";
						result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);

						result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
						result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);


						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						//if (only_change==true) result=result+" where FL_CHANGE_NOM=1";
						result=result+"	ORDER BY NAMENOM";

						}
					}
				else //������ �������
					{
					if (price_sklad==false)
						{//��� ���������//� ���������  //������ �������  //���� �� �����������
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+" ZNACH_PRICE, IDGRPNOM, snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
						result=result+" and IDED_SPRICE=IDBASEDNOM";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					else
						{//��� ��������//� ���������// ������ ������� //���� ������
						result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
						result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
						result=result+" from rggoods ";
						result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
						result=result+" left outer join SED on IDBASEDNOM=IDED ";
						result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
						result=result+" where rggoods.kol_rggoods!=0 ";
						result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
						result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
						//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
						result=result+" ORDER BY NAMENOM ";
						}
					}
				}
		} //��� �����
else
		{ //�� �������
		if (id_grp==0)
				{ //�������� �������
				if (check_ost==false)  //�������� ������� // ��� ��������
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//�������� �������� ������//��� ��������  //��� ������, �� ������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 AS REM_OST";
								result=result+" from SNOM";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM";
								}
							else
								{//�������� �������� ������//��� ��������//��� ������, �� ������ ������� //���� ������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 AS REM_OST ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							}
						else //������ �������
							{
							if (price_sklad==false)
								{//�������� �������� ������//��� ��������  //������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM, snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL , 0.000 AS REM_OST";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//�������� �������� ������//��� ��������// ������ ������� //���� ������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, SHED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
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
				else     //�������� �������//� ���������
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//�������� �������� �������//c ���������  //��� ������, �� ������ �������  //���� �� �����������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);


								result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
								result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);



								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							else
								{ //�������� �������� �������//� ��������  //��� ������, �� ������ �������  //���� �� ������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);


								result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
								result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);


								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM IS NULL";
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";

								}
							}
						else //������ �������
							{
							if (price_sklad==false)
								{//�������� �������� �������//� ���������  //������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM IS NULL";
							   //	if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//�������� �������� �������//� ���������// ������ ������� //���� ������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST  ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
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
		else    //������ ������
				{

				if (check_ost==false)  //������ ������ // ��� ��������
						{
						if (only_ostatok==false)
							{
							if (PriceSklad==false)
								{//�������� ������ ������//��� ��������  //��� ������, �� ������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 as REM_OST";
								result=result+" from SNOM";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM="+IntToStr(id_grp);
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM";
								}
							else
								{//�������� ������ ������//��� ��������//��� ������, �� ������ ������� //���� ������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, 0.000 AS SUMKOL, 0.000 AS REM_OST  ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM"+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							}
						else //������ �������
							{
							if (price_sklad==false)
								{//�������� ������ ������//��� ��������  //������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM, snominetcat.id_snominetcat,rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST  ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(IdGrp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//�������� ������ ������//��� ��������// ������ ������� //���� ������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, SHED, ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST  ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							}
						}
				else     //������ ������//� ���������
						{
						if (only_ostatok==false)
							{
							if (price_sklad==false)
								{//�������� ������ ������//c ���������  //��� ������, �� ������ �������  //���� �� �����������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);

								result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
								result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);


								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";
								}
							else
								{ //�������� ������ ������//� ��������  //��� ������, �� ������ �������  //���� �� ������
								result=result+"select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+"rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, rem_rggoods.kol_rem_rggoods as REM_OST ";
								result=result+"from SNOM  ";
								result=result+"left outer join SED on IDBASEDNOM=IDED ";
								result=result+"	left outer join rggoods on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" and rggoods.idfirm_rggoods="+IntToStr(id_firm)+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);


								result=result+"	left outer join rem_rggoods on snom.idnom=rem_rggoods.idnom_rem_rggoods ";
								result=result+" and rem_rggoods.idfirm_rem_rggoods="+IntToStr(id_firm)+" and rem_rggoods.idsklad_rem_rggoods= "+IntToStr(id_sklad);


								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where IDGRPNOM="+IntToStr(id_grp);;
								//if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+"	ORDER BY NAMENOM";

								}
							}
						else //������ �������
							{
							if (price_sklad==false)
								{//�������� ������ ������//� ���������  //������ �������  //���� �� �����������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" ZNACH_PRICE, IDGRPNOM,snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
								result=result+" and IDED_SPRICE=IDBASEDNOM";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
								result=result+" where rggoods.kol_rggoods!=0 ";
								result=result+" and rggoods.idfirm_rggoods= "+IntToStr(id_firm);
								result=result+" and rggoods.idsklad_rggoods= "+IntToStr(id_sklad);
								result=result+" and IDGRPNOM="+IntToStr(IdGrp);
							   //	if (only_change==true) result=result+" and FL_CHANGE_NOM=1";
								result=result+" ORDER BY NAMENOM ";
								}
							else
								{//�������� ������ ������//� ���������// ������ ������� //���� ������
								result=result+" select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED,SHED,  ";
								result=result+" rggoods.rprice_rggoods as ZNACH_PRICE, IDGRPNOM, snominetcat.id_snominetcat, rggoods.kol_rggoods AS SUMKOL, 0.000 AS REM_OST ";
								result=result+" from rggoods ";
								result=result+" left outer join snom on snom.idnom=rggoods.idnom_rggoods ";
								result=result+" left outer join SED on IDBASEDNOM=IDED ";
								result=result+" left outer join snominetcat on snom.idnom=snominetcat.idnom_snominetcat and snominetcat.idinetcat_snominetcat="+IntToStr(id_inet_catalog);
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
//				if (check_ost==false)    //������ ������//��� ��������
//						{
//						result=result+" select IDNOM,FL_CHANGE_NOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE, IDGRPNOM, 0.000 AS SUMKOL";
//						result=result+" from SNOM";
//						result=result+" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(id_type_price);
//						result=result+" left outer join SED on IDBASEDNOM=IDED";
//						result=result+" where IDGRPNOM="+IntToStr(id_grp);
//						if (OnlyChange==true) result=result+" and FL_CHANGE_NOM=1";
//						result=result+" ORDER BY NAMENOM";
//						}
//				else   //������ ������ //� ���������
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
Table->ParamByName("PARAM_IDGRP")->AsString=Grp;
if (All==true)
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=0;
	}
Table->ParamByName("PARAM_IDFIRM")->AsString=IdFirm;
Table->ParamByName("PARAM_IDSKLAD")->AsString=IdSklad;
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsString=IdTypePrice;
Table->ParamByName("PARAM_IDINET_CAT")->AsString=IdInetCatalog;

Table->ParamByName("PARAM_FL_OST")->AsInteger=CheckOst;


 //   :PARAM_FL_RASV_FIRM,
//	:PARAM_IDSKLAD,
//    :PARAM_FL_RASV_SKLAD,
//    :PARAM_IDTNOM,
 //   :PARAM_FL_RASV_TNOM,
 //   :PARAM_FL_PRICE_SKLAD,
 //	:PARAM_FL_RASV_PRICE_PO_ED,
//    :PARAM_FL_ONLY_OST,
 //	:PARAM_IDINET_CAT

//Table->SelectSQL->Clear();
//Table->SelectSQL->Add(GetTextQuery(Grp,All,CheckOst,IdFirm,IdSklad,IdTypePrice,OnlyOstatok,PriceSklad,OnlyChange,IdInetCatalog));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprNom::NewElement(__int64 IdGrp)
{
bool result=false;
Element->Active=false;
Code->Active=false;

//if(glError==false)
//		{
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
				ElementNAMENOM->AsString="������������ �"+ElementCODENOM->AsString;
				ElementFNAMENOM->AsString=ElementNAMENOM->AsString;
				ElementKRNAMENOM->AsString=ElementNAMENOM->AsString;
				ElementTNOM->AsInteger=0;
				Element->Post();
				if (SaveElement()==true)
					{
					IDMSprEd * ed;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd, (void**)&ed);
					ed->Init(InterfaceMainObject,0);
					if (ed->NewElement(glStrToInt64(ElementIDNOM->AsString))==true)
						{
						ed->ElementNAMEED->AsString="��.";
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
								TextError="�� ������� �������� ������� ����� �������� ������� �������! "+TextError;
								}
							}
						else
							{
							Error=true;
							result=false;
							TextError="�� ������� �������� ������� ������� ���������! "+ed->TextError;
							}
						}
					else
						{
						Error=true;
						result=false;
						TextError="�� ������� ������� ������� ������� ���������! "+ed->TextError;
						}

					ed->kanRelease();

					}
				else
					{
					Error=true;
					result=false;
					TextError="�� ������� �������� ����� �������! "+TextError;
					}

				}
		else
				{
				Error=true;
				result=false;
				TextError="�� ������� ������������ ��� ��������! \n ��������� ������������ �������� ����!";

				}
//        Code->Active=false;
//        }
//else
//		{
//		Error=true;
//		result=false;
//		TextError="�� ������� ������� ����� �������! ������ � ���������� ���������!";
//
//		}
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
__int64 TDMSprNom::FindPoArtikulu(UnicodeString artikul)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDNOM from SNOM where ARTNOM=:PARAM_ART");
pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
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

//��������� ��� �� ������������
if (CheckCode(glStrToInt64(ElementIDNOM->AsString),
			 ElementCODENOM->AsInteger)==true)
	{
	res=false;
	TextError="��� ������ �� ���������� !";
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
void TDMSprNom::ChancheGrp(__int64 NewGrp, __int64 id_nom)
{
OpenElement(id_nom);
Element->Edit();
ElementIDGRPNOM->AsString=NewGrp;
Element->Post();
SaveElement();
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
IDMQueryUpdate * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate, (void**)&dm);
dm->Init(InterfaceMainObject,0);
try {
	//������ �������� ������������
	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SSEZKF where IDNOM_SSEZKF="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//�������������
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SMOD where IDNOM_MOD="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//�������� ������������ �� ������

	//������

	//���. ��������


	//������
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SPART where IDNOMPART="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//����
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SPRICE where IDNOM_PRICE="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//��������� � NULL �������� � ������� �������
	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("update SNOM set");
	dm->pFIBQ->SQL->Add("  IDBASEDNOM = NULL, ");
	dm->pFIBQ->SQL->Add("  IDOSNEDNOM =  NULL, ");
	dm->pFIBQ->SQL->Add("  IDFISED_SNOM =  NULL ");
	dm->pFIBQ->SQL->Add("where   IDNOM = "+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	dm->pFIBTr->Commit();   //���������� �.�. � ������ ������ ������ �������� �� ��������� � ������ ����

	//������ �������
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("delete from SED where IDNOMED="+IntToStr(id_nom));
	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();

	//���������� ��� �������
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

dm->kanRelease();
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
//���������� true ���� ����� ��� �� ����������
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



