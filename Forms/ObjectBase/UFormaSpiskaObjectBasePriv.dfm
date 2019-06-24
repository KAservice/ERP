object FormaSpiskaObjectBasePriv: TFormaSpiskaObjectBasePriv
  Left = 339
  Top = 240
  Caption = #1055#1088#1080#1074#1077#1083#1077#1075#1080#1080' '#1085#1072' '#1086#1073#1098#1077#1082#1090#1099
  ClientHeight = 584
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
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 969
    Height = 113
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
      Top = 90
      Width = 64
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
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
        Width = 190
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 351
        Top = 0
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 374
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
      end
      object ToolButtonDelete: TToolButton
        Left = 397
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 420
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 455
        Top = 0
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        Style = tbsCheck
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 478
        Top = 0
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        OnClick = ToolButtonIsmGrpClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 501
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 524
        Top = 0
        Caption = 'ToolButton5'
        ImageIndex = 48
        OnClick = ToolButton5Click
      end
      object ToolButton6: TToolButton
        Left = 547
        Top = 0
        Action = ActionCreateFullStandartMainMenu
        ParentShowHint = False
        ShowHint = True
      end
    end
    object NameGrpUsercxLookupComboBox: TcxLookupComboBox
      Left = 556
      Top = 61
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
      Left = 389
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081':'
    end
    object ApplicationcxImageComboBox: TcxImageComboBox
      Left = 114
      Top = 58
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeApplication
      EditValue = 0
      Properties.Items = <>
      Properties.OnEditValueChanged = ApplicationcxImageComboBoxPropertiesEditValueChanged
      TabOrder = 3
      Width = 267
    end
    object cxLabel2: TcxLabel
      Left = 16
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1083#1086#1078#1077#1085#1080#1077':'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 113
    Width = 11
    Height = 414
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
    Top = 527
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
    Top = 113
    Width = 10
    Height = 414
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
    Top = 113
    Width = 13
    Height = 414
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
    Top = 113
    Width = 327
    Height = 414
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -17
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
    Top = 113
    Width = 608
    Height = 414
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
      DataController.DataSource = DMObjectBasePriv.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 60
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
        Width = 283
      end
      object cxGrid1DBTableView1NUMBER_OBJECT_BASE_PRIV: TcxGridDBColumn
        Caption = #1054#1073#1098#1077#1082#1090' ('#1085#1077' '#1080#1089#1087'.)'
        DataBinding.FieldName = 'NUMBER_OBJECT_BASE_PRIV'
        RepositoryItem = DM.cxEditRepository1ImageComboBoxGC_ObjectBaseForPriv
        Width = 78
      end
      object cxGrid1DBTableView1EXEC_OBJECT_BASE_PRIV: TcxGridDBColumn
        Caption = #1055#1088#1086#1089#1084#1086#1090#1088' ('#1074#1099#1087#1086#1083#1085#1077#1085#1080#1077')'
        DataBinding.FieldName = 'EXEC_OBJECT_BASE_PRIV'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 48
      end
      object cxGrid1DBTableView1INS_OBJECT_BASE_PRIV: TcxGridDBColumn
        Caption = #1042#1089#1090#1072#1074#1082#1072
        DataBinding.FieldName = 'INS_OBJECT_BASE_PRIV'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 51
      end
      object cxGrid1DBTableView1EDIT_OBJECT_BASE_PRIV: TcxGridDBColumn
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'EDIT_OBJECT_BASE_PRIV'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 44
      end
      object cxGrid1DBTableView1DEL_OBJECT_BASE_PRIV: TcxGridDBColumn
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077
        DataBinding.FieldName = 'DEL_OBJECT_BASE_PRIV'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 42
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
