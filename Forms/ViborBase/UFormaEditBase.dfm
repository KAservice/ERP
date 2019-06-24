object FormaEditBase: TFormaEditBase
  Left = 324
  Top = 298
  BorderIcons = [biHelp]
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1086#1081' '#1073#1072#1079#1099
  ClientHeight = 178
  ClientWidth = 460
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 282
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1073#1072#1079#1099' '#1074' '#1089#1087#1080#1089#1082#1077' '#1080#1085#1092#1086#1088#1084'. '#1073#1072#1079':'
  end
  object Label2: TLabel
    Left = 10
    Top = 65
    Width = 138
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103
  end
  object Label3: TLabel
    Left = 10
    Top = 127
    Width = 275
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1040#1056#1052' '#1089' '#1085#1072#1089#1090#1088#1086#1081#1082#1072#1084#1080' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103':'
  end
  object cxButtonOK: TcxButton
    Left = 359
    Top = 59
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 3
  end
  object cxButtonCancel: TcxButton
    Left = 358
    Top = 112
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 4
  end
  object NumberARM: TcxTextEdit
    Left = 283
    Top = 121
    Hint = #1053#1086#1084#1077#1088' '#1040#1056#1052#1072' '#1089' '#1085#1072#1089#1090#1088#1086#1081#1082#1072#1084#1080' '#1087#1086#1076#1082#1083#1102#1095#1072#1077#1084#1086#1075#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    Text = 'NumberARM'
    OnKeyDown = NumberARMKeyDown
    Width = 53
  end
  object ConnectString: TcxTextEdit
    Left = 10
    Top = 85
    Hint = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103' '#1082' SQL '#1089#1077#1088#1074#1077#1088#1091' Firebird'
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    Text = 'ConnectString'
    OnKeyDown = ConnectStringKeyDown
    Width = 326
  end
  object NameBase: TcxTextEdit
    Left = 10
    Top = 33
    Hint = #1053#1072#1079#1074#1072#1085#1080#1077' '#1074' '#1089#1087#1080#1089#1082#1077' '#1074#1099#1073#1086#1088#1072' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1099#1093' '#1073#1072#1079
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'NameBase'
    OnKeyDown = NameBaseKeyDown
    Width = 326
  end
  object ActionList: TActionList
    Images = FormaViborBase.ImageList1
    Left = 336
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1054#1090#1084#1077#1085#1072
      ImageIndex = 0
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 1
      OnExecute = ActionOKExecute
    end
  end
end
