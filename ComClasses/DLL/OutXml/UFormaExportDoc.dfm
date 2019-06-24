object FormaExportDoc: TFormaExportDoc
  Left = 0
  Top = 0
  Caption = #1069#1082#1089#1087#1086#1088#1090' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
  ClientHeight = 394
  ClientWidth = 764
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 264
    Height = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1069#1082#1089#1087#1086#1088#1090' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 524
    Top = 10
    Width = 29
    Height = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 72
    Top = 73
    Width = 108
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072':'
  end
  object Label7: TLabel
    Left = 10
    Top = 230
    Width = 239
    Height = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1084#1087#1086#1088#1090' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 162
    Top = 293
    Width = 38
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1072#1081#1083':'
  end
  object NachcxDateEdit: TcxDateEdit
    Left = 332
    Top = 13
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 158
  end
  object ConcxDateEdit: TcxDateEdit
    Left = 588
    Top = 13
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 159
  end
  object PatchcxButtonEdit: TcxButtonEdit
    Left = 218
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = PatchcxButtonEditPropertiesButtonClick
    TabOrder = 2
    Text = 'PatchcxButtonEdit'
    Width = 452
  end
  object PoDatecxCheckBox: TcxCheckBox
    Left = 218
    Top = 126
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086' '#1076#1072#1090#1072#1084
    TabOrder = 3
    Width = 159
  end
  object ExportAllDoccxButton: TcxButton
    Left = 458
    Top = 171
    Width = 166
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
    TabOrder = 4
    OnClick = ExportAllDoccxButtonClick
  end
  object SprcxButton: TcxButton
    Left = 271
    Top = 171
    Width = 163
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
    TabOrder = 5
    OnClick = SprcxButtonClick
  end
  object cxButtonClose: TcxButton
    Left = 649
    Top = 343
    Width = 98
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 6
    OnClick = cxButtonCloseClick
  end
  object FileNamecxButtonEdit: TcxButtonEdit
    Left = 218
    Top = 289
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = FileNamecxButtonEditPropertiesButtonClick
    TabOrder = 7
    Text = 'FileNamecxButtonEdit'
    Width = 452
  end
  object cxButtonImport: TcxButton
    Left = 458
    Top = 343
    Width = 166
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1084#1087#1086#1088#1090
    TabOrder = 8
    OnClick = cxButtonImportClick
  end
  object SaveDialog1: TSaveDialog
    FileName = 'report.xml'
    Left = 240
    Top = 88
  end
  object OpenDialog1: TOpenDialog
    Left = 248
    Top = 240
  end
end
