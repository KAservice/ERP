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
CountLoadModules=List->Count;   // в этом случае  все модули должны быть
								//выгружены и соответственно размер списка 0
								//а если не все модули выгружены нельзя выгружать COM систему
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

OutputDebugStringA("Получаем имя модуля: ");
TkanBaseGuid *base_guid=new TkanBaseGuid();
AnsiString ansi_name_modul=base_guid->GetNameModul(id_class);
delete base_guid;

OutputDebugStringA(("Получили имя модуля: "+ansi_name_modul).c_str());
	HINSTANCE dllIn=GetModule(ansi_name_modul);
	if(dllIn)
		{
		DllGetClassObject=(DllGetClassObjectType*)GetProcAddress(dllIn,"_kanGetClassObject");
		result = DllGetClassObject(id_class,id_interface,ppv);
		//можем получить только интерфейс фабрики классов
		//для других интерфейсов будет 0

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

//перебираем список модулей, вдруг уже загружен
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
	OutputDebugStringA(("Загружаем модуль: "+name_modul).c_str());
	result=LoadLibrary(name_modul.c_str());

	//передаем TApplication
		DllSendApplication=0;
		DllSendApplication=(DllSendApplicationType*)GetProcAddress(result,"_kanSendApplication");
		if (DllSendApplication!=0 && glApp!=0)
			{
			DllSendApplication(glApp);
			}

	//Инициализируем библиотеку
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
OutputDebugStringA(("Получаем GUID модуля по ProgId: "+AnsiString(prog_id)).c_str());

TkanBaseGuid *base_guid=new TkanBaseGuid();
*guid=base_guid->GetCLSIDFromProgID(pi);
delete base_guid;

OutputDebugStringW(("Получили GUID  "+GUIDToString(*guid)).c_str());

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
OutputDebugStringA(("Создаем объект: "+AnsiString(prog_id)).c_str());
CLSID clsid;
IkanClassFactory * i_cf;
if(kanCLSIDFromProgID(prog_id,&clsid)==-1)
	{
	OutputDebugStringA("Получаем интерфейс фабрики классов ");
	if (kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) ==-1)
		{
		OutputDebugStringA("Получили интерфейс фабрики классов ");
		OutputDebugStringA("Непосредственно создаем объект  ");
		if(i_cf->kanCreateInstance(id_interface,ppv)==-1)
			{
			OutputDebugStringA("Создали объект  ");
			result=-1;
			}
		else
			{
			ShowMessage("Ошибка при получении интерфейса "+GUIDToString(id_interface)+" объекта "+AnsiString(prog_id)+"!");
			}
		i_cf->kanRelease();
		OutputDebugStringA(("Создан объект: "+AnsiString(prog_id)).c_str());
		}
	else
		{
		ShowMessage("Ошибка при получении интерфейса IID_IkanClassFactory объекта "+AnsiString(prog_id)+"!");
		}
	}
else
	{
	ShowMessage("Ошибка при получении CLSID объекта "+AnsiString(prog_id)+"! Возможно класс не зарегистрирован в системе kanCOM!");
	}
return result;
}

//----------------------------------------------------------------------------
int TkanComClassFactory::UnloadModule(HINSTANCE dll_in)
{//попробуем выгрузить модуль
int result=0;
	if(dll_in)
		{
		DllCanUnloadNow=0;
		DllCanUnloadNow=(DllCanUnloadNowType*)GetProcAddress(dll_in,"_kanCanUnloadNow");
		if (DllCanUnloadNow!=0)
			{
			if (DllCanUnloadNow()==-1)
				{
				//завершаем работу с библиотекой
				typedef int (__import  DllkanDoneType(void));
				DllkanDoneType * DllkanDone=0;
				DllkanDone=(DllkanDoneType*)GetProcAddress(dll_in,"_kanDone");
				if (DllkanDone!=0)
					{
					DllkanDone();
					}
				//ShowMessage("Выгружаем свободный модуль - "+El->NameModul);
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
//перебираем все загруженные модули и свободные выгружаем



//перебираем список модулей
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
//перебираем список модулей
for (int i=0; i<List->Count;i++)
	{
	TElementSpiska * el;
	el=(TElementSpiska*) List->Items[i];
	str=str+el->NameModul+" \n";
	kol++;
	}


    ShowMessage("Загружены следующие модули:\n "+str);

}
//-----------------------------------------------------------------------------
void TkanComClassFactory::UnloadAllModules(void)
{//выгружаем все модули при завершении работы приложения

TElementSpiska * el;

for (int i=0; i<List->Count;i++)
	{
	el=(TElementSpiska*) List->Items[i];
	AnsiString s=el->NameModul;

	//завершаем работу с библиотекой
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

