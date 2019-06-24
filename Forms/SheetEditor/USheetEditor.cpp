//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "USheetEditor.h"
#include "UModifyFormSheetEditor.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

#pragma link "dxPSContainerLnk"
#pragma link "dxPSCore"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"
#pragma link "dxPSBaseGridLnk"
#pragma link "dxPScxSSLnk"
#pragma link "dxBkgnd"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxBkgnd"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxSSheet"
#pragma link "dxBkgnd"
#pragma link "dxPrnDev"
#pragma link "dxPrnPg"
#pragma link "dxPSBaseGridLnk"
#pragma link "dxPSCompsProvider"
#pragma link "dxPSCore"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"
#pragma resource "*.dfm"

//TSheetEditor *SheetEditor;
//---------------------------------------------------------------------------
__fastcall TSheetEditor::TSheetEditor(TComponent* Owner)
  : TForm(Owner)
{
  TForm::TForm(Owner);
  cbxFont->Items->Assign(Screen->Fonts);
  cbxFont->Text = "Tahoma";
  cbxSize->Text = "10";
  FSummaryItemHeight = 10;
  #if __BORLANDC__ >= 0x0560
    pmRedo->AutoHotkeys = maManual;
    pmUndo->AutoHotkeys = maManual;
  #endif
  
  
}

//---------------------------------------------------------------------------
void __fastcall TSheetEditor::NewSheet(String SheetName)
{
//  TFeatureChildForm* Child;
//	Child = new TFeatureChildForm(this);
//  if (SheetName == "")
//  	Child->Caption = "WorkBook - " + IntToStr(this->MDIChildCount);
//  else
//    Child->Caption = ExtractFileName(SheetName);
//  Child->cxSpreadSheetBook->OnSetSelection = cxSpreadBookSetSelection;
//  Child->SetSelection();
}


