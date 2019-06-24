object FormaSpiskaSprInfBaseVibor: TFormaSpiskaSprInfBaseVibor
  Left = 312
  Top = 123
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1099#1077' '#1073#1072#1079#1099'"'
  ClientHeight = 421
  ClientWidth = 566
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 566
    Height = 25
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object HintLabel: TLabel
      Left = 8
      Top = 4
      Width = 44
      Height = 16
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 25
    Width = 9
    Height = 334
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    ExplicitHeight = 327
  end
  object Panel3: TPanel
    Left = 552
    Top = 25
    Width = 14
    Height = 334
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    ExplicitHeight = 327
  end
  object Panel4: TPanel
    Left = 0
    Top = 359
    Width = 566
    Height = 62
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    ExplicitTop = 352
    object ButtonClose: TButton
      Left = 432
      Top = 16
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 25
    Width = 543
    Height = 334
    Align = alClient
    DataSource = DMSprInfBase.DataSourceTable
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        Title.Caption = #8470
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PREFIKS_SINFBASE_OBMEN'
        Title.Caption = #1055#1088#1077#1092#1080#1082#1089':'
        Width = 138
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME_SINFBASE_OBMEN'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
        Visible = True
      end>
  end
end
