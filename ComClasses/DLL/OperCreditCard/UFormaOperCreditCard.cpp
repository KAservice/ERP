//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaOperCreditCard.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IDMQueryRead.h"
#include "IDMDocPKORozn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaOperCreditCard::TFormaOperCreditCard(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaOperCreditCard::Init(void)
{
bool result=false;


if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();

	//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}

    //���������� �������� ���������� ����������� ����������� � �������
	IDevices * i_dev;
	if (InterfaceMainObject->kanQueryInterface(IID_IDevices,(void**)&i_dev)==-1)
		{
		if (i_dev)
			{
			if (i_dev->GetDeviceObject(1, (void**) &glFR)!=-1)
				{
				glFR=0;
				}
			if(	i_dev->GetDeviceObject(2, (void**) &glDisplayPok)!=-1)
				{
                glDisplayPok=0;
				}
			i_dev->kanRelease();
			}
		}
	else
		{
		glFR=0;
        glDisplayPok=0;
		}

	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
												 (void**)&DMSprDiscountCard);
DMSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);


LabelMessage->Caption="";

//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaOperCreditCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaOperCreditCard::FormClose(TObject *Sender, TCloseAction &Action)

{
//������� ICallBack ��� �������� ������� � ���������� �����
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DMSprDiscountCard->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaOperCreditCard::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==1)
	{
	if (type_event==1)
		{
		EndViborDiscountCard();
		}
	FormaInputDiscountCard=0;
	}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaOperCreditCard::ActionViborCardPoCoduExecute(TObject *Sender)

{
ViborCard();
}
//---------------------------------------------------------------------------
//�����  �����
void  TFormaOperCreditCard::ViborCard(void)
{

	if (FormaInputDiscountCard==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputDiscountCard.1",IID_IFormaInputDiscountCard,
												 (void**)&FormaInputDiscountCard);
		FormaInputDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputDiscountCard->Vibor=true;
		//FormaInputDiscountCard->NameLabel->Caption="������� ��� ��������� �����:";
		//FormaInputDiscountCard->Caption="��� ���������� �����";
		FormaInputDiscountCard->NumberProcVibor=1;
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaOperCreditCard::EndViborDiscountCard(void)
{
//if (glScaner)if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;


				AnsiString s=FormaInputDiscountCard->InputText;
				if (s.Length()>13) {s.SetLength(13);}
				__int64 id_card=0;
				if (s.Length()>6)
					{ //���� ����� �� ����� ����
					id_card=DMSprDiscountCard->PoiskPoShCodu(s);
					}
				else
					{ //���� ����� �� ����
					id_card=DMSprDiscountCard->PoiskPoCodu(s);
					}

				if (id_card>0)
					{
					DMSprDiscountCard->OpenElement(id_card);
					if (DMSprDiscountCard->ElementACT_SDISCOUNT_CARD->AsInteger==1)
						{   //����� �������
						LabelMessage->Caption="";
						NameKlientLabel->Caption="������: "+DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						NameCardLabel->Caption="�����: "+DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;

						//������� ������������ ����� �������
						IDMQueryRead *q;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
						q->Init(InterfaceMainObject,InterfaceOwnerObject);
						q->pFIBQ->Close();
						q->pFIBQ->SQL->Clear();
						UnicodeString zapros="select sdog.maxsumcredit_sdog    \
								from sdog                      \
								where sdog.id_sdog=:PARAM_ID ";
						q->pFIBQ->SQL->Add(zapros);
						q->pFIBQ->ParamByName("PARAM_ID")->AsString=DMSprDiscountCard->ElementIDDOG_SDISCOUNT_CARD->AsString;
						q->pFIBQ->ExecQuery();
						double max_sum_credit=q->pFIBQ->FieldByName("maxsumcredit_sdog")->AsFloat;



						//������� ������� ����� �������
						q->pFIBQ->Close();
						q->pFIBQ->SQL->Clear();
						zapros="select rgvsrasch.sum_vsrasch   \
									from rgvsrasch        \
									where rgvsrasch.idfirm_vsrasch=:PARAM_IDFIRM and  \
									rgvsrasch.idklient_vsrasch=:PARAM_IDKLIENT ";
						q->pFIBQ->SQL->Add(zapros);
						q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
						q->pFIBQ->ParamByName("PARAM_IDKLIENT")->AsString=DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString;
						q->pFIBQ->ExecQuery();
						double tec_dolg=q->pFIBQ->FieldByName("sum_vsrasch")->AsFloat;

						q->kanRelease();

						MaxDolgLabel->Caption=FloatToStrF(max_sum_credit,ffFixed,15,2);
						TecDolgLabel->Caption=FloatToStrF(tec_dolg,ffFixed,15,2);
						}
					else
						{
						LabelMessage->Caption="����� �� �������!";
						MaxDolgLabel->Caption="";
						TecDolgLabel->Caption="";
						NameKlientLabel->Caption="������: ";
						NameCardLabel->Caption="�����: ";
						}
					}
			else
					{
					LabelMessage->Caption="����� �� �������!";
					MaxDolgLabel->Caption="";
					TecDolgLabel->Caption="";
					NameKlientLabel->Caption="������: ";
					NameCardLabel->Caption="�����: ";
					}



}

//---------------------------------------------------------------------------
bool TFormaOperCreditCard::Oplatit(void)
{
bool result=false;
//�������� ��������
CreateDoc();
PrintCheck();
//���������� ��� �� ��
return result;
}
//----------------------------------------------------------------------------
bool TFormaOperCreditCard::CreateDoc(void)
{
bool result=false;


IDMDocPKORozn *doc;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);

try
	{
	doc->NewDoc();
	doc->DocAll->Edit();
	doc->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
	doc->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
	doc->DocAllIDKLDOC->AsString=DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString;
	doc->DocAllIDDOGDOC->AsString=DMSprDiscountCard->ElementIDDOG_SDISCOUNT_CARD->AsString;
	doc->DocAllSUMDOC->AsFloat=StrToFloat(SummacxCalcEdit->Text);
	doc->DocAll->Post();

	doc->Doc->Edit();
	doc->DocIDKKM_DPKOROZN->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
	doc->DocIDCARD_DPKOROZN->AsString=DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString;
    doc->DocOPERATION_DPKOROZN->AsInteger=11;  //�������� � ���������� �������
	doc->Doc->Post();

	if (doc->SaveDoc()==true)
		{
		if(doc->DvRegDoc()==true)
			{


			}
		else
			{

			}
		}
	}
catch(Exception &exception)
	{
	ShowMessage("������ ��� �������� ���������: "+exception.Message);
	}


return result;
}
//----------------------------------------------------------------------------
bool TFormaOperCreditCard::PrintCheck(void)
{
bool result=false;

if (DM_Connection->Arm_GetParameter("NO_PRINT_FR")=="YES")
		{
		result=true;
		return result;
		}


// �������� ���� ���������� ���� ������������ ���
if(DM_Connection->Arm_GetParameter("PrintFiscalCheck")=="1")
	{
	result=PrintFiscalCheck();
	}
else
	{
	result=PrintNoFiscalCheck();
	}

return result;

}
//----------------------------------------------------------------------------

