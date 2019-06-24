object FormaCreateCard: TFormaCreateCard
  Left = 0
  Top = 0
  Caption = #1052#1072#1089#1089#1086#1074#1086#1077' '#1089#1086#1079#1076#1072#1085#1080#1077' '#1076#1080#1089#1082#1086#1085#1090#1085#1099#1093' '#1082#1072#1088#1090
  ClientHeight = 476
  ClientWidth = 622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object StartNumbercxTextEdit: TcxTextEdit
    Left = 25
    Top = 30
    TabOrder = 0
    Text = 'StartNumbercxTextEdit'
    Width = 121
  end
  object EndNumbercxTextEdit: TcxTextEdit
    Left = 296
    Top = 32
    TabOrder = 1
    Text = 'EndNumbercxTextEdit'
    Width = 121
  end
  object PrefiksCardcxTextEdit: TcxTextEdit
    Left = 113
    Top = 60
    TabOrder = 2
    Text = 'PrefiksCardcxTextEdit'
    Width = 121
  end
  object ProcentcxCalcEdit: TcxCalcEdit
    Left = 480
    Top = 278
    EditValue = 0.000000000000000000
    TabOrder = 11
    Width = 121
  end
  object SingleCardcxCheckBox: TcxCheckBox
    Left = 40
    Top = 226
    Caption = #1086#1076#1085#1086#1088#1072#1079#1086#1074#1072#1103' '#1082#1072#1088#1090#1072
    TabOrder = 10
    Width = 185
  end
  object NameKlientcxButtonEdit: TcxButtonEdit
    Left = 296
    Top = 140
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameKlientcxButtonEditPropertiesButtonClick
    TabOrder = 7
    Text = 'NameKlientcxButtonEdit'
    Width = 305
  end
  object cxButtonCreate: TcxButton
    Left = 336
    Top = 423
    Width = 130
    Height = 33
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 14
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 480
    Top = 423
    Width = 121
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 15
    OnClick = cxButtonCloseClick
  end
  object cxLabel1: TcxLabel
    Left = 8
    Top = 8
    Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1081' '#1082#1086#1076' '#1082#1072#1088#1090#1099':'
  end
  object cxLabel2: TcxLabel
    Left = 287
    Top = 6
    Caption = #1050#1086#1085#1077#1095#1085#1099#1081' '#1082#1086#1076' '#1082#1072#1088#1090#1099':'
  end
  object cxLabel3: TcxLabel
    Left = 8
    Top = 60
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1082#1072#1088#1090#1099':'
  end
  object cxLabel4: TcxLabel
    Left = 295
    Top = 172
    Caption = #1058#1080#1087' '#1082#1072#1088#1090#1099':'
  end
  object cxLabel5: TcxLabel
    Left = 373
    Top = 279
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1089#1082#1080#1076#1082#1080':'
  end
  object cxLabel6: TcxLabel
    Left = 295
    Top = 120
    Caption = #1042#1083#1072#1076#1077#1083#1077#1094' '#1082#1072#1088#1090#1099' ('#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090'):'
  end
  object cxImageComboBoxTypeCard: TcxImageComboBox
    Left = 296
    Top = 192
    RepositoryItem = DM.cxEditRepository1ImageComboBoxItem1TypeDiscountCard
    Properties.Items = <>
    TabOrder = 8
    Width = 305
  end
  object VidCardcxButtonEdit: TcxButtonEdit
    Left = 296
    Top = 248
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = VidCardcxButtonEditPropertiesButtonClick
    TabOrder = 9
    Text = 'VidCardcxButtonEdit'
    Width = 305
  end
  object cxLabel7: TcxLabel
    Left = 296
    Top = 227
    Caption = #1042#1080#1076' '#1082#1072#1088#1090#1099':'
  end
  object NameGrpKlientcxButtonEdit: TcxButtonEdit
    Left = 296
    Top = 84
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameGrpKlientcxButtonEditPropertiesButtonClick
    TabOrder = 6
    Text = 'NameGrpKlientcxButtonEdit'
    Width = 305
  end
  object cxLabel8: TcxLabel
    Left = 295
    Top = 62
    Caption = #1043#1088#1091#1087#1087#1072' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1086#1074' ('#1076#1083#1103' '#1085#1086#1074#1099#1093'):'
  end
  object NameCardcxTextEdit: TcxTextEdit
    Left = 164
    Top = 326
    TabOrder = 12
    Text = 'NameCardcxTextEdit'
    Width = 201
  end
  object NameKlientcxTextEdit: TcxTextEdit
    Left = 164
    Top = 377
    TabOrder = 13
    Text = 'NameKlientcxTextEdit'
    Width = 201
  end
  object cxLabel9: TcxLabel
    Left = 29
    Top = 326
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1082#1072#1088#1090#1099
  end
  object cxLabel10: TcxLabel
    Left = 371
    Top = 326
    Caption = '+ '#1050#1086#1076' '#1082#1072#1088#1090#1099
  end
  object cxLabel11: TcxLabel
    Left = 17
    Top = 378
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1082#1083#1080#1077#1085#1090#1072
  end
  object cxLabel12: TcxLabel
    Left = 371
    Top = 378
    Caption = '+ '#1082#1086#1076' '#1082#1083#1080#1077#1085#1090#1072
  end
  object cxRadioGroup1: TcxRadioGroup
    Left = 17
    Top = 97
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
    Properties.Items = <>
    TabOrder = 3
    Height = 105
    Width = 272
  end
  object ViborKlientcxRadioButton: TcxRadioButton
    Left = 29
    Top = 123
    Width = 140
    Height = 17
    Caption = #1086#1076#1080#1085' '#1076#1083#1103' '#1074#1089#1077#1093' '#1082#1072#1088#1090
    TabOrder = 4
  end
  object NewKlientcxRadioButton: TcxRadioButton
    Left = 29
    Top = 163
    Width = 244
    Height = 17
    Caption = #1089#1086#1079#1076#1072#1074#1072#1090#1100' '#1085#1086#1074#1086#1075#1086' '#1076#1083#1103' '#1082#1072#1078#1076#1081' '#1082#1072#1088#1090#1099
    TabOrder = 5
  end
end
