object FormaViborSprStrObject: TFormaViborSprStrObject
  Left = 531
  Top = 18
  Width = 452
  Height = 576
  Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 444
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 16
      Width = 385
      Height = 29
      Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072' '#1086#1073#1098#1077#1082#1090#1086#1074' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 9
    Height = 448
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 505
    Width = 444
    Height = 37
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object ButtonClose: TButton
      Left = 360
      Top = 8
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
  end
  object Panel4: TPanel
    Left = 440
    Top = 57
    Width = 4
    Height = 448
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object TreeView1: TTreeView
    Left = 9
    Top = 57
    Width = 431
    Height = 448
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Indent = 19
    ParentFont = False
    SortType = stText
    TabOrder = 4
    OnCustomDrawItem = TreeView1CustomDrawItem
    OnDblClick = TreeView1DblClick
  end
end
