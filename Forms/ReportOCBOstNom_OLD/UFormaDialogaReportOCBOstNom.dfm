object FormaDialogaReportOCBOstNom: TFormaDialogaReportOCBOstNom
  Left = 249
  Top = 136
  Caption = #1054#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1090#1086#1074#1072#1088#1086#1074' '#1087#1086' '#1089#1082#1083#1072#1076#1091':'
  ClientHeight = 272
  ClientWidth = 606
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
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 30
    Top = 10
    Width = 408
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103'  '#1080' '#1090#1086#1074#1072#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 20
    Top = 59
    Width = 14
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 286
    Top = 59
    Width = 32
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 79
    Top = 148
    Width = 43
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1083#1072#1076':'
  end
  object PosNachLabel: TLabel
    Left = 49
    Top = 98
    Width = 90
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'PosNachLabel'
  end
  object PosConLabel: TLabel
    Left = 325
    Top = 98
    Width = 82
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'PosConLabel'
  end
  object GrPosledLabel: TLabel
    Left = 0
    Top = 236
    Width = 105
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'GrPosledLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ButtonRun: TButton
    Left = 256
    Top = 187
    Width = 112
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonRunClick
  end
  object DateNach: TDateTimePicker
    Left = 49
    Top = 59
    Width = 189
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Date = 38654.000000000000000000
    Time = 38654.000000000000000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnChange = DateNachChange
  end
  object DateCon: TDateTimePicker
    Left = 325
    Top = 59
    Width = 188
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    BevelOuter = bvNone
    Date = 38654.999988425900000000
    Time = 38654.999988425900000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnChange = DateConChange
  end
  object ButtonClose: TButton
    Left = 384
    Top = 187
    Width = 119
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
  end
  object NameSkladEdit: TEdit
    Left = 138
    Top = 138
    Width = 336
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Color = clBtnFace
    TabOrder = 4
    Text = 'NameSkladEdit'
  end
  object ButtonViborSklad: TButton
    Left = 473
    Top = 138
    Width = 25
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonViborSkladClick
  end
  object BitBtnConPerioda: TBitBtn
    Left = 512
    Top = 59
    Width = 34
    Height = 35
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DoubleBuffered = True
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
    ParentDoubleBuffered = False
    TabOrder = 6
    OnClick = BitBtnConPeriodaClick
  end
  object BitBtnNachPerioda: TBitBtn
    Left = 238
    Top = 59
    Width = 34
    Height = 35
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DoubleBuffered = True
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
    ParentDoubleBuffered = False
    TabOrder = 7
    OnClick = BitBtnNachPeriodaClick
  end
  object IBQSkl: TpFIBDataSet
    SelectSQL.Strings = (
      '         select'
      'NAMESKLAD, IDSKLAD,'
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
      'from OCB_OSTNOM_PO_SKLADAM_PROC (:DATENACH, :DATECON)'
      'group by NAMESKLAD, IDSKLAD')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 56
    Top = 152
    object IBQSklNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQSklPRIHODKOL: TFIBBCDField
      FieldName = 'PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklPRIHODSUM: TFIBBCDField
      FieldName = 'PRIHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklRASHODKOL: TFIBBCDField
      FieldName = 'RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklRASHODSUM: TFIBBCDField
      FieldName = 'RASHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklPR_DOCON_KOL: TFIBBCDField
      FieldName = 'PR_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklPR_DOCON_SUM: TFIBBCDField
      FieldName = 'PR_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklRAS_DOCON_KOL: TFIBBCDField
      FieldName = 'RAS_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklRAS_DOCON_SUM: TFIBBCDField
      FieldName = 'RAS_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklOSTKOL: TFIBBCDField
      FieldName = 'OSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklOSTSUM: TFIBBCDField
      FieldName = 'OSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklNACHOSTKOL: TFIBBCDField
      FieldName = 'NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklNACHOSTSUM: TFIBBCDField
      FieldName = 'NACHOSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklCONOSTKOL: TFIBBCDField
      FieldName = 'CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQSklCONOSTSUM: TFIBBCDField
      FieldName = 'CONOSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQSklIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
  end
  object IBQGrp: TpFIBDataSet
    SelectSQL.Strings = (
      '       select'
      'NAMEGN, IDGN,'
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
      
        'from OCB_OSTNOM_PO_GRPNOM_PROC ( :DATENACH, :DATECON,:PAR_IDSKLA' +
        'D)'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 88
    Top = 152
    object IBQGrpNAMEGN: TFIBStringField
      FieldName = 'NAMEGN'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQGrpPRIHODKOL: TFIBBCDField
      FieldName = 'PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpPRIHODSUM: TFIBBCDField
      FieldName = 'PRIHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpRASHODKOL: TFIBBCDField
      FieldName = 'RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpRASHODSUM: TFIBBCDField
      FieldName = 'RASHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpPR_DOCON_KOL: TFIBBCDField
      FieldName = 'PR_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpPR_DOCON_SUM: TFIBBCDField
      FieldName = 'PR_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpRAS_DOCON_KOL: TFIBBCDField
      FieldName = 'RAS_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpRAS_DOCON_SUM: TFIBBCDField
      FieldName = 'RAS_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpOSTKOL: TFIBBCDField
      FieldName = 'OSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpOSTSUM: TFIBBCDField
      FieldName = 'OSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpNACHOSTKOL: TFIBBCDField
      FieldName = 'NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpNACHOSTSUM: TFIBBCDField
      FieldName = 'NACHOSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpCONOSTKOL: TFIBBCDField
      FieldName = 'CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQGrpCONOSTSUM: TFIBBCDField
      FieldName = 'CONOSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQGrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
  end
  object IBQEl: TpFIBDataSet
    SelectSQL.Strings = (
      '         select'
      'NAME, NAMEED,'
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
      
        'from OCB_OSTNOM_PO_NOM_PROC (:DATENACH, :DATECON, :PAR_IDSKLAD, ' +
        ':PAR_IDGRPNOM)'
      'left outer join SNOM on IDNOMENKL=IDNOM'
      'left outer join SED on IDBASEDNOM=IDED'
      'group by NAME, NAMEED')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 120
    Top = 152
    object IBQElNAME: TFIBStringField
      FieldName = 'NAME'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQElPRIHODKOL: TFIBBCDField
      FieldName = 'PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElPRIHODSUM: TFIBBCDField
      FieldName = 'PRIHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElRASHODKOL: TFIBBCDField
      FieldName = 'RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElRASHODSUM: TFIBBCDField
      FieldName = 'RASHODSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElPR_DOCON_KOL: TFIBBCDField
      FieldName = 'PR_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElPR_DOCON_SUM: TFIBBCDField
      FieldName = 'PR_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElRAS_DOCON_KOL: TFIBBCDField
      FieldName = 'RAS_DOCON_KOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElRAS_DOCON_SUM: TFIBBCDField
      FieldName = 'RAS_DOCON_SUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElOSTKOL: TFIBBCDField
      FieldName = 'OSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElOSTSUM: TFIBBCDField
      FieldName = 'OSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElNACHOSTKOL: TFIBBCDField
      FieldName = 'NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElNACHOSTSUM: TFIBBCDField
      FieldName = 'NACHOSTSUM'
      Size = 2
      RoundByScale = True
    end
    object IBQElCONOSTKOL: TFIBBCDField
      FieldName = 'CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQElCONOSTSUM: TFIBBCDField
      FieldName = 'CONOSTSUM'
      Size = 2
      RoundByScale = True
    end
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
    Top = 152
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
