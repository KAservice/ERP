//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "GlavForm.h"
#include "amc100k.h"
//#include "CashServer.h"
#include "UDMDocCheck.h"
#include "UDMSprEd.h"
#include "UDMSprNom.h"
#include "UDM.h"
#include "UDMSprUser.h"
#include "UDMSprPrice.h"
#include "UDMSprARM.h"
#include "UDMSprOborud.h"
#include "UAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool zapusk;

TFormGl *FormGl;
amc100k *amc;
TDMDocCheck *Check;
TDMSprNom *Nom;
TDMSprEd * Ed;
TDMSprARM *glARM;
int glNumberARM;
TDMSprPrice * DMSprPrice;
extern TDMSprUser *glUser;
extern String ComandString;
void glSaveProtocol(String str);
String AddEAN13(String Cod) ;

AnsiString BaseVersion;
AnsiString ProgramVersion;
int glRegNumber;
extern bool glDemo;
extern AnsiString GetVersionProgramFile(void);
//---------------------------------------------------------------------------
__fastcall TFormGl::TFormGl(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormCreate(TObject *Sender)
{
ProgramVersion="2.7";
LabelSostCheck->Caption="";
LabelProcent->Caption="";
LabelSummaNach->Caption="";
LabelOperation->Caption="";

amc=new amc100k(true);
DM=new TDM(Application);
//зададим каталог протоколов
AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
		CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
		{
		DM->glCatalogProtocol=ProgramCatalog+"\\Log";
		}

Check=new TDMDocCheck(Application);
Nom=new TDMSprNom(Application);
Ed=new TDMSprEd(Application);
glARM=new TDMSprARM(Application);
DMSprPrice=new TDMSprPrice(Application);
//glUser=new TDMSprUser(Application);

}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormShow(TObject *Sender)
{
if (zapusk==true) return;
AnsiString connect_string="";
AnsiString set_number="";
AnsiString password_user="";
AnsiString name_user="";
int Kol=0;
//ComandString="/localhost:C:\\Data\\SP_CENTER.gdb/1/SYSDBA/masterkey";
if (Trim(ComandString)!="")
        {
        try
                {
                for (int i=1;i<ComandString.Length()+1;i++)
						{
                        if (ComandString[i]=='/')
								{
                                Kol=Kol+1;
                                }
                        else
                                {
								if (Kol==1){connect_string=connect_string+ComandString[i];}
								if (Kol==2){set_number=set_number+ComandString[i];}
								if (Kol==3){name_user=name_user+ComandString[i];}
								if (Kol==4){password_user=password_user+ComandString[i];}
                                }
                        }
//				ShowMessage("Строка подключения:"+connect_string);
//				ShowMessage("Сетевой номер:"+set_number);
//				ShowMessage("Пользователь:"+name_user);
//				ShowMessage("Пароль:"+password_user);

				DM->ConnectString=Trim(connect_string);
				DM->PasswordUser=Trim(password_user);
				DM->NameUser=Trim(name_user);

                if(DM->GlobConnect()==true)
						{
						if (glUser->FindPoName(name_user)==1)
							{
							}
						else
							{
							ShowMessage("Не найден пользователь в справочнике пользователей! Необходимо завершить работу!");
							}

						StatusBar->Panels->Items[0]->Text=glUser->ElementNAME_USER->AsString;
						StatusBar->Panels->Items[1]->Text=DM->ConnectString;

						Visible=true;
						glNumberARM=StrToInt(set_number);
						if (glARM->FindPoCodu(glNumberARM)==0)
							{
							ShowMessage ("Не найдены настройки рабочего места!");
							OpenFormViborBase();
							}
						else
							{
							//подключаем устройства
							ConnectDevice();
							}

                        }
				else
						{
						ShowMessage("Не удалось подключиться к базе данных!\nСтрока подключения:"+connect_string
						+"\nСетевой номер:"+set_number
						+"\nПользователь:"+name_user
						+"\nПароль:"+password_user);
						OpenFormViborBase();
						}
				}
		catch (...)
				{
				ShowMessage("Ошибка при загрузке параметров из командной строки!\nСтрока подключения:"+connect_string
				+"\nСетевой номер:"+set_number
				+"\nПользователь:"+name_user
				+"\nПароль:"+password_user);
				OpenFormViborBase();
				}

       }
else
        {
        OpenFormViborBase();
        }
}
//---------------------------------------------------------------------------
void TFormGl::OpenFormViborBase(void)
{
FormaViborBase=new TFormaViborBase(Application);
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
        DM->ConnectString=FormaViborBase->ConnectString;
		DM->PasswordUser=FormaViborBase->PasswordUser;
		DM->NameUser=FormaViborBase->NameUser;

        if(DM->GlobConnect()==true)
				{
				if (glUser->FindPoName(FormaViborBase->NameUser)==1)
						{
						}
				else
						{
						ShowMessage("Не найден пользователь в справочнике пользователей! Необходимо завершить работу!");
						}

				Visible=true;
				glNumberARM=FormaViborBase->NumberARM;
				glARM->FindPoCodu(glNumberARM);
				ConnectDevice();

				StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
				StatusBar->Panels->Items[1]->Text=DM->ConnectString;

				FormaViborBase->CloseForm=true;
				}
		else
                {
				ShowMessage("Не удалось подключиться  к базе данных!");
                FormaViborBase->CloseForm=false;
                glSaveProtocol("Не удалось подключиться  к базе данных!");
                }
        }
else
        {
        //закрываем программу
        Close();

        }
}
//---------------------------------------------------------------------------
void TFormGl::ConnectDevice(void)
{
TDMSprARM * DMSprARM=new TDMSprARM(Application);
if(DMSprARM->FindPoCodu(glNumberARM)==0)
        {
        delete DMSprARM;
        return;
        }

TDMSprOborud * DMSprOborud=new TDMSprOborud(Application);
DMSprOborud->OpenTable(DMSprARM->ElementID_SARM->AsInt64);

DMSprOborud->Table->First();
while(!DMSprOborud->Table->Eof)
        {
        if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="kkm")
                {
                //подключим ккм в режиме ON-Line
                amc->ComName="COM"+DMSprOborud->TableCOMNAME_OBORUD->AsString;
                amc->intSetNumber=glNumberARM;
                amc->Resume();
                zapusk=true;
                break;
                }
        DMSprOborud->Table->Next();
        }

