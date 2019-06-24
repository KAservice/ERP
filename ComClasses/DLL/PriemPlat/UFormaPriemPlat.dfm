object FormaPriemPlat: TFormaPriemPlat
  Left = 192
  Top = 201
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  Caption = #1055#1088#1080#1077#1084' '#1087#1083#1072#1090#1077#1078#1077#1081' '#1079#1072' '#1091#1089#1083#1091#1075#1080' '#1089#1074#1103#1079#1080
  ClientHeight = 573
  ClientWidth = 889
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 889
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object NameKKMLabel: TLabel
      Left = 566
      Top = 11
      Width = 150
      Height = 24
      Alignment = taRightJustify
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object UchLabel: TLabel
      Left = 756
      Top = 11
      Width = 89
      Height = 24
      Caption = 'UchLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 477
    Width = 889
    Height = 96
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelZaprosProverkaRekvisitov: TLabel
      Left = 16
      Top = 6
      Width = 152
      Height = 13
      Caption = 'LabelZaprosProverkaRekvisitov'
    end
    object LabelCatalogCiberplat: TLabel
      Left = 16
      Top = 78
      Width = 103
      Height = 13
      Caption = 'LabelCatalogCiberplat'
    end
    object cxButton1: TcxButton
      Left = 163
      Top = 40
      Width = 130
      Height = 33
      Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1088#1077#1082#1074#1080#1079#1080#1090#1086#1074
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 299
      Top = 40
      Width = 130
      Height = 33
      Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1086#1090#1074#1077#1090
      TabOrder = 1
    end
    object cxButton3: TcxButton
      Left = 435
      Top = 40
      Width = 130
      Height = 33
      Caption = #1047#1072#1087#1088#1086#1089' '#1085#1072' '#1087#1083#1072#1090#1077#1078
      TabOrder = 2
    end
    object cxButton4: TcxButton
      Left = 571
      Top = 40
      Width = 130
      Height = 33
      Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1086#1090#1074#1077#1090
      TabOrder = 3
    end
    object ButtonClose: TcxButton
      Left = 770
      Top = 35
      Width = 75
      Height = 38
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 41
    Width = 257
    Height = 436
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    object cxGrid1: TcxGrid
      Left = 0
      Top = 0
      Width = 257
      Height = 436
      Align = alClient
      TabOrder = 0
      object cxGrid1DBTableViewOperators: TcxGridDBTableView
        NavigatorButtons.ConfirmDelete = False
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        object cxGrid1DBTableViewOperatorsCODOPER_CODETEL: TcxGridDBColumn
          Caption = #1050#1086#1076
          DataBinding.FieldName = 'CODOPER_CODETEL'
          Width = 37
        end
        object cxGrid1DBTableViewOperatorsNAME_CODETEL: TcxGridDBColumn
          Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
          DataBinding.FieldName = 'NAME_CODETEL'
          Width = 185
        end
        object cxGrid1DBTableViewOperatorsPRCOMIS_SCODETEL: TcxGridDBColumn
          Caption = #1050#1086#1084#1080#1089#1089#1080#1103
          DataBinding.FieldName = 'PRCOMIS_SCODETEL'
          Width = 33
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableViewOperators
      end
    end
  end
  object Panel5: TPanel
    Left = 257
    Top = 41
    Width = 19
    Height = 436
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 276
    Top = 41
    Width = 613
    Height = 436
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object cxGrid2: TcxGrid
      Left = 0
      Top = 0
      Width = 613
      Height = 75
      Align = alClient
      TabOrder = 0
      object cxGrid2TableView1: TcxGridTableView
        NavigatorButtons.ConfirmDelete = False
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <
          item
            Kind = skSum
            Column = cxGrid2TableView1Column2
          end
          item
            Kind = skSum
            Column = cxGrid2TableView1Column3
          end>
        DataController.Summary.SummaryGroups = <>
        OptionsView.ColumnAutoWidth = True
        OptionsView.Footer = True
        OptionsView.GroupByBox = False
        object cxGrid2TableView1Column1: TcxGridColumn
          Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
          Width = 500
        end
        object cxGrid2TableView1Column2: TcxGridColumn
          Caption = #1057#1091#1084#1084#1072
          DataBinding.ValueType = 'Float'
          Width = 88
        end
        object cxGrid2TableView1Column3: TcxGridColumn
          Caption = #1050#1086#1084#1080#1089#1089#1080#1103
          DataBinding.ValueType = 'Float'
          Width = 89
        end
      end
      object cxGrid2Level1: TcxGridLevel
        GridView = cxGrid2TableView1
      end
    end
    object Panel4: TPanel
      Left = 0
      Top = 75
      Width = 613
      Height = 361
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 1
      object NumKvLabel: TLabel
        Left = 6
        Top = 81
        Width = 163
        Height = 24
        Alignment = taRightJustify
        Caption = #1050#1074#1080#1090#1072#1085#1094#1080#1103': 1236'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 38
        Top = 111
        Width = 40
        Height = 24
        Caption = #1050#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 212
        Top = 108
        Width = 64
        Height = 24
        Caption = #1053#1086#1084#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 0
        Top = 145
        Width = 50
        Height = 16
        Caption = #1050#1083#1080#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 10
        Top = 222
        Width = 48
        Height = 13
        Caption = #1058#1080#1087' '#1095#1077#1082#1072':'
      end
      object Label2: TLabel
        Left = 264
        Top = 222
        Width = 37
        Height = 13
        Caption = #1057#1091#1084#1084#1072':'
      end
      object KlNaydenLabel: TLabel
        Left = 6
        Top = 261
        Width = 93
        Height = 16
        Caption = 'KlNaydenLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Prim: TLabel
        Left = 6
        Top = 241
        Width = 31
        Height = 20
        Alignment = taCenter
        Caption = 'Prim'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object SumKlLabel: TLabel
        Left = 538
        Top = 81
        Width = 67
        Height = 13
        Alignment = taRightJustify
        Caption = 'SumKlLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object DBTextNAME_CODETEL: TDBText
        Left = -2
        Top = 32
        Width = 123
        Height = 13
        AutoSize = True
        DataField = 'NAME_CODETEL'
      end
      object DBTextNAMENOM: TDBText
        Left = 62
        Top = 48
        Width = 92
        Height = 13
        AutoSize = True
        DataField = 'NAMENOM'
      end
      object DBTextNOM_DEPARTMENT_NUMOTDKKT_SDEPAR: TDBText
        Left = -2
        Top = 48
        Width = 42
        Height = 13
        DataField = 'NOM_DEPARTMENT_NUMOTDKKT_SDEPAR'
      end
      object DBTextNAMENOMCOM: TDBText
        Left = 62
        Top = 62
        Width = 116
        Height = 13
        AutoSize = True
        DataField = 'NAMENOMCOM'
      end
      object DBTextCOM_DEPARTMENT_NUMOTDKKT_SDEPAR: TDBText
        Left = -2
        Top = 62
        Width = 42
        Height = 13
        DataField = 'COM_DEPARTMENT_NUMOTDKKT_SDEPAR'
      end
      object DBTextPRCOMIS_SCODETEL: TDBText
        Left = 542
        Top = 51
        Width = 59
        Height = 32
        DataField = 'PRCOMIS_SCODETEL'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LabelNameBank: TLabel
        Left = 398
        Top = 281
        Width = 198
        Height = 13
        Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1073#1072#1085#1082#1072' ('#1087#1083#1072#1090#1077#1078#1085#1086#1081' '#1089#1080#1089#1090#1077#1084#1099'):'
      end
      object LabelNumTerminal: TLabel
        Left = 409
        Top = 59
        Width = 95
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1090#1077#1088#1084#1080#1085#1072#1083#1072':'
      end
      object LabelNumDoc: TLabel
        Left = 6
        Top = 283
        Width = 94
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
      end
      object LabelAdressTerminal: TLabel
        Left = 398
        Top = 296
        Width = 92
        Height = 13
        Caption = #1040#1076#1088#1077#1089' '#1090#1077#1088#1084#1080#1085#1072#1083#1072':'
      end
      object LabelDateTimePlatega: TLabel
        Left = 398
        Top = 315
        Width = 113
        Height = 13
        Caption = #1044#1072#1090#1072', '#1074#1088#1077#1084#1103' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object LabelNameDomOperator: TLabel
        Left = 6
        Top = 302
        Width = 169
        Height = 13
        Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1076#1086#1084#1072#1096#1085#1077#1075#1086' '#1086#1087#1077#1088#1072#1090#1086#1088#1072':'
      end
      object LabelCodeAutorization: TLabel
        Left = 6
        Top = 321
        Width = 90
        Height = 13
        Caption = #1050#1086#1076' '#1072#1074#1090#1086#1088#1080#1079#1072#1094#1080#1080':'
      end
      object LabelLicSchetIsCiberplat: TLabel
        Left = 6
        Top = 336
        Width = 144
        Height = 13
        Caption = #1051#1080#1094#1077#1074#1086#1081' '#1089#1095#1077#1090' '#1080#1079' '#1050#1080#1073#1077#1088#1087#1083#1072#1090':'
      end
      object Label1: TLabel
        Left = 6
        Top = 177
        Width = 72
        Height = 13
        Caption = #1051#1080#1094#1077#1074#1086#1081' '#1089#1095#1077#1090':'
      end
      object LabelMsg: TLabel
        Left = 6
        Top = 350
        Width = 138
        Height = 13
        Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1082#1072' '#1082#1086#1076#1072' '#1086#1090#1074#1077#1090#1072':'
      end
      object LabelIdTerminal: TLabel
        Left = 414
        Top = 40
        Width = 72
        Height = 13
        Caption = 'ID '#1090#1077#1088#1084#1080#1085#1072#1083#1072':'
      end
      object CodeEdit: TcxTextEdit
        Left = 102
        Top = 105
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 0
        Text = 'CodeEdit'
        OnExit = CodeEditExit
        OnKeyPress = CodeEditKeyPress
        Width = 76
      end
      object NumberEdit: TcxTextEdit
        Left = 298
        Top = 105
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 1
        Text = 'NumberEdit'
        OnExit = NumberEditExit
        OnKeyPress = NumberEditKeyPress
        Width = 154
      end
      object NameKlientEdit: TcxTextEdit
        Left = 102
        Top = 143
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -16
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 2
        Text = 'NameKlientEdit'
        OnExit = NameKlientEditExit
        OnKeyPress = NameKlientEditKeyPress
        Width = 351
      end
      object ComboBox: TcxComboBox
        Left = 102
        Top = 211
        ParentFont = False
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          #1055#1088#1086#1076#1072#1078#1072
          #1042#1086#1079#1074#1088#1072#1090)
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 4
        Width = 121
      end
      object SumCheckEdit: TcxCalcEdit
        Left = 322
        Top = 211
        EditValue = 0.000000000000000000
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 5
        OnExit = SumCheckEditExit
        OnKeyPress = SumCheckEditKeyPress
        Width = 128
      end
      object ButtonPrintCheck: TcxButton
        Left = 510
        Top = 174
        Width = 90
        Height = 38
        Caption = #1063#1077#1082
        TabOrder = 7
        OnClick = ButtonPrintCheckClick
      end
      object ButtonPrintKvitan: TcxButton
        Left = 510
        Top = 123
        Width = 90
        Height = 38
        Caption = #1050#1074#1080#1090#1072#1085#1094#1080#1103
        TabOrder = 6
        OnClick = ButtonPrintKvitanClick
      end
      object cxTextEditLicSchet: TcxTextEdit
        Left = 102
        Top = 177
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -16
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 3
        Text = 'cxTextEditLicSchet'
        OnExit = NameKlientEditExit
        OnKeyPress = NameKlientEditKeyPress
        Width = 351
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 378
    Top = 32
    object N1: TMenuItem
      Caption = #1050#1050#1052
      GroupIndex = 10
      object N2: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100
      end
      object X1: TMenuItem
        Caption = 'X - '#1086#1090#1095#1077#1090
        OnClick = X1Click
      end
      object Z1: TMenuItem
        Caption = 'Z - '#1086#1090#1095#1077#1090
        OnClick = Z1Click
      end
      object N3: TMenuItem
        Caption = #1055#1086' '#1086#1090#1076#1077#1083#1072#1084
        OnClick = N3Click
      end
    end
    object N4: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080
      GroupIndex = 10
      object MaimMenuProvestiPlateg: TMenuItem
        Caption = #1055#1088#1086#1074#1077#1089#1090#1080' '#1087#1083#1072#1090#1077#1078
        OnClick = MaimMenuProvestiPlategClick
      end
    end
  end
  object ActionList1: TActionList
    Left = 16
    Top = 8
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
