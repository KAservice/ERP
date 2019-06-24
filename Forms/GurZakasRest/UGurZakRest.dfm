object FormaGurZakRest: TFormaGurZakRest
  Left = 270
  Top = 120
  Width = 696
  Height = 480
  Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1082#1072#1079#1086#1074':'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 688
    Height = 81
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 40
      Width = 244
      Height = 36
      Caption = #1046#1091#1088#1085#1072#1083' '#1079#1072#1082#1072#1079#1086#1074':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 81
    Width = 9
    Height = 279
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 680
    Top = 81
    Width = 8
    Height = 279
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 0
    Top = 360
    Width = 688
    Height = 93
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 3
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 81
    Width = 671
    Height = 279
    Align = alClient
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
end
