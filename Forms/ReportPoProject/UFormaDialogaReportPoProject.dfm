object FormaDialogaReportPoProject: TFormaDialogaReportPoProject
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1087#1088#1086#1077#1082#1090#1072#1084':'
  ClientHeight = 392
  ClientWidth = 422
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 192
    Height = 26
    Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1087#1088#1086#1077#1082#1090#1072#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 34
    Top = 35
    Width = 12
    Height = 26
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 217
    Top = 35
    Width = 24
    Height = 26
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 34
    Top = 115
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 8
    Top = 324
    Width = 143
    Height = 39
    Caption = 
      #1058#1080#1087' '#1094#1077#1085' '#1076#1083#1103' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088', '#1082#1086#1090#1086#1088#1099#1093' '#1085#1077' '#1073#1099#1083#1086' '#1085#1072' '#1089#1082#1083#1072#1076#1077' '#1074' '#1084#1086#1084#1077#1085#1090' '#1087#1088#1086#1076 +
      #1072#1078#1080':'
    WordWrap = True
  end
  object Label6: TLabel
    Left = 30
    Top = 88
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label7: TLabel
    Left = 32
    Top = 134
    Width = 38
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 13
    Top = 148
    Width = 77
    Height = 13
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 13
    Top = 169
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object DateNach: TcxDateEdit
    Left = 60
    Top = 43
    Properties.Kind = ckDateTime
    TabOrder = 0
    OnKeyDown = DateNachKeyDown
    Width = 137
  end
  object DateCon: TcxDateEdit
    Left = 268
    Top = 43
    Properties.Kind = ckDateTime
    TabOrder = 1
    OnKeyDown = DateConKeyDown
    Width = 141
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 96
    Top = 85
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
    TabOrder = 2
    Text = 'NameFirmEdit'
    Width = 313
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
    Top = 112
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameSkladEdit'
    Width = 313
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 96
    Top = 139
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameGrpNomEdit'
    Width = 313
  end
  object NameNomEdit: TcxButtonEdit
    Left = 96
    Top = 166
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 313
  end
  object OnlyCheckBox: TcxCheckBox
    Left = 97
    Top = 224
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100
    TabOrder = 7
    OnKeyDown = OnlyCheckBoxKeyDown
    Width = 121
  end
  object TypeNomComboBox: TcxComboBox
    Left = 224
    Top = 224
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1090#1086#1083#1100#1082#1086' '#1090#1086#1074#1072#1088#1099' (0)'
      #1090#1086#1083#1100#1082#1086' '#1091#1089#1083#1091#1075#1080' (1)'
      #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1076#1091#1082#1094#1080#1103' (2)')
    Properties.OnChange = TypeNomComboBoxPropertiesChange
    TabOrder = 8
    Width = 185
  end
  object OnlyOperationCheckBox: TcxCheckBox
    Left = 96
    Top = 261
    Caption = #1090#1086#1083#1100#1082#1086' '#1086#1087#1077#1088#1072#1094#1080#1080
    TabOrder = 9
    OnKeyDown = OnlyOperationCheckBoxKeyDown
    Width = 121
  end
  object OperationComboBox: TcxComboBox
    Left = 224
    Top = 256
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1087#1088#1086#1095#1077#1077' (0)'
      #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' (1)'
      #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' '#1074' '#1082#1088#1077#1076#1080#1090' (2)'
      #1054#1087#1090#1086#1074#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' (3)')
    Properties.OnChange = OperationComboBoxPropertiesChange
    TabOrder = 10
    Width = 185
  end
  object TypePriceComboBox: TcxComboBox
    Left = 224
    Top = 320
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 11
    Width = 185
  end
  object DocCheckBox: TcxCheckBox
    Left = 96
    Top = 356
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080
    TabOrder = 13
    OnKeyDown = DocCheckBoxKeyDown
    Width = 121
  end
  object cxButtonCreateReport: TcxButton
    Left = 240
    Top = 356
    Width = 83
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 14
    OnClick = cxButtonCreateReportClick
  end
  object cxButtonClose: TcxButton
    Left = 334
    Top = 356
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 15
  end
  object cxCheckBoxVisibleOtrOst: TcxCheckBox
    Left = 96
    Top = 288
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1090#1086#1074#1072#1088#1099', '#1082#1086#1090#1086#1088#1099#1093' '#1085#1077' '#1073#1099#1083#1086' '#1085#1072' '#1089#1082#1083#1072#1076#1077' '#1074' '#1084#1086#1084#1077#1085#1090' '#1087#1088#1086#1076#1072#1078#1080
    Properties.MultiLine = True
    TabOrder = 12
    OnKeyDown = cxCheckBoxVisibleOtrOstKeyDown
    Width = 312
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 96
    Top = 192
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameProjectcxButtonEditPropertiesButtonClick
    TabOrder = 6
    Text = 'NameProjectcxButtonEdit'
    OnKeyDown = NameProjectcxButtonEditKeyDown
    Width = 313
  end
  object cxLabel1: TcxLabel
    Left = 32
    Top = 192
    Caption = #1055#1088#1086#1077#1082#1090':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 248
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
  end
end
