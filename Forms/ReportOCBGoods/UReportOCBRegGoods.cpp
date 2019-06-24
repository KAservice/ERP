//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReportOCBRegGoods.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TReportOCBRegGoods::TReportOCBRegGoods()
{
//
OutputDocDv=false;
}
//-----------------------------------------------------------------------------
TReportOCBRegGoods::~TReportOCBRegGoods()
{

if (DMQueryRead) DMQueryRead->kanRelease();
}
//-----------------------------------------------------------------------
bool TReportOCBRegGoods::Init(void)
{
bool result=false;





//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::CreateReport(void)
{
numRow=0;
numCol=0;
porNumStr=0;
porNumStrGrp=0;
NachOstReport=0;
PrihodReport=0;
RashodReport=0;
ConOstReport=0;
NumStrGrp=0;
IdTecFirm=0;
IdTecSklad=0;
IdTecGrpNom=0;
IdTecNom=0;
num_row_firm=0;
NachOstFirm=0;
PrihodFirm=0;
RashodFirm=0;
ConOstFirm=0;
num_row_sklad=0;
NachOstSklad=0;
PrihodSklad=0;
RashodSklad=0;
ConOstSklad=0;
num_row_grp_nom=0;
NachOstGrpNom=0;
PrihodGrpNom=0;
RashodGrpNom=0;
ConOstGrpNom=0;


TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;
//PrintForm->Visible=false;
//FormIndicator=new TFormIndicator(Application);
//FormIndicator->LabelInfo->Caption="Выполнение запроса...";
//FormIndicator->Caption="Выполнение запроса...";
//FormIndicator->Show();
//PrintForm->SS->Visible=false;
PrintForm->SS->BeginUpdate();

OutputZagolovokReport(PrintForm);
CreateReportOCB(PrintForm);
OutputPodavalReport(PrintForm);

PrintForm->SS->EndUpdate();
//delete FormIndicator;
//PrintForm->SS->Visible=true;
PrintForm->Show();
}
//----------------------------------------------------------------------------
AnsiString TReportOCBRegGoods::GetTextQuery(void)
{
AnsiString zapros="";


zapros=zapros+" select  *";

	zapros=zapros+" from OCB_RGGOODS_FULL_REPORT  (:PARAM_POSNACH, :PARAM_POSCON, :PARAM_IDFIRM, :PARAM_IDSKLAD, :PARAM_IDGRP, :PARAM_IDNOM)";



return zapros;
}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::CreateReportOCB(TSheetEditor *prForm)
{
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,InterfaceImpl);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(GetTextQuery());
DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSkl;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDGRP")->AsInt64=IdGrpNom;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;


DMQueryRead->pFIBQ->ExecQuery();




IdTecFirm=0;//IBQIDFIRM->AsInteger;
//num_row_firm=numRow;
//NewOutputStringFirm(prForm);


IdTecSklad=0;//IBQIDSKLAD->AsInteger;
//num_row_sklad=numRow;
//NewOutputStringSklad(prForm);


IdTecGrpNom=0;//;IBQIDGN->AsInteger;
//num_row_grp_nom=numRow;
//NewOutputStringGrpNom(prForm);

IdTecNom=0;

NachOstReport=0;
PrihodReport=0;
RashodReport=0;
ConOstReport=0;

NachOstFirm=0;
PrihodFirm=0;
RashodFirm=0;
ConOstFirm=0;

NachOstSklad=0;
PrihodSklad=0;
RashodSklad=0;
ConOstSklad=0;

NachOstGrpNom=0;
PrihodGrpNom=0;
RashodGrpNom=0;
ConOstGrpNom=0;

//FormIndicator->Max=DMQueryRead->pFIBQ->RecordCount;
//FormIndicator->Step=1;
//FormIndicator->LabelInfo->Caption="Построение печатной формы...";
//FormIndicator->Caption="Построение печатной формы...";
//FormIndicator->Start();

				while(!DMQueryRead->pFIBQ->Eof)
						{

                        //фирма
						if (DMQueryRead->pFIBQ->FieldByName("IDFIRM_PROC")->AsInt64==IdTecFirm)
                                {   //эта же фирма
								NachOstFirm=NachOstFirm+DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
														*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodFirm=PrihodFirm+DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
														*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodFirm=RashodFirm+DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
														*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstFirm=ConOstFirm+DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
														*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;

                                }
                        else
                                {
                                OutputStringItogiFirm(prForm);
								OutputStringFirm(prForm);
								IdTecFirm=DMQueryRead->pFIBQ->FieldByName("IDFIRM_PROC")->AsInt64;
                                IdTecSklad=0;
                                IdTecGrpNom=0;
                                IdTecNom=0;

								NachOstFirm=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodFirm=DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodFirm=DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstFirm=DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
                                }

                        //склад
						if (DMQueryRead->pFIBQ->FieldByName("IDSKLAD_PROC")->AsInt64==IdTecSklad)
                                {   //эта же склад
								NachOstSklad=NachOstSklad+DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodSklad=PrihodSklad+DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodSklad=RashodSklad+DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstSklad=ConOstSklad+DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiSklad(prForm);


                                OutputStringSklad(prForm);
								//NewOutputStringGrpNom(prForm);

								IdTecSklad=DMQueryRead->pFIBQ->FieldByName("IDSKLAD_PROC")->AsInt64;
                                IdTecGrpNom=0;
                                IdTecNom=0;

								NachOstSklad=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodSklad=DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodSklad=DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstSklad=DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;

                                }

                        //группа номенклатуры
						if (DMQueryRead->pFIBQ->FieldByName("IDGRP_PROC")->AsInt64==IdTecGrpNom)
                                {   //этот же группа
								NachOstGrpNom=NachOstGrpNom+DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
											*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodGrpNom=PrihodGrpNom+DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
											*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodGrpNom=RashodGrpNom+DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
											*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstGrpNom=ConOstGrpNom+DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
											*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
                                }
                        else
                                {

                                OutputStringItogiGrpNom(prForm);


                                OutputStringGrpNom(prForm);
								IdTecGrpNom=DMQueryRead->pFIBQ->FieldByName("IDGRP_PROC")->AsInt64;
                                IdTecNom=0;

								NachOstGrpNom=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								PrihodGrpNom=DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								RashodGrpNom=DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								ConOstGrpNom=DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
												*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
								}

//						//группа номенклатуры
//						if (DMQueryRead->pFIBQ->FieldByName("IDNOM_PROC")->AsInteger==IdTecNom)
//								{   //этот же группа
////								SumNachOstNom=SumNachOstNom+DMQueryRead->pFIBQ->FieldByName("NACHOSTSUM_PROC")->AsFloat;
////								SumPrihodNom=SumPrihodNom+DMQueryRead->pFIBQ->FieldByName("PRIHODSUM_PROC")->AsFloat;
////								SumRashodNom=SumRashodNom+DMQueryRead->pFIBQ->FieldByName("RASHODSUM_PROC")->AsFloat;
////								SumConOstNom=SumConOstNom+DMQueryRead->pFIBQ->FieldByName("CONOSTSUM_PROC")->AsFloat;
////								KolNachOstNom=KolNachOstNom+DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat;
////								KolPrihodNom=KolPrihodNom+DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat;
////								KolRashodNom=KolRashodNom+DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat;
////								KolConOstNom=KolConOstNom+DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat;
//								}
//						else
//								{
//
////                                OutputStringItogiNom(prForm);
//
//
//
////								IdTecNom=DMQueryRead->pFIBQ->FieldByName("IDNOM_PROC")->AsInteger;
//
////								SumNachOstNom=DMQueryRead->pFIBQ->FieldByName("NACHOSTSUM_PROC")->AsFloat;
////								SumPrihodNom=DMQueryRead->pFIBQ->FieldByName("PRIHODSUM_PROC")->AsFloat;
////								SumRashodNom=DMQueryRead->pFIBQ->FieldByName("RASHODSUM_PROC")->AsFloat;
////								SumConOstNom=DMQueryRead->pFIBQ->FieldByName("CONOSTSUM_PROC")->AsFloat;
////								KolNachOstNom=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat;
////								KolPrihodNom=DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat;
////								KolRashodNom=DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat;
////								KolConOstNom=DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat;
//								}

                       // OutputStringPart(prForm);

						NachOstReport=NachOstReport+DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
									*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
						PrihodReport=PrihodReport+DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
									*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
						RashodReport=RashodReport+DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
									*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
						ConOstReport=ConOstReport+DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
									*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
                     //   OtrSebRealReport=SumRealReport+IBQNACHOSTSUM->AsFloat;

                    //    if (DocCheckBox->Checked==true)
                    //            {
                    //            CreateReportDoc(prForm);
                    //            }

						OutputStringNom(prForm);

						if (OutputDocDv==true)
                                {
								CreateReportDoc(prForm);
								}

                        porNumStrGrp++;
						porNumStr++;
//						FormIndicator->StepIt();
						DMQueryRead->pFIBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiSklad(prForm);
OutputStringItogiGrpNom(prForm);
//OutputStringItogiNom(prForm);

DMQueryRead->pFIBQ->Close();
}
//---------------------------------------------------------------------------
void TReportOCBRegGoods::OutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
		cHeader->Size[2] = 250;
		cHeader->Size[3] = 60;
		cHeader->Size[4] = 100;
		cHeader->Size[5] = 90;
		cHeader->Size[6] = 90;
		cHeader->Size[7] = 100;
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Остатки и движения товаров c "+DateToStr(DateNach)
						+" по "+DateToStr(DateCon);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;



numRow++;
numRow++;

//if (PriceCheckBox->Checked==true)
//		{
//		cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
//		cell->Text = "Тип цен: "+TypePriceComboBox->Text;
//		cell->Style->HorzTextAlign = haLEFT;
//		cell->Style->Font->Size = 16;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
//		delete cell;
//		}


numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Номенклатура";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Цена";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Нач. остаток";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Приход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Расход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кон. остаток";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;



}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringFirm(TSheetEditor *prForm)
{
num_row_firm=numRow;

TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Фирма: "+ DMQueryRead->pFIBQ->FieldByName("NAMEFIRM_PROC")->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//розничная цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;


numRow++;



}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringItogiFirm(TSheetEditor *prForm)
{
if (num_row_firm==0) return;
TcxSSCellObject *cell;
if(NachOstFirm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_firm);
        cell->Text = FloatToStrF(NachOstFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodFirm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(PrihodFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodFirm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(RashodFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstFirm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_firm);
        cell->Text = FloatToStrF(ConOstFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringSklad(TSheetEditor *prForm)
{
num_row_sklad=numRow;

TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

//склад
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Склад: "+DMQueryRead->pFIBQ->FieldByName("NAMESKLAD_PROC")->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//розничная цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

numRow++;

}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringItogiSklad(TSheetEditor *prForm)
{
if ( num_row_sklad==0) return;
TcxSSCellObject *cell;
if(NachOstSklad!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_sklad);
        cell->Text = FloatToStrF(NachOstSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodSklad!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
        cell->Text = FloatToStrF(PrihodSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodSklad!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_sklad);
        cell->Text = FloatToStrF(RashodSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstSklad!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_sklad);
        cell->Text = FloatToStrF(ConOstSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_sklad] = 30;


}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringGrpNom(TSheetEditor *prForm)
{
num_row_grp_nom=numRow;

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
///cell->Text = IntToStr(porNumKlient);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//группа номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DMQueryRead->pFIBQ->FieldByName("NAMEGRP_PROC")->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//розничная цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//нач. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

numRow++;



}
//-----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringItogiGrpNom(TSheetEditor *prForm)
{
if ( num_row_grp_nom==0) return;
TcxSSCellObject *cell;
if(NachOstGrpNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_grp_nom);
        cell->Text = FloatToStrF(NachOstGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodGrpNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
        cell->Text = FloatToStrF(PrihodGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodGrpNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_nom);
        cell->Text = FloatToStrF(RashodGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstGrpNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_grp_nom);
        cell->Text = FloatToStrF(ConOstGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенлатура
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DMQueryRead->pFIBQ->FieldByName("NAMENOM_PROC")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//розничная цена
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
	}
if (DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat,ffFixed,10,3)
//										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
//cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;


//нач лстаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
	}
if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat,ffFixed,10,3)
										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}

if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;
numCol++;


//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
		*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
	}
if (DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if(DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat,ffFixed,10,3)
										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}
if (DMQueryRead->pFIBQ->FieldByName("PRIHODKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
	}
if (DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if (DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat!=0)
	{
cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat,ffFixed,10,3)
										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}
if (DMQueryRead->pFIBQ->FieldByName("RASHODKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
if (DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
				*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
	}
if (DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if (DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat!=0)
	{
	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat,ffFixed,10,3)
										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}
if (DMQueryRead->pFIBQ->FieldByName("CONOSTKOL_PROC")->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;



numRow++;
numRow++;

}

//---------------------------------------------------------------------------
void TReportOCBRegGoods::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(NachOstReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(PrihodReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(RashodReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(ConOstReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;


numCol++;
//prForm->SS->History->Clear();
}
//----------------------------------------------------------------------------
AnsiString TReportOCBRegGoods::GetTextZaprosDoc(void)
{
AnsiString zapros="";
zapros=zapros+" select rggoods_dv.posdoc_rggoods_dv,       ";
zapros=zapros+"         rggoods_dv.tdv_rggoods_dv,         ";
zapros=zapros+"         galldoc.numdoc,                    ";
zapros=zapros+"         galldoc.tdoc,                      ";
zapros=zapros+"         rggoods_dv.kol_rggoods_dv          ";
zapros=zapros+" from rggoods_dv                            ";
zapros=zapros+" left outer join galldoc on galldoc.iddoc=rggoods_dv.iddoc_rggoods_dv               ";
zapros=zapros+" where (rggoods_dv.posdoc_rggoods_dv  between :PARAM_POSNACH and :PARAM_POSCON)     ";
zapros=zapros+"         and rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM                             ";
zapros=zapros+"         and rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD                           ";
zapros=zapros+"         and rggoods_dv.idnom_rggoods_dv=:PARAM_IDNOM                               ";
zapros=zapros+"         and rggoods_dv.rprice_rggoods_dv=:PARAM_RPRICE                             ";
zapros=zapros+" order by rggoods_dv.posdoc_rggoods_dv                                              ";

return zapros;
}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::CreateReportDoc(TSheetEditor *prForm)
{
TecConOstatokPoDocKol=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat;
TecConOstatokPoDocSum=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;

InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryReadDoc);
DMQueryReadDoc->Init(InterfaceMainObject,InterfaceImpl);
DMQueryReadDoc->pFIBQ->Close();
DMQueryReadDoc->pFIBQ->SQL->Clear();
DMQueryReadDoc->pFIBQ->SQL->Add(GetTextZaprosDoc());
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=
						DMQueryRead->pFIBQ->FieldByName("IDFIRM_PROC")->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=
						DMQueryRead->pFIBQ->FieldByName("IDSKLAD_PROC")->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=
						DMQueryRead->pFIBQ->FieldByName("IDNOM_PROC")->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_RPRICE")->AsFloat=
						DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;


DMQueryReadDoc->pFIBQ->ExecQuery();
while(!DMQueryReadDoc->pFIBQ->Eof)
		{
		OutputStringDoc(prForm);
		DMQueryReadDoc->pFIBQ->Next();
        }

DMQueryReadDoc->pFIBQ->Close();
DMQueryReadDoc->kanRelease();
}
//----------------------------------------------------------------------------
void TReportOCBRegGoods::OutputStringDoc(TSheetEditor *prForm)
{
prForm->SS->ActiveSheet->Rows->Size[numRow]=15;
prForm->SS->ActiveSheet->Rows->Size[numRow+1]=15;

TcxSSCellObject *cell;
numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенлатура
//glGetNameDoc(IBQDocTDOC->AsString)
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DMQueryReadDoc->pFIBQ->FieldByName("TDOC")->AsString)+"  №"+
				DMQueryReadDoc->pFIBQ->FieldByName("NUMDOC")->AsString+" от "+
				DMQueryReadDoc->pFIBQ->FieldByName("POSDOC_RGGOODS_DV")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//розничная цена
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
//if (DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
//	{
//	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
//	}
//if (DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat<0)
//	{
//	cell->Style->Font->FontColor=2;
//	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat,ffFixed,10,3)
//										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
//cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;


//нач лстаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
//			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
//	{
//	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
//						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
//	}
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
//	{
//	cell->Style->Font->FontColor=2;
//	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat!=0)
//	{
//	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat,ffFixed,10,3)
//										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
//	}
//
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
//	{
//	cell->Style->Font->FontColor=2;
//	}
delete cell;
numCol++;


//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_RGGOODS_DV")->AsInteger==0)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
		*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
		TecConOstatokPoDocSum=TecConOstatokPoDocSum+DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_RGGOODS_DV")->AsInteger==0)
	{
	if(DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat,ffFixed,10,3);
									   //	+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
		TecConOstatokPoDocKol=TecConOstatokPoDocKol+DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	cell->Style->HorzTextAlign = haRIGHT;
	}
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_RGGOODS_DV")->AsInteger==1)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
		TecConOstatokPoDocSum=TecConOstatokPoDocSum-DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat
						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_RGGOODS_DV")->AsInteger==1)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat,ffFixed,10,3);
									   //	+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
		TecConOstatokPoDocKol=TecConOstatokPoDocKol-DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}


delete cell;
numCol++;

//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 8;

if (TecConOstatokPoDocSum!=0)
	{
	cell->Text = FloatToStrF(TecConOstatokPoDocSum,ffFixed,10,2);
	}
if (TecConOstatokPoDocSum<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (TecConOstatokPoDocKol!=0)
	{
	cell->Text = FloatToStrF(TecConOstatokPoDocKol,ffFixed,10,3);
										//+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}
if (TecConOstatokPoDocKol<0)
	{
	cell->Style->Font->FontColor=2;
	}

delete cell;
numCol++;



numRow++;
numRow++;

}
//----------------------------------------------------------------------------
