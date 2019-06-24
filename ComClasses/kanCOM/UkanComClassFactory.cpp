//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanComClassFactory.h"
#include "vcl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern int NumObject;
extern TApplication * glApp;
extern int CountLoadModules;
//----------------------------------------------------------------------------
TkanComClassFactory::TkanComClassFactory()
{


NumRefs=0;
++NumObject;
List=new TList;
}
//----------------------------------------------------------------------------
TkanComClassFactory::~TkanComClassFactory()
{
CountLoadModules=List->Count;   // � ���� ������  ��� ������ ������ ����
								//��������� � �������������� ������ ������ 0
								//� ���� �� ��� ������ ��������� ������ ��������� COM �������
for (int i=0; i<List->Count;i++)
	{
	TElementSpiska *object=(TElementSpiska*) List->Items[i];
	delete object;
	}
delete List;

--NumObject;
}
//----------------------------------------------------------------------------

int TkanComClassFactory::kanQueryInterface(REFIID id_interface, void**ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*> (this);
	result=-1;
	}
else if (id_interface==IID_IkanCom)
	{
	*ppv=static_cast<IkanCom*> (this);
	result=-1;
	}
else
	{
	*ppv=NULL;
	result=0;
	return result;
	}

kanAddRef();

return result;
}
//---------------------------------------------------------------------------
int TkanComClassFactory::kanAddRef(void)
{
return (++NumRefs);
}
//-----------------------------------------------------------------------------
int TkanComClassFactory::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;

	return 0;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TkanComClassFactory::kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
UnicodeString name_modul="";

OutputDebugStringA("�������� ��� ������: ");
TkanBaseGuid *base_guid=new TkanBaseGuid();
AnsiString ansi_name_modul=base_guid->GetNameModul(id_class);
delete base_guid;

OutputDebugStringA(("�������� ��� ������: "+ansi_name_modul).c_str());
	HINSTANCE dllIn=GetModule(ansi_name_modul);
	if(dllIn)
		{
		DllGetClassObject=(DllGetClassObjectType*)GetProcAddress(dllIn,"_kanGetClassObject");
		result = DllGetClassObject(id_class,id_interface,ppv);
		//����� �������� ������ ��������� ������� �������
		//��� ������ ����������� ����� 0

		}

UnloadFreeModules();
return result;
}
//-------------------------------------------------------------------------
HINSTANCE TkanComClassFactory::GetModule(AnsiString name_modul)
{
HINSTANCE result=0;
TElementSpiska * el;
bool nayden=false;

//���������� ������ �������, ����� ��� ��������
for (int i=0; i<List->Count;i++)
	{
	el=(TElementSpiska*) List->Items[i];
	if (el->NameModul==name_modul)
		{
		result=el->DllInstance;
		nayden=true;
		}
	}

if (nayden==false)
	{
	OutputDebugStringA(("��������� ������: "+name_modul).c_str());
	result=LoadLibrary(name_modul.c_str());

	//�������� TApplication
		DllSendApplication=0;
		DllSendApplication=(DllSendApplicationType*)GetProcAddress(result,"_kanSendApplication");
		if (DllSendApplication!=0 && glApp!=0)
			{
			DllSendApplication(glApp);
			}

	//�������������� ����������
	typedef int (__import  DllkanInitType(void));
	DllkanInitType * DllkanInit=0;
	DllkanInit=(DllkanInitType*)GetProcAddress(result,"_kanInit");
		if (DllkanInit!=0)
			{
			DllkanInit();
			}

	el=new TElementSpiska;
	el->DllInstance=result;
	el->NameModul=name_modul;
    List->Add(el);
	}

CountLoadModules=List->Count;
return result;
}

