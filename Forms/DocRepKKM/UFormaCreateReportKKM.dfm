object FormaCreateReportKKM: TFormaCreateReportKKM
  Left = 279
  Top = 176
  Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1090#1095#1077#1090' '#1050#1050#1052
  ClientHeight = 266
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label12: TLabel
    Left = 27
    Top = 50
    Width = 64
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1088#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label15: TLabel
    Left = 37
    Top = 132
    Width = 35
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1050#1052':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 145
    Top = 165
    Width = 66
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1050#1051':'
  end
  object Label13: TLabel
    Left = 27
    Top = 90
    Width = 60
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1083#1072#1076':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 49
    Top = 20
    Width = 60
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1077#1088#1080#1086#1076' '#1089
  end
  object Label2: TLabel
    Left = 246
    Top = 20
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
  end
  object DateTimePicker1: TcxDateEdit
    Left = 119
    Top = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
    Width = 120
  end
  object DateTimePicker2: TcxDateEdit
    Left = 268
    Top = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 1
    Width = 117
  end
  object EditFirm: TcxButtonEdit
    Left = 118
    Top = 49
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = EditFirmPropertiesButtonClick
    TabOrder = 2
    Text = 'EditFirm'
    Width = 267
  end
  object EditSklad: TcxButtonEdit
    Left = 118
    Top = 89
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = EditSkladPropertiesButtonClick
    TabOrder = 3
    Text = 'EditSklad'
    Width = 267
  end
  object EditKKM: TcxButtonEdit
    Left = 118
    Top = 128
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = EditKKMPropertiesButtonClick
    TabOrder = 4
    Text = 'EditKKM'
    Width = 267
  end
  object NumberKlEdit: TcxTextEdit
    Left = 236
    Top = 161
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 5
    Text = 'NumberKlEdit'
    Width = 149
  end
  object cxButtonCreate: TcxButton
    Left = 158
    Top = 217
    Width = 103
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 6
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 295
    Top = 217
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 7
    OnClick = cxButtonCloseClick
  end
  object ActionList: TActionList
    Left = 182
    Top = 72
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
