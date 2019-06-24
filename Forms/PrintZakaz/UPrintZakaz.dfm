object FormaPrintZakaz: TFormaPrintZakaz
  Left = 404
  Top = 323
  Width = 335
  Height = 112
  Caption = 'FormaPrintZakaz'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 64
    Width = 84
    Height = 13
    Caption = #1055#1077#1095#1072#1090#1100' '#1079#1072#1082#1072#1079#1072'...'
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    Left = 16
    Top = 8
  end
end
