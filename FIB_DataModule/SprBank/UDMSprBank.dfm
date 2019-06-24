object DMSprBank: TDMSprBank
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 144
  Width = 276
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 80
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 200
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
    Left = 200
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDBANK, NAMEBANK, GORBANK from SBANK')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDBANK: TFIBBCDField
      FieldName = 'IDBANK'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEBANK: TFIBWideStringField
      FieldName = 'NAMEBANK'
      Size = 100
    end
    object TableGORBANK: TFIBWideStringField
      FieldName = 'GORBANK'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SBANK'
      'SET '
      '    NAMEBANK = :NAMEBANK,'
      '    BIKBANK = :BIKBANK,'
      '    GORBANK = :GORBANK,'
      '    KSBANK = :KSBANK,'
      '    GID_SBANK = :GID_SBANK'
      'WHERE'
      '    IDBANK = :OLD_IDBANK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBANK'
      'WHERE'
      '        IDBANK = :OLD_IDBANK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBANK('
      '    IDBANK,'
      '    NAMEBANK,'
      '    BIKBANK,'
      '    GORBANK,'
      '    KSBANK,'
      '    GID_SBANK'
      ')'
      'VALUES('
      '    :IDBANK,'
      '    :NAMEBANK,'
      '    :BIKBANK,'
      '    :GORBANK,'
      '    :KSBANK,'
      '    :GID_SBANK'
      ')')
    RefreshSQL.Strings = (
      'select * from SBANK where(  IDBANK=:ID'
      '     ) and (     SBANK.IDBANK = :OLD_IDBANK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SBANK where IDBANK=:ID')
    AutoUpdateOptions.UpdateTableName = 'SBANK'
    AutoUpdateOptions.KeyFields = 'IDBANK'
    AutoUpdateOptions.GeneratorName = 'GEN_SBANK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementIDBANK: TFIBBCDField
      FieldName = 'IDBANK'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEBANK: TFIBWideStringField
      FieldName = 'NAMEBANK'
      Size = 100
    end
    object ElementBIKBANK: TFIBWideStringField
      FieldName = 'BIKBANK'
      Size = 9
    end
    object ElementGORBANK: TFIBWideStringField
      FieldName = 'GORBANK'
    end
    object ElementKSBANK: TFIBWideStringField
      FieldName = 'KSBANK'
    end
    object ElementGID_SBANK: TFIBWideStringField
      FieldName = 'GID_SBANK'
      Size = 10
    end
  end
end
