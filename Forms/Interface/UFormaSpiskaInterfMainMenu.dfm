object FormaSpiskaInterfMainMenu: TFormaSpiskaInterfMainMenu
  Left = 339
  Top = 240
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1075#1083#1072#1074#1085#1086#1075#1086' '#1084#1077#1085#1102
  ClientHeight = 676
  ClientWidth = 969
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
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 969
    Height = 129
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 351
      Top = 102
      Width = 76
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object HintLabel: TLabel
      Left = 10
      Top = 34
      Width = 58
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
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
      object ToolButton5: TToolButton
        Left = 470
        Top = 0
        Caption = 'ToolButton5'
        ImageIndex = 48
        OnClick = ToolButton5Click
      end
      object ToolButton6: TToolButton
        Left = 493
        Top = 0
        Action = ActionCreateFullStandartMainMenu
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonClearMenu: TToolButton
        Left = 516
        Top = 0
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100' '#1084#1077#1085#1102
        Caption = 'ToolButtonClearMenu'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonClearMenuClick
      end
      object ToolButtonOpenSpisokParam: TToolButton
        Left = 539
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1089#1087#1080#1089#1086#1082' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074
        Caption = 'ToolButtonOpenSpisokParam'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenSpisokParamClick
      end
    end
    object NameGrpUsercxLookupComboBox: TcxLookupComboBox
      Left = 508
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'ID_SGRPUSER'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SGRPUSER'
        end>
      Properties.OnEditValueChanged = NameGrpUsercxLookupComboBoxPropertiesEditValueChanged
      EditValue = 0
      TabOrder = 1
      Width = 320
    end
    object cxLabel1: TcxLabel
      Left = 351
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081':'
    end
    object cxLabel2: TcxLabel
      Left = 11
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1052#1086#1076#1091#1083#1100':'
    end
    object NameModulcxImageComboBox: TcxImageComboBox
      Left = 71
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeProgramModule
      EditValue = 0
      Properties.Items = <>
      Properties.OnEditValueChanged = NameModulcxImageComboBoxPropertiesEditValueChanged
      TabOrder = 4
      Width = 267
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 129
    Width = 11
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 619
    Width = 969
    Height = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    object cxButtonClose: TcxButton
      Left = 868
      Top = 14
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 768
      Top = 14
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 668
      Top = 14
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
  end
  object Panel4: TPanel
    Left = 959
    Top = 129
    Width = 10
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object Panel5: TPanel
    Left = 338
    Top = 129
    Width = 13
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 6
  end
  object cxTreeView1: TcxTreeView
    Left = 11
    Top = 129
    Width = 327
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -18
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
    Left = 351
    Top = 129
    Width = 608
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMInterfMainMenu.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 52
      end
      object cxGrid1DBTableView1INDEX_INTERF_MAINMENU: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089
        DataBinding.FieldName = 'INDEX_INTERF_MAINMENU'
        Width = 40
      end
      object cxGrid1DBTableView1NAME_INTERF_MAINMENU: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_INTERF_MAINMENU'
        Width = 79
      end
      object cxGrid1DBTableView1NAME_PROGRAM_MODULE: TcxGridDBColumn
        Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1085#1099#1081' '#1084#1086#1076#1091#1083#1100
        DataBinding.FieldName = 'NAME_PROGRAM_MODULE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick
        Width = 109
      end
      object cxGrid1DBTableView1SHORTCUT_INTERF_MAINMENU: TcxGridDBColumn
        Caption = #1050#1086#1076' '#1082#1083#1072#1074#1080#1096#1080' '#1073#1099#1089#1088#1086#1075#1086' '#1074#1099#1079#1086#1074#1072
        DataBinding.FieldName = 'SHORTCUT_INTERF_MAINMENU'
        Width = 25
      end
      object cxGrid1DBTableView1FL_OPEN_EL_INTERF_MAINMENU: TcxGridDBColumn
        DataBinding.FieldName = 'FL_OPEN_EL_INTERF_MAINMENU'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 20
      end
      object cxGrid1DBTableView1IDEL_INTERF_MAINMENU: TcxGridDBColumn
        DataBinding.FieldName = 'IDEL_INTERF_MAINMENU'
        Width = 34
      end
      object cxGrid1DBTableView1GUIDMOD_INTERF_MAINMENU: TcxGridDBColumn
        DataBinding.FieldName = 'GUIDMOD_INTERF_MAINMENU'
        Width = 63
      end
      object cxGrid1DBTableView1TYPEMOD_PROGRAM_MODULE: TcxGridDBColumn
        DataBinding.FieldName = 'TYPEMOD_PROGRAM_MODULE'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeApplication
        Width = 55
      end
      object cxGrid1DBTableView1PATCH_PROGRAM_MODULE: TcxGridDBColumn
        DataBinding.FieldName = 'PATCH_PROGRAM_MODULE'
        Width = 129
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 32
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionCreateFullStandartMainMenu: TAction
      Caption = 'ActionCreateFullStandartMainMenu'
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1087#1086#1083#1085#1086#1077' '#1089#1090#1072#1085#1076#1072#1088#1085#1086#1077' '#1075#1083#1072#1074#1085#1086#1077' '#1084#1077#1085#1102
      ImageIndex = 45
      OnExecute = ActionCreateFullStandartMainMenuExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 448
    Top = 16
  end
end
