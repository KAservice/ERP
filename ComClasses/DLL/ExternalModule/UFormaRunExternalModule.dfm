object FormaRunExternalModule: TFormaRunExternalModule
  Left = 0
  Top = 0
  Caption = #1042#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
  ClientHeight = 302
  ClientWidth = 621
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object FileNameModuleLabel: TLabel
    Left = 8
    Top = 283
    Width = 102
    Height = 13
    Caption = 'FileNameModuleLabel'
  end
  object Memo1: TMemo
    Left = 0
    Top = 62
    Width = 621
    Height = 189
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    Color = clMenu
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 251
    Width = 621
    Height = 51
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alBottom
    Caption = 'Panel1'
    TabOrder = 1
    object Button1: TButton
      Left = 496
      Top = 12
      Width = 97
      Height = 27
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 621
    Height = 62
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alTop
    Caption = 'Panel2'
    TabOrder = 2
  end
  object fsScript1: TfsScript
    SyntaxType = 'C++Script'
    Left = 224
    Top = 16
  end
  object fsCPP1: TfsCPP
    Left = 176
  end
  object fsPascal1: TfsPascal
  end
  object fsJScript1: TfsJScript
    Left = 56
  end
  object fsBasic1: TfsBasic
    Left = 112
  end
  object fsFormsRTTI1: TfsFormsRTTI
    Left = 400
  end
  object fsClassesRTTI1: TfsClassesRTTI
    Left = 288
  end
  object frxReport1: TfrxReport
    Version = '4.9.116'
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
    OnUserFunction = frxReport1UserFunction
    OnClosePreview = frxReport1ClosePreview
    Left = 24
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
    Left = 28
    Top = 120
  end
  object frxBarCodeObject1: TfrxBarCodeObject
    Left = 152
    Top = 88
  end
  object frxOLEObject1: TfrxOLEObject
    Left = 216
    Top = 104
  end
  object frxRichObject1: TfrxRichObject
    Left = 272
    Top = 80
  end
  object frxCrossObject1: TfrxCrossObject
    Left = 328
    Top = 96
  end
  object frxCheckBoxObject1: TfrxCheckBoxObject
    Left = 400
    Top = 80
  end
  object frxGradientObject1: TfrxGradientObject
    Left = 472
    Top = 104
  end
  object frxDialogControls1: TfrxDialogControls
    Left = 552
    Top = 88
  end
  object frxGZipCompressor1: TfrxGZipCompressor
    Left = 624
    Top = 104
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    BCDToCurrency = False
    Left = 688
    Top = 88
  end
  object frxCrypt1: TfrxCrypt
    Left = 744
    Top = 104
  end
  object frxChartObject1: TfrxChartObject
    Left = 688
    Top = 32
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
    Left = 408
    Top = 248
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
    Left = 24
    Top = 296
  end
  object fsGraphicsRTTI1: TfsGraphicsRTTI
    Left = 344
    Top = 16
  end
  object fsExtCtrlsRTTI1: TfsExtCtrlsRTTI
    Left = 456
    Top = 24
  end
  object fsDialogsRTTI1: TfsDialogsRTTI
    Left = 512
    Top = 8
  end
  object fsMenusRTTI1: TfsMenusRTTI
    Left = 576
    Top = 24
  end
  object fsIniRTTI1: TfsIniRTTI
    Left = 640
    Top = 8
  end
  object fsChartRTTI1: TfsChartRTTI
    Left = 744
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 232
    Top = 248
  end
  object frxFIBComponents1: TfrxFIBComponents
    Left = 496
    Top = 248
  end
  object frxXLSExport1: TfrxXLSExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    ExportEMF = True
    AsText = False
    Background = True
    FastExport = True
    PageBreaks = True
    EmptyLines = True
    SuppressPageHeadersFooters = False
    Left = 112
    Top = 296
  end
  object frxRTFExport1: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    ExportEMF = True
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 208
    Top = 296
  end
  object frxJPEGExport1: TfrxJPEGExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Left = 328
    Top = 248
  end
  object frxTIFFExport1: TfrxTIFFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Left = 328
    Top = 304
  end
  object frxBMPExport1: TfrxBMPExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Left = 408
    Top = 304
  end
  object frxMailExport1: TfrxMailExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    ShowExportDialog = True
    SmtpPort = 25
    UseIniFile = True
    TimeOut = 60
    ConfurmReading = False
    Left = 464
    Top = 304
  end
  object frxODSExport1: TfrxODSExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    ExportEMF = True
    Background = True
    Creator = 'FastReport'
    EmptyLines = True
    SuppressPageHeadersFooters = False
    Left = 552
    Top = 296
  end
  object frxODTExport1: TfrxODTExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    ExportEMF = True
    Background = True
    Creator = 'FastReport'
    EmptyLines = True
    SuppressPageHeadersFooters = False
    Left = 624
    Top = 288
  end
  object frxGIFExport1: TfrxGIFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Left = 656
    Top = 232
  end
  object frxSimpleTextExport1: TfrxSimpleTextExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Frames = False
    EmptyLines = False
    OEMCodepage = False
    Left = 144
    Top = 160
  end
  object frxJPEGExport2: TfrxJPEGExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Left = 248
    Top = 160
  end
  object frxXMLExport1: TfrxXMLExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    Background = True
    Creator = 'FastReport'
    EmptyLines = True
    SuppressPageHeadersFooters = False
    RowsCount = 0
    Split = ssNotSplit
    Left = 352
    Top = 168
  end
end
