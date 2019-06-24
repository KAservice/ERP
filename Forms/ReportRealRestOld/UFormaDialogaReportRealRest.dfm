object FormaDialogaReportRealRest: TFormaDialogaReportRealRest
  Left = 166
  Top = 108
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1087#1088#1086#1076#1072#1078#1072#1093' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1086#1079#1085'.):'
  ClientHeight = 244
  ClientWidth = 455
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
    Width = 371
    Height = 24
    Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'  '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1077#1089#1090#1086#1088#1072#1085'.):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 12
    Height = 29
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 224
    Top = 48
    Width = 29
    Height = 29
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 104
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 24
    Top = 136
    Width = 61
    Height = 13
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object PosConLabel: TLabel
    Left = 264
    Top = 80
    Width = 63
    Height = 13
    Caption = 'PosConLabel'
  end
  object PosNachLabel: TLabel
    Left = 40
    Top = 80
    Width = 70
    Height = 13
    Caption = 'PosNachLabel'
  end
  object Label6: TLabel
    Left = 8
    Top = 216
    Width = 316
    Height = 13
    Caption = #1044#1072#1085#1085#1099#1081' '#1086#1090#1095#1077#1090' '#1092#1086#1088#1084#1080#1088#1091#1077#1090#1089#1103' '#1087#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084' "'#1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080'"'
  end
  object ButtonRun: TButton
    Left = 192
    Top = 176
    Width = 91
    Height = 33
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonRunClick
  end
  object DateNach: TDateTimePicker
    Left = 40
    Top = 48
    Width = 153
    Height = 28
    Date = 38654.000000000000000000
    Time = 38654.000000000000000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnChange = DateNachChange
  end
  object DateCon: TDateTimePicker
    Left = 256
    Top = 48
    Width = 153
    Height = 28
    Date = 38654.999988425900000000
    Time = 38654.999988425900000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnChange = DateConChange
  end
  object ButtonClose: TButton
    Left = 296
    Top = 176
    Width = 97
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
  end
  object NameSkladEdit: TEdit
    Left = 96
    Top = 96
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 4
    Text = 'NameSkladEdit'
  end
  object ButtonViborSklad: TButton
    Left = 368
    Top = 96
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonViborSkladClick
  end
  object NameKlientEdit: TEdit
    Left = 96
    Top = 128
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 6
    Text = 'NameKlientEdit'
  end
  object ButtonViborKlienta: TButton
    Left = 368
    Top = 128
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 7
    OnClick = ButtonViborKlientaClick
  end
  object BitBtnNachPerioda: TBitBtn
    Left = 193
    Top = 48
    Width = 28
    Height = 28
    TabOrder = 8
    OnClick = BitBtnNachPeriodaClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333FFFFF3333333333000003333333333F77777FFF333333009999900
      3333333777777777FF33330998FFF899033333777333F3777FF33099FFFCFFF9
      903337773337333777F3309FFFFFFFCF9033377333F3337377FF098FF0FFFFFF
      890377F3373F3333377F09FFFF0FFFFFF90377F3F373FFFFF77F09FCFFF90000
      F90377F733377777377F09FFFFFFFFFFF90377F333333333377F098FFFFFFFFF
      890377FF3F33333F3773309FCFFFFFCF9033377F7333F37377F33099FFFCFFF9
      90333777FF37F3377733330998FCF899033333777FF7FF777333333009999900
      3333333777777777333333333000003333333333377777333333}
    NumGlyphs = 2
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 416
    Top = 8
  end
  object IBQSkl: TpFIBDataSet
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 416
    Top = 40
  end
  object IBQKl: TpFIBDataSet
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 416
    Top = 80
  end
  object IBQGrp: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMEGN, IDGN,SUM(SUMCHKT)  AS SUMMA, SUM(KFCHKT*KOLCHKT)' +
        '  AS SUMKOL'
      ''
      'from '
      '  DCHKT'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join GALLDOC on IDDOCCHKT=IDDOC'
      'where POSDOC  between :PARAM_POSNACH and :PARAM_POSCON'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 416
    Top = 112
    object IBQGrpNAMEGN: TFIBStringField
      FieldName = 'NAMEGN'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQGrpIDGN: TFIBIntegerField
      FieldName = 'IDGN'
    end
    object IBQGrpSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
  end
  object IBQEl: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMENOM, NAMEED, SUM(SUMCHKT)  AS SUMMA, SUM(KFCHKT*KOLC' +
        'HKT)  AS SUMKOL'
      'from '
      '  DCHKT'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      'left outer join GALLDOC on IDDOCCHKT=IDDOC'
      'where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 416
    Top = 144
    object IBQElNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object IBQElSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
end
