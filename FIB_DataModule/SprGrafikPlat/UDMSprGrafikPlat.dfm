object DMSprGrafikPlat: TDMSprGrafikPlat
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 137
  Width = 315
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPLAT'
      'SET '
      '    IDDOG_SGRPLAT = :IDDOG_SGRPLAT,'
      '    DO_SGRPLAT = :DO_SGRPLAT,'
      '    SUM_SGRPLAT = :SUM_SGRPLAT,'
      '    GID_SGRPLAT = :GID_SGRPLAT'
      'WHERE'
      '    ID_SGRPLAT = :OLD_ID_SGRPLAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPLAT'
      'WHERE'
      '        ID_SGRPLAT = :OLD_ID_SGRPLAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPLAT('
      '    ID_SGRPLAT,'
      '    IDDOG_SGRPLAT,'
      '    DO_SGRPLAT,'
      '    SUM_SGRPLAT,'
      '    GID_SGRPLAT'
      ')'
      'VALUES('
      '    :ID_SGRPLAT,'
      '    :IDDOG_SGRPLAT,'
      '    :DO_SGRPLAT,'
      '    :SUM_SGRPLAT,'
      '    :GID_SGRPLAT'
      ')')
    RefreshSQL.Strings = (
      'select  *'
      'from   SGRPLAT'
      'where(  IDDOG_SGRPLAT=:PARAM_IDDOG'
      '     ) and (     SGRPLAT.ID_SGRPLAT = :OLD_ID_SGRPLAT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  *'
      'from   SGRPLAT'
      'where IDDOG_SGRPLAT=:PARAM_IDDOG')
    AutoUpdateOptions.UpdateTableName = 'SGRPLAT'
    AutoUpdateOptions.KeyFields = 'ID_SGRPLAT'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPLAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    object TableDO_SGRPLAT: TFIBDateField
      FieldName = 'DO_SGRPLAT'
    end
    object TableSUM_SGRPLAT: TFIBBCDField
      FieldName = 'SUM_SGRPLAT'
      Size = 2
      RoundByScale = True
    end
    object TableID_SGRPLAT: TFIBBCDField
      FieldName = 'ID_SGRPLAT'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOG_SGRPLAT: TFIBBCDField
      FieldName = 'IDDOG_SGRPLAT'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SGRPLAT: TFIBWideStringField
      FieldName = 'GID_SGRPLAT'
      Size = 10
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
    Left = 224
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
    Left = 224
    Top = 72
  end
end
