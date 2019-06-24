object REM_FormaGurZDop: TREM_FormaGurZDop
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1103#1074#1086#1082' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
  ClientHeight = 511
  ClientWidth = 1174
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
    Width = 1174
    Height = 201
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 167
      Top = 39
      Width = 71
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 14
      Top = 39
      Width = 132
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1103#1074#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 736
      Top = 33
      Width = 192
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
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
      Width = 1174
      Height = 26
      ButtonHeight = 23
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
      object ToolButtonAddNewZ: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonAddNewZ'
        ImageIndex = 0
        OnClick = ToolButtonAddNewZClick
      end
      object ToolButtonOpenDoc: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonOpenDoc'
        ImageIndex = 1
        OnClick = ToolButtonOpenDocClick
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButton3: TToolButton
        Left = 77
        Top = 0
        Hint = #1048#1089#1090#1086#1088#1080#1103' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1089#1086#1089#1090#1086#1103#1085#1080#1103' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButton3'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonParamOtbor: TToolButton
        Left = 100
        Top = 0
        Hint = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072
        ImageIndex = 33
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOtbor: TToolButton
        Left = 123
        Top = 0
        Hint = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1086#1090#1073#1086#1088#1086#1084
        Caption = 'ToolButtonOtbor'
        ImageIndex = 30
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
      end
      object ToolButtonRefresh: TToolButton
        Left = 146
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButton2: TToolButton
        Left = 169
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonDelete: TToolButton
        Left = 251
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 274
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 338
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 361
        Top = 0
        Caption = 'ToolButton5'
        DropdownMenu = PopupMenuCreateNewDocRemont
        ImageIndex = 0
      end
    end
    object SerNumcxTextEdit: TcxTextEdit
      Left = 183
      Top = 122
      TabOrder = 1
      Text = 'SerNumcxTextEdit'
      Width = 201
    end
    object cxLabel1: TcxLabel
      Left = 45
      Top = 128
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
    end
    object cxButtonPoiskPoSerNum: TcxButton
      Left = 751
      Top = 60
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091
      TabOrder = 3
      OnClick = cxButtonPoiskPoSerNumClick
    end
    object SerNum2cxTextEdit: TcxTextEdit
      Left = 183
      Top = 158
      TabOrder = 4
      Text = 'SerNum2cxTextEdit'
      Width = 201
    end
    object KlientNamecxTextEdit: TcxTextEdit
      Left = 495
      Top = 89
      TabOrder = 5
      Text = 'KlientNamecxTextEdit'
      Width = 201
    end
    object ModelcxTextEdit: TcxTextEdit
      Left = 183
      Top = 89
      TabOrder = 6
      Text = 'ModelcxTextEdit'
      Width = 201
    end
    object cxLabel2: TcxLabel
      Left = 45
      Top = 159
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088' 2:'
    end
    object cxLabel3: TcxLabel
      Left = 423
      Top = 90
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object cxLabel4: TcxLabel
      Left = 100
      Top = 90
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object cxButtonPoiskPoSerNum2: TcxButton
      Left = 751
      Top = 91
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091' 2'
      TabOrder = 10
      OnClick = cxButtonPoiskPoSerNum2Click
    end
    object cxButtonPoiskPoModel: TcxButton
      Left = 751
      Top = 122
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1084#1086#1076#1077#1083#1080
      TabOrder = 11
      OnClick = cxButtonPoiskPoModelClick
    end
    object cxButtonPoiskPoKlientu: TcxButton
      Left = 751
      Top = 153
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1080#1077#1085#1090#1091
      TabOrder = 12
      OnClick = cxButtonPoiskPoKlientuClick
    end
    object NameHardwarecxButtonEdit: TcxButtonEdit
      Left = 423
      Top = 153
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      TabOrder = 13
      Text = 'NameHardwarecxButtonEdit'
      Width = 282
    end
    object cxLabel5: TcxLabel
      Left = 423
      Top = 127
      Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
    end
    object cxButtonPoiskPoHardware: TcxButton
      Left = 959
      Top = 60
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102
      TabOrder = 15
      OnClick = cxButtonPoiskPoHardwareClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 201
    Width = 4
    Height = 240
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 441
    Width = 1174
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 1159
    Top = 201
    Width = 15
    Height = 240
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 4
    Top = 201
    Width = 1155
    Height = 240
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    LevelTabs.Style = 8
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMGurZ.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <
        item
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          FieldName = 'SUM_REM_Z'
          DisplayText = #1057#1091#1084#1084#1072
        end>
      DataController.Summary.SummaryGroups = <
        item
          Links = <
            item
              Column = cxGrid1DBTableView1SUM_REM_Z
            end>
          SummaryItems = <
            item
            end>
        end>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ShowEditButtons = gsebForFocusedRecord
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1OUT_REM_Z: TcxGridDBColumn
        Caption = #1042#1099#1087'.'
        DataBinding.FieldName = 'OUT_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1OUT_REM_ZCustomDrawCell
        Width = 28
      end
      object cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z: TcxGridDBColumn
        Caption = #1059#1074#1077#1076#1086#1084#1083'.'
        DataBinding.FieldName = 'FL_KLIENT_UVEDOML_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell
        Width = 26
      end
      object cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z: TcxGridDBColumn
        Caption = #1050#1086#1085#1089#1091#1083#1100#1090'.'
        DataBinding.FieldName = 'FL_TREB_KONS_KL_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1FL_TREB_KONS_KL_REM_ZCustomDrawCell
        Width = 23
      end
      object cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z: TcxGridDBColumn
        Caption = #1054#1090#1074#1077#1090
        DataBinding.FieldName = 'FL_KL_OTV_NA_ZAPROS_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_ZCustomDrawCell
        Width = 27
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 63
      end
      object cxGrid1DBTableView1NUM_REM_Z: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'NUM_REM_Z'
        Width = 46
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z'
        Width = 79
      end
      object cxGrid1DBTableView1NAME_SKLAD_PR: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076' '#1087#1088'.'
        DataBinding.FieldName = 'NAME_SKLAD_PR'
        Options.ShowEditButtons = isebNever
        Width = 80
      end
      object cxGrid1DBTableView1NAME_REM_SMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SMODEL'
        Width = 82
      end
      object cxGrid1DBTableView1MODEL_REM_Z: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_REM_Z'
        Width = 85
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 129
      end
      object cxGrid1DBTableView1SERNUM2_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        Width = 69
      end
      object cxGrid1DBTableView1NAME_REMSSOST: TcxGridDBColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'NAME_REMSSOST'
        Width = 117
      end
      object cxGrid1DBTableView1SUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_Z'
        Width = 49
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 116
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_Z: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        Width = 122
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 440
    Top = 32
  end
  object PopupMenuCreateNewDocRemont: TPopupMenu
    Left = 576
    Top = 32
    object PMCreateDocZPost: TMenuItem
      Caption = #1055#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077
      OnClick = PMCreateDocZPostClick
    end
    object PMCreateDocZVid: TMenuItem
      Caption = #1042#1099#1076#1072#1095#1072
      OnClick = PMCreateDocZVidClick
    end
    object PMCreateDocZPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      OnClick = PMCreateDocZPerClick
    end
    object PMCreateDocZStart: TMenuItem
      Caption = #1053#1072#1095#1072#1083#1086' '#1088#1077#1084#1086#1085#1090#1072
      OnClick = PMCreateDocZStartClick
    end
    object PMCreateDocZEnd: TMenuItem
      Caption = #1050#1086#1085#1077#1094' '#1088#1077#1084#1086#1085#1090#1072
      OnClick = PMCreateDocZEndClick
    end
    object PMCreateDocZOper: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103
      OnClick = PMCreateDocZOperClick
    end
    object PMCreateDocZTreb: TMenuItem
      Caption = #1058#1088#1077#1073#1086#1074#1072#1085#1080#1077
      OnClick = PMCreateDocZTrebClick
    end
    object PMCreateDocZAktPr: TMenuItem
      Caption = #1040#1082#1090' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
      OnClick = PMCreateDocZAktPrClick
    end
    object PMCreateDocZVosvrZap: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1079#1072#1087#1095#1072#1089#1090#1077#1081
      OnClick = PMCreateDocZVosvrZapClick
    end
  end
end
