object DMSprObmenTypeDoc: TDMSprObmenTypeDoc
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 178
  Width = 283
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE STYPEDOC_OBMEN'
      'SET '
      '    GID_STYPEDOC_OBMEN = :GID_STYPEDOC_OBMEN,'
      '    IDBASE_STYPEDOC_OBMEN = :IDBASE_STYPEDOC_OBMEN,'
      '    NAME_STYPEDOC_OBMEN = :NAME_STYPEDOC_OBMEN'
      'WHERE'
      '    ID_STYPEDOC_OBMEN = :OLD_ID_STYPEDOC_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STYPEDOC_OBMEN'
      'WHERE'
      '        ID_STYPEDOC_OBMEN = :OLD_ID_STYPEDOC_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STYPEDOC_OBMEN('
      '    ID_STYPEDOC_OBMEN,'
      '    GID_STYPEDOC_OBMEN,'
      '    IDBASE_STYPEDOC_OBMEN,'
      '    NAME_STYPEDOC_OBMEN'
      ')'
      'VALUES('
      '    :ID_STYPEDOC_OBMEN,'
      '    :GID_STYPEDOC_OBMEN,'
      '    :IDBASE_STYPEDOC_OBMEN,'
      '    :NAME_STYPEDOC_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from  STYPEDOC_OBMEN'
      ''
      'where(  IDBASE_STYPEDOC_OBMEN=:PARAM_IDBASE'
      
        '     ) and (     STYPEDOC_OBMEN.ID_STYPEDOC_OBMEN = :OLD_ID_STYP' +
        'EDOC_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from  STYPEDOC_OBMEN'
      ''
      'where IDBASE_STYPEDOC_OBMEN=:PARAM_IDBASE')
    AutoUpdateOptions.UpdateTableName = 'STYPEDOC_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_STYPEDOC_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPEDOC_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 120
    Top = 16
    object TableNAME_STYPEDOC_OBMEN: TFIBStringField
      FieldName = 'NAME_STYPEDOC_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STYPEDOC_OBMEN: TFIBBCDField
      FieldName = 'ID_STYPEDOC_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_STYPEDOC_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_STYPEDOC_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableGID_STYPEDOC_OBMEN: TFIBStringField
      FieldName = 'GID_STYPEDOC_OBMEN'
      Size = 10
      EmptyStrToNull = True
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 200
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
    Left = 200
    Top = 64
  end
end
