//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaAddDataInNewBase.h"
#include "UDataModuleMain.h"
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxLookupEdit"
#pragma link "cxMaskEdit"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCalc"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaAddDataInNewBase::TFormaAddDataInNewBase(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaAddDataInNewBase::FormCreate(TObject *Sender)
{
BaseList->Active=true;
NameServercxTextEdit->Text="localhost";
FilecxTextEdit->Text="K:\\Base.fdb";
NameUsercxTextEdit->Text="SYSDBA";
PasswordUsercxTextEdit->Text="masterkey";
}
//---------------------------------------------------------------------------
void __fastcall TFormaAddDataInNewBase::FormClose(TObject *Sender,
      TCloseAction &Action)
{
BaseList->Active=false;
XSetupObmen->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
int TFormaAddDataInNewBase::CheckTypeTable(void)
{
int result=0;

Fields->First();

while(!Fields->Eof)
	{
	if (FieldsRDBFIELD_NAME->AsString=="TYPE_TBL_"+Trim(TablesTABLE_NAME->AsString))
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
//----------------------------------------------------------------------------
bool TFormaAddDataInNewBase::CheckTableForOutput(UnicodeString name_table)
{  //таблицы, которые не логгируются  и не выгружаются
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
	if (Trim(name_table)=="SARM"){result=false;}
	if (Trim(name_table)=="SARM_PAR"){result=false;}
	if (Trim(name_table)=="SOBORUD"){result=false;}
	if (Trim(name_table)=="SOBORUD_PAR"){result=false;}

return result;
}

//----------------------------------------------------------------------------
bool TFormaAddDataInNewBase::CheckTypeFieldLongString(UnicodeString name_domain)
{   //длинные строки, не сохраняются значения в таблице изменения
bool result=false;

	if (Trim(name_domain)=="DOMAIN_TEXT_1500"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_TEXT_500"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_STR_PAR"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_ZAPROS"){ result=true; }
return result;
}
//----------------------------------------------------------------------------
bool TFormaAddDataInNewBase::CheckTypeFieldBlob(UnicodeString name_domain)
{    //BLOB, не сохраняются значения в таблице изменения
bool result=false;

	if (Trim(name_domain)=="DOMAIN_IMAGE"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_IMAGE_SMALL"){ result=true; }
	if (Trim(name_domain)=="DOMAIN_EXTMODULE_BLOB"){ result=true; }

return result;
}
//----------------------------------------------------------------------------
bool TFormaAddDataInNewBase::CheckRecordForOutput(AnsiString name_table)
{
bool result=true;

if (name_table=="SPRICE")
        {
        //надо проверить а нужно ли выгружать указанный тип цен
		TableTypePrice->First();
		result=false;
		while (!TableTypePrice->Eof)
                {
				if (Query->FieldByName("IDTYPE_PRICE")->AsInt64==
						TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN->AsInt64)
						{
						result=true;
						break;
                        }
				TableTypePrice->Next();
				}
		}

return result;
}
//-----------------------------------------------------------------------------
bool TFormaAddDataInNewBase::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;

//не выгружаем поля IDEXT_BASE и IDEXT_DOUT
if(name_field=="IDEXT_BASE_"+Trim(name_table)) return result;
if(name_field=="IDEXT_DOUT_"+Trim(name_table)) return result;
if(name_field=="TYPE_TBL_"+Trim(name_table)) return result;


if (name_field=="PRDOC") return result;
if (name_field=="FL_CHANGE_NOM") return result;//  не надо выгружать флаг изменения цен


if (XSetupObmenOUTZPRICE_XSETUP_OBMEN->AsInteger==1)
	//Справочник партии
	{  //выгружаем закупочные цены
	}
else
	{//фильтрация по закупочным ценам
	if (name_field=="PRICEZPART") return result;
	}


if (name_field=="KOLPRODNOM") return result;
if (name_field=="IDEDPRODNOM") return result;
if (name_field=="IDMPRIGNOM") return result;


result=true;
return result;

}

//----------------------------------------------------------------------
bool TFormaAddDataInNewBase::AddDataAllSpr(__int64 id_base)
{
bool result=false;
IdBaseForObmen=id_base;
if (IdBaseForObmen==0)
	{
	TextError="Не задан идентификатор базы для обмена!";
	return result;
	}

TableBaseForObmen->Active=false;
TableBaseForObmen->ParamByName("PARAM_IDBASE_FOR_OBMEN")->AsInt64=id_base;
TableBaseForObmen->Active=true;


TableTypePrice->Active=false;
TableTypePrice->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableTypePrice->Active=true;

//настройки обмена
XSetupObmen->Active=false;
XSetupObmen->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
XSetupObmen->Active=true;

//подключение к новой базе

try
		{
		NewDataBase->Connected=false;
		NewDataBase->DBName=NameServercxTextEdit->Text+":"
							+FilecxTextEdit->Text;
		NewDataBase->DBParams->Clear();
		NewDataBase->DBParams->Add(" user_name="+NameUsercxTextEdit->Text);
		NewDataBase->DBParams->Add(" lc_ctype=UTF8");
		NewDataBase->DBParams->Add(" password="+PasswordUsercxTextEdit->Text);
		NewDataBase->Connected=true;
		}
catch (Exception &exception)
		{
		SaveProtocol("Ошибка при подключении к новой базе:"+exception.Message);
		NewDataBase->Connected=false;
		return result;
		}

if(DeleteConstraints()==false)
	{
	return result;
	}

DeleteNachData();


if (SetValuesGenerator()==false)
	{
	return result;
	}

if (SetValuesGeneratorCodeElement()==false)
	{
	return result;
	}

if (SetPrefiksInfBase (id_base)==false)
	{
	return result;
	}

OtklLoggir();
NumRecord=1;


Tables->Active=true;
Fields->Active=true;

Tables->First();
while (!Tables->Eof)
	{
    int type_table=CheckTypeTable();

	if (type_table==1) //Справочник
		{
		OutputTable(Trim(TablesTABLE_NAME->AsString));
		}

	if (type_table==2)  //Документ
		{
		if (MoveDoccxCheckBox->Checked==true)
			{
			OutputDoc(Trim(TablesTABLE_NAME->AsString));
			}
        }
	Tables->Next();
	}


SaveProtocol("Данные перенесены! Не забудьте вставить ограничения новой базы! \
				Для этого обновите структуру новой базы с помощью DatabaseComparer!");

//удалим логгирование какое есть
RunQueryDelete("XTISM_FIELDS");
RunQueryDelete("XTISM");

VklLoggir();
NewDataBase->Connected=false;

TableBaseForObmen->Active=false;
XSetupObmen->Active=false;
TableTypePrice->Active=false;
result=true;
return result;



}
//----------------------------------------------------------------------
void TFormaAddDataInNewBase::OutputTable(AnsiString table_name)
{
SaveProtocol("Выгружаем справочник "+table_name);

//предварительно очистим таблицу
RunQueryDelete(table_name);


UnicodeString zapros="select * from "+table_name;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(zapros);

		try
				{
				Query->ExecQuery();
				}
		catch (Exception &exception)
				{
				SaveProtocol("Ошибка при открытии таблицы справочника \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя таблицы:"+table_name);
				}

int kol_rec=0;

while(!Query->Eof)
		{

		if (CheckRecordForOutput(table_name)==false)      //проверим нужно ли выгружать
                {                                         //текущую запись
				Query->Next();
				continue;
                }

		UnicodeString fields="";
		UnicodeString values="";

		Fields->First();
		while(!Fields->Eof)
			{
			UnicodeString name_field=Trim(FieldsRDBFIELD_NAME->AsString);
			UnicodeString value_field=Trim(Query->FieldByName(name_field)->AsString);

			//проверим надо ли выгружать поле
			if (CheckFieldForOutput(name_field, table_name)==false)
				{
				Fields->Next();
				continue;
				}

			//формируем запрос вставки
			//надо учитывать тип поля
			UnicodeString domain_field=Trim(FieldsRDBFIELD_SOURCE->AsString);
			if (CheckTypeFieldLongString(domain_field)==true)
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
			else if (CheckTypeFieldBlob(domain_field)==true)
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
			else
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
            Fields->Next();
			}

		zapros="insert into "+table_name+" ("+fields+")";
		zapros=zapros+" values ("+values+")";


		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);

		//заполняем значения параметров
		Fields->First();
		while(!Fields->Eof)
			{
			UnicodeString name_field=Trim(FieldsRDBFIELD_NAME->AsString);

			//проверим надо ли выгружать поле
			if (CheckFieldForOutput(name_field, table_name)==false)
				{
				Fields->Next();
				continue;
				}

			//надо учитывать тип поля
			UnicodeString domain_field=Trim(FieldsRDBFIELD_SOURCE->AsString);
			if (CheckTypeFieldLongString(domain_field)==true)
				{
				QueryUpdate->ParamByName("PARAM_"+name_field)->AsString=
									Trim(Query->FieldByName(name_field)->AsString);
				}
			else if (CheckTypeFieldBlob(domain_field)==true)
				{
					//считаем в stream и загрузим из stream
				TMemoryStream *m=new TMemoryStream();
				Query->FieldByName(name_field)->SaveToStream(m);
                QueryUpdate->ParamByName("PARAM_"+name_field)->LoadFromStream(m);
				delete m;
				}
			else
				{
				QueryUpdate->ParamByName("PARAM_"+name_field)->AsString=
									Trim(Query->FieldByName(name_field)->AsString);
				}
			Fields->Next();
			}



		//добавляем запись в новую базу


			try
				{
				QueryUpdate->ExecQuery();
				pFIBTrUpdate->Commit();
				}

			catch (Exception &exception)
				{
				SaveProtocol("Ошибка при вставке записи \n"
						+exception.Message+"  \n Запрос:"+zapros);
				pFIBTrUpdate->Rollback();
				}

			
		QueryUpdate->Close();

		Query->Next();
		kol_rec++;
		}

SaveProtocol("Обновлено записей - "+IntToStr(kol_rec));
Query->Close();


}
//----------------------------------------------------------------------
void TFormaAddDataInNewBase::OutputDoc(AnsiString table_name)
{
SaveProtocol("Выгружаем документ "+table_name);

//предварительно очистим таблицу
RunQueryDelete(table_name);


UnicodeString zapros="select * from "+table_name;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(zapros);

		try
				{
				Query->ExecQuery();
				}
		catch (Exception &exception)
				{
				SaveProtocol("Ошибка при открытии таблицы документа \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя таблицы:"+table_name);
				}

int kol_rec=0;

while(!Query->Eof)
		{

		if (CheckRecordForOutput(table_name)==false)      //проверим нужно ли выгружать
                {                                         //текущую запись
				Query->Next();
				continue;
				}


		//надо проверить поле по базе
		UnicodeString name_field_base="IDBASE_"+table_name;
		UnicodeString value_field_base=Trim(Query->FieldByName(name_field_base)->AsString);
		__int64 id_base=0;
		if (Trim(value_field_base)!="")
			{
			id_base=StrToInt64(value_field_base);
			}

		bool fl_output=false;

		if (id_base !=0)
			{
			TableBaseForObmen->First();
			while(!TableBaseForObmen->Eof)
				{
				if(id_base==TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN->AsInt64)
					{
					fl_output=true;
					break;
					}
				TableBaseForObmen->Next();
				}
			}

		if (fl_output==false)
			{
			Query->Next();
			continue;
			}
        //конец проверки по базе


		UnicodeString fields="";
		UnicodeString values="";

		Fields->First();
		while(!Fields->Eof)
			{
			UnicodeString name_field=Trim(FieldsRDBFIELD_NAME->AsString);
			UnicodeString value_field=Trim(Query->FieldByName(name_field)->AsString);

			//проверим надо ли выгружать поле
			if (CheckFieldForOutput(name_field, table_name)==false)
				{
				Fields->Next();
				continue;
				}

			//формируем запрос вставки
			//надо учитывать тип поля
			UnicodeString domain_field=Trim(FieldsRDBFIELD_SOURCE->AsString);
			if (CheckTypeFieldLongString(domain_field)==true)
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
			else if (CheckTypeFieldBlob(domain_field)==true)
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
			else
				{
				if (fields=="")
					{
					fields=name_field;
					values=":PARAM_"+name_field;
					}
				else
					{
					fields=fields+", "+name_field;
					values=values+",:PARAM_"+name_field;
					}
				}
            Fields->Next();
			}

		zapros="insert into "+table_name+" ("+fields+")";
		zapros=zapros+" values ("+values+")";


		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(zapros);

		//заполняем значения параметров
		Fields->First();
		while(!Fields->Eof)
			{
			UnicodeString name_field=Trim(FieldsRDBFIELD_NAME->AsString);

			//проверим надо ли выгружать поле
			if (CheckFieldForOutput(name_field, table_name)==false)
				{
				Fields->Next();
				continue;
				}

			//надо учитывать тип поля
			UnicodeString domain_field=Trim(FieldsRDBFIELD_SOURCE->AsString);
			if (CheckTypeFieldLongString(domain_field)==true)
				{
				QueryUpdate->ParamByName("PARAM_"+name_field)->AsString=
									Trim(Query->FieldByName(name_field)->AsString);
				}
			else if (CheckTypeFieldBlob(domain_field)==true)
				{
					//считаем в stream и загрузим из stream
				TMemoryStream *m=new TMemoryStream();
				Query->FieldByName(name_field)->SaveToStream(m);
                QueryUpdate->ParamByName("PARAM_"+name_field)->LoadFromStream(m);
				delete m;
				}
			else
				{
				QueryUpdate->ParamByName("PARAM_"+name_field)->AsString=
									Trim(Query->FieldByName(name_field)->AsString);
				//SaveProtocol("Параметр - "+name_field);
				//SaveProtocol("значение - "+Trim(Query->FieldByName(name_field)->AsString));
				}
			Fields->Next();
			}

		//добавляем запись в новую базу

			//SaveProtocol("запрос - "+zapros);
			try
				{
				QueryUpdate->ExecQuery();
				pFIBTrUpdate->Commit();
				}

			catch (Exception &exception)
				{
				SaveProtocol("Ошибка при вставке записи \n"
						+exception.Message+"  \n Запрос:"+zapros);
				pFIBTrUpdate->Rollback();
				}


		QueryUpdate->Close();

		Query->Next();
		kol_rec++;
		}

SaveProtocol("Обновлено записей - "+IntToStr(kol_rec));
Query->Close();


}
//----------------------------------------------------------------------
void TFormaAddDataInNewBase::SaveProtocol(AnsiString s)
{

Memo1->Lines->Add(s);

AnsiString FileNameProtocol=ExtractFileDir(Application->ExeName)+"\\Log\\"+ DateToStr(Date())+".txt";

s=TimeToStr(Time())+"  "+s+"\n";

const char *fileName=FileNameProtocol.c_str();
ofstream outfile(fileName, ios::out | ios::app);

if (!outfile)
		{
		 return;
		}

outfile<<s.c_str();
outfile.close();

}
//-----------------------------------------------------------------------
void __fastcall TFormaAddDataInNewBase::cxButtonAddDataClick(TObject *Sender)
{

BaseList->First();
BaseList->MoveBy(NameBasecxLookupComboBox->ItemIndex);

AddDataAllSpr(BaseListID_SINFBASE_OBMEN->AsInt64);
}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::SetValuesGenerator(void)
{
bool result=true;
SaveProtocol("Устанавливаем значения генераторов");
BaseList->First();
BaseList->MoveBy(NameBasecxLookupComboBox->ItemIndex);
__int64 id_base=BaseListID_SINFBASE_OBMEN->AsInt64;

if (id_base > 999)
	{
    SaveProtocol("ID Базы превышает 999. Обмен с такой базой невозможен!");
	return result;
	}
	
	TableGenerators->Active=true;
	TableGenerators->First();

	while(!TableGenerators->Eof)
		{
		AnsiString name_generator=Trim(TableGenerators->FieldByName("RDB$GENERATOR_NAME")->AsString);
		if ( name_generator=="GEN_SDISCOUNT_CARD_CODE" ||
					name_generator=="GEN_SED_CODE"     ||
					name_generator=="GEN_SNOM_CODE"	)
			{
				TableGenerators->Next();
				continue;
			}

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR "+name_generator
						+" TO "+IntToStr(id_base)+"00000000000000");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			}
		catch (Exception &exception)
				{
				pFIBTrUpdate->Rollback();
				result=false;
				SaveProtocol("Ошибка установки генераторов! "+exception.Message);
				}
		QueryUpdate->Close();
		TableGenerators->Next();
		}

	TableGenerators->Active=false;

SaveProtocol("Завершена процедура установки генераторов");
return result;
}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::SetValuesGeneratorCodeElement(void)
{
bool result=true;


//НОМЕНКЛАТУРА
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SNOM_CODE TO "+CodeNom1cxCalcEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение генератора кода номенклатуры!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP= "+CodeNom2cxCalcEdit->Text);
		QueryUpdate->SQL->Add(" where ID_SETUP=201");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение верхней границы кода номенклатуры!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки верхней границы кода номенклатуры! "+exception.Message);
				}
	QueryUpdate->Close();

