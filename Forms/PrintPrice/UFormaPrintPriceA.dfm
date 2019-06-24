object FormaPrintPriceA: TFormaPrintPriceA
  Left = 235
  Top = 216
  Caption = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1086#1074
  ClientHeight = 558
  ClientWidth = 917
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 917
    Height = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 917
      Height = 27
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton2: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton2'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object AddNomToolButton: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1091
        Caption = 'AddNomToolButton'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = AddNomToolButtonClick
      end
      object AddGrpToolButton: TToolButton
        Left = 31
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1075#1088#1091#1087#1087#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        Caption = 'AddGrpToolButton'
        ImageIndex = 34
        ParentShowHint = False
        ShowHint = True
        OnClick = AddGrpToolButtonClick
      end
      object ViborPeremToolButton: TToolButton
        Left = 54
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100#1076#1086#1082#1091#1084#1077#1085#1090'  '#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
        Caption = 'ViborPeremToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ViborPeremToolButtonClick
      end
      object ViborPrihNaklToolButton: TToolButton
        Left = 77
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103
        Caption = 'ViborPrihNaklToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ViborPrihNaklToolButtonClick
      end
      object DelNomToolButton: TToolButton
        Left = 100
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'DelNomToolButton'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = DelNomToolButtonClick
      end
      object ClearToolButton: TToolButton
        Left = 123
        Top = 0
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100
        Caption = 'ClearToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ClearToolButtonClick
      end
      object ToolButton1: TToolButton
        Left = 146
        Top = 0
        Caption = 'ToolButton1'
        ImageIndex = 3
      end
      object ToolButton3: TToolButton
        Left = 169
        Top = 0
        Width = 133
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 302
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1086#1074' '#8470'1'
        Caption = 'ToolButton4'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton4Click
      end
      object ToolButtonPrintNumber2: TToolButton
        Left = 325
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1082#1080#1086#1074' '#8470'2'
        Caption = 'ToolButtonPrintNumber2'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber2Click
      end
      object ToolButtonPrintNumber3: TToolButton
        Left = 348
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'3'
        Caption = 'ToolButtonPrintNumber3'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber3Click
      end
      object ToolButtonPrintNumber4: TToolButton
        Left = 371
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'4'
        Caption = 'ToolButtonPrintNumber4'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber4Click
      end
      object ToolButtonPrintPrice5: TToolButton
        Left = 394
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'5'
        Caption = 'ToolButtonPrintPrice5'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintPrice5Click
      end
      object ToolButtonPrintPrice6: TToolButton
        Left = 417
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'6'
        Caption = 'ToolButtonPrintPrice6'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintPrice6Click
      end
      object ToolButtonPrintPrice7: TToolButton
        Left = 440
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'7'
        Caption = 'ToolButtonPrintPrice7'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintPrice7Click
      end
      object ToolButton6: TToolButton
        Left = 463
        Top = 0
        Caption = 'ToolButton6'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
      end
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 27
      Width = 917
      Height = 25
      Caption = 'ToolBar2'
      EdgeBorders = [ebBottom]
      Images = DM.ImageList1
      TabOrder = 1
      object ToolButton7: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton7'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButton5: TToolButton
        Left = 8
        Top = 0
        Width = 271
        Caption = 'ToolButton5'
        Style = tbsSeparator
      end
      object ToolButtonPrintBarCode1: TToolButton
        Left = 279
        Top = 0
        Caption = 'ToolButtonPrintBarCode1'
        ImageIndex = 37
        OnClick = ToolButtonPrintBarCode1Click
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 80
    Width = 10
    Height = 412
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 635
    Top = 80
    Width = 282
    Height = 412
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
    object Label1: TLabel
      Left = 7
      Top = 22
      Width = 54
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 7
      Top = 95
      Width = 64
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 7
      Top = 171
      Width = 42
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1077#1089#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object FirmaComboBox: TComboBox
      Left = 7
      Top = 46
      Width = 250
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Style = csDropDownList
      TabOrder = 0
      OnChange = FirmaComboBoxChange
    end
    object TypePriceComboBox: TComboBox
      Left = 7
      Top = 118
      Width = 250
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Style = csDropDownList
      TabOrder = 1
      OnChange = TypePriceComboBoxChange
    end
    object ScaleComboBox: TComboBox
      Left = 7
      Top = 194
      Width = 250
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Style = csDropDownList
      TabOrder = 2
      OnChange = ScaleComboBoxChange
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 492
    Width = 917
    Height = 66
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 10
    Top = 80
    Width = 625
    Height = 412
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
    end
    object cxGrid1TableView1: TcxGridTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1TableView1Column1: TcxGridColumn
        Width = 20
      end
      object cxGrid1TableView1IDNOM: TcxGridColumn
        Caption = 'IDNOM'
        Visible = False
      end
      object cxGrid1TableView1GRP: TcxGridColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.ValueType = 'Integer'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.ReadOnly = True
        OnCustomDrawCell = cxGrid1TableView1GRPCustomDrawCell
        Width = 76
      end
      object cxGrid1TableView1NAMENOM: TcxGridColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Width = 236
      end
      object cxGrid1TableView1IDED: TcxGridColumn
        Caption = 'IDED'
        Visible = False
      end
      object cxGrid1TableView1NAMEED: TcxGridColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Width = 83
      end
      object cxGrid1TableView1KOL: TcxGridColumn
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 91
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1TableView1
    end
  end
  object ActionList: TActionList
    Left = 632
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 472
    Top = 24
  end
end
