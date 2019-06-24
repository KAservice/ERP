//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UkanComClassFactory.h"
#include "UkanBaseGuid.h"
//---------------------------------------------------------------------------
extern "C" int __declspec (dllexport) kanGetInterfaceCom(REFIID id_class, REFIID id_interface, void ** ppv);
extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" void __declspec (dllexport) kanShowListLoadModules(void);
extern "C" void __declspec (dllexport) kanUnloadFreeModules(void);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
extern "C" void __declspec (dllexport) kanInit(void);
extern "C" void __declspec (dllexport) kanDone(void);
//---------------------------------------------------------------------------


int NumObject=0;
int CountLoadModules=0;
TApplication * glApp=0;
TApplication * dllApp=0;
TkanComClassFactory * glCom=0;
void CreateNewBaseGuid(bool create_new);

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{

	return 1;
}
//---------------------------------------------------------------------------
int kanGetInterfaceCom(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;

	glCom=new TkanComClassFactory();      		//����� �������� ������ ��������� IkanCom
	result=glCom->kanQueryInterface(id_interface, ppv);               //��� ������ ����������� ����� 0
	if (result!=-1)
		{
		delete glCom;
		glCom=0;
		}

//�������� ���������� �� ���� GUID��, ���� ��� �� ��������
CreateNewBaseGuid(false);


return result;
}
//----------------------------------------------------------------------------
int kanSendApplication(TApplication * app)
{
int result=-1;
dllApp=Application;
glApp=app;
return result;
}
//----------------------------------------------------------------------------
void CreateNewBaseGuid(bool create_new)
{
if (create_new==false)
	{//������� ����� ������ ���� ��� ������
	UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
	if (FileExists("kanGUID.dat")==true)
		{
		return;
		}
	}

//������� ����� � ����� ������
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
	if (FileExists("kanGUID.dat")==true)
		{
		DeleteFile("kanGUID.dat");
		}

//�������� ������ ������ dll �������� ��������
//���������� ������ � �������� �������������� ������� ����������� �������

TSearchRec F;
int ires=FindFirst(ProgramCatalog+"\\*.dll",faAnyFile|faDirectory,F);
while (!ires)
	{
	 if (F.Attr &faDirectory)
		{//�������

		}
	 else
		{//����
		AnsiString modul=F.Name;
		glCom->kanRegisterClassInModule(modul.c_str());
		}
	ires=FindNext(F);
	}
FindClose(F);

}
//---------------------------------------------------------------------------
void kanShowListLoadModules(void)
{
glCom->ShowListLoadModules();
}
//---------------------------------------------------------------------------
void kanUnloadFreeModules(void)
{
glCom->UnloadFreeModules();
}
//--------------------------------------------------------------------------
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0 && CountLoadModules==0)
	{
	result= -1;
	}

return result;
}
//-----------------------------------------------------------------------------
void kanInit(void)
{


}
//-----------------------------------------------------------------------------
void kanDone(void)
{
glCom->UnloadFreeModules();

}
//------------------------------------------------------------------------------
