//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMGurAllDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------

#include "IDMSetup.h"
#include "IHOT_DMDocBron.h"
#include "IHOT_DMDocOtmenaBron.h"
#include "IHOT_DMDocRaschet.h"
#include "IHOT_DMDocRasm.h"
#include "IHOT_DMDocReal.h"
#include "IHOT_DMDocViezd.h"

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
__fastcall THOT_DMGurAllDoc::THOT_DMGurAllDoc(TComponent* Owner)
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

void __fastcall THOT_DMGurAllDoc::DataModuleCreate(TObject *Sender)
{
OtborVkl=false;
OtborPoFirm=false;
OtborPoKlient=false;
OtborPoSklad=false;
OtborPoTypeDoc=false;
NoCheck=false;
StringTypeDoc="";
}
//---------------------------------------------------------------------------
bool THOT_DMGurAllDoc::Init(void)
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

Table->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_DMGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMGurAllDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void THOT_DMGurAllDoc::OpenTable()
{

Table->Active=false;
AnsiString zapros="select HOT_GALLDOC.*, NAMEFIRM, NAMEKLIENT, NAME_USER ";
zapros=zapros+" from HOT_GALLDOC";
zapros=zapros+" LEFT OUTER JOIN SFIRM ON IDFIRM_HOT_GALLDOC=IDFIRM";
zapros=zapros+" left outer join SKLIENT on IDKL_HOT_GALLDOC=IDKLIENT";
zapros=zapros+" left outer join SUSER on  IDUSER_HOT_GALLDOC= ID_USER";

zapros=zapros+" where POS_HOT_GALLDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";

if (StringTypeDoc!="" && OtborVkl==true)
        {
		zapros=zapros+" AND TDOC_HOT_GALLDOC in ("+StringTypeDoc+" ) ";
        }
else
        {

        }

if (IdFirm>0 && OtborVkl==true)
        {
		zapros=zapros+" AND IDFIRM_HOT_GALLDOC="+IntToStr(IdFirm);
        }

if (IdKlient>0 && OtborVkl==true)
        {
		zapros=zapros+" AND IDKL_HOT_GALLDOC="+IntToStr(IdKlient);
        }


zapros=zapros+" order by POS_HOT_GALLDOC";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon; 
Table->Active=true;

}
//---------------------------------------------------------------------------
void THOT_DMGurAllDoc::UpdateTable(void)
{
IdDocH=TableID_HOT_GALLDOC->AsInt64;
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_HOT_GALLDOC",IntToStr(IdDocH),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------


void THOT_DMGurAllDoc::AllCancelDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
        {
		CancelDvRegDoc(Trim(TableTDOC_HOT_GALLDOC->AsString), TableID_HOT_GALLDOC->AsInt64);
        Table->Next();
        }

}
//--------------------------------------------------------------------
void THOT_DMGurAllDoc::AllDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
		{
		CancelDvRegDoc(Trim(TableTDOC_HOT_GALLDOC->AsString), TableID_HOT_GALLDOC->AsInt64);
		Table->Next();
		}
}
//-----------------------------------------------------------------------
bool THOT_DMGurAllDoc::DvRegDoc(AnsiString type_doc, __int64 id_doc)
{
bool result=false;
if(type_doc=="BRON")
		{
		IHOT_DMDocBron *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocBron.1",IID_IHOT_DMDocBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="RASM")
		{
		IHOT_DMDocRasm *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRasm.1",IID_IHOT_DMDocRasm,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="OTMBRON")
		{
		IHOT_DMDocOtmenaBron *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocOtmenaBron.1",IID_IHOT_DMDocOtmenaBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="RASCHET")
		{
		IHOT_DMDocRaschet *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRaschet.1",IID_IHOT_DMDocRaschet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}


if(type_doc=="REAL")
		{
		IHOT_DMDocReal *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocReal.1",IID_IHOT_DMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="VIEZD")
		{
		IHOT_DMDocViezd *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocViezd.1",IID_IHOT_DMDocViezd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true)
			{
			 result=true;
			}
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}


return result;
}
//----------------------------------------------------------------------
bool THOT_DMGurAllDoc::CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)
{
bool result=false;
if(type_doc=="BRON")
		{
		IHOT_DMDocBron *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocBron.1",IID_IHOT_DMDocBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc(id_doc);
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}
if(type_doc=="RASM")
		{
		IHOT_DMDocRasm *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRasm.1",IID_IHOT_DMDocRasm,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{

			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="OTMBRON")
		{
		IHOT_DMDocOtmenaBron *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocOtmenaBron.1",IID_IHOT_DMDocOtmenaBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="RASCHET")
		{
		IHOT_DMDocRaschet *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRaschet.1",IID_IHOT_DMDocRaschet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}


if(type_doc=="REAL")
		{
		IHOT_DMDocReal *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocReal.1",IID_IHOT_DMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}

if(type_doc=="VIEZD")
		{
		IHOT_DMDocViezd *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocViezd.1",IID_IHOT_DMDocViezd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->OpenDoc( id_doc);
		//doc->EnableDvReg=true;
		if (doc->CancelDvRegDoc()==true)
			{
			 result=true;
			 }
		else
			{
			TextError=doc->TextError;
			}
		doc->kanRelease();
		}
return result;
}
//--------------------------------------------------------------------------



void __fastcall THOT_DMGurAllDoc::TableTDOC_HOT_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=glGetNameDocHotel(TableTDOC_HOT_GALLDOC->AsString);
}
//---------------------------------------------------------------------------

