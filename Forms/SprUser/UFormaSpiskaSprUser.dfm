object FormaSpiskaSprUser: TFormaSpiskaSprUser
  Left = 461
  Top = 146
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082'  '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
  ClientHeight = 420
  ClientWidth = 823
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
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 823
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 303
      Top = 51
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
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 823
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton3: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object NewGrpUserToolButton: TToolButton
        Left = 8
        Top = 0
        Action = ActionNewGrpUser
      end
      object EditGrpUserToolButton: TToolButton
        Left = 31
        Top = 0
        Action = ActionEditGrpUser
      end
      object DeleteGrpUserToolButton: TToolButton
        Left = 54
        Top = 0
        Action = ActionDeleteGrpUser
      end
      object ToolButtonAddStandartGrup: TToolButton
        Left = 77
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1099#1077' '#1075#1088#1091#1087#1087#1099
        Caption = 'ToolButtonAddStandartGrup'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddStandartGrupClick
      end
      object ToolButton1: TToolButton
        Left = 100
        Top = 0
        Width = 236
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 336
        Top = 0
        Action = ActionNewElement
      end
      object ToolButtonEdit: TToolButton
        Left = 359
        Top = 0
        Action = ActionEditElement
      end
      object ToolButtonDelete: TToolButton
        Left = 382
        Top = 0
        Action = ActionDeleteElement
      end
      object ToolButton5: TToolButton
        Left = 405
        Top = 0
        Width = 8
        Caption = 'ToolButton5'
        ImageIndex = 10
        Style = tbsSeparator
      end
      object ToolButton2: TToolButton
        Left = 413
        Top = 0
        Action = ActionPoGrp
        Style = tbsCheck
      end
      object ToolButton4: TToolButton
        Left = 436
        Top = 0
        Action = ActionChangeGrp
      end
      object ToolButtonUpdate: TToolButton
        Left = 459
        Top = 0
        Caption = 'ToolButtonUpdate'
        ImageIndex = 48
        OnClick = ToolButtonUpdateClick
      end
      object ToolButton6: TToolButton
        Left = 482
        Top = 0
        Width = 141
        Caption = 'ToolButton6'
        ImageIndex = 50
        Style = tbsSeparator
      end
      object ToolButtonNewUserServer: TToolButton
        Left = 623
        Top = 0
        Hint = #1047#1072#1088#1077#1075#1080#1089#1090#1088#1080#1088#1086#1074#1072#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103' '#1085#1072' '#1089#1077#1088#1074#1077#1088#1077
        Caption = 'ToolButtonNewUserServer'
        ImageIndex = 49
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewUserServerClick
      end
      object ToolButtonNasnRoleAllUser: TToolButton
        Left = 646
        Top = 0
        Hint = #1053#1072#1079#1085#1072#1095#1080#1090#1100' '#1088#1086#1083#1080' '#1074#1089#1077#1084' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103#1084
        Caption = 'ToolButtonNasnRoleAllUser'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNasnRoleAllUserClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 8
    Height = 291
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 816
    Top = 73
    Width = 7
    Height = 291
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object Panel4: TPanel
    Left = 0
    Top = 364
    Width = 823
    Height = 56
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
    object cxButtonClose: TcxButton
      Left = 647
      Top = 15
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel5: TPanel
    Left = 282
    Top = 73
    Width = 8
    Height = 291
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 6
  end
  object cxGrid1: TcxGrid
    Left = 290
    Top = 73
    Width = 526
    Height = 291
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
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1048#1084#1103
        DataBinding.FieldName = 'NAME_USER'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 175
      end
      object cxGrid1DBTableView1NAME2_USER: TcxGridDBColumn
        Caption = #1048#1084#1103' 2'
        DataBinding.FieldName = 'NAME2_USER'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 150
      end
      object cxGrid1DBTableView1FNAME_USER: TcxGridDBColumn
        Caption = #1055#1086#1083#1085#1086#1077' '#1080#1084#1103
        DataBinding.FieldName = 'FNAME_USER'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 171
      end
      object cxGrid1DBTableView1USERID: TcxGridDBColumn
        Caption = #1057#1077#1088#1074#1077#1088
        DataBinding.FieldName = 'USERID'
        OnCustomDrawCell = cxGrid1DBTableView1USERIDCustomDrawCell
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 28
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxTreeView1: TcxTreeView
    Left = 8
    Top = 73
    Width = 274
    Height = 291
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
    HideSelection = False
    ReadOnly = True
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
    object ActionNewGrpUser: TAction
      Caption = 'ActionNewGrpUser'
      ImageIndex = 0
      OnExecute = ActionNewGrpUserExecute
    end
    object ActionEditGrpUser: TAction
      Caption = 'ActionEditGrpUser'
      ImageIndex = 1
      OnExecute = ActionEditGrpUserExecute
    end
    object ActionDeleteGrpUser: TAction
      Caption = 'ActionDeleteGrpUser'
      ImageIndex = 2
      OnExecute = ActionDeleteGrpUserExecute
    end
    object ActionNewElement: TAction
      Caption = 'ActionNewElement'
      ImageIndex = 0
      OnExecute = ActionNewElementExecute
    end
    object ActionEditElement: TAction
      Caption = 'ActionEditElement'
      ImageIndex = 1
      OnExecute = ActionEditElementExecute
    end
    object ActionDeleteElement: TAction
      Caption = 'ActionDeleteElement'
      ImageIndex = 2
      OnExecute = ActionDeleteElementExecute
    end
    object ActionPoGrp: TAction
      Caption = 'ActionPoGrp'
      ImageIndex = 8
      OnExecute = ActionPoGrpExecute
    end
    object ActionChangeGrp: TAction
      Caption = 'ActionChangeGrp'
      ImageIndex = 9
      OnExecute = ActionChangeGrpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
