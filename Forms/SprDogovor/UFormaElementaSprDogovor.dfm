object FormaElementaSprDogovor: TFormaElementaSprDogovor
  Left = 447
  Top = 118
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1044#1086#1075#1086#1074#1086#1088#1099'"'
  ClientHeight = 359
  ClientWidth = 578
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
  object Label3: TLabel
    Left = 10
    Top = 89
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 226
    Top = 209
    Width = 185
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1075#1072#1089#1080#1090#1100' '#1079#1072#1076#1086#1083#1078#1077#1085#1085#1086#1089#1090#1100' '#1076#1086
  end
  object Label1: TLabel
    Left = 374
    Top = 20
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object Label2: TLabel
    Left = 286
    Top = 249
    Width = 92
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1088#1086#1082' '#1082#1088#1077#1076#1080#1090#1072':'
  end
  object Label5: TLabel
    Left = 276
    Top = 288
    Width = 137
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1072#1082#1089'.'#1089#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1090#1072':'
  end
  object Label6: TLabel
    Left = 10
    Top = 153
    Width = 181
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1087#1086#1089#1086#1073' '#1087#1086#1075#1072#1096#1077#1085#1080#1103' '#1082#1088#1077#1076#1080#1090#1072':'
  end
  object Label7: TLabel
    Left = 10
    Top = 219
    Width = 55
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label8: TLabel
    Left = 10
    Top = 59
    Width = 111
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1076#1086#1075#1086#1074#1086#1088#1072':'
  end
  object Label9: TLabel
    Left = 295
    Top = 62
    Width = 15
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1086#1090
  end
  object cxButtonGrafikPlat: TcxButton
    Left = 117
    Top = 320
    Width = 139
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1088#1072#1092#1080#1082' '#1087#1083#1072#1090#1077#1078#1077#1081
    TabOrder = 9
    OnClick = cxButtonGrafikPlatClick
  end
  object cxButtonSave: TcxButton
    Left = 263
    Top = 320
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionSave
    TabOrder = 11
  end
  object cxButtonOK: TcxButton
    Left = 363
    Top = 320
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 10
  end
  object cxButtonClose: TcxButton
    Left = 463
    Top = 320
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 12
  end
  object MaxSumCreditcxDBCalcEdit: TcxDBCalcEdit
    Left = 414
    Top = 283
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'MAXSUMCREDIT_SDOG'
    TabOrder = 8
    OnKeyDown = MaxSumCreditcxDBCalcEditKeyDown
    Width = 139
  end
  object SrokcxDBTextEdit: TcxDBTextEdit
    Left = 412
    Top = 242
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SROK_SDOG'
    TabOrder = 6
    OnKeyDown = SrokcxDBTextEditKeyDown
    Width = 141
  end
  object DocxDBDateEdit: TcxDBDateEdit
    Left = 412
    Top = 209
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DO_SDOG'
    TabOrder = 5
    OnKeyDown = DocxDBDateEditKeyDown
    Width = 141
  end
  object TypePriceComboBox: TcxComboBox
    Left = 10
    Top = 242
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 7
    Width = 178
  end
  object WayPayComboBox: TcxComboBox
    Left = 10
    Top = 176
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      '   - 0 '#1089#1074#1086#1073#1086#1076#1085#1099#1081
      '   - 1 '#1088#1072#1074#1085#1099#1084#1080' '#1076#1086#1083#1103#1084#1080' '#1082#1072#1078#1076#1099#1081' '#1084#1077#1089#1103#1094' '#1076#1086' '#1091#1082#1072#1079#1072#1085#1085#1086#1081' '#1076#1072#1090#1099
      
        '   - 2 '#1088#1072#1074#1085#1099#1084#1080' '#1076#1086#1083#1103#1084#1080' '#1082#1072#1078#1076#1099#1081' '#1084#1077#1089#1103#1094' '#1074' '#1090#1077#1095#1077#1085#1080#1080' '#1086#1090#1089#1088#1086#1095#1082#1080' ('#1086#1090#1089#1088#1086#1095#1082#1072' ' +
        #1074' '#1084#1077#1089#1103#1094#1072#1093')'
      '   - 3 '#1074' '#1090#1077#1095#1077#1085#1080#1080' '#1086#1090#1089#1088#1086#1095#1082#1080' '#1087#1083#1072#1090#1077#1078#1072' ('#1086#1090#1089#1088#1086#1095#1082#1072' '#1074' '#1076#1085#1103#1093')'
      '   - 4 '#1076#1086' '#1091#1082#1072#1079#1072#1085#1085#1086#1081' '#1076#1072#1090#1099
      '   - 5 '#1087#1086' '#1079#1072#1076#1072#1085#1085#1086#1084#1091' '#1075#1088#1072#1092#1080#1082#1091' '#1087#1083#1072#1090#1077#1078#1077#1081)
    Properties.OnChange = WayPayComboBoxPropertiesChange
    TabOrder = 4
    Width = 543
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 112
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SDOG'
    TabOrder = 3
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 543
  end
  object DatecxDBDateEdit: TcxDBDateEdit
    Left = 336
    Top = 54
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DATE_SDOG'
    TabOrder = 2
    OnExit = DatecxDBDateEditExit
    OnKeyDown = DatecxDBDateEditKeyDown
    Width = 149
  end
  object NumcxDBTextEdit: TcxDBTextEdit
    Left = 124
    Top = 54
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMBER_SDOG'
    TabOrder = 1
    OnExit = NumcxDBTextEditExit
    OnKeyDown = NumcxDBTextEditKeyDown
    Width = 149
  end
  object IDcxDBTextEdit: TcxDBTextEdit
    Left = 409
    Top = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabStop = False
    DataBinding.DataField = 'ID_SDOG'
    Properties.ReadOnly = True
    TabOrder = 0
    Width = 144
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
