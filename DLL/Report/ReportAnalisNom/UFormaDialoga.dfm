object FormaDialoga: TFormaDialoga
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1077#1090' "'#1040#1085#1072#1083#1080#1079' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099'"'
  ClientHeight = 331
  ClientWidth = 611
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 17
  object Label1: TLabel
    Left = 21
    Top = 10
    Width = 527
    Height = 96
    Alignment = taCenter
    AutoSize = False
    Caption = 
      #1040#1085#1072#1083#1080#1079' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084' '#1089' '#1088#1072#1089#1095#1077#1090#1086#1084' '#1074#1088#1077#1084#1077#1085#1080' '#1085#1072#1093#1086#1078#1076#1077#1085#1080#1103' '#1085#1072' ' +
      #1089#1082#1083#1072#1076#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object Label2: TLabel
    Left = 42
    Top = 129
    Width = 12
    Height = 28
    Caption = #1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 314
    Top = 135
    Width = 29
    Height = 28
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 42
    Top = 192
    Width = 92
    Height = 28
    Caption = #1043#1088#1091#1087#1087#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object cxButtonRun: TcxButton
    Left = 366
    Top = 288
    Width = 119
    Height = 32
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonRunClick
  end
  object cxButtonClose: TcxButton
    Left = 502
    Top = 288
    Width = 98
    Height = 32
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = cxButtonCloseClick
  end
  object PosNachcxDateEdit: TcxDateEdit
    Left = 63
    Top = 136
    Properties.Kind = ckDateTime
    TabOrder = 2
    Width = 231
  end
  object PosConcxDateEdit: TcxDateEdit
    Left = 366
    Top = 136
    Properties.Kind = ckDateTime
    TabOrder = 3
    Width = 221
  end
  object cxLookupComboBox1: TcxLookupComboBox
    Left = 188
    Top = 199
    Properties.DropDownListStyle = lsFixedList
    Properties.KeyFieldNames = 'IDGN'
    Properties.ListColumns = <
      item
        Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1082#1083#1072#1090#1091#1088#1099
        FieldName = 'NAMEGN'
      end>
    Properties.ListSource = DataSourceGrpNom
    EditValue = 0
    TabOrder = 4
    Width = 399
  end
  object pFIBTransaction1: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 64
    Top = 256
  end
  object SpisokGrpNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDGN, NAMEGN '
      'from sgrpnom'
      'order by NAMEGN')
    Left = 200
    Top = 256
    poUseLargeIntField = True
    object SpisokGrpNomIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object SpisokGrpNomNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
  end
  object DataSourceGrpNom: TDataSource
    DataSet = SpisokGrpNom
    Left = 160
    Top = 208
  end
end
