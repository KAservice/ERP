object Forma_ZakazOf: TForma_ZakazOf
  Left = 143
  Top = 131
  Width = 779
  Height = 590
  Caption = #1047#1072#1082#1072#1079
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 440
    Width = 771
    Height = 96
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
    object KrNameNomDBText: TDBText
      Left = 576
      Top = 16
      Width = 177
      Height = 13
      DataField = 'KRNAMENOM'
    end
    object Label2: TLabel
      Left = 8
      Top = 13
      Width = 114
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1087#1088#1080#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103':'
    end
    object MPrigDBText: TDBText
      Left = 128
      Top = 8
      Width = 281
      Height = 17
      DataField = 'NAME_MPRIG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 464
      Top = 16
      Width = 96
      Height = 13
      Caption = #1050#1088'. '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    end
    object NameUserDBText: TDBText
      Left = 104
      Top = 48
      Width = 144
      Height = 20
      AutoSize = True
      DataField = 'NAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 8
      Top = 48
      Width = 95
      Height = 20
      Caption = #1054#1092#1080#1094#1080#1072#1085#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 488
      Top = 48
      Width = 221
      Height = 24
      Caption = '<<'#1058#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088'>>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StatusBar: TStatusBar
      Left = 1
      Top = 76
      Width = 769
      Height = 19
      Panels = <
        item
          Text = #1050#1050#1052
          Width = 150
        end
        item
          Text = #1058#1080#1087' '#1094#1077#1085
          Width = 150
        end>
      SimplePanel = False
    end
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 137
    Width = 771
    Height = 303
    Align = alClient
    DataSource = DMRegZak.DataSourceDocT
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgConfirmDelete]
    ParentFont = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        ReadOnly = True
        Title.Caption = #8470
        Width = 23
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOLPR_ZAKT'
        Title.Caption = #1055#1077#1095'.'
        Width = 30
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMENOM'
        ReadOnly = True
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 289
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOLZ_ZAKT'
        Title.Caption = #1047#1072#1082'.'
        Width = 41
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOLOT_ZAKT'
        Title.Caption = #1042#1099#1087'.'
        Width = 39
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMEED'
        ReadOnly = True
        Title.Caption = #1045#1076#1080#1085#1080#1094#1072
        Width = 84
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KF_ZAKT'
        ReadOnly = True
        Title.Caption = 'K'
        Width = 63
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PRICE_ZAKT'
        ReadOnly = True
        Title.Caption = #1062#1077#1085#1072
        Width = 68
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUM_ZAKT'
        ReadOnly = True
        Title.Caption = #1057#1091#1084#1084#1072
        Width = 86
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 771
    Height = 137
    Align = alTop
    Anchors = []
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 2
    object Label1: TLabel
      Left = 216
      Top = 32
      Width = 136
      Height = 37
      Caption = #1047#1072#1082#1072#1079' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -32
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 5
      Width = 68
      Height = 20
      Caption = #1050#1083#1080#1077#1085#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKlientDBText: TDBText
      Left = 80
      Top = 5
      Width = 151
      Height = 20
      AutoSize = True
      DataField = 'NAMEKLIENT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object IDZakDBText: TDBText
      Left = 368
      Top = 33
      Width = 202
      Height = 37
      AutoSize = True
      DataField = 'ID_ZAK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameStrObDBText: TDBText
      Left = 8
      Top = 95
      Width = 441
      Height = 33
      DataField = 'NAME_STROB'
      DataSource = DMRegZak.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox1: TGroupBox
      Left = 616
      Top = 80
      Width = 153
      Height = 49
      Caption = #1057#1091#1084#1084#1072':'
      TabOrder = 0
      object SumDoc: TDBText
        Left = 6
        Top = 12
        Width = 139
        Height = 33
        Alignment = taCenter
        DataField = 'SUM_ZAK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object GroupBox2: TGroupBox
      Left = 464
      Top = 80
      Width = 145
      Height = 50
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
      TabOrder = 1
      object SostZakaz: TLabel
        Left = 8
        Top = 18
        Width = 129
        Height = 24
        Alignment = taCenter
        AutoSize = False
        Caption = 'SostZakaz'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object MainMenu: TMainMenu
    Left = 8
    Top = 40
    object N22: TMenuItem
      Caption = #1054#1073#1098#1077#1082#1090
      object N23: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100
        OnClick = N23Click
      end
      object N24: TMenuItem
        Caption = #1053#1072#1080#1090#1080' '#1087#1086' '#1082#1086#1076#1091
        ShortCut = 112
        OnClick = N24Click
      end
    end
    object N20: TMenuItem
      Caption = #1050#1083#1080#1077#1085#1090
      object N21: TMenuItem
        Caption = #1053#1072#1081#1090#1080' '#1087#1086' '#1082#1086#1076#1091
        ShortCut = 113
        OnClick = N21Click
      end
    end
    object N1: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      object N2: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091' '#1041#1042
        ShortCut = 116
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091
        ShortCut = 117
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1041#1042
        ShortCut = 118
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        ShortCut = 119
        OnClick = N5Click
      end
    end
    object N6: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1103
      object N7: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1077#1076#1080#1085#1080#1094#1091
        ShortCut = 16474
        OnClick = N7Click
      end
      object N18: TMenuItem
        Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1086
        ShortCut = 16472
      end
      object N19: TMenuItem
        Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1086' '#1074#1089#1077
        ShortCut = 16451
        OnClick = N19Click
      end
      object N8: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        ShortCut = 46
        OnClick = N8Click
      end
      object N15: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1079#1072#1082#1072#1079
        OnClick = N15Click
      end
    end
    object N9: TMenuItem
      Caption = #1055#1077#1095#1072#1090#1100
      object N16: TMenuItem
        Caption = #1047#1072#1082#1072#1079
        ShortCut = 120
        OnClick = N16Click
      end
      object N11: TMenuItem
        Caption = #1057#1095#1077#1090
        ShortCut = 16504
        OnClick = N11Click
      end
      object N10: TMenuItem
        Caption = #1047#1072#1082#1072#1079' '#1085#1072' '#1082#1091#1093#1085#1077
        ShortCut = 121
        OnClick = N10Click
      end
      object N12: TMenuItem
        Caption = #1057#1095#1077#1090' '#1085#1072' '#1060#1056
        ShortCut = 122
        OnClick = N12Click
      end
      object N13: TMenuItem
        Caption = #1063#1077#1082' '#1050#1050#1052
        ShortCut = 123
        OnClick = N13Click
      end
      object N14: TMenuItem
        Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
        ShortCut = 16507
        OnClick = N14Click
      end
    end
    object N17: TMenuItem
      Caption = #1047#1072#1082#1088#1099#1090#1100
      OnClick = N17Click
    end
  end
end
