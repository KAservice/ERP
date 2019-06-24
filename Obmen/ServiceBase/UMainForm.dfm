object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 641
  ClientWidth = 991
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object StatusBar: TStatusBar
    Left = 0
    Top = 622
    Width = 991
    Height = 19
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 991
    Height = 43
    ButtonHeight = 39
    ButtonWidth = 39
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Images = DataModuleMain.ImageList1
    TabOrder = 1
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Action = ActionOpenFormCreateNewBase
    end
  end
  object MainMenu1: TMainMenu
    Left = 368
    Top = 48
    object N7: TMenuItem
      Caption = #1055#1077#1088#1077#1085#1086#1089' '#1076#1072#1085#1085#1099#1093
      object CreateNewBase: TMenuItem
        Action = ActionOpenFormCreateNewBase
      end
    end
    object N3: TMenuItem
      Caption = #1051#1086#1075#1075#1080#1088#1086#1074#1072#1085#1080#1077
      object N4: TMenuItem
        Action = ActionOpenFormCreateLog
      end
    end
    object N5: TMenuItem
      Caption = #1058#1072#1073#1083#1080#1094#1099
      object N6: TMenuItem
        Caption = #1055#1086#1076#1075'. '#1076#1072#1085#1085#1099#1077
        OnClick = N6Click
      end
      object OpenTableIsmMainMenu: TMenuItem
        Caption = #1058#1072#1073#1083#1080#1094#1072' '#1080#1079#1084#1077#1085#1077#1085#1080#1081
        OnClick = OpenTableIsmMainMenuClick
      end
      object OpenFormaXTablebaseMainMenu: TMenuItem
        Action = ActionOpenFormaXTableBase
      end
    end
    object N8: TMenuItem
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      object SetGeneratorsMainMenu: TMenuItem
        Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1086#1074
        OnClick = SetGeneratorsMainMenuClick
      end
      object GreateServDoc: TMenuItem
        Caption = #1057#1077#1088#1074#1080#1089#1085#1099#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        OnClick = GreateServDocClick
      end
    end
    object N1: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N2: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      end
    end
  end
  object ActionList1: TActionList
    Images = DataModuleMain.ImageList1
    Left = 416
    Top = 184
    object ActionOpenFormCreateNewBase: TAction
      Caption = #1055#1077#1088#1077#1085#1086#1089' '#1076#1072#1085#1085#1099#1093' '#1074' '#1087#1086#1076#1095#1080#1085#1077#1085#1085#1091#1102' '#1073#1072#1079#1091
      Hint = #1055#1077#1088#1077#1085#1086#1089' '#1076#1072#1085#1085#1099#1093' '#1074' '#1087#1086#1076#1095#1080#1085#1077#1085#1085#1091#1102' '#1073#1072#1079#1091
      ImageIndex = 0
      OnExecute = ActionOpenFormCreateNewBaseExecute
    end
    object ActionOpenFormCreateLog: TAction
      Caption = #1058#1088#1080#1075#1075#1077#1088#1099
      OnExecute = ActionOpenFormCreateLogExecute
    end
    object ActionOpenFormaXTableBase: TAction
      Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1090#1072#1073#1083#1080#1094
      OnExecute = ActionOpenFormaXTableBaseExecute
    end
  end
end
