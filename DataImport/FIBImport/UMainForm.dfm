object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 646
  ClientWidth = 1129
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
  object MainMenu1: TMainMenu
    Left = 24
    Top = 8
    object N1: TMenuItem
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072
      object N3: TMenuItem
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        object OpenFormImportGrpNom: TMenuItem
          Caption = #1043#1088#1091#1087#1087#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
          OnClick = OpenFormImportGrpNomClick
        end
        object OpenFormImportNomMainMenu: TMenuItem
          Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088
          OnClick = OpenFormImportNomMainMenuClick
        end
        object OpenFormImportEdMainMenu: TMenuItem
          Caption = #1045#1076#1080#1085#1080#1094
          OnClick = OpenFormImportEdMainMenuClick
        end
        object OpenFormSetEdNomMainMenu: TMenuItem
          Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1077#1076#1080#1085#1080#1094' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088
          OnClick = OpenFormSetEdNomMainMenuClick
        end
      end
      object N4: TMenuItem
        Caption = #1062#1077#1085#1099
        object N5: TMenuItem
          Caption = #1058#1080#1087#1099' '#1094#1077#1085
          OnClick = N5Click
        end
        object N6: TMenuItem
          Caption = #1062#1077#1085#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
          OnClick = N6Click
        end
      end
      object N7: TMenuItem
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090#1099
        object N8: TMenuItem
          Caption = #1043#1088#1091#1087#1087#1099' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1086#1074
          OnClick = N8Click
        end
        object N9: TMenuItem
          Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090#1099
          OnClick = N9Click
        end
        object N15: TMenuItem
          Caption = #1044#1080#1089#1082#1086#1085#1090#1085#1099#1077' '#1082#1072#1088#1090#1099
          OnClick = N15Click
        end
      end
      object N10: TMenuItem
        Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1077' '#1086#1089#1090#1072#1090#1082#1080
        object N11: TMenuItem
          Caption = #1054#1089#1090#1072#1090#1082#1080' '#1090#1086#1074#1072#1088#1086#1074
          OnClick = N11Click
        end
        object N12: TMenuItem
          Caption = #1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099
          OnClick = N12Click
        end
      end
      object N13: TMenuItem
        Caption = #1050#1050#1058
        object N14: TMenuItem
          Caption = #1043#1088#1091#1087#1087#1099' '#1050#1050#1058
          OnClick = N14Click
        end
        object N31: TMenuItem
          Caption = #1050#1050#1058
          OnClick = N31Click
        end
      end
      object N17: TMenuItem
        Caption = #1043#1083#1072#1074#1085#1086#1077' '#1084#1077#1085#1102
        object N18: TMenuItem
          Caption = #1043#1088#1091#1087#1087#1099
          OnClick = N18Click
        end
        object N19: TMenuItem
          Caption = #1052#1077#1085#1102
          OnClick = N19Click
        end
      end
    end
    object N2: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
    end
  end
end
