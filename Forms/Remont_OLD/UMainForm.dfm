object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1057#1077#1088#1074#1080#1089#1085#1099#1081' '#1094#1077#1085#1090#1088
  ClientHeight = 213
  ClientWidth = 339
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  WindowMenu = WindowsAll
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 194
    Width = 339
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 50
      end
      item
        Width = 200
      end
      item
        Width = 50
      end
      item
        Width = 50
      end>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 339
    Height = 29
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    Left = 200
    Top = 48
    object N3: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082
      object OpenSprNeispr: TMenuItem
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1077#1081
        OnClick = OpenSprNeisprClick
      end
      object OpenSprModel: TMenuItem
        Caption = #1052#1086#1076#1077#1083#1077#1081
        OnClick = OpenSprModelClick
      end
      object OpenSprSost: TMenuItem
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1081
        OnClick = OpenSprSostClick
      end
      object OpenSprTRemont: TMenuItem
        Caption = #1058#1080#1087#1086#1074' '#1088#1077#1084#1086#1085#1090#1072
        OnClick = OpenSprTRemontClick
      end
    end
    object N8: TMenuItem
      Caption = #1046#1091#1088#1085#1072#1083
      object OpenGurnalZ: TMenuItem
        Caption = #1047#1072#1103#1074#1082#1080' '#1085#1072' '#1088#1077#1084#1086#1085#1090
        OnClick = OpenGurnalZClick
      end
    end
    object WindowsAll: TMenuItem
      Caption = #1054#1082#1085#1072
      object Windows: TMenuItem
      end
    end
    object N1: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object OpenFormAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = OpenFormAboutClick
      end
    end
  end
end
