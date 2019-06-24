object DMSprOKEI: TDMSprOKEI
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 997
  Top = 119
  Height = 182
  Width = 276
  object Table: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    OnCalcFields = TableCalcFields
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from SOKEI')
    Left = 136
    Top = 16
    object TableIDOKEI: TIntegerField
      FieldName = 'IDOKEI'
      Origin = 'SOKEI.IDOKEI'
      Required = True
    end
    object TableNAMEOKEI: TIBStringField
      FieldName = 'NAMEOKEI'
      Origin = 'SOKEI.NAMEOKEI'
      Size = 10
    end
    object TableCODEOKEI: TIntegerField
      FieldName = 'CODEOKEI'
      Origin = 'SOKEI.CODEOKEI'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TIBDataSet
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from SOKEI'
      'where'
      '  IDOKEI = :OLD_IDOKEI')
    InsertSQL.Strings = (
      'insert into SOKEI'
      '  (IDOKEI, NAMEOKEI, CODEOKEI)'
      'values'
      '  (:IDOKEI, :NAMEOKEI, :CODEOKEI)')
    RefreshSQL.Strings = (
      'Select '
      '  IDOKEI,'
      '  NAMEOKEI,'
      '  CODEOKEI'
      'from SOKEI '
      'where'
      '  IDOKEI = :IDOKEI')
    SelectSQL.Strings = (
      'select * from SOKEI where IDOKEI=:ID')
    ModifySQL.Strings = (
      'update SOKEI'
      'set'
      '  IDOKEI = :IDOKEI,'
      '  NAMEOKEI = :NAMEOKEI,'
      '  CODEOKEI = :CODEOKEI'
      'where'
      '  IDOKEI = :OLD_IDOKEI')
    GeneratorField.Field = 'IDOKEI'
    GeneratorField.Generator = 'GEN_SOKEI_ID'
    Left = 136
    Top = 80
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    DefaultAction = TARollback
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 200
    Top = 32
  end
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
end
