object REM_FormaGurZPredv: TREM_FormaGurZPredv
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1103#1074#1086#1082' ('#1087#1088#1077#1076#1074'.) '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
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
    Height = 193
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 152
      Top = 165
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
      Left = 12
      Top = 165
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
      Left = 943
      Top = 173
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
      object ToolButtonOpenNew: TToolButton
        Left = 169
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1078#1091#1088#1085#1072#1083' '#1073#1077#1079' '#1087#1086#1080#1089#1082#1072' '#1080' '#1092#1080#1083#1100#1090#1088#1086#1074
        Caption = 'ToolButtonOpenNew'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenNewClick
      end
      object ToolButton2: TToolButton
        Left = 192
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonDelete: TToolButton
        Left = 274
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton4: TToolButton
        Left = 297
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 361
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 384
        Top = 0
        Caption = 'ToolButton5'
        DropdownMenu = PopupMenuCreateNewDocRemont
        ImageIndex = 0
      end
      object ToolButtonOpenGurAllDoc: TToolButton
        Left = 407
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1099' '#1087#1086' '#1079#1072#1103#1074#1082#1077
        Caption = 'ToolButtonOpenGurAllDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCopyZayavka: TToolButton
        Left = 430
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonCopyZayavka'
        ImageIndex = 52
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCopyZayavkaClick
      end
      object ToolButtonCreateNewNaOsnDanForm: TToolButton
        Left = 453
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1076#1072#1085#1085#1099#1093' '#1092#1086#1088#1084#1099
        Caption = 'ToolButtonCreateNewNaOsnDanForm'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateNewNaOsnDanFormClick
      end
      object ToolButtonCreateNaOsnSprHardware: TToolButton
        Left = 476
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
        Caption = 'ToolButtonCreateNaOsnSprHardware'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateNaOsnSprHardwareClick
      end
      object ToolButtonZapShapkuNaOsnZayavki: TToolButton
        Left = 499
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1096#1072#1087#1082#1091' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1090#1077#1082#1091#1097#1077#1081' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonZapShapkuNaOsnZayavki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonZapShapkuNaOsnZayavkiClick
      end
      object ToolButtonOpenCQuery: TToolButton
        Left = 522
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1079#1072#1087#1088#1086#1089' '#1079#1072#1087#1095#1072#1089#1090#1077#1081
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenGurCQuery: TToolButton
        Left = 545
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1078#1091#1088#1085#1072#1083' '#1079#1072#1087#1088#1086#1089#1086#1074
        Caption = 'ToolButtonOpenGurCQuery'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenOnlySklad: TToolButton
        Left = 568
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1085#1072' '#1074#1099#1073#1088#1072#1085#1085#1086#1084' '#1089#1082#1083#1072#1076#1077
        Caption = 'ToolButtonOpenOnlySklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenVPuti: TToolButton
        Left = 591
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1086#1090#1087#1088#1072#1074#1083#1077#1085#1085#1099#1077' ('#1074' '#1087#1091#1090#1080')'
        Caption = 'ToolButtonOpenVPuti'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenAllSklad: TToolButton
        Left = 614
        Top = 0
        Hint = #1053#1072#1093#1086#1076#1103#1090#1089#1103' '#1085#1072' '#1074#1089#1077#1093' '#1089#1082#1083#1072#1076#1072#1093
        Caption = 'ToolButtonOpenAllSklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
    end
    object cxLabel4: TcxLabel
      Left = 584
      Top = 40
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object ModelcxTextEdit: TcxTextEdit
      Left = 695
      Top = 39
      TabOrder = 2
      Text = 'ModelcxTextEdit'
      Width = 201
    end
    object SerNumcxTextEdit: TcxTextEdit
      Left = 169
      Top = 39
      TabOrder = 4
      Text = 'SerNumcxTextEdit'
      Width = 201
    end
    object cxLabel1: TcxLabel
      Left = 31
      Top = 40
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
    end
    object cxLabel2: TcxLabel
      Left = 21
      Top = 66
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088' 2:'
    end
    object SerNum2cxTextEdit: TcxTextEdit
      Left = 169
      Top = 65
      TabOrder = 7
      Text = 'SerNum2cxTextEdit'
      Width = 201
    end
    object NameHardwarecxButtonEdit: TcxButtonEdit
      Left = 584
      Top = 120
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameHardwarecxButtonEditPropertiesButtonClick
      TabOrder = 8
      Text = 'NameHardwarecxButtonEdit'
      Width = 312
    end
    object cxLabel5: TcxLabel
      Left = 584
      Top = 94
      Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
    end
    object cxLabel3: TcxLabel
      Left = 587
      Top = 66
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object KlientNamecxTextEdit: TcxTextEdit
      Left = 695
      Top = 65
      TabOrder = 11
      Text = 'KlientNamecxTextEdit'
      Width = 201
    end
    object cxButtonPoiskPoSerNum: TcxButton
      Left = 376
      Top = 34
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091
      TabOrder = 12
      OnClick = cxButtonPoiskPoSerNumClick
    end
    object cxButtonPoiskPoSerNum2: TcxButton
      Left = 376
      Top = 65
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091' 2'
      TabOrder = 13
      OnClick = cxButtonPoiskPoSerNum2Click
    end
    object cxButtonPoiskPoModel: TcxButton
      Left = 943
      Top = 34
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1084#1086#1076#1077#1083#1080
      TabOrder = 14
      OnClick = cxButtonPoiskPoModelClick
    end
    object cxButtonPoiskPoKlientu: TcxButton
      Left = 943
      Top = 65
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1080#1077#1085#1090#1091
      TabOrder = 15
      OnClick = cxButtonPoiskPoKlientuClick
    end
    object cxButtonPoiskPoHardware: TcxButton
      Left = 943
      Top = 120
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102
      TabOrder = 16
      OnClick = cxButtonPoiskPoHardwareClick
    end
    object NumGarDoccxTextEdit: TcxTextEdit
      Left = 169
      Top = 92
      TabOrder = 3
      Text = 'NumGarDoccxTextEdit'
      Width = 201
    end
    object cxLabel6: TcxLabel
      Left = 11
      Top = 93
      Caption = #1053#1086#1084#1077#1088' '#1075#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
    end
    object cxButtonPoNumGarDoc: TcxButton
      Left = 376
      Top = 96
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1075#1072#1088'. '#1076#1086#1082'.'
      TabOrder = 18
      OnClick = cxButtonPoNumGarDocClick
    end
    object cxCheckBoxIspSprHardware: TcxCheckBox
      Left = 169
      Top = 122
      Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
      TabOrder = 19
      Width = 330
    end
    object cxLabelHint: TcxLabel
      Left = 173
      Top = 142
      Caption = 'cxLabelHint'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -13
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object cxLabelSerNum1: TcxLabel
      Left = 587
      Top = 142
      Caption = 'cxLabelSerNum1'
    end
    object cxLabelSerNum2: TcxLabel
      Left = 587
      Top = 157
      Caption = 'cxLabelSerNum2'
    end
    object NameSkladcxButtonEdit: TcxButtonEdit
      Left = 943
      Top = 151
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladcxButtonEditPropertiesButtonClick
      TabOrder = 23
      Text = 'NameSkladcxButtonEdit'
      Width = 216
    end
    object cxLabel7: TcxLabel
      Left = 879
      Top = 150
      Caption = #1057#1082#1083#1072#1076':'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 193
    Width = 4
    Height = 248
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
    Top = 193
    Width = 15
    Height = 248
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
    Top = 193
    Width = 1155
    Height = 248
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
          Kind = skCount
          FieldName = 'ID_REM_Z'
          Column = cxGrid1DBTableView1KLIENT_NAME_REM_Z
        end
        item
          Kind = skSum
          FieldName = 'SUM_REM_Z'
          Column = cxGrid1DBTableView1SUMNACHA_REM_Z2
        end>
      DataController.Summary.SummaryGroups = <
        item
          Links = <
            item
              Column = cxGrid1DBTableView1SUMNACHA_REM_Z2
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
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PREFIKS_NUM_REM_Z2: TcxGridDBColumn
        Caption = #1055#1088#1077#1092#1080#1082#1089
        DataBinding.FieldName = 'PREFIKS_NUM_REM_Z2'
        Width = 28
      end
      object cxGrid1DBTableView1POS_REM_Z2: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z2'
        Width = 112
      end
      object cxGrid1DBTableView1NUM_REM_Z2: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'OPER_REM_Z2'
        Width = 35
      end
      object cxGrid1DBTableView1NAME_SBRAND: TcxGridDBColumn
        Caption = #1041#1088#1077#1085#1076
        DataBinding.FieldName = 'NAME_SBRAND'
        Width = 67
      end
      object cxGrid1DBTableView1NAME_SKLAD_PR: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076' '#1087#1088'.'
        DataBinding.FieldName = 'NAME_SKLAD_PR'
        Options.ShowEditButtons = isebNever
        Width = 158
      end
      object cxGrid1DBTableView1NAME_REM_SMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SMODEL'
        Width = 73
      end
      object cxGrid1DBTableView1MODEL_STR_REM_Z2: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_STR_REM_Z2'
        Width = 96
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 96
      end
      object cxGrid1DBTableView1SERNUM1_REM_Z2: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM1_REM_Z2'
        Width = 86
      end
      object cxGrid1DBTableView1SUMNACHA_REM_Z2: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMNACHA_REM_Z2'
        Width = 49
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 110
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_Z: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        Width = 110
      end
      object cxGrid1DBTableView1RESULT_REM_Z2: TcxGridDBColumn
        DataBinding.FieldName = 'RESULT_REM_Z2'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemRESULT_REM_Z2
        Width = 64
      end
      object cxGrid1DBTableView1PRICHINA_LIST_REM_Z2: TcxGridDBColumn
        DataBinding.FieldName = 'PRICHINA_LIST_REM_Z2'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemPRICHINA_LIST_REM_Z2
        Width = 57
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Left = 16
    Top = 72
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 8
    Top = 32
  end
  object PopupMenuCreateNewDocRemont: TPopupMenu
    Left = 64
    Top = 128
    object PMCreateDocZPost: TMenuItem
      Caption = #1055#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077
    end
    object PMCreateDocZVid: TMenuItem
      Caption = #1042#1099#1076#1072#1095#1072
    end
    object PMCreateDocZPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
    end
    object PMCreateDocZStart: TMenuItem
      Caption = #1053#1072#1095#1072#1083#1086' '#1088#1077#1084#1086#1085#1090#1072
    end
    object PMCreateDocZEnd: TMenuItem
      Caption = #1050#1086#1085#1077#1094' '#1088#1077#1084#1086#1085#1090#1072
    end
    object PMCreateDocZOper: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103
    end
    object PMCreateDocZTreb: TMenuItem
      Caption = #1058#1088#1077#1073#1086#1074#1072#1085#1080#1077
    end
    object PMCreateDocZAktPr: TMenuItem
      Caption = #1040#1082#1090' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
    end
    object PMCreateDocZVosvrZap: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1079#1072#1087#1095#1072#1089#1090#1077#1081
    end
    object PMCreateDocVidachaHW: TMenuItem
      Caption = #1042#1099#1076#1072#1095#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
    end
    object PMCreateDocVosvratHW: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
    end
  end
end
