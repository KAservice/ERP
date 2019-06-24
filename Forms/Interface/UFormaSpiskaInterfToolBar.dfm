object FormaSpiskaInterfToolBar: TFormaSpiskaInterfToolBar
  Left = 339
  Top = 240
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1072#1085#1077#1083#1080' '#1082#1085#1086#1087#1086#1082
  ClientHeight = 593
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
    Height = 97
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
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
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 77
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 112
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 135
        Top = 0
        Caption = 'ToolButton5'
        ImageIndex = 48
        OnClick = ToolButton5Click
      end
      object ToolButton6: TToolButton
        Left = 158
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1091#1102' '#1087#1072#1085#1077#1083#1100' '#1082#1085#1086#1087#1086#1082
        Action = ActionCreateFullStandartMainMenu
        ParentShowHint = False
        ShowHint = True
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
    Top = 97
    Width = 11
    Height = 440
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 537
    Width = 969
    Height = 56
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
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
    Top = 97
    Width = 10
    Height = 440
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object Panel5: TPanel
    Left = 11
    Top = 97
    Width = 14
    Height = 440
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object cxGrid1: TcxGrid
    Left = 25
    Top = 97
    Width = 934
    Height = 440
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMInterfToolBar.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 30
      end
      object cxGrid1DBTableView1NAME_INTERF_TOOLBAR: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_INTERF_TOOLBAR'
        Width = 191
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
        Width = 294
      end
      object cxGrid1DBTableView1MODUL_INTERF_TOOLBAR: TcxGridDBColumn
        Caption = #1052#1086#1076#1091#1083#1100' ('#1085#1077' '#1080#1089#1087'.)'
        DataBinding.FieldName = 'MODUL_INTERF_TOOLBAR'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxGC_Forms
        Width = 100
      end
      object cxGrid1DBTableView1HINT_INTERF_TOOLBAR: TcxGridDBColumn
        Caption = #1055#1086#1076#1089#1082#1072#1079#1082#1072
        DataBinding.FieldName = 'HINT_INTERF_TOOLBAR'
        Width = 190
      end
      object cxGrid1DBTableView1IMAGEINDEX_INTERF_TOOLBAR: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089' '#1087#1080#1082#1090#1086#1075#1088#1072#1084#1084#1099
        DataBinding.FieldName = 'IMAGEINDEX_INTERF_TOOLBAR'
        Width = 65
      end
      object cxGrid1DBTableView1INDEX_INTERF_TOOLBAR: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1080
        DataBinding.FieldName = 'INDEX_INTERF_TOOLBAR'
        Width = 62
      end
      object cxGrid1DBTableView1PATCH_PROGRAM_MODULE: TcxGridDBColumn
        DataBinding.FieldName = 'PATCH_PROGRAM_MODULE'
      end
      object cxGrid1DBTableView1GUIDMOD_INTERF_TOOLBAR: TcxGridDBColumn
        DataBinding.FieldName = 'GUIDMOD_INTERF_TOOLBAR'
      end
      object cxGrid1DBTableView1IDEL_INTERF_TOOLBAR: TcxGridDBColumn
        DataBinding.FieldName = 'IDEL_INTERF_TOOLBAR'
      end
      object cxGrid1DBTableView1FL_OPEN_EL_INTERF_TOOLBAR: TcxGridDBColumn
        DataBinding.FieldName = 'FL_OPEN_EL_INTERF_TOOLBAR'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 216
    Top = 16
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
    Left = 392
    Top = 16
  end
end
