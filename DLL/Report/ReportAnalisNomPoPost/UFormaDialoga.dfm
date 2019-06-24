object FormaDialoga: TFormaDialoga
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1077#1090' "'#1040#1085#1072#1083#1080#1079' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1087#1086' '#1087#1086#1089#1090#1072#1097#1080#1082#1072#1084'"'
  ClientHeight = 370
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
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Alignment = taCenter
    AutoSize = False
    Caption = 
      #1040#1085#1072#1083#1080#1079' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1087#1086' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072#1084' '#1089' '#1088#1072#1089#1095#1077#1090#1086#1084' '#1074#1088#1077#1084#1077#1085#1080' '#1085#1072#1093#1086#1078#1076#1077#1085#1080#1103 +
      ' '#1085#1072' '#1089#1082#1083#1072#1076#1077
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
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 81
    Top = 194
    Width = 92
    Height = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1088#1091#1087#1087#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 26
    Top = 234
    Width = 142
    Height = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object cxButtonRun: TcxButton
    Left = 375
    Top = 327
    Width = 119
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonRunClick
  end
  object cxButtonClose: TcxButton
    Left = 502
    Top = 327
    Width = 98
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = cxButtonCloseClick
  end
  object PosNachcxDateEdit: TcxDateEdit
    Left = 63
    Top = 136
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 2
    Width = 231
  end
  object PosConcxDateEdit: TcxDateEdit
    Left = 366
    Top = 136
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 3
    Width = 221
  end
  object cxLookupComboBox1: TcxLookupComboBox
    Left = 188
    Top = 199
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.KeyFieldNames = 'IDGRPKL'
    Properties.ListColumns = <
      item
        FieldName = 'NAMEGRPKL'
      end>
    Properties.ListSource = DataSourceGrpKlient
    Properties.OnValidate = cxLookupComboBox1PropertiesValidate
    EditValue = 0
    TabOrder = 4
    Width = 399
  end
  object NameKlientcxLookupComboBox: TcxLookupComboBox
    Left = 188
    Top = 241
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.KeyFieldNames = 'IDKLIENT'
    Properties.ListColumns = <
      item
        FieldName = 'NAMEKLIENT'
      end>
    Properties.ListSource = DataSourceSpisokKlient
    TabOrder = 5
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
    Left = 40
    Top = 216
  end
  object SpisokGrpKlient: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDGRPKL, NAMEGRPKL '
      'from SGRPKL'
      'order by NAMEGRPKL')
    Transaction = pFIBTransaction1
    Left = 344
    Top = 144
    poUseLargeIntField = True
    object SpisokGrpKlientIDGRPKL: TFIBLargeIntField
      FieldName = 'IDGRPKL'
    end
    object SpisokGrpKlientNAMEGRPKL: TFIBWideStringField
      FieldName = 'NAMEGRPKL'
      Size = 200
    end
  end
  object DataSourceGrpKlient: TDataSource
    DataSet = SpisokGrpKlient
    Left = 296
    Top = 144
  end
  object SpisokKlient: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDKLIENT, NAMEKLIENT'
      'from SKLIENT'
      'where IDGRPKLIENT=:PARAM_IDGRP'
      'order by NAMEKLIENT')
    Transaction = pFIBTransaction1
    Left = 344
    Top = 192
    poUseLargeIntField = True
    object SpisokKlientIDKLIENT: TFIBLargeIntField
      FieldName = 'IDKLIENT'
    end
    object SpisokKlientNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
  end
  object DataSourceSpisokKlient: TDataSource
    DataSet = SpisokKlient
    Left = 296
    Top = 192
  end
end