bool TFormaOperCreditCard::PrintFiscalCheck(void)
{
bool Res=false;
if (glFR)
	{
	if(glFR->ConnectFR==false)
        {
		LabelMessage->Caption="���������� ����������� �� ���������!";
		return Res;
        }
	}
else
	{
	LabelMessage->Caption="���������� ����������� �� ���������!";
	return Res;
    }


try
	{
		UnicodeString StrPr="  ";

			StrPr="### ������: "+DMSprDiscountCard->ElementNAMEKLIENT->AsString+";";
			StrPr=StrPr+"�����: "+DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString+";"
				+" �����: "+SummacxCalcEdit->Text+";";

			DM_Connection->glSaveProtocol(StrPr);



	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->OpenNoFiscalCheck()==false )
		{
		throw Exception(glFR->TextError);
		}



	if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
		{
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (glFR->PrintString("������: "+DMSprDiscountCard->ElementNAMEKLIENT->AsString,1,1,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if (glFR->PrintString("�����: "+DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString,1,1,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if(glFR->CloseNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}

	double sum_oplat=StrToFloat(SummacxCalcEdit->Text);

		if(glFR->PrintFiscalCheck(sum_oplat,
									1,
									sum_oplat,
									0,
									0,
									0,
									0)==false)
			{
			throw Exception(glFR->TextError);
			}



	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	}


return Res;

}
//----------------------------------------------------------------------------
bool TFormaOperCreditCard::PrintNoFiscalCheck(void)
{
bool Res=false;
if (glFR)
	{
	if(glFR->ConnectFR==false)
        {
		LabelMessage->Caption="���������� ����������� �� ���������!";
		return Res;
        }
	}
else
	{
	LabelMessage->Caption="���������� ����������� �� ���������!";
	return Res;
    }


try
	{
		UnicodeString StrPr="  ";

			StrPr="### ������: "+DMSprDiscountCard->ElementNAMEKLIENT->AsString+";";
			StrPr=StrPr+"�����: "+DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString+";"
				+" �����: "+SummacxCalcEdit->Text+";";

			DM_Connection->glSaveProtocol(StrPr);


	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->OpenNoFiscalCheck()==false )
		{
		throw Exception(glFR->TextError);
		}



	if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
		{
		if (glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}




	if(glFR->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

		double sum_oplat=StrToFloat(SummacxCalcEdit->Text);
		if(glFR->PrintString("����: "+FloatToStrF(sum_oplat,ffFixed,15,2),4,1,2,true,false,false)==false)
				{
				throw Exception(glFR->TextError);
				}

		for (int i=0;i<3;i++)
			{
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			 }

		if(glFR->PrintString("������� _____________ ",1,0,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		for (int i=0;i<6;i++)
			{
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			 }

		if(glFR->CloseNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}

		glFR->Cut(1);
	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	}


return Res;
}
//----------------------------------------------------------------------------
void __fastcall TFormaOperCreditCard::cxButton1Click(TObject *Sender)
{
Oplatit();
}
//---------------------------------------------------------------------------

