object FormaDialogaReportOCBVSRasch: TFormaDialogaReportOCBVSRasch
  Left = 466
  Top = 109
  Width = 460
  Height = 267
  Caption = #1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099' '#1089' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072#1084#1080'::'
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
    Width = 393
    Height = 29
    Caption = #1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099': '#1089' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072#1084#1080
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
    Left = 232
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
    Left = 32
    Top = 96
    Width = 64
    Height = 13
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090'::'
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
  object NameKlientEdit: TEdit
    Left = 96
    Top = 96
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 4
    Text = 'NameKlientEdit'
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
  object IBQKl: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      '         select'
      'NAMEKLIENT_PROC, IDKLIENT_PROC,'
      'SUM(PRIHOD_SUM) AS PRIHODSUM,'
      'SUM(RASHOD_SUM) AS RASHODSUM,'
      'SUM(PRIHOD_DO_CON_SUM) AS PR_DOCON_SUM,'
      'SUM(RASHOD_DO_CON_SUM) AS RAS_DOCON_SUM,'
      'SUM(TEC_OST_SUM) AS OSTSUM ,'
      
        '(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM) ' +
        ' -SUM(PRIHOD_SUM)  +SUM(RASHOD_SUM)           )  AS  NACHOSTSUM,'
      
        '(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM) ' +
        '        )  AS  CONOSTSUM'
      'from OCB_RGVSRASCH_PO_KLIENTAM_PROC(:DATENACH, :DATECON)'
      'group by NAMEKLIENT_PROC, IDKLIENT_PROC')
    Left = 56
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
      end>
    object IBQKlNAMEKLIENT_PROC: TIBStringField
      FieldName = 'NAMEKLIENT_PROC'
      Size = 50
    end
    object IBQKlIDKLIENT_PROC: TIntegerField
      FieldName = 'IDKLIENT_PROC'
    end
    object IBQKlPRIHODSUM: TIBBCDField
      FieldName = 'PRIHODSUM'
      Precision = 18
      Size = 2
    end
    object IBQKlRASHODSUM: TIBBCDField
      FieldName = 'RASHODSUM'
      Precision = 18
      Size = 2
    end
    object IBQKlNACHOSTSUM: TIBBCDField
      FieldName = 'NACHOSTSUM'
      Precision = 18
      Size = 2
    end
    object IBQKlCONOSTSUM: TIBBCDField
      FieldName = 'CONOSTSUM'
      Precision = 18
      Size = 2
    end
  end
  object IBQDoc: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select  POSDOC_VSRASCH_DV,SUM_VSRASCH_DV, TDV_VSRASCH_DV,'
      '  NUMDOC, TDOC'
      'from '
      '  RGVSRASCH_DV'
      'left outer join GALLDOC  on IDDOC_VSRASCH_DV=IDDOC '
      
        'where (IDKLIENT_VSRASCH_DV=:PARAM_IDKLIENT) AND (POSDOC_VSRASCH_' +
        'DV  between :PARAM_POSNACH and :PARAM_POSCON)'
      'order by POSDOC_VSRASCH_DV')
    Left = 88
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDKLIENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_POSNACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_POSCON'
        ParamType = ptUnknown
      end>
    object IBQDocPOSDOC_VSRASCH_DV: TDateTimeField
      FieldName = 'POSDOC_VSRASCH_DV'
      Origin = 'RGVSRASCH_DV.POSDOC_VSRASCH_DV'
    end
    object IBQDocSUM_VSRASCH_DV: TIBBCDField
      FieldName = 'SUM_VSRASCH_DV'
      Origin = 'RGVSRASCH_DV.SUM_VSRASCH_DV'
      Precision = 18
      Size = 2
    end
    object IBQDocNUMDOC: TIntegerField
      FieldName = 'NUMDOC'
      Origin = 'GALLDOC.NUMDOC'
    end
    object IBQDocTDOC: TIBStringField
      FieldName = 'TDOC'
      Origin = 'GALLDOC.TDOC'
      Size = 10
    end
    object IBQDocTDV_VSRASCH_DV: TSmallintField
      FieldName = 'TDV_VSRASCH_DV'
      Origin = 'RGVSRASCH_DV.TDV_VSRASCH_DV'
    end
  end
end
