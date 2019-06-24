object FormaSvertkaItogov: TFormaSvertkaItogov
  Left = 337
  Top = 114
  Caption = #1057#1074#1077#1088#1090#1082#1072' '#1080#1090#1086#1075#1086#1074':'
  ClientHeight = 226
  ClientWidth = 445
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
    Width = 186
    Height = 29
    Caption = #1057#1074#1077#1088#1090#1082#1072' '#1080#1090#1086#1075#1086#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 136
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 48
    Top = 99
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object ButtonCreateDocOstNom: TButton
    Left = 232
    Top = 168
    Width = 91
    Height = 33
    Caption = #1044#1086#1082'. "'#1054#1089#1090'. '#1085#1086#1084'."'
    TabOrder = 0
    OnClick = ButtonCreateDocOstNomClick
  end
  object DateCon: TDateTimePicker
    Left = 240
    Top = 48
    Width = 153
    Height = 24
    Date = 38654.999988425900000000
    Time = 38654.999988425900000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ButtonClose: TButton
    Left = 328
    Top = 168
    Width = 97
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 2
    OnClick = ButtonCloseClick
  end
  object NameSkladEdit: TEdit
    Left = 96
    Top = 128
    Width = 233
    Height = 21
    Color = clBtnFace
    TabOrder = 3
    Text = 'NameSkladEdit'
  end
  object ButtonViborSklad: TButton
    Left = 328
    Top = 128
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 4
    OnClick = ButtonViborSkladClick
  end
  object BitBtnDateTime: TBitBtn
    Left = 392
    Top = 48
    Width = 23
    Height = 23
    TabOrder = 5
    OnClick = BitBtnDateTimeClick
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
  object DateNach: TDateTimePicker
    Left = 40
    Top = 48
    Width = 153
    Height = 24
    Date = 38654.000000000000000000
    Time = 38654.000000000000000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object NameFirmaEdit: TEdit
    Left = 96
    Top = 96
    Width = 233
    Height = 21
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
    Text = 'NameFirmaEdit'
  end
  object ButtonVibFirm: TButton
    Left = 328
    Top = 96
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 8
    TabStop = False
    OnClick = ButtonVibFirmClick
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
    Left = 144
    Top = 160
  end
  object IBQEl: TpFIBDataSet
    SelectSQL.Strings = (
      '         select'
      'NAMENOM, IDNOM, NAMEED, IDED,'
      'SUM(KOLOSTNOM) AS SUMKOL ,'
      'SUM(SUMOSTNOM)'
      'from RGOSTNOM'
      'left outer join SNOM on IDNOMOSTNOM=IDNOM'
      'left outer join SED on IDBASEDNOM=IDED'
      'where IDFIRMOSTNOM=:PARAM_IDFIRM AND IDSKLOSTNOM=:PARAM_IDSKLAD'
      'group by NAMENOM, IDNOM, NAMEED, IDED')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 144
    Top = 192
    object IBQElNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElIDNOM: TFIBIntegerField
      FieldName = 'IDNOM'
    end
    object IBQElNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElIDED: TFIBIntegerField
      FieldName = 'IDED'
    end
    object IBQElSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElSUM: TFIBBCDField
      FieldName = 'SUM'
      Size = 2
      RoundByScale = True
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
