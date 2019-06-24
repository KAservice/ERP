object FormaCheckKKMkPKO: TFormaCheckKKMkPKO
  Left = 293
  Top = 142
  Width = 321
  Height = 519
  Caption = #1063#1077#1082' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1086#1081' '#1084#1072#1096#1080#1085#1099
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
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 289
    Height = 465
    BevelOuter = bvLowered
    TabOrder = 0
    object UchLabel: TLabel
      Left = 8
      Top = 112
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
    object Prim: TLabel
      Left = 8
      Top = 8
      Width = 273
      Height = 49
      Alignment = taCenter
      AutoSize = False
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object SumCheckLabel: TLabel
      Left = 127
      Top = 384
      Width = 153
      Height = 24
      Alignment = taRightJustify
      Caption = 'SumCheckLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKKMLabel: TLabel
      Left = 8
      Top = 88
      Width = 150
      Height = 24
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 8
      Top = 152
      Width = 273
      Height = 225
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'Memo11111111111111111111111111111111')
      ParentFont = False
      TabOrder = 0
    end
    object ButtonPrintCheck: TButton
      Left = 128
      Top = 432
      Width = 75
      Height = 25
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 1
      OnClick = ButtonPrintCheckClick
    end
    object ButtonClose: TButton
      Left = 208
      Top = 432
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 2
      OnClick = ButtonCloseClick
    end
  end
end
