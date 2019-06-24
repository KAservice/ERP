object FormaSpiskaSprNom: TFormaSpiskaSprNom
  Left = 337
  Top = 195
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'"'
  ClientHeight = 621
  ClientWidth = 943
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
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 943
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 285
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
    object RegimLabel: TLabel
      Left = 285
      Top = 43
      Width = 67
      Height = 13
      Caption = 'RegimLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 943
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
      object ToolButton5: TToolButton
        Left = 77
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1075#1088#1091#1087#1087#1099
        Caption = 'ToolButton5'
        ImageIndex = 35
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton5Click
      end
      object ToolButtonOpenSprNacenka: TToolButton
        Left = 100
        Top = 0
        Caption = 'ToolButtonOpenSprNacenka'
        ImageIndex = 41
        OnClick = ToolButtonOpenSprNacenkaClick
      end
      object ToolButton2: TToolButton
        Left = 123
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButtonViborFirm: TToolButton
        Left = 207
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1092#1080#1088#1084#1091
        Caption = 'ToolButtonViborFirm'
        DropdownMenu = PopupMenuSprFirm
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonViborSklad: TToolButton
        Left = 230
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1089#1082#1083#1072#1076
        Caption = 'ToolButtonViborSklad'
        DropdownMenu = PopupMenuSprSklad
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton8: TToolButton
        Left = 253
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1080#1085#1090#1077#1088#1085#1077#1090' '#1082#1072#1090#1072#1083#1086#1075
        Caption = 'ToolButton8'
        DropdownMenu = PopupMenuSprInetCatalog
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton3: TToolButton
        Left = 276
        Top = 0
        Width = 67
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
      object ToolButtonOnlyOstatok: TToolButton
        Left = 516
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1085#1077#1085#1091#1083#1077#1074#1099#1077' '#1086#1089#1090#1072#1090#1082#1080
        Caption = 'ToolButtonOnlyOstatok'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOnlyOstatokClick
      end
      object ToolButtonPriceSklad: TToolButton
        Left = 539
        Top = 0
        Hint = #1062#1077#1085#1099' '#1089#1082#1083#1072#1076#1072
        Caption = 'ToolButtonPriceSklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonPriceSkladClick
      end
      object ToolButtonCheckOnlyChange: TToolButton
        Left = 562
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1080#1079#1084#1077#1085#1077#1085#1085#1099#1077
        Caption = 'ToolButtonCheckOnlyChange'
        ImageIndex = 39
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        Visible = False
        OnClick = ToolButtonCheckOnlyChangeClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 585
        Top = 0
        Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074' '#1076#1088#1091#1075#1091#1102' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonIsmGrpClick
      end
      object ToolButtonAddSprBV: TToolButton
        Left = 608
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1073#1099#1089#1090#1088#1086#1075#1086' '#1074#1099#1079#1086#1074#1072
        Caption = 'ToolButtonAddSprBV'
        DropdownMenu = PopupMenuSprBV
        ImageIndex = 7
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonAddSprScale: TToolButton
        Left = 631
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1074#1077#1089#1086#1074
        Caption = 'ToolButtonAddSprScale'
        DropdownMenu = PopupMenuSprScale
        ImageIndex = 23
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonPrint: TToolButton
        Left = 654
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1074#1089#1077#1075#1086' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072
        Caption = 'ToolButtonPrint'
        ImageIndex = 35
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintClick
      end
      object ToolButtonClearChange: TToolButton
        Left = 677
        Top = 0
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100' '#1092#1083#1072#1075#1080' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Caption = 'ToolButtonClearChange'
        ImageIndex = 40
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonClearChangeClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 700
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton7: TToolButton
        Left = 723
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1092#1086#1088#1084#1099
        Caption = 'ToolButton7'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton7Click
      end
      object ToolButtonDelInetCatalog: TToolButton
        Left = 746
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079' '#1080#1085#1090#1077#1088#1085#1077#1090' '#1082#1072#1090#1072#1083#1086#1075#1072
        Caption = 'ToolButtonDelInetCatalog'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDelInetCatalogClick
      end
    end
    object SpisokTypePrice: TcxComboBox
      Left = 756
      Top = 46
      Properties.DropDownListStyle = lsFixedList
      Properties.ImmediatePost = True
      Properties.OnValidate = SpisokTypePricePropertiesValidate
      TabOrder = 1
      Width = 173
    end
    object cxComboBoxTypeOst: TcxComboBox
      Left = 556
      Top = 47
      Properties.Items.Strings = (
        #1041#1077#1079' '#1086#1089#1090#1072#1090#1082#1086#1074
        #1054#1089#1090#1072#1090#1082#1080': '#1054#1089#1085#1086#1085#1086#1081' '#1091#1095#1077#1090
        #1054#1089#1090#1072#1090#1082#1080': '#1087#1086#1076#1089#1080#1089#1090#1077#1084#1072' '#1056#1077#1084#1086#1085#1090
        #1054#1089#1090#1072#1082#1090#1080': '#1086#1073#1098#1077#1076#1080#1085#1077#1085#1085#1099#1077)
      Properties.OnChange = cxComboBoxTypeOstPropertiesChange
      TabOrder = 2
      Width = 190
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 9
    Height = 502
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 575
    Width = 943
    Height = 46
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    TabStop = True
    object LabelFirma: TLabel
      Left = 123
      Top = 6
      Width = 62
      Height = 13
      Alignment = taRightJustify
      Caption = 'LabelFirma'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSklad: TLabel
      Left = 429
      Top = 6
      Width = 64
      Height = 13
      Alignment = taRightJustify
      Caption = 'LabelSklad'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelInetCatalog: TLabel
      Left = 123
      Top = 25
      Width = 97
      Height = 13
      Alignment = taRightJustify
      Caption = 'LabelInetCatalog'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cxButtonClose: TcxButton
      Left = 698
      Top = 16
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonVibor: TcxButton
      Left = 606
      Top = 16
      Width = 75
      Height = 25
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1042#1099#1073#1088#1072#1090#1100
      TabOrder = 1
      OnClick = cxButtonViborClick
    end
  end
  object Panel4: TPanel
    Left = 935
    Top = 73
    Width = 8
    Height = 502
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object Panel5: TPanel
    Left = 269
    Top = 73
    Width = 10
    Height = 502
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 6
  end
  object cxTreeView1: TcxTreeView
    Left = 9
    Top = 73
    Width = 260
    Height = 502
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
    OnKeyDown = cxTreeView1KeyDown
    HideSelection = False
    ReadOnly = True
    RowSelect = True
  end
  object cxGrid1: TcxGrid
    Left = 279
    Top = 73
    Width = 656
    Height = 502
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
      OptionsCustomize.ColumnsQuickCustomization = True
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
      object cxGrid1DBTableView1ID_SNOMINETCAT: TcxGridDBColumn
        Caption = #1048#1050
        DataBinding.FieldName = 'ID_SNOMINETCAT'
        OnCustomDrawCell = cxGrid1DBTableView1ID_SNOMINETCATCustomDrawCell
        Width = 24
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 25
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 31
      end
      object cxGrid1DBTableView1NAME_STNOM: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1085#1086#1084'.'
        DataBinding.FieldName = 'NAME_STNOM'
        Width = 30
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 25
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Width = 38
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAMENOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 103
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 24
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        Width = 36
      end
      object cxGrid1DBTableView1ZNACH_PRICE: TcxGridDBColumn
        Caption = #1062#1077#1085#1072' ('#1089#1087#1088'.)'
        DataBinding.FieldName = 'ZNACH_PRICE'
        Styles.Content = DM.cxStyleHeaderTable
        Styles.Header = DM.cxStyleHeaderTable
        Width = 31
      end
      object cxGrid1DBTableView1OUT_PRICE_SKLAD: TcxGridDBColumn
        Caption = #1062#1077#1085#1072' ('#1089#1082#1083#1072#1076')'
        DataBinding.FieldName = 'OUT_PRICE_SKLAD'
        Styles.Content = DM.cxStyleHeaderTable
        Width = 33
      end
      object cxGrid1DBTableView1SUMKOL: TcxGridDBColumn
        Caption = #1054#1089#1090#1072#1090#1086#1082
        DataBinding.FieldName = 'SUMKOL'
        Styles.Content = DM.cxStyleHeaderTable
        Styles.Header = DM.cxStyleHeaderTable
        Width = 34
      end
      object cxGrid1DBTableView1IDNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDNOM'
        Visible = False
      end
      object cxGrid1DBTableView1REM_OST: TcxGridDBColumn
        Caption = #1054#1089#1090'. '#1088#1077#1084#1086#1085#1090
        DataBinding.FieldName = 'REM_OST'
        Styles.Content = DM.cxStyleHeaderTable
        Width = 34
      end
      object cxGrid1DBTableView1OUT_NAME_MHRAN: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'.'
        DataBinding.FieldName = 'OUT_NAME_MHRAN'
        Width = 45
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object PopupMenuSprBV: TPopupMenu
    OnPopup = PopupMenuSprBVPopup
    Left = 160
    Top = 272
  end
  object PopupMenuSprScale: TPopupMenu
    OnPopup = PopupMenuSprScalePopup
    Left = 64
    Top = 272
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 72
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
  end
  object PopupMenuSprFirm: TPopupMenu
    OnPopup = PopupMenuSprFirmPopup
    Left = 72
    Top = 104
  end
  object PopupMenuSprSklad: TPopupMenu
    OnPopup = PopupMenuSprSkladPopup
    Left = 192
    Top = 104
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 112
    Top = 360
  end
  object PopupMenuSprInetCatalog: TPopupMenu
    OnPopup = PopupMenuSprInetCatalogPopup
    Left = 72
    Top = 168
  end
end