//-------------------------------------------------------------------------
int TkanComClassFactory::kanProgIDFromCLSID(GUID guid, char *  prog_id )
{
int result=-1;

TkanBaseGuid *base_guid=new TkanBaseGuid();
AnsiString ansi_prog_id=base_guid->GetProgIDFromCLSID(guid);
delete base_guid;

prog_id=ansi_prog_id.c_str();
return result;
}
//------------------------------------------------------------------------
int TkanComClassFactory::kanCLSIDFromProgID(char * prog_id, GUID * guid)
{
int result=0;
AnsiString pi=prog_id;
OutputDebugStringA(("�������� GUID ������ �� ProgId: "+AnsiString(prog_id)).c_str());

TkanBaseGuid *base_guid=new TkanBaseGuid();
*guid=base_guid->GetCLSIDFromProgID(pi);
delete base_guid;

OutputDebugStringW(("�������� GUID  "+GUIDToString(*guid)).c_str());

result=-1;
return result;
}
//--------------------------------------------------------------------------
int TkanComClassFactory::kanAddClass(REFIID id_class, char * prog_id, char * file_name_modul)
{
int result=-1;

TkanBaseGuid *base_guid=new TkanBaseGuid();
if (base_guid->AddClass(id_class, prog_id, file_name_modul)==true)
	{
	result=-1;
	}
else
	{
    result=0;
	}

delete base_guid;

return result;
}
//----------------------------------------------------------------------------
int TkanComClassFactory::kanRemoveClass(REFIID id_class)
{
int result=-1;

TkanBaseGuid *base_guid=new TkanBaseGuid();
if (base_guid->RemoveClass(id_class)==true)
	{
	result=-1;
	}
else
	{
    result=0;
	}

delete base_guid;

return result;
}
//----------------------------------------------------------------------------
int TkanComClassFactory::kanRegisterClassInModule(char * file_name_modul)
{
int result=0;
DllRegisterServer=0;

	HINSTANCE dllIn=LoadLibrary(file_name_modul);
	if(dllIn)
		{
		DllRegisterServer=(DllRegisterServerType*)GetProcAddress(dllIn,"_kanRegisterServer");
		if (DllRegisterServer!=0)
			{
			IkanCom * icom;
			if(kanQueryInterface(IID_IkanCom, (void **) &icom)==-1)
				{
				result = DllRegisterServer(icom);
				}
			}
		FreeLibrary(dllIn);
		}

return result;
}
//----------------------------------------------------------------------------
int TkanComClassFactory::kanUnregisterClassInModule(char * file_name_modul)
{
int result=0;
DllUnregisterServer=0;

	HINSTANCE dllIn=LoadLibrary(file_name_modul);
	if(dllIn)
		{
		DllUnregisterServer=(DllUnregisterServerType*)GetProcAddress(dllIn,"_kanUnregisterServer");
		if (DllUnregisterServer!=0)
			{
			IkanCom * icom;
			if (kanQueryInterface(IID_IkanCom, (void **) &icom)==-1)
				{
				result = DllUnregisterServer(icom);
				}
			}
		FreeLibrary(dllIn);
		}

return result;
}
//------------------------------------------------------------------------------
int TkanComClassFactory::kanCreateObject(char * prog_id, REFIID id_interface, void** ppv)
{
int result=0;
OutputDebugStringA(("������� ������: "+AnsiString(prog_id)).c_str());
CLSID clsid;
IkanClassFactory * i_cf;
if(kanCLSIDFromProgID(prog_id,&clsid)==-1)
	{
	OutputDebugStringA("�������� ��������� ������� ������� ");
	if (kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) ==-1)
		{
		OutputDebugStringA("�������� ��������� ������� ������� ");
		OutputDebugStringA("��������������� ������� ������  ");
		if(i_cf->kanCreateInstance(id_interface,ppv)==-1)
			{
			OutputDebugStringA("������� ������  ");
			result=-1;
			}
		else
			{
			ShowMessage("������ ��� ��������� ���������� "+GUIDToString(id_interface)+" ������� "+AnsiString(prog_id)+"!");
			}
		i_cf->kanRelease();
		OutputDebugStringA(("������ ������: "+AnsiString(prog_id)).c_str());
		}
	else
		{
		ShowMessage("������ ��� ��������� ���������� IID_IkanClassFactory ������� "+AnsiString(prog_id)+"!");
		}
	}
else
	{
	ShowMessage("������ ��� ��������� CLSID ������� "+AnsiString(prog_id)+"! �������� ����� �� ��������������� � ������� kanCOM!");
	}
return result;
}

//----------------------------------------------------------------------------
int TkanComClassFactory::UnloadModule(HINSTANCE dll_in)
{//��������� ��������� ������
int result=0;
	if(dll_in)
		{
		DllCanUnloadNow=0;
		DllCanUnloadNow=(DllCanUnloadNowType*)GetProcAddress(dll_in,"_kanCanUnloadNow");
		if (DllCanUnloadNow!=0)
			{
			if (DllCanUnloadNow()==-1)
				{
				//��������� ������ � �����������
				typedef int (__import  DllkanDoneType(void));
				DllkanDoneType * DllkanDone=0;
				DllkanDone=(DllkanDoneType*)GetProcAddress(dll_in,"_kanDone");
				if (DllkanDone!=0)
					{
					DllkanDone();
					}
				//ShowMessage("��������� ��������� ������ - "+El->NameModul);
				FreeLibrary(dll_in);
				result=-1;
				}
			}
		}
return result;
}
//-----------------------------------------------------------------------------
void TkanComClassFactory::UnloadFreeModules(void)
{
//���������� ��� ����������� ������ � ��������� ���������



//���������� ������ �������
for (int i=0; i<List->Count;i++)
	{
	El=(TElementSpiska*) List->Items[i];
	if (UnloadModule(El->DllInstance)==-1)
		{
		delete El;
		List->Items[i]=NULL;
		}
	}
List->Pack();
}
//---------------------------------------------------------------------------
void TkanComClassFactory::ShowListLoadModules(void)
{
AnsiString str="";
int kol=0;
//���������� ������ �������
for (int i=0; i<List->Count;i++)
	{
	TElementSpiska * el;
	el=(TElementSpiska*) List->Items[i];
	str=str+el->NameModul+" \n";
	kol++;
	}


    ShowMessage("��������� ��������� ������:\n "+str);

}
//-----------------------------------------------------------------------------
void TkanComClassFactory::UnloadAllModules(void)
{//��������� ��� ������ ��� ���������� ������ ����������

TElementSpiska * el;

for (int i=0; i<List->Count;i++)
	{
	el=(TElementSpiska*) List->Items[i];
	AnsiString s=el->NameModul;

	//��������� ������ � �����������
	typedef int (__import  DllkanDoneType(void));
	DllkanDoneType * DllkanDone=0;
	DllkanDone=(DllkanDoneType*)GetProcAddress(el->DllInstance,"_kanDone");
	if (DllkanDone!=0)
		{
		DllkanDone();
		}
	FreeLibrary(el->DllInstance);
	}

}
//-----------------------------------------------------------------------------

