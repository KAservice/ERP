object DMSprNachisl: TDMSprNachisl
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 345
  Width = 510
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNACHISL'
      'SET '
      '    IDBASE_SNACHISL = :IDBASE_SNACHISL,'
      '    GID_SNACHISL = :GID_SNACHISL,'
      '    IDNOM_SNACHISL = :IDNOM_SNACHISL,'
      '    IDTNACH_SNACHISL = :IDTNACH_SNACHISL,'
      '    VALUE_SNACHISL = :VALUE_SNACHISL'
      'WHERE'
      '    ID_SNACHISL = :OLD_ID_SNACHISL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNACHISL'
      'WHERE'
      '        ID_SNACHISL = :OLD_ID_SNACHISL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNACHISL('
      '    ID_SNACHISL,'
      '    IDBASE_SNACHISL,'
      '    GID_SNACHISL,'
      '    IDNOM_SNACHISL,'
      '    IDTNACH_SNACHISL,'
      '    VALUE_SNACHISL'
      ')'
      'VALUES('
      '    :ID_SNACHISL,'
      '    :IDBASE_SNACHISL,'
      '    :GID_SNACHISL,'
      '    :IDNOM_SNACHISL,'
      '    :IDTNACH_SNACHISL,'
      '    :VALUE_SNACHISL'
      ')')
    RefreshSQL.Strings = (
      'select        snachisl.*,'
      '        stnachisl.name_stnachisl'
      'from '
      '  snachisl'
      
        'left outer join stnachisl on snachisl.idtnach_snachisl=stnachisl' +
        '.id_stnachisl'
      'where(  '
      '  snachisl.idnom_snachisl=:PARAM_IDNOM'
      '     ) and (     SNACHISL.ID_SNACHISL = :OLD_ID_SNACHISL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select        snachisl.*,'
      '        stnachisl.name_stnachisl'
      'from '
      '  snachisl'
      
        'left outer join stnachisl on snachisl.idtnach_snachisl=stnachisl' +
        '.id_stnachisl'
      'where '
      '  snachisl.idnom_snachisl=:PARAM_IDNOM'
      'order by stnachisl.name_stnachisl'
      '')
    AutoUpdateOptions.UpdateTableName = 'SNACHISL'
    AutoUpdateOptions.KeyFields = 'ID_SNACHISL'
    AutoUpdateOptions.GeneratorName = 'GEN_SNACHISL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_SNACHISL: TFIBLargeIntField
      FieldName = 'ID_SNACHISL'
    end
    object TableIDBASE_SNACHISL: TFIBLargeIntField
      FieldName = 'IDBASE_SNACHISL'
    end
    object TableGID_SNACHISL: TFIBWideStringField
      FieldName = 'GID_SNACHISL'
      Size = 10
    end
    object TableIDNOM_SNACHISL: TFIBLargeIntField
      FieldName = 'IDNOM_SNACHISL'
    end
    object TableIDTNACH_SNACHISL: TFIBLargeIntField
      FieldName = 'IDTNACH_SNACHISL'
    end
    object TableVALUE_SNACHISL: TFIBBCDField
      FieldName = 'VALUE_SNACHISL'
      Size = 2
      RoundByScale = True
    end
    object TableNAME_STNACHISL: TFIBWideStringField
      FieldName = 'NAME_STNACHISL'
      Size = 200
    end
    object TableNAME_TYPE_NACHISL_LOOKUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NACHISL_LOOKUP'
      LookupDataSet = TypeNachisl
      LookupKeyFields = 'ID_STNACHISL'
      LookupResultField = 'NAME_STNACHISL'
      KeyFields = 'IDTNACH_SNACHISL'
      Lookup = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNACHISL'
      'SET '
      '    IDBASE_SNACHISL = :IDBASE_SNACHISL,'
      '    GID_SNACHISL = :GID_SNACHISL,'
      '    IDNOM_SNACHISL = :IDNOM_SNACHISL,'
      '    IDTNACH_SNACHISL = :IDTNACH_SNACHISL,'
      '    VALUE_SNACHISL = :VALUE_SNACHISL'
      'WHERE'
      '    ID_SNACHISL = :OLD_ID_SNACHISL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNACHISL'
      'WHERE'
      '        ID_SNACHISL = :OLD_ID_SNACHISL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNACHISL('
      '    ID_SNACHISL,'
      '    IDBASE_SNACHISL,'
      '    GID_SNACHISL,'
      '    IDNOM_SNACHISL,'
      '    IDTNACH_SNACHISL,'
      '    VALUE_SNACHISL'
      ')'
      'VALUES('
      '    :ID_SNACHISL,'
      '    :IDBASE_SNACHISL,'
      '    :GID_SNACHISL,'
      '    :IDNOM_SNACHISL,'
      '    :IDTNACH_SNACHISL,'
      '    :VALUE_SNACHISL'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  snachisl'
      'where(  snachisl.id_snachisl=:PARAM_ID'
      '     ) and (     SNACHISL.ID_SNACHISL = :OLD_ID_SNACHISL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  snachisl'
      'where snachisl.id_snachisl=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNACHISL'
    AutoUpdateOptions.KeyFields = 'ID_SNACHISL'
    AutoUpdateOptions.GeneratorName = 'GEN_SNACHISL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementID_SNACHISL: TFIBBCDField
      FieldName = 'ID_SNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SNACHISL: TFIBBCDField
      FieldName = 'IDBASE_SNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SNACHISL: TFIBWideStringField
      FieldName = 'GID_SNACHISL'
      Size = 10
    end
    object ElementIDNOM_SNACHISL: TFIBBCDField
      FieldName = 'IDNOM_SNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTNACH_SNACHISL: TFIBBCDField
      FieldName = 'IDTNACH_SNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementVALUE_SNACHISL: TFIBBCDField
      FieldName = 'VALUE_SNACHISL'
      Size = 2
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 72
  end
  object TypeNachisl: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnachisl.id_stnachisl,'
      '       stnachisl.name_stnachisl'
      'from stnachisl')
    Transaction = IBTr
    Left = 152
    Top = 136
    poUseLargeIntField = True
    object TypeNachislID_STNACHISL: TFIBLargeIntField
      FieldName = 'ID_STNACHISL'
    end
    object TypeNachislNAME_STNACHISL: TFIBWideStringField
      FieldName = 'NAME_STNACHISL'
      Size = 200
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 248
    Top = 144
    qoStartTransaction = True
  end
end
