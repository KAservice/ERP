object DMSprOKEI: TDMSprOKEI
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 153
  Width = 309
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SOKEI')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDOKEI: TFIBBCDField
      FieldName = 'IDOKEI'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEOKEI: TFIBWideStringField
      FieldName = 'NAMEOKEI'
      Size = 100
    end
    object TableCODEOKEI: TFIBIntegerField
      FieldName = 'CODEOKEI'
    end
    object TableGID_SOKEI: TFIBWideStringField
      FieldName = 'GID_SOKEI'
      Size = 10
    end
    object TableIDBASE_SOKEI: TFIBBCDField
      FieldName = 'IDBASE_SOKEI'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SOKEI'
      'SET '
      '    NAMEOKEI = :NAMEOKEI,'
      '    CODEOKEI = :CODEOKEI,'
      '    GID_SOKEI = :GID_SOKEI'
      'WHERE'
      '    IDOKEI = :OLD_IDOKEI'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SOKEI'
      'WHERE'
      '        IDOKEI = :OLD_IDOKEI'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SOKEI('
      '    IDOKEI,'
      '    NAMEOKEI,'
      '    CODEOKEI,'
      '    GID_SOKEI'
      ')'
      'VALUES('
      '    :IDOKEI,'
      '    :NAMEOKEI,'
      '    :CODEOKEI,'
      '    :GID_SOKEI'
      ')')
    RefreshSQL.Strings = (
      'select * from SOKEI where(  IDOKEI=:ID'
      '     ) and (     SOKEI.IDOKEI = :OLD_IDOKEI'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SOKEI where IDOKEI=:ID')
    AutoUpdateOptions.UpdateTableName = 'SOKEI'
    AutoUpdateOptions.KeyFields = 'IDOKEI'
    AutoUpdateOptions.GeneratorName = 'GEN_SOKEI_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementIDOKEI: TFIBBCDField
      FieldName = 'IDOKEI'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEOKEI: TFIBWideStringField
      FieldName = 'NAMEOKEI'
      Size = 100
    end
    object ElementCODEOKEI: TFIBIntegerField
      FieldName = 'CODEOKEI'
    end
    object ElementGID_SOKEI: TFIBWideStringField
      FieldName = 'GID_SOKEI'
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
    Top = 80
  end
end
