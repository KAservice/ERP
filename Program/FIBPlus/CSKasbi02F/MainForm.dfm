object MainForm: TMainForm
  Left = 254
  Top = 111
  Caption = #1050#1072#1089#1089#1086#1074#1099#1081' '#1089#1077#1088#1074#1077#1088' '#1050#1072#1089#1073#1080'-02'#1060
  ClientHeight = 353
  ClientWidth = 492
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 492
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 40
      Top = 32
      Width = 156
      Height = 24
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1095#1077#1082'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSostCheck: TLabel
      Left = 368
      Top = 32
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
    object LabelActiveKKM: TLabel
      Left = 8
      Top = 32
      Width = 25
      Height = 24
      Alignment = taRightJustify
      Caption = '    '
      Color = clRed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object NameFirm: TDBText
      Left = 8
      Top = 8
      Width = 63
      Height = 16
      AutoSize = True
      DataField = 'NAMEFIRM'
      DataSource = DMSprARM.DataSourceElement
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameSklad: TDBText
      Left = 410
      Top = 10
      Width = 72
      Height = 16
      Alignment = taRightJustify
      AutoSize = True
      DataField = 'NAMESKLAD'
      DataSource = DMSprARM.DataSourceElement
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object OperCHK: TDBText
      Left = 208
      Top = 8
      Width = 68
      Height = 20
      AutoSize = True
      DataField = 'OPERCHK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NumberDoc: TDBText
      Left = 200
      Top = 32
      Width = 103
      Height = 24
      AutoSize = True
      DataField = 'NUMDOC'
      DataSource = DMDocCheck.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 254
    Width = 492
    Height = 99
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Label3: TLabel
      Left = 256
      Top = 1
      Width = 70
      Height = 24
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 256
      Top = 28
      Width = 66
      Height = 24
      Caption = #1048#1090#1086#1075#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 1
      Width = 101
      Height = 16
      Caption = #1050#1086#1085#1090#1088'. '#1083#1077#1085#1090#1072' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelSoobshenie: TLabel
      Left = 0
      Top = 67
      Width = 54
      Height = 13
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
    end
    object SumFull: TDBText
      Left = 336
      Top = 0
      Width = 70
      Height = 24
      AutoSize = True
      DataField = 'SUMFULL'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumDoc: TDBText
      Left = 336
      Top = 30
      Width = 73
      Height = 24
      AutoSize = True
      DataField = 'SUMDOC'
      DataSource = DMDocCheck.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KlChk: TDBText
      Left = 120
      Top = 0
      Width = 34
      Height = 16
      AutoSize = True
      DataField = 'NKLCHK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object TDBText
      Left = 200
      Top = 88
      Width = 65
      Height = 17
    end
    object SummaSkidok: TDBText
      Left = 88
      Top = 24
      Width = 88
      Height = 16
      AutoSize = True
      DataField = 'SUMSKIDOK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SummaNadbavok: TDBText
      Left = 88
      Top = 40
      Width = 110
      Height = 16
      AutoSize = True
      DataField = 'SUMNADBAVOK'
      DataSource = DMDocCheck.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 8
      Top = 24
      Width = 50
      Height = 16
      Caption = #1057#1082#1080#1076#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 8
      Top = 40
      Width = 68
      Height = 16
      Caption = #1053#1072#1076#1073#1072#1074#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object StatusBar: TStatusBar
      Left = 0
      Top = 80
      Width = 492
      Height = 19
      Panels = <
        item
          Width = 100
        end
        item
          Width = 50
        end>
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 65
    Width = 9
    Height = 189
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 486
    Top = 65
    Width = 6
    Height = 189
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object PageControl1: TPageControl
    Left = 9
    Top = 65
    Width = 477
    Height = 189
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1095#1077#1082
      object DBGrid1: TDBGrid
        Left = 0
        Top = 0
        Width = 469
        Height = 161
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
            FieldName = 'RECNO'
            Title.Caption = #8470
            Width = 27
            Visible = True
          end
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
            Title.Caption = #1050#1086#1083'.'
            Width = 52
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'NAMEED'
            Title.Caption = #1045#1076'.'
            Width = 54
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
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object RE: TRichEdit
        Left = 0
        Top = 0
        Width = 469
        Height = 161
        Align = alClient
        Lines.Strings = (
          'RE')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
