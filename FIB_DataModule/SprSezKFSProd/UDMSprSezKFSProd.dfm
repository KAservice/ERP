object DMSprSezKFSProd: TDMSprSezKFSProd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 129
  Width = 279
  object DataSourceTable: TDataSource
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSEZKF_SPROD'
      'SET '
      '    IDSSPROD_SSEZKF_SPROD = :IDSSPROD_SSEZKF_SPROD,'
      '    MONTH_SSEZKF_SPROD = :MONTH_SSEZKF_SPROD,'
      '    VALUE_SSEZKF_SPROD = :VALUE_SSEZKF_SPROD,'
      '    GID_SSEZKF_SPROD = :GID_SSEZKF_SPROD'
      'WHERE'
      '    ID_SSEZKF_SPROD = :OLD_ID_SSEZKF_SPROD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSEZKF_SPROD'
      'WHERE'
      '        ID_SSEZKF_SPROD = :OLD_ID_SSEZKF_SPROD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSEZKF_SPROD('
      '    ID_SSEZKF_SPROD,'
      '    IDSSPROD_SSEZKF_SPROD,'
      '    MONTH_SSEZKF_SPROD,'
      '    VALUE_SSEZKF_SPROD,'
      '    GID_SSEZKF_SPROD'
      ')'
      'VALUES('
      '    :ID_SSEZKF_SPROD,'
      '    :IDSSPROD_SSEZKF_SPROD,'
      '    :MONTH_SSEZKF_SPROD,'
      '    :VALUE_SSEZKF_SPROD,'
      '    :GID_SSEZKF_SPROD'
      ')')
    RefreshSQL.Strings = (
      'select  *'
      'from  SSEZKF_SPROD'
      'where(  IDSSPROD_SSEZKF_SPROD=:PARAM_IDSPROD'
      
        '     ) and (     SSEZKF_SPROD.ID_SSEZKF_SPROD = :OLD_ID_SSEZKF_S' +
        'PROD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  *'
      'from  SSEZKF_SPROD'
      'where IDSSPROD_SSEZKF_SPROD=:PARAM_IDSPROD')
    AutoUpdateOptions.UpdateTableName = 'SSEZKF_SPROD'
    AutoUpdateOptions.KeyFields = 'ID_SSEZKF_SPROD'
    AutoUpdateOptions.GeneratorName = 'GEN_SSEZKF_SPROD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableMONTH_SSEZKF_SPROD: TFIBIntegerField
      FieldName = 'MONTH_SSEZKF_SPROD'
    end
    object TableVALUE_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'ID_SSEZKF_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDSSPROD_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'IDSSPROD_SSEZKF_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSEZKF_SPROD: TFIBWideStringField
      FieldName = 'GID_SSEZKF_SPROD'
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
    Left = 208
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
    Left = 208
    Top = 72
  end
end
