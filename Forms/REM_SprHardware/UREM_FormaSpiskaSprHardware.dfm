object REM_FormaSpiskaSprHardware: TREM_FormaSpiskaSprHardware
  Left = 337
  Top = 195
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'"'
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
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 969
    Height = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    ExplicitTop = 19
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
        Width = 154
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 231
        Top = 0
        Width = 113
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 344
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1077#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 367
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 390
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton6: TToolButton
        Left = 413
        Top = 0
        Caption = 'ToolButton6'
        ImageIndex = 48
        OnClick = ToolButton6Click
      end
      object ToolButton4: TToolButton
        Left = 436
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 471
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
        Left = 494
        Top = 0
        Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074' '#1076#1088#1091#1075#1091#1102' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonIsmGrpClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 517
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 11
    Height = 562
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
    TabOrder = 3
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
  end
  object Panel4: TPanel
    Left = 959
    Top = 57
    Width = 10
    Height = 562
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
    Left = 231
    Top = 57
    Width = 12
    Height = 562
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
    ExplicitLeft = 331
  end
  object cxTreeView1: TcxTreeView
    Left = 11
    Top = 57
    Width = 220
    Height = 562
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
    RowSelect = True
  end
  object Panel6: TPanel
    Left = 243
    Top = 57
    Width = 716
    Height = 562
    Align = alClient
    BevelEdges = []
    BevelOuter = bvNone
    TabOrder = 6
    ExplicitLeft = 343
    ExplicitWidth = 616
    object Panel7: TPanel
      Left = 0
      Top = 0
      Width = 716
      Height = 97
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitWidth = 616
      object LabelNameGrp: TLabel
        Left = 8
        Top = 69
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
      object SerNumcxTextEdit: TcxTextEdit
        Left = 7
        Top = 26
        TabOrder = 0
        Text = 'SerNumcxTextEdit'
        Width = 214
      end
      object SerNum2cxTextEdit: TcxTextEdit
        Left = 227
        Top = 26
        TabOrder = 1
        Text = 'SerNum2cxTextEdit'
        Width = 198
      end
      object cxLabel2: TcxLabel
        Left = 227
        Top = 0
        Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088' 2:'
      end
      object cxLabel1: TcxLabel
        Left = 7
        Top = 0
        Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
      end
      object cxButtonPoiskPoSerNum: TcxButton
        Left = 431
        Top = 7
        Width = 177
        Height = 25
        Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091
        TabOrder = 4
        OnClick = cxButtonPoiskPoSerNumClick
      end
      object cxButtonPoiskPoSerNum2: TcxButton
        Left = 432
        Top = 38
        Width = 177
        Height = 25
        Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091' 2'
        TabOrder = 5
        OnClick = cxButtonPoiskPoSerNum2Click
      end
      object cxButtonPoiskPoSerNumStr: TcxButton
        Left = 432
        Top = 69
        Width = 177
        Height = 25
        Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1089#1077#1088'. '#1085#1086#1084#1077#1088#1091' ('#1089#1090#1088'.)'
        TabOrder = 6
        OnClick = cxButtonPoiskPoSerNumStrClick
      end
    end
    object cxGrid1: TcxGrid
      Left = 0
      Top = 97
      Width = 716
      Height = 465
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      TabOrder = 1
      ExplicitWidth = 616
      object cxGrid1DBTableView1: TcxGridDBTableView
        OnDblClick = cxGrid1DBTableView1DblClick
        OnKeyPress = cxGrid1DBTableView1KeyPress
        NavigatorButtons.ConfirmDelete = False
        DataController.DataSource = REM_DMSprHardware.DataSourceTable
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
        OptionsSelection.HideFocusRectOnExit = False
        OptionsSelection.InvertSelect = False
        OptionsSelection.MultiSelect = True
        OptionsSelection.UnselectFocusedRecordOnExit = False
        OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
        OptionsView.CellAutoHeight = True
        OptionsView.ColumnAutoWidth = True
        OptionsView.Footer = True
        OptionsView.GroupByBox = False
        Styles.Header = DM.cxStyleHeaderTable
        object cxGrid1DBTableView1FL_NECOND_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1053#1077#1082#1086#1085#1076#1080#1094#1080#1103
          DataBinding.FieldName = 'FL_NECOND_REM_SHARDWARE'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 20
        end
        object cxGrid1DBTableView1CODE_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1050#1086#1076
          DataBinding.FieldName = 'CODE_REM_SHARDWARE'
          Width = 21
        end
        object cxGrid1DBTableView1ARTIKUL_REM_SHARDWARE: TcxGridDBColumn
          DataBinding.FieldName = 'ARTIKUL_REM_SHARDWARE'
          Width = 36
        end
        object cxGrid1DBTableView1NAME_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          DataBinding.FieldName = 'NAME_REM_SHARDWARE'
          Width = 111
        end
        object cxGrid1DBTableView1NAME_ENG_REM_SHARDWARE: TcxGridDBColumn
          DataBinding.FieldName = 'NAME_ENG_REM_SHARDWARE'
          Width = 90
        end
        object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088
          DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
          Width = 34
        end
        object cxGrid1DBTableView1ID_REM_SHARDWARE: TcxGridDBColumn
          DataBinding.FieldName = 'ID_REM_SHARDWARE'
          Visible = False
        end
        object cxGrid1DBTableView1SERNUM2_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
          DataBinding.FieldName = 'SERNUM2_REM_SHARDWARE'
          Width = 30
        end
        object cxGrid1DBTableView1PRICE_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1062#1077#1085#1072
          DataBinding.FieldName = 'PRICE_REM_SHARDWARE'
          Width = 33
        end
        object cxGrid1DBTableView1SROKWARRANTY_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1057#1088#1086#1082' '#1075#1072#1088#1072#1085#1090#1080#1080
          DataBinding.FieldName = 'SROKWARRANTY_REM_SHARDWARE'
          Width = 20
        end
        object cxGrid1DBTableView1FL_REMONT_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1041#1099#1083' '#1074' '#1088#1077#1084#1086#1085#1090#1077
          DataBinding.FieldName = 'FL_REMONT_REM_SHARDWARE'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 20
        end
        object cxGrid1DBTableView1FL_FICT_REMONT_REM_SHARDWARE: TcxGridDBColumn
          Caption = #1060#1080#1082#1090#1080#1074'. '#1088#1077#1084#1086#1085#1090
          DataBinding.FieldName = 'FL_FICT_REMONT_REM_SHARDWARE'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 20
        end
        object cxGrid1DBTableView1PARTNUM_REM_SHARDWARE: TcxGridDBColumn
          DataBinding.FieldName = 'PARTNUM_REM_SHARDWARE'
          Width = 25
        end
        object cxGrid1DBTableView1OUT_NAME_FIRM: TcxGridDBColumn
          DataBinding.FieldName = 'OUT_NAME_FIRM'
          Width = 37
        end
        object cxGrid1DBTableView1OUT_NAME_SKLAD: TcxGridDBColumn
          DataBinding.FieldName = 'OUT_NAME_SKLAD'
          Width = 39
        end
        object cxGrid1DBTableView1OUT_NAME_TYPE_NOM: TcxGridDBColumn
          DataBinding.FieldName = 'OUT_NAME_TYPE_NOM'
          Width = 39
        end
        object cxGrid1DBTableView1OUT_OST: TcxGridDBColumn
          DataBinding.FieldName = 'OUT_OST'
          Width = 39
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
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
    Left = 648
    Top = 8
  end
end
