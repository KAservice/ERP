object REM_FormaGurCustQueryDetal: TREM_FormaGurCustQueryDetal
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1087#1088#1086#1089#1086#1074' '#1047#1072#1082#1072#1079#1095#1080#1082#1086#1074':'
  ClientHeight = 415
  ClientWidth = 856
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
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 856
    Height = 157
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 136
      Top = 32
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
      Left = 8
      Top = 32
      Width = 139
      Height = 16
      Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1087#1088#1086#1089#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 676
      Top = 137
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
    object Label27: TLabel
      Left = 8
      Top = 119
      Width = 56
      Height = 13
      Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 856
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
      object ToolButtonOpenTrebZakaz: TToolButton
        Left = 361
        Top = 0
        Hint = #1058#1088#1077#1073#1091#1077#1090#1089#1103' '#1079#1072#1082#1072#1079#1072#1090#1100' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
        Caption = 'ToolButtonOpenTrebZakaz'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenTrebZakazClick
      end
      object ToolButtonOpenPoNumberZakaz: TToolButton
        Left = 384
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1079#1072#1082#1072#1079#1072
        Caption = 'ToolButtonOpenPoNumberZakaz'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenPoNumberZakazClick
      end
      object ToolButtonSetNumberDateZakaza: TToolButton
        Left = 407
        Top = 0
        Hint = #1055#1088#1086#1089#1090#1072#1074#1080#1090#1100' '#1085#1086#1084#1077#1088' '#1080' '#1076#1072#1090#1091' '#1079#1072#1082#1072#1079#1072
        Caption = 'ToolButtonSetNumberDateZakaza'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetNumberDateZakazaClick
      end
      object ToolButtonSetPredvZakazano: TToolButton
        Left = 430
        Top = 0
        Hint = #1055#1088#1086#1089#1090#1072#1074#1080#1090#1100' '#1087#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1086' '#1079#1072#1082#1072#1079#1072#1085#1086
        Caption = 'ToolButtonSetPredvZakazano'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetPredvZakazanoClick
      end
      object ToolButtonSetVipolneno: TToolButton
        Left = 453
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074#1099#1087#1086#1083#1085#1077#1085#1086
        Caption = 'ToolButtonSetVipolneno'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetVipolnenoClick
      end
      object ToolButtonSetOtpravleno: TToolButton
        Left = 476
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1086#1090#1087#1088#1072#1074#1083#1077#1085#1086' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1086#1084
        Caption = 'ToolButtonSetOtpravleno'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetOtpravlenoClick
      end
      object ToolButton5: TToolButton
        Left = 499
        Top = 0
        Width = 35
        Caption = 'ToolButton5'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonOpenGurAllDocPoZ: TToolButton
        Left = 534
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1078#1091#1088#1085#1072#1083' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1087#1086' '#1079#1072#1103#1074#1082#1077
        Caption = 'ToolButtonOpenGurAllDocPoZ'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGurAllDocPoZClick
      end
      object ToolButtonOpenZ: TToolButton
        Left = 557
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonOpenZ'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenZClick
      end
    end
    object ModelcxTextEdit: TcxTextEdit
      Left = 501
      Top = 61
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 1
      Text = 'ModelcxTextEdit'
      Width = 195
    end
    object cxLabel4: TcxLabel
      Left = 444
      Top = 58
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object cxLabel3: TcxLabel
      Left = 443
      Top = 33
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object cxButtonPoiskPoModel: TcxButton
      Left = 700
      Top = 56
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1084#1086#1076#1077#1083#1080
      TabOrder = 4
      OnClick = cxButtonPoiskPoModelClick
    end
    object cxButtonPoiskPoKlientu: TcxButton
      Left = 700
      Top = 31
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1080#1077#1085#1090#1091
      TabOrder = 5
      OnClick = cxButtonPoiskPoKlientuClick
    end
    object KlientNamecxTextEdit: TcxTextEdit
      Left = 501
      Top = 31
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 6
      Text = 'KlientNamecxTextEdit'
      Width = 195
    end
    object NameZayavkacxButtonEdit: TcxButtonEdit
      Left = 149
      Top = 88
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
      Properties.OnButtonClick = NameZayavkacxButtonEditPropertiesButtonClick
      TabOrder = 7
      Text = 'NameZayavkacxButtonEdit'
      Width = 222
    end
    object cxLabel2: TcxLabel
      Left = 31
      Top = 89
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
    end
    object NameKlientcxLabel: TcxLabel
      Left = 518
      Top = 98
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'NameKlientcxLabel'
    end
    object NameModelcxLabel: TcxLabel
      Left = 518
      Top = 85
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'NameModelcxLabel'
    end
    object SerNumcxLabel: TcxLabel
      Left = 400
      Top = 85
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'SerNumcxLabel'
    end
    object SerNum2cxLabel: TcxLabel
      Left = 400
      Top = 100
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'SerNum2cxLabel'
    end
    object cxButtonOtborPoZayavka: TcxButton
      Left = 700
      Top = 88
      Width = 144
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1055#1086' '#1079#1072#1103#1074#1082#1077
      TabOrder = 13
      OnClick = cxButtonOtborPoZayavkaClick
    end
    object cxLabel1: TcxLabel
      Left = 267
      Top = 132
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1086#1084#1077#1088' '#1079#1072#1082#1072#1079#1072':'
    end
    object cxLabel5: TcxLabel
      Left = 462
      Top = 132
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072':'
    end
    object NameProducercxButtonEdit: TcxButtonEdit
      Left = 8
      Top = 132
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
      Properties.OnButtonClick = NameProducercxButtonEditPropertiesButtonClick
      TabOrder = 16
      Text = 'NameProducercxButtonEdit'
      Width = 249
    end
    object NumberZakazcxSpinEdit: TcxSpinEdit
      Left = 353
      Top = 132
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 17
      Width = 98
    end
    object DateZakazcxDateEdit: TcxDateEdit
      Left = 540
      Top = 132
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      TabOrder = 18
      Width = 98
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
    Width = 856
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 844
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
    Width = 841
    Height = 201
    Align = alClient
    TabOrder = 4
    LevelTabs.Style = 8
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMGurCustQuery.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <
        item
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skCount
          FieldName = 'ID_REM_CQUERY'
          Column = cxGrid1DBTableView1NAMEKLIENT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1PRNOM_SUM_STR
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1NOM_SUM_STR
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1KOL_REM_CQUERYT
        end>
      DataController.Summary.SummaryGroups = <
        item
          Links = <
            item
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
      OptionsSelection.InvertSelect = False
      OptionsView.ShowEditButtons = gsebForFocusedRecord
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1TYPE_REM_CQUERY: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TYPE_REM_CQUERY'
        Width = 29
      end
      object cxGrid1DBTableView1RUN_REM_CQUERY: TcxGridDBColumn
        Caption = #1042#1099#1087'.'
        DataBinding.FieldName = 'RUN_REM_CQUERY'
        OnCustomDrawCell = cxGrid1DBTableView1RUN_REM_CQUERYCustomDrawCell
        Width = 22
      end
      object cxGrid1DBTableView1ID_REM_CQUERY: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_CQUERY'
        Visible = False
      end
      object cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERY: TcxGridDBColumn
        Caption = #1059#1074#1077#1076#1086#1084#1083'.'
        DataBinding.FieldName = 'FL_KLIENT_UVEDOML_REM_CQUERY'
        OnCustomDrawCell = cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERYCustomDrawCell
        Width = 24
      end
      object cxGrid1DBTableView1NAME_SBRAND: TcxGridDBColumn
        Caption = #1041#1088#1077#1085#1076
        DataBinding.FieldName = 'NAME_SBRAND'
        Width = 30
      end
      object cxGrid1DBTableView1NAME_SPRODUCER: TcxGridDBColumn
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
        DataBinding.FieldName = 'NAME_SPRODUCER'
        Width = 29
      end
      object cxGrid1DBTableView1POS_REM_CQUERY: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_CQUERY'
        Width = 38
      end
      object cxGrid1DBTableView1NUM_REM_CQUERY: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_CQUERY'
        Width = 23
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 50
      end
      object cxGrid1DBTableView1NAME_REM_SMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SMODEL'
        Width = 38
      end
      object cxGrid1DBTableView1NUM_ZAKAZA_REM_CQUERY: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088' '#1079#1072#1082#1072#1079#1072
        DataBinding.FieldName = 'NUM_ZAKAZA_REM_CQUERY'
        Width = 24
      end
      object cxGrid1DBTableView1DATE_ZAKAZA_REM_CQUERY: TcxGridDBColumn
        Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072
        DataBinding.FieldName = 'DATE_ZAKAZA_REM_CQUERY'
        Width = 35
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Visible = False
        Width = 30
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1047#1048#1055
        DataBinding.FieldName = 'NAMENOM'
        Styles.Content = DM.cxStyleSmallFont
        Width = 101
      end
      object cxGrid1DBTableView1KOL_REM_CQUERYT: TcxGridDBColumn
        DataBinding.FieldName = 'KOL_REM_CQUERYT'
        Width = 20
      end
      object cxGrid1DBTableView1KF_REM_CQUERYT: TcxGridDBColumn
        DataBinding.FieldName = 'KF_REM_CQUERYT'
        Width = 21
      end
      object cxGrid1DBTableView1PRICE_REM_CQUERYT: TcxGridDBColumn
        DataBinding.FieldName = 'PRICE_REM_CQUERYT'
        Width = 22
      end
      object cxGrid1DBTableView1NOM_SUM_STR: TcxGridDBColumn
        DataBinding.FieldName = 'NOM_SUM_STR'
        Width = 21
      end
      object cxGrid1DBTableView1PRICE_ZAKUP_SPRNOM: TcxGridDBColumn
        DataBinding.FieldName = 'PRICE_ZAKUP_SPRNOM'
        Width = 21
      end
      object cxGrid1DBTableView1PRNOM_SUM_STR: TcxGridDBColumn
        DataBinding.FieldName = 'PRNOM_SUM_STR'
        Width = 22
      end
      object cxGrid1DBTableView1FL_DOSTUPNO_SPRNOM: TcxGridDBColumn
        DataBinding.FieldName = 'FL_DOSTUPNO_SPRNOM'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 22
      end
      object cxGrid1DBTableView1PRODAVEC_NAME: TcxGridDBColumn
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094
        DataBinding.FieldName = 'PRODAVEC_NAME'
        Width = 44
      end
      object cxGrid1DBTableView1NUM_STR_ZAK_POST_REM_CQUERY: TcxGridDBColumn
        DataBinding.FieldName = 'NUM_STR_ZAK_POST_REM_CQUERY'
        Width = 45
      end
      object cxGrid1DBTableView1NUM_STR_ZAK_SPROV_REM_CQUERY: TcxGridDBColumn
        Caption = #1047#1072#1082#1072#1079' '#1089#1077#1088#1074#1080#1089' '#1087#1088#1086#1074#1072#1081#1076#1077#1088#1091
        DataBinding.FieldName = 'NUM_STR_ZAK_SPROV_REM_CQUERY'
        Width = 44
      end
      object cxGrid1DBTableView1NUMDOCTK_REM_CQUERY: TcxGridDBColumn
        Caption = #1058#1088#1077#1082' '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMDOCTK_REM_CQUERY'
        Width = 61
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
    Top = 24
  end
end
