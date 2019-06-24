object FormaSpiskaSprNakSkidok: TFormaSpiskaSprNakSkidok
  Left = 295
  Top = 118
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1089#1082#1080#1076#1086#1082' '#1087#1086' '#1085#1072#1082#1086#1087#1080#1090#1077#1083#1100#1085#1099#1084' '#1082#1072#1088#1090#1072#1084
  ClientHeight = 388
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
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object HintLabel: TLabel
      Left = 8
      Top = 28
      Width = 44
      Height = 16
      Caption = #1058#1077#1082#1089#1090
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
      Width = 525
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
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 36
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 9
    Height = 286
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 335
    Width = 525
    Height = 53
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object cxButtonClose: TcxButton
      Left = 437
      Top = 16
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 512
    Top = 49
    Width = 13
    Height = 286
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 49
    Width = 503
    Height = 286
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 37
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 121
      end
      object cxGrid1DBTableView1NAME_SVID_DCARD: TcxGridDBColumn
        Caption = #1042#1080#1076' '#1082#1072#1088#1090#1099
        DataBinding.FieldName = 'NAME_SVID_DCARD'
        Width = 164
      end
      object cxGrid1DBTableView1SUM_SNAK_SKIDOK: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_SNAK_SKIDOK'
        Width = 60
      end
      object cxGrid1DBTableView1PROCENT_SNAK_SKIDOK: TcxGridDBColumn
        Caption = #1055#1088#1086#1094#1077#1085#1090
        DataBinding.FieldName = 'PROCENT_SNAK_SKIDOK'
        Width = 59
      end
      object cxGrid1DBTableView1PERIOD_SNAK_SKIDOK: TcxGridDBColumn
        Caption = #1055#1077#1088#1080#1086#1076
        DataBinding.FieldName = 'PERIOD_SNAK_SKIDOK'
        Width = 60
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 248
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
