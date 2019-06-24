//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMDocReal.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"

#include "IDMSprNom.h"
#include "IDMSprEd.h"
#include "IDMQueryRead.h"
#include "IHOT_DMSprPrOsnUslug.h"
#include "IDMSprPrice.h"
#include "DateUtils.hpp"
#include "IDMTableNumberDoc.h"
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
__fastcall THOT_DMDocReal::THOT_DMDocReal(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
}
//---------------------------------------------------------------------------
bool THOT_DMDocReal::Init(void)
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
IBTrDvReg->DefaultDatabase=DM_Connection->pFIBData;

DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
TypePriceDataSet->Database=DM_Connection->pFIBData;
SpisokGuestOsnUslug->Database=DM_Connection->pFIBData;
SpisokGuestDopUslug->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;



DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int THOT_DMDocReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMDocReal::DataModuleDestroy(TObject *Sender)
{
SpisokGuestOsnUslug->Active=false;
SpisokGuestDopUslug->Active=false;

DocAll->Close();
Doc->Close();
DocT->Close();
//NumDoc->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void THOT_DMDocReal::NewDoc(void)
{
DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();
DocT->Open();

IdDoc=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
DocIDDOCH_HOT_DREAL->AsString=IdDoc;
Doc->Post();

DocAllPOS_HOT_GALLDOC->AsDateTime=Now();
DocAllTDOC_HOT_GALLDOC->AsString="REAL";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSER_HOT_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRM_HOT_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLAD_HOT_GALLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_HOT_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}

//получим номер документа
NumDoc->Active=false;
IDMTableNumberDoc * dm_num;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
dm_num->Init(InterfaceMainObject,0);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REAL");
NumDoc->Open();
DocAllNUMBER_HOT_GALLDOC->AsInteger=NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;

DocAll->Post(); 
}
//----------------------------------------------------------------------------
void THOT_DMDocReal::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;
        DocT->ParamByName("ID")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
        DocT->Open();

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();


}

//----------------------------------------------------------------------------
void THOT_DMDocReal::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();
}
//----------------------------------------------------------------------------
bool THOT_DMDocReal::SaveDoc(void)
{
//DocT->First();
//ShowMessage("Тип"+DocTTUSL_HOT_DREALT->AsString);
//ShowMessage("Тариф"+DocTIDTPRICE_HOT_DREALT->AsString);

bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
        }

DocAll->Edit();
DocAllSUM_HOT_GALLDOC->AsFloat=Summa();
DocAll->Post();



try
        {
		IdDoc=glStrToInt64(DocAllID_HOT_GALLDOC->AsString);

		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();;

        OpenDoc(IdDoc);
        Res=true;
		}
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				Res=false;
				}
return Res;
}
//-----------------------------------------------------------------------------


bool THOT_DMDocReal::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return res;
        }

try
        {
        if (CancelDvRegDoc()!=true)
                {
                res=false;
                return res;
                }

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

        DocT->ApplyUpdates();
        Doc->ApplyUpdates();
        DocAll->ApplyUpdates();
		IBTrUpdate->Commit();
        res=true;
		}

catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				res=false;
				}
return res;

}
//-----------------------------------------------------------------------------
void THOT_DMDocReal::AddDocNewString(void)
{
DocT->Append();
DocTIDDOCH_HOT_DREALT->AsString=DocAllID_HOT_GALLDOC->AsString;
DocT->Post();

}
//-----------------------------------------------------------------------------
void THOT_DMDocReal::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double THOT_DMDocReal::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_HOT_DREALT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool THOT_DMDocReal::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
        }

try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOCH")->AsInt64=
						glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
				QueryDvReg->ExecProc();
				IBTrDvReg->Commit();

                result=true;
                }
        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}

QueryDvReg->Close();
return result;
}
//-----------------------------------------------------------------------------
bool THOT_DMDocReal::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
        }

try
		{     
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOCH")->AsInt64=
						glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
				QueryCancelDvReg->ExecProc();
				IBTrDvReg->Commit();

				result=true;

        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}
QueryCancelDvReg->Close();
return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall THOT_DMDocReal::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCH_HOT_DREAL->AsString=DocAllID_HOT_GALLDOC->AsString;

if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	DocIDBASE_HOT_DREAL->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOCH_HOT_DREALT->AsString=DocAllID_HOT_GALLDOC->AsString;


	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_HOT_DREALT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		}
}

//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_HOT_DREALT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUM_HOT_GALLDOC->AsFloat=DocAllSUM_HOT_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------


