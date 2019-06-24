//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UGlobalFunction.h"

#include <fstream.h>
//#include "math.h"
#include "DateUtils.hpp"
#include "SYSUtils.hpp"


//---------------------------------------------------------------------------

#pragma package(smart_init)


//-----------------------------------------------------------------------------
__int64 glStrToInt64(UnicodeString value)
{
__int64 result=0;
if (Trim(value)!="")
	{
     result=StrToInt64(value);
	}
return result;
}
//-----------------------------------------------------------------------------

UnicodeString glGetNameDoc(UnicodeString StrCodeDoc)
{
UnicodeString Text=StrCodeDoc;
if (StrCodeDoc=="CHK"){Text="��� ���";}
if (StrCodeDoc=="PRN"){Text="����. ����.";}
if (StrCodeDoc=="SCH"){Text="���� �� ������";}
if (StrCodeDoc=="OSN"){Text="������� �������.";}
if (StrCodeDoc=="PER"){Text="�����������";}
if (StrCodeDoc=="REA"){Text="����������";}
if (StrCodeDoc=="SPN"){Text="��� ��������";}
if (StrCodeDoc=="VPO"){Text="������� ����������";}
if (StrCodeDoc=="PKO"){Text="����. ����. �����";}
if (StrCodeDoc=="RKO"){Text="����. ����. �����";}
if (StrCodeDoc=="PLP"){Text="��������� ���������";}
if (StrCodeDoc=="PNS"){Text="����������� �� ����";}
if (StrCodeDoc=="REAL_REST"){Text="��� ����������";}
if (StrCodeDoc=="INV"){Text="��������������";}
if (StrCodeDoc=="REPKKM"){Text="����� ���";}
if (StrCodeDoc=="OSTVS"){Text="����. ��������������";}
if (StrCodeDoc=="SCHFACT"){Text="����-�������";}
if (StrCodeDoc=="REALROZN"){Text="���������� ����.";}
if (StrCodeDoc=="PKOROZN"){Text="������ ���.";}
if (StrCodeDoc=="RKOROZN"){Text="������ ���.";}
if (StrCodeDoc=="REC_KDR"){Text="������ ���";}
if (StrCodeDoc=="VPOK"){Text="������� ����������";}
if (StrCodeDoc=="ISMPRICE"){Text="����������";}
if (StrCodeDoc=="SPOTROST"){Text="�������� ���. ��������";}
if (StrCodeDoc=="REV"){Text="�������";}
if (StrCodeDoc=="VIPPROD"){Text="������ ���������";}
if (StrCodeDoc=="SBKOMPL"){Text="������ ���������";}
if (StrCodeDoc=="RASBKOMPL"){Text="�������� ���������";}
if (StrCodeDoc=="ZAMENA"){Text="������";}
if (StrCodeDoc=="KORRVS"){Text="����. ��������������";}
if (StrCodeDoc=="VIPBANK"){Text="������� �����";}
if (StrCodeDoc=="OTCHPOST"){Text="����� ����������";}

//�������� ���������
if (StrCodeDoc=="RG_ADVCUST"){Text="�������� �������� ������";}
if (StrCodeDoc=="RG_BANK"){Text="�������� �������� ����";}
if (StrCodeDoc=="RG_GOODS"){Text="�������� �������� ������� �������";}
if (StrCodeDoc=="RG_KASSA"){Text="�������� �������� �����";}
if (StrCodeDoc=="RG_OSTNOM"){Text="�������� �������� ������� ������ �������";}
if (StrCodeDoc=="RG_PAYSALE"){Text="�������� �������� ������ ����������";}
if (StrCodeDoc=="RG_VSRASCH"){Text="�������� �������� �������������";}
if (StrCodeDoc=="RG_CARDBAL"){Text="�������� �������� �������� �� ������";}
if (StrCodeDoc=="RG_OTCHPOST"){Text="�������� �������� ����� ����������";}

return Text;
}
//----------------------------------------------------------------------------
UnicodeString glGetNameDocHotel(UnicodeString StrCodeDoc)
{
UnicodeString Text="";

if (StrCodeDoc=="BRON"){Text="������������ ������";}
if (StrCodeDoc=="RASM"){Text="���������� � ������";}
if (StrCodeDoc=="VIEZD"){Text="����� �� ������";}
if (StrCodeDoc=="REAL"){Text="���������� (����.)";}
if (StrCodeDoc=="RASCHET"){Text="������ (����.)";}
if (StrCodeDoc=="OTMBRON"){Text="������ �����";}

return Text;
}
//----------------------------------------------------------------------------
UnicodeString glGetNameDocRemont(UnicodeString str_code_doc)
{
UnicodeString Text="";

if (str_code_doc=="REMONT"){Text="������ �� ������";}
if (str_code_doc=="REMONTHW"){Text="������ ������������";}
if (str_code_doc=="REMONTKKT"){Text="������ ���";}
if (str_code_doc=="KM1"){Text="��� �� 1";}
if (str_code_doc=="KM2"){Text="��� �� 2";}
if (str_code_doc=="SETSERVKKT"){Text="������ ���";}
if (str_code_doc=="SETSERVHW"){Text="������ ������������";}
if (str_code_doc=="REMPRN"){Text="����. ��������� (������)";}
if (str_code_doc=="REMREAL"){Text="���������� (������)";}
if (str_code_doc=="REMOSN"){Text="���� �������� (������)";}
if (str_code_doc=="REMSBKOMPL"){Text="������ ��������� (������)";}
if (str_code_doc=="POSTOTDIL"){Text="����������� �� ������ (������)";}
if (str_code_doc=="VOSDILERU"){Text="������� ������ (������)";}
if (str_code_doc=="PERSC"){Text="�������� � �� (������)";}
if (str_code_doc=="VOSVISSC"){Text="������� �� �� (������)";}
if (str_code_doc=="REMVPOK"){Text="������� ���������� (������)";}
if (str_code_doc=="REMAKT"){Text="��� (������)";}
if (str_code_doc=="REMPER"){Text="����������� (������)";}


if (str_code_doc=="REMZPOST"){Text="����������� � ������(������)";}
if (str_code_doc=="REMZVID"){Text="������ �� ������� (������)";}
if (str_code_doc=="REMZPER"){Text="����������� ������ (������)";}
if (str_code_doc=="REMZSTART"){Text="������ ������� (������)";}
if (str_code_doc=="REMZEND"){Text="����� ������� (������)";}
if (str_code_doc=="REMZOPER"){Text="��������� �������� (������)";}
if (str_code_doc=="REMZTREB"){Text="���������� ��������� (������)";}
if (str_code_doc=="REMZAKTPR"){Text="��� ������������� (������)";}
if (str_code_doc=="REMZVZAP"){Text="������ �����. ��������� (������)";}

if (str_code_doc=="REMSPN"){Text="�������� ���. (������)";}

if (str_code_doc=="REM_RGOTCHPOST"){Text="�������� �������� ����� ���������� (������)";}

if (str_code_doc=="REM_VIDACHA_HW"){Text="������ ������������";}
if (str_code_doc=="REM_VOSVRAT_HW"){Text="������� ������������";}
if (str_code_doc=="REM_ZAKPOST"){Text="����� ����������";}
if (str_code_doc=="REM_OTPRPOST"){Text="�������� �����������";}


if (str_code_doc=="REM_VZPER"){Text="����������� �����. ���";}
if (str_code_doc=="REM_VZVPO"){Text="������� ���������� �����. ���";}
return Text;
}
//----------------------------------------------------------------------------
UnicodeString glFloatToStringComma(double value)
{
UnicodeString result="";
UnicodeString StrValue=FloatToStr(value);

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
//----------------------------------------------------------------------------------
double glStringToFloatComma(UnicodeString value)
{
double res=0;
UnicodeString result="";
UnicodeString StrValue=value;

for(int i=1;i<=StrValue.Length();i++)
		{
		if (StrValue[i]=='.')
				{
				result=result+",";

				}
		else
				{
				result=result+StrValue[i];
				}
		}

res=StrToFloat(result);
return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//��������� ������ Str ����� ��������� Symbol �� Len
UnicodeString glDopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
UnicodeString glDopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
UnicodeString triada(UnicodeString in, int tn)
{
if (in == "   ") return "";
if (in == "000") return "";
UnicodeString out = "";
UnicodeString sotni[9] =
{"���", "������", "������", "���������", "�������",
"��������", "�������", "���������", "���������"};
UnicodeString dubl[10] =
{"������", "�����������", "����������", "����������", "������������",
"����������", "�����������", "����������", "������������", "������������"};
UnicodeString des[8] =
{"��������", "��������", "�����", "���������",
"����������", "���������", "�����������", "���������"};
UnicodeString ed[9] = {"����", "���", "���", "������", "����", "�����","����", "������", "������"};
UnicodeString edj[9] = {"����", "���", "���", "������", "����", "�����","����", "������", "������"};
UnicodeString ind[5] = {"", " �����", " �������", " ��������", " ��������"};
UnicodeString post;
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
                case '1': post = ind[tn] + "�"; break;
                case '2': post = ind[tn] + "�"; break;
                case '3': post = ind[tn] + "�"; break;
                case '4': post = ind[tn] + "�"; break;
                default : post = ind[tn] + ""; break;
                }
        if ((tn==2)||(tn==3)||(tn==4)) switch (in[3])
                {
                case '1': post = ind[tn] + ""; break;
                case '2': post = ind[tn] + "�"; break;
                case '3': post = ind[tn] + "�"; break;
                case '4': post = ind[tn] + "�"; break;
                default : post = ind[tn] + "��"; break;
                }
        }
else
        {
        switch (tn)
                {
                case 1  : post = ind[tn]; break;
                default : post = ind[tn] + "��"; break;
                }
        }
out = out + post;
return out;
}
//-----------------------------------------------------------------------
UnicodeString ValuePropis(UnicodeString in)
{
UnicodeString out;
UnicodeString trs[5];
UnicodeString tro[5];
UnicodeString buf;
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
//------------------------------------------------------------------------------
static double vseg[] = { 1e9, 1e6, 1e3, 1};
static char dsot[][11] =
{ "",          "��� ",       "������ ",   "������ ",     "��������� ",
  "������� ",  "�������� ",  "������� ",  "��������� ",  "��������� "};
static char ddec[][13] =
{ "",          "������ ",    "�������� ", "�������� ",   "����� ",
  "��������� ","���������� ","��������� ","����������� ","��������� "};
static char dde [][14] =
{ "����������� ", "���������� ",  "���������� ",
  "������������ ","���������� ",  "����������� ",
  "���������� ",  "������������ ","������������ " };
static char ded [][8] =
{ "",          "���� ",      "��� ",      "��� ",        "������ ",
  "���� ",     "����� ",     "���� ",     "������ ",     "������ "};
static char dedt[][6]    = { "���� ", "��� " };
static char dseg[][9]    = { "��������", "�������", "�����", "����" };
static char dsem[][3][5] = {{ " ",  "� ", "�� " },  // ��������
                            { " ",  "� ", "�� " },  // �������
                            { "� ", "� ", " "   },  // �����
                            { "� ", "� ", "�� " },  // ������
                            { "���","���","��"  }}; // ������

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
          // 1 - ��������   �������   ������ �����  �������
          // 2 - ���������  ��������  ������ �����  �������
          // 3 - ���������� ��������� �����  ������ ������
      if (vt) {
        strcat(buf,dsot[vt/100]);  vt %= 100;
        if (vt >= 20  ||  vt <= 10) {
          strcat(buf,ddec[vt/10]);  vt %= 10;
          if (seg == 2  &&  (vt == 1  ||  vt == 2))
                strcat(buf,dedt[vt-1]);
          else  strcat(buf,ded[vt]);
        } else  strcat(buf,dde[vt-11]);
      } else if (buf[0] == 0)  strcat(buf,"���� ");
      strcat(buf,dseg[seg]);
      strcat(buf,dsem[seg][how-1]);
    }
  }
  if (kop)
	  sprintf(buf+strlen(buf),"%02.0lf ����%s",
                              v*100,
                              dsem[4][HowTell((long)Round(v*100))-1]);

  if (up) CharUpper(buf);
  else    CharUpperBuff(buf,1);
  return  buf;
}
//-----------------------------------------------------------------------------
UnicodeString glCurrencyPropis(double Value)
{
UnicodeString result;
char * b=new char[300];
result=UnicodeString(WriteSum(Value,b,true, false));
delete b;
return result;
}
//------------------------------------------------------------------------
UnicodeString glIntegerValuePropis(int Value)
{
UnicodeString result="";
result=ValuePropis(IntToStr(Value));
return result;
}

