object Kalkulator: TKalkulator
  Left = 137
  Top = 165
  BorderStyle = bsDialog
  Caption = 'Kalkulator'
  ClientHeight = 261
  ClientWidth = 264
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
  DesignSize = (
    264
    261)
  PixelsPerInch = 96
  TextHeight = 13
  object kn1: TBitBtn
    Left = 8
    Top = 72
    Width = 60
    Height = 60
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = kn1Click
  end
  object Tablo: TEdit
    Left = 76
    Top = 17
    Width = 178
    Height = 37
    Anchors = []
    BiDiMode = bdLeftToRight
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 1
    Text = '0.00'
  end
  object kn2: TBitBtn
    Left = 72
    Top = 72
    Width = 60
    Height = 60
    Caption = '2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = kn2Click
  end
  object kn3: TBitBtn
    Left = 136
    Top = 72
    Width = 60
    Height = 60
    Caption = '3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = kn3Click
  end
  object kn4: TBitBtn
    Left = 8
    Top = 136
    Width = 60
    Height = 60
    Caption = '4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = kn4Click
  end
  object kn9: TBitBtn
    Left = 136
    Top = 200
    Width = 60
    Height = 60
    Caption = '9'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = kn9Click
  end
  object kn5: TBitBtn
    Left = 72
    Top = 136
    Width = 60
    Height = 60
    Caption = '5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = kn5Click
  end
  object kn6: TBitBtn
    Left = 136
    Top = 136
    Width = 60
    Height = 60
    Caption = '6'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = kn6Click
  end
  object kn7: TBitBtn
    Left = 8
    Top = 200
    Width = 60
    Height = 60
    Caption = '7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = kn7Click
  end
  object kn8: TBitBtn
    Left = 72
    Top = 200
    Width = 60
    Height = 60
    Caption = '8'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = kn8Click
  end
  object kn0: TBitBtn
    Left = 200
    Top = 72
    Width = 60
    Height = 60
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    OnClick = kn0Click
  end
  object knComma: TBitBtn
    Left = 200
    Top = 136
    Width = 60
    Height = 60
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 11
    OnClick = knCommaClick
  end
  object knOK: TBitBtn
    Left = 200
    Top = 200
    Width = 60
    Height = 60
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 12
    OnClick = knOKClick
  end
  object knC: TBitBtn
    Left = 8
    Top = 8
    Width = 60
    Height = 60
    Caption = 'C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 13
    OnClick = knCClick
  end
end
