object FormaSpiskaSprOborud: TFormaSpiskaSprOborud
  Left = 312
  Top = 224
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
  ClientHeight = 366
  ClientWidth = 627
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
    Width = 627
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object ZagolovokLabel: TLabel
      Left = 8
      Top = 32
      Width = 114
      Height = 16
      Caption = 'ZagolovokLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 627
      Height = 33
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
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Hint = #1048#1079#1084#1077#1085#1080#1090#1100
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonOpenSpisokParam: TToolButton
        Left = 77
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1089#1087#1080#1089#1086#1082' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074
        Caption = 'ToolButtonOpenSpisokParam'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenSpisokParamClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 9
    Height = 262
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 311
    Width = 627
    Height = 55
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 534
      Top = 14
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 617
    Top = 49
    Width = 10
    Height = 262
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 49
    Width = 608
    Height = 262
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyDown = cxGrid1DBTableView1KeyDown
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 53
      end
      object cxGrid1DBTableViewON_START_SOBORUD: TcxGridDBColumn
        Caption = #1055#1088#1080' '#1089#1090#1072#1088#1090#1077
        DataBinding.FieldName = 'ON_START_SOBORUD'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
      end
      object cxGrid1DBTableView1NAME_OBORUD: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_OBORUD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 181
      end
      object cxGrid1DBTableView1TYPE_OBORUD: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TYPE_OBORUD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 120
      end
      object cxGrid1DBTableView1MODEL_OBORUD: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_OBORUD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 106
      end
      object cxGrid1DBTableView1MODUL_SOBORUD: TcxGridDBColumn
        Caption = #1052#1086#1076#1091#1083#1100
        DataBinding.FieldName = 'MODUL_SOBORUD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
      end
      object cxGrid1DBTableView1COMNAME_OBORUD: TcxGridDBColumn
        Caption = #1055#1086#1088#1090
        DataBinding.FieldName = 'COMNAME_OBORUD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 54
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
end
