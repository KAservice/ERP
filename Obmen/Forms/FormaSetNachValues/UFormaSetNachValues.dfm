object FormaSetNachValues: TFormaSetNachValues
  Left = 0
  Top = 0
  Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1085#1072#1095#1072#1083#1100#1085#1099#1093' '#1079#1085#1072#1095#1077#1085#1080#1081
  ClientHeight = 482
  ClientWidth = 716
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Label1: TLabel
    Left = 39
    Top = 54
    Width = 258
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1074#1089#1077#1093' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1086#1074':'
  end
  object Label2: TLabel
    Left = 39
    Top = 144
    Width = 271
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1076#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label3: TLabel
    Left = 88
    Top = 196
    Width = 222
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1076#1072' '#1077#1076#1080#1085#1080#1094':'
  end
  object Label4: TLabel
    Left = 18
    Top = 248
    Width = 289
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1076#1072' '#1076#1080#1089#1082#1086#1085#1090#1085#1099#1093' '#1082#1072#1088#1090':'
  end
  object Label6: TLabel
    Left = 18
    Top = 77
    Width = 384
    Height = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1090#1086#1083#1100#1082#1086' '#1087#1077#1088#1074#1099#1077' '#1079#1085#1072#1095#1072#1097#1080#1077' '#1094#1080#1092#1088#1099' '#1073#1077#1079' '#1085#1091#1083#1077#1081' ('#1088#1072#1074#1085#1086' ID '#1073#1072#1079#1099')'
  end
  object Label5: TLabel
    Left = 18
    Top = 8
    Width = 536
    Height = 34
    Caption = 
      #1042#1085#1080#1084#1072#1085#1080#1077'! '#1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1085#1077#1087#1088#1072#1074#1080#1083#1100#1085#1099#1093' '#1079#1085#1072#1095#1077#1085#1080#1081' '#1087#1088#1080#1074#1077#1076#1077#1090' '#1082' '#1087#1086#1074#1088#1077#1078#1076#1077#1085#1080#1102 +
      ' '#1074#1089#1077#1093' '#1073#1072#1079', '#1091#1095#1072#1089#1090#1074#1091#1102#1097#1080#1093' '#1074' '#1086#1073#1084#1077#1085#1077'!'
    WordWrap = True
  end
  object Label7: TLabel
    Left = 18
    Top = 344
    Width = 634
    Height = 17
    Caption = 
      #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1086#1074' '#1076#1083#1103' '#1085#1086#1074#1099#1093' '#1090#1072#1073#1083#1080#1094'. ('#1059' '#1082#1086#1090#1086#1088#1099#1093' '#1079#1085#1072 +
      #1095#1077#1085#1080#1077' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072' '#1088#1072#1074#1085#1086' 0.)'
  end
  object NachValueGenEdit: TEdit
    Left = 327
    Top = 50
    Width = 158
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
    Text = 'NachValueGenEdit'
  end
  object ButtonSetValueGen: TButton
    Left = 510
    Top = 47
    Width = 98
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 1
    OnClick = ButtonSetValueGenClick
  end
  object NachCodeNomEdit: TEdit
    Left = 327
    Top = 144
    Width = 158
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 2
    Text = 'NachCodeNomEdit'
  end
  object NachCodeEdEdit: TEdit
    Left = 327
    Top = 192
    Width = 158
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 3
    Text = 'NachCodeEdEdit'
  end
  object NachCodeDiscountCardEdit: TEdit
    Left = 326
    Top = 248
    Width = 158
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 4
    Text = 'NachCodeDiscountCardEdit'
  end
  object ButtonNachCodeNom: TButton
    Left = 510
    Top = 137
    Width = 98
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 5
    OnClick = ButtonNachCodeNomClick
  end
  object ButtonNachCodeEd: TButton
    Left = 510
    Top = 190
    Width = 98
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 6
    OnClick = ButtonNachCodeEdClick
  end
  object ButtonNachCodeDiscountCard: TButton
    Left = 510
    Top = 244
    Width = 98
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 7
    OnClick = ButtonNachCodeDiscountCardClick
  end
  object ButtonSetNulGen: TButton
    Left = 510
    Top = 376
    Width = 98
    Height = 33
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 8
    OnClick = ButtonSetNulGenClick
  end
  object ButtonCheckNullGen: TButton
    Left = 296
    Top = 376
    Width = 208
    Height = 33
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1085#1091#1083'. '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1099
    TabOrder = 9
    OnClick = ButtonCheckNullGenClick
  end
  object Button1: TButton
    Left = 8
    Top = 431
    Width = 258
    Height = 34
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1086#1074
    TabOrder = 10
    OnClick = Button1Click
  end
  object TableGenerators: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from    rdb$generators where (rdb$generators.rdb$system' +
        '_flag is null)'
      '        or (rdb$generators.rdb$system_flag=0)')
    Transaction = pFIBTran
    Database = DataModuleMain.pFIBDatabase
    UpdateTransaction = DataModuleMain.pFIBTrMain
    Left = 80
    Top = 272
  end
  object pFIBTran: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 192
    Top = 272
  end
  object QueryUpdate: TpFIBQuery
    Transaction = TrUpdate
    Database = DataModuleMain.pFIBDatabase
    Left = 376
    Top = 272
    qoStartTransaction = True
  end
  object TrUpdate: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 448
    Top = 272
  end
  object Query: TpFIBQuery
    Transaction = pFIBTran
    Database = DataModuleMain.pFIBDatabase
    Left = 64
    Top = 368
    qoStartTransaction = True
  end
  object SaveDialog1: TSaveDialog
    Left = 328
    Top = 432
  end
end
