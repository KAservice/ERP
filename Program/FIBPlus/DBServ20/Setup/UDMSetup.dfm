object DMSetup: TDMSetup
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 325
  Width = 385
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 192
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 192
    Top = 64
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SETUP'
      'SET '
      '    DESCRIPTION_SETUP = :DESCRIPTION_SETUP,'
      '    VALUE_SETUP = :VALUE_SETUP,'
      '    GID_SETUP = :GID_SETUP,'
      '    IDBASE_SETUP = :IDBASE_SETUP,'
      '    VALUE_TIMESTAMP_SETUP = :VALUE_TIMESTAMP_SETUP,'
      '    TYPE_VALUE_SETUP = :TYPE_VALUE_SETUP'
      'WHERE'
      '    ID_SETUP = :OLD_ID_SETUP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SETUP'
      'WHERE'
      '        ID_SETUP = :OLD_ID_SETUP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SETUP('
      '    ID_SETUP,'
      '    DESCRIPTION_SETUP,'
      '    VALUE_SETUP,'
      '    GID_SETUP,'
      '    IDBASE_SETUP,'
      '    VALUE_TIMESTAMP_SETUP,'
      '    TYPE_VALUE_SETUP'
      ')'
      'VALUES('
      '    :ID_SETUP,'
      '    :DESCRIPTION_SETUP,'
      '    :VALUE_SETUP,'
      '    :GID_SETUP,'
      '    :IDBASE_SETUP,'
      '    :VALUE_TIMESTAMP_SETUP,'
      '    :TYPE_VALUE_SETUP'
      ')')
    RefreshSQL.Strings = (
      'select  *'
      'from   SETUP'
      ''
      ' WHERE '
      '        SETUP.ID_SETUP = :OLD_ID_SETUP'
      '    ')
    SelectSQL.Strings = (
      'select  *'
      'from   SETUP'
      'order by ID_SETUP')
    AutoUpdateOptions.UpdateTableName = 'SETUP'
    AutoUpdateOptions.KeyFields = 'ID_SETUP'
    AutoUpdateOptions.GeneratorName = 'GEN_SETUP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 16
    object TableID_SETUP: TFIBBCDField
      FieldName = 'ID_SETUP'
      Size = 0
      RoundByScale = True
    end
    object TableDESCRIPTION_SETUP: TFIBStringField
      FieldName = 'DESCRIPTION_SETUP'
      Size = 50
      EmptyStrToNull = True
    end
    object TableVALUE_SETUP: TFIBStringField
      FieldName = 'VALUE_SETUP'
      Size = 50
      EmptyStrToNull = True
    end
    object TableGID_SETUP: TFIBStringField
      FieldName = 'GID_SETUP'
      Size = 10
      EmptyStrToNull = True
    end
    object TableVALUE_TIMESTAMP_SETUP: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_SETUP'
      DisplayFormat = 'c'
    end
    object TableTYPE_VALUE_SETUP: TFIBSmallIntField
      FieldName = 'TYPE_VALUE_SETUP'
      OnGetText = TableTYPE_VALUE_SETUPGetText
      OnSetText = TableTYPE_VALUE_SETUPSetText
    end
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SETUP'
      'SET '
      '    DESCRIPTION_SETUP = :DESCRIPTION_SETUP,'
      '    VALUE_SETUP = :VALUE_SETUP,'
      '    GID_SETUP = :GID_SETUP,'
      '    IDBASE_SETUP = :IDBASE_SETUP,'
      '    VALUE_TIMESTAMP_SETUP = :VALUE_TIMESTAMP_SETUP,'
      '    TYPE_VALUE_SETUP = :TYPE_VALUE_SETUP'
      'WHERE'
      '    ID_SETUP = :OLD_ID_SETUP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SETUP'
      'WHERE'
      '        ID_SETUP = :OLD_ID_SETUP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SETUP('
      '    ID_SETUP,'
      '    DESCRIPTION_SETUP,'
      '    VALUE_SETUP,'
      '    GID_SETUP,'
      '    IDBASE_SETUP,'
      '    VALUE_TIMESTAMP_SETUP,'
      '    TYPE_VALUE_SETUP'
      ')'
      'VALUES('
      '    :ID_SETUP,'
      '    :DESCRIPTION_SETUP,'
      '    :VALUE_SETUP,'
      '    :GID_SETUP,'
      '    :IDBASE_SETUP,'
      '    :VALUE_TIMESTAMP_SETUP,'
      '    :TYPE_VALUE_SETUP'
      ')')
    RefreshSQL.Strings = (
      'select * from SETUP'
      'where(  ID_SETUP=:PARAM_ID'
      '     ) and (     SETUP.ID_SETUP = :OLD_ID_SETUP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SETUP'
      'where ID_SETUP=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SETUP'
    AutoUpdateOptions.KeyFields = 'ID_SETUP'
    AutoUpdateOptions.GeneratorName = 'GEN_SETUP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 64
    object ElementID_SETUP: TFIBBCDField
      FieldName = 'ID_SETUP'
      Size = 0
      RoundByScale = True
    end
    object ElementDESCRIPTION_SETUP: TFIBStringField
      FieldName = 'DESCRIPTION_SETUP'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementVALUE_SETUP: TFIBStringField
      FieldName = 'VALUE_SETUP'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementGID_SETUP: TFIBStringField
      FieldName = 'GID_SETUP'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementVALUE_TIMESTAMP_SETUP: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_SETUP'
      DisplayFormat = 'c'
    end
    object ElementTYPE_VALUE_SETUP: TFIBSmallIntField
      FieldName = 'TYPE_VALUE_SETUP'
    end
  end
  object pFIBQKolPrDoc: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    SQL.Strings = (
      'select count(IDDOC) AS KOLPRDOC   from GALLDOC'
      ' where  (PRDOC>0)  AND  (POSDOC-:PARAM_POSDOC>0.0001)'
      ' AND (TDOC in (:PARAM_TYPEDOC ))')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 120
    qoStartTransaction = True
  end
end
