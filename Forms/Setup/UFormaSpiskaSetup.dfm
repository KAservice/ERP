object FormaSpiskaSetup: TFormaSpiskaSetup
  Left = 269
  Top = 66
  Caption = #1057#1080#1089#1090#1077#1084#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 343
  ClientWidth = 664
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
    Width = 664
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 664
      Height = 29
      Caption = 'ToolBar1'
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
      object ToolButton3: TToolButton
        Left = 54
        Top = 0
        Width = 83
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonAddStandartValue: TToolButton
        Left = 137
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        Caption = 'ToolButtonAddStandartValue'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddStandartValueClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 9
    Height = 271
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 304
    Width = 664
    Height = 39
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonOK: TcxButton
      Left = 487
      Top = 6
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 568
      Top = 6
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 652
    Top = 33
    Width = 12
    Height = 271
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 33
    Width = 643
    Height = 271
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1ID_SETUP: TcxGridDBColumn
        Caption = 'ID'
        DataBinding.FieldName = 'ID_SETUP'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 47
      end
      object cxGrid1DBTableView1DESCRIPTION_SETUP: TcxGridDBColumn
        Caption = #1054#1087#1080#1089#1072#1085#1080#1077
        DataBinding.FieldName = 'DESCRIPTION_SETUP'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 273
      end
      object cxGrid1DBTableView1TYPE_VALUE_SETUP: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1079#1085#1072#1095#1077#1085#1080#1103
        DataBinding.FieldName = 'TYPE_VALUE_SETUP'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.Items.Strings = (
          #1053#1077' '#1079#1072#1076#1072#1085
          #1057#1090#1088#1086#1082#1072
          #1055#1086#1079#1080#1094#1080#1103' '#1076#1072#1090#1072'/'#1074#1088#1077#1084#1103)
        Styles.Header = DM.cxStyleHeaderTable
        Width = 89
      end
      object cxGrid1DBTableView1VALUE_SETUP: TcxGridDBColumn
        Caption = #1047#1085#1072#1095#1077#1085#1080#1077
        DataBinding.FieldName = 'VALUE_SETUP'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 92
      end
      object cxGrid1DBTableView1VALUE_TIMESTAMP_SETUP: TcxGridDBColumn
        Caption = #1047#1085#1072#1095#1077#1085#1080#1077' ('#1044#1072#1090#1072'/'#1074#1088#1077#1084#1103')'
        DataBinding.FieldName = 'VALUE_TIMESTAMP_SETUP'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Styles.Header = DM.cxStyleHeaderTable
        Width = 140
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
