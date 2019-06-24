object REM_FormaSpiskaSprHardwareIsp: TREM_FormaSpiskaSprHardwareIsp
  Left = 240
  Top = 20
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1077' '#1079#1072#1087#1095#1072#1089#1090#1077#1081'"'
  ClientHeight = 518
  ClientWidth = 847
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
    Width = 847
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
      Width = 847
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
      object LabelModel: TLabel
        Left = 113
        Top = 0
        Width = 153
        Height = 22
        Caption = #1052#1086#1076#1077#1083#1100' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
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
    Width = 11
    Height = 392
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
    Top = 452
    Width = 847
    Height = 66
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object cxButton1: TcxButton
      Left = 504
      Top = 16
      Width = 105
      Height = 33
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 831
    Top = 60
    Width = 16
    Height = 392
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
    Width = 820
    Height = 392
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 32
      end
      object cxGrid1DBTableView1ID_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1053#1077' '#1080#1089#1087'.'
        DataBinding.FieldName = 'ID_REM_SHARDWARE_ISP'
        Visible = False
      end
      object cxGrid1DBTableView1POS_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_SHARDWARE_ISP'
        Width = 70
      end
      object cxGrid1DBTableView1FL_OTCH_PR_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1054#1090#1095#1080#1090#1072#1085#1086
        DataBinding.FieldName = 'FL_OTCH_PR_REM_SHARDWARE_ISP'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 20
      end
      object cxGrid1DBTableView1FL_REAL_ISP_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1086
        DataBinding.FieldName = 'FL_REAL_ISP_REM_SHARDWARE_ISP'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 20
      end
      object cxGrid1DBTableView1NAME_REM_STYPUSLOV: TcxGridDBColumn
        Caption = #1058#1080#1087#1086#1074#1086#1081' '#1091#1079#1077#1083
        DataBinding.FieldName = 'NAME_REM_STYPUSLOV'
        Width = 182
      end
      object cxGrid1DBTableView1DESCR_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1076#1077#1090#1072#1083#1080', '#1091#1079#1083#1072
        DataBinding.FieldName = 'DESCR_REM_SHARDWARE_ISP'
        Width = 186
      end
      object cxGrid1DBTableView1KOL_REM_SHARDWARE_ISP: TcxGridDBColumn
        Caption = #1050#1086#1083
        DataBinding.FieldName = 'KOL_REM_SHARDWARE_ISP'
        Width = 37
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_Z: TcxGridDBColumn
        Caption = #1055#1088#1077#1092#1080#1082#1089
        DataBinding.FieldName = 'PREFIKS_NUM_REM_Z'
        Width = 20
      end
      object cxGrid1DBTableView1NUM_REM_Z: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_Z'
        Width = 41
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1044#1072#1090#1072' '#1079#1072#1103#1074#1082#1080
        DataBinding.FieldName = 'POS_REM_Z'
        Width = 41
      end
      object cxGrid1DBTableView1MODEL_REM_Z: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_REM_Z'
        Width = 44
      end
      object cxGrid1DBTableView1SERNUM_STR_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 32
      end
      object cxGrid1DBTableView1NAME_REM_Z: TcxGridDBColumn
        Caption = #1047#1072#1103#1074#1082#1072
        DataBinding.FieldName = 'NAME_REM_Z'
        Width = 46
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Width = 47
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 264
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
