object FormaDialogaReportOtrSpis: TFormaDialogaReportOtrSpis
  Left = 513
  Top = 17
  Caption = #1054#1090#1088#1080#1094#1072#1090#1077#1083#1100#1085#1086#1077' '#1089#1087#1080#1089#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  ClientHeight = 254
  ClientWidth = 488
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
    Width = 380
    Height = 29
    Caption = #1054#1090#1088#1080#1094'. '#1089#1087#1080#1089#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
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
  object LabelDoc: TLabel
    Left = 96
    Top = 160
    Width = 78
    Height = 20
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 48
    Top = 136
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object PosNachLabel: TLabel
    Left = 40
    Top = 80
    Width = 70
    Height = 13
    Caption = 'PosNachLabel'
  end
  object PosConLabel: TLabel
    Left = 264
    Top = 80
    Width = 63
    Height = 13
    Caption = 'PosConLabel'
  end
  object ButtonRun: TButton
    Left = 248
    Top = 200
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
    Left = 344
    Top = 200
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
  object ButtonReportPoDoc: TButton
    Left = 144
    Top = 200
    Width = 99
    Height = 33
    Caption = #1055#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1091
    TabOrder = 6
    OnClick = ButtonReportPoDocClick
  end
  object TypePriceComboBox: TComboBox
    Left = 96
    Top = 128
    Width = 289
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 7
    OnChange = TypePriceComboBoxChange
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
  object BitBtnConPerioda: TBitBtn
    Left = 408
    Top = 48
    Width = 28
    Height = 28
    TabOrder = 9
    OnClick = BitBtnConPeriodaClick
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
    Left = 448
    Top = 8
  end
  object Grp: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMEGN, IDGN, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL , SUM(KOL' +
        '_RGOTRSPIS_DV*ZNACH_PRICE)  AS SUMM'
      ''
      ''
      'from '
      ' RGOTRSPIS_DV'
      'left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      
        'left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:P' +
        'ARAM_IDTYPE_PRICE)'
      
        'where POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POS' +
        'CON'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 448
    Top = 72
    object GrpNAMEGN: TFIBStringField
      FieldName = 'NAMEGN'
      Size = 50
      EmptyStrToNull = True
    end
    object GrpIDGN: TFIBIntegerField
      FieldName = 'IDGN'
    end
    object GrpSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object GrpSUMM: TFIBFloatField
      FieldName = 'SUMM'
    end
  end
  object El: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMENOM, NAMEED, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL, ZNACH' +
        '_PRICE'
      'from '
      '  RGOTRSPIS_DV'
      'left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      
        'left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:P' +
        'ARAM_IDTYPE_PRICE)'
      
        'where (POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_PO' +
        'SCON)'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED, ZNACH_PRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 448
    Top = 112
    object ElNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object ElSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object ElZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
  end
  object Price: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SPRICE'
      'where IDNOM_PRICE=:PARAM_IDNOM and '
      '     IDTYPE_PRICE=:PARAM_IDTYPE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 448
    Top = 152
    object PriceID_PRICE: TFIBIntegerField
      FieldName = 'ID_PRICE'
    end
    object PriceIDNOM_PRICE: TFIBIntegerField
      FieldName = 'IDNOM_PRICE'
    end
    object PriceIDTYPE_PRICE: TFIBIntegerField
      FieldName = 'IDTYPE_PRICE'
    end
    object PriceZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object PriceGID_SPRICE: TFIBStringField
      FieldName = 'GID_SPRICE'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 16
    Top = 160
    object TypePriceID_TPRICE: TFIBIntegerField
      FieldName = 'ID_TPRICE'
    end
    object TypePriceNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object TypePriceGID_STPRICE: TFIBStringField
      FieldName = 'GID_STPRICE'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
