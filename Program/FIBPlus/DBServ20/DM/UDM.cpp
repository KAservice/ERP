//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDM.h"
#include "inifiles.hpp"
#include "math.h"
#include <fstream.h>
#include "UDMSprUser.h"
#include "DateUtils.hpp"
#include "SYSUtils.hpp"
#include "UDMSetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxStyles"
#pragma link "cxLocalization"
#pragma link "cxEdit"
#pragma link "cxEditRepositoryItems"
#pragma resource "*.dfm"
TDM *DM;
TDMSprUser * glUser;
String gl_prefiks_ib;
bool gl_add_table_ism;
AnsiString glStringFullTypeDoc;
AnsiString glStringFullTypeDocNoCheck;
extern AnsiString BaseVersion;
extern AnsiString ProgramVersion;


AnsiString glPrefiksKolShtrihCoda;
AnsiString glPrefiksLokShtrihCoda;
int glMinCodNom;
int glMaxCodNom;
bool glError;
bool glDemo;

//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
        : TDataModule(Owner)
{
pFIBData->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleCreate(TObject *Sender)
{
glStringFullTypeDoc="'PRN', 'CHK', 'SCH', 'OSN', 'PER', 'SPN', 'VPO',  'PKO', 'RKO',\
  'PLP', 'PNS', 'INV', 'REAL_REST', 'REPKKM', 'REA', 'OSTVS', 'SCHFACT','REALROZN',\
  'PKOROZN','RKOROZN','VPOK', 'ISMPRICE','SPOTROST', 'REV','VIPPROD','SBKOMPL','RASBKOMPL',\
  'ZAMENA','KORRVS','VIPBANK',\
  'RG_ADVCUST', 'RG_BANK', 'RG_GOODS', 'RG_KASSA', 'RG_OSTNOM', 'RG_PAYSALE', 'RG_VSRASCH', 'RG_CARDBAL'";

glStringFullTypeDocNoCheck="'PRN','SCH', 'OSN', 'PER', 'SPN', 'VPO',  'PKO', 'RKO',\
  'PLP', 'PNS', 'INV', 'REAL_REST', 'REPKKM', 'REA', 'OSTVS', 'SCHFACT','REALROZN',\
  'PKOROZN','RKOROZN','VPOK', 'ISMPRICE','SPOTROST', 'REV', 'VIPPROD','SBKOMPL','RASBKOMPL',\
  'ZAMENA','KORRVS','VIPBANK', \
  'RG_ADVCUST', 'RG_BANK', 'RG_GOODS', 'RG_KASSA', 'RG_OSTNOM', 'RG_PAYSALE', 'RG_VSRASCH','RG_CARDBAL'";
  
glUser=new TDMSprUser(Application);
}
//---------------------------------------------------------------------------

void __fastcall TDM::DataModuleDestroy(TObject *Sender)
{
if (glUser!=0) delete glUser;
//IBData->Connected=false;

if (pFIBData->Connected)	{
	//for (i = 0; i < pFIBData->TransactionCount-1; i++) {
	//	if (pFIBTr(pFIBData->Transactions[i]).InTransaction) {
	//	pFIBTr
	//	}
	//}

	pFIBData->CloseDataSets();
	pFIBData->Connected=false;
	}




}
//---------------------------------------------------------------------------
void TDM::DisconnectBase(void)
{
 if (glUser!=0) delete glUser;
 glUser=0;
//IBData->Connected=false;

if (pFIBData->Connected)
	{ 
	pFIBData->CloseDataSets();
	pFIBData->Connected=false;
	}
}
//-------------------------------------------------------------------------
bool TDM::CheckEnableStart(AnsiString role_user)
{
bool result=false;
AnsiString file_name=ExtractFileName(Application->ExeName);

	if (file_name=="PAdmin.exe")
		{
		if (role_user=="CASHIERS" ||
						   role_user=="CASHSERVERS"  ||
						   role_user=="ROLE_USERINFO" )
			{
			throw Exception("Недостаточно прав доступа для запуска программы! Текущая роль пользователя: "+role_user);
			}
		}

return result;		
}
//---------------------------------------------------------------------------
bool TDM::GlobConnect(void)
{
bool Res=false;
TextVipOper="Выполненные операции:";

NameServer=GetNameServer(ConnectString);
AnsiString role_user;

try
		{
		//
		if (NameUser=="SYSDBA")
			{
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser);
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;

            TextVipOper="Подключение SYSDBA - OK";
			}
		else
			{//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;
			TextVipOper=TextVipOper+" Подключение USERINFO - OK";

			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+NameUser+"'");
			pFIBQ->ExecQuery();
			TextVipOper=TextVipOper+" Получение NAME2 - OK";

			NameUser2=pFIBQ->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=pFIBQ->FieldByName("IDGRP_USER")->AsInt64;
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			pFIBQ->ExecQuery();
			TextVipOper=TextVipOper+" Получение роли пользователя - OK";

			role_user=pFIBQ->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;

            CheckEnableStart(role_user);

			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			TextVipOper=TextVipOper+" Подключение с NAME2 - OK";
			}

        TDMSetup * DMSetup=new TDMSetup(Application);

        DMSetup->OpenElement(20);
        try     {
				DMSetup->ElementVALUE_SETUP->AsInteger;
                glPrefiksLokShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                }
        catch(...)
                {
                glError=true;

				}

        DMSetup->OpenElement(21);
        try     {
                DMSetup->ElementVALUE_SETUP->AsInteger;
                glPrefiksKolShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                }
        catch(...)
                {
                glError=true;
                }


        delete DMSetup;

        Res=true;
        GetVersionBase();
        }