//--------------------------------------------------------------------------
UnicodeString glAddEAN13(UnicodeString Cod)
{
UnicodeString ShCod="";

if (Cod.Length()!=12)
        {
        return ShCod=Cod+"-";
        }

//����� Cod 12 �������� �����������

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
int glGetRateNDS(int code)     //�������� ������ ���
{
int result=0;

switch (code)
	{
	case 0:    //�� �����
		{
		result=0;;
		}break;
	case 1:    //��� ���
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
//------------------------------------------------------------------------------
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
double glRoundValue(double value, int  rasr)
{
double result=0;
double st=0;
st=powl(10,rasr);
result=(floor(value*st+0.5))/st;

return result;
}
//-------------------------------------------------------------------------
UnicodeString glGetStringFullTypeDoc(void)
{
UnicodeString result=" 'PRN', 'CHK', 'SCH', 'OSN', 'PER', 'SPN', 'VPO',  'PKO', 'RKO',\
  'PLP', 'PNS', 'INV', 'REAL_REST', 'REPKKM', 'REA', 'OSTVS', 'SCHFACT','REALROZN',\
  'PKOROZN','RKOROZN','VPOK', 'ISMPRICE','SPOTROST', 'REV','VIPPROD','SBKOMPL','RASBKOMPL',\
  'ZAMENA','KORRVS','VIPBANK','OTCHPOST',\
  'RG_ADVCUST', 'RG_BANK', 'RG_GOODS', 'RG_KASSA', 'RG_OSTNOM', 'RG_PAYSALE', 'RG_VSRASCH', 'RG_CARDBAL'";
  return result;
}
//---------------------------------------------------------------------------

UnicodeString glGetStringFullTypeDocNoCheck(void)
{
UnicodeString result=" 'PRN','SCH', 'OSN', 'PER', 'SPN', 'VPO',  'PKO', 'RKO',\
  'PLP', 'PNS', 'INV', 'REAL_REST', 'REPKKM', 'REA', 'OSTVS', 'SCHFACT','REALROZN',\
  'PKOROZN','RKOROZN','VPOK', 'ISMPRICE','SPOTROST', 'REV', 'VIPPROD','SBKOMPL','RASBKOMPL',\
  'ZAMENA','KORRVS','VIPBANK','OTCHPOST', \
  'RG_ADVCUST', 'RG_BANK', 'RG_GOODS', 'RG_KASSA', 'RG_OSTNOM', 'RG_PAYSALE', 'RG_VSRASCH','RG_CARDBAL' ";
return result;
}
//----------------------------------------------------------------------------
UnicodeString glCommaToPixel(UnicodeString value)
{
UnicodeString result="";
UnicodeString StrValue=value;

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
//-----------------------------------------------------------------------------
UnicodeString glConvertString(UnicodeString s1, UnicodeString s2, UnicodeString s3)   //�������� � ������ s1 ��� ��������� s2 �� s3
{
UnicodeString result;
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
UnicodeString glGetVersionProgramFile(void)
{
UnicodeString result="";
AnsiString file_name=Application->ExeName;
DWORD h;
DWORD Size=GetFileVersionInfoSize(file_name.c_str(),&h);
if (Size!=0)
	{
	char *buf;
	buf=(char*)GlobalAlloc(GMEM_FIXED,Size);
	if(GetFileVersionInfo(file_name.c_str(),h,Size,buf)!=0)
		{
		char * ValueBuf;
		UINT Len;
		VerQueryValue(buf,"\\VarFileInfo\\Translation",&(void*) ValueBuf,&Len);
		if(Len==4)
			{
			UnicodeString CharSet=IntToHex((int)MAKELONG(*(int*)(ValueBuf+2),*(int*)ValueBuf),8);
			if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet
					+"\\FileVersion").c_str(),&(void *)ValueBuf,&Len)!=0)
						{
						result=AnsiString(ValueBuf);
						}
			}
		}
	GlobalFree(buf);
	}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString glGetNameProcedureCancelDvReg(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="CHK"){result="DOC_CHK_CANCEL_DVREG";}
if (type_doc=="PRN"){result="DOC_PRN_CANCEL_DVREG";}//{Text="����. ����.";}
if (type_doc=="SCH"){result="DOC_SCH_CANCEL_DVREG";}//{Text="���� �� ������";}
if (type_doc=="OSN"){result="DOC_OSN_CANCEL_DVREG";}//{Text="������� �������.";}
if (type_doc=="PER"){result="DOC_PER_CANCEL_DVREG";}//{Text="�����������";}
if (type_doc=="REA"){result="DOC_REA_CANCEL_DVREG";}//{Text="����������";}
if (type_doc=="SPN"){result="DOC_SPN_CANCEL_DVREG";}//{Text="��� ��������";}
if (type_doc=="VPO"){result="DOC_VPO_CANCEL_DVREG";}//{Text="������� ����������";}
if (type_doc=="PKO"){result="DOC_PKO_CANCEL_DVREG";}//{Text="����. ����. �����";}
if (type_doc=="RKO"){result="DOC_RKO_CANCEL_DVREG";}//{Text="����. ����. �����";}
if (type_doc=="PLP"){result="DOC_PLP_CANCEL_DVREG";}//{Text="��������� ���������";}
if (type_doc=="PNS"){result="DOC_PNS_CANCEL_DVREG";}//{Text="����������� �� ����";}
if (type_doc=="INV"){result="DOC_INV_CANCEL_DVREG";}//{Text="��������������";}
if (type_doc=="REPKKM"){result="DOC_REPKKM_CANCEL_DVREG";}//{Text="����� ���";}
if (type_doc=="OSTVS"){result="DOC_OSTVS_CANCEL_DVREG";}//{Text="����. ��������������";}
if (type_doc=="SCHFACT"){result="DOC_SCHFACT_CANCEL_DVREG";}//{Text="����-�������";}
if (type_doc=="REALROZN"){result="DOC_REALROZN_CANCEL_DVREG";}//{Text="���������� ����.";}
if (type_doc=="PKOROZN"){result="DOC_PKOROZN_CANCEL_DVREG";}//{Text="������ ���.";}
if (type_doc=="RKOROZN"){result="DOC_RKOROZN_CANCEL_DVREG";}//{Text="������ ���.";}

if (type_doc=="VPOK"){result="DOC_VPOK_CANCEL_DVREG";}//{Text="������� ����������";}

if (type_doc=="ISMPRICE"){result="DOC_ISMPRICE_CANCEL_DVREG";}//{Text="����������";}
if (type_doc=="SPOTROST"){result="DOC_SPOTROST_CANCEL_DVREG";}//{Text="�������� ���. ��������";}
if (type_doc=="REV"){result="DOC_REV_CANCEL_DVREG";}//{Text="�������";}

if (type_doc=="SBKOMPL"){result="DOC_SBKOMPL_CANCEL_DVREG";}//
if (type_doc=="RASBKOMPL"){result="DOC_RASBKOMPL_CANCEL_DVREG";}//
if (type_doc=="ZAMENA"){result="DOC_ZAMENA_CANCEL_DVREG";}//

if (type_doc=="KORRVS"){result="DOC_KORRVS_CANCEL_DVREG";}
if (type_doc=="VIPBANK"){result="DOC_VIPBANK_CANCEL_DVREG";}
if (type_doc=="OTCHPOST"){result="DOC_OTCHPOST_CANCEL_DVREG";}

//��������� ���������
if (type_doc=="RG_ADVCUST"){result="DOC_RGADVCUST_CANCEL_DVREG";}
if (type_doc=="RG_BANK"){result="DOC_RGBANK_CANCEL_DVREG";}
if (type_doc=="RG_CARDBAL"){result="DOC_RGCARD_BALANCE_CANCEL_DVREG";}
if (type_doc=="RG_OSTNOM"){result="DOC_RGGOODS_CANCEL_DVREG";}
if (type_doc=="RG_KASSA"){result="DOC_RGKASSA_CANCEL_DVREG";}
if (type_doc=="RG_OSTNOM"){result="DOC_RGOSTNOM_CANCEL_DVREG";}
if (type_doc=="RG_PAYSALE"){result="DOC_RGPAYSALE_CANCEL_DVREG";}
if (type_doc=="RG_VSRASCH"){result="DOC_RGVSRASCH_CANCEL_DVREG";}
if (type_doc=="RG_OTCHPOST"){result="DOC_RGOTCHPOST_CANCEL_DVREG";}


return result;
}
//-----------------------------------------------------------------------------
UnicodeString glGetNameProcedureDvReg(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="CHK"){result="DOC_CHK_DVREG";}
if (type_doc=="PRN"){result="DOC_PRN_DVREG";}//{Text="����. ����.";}
if (type_doc=="SCH"){result="DOC_SCH_DVREG";}//{Text="���� �� ������";}
if (type_doc=="OSN"){result="DOC_OSN_DVREG";}//{Text="������� �������.";}
if (type_doc=="PER"){result="DOC_PER_DVREG";}//{Text="�����������";}
if (type_doc=="REA"){result="DOC_REA_DVREG";}//{Text="����������";}
if (type_doc=="SPN"){result="DOC_SPN_DVREG";}//{Text="��� ��������";}
if (type_doc=="VPO"){result="DOC_VPO_DVREG";}//{Text="������� ����������";}
if (type_doc=="PKO"){result="DOC_PKO_DVREG";}//{Text="����. ����. �����";}
if (type_doc=="RKO"){result="DOC_RKO_DVREG";}//{Text="����. ����. �����";}
if (type_doc=="PLP"){result="DOC_PLP_DVREG";}//{Text="��������� ���������";}
if (type_doc=="PNS"){result="DOC_PNS_DVREG";}//{Text="����������� �� ����";}
if (type_doc=="INV"){result="DOC_INV_DVREG";}//{Text="��������������";}
if (type_doc=="REPKKM"){result="DOC_REPKKM_DVREG";}//{Text="����� ���";}
if (type_doc=="OSTVS"){result="DOC_OSTVS_DVREG";}//{Text="����. ��������������";}
if (type_doc=="SCHFACT"){result="DOC_SCHFACT_DVREG";}//{Text="����-�������";}
if (type_doc=="REALROZN"){result="DOC_REALROZN_DVREG";}//{Text="���������� ����.";}
if (type_doc=="PKOROZN"){result="DOC_PKOROZN_DVREG";}//{Text="������ ���.";}
if (type_doc=="RKOROZN"){result="DOC_RKOROZN_DVREG";}//{Text="������ ���.";}

if (type_doc=="VPOK"){result="DOC_VPOK_DVREG";}//{Text="������� ����������";}

if (type_doc=="ISMPRICE"){result="DOC_ISMPRICE_DVREG";}//{Text="����������";}
if (type_doc=="SPOTROST"){result="DOC_SPOTROST_DVREG";}//{Text="�������� ���. ��������";}
if (type_doc=="REV"){result="DOC_REV_DVREG";}//{Text="�������";}

if (type_doc=="SBKOMPL"){result="DOC_SBKOMPL_DVREG";}//{Text="����������";}
if (type_doc=="RASBKOMPL"){result="DOC_RASBKOMPL_DVREG";}//{Text="�������� ���. ��������";}
if (type_doc=="ZAMENA"){result="DOC_ZAMENA_DVREG";}//{Text="�������";}

if (type_doc=="KORRVS"){result="DOC_KORRVS_DVREG";}
if (type_doc=="VIPBANK"){result="DOC_VIPBANK_DVREG";}
if (type_doc=="OTCHPOST"){result="DOC_OTCHPOST_DVREG";}

//��������� ���������
if (type_doc=="RG_ADVCUST"){result="DOC_RGADVCUST_DVREG";}
if (type_doc=="RG_BANK"){result="DOC_RGBANK_DVREG";}
if (type_doc=="RG_CARDBAL"){result="DOC_RGCARD_BALANCE_DVREG";}
if (type_doc=="RG_OSTNOM"){result="DOC_RGGOODS_DVREG";}
if (type_doc=="RG_KASSA"){result="DOC_RGKASSA_DVREG";}
if (type_doc=="RG_OSTNOM"){result="DOC_RGOSTNOM_DVREG";}
if (type_doc=="RG_PAYSALE"){result="DOC_RGPAYSALE_DVREG";}
if (type_doc=="RG_VSRASCH"){result="DOC_RGVSRASCH_DVREG";}
if (type_doc=="RG_OTCHPOST"){result="DOC_RGOTCHPOST_DVREG";}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString glGetNameProcedureCancelDvRegRemontSystem(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="KM1"){result="REM_DOC_KM1_CANCEL_DVREG";}
if (type_doc=="KM2"){result="REM_DOC_KM2_CANCEL_DVREG";}
if (type_doc=="REMONTHW"){result="REM_DOC_REMONTHW_CANCEL_DVREG";}
if (type_doc=="REMONTKKT"){result="REM_DOC_REMONTKKT_CANCEL_DVREG";}
if (type_doc=="REMONT"){result="REM_DOC_REMONT_CANCEL_DVREG";}
if (type_doc=="SETSERVHW"){result="REM_DOC_SETSERVHW_CANCEL_DVREG";}
if (type_doc=="SETSERVKKT"){result="REM_DOC_SETSERVKKT_CANCEL_DVREG";}


if (type_doc=="REMPRN"){result="REM_DOC_PRN_CANCEL_DVREG";}
if (type_doc=="REMREAL"){result="REM_DOC_REAL_CANCEL_DVREG";}
if (type_doc=="REMOSN"){result="REM_DOC_OSN_CANCEL_DVREG";}
if (type_doc=="REMSBKOMPL"){result="REM_DOC_SBKOMPL_CANCEL_DVREG";}
if (type_doc=="POSTOTDIL"){result="REM_DOC_DILPOST_CANCEL_DVREG";}
if (type_doc=="VOSDILERU"){result="REM_DOC_DILRET_CANCEL_DVREG";}
if (type_doc=="PERSC"){result="REM_DOC_SCPER_CANCEL_DVREG";}
if (type_doc=="VOSVISSC"){result="REM_DOC_SCRET_CANCEL_DVREG";}
if (type_doc=="REMVPOK"){result="REM_DOC_VPOK_CANCEL_DVREG";}
if (type_doc=="REMAKT"){result="REM_DOC_DAKT_CANCEL_DVREG";}
if (type_doc=="REMPER"){result="REM_DOC_PER_CANCEL_DVREG";}

if (type_doc=="REMZPOST"){result="REM_DOC_ZPOST_CANCEL_DVREG";}
if (type_doc=="REMZVID"){result="REM_DOC_ZVID_CANCEL_DVREG";}
if (type_doc=="REMZPER"){result="REM_DOC_ZPER_CANCEL_DVREG";}
if (type_doc=="REMZSTART"){result="REM_DOC_ZSTART_CANCEL_DVREG";}
if (type_doc=="REMZEND"){result="REM_DOC_ZEND_CANCEL_DVREG";}
if (type_doc=="REMZOPER"){result="REM_DOC_ZOPER_CANCEL_DVREG";}
if (type_doc=="REMZTREB"){result="REM_DOC_ZTREB_CANCEL_DVREG";}
if (type_doc=="REMZAKTPR"){result="REM_DOC_ZAKTPR_CANCEL_DVREG";}
if (type_doc=="REMZVZAP"){result="REM_DOC_ZVZAP_CANCEL_DVREG";}


if (type_doc=="REMSPN"){result="REM_DOC_SPN_CANCEL_DVREG";}

if (type_doc=="REM_RGOTCHPOST"){result="REM_DOC_RGOTCHPOST_CANCEL_DVREG";}

if (type_doc=="REM_VIDACHA_HW"){result="REM_DOC_VIDACHA_HW_CANCEL_DVREG";}
if (type_doc=="REM_VOSVRAT_HW"){result="REM_DOC_VOSVRAT_HW_CANCEL_DVREG";}

if (type_doc=="REM_ZAKPOST"){result="REM_DOC_ZAKPOST_CANCEL_DVREG";}
if (type_doc=="REM_OTPRPOST"){result="REM_DOC_OTPRPOST_CANCEL_DVREG";}


if (type_doc=="REM_VZPER"){result="REM_DOC_VZPER_CANCEL_DVREG";}
if (type_doc=="REM_VZVPO"){result="REM_DOC_VZVPO_CANCEL_DVREG";}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString glGetNameProcedureDvRegRemontSystem(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="REMONT"){result="REM_DOC_REMONT_DVREG";}
if (type_doc=="REMONTHW"){result="REM_DOC_REMONTHW_DVREG";}
if (type_doc=="REMONTKKT"){result="REM_DOC_REMONTKKT_DVREG";}
if (type_doc=="KM1"){result="REM_DOC_KM1_DVREG";}
if (type_doc=="KM2"){result="REM_DOC_KM2_DVREG";}
if (type_doc=="SETSERVKKT"){result="REM_DOC_SETSERVKKT_DVREG";}
if (type_doc=="SETSERVHW"){result="REM_DOC_SETSERVHW_DVREG";}

if (type_doc=="REMPRN"){result="REM_DOC_PRN_DVREG";}
if (type_doc=="REMREAL"){result="REM_DOC_REAL_DVREG";}
if (type_doc=="REMOSN"){result="REM_DOC_OSN_DVREG";}
if (type_doc=="REMSBKOMPL"){result="REM_DOC_SBKOMPL_DVREG";}
if (type_doc=="POSTOTDIL"){result="REM_DOC_DILPOST_DVREG";}
if (type_doc=="VOSDILERU"){result="REM_DOC_DILRET_DVREG";}
if (type_doc=="PERSC"){result="REM_DOC_SCPER_DVREG";}
if (type_doc=="VOSVISSC"){result="REM_DOC_SCRET_DVREG";}
if (type_doc=="REMVPOK"){result="REM_DOC_VPOK_DVREG";}
if (type_doc=="REMAKT"){result="REM_DOC_DAKT_DVREG";}

if (type_doc=="REMPER"){result="REM_DOC_PER_DVREG";}

if (type_doc=="REMZPOST"){result="REM_DOC_ZPOST_DVREG";}
if (type_doc=="REMZVID"){result="REM_DOC_ZVID_DVREG";}
if (type_doc=="REMZPER"){result="REM_DOC_ZPER_DVREG";}
if (type_doc=="REMZSTART"){result="REM_DOC_ZSTART_DVREG";}
if (type_doc=="REMZEND"){result="REM_DOC_ZEND_DVREG";}
if (type_doc=="REMZOPER"){result="REM_DOC_ZOPER_DVREG";}
if (type_doc=="REMZTREB"){result="REM_DOC_ZTREB_DVREG";}
if (type_doc=="REMZAKTPR"){result="REM_DOC_ZAKTPR_DVREG";}
if (type_doc=="REMZVZAP"){result="REM_DOC_ZVZAP_DVREG";}

if (type_doc=="REMSPN"){result="REM_DOC_SPN_DVREG";}
if (type_doc=="REM_RGOTCHPOST"){result="REM_DOC_RGOTCHPOST_DVREG";}

if (type_doc=="REM_VIDACHA_HW"){result="REM_DOC_VIDACHA_HW_DVREG";}
if (type_doc=="REM_VOSVRAT_HW"){result="REM_DOC_VOSVRAT_HW_DVREG";}

if (type_doc=="REM_ZAKPOST"){result="REM_DOC_ZAKPOST_DVREG";}
if (type_doc=="REM_OTPRPOST"){result="REM_DOC_OTPRPOST_DVREG";}

if (type_doc=="REM_VZPER"){result="REM_DOC_VZPER_DVREG";}
if (type_doc=="REM_VZVPO"){result="REM_DOC_VZVPO_DVREG";}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString glGetNameProcedureCancelDvRegHotelSystem(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="BRON"){result="HOT_DOC_BRON_CANCEL_DVREG";}
if (type_doc=="OTMBRON"){result="HOT_DOC_OTMBRON_CANCEL_DVREG";}
if (type_doc=="RASCHET"){result="HOT_DOC_RASCHET_CANCEL_DVREG";}
if (type_doc=="RASM"){result="HOT_DOC_RASM_CANCEL_DVREG";}
if (type_doc=="REAL"){result="HOT_DOC_REAL_CANCEL_DVREG";}
if (type_doc=="VIEZD"){result="HOT_DOC_VIESD_CANCEL_DVREG";}


return result;
}
//-----------------------------------------------------------------------------


UnicodeString glGetNameProcedureDvRegHotelSystem(UnicodeString type_doc)
{
UnicodeString result="";

if (type_doc=="BRON"){result="HOT_DOC_BRON_DVREG";}
if (type_doc=="OTMBRON"){result="HOT_DOC_OTMBRON_DVREG";}
if (type_doc=="RASCHET"){result="HOT_DOC_RASCHET_DVREG";}
if (type_doc=="RASM"){result="HOT_DOC_RASM_DVREG";}
if (type_doc=="REAL"){result="HOT_DOC_REAL_DVREG";}
if (type_doc=="VIEZD"){result="HOT_DOC_VIESD_DVREG";}


return result;
}
//-----------------------------------------------------------------------------
UnicodeString glDelSymbolOfBarCode(UnicodeString bar_code)
{
UnicodeString result="";
UnicodeString s=bar_code;
UnicodeString barcode_for_poisk="";

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
result=barcode_for_poisk;
return result;
}
//----------------------------------------------------------------------------
UnicodeString glDelSymbolOfDoubleValue (UnicodeString value)
{

UnicodeString result="";
UnicodeString StrValue=value;
int kol_tchk=0;
for(int i=1;i<=StrValue.Length();i++)
		{
		if (kol_tchk <= 1)
			{
			UnicodeString symbol=StrValue[i];
			if (symbol =='.' || symbol==',')
				{
				kol_tchk++;
				if (kol_tchk <= 1)
					{
					result=result+symbol;
                    }
				}
			else
				{
				if (symbol=='0' || symbol=='1' || symbol=='2'   || symbol=='3' || symbol=='4'
					|| symbol=='5' || symbol=='6' || symbol=='7'  || symbol=='8'  || symbol=='9')
					{
					result=result+symbol;
					}
				}

			}
		}

result=Trim(result);
return result;


}
//----------------------------------------------------------------------------
