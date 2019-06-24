object FormaElementaExtModule: TFormaElementaExtModule
  Left = 462
  Top = 235
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1042#1085#1077#1096#1085#1080#1077' '#1084#1086#1076#1091#1083#1080'"'
  ClientHeight = 518
  ClientWidth = 538
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 11
    Top = 49
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 69
    Top = 82
    Width = 38
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1072#1081#1083':'
  end
  object cxButtonOK: TcxButton
    Left = 299
    Top = 478
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 414
    Top = 478
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object cxLabel2: TcxLabel
    Left = 210
    Top = 11
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1084#1086#1076#1091#1083#1103':'
  end
  object TypeModulecxDBImageComboBox: TcxDBImageComboBox
    Left = 319
    Top = 10
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeExtModule
    DataBinding.DataField = 'TYPE_EXT_MODULE'
    Properties.Items = <>
    TabOrder = 1
    Width = 192
  end
  object NameObjectcxDBTextEdit: TcxDBTextEdit
    Left = 116
    Top = 46
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_EXT_MODULE'
    TabOrder = 2
    Width = 395
  end
  object FileNamecxDBButtonEdit: TcxDBButtonEdit
    Left = 116
    Top = 79
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'FILE_NAME_EXT_MODULE'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = FileNamecxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 395
  end
  object IspcxDBCheckBox: TcxDBCheckBox
    Left = 15
    Top = 10
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100
    DataBinding.DataField = 'ISP_EXT_MODULE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 0
    Width = 149
  end
  object GroupBox1: TGroupBox
    Left = 10
    Top = 185
    Width = 493
    Height = 253
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1072#1074#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
    TabOrder = 7
    object ToolBar1: TToolBar
      Left = 2
      Top = 18
      Width = 489
      Height = 24
      Caption = 'ToolBar1'
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton3: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton1: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButton1'
        ImageIndex = 0
        OnClick = ToolButton1Click
      end
      object ToolButton2: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButton2'
        ImageIndex = 2
        OnClick = ToolButton2Click
      end
    end
    object cxGrid1: TcxGrid
      Left = 2
      Top = 42
      Width = 489
      Height = 209
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      TabOrder = 1
      object cxGrid1DBTableView1: TcxGridDBTableView
        NavigatorButtons.ConfirmDelete = False
        DataController.DataSource = DMExtModulePriv.DataSourceTable
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        Styles.Header = DM.cxStyleHeaderTable
        object cxGrid1DBTableView1IDGRPUSER_EXT_MODULE_PRIV: TcxGridDBColumn
          Caption = #1043#1088#1091#1087#1087#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
          DataBinding.FieldName = 'IDGRPUSER_EXT_MODULE_PRIV'
          PropertiesClassName = 'TcxLookupComboBoxProperties'
          Properties.KeyFieldNames = 'ID_SGRPUSER'
          Properties.ListColumns = <
            item
              FieldName = 'NAME_SGRPUSER'
            end>
          Properties.ListSource = DMExtModulePriv.DataSourceSprGrpUser
          Width = 284
        end
        object cxGrid1DBTableView1EXEC_EXT_MODULE_PRIV: TcxGridDBColumn
          Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1080#1077
          DataBinding.FieldName = 'EXEC_EXT_MODULE_PRIV'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 119
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
  end
  object cxDBRadioGroupResidence: TcxDBRadioGroup
    Left = 10
    Top = 117
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1093#1088#1072#1085#1077#1085#1080#1103' '#1084#1086#1076#1091#1083#1103
    DataBinding.DataField = 'RESIDENCE_EXT_MODULE'
    Properties.Columns = 2
    Properties.Items = <
      item
        Caption = #1042' '#1092#1072#1081#1083#1077
        Value = 0
      end
      item
        Caption = #1042' '#1073#1072#1079#1077
        Value = 1
      end>
    TabOrder = 8
    Height = 60
    Width = 395
  end
  object cxButtonFileInBlob: TcxButton
    Left = 412
    Top = 134
    Width = 117
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1079' '#1092#1072#1081#1083#1072' '#1074' '#1073#1072#1079#1091
    TabOrder = 9
    OnClick = cxButtonFileInBlobClick
  end
  object cxButtonBlobInFile: TcxButton
    Left = 159
    Top = 478
    Width = 117
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1079' '#1073#1072#1079#1099' '#1074' '#1092#1072#1081#1083
    TabOrder = 10
    OnClick = cxButtonBlobInFileClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 352
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 384
    Top = 64
  end
  object SaveDialog1: TSaveDialog
    Left = 48
    Top = 464
  end
end