delete DMSprOborud;
delete DMSprARM;

}


//---------------------------------------------------------------------------

void __fastcall TFormGl::FormClose(TObject *Sender, TCloseAction &Action)
{
amc->Terminate();
delete amc;
delete Ed;
delete Nom;
delete Check;
delete DM;
delete glARM;
delete DMSprPrice;
//delete glUser;
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormDestroy(TObject *Sender)
{
//Shell_NotifyIcon(NIM_DELETE, &NID);
}


//----------------------------------------------------------------------------

//обновим основную форму
void __fastcall TFormGl::UpdateForm()
{


switch (amc->EventKKM)
        {

        case amc->ConnectEvent :  //подключение ККМ
                {
                NewCheck=true;

                StrokaMemo="Установлено соединение с ККМ!";
                FormGl->LabelActiveKKM->Color=clGreen;
                FormGl->LabelSoobshenie->Font->Color=clGreen;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");
                } break;

        case amc->DisconnectEvent :     //отключение ККМ
                {
                NewCheck=true;


                FormGl->LabelActiveKKM->Color=clRed;
                StrokaMemo="ККМ отключена!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case amc->IzmStatusKKMEvent :  //изменение статуса ккм
                {


                if (amc->EstSvazKKM==true)
                        {
                        FormGl->LabelActiveKKM->Color=clGreen;
                        }
                else
                        {
                        FormGl->LabelActiveKKM->Color=clRed;
                        }

                StrokaMemo="Изменение статуса ККМ!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;

        case amc->PaketOtKKMEvent :     //пакет от ккм
                {
                StrokaMemo="Пакет от ККМ!";
                //FormGl->RichOperation->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case amc->ErrorConnectEvent:      //ошибка подключения к ккм
                {
                NewCheck=true;

                FormGl->LabelActiveKKM->Color=clRed;
                StrokaMemo="Ошибка подключения к ККМ!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ErrorObmenEvent:       //ошибка обмена
                {
                StrokaMemo=amc->TextError;
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduEvent:      //запрос по коду
                {

                StrokaMemo="Запрос по коду!";
                 if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ПРОДАЖА ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ВОЗВРАТ ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная операция ";
                                }
                         }
                StrokaMemo=StrokaMemo+" Номер чека: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" Код товара: "+FloatToStr(amc->CodeTovar);
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduKolEvent:     //запрос по коду с количеством
                {
                StrokaMemo="Запрос по коду с количеством!";
                 if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ПРОДАЖА ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ВОЗВРАТ ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная операция ";
                                }
                         }
                StrokaMemo=StrokaMemo+" Номер чека: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" Код товара: "+FloatToStr(amc->CodeTovar);
                StrokaMemo=StrokaMemo+" Кол-во: "+FloatToStr(amc->KolTovar);
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->DobavlenieSvobSummEvent:  //добавление свободной суммы в чек
                {
                StrokaMemo="Добавление свободной суммы!";

                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ПРОДАЖА ";
                        FormGl->LabelOperation->Caption="продажа";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ВОЗВРАТ ";
                                FormGl->LabelOperation->Caption="возврат";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная операция ";
                                }
                         }
                StrokaMemo=StrokaMemo+" Номер чека: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" Номер покупки: "+IntToStr(amc->NumberPokupki);
                StrokaMemo=StrokaMemo+" Отдел: "+IntToStr(amc->Otdel);
                StrokaMemo=StrokaMemo+" Сумма покупки: "+FloatToStr(amc->SummaPokupki);

                if (NewCheck==true)
                        {//очищяем таблицу чека

                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        FormGl->LabelItog->Caption="Итог: ";

                        }

                 NewCheck=false;
                 FormGl->LabelNumberCheck->Caption="Текущий чек №"+IntToStr(amc->NumberCheck );
                 FormGl->LabelItog->Caption="Итог:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                 FormGl->LabelSummaCheck->Caption="Сумма:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                 FormGl->LabelSostCheck->Font->Color=clRed;
                 FormGl->LabelSostCheck->Caption="Чек открыт";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;

                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;

        case amc->DobavleniePokupkiEvent:  //добавление покупки в чек
                {
                StrokaMemo="Добавление покупки!";

                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ПРОДАЖА ";
                        FormGl->LabelOperation->Caption="продажа";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ВОЗВРАТ ";
                                FormGl->LabelOperation->Caption="возврат";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная операция ";
                                }
                         }
                StrokaMemo=StrokaMemo+" Номер чека: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" Номер покупки: "+IntToStr(amc->NumberPokupki);
                StrokaMemo=StrokaMemo+" Отдел: "+IntToStr(amc->Otdel);
                StrokaMemo=StrokaMemo+" Сумма покупки: "+FloatToStr(amc->SummaPokupki);

                if (NewCheck==true)
                        {//очищяем таблицу чека
                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        FormGl->LabelItog->Caption="Итог: ";

                        }


                FormGl->LabelNumberCheck->Caption="Текущий чек №"+IntToStr(amc->NumberCheck );
                FormGl->LabelItog->Caption="Итог:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                FormGl->LabelSummaCheck->Caption="Сумма:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                FormGl->LabelSostCheck->Font->Color=clRed;
                FormGl->LabelSostCheck->Caption="Чек открыт";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZakrChekaEvent:       //закрытие чека
                {
                StrokaMemo="Закрытие чека!";
                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ПРОДАЖА ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ВОЗВРАТ ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная операция ";
                                }
                         }

                StrokaMemo=StrokaMemo+" № чека: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" № КЛ: "+IntToStr(amc->NumberKl);

               StrokaMemo=StrokaMemo+" Опл: ";
               if ( amc->Oplata==amc->Nal )
                        {
                        StrokaMemo=StrokaMemo+"нал.";
                        }
                        else
                        {
                        if ( amc->Oplata==amc->BesNal )
                                {
                                StrokaMemo=StrokaMemo+"безнал.";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" Неизвестная оплата";
                                }
                         }

               StrokaMemo=StrokaMemo+" Начис: " ;
               if ( amc->Nachislenie==amc->No )
                        {
                        StrokaMemo=StrokaMemo+"нет";
                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        }
               if ( amc->Nachislenie==amc->Nadbavka )
                        {
                        StrokaMemo=StrokaMemo+"надбавка";
                        FormGl->LabelProcent->Caption="+ "+IntToStr(amc->Procent)+"%";
                        FormGl->LabelSummaNach->Caption="Надбавка:  "+FloatToStrF( amc->RealSummaCheck-amc->SummaCheck ,ffCurrency,10,2);

                        }
               if ( amc->Nachislenie==amc->Skidka )
                        {
                        StrokaMemo=StrokaMemo+"скидка";
                        FormGl->LabelProcent->Caption="- "+IntToStr(amc->Procent)+"%";
                        FormGl->LabelSummaNach->Caption="Скидка:  "+FloatToStrF( amc->SummaCheck-amc->RealSummaCheck,ffCurrency,10,2 );
                        }
                StrokaMemo=StrokaMemo+" %: "+IntToStr(amc->Procent);
                StrokaMemo=StrokaMemo+" Кол. пок.: "+IntToStr(amc->KolPokupok);
                StrokaMemo=StrokaMemo+" Без начисл: "+FloatToStr(amc->SummaCheck);
                StrokaMemo=StrokaMemo+" С начис: "+FloatToStr(amc->RealSummaCheck);

                FormGl->LabelSostCheck->Font->Color=clGreen;
                FormGl->LabelSostCheck->Caption="Чек закрыт";
                FormGl->LabelNumberKl->Caption=" Контр. лента №"+IntToStr(amc->NumberKl);
                FormGl->LabelItog->Caption="Итог:  "+FloatToStrF(amc->RealSummaCheck,ffCurrency,10,2);
                FormGl->LabelSummaCheck->Caption="Сумма:  "+FloatToStrF(amc->SummaCheck,ffCurrency,10,2);

                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");

                } break;
        case amc->SbrosChekaEvent:     //сброс чека
                {
                StrokaMemo="Сброс чека!";
                FormGl->LabelSostCheck->Font->Color=clGreen;
                FormGl->LabelSostCheck->Caption="Чек сброшен";
                FormGl->LabelItog->Caption="Итог:  ";
                FormGl->LabelSummaCheck->Caption="Сумма:  ";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");

                } break;
        default :
                {

                } break;
        }

}
//----------------------------------------------------------------------------
//обработать запрос ККМ
void  __fastcall TFormGl::ObrabotatZaprosKKM()
{

switch (amc->EventKKM)
        {

        case amc->ConnectEvent :
                {

                } break;
        case amc->DisconnectEvent :
                {


                } break;
        case amc->PaketOtKKMEvent :
                {

                } break;
        case amc->ErrorConnectEvent:
                {

                } break;
        case amc->ErrorObmenEvent:
                {

                } break;
        case amc->ZaprosPoCoduEvent:
				{
				Price=0;
                //получим параметры товара
                StrokaMemo="Ответ: ";
                if (Nom->FindPoCodu(amc->CodeTovar)>0)   //ищем товар по коду
                        {
						Ed->OpenElement(Nom->ElementIDBASEDNOM->AsInt64);
                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //тип цен
														Nom->ElementIDNOM->AsInt64,         //номенклатура
														Nom->ElementIDBASEDNOM->AsInt64,    //единица
														1,                                 //кф единицы
														Nom->ElementIDBASEDNOM->AsInt64) ; //базовая единица

						if ( Price > 0.001)
								{
								amc->PriceTovar=Price;
								StrokaMemo=StrokaMemo+" Цена: "+FloatToStr(Price);
                                               amc->EnableOtvet=true;
                                }
                        else
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" Не найдена цена! Не отвечать!" ;
                                }
                        }
                else    //не нашли товар по коду, ищем единицу;
                        {
                        String shcode=FloatToStr(amc->CodeTovar);
                        shcode=AddEAN13(shcode);
                        if (Ed->FindEdPoSh(shcode)>0)
                                {
								if (Nom->OpenElement(Ed->ElementIDNOMED->AsInt64)>0)
                                        {
                                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
										StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

												Price=0;
												Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //тип цен
														Nom->ElementIDNOM->AsInt64,         //номенклатура
														Ed->ElementIDED->AsInt64,    //единица
														Ed->ElementKFED->AsFloat,                                 //кф единицы
														Nom->ElementIDBASEDNOM->AsInt64) ; //базовая единица

										if ( Price > 0.001)
												{
												amc->PriceTovar=Price;
                                                StrokaMemo=StrokaMemo+" Цена: "+FloatToStr(Price)
                                                          +" за  "+Ed->ElementNAMEED->AsString+" (КФ: "+Ed->ElementKFED->AsString+")";
                                                amc->EnableOtvet=true;
                                                }
                                        else
                                                {
                                                amc->EnableOtvet=false;
                                                StrokaMemo=StrokaMemo+" Не найдена цена! Не отвечать!" ;
                                                }
                                        }
                                }
                        else   //не нашли единицу
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" Не найден товар! Не отвечать!";
                                }
                        }

                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduKolEvent:
				{
				Price=0;
                 //получим параметры товара
                int KolNom=Nom->FindPoCodu(amc->CodeTovar);
                StrokaMemo="Ответ: ";
                if (KolNom==1)
                        {
                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //тип цен
														Nom->ElementIDNOM->AsInt64,         //номенклатура
														Nom->ElementIDBASEDNOM->AsInt64,    //единица
														1,                                 //кф единицы
														Nom->ElementIDBASEDNOM->AsInt64) ; //базовая единица

						if ( Price > 0.001)
								{
								amc->PriceTovar=Price;
                                StrokaMemo=StrokaMemo+" Цена: "+FloatToStr(Price);
                                amc->EnableOtvet=true;
                                }
                        else
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" Не найдена цена! Не отвечать!" ;
                                }
                        }
                else
                        {
                        amc->EnableOtvet=false;
                        StrokaMemo=StrokaMemo+" Не найден товар! Не отвечать!";
                        }
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case amc->DobavlenieSvobSummEvent:  //добавление свободной суммы в чек
				{
				Price=0;
                if (NewCheck==true)
                        {
                        //Check->IBTr->Rollback();
                        //Check->IBTr->StartTransaction();
                        //Check->DocAll->Active=true;
                        //Check->Doc->Active=true;
                        //Check->DocT->Active=true;
                        Check->OpenDoc(0);
                        Check->NewDoc();
                        Check->DocAll->Edit();
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
						Check->DocAllIDSKLDOC->AsInt64=glARM->ElementIDSKLAD_SARM->AsInt64;
                        Check->DocAll->Post();
                        Check->Doc->Edit();

                        if (amc->CheckOperation==amc->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (amc->CheckOperation==amc->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }

						Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;
						Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                        Check->Doc->Post();
                        NewCheck=false;
                        TekSummaCheck=0;
                        }
                Nom->FindPoCodu(1);
                if (Nom->Element->RecordCount==1)
                        {
                        Check->AddDocNewString();
                        Check->DocT->Edit();
						Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                        Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
						Check->DocTIDEDCHKT->AsInt64=Nom->ElementIDBASEDNOM->AsInt64;
                        Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
                        Check->DocTKOLCHKT->AsFloat=amc->KolTovar;
                        Check->DocTKFCHKT->AsFloat=1;
                        Check->DocTPRICECHKT->AsFloat=amc->PriceTovar;
                        Check->DocTSUMCHKT->AsFloat=amc->SummaPokupki;
                        Check->DocT->Post();
                        }
                else
                        {
                        FormGl->RE->Lines->Add("Не найден товар с кодом свободной суммы (1)! ");
                        glSaveProtocol("Не найден товар с кодом свободной суммы (1)! ");
                        }
                TekSummaCheck=TekSummaCheck+amc->SummaPokupki;

                } break;


        case amc->DobavleniePokupkiEvent:
                {
                if (NewCheck==true)
                        {
                        //Check->IBTr->Rollback();
                        //Check->IBTr->StartTransaction();
                        //Check->DocAll->Active=true;
                        //Check->Doc->Active=true;
                       // Check->DocT->Active=true;
                        Check->OpenDoc(0);
                        Check->NewDoc();
                        Check->DocAll->Edit();
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
                        Check->DocAllIDSKLDOC->AsInteger=glARM->ElementIDSKLAD_SARM->AsInteger;
                        Check->DocAll->Post();
                        Check->Doc->Edit();
						Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;
						Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                        if (amc->CheckOperation==amc->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (amc->CheckOperation==amc->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }
                                
                        Check->Doc->Post();
                        NewCheck=false;
                        TekSummaCheck=0;
                        }
                Check->AddDocNewString();
                Check->DocT->Edit();
				Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                Check->DocTIDEDCHKT->AsInt64=Ed->ElementIDED->AsInt64;
                Check->DocTNAMEED->AsString=Ed->ElementNAMEED->AsString;
                Check->DocTKOLCHKT->AsFloat=amc->KolTovar;
                Check->DocTKFCHKT->AsFloat=Ed->ElementKFED->AsFloat;
                Check->DocTPRICECHKT->AsFloat=amc->PriceTovar;
                Check->DocTSUMCHKT->AsFloat=amc->SummaPokupki;
                Check->DocT->Post();
                TekSummaCheck=TekSummaCheck+amc->SummaPokupki;

                } break;
        case amc->ZakrChekaEvent:
                {
                Check->Doc->Edit();
                Check->DocNCHECKCHK->AsInteger=amc->NumberCheck;
                Check->DocNKLCHK->AsInteger=amc->NumberKl;
                Check->Doc->Post();
                if (amc->Nachislenie!=amc->No)
                        {
                        RaspredNachislenie();
                        }
                TekSummaCheck=amc->RealSummaCheck;
                if (Check->SaveDoc()==true)
                        {
                        if(Check->DvRegDoc()==false)
                                {
                                FormGl->RE->Lines->Add("Не удалось провести чек!");
                                glSaveProtocol("Не удалось провести чек!");
                                }
                        }
                else
                        {
                        FormGl->RE->Lines->Add("Не удалось записать чек!");
                         glSaveProtocol("Не удалось записать чек!");

                        }
                NewCheck=true;

                } break;
        case amc->SbrosChekaEvent:
                {
                 Check->DocT->CancelUpdates();
                 Check->Doc->CancelUpdates();
                 Check->DocAll->CancelUpdates();
                 Check->IBTr->Commit();

                NewCheck=true;
                } break;
        default :
                {

                } break;
        }
}

