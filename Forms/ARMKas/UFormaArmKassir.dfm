object FormaARMKassir: TFormaARMKassir
  Left = 250
  Top = 138
  Caption = #1040#1056#1052' '#1082#1072#1089#1089#1080#1088#1072
  ClientHeight = 657
  ClientWidth = 927
  Color = clBtnFace
  Constraints.MinWidth = 935
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu1
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
  object Panel5: TPanel
    Left = 0
    Top = 502
    Width = 927
    Height = 155
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 1
    object Prim: TLabel
      Left = 10
      Top = 75
      Width = 572
      Height = 43
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = False
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object Oper: TDBText
      Left = 10
      Top = 27
      Width = 46
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taCenter
      AutoSize = True
      DataField = 'OPERCHK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object GroupBoxSum: TGroupBox
      Left = 535
      Top = 6
      Width = 185
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072':'
      TabOrder = 2
      object SumDoc: TDBText
        Left = 10
        Top = 20
        Width = 171
        Height = 30
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        DataField = 'SUMDOC'
        DataSource = DMDocCheck.DataSourceDocAll
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object GroupBoxSdacha: TGroupBox
      Left = 727
      Top = 6
      Width = 185
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1076#1072#1095#1072':'
      TabOrder = 3
      object Sdacha: TDBText
        Left = 10
        Top = 20
        Width = 159
        Height = 30
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        DataField = 'SDACHA_DCHK'
        DataSource = DMDocCheck.DataSourceDoc
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object GroupBoxPC: TGroupBox
      Left = 343
      Top = 6
      Width = 185
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081':'
      TabOrder = 1
      object OplataPC: TcxDBCalcEdit
        Left = 7
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'OPLPCCHK'
        DataBinding.DataSource = DMDocCheck.DataSourceDoc
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -23
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 0
        OnExit = OplataPCExit
        OnKeyDown = OplataPCKeyDown
        Width = 171
      end
    end
    object GroupBoxNal: TGroupBox
      Left = 151
      Top = 6
      Width = 185
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080':'
      TabOrder = 0
      object Nal: TcxDBCalcEdit
        Left = 7
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALCHK'
        DataBinding.DataSource = DMDocCheck.DataSourceDoc
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -23
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.HotTrack = True
        Style.IsFontAssigned = True
        TabOrder = 0
        OnExit = NalExit
        OnKeyDown = NalKeyDown
        Width = 169
      end
    end
    object StatusBar: TStatusBar
      Left = 1
      Top = 135
      Width = 925
      Height = 19
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Panels = <
        item
          Text = #1060#1080#1088#1084#1072
          Width = 200
        end
        item
          Text = #1057#1082#1083#1072#1076
          Width = 200
        end
        item
          Text = #1050#1050#1052
          Width = 100
        end
        item
          Text = #1060#1056' '#8470
          Width = 80
        end
        item
          Text = #1050#1051' '#8470
          Width = 75
        end
        item
          Text = #1095#1077#1082' '#8470
          Width = 50
        end>
    end
    object ButtonPrint: TcxButton
      Left = 601
      Top = 75
      Width = 150
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 5
    end
    object ButtonClose: TcxButton
      Left = 758
      Top = 75
      Width = 154
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 6
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 927
    Height = 159
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 2
    object NameDoc: TLabel
      Left = 10
      Top = 54
      Width = 130
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1063#1077#1082' '#1050#1050#1052' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKKMLabel: TLabel
      Left = 795
      Top = 10
      Width = 127
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TypePriceLabel: TLabel
      Left = 799
      Top = 32
      Width = 123
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = 'TypePriceLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object UchLabel: TLabel
      Left = 817
      Top = 54
      Width = 101
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = 'UchLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NumberDocDBText: TDBText
      Left = 158
      Top = 49
      Width = 129
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataField = 'NUMDOC'
      DataSource = DMDocCheck.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKlientDBText: TDBText
      Left = 10
      Top = 10
      Width = 306
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataField = 'NAMEKLIENT'
      DataSource = DMDocCheck.DataSourceDocAll
    end
    object PanelName: TPanel
      Left = 10
      Top = 90
      Width = 460
      Height = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 0
      object NameNomDBText: TDBText
        Left = 10
        Top = 10
        Width = 444
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataField = 'NAMENOM'
        DataSource = DMDocCheck.DataSourceDocT
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 10
        Top = 39
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
    end
    object PanelKF: TPanel
      Left = 620
      Top = 90
      Width = 139
      Height = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 1
      object Label7: TLabel
        Left = 10
        Top = 39
        Width = 22
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1060':'
      end
      object KFDBText: TDBText
        Left = 10
        Top = 10
        Width = 119
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        DataField = 'KFCHKT'
        DataSource = DMDocCheck.DataSourceDocT
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object PanelPrice: TPanel
      Left = 759
      Top = 90
      Width = 159
      Height = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 2
      object Label8: TLabel
        Left = 10
        Top = 39
        Width = 36
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1062#1077#1085#1072':'
      end
      object PriceDBText: TDBText
        Left = 10
        Top = 10
        Width = 139
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        DataField = 'PRICECHKT'
        DataSource = DMDocCheck.DataSourceDocT
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object PanelKol: TPanel
      Left = 470
      Top = 90
      Width = 150
      Height = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 3
      object Label6: TLabel
        Left = 10
        Top = 39
        Width = 81
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      end
      object KolDBText: TDBText
        Left = 10
        Top = 10
        Width = 129
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        DataField = 'KOLCHKT'
        DataSource = DMDocCheck.DataSourceDocT
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object NameDCardcxDBLabel: TcxDBLabel
      Left = 9
      Top = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
      DataBinding.DataSource = DMDocCheck.DataSourceDoc
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 159
    Width = 927
    Height = 343
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnExit = cxGrid1Exit
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMDocCheck.DataSourceDocT
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMCHKT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SKCHKT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1NADCHKT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsSelection.InvertSelect = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Footer = DM.cxStyleFooterSum
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 49
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Width = 222
      end
      object cxGrid1DBTableView1KOLCHKT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOLCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.OnValidate = cxGrid1DBTableView1KOLCHKTPropertiesValidate
        Width = 46
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
        Width = 59
      end
      object cxGrid1DBTableView1KFCHKT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KFCHKT'
        Options.Editing = False
        Width = 39
      end
      object cxGrid1DBTableView1PRICECHKT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICECHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 74
      end
      object cxGrid1DBTableView1SUMCHKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 96
      end
      object cxGrid1DBTableView1PRSKCHKT: TcxGridDBColumn
        Caption = '-%'
        DataBinding.FieldName = 'PRSKCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ReadOnly = True
        Width = 34
      end
      object cxGrid1DBTableView1PRNADCHKT: TcxGridDBColumn
        Caption = '+%'
        DataBinding.FieldName = 'PRNADCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ReadOnly = True
        Width = 31
      end
      object cxGrid1DBTableView1SKCHKT: TcxGridDBColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.FieldName = 'SKCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ReadOnly = True
        Width = 48
      end
      object cxGrid1DBTableView1NADCHKT: TcxGridDBColumn
        Caption = #1053#1072#1076#1073#1072#1074#1082#1072
        DataBinding.FieldName = 'NADCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ReadOnly = True
        Width = 52
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object MainMenu1: TMainMenu
    Left = 232
    Top = 96
    object N14: TMenuItem
      Caption = #1053#1086#1074#1099#1081' '#1095#1077#1082
      GroupIndex = 10
      object NewCheckSale: TMenuItem
        Caption = #1055#1088#1086#1076#1072#1078#1072
        ShortCut = 112
        OnClick = NewCheckSaleClick
      end
      object NewCheckReturnSale: TMenuItem
        Caption = #1042#1086#1079#1074#1088#1072#1090
        ShortCut = 113
        OnClick = NewCheckReturnSaleClick
      end
      object OpenCheck: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1095#1077#1082' '#1087#1088#1086#1076#1072#1078#1080
        ShortCut = 114
        OnClick = OpenCheckClick
      end
      object OpenCheckForVosvratMainMenu: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1095#1077#1082' '#1076#1083#1103' '#1074#1086#1079#1074#1088#1072#1090#1072
        OnClick = OpenCheckForVosvratMainMenuClick
      end
    end
    object N2: TMenuItem
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
      GroupIndex = 10
      object MenuInputCodeBV: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091' '#1041#1042
        ShortCut = 116
        OnClick = MenuInputCodeBVClick
      end
      object MenuInputCodeNom: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ShortCut = 117
        OnClick = MenuInputCodeNomClick
      end
      object N8: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1041#1042
        ShortCut = 118
        OnClick = N8Click
      end
      object N11: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        ShortCut = 119
        OnClick = N11Click
      end
      object AddSvobSum: TMenuItem
        Caption = #1057#1074#1086#1073#1086#1076#1085#1072#1103' '#1089#1091#1084#1084#1072
        ShortCut = 16500
        OnClick = AddSvobSumClick
      end
      object PoBarCode: TMenuItem
        Caption = #1055#1086' '#1064#1050' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ShortCut = 45
        OnClick = PoBarCodeClick
      end
      object PoArtikulu: TMenuItem
        Caption = #1055#1086' '#1072#1088#1090#1080#1082#1091#1083#1091
        ShortCut = 16503
        OnClick = PoArtikuluClick
      end
    end
    object N1: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1103
      GroupIndex = 10
      object N4: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1077#1076#1080#1085#1080#1094#1091
        ShortCut = 16474
        OnClick = N4Click
      end
      object DeleteString: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        ShortCut = 46
        OnClick = DeleteStringClick
      end
      object VibratProjectMainMenu: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1088#1086#1077#1082#1090
        ShortCut = 16472
        OnClick = VibratProjectMainMenuClick
      end
    end
    object N3: TMenuItem
      Caption = #1054#1087#1083#1072#1090#1072
      GroupIndex = 10
      object N9: TMenuItem
        Caption = #1053#1072#1083#1080#1095#1085#1099#1077
        ShortCut = 120
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1072
        ShortCut = 121
        OnClick = N10Click
      end
    end
    object N6: TMenuItem
      Caption = #1057#1082#1080#1076#1082#1080
      GroupIndex = 10
      object ViborDiscCardMainmenu: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1082#1072#1088#1090#1091
        ShortCut = 122
        OnClick = ViborDiscCardMainmenuClick
      end
    end
    object N15: TMenuItem
      Caption = #1055#1077#1095#1072#1090#1100
      GroupIndex = 10
      object MenuPrintCheck: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1095#1077#1082#1072
        OnClick = MenuPrintCheckClick
      end
      object N12: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1090#1086#1074#1072#1088#1085#1086#1075#1086' '#1095#1077#1082#1072
        OnClick = N12Click
      end
      object mmPrintCoodsCheckOnFR: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1090#1086#1074#1072#1088#1085#1086#1075#1086' '#1095#1077#1082#1072' '#1085#1072' '#1060#1056
        OnClick = mmPrintCoodsCheckOnFRClick
      end
      object SaveCheckMainMenu: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1095#1077#1082
        ShortCut = 123
        OnClick = SaveCheckMainMenuClick
      end
      object CloseDoc: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100' '#1095#1077#1082
        ShortCut = 16507
        OnClick = CloseDocClick
      end
    end
    object N7: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099' '#1050#1050#1052
      GroupIndex = 10
      object PrintXreport: TMenuItem
        Caption = 'X-'#1086#1090#1095#1077#1090
        OnClick = PrintXreportClick
      end
      object PrintZreport: TMenuItem
        Caption = 'Z-'#1086#1090#1095#1077#1090
        OnClick = PrintZreportClick
      end
      object Vnesenie: TMenuItem
        Caption = #1042#1085#1077#1089#1077#1085#1080#1077
        OnClick = VnesenieClick
      end
      object Snatie: TMenuItem
        Caption = #1057#1085#1103#1090#1080#1077
        OnClick = SnatieClick
      end
    end
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 400
    Top = 48
    object OpenHelp: TAction
      Caption = 'OpenHelp'
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 54
      OnExecute = ActionPrintExecute
    end
  end
end
