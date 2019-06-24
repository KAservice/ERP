//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaCreateTriggerLog.h"
#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "pFIBScripter"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaCreateTriggerLog::TFormaCreateTriggerLog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateTriggerLog::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void TFormaCreateTriggerLog::UpdateForm(void)
{
Tables->Active=true;
Fields->Active=true;

}
//---------------------------------------------------------------------------
// ВАЖНО!!!!! ДЛЯ ТРИГГЕРОВ ЛОГГИРОВАВНИЯ
//-----------------------------------------------------------------------------
bool TFormaCreateTriggerLog::CheckTableForGreateTrigger(AnsiString name_table)
{  //таблицы, которые не логгируются
bool result=true;
	if (Trim(name_table)=="XDATA_OUT"){ result=false; }
	if (Trim(name_table)=="XFIELD_BASE"){result=false; }
	if (Trim(name_table)=="XMESSAGE_OBMEN"){result=false;}
	if (Trim(name_table)=="XTABLE_BASE") {result=false;}
	if (Trim(name_table)=="XTISM"){result=false;}
	if (Trim(name_table)=="XTISM_FIELDS"){result=false;}
	if (Trim(name_table)=="SYSTEM"){result=false;}
	if (Trim(name_table)=="XSETUP_OBMEN"){result=false;}
	if (Trim(name_table)=="XBASE_FOR_OBMEN"){result=false;}
	if (Trim(name_table)=="XTPRICE_FOR_OBMEN"){result=false;}
	if (Trim(name_table)=="VT_OST_NA_SKLADE"){result=false;}
	if (Trim(name_table)=="VT_OST_PO_REV"){result=false;}
	if (Trim(name_table)=="GURNALPLAT"){result=false;}
	if (Trim(name_table)=="LOG"){result=false;}
	if (Trim(name_table)=="RGZAK"){result=false;}
	if (Trim(name_table)=="RGZAKT"){result=false;}
	if (Trim(name_table)=="SETUP"){result=false;}
return result;
}
//---------------------------------------------------------------------------
bool TFormaCreateTriggerLog::CheckFieldForGreateTrigger(AnsiString name_field)
{
bool result=true;



return result;
}
//----------------------------------------------------------------------------
bool TFormaCreateTriggerLog::CheckTypeFieldLongString(UnicodeString name_domain)
{   //длинные строки, не сохраняются значения в таблице изменения
bool result=false;

	if (Trim(name_domain)=="DOMAIN_TEXT_1500"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_TEXT_500"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_STR_PAR"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_ZAPROS"){ result=true; }
return result;
}
//----------------------------------------------------------------------------
bool TFormaCreateTriggerLog::CheckTypeFieldBlob(UnicodeString name_domain)
{    //BLOB, не сохраняются значения в таблице изменения
bool result=false;

	if (Trim(name_domain)=="DOMAIN_IMAGE"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_IMAGE_SMALL"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_EXTMODULE_BLOB"){ result=true; }

return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaCreateTriggerLog::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
Tables->Active=false;
Fields->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateTriggerLog::ButtonAddFieldClick(TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	zapros="ALTER TABLE "+TablesTABLE_NAME->AsString;
	zapros=zapros+" ADD "+Trim(NameFieldEdit->Text)+"_"+Trim(TablesTABLE_NAME->AsString)
	+" "+NameDomainEdit->Text;
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		String V="Ошибка при добавлении поля в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}
	QueryUpdate->Close();
	
	Tables->Next();
	}



}

//---------------------------------------------------------------------------
void __fastcall TFormaCreateTriggerLog::ButtondelFieldClick(TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	zapros="ALTER TABLE "+TablesTABLE_NAME->AsString;
	zapros=zapros+" DROP "+Trim(NameFieldEdit->Text)+"_"+Trim(TablesTABLE_NAME->AsString);
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		String V="Ошибка при удалении поля из таблицы "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
		}
    QueryUpdate->Close();
	Tables->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateTriggerLog::ButtonCreateStrTableClick(TObject *Sender)
{

Tables->First();

while (!Tables->Eof)
	{
	AnsiString zapros="SELECT ID_XTABLE_BASE FROM XTABLE_BASE";
	zapros=zapros+" WHERE NAMETAB_XTABLE_BASE='";
	zapros=zapros+Trim(TablesTABLE_NAME->AsString)+"'";

	Query->Close();
	Query->SQL->Clear();
	Query->SQL->Add(zapros);
	Query->ExecQuery();
	__int64 id=Query->FieldByName("ID_XTABLE_BASE")->AsInt64;
    Query->Close();
	if (id==0)
		{//не нашли

		zapros="INSERT INTO XTABLE_BASE";
		zapros=zapros+" (NAMETAB_XTABLE_BASE) VALUES ('";
		zapros=zapros+Trim(TablesTABLE_NAME->AsString)+"')";
		try
			{
			QueryUpdate->Close();
			QueryUpdate->SQL->Clear();
			QueryUpdate->SQL->Add(zapros);
			QueryUpdate->ExecQuery();
			IBTrUpdate->Commit();
			}
		catch (Exception &exception)
			{
			IBTrUpdate->Rollback();

			String V="Ошибка при добавлении таблицы "+TablesTABLE_NAME->AsString+" "+exception.Message;
			String Z="Продолжить?";
			if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
			}
		}

	Tables->Next();
	}
}
//---------------------------------------------------------------------------

AnsiString TFormaCreateTriggerLog::GetZaprosAfterInsert(AnsiString name_table, AnsiString name_field_pk)
{
AnsiString result="";
AnsiString name_field_id_base="IDBASE_"+Trim(name_table);
AnsiString name_field_id_ext_base="IDEXT_BASE_"+Trim(name_table);
AnsiString name_field_id_ext_dataout="IDEXT_DOUT_"+Trim(name_table);

//получим тип таблицы
int type_object=GetTypeTable(name_table);

result=result+"CREATE TRIGGER ADD_LOG_"+Trim(name_table)+"_INS FOR " +Trim(name_table)+" \n" ;
result=result+"ACTIVE AFTER INSERT POSITION 32767 \n" ;
result=result+"AS \n" ;
result=result+"DECLARE VARIABLE id_xtism BIGINT ; \n";
result=result+"DECLARE VARIABLE add_in_tism char ; \n";
result=result+"DECLARE VARIABLE idext_base BIGINT ; \n";
result=result+"DECLARE VARIABLE idext_data_out BIGINT ; \n";
if (type_object==3)
	{
result=result+"DECLARE VARIABLE add_in_tism_reg char ; \n";
	}
result=result+"begin \n" ;

result=result+"  \n" ;
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=4 into :add_in_tism; \n";
result=result+"  if (add_in_tism='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование*/ \n";
result=result+"    end \n";
result=result+"  \n" ;


if (type_object==3)
	{
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=6 into :add_in_tism_reg; \n";
result=result+"  if (add_in_tism_reg='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование регистров*/ \n";
result=result+"    end \n";
result=result+"  \n" ;
	}


result=result+"   idext_base=0; \n";
result=result+"   idext_data_out=0; \n";
result=result+"if (current_user='EXTUSER') then  \n";
result=result+"     begin /*внешнее изменение*/\n";
result=result+"          idext_base=new."+Trim(name_field_id_ext_base)+"; \n";
result=result+"          idext_data_out=new."+Trim(name_field_id_ext_dataout)+"; \n";
result=result+"     end \n";





result=result+"  \n" ;
result=result+"  id_xtism=gen_id(GEN_XTISM_ID,1); \n";
result=result+"  \n" ;

result=result+"           insert into xtism (xtism.id_xtism,  \n";
result=result+"                       xtism.operation_xtism ,   /*операция 1 вставка 2 изменение 3 удаление 4 отмена 5 проведение*/    \n";
result=result+"                       xtism.type_object_xtism , /*тип объекта 1 справочник 2 документ 3 регистр*/  \n ";
result=result+"                       xtism.name_table_xtism ,  /*имя таблицы*/             \n ";
result=result+"                       xtism.name_field_id_xtism , /*имя поля первичного ключа*/  \n ";
result=result+"                       xtism.value_field_id_xtism ,/* значение первичного ключа*/  \n";
result=result+"                       xtism.idbase_xtism,         /* id базы владельца, для фильтрации */   \n";
result=result+"                       xtism.idext_base_xtism,         /* id внешней базы для квитанции */   \n";
result=result+"                       xtism.idext_dataout_xtism)         /* id_data_out для квитанции при внешнем обновлении */   \n";

result=result+"              values (:id_xtism,  \n";
result=result+"                     1, \n ";
result=result+"                    "+IntToStr(type_object)+", \n";
result=result+"                     '"+Trim(name_table)+"', \n";
result=result+"                     '"+ Trim(name_field_pk)+"', \n";
result=result+"                     new."+Trim(name_field_pk)+", \n";
result=result+"                     new." +Trim(name_field_id_base)+", \n";
result=result+"                     :idext_base, \n";
result=result+"                     :idext_data_out); \n";

result=result+"	   \n ";
//справочник
//документ


//регистр

Fields->First();
while(!Fields->Eof)
	{
	if (Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_BASE_"+Trim(name_table) ||
				   Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_DOUT_"+Trim(name_table))
		{
		Fields->Next();
		continue;
		}
		
	if (CheckFieldForGreateTrigger(Trim(FieldsRDBFIELD_NAME->AsString))==false)
		{
		Fields->Next();
		continue;
		}

	result=result+"if (not(new."+Trim(FieldsRDBFIELD_NAME->AsString)+" is null)) then  \n";
	result=result+"   insert into xtism_fields (xtism_fields.idxtism_xtism_fields,  \n";
	result=result+"                             xtism_fields.field_name_xtism_fields, \n";
	result=result+"                             xtism_fields.old_value_xtism_fields, \n";
	result=result+"                             xtism_fields.new_value_xtism_fields, \n";
	result=result+"                             xtism_fields.type_xtism_fields) \n";

	result=result+"                     values (:id_xtism,  \n";
	result=result+"                             '"+Trim(FieldsRDBFIELD_NAME->AsString)+"',\n";

	//старое значение
	result=result+"                             null, \n";


	//новое значение
	if (CheckTypeFieldLongString(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //длинная строка
		result=result+"                             null, \n";
		result=result+"                             2); \n";      //тип поля
		}
	else if(CheckTypeFieldBlob(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //BLOB поле
		result=result+"                             null, \n";
		result=result+"                             3); \n";      //тип поля
		}
	else
		{ //обычное поле
		result=result+"                             new."+Trim(FieldsRDBFIELD_NAME->AsString)+", \n";
		result=result+"                             1); \n";    //тип поля
		}

	result=result+"	   \n ";

	Fields->Next();
	}

result=result+"end \n" ;
return result;
}
//---------------------------------------------------------------------------
int TFormaCreateTriggerLog::GetTypeTable(AnsiString name_table)
{
int result=0;
Fields->First();
while(!Fields->Eof)
	{
	if (FieldsRDBFIELD_NAME->AsString=="TYPE_TBL_"+Trim(name_table))
		{
		if (FieldsRDBFIELD_SOURCE->AsString=="DOMAIN_TYPE_TBL_SPR")
			{
            result=1;
			}

		if (FieldsRDBFIELD_SOURCE->AsString=="DOMAIN_TYPE_TBL_DOC")
			{
			result=2;
			}

		if (FieldsRDBFIELD_SOURCE->AsString=="DOMAIN_TYPE_TBL_REG")
			{
			result=3;
			}
		}
	Fields->Next();
	}
return result;
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonCreateTriggerAfterInsertClick(TObject *Sender)
{
AnsiString zapros=GetZaprosAfterInsert(TablesTABLE_NAME->AsString,
										TablesFIELD_NAME->AsString);
RichEdit1->Clear();
RichEdit1->Text=zapros;
}
//---------------------------------------------------------------------------
AnsiString TFormaCreateTriggerLog::GetZaprosAfterUpdate(AnsiString name_table, AnsiString name_field_pk)
{
AnsiString result="";
AnsiString name_field_id_base="IDBASE_"+Trim(name_table);
AnsiString name_field_id_ext_base="IDEXT_BASE_"+Trim(name_table);
AnsiString name_field_id_ext_dataout="IDEXT_DOUT_"+Trim(name_table);

//получим тип таблицы
int type_object=GetTypeTable(name_table);

result=result+"CREATE TRIGGER ADD_LOG_"+Trim(name_table)+"_UPD FOR " +Trim(name_table)+" \n" ;
result=result+"ACTIVE AFTER UPDATE POSITION 32767 \n" ;
result=result+"AS \n" ;
result=result+"DECLARE VARIABLE id_xtism BIGINT ; \n";
result=result+"DECLARE VARIABLE add_in_tism char ; \n";
result=result+"DECLARE VARIABLE idext_base BIGINT ; \n";
result=result+"DECLARE VARIABLE idext_data_out BIGINT ; \n";
if (type_object==3)
	{
result=result+"DECLARE VARIABLE add_in_tism_reg char ; \n";
	}
result=result+"begin \n" ;

result=result+"  \n" ;
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=4 into :add_in_tism; \n";
result=result+"  if (add_in_tism='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование*/ \n";
result=result+"    end \n";
result=result+"  \n" ;


if (type_object==3)
	{
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=6 into :add_in_tism_reg; \n";
result=result+"  if (add_in_tism_reg='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование регистров*/ \n";
result=result+"    end \n";
result=result+"  \n" ;
	}

if (name_table=="GALLDOC" || name_table=="REM_GALLDOC"
		|| name_table=="HOT_GALLDOC" || name_table=="ZP_GALLDOC")
	{
result=result+"if (current_user='DVREGDOC_USER') then  \n";
result=result+"     begin /*не надо логгировать*/\n";
result=result+"       exit;  /*не надо логгировать*/ \n";
result=result+"     end \n";
	}


result=result+"   idext_base=0; \n";
result=result+"   idext_data_out=0; \n";
result=result+"if (current_user='EXTUSER') then  \n";
result=result+"     begin /*внешнее изменение*/\n";
result=result+"          idext_base=new."+Trim(name_field_id_ext_base)+"; \n";
result=result+"          idext_data_out=new."+Trim(name_field_id_ext_dataout)+"; \n";
result=result+"     end \n";

result=result+"  \n" ;
result=result+"  id_xtism=gen_id(GEN_XTISM_ID,1); \n";
result=result+"  \n" ;


result=result+" 	      insert into xtism (xtism.id_xtism,  \n";
result=result+"                       xtism.operation_xtism ,   /*операция 1 вставка 2 изменение 3 удаление*/    \n";
result=result+"                       xtism.type_object_xtism , /*тип объекта 1 справочник 2 документ 3 регистр*/  \n ";
result=result+"                       xtism.name_table_xtism ,  /*имя таблицы*/             \n ";
result=result+"                       xtism.name_field_id_xtism , /*имя поля первичного ключа*/  \n ";
result=result+"                       xtism.value_field_id_xtism ,/* значение первичного ключа*/  \n";
result=result+"                       xtism.idbase_xtism,         /* id базы владельца, для фильтрации */   \n";
result=result+"                       xtism.idext_base_xtism,         /* id внешней базы для квитанции */   \n";
result=result+"                       xtism.idext_dataout_xtism)         /* id_data_out для квитанции при внешнем обновлении */   \n";
result=result+"              values (:id_xtism,  \n";
result=result+"                     2, \n ";
result=result+"                    "+IntToStr(type_object)+", \n";
result=result+"                     '"+Trim(name_table)+"', \n";
result=result+"                     '"+ Trim(name_field_pk)+"', \n";
result=result+"                     old."+Trim(name_field_pk)+", \n";
result=result+"                     new." +Trim(name_field_id_base)+", \n";
result=result+"                     :idext_base, \n";
result=result+"                     :idext_data_out); \n";
//справочник
//документ


//регистр
result=result+"  \n" ;
result=result+"  \n" ;
Fields->First();
while(!Fields->Eof)
	{
	if (Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_BASE_"+Trim(name_table) ||
				   Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_DOUT_"+Trim(name_table))
		{
		Fields->Next();
		continue;
		}

	if (CheckFieldForGreateTrigger(Trim(FieldsRDBFIELD_NAME->AsString))==false)
		{
		Fields->Next();
		continue;
		}

	result=result+"if ((old."+Trim(FieldsRDBFIELD_NAME->AsString)+" is null and new."+Trim(FieldsRDBFIELD_NAME->AsString)+" is not null) or  \n";
	result=result+"  (new."+Trim(FieldsRDBFIELD_NAME->AsString)+" is null and old."+Trim(FieldsRDBFIELD_NAME->AsString)+" is not null) or  \n";
	result=result+"  (new."+Trim(FieldsRDBFIELD_NAME->AsString)+" is not null and old."+Trim(FieldsRDBFIELD_NAME->AsString)+" is not null and  \n";
	result=result+"   new."+Trim(FieldsRDBFIELD_NAME->AsString)+" <> old."+Trim(FieldsRDBFIELD_NAME->AsString)+" )) then  \n";

	result=result+"   insert into xtism_fields (xtism_fields.idxtism_xtism_fields,  \n";
	result=result+"                             xtism_fields.field_name_xtism_fields, \n";
	result=result+"                             xtism_fields.old_value_xtism_fields, \n";
	result=result+"                             xtism_fields.new_value_xtism_fields, \n";
	result=result+"                             xtism_fields.type_xtism_fields) \n";
	result=result+"                     values (:id_xtism,  \n";
	result=result+"                             '"+Trim(FieldsRDBFIELD_NAME->AsString)+"',\n";

	//старое значение
	if (CheckTypeFieldLongString(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //длинная строка
		result=result+"                             null, \n";
		}
	else if(CheckTypeFieldBlob(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //BLOB поле
        result=result+"                             null, \n";
		}
	else
		{ //обычное поле
		result=result+"                             old."+Trim(FieldsRDBFIELD_NAME->AsString)+", \n";
		}

	//новое поле
	if (CheckTypeFieldLongString(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //длинная строка
		result=result+"                             null, \n";
		result=result+"                             2); \n";
		}
	else if(CheckTypeFieldBlob(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //BLOB поле
		result=result+"                             null, \n";
		result=result+"                             3); \n";
		}
	else
		{ //обычное поле
		result=result+"                             new."+Trim(FieldsRDBFIELD_NAME->AsString)+", \n";
		result=result+"                             1); \n";
		}



	result=result+"	   \n ";

	Fields->Next();
	}

result=result+"end \n" ;
return result;


}
//------------------------------------------------------------------------------
AnsiString TFormaCreateTriggerLog::GetZaprosAfterDelete(AnsiString name_table, AnsiString name_field_pk)
{
AnsiString result="";
AnsiString name_field_id_base="IDBASE_"+Trim(name_table);
AnsiString name_field_id_ext_base="IDEXT_BASE_"+Trim(name_table);
AnsiString name_field_id_ext_dataout="IDEXT_DOUT_"+Trim(name_table);

//получим тип таблицы
int type_object=GetTypeTable(name_table);

result=result+"CREATE TRIGGER ADD_LOG_"+Trim(name_table)+"_DEL FOR " +Trim(name_table)+" \n" ;
result=result+"ACTIVE AFTER DELETE POSITION 32767 \n" ;
result=result+"AS \n" ;
result=result+"DECLARE VARIABLE id_xtism BIGINT ; \n";
result=result+"DECLARE VARIABLE add_in_tism char ; \n";
if (type_object==3)
	{
result=result+"DECLARE VARIABLE add_in_tism_reg char ; \n";
	}
result=result+"begin \n" ;

result=result+"  \n" ;
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=4 into :add_in_tism; \n";
result=result+"  if (add_in_tism='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование*/ \n";
result=result+"    end \n";
result=result+"  \n" ;


if (type_object==3)
	{
result=result+"  select VALUE_SETUP from SETUP where ID_SETUP=6 into :add_in_tism_reg; \n";
result=result+"  if (add_in_tism_reg='1') then   \n";
result=result+"     begin \n";
result=result+"     end \n";
result=result+"  else\n";
result=result+"    begin \n";
result=result+"       exit;  /*не включено логгирование регистров*/ \n";
result=result+"    end \n";
result=result+"  \n" ;
	}

result=result+"  \n" ;
result=result+"  id_xtism=gen_id(GEN_XTISM_ID,1); \n";
result=result+"  \n" ;



result=result+" 	      insert into xtism (xtism.id_xtism,  \n";
result=result+"                       xtism.operation_xtism ,   /*операция 1 вставка 2 изменение 3 удаление*/    \n";
result=result+"                       xtism.type_object_xtism , /*тип объекта 1 справочник 2 документ 3 регистр*/  \n ";
result=result+"                       xtism.name_table_xtism ,  /*имя таблицы*/             \n ";
result=result+"                       xtism.name_field_id_xtism , /*имя поля первичного ключа*/  \n ";
result=result+"                       xtism.value_field_id_xtism ,/* значение первичного ключа*/  \n";
result=result+"                       xtism.idbase_xtism)         /* id базы владельца, для фильтрации */   \n";

result=result+"              values (:id_xtism,  \n";
result=result+"                     3, \n ";
result=result+"                    "+IntToStr(type_object)+", \n";
result=result+"                     '"+Trim(name_table)+"', \n";
result=result+"                     '"+ Trim(name_field_pk)+"', \n";
result=result+"                     old."+Trim(name_field_pk)+", \n";
result=result+"                     old." +Trim(name_field_id_base)+"); \n";

//справочник
//документ


//регистр
result=result+"  \n" ;
Fields->First();
while(!Fields->Eof)
	{
	if (Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_BASE_"+Trim(name_table) ||
				   Trim(FieldsRDBFIELD_NAME->AsString)=="IDEXT_DOUT_"+Trim(name_table))
		{
		Fields->Next();
		continue;
		}

	if (CheckFieldForGreateTrigger(Trim(FieldsRDBFIELD_NAME->AsString))==false)
		{
		Fields->Next();
		continue;
		}
		
	result=result+"if (not(old."+Trim(FieldsRDBFIELD_NAME->AsString)+" is null )) then  \n";
	result=result+"   insert into xtism_fields (xtism_fields.idxtism_xtism_fields,  \n";
	result=result+"                             xtism_fields.field_name_xtism_fields, \n";
	result=result+"                             xtism_fields.old_value_xtism_fields, \n";
	result=result+"                             xtism_fields.new_value_xtism_fields, \n";
	result=result+"                             xtism_fields.type_xtism_fields) \n";
	result=result+"                     values (:id_xtism,  \n";
	result=result+"                             '"+Trim(FieldsRDBFIELD_NAME->AsString)+"',\n";

	//старое поле
	if (CheckTypeFieldLongString(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //длинная строка
		result=result+"                             null, \n";
		result=result+"                             null, \n";
		result=result+"                             2); \n";
		}
	else if(CheckTypeFieldBlob(Trim(FieldsRDBFIELD_SOURCE->AsString))==true)
		{ //BLOB поле
		result=result+"                             null, \n";
		result=result+"                             null, \n";
		result=result+"                             3); \n";
		}
	else
		{ //обычное поле
		result=result+"                             old."+Trim(FieldsRDBFIELD_NAME->AsString)+", \n";
		result=result+"                             null, \n";
		result=result+"                             1); \n";
		}




	result=result+"	   \n ";

	Fields->Next();
	}

result=result+"end \n" ;
return result;


}
//-----------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonCreateTriggerAfterUpdateClick(TObject *Sender)
{
AnsiString zapros=GetZaprosAfterUpdate(TablesTABLE_NAME->AsString,
										TablesFIELD_NAME->AsString);
RichEdit1->Clear();
RichEdit1->Text=zapros;
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonCreatetriggerAfterDeleteClick(TObject *Sender)
{
AnsiString zapros=GetZaprosAfterDelete(TablesTABLE_NAME->AsString,
										TablesFIELD_NAME->AsString);
RichEdit1->Clear();
RichEdit1->Text=zapros;
}
//---------------------------------------------------------------------------


void __fastcall TFormaCreateTriggerLog::ButtonCreateALLTriggerAfterInsertClick(
	  TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros=GetZaprosAfterInsert(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);

	try
		{
	   //	IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
		//IBTrUpdate->Commit();
//		QueryUpdate->Active=false;
//		QueryUpdate->SQL->Clear();
//		QueryUpdate->SQL->Add(zapros);
//		QueryUpdate->ExecSQL();

		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}

	Tables->Next();
	}
ShowMessage("Триггеры логгирования вставки вставлены!");
//IBTrUpdate->Commit();
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonDeleteALLTriggerAfterInsertClick(
	  TObject *Sender)
{
AnsiString zapros="";

Tables->First();

while (!Tables->Eof)
	{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}
	zapros="DROP TRIGGER ADD_LOG_"+Trim(TablesTABLE_NAME->AsString)+"_INS ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		String V="Ошибка при удаления триггера вставки из "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
		}

	Tables->Next();
	}

ShowMessage("Триггеры логгирования вставки удалены!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonCreateALLTriggerAfterUpdateClick(
	  TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros=GetZaprosAfterUpdate(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);

	try
		{
		//IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
	  //	IBTrUpdate->Commit();
//		QueryUpdate->Active=false;
//		QueryUpdate->SQL->Clear();
//		QueryUpdate->SQL->Add(zapros);
//		QueryUpdate->ExecSQL();

		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}

	Tables->Next();
	}
ShowMessage("Триггеры логгирования изменений вставлены!");
//IBTrUpdate->Commit();
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonDeleteALLTriggerAfterUpdateClick(
      TObject *Sender)
{
AnsiString zapros="";

Tables->First();

while (!Tables->Eof)
	{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros="DROP TRIGGER ADD_LOG_"+Trim(TablesTABLE_NAME->AsString)+"_UPD ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		String V="Ошибка при удаления триггера изменения из "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
		}

	Tables->Next();
	}

ShowMessage("Триггеры логгирования изменений удалены!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonCreateAllTriggerAfterDeleteClick(
      TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{

	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}
	
	zapros=GetZaprosAfterDelete(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);

	try
		{
		//IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
		//IBTrUpdate->Commit();
//		QueryUpdate->Active=false;
//		QueryUpdate->SQL->Clear();
//		QueryUpdate->SQL->Add(zapros);
//		QueryUpdate->ExecSQL();

		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}

	Tables->Next();
	}
ShowMessage("Триггеры логгирования удалений вставлены!");
//IBTrUpdate->Commit();
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonDeleteTriggerAfterDeleteClick(TObject *Sender)
{
AnsiString zapros="";

Tables->First();

while (!Tables->Eof)
	{

	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros="DROP TRIGGER ADD_LOG_"+Trim(TablesTABLE_NAME->AsString)+"_DEL ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		String V="Ошибка при удаления триггера удаления из "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
		}

	Tables->Next();
	}

ShowMessage("Триггеры логгирования удалений удалены!");
}
//---------------------------------------------------------------------------


void __fastcall TFormaCreateTriggerLog::TablesCalcFields(TDataSet *DataSet)
{
TablesRECNO->AsInteger=Tables->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button4Click(TObject *Sender)
{
AnsiString zapros="";


zapros="DROP TRIGGER ADD_LOG_"+Trim(TableNameEdit->Text)+"_INS ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		ShowMessage("Выполнено!");
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		ShowMessage("Ошибка при удаления триггера вставки из "+TableNameEdit->Text+" "+exception.Message);

		}



}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button2Click(TObject *Sender)
{
AnsiString zapros="";


	zapros="DROP TRIGGER ADD_LOG_"+Trim(TableNameEdit->Text)+"_UPD ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		ShowMessage("Выполнено!");
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		ShowMessage("Ошибка при удаления триггера изменения из "+TableNameEdit->Text+" "+exception.Message);
		}



}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button3Click(TObject *Sender)
{
AnsiString zapros="";


	zapros="DROP TRIGGER ADD_LOG_"+Trim(TableNameEdit->Text)+"_DEL ";
	try
		{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);
		QueryUpdate->ExecQuery();
		IBTrUpdate->Commit();
		ShowMessage("Выполнено!");
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();

		ShowMessage("Ошибка при удаления триггера удаления из "+TableNameEdit->Text+" "+exception.Message);

		}



}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button1Click(TObject *Sender)
{

Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	if (Trim(TableNameEdit->Text)==Trim(TablesTABLE_NAME->AsString))
		{

	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros=GetZaprosAfterInsert(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);

	try
		{
	   //	IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
		ShowMessage("Триггеры логгирования вставки вставлены!");

		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}
		}
	Tables->Next();


	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button5Click(TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	if (Trim(TableNameEdit->Text)==Trim(TablesTABLE_NAME->AsString))
		{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}

	zapros=GetZaprosAfterUpdate(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);
    RichEdit1->Clear();
	RichEdit1->Text=zapros;
	try
		{
		//IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
		ShowMessage("Триггеры логгирования изменений вставлены!");
		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}

		}
		}
	Tables->Next();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::Button6Click(TObject *Sender)
{
Tables->First();
AnsiString zapros="";

while (!Tables->Eof)
	{
	if (Trim(TableNameEdit->Text)==Trim(TablesTABLE_NAME->AsString))
		{
	if (CheckTableForGreateTrigger(TablesTABLE_NAME->AsString)==false){Tables->Next(); continue;}
	
	zapros=GetZaprosAfterDelete(TablesTABLE_NAME->AsString, TablesFIELD_NAME->AsString);

	try
		{
		//IBTrUpdate->StartTransaction();
		IBScript1->Script->Clear();
		IBScript1->Script->Add(zapros);
		IBScript1->ExecuteScript();
		ShowMessage("Триггеры логгирования удалений вставлены!");

		}
	catch (Exception &exception)
		{
		IBTrUpdate->Rollback();
		RichEdit1->Clear();
		RichEdit1->Text=zapros;
		String V="Ошибка при добавлении триггера в таблицу "+TablesTABLE_NAME->AsString+" "+exception.Message;
		String Z="Продолжить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				return;
				}
		}
		}

	Tables->Next();
	}


}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonClearClick(TObject *Sender)
{
AnsiString zapros="";
zapros="DELETE FROM XFIELD_BASE";
QueryUpdate->Close();
QueryUpdate->SQL->Clear();
QueryUpdate->SQL->Add(zapros);
QueryUpdate->ExecQuery();
IBTrUpdate->Commit();

zapros="DELETE FROM XTABLE_BASE";
QueryUpdate->Close();
QueryUpdate->SQL->Clear();
QueryUpdate->SQL->Add(zapros);
QueryUpdate->ExecQuery();
IBTrUpdate->Commit();
ShowMessage("Выполнено!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateTriggerLog::ButtonSetGenMaxValueClick(TObject *Sender)

{

UnicodeString V="Внимание! Установка значений генераторов может повредить информационную базу! Продолжить? ";
UnicodeString Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}

AnsiString zapros="";
//получим ID базы
int id_base=0;

zapros="select setup.value_setup from setup where setup.id_setup=3";


Query->Close();
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ExecQuery();
id_base=Query->FieldByName("value_setup")->AsInt64;
Query->Close();

V="Внимание! Проверяются значения генераторов для базы ID = "+IntToStr(id_base)+" ! Продолжить? ";
Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}


Tables->First();


while (!Tables->Eof)
	{
	//получим макс. значение
	if (id_base==1)
		{
		zapros="select max("+TablesTABLE_NAME->AsString+"."+TablesFIELD_NAME->AsString+") from "+TablesTABLE_NAME->AsString;
		zapros=zapros+" where "+TablesTABLE_NAME->AsString+"."+TablesFIELD_NAME->AsString;
		zapros=zapros+" < "+IntToStr(id_base)+"00000000000000";
		}

	if (id_base > 1)
		{
		zapros="select max("+TablesTABLE_NAME->AsString+"."+TablesFIELD_NAME->AsString+") from "+TablesTABLE_NAME->AsString;
		zapros=zapros+" where "+TablesTABLE_NAME->AsString+"."+TablesFIELD_NAME->AsString;
		zapros=zapros+" > "+IntToStr(id_base)+"00000000000000";
		zapros=zapros+" and "+TablesTABLE_NAME->AsString+"."+TablesFIELD_NAME->AsString;
		zapros=zapros+" < "+IntToStr(id_base+1)+"00000000000000";
		}

		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add(zapros);
		Query->ExecQuery();
		__int64 value_gen=0;
		if(Query->FieldByName("MAX")->AsString=="")
			{

			}
		else
			{
			value_gen=Query->FieldByName("MAX")->AsInt64;
			}
	   Query->Close();

	if (value_gen > 0)
		{
		zapros="SET GENERATOR GEN_"+TablesTABLE_NAME->AsString+"_ID TO "+IntToStr(value_gen);

		try
			{
			QueryUpdate->Close();
			QueryUpdate->SQL->Clear();
			QueryUpdate->SQL->Add(zapros);
			QueryUpdate->ExecQuery();
			IBTrUpdate->Commit();
			}
		catch (Exception &exception)
			{
			IBTrUpdate->Rollback();
			String V="Ошибка при установке генератора таблицы "+TablesTABLE_NAME->AsString+" "+exception.Message;
			String Z="Продолжить?";
			if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				QueryUpdate->Close();
				return;
				}

			}
		QueryUpdate->Close();
		}
	Tables->Next();
	}

ShowMessage("Выполнено! Дополнительно необходимо установить значения генераторов кодов элементов вручную");
}
//---------------------------------------------------------------------------

