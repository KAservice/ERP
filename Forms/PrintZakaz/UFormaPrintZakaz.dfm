object FormaPrintZakaz: TFormaPrintZakaz
  Left = 404
  Top = 323
  Caption = 'FormaPrintZakaz'
  ClientHeight = 85
  ClientWidth = 327
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
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 64
    Width = 84
    Height = 13
    Caption = #1055#1077#1095#1072#1090#1100' '#1079#1072#1082#1072#1079#1072'...'
  end
  object IPLabel: TLabel
    Left = 72
    Top = 16
    Width = 36
    Height = 13
    Caption = 'IPLabel'
  end
  object PortLabel: TLabel
    Left = 72
    Top = 40
    Width = 45
    Height = 13
    Caption = 'PortLabel'
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 16
    Top = 8
  end
  object Timer1: TTimer
    Interval = 15000
    OnTimer = Timer1Timer
    Left = 216
    Top = 16
  end
end
