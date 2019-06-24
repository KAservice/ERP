object DMSprObmenPrice: TDMSprObmenPrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 503
  Top = 188
  Height = 113
  Width = 273
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
    Top = 16
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TIBDataSet
    Database = DM.IBData
    Transaction = IBTr
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    BufferChunks = 1000
    CachedUpdates = True
    DeleteSQL.Strings = (
      'delete from SSKLAD_OBMEN'
      'where'
      '  ID_SSKLAD_OBMEN = :OLD_ID_SSKLAD_OBMEN')
    InsertSQL.Strings = (
      'insert into SSKLAD_OBMEN'
      '  (ID_SSKLAD_OBMEN, IDBASE_SSKLAD_OBMEN, IDSKLAD_SSKLAD_OBMEN)'
      'values'
      
        '  (:ID_SSKLAD_OBMEN, :IDBASE_SSKLAD_OBMEN, :IDSKLAD_SSKLAD_OBMEN' +
        ')')
    RefreshSQL.Strings = (
      'select SSKLAD_OBMEN.*, NAMESKLAD '
      'from SSKLAD_OBMEN'
      'left outer join SSklad on IDSKLAD=IDSKLAD_SSKLAD_OBMEN'
      'where'
      '  ID_SSKLAD_OBMEN = :ID_SSKLAD_OBMEN')
    SelectSQL.Strings = (
      'select SSKLAD_OBMEN.*, NAMESKLAD '
      'from SSKLAD_OBMEN'
      'left outer join SSklad on IDSKLAD=IDSKLAD_SSKLAD_OBMEN'
      'where IDBASE_SSKLAD_OBMEN=:PARAM_IDBASE')
    ModifySQL.Strings = (
      'update SSKLAD_OBMEN'
      'set'
      '  ID_SSKLAD_OBMEN = :ID_SSKLAD_OBMEN,'
      '  IDBASE_SSKLAD_OBMEN = :IDBASE_SSKLAD_OBMEN,'
      '  IDSKLAD_SSKLAD_OBMEN = :IDSKLAD_SSKLAD_OBMEN'
      'where'
      '  ID_SSKLAD_OBMEN = :OLD_ID_SSKLAD_OBMEN')
    GeneratorField.Field = 'ID_SSKLAD_OBMEN'
    GeneratorField.Generator = 'GEN_SSKLAD_OBMEN_ID'
    Left = 136
    Top = 16
    object TableID_SSKLAD_OBMEN: TIntegerField
      FieldName = 'ID_SSKLAD_OBMEN'
      Origin = 'SSKLAD_OBMEN.ID_SSKLAD_OBMEN'
      Required = True
    end
    object TableGID_SSKLAD_OBMEN: TIBStringField
      FieldName = 'GID_SSKLAD_OBMEN'
      Origin = 'SSKLAD_OBMEN.GID_SSKLAD_OBMEN'
      Required = True
      Size = 10
    end
    object TableIDBASE_SSKLAD_OBMEN: TIntegerField
      FieldName = 'IDBASE_SSKLAD_OBMEN'
      Origin = 'SSKLAD_OBMEN.IDBASE_SSKLAD_OBMEN'
    end
    object TableIDSKLAD_SSKLAD_OBMEN: TIntegerField
      FieldName = 'IDSKLAD_SSKLAD_OBMEN'
      Origin = 'SSKLAD_OBMEN.IDSKLAD_SSKLAD_OBMEN'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAMESKLAD: TIBStringField
      FieldName = 'NAMESKLAD'
      Origin = 'SSKLAD.NAMESKLAD'
      Size = 50
    end
  end
end
