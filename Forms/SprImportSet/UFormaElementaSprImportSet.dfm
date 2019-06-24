object FormaElementaSprImportSet: TFormaElementaSprImportSet
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1080#1084#1087#1086#1088#1090#1072'"'
  ClientHeight = 302
  ClientWidth = 438
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 18
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 10
    Top = 114
    Width = 78
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099':'
  end
  object Label3: TLabel
    Left = 10
    Top = 73
    Width = 77
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1087#1086#1080#1089#1082#1072':'
  end
  object cxButtonOK: TcxButton
    Left = 233
    Top = 252
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 332
    Top = 252
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SIMPORTSET'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 415
  end
  object TypeSearchcxComboBox: TcxComboBox
    Left = 98
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Items.Strings = (
      '0 '#1053#1077' '#1079#1072#1076#1072#1085
      '1 '#1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      '2 '#1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102' '#1077#1076#1080#1085#1080#1094#1099
      '3 '#1055#1086' '#1072#1088#1090#1080#1082#1091#1083#1091
      '4 '#1055#1086' '#1082#1086#1076#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      '5 '#1055#1086' '#1082#1086#1076#1091' '#1077#1076#1080#1085#1080#1094#1099
      '6 '#1055#1086' '#1096#1082' '#1077#1076#1080#1085#1080#1094#1099)
    Properties.OnValidate = TypeSearchcxComboBoxPropertiesValidate
    TabOrder = 1
    Text = 'TypeSearchcxComboBox'
    Width = 327
  end
  object StrParamcxDBMemo: TcxDBMemo
    Left = 10
    Top = 138
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'STRPAR_SIMPORTSET'
    TabOrder = 3
    OnKeyPress = StrParamcxDBMemoKeyPress
    Height = 107
    Width = 415
  end
  object TypeObrcxDBCalcEdit: TcxDBCalcEdit
    Left = 276
    Top = 105
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'TYPE_OBR_SIMPORTSET'
    TabOrder = 2
    OnKeyPress = TypeObrcxDBCalcEditKeyPress
    Width = 149
  end
  object cxLabel1: TcxLabel
    Left = 167
    Top = 106
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1086#1073#1088#1072#1073#1086#1090#1082#1080':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 24
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
