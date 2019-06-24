object REM_FormaGurZ: TREM_FormaGurZ
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1103#1074#1086#1082' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
  ClientHeight = 415
  ClientWidth = 954
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
    Width = 954
    Height = 157
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 124
      Top = 134
      Width = 61
      Height = 16
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 134
      Width = 120
      Height = 16
      Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1103#1074#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 754
      Top = 141
      Width = 168
      Height = 16
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
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
      Width = 954
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
        OnClick = ToolButtonOpenGurAllDocClick
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
        OnClick = ToolButtonOpenCQueryClick
      end
      object ToolButtonOpenGurCQuery: TToolButton
        Left = 545
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1078#1091#1088#1085#1072#1083' '#1079#1072#1087#1088#1086#1089#1086#1074
        Caption = 'ToolButtonOpenGurCQuery'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGurCQueryClick
      end
      object ToolButtonOpenOnlySklad: TToolButton
        Left = 568
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1085#1072' '#1074#1099#1073#1088#1072#1085#1085#1086#1084' '#1089#1082#1083#1072#1076#1077
        Caption = 'ToolButtonOpenOnlySklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenOnlySkladClick
      end
      object ToolButtonOpenVPuti: TToolButton
        Left = 591
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1086#1090#1087#1088#1072#1074#1083#1077#1085#1085#1099#1077' ('#1074' '#1087#1091#1090#1080')'
        Caption = 'ToolButtonOpenVPuti'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenVPutiClick
      end
      object ToolButtonOpenAllSklad: TToolButton
        Left = 614
        Top = 0
        Hint = #1053#1072#1093#1086#1076#1103#1090#1089#1103' '#1085#1072' '#1074#1089#1077#1093' '#1089#1082#1083#1072#1076#1072#1093
        Caption = 'ToolButtonOpenAllSklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenAllSkladClick
      end
      object ToolButtonCopyInClipboard: TToolButton
        Left = 637
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088' '#1086#1073#1084#1077#1085#1072' '#1090#1077#1082#1089#1090' '#1080#1079' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonCopyInClipboard'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCopyInClipboardClick
      end
      object ToolButtonSaveUserSetup: TToolButton
        Left = 660
        Top = 0
        Hint = #1047#1072#1087#1080#1089#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1092#1086#1088#1084#1099
        Caption = 'ToolButtonSaveUserSetup'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSaveUserSetupClick
      end
      object ToolButtonOpenGarTalon: TToolButton
        Left = 683
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1086' '#1079#1072#1074#1086#1076#1089#1082#1086#1084#1091' '#1085#1086#1084#1077#1088#1091' 1'
        Caption = 'ToolButtonOpenGarTalon'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGarTalonClick
      end
      object ToolButtonSetNullInCustQuery: TToolButton
        Left = 706
        Top = 0
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100' ID '#1079#1072#1103#1074#1082#1080' '#1074' '#1079#1072#1087#1088#1086#1089#1077', '#1086#1090#1074#1103#1079#1072#1090#1100' '#1086#1090' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonSetNullInCustQuery'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetNullInCustQueryClick
      end
    end
    object cxLabel4: TcxLabel
      Left = 475
      Top = 33
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object ModelcxTextEdit: TcxTextEdit
      Left = 565
      Top = 32
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 2
      Text = 'ModelcxTextEdit'
      Width = 163
    end
    object SerNumcxTextEdit: TcxTextEdit
      Left = 137
      Top = 32
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 4
      Text = 'SerNumcxTextEdit'
      Width = 164
    end
    object cxLabel1: TcxLabel
      Left = 25
      Top = 33
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
    end
    object cxLabel2: TcxLabel
      Left = 17
      Top = 54
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088' 2:'
    end
    object SerNum2cxTextEdit: TcxTextEdit
      Left = 137
      Top = 53
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 7
      Text = 'SerNum2cxTextEdit'
      Width = 164
    end
    object NameHardwarecxButtonEdit: TcxButtonEdit
      Left = 475
      Top = 98
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameHardwarecxButtonEditPropertiesButtonClick
      TabOrder = 8
      Text = 'NameHardwarecxButtonEdit'
      Width = 253
    end
    object cxLabel5: TcxLabel
      Left = 475
      Top = 76
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
    end
    object cxLabel3: TcxLabel
      Left = 477
      Top = 54
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object KlientNamecxTextEdit: TcxTextEdit
      Left = 565
      Top = 53
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 11
      Text = 'KlientNamecxTextEdit'
      Width = 163
    end
    object cxButtonPoiskPoSerNum: TcxButton
      Left = 306
      Top = 28
      Width = 143
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091
      TabOrder = 12
      OnClick = cxButtonPoiskPoSerNumClick
    end
    object cxButtonPoiskPoSerNum2: TcxButton
      Left = 306
      Top = 53
      Width = 143
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091' 2'
      TabOrder = 13
      OnClick = cxButtonPoiskPoSerNum2Click
    end
    object cxButtonPoiskPoModel: TcxButton
      Left = 766
      Top = 28
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1084#1086#1076#1077#1083#1080
      TabOrder = 14
      OnClick = cxButtonPoiskPoModelClick
    end
    object cxButtonPoiskPoKlientu: TcxButton
      Left = 766
      Top = 53
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1080#1077#1085#1090#1091
      TabOrder = 15
      OnClick = cxButtonPoiskPoKlientuClick
    end
    object cxButtonPoiskPoHardware: TcxButton
      Left = 766
      Top = 98
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102
      TabOrder = 16
      OnClick = cxButtonPoiskPoHardwareClick
    end
    object NumGarDoccxTextEdit: TcxTextEdit
      Left = 137
      Top = 75
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 3
      Text = 'NumGarDoccxTextEdit'
      Width = 164
    end
    object cxLabel6: TcxLabel
      Left = 9
      Top = 76
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1086#1084#1077#1088' '#1075#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
    end
    object cxButtonPoNumGarDoc: TcxButton
      Left = 306
      Top = 78
      Width = 143
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1075#1072#1088'. '#1076#1086#1082'.'
      TabOrder = 18
      OnClick = cxButtonPoNumGarDocClick
    end
    object cxCheckBoxIspSprHardware: TcxCheckBox
      Left = 137
      Top = 99
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
      TabOrder = 19
      Width = 268
    end
    object cxLabelHint: TcxLabel
      Left = 141
      Top = 115
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'cxLabelHint'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -11
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object cxLabelSerNum1: TcxLabel
      Left = 477
      Top = 115
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'cxLabelSerNum1'
    end
    object cxLabelSerNum2: TcxLabel
      Left = 477
      Top = 128
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'cxLabelSerNum2'
    end
    object NameSkladcxButtonEdit: TcxButtonEdit
      Left = 766
      Top = 123
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
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
      Width = 176
    end
    object cxLabel7: TcxLabel
      Left = 714
      Top = 122
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1057#1082#1083#1072#1076':'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 157
    Width = 3
    Height = 201
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 358
    Width = 954
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 942
    Top = 157
    Width = 12
    Height = 201
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 3
    Top = 157
    Width = 939
    Height = 201
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
          Column = cxGrid1DBTableView1SUM_REM_Z
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
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_Z: TcxGridDBColumn
        Caption = #1043#1086#1090#1086#1074#1086' '#1082' '#1074#1099#1076#1072#1095#1077
        DataBinding.FieldName = 'GOTOVO_K_VIDACHE_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell
        Width = 23
      end
      object cxGrid1DBTableView1OUT_REM_Z: TcxGridDBColumn
        Caption = #1042#1099#1087'.'
        DataBinding.FieldName = 'OUT_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1OUT_REM_ZCustomDrawCell
        Width = 23
      end
      object cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z: TcxGridDBColumn
        Caption = #1059#1074#1077#1076#1086#1084#1083'.'
        DataBinding.FieldName = 'FL_KLIENT_UVEDOML_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell
        Width = 22
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
        Width = 23
      end
      object cxGrid1DBTableView1FL_POVTOR: TcxGridDBColumn
        Caption = #1055#1086#1074#1090#1086#1088
        DataBinding.FieldName = 'FL_POVTOR_REM_Z'
        OnCustomDrawCell = cxGrid1DBTableView1FL_POVTORCustomDrawCell
        Width = 24
      end
      object cxGrid1DBTableView1FL_ADDREPORT: TcxGridDBColumn
        Caption = #1054#1090#1095#1080#1090#1072#1085
        DataBinding.FieldName = 'FL_ADDREPORT_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 23
      end
      object cxGrid1DBTableView1FL_NADO_OTCH_REM_Z: TcxGridDBColumn
        Caption = #1053#1072#1076#1086' '#1086#1090#1095#1080#1090#1072#1090#1100
        DataBinding.FieldName = 'FL_NADO_OTCH_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 25
      end
      object cxGrid1DBTableView1FL_NE_OTCH_REM_Z: TcxGridDBColumn
        Caption = #1053#1077' '#1086#1090#1095#1080#1090#1099#1074#1072#1090#1100
        DataBinding.FieldName = 'FL_NE_OTCH_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 24
      end
      object cxGrid1DBTableView1NAME_SBRAND: TcxGridDBColumn
        Caption = #1041#1088#1077#1085#1076
        DataBinding.FieldName = 'NAME_SBRAND'
        Width = 39
      end
      object cxGrid1DBTableView1NAME_STREMONT: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'NAME_STREMONT'
        Width = 37
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1041#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Width = 41
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 39
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_Z: TcxGridDBColumn
        Caption = #1055#1088#1077#1092#1080#1082#1089
        DataBinding.FieldName = 'PREFIKS_NUM_REM_Z'
        Width = 40
      end
      object cxGrid1DBTableView1NUM_REM_Z: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'NUM_REM_Z'
        Width = 24
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z'
        Width = 48
      end
      object cxGrid1DBTableView1NAME_SKLAD_PR: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076' '#1087#1088'.'
        DataBinding.FieldName = 'NAME_SKLAD_PR'
        Options.ShowEditButtons = isebNever
        Width = 41
      end
      object cxGrid1DBTableView1NAME_SKLAD_OST: TcxGridDBColumn
        Caption = #1053#1072#1093#1086#1076#1080#1090#1089#1103
        DataBinding.FieldName = 'NAME_SKLAD_OST'
        Width = 42
      end
      object cxGrid1DBTableView1IDREC_RGOTPRZ: TcxGridDBColumn
        Caption = #1042' '#1087#1091#1090#1080
        DataBinding.FieldName = 'IDREC_RGOTPRZ'
        OnCustomDrawCell = cxGrid1DBTableView1IDREC_RGOTPRZCustomDrawCell
        Width = 23
      end
      object cxGrid1DBTableView1NAME_REM_SMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SMODEL'
        Width = 37
      end
      object cxGrid1DBTableView1MODEL_REM_Z: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_REM_Z'
        Width = 46
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 48
      end
      object cxGrid1DBTableView1SERNUM2_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        Width = 42
      end
      object cxGrid1DBTableView1NAME_REMSSOST: TcxGridDBColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'NAME_REMSSOST'
        Width = 42
      end
      object cxGrid1DBTableView1SUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_Z'
        Width = 43
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 49
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_Z: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        Width = 49
      end
      object cxGrid1DBTableView1NAMEDILER: TcxGridDBColumn
        Caption = #1044#1080#1083#1077#1088
        DataBinding.FieldName = 'NAMEDILER'
        Width = 42
      end
      object cxGrid1DBTableView1SOST_CQUERY: TcxGridDBColumn
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1079#1072#1082#1072#1079#1072
        DataBinding.FieldName = 'SOST_CQUERY'
        OnCustomDrawCell = cxGrid1DBTableView1SOST_CQUERYCustomDrawCell
        Width = 24
      end
      object cxGrid1DBTableView1ID_REM_CQUERY: TcxGridDBColumn
        Caption = #1045#1089#1090#1100' '#1079#1072#1087#1088#1086#1089
        DataBinding.FieldName = 'ID_REM_CQUERY'
        OnCustomDrawCell = cxGrid1DBTableView1ID_REM_CQUERYCustomDrawCell
        Width = 25
      end
      object cxGrid1DBTableView1IDDOC_VIDACHA_HW: TcxGridDBColumn
        Caption = #1042#1099#1076#1072#1085#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'IDDOC_VIDACHA_HW'
        OnCustomDrawCell = cxGrid1DBTableView1IDDOC_VIDACHA_HWCustomDrawCell
        Width = 20
      end
      object cxGrid1DBTableView1IDDOC_VOSVRAT_HW: TcxGridDBColumn
        Caption = #1042#1086#1079#1074#1088#1072#1097#1077#1085#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'IDDOC_VOSVRAT_HW'
        OnCustomDrawCell = cxGrid1DBTableView1IDDOC_VOSVRAT_HWCustomDrawCell
        Width = 22
      end
      object cxGrid1DBTableView1SROK_REMONTA: TcxGridDBColumn
        Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072
        DataBinding.FieldName = 'SROK_REMONTA'
        Width = 23
      end
      object cxGrid1DBTableView1SROK_REMONTA_NOW: TcxGridDBColumn
        Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072' '#1090#1077#1082'.'
        DataBinding.FieldName = 'SROK_REMONTA_NOW'
        Width = 22
      end
      object cxGrid1DBTableView1FL_FICTIV_REM_Z: TcxGridDBColumn
        Caption = #1060#1080#1082#1090#1080#1074'.'
        DataBinding.FieldName = 'FL_FICTIV_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 23
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
    object PMCreateDocVidachaHW: TMenuItem
      Caption = #1042#1099#1076#1072#1095#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnClick = PMCreateDocVidachaHWClick
    end
    object PMCreateDocVosvratHW: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnClick = PMCreateDocVosvratHWClick
    end
  end
end
