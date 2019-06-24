object DMSprSklad: TDMSprSklad
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
    SelectSQL.Strings = (
      'select  * from SSKLAD')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 16
    object TableNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object TableMOLSKLAD: TFIBStringField
      FieldName = 'MOLSKLAD'
      EmptyStrToNull = True
    end
    object TableADRSKLAD: TFIBStringField
      FieldName = 'ADRSKLAD'
      Size = 100
      EmptyStrToNull = True
    end
    object TableTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSKLAD: TFIBStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSKLAD'
      'SET '
      '    NAMESKLAD = :NAMESKLAD,'
      '    MOLSKLAD = :MOLSKLAD,'
      '    ADRSKLAD = :ADRSKLAD,'
      '    TSKLAD = :TSKLAD,'
      '    GID_SSKLAD = :GID_SSKLAD'
      'WHERE'
      '    IDSKLAD = :OLD_IDSKLAD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSKLAD'
      'WHERE'
      '        IDSKLAD = :OLD_IDSKLAD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSKLAD('
      '    IDSKLAD,'
      '    NAMESKLAD,'
      '    MOLSKLAD,'
      '    ADRSKLAD,'
      '    TSKLAD,'
      '    GID_SSKLAD'
      ')'
      'VALUES('
      '    :IDSKLAD,'
      '    :NAMESKLAD,'
      '    :MOLSKLAD,'
      '    :ADRSKLAD,'
      '    :TSKLAD,'
      '    :GID_SSKLAD'
      ')')
    RefreshSQL.Strings = (
      'select * from SSKLAD where(  IDSKLAD=:ID'
      '     ) and (     SSKLAD.IDSKLAD = :OLD_IDSKLAD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SSKLAD where IDSKLAD=:ID')
    AutoUpdateOptions.UpdateTableName = 'SSKLAD'
    AutoUpdateOptions.KeyFields = 'IDSKLAD'
    AutoUpdateOptions.GeneratorName = 'GEN_SSKLAD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 96
    object ElementNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementMOLSKLAD: TFIBStringField
      FieldName = 'MOLSKLAD'
      EmptyStrToNull = True
    end
    object ElementADRSKLAD: TFIBStringField
      FieldName = 'ADRSKLAD'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object ElementIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SSKLAD: TFIBStringField
      FieldName = 'GID_SSKLAD'
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
