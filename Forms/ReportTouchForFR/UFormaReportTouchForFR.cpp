//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportTouchForFR.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDevices.h"
#include "IDMSprFirm.h"
#include "IDMQueryRead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalendar"
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
__fastcall TFormaReportTouchForFR::TFormaReportTouchForFR(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TFormaReportTouchForFR::Init(void)
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
			i_dev->kanRelease();
			}
		}
	else
		{
		glFR=0;
		}
	}





Vibor=false;       //��� ������

PosNachcxDateEdit->Date=Date()+EncodeTime(0,0,0,0);
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);


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
int TFormaReportTouchForFR::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportTouchForFR::FormClose(TObject *Sender, TCloseAction &Action)

{
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportTouchForFR::BitBtnReportClick(TObject *Sender)
{

			double sum_sale=0;
			double sale_oplata_nal=0;
			double sale_oplata_pc=0;
			double sum_return_sale=0;
			double return_sale_oplata_nal=0;
			double return_sale_oplata_pc=0;
			__int64 id_firm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);

			IDMQueryRead *dm_q;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_q);
			dm_q->Init(InterfaceMainObject,InterfaceImpl);
			dm_q->pFIBQ->Close();

			///�������
			dm_q->pFIBQ->SQL->Clear();
			dm_q->pFIBQ->SQL->Add("  select sum(galldoc.sumdoc) as SUMMA, ");
			dm_q->pFIBQ->SQL->Add("       sum(dchk.oplnalchk) as OPL_NAL,                                     ");
			dm_q->pFIBQ->SQL->Add("       sum(dchk.oplpcchk) as OPL_PC                                        ");
			dm_q->pFIBQ->SQL->Add("  from dchk                                                                ");
			dm_q->pFIBQ->SQL->Add("  left outer join galldoc on dchk.iddocchk=galldoc.iddoc                   ");
			dm_q->pFIBQ->SQL->Add("  where dchk.operchk=0 and                                                 ");
			dm_q->pFIBQ->SQL->Add("          (galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON) and    ");
			dm_q->pFIBQ->SQL->Add("          dchk.idkkmchk=:PARAM_IDKASSA  and                                ");
			dm_q->pFIBQ->SQL->Add("  		galldoc.idfirmdoc=:PARAM_IDFIRM                                  ");

			dm_q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=id_firm;
			dm_q->pFIBQ->ParamByName("PARAM_IDKASSA")->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
			dm_q->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
			dm_q->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime= PosConcxDateEdit->Date;
			dm_q->pFIBQ->ExecQuery();

			sum_sale=dm_q->pFIBQ->FieldByName("SUMMA")->AsFloat;
			sale_oplata_nal=dm_q->pFIBQ->FieldByName("OPL_NAL")->AsFloat;
			sale_oplata_pc=dm_q->pFIBQ->FieldByName("OPL_PC")->AsFloat;
			dm_q->pFIBQ->Close();

			//��������
			dm_q->pFIBQ->SQL->Clear();
			dm_q->pFIBQ->SQL->Add("  select sum(galldoc.sumdoc) as SUMMA, ");
			dm_q->pFIBQ->SQL->Add("       sum(dchk.oplnalchk) as OPL_NAL,                                     ");
			dm_q->pFIBQ->SQL->Add("       sum(dchk.oplpcchk) as OPL_PC                                        ");
			dm_q->pFIBQ->SQL->Add("  from dchk                                                                ");
			dm_q->pFIBQ->SQL->Add("  left outer join galldoc on dchk.iddocchk=galldoc.iddoc                   ");
			dm_q->pFIBQ->SQL->Add("  where dchk.operchk=1 and                                                 ");
			dm_q->pFIBQ->SQL->Add("          (galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON) and    ");
			dm_q->pFIBQ->SQL->Add("          dchk.idkkmchk=:PARAM_IDKASSA  and                                ");
			dm_q->pFIBQ->SQL->Add("  		galldoc.idfirmdoc=:PARAM_IDFIRM                                  ");

			dm_q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=id_firm;
			dm_q->pFIBQ->ParamByName("PARAM_IDKASSA")->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
			dm_q->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
			dm_q->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime= PosConcxDateEdit->Date;
			dm_q->pFIBQ->ExecQuery();

			sum_return_sale=dm_q->pFIBQ->FieldByName("SUMMA")->AsFloat;
			return_sale_oplata_nal=dm_q->pFIBQ->FieldByName("OPL_NAL")->AsFloat;
			return_sale_oplata_pc=dm_q->pFIBQ->FieldByName("OPL_PC")->AsFloat;
			dm_q->pFIBQ->Close();
			dm_q->kanRelease();

		try
			{
			glFR->OpenNoFiscalCheck();
			glFR->PrintString(DM_Connection->ARMInfoNAMEFIRM->AsString,1,0,1,true,false, false);    //�����
			glFR->PrintString("�����",1,1,1,true,false, false);    //�����
			AnsiString s="    c  "+DateTimeToStr(PosNachcxDateEdit->Date);
			glFR->PrintString(s,1,1,0,true,false, false);
			s="    �� "+DateTimeToStr(PosConcxDateEdit->Date);
			glFR->PrintString(s,1,1,0,true,false, false);
			glFR->PrintString("    �����: "+DM_Connection->ARMInfoNAMEKKM->AsString,1,1,0,true,false, false);
			glFR->PrintString("�������:",1,1,0,true,false, false);    //����
			glFR->PrintLine();
			glFR->PrintString("�����:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(sum_sale,ffFixed,15,2),1,1,2,true,false, false);    //�����
			glFR->PrintString("������ ���������:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(sale_oplata_nal,ffFixed,15,2),1,1,2,true,false, false);    //�����
			glFR->PrintString("������ ������:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(sale_oplata_pc,ffFixed,15,2),1,1,2,true,false, false);    //�����

			glFR->PrintString("��������:",1,1,0,true,false, false);    //����
			glFR->PrintLine();
			glFR->PrintString("�����:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(sum_return_sale,ffFixed,15,2),1,1,2,true,false, false);    //�����
			glFR->PrintString("������ ���������:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(return_sale_oplata_nal,ffFixed,15,2),1,1,2,true,false, false);    //�����
			glFR->PrintString("������ ������:",1,1,0,true,false, false);    //����
			glFR->PrintString(FloatToStrF(return_sale_oplata_pc,ffFixed,15,2),1,1,2,true,false, false);    //�����

			if(glFR->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false,false)==false)
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
			glFR->CloseNoFiscalCheck();
			glFR->Cut(1);
			}
		catch(Exception &exception)
			{
			ShowMessage("������: "+exception.Message);
			}

}
//---------------------------------------------------------------------------

void __fastcall TFormaReportTouchForFR::ButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
