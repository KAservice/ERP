object FormaGurDocPer: TFormaGurDocPer
  Left = 230
  Top = 167
  Caption = #1046#1091#1088#1085#1072#1083' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' "'#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077'":'
  ClientHeight = 523
  ClientWidth = 825
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 825
    Height = 60
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 226
      Top = 39
      Width = 71
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 39
      Width = 190
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1087#1077#1088#1077#1084#1077#1097#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 825
      Height = 26
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewDoc: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewDoc'
        ImageIndex = 0
        OnClick = ToolButtonNewDocClick
      end
      object ToolButton4: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButton4'
        ImageIndex = 1
        OnClick = ToolButton4Click
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 51
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 128
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 151
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonRefresh: TToolButton
        Left = 174
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButton5: TToolButton
        Left = 197
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1088#1077#1077#1089#1090#1088#1072
        Caption = 'ToolButton5'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton5Click
      end
      object ToolButtonExtModule: TToolButton
        Left = 220
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 60
    Width = 11
    Height = 393
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 453
    Width = 825
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object PrimPercxDBLabel: TcxDBLabel
      Left = 18
      Top = 7
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataBinding.DataField = 'PRIMPER'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -17
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxButton1: TcxButton
      Left = 718
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 810
    Top = 60
    Width = 15
    Height = 393
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 60
    Width = 799
    Height = 393
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088'.'
        DataBinding.FieldName = 'PRDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 31
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 148
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POSDOC'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 55
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMDOC'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 49
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 141
      end
      object cxGrid1DBTableView1NAMESKLADPOL: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076'-'#1087#1086#1083#1091#1095#1072#1090#1077#1083#1100
        DataBinding.FieldName = 'NAMESKLADPOL'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 120
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMDOC'
        Options.Editing = False
        Styles.Content = DM.cxStyleHeaderTable
        Styles.Header = DM.cxStyleHeaderTable
        Width = 52
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 56
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 288
  end
end
