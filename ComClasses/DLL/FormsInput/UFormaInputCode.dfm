object FormaInputCode: TFormaInputCode
  Left = 252
  Top = 95
  Caption = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1076' '#1090#1086#1074#1072#1088#1072
  ClientHeight = 123
  ClientWidth = 373
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 39
    Width = 77
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1090#1086#1074#1072#1088#1072':'
  end
  object NameSprLabel: TLabel
    Left = 10
    Top = 10
    Width = 119
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'NameSprLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 207
    Top = 39
    Width = 84
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' :'
  end
  object CodeEdit: TcxTextEdit
    Left = 10
    Top = 63
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -23
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = [fsBold]
    Style.IsFontAssigned = True
    TabOrder = 0
    Text = 'CodeEdit'
    OnKeyPress = CodeEditKeyPress
    Width = 149
  end
  object KolEdit: TcxCalcEdit
    Left = 207
    Top = 63
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    EditValue = 0.000000000000000000
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -23
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = [fsBold]
    Style.IsFontAssigned = True
    TabOrder = 1
    OnKeyPress = KolEditKeyPress
    Width = 149
  end
end