void __fastcall THOT_DMDocReal::DocAllPOS_HOT_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedHotel(DocAllPOS_HOT_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTKOL_HOT_DREALTChange(TField *Sender)
{
OldSummaStr=DocTSUM_HOT_DREALT->AsFloat;

DocTSUM_HOT_DREALT->AsFloat=NewSummaStr=DocTKOL_HOT_DREALT->AsFloat*DocTPRICE_HOT_DREALT->AsFloat;

DocAll->Edit();
DocAllSUM_HOT_GALLDOC->AsFloat=DocAllSUM_HOT_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTPRICE_HOT_DREALTChange(TField *Sender)
{
OldSummaStr=DocTSUM_HOT_DREALT->AsFloat;

DocTSUM_HOT_DREALT->AsFloat=NewSummaStr=DocTKOL_HOT_DREALT->AsFloat*DocTPRICE_HOT_DREALT->AsFloat;

DocAll->Edit();
DocAllSUM_HOT_GALLDOC->AsFloat=DocAllSUM_HOT_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
}
//---------------------------------------------------------------------------


void THOT_DMDocReal::AddStringReal(TDateTime pos_nach, TDateTime pos_con,
							__int64 id_nomer, AnsiString name_nomer,
							__int64 id_cat, AnsiString name_cat,
							__int64 id_type_pos, AnsiString name_type_pos,
							__int64 id_guest,AnsiString name_guest,
							bool add_bron)
{
//if (add_bron==true)
//	{
//	//получим количество бронирования
//	KolBron=1;
//	TDMSetup *dm_setup=new TDMSetup(Application);
//	dm_setup->OpenElement(103);
//	if (dm_setup->ElementVALUE_SETUP->AsString!="")
//		{
//		KolBron=StrToInt(dm_setup->ElementVALUE_SETUP->AsString);
//		}
//	delete dm_setup;
//	}
//
//
//
//THOT_DMSprPrOsnUslug * HOT_DMSprPrOsnUslug=new THOT_DMSprPrOsnUslug(Application);
////количество проживания меньше суток
//
//
//
//	unsigned short year,month,day,hour,min,sec,msec;
//	DecodeDateTime(pos_nach,year,month,day,hour,min,sec,msec);
//
//
//	TDateTime tek_pos_nach=pos_nach;
//	TDateTime tek_pos;
//	int int_rasch_hour=12;
//
//
//	tek_pos=EncodeDateTime(year,month,day,int_rasch_hour,0,0,0);
//   //	ShowMessage("Начало отсчета:"+DateTimeToStr(tek_pos));
//
//	double tek_kol=0;
//	__int64 id_tek_type_price=0;
//
//
//	int kol_dob_strok=0;
//	__int64 id_new_type_price=0;
//
//	HOT_DMSprPrOsnUslug->GetParamPrice (id_cat,id_type_pos,tek_pos+0.01);
//	id_tek_type_price=HOT_DMSprPrOsnUslug->IdTypePrice;
//
//if (tek_pos+1<=pos_con)
//	{
//
//
//	Loop:
//			HOT_DMSprPrOsnUslug->GetParamPrice (id_cat,id_type_pos,tek_pos+0.01);
//			id_new_type_price=HOT_DMSprPrOsnUslug->IdTypePrice;
//
//				if (id_tek_type_price==id_new_type_price)
//					{
//					tek_kol++;
//					}
//				else
//					{ //создаем новую строку
//					//услуга бронирования
//					if(add_bron==true)
//						{
//						int kol_bron=0;
//						if (tek_kol<KolBron)
//							{
//							kol_bron=tek_kol;
//							KolBron=KolBron-tek_kol;
//							}
//						else
//							{
//							kol_bron=KolBron;
//							KolBron=0;
//							}
//						if (kol_bron>0 && HOT_DMSprPrOsnUslug->IdNomBron>0 )
//							{
//							AddStringNewReal( tek_pos_nach,	pos_con,
//								id_nomer,name_nomer,
//								id_cat, name_cat,
//								id_type_pos, name_type_pos,
//								id_guest, name_guest,
//								HOT_DMSprPrOsnUslug->IdNomBron, HOT_DMSprPrOsnUslug->NameNomBron,
//								HOT_DMSprPrOsnUslug->IdEdBron,HOT_DMSprPrOsnUslug->KFEdBron,HOT_DMSprPrOsnUslug->NameEdBron,
//								HOT_DMSprPrOsnUslug->IdTypePrice,
//								kol_bron,
//								2
//								);
//							}
//						}
//
//
//					//проживание
//					AddStringNewReal( tek_pos_nach, tek_pos,
//							id_nomer, name_nomer,
//							id_cat, name_cat,
//							id_type_pos, name_type_pos,
//							id_guest, name_guest,
//							HOT_DMSprPrOsnUslug->IdNomProg,HOT_DMSprPrOsnUslug->NameNomProg,
//							HOT_DMSprPrOsnUslug->IdEdProg,HOT_DMSprPrOsnUslug->KFEdProg, HOT_DMSprPrOsnUslug->NameEdProg,
//							id_tek_type_price,
//							tek_kol,
//							1
//							);
//					id_tek_type_price=id_new_type_price;
//                    tek_pos_nach=tek_pos;
//					tek_kol=1;
//					}
//			 tek_pos++;
//			 if (tek_pos+1<=pos_con) goto Loop;
//
//	}
//
//	if (tek_pos<pos_con)
//		{
//		//необходимо добавить задержку после расчетного часа
//	   //	ShowMessage("Рассчитываем задержку между "+DateTimeToStr(tek_pos)+" и "+DateTimeToStr(pos_con));
//		int kol_hour=HoursBetween(tek_pos,pos_con);
//		if (0<kol_hour && kol_hour<=6)
//			{ //почасовая оплата
//			tek_kol=tek_kol+(0.04166666666*kol_hour);
//			}
//		if (6<kol_hour && kol_hour<=12)
//			{
//			tek_kol=tek_kol+0.5;
//			}
//
//		if (12<kol_hour && kol_hour<=18)
//			{
//			tek_kol=tek_kol+0.75;
//			}
//
//		if (18<kol_hour)
//			{
//			tek_kol=tek_kol+1;
//			}
//		}
//
//if (tek_kol<1) tek_kol=1;
////добавляем последнюю строку
//		if (tek_kol!=0) 
//			{
//			if (add_bron==true)
//				{
//				int kol_bron=0;
//				if (tek_kol<KolBron)
//					{
//					kol_bron=tek_kol;
//					KolBron=KolBron-tek_kol;
//					}
//				else
//					{
//					kol_bron=KolBron;
//					KolBron=0;
//					}
//				//услуга бронирования
//				if(kol_bron>0 && HOT_DMSprPrOsnUslug->IdNomBron>0)
//					{
//					AddStringNewReal( tek_pos_nach,	pos_con,
//							id_nomer,name_nomer,
//							id_cat, name_cat,
//							id_type_pos, name_type_pos,
//							id_guest, name_guest,
//							HOT_DMSprPrOsnUslug->IdNomBron, HOT_DMSprPrOsnUslug->NameNomBron,
//							HOT_DMSprPrOsnUslug->IdEdBron,HOT_DMSprPrOsnUslug->KFEdBron,HOT_DMSprPrOsnUslug->NameEdBron,
//							HOT_DMSprPrOsnUslug->IdTypePrice,
//							kol_bron,
//							2
//							);
//					}
//				}
//
//			AddStringNewReal( tek_pos_nach,	pos_con,
//							id_nomer,name_nomer,
//							id_cat, name_cat,
//							id_type_pos, name_type_pos,
//							id_guest, name_guest,
//							HOT_DMSprPrOsnUslug->IdNomProg, HOT_DMSprPrOsnUslug->NameNomProg,
//							HOT_DMSprPrOsnUslug->IdEdProg,HOT_DMSprPrOsnUslug->KFEdProg,HOT_DMSprPrOsnUslug->NameEdProg,
//							HOT_DMSprPrOsnUslug->IdTypePrice,
//							tek_kol,
//							1
//							)  ;
//			}
//
//
//delete HOT_DMSprPrOsnUslug;
}
//-----------------------------------------------------------------------------
void THOT_DMDocReal::AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,
							__int64 id_nomer, AnsiString name_nomer,
							__int64 id_cat,  AnsiString name_cat,
							__int64 id_type_pos, AnsiString name_type_pos,
							__int64 id_guest, AnsiString name_guest,
							__int64 id_nom, AnsiString name_nom,
							__int64 id_ed, double kf, AnsiString name_ed,
							__int64 id_type_price,
							double kol,
							int type_usl
							)
{
//TDMSprPrice *  DMSprPrice=new TDMSprPrice(Application);
//
//DocT->Append();
//DocTTUSL_HOT_DREALT->AsInteger=type_usl;
//
//if(id_nom!=0)
//	{
//	DocTIDNOM_HOT_DREALT->AsInt64=id_nom;
//	}
//DocTNAMENOM->AsString=name_nom;
//if (id_type_price!=0)
//	{
//	DocTIDTPRICE_HOT_DREALT->AsInt64=id_type_price;
//	}
//if(id_ed!=0)
//	{
//	DocTIDED_HOT_DREALT->AsInt64=id_ed;
//	}
//
//DocTKF_HOT_DREALT->AsFloat=kf;
//DocTNAMEED->AsString=name_ed;
//DMSprPrice->FindElement(DocTIDTPRICE_HOT_DREALT->AsInt64,
//								DocTIDNOM_HOT_DREALT->AsInt64);
//
//DocTPRICE_HOT_DREALT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat
//									*DocTKF_HOT_DREALT->AsFloat;
//
//DocTKOL_HOT_DREALT->AsFloat=kol;
//DocTPOSNACH_HOT_DREALT->AsDateTime=pos_nach;
//DocTPOSCON_HOT_DREALT->AsDateTime=pos_con;
//if(id_nomer!=0)
//	{
//	DocTIDNOMER_HOT_DREALT->AsInt64=id_nomer;
//	}
//if (id_cat)
//	{
//	DocTIDCAT_HOT_DREALT->AsInt64=id_cat;
//	}
//if(id_type_pos)
//	{
//	DocTIDTPOS_HOT_DREALT->AsInt64=id_type_pos;
//	}
//if(id_guest!=0)
//	{
//	DocTIDGUEST_HOT_DREALT->AsInt64=id_guest;
//	}
//	
//DocTNAME_HOT_SNF->AsString=name_nomer;
//DocTNAME_HOT_SCATNOM->AsString=name_cat;
//DocTNAME_HOT_STYPEPOS->AsString=name_type_pos;
//DocTNAMEKLIENT->AsString=name_guest;
//
//			DocT->Post();
//
//delete DMSprPrice;
}
//--------------------------------------------------------------------------
void THOT_DMDocReal::GetSpisokGuest(void)
{
SpisokGuestOsnUslug->Active=false;
SpisokGuestDopUslug->Active=false;

SpisokGuestOsnUslug->ParamByName("PARAM_IDDOCH")->AsInt64=
			glStrToInt64(DocAllID_HOT_GALLDOC->AsString);
SpisokGuestDopUslug->ParamByName("PARAM_IDDOCH")->AsInt64=
			glStrToInt64(DocAllID_HOT_GALLDOC->AsString);

SpisokGuestOsnUslug->Active=true;
SpisokGuestDopUslug->Active=true;
}
//--------------------------------------------------------------------------
double THOT_DMDocReal::GetKolOsnUslugGuest(__int64 id_guest)
{
double result=0;

SpisokGuestOsnUslug->First();
while (!SpisokGuestOsnUslug->Eof)
	{
	if (glStrToInt64(SpisokGuestOsnUslugIDKLIENT->AsString)==id_guest)
		{
		 result=SpisokGuestOsnUslugSUMKOL->AsFloat;
		 break;
		}
	SpisokGuestOsnUslug->Next();
	}

return result;
}
//---------------------------------------------------------------------------
double THOT_DMDocReal::GetSumDopUslugGuest(__int64 id_guest)
{
double result=0;

SpisokGuestDopUslug->First();
while (!SpisokGuestDopUslug->Eof)
	{
	if (glStrToInt64(SpisokGuestDopUslugIDKLIENT->AsString)==id_guest)
		{
		 result=SpisokGuestDopUslugSUM->AsFloat;
		 break;
		}
	SpisokGuestDopUslug->Next();
	}

return result;     

}
//----------------------------------------------------------------------------
void __fastcall THOT_DMDocReal::DocAllIDBASE_HOT_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_HOT_DREAL->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
	Doc->Post();
	}
