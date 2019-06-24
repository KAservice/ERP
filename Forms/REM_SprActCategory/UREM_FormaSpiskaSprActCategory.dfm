object REM_FormaSpiskaSprActCategory: TREM_FormaSpiskaSprActCategory
  Left = 244
  Top = 12
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1050#1072#1090#1077#1075#1086#1088#1080#1080' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103' ('#1047#1072#1103#1074#1082#1080' '#1085#1072' '#1088#1077#1084#1086#1085#1090')'
  ClientHeight = 496
  ClientWidth = 556
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
    Width = 556
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 556
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
      object ToolButtonInsert: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonInsert'
        ImageIndex = 0
        OnClick = ToolButtonInsertClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        Style = tbsCheck
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 70
    Width = 11
    Height = 356
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
    Top = 426
    Width = 556
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 452
      Top = 28
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
    Left = 544
    Top = 70
    Width = 12
    Height = 356
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
    Top = 70
    Width = 533
    Height = 356
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
      OptionsData.Editing = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 79
      end
      object cxGrid1DBTableView1NAME_TPRICE: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_SPRODUCER'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 207
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 93
      end
      object cxGrid1DBTableViewINNKLIENT: TcxGridDBColumn
        DataBinding.FieldName = 'INNKLIENT'
        Width = 81
      end
      object cxGrid1DBTableView1POSZAGRNOM_SPRODUCER: TcxGridDBColumn
        DataBinding.FieldName = 'POSZAGRNOM_SPRODUCER'
        Width = 71
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
end
