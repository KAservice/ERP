object FormaPrintExternalReport: TFormaPrintExternalReport
  Left = 312
  Top = 194
  Caption = #1055#1077#1095#1072#1090#1100
  ClientHeight = 114
  ClientWidth = 330
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 89
    Width = 250
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1082#1088#1099#1090#1080#1077' '#1074#1085#1077#1096#1085#1077#1081' '#1087#1077#1095#1072#1090#1085#1086#1081' '#1092#1086#1088#1084#1099'....'
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 80
    Top = 16
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 120
    Top = 16
  end
end