catch (Exception &exception)
		{
		Error=true;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		Res=false;
		pFIBData->Connected=false;
        }

return Res;
}
//---------------------------------------------------------------------------
bool TDM::GlobConnect2(void)
{
bool Res=false;

AnsiString role_user="";
try
        {
		if (NameUser=="SYSDBA")
			{
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser);
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			}
		else
			{//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;

			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+NameUser+"'");
			pFIBQ->ExecQuery();
			NameUser2=pFIBQ->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=pFIBQ->FieldByName("IDGRP_USER")->AsInt64;
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			pFIBQ->ExecQuery();
			role_user=pFIBQ->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			}

        if (glUser->FindPoName(NameUser)==1)
				{

				}
                                TDMSetup * DMSetup=new TDMSetup(Application);

								DMSetup->OpenElement(20);
                                try     {
                                        DMSetup->ElementVALUE_SETUP->AsInteger;
                                        glPrefiksLokShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                                        }
                                catch(...)
                                        {
                                        glError=true;
                                        }

                                DMSetup->OpenElement(21);
                                try     {
                                        DMSetup->ElementVALUE_SETUP->AsInteger;
                                        glPrefiksKolShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                                        }
                                catch(...)
                                        {
                                        glError=true;
                                        }


                                delete DMSetup;
                                Res=true;
                                GetVersionBase();

        }
catch (Exception &exception)
        {
        Error=true;
        Res=false;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		pFIBData->Connected=false;
        TextError=exception.Message;
        }