void __fastcall TSheetEditor::actCloseWorkBookExecute(TObject *Sender)
{
  ActiveMDIChild->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actExitExecute(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::SaveSpreadSheet1Click(TObject *Sender)
{
  String FileName;
  if(OpenDialog->Execute())
  {
    FileName = ChangeFileExt(OpenDialog->FileName, ".xls");
    SheetBook->SaveToFile(FileName);
    ActiveMDIChild->Caption = FileName;
  }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actAutomaticCalcExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->AutoRecalc = ((TCustomAction*)Sender)->Checked;
  if (SheetBook->AutoRecalc)
      SheetBook->Recalc();
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actRecalcFormulasExecute(TObject *Sender)
{
  CheckMenuItem(Sender); 
  SheetBook->Recalc();
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actCopyExecute(TObject *Sender)
{
  TRect rec;
  rec = SheetBook->ActiveSheet->SelectionRect;
  SheetBook->ActiveSheet->Copy(rec, false);
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::AlwaysEnabled(TObject *Sender)
{
  ((TCustomAction*)Sender)->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actCutExecute(TObject *Sender)
{
  TRect rec;
  rec = SheetBook->SelectionRect;
  SheetBook->ActiveSheet->Copy(rec, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actPasteExecute(TObject *Sender)
{
  TRect rec;
  rec = SheetBook->SelectionRect;
  SheetBook->ActiveSheet->Paste(Point(rec.left, rec.top));
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::edtCellEditChange(TObject *Sender)
{
  if (FIsUpdate) return;
  TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(ActiveSpreadSheet->SelectionRect.Left,
    ActiveSpreadSheet->SelectionRect.Top);
  try {
    CellObject->SetCellText(((TEdit*)Sender)->Text, false);
  }
  __finally {
    delete CellObject;
  }
  SheetBook->UpdateControl();
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::edtCellEditExit(TObject *Sender)
{
  TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(ActiveSpreadSheet->SelectionRect.Left,
    ActiveSpreadSheet->SelectionRect.Top);
  try {
    CellObject->Text = CellObject->Text;
  }
  __finally {
    delete CellObject;
  }
  SheetBook->UpdateControl();
  SheetBook->SetFocus();
  cxSpreadBookSetSelection(this, ActiveSpreadSheet);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::SetStates()
{
  TFontStyles AStyle;
  TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(ActiveSpreadSheet->SelectionRect.Left,
    ActiveSpreadSheet->SelectionRect.Top);
    try
    {
      tbLeftAlign->Down =  (CellObject->DisplayTextAlignment == dtaLEFT) ||
        (CellObject->DisplayTextAlignment == dtaFILL) || (CellObject->DisplayTextAlignment == dtaJUSTIFY);
      tbCenterAlign->Down = CellObject->DisplayTextAlignment == dtaCENTER;
      tbRightAlign->Down = CellObject->DisplayTextAlignment == dtaRIGHT;

      AStyle = CellObject->Style->Font->Style;

      tbBold->Down = AStyle.Contains(fsBold);
      tbItalic->Down = AStyle.Contains(fsItalic);
      tbUnderline->Down = AStyle.Contains(fsUnderline);
      tbStrikeOut->Down = AStyle.Contains(fsStrikeOut);

      edtCellEdit->Text = CellObject->Text;
      cbxFont->Text = CellObject->Style->Font->Name;
      cbxSize->Text = IntToStr(CellObject->Style->Font->Size);
    }
    __finally
    {
      delete CellObject;
    }
    {
      actBeveledLookandFeel->Checked = SheetBook->PainterType == ptOfficeXPStyle;
      actBufferedpaint->Checked = SheetBook->BufferedPaint;
      actShowcaptions->Checked = SheetBook->ShowCaptionBar;
      actShowgrid->Checked = SheetBook->ShowGrid;
      actShowheaders->Checked = SheetBook->ShowHeaders;
      actShowformulas->Checked = SheetBook->ShowFormulas;
      actR1C1Referencestyle->Checked = SheetBook->R1C1ReferenceStyle;
      actAutomaticCalc->Checked = SheetBook->AutoRecalc;
    }
}
String __fastcall TSheetEditor::GetCellText(TRect SelectionRect, bool R1C1)
{
  return SheetBook->CellsNameByRef(SheetBook->ActivePage, SelectionRect, true);
}

void __fastcall TSheetEditor::cxSpreadBookSetSelection(TObject *Sender, TcxSSBookSheet *ASheet)
{
  try {
    FIsUpdate = true;
    SetStates();
    pnCellsRect->Caption = GetCellText(ASheet->SelectionRect, SheetBook->R1C1ReferenceStyle);
    }
  __finally{
    FIsUpdate = False;
   }
}

void __fastcall TSheetEditor::cbxSizeKeyPress(TObject *Sender, char &Key)
{
  if (Key == 13)
    _WINUSER_::SetFocus(SheetBook->Handle);
  else
    if ((Key < 48) || (Key > 58))
      Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actBeveledLookandFeelExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->PainterType = (TcxSSPainterType)((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actBufferedpaintExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->BufferedPaint = ((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowcaptionsExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->ShowCaptionBar = ((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowgridExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->ShowGrid = ((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowheadersExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->ShowHeaders = ((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowformulasExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->ShowFormulas = ((TCustomAction*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actR1C1ReferencestyleExecute(TObject *Sender)
{
  if (IsUpdate) return;
  CheckMenuItem(Sender);
  SheetBook->R1C1ReferenceStyle = ((TCustomAction*)Sender)->Checked;
  pnCellsRect->Caption = GetCellText(ActiveSpreadSheet->SelectionRect, SheetBook->R1C1ReferenceStyle);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::SetValue(TStyleValues AValueSet, TFontStyles AStyles, TStyleValue AFlag, TFontStyle ANeedStyle,
    TFontStyles *ASetStyles)
{
  if (AValueSet.Contains(AFlag)) {
    if (AStyles.Contains(ANeedStyle))
      ASetStyles->operator <<(ANeedStyle);
    else
      ASetStyles->operator >>(ANeedStyle);
  }
}

void __fastcall TSheetEditor::SetCellsStyle(TStyleValues AValuesSet, TcxHorzTextAlign AAlign,
  int AFontSize, String AFontName, TFontStyles AStyles){
  TFontStyles AStyle;
  int i, j;
  try {
    SheetBook->BeginUpdate();
    int lf = ActiveSpreadSheet->SelectionRect.left;
    int rg = ActiveSpreadSheet->SelectionRect.right;
    int tp = ActiveSpreadSheet->SelectionRect.top;
    int bt = ActiveSpreadSheet->SelectionRect.bottom;
    TcxSSCellObject *CellObject;
      for (i = lf; i <= rg; i++)
        for (j = tp; j <= bt; j++) {
          CellObject = ActiveSpreadSheet->GetCellObject(i, j);
          try {
              AStyle = CellObject->Style->Font->Style;
              if (AValuesSet.Contains(svFontName))
                CellObject->Style->Font->Name = AFontName;
              if (AValuesSet.Contains(svSize))
                CellObject->Style->Font->Size = AFontSize;
              if (AValuesSet.Contains(svAlign))
                CellObject->Style->HorzTextAlign = AAlign;
              SetValue(AValuesSet, AStyles, svBold, fsBold, &AStyle);
              SetValue(AValuesSet, AStyles, svItalic, fsItalic, &AStyle);
              SetValue(AValuesSet, AStyles, svUnderline, fsUnderline, &AStyle);
              SetValue(AValuesSet, AStyles, svStrikeOut, fsStrikeOut, &AStyle);
              CellObject->Style->Font->Style = AStyle;
            }
          __finally {
          delete CellObject;
          }
        }
  }
  __finally
  {
    SheetBook->EndUpdate();
    SheetBook->UpdateControl();
  }
}

void __fastcall TSheetEditor::actCellLeftAlignExecute(TObject *Sender)
{
  SetCellsStyle(TStyleValues() << svAlign, haLEFT, 0, cbxFont->Text, TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actCellRightAlignExecute(TObject *Sender)
{
  SetCellsStyle(TStyleValues() << svAlign, haRIGHT, 0, cbxFont->Text, TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actBoldExecute(TObject *Sender)
{
  if (tbBold->Down){
    SetCellsStyle(TStyleValues() << svBold, haGENERAL, 0, "", TFontStyles() << fsBold);
  }
  else
    SetCellsStyle(TStyleValues() << svBold, haGENERAL, 0, "", TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actFontSizeExecute(TObject *Sender)
{
  int ASize;
  if (Cxssutils::cxTryStrToInt(cbxSize->Text, ASize)) 
    SetCellsStyle(TStyleValues() << svSize, haGENERAL, ASize, cbxFont->Text, TFontStyles());
}

void __fastcall TSheetEditor::actCellCenterAlignExecute(TObject *Sender)
{
  SetCellsStyle(TStyleValues() << svAlign, haCENTER, 0, cbxFont->Text, TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actMergeCellsExecute(TObject *Sender)
{
  ActiveSpreadSheet->SetMergedState(ActiveSpreadSheet->SelectionRect, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actSplitCellsExecute(TObject *Sender)
{
  ActiveSpreadSheet->SetMergedState(ActiveSpreadSheet->SelectionRect, false);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::CalculateSummary(int AType)
{
  String S;
  TRect ARect;
  String AFunc[5] = {"Sum", "Average", "Count", "Max", "Min"};
  try {
    ARect = SheetBook->SelectionRect;
    S = SheetBook->CellsNameByRef(SheetBook->ActivePage, ARect, false);
    TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(ARect.Right, ARect.Bottom + 1);
    try {
      CellObject->Text = "=" + AFunc[AType] + "(" + S + ")";
    }
    __finally {
      delete CellObject;
     }
  }
  __finally {
    SheetBook->UpdateControl();
    }
}

void __fastcall TSheetEditor::actSummaryExecute(TObject *Sender)
{
  CalculateSummary(((TComponent*)Sender)->Tag);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actRowExecute(TObject *Sender)
{
   ActiveSpreadSheet->InsertCells(ActiveSpreadSheet->SelectionRect, msAllRow);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actColumnExecute(TObject *Sender)
{
   ActiveSpreadSheet->InsertCells(ActiveSpreadSheet->SelectionRect, msAllCol);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actSheetExecute(TObject *Sender)
{
  SheetBook->PageCount++;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actFontExecute(TObject *Sender)
{
  SetCellsStyle(TStyleValues() << svFontName, haGENERAL, 0, cbxFont->Text, TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actSortAscendingExecute(TObject *Sender)
{
  TcxSortType *SortType;
  SortType = new TcxSortType;
  *SortType = Cxsstypes::stAscending;
  if (((TComponent*)Sender)->Tag)
    *SortType = Cxsstypes::stDescending;
  try{
    ActiveSpreadSheet->Sort(ActiveSpreadSheet->SelectionRect, SortType, 0);
  }
  __finally {
    delete SortType;
  }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actStrikeOutExecute(TObject *Sender)
{
  if (tbStrikeOut->Down){
    SetCellsStyle(TStyleValues() << svStrikeOut, haGENERAL, 0, "", TFontStyles() << fsStrikeOut);
  }
  else
    SetCellsStyle(TStyleValues() << svStrikeOut, haGENERAL, 0, "", TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actUnderlineExecute(TObject *Sender)
{
  if (tbUnderline->Down){
    SetCellsStyle(TStyleValues() << svUnderline, haGENERAL, 0, "", TFontStyles() << fsUnderline);
  }
  else
    SetCellsStyle(TStyleValues() << svUnderline, haGENERAL, 0, "", TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actItalicExecute(TObject *Sender)
{
  if (tbItalic->Down){
    SetCellsStyle(TStyleValues() << svItalic, haGENERAL, 0, "", TFontStyles() << fsItalic);
  }
  else
    SetCellsStyle(TStyleValues() << svItalic, haGENERAL, 0, "", TFontStyles());
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowRowExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, false, true, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actHideRowExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, false, true, false);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actHideColExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, true, false, false);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowColExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, true, false, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actFormatCellsExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->FormatCells(ActiveSpreadSheet->SelectionRect);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actHideCellsExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, true, true, false);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actShowCellsExecute(TObject *Sender)
{
  if (IsUpdate) return;
  ActiveSpreadSheet->SetVisibleState(ActiveSpreadSheet->SelectionRect, true, true, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actCellsExecute(TObject *Sender)
{
  TModifyFormSheetEditor *Modify;
  Modify = new TModifyFormSheetEditor(this);
     try {
      div_t sHeight, mHeight, sWidth, mWidth;
      sHeight = div(SheetBook->Height, 2);
      mHeight = div(Modify->Height, 2);
      Modify->Top = (SheetBook->Top + sHeight.quot) + mHeight.quot;

      sWidth = div(SheetBook->Width, 2);
      mWidth = div(Modify->Width, 2);
      Modify->Left = (SheetBook->Left + sWidth.quot) + mWidth.quot;
      TcxSSModifyType ModifyType = mtDelete;
      if (((TComponent*)Sender)->Tag)
        ModifyType = mtInsert;
       if (Modify->Execute(ModifyType))
         if (ModifyType == mtInsert)
           ActiveSpreadSheet->InsertCells(ActiveSpreadSheet->SelectionRect, Modify->Modify);
          else
            ActiveSpreadSheet->DeleteCells(ActiveSpreadSheet->SelectionRect, Modify->Modify);
     }
     __finally {
       Modify->Free();
     }
}
//---------------------------------------------------------------------------
void __fastcall TSheetEditor::actOpenSpreadSheetExecute(TObject *Sender)
{
  if (OpenDialog->Execute())
  {
    NewSheet(OpenDialog->FileName);
    try {
      try {
        SheetBook->LoadFromFile(OpenDialog->FileName);
      }
      catch (Exception &err) {
        Application->ShowException(&err);
        ActiveMDIChild->Close();
      }
    }
    __finally {
      actShowgrid->Checked = SheetBook->ShowGrid;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TSheetEditor::actSaveSpeadSheetExecute(TObject *Sender)
{
  String AFileName;
  if (SaveDialog->Execute())
  {
    AFileName = ChangeFileExt(SaveDialog->FileName, ".xls");
    SheetBook->SaveToFile(AFileName);
    ActiveMDIChild->Caption = ExtractFileName(AFileName);
  }
}

void __fastcall TSheetEditor::edtCellEditKeyPress(TObject *Sender, char &Key)
{
  if (Key == 13)
  {
    _WINUSER_::SetFocus(SheetBook->Handle);
    edtCellEditExit(Sender);
  }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::SetHorzStyle(TRect ARect, int ARow, TcxSSEdgeLineStyle AStyle)
{
  if (AStyle != lsNone)
  {
    for(int i = ARect.Left; i <= ARect.Right; i++)
    {
      TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(i, ARow);
      try {
        CellObject->Style->Borders->Edges[eTop]->Style = AStyle;
      }
    __finally {
        delete CellObject;
      }
    }
  }
}
void __fastcall TSheetEditor::SetVertStyle(TRect ARect, int ACol, TcxSSEdgeLineStyle AStyle)
{
    if (AStyle != lsNone)
      for (int i = ARect.Top; i <= ARect.Bottom; i++)
      {
        TcxSSCellObject *CellObject = ActiveSpreadSheet->GetCellObject(ACol, i);
        try {
          CellObject->Style->Borders->Edges[eLeft]->Style = AStyle;
        }
        __finally {
          delete CellObject;
        }
      }
}

void __fastcall TSheetEditor::MeasureItem(TObject *Sender, TCanvas *ACanvas,
      int &Width, int &Height)
{
  Width = 14;
  Height = 24;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::DrawItem(TObject *Sender, TCanvas *ACanvas,
      TRect &ARect, bool Selected)
{
  if (Selected)
    ACanvas->Brush->Color = clHighlight;
  else
    ACanvas->Brush->Color = clMenu;
  ACanvas->Brush->Style = bsSolid;
  ACanvas->FillRect(ARect);
  imgBordersImages->Draw(ACanvas, ARect.Left + 2, ARect.Top + 2, ((TMenuItem*)Sender)->ImageIndex, true);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::BordersClick(TObject *Sender)
{
  TcxSSEdgeLineStyle AOutBorders[12][4]  =
    {{lsDefault, lsDefault, lsDefault, lsDefault},
     {lsNone, lsNone, lsNone, lsDouble},
     {lsNone, lsThin, lsNone, lsThick},
     {lsNone, lsNone, lsNone, lsThin},
     {lsNone, lsNone, lsNone, lsThick},
     {lsThin, lsThin, lsThin, lsThin},
     {lsThin, lsNone, lsNone, lsNone},
     {lsNone, lsThin, lsNone, lsThin},
     {lsThin, lsThin, lsThin, lsThin},
     {lsNone, lsNone, lsThin, lsNone},
     {lsNone, lsThin, lsNone, lsDouble},
     {lsThick, lsThick, lsThick, lsThick}};

  TcxSSEdgeLineStyle AInBorders[2] = {lsDefault, lsThin};
  TRect ARect;
  SheetBook->BeginUpdate();
  try {
    ARect = ActiveSpreadSheet->SelectionRect;
    int AKey = ((TMenuItem*)Sender)->ImageIndex;
    SetVertStyle(ARect, ARect.Left, AOutBorders[AKey][eLeft]);
    SetHorzStyle(ARect, ARect.Top, AOutBorders[AKey][eTop]);
    SetVertStyle(ARect, ARect.Right + 1, AOutBorders[AKey][eRight]);
    SetHorzStyle(ARect, ARect.Bottom + 1, AOutBorders[AKey][eBottom]);
    for (int i = ARect.Top + 1; i <= ARect.Bottom; i++)
      SetHorzStyle(ARect, i, AInBorders[AKey == 5]);
    for (int i = ARect.Left + 1; i <= ARect.Right; i++)
      SetVertStyle(ARect, i, AInBorders[AKey == 5]);
  }
  __finally{
    SheetBook->EndUpdate();
    SheetBook->UpdateControl();
  }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actSaveAsExecute(TObject *Sender)
{
  if (SaveDialog->Execute()) {
    SheetBook->SaveToFile(SaveDialog->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSheetEditor::tbBorderStyleClick(TObject *Sender)
{
  TRect ARect;
  TPoint APoint;
  ARect = tbBorderStyle->BoundsRect;
  ARect.Left = tbsFormatting->ClientToScreen(Point(ARect.Left, ARect.Top)).x;
  ARect.Top = tbsFormatting->ClientToScreen(Point(ARect.Left, ARect.Top)).y;

  ARect.Right = tbsFormatting->ClientToScreen(Point(ARect.Right, ARect.Bottom)).x;
  ARect.Bottom = tbsFormatting->ClientToScreen(Point(ARect.Right, ARect.Bottom)).y;

  tbBorderStyle->Down = true;
  pmBorders->Popup(ARect.Left, ARect.Bottom);
  tbBorderStyle->Down = false;
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::cbxFontKeyPress(TObject *Sender, char &Key)
{
  if (Key == 13)
    _WINUSER_::SetFocus(SheetBook->Handle);
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::pmUndoPopup(TObject *Sender)
{
  while (((TPopupMenu*)Sender)->Items->Count > 0)
    ((TPopupMenu*)Sender)->Items->Delete(0);
  TMenuItem *Item;
  for(int i=0; i <= SheetBook->History->UndoActions->Count; i++)
  {
     Item = new TMenuItem(static_cast<TPopupMenu*>(Sender));
     if (i < SheetBook->History->UndoActions->Count)
       Item->Caption = SheetBook->History->UndoActions->Item[i]->Description;
     else
       Item->Caption = " ";
     Item->OnMeasureItem = URMeasureItem;
     Item->OnDrawItem = URDrawItem;
     Item->OnClick = UndoItemClick;
     static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
  }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::pmRedoPopup(TObject *Sender)
{
  while (((TPopupMenu*)Sender)->Items->Count > 0)
    ((TPopupMenu*)Sender)->Items->Delete(0);

  TMenuItem *Item;
   for(int i=0; i <= SheetBook->History->RedoActions->Count; i++)
   {
      Item = new TMenuItem((TComponent*)Sender);
      if (i < SheetBook->History->RedoActions->Count)
        Item->Caption = SheetBook->History->RedoActions->Item[i]->Description;
      else
        Item->Caption = " ";
      Item->OnMeasureItem = URMeasureItem;
      Item->OnDrawItem = URDrawItem;
      Item->OnClick = RedoItemClick;
      ((TPopupMenu*)Sender)->Items->Add(Item);
   }
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::URMeasureItem(TObject *Sender,
      TCanvas *ACanvas, int &Width, int &Height)
{
  Width = 90;
  if (((TMenuItem*)Sender)->MenuIndex == ((TPopupMenu*)((TComponent*)Sender)->Owner)->Items->Count - 1)
    Height = ACanvas->TextHeight("W") + FSummaryItemHeight; else
  Height = ACanvas->TextHeight("W");
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::URDrawItem(TObject *Sender,
      TCanvas *ACanvas, const TRect &ARect, bool Selected)
{
  String Str;
  if (((TComponent*)Sender)->Owner->Name == "pmUndo")
    Str = "Undo %d Actions";
  else
    Str = "Redo %d Actions";
  DrawUndoRedoItem((TPopupMenu*)((TComponent*)Sender)->Owner, (TMenuItem*)Sender, ACanvas, ARect, Selected, Str);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::UndoItemClick(TObject *Sender)
{
  if (((TMenuItem*)Sender)->MenuIndex < ((TPopupMenu*)((TMenuItem*)Sender)->Owner)->Items->Count - 1)
    SheetBook->History->Undo(((TMenuItem*)Sender)->MenuIndex + 1);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::RedoItemClick(TObject *Sender)
{
  if (((TMenuItem*)Sender)->MenuIndex < ((TPopupMenu*)((TMenuItem*)Sender)->Owner)->Items->Count - 1)
    SheetBook->History->Redo(((TMenuItem*)Sender)->MenuIndex + 1);
}
//---------------------------------------------------------------------------

void __fastcall UpdatePreviousItems(TPopupMenu *APopupMenu, TCanvas *ACanvas, const TRect ARect, int AIndex)
{
  TRect Rec;
  Rec = ARect;
  String Str;
  int i;
  for(i = AIndex - 1; i >= 0; i--){
    Rec = Rect(Rec.Left, ACanvas->TextHeight('W') * i, Rec.Right, ACanvas->TextHeight('W') * (i + 1));
    ACanvas->Brush->Color = clHighlight;
    ACanvas->Brush->Style = bsSolid;
    ACanvas->FillRect(Rec);
    ACanvas->TextRect(Rec, Rec.Left, Rec.Top, APopupMenu->Items[0].Items[i]->Caption);
  }
}
void __fastcall UpdateNextItems(TPopupMenu *APopupMenu, TCanvas *ACanvas, TRect ARect, int Index)
{
  TRect Rec;
  Rec = ARect;
  String Str;
  for (int i=Index+1; i <= APopupMenu->Items->Count - 2; i++){
    Rec = Rect(Rec.Left, Rec.Top + ACanvas->TextHeight('W'), Rec.Right, Rec.Bottom + ACanvas->TextHeight('W'));
    ACanvas->Brush->Color = clMenu;
    ACanvas->Brush->Style = bsSolid;
    ACanvas->FillRect(Rec);
    ACanvas->TextRect(Rec, Rec.Left, Rec.Top, APopupMenu->Items[0].Items[i]->Caption);
  }
}
void __fastcall TSheetEditor::DrawActionsCount(TPopupMenu *APopupMenu, TCanvas *ACanvas, TMenuItem *ASender, const TRect ARect, String AInfoStr)
{
  TRect Rec;
  int ActionsCount, Btn;
  String Str;
  if ((APopupMenu->Items->Count - 1) == ASender->MenuIndex)
  {
    Btn = (APopupMenu->Items->Count - 1) * ACanvas->TextHeight('W') - 1 + (ARect.Bottom -  ARect.Top);
    ActionsCount = ASender->MenuIndex;
  } else
  {
    Btn = (APopupMenu->Items->Count - 1) * ACanvas->TextHeight('W') - 1 + FSummaryItemHeight + (ARect.Bottom -  ARect.Top);
    ActionsCount = ASender->MenuIndex + 1;
  }
  Rec = Rect(ARect.Left + 1, (APopupMenu->Items->Count - 1) * ACanvas->TextHeight('W') + 1,
    ARect.Right - 1, Btn);

  ACanvas->Brush->Color = clMenu;
  ACanvas->Brush->Style = bsSolid;
  ACanvas->FillRect(Rec);

  Str = Format(AInfoStr, ARRAYOFCONST(((int)ActionsCount)));
  div_t lft = div(Rec.Left + Rec.Right, 2), tw = div(ACanvas->TextWidth(Str), 2);
  int leftpar = lft.quot - tw.quot;
  div_t tp = div(Rec.Top + Rec.Bottom, 2), th = div(ACanvas->TextHeight(Str), 2);
  int toppar = tp.quot - th.quot;
  Frame3D(ACanvas, Rec, clBtnShadow, clBtnHighlight, 1);
  ACanvas->TextRect(Rec, leftpar, toppar, Str);
}

void __fastcall TSheetEditor::DrawUndoRedoItem(TPopupMenu *APopupMenu, TMenuItem *ASender, TCanvas *ACanvas, const TRect ARect, bool Selected, String AInfoStr)
{
  if (ASender->MenuIndex == (APopupMenu->Items->Count - 1)) {
    ACanvas->Brush->Color = clMenu;
    ACanvas->Brush->Style = bsSolid;
    ACanvas->FillRect(ARect);
    if (Selected){
      UpdatePreviousItems(APopupMenu, ACanvas, ARect, ASender->MenuIndex);
    }
  }
  else{
    if (Selected){
      ACanvas->Brush->Color = clHighlight;
      ACanvas->Brush->Style = bsSolid;
      ACanvas->FillRect(Rect(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom));
      UpdatePreviousItems(APopupMenu, ACanvas, ARect, ASender->MenuIndex);
    }
    else {
      ACanvas->Brush->Color = clMenu;
      ACanvas->Brush->Style = bsSolid;
      ACanvas->FillRect(ARect);
      UpdateNextItems(APopupMenu, ACanvas, ARect, ASender->MenuIndex);
    }
    ACanvas->TextRect(ARect, ARect.Left, ARect.Top, ASender->Caption);
  }
  DrawActionsCount(APopupMenu, ACanvas, ASender, ARect, AInfoStr);
}

void __fastcall TSheetEditor::actHistory(TObject *Sender)
{
  ((TCustomAction*)(Sender))->Enabled = (SheetBook->History->UndoActions->Count > 0);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actRedoUpdate(TObject *Sender)
{
  ((TCustomAction*)(Sender))->Enabled = (SheetBook->History->RedoActions->Count > 0);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actUndoExecute(TObject *Sender)
{
  SheetBook->History->Undo(1);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actRedoExecute(TObject *Sender)
{
  SheetBook->History->Redo(1);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::IsEditorMode(TObject *Sender)
{

 // ((TCustomAction*)Sender)->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::SSSheetPopupMenu(
      TObject *Sender, int X, int Y)
{
pmSheetPopup->Popup(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TSheetEditor::SSContextPopup(
      TObject *Sender, TPoint &MousePos, bool &Handled)
{
  if ((MousePos.x == -1) && (MousePos.y == -1))
  {
    MousePos = this->ClientToScreen(Point(0, 0));
  }
  //SheetEditor->pmSheetPopup->Popup(MousePos.x, MousePos.y);
  pmSheetPopup->Popup(MousePos.x, MousePos.y);
  Handled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSheetEditor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//delete SS;
Action=caFree;        
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::FormActivate(TObject *Sender)
{
SS->SetFocus();          
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::actPreeViewExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Preview(true);         
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actPrintExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Print(true, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actPageSetupExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->PageSetup();        
}
//---------------------------------------------------------------------------


void __fastcall TSheetEditor::ToolButtonPrinrAllClick(TObject *Sender)
{
//печать всех страниц
//dxComponentPrinter1->ReportLink[0]->PrintPages	
}
//---------------------------------------------------------------------------

void __fastcall TSheetEditor::actPrintNoDialogExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Print(false, NULL);
}
//---------------------------------------------------------------------------
void TSheetEditor::SetRowsHeightAuto(int y, int x1, int x2,  int x_max, AnsiString s)
{
TcxSSCellObject *cell;
TcxSSCellObject *cell2;
cell2 = SS->ActiveSheet->GetCellObject(x1, y);

int width_cell=0;
int x_tek=x1;

while(x_tek<=x2)
	{ 
	width_cell=width_cell+SS->ActiveSheet->Cols->Size[x_tek];
	x_tek++;
	}

SS->ActiveSheet->Cols->Size[x_max]=width_cell;

cell = SS->ActiveSheet->GetCellObject(x_max, y);
cell->Style->WordBreak = true;
cell->Text=s;
cell->Style->Font->Size=cell2->Style->Font->Size;
cell->Style->Font->Style=cell2->Style->Font->Style;
delete cell;

cell = SS->ActiveSheet->GetCellObject(x_max, y);
cell->Style->WordBreak = false;
cell->Text="";
delete cell;

delete cell2;
}
//----------------------------------------------------------------------------
void __fastcall TSheetEditor::ToolButtonPageSetupClick(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->PageSetup(); 	
}
//---------------------------------------------------------------------------