//----------------------------------------------------------------------------
void __fastcall TFormGl::ObrabExternalEvent()
{

ObrabotatZaprosKKM();
UpdateForm();
}
//----------------------------------------------------------------------------
void TFormGl::RaspredNachislenie(void)
{
double Skidka=0;
double Nadbavka=0;

if (amc->Nachislenie==amc->Skidka)
        {
        Skidka=amc->SummaCheck-amc->RealSummaCheck;
        }
if(amc->Nachislenie==amc->Nadbavka)
        {
        Nadbavka=amc->RealSummaCheck-amc->SummaCheck;
        }

if (amc->Nachislenie!=amc->No )
        {
        int Kol=0;
        Check->DocT->First();
        while(!Check->DocT->Eof)
                {
                Check->DocT->Edit();
                if (amc->Nachislenie==amc->Skidka)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTSKCHKT->AsFloat=Skidka;
                                }
                        else
                                {
                                Check->DocTSKCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat*(amc->Procent)/100;
                                Skidka=Skidka-Check->DocTSKCHKT->AsFloat;
                                }
                        Check->DocTSUMCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat-Check->DocTSKCHKT->AsFloat;

                        }

                if (amc->Nachislenie==amc->Nadbavka)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTNADCHKT->AsFloat=Nadbavka;
                                }
                        else
                                {
                                Check->DocTNADCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat*(amc->Procent)/100;
                                Nadbavka=Nadbavka-Check->DocTNADCHKT->AsFloat;
                                }
                        Check->DocTSUMCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat+Check->DocTNADCHKT->AsFloat;

                        }


                Check->DocT->Post();
                Kol=Kol+1;
                Check->DocT->Next();
                }
        }
}
//-----------------------------------------------------------------------------




void __fastcall TFormGl::OpenAboutClick(TObject *Sender)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Кассовый сервер АМС-100К";
form->VerProgLabel->Caption="Версия программы: "+ProgramVersion;
form->VerBaseLabel->Caption="Версия базы: "+BaseVersion;
//получим версию файла
form->VerFileLabel->Caption="Версия файла: "+GetVersionProgramFile();
//регистрационный номер
form->RegNumberLabel->Caption="Регистрационный номер: "+IntToStr(glRegNumber)
	+" ("+IntToHex(glRegNumber, 8)+")";
//TDMSetup * DMSetup=new TDMSetup(Application);
//DMSetup->OpenElement(15);
form->GrPosledLabel->Caption="";//"Граница последовательности: "
//				+DMSetup->ElementVALUE_SETUP->AsString;
//delete DMSetup;
if (glDemo==true)
	{
	form->DemoLabel->Visible=true;
	}
else
	{
	form->DemoLabel->Visible=false;
	}
form->UpdateForm();
form->ShowModal();
}
//---------------------------------------------------------------------------

