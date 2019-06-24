object FormaElementaSprSklad: TFormaElementaSprSklad
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1057#1082#1083#1072#1076#1099'"'
  ClientHeight = 465
  ClientWidth = 523
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 7
    Top = 44
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 89
    Top = 10
    Width = 159
    Height = 13
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1085#1086#1084#1077#1088#1086#1074' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
  end
  object Label3: TLabel
    Left = 14
    Top = 120
    Width = 34
    Height = 13
    Caption = #1040#1076#1088#1077#1089':'
  end
  object Label4: TLabel
    Left = 8
    Top = 63
    Width = 176
    Height = 13
    Caption = #1052#1072#1090#1077#1088#1080#1072#1083#1100#1085#1086'-'#1086#1090#1074#1077#1090#1089#1090#1074#1077#1085#1085#1086#1077' '#1083#1080#1094#1086':'
  end
  object Label5: TLabel
    Left = 14
    Top = 162
    Width = 48
    Height = 13
    Caption = #1058#1077#1083#1077#1092#1086#1085':'
  end
  object Label6: TLabel
    Left = 15
    Top = 198
    Width = 31
    Height = 13
    Caption = 'E-mail:'
  end
  object Label7: TLabel
    Left = 27
    Top = 226
    Width = 59
    Height = 13
    Caption = #1042' '#1082#1086#1085#1090#1072#1082#1090#1077':'
  end
  object Label8: TLabel
    Left = 27
    Top = 253
    Width = 57
    Height = 13
    Caption = 'WEB  '#1089#1072#1081#1090':'
  end
  object Label9: TLabel
    Left = 27
    Top = 280
    Width = 78
    Height = 13
    Caption = #1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099':'
  end
  object Label10: TLabel
    Left = 27
    Top = 307
    Width = 56
    Height = 13
    Caption = #1044#1086#1087'. '#1080#1085#1092#1086':'
  end
  object cxButtonOK: TcxButton
    Left = 332
    Top = 423
    Width = 74
    Height = 25
    Action = ActionOK
    TabOrder = 5
  end
  object cxButtonClose: TcxButton
    Left = 412
    Top = 423
    Width = 76
    Height = 25
    Action = ActionClose
    TabOrder = 6
  end
  object TypeSkladcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 350
    Caption = #1076#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086' '#1091#1095#1077#1090' '#1087#1086' '#1094#1077#1085#1072#1084' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
    DataBinding.DataField = 'TSKLAD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 3
    OnKeyDown = TypeSkladcxDBCheckBoxKeyDown
    Width = 313
  end
  object AdrcxDBTextEdit: TcxDBTextEdit
    Left = 150
    Top = 120
    DataBinding.DataField = 'ADRSKLAD'
    TabOrder = 2
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object MOLcxDBTextEdit: TcxDBTextEdit
    Left = 150
    Top = 80
    DataBinding.DataField = 'MOLSKLAD'
    TabOrder = 1
    OnKeyDown = MOLcxDBTextEditKeyDown
    Width = 338
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 150
    Top = 42
    DataBinding.DataField = 'NAMESKLAD'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 338
  end
  object PrefiksNumcxDBTextEdit: TcxDBTextEdit
    Left = 261
    Top = 7
    DataBinding.DataField = 'PREFIKS_NUM_SSKLAD'
    TabOrder = 4
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 84
  end
  object PhonecxDBTextEdit: TcxDBTextEdit
    Left = 150
    Top = 159
    DataBinding.DataField = 'PHONE_SSKLAD'
    TabOrder = 7
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object EMailcxDBTextEdit: TcxDBTextEdit
    Left = 150
    Top = 196
    DataBinding.DataField = 'EMAIL_SSKLAD'
    TabOrder = 8
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object DblUchetAllNomcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 368
    Caption = #1076#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090' '#1074' '#1089#1080#1089#1090#1077#1084#1077' '#1056#1077#1084#1086#1085#1090' '#1087#1086' '#1074#1089#1077#1084' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072#1084
    DataBinding.DataField = 'DBLUCHETALLNOM_SSKLAD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 9
    OnKeyDown = TypeSkladcxDBCheckBoxKeyDown
    Width = 371
  end
  object DblUchetcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 386
    Caption = 
      #1076#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090' '#1074' '#1089#1080#1089#1090#1077#1084#1077' '#1056#1077#1084#1086#1085#1090' '#1090#1086#1083#1100#1082#1086' '#1077#1089#1083#1080' '#1074' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1077' '#1089#1090#1086#1080#1090' '#1092 +
      #1083#1072#1075' '#1044#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090
    DataBinding.DataField = 'DBLUCHET_SSKLAD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 10
    OnKeyDown = TypeSkladcxDBCheckBoxKeyDown
    Width = 520
  end
  object cxDBTextEditVKONTAKTE_SSKLAD: TcxDBTextEdit
    Left = 150
    Top = 223
    DataBinding.DataField = 'VKONTAKTE_SSKLAD'
    TabOrder = 11
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object cxDBTextEditWEBSITE_SSKLAD: TcxDBTextEdit
    Left = 150
    Top = 250
    DataBinding.DataField = 'WEBSITE_SSKLAD'
    TabOrder = 12
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object cxDBTextEditREGIM_RABOTI_SSKLAD: TcxDBTextEdit
    Left = 150
    Top = 277
    DataBinding.DataField = 'REGIM_RABOTI_SSKLAD'
    TabOrder = 13
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object cxDBTextEditDOPINFO_SSKLAD: TcxDBTextEdit
    Left = 150
    Top = 304
    DataBinding.DataField = 'DOPINFO_SSKLAD'
    TabOrder = 14
    OnKeyDown = AdrcxDBTextEditKeyDown
    Width = 338
  end
  object ActionList: TActionList
    Left = 32
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
