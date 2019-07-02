object F1: TF1
  Left = 248
  Top = 249
  Anchors = [akTop]
  Caption = #1054#1089#1085#1086#1074#1085#1086#1081' '#1084#1086#1076#1091#1083#1100':'
  ClientHeight = 437
  ClientWidth = 824
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  WindowMenu = Windows
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object StatusBar: TStatusBar
    Left = 0
    Top = 418
    Width = 824
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
    Width = 824
    Height = 30
    ButtonHeight = 23
    Caption = 'ToolBar1'
    EdgeBorders = [ebTop, ebBottom]
    Images = ImageListToolBar
    TabOrder = 1
    Transparent = False
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 40
    object Help: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      GroupIndex = 15
      object MainMenuAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        ShortCut = 16497
        OnClick = MainMenuAboutClick
      end
      object MainMenuHelp: TMenuItem
        Caption = #1057#1086#1076#1077#1088#1078#1072#1085#1080#1077
        ShortCut = 112
        OnClick = MainMenuHelpClick
      end
    end
    object Windows: TMenuItem
      Caption = #1054#1082#1085#1072
      GroupIndex = 16
      object Window: TMenuItem
      end
    end
  end
  object ImageListToolBar: TImageList
    Left = 120
    Top = 40
  end
  object ActionList1: TActionList
    Left = 336
    Top = 168
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionShowMessageOnClose: TAction
      Caption = 'ActionShowMessageOnClose'
      ShortCut = 32856
      OnExecute = ActionShowMessageOnCloseExecute
    end
  end
end
