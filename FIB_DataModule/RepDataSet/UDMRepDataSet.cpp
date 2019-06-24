//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMRepDataSet.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMRepDataSet::TDMRepDataSet(TComponent* Owner)
	: TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TDMRepDataSet::DataModuleDestroy(TObject *Sender)
{
DataSet->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMRepDataSet::Init(void)
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

Transaction->DefaultDatabase=DM_Connection->pFIBData;
DataSet->Database=DM_Connection->pFIBData;


DataSet->SelectSQL->Clear();
DataSet->SelectSQL->Add("select * from REM_SHW_GET_TBL_ISP_ZIP(:PARAM_IDHW) order by out_pos");


result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMRepDataSet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
//интерфейс IkasDM


//параметры
bool TDMRepDataSet::SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsString=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)
{

bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsInteger=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)
{

bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsFloat=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)
{

bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsString=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsDateTime=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)
{

bool result=false;
try
	{
	DataSet->ParamByName(name_parameter)->AsBoolean=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------


bool TDMRepDataSet::OpenDataSet(int index_data_set)
{

bool result=false;
try
	{
	DataSet->Open();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::CloseDataSet(int index_data_set)
{
bool result=false;
try
	{
	DataSet->Close();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------

// значения полей
bool TDMRepDataSet::SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsInteger=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
int TDMRepDataSet::GetValueFieldAsInt (UnicodeString name_field, int index_data_set)
{

return DataSet->FieldByName(name_field)->AsInteger;

}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSet::SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsString=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
__int64 TDMRepDataSet::GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)
{

return	glStrToInt64(DataSet->FieldByName(name_field)->AsString);

}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSet::SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsFloat=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;

}
//-----------------------------------------------------------------------------------------------------
double TDMRepDataSet::GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)
{
return	DataSet->FieldByName(name_field)->AsFloat;
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSet::SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsString=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;

}
//-----------------------------------------------------------------------------------------------------
UnicodeString TDMRepDataSet::GetValueFieldAsString (UnicodeString name_field, int index_data_set)
{
return	DataSet->FieldByName(name_field)->AsString;
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSet::SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsDateTime=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
TDateTime TDMRepDataSet::GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)
{

return	DataSet->FieldByName(name_field)->AsDateTime;
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSet::SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
	{
	DataSet->FieldByName(name_field)->AsBoolean=value;
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::GetValueFieldAsBool (UnicodeString name_field, int index_data_set)
{

return	DataSet->FieldByName(name_field)->AsBoolean;
}
//-----------------------------------------------------------------------------------------------------


bool TDMRepDataSet::SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)
{
bool result=false;
//try
//	{
//	TBlobField * field=DataSet->FieldByName(name_field)->AsBlob;
//
//	result=true;
//	}
//catch(Exception &exception)
//		{
//		TextError=exception.Message;
//		result=false;
//		}
return result;

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{
//return Object->SaveValueFieldToFile(file_name, name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)
{

//return Object->LoadValueFieldFromStream(s,name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

//return Object->LoadValueFieldFromFile(file_name, name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------

//навиация
int TDMRepDataSet::GetRecordCount(int index_data_set)
{

return DataSet->RecordCount;
}
//-----------------------------------------------------------------------------------------------------
int TDMRepDataSet::GetIndexTecRecord(int index_data_set)
{
return DataSet->RecNo;

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::GetEof(int index_data_set)
{
return DataSet->Eof;

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::First(int index_data_set)
{
bool result=false;
try
	{
	DataSet->First();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::Next(int index_data_set)
{
bool result=false;
try
	{
	DataSet->Next();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::Last(int index_data_set)
{
bool result=false;
try
	{
	DataSet->Last();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::MoveBy(int kol_rec,int index_data_set)
{
bool result=false;
try
	{
	DataSet->MoveBy(kol_rec);
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;

}
//-----------------------------------------------------------------------------------------------------

//сохранение удаление записей
bool TDMRepDataSet::Edit(int index_data_set)
{
bool result=false;
try
	{
	DataSet->Edit();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSet::Post(int index_data_set)
{
bool result=false;
try
	{
	DataSet->Post();
	result=true;
	}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------------------------------


//интерфейс IkasDMDataSet

TDataSource * TDMRepDataSet::kanGetDataSource(int index_data_source)
{

return DataSource;
}
//-----------------------------------------------------------------------------------------------------
