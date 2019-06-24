object ART_FormaSpiskaSprInfBlockSostav: TART_FormaSpiskaSprInfBlockSostav
  Left = 240
  Top = 20
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1099#1081' '#1073#1083#1086#1082
  ClientHeight = 455
  ClientWidth = 525
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 525
    Height = 46
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object HintLabel: TLabel
      Left = 7
      Top = 32
      Width = 36
      Height = 13
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelNom: TLabel
      Left = 9
      Top = 20
      Width = 206
      Height = 16
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 525
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 9
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 9
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton3'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 32
        Top = 0
        Width = 6
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonUpdateForm: TToolButton
        Left = 38
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1092#1086#1088#1084#1091
        Caption = 'ToolButtonUpdateForm'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdateFormClick
      end
      object ToolButtonDesinerOpen: TToolButton
        Left = 61
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1076#1080#1079#1072#1081#1085#1077#1088
        Caption = 'ToolButtonDesinerOpen'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDesinerOpenClick
      end
      object ToolButtonShowNoBase: TToolButton
        Left = 84
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1085#1077' '#1079#1072#1075#1088#1091#1078#1072#1103' '#1080#1079' '#1073#1072#1079#1099
        Caption = 'ToolButtonShowNoBase'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonShowNoBaseClick
      end
      object ToolButtonSaveInBase: TToolButton
        Left = 107
        Top = 0
        Hint = #1047#1072#1087#1080#1089#1072#1090#1100' '#1074' '#1073#1072#1079#1091
        Caption = 'ToolButtonSaveInBase'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSaveInBaseClick
      end
      object ToolButtonClose: TToolButton
        Left = 130
        Top = 0
        Hint = #1047#1072#1082#1088#1099#1090#1100
        Action = ActionClose
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton4: TToolButton
        Left = 153
        Top = 0
        Width = 200
        Caption = 'ToolButton4'
        ImageIndex = 54
        Style = tbsSeparator
      end
      object ToolButtonsaveIsmen: TToolButton
        Left = 353
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1074' '#1073#1072#1079#1077
        Caption = 'ToolButtonsaveIsmen'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonsaveIsmenClick
      end
      object ToolButtonAddString: TToolButton
        Left = 376
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonAddString'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddStringClick
      end
      object ToolButtonDeleteString: TToolButton
        Left = 399
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonDeleteString'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteStringClick
      end
      object ToolButtonPrint: TToolButton
        Left = 422
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100
        Caption = 'ToolButtonPrint'
        ImageIndex = 15
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 46
    Width = 9
    Height = 403
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 449
    Width = 525
    Height = 6
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 512
    Top = 46
    Width = 13
    Height = 403
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxPageControl1: TcxPageControl
    Left = 9
    Top = 46
    Width = 503
    Height = 403
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 403
    ClientRectRight = 503
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1057#1090#1088#1072#1085#1080#1094#1072
      ImageIndex = 0
      object frxPreview1: TfrxPreview
        Left = 0
        Top = 0
        Width = 503
        Height = 379
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        OutlineVisible = False
        OutlineWidth = 120
        ThumbnailVisible = False
        UseReportHints = True
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 503
        Height = 318
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
      object Panel6: TPanel
        Left = 0
        Top = 318
        Width = 503
        Height = 61
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alBottom
        TabOrder = 1
        ExplicitTop = 319
        object Button3: TButton
          Left = 6
          Top = 16
          Width = 73
          Height = 21
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072
          TabOrder = 0
          OnClick = Button3Click
        end
      end
    end
    object cxTabSheet3: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1042' '#1073#1072#1079#1077
      ImageIndex = 2
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 503
        Height = 325
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          object cxGrid1DBTableView1INDEX_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'INDEX_ART_IB_S'
            Width = 31
          end
          object cxGrid1DBTableView1TYPE_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'TYPE_ART_IB_S'
            Width = 32
          end
          object cxGrid1DBTableView1TEXT_ART_IB_ST: TcxGridDBColumn
            DataBinding.FieldName = 'TEXT_ART_IB_S'
            Width = 276
          end
          object cxGrid1DBTableView1TYPE_TEXT_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'TYPE_TEXT_ART_IB_S'
            PropertiesClassName = 'TcxImageComboBoxProperties'
            Properties.Items = <>
            RepositoryItem = DM.cxEditRepository1ImageComboBoxItemTypeTextInfBlock
            Width = 50
          end
          object cxGrid1DBTableView1NAME_ART_IMG: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_ART_IMG'
            Width = 78
          end
          object cxGrid1DBTableView1IDIMG_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'IDIMG_ART_IB_S'
            Width = 60
          end
          object cxGrid1DBTableView1ID_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'ID_ART_IB_S'
            Width = 51
          end
          object cxGrid1DBTableView1IDIB_ART_IB_S: TcxGridDBColumn
            DataBinding.FieldName = 'IDIB_ART_IB_S'
            Width = 39
          end
          object cxGrid1DBTableView1FONT_SIZE_ART_IB_S: TcxGridDBColumn
            Caption = #1056#1072#1079#1084#1077#1088' '#1096#1088#1080#1092#1090#1072
            DataBinding.FieldName = 'FONT_SIZE_ART_IB_S'
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 325
        Width = 503
        Height = 55
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alBottom
        Caption = 'Panel7'
        TabOrder = 1
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 304
    Top = 144
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionSaveIsmen: TAction
      Caption = 'ActionSaveIsmen'
    end
    object ActionCancelIsmen: TAction
      Caption = 'ActionCancelIsmen'
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 384
    Top = 24
  end
  object frxDesigner1: TfrxDesigner
    DefaultScriptLanguage = 'PascalScript'
    DefaultFont.Charset = DEFAULT_CHARSET
    DefaultFont.Color = clWindowText
    DefaultFont.Height = -17
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
    Left = 464
    Top = 152
  end
  object frxReport1: TfrxReport
    Version = '4.9.116'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    Preview = frxPreview1
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = #1055#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 41720.600515335650000000
    ReportOptions.LastChange = 41771.549878981480000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 384
    Top = 152
    Datasets = <>
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
end
