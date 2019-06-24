object FormaSpiskaSprOborudParam: TFormaSpiskaSprOborudParam
  Left = 417
  Top = 182
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 303
  ClientWidth = 591
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
    Width = 591
    Height = 89
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object LabelHeader: TLabel
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
      Width = 591
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
      object ToolButtonGetParameterIsFiskRegSaveInFile: TToolButton
        Left = 54
        Top = 0
        Hint = 
          #1055#1086#1083#1091#1095#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1079' '#1092#1080#1089#1082#1072#1083#1100#1085#1086#1075#1086' '#1088#1077#1075#1080#1089#1090#1088#1072#1090#1086#1088#1072' '#1080' '#1089#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073 +
          #1091#1092#1077#1088
        Caption = 'ToolButtonGetParameterIsFiskRegSaveInFile'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonGetParameterIsFiskRegSaveInFileClick
      end
      object ToolButtonSaveInFileDopAction: TToolButton
        Left = 77
        Top = 0
        Hint = 
          #1055#1086#1083#1091#1095#1080#1090#1100' '#1076#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1076#1077#1081#1089#1090#1074#1080#1103' '#1080#1079' '#1092#1080#1089#1082#1072#1083#1100#1085#1086#1075#1086' '#1088#1077#1075#1080#1089#1090#1088#1072#1090#1086#1088#1072' '#1080' '#1089 +
          #1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088
        Caption = 'ToolButtonSaveInFileDopAction'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSaveInFileDopActionClick
      end
      object ToolButtonGetSpisokMetod: TToolButton
        Left = 100
        Top = 0
        Hint = #1055#1086#1083#1091#1095#1080#1090#1100#1057#1087#1080#1089#1086#1082' '#1084#1077#1090#1086#1076#1086#1074
        Caption = 'ToolButtonGetSpisokMetod'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonGetSpisokMetodClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 9
    Height = 145
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 234
    Width = 591
    Height = 69
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 269
      Top = 14
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 188
      Top = 14
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 579
    Top = 89
    Width = 12
    Height = 145
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 89
    Width = 570
    Height = 145
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
      object cxGrid1DBTableView1ID_SOBORUD_PAR: TcxGridDBColumn
        DataBinding.FieldName = 'ID_SOBORUD_PAR'
        Visible = False
      end
      object cxGrid1DBTableView1INDEX_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089
        DataBinding.FieldName = 'INDEX_SOBORUD_PAR'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 44
      end
      object cxGrid1DBTableView1NAME_GRP_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_GRP_SOBORUD_PAR'
        Width = 66
      end
      object cxGrid1DBTableView1NAME_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_SOBORUD_PAR'
        Width = 66
      end
      object cxGrid1DBTableView1TYPE_PARAMETER_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TYPE_PARAMETER_SOBORUD_PAR'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeValue
        Width = 65
      end
      object cxGrid1DBTableView1VALUE_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1047#1085#1072#1095#1077#1085#1080#1077
        DataBinding.FieldName = 'VALUE_SOBORUD_PAR'
        Width = 90
      end
      object cxGrid1DBTableView1VALUE_TIMESTAMP_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1047#1085#1072#1095#1077#1085#1080#1077' ('#1044#1072#1090#1072')'
        DataBinding.FieldName = 'VALUE_TIMESTAMP_SOBORUD_PAR'
        PropertiesClassName = 'TcxDateEditProperties'
        Width = 145
      end
      object cxGrid1DBTableView1BEFORE_CONNECT_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1044#1086
        DataBinding.FieldName = 'BEFORE_CONNECT_SOBORUD_PAR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 32
      end
      object cxGrid1DBTableView1AFTER_CONNECT_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1055#1086#1089#1083#1077
        DataBinding.FieldName = 'AFTER_CONNECT_SOBORUD_PAR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 31
      end
      object cxGrid1DBTableView1ON_CONNECT_SOBORUD_PAR: TcxGridDBColumn
        Caption = #1055#1088#1080' '#1082#1072#1078#1076#1086#1084' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1080
        DataBinding.FieldName = 'ON_CONNECT_SOBORUD_PAR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 29
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 368
    Top = 24
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
  object SaveTextFileDialog1: TSaveTextFileDialog
    Left = 64
    Top = 240
  end
end
