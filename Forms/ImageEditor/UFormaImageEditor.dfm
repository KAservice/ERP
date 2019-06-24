object FormaImageEditor: TFormaImageEditor
  Left = 0
  Top = 0
  Caption = 'FormaImageEditor'
  ClientHeight = 370
  ClientWidth = 699
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 699
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 296
    Width = 699
    Height = 74
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
  end
  object cxImage1: TcxImage
    Left = 0
    Top = 65
    Align = alClient
    Properties.GraphicClassName = 'TJPEGImage'
    TabOrder = 2
    ExplicitTop = 59
    Height = 231
    Width = 699
  end
end
