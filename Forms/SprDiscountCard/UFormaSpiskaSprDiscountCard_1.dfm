object FormaSpiskaSprDiscountCard_1: TFormaSpiskaSprDiscountCard_1
  Left = 195
  Top = 147
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1076#1080#1089#1082#1086#1085#1090#1085#1099#1093' '#1082#1072#1088#1090':'
  ClientHeight = 604
  ClientWidth = 921
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
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 921
    Height = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 345
      Top = 59
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
    object ToolBar3: TToolBar
      Left = 0
      Top = 0
      Width = 921
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
      object ToolButtonEditGrp: TToolButton
        Left = 31
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonEditGrp'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditGrpClick
      end
      object ToolButtonDelGrp: TToolButton
        Left = 54
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonDelGrp'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDelGrpClick
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
        Width = 120
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 281
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1077#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 304
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 327
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 350
        Top = 0
        Width = 27
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAllElement: TToolButton
        Left = 377
        Top = 0
        Hint = #1054#1090#1082#1083#1102#1095#1080#1090#1100' '#1080#1077#1088#1072#1088#1093#1080#1102' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
        Caption = 'ToolButtonAllElement'
        ImageIndex = 8
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonAllElementClick
      end
      object ToolButtonUpdateForm: TToolButton
        Left = 400
        Top = 0
        Caption = 'ToolButtonUpdateForm'
        ImageIndex = 48
        OnClick = ToolButtonUpdateFormClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 423
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 80
    Width = 11
    Height = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 914
    Top = 80
    Width = 7
    Height = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 4
  end
  object Panel4: TPanel
    Left = 0
    Top = 544
    Width = 921
    Height = 60
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object cxButtonClose: TcxButton
      Left = 822
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
  end
  object cxGrid1: TcxGrid
    Left = 327
    Top = 80
    Width = 587
    Height = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyDown = cxGrid1DBTableView1KeyDown
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
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470' '#1087'.'
        DataBinding.FieldName = 'RECNO'
        Width = 22
      end
      object cxGrid1DBTableView1ACT_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1040#1089#1090'.'
        DataBinding.FieldName = 'ACT_SDISCOUNT_CARD'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 21
      end
      object cxGrid1DBTableView1SINGLE_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1054#1076#1085#1086#1088#1072#1079#1086#1074#1072#1103
        DataBinding.FieldName = 'SINGLE_SDISCOUNT_CARD'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 37
      end
      object cxGrid1DBTableView1CODE_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_SDISCOUNT_CARD'
        Width = 43
      end
      object cxGrid1DBTableView1SHCODE_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1064#1088#1080#1093'-'#1082#1086#1076
        DataBinding.FieldName = 'SHCODE_SDISCOUNT_CARD'
        Width = 76
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 84
      end
      object cxGrid1DBTableView1NAME_SVID_DCARD: TcxGridDBColumn
        Caption = #1042#1080#1076' '#1082#1072#1088#1090#1099
        DataBinding.FieldName = 'NAME_SVID_DCARD'
        Width = 78
      end
      object cxGrid1DBTableView1NAME_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_SDISCOUNT_CARD'
        Width = 74
      end
      object cxGrid1DBTableView1TYPE_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TYPE_SDISCOUNT_CARD'
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem1TypeDiscountCard
        Width = 37
      end
      object cxGrid1DBTableView1NACH_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1053#1072#1095'.'
        DataBinding.FieldName = 'NACH_SDISCOUNT_CARD'
        Width = 39
      end
      object cxGrid1DBTableView1CON_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = #1050#1086#1085'.'
        DataBinding.FieldName = 'CON_SDISCOUNT_CARD'
        Width = 38
      end
      object cxGrid1DBTableView1PRSK_SDISCOUNT_CARD: TcxGridDBColumn
        Caption = '%'
        DataBinding.FieldName = 'PRSK_SDISCOUNT_CARD'
        Width = 36
      end
      object cxGrid1DBTableView1ID_SDISCOUNT_CARD: TcxGridDBColumn
        DataBinding.FieldName = 'ID_SDISCOUNT_CARD'
        Visible = False
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxTreeView1: TcxTreeView
    Left = 11
    Top = 80
    Width = 308
    Height = 464
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
    OnKeyDown = cxTreeView1KeyDown
    HideSelection = False
    ReadOnly = True
  end
  object Panel6: TPanel
    Left = 319
    Top = 80
    Width = 8
    Height = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 6
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
    Left = 432
    Top = 24
  end
end
