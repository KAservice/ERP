object REM_FormaZayavkaDv: TREM_FormaZayavkaDv
  Left = 240
  Top = 20
  Caption = #1046#1091#1088#1085#1072#1083' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1089#1086#1089#1090#1086#1103#1085#1080#1103' '#1079#1072#1103#1074#1082#1080
  ClientHeight = 478
  ClientWidth = 928
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
    Width = 928
    Height = 60
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object HintLabel: TLabel
      Left = 10
      Top = 34
      Width = 49
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
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
      Width = 928
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
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
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
      object LabelZayavka: TLabel
        Left = 113
        Top = 0
        Width = 206
        Height = 22
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 60
    Width = 10
    Height = 352
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
    Top = 412
    Width = 928
    Height = 66
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object cxButtonClose: TcxButton
      Left = 778
      Top = 30
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 912
    Top = 60
    Width = 16
    Height = 352
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
    Left = 10
    Top = 60
    Width = 902
    Height = 352
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMZayavkaDv.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_REM_Z_DV'
          Column = cxGrid1DBTableView1SUM_REM_Z_DV
          DisplayText = #1057#1091#1084#1084#1072
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1OUT_REM_Z_DV: TcxGridDBColumn
        Caption = #1042#1099#1087'.'
        DataBinding.FieldName = 'OUT_REM_Z_DV'
        Width = 30
      end
      object cxGrid1DBTableView1POS_REM_Z_DV: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z_DV'
        Width = 103
      end
      object cxGrid1DBTableView1OPER_REM_Z_DV: TcxGridDBColumn
        Caption = #1054#1087#1077#1088#1072#1094#1080#1103
        DataBinding.FieldName = 'OPER_REM_Z_DV'
        Width = 72
      end
      object cxGrid1DBTableView1NAME_REMSSOST: TcxGridDBColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'NAME_REMSSOST'
        Options.ShowEditButtons = isebAlways
        Width = 109
      end
      object cxGrid1DBTableView1NAME_SKLAD_TEC: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086#1085#1072#1093#1086#1078#1076#1077#1085#1080#1077
        DataBinding.FieldName = 'NAME_SKLAD_TEC'
        Width = 98
      end
      object cxGrid1DBTableView1NAME_STREMONT: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1088#1077#1084#1086#1085#1090#1072
        DataBinding.FieldName = 'NAME_STREMONT'
        Width = 75
      end
      object cxGrid1DBTableView1SROK_REM_Z_DV: TcxGridDBColumn
        Caption = #1057#1088#1086#1082
        DataBinding.FieldName = 'SROK_REM_Z_DV'
        Width = 69
      end
      object cxGrid1DBTableView1SUM_REM_Z_DV: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_Z_DV'
        Width = 69
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
        DataBinding.FieldName = 'NAME_USER'
        Width = 106
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 672
    Top = 8
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
