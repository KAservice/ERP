object FormaRunExternalModule: TFormaRunExternalModule
  Left = 0
  Top = 0
  Caption = #1042#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
  ClientHeight = 212
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object FileNameModuleLabel: TLabel
    Left = 10
    Top = 173
    Width = 127
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'FileNameModuleLabel'
  end
  object Button1: TButton
    Left = 544
    Top = 167
    Width = 75
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object fsScript1: TfsScript
    SyntaxType = 'C++Script'
    Left = 136
  end
  object fsCPP1: TfsCPP
    Left = 96
  end
  object fsPascal1: TfsPascal
  end
  object fsJScript1: TfsJScript
    Left = 32
  end
  object fsBasic1: TfsBasic
    Left = 64
  end
  object fsFormsRTTI1: TfsFormsRTTI
    Left = 256
  end
  object fsClassesRTTI1: TfsClassesRTTI
    Left = 184
  end
  object frxReport1: TfrxReport
    Version = '4.9.53'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Maximized = False
    PreviewOptions.Modal = False
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40005.823532615740000000
    ReportOptions.LastChange = 40005.827353333320000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    OnClosePreview = frxReport1ClosePreview
    Top = 72
    Datasets = <
      item
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
    end
  end
  object frxDesigner1: TfrxDesigner
    DefaultScriptLanguage = 'PascalScript'
    DefaultFont.Charset = DEFAULT_CHARSET
    DefaultFont.Color = clWindowText
    DefaultFont.Height = -13
    DefaultFont.Name = 'Arial'
    DefaultFont.Style = []
    DefaultLeftMargin = 10.000000000000000000
    DefaultRightMargin = 10.000000000000000000
    DefaultTopMargin = 10.000000000000000000
    DefaultBottomMargin = 10.000000000000000000
    DefaultPaperSize = 9
    DefaultOrientation = poPortrait
    GradientEnd = 11982554
    GradientStart = clWindow
    TemplatesExt = 'fr3'
    Restrictions = []
    RTLLanguage = False
    MemoParentFont = False
    Left = 32
    Top = 72
  end
  object frxBarCodeObject1: TfrxBarCodeObject
    Left = 80
    Top = 72
  end
  object frxOLEObject1: TfrxOLEObject
    Left = 112
    Top = 72
  end
  object frxRichObject1: TfrxRichObject
    Left = 144
    Top = 72
  end
  object frxCrossObject1: TfrxCrossObject
    Left = 176
    Top = 72
  end
  object frxCheckBoxObject1: TfrxCheckBoxObject
    Left = 208
    Top = 72
  end
  object frxGradientObject1: TfrxGradientObject
    Left = 240
    Top = 72
  end
  object frxDialogControls1: TfrxDialogControls
    Left = 272
    Top = 72
  end
  object frxGZipCompressor1: TfrxGZipCompressor
    Left = 304
    Top = 72
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    BCDToCurrency = False
    Left = 336
    Top = 72
  end
  object frxCrypt1: TfrxCrypt
    Left = 368
    Top = 72
  end
  object frxChartObject1: TfrxChartObject
    Left = 400
    Top = 72
  end
  object frxUserDataSet1: TfrxUserDataSet
    RangeEnd = reCount
    UserName = 'frxUserDataSet1'
    Fields.Strings = (
      'Id1'
      'Id2'
      'Id3'
      'IntValue1')
    OnGetValue = frxUserDataSet1GetValue
    Left = 136
    Top = 120
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    Left = 224
    Top = 112
  end
  object fsGraphicsRTTI1: TfsGraphicsRTTI
    Left = 216
  end
  object fsExtCtrlsRTTI1: TfsExtCtrlsRTTI
    Left = 288
  end
  object fsDialogsRTTI1: TfsDialogsRTTI
    Left = 320
  end
  object fsMenusRTTI1: TfsMenusRTTI
    Left = 360
  end
  object fsIniRTTI1: TfsIniRTTI
    Left = 392
  end
  object fsChartRTTI1: TfsChartRTTI
    Left = 432
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 352
    Top = 160
  end
  object frxFIBComponents1: TfrxFIBComponents
    Left = 416
    Top = 136
  end
end
