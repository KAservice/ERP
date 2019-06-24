object FormaElementaSprCatNom: TFormaElementaSprCatNom
  Left = 363
  Top = 49
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1072#1090#1077#1075#1086#1088#1080#1080' '#1085#1086#1084#1077#1088#1086#1074'"'
  ClientHeight = 148
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 20
    Top = 30
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    FocusControl = NameCatNom
  end
  object Label2: TLabel
    Left = 286
    Top = 108
    Width = 141
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1086#1084#1077#1088#1086#1074':'
    FocusControl = KolCatNom
  end
  object Label11: TLabel
    Left = 20
    Top = 69
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object NameCatNom: TDBEdit
    Left = 128
    Top = 20
    Width = 425
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'NAME_CATNOM'
    DataSource = DMSprCatNom.DataSourceElement
    TabOrder = 0
  end
  object KolCatNom: TDBEdit
    Left = 423
    Top = 98
    Width = 120
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'KOL_CATNOM'
    DataSource = DMSprCatNom.DataSourceElement
    TabOrder = 1
  end
  object ButtonClose: TButton
    Left = 463
    Top = 148
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 2
    OnClick = ButtonCloseClick
  end
  object ButtonOK: TButton
    Left = 354
    Top = 148
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'OK'
    TabOrder = 3
    OnClick = ButtonOKClick
  end
  object NameNom: TDBEdit
    Left = 128
    Top = 59
    Width = 395
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Color = clBtnFace
    DataField = 'NAMENOM'
    DataSource = DMSprCatNom.DataSourceElement
    ReadOnly = True
    TabOrder = 4
  end
  object ButtonVoborNom: TButton
    Left = 517
    Top = 59
    Width = 26
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonVoborNomClick
  end
end
