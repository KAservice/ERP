object FormaDocCheckTouch: TFormaDocCheckTouch
  Left = 222
  Top = 20
  Caption = #1063#1077#1082' '#1050#1050#1052
  ClientHeight = 656
  ClientWidth = 926
  Color = clBtnFace
  Constraints.MinWidth = 935
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
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 926
    Height = 490
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabHeight = 30
    TabOrder = 0
    TabWidth = 150
    ExplicitHeight = 468
    ClientRectBottom = 490
    ClientRectRight = 926
    ClientRectTop = 32
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 926
        Height = 209
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object NameDoc: TLabel
          Left = 556
          Top = 114
          Width = 152
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1063#1077#1082' '#1050#1050#1052' '#8470
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -27
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object UchLabel: TLabel
          Left = 447
          Top = 112
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
        object NumDocDBText: TDBText
          Left = 709
          Top = 114
          Width = 209
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          AutoSize = True
          DataField = 'NUMDOC'
          DataSource = DMDocCheck.DataSourceDocAll
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object NamePriceLabel: TLabel
          Left = 766
          Top = 93
          Width = 116
          Height = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Alignment = taRightJustify
          Caption = 'NamePriceLabel'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -17
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label4: TLabel
          Left = 9
          Top = 95
          Width = 78
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1083#1080#1077#1085#1090':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object NameKlientDBText: TDBText
          Left = 100
          Top = 95
          Width = 176
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          AutoSize = True
          DataField = 'NAMEKLIENT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label1: TLabel
          Left = 10
          Top = 114
          Width = 122
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1080#1089#1082'. '#1082#1072#1088#1090#1072':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Panel8: TPanel
          Left = 4
          Top = 146
          Width = 460
          Height = 60
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          BevelOuter = bvLowered
          TabOrder = 0
          object DBText1: TDBText
            Left = 10
            Top = 10
            Width = 443
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
        object Panel11: TPanel
          Left = 616
          Top = 146
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
          object DBText3: TDBText
            Left = 7
            Top = 8
            Width = 122
            Height = 31
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            DataField = 'KFCHKT'
            DataSource = DMDocCheck.DataSourceDocT
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object Panel12: TPanel
          Left = 753
          Top = 146
          Width = 173
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
          object DBText4: TDBText
            Left = 10
            Top = 10
            Width = 159
            Height = 31
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            DataField = 'PRICECHKT'
            DataSource = DMDocCheck.DataSourceDocT
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object Panel13: TPanel
          Left = 465
          Top = 146
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
          object DBText2: TDBText
            Left = 7
            Top = 8
            Width = 136
            Height = 31
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            DataField = 'KOLCHKT'
            DataSource = DMDocCheck.DataSourceDocT
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object BitBtn1: TBitBtn
          Left = 10
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1074#1099#1081' '#1095#1077#1082
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 4
          WordWrap = True
          OnClick = BitBtn1Click
        end
        object BitBtnAddSprBVNom: TBitBtn
          Left = 272
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1041#1042
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 5
          WordWrap = True
          OnClick = BitBtnAddSprBVNomClick
        end
        object BitBtn3: TBitBtn
          Left = 447
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1045#1076#1080#1085#1080'- '#1094#1072
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 6
          WordWrap = True
          OnClick = BitBtn3Click
        end
        object BitBtn4: TBitBtn
          Left = 534
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1086#1083#1080'- '#1095#1077#1089#1090#1074#1086
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 7
          WordWrap = True
          OnClick = BitBtn4Click
        end
        object BitBtn5: TBitBtn
          Left = 622
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1086#1087'.'
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 8
          WordWrap = True
          OnClick = BitBtn5Click
        end
        object BitBtn6: TBitBtn
          Left = 709
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333303333
            333333333337F33333333333333033333333333333373F333333333333090333
            33333333337F7F33333333333309033333333333337373F33333333330999033
            3333333337F337F33333333330999033333333333733373F3333333309999903
            333333337F33337F33333333099999033333333373333373F333333099999990
            33333337FFFF3FF7F33333300009000033333337777F77773333333333090333
            33333333337F7F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333300033333333333337773333333}
          NumGlyphs = 2
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 9
          WordWrap = True
          OnClick = BitBtn6Click
        end
        object BitBtn7: TBitBtn
          Left = 796
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000333
            3333333333777F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333309033333333333FF7F7FFFF333333000090000
            3333333777737777F333333099999990333333373F3333373333333309999903
            333333337F33337F33333333099999033333333373F333733333333330999033
            3333333337F337F3333333333099903333333333373F37333333333333090333
            33333333337F7F33333333333309033333333333337373333333333333303333
            333333333337F333333333333330333333333333333733333333}
          NumGlyphs = 2
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 10
          WordWrap = True
          OnClick = BitBtn7Click
        end
        object BitBtnAddGoodsPoCodu: TBitBtn
          Left = 185
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1086#1076
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 11
          WordWrap = True
          OnClick = BitBtnAddGoodsPoCoduClick
        end
        object BitBtnPodbor: TBitBtn
          Left = 359
          Top = 6
          Width = 87
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1076#1073#1086#1088
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 12
          WordWrap = True
          OnClick = BitBtnPodborClick
        end
        object BitBtnInputDiscountCard: TBitBtn
          Left = 97
          Top = 6
          Width = 86
          Height = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1080#1089#1082#1086#1085#1090'. '#1082#1072#1088#1090#1072
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 13
          WordWrap = True
          OnClick = BitBtnInputDiscountCardClick
        end
        object NameDiscountCardcxDBLabel: TcxDBLabel
          Left = 148
          Top = 112
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -18
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          Height = 30
          Width = 302
        end
      end
      object cxGrid1: TcxGrid
        Left = 0
        Top = 209
        Width = 926
        Height = 235
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 1
        ExplicitTop = 238
        ExplicitHeight = 184
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DMDocCheck.DataSourceDocT
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              FieldName = 'SUMCHKT'
              Column = cxGrid1DBTableView1SUMCHKT
            end
            item
              Kind = skSum
              FieldName = 'SKCHKT'
              Column = cxGrid1DBTableView1SKCHKT
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 45
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            Width = 234
          end
          object cxGrid1DBTableView1KOLCHKT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLCHKT'
            Width = 62
          end
          object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            Width = 59
          end
          object cxGrid1DBTableView1KFCHKT: TcxGridDBColumn
            Caption = #1050#1060'.'
            DataBinding.FieldName = 'KFCHKT'
            Width = 73
          end
          object cxGrid1DBTableView1PRICECHKT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICECHKT'
            Width = 69
          end
          object cxGrid1DBTableView1SUMCHKT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUMCHKT'
            Styles.Content = DM.cxStyleFooterSum
            Width = 95
          end
          object cxGrid1DBTableView1PRSKCHKT: TcxGridDBColumn
            Caption = '-%'
            DataBinding.FieldName = 'PRSKCHKT'
            Width = 32
          end
          object cxGrid1DBTableView1SKCHKT: TcxGridDBColumn
            Caption = #1057#1082#1080#1076#1082#1072
            DataBinding.FieldName = 'SKCHKT'
            Width = 81
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 444
        Width = 926
        Height = 14
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 2
        ExplicitTop = 422
        object KrNameNomDBText: TDBText
          Left = 60
          Top = 0
          Width = 123
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          AutoSize = True
          DataField = 'KRNAMENOM'
          DataSource = DMDocCheck.DataSourceDocT
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1083#1072#1090#1072
      ImageIndex = 1
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 926
        Height = 89
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object NameKlientDopDBText: TDBText
          Left = 132
          Top = 14
          Width = 517
          Height = 35
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataField = 'NAMEKLIENT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -23
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object NameCardDopDBText: TDBText
          Left = 132
          Top = 41
          Width = 451
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataField = 'NAME_SDISCOUNT_CARD'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -23
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object Label17: TLabel
          Left = 42
          Top = 23
          Width = 50
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1083#1080#1077#1085#1090':'
        end
        object Label18: TLabel
          Left = 50
          Top = 50
          Width = 42
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1072#1088#1090#1072':'
        end
      end
      object GroupBox14: TGroupBox
        Left = 194
        Top = 89
        Width = 719
        Height = 369
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1082#1072#1088#1090#1099' '#1086#1087#1083#1072#1090#1099':'
        TabOrder = 1
        object Panel4: TPanel
          Left = 2
          Top = 18
          Width = 715
          Height = 53
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object BitBtn2: TBitBtn
            Left = 4
            Top = 1
            Width = 123
            Height = 49
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1072#1088#1090#1091
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 0
            WordWrap = True
          end
          object BitBtn8: TBitBtn
            Left = 130
            Top = 1
            Width = 124
            Height = 49
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082#1072#1088#1090#1091
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 1
            WordWrap = True
          end
          object BitBtn9: TBitBtn
            Left = 257
            Top = 1
            Width = 123
            Height = 49
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1057#1091#1084#1084#1072' '#1087#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 2
            WordWrap = True
          end
          object BitBtn10: TBitBtn
            Left = 384
            Top = 1
            Width = 123
            Height = 49
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1057#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1085#1086#1081' '#1082#1072#1088#1090#1086#1081
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 3
            WordWrap = True
          end
        end
        object cxGrid2: TcxGrid
          Left = 2
          Top = 71
          Width = 715
          Height = 245
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          ExplicitHeight = 223
          object cxGrid2DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <
              item
                Kind = skSum
                FieldName = 'SUMCREDIT_DCHK_OPL'
                Column = cxGrid2DBTableView1SUMCREDIT_DCHK_OPL
              end
              item
                Kind = skSum
                FieldName = 'SUMPLAT_DCHK_OPL'
                Column = cxGrid2DBTableView1SUMPLAT_DCHK_OPL
              end>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.Footer = True
            OptionsView.GroupByBox = False
            Styles.Header = DM.cxStyleHeaderTable
            object cxGrid2DBTableView1RECNO: TcxGridDBColumn
              Caption = #8470
              DataBinding.FieldName = 'RECNO'
              Width = 27
            end
            object cxGrid2DBTableView1NAME_SDISCOUNT_CARD: TcxGridDBColumn
              Caption = #1050#1072#1088#1090#1072
              DataBinding.FieldName = 'NAME_SDISCOUNT_CARD'
              Width = 297
            end
            object cxGrid2DBTableView1SUMPLAT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1087#1083#1072#1090#1077#1078#1072
              DataBinding.FieldName = 'SUMPLAT_DCHK_OPL'
              Width = 101
            end
            object cxGrid2DBTableView1SUMCREDIT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1090#1072
              DataBinding.FieldName = 'SUMCREDIT_DCHK_OPL'
              Width = 103
            end
          end
          object cxGrid2Level1: TcxGridLevel
            GridView = cxGrid2DBTableView1
          end
        end
        object Panel10: TPanel
          Left = 2
          Top = 316
          Width = 715
          Height = 51
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alBottom
          BevelOuter = bvNone
          TabOrder = 2
          object GroupBox15: TGroupBox
            Left = 5
            Top = -1
            Width = 341
            Height = 50
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1042#1089#1077#1075#1086' '#1087#1083#1072#1090#1077#1078#1085#1099#1084#1080' '#1082#1072#1088#1090#1072#1084#1080':'
            TabOrder = 0
            object AllOplPlatCardcxDBLabel: TcxDBLabel
              Left = 2
              Top = 18
              Margins.Left = 4
              Margins.Top = 4
              Margins.Right = 4
              Margins.Bottom = 4
              Align = alClient
              DataBinding.DataField = 'OPLPLATCARD_ALL_DCHK'
              ParentFont = False
              Properties.Alignment.Horz = taRightJustify
              Properties.Orientation = cxoLeft
              Style.BorderStyle = ebsNone
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clNavy
              Style.Font.Height = -20
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              Height = 30
              Width = 337
              AnchorX = 339
            end
          end
          object GroupBox16: TGroupBox
            Left = 353
            Top = -1
            Width = 351
            Height = 50
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1042#1089#1077#1075#1086' '#1082#1088#1077#1076#1080#1090#1085#1099#1084#1080' '#1082#1072#1088#1090#1072#1084#1080':'
            TabOrder = 1
            object AllOplCreditCardcxDBLabel: TcxDBLabel
              Left = 2
              Top = 18
              Margins.Left = 4
              Margins.Top = 4
              Margins.Right = 4
              Margins.Bottom = 4
              Align = alClient
              DataBinding.DataField = 'OPLCREDITCARD_ALL_DCHK'
              ParentFont = False
              Properties.Alignment.Horz = taRightJustify
              Properties.Orientation = cxoLeft
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clNavy
              Style.Font.Height = -20
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              Height = 30
              Width = 347
              AnchorX = 349
            end
          end
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 89
        Width = 12
        Height = 369
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 2
        ExplicitHeight = 347
      end
      object Panel9: TPanel
        Left = 913
        Top = 89
        Width = 13
        Height = 369
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 3
        ExplicitHeight = 347
      end
      object Panel14: TPanel
        Left = 12
        Top = 89
        Width = 178
        Height = 369
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 4
        ExplicitHeight = 347
        object GroupBox13: TGroupBox
          Left = 0
          Top = 0
          Width = 178
          Height = 238
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alTop
          Caption = #1054#1089#1085#1086#1074#1085#1072#1103' '#1082#1072#1088#1090#1072' '#1086#1087#1083#1072#1090#1099':'
          TabOrder = 0
          object GroupBox11: TGroupBox
            Left = 6
            Top = 20
            Width = 166
            Height = 48
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1055#1083#1072#1090#1077#1078#1085#1072#1103' '#1082#1072#1088#1090#1072
            TabOrder = 0
            object OplataPlatCardDBText: TDBText
              Left = 2
              Top = 18
              Width = 162
              Height = 28
              Margins.Left = 4
              Margins.Top = 4
              Margins.Right = 4
              Margins.Bottom = 4
              Align = alClient
              Alignment = taRightJustify
              DataField = 'OPLPLATCARD_DCHK'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -28
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
            end
          end
          object InputSumOsnPlatCardBitBtn: TBitBtn
            Left = 5
            Top = 73
            Width = 166
            Height = 49
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1081' '#1082#1072#1088#1090#1086#1081
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 1
            WordWrap = True
            OnClick = InputSumOsnPlatCardBitBtnClick
          end
          object GroupBox12: TGroupBox
            Left = 9
            Top = 129
            Width = 165
            Height = 48
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1050#1088#1077#1076#1080#1090#1085#1072#1103' '#1082#1072#1088#1090#1072
            TabOrder = 2
            object OplataCreditCardDBText: TDBText
              Left = 2
              Top = 18
              Width = 161
              Height = 28
              Margins.Left = 4
              Margins.Top = 4
              Margins.Right = 4
              Margins.Bottom = 4
              Align = alClient
              Alignment = taRightJustify
              DataField = 'OPLCREDITCARD_DCHK'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -23
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              ExplicitWidth = 160
            end
          end
          object InputSumOsnCreditCardBitBtn: TBitBtn
            Left = 4
            Top = 180
            Width = 166
            Height = 50
            Margins.Left = 4
            Margins.Top = 4
            Margins.Right = 4
            Margins.Bottom = 4
            Caption = #1050#1088#1077#1076#1080#1090#1085#1086#1081' '#1082#1072#1088#1090#1086#1081
            DoubleBuffered = True
            ParentDoubleBuffered = False
            TabOrder = 3
            WordWrap = True
            OnClick = InputSumOsnCreditCardBitBtnClick
          end
        end
        object BitBtn16: TBitBtn
          Left = 4
          Top = 297
          Width = 166
          Height = 49
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1088#1086#1095#1077#1077
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 1
          WordWrap = True
        end
        object GroupBox1: TGroupBox
          Left = 5
          Top = 241
          Width = 165
          Height = 48
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1055#1088#1086#1095#1072#1103' '#1086#1087#1083#1072#1090#1072
          TabOrder = 2
        end
      end
      object Panel6: TPanel
        Left = 190
        Top = 89
        Width = 4
        Height = 369
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 5
        ExplicitHeight = 347
      end
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 637
    Width = 926
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
        Width = 100
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
  object Panel2: TPanel
    Left = 0
    Top = 490
    Width = 926
    Height = 147
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object Oper: TDBText
      Left = 17
      Top = 92
      Width = 46
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taCenter
      AutoSize = True
      DataField = 'OPERCHK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Prim: TLabel
      Left = 10
      Top = 125
      Width = 31
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BitBtn11: TBitBtn
      Left = 197
      Top = 78
      Width = 173
      Height = 50
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 0
      WordWrap = True
      OnClick = BitBtn11Click
    end
    object BitBtn14: TBitBtn
      Left = 378
      Top = 78
      Width = 172
      Height = 50
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1072#1085#1082#1086#1074#1089#1082#1086#1081' '#1082#1072#1088#1090#1086#1081
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 1
      WordWrap = True
      OnClick = BitBtn14Click
    end
    object PrintCheckBitBtn: TBitBtn
      Left = 556
      Top = 78
      Width = 172
      Height = 50
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1095#1072#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 2
      OnClick = PrintCheckBitBtnClick
    end
    object BitBtn17: TBitBtn
      Left = 736
      Top = 78
      Width = 172
      Height = 50
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 3
      OnClick = BitBtn17Click
    end
    object GroupBox5: TGroupBox
      Left = 12
      Top = 8
      Width = 179
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072
      TabOrder = 4
      object SumDocDBText: TDBText
        Left = 2
        Top = 18
        Width = 175
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Alignment = taRightJustify
        DataField = 'SUMDOC'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 174
        ExplicitHeight = 41
      end
    end
    object GroupBox7: TGroupBox
      Left = 736
      Top = 8
      Width = 172
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1076#1072#1095#1072
      TabOrder = 5
      object SdachaDBText: TDBText
        Left = 2
        Top = 18
        Width = 168
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Alignment = taRightJustify
        DataField = 'SDACHA_DCHK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ExplicitHeight = 41
      end
    end
    object GroupBox6: TGroupBox
      Left = 558
      Top = 8
      Width = 172
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1083#1072#1090#1072
      TabOrder = 6
      object AllOplDBText: TDBText
        Left = 2
        Top = 18
        Width = 168
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Alignment = taRightJustify
        DataField = 'ALLOPL'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ExplicitHeight = 41
      end
    end
    object GroupBox8: TGroupBox
      Left = 378
      Top = 8
      Width = 172
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1072#1085#1082'. '#1082#1072#1088#1090#1086#1081
      TabOrder = 7
      object OplataBankCardDBText: TDBText
        Left = 2
        Top = 18
        Width = 168
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Alignment = taRightJustify
        DataField = 'OPLPCCHK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ExplicitHeight = 41
      end
    end
    object GroupBox9: TGroupBox
      Left = 199
      Top = 8
      Width = 173
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080
      TabOrder = 8
      object NalChkDBText: TDBText
        Left = 2
        Top = 18
        Width = 169
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Alignment = taRightJustify
        DataField = 'NALCHK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 168
        ExplicitHeight = 41
      end
    end
  end
end
