object FormaReportRasmHotel: TFormaReportRasmHotel
  Left = 323
  Top = 125
  Width = 429
  Height = 238
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1073#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1080' '#1084#1077#1089#1090':'
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
    Width = 338
    Height = 29
    Caption = #1054#1090#1095#1077#1090' '#1086' '#1088#1072#1079#1084#1077#1097#1077#1085#1080#1080' '#1075#1086#1089#1090#1077#1081':'
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
    Left = 200
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
  object ButtonRun: TButton
    Left = 192
    Top = 160
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
  end
  object DateCon: TDateTimePicker
    Left = 240
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
    TabOrder = 2
  end
  object ButtonClose: TButton
    Left = 288
    Top = 160
    Width = 97
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
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
    Top = 168
  end
  object IBQRegRasm: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select RGRASM.*, NAME_NOMHOT, KOLM_NOMHOT, NAMEKLIENT, NAME_ZRAS' +
        'M '
      'from '
      'RGRASM'
      'left outer join SNOMHOT on IDNOMER_RGRASM=ID_NOMHOT'
      'left outer join SKLIENT on  IDGOST_RGRASM=IDKLIENT'
      'left outer join SZRASM on IDZRASM_RGRASM=ID_ZRASM'
      'order by NAME_NOMHOT')
    Left = 56
    Top = 168
    object IBQRegRasmID_RGRASM: TIntegerField
      FieldName = 'ID_RGRASM'
      Origin = 'RGRASM.ID_RGRASM'
      Required = True
    end
    object IBQRegRasmIDZRASM_RGRASM: TIntegerField
      FieldName = 'IDZRASM_RGRASM'
      Origin = 'RGRASM.IDZRASM_RGRASM'
    end
    object IBQRegRasmIDPLAT_RGRASM: TIntegerField
      FieldName = 'IDPLAT_RGRASM'
      Origin = 'RGRASM.IDPLAT_RGRASM'
    end
    object IBQRegRasmIDGOST_RGRASM: TIntegerField
      FieldName = 'IDGOST_RGRASM'
      Origin = 'RGRASM.IDGOST_RGRASM'
    end
    object IBQRegRasmIDNOMER_RGRASM: TIntegerField
      FieldName = 'IDNOMER_RGRASM'
      Origin = 'RGRASM.IDNOMER_RGRASM'
    end
    object IBQRegRasmPOSCON_RGRASM: TDateTimeField
      FieldName = 'POSCON_RGRASM'
      Origin = 'RGRASM.POSCON_RGRASM'
    end
    object IBQRegRasmKOLMEST_RGRASM: TSmallintField
      FieldName = 'KOLMEST_RGRASM'
      Origin = 'RGRASM.KOLMEST_RGRASM'
    end
    object IBQRegRasmACTIVE_RGRASM: TSmallintField
      FieldName = 'ACTIVE_RGRASM'
      Origin = 'RGRASM.ACTIVE_RGRASM'
    end
    object IBQRegRasmNAME_NOMHOT: TIBStringField
      FieldName = 'NAME_NOMHOT'
      Origin = 'SNOMHOT.NAME_NOMHOT'
      Size = 50
    end
    object IBQRegRasmKOLM_NOMHOT: TIntegerField
      FieldName = 'KOLM_NOMHOT'
      Origin = 'SNOMHOT.KOLM_NOMHOT'
    end
    object IBQRegRasmNAMEKLIENT: TIBStringField
      FieldName = 'NAMEKLIENT'
      Origin = 'SKLIENT.NAMEKLIENT'
      Size = 50
    end
    object IBQRegRasmNAME_ZRASM: TIBStringField
      FieldName = 'NAME_ZRASM'
      Origin = 'SZRASM.NAME_ZRASM'
      Size = 50
    end
  end
end