return Res;
}
//---------------------------------------------------------------------------
bool TDM::GlobConnect3(void)
{
bool Res=false;
AnsiString role_user="";
try
        {
			//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;

			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select NAME2_USER, NAME_USER, IDGRP_USER from SUSER where ID_USER='"+IntToStr(CodeUser)+"'");
			pFIBQ->ExecQuery();
			NameUser=pFIBQ->FieldByName("NAME_USER")->AsString;
			NameUser2=pFIBQ->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=pFIBQ->FieldByName("IDGRP_USER")->AsInt64;
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
			pFIBQ->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			pFIBQ->ExecQuery();
			role_user=pFIBQ->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=WIN1251");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;

                                TDMSetup * DMSetup=new TDMSetup(Application);
 
                                DMSetup->OpenElement(20);
                                try     {
                                        DMSetup->ElementVALUE_SETUP->AsInteger;
                                        glPrefiksLokShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                                        }
                                catch(...)
                                        {
                                        glError=true;
                                        }

                                DMSetup->OpenElement(21);
                                try     {
                                        DMSetup->ElementVALUE_SETUP->AsInteger;
                                        glPrefiksKolShtrihCoda=DMSetup->ElementVALUE_SETUP->AsString;
                                        }
                                catch(...)
                                        {
                                        glError=true;
                                        }


                                delete DMSetup;
                                Res=true;
                                GetVersionBase();

        }
catch (Exception &exception)
        {
        Error=true;
        Res=false;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		pFIBData->Connected=false;
        TextError=exception.Message;
        }
return Res;
}
//----------------------------------------------------------------------------
AnsiString TDM::GetNameServer(AnsiString connect_string)
{
AnsiString result="";
int num=connect_string.AnsiPos(":");
result=connect_string.SetLength(num-1);

return result;
}
//----------------------------------------------------------------------------
AnsiString TDM::GetVersionBase(void)
{
AnsiString result="";
IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add("select * from SYSTEM");
IBQ->Active=true;
AnsiString HVer=IBQ->Fields->Fields[1]->FieldName;
AnsiString LVer=IBQ->Fields->Fields[2]->FieldName;
IBQ->Active=false;
BaseVersion=HVer.Delete(1,5)+"."+LVer.Delete(1,5);

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
String AddEAN13(AnsiString Cod)
{
String ShCod="";

if (Cod.Length()!=12)
        {
        return ShCod=Cod+"-";
        }

//длина Cod 12 символов обязательно

double Ch=0;
double NeCh=0;
double E13=0;

for (int i=1;i<7;i++)
        {
        Ch=Ch+(int)StrToFloat(Cod[2*i]);
        NeCh=NeCh+(int)StrToFloat(Cod[2*i-1]);
        }

Ch=Ch*3;
E13=((Ch+NeCh)/10)-(floor((Ch+NeCh)/10));
E13=10-floor(E13*10);
if (E13==10){E13=0;}

ShCod=Cod+IntToStr((int)E13);
return ShCod;
}
//----------------------------------------------------------------------------
void glSaveProtocol(String str)
{
//
}
//---------------------------------------------------------------------------
String glGetNameDoc(String StrCodeDoc)
{
String Text=StrCodeDoc;
if (StrCodeDoc=="CHK"){Text="Чек ККМ";}
if (StrCodeDoc=="PRN"){Text="Прих. накл.";}
if (StrCodeDoc=="SCH"){Text="Счет на оплату";}
if (StrCodeDoc=="OSN"){Text="Остатки номенкл.";}
if (StrCodeDoc=="PER"){Text="Перемещение";}
if (StrCodeDoc=="REA"){Text="Реализация";}
if (StrCodeDoc=="SPN"){Text="Акт списания";}
if (StrCodeDoc=="VPO"){Text="Возврат поставщику";}
if (StrCodeDoc=="PKO"){Text="Прих. касс. ордер";}
if (StrCodeDoc=="RKO"){Text="Расх. касс. ордер";}
if (StrCodeDoc=="PLP"){Text="Платежное поручение";}
if (StrCodeDoc=="PNS"){Text="Поступление на счет";}
if (StrCodeDoc=="REAL_REST"){Text="Акт реализации";}
if (StrCodeDoc=="INV"){Text="Инвентаризация";}
if (StrCodeDoc=="REPKKM"){Text="Отчет ККМ";}
if (StrCodeDoc=="OSTVS"){Text="Корр. взаиморасчетов";}
if (StrCodeDoc=="SCHFACT"){Text="Счет-фактура";}
if (StrCodeDoc=="REALROZN"){Text="Реализация розн.";}
if (StrCodeDoc=="PKOROZN"){Text="Приход нал.";}
if (StrCodeDoc=="RKOROZN"){Text="Расход нал.";}
if (StrCodeDoc=="REC_KDR"){Text="Запись КДР";}
if (StrCodeDoc=="VPOK"){Text="Возврат покупателя";}
if (StrCodeDoc=="ISMPRICE"){Text="Переоценка";}
if (StrCodeDoc=="SPOTROST"){Text="Списание отр. остатков";}
if (StrCodeDoc=="REV"){Text="Ревизия";}
if (StrCodeDoc=="VIPPROD"){Text="Выпуск продукции";}
if (StrCodeDoc=="SBKOMPL"){Text="Сборка комплекта";}
if (StrCodeDoc=="RASBKOMPL"){Text="Разборка комплекта";}
if (StrCodeDoc=="ZAMENA"){Text="Замена";}
if (StrCodeDoc=="KORRVS"){Text="Корр. взаиморасчетов";}
if (StrCodeDoc=="VIPBANK"){Text="Выписка банка";}

//СЛУЖБНЫЕ ДОКУМЕНТЫ
if (StrCodeDoc=="RG_ADVCUST"){Text="Движение регистра Авансы";}
if (StrCodeDoc=="RG_BANK"){Text="Движение регистра Банк";}
if (StrCodeDoc=="RG_GOODS"){Text="Движение регистра Остатки товаров";}
if (StrCodeDoc=="RG_KASSA"){Text="Движение регистра Касса";}
if (StrCodeDoc=="RG_OSTNOM"){Text="Движение регистра Остатки партий товаров";}
if (StrCodeDoc=="RG_PAYSALE"){Text="Движение регистра Оплата реализации";}
if (StrCodeDoc=="RG_VSRASCH"){Text="Движение регистра Взаиморасчеты";}
if (StrCodeDoc=="RG_CARDBAL"){Text="Движение регистра Средства на картах";}
return Text;
}
//----------------------------------------------------------------------------
AnsiString glGetNameDocHotel(AnsiString StrCodeDoc)
{
AnsiString Text="";

if (StrCodeDoc=="BRON"){Text="Бронирование номера";}
if (StrCodeDoc=="RASM"){Text="Размещение в номере";}
if (StrCodeDoc=="VIEZD"){Text="Выезд из номера";}
if (StrCodeDoc=="REAL"){Text="Реализация (гост.)";}
if (StrCodeDoc=="RASCHET"){Text="Расчет (гост.)";}
if (StrCodeDoc=="OTMBRON"){Text="Отмена брони";}

return Text;
}
//----------------------------------------------------------------------------
AnsiString glGetNameDocRemont(AnsiString str_code_doc)
{
AnsiString Text="";

if (str_code_doc=="REMONT"){Text="Ремонт по заявке";}
if (str_code_doc=="REMONTHW"){Text="Ремонт оборудования";}
if (str_code_doc=="REMONTKKT"){Text="Ремонт ККТ";}
if (str_code_doc=="KM1"){Text="Акт КМ 1";}
if (str_code_doc=="KM2"){Text="Акт КМ 2";}
if (str_code_doc=="SETSERVKKT"){Text="Сервис ККТ";}
if (str_code_doc=="SETSERVHW"){Text="Сервис оборудования";}
return Text;
}
//----------------------------------------------------------------------------
AnsiString triada(AnsiString in, int tn)
{
if (in == "   ") return "";
if (in == "000") return "";
AnsiString out = "";
AnsiString sotni[9] = 
{"сто", "двести", "триста", "четыреста", "пятьсот",
"шестьсот", "семьсот", "восемьсот", "девятьсот"};
AnsiString dubl[10] = 
{"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
"пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
AnsiString des[8] = 
{"двадцать", "тридцать", "сорок", "пятьдесят",
"шестьдесят", "семьдясят", "восемьдясят", "девяносто"};
AnsiString ed[9] = {"один", "два", "три", "четыре", "пять", "шесть","семь", "восемь", "девять"};
AnsiString edj[9] = {"одна", "две", "три", "четыре", "пять", "шесть","семь", "восемь", "девять"};
AnsiString ind[5] = {"", " тысяч", " миллион", " миллиард", " триллион"};
AnsiString post;
if (in[1] != ' ') if (in[1] != '0')
        { out = out + sotni[(int)StrToFloat(in[1])-1]; }
if (in[2] == '1')
        { out = out + " " + dubl[(int)StrToFloat(in[3])]; }
if (in[2] != '1') if (in[2] != ' ') if (in[2] != '0')
        { out = out + " " + des[(int)StrToFloat(in[2])-2]; }
if (in[3] != '0') if (in[2] != '1')
        {
        if (tn == 1)
                out = out + " " + edj[(int)StrToFloat(in[3])-1];
        if (tn != 1)
                out = out + " " + ed[(int)StrToFloat(in[3])-1];
        }
if (tn>0) if (in[2] != '1')
        {
        if (tn==1) switch (in[3])
                {
                case '1': post = ind[tn] + "а"; break;
                case '2': post = ind[tn] + "и"; break;
                case '3': post = ind[tn] + "и"; break;
                case '4': post = ind[tn] + "и"; break;
                default : post = ind[tn] + ""; break;
                }
        if ((tn==2)||(tn==3)||(tn==4)) switch (in[3])
                {
                case '1': post = ind[tn] + ""; break;
                case '2': post = ind[tn] + "а"; break;
                case '3': post = ind[tn] + "а"; break;
                case '4': post = ind[tn] + "а"; break;
                default : post = ind[tn] + "ов"; break;
                }
        }
else
        {
        switch (tn)
                {
                case 1  : post = ind[tn]; break;
                default : post = ind[tn] + "ов"; break;
                }
        }
out = out + post;
return out;
}
//-----------------------------------------------------------------------
AnsiString ValuePropis(AnsiString in)
{
AnsiString out;
AnsiString trs[5];
AnsiString tro[5];
AnsiString buf;
int n,s;
div_t dr;

while (in.Length() < 15)
        {
        in = " " + in;
        }
for (n=0;n<5;n++) trs[n] = in;
trs[0] = trs[0].Delete(1,in.Length()-3);
trs[1] = trs[1].Delete(1,in.Length()-6).Delete(4,4);
trs[2] = trs[2].Delete(1,in.Length()-9).Delete(4,6);
trs[3] = trs[3].Delete(1,in.Length()-12).Delete(4,9);
trs[4] = trs[4].Delete(1,in.Length()-15).Delete(4,12);

for (n=0;n<5;n++)
        {
        tro[n] = triada(trs[n],n);
        }
out = " "+tro[4]+" "+tro[3]+" "+tro[2]+" "+tro[1]+" "+tro[0]+" ";
out = out.Trim();
return out;
}
//--------------------------------------------------------------------------
//------------------------------------------------------------------------------
static double vseg[] = { 1e9, 1e6, 1e3, 1};
static char dsot[][11] =
{ "",          "сто ",       "двести ",   "триста ",     "четыреста ",
  "пятьсот ",  "шестьсот ",  "семьсот ",  "восемьсот ",  "девятьсот "};
static char ddec[][13] =
{ "",          "десять ",    "двадцать ", "тридцать ",   "сорок ",
  "пятьдесят ","шестьдесят ","семьдесят ","восемьдесят ","девяносто "};
static char dde [][14] =
{ "одиннадцать ", "двенадцать ",  "тринадцать ",
  "четырнадцать ","пятнадцать ",  "шестнадцать ",
  "семнадцать ",  "восемнадцать ","девятнадцать " };
static char ded [][8] =
{ "",          "один ",      "два ",      "три ",        "четыре ",
  "пять ",     "шесть ",     "семь ",     "восемь ",     "девять "};
static char dedt[][6]    = { "одна ", "две " };
static char dseg[][9]    = { "миллиард", "миллион", "тысяч", "рубл" };
static char dsem[][3][5] = {{ " ",  "а ", "ов " },  // миллиард
                            { " ",  "а ", "ов " },  // миллион
                            { "а ", "и ", " "   },  // тысяч
                            { "ь ", "я ", "ей " },  // рублей
                            { "йка","йки","ек"  }}; // копеек

static int
HowTell (long n)
{
  n %= 100;
  if (n >= 10  &&  n <= 20) return  3;
  n %= 10;
  return  n == 1? 1: n <= 4  &&  n > 0? 2: 3;
}

static double
Round (double op)
{
  return  floor(op + 0.5);
}

static double
Round (double op,double pow)
{
  if (pow <= 0.)  return  op;
  if (op>0. && op<pow || op<0. && op>pow) return 0.;
  op = floor(op/pow + 0.5) * pow;
  return  op>0. && op<pow || op<0. && op>pow? 0.: op;
}

char*
WriteSum (double v,char *buf,bool kop,bool up)
{
  buf[0] = 0;
  if (v >= 1e12  ||  v <= 0.009) return buf;
  v = Round(v,0.01);
  for (int seg=0; seg<4; seg++) {
    int vt = int(v / vseg[seg]);
    v -= vseg[seg] * vt;
    if (vt  ||  seg == 3) {
      int how = HowTell(vt);
          // 1 - миллиард   миллион   тысяча рубль  копейка
          // 2 - миллиарда  миллиона  тысячи рубля  копейки
          // 3 - миллиардов миллионов тысяч  рублей копеек
      if (vt) {
        strcat(buf,dsot[vt/100]);  vt %= 100;
        if (vt >= 20  ||  vt <= 10) {
          strcat(buf,ddec[vt/10]);  vt %= 10;
          if (seg == 2  &&  (vt == 1  ||  vt == 2))
                strcat(buf,dedt[vt-1]);
          else  strcat(buf,ded[vt]);
        } else  strcat(buf,dde[vt-11]);
      } else if (buf[0] == 0)  strcat(buf,"ноль ");
      strcat(buf,dseg[seg]);
      strcat(buf,dsem[seg][how-1]);
    }
  }
  if (kop)
      sprintf(buf+strlen(buf),"%02.0lf копе%s",
                              v*100,
                              dsem[4][HowTell((long)Round(v*100))-1]);

  if (up) CharUpper(buf);
  else    CharUpperBuff(buf,1);
  return  buf;
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
String CurrencyPropis(double Value)
{
AnsiString result;
char * b=new char[300];
result=AnsiString(WriteSum(Value,b,true, false));
delete b;
return result;
}
//------------------------------------------------------------------------
String IntegerValuePropis(int Value)
{
String result="";
result=ValuePropis(IntToStr(Value));        
return result;
}

//------------------------------------------------------------------------
float glGetKolProgiv1(TDateTime Nach, TDateTime Con)
{
float result=0;
TDateTime TekDate=Nach;

if ((CompareTime(TekDate,EncodeTime(0,0,0,0))==1) && (CompareTime(TekDate,EncodeTime(12,0,0,0))==-1))
        {
        Word  Year;
        Word Month;
        Word Day;
        DecodeDate(TekDate, Year,Month,Day);
        TekDate=EncodeDateTime( Year,Month,Day,12,0,0,0);
        result=0;
        }
else
        {
        TekDate=TekDate+1;
        Word  Year;
        Word Month;
        Word Day;
        DecodeDate(TekDate, Year,Month,Day);
        TekDate=EncodeDateTime( Year,Month,Day,12,0,0,0);
        result=1;
        }

//ShowMessage(DateTimeToStr(TekDate));
int KolSutok=DaysBetween(TekDate,Con);
//ShowMessage(IntToStr(KolSutok));
TekDate=TekDate+KolSutok;
//ShowMessage(DateTimeToStr(TekDate));
result=result+KolSutok;
//ShowMessage(FloatToStr(result));

int KolHour=HoursBetween(TekDate,Con);

if (KolHour>0 && KolHour<6)
        {
        result=result+0.25;
        }

if (KolHour>=6 && KolHour<12)
        {
        result=result+0.5;
        }

if (KolHour>=12 && KolHour<18)
        {
        result=result+0.75;
        }

if (KolHour>=18 && KolHour<24)
        {
        result=result+1;
        }

if (result<1)
        {
        result=1;
        }

return result;
}
//--------------------------------------------------------------------------
AnsiString CommaToPixel(String value)
{
String result="";
String StrValue=value;

for(int i=1;i<=StrValue.Length();i++)
        {
        if (StrValue[i]==',')
                {
                result=result+".";

                }
        else
                {
                result=result+StrValue[i];
                }
        }
return result;
}

//---------------------------------------------------------------------------
int ArrayParity_EAN13 [10][6]= {1,1,1,1,1,1,
                                1,1,2,1,2,2,
                                1,1,2,2,1,2,
                                1,1,2,2,2,1,
                                1,2,1,1,2,2,
                                1,2,2,1,1,2,
                                1,2,2,2,1,1,
                                1,2,1,2,1,2,
                                1,2,1,2,2,1,
                                1,2,2,1,2,1 };

AnsiString ArrayA_EAN13[10]={"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011"};
AnsiString ArrayB_EAN13[10]={"0100111","0110011","0011011","0100001","0011101","0111001","0000101","0010001","0001001","0010111"};
AnsiString ArrayC_EAN13[10]={"1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};

//----------------------------------------------------------------------------
AnsiString GetBinareStructEAN13(AnsiString sh_code)
{
AnsiString result="";
if (sh_code.Length()!=13) return result;

int num_str_parity=StrToFloat(sh_code[1]);
int el=0;
int parity=0;

//краевые штрихи
result="202";

//12
el=StrToFloat(sh_code[2]);
parity=ArrayParity_EAN13[num_str_parity][0];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

//11
el=StrToFloat(sh_code[3]);
parity=ArrayParity_EAN13[num_str_parity][1];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

//10
el=StrToFloat(sh_code[4]);
parity=ArrayParity_EAN13[num_str_parity][2];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

//9
el=StrToFloat(sh_code[5]);
parity=ArrayParity_EAN13[num_str_parity][3];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

//8
el=StrToFloat(sh_code[6]);
parity=ArrayParity_EAN13[num_str_parity][4];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

//7
el=StrToFloat(sh_code[7]);
parity=ArrayParity_EAN13[num_str_parity][5];
if (parity==1){result=result+ArrayA_EAN13[el];}
if (parity==2){result=result+ArrayB_EAN13[el];}

result=result+"02020";

//6
el=StrToFloat(sh_code[8]);
result=result+ArrayC_EAN13[el];

//5
el=StrToFloat(sh_code[9]);
result=result+ArrayC_EAN13[el];

//4
el=StrToFloat(sh_code[10]);
result=result+ArrayC_EAN13[el];

//3
el=StrToFloat(sh_code[11]);
result=result+ArrayC_EAN13[el];

//2
el=StrToFloat(sh_code[12]);
result=result+ArrayC_EAN13[el];

//1
el=StrToFloat(sh_code[13]);
result=result+ArrayC_EAN13[el];

result=result+"202";

return result;
}
//-----------------------------------------------------------------------------
AnsiString ConvertString(AnsiString s1, AnsiString s2, AnsiString s3)   //Заменить в строке s1 все вхождения s2 на s3
{
AnsiString result;
int i0=1,i=s1.Pos(s2);
while(i>i0)
	{
	s1.Delete(i,s2.Length());
	s1.Insert(s3,i);
	i0=i+s3.Length();
	i=i0-1+s1.SubString(i0,255).Pos(s2);
	}
result=s1;
return result;
}
//-------------------------------------------------------------------------------
double RoundValue(double value, int  rasr)
{
double result=0;
double st=0;
st=pow(10,rasr);
result=(floor(value*st+0.5))/st;

return result;
}
//-------------------------------------------------------------------------
AnsiString GetVersionProgramFile(void)
{
AnsiString result="";

return result;
}
//---------------------------------------------------------------------------
void AddLog(__int64 id_user,
					int type,
					int object,
					int oper,
					AnsiString message,
					AnsiString code_object,
					__int64 id_object,
					int subsystem)
{
int application=0;
AnsiString name_file=ExtractFileName(Application->ExeName);
if (name_file=="PAdmin.exe") {application=1;}
if (name_file=="PArmKas.exe") {application=2;}
if (name_file=="PArmOf.exe") {application=3;}
if (name_file=="DBServ20.dll") {application=4;}
if (name_file=="DBServ10.dll") {application=4;}

try
	{
	DM->pFIBQLog->Close();
	if (id_user!=0) DM->pFIBQLog->ParamByName("IDUSER_LOG")->AsInt64=id_user;
	DM->pFIBQLog->ParamByName("TYPE_LOG")->AsInteger=type;
	DM->pFIBQLog->ParamByName("OBJECT_LOG")->AsInteger=object;
	DM->pFIBQLog->ParamByName("OPER_LOG")->AsInteger=oper;
	DM->pFIBQLog->ParamByName("MESSAGE_LOG")->AsString=message;

	DM->pFIBQLog->ParamByName("APPLICATION_LOG")->AsInteger=application;
	DM->pFIBQLog->ParamByName("CODEOB_LOG")->AsString=code_object;
	DM->pFIBQLog->ParamByName("IDOBJECT_LOG")->AsInt64=id_object;
	DM->pFIBQLog->ParamByName("SUBSYSTEM_LOG")->AsInteger=subsystem;

	DM->pFIBQLog->ExecQuery();
	DM->pFIBTrLog->Commit();
	DM->pFIBQLog->Close();
	}
catch (...) {}
}
//-----------------------------------------------------------------------------
__int64 glStrToInt64(AnsiString value)
{
__int64 result=0;
if (Trim(value)!="")
	{
     result=StrToInt64(value);
	}
return result;
}
//----------------------------------------------------------------------------
AnsiString glFormatForXML(AnsiString s)
{
String S1=s;
String S2="&";
String S3="&amp;";

int i0=0,i=S1.Pos(S2);
while(i)
		{
		S1=S1.SubString(1,i+i0-1)+S3+
				S1.SubString(i+i0+S2.Length(),255);
		i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
		}


S2=">";
S3="&gt;";

i0=0,i=S1.Pos(S2);
while(i)
		{
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="<";
S3="&lt;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\"";
S3="&quot;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\'";
S3="&apos;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }


return S1;
}

//---------------------------------------------------------------------------
int GetRateNDS(int code)     //получить ставку НДС
{
int result=0;

switch (code)
	{
	case 0:    //не задан
		{
		result=0;;
		}break;
	case 1:    //без ндс
		{
		result=0;
		}break;

	case 2:    //0%
		{
		result=0;
		}break;
	case 3:    //10%
		{
		result=10;
		}break;
	case 4:    //18%
		{
		result=18;
		}break;
	}

return result;
}
//----------------------------------------------------------------------------
int glCompareDoubleValue(double v1, double v2, int pogr)
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
