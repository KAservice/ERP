object DMSprFactor: TDMSprFactor
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SFACTOR'
      'SET '
      '    GID_SFACTOR = :GID_SFACTOR,'
      '    IDBASE_SFACTOR = :IDBASE_SFACTOR,'
      '    NAME_SFACTOR = :NAME_SFACTOR,'
      '    INDEX_SFACTOR = :INDEX_SFACTOR'
      'WHERE'
      '    ID_SFACTOR = :OLD_ID_SFACTOR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SFACTOR'
      'WHERE'
      '        ID_SFACTOR = :OLD_ID_SFACTOR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SFACTOR('
      '    ID_SFACTOR,'
      '    GID_SFACTOR,'
      '    IDBASE_SFACTOR,'
      '    NAME_SFACTOR,'
      '    INDEX_SFACTOR'
      ')'
      'VALUES('
      '    :ID_SFACTOR,'
      '    :GID_SFACTOR,'
      '    :IDBASE_SFACTOR,'
      '    :NAME_SFACTOR,'
      '    :INDEX_SFACTOR'
      ')')
    RefreshSQL.Strings = (
      'select  * from SFACTOR'
      ''
      ' WHERE '
      '        SFACTOR.ID_SFACTOR = :OLD_ID_SFACTOR'
      '    ')
    SelectSQL.Strings = (
      'select  * from SFACTOR')
    AutoUpdateOptions.UpdateTableName = 'SFACTOR'
    AutoUpdateOptions.KeyFields = 'ID_SFACTOR'
    AutoUpdateOptions.GeneratorName = 'GEN_SFACTOR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_SFACTOR: TFIBLargeIntField
      FieldName = 'ID_SFACTOR'
    end
    object TableGID_SFACTOR: TFIBWideStringField
      FieldName = 'GID_SFACTOR'
      Size = 10
    end
    object TableIDBASE_SFACTOR: TFIBLargeIntField
      FieldName = 'IDBASE_SFACTOR'
    end
    object TableNAME_SFACTOR: TFIBWideStringField
      FieldName = 'NAME_SFACTOR'
      Size = 200
    end
    object TableINDEX_SFACTOR: TFIBIntegerField
      FieldName = 'INDEX_SFACTOR'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SFACTOR'
      'SET '
      '    GID_SFACTOR = :GID_SFACTOR,'
      '    IDBASE_SFACTOR = :IDBASE_SFACTOR,'
      '    NAME_SFACTOR = :NAME_SFACTOR,'
      '    INDEX_SFACTOR = :INDEX_SFACTOR'
      'WHERE'
      '    ID_SFACTOR = :OLD_ID_SFACTOR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SFACTOR'
      'WHERE'
      '        ID_SFACTOR = :OLD_ID_SFACTOR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SFACTOR('
      '    ID_SFACTOR,'
      '    GID_SFACTOR,'
      '    IDBASE_SFACTOR,'
      '    NAME_SFACTOR,'
      '    INDEX_SFACTOR'
      ')'
      'VALUES('
      '    :ID_SFACTOR,'
      '    :GID_SFACTOR,'
      '    :IDBASE_SFACTOR,'
      '    :NAME_SFACTOR,'
      '    :INDEX_SFACTOR'
      ')')
    RefreshSQL.Strings = (
      'select * from SFACTOR'
      'where(  ID_SFACTOR=:PARAM_ID'
      '     ) and (     SFACTOR.ID_SFACTOR = :OLD_ID_SFACTOR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SFACTOR'
      'where ID_SFACTOR=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SFACTOR'
    AutoUpdateOptions.KeyFields = 'ID_SFACTOR'
    AutoUpdateOptions.GeneratorName = 'GEN_SFACTOR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    poUseLargeIntField = True
    object ElementID_SFACTOR: TFIBLargeIntField
      FieldName = 'ID_SFACTOR'
    end
    object ElementGID_SFACTOR: TFIBWideStringField
      FieldName = 'GID_SFACTOR'
      Size = 10
    end
    object ElementIDBASE_SFACTOR: TFIBLargeIntField
      FieldName = 'IDBASE_SFACTOR'
    end
    object ElementNAME_SFACTOR: TFIBWideStringField
      FieldName = 'NAME_SFACTOR'
      Size = 200
    end
    object ElementINDEX_SFACTOR: TFIBIntegerField
      FieldName = 'INDEX_SFACTOR'
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
