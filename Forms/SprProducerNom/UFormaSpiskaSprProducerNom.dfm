object FormaSpiskaSprProducerNom: TFormaSpiskaSprProducerNom
  Left = 337
  Top = 195
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'"'
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
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  OnResize = FormResize
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
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 364
      Top = 45
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
    object RegimLabel: TLabel
      Left = 364
      Top = 33
      Width = 85
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'RegimLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 114
      Top = 33
      Width = 203
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1076#1086' '#1085#1072#1078#1080#1084#1072#1090#1100' '#1054#1041#1053#1054#1042#1048#1058#1068
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelObnovleno: TLabel
      Left = 748
      Top = 73
      Width = 84
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1085#1086#1074#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 969
      Height = 26
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
      object ToolButtonNewGrp: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonNewGrp'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewGrpClick
      end
      object ToolButtonEdiGrp: TToolButton
        Left = 31
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonEdiGrp'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEdiGrpClick
      end
      object ToolButtonDeleteGrp: TToolButton
        Left = 54
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonDeleteGrp'
        ImageIndex = 2
        OnClick = ToolButtonDeleteGrpClick
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
        Width = 182
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 343
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1077#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonCopyRecord: TToolButton
        Left = 366
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1087#1080#1089#1100
        Caption = 'ToolButtonCopyRecord'
        ImageIndex = 52
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCopyRecordClick
      end
      object ToolButtonEdit: TToolButton
        Left = 389
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 412
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton6: TToolButton
        Left = 435
        Top = 0
        Caption = 'ToolButton6'
        ImageIndex = 48
        OnClick = ToolButton6Click
      end
      object ToolButton4: TToolButton
        Left = 458
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 493
        Top = 0
        Hint = #1054#1090#1082#1083#1102#1095#1080#1090#1100' '#1080#1077#1088#1072#1088#1093#1080#1102' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 516
        Top = 0
        Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074' '#1076#1088#1091#1075#1091#1102' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonIsmGrpClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 539
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton7: TToolButton
        Left = 562
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1092#1086#1088#1084#1099
        Caption = 'ToolButton7'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton7Click
      end
      object ToolButtonPoiskPoModel: TToolButton
        Left = 585
        Top = 0
        Hint = #1048#1089#1082#1072#1090#1100' '#1087#1086' '#1087#1086#1083#1085#1086#1084#1091' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1102' '#1084#1086#1076#1077#1083#1080
        Caption = 'ToolButtonPoiskPoModel'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPoiskPoModelClick
      end
      object ToolButtonSetDostupno0: TToolButton
        Left = 608
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1044#1086#1089#1090#1091#1087#1085#1086' '#1074' '#1085#1086#1083#1100
        Caption = 'ToolButtonSetDostupno0'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetDostupno0Click
      end
    end
    object SpisokTypePrice: TcxComboBox
      Left = 746
      Top = 36
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.ImmediatePost = True
      Properties.OnValidate = SpisokTypePricePropertiesValidate
      TabOrder = 1
      Width = 213
    end
    object NameGroupElementcxComboBox: TcxComboBox
      Left = 14
      Top = 63
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = NameGroupElementcxComboBoxPropertiesChange
      TabOrder = 2
      Width = 321
    end
    object InputStrcxTextEdit: TcxTextEdit
      Left = 458
      Top = 66
      TabOrder = 3
      Text = 'InputStrcxTextEdit'
      Width = 159
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 97
    Width = 11
    Height = 522
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
    TabStop = True
    object cxButtonClose: TcxButton
      Left = 859
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonVibor: TcxButton
      Left = 746
      Top = 20
      Width = 92
      Height = 30
      Caption = #1042#1099#1073#1088#1072#1090#1100
      TabOrder = 1
      OnClick = cxButtonViborClick
    end
  end
  object Panel4: TPanel
    Left = 959
    Top = 97
    Width = 10
    Height = 522
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
    Left = 257
    Top = 97
    Width = 12
    Height = 522
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
    Top = 97
    Width = 246
    Height = 522
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
    OnKeyDown = cxTreeView1KeyDown
    HideSelection = False
    ReadOnly = True
    RowSelect = True
  end
  object cxGrid1: TcxGrid
    Left = 269
    Top = 97
    Width = 690
    Height = 522
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
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsSelection.MultiSelect = True
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1FL_DOSTUPNO_SPRNOM: TcxGridDBColumn
        Caption = #1044#1086#1089#1090#1091#1087#1085#1086
        DataBinding.FieldName = 'FL_DOSTUPNO_SPRNOM'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 21
      end
      object cxGrid1DBTableView1CODE_SPRNOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_SPRNOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 24
      end
      object cxGrid1DBTableView1ART_SPRNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ART_SPRNOM'
        Width = 62
      end
      object cxGrid1DBTableView1ART2_SPRNOM: TcxGridDBColumn
        DataBinding.FieldName = 'ART2_SPRNOM'
        Width = 48
      end
      object cxGrid1DBTableView1CODE_ANALOG_STR_SPRNOM: TcxGridDBColumn
        Caption = #1040#1085#1072#1083#1086#1075
        DataBinding.FieldName = 'CODE_ANALOG_STR_SPRNOM'
        Width = 40
      end
      object cxGrid1DBTableView1NAME_SPRNOM: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_SPRNOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 139
      end
      object cxGrid1DBTableView1NAME_SPRED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAME_SPRED'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 23
      end
      object cxGrid1DBTableView1BARCODE_SPREDED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'BARCODE_SPREDED'
        Width = 37
      end
      object cxGrid1DBTableView1VALUE_SPRPRICE: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'VALUE_SPRPRICE'
        Styles.Content = DM.cxStyleHeaderTable
        Styles.Header = DM.cxStyleHeaderTable
        Width = 40
      end
      object cxGrid1DBTableView1ID_SPRNOM: TcxGridDBColumn
        DataBinding.FieldName = 'ID_SPRNOM'
        Visible = False
      end
      object cxGrid1DBTableView1MODEL_SPRNOM: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_STR_SPRNOM'
        Width = 34
      end
      object cxGrid1DBTableView1PRICE_ZAKUP_SPRNOM: TcxGridDBColumn
        Caption = #1062#1077#1085#1072' '#1079#1072#1082'.'
        DataBinding.FieldName = 'PRICE_ZAKUP_SPRNOM'
        Width = 25
      end
      object cxGrid1DBTableView1PRICE_SPRNOM: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_SPRNOM'
        Width = 21
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076' '#1085#1086#1084'.'
        DataBinding.FieldName = 'CODENOM'
        Width = 31
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083' '#1085#1086#1084'.'
        DataBinding.FieldName = 'ARTNOM'
        Width = 27
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Width = 35
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        Width = 29
      end
      object cxGrid1DBTableView1ISM_SPRNOM: TcxGridDBColumn
        DataBinding.FieldName = 'ISM_SPRNOM'
        Width = 52
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxButtonPoisk: TcxButton
    Left = 632
    Top = 65
    Width = 75
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 7
    OnClick = cxButtonPoiskClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
    Top = 48
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
    Left = 656
    Top = 24
  end
end