DocT->First();
while (!DocT->Eof)
	{
	if (glStrToInt64(DocAllIDBASE_HOT_GALLDOC->AsString)!=0)
		{
		DocT->Edit();
		DocTIDBASE_HOT_DREALT->AsString=DocAllIDBASE_HOT_GALLDOC->AsString;
		DocT->Post();
		}
	DocT->Next();
	}
}
//---------------------------------------------------------------------------



void __fastcall THOT_DMDocReal::DocTTUSL_HOT_DREALTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (DocTTUSL_HOT_DREALT->AsInteger==0)
		{
		Text="Не зад.";
		}
if (DocTTUSL_HOT_DREALT->AsInteger==1)
		{
		Text="Осн.";
		}
if (DocTTUSL_HOT_DREALT->AsInteger==2)
		{
		Text="Брон.";
		}
if (DocTTUSL_HOT_DREALT->AsInteger==3)
		{
		Text="Доп.";
		}
if (DocTTUSL_HOT_DREALT->AsInteger==4)
		{
		Text="Пит.";
		}
}
//---------------------------------------------------------------------------

void __fastcall THOT_DMDocReal::DocTTUSL_HOT_DREALTSetText(TField *Sender, const UnicodeString Text)

{
if(Text=="Не зад.")
		{
		DocTTUSL_HOT_DREALT->AsInteger=0;
		}
if(Text=="Осн.")
		{
		DocTTUSL_HOT_DREALT->AsInteger=1;
		}
if(Text=="Брон.")
		{
		DocTTUSL_HOT_DREALT->AsInteger=2;
		}
if(Text=="Доп.")
		{
		DocTTUSL_HOT_DREALT->AsInteger=3;
		}
if(Text=="Пит.")
		{
		DocTTUSL_HOT_DREALT->AsInteger=4;
		}
}
//---------------------------------------------------------------------------

