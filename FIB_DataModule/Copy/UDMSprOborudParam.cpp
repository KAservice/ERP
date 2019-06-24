//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprOborudParam.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
__fastcall TDMSprOborudParam::TDMSprOborudParam(TComponent* Owner)
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
bool TDMSprOborudParam::Init(void)
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
IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprOborudParam::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprOborudParam::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void __fastcall TDMSprOborudParam::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDOBORUD_SOBORUD_PAR->AsString=IdOwner;


}
//---------------------------------------------------------------------------

       //IkasDM
	//параметры
bool TDMSprOborudParam::SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsString=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsString=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsInteger=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsInteger=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsFloat=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsFloat=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsString=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsString=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsDateTime=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsDateTime=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->ParamByName(name_parameter)->AsBoolean=value;
				result=true;
				}break;
			case 1:
				{
				Element->ParamByName(name_parameter)->AsBoolean=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------


bool TDMSprOborudParam::OpenDataSet(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Open();
				result=true;
				}break;
			case 1:
				{
				Element->Open();
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------------------
bool TDMSprOborudParam::CloseDataSet(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Close();
				result=true;
				}break;
			case 1:
				{
				Element->Close();
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------------------

	// значения полей
bool TDMSprOborudParam::SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsInteger=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsInteger=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
int TDMSprOborudParam::GetValueFieldAsInt (UnicodeString name_field, int index_data_set)
{
int result=0;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=Table->FieldByName(name_field)->AsInteger;
				}break;
			case 1:
				{
				result=Element->FieldByName(name_field)->AsInteger;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//------------------------------------------------------------------------------------

bool TDMSprOborudParam::SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsString=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsString=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
__int64 TDMSprOborudParam::GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)
{
__int64 result=0;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=glStrToInt64(Table->FieldByName(name_field)->AsString);
				}break;
			case 1:
				{
				result=glStrToInt64(Element->FieldByName(name_field)->AsString);
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//------------------------------------------------------------------------------------

bool TDMSprOborudParam::SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsFloat=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsFloat=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
double TDMSprOborudParam::GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)
{
double result=0;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=Table->FieldByName(name_field)->AsFloat;
				}break;
			case 1:
				{
				result=Element->FieldByName(name_field)->AsFloat;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//------------------------------------------------------------------------------------

bool TDMSprOborudParam::SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsString=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsString=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMSprOborudParam::GetValueFieldAsString (UnicodeString name_field, int index_data_set)
{
UnicodeString result=0;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=Table->FieldByName(name_field)->AsString;
				}break;
			case 1:
				{
				result=Element->FieldByName(name_field)->AsString;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
bool TDMSprOborudParam::SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsDateTime=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsDateTime=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
TDateTime TDMSprOborudParam::GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)
{
TDateTime result=0;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=Table->FieldByName(name_field)->AsDateTime;
				}break;
			case 1:
				{
				result=Element->FieldByName(name_field)->AsDateTime;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;
}
//------------------------------------------------------------------------------------
bool TDMSprOborudParam::SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->FieldByName(name_field)->AsBoolean=value;
				result=true;
				}break;
			case 1:
				{
				Element->FieldByName(name_field)->AsBoolean=value;
				result=true;
				}break;
			}
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	}
return result;



}
//--------------------------------------------------------------------------------
bool TDMSprOborudParam::GetValueFieldAsBool (UnicodeString name_field, int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				result=Table->FieldByName(name_field)->AsBoolean;
				}break;
			case 1:
				{
				result=Element->FieldByName(name_field)->AsBoolean;
				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------------

bool TDMSprOborudParam::SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------

	//навиация
int TDMSprOborudParam::GetRecordCount(int index_data_set)
{
int result=-1;

		switch (index_data_set)
			{
			case 0:
				{
				result=Table->RecordCount;
				}break;
			case 1:
				{

				}break;
			}

return result;
}
//-----------------------------------------------------------------------------
int TDMSprOborudParam::GetIndexTecRecord(int index_data_set)
{
int result=-1;

		switch (index_data_set)
			{
			case 0:
				{
				result=Table->RecNo;
				}break;
			case 1:
				{

				}break;
			}

return result;
}
//------------------------------------------------------------------------
bool TDMSprOborudParam::GetEof(int index_data_set)
{
bool result=false;

		switch (index_data_set)
			{
			case 0:
				{
				result=Table->Eof;
				}break;
			case 1:
				{

				}break;
			}

return result;
}
//------------------------------------------------------------------------
bool TDMSprOborudParam::First(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->First();
				}break;
			case 1:
				{

				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------
bool TDMSprOborudParam::Next(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Next();
				}break;
			case 1:
				{

				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------
//-------------------------------------------------------------------------
bool TDMSprOborudParam::Last(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Last();
				}break;
			case 1:
				{

				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------
bool TDMSprOborudParam::MoveBy(int kol_rec,int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->MoveBy(kol_rec);
				}break;
			case 1:
				{

				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
	//сохранение удаление записей
bool TDMSprOborudParam::Edit(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Edit();
				}break;
			case 1:
				{
				Element->Edit();
				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::Post(int index_data_set)
{
bool result=false;
try
		{
		switch (index_data_set)
			{
			case 0:
				{
				Table->Post();
				}break;
			case 1:
				{
				Element->Post();
				}break;
			}
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------


		 //IkasDMSpr
	//таблица
bool TDMSprOborudParam::OpenTable(int type_search)  //0 без поиска, 1 по наименованию, 2 по реквизиту
{
bool result=false;
try
		{
		Table->Close();
		Table->ParamByName("PARAM_IDOWNER")->AsInt64=IdOwner;
		Table->Open();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-------------------------------------------------------------------------------
bool TDMSprOborudParam::CloseTable(void)
{
bool result=false;
try
		{
		Table->Close();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;

}
//-------------------------------------------------------------------------------
bool TDMSprOborudParam::DeleteString(void)
{
bool result=false;
try
		{
		Table->Delete();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;

}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::AppendString(void)
{
bool result=false;
try
		{
		Table->Append();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;


}
//----------------------------------------------------------------------------
bool TDMSprOborudParam::SaveChanges(void)
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdOwner);
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::CancelChanges(void)
{
bool result=true;
try
		{
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdOwner);
		}
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
return result;

}
//----------------------------------------------------------------------------
bool TDMSprOborudParam::SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------
bool TDMSprOborudParam::SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------

	//элемент
bool TDMSprOborudParam::NewElement()
{
bool result=false;
try
		{
		Element->Append();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprOborudParam::OpenElement(__int64 id)
{
bool result=false;
try
		{
        Element->Close();
		Element->ParamByName("PARAM_ID")->AsString=id;
		Element->Open();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------

bool TDMSprOborudParam::DeleteElement(__int64 id)
{
bool result=false;
try
		{
		OpenElement(id);
		Element->Delete();
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprOborudParam::SaveElement(void)
{
bool result=false;

IdEl=glStrToInt64(ElementID_SOBORUD_PAR->AsString);

try
		{
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(IdEl);
		result=true;
		}
catch(Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprOborudParam::ChangeGrp(__int64 new_id_grp, __int64 id_el)
{
bool result=false;

return result;
}
//------------------------------------------------------------------------------


//интерфейс IkasDMDataSet

TDataSource * TDMSprOborudParam::kanGetDataSource(int index_data_source)
{
TDataSource * result=0;
		switch (index_data_source)
			{
			case 0:
				{
				result=DataSourceTable;
				}break;
			case 1:
				{
				result=DataSourceElement;
				}break;
			}
return result;
}
//-----------------------------------------------------------------------------------------------------





