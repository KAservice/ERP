object FormaReportTouchForFR: TFormaReportTouchForFR
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1077#1090#1099
  ClientHeight = 285
  ClientWidth = 519
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 202
    Height = 29
    Caption = #1054#1090#1095#1077#1090#1099' '#1079#1072' '#1087#1077#1088#1080#1086#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 61
    Width = 11
    Height = 29
    Caption = #1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 241
    Top = 61
    Width = 27
    Height = 29
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object PosNachcxDateEdit: TcxDateEdit
    Left = 41
    Top = 69
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 177
  end
  object PosConcxDateEdit: TcxDateEdit
    Left = 288
    Top = 69
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 177
  end
  object BitBtnReport: TBitBtn
    Left = 184
    Top = 200
    Width = 140
    Height = 40
    Caption = #1054#1090#1095#1077#1090
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 2
    OnClick = BitBtnReportClick
  end
  object ButtonClose: TButton
    Left = 330
    Top = 200
    Width = 140
    Height = 40
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
  end
end
