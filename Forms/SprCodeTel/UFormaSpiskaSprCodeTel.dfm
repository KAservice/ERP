object FormaSpiskaSprCodeTel: TFormaSpiskaSprCodeTel
  Left = 357
  Top = 47
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1090#1077#1083#1077#1092#1086#1085#1085#1099#1093' '#1082#1086#1076#1086#1074':'
  ClientHeight = 375
  ClientWidth = 509
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
    Width = 509
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 626
      Height = 29
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
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 9
    Height = 246
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 496
    Top = 73
    Width = 13
    Height = 246
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 0
    Top = 319
    Width = 509
    Height = 56
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 421
      Top = 14
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 73
    Width = 487
    Height = 246
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 46
      end
      object cxGrid1DBTableView1CODE_CODETEL: TcxGridDBColumn
        Caption = #1050#1086#1076' '#1090#1077#1083'.'
        DataBinding.FieldName = 'CODE_CODETEL'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 75
      end
      object cxGrid1DBTableView1CODOPER_CODETEL: TcxGridDBColumn
        Caption = #1050#1086#1076' '#1086#1087#1077#1088#1072#1090#1086#1088#1072
        DataBinding.FieldName = 'CODOPER_CODETEL'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 101
      end
      object cxGrid1DBTableView1NAME_CODETEL: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_CODETEL'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 176
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 149
      end
      object cxGrid1DBTableView1PRCOMIS_SCODETEL: TcxGridDBColumn
        Caption = #1055#1088#1086#1094#1077#1085#1090' '#1082#1086#1084#1080#1089#1089#1080#1080
        DataBinding.FieldName = 'PRCOMIS_SCODETEL'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 50
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
