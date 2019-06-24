object FormaReportOCBOstPart: TFormaReportOCBOstPart
  Left = 189
  Top = 219
  Width = 489
  Height = 273
  Caption = #1054#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1087#1072#1088#1090#1080#1081' '#1090#1086#1074#1072#1088#1086#1074' '#1087#1086' '#1089#1082#1083#1072#1076#1091':'
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
    Width = 435
    Height = 29
    Caption = #1054#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103'  '#1087#1072#1088#1090#1080#1081' '#1090#1086#1074#1072#1088#1086#1074
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
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
    Left = 192
    Top = 136
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
    CalAlignment = dtaLeft
    Date = 38654
    Time = 38654
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 1
    OnChange = DateNachChange
  end
  object DateCon: TDateTimePicker
    Left = 264
    Top = 48
    Width = 153
    Height = 28
    CalAlignment = dtaLeft
    Date = 38654.9999884259
    Time = 38654.9999884259
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 2
    OnChange = DateConChange
  end
  object ButtonClose: TButton
    Left = 296
    Top = 136
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
  object BitBtnNachPerioda: TBitBtn
    Left = 193
    Top = 48
    Width = 28
    Height = 28
    TabOrder = 6
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
    Left = 416
    Top = 48
    Width = 28
    Height = 28
    TabOrder = 7
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
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 8
    Top = 192
  end
  object IBQ: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      '         select'
      
        'NAMEGRP_PROC, IDGRP_PROC, NAMENOM_PROC, IDNOM_PROC, NAMEED_PROC,' +
        ' IDED_PROC, NAMEPART_PROC, IDPART_PROC,'
      'SUM(PRIHOD_KOL) AS PRIHODKOL,'
      'SUM(PRIHOD_SUM) AS PRIHODSUM,'
      'SUM(RASHOD_KOL) AS RASHODKOL,'
      'SUM(RASHOD_SUM) AS RASHODSUM,'
      'SUM(PRIHOD_DO_CON_KOL) AS PR_DOCON_KOL,'
      'SUM(PRIHOD_DO_CON_SUM) AS PR_DOCON_SUM,'
      'SUM(RASHOD_DO_CON_KOL) AS RAS_DOCON_KOL,'
      'SUM(RASHOD_DO_CON_SUM) AS RAS_DOCON_SUM,'
      'SUM(TEC_OST_KOL) AS OSTKOL,'
      'SUM(TEC_OST_SUM) AS OSTSUM ,'
      
        '(SUM(TEC_OST_KOL)-SUM(PRIHOD_DO_CON_KOL)+SUM(RASHOD_DO_CON_KOL) ' +
        ' - SUM(PRIHOD_KOL)  +SUM(RASHOD_KOL)           )  AS  NACHOSTKOL' +
        ','
      
        '(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM) ' +
        ' -SUM(PRIHOD_SUM)  +SUM(RASHOD_SUM)           )  AS  NACHOSTSUM,'
      ''
      
        '(SUM(TEC_OST_KOL)-SUM(PRIHOD_DO_CON_KOL)+SUM(RASHOD_DO_CON_KOL) ' +
        '           )  AS  CONOSTKOL,'
      
        '(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM) ' +
        '        )  AS  CONOSTSUM'
      'from OCB_OST_PART_NOM (:DATENACH, :DATECON, :PAR_IDSKLAD)'
      ''
      
        'group by NAMEGRP_PROC, IDGRP_PROC, NAMENOM_PROC, IDNOM_PROC, NAM' +
        'EED_PROC, IDED_PROC, NAMEPART_PROC, IDPART_PROC'
      '')
    Left = 40
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'DATENACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'DATECON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PAR_IDSKLAD'
        ParamType = ptUnknown
      end>
    object IBQNAMEGRP_PROC: TIBStringField
      FieldName = 'NAMEGRP_PROC'
      Size = 100
    end
    object IBQIDGRP_PROC: TIntegerField
      FieldName = 'IDGRP_PROC'
    end
    object IBQNAMENOM_PROC: TIBStringField
      FieldName = 'NAMENOM_PROC'
      Size = 100
    end
    object IBQIDNOM_PROC: TIntegerField
      FieldName = 'IDNOM_PROC'
    end
    object IBQNAMEED_PROC: TIBStringField
      FieldName = 'NAMEED_PROC'
    end
    object IBQIDED_PROC: TIntegerField
      FieldName = 'IDED_PROC'
    end
    object IBQNAMEPART_PROC: TIBStringField
      FieldName = 'NAMEPART_PROC'
      Size = 100
    end
    object IBQIDPART_PROC: TIntegerField
      FieldName = 'IDPART_PROC'
    end
    object IBQPRIHODKOL: TIBBCDField
      FieldName = 'PRIHODKOL'
      Precision = 18
      Size = 3
    end
    object IBQPRIHODSUM: TIBBCDField
      FieldName = 'PRIHODSUM'
      Precision = 18
      Size = 2
    end
    object IBQRASHODKOL: TIBBCDField
      FieldName = 'RASHODKOL'
      Precision = 18
      Size = 3
    end
    object IBQRASHODSUM: TIBBCDField
      FieldName = 'RASHODSUM'
      Precision = 18
      Size = 2
    end
    object IBQNACHOSTKOL: TIBBCDField
      FieldName = 'NACHOSTKOL'
      Precision = 18
      Size = 3
    end
    object IBQNACHOSTSUM: TIBBCDField
      FieldName = 'NACHOSTSUM'
      Precision = 18
      Size = 2
    end
    object IBQCONOSTKOL: TIBBCDField
      FieldName = 'CONOSTKOL'
      Precision = 18
      Size = 3
    end
    object IBQCONOSTSUM: TIBBCDField
      FieldName = 'CONOSTSUM'
      Precision = 18
      Size = 2
    end
  end
end
