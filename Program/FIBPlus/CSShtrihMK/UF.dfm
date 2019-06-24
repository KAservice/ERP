object F: TF
  Left = 322
  Top = 256
  Width = 641
  Height = 448
  Caption = #1050#1072#1089#1089#1086#1074#1099#1081' '#1089#1077#1088#1074#1077#1088' '#1064#1090#1088#1080#1093'-'#1052#1080#1085#1080'-'#1050
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 633
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object LabelNumberCheck: TLabel
      Left = 8
      Top = 80
      Width = 123
      Height = 24
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1095#1077#1082
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSostCheck: TLabel
      Left = 440
      Top = 80
      Width = 116
      Height = 24
      Caption = ' '#1063#1077#1082' '#1079#1072#1082#1088#1099#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText1: TDBText
      Left = 8
      Top = 48
      Width = 62
      Height = 20
      AutoSize = True
      DataField = 'NAMEFIRM'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 555
      Top = 48
      Width = 62
      Height = 20
      Alignment = taRightJustify
      AutoSize = True
      DataField = 'NAMESKLAD'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBText5: TDBText
      Left = 256
      Top = 80
      Width = 72
      Height = 24
      AutoSize = True
      DataField = 'OPERCHK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 633
      Height = 41
      ButtonHeight = 29
      ButtonWidth = 32
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      TabOrder = 0
      object DBText3: TDBText
        Left = 0
        Top = 2
        Width = 93
        Height = 29
        AutoSize = True
        DataField = 'NAMEKKM'
        DataSource = DMSprKKM.DataSourceElement
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 322
    Width = 633
    Height = 99
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelSummaNach: TLabel
      Left = 136
      Top = 33
      Width = 77
      Height = 24
      Caption = 'C'#1082#1080#1076#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clPurple
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelProcent: TLabel
      Left = 168
      Top = 9
      Width = 24
      Height = 24
      Caption = '-%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clPurple
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSoobshenie: TLabel
      Left = 0
      Top = 67
      Width = 633
      Height = 13
      Align = alBottom
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
    end
    object StatusBar: TStatusBar
      Left = 0
      Top = 80
      Width = 633
      Height = 19
      Panels = <
        item
          Width = 100
        end
        item
          Width = 50
        end>
      SimplePanel = False
    end
    object Panel5: TPanel
      Left = 400
      Top = 8
      Width = 225
      Height = 57
      BevelOuter = bvLowered
      TabOrder = 1
      object DBText4: TDBText
        Left = 8
        Top = 8
        Width = 217
        Height = 41
        Alignment = taCenter
        DataField = 'SUMDOC'
        DataSource = DMDocCheck.DataSourceDocAll
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -32
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 113
    Width = 9
    Height = 209
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 627
    Top = 113
    Width = 6
    Height = 209
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object PageControl1: TPageControl
    Left = 9
    Top = 113
    Width = 618
    Height = 209
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1095#1077#1082
      object DBGrid1: TDBGrid
        Left = 0
        Top = 0
        Width = 610
        Height = 181
        Align = alClient
        DataSource = DMDocCheck.DataSourceDocT
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
        Columns = <
          item
            Expanded = False
            FieldName = 'NAMENOM'
            Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            Width = 213
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'KOLCHKT'
            Title.Caption = #1050#1086#1083
            Width = 48
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'NAMEED'
            Title.Caption = #1045#1076'.'
            Width = 52
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'KFCHKT'
            Title.Caption = #1050#1060
            Width = 45
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'PRICECHKT'
            Title.Caption = #1062#1077#1085#1072
            Width = 74
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'SUMCHKT'
            Title.Caption = #1057#1091#1084#1084#1072
            Width = 72
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'SKCHKT'
            Title.Caption = #1057#1082#1080#1076#1082#1072
            Width = 55
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'NADCHKT'
            Title.Caption = #1053#1072#1076#1073#1072#1074#1082#1072
            Width = 60
            Visible = True
          end>
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1088#1086#1090#1086#1082#1086#1083
      ImageIndex = 1
      object RE: TRichEdit
        Left = 0
        Top = 0
        Width = 610
        Height = 181
        Align = alClient
        Lines.Strings = (
          'RE')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
