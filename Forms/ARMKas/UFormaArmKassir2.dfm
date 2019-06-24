object FormaARMKassir2: TFormaARMKassir2
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
    Top = 524
    Width = 927
    Height = 133
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 1
    object Prim: TLabel
      Left = 12
      Top = 76
      Width = 581
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
      Top = 20
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
      Top = 7
      Width = 185
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072':'
      TabOrder = 2
      object SumDocLabel: TLabel
        Left = -69
        Top = 12
        Width = 250
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'SumDocLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object GroupBoxSdacha: TGroupBox
      Left = 727
      Top = 6
      Width = 185
      Height = 63
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1076#1072#1095#1072':'
      TabOrder = 3
      object SdachaLabel: TLabel
        Left = -54
        Top = 14
        Width = 232
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'SdachaLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
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
      object OplCardcxCalcEdit: TcxCalcEdit
        Left = 16
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        EditValue = 0.000000000000000000
        ParentFont = False
        Properties.ReadOnly = True
        Properties.OnEditValueChanged = OplCardcxCalcEditPropertiesEditValueChanged
        Style.Color = clInactiveBorder
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -23
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 0
        OnKeyDown = OplCardcxCalcEditKeyDown
        Width = 149
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
      object NalcxCalcEdit: TcxCalcEdit
        Left = 16
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        EditValue = 0.000000000000000000
        ParentFont = False
        Properties.OnEditValueChanged = NalcxCalcEditPropertiesEditValueChanged
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -23
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 0
        OnExit = NalcxCalcEditExit
        OnKeyDown = NalcxCalcEditKeyDown
        Width = 149
      end
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
      TabOrder = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
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
      TabOrder = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 927
    Height = 129
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 2
    object NameKKMLabel: TLabel
      Left = 795
      Top = 5
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
      Top = 27
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
      Left = 528
      Top = 36
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
    object NameKlientLabel: TLabel
      Left = 5
      Top = 5
      Width = 103
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NameKlientLabel'
    end
    object NameDiscountCardLabel: TLabel
      Left = 5
      Top = 22
      Width = 152
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NameDiscountCardLabel'
    end
    object NameFirmLabel: TLabel
      Left = 5
      Top = 46
      Width = 97
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NameFirmLabel'
    end
    object PanelName: TPanel
      Left = 2
      Top = 62
      Width = 468
      Height = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 0
      object Label5: TLabel
        Left = 10
        Top = 44
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object NameNomLabel: TLabel
        Left = 10
        Top = 1
        Width = 289
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'NameNomLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object PanelKF: TPanel
      Left = 636
      Top = 62
      Width = 109
      Height = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 1
      object Label7: TLabel
        Left = 7
        Top = 44
        Width = 22
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1060':'
      end
      object KFLabel: TLabel
        Left = -47
        Top = 1
        Width = 148
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'KFLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object PanelPrice: TPanel
      Left = 745
      Top = 62
      Width = 174
      Height = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 2
      object Label8: TLabel
        Left = 10
        Top = 44
        Width = 36
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1062#1077#1085#1072':'
      end
      object PriceLabel: TLabel
        Left = -20
        Top = 1
        Width = 189
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'PriceLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object PanelKol: TPanel
      Left = 470
      Top = 62
      Width = 165
      Height = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      BevelOuter = bvLowered
      TabOrder = 3
      object Label6: TLabel
        Left = 10
        Top = 44
        Width = 81
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      end
      object KolLabel: TLabel
        Left = 4
        Top = 1
        Width = 155
        Height = 48
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'KolLabel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -38
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 129
    Width = 927
    Height = 395
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    OnExit = cxGrid1Exit
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
    end
    object cxGrid1TableView1: TcxGridTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0.00'
          Kind = skSum
          OnGetText = cxGrid1TableView1TcxGridDataControllerTcxDataSummaryFooterSummaryItems0GetText
          Column = cxGrid1TableView1SUM
        end
        item
          Kind = skSum
          Column = cxGrid1TableView1SKIDKA
        end>
      DataController.Summary.SummaryGroups = <>
      DataController.OnAfterPost = cxGrid1TableView1DataControllerAfterPost
      OptionsBehavior.IncSearch = True
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Content = DM.cxStyleGirnFont
      Styles.Footer = DM.cxStyleFooterSum
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1TableView1FL_PRINT: TcxGridColumn
        OnCustomDrawCell = cxGrid1TableView1FL_PRINTCustomDrawCell
        Width = 26
      end
      object cxGrid1TableView1RECNO: TcxGridColumn
        Caption = #8470
        Width = 21
      end
      object cxGrid1TableView1IDNOM: TcxGridColumn
        Caption = 'IDNOM'
        Visible = False
      end
      object cxGrid1TableView1NAMENOM: TcxGridColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        OnGetDisplayText = cxGrid1TableView1NAMENOMGetDisplayText
        Width = 244
      end
      object cxGrid1TableView1KRNAMENOM: TcxGridColumn
        Visible = False
      end
      object cxGrid1TableView1TNOM: TcxGridColumn
        DataBinding.ValueType = 'Integer'
        Visible = False
      end
      object cxGrid1TableView1KOL: TcxGridColumn
        Caption = #1050#1086#1083'.'
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.000'
        Properties.ImmediatePost = True
        Properties.QuickClose = True
        OnGetDisplayText = cxGrid1TableView1KOLGetDisplayText
        Width = 57
      end
      object cxGrid1TableView1IDED: TcxGridColumn
        Caption = 'IDED'
        Visible = False
      end
      object cxGrid1TableView1NAMEED: TcxGridColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1TableView1NAMEEDPropertiesButtonClick
        Width = 60
      end
      object cxGrid1TableView1KFED: TcxGridColumn
        Caption = #1050#1060
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.AssignedValues.DisplayFormat = True
        Properties.ReadOnly = True
        OnGetDisplayText = cxGrid1TableView1KFEDGetDisplayText
        Width = 43
      end
      object cxGrid1TableView1PRICE: TcxGridColumn
        Caption = #1062#1077#1085#1072
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        OnGetDisplayText = cxGrid1TableView1PRICEGetDisplayText
        Width = 98
      end
      object cxGrid1TableView1SUM: TcxGridColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.ValueType = 'Variant'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Properties.Precision = 15
        Properties.ReadOnly = False
        Width = 108
      end
      object cxGrid1TableView1PRSK: TcxGridColumn
        Caption = '-%'
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.AssignedValues.DisplayFormat = True
        Properties.ReadOnly = True
        Width = 31
      end
      object cxGrid1TableView1SKIDKA: TcxGridColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Properties.ReadOnly = True
        Width = 62
      end
      object cxGrid1TableView1PRSK_CARD: TcxGridColumn
        DataBinding.ValueType = 'Float'
        Visible = False
      end
      object cxGrid1TableView1PRSK_AUTO: TcxGridColumn
        DataBinding.ValueType = 'Float'
        Visible = False
      end
      object cxGrid1TableView1IDFIRM: TcxGridColumn
        Caption = 'IDFIRM'
        Visible = False
      end
      object cxGrid1TableView1NAMEFIRM: TcxGridColumn
        Caption = #1060#1080#1088#1084#1072
        Visible = False
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1TableView1
    end
  end
  object MainMenu1: TMainMenu
    Left = 224
    Top = 104
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
        ShortCut = 115
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
        ShortCut = 8309
        OnClick = PoBarCodeClick
      end
    end
    object N1: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1103
      GroupIndex = 10
      object N4: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1077#1076#1080#1085#1080#1094#1091
        ShortCut = 16449
        OnClick = N4Click
      end
      object DeleteString: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        ShortCut = 46
        OnClick = DeleteStringClick
      end
    end
    object N3: TMenuItem
      Caption = #1054#1087#1083#1072#1090#1072
      GroupIndex = 10
      object N9: TMenuItem
        Caption = #1053#1072#1083#1080#1095#1085#1099#1077
        ShortCut = 16504
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1072
        ShortCut = 16505
        OnClick = N10Click
      end
      object OpalataPoFirmMainMenu: TMenuItem
        Caption = #1054#1087#1083#1072#1090#1072' '#1087#1086' '#1092#1080#1088#1084#1072#1084
        ShortCut = 120
        OnClick = OpalataPoFirmMainMenuClick
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
        ShortCut = 16472
        OnClick = PrintXreportClick
      end
      object PrintZreport: TMenuItem
        Caption = 'Z-'#1086#1090#1095#1077#1090
        ShortCut = 16474
        OnClick = PrintZreportClick
      end
      object Vnesenie: TMenuItem
        Caption = #1042#1085#1077#1089#1077#1085#1080#1077
        ShortCut = 16470
        OnClick = VnesenieClick
      end
      object Snatie: TMenuItem
        Caption = #1057#1085#1103#1090#1080#1077
        ShortCut = 16467
        OnClick = SnatieClick
      end
      object ReportTecProdagiMainMenu: TMenuItem
        Caption = #1058#1077#1082#1091#1097#1080#1077' '#1087#1088#1086#1076#1072#1078#1080
        ShortCut = 16464
        OnClick = ReportTecProdagiMainMenuClick
      end
    end
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 408
    Top = 80
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
  object ImageList1: TImageList
    Left = 424
    Top = 504
    Bitmap = {
      494C0101020014002C0010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00005DB92BFE0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007BCE
      98FE3EB343FE0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004BBF
      79FE41BD7BFE57B724FE00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000003DBB
      6EFE3EBA6DFE3FB54FFE00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000003FBA
      70FE41BC72FE3EBC75FE45B016FE000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000051C07CFE3EBA
      6EFE58C483FE41BB71FE41BB72FE000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000041BC71FE5CC9
      8DFF0000000042BB71FE41BC6FFE3CB648FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003FBC70FF3FBC70FF0000
      000000000000000000003EBB6FFF41BC74FE68C465FE00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005FC687FE4DC17FFE000000000000
      00000000000000000000000000003EBC70FF41BC75FE00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000046BC75FE3FBC70FF000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000081D2A0FE3FBC70FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000003EBB
      70FF000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000082D2A2FE0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF00000000FFFFFE3F00000000
      F7FFFE3F00000000E7FFFFFF00000000E3FFFFFF00000000E3FFFE3F00000000
      E1FFFE3F00000000C1FFFE3F00000000C8FFFE3F000000009C7FFE3F00000000
      3E7FFE3F00000000FF3FFE3F00000000FF9FFE3F00000000FFEFFE3F00000000
      FFF7FFFF00000000FFFFFFFF0000000000000000000000000000000000000000
      000000000000}
  end
end
