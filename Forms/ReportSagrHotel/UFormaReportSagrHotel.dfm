object FormaReportSagrHotel: TFormaReportSagrHotel
  Left = 313
  Top = 69
  Width = 455
  Height = 280
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1079#1072#1075#1088#1091#1078#1077#1085#1085#1086#1089#1090#1080' '#1075#1086#1089#1090#1080#1085#1080#1094#1099
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
    Left = 40
    Top = 16
    Width = 317
    Height = 24
    Caption = #1054#1090#1095#1077#1090' '#1086' '#1079#1072#1075#1088#1091#1078#1077#1085#1085#1086#1089#1090#1080' '#1075#1086#1089#1090#1080#1085#1080#1094#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 64
    Top = 64
    Width = 10
    Height = 24
    Caption = #1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 200
    Top = 64
    Width = 22
    Height = 24
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 120
    Width = 56
    Height = 13
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
    FocusControl = NameCatNomDBEdit
  end
  object ButtonClose: TButton
    Left = 304
    Top = 152
    Width = 83
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 0
    OnClick = ButtonCloseClick
  end
  object ButtonCreate: TButton
    Left = 208
    Top = 152
    Width = 83
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 1
    OnClick = ButtonCreateClick
  end
  object DateNach: TDateTimePicker
    Left = 88
    Top = 64
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 38676
    Time = 38676
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object DateCon: TDateTimePicker
    Left = 232
    Top = 64
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 38676
    Time = 38676
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
  end
  object NameCatNomDBEdit: TDBEdit
    Left = 72
    Top = 112
    Width = 294
    Height = 21
    DataField = 'NAME_CATNOM'
    DataSource = DataSourceCatNom
    TabOrder = 4
  end
  object ButtonOpenCatNom: TButton
    Left = 360
    Top = 112
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonOpenCatNomClick
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    DefaultAction = TARollback
    Params.Strings = (
      'read'
      'consistency')
    AutoStopAction = saNone
    Left = 8
    Top = 8
  end
  object IBQCatNom: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from SCATNOM where ID_CATNOM=:PARAM_ID')
    Left = 280
    Top = 104
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_ID'
        ParamType = ptUnknown
      end>
    object IBQCatNomID_CATNOM: TIntegerField
      FieldName = 'ID_CATNOM'
      Origin = 'SCATNOM.ID_CATNOM'
      Required = True
    end
    object IBQCatNomIDNOM_CATNOM: TIntegerField
      FieldName = 'IDNOM_CATNOM'
      Origin = 'SCATNOM.IDNOM_CATNOM'
    end
    object IBQCatNomNAME_CATNOM: TIBStringField
      FieldName = 'NAME_CATNOM'
      Origin = 'SCATNOM.NAME_CATNOM'
      Size = 50
    end
    object IBQCatNomKOL_CATNOM: TIntegerField
      FieldName = 'KOL_CATNOM'
      Origin = 'SCATNOM.KOL_CATNOM'
    end
  end
  object DataSourceCatNom: TDataSource
    DataSet = IBQCatNom
    Left = 312
    Top = 104
  end
  object IBQNom: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select SNOMHOT.*, NAME_CATNOM'
      '   from SNOMHOT '
      'left outer join SCATNOM on IDCAT_NOMHOT=ID_CATNOM'
      'where IDCAT_NOMHOT=:PARAM_IDCAT'
      'order by NAME_CATNOM')
    Top = 160
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDCAT'
        ParamType = ptUnknown
      end>
    object IBQNomID_NOMHOT: TIntegerField
      FieldName = 'ID_NOMHOT'
      Origin = 'SNOMHOT.ID_NOMHOT'
      Required = True
    end
    object IBQNomIDCAT_NOMHOT: TIntegerField
      FieldName = 'IDCAT_NOMHOT'
      Origin = 'SNOMHOT.IDCAT_NOMHOT'
    end
    object IBQNomNAME_NOMHOT: TIBStringField
      FieldName = 'NAME_NOMHOT'
      Origin = 'SNOMHOT.NAME_NOMHOT'
      Size = 50
    end
    object IBQNomKOLM_NOMHOT: TIntegerField
      FieldName = 'KOLM_NOMHOT'
      Origin = 'SNOMHOT.KOLM_NOMHOT'
    end
    object IBQNomNAME_CATNOM: TIBStringField
      FieldName = 'NAME_CATNOM'
      Origin = 'SCATNOM.NAME_CATNOM'
      Size = 50
    end
  end
  object DataSource1: TDataSource
    DataSet = IBQNom
    Left = 32
    Top = 160
  end
  object CatNom: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from SCATNOM')
    Top = 200
    object CatNomID_CATNOM: TIntegerField
      FieldName = 'ID_CATNOM'
      Origin = 'SCATNOM.ID_CATNOM'
      Required = True
    end
    object CatNomIDNOM_CATNOM: TIntegerField
      FieldName = 'IDNOM_CATNOM'
      Origin = 'SCATNOM.IDNOM_CATNOM'
    end
    object CatNomNAME_CATNOM: TIBStringField
      FieldName = 'NAME_CATNOM'
      Origin = 'SCATNOM.NAME_CATNOM'
      Size = 50
    end
    object CatNomKOL_CATNOM: TIntegerField
      FieldName = 'KOL_CATNOM'
      Origin = 'SCATNOM.KOL_CATNOM'
    end
  end
  object RegBron: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * '
      'from '
      'RGBRON'
      'where IDNOMER_RGBRON=:PARAM_IDNOMER'
      'and '
      '('
      '(:NACH < POSNACH_RGBRON and POSNACH_RGBRON <= :CON)   OR'
      '(:NACH < POSCON_RGBRON and POSCON_RGBRON <=  :CON)  OR'
      '('
      '(:NACH between POSNACH_RGBRON  and POSCON_RGBRON)'
      'and '
      '(:CON between POSNACH_RGBRON  and POSCON_RGBRON)'
      '))')
    Left = 104
    Top = 208
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDNOMER'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end>
    object RegBronID_RGBRON: TIntegerField
      FieldName = 'ID_RGBRON'
      Origin = 'RGBRON.ID_RGBRON'
      Required = True
    end
    object RegBronIDZBRON_RGBRON: TIntegerField
      FieldName = 'IDZBRON_RGBRON'
      Origin = 'RGBRON.IDZBRON_RGBRON'
    end
    object RegBronIDPLAT_RGBRON: TIntegerField
      FieldName = 'IDPLAT_RGBRON'
      Origin = 'RGBRON.IDPLAT_RGBRON'
    end
    object RegBronIDGOST_RGBRON: TIntegerField
      FieldName = 'IDGOST_RGBRON'
      Origin = 'RGBRON.IDGOST_RGBRON'
    end
    object RegBronIDNOMER_RGBRON: TIntegerField
      FieldName = 'IDNOMER_RGBRON'
      Origin = 'RGBRON.IDNOMER_RGBRON'
    end
    object RegBronPOSNACH_RGBRON: TDateTimeField
      FieldName = 'POSNACH_RGBRON'
      Origin = 'RGBRON.POSNACH_RGBRON'
    end
    object RegBronPOSCON_RGBRON: TDateTimeField
      FieldName = 'POSCON_RGBRON'
      Origin = 'RGBRON.POSCON_RGBRON'
    end
    object RegBronKOLMEST_RGBRON: TSmallintField
      FieldName = 'KOLMEST_RGBRON'
      Origin = 'RGBRON.KOLMEST_RGBRON'
    end
    object RegBronACTIVE_RGBRON: TSmallintField
      FieldName = 'ACTIVE_RGBRON'
      Origin = 'RGBRON.ACTIVE_RGBRON'
    end
  end
  object RegRasm: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * '
      'from '
      'RGRASM'
      'where IDNOMER_RGRASM=:PARAM_IDNOMER'
      'and '
      '('
      '(:NACH < POSNACH_RGRASM and POSNACH_RGRASM <= :CON  )  OR'
      '(:NACH < POSCON_RGRASM and  POSCON_RGRASM <= :CON )  OR'
      '('
      '(:NACH between POSNACH_RGRASM  and POSCON_RGRASM)'
      'and '
      '(:CON between POSNACH_RGRASM  and POSCON_RGRASM)'
      '))')
    Left = 144
    Top = 208
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDNOMER'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CON'
        ParamType = ptUnknown
      end>
    object RegRasmID_RGRASM: TIntegerField
      FieldName = 'ID_RGRASM'
      Origin = 'RGRASM.ID_RGRASM'
      Required = True
    end
    object RegRasmIDZRASM_RGRASM: TIntegerField
      FieldName = 'IDZRASM_RGRASM'
      Origin = 'RGRASM.IDZRASM_RGRASM'
    end
    object RegRasmIDPLAT_RGRASM: TIntegerField
      FieldName = 'IDPLAT_RGRASM'
      Origin = 'RGRASM.IDPLAT_RGRASM'
    end
    object RegRasmIDGOST_RGRASM: TIntegerField
      FieldName = 'IDGOST_RGRASM'
      Origin = 'RGRASM.IDGOST_RGRASM'
    end
    object RegRasmIDNOMER_RGRASM: TIntegerField
      FieldName = 'IDNOMER_RGRASM'
      Origin = 'RGRASM.IDNOMER_RGRASM'
    end
    object RegRasmPOSNACH_RGRASM: TDateTimeField
      FieldName = 'POSNACH_RGRASM'
      Origin = 'RGRASM.POSNACH_RGRASM'
    end
    object RegRasmPOSCON_RGRASM: TDateTimeField
      FieldName = 'POSCON_RGRASM'
      Origin = 'RGRASM.POSCON_RGRASM'
    end
    object RegRasmKOLMEST_RGRASM: TSmallintField
      FieldName = 'KOLMEST_RGRASM'
      Origin = 'RGRASM.KOLMEST_RGRASM'
    end
    object RegRasmACTIVE_RGRASM: TSmallintField
      FieldName = 'ACTIVE_RGRASM'
      Origin = 'RGRASM.ACTIVE_RGRASM'
    end
  end
end
