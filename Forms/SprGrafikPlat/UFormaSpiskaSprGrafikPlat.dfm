object FormaSpiskaSprGrafikPlat: TFormaSpiskaSprGrafikPlat
  Left = 382
  Top = 162
  Caption = #1043#1088#1072#1092#1080#1082' '#1087#1083#1072#1090#1077#1078#1077#1081' '#1087#1086' '#1076#1086#1075#1086#1074#1086#1088#1091
  ClientHeight = 309
  ClientWidth = 368
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 368
    Height = 89
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object LabelZagolovok: TLabel
      Left = 8
      Top = 32
      Width = 345
      Height = 49
      Alignment = taCenter
      AutoSize = False
      Caption = #1085#1077#1080#1079#1074#1077#1089#1090#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 368
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentShowHint = False
      ShowHint = False
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
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonDelete: TToolButton
        Left = 31
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 9
    Height = 151
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 240
    Width = 368
    Height = 69
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 278
      Top = 22
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 196
      Top = 22
      Width = 75
      Height = 24
      Action = ActionOK
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 356
    Top = 89
    Width = 12
    Height = 151
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 89
    Width = 347
    Height = 151
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
      object cxGrid1DBTableView1SUM_SGRPLAT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_SGRPLAT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1DO_SGRPLAT: TcxGridDBColumn
        Caption = #1044#1086
        DataBinding.FieldName = 'DO_SGRPLAT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
