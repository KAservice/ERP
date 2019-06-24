object DMSprTypeAnalog: TDMSprTypeAnalog
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 304
  Width = 551
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourcePodr: TDataSource
    AutoEdit = False
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE STYPE_ANALOG'
      'SET '
      '    IDBASE_STYPE_ANALOG = :IDBASE_STYPE_ANALOG,'
      '    GID_STYPE_ANALOG = :GID_STYPE_ANALOG,'
      '    NAME_STYPE_ANALOG = :NAME_STYPE_ANALOG'
      'WHERE'
      '    ID_STYPE_ANALOG = :OLD_ID_STYPE_ANALOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STYPE_ANALOG'
      'WHERE'
      '        ID_STYPE_ANALOG = :OLD_ID_STYPE_ANALOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STYPE_ANALOG('
      '    ID_STYPE_ANALOG,'
      '    IDBASE_STYPE_ANALOG,'
      '    GID_STYPE_ANALOG,'
      '    NAME_STYPE_ANALOG'
      ')'
      'VALUES('
      '    :ID_STYPE_ANALOG,'
      '    :IDBASE_STYPE_ANALOG,'
      '    :GID_STYPE_ANALOG,'
      '    :NAME_STYPE_ANALOG'
      ')')
    RefreshSQL.Strings = (
      'select stype_analog.*'
      'from stype_analog'
      ''
      ' WHERE '
      '        STYPE_ANALOG.ID_STYPE_ANALOG = :OLD_ID_STYPE_ANALOG'
      '    ')
    SelectSQL.Strings = (
      'select stype_analog.*'
      'from stype_analog'
      'order by stype_analog.name_stype_analog')
    AutoUpdateOptions.UpdateTableName = 'STYPE_ANALOG'
    AutoUpdateOptions.KeyFields = 'ID_STYPE_ANALOG'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPE_ANALOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STYPE_ANALOG: TFIBLargeIntField
      FieldName = 'ID_STYPE_ANALOG'
    end
    object TableIDBASE_STYPE_ANALOG: TFIBLargeIntField
      FieldName = 'IDBASE_STYPE_ANALOG'
    end
    object TableGID_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'GID_STYPE_ANALOG'
      Size = 10
    end
    object TableNAME_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'NAME_STYPE_ANALOG'
      Size = 200
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
    Left = 272
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
    Left = 272
    Top = 72
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE STYPE_ANALOG'
      'SET '
      '    IDBASE_STYPE_ANALOG = :IDBASE_STYPE_ANALOG,'
      '    GID_STYPE_ANALOG = :GID_STYPE_ANALOG,'
      '    NAME_STYPE_ANALOG = :NAME_STYPE_ANALOG'
      'WHERE'
      '    ID_STYPE_ANALOG = :OLD_ID_STYPE_ANALOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STYPE_ANALOG'
      'WHERE'
      '        ID_STYPE_ANALOG = :OLD_ID_STYPE_ANALOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STYPE_ANALOG('
      '    ID_STYPE_ANALOG,'
      '    IDBASE_STYPE_ANALOG,'
      '    GID_STYPE_ANALOG,'
      '    NAME_STYPE_ANALOG'
      ')'
      'VALUES('
      '    :ID_STYPE_ANALOG,'
      '    :IDBASE_STYPE_ANALOG,'
      '    :GID_STYPE_ANALOG,'
      '    :NAME_STYPE_ANALOG'
      ')')
    RefreshSQL.Strings = (
      'select stype_analog.*'
      'from stype_analog'
      'where(  stype_analog.id_stype_analog=:PARAM_ID'
      
        '     ) and (     STYPE_ANALOG.ID_STYPE_ANALOG = :OLD_ID_STYPE_AN' +
        'ALOG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select stype_analog.*'
      'from stype_analog'
      'where stype_analog.id_stype_analog=:PARAM_ID'
      'order by stype_analog.name_stype_analog')
    AutoUpdateOptions.UpdateTableName = 'STYPE_ANALOG'
    AutoUpdateOptions.KeyFields = 'ID_STYPE_ANALOG'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPE_ANALOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_STYPE_ANALOG: TFIBLargeIntField
      FieldName = 'ID_STYPE_ANALOG'
    end
    object ElementIDBASE_STYPE_ANALOG: TFIBLargeIntField
      FieldName = 'IDBASE_STYPE_ANALOG'
    end
    object ElementGID_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'GID_STYPE_ANALOG'
      Size = 10
    end
    object ElementNAME_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'NAME_STYPE_ANALOG'
      Size = 200
    end
  end
end
