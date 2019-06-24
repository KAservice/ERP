object DMSprSezKF: TDMSprSezKF
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 132
  Width = 307
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSEZKF'
      'SET '
      '    IDNOM_SSEZKF = :IDNOM_SSEZKF,'
      '    MONTH_SSEZKF = :MONTH_SSEZKF,'
      '    VALUE_SSEZKF = :VALUE_SSEZKF,'
      '    GID_SSEZKF = :GID_SSEZKF'
      'WHERE'
      '    ID_SSEZKF = :OLD_ID_SSEZKF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSEZKF'
      'WHERE'
      '        ID_SSEZKF = :OLD_ID_SSEZKF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSEZKF('
      '    ID_SSEZKF,'
      '    IDNOM_SSEZKF,'
      '    MONTH_SSEZKF,'
      '    VALUE_SSEZKF,'
      '    GID_SSEZKF'
      ')'
      'VALUES('
      '    :ID_SSEZKF,'
      '    :IDNOM_SSEZKF,'
      '    :MONTH_SSEZKF,'
      '    :VALUE_SSEZKF,'
      '    :GID_SSEZKF'
      ')')
    RefreshSQL.Strings = (
      'select  *'
      'from SSEZKF'
      'where(  IDNOM_SSEZKF=:PARAM_IDNOM'
      '     ) and (     SSEZKF.ID_SSEZKF = :OLD_ID_SSEZKF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  *'
      'from SSEZKF'
      'where IDNOM_SSEZKF=:PARAM_IDNOM')
    AutoUpdateOptions.UpdateTableName = 'SSEZKF'
    AutoUpdateOptions.KeyFields = 'ID_SSEZKF'
    AutoUpdateOptions.GeneratorName = 'GEN_SSEZKF_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 16
    object TableMONTH_SSEZKF: TFIBIntegerField
      FieldName = 'MONTH_SSEZKF'
    end
    object TableVALUE_SSEZKF: TFIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Size = 3
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SSEZKF: TFIBBCDField
      FieldName = 'ID_SSEZKF'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_SSEZKF: TFIBBCDField
      FieldName = 'IDNOM_SSEZKF'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSEZKF: TFIBWideStringField
      FieldName = 'GID_SSEZKF'
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
    Left = 248
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
    Left = 248
    Top = 64
  end
end
