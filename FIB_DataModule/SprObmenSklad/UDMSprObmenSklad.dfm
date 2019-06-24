object DMSprObmenSklad: TDMSprObmenSklad
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 138
  Width = 283
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSKLAD_OBMEN'
      'SET '
      '    GID_SSKLAD_OBMEN = :GID_SSKLAD_OBMEN,'
      '    IDBASE_SSKLAD_OBMEN = :IDBASE_SSKLAD_OBMEN,'
      '    IDSKLAD_SSKLAD_OBMEN = :IDSKLAD_SSKLAD_OBMEN'
      'WHERE'
      '    ID_SSKLAD_OBMEN = :OLD_ID_SSKLAD_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSKLAD_OBMEN'
      'WHERE'
      '        ID_SSKLAD_OBMEN = :OLD_ID_SSKLAD_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSKLAD_OBMEN('
      '    ID_SSKLAD_OBMEN,'
      '    GID_SSKLAD_OBMEN,'
      '    IDBASE_SSKLAD_OBMEN,'
      '    IDSKLAD_SSKLAD_OBMEN'
      ')'
      'VALUES('
      '    :ID_SSKLAD_OBMEN,'
      '    :GID_SSKLAD_OBMEN,'
      '    :IDBASE_SSKLAD_OBMEN,'
      '    :IDSKLAD_SSKLAD_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select SSKLAD_OBMEN.*, NAMESKLAD '
      'from SSKLAD_OBMEN'
      'left outer join SSklad on IDSKLAD=IDSKLAD_SSKLAD_OBMEN'
      'where(  IDBASE_SSKLAD_OBMEN=:PARAM_IDBASE'
      
        '     ) and (     SSKLAD_OBMEN.ID_SSKLAD_OBMEN = :OLD_ID_SSKLAD_O' +
        'BMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SSKLAD_OBMEN.*, NAMESKLAD '
      'from SSKLAD_OBMEN'
      'left outer join SSklad on IDSKLAD=IDSKLAD_SSKLAD_OBMEN'
      'where IDBASE_SSKLAD_OBMEN=:PARAM_IDBASE')
    AutoUpdateOptions.UpdateTableName = 'SSKLAD_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_SSKLAD_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_SSKLAD_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 136
    Top = 16
    object TableNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SSKLAD_OBMEN: TFIBBCDField
      FieldName = 'ID_SSKLAD_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SSKLAD_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_SSKLAD_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_SSKLAD_OBMEN: TFIBBCDField
      FieldName = 'IDSKLAD_SSKLAD_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSKLAD_OBMEN: TFIBStringField
      FieldName = 'GID_SSKLAD_OBMEN'
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
    Left = 216
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
    Left = 216
    Top = 64
  end
end
