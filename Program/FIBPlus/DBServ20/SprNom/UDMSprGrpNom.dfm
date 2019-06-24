object DMSprGrpNom: TDMSprGrpNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SGRPNOM'
      'order by IDGRPGN')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 24
    object TableNAMEGN: TFIBStringField
      FieldName = 'NAMEGN'
      Size = 50
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPGN: TFIBBCDField
      FieldName = 'IDGRPGN'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SGRPNOM: TFIBStringField
      FieldName = 'GID_SGRPNOM'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPNOM'
      'SET '
      '    NAMEGN = :NAMEGN,'
      '    IDGRPGN = :IDGRPGN,'
      '    GID_SGRPNOM = :GID_SGRPNOM'
      'WHERE'
      '    IDGN = :OLD_IDGN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPNOM'
      'WHERE'
      '        IDGN = :OLD_IDGN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPNOM('
      '    IDGN,'
      '    NAMEGN,'
      '    IDGRPGN,'
      '    GID_SGRPNOM'
      ')'
      'VALUES('
      '    :IDGN,'
      '    :NAMEGN,'
      '    :IDGRPGN,'
      '    :GID_SGRPNOM'
      ')')
    RefreshSQL.Strings = (
      'select * from SGRPNOM where(  IDGN=:ID'
      '     ) and (     SGRPNOM.IDGN = :OLD_IDGN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SGRPNOM where IDGN=:ID')
    AutoUpdateOptions.UpdateTableName = 'SGRPNOM'
    AutoUpdateOptions.KeyFields = 'IDGN'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 80
    object ElementNAMEGN: TFIBStringField
      FieldName = 'NAMEGN'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPGN: TFIBBCDField
      FieldName = 'IDGRPGN'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SGRPNOM: TFIBStringField
      FieldName = 'GID_SGRPNOM'
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
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
