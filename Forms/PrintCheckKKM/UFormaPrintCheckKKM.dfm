object FormaPrintCheckKKM: TFormaPrintCheckKKM
  Left = 594
  Top = 187
  Caption = #1063#1077#1082' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1086#1081' '#1084#1072#1096#1080#1085#1099
  ClientHeight = 591
  ClientWidth = 473
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 108
    Top = 0
    Width = 356
    Height = 553
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    BevelOuter = bvLowered
    TabOrder = 0
    object UchLabel: TLabel
      Left = 20
      Top = 69
      Width = 101
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'UchLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Prim: TLabel
      Left = 10
      Top = 10
      Width = 336
      Height = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taCenter
      AutoSize = False
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object NameKKMLabel: TLabel
      Left = 20
      Top = 98
      Width = 167
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 20
      Top = 286
      Width = 44
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1090#1076#1077#1083':'
    end
    object Label2: TLabel
      Left = 98
      Top = 315
      Width = 74
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 59
      Top = 384
      Width = 124
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 39
      Top = 443
      Width = 138
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 20
      Top = 138
      Width = 316
      Height = 109
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'Memo11111111111111111111111111111'
        '1'
        '11')
      ParentFont = False
      TabOrder = 0
    end
    object ButtonPrintCheck: TButton
      Left = 128
      Top = 502
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 1
      OnClick = ButtonPrintCheckClick
    end
    object ButtonClose: TButton
      Left = 236
      Top = 502
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 2
      OnClick = ButtonCloseClick
    end
    object SumCheckEdit: TEdit
      Left = 197
      Top = 305
      Width = 139
      Height = 40
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = 'SumCheckEdit'
    end
    object OtdelEdit: TEdit
      Left = 20
      Top = 305
      Width = 50
      Height = 40
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = '1'
    end
    object ComboBox: TComboBox
      Left = 108
      Top = 266
      Width = 228
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 5
      Text = 'ComboBox'
      Items.Strings = (
        #1055#1088#1086#1076#1072#1078#1072
        #1042#1086#1079#1074#1088#1072#1090)
    end
    object NalEdit: TEdit
      Left = 197
      Top = 374
      Width = 139
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      Text = 'NalEdit'
    end
    object PlatCardEdit: TEdit
      Left = 197
      Top = 433
      Width = 139
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      Text = 'PlatCardEdit'
    end
  end
  object BitBtnOtdel: TBitBtn
    Left = 10
    Top = 0
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1076#1077#1083
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 1
    OnClick = BitBtnOtdelClick
  end
  object BitBtnSumma: TBitBtn
    Left = 10
    Top = 69
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1091#1084#1084#1072
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 2
    OnClick = BitBtnSummaClick
  end
  object BitBtnSale: TBitBtn
    Left = 10
    Top = 138
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1086#1076#1072#1078#1072
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 3
    OnClick = BitBtnSaleClick
  end
  object BitBtnReturnSale: TBitBtn
    Left = 10
    Top = 207
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1086#1079#1074#1088#1072#1090
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 4
    OnClick = BitBtnReturnSaleClick
  end
  object BitBtnNal: TBitBtn
    Left = 10
    Top = 276
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 5
    OnClick = BitBtnNalClick
  end
  object BitBtnPlatCard: TBitBtn
    Left = 10
    Top = 345
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 6
    OnClick = BitBtnPlatCardClick
  end
  object BitBtnPrint: TBitBtn
    Left = 10
    Top = 414
    Width = 92
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1077#1095#1072#1090#1100
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 7
    OnClick = BitBtnPrintClick
  end
  object BitBtnClose: TBitBtn
    Left = 10
    Top = 482
    Width = 92
    Height = 71
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 8
    OnClick = BitBtnCloseClick
  end
  object MainMenu1: TMainMenu
    Left = 8
    object N1: TMenuItem
      Caption = #1050#1050#1052
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
  end
end