//ЕДИНИЦЫ
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SED_CODE TO "+CodeEd1cxCalcEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение генератора кода единицы!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP= "+CodeEd2cxCalcEdit->Text);
		QueryUpdate->SQL->Add(" where ID_SETUP=202");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение верхней границы кода единицы номенклатуры!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки верхней границы кода единицы номенклатуры! "+exception.Message);
				}
	QueryUpdate->Close();

//ДИСКОНТНЫЕ КАРТЫ

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SDISCOUNT_CARD_CODE TO "+CodeCard1cxCalcEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение генератора кода диск. карты!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP= "+CodeCard2cxCalcEdit->Text);
		QueryUpdate->SQL->Add(" where ID_SETUP=203");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено значение верхней границы кода диск. карты!");
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки верхней границы кода диск. карты! "+exception.Message);
				}
	QueryUpdate->Close();


return result;
}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::SetPrefiksInfBase (__int64 id_base)
{
bool result=false;
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP= "+IntToStr(id_base));
		QueryUpdate->SQL->Add(" where ID_SETUP=3");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Установлено ID базы!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка установки ID базы! "+exception.Message);
				}
	QueryUpdate->Close();
return result;
}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::OtklLoggir(void)
{
bool result=false;
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP=null");
		QueryUpdate->SQL->Add(" where ID_SETUP=4");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("ОТКЛЮЧЕНО ЛОГГИРОВАНИЕ!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка при отключении логгирования! "+exception.Message);
				}
	QueryUpdate->Close();

