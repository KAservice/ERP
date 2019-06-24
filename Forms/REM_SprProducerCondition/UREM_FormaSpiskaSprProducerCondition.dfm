object REM_FormaSpiskaSprProducerCondition: TREM_FormaSpiskaSprProducerCondition
  Left = 339
  Top = 240
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "Condition '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1077#1081' ('#1087#1086#1089#1090#1072#1074#1097#1080#1082#1086#1074')"'
  ClientHeight = 549
  ClientWidth = 787
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
    Width = 787
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 296
      Top = 56
      Width = 58
      Height = 16
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
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
      Width = 969
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
      object ToolButtonNewScale: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewScale'
        ImageIndex = 0
        OnClick = ToolButtonNewScaleClick
      end
      object ToolButtonEdiScale: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdiScale'
        ImageIndex = 1
        OnClick = ToolButtonEdiScaleClick
      end
      object ToolButtonDeleteScale: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDeleteScale'
        ImageIndex = 2
        OnClick = ToolButtonDeleteScaleClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 161
        Top = 0
        Width = 136
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 297
        Top = 0
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 320
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 343
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 366
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 401
        Top = 0
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        Style = tbsCheck
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 424
        Top = 0
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        OnClick = ToolButtonIsmGrpClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 447
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object NameGroupElementcxComboBox: TcxComboBox
      Left = 11
      Top = 51
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = NameGroupElementcxComboBoxPropertiesChange
      TabOrder = 1
      Width = 261
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 9
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 503
    Width = 787
    Height = 46
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    object cxButtonClose: TcxButton
      Left = 705
      Top = 11
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 624
      Top = 11
      Width = 75
      Height = 25
      Caption = #1054#1050
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 543
      Top = 11
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 2
    end
  end
  object Panel4: TPanel
    Left = 779
    Top = 73
    Width = 8
    Height = 430
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object Panel5: TPanel
    Left = 275
    Top = 73
    Width = 10
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 6
  end
  object cxTreeView1: TcxTreeView
    Left = 9
    Top = 73
    Width = 266
    Height = 430
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -15
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = []
    Style.IsFontAssigned = True
    TabOrder = 0
    OnDblClick = cxTreeView1DblClick
    OnKeyPress = cxTreeView1KeyPress
    HideSelection = False
    ReadOnly = True
  end
  object cxGrid1: TcxGrid
    Left = 285
    Top = 73
    Width = 494
    Height = 430
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 33
      end
      object cxGrid1DBTableView1CODE_REM_SPRCONDITION: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRCONDITION'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 53
      end
      object cxGrid1DBTableView1NAME_REM_SPRCONDITION: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_REM_SPRCONDITION'
        Width = 130
      end
      object cxGrid1DBTableView1NAME_ENG_REM_SPRCONDITION: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' ('#1072#1085#1075#1083'.)'
        DataBinding.FieldName = 'NAME_ENG_REM_SPRCONDITION'
        Width = 129
      end
      object cxGrid1DBTableView1ID_REM_SPRCONDITION: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_SPRCONDITION'
        Visible = False
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
    Left = 448
    Top = 32
  end
end
