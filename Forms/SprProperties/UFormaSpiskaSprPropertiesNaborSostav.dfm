object FormaSpiskaSprPropertiesNaborSostav: TFormaSpiskaSprPropertiesNaborSostav
  Left = 240
  Top = 20
  Caption = #1057#1086#1089#1090#1072#1074' '#1085#1072#1073#1086#1088#1072' '#1089#1074#1086#1081#1089#1090#1074' ('#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082')'
  ClientHeight = 528
  ClientWidth = 646
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
    Width = 646
    Height = 60
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
      Width = 646
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 9
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 9
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 32
        Top = 0
        Hint = #1048#1079#1084#1077#1085#1080#1090#1100
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 55
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton3: TToolButton
        Left = 78
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton3'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object LabelHeaderText: TLabel
        Left = 101
        Top = 0
        Width = 206
        Height = 22
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ToolButton2: TToolButton
        Left = 307
        Top = 0
        Width = 6
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 60
    Width = 11
    Height = 403
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
    Top = 463
    Width = 646
    Height = 65
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 538
      Top = 17
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 630
    Top = 60
    Width = 16
    Height = 403
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 60
    Width = 619
    Height = 403
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 34
      end
      object cxGrid1DBTableView1INDEX_SNOMPROPVALUE: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089
        DataBinding.FieldName = 'INDEXSORT_SPROPNABOR_SOST'
        Width = 32
      end
      object cxGrid1DBTableView1NAME_SPROP_GRP: TcxGridDBColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_SPROP_GRP'
        Width = 85
      end
      object cxGrid1DBTableView1NAME_FOR_PRINT_SPROP_GRP: TcxGridDBColumn
        Caption = #1043#1088#1091#1087#1087#1072' ('#1076#1083#1103' '#1087#1077#1095#1072#1090#1080')'
        DataBinding.FieldName = 'NAME_FOR_PRINT_SPROP_GRP'
        Width = 84
      end
      object cxGrid1DBTableView1NAME_SPROP: TcxGridDBColumn
        Caption = #1057#1074#1086#1081#1089#1090#1074#1086
        DataBinding.FieldName = 'NAME_SPROP'
        PropertiesClassName = 'TcxMemoProperties'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 130
      end
      object cxGrid1DBTableView1NAME_FOR_PRINT_SPROP: TcxGridDBColumn
        Caption = #1057#1074#1086#1081#1089#1090#1074#1086' ('#1076#1083#1103' '#1087#1077#1095#1072#1090#1080')'
        DataBinding.FieldName = 'NAME_FOR_PRINT_SPROP'
        Width = 112
      end
      object cxGrid1DBTableView1Column1: TcxGridDBColumn
        DataBinding.FieldName = 'ADD1_SPROPNABOR_SOST'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 25
      end
      object cxGrid1DBTableView1Column2: TcxGridDBColumn
        DataBinding.FieldName = 'ADD2_SPROPNABOR_SOST'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 25
      end
      object cxGrid1DBTableView1Column3: TcxGridDBColumn
        DataBinding.FieldName = 'ADD3_SPROPNABOR_SOST'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 25
      end
      object cxGrid1DBTableView1Column4: TcxGridDBColumn
        DataBinding.FieldName = 'ADD4_SPROPNABOR_SOST'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 29
      end
      object cxGrid1DBTableView1Column5: TcxGridDBColumn
        DataBinding.FieldName = 'ADD5_SPROPNABOR_SOST'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 24
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
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
  object PopupMenuExtModule: TPopupMenu
    Left = 104
    Top = 16
  end
end