return result;
}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::VklLoggir(void)
{
bool result=false;
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP=1 ");
		QueryUpdate->SQL->Add(" where ID_SETUP=4");
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("ВКЛЮЧЕНО ЛОГГИРОВАНИЕ!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка при ВКЛЮЧЕНИИ ЛОГГИРОВАНИЯ! "+exception.Message);
				}
	QueryUpdate->Close();

return result;


}
//---------------------------------------------------------------------------
bool TFormaAddDataInNewBase::DeleteConstraints(void)
{
bool result=true;
SaveProtocol("Начало удаления ограничений базы");

TableConstraints->Active=false;
TableConstraints->Active=true;
TableConstraints->First();

while(!TableConstraints->Eof)
	{
	QueryUpdate->Close();


		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" ALTER TABLE "+TableConstraints->FieldByName("TABLE_NAME")->AsString);
		QueryUpdate->SQL->Add(" DROP CONSTRAINT "+TableConstraints->FieldByName("CONST_NAME")->AsString);
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка при удалении ограничения! "+
				TableConstraints->FieldByName("CONST_NAME")->AsString+"  "+exception.Message);
				}
	QueryUpdate->Close();


	TableConstraints->Next();
	}
	
TableConstraints->Active=false;
SaveProtocol("Конец удаления ограничений базы");
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaAddDataInNewBase::cxButtonViborFileClick(TObject *Sender)
{
if(OpenDialog1->Execute())
		{
		FilecxTextEdit->Text=OpenDialog1->FileName;
		}
}
//---------------------------------------------------------------------------
void TFormaAddDataInNewBase::DeleteNachData(void)
{
RunQueryDelete("INTERF_MAINMENU");
RunQueryDelete("INTERF_TOOLBAR");
RunQueryDelete("INTERF_MAINMENU_GRP");


RunQueryDelete("SUSER");
RunQueryDelete("SGRPUSER");

RunQueryDelete("LOG");
}
//---------------------------------------------------------------------------
void TFormaAddDataInNewBase::RunQueryDelete(AnsiString name_table)
{
		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("delete from "+name_table);
		try
			{
			QueryUpdate->ExecQuery();
			pFIBTrUpdate->Commit();
			SaveProtocol("Очищена таблица "+name_table+"!");
			}
		catch (Exception &exception)
				{
				pFIBTrUpdate->Rollback();
				SaveProtocol("Ошибка при очистке таблицы "+name_table+"!"+exception.Message);
				}
	QueryUpdate->Close();

}
//--------------------------------------------------------------------------
void __fastcall TFormaAddDataInNewBase::cxButtonDeleteConstraintsClick(TObject *Sender)
{

//подключение к новой базе

try
		{
		NewDataBase->Connected=false;
		NewDataBase->DBName=NameServercxTextEdit->Text+":"
							+FilecxTextEdit->Text;
		NewDataBase->DBParams->Clear();
		NewDataBase->DBParams->Add(" user_name="+NameUsercxTextEdit->Text);
		NewDataBase->DBParams->Add(" lc_ctype=UTF8");
		NewDataBase->DBParams->Add(" password="+PasswordUsercxTextEdit->Text);
		NewDataBase->Connected=true;
		}
catch (Exception &exception)
		{
		SaveProtocol("Ошибка при подключении к новой базе:"+exception.Message);
		NewDataBase->Connected=false;
		return;
		}

DeleteConstraints();


NewDataBase->Connected=false;
}
//---------------------------------------------------------------------------

