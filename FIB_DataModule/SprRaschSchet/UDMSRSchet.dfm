object DMSprRaschSchet: TDMSprRaschSchet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 710
  Top = 200
  Height = 250
  Width = 297
  object Table: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    OnCalcFields = TableCalcFields
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where IDFIRMBSCHET=:IDFIRM')
    Left = 152
    Top = 16
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDFIRM'
        ParamType = ptUnknown
      end>
    object TableIDBSCHET: TIntegerField
      FieldName = 'IDBSCHET'
      Origin = 'SBSCHET.IDBSCHET'
      Required = True
    end
    object TableNAMEBSCHET: TIBStringField
      FieldName = 'NAMEBSCHET'
      Origin = 'SBSCHET.NAMEBSCHET'
      Size = 30
    end
    object TableNUMBSCHET: TIBStringField
      FieldName = 'NUMBSCHET'
      Origin = 'SBSCHET.NUMBSCHET'
    end
    object TableIDBANKBSCHET: TIntegerField
      FieldName = 'IDBANKBSCHET'
      Origin = 'SBSCHET.IDBANKBSCHET'
    end
    object TableIDFIRMBSCHET: TIntegerField
      FieldName = 'IDFIRMBSCHET'
      Origin = 'SBSCHET.IDFIRMBSCHET'
    end
    object TableIDBANK: TIntegerField
      FieldName = 'IDBANK'
      Origin = 'SBANK.IDBANK'
    end
    object TableNAMEBANK: TIBStringField
      FieldName = 'NAMEBANK'
      Origin = 'SBANK.NAMEBANK'
      Size = 100
    end
    object TableBIKBANK: TIBStringField
      FieldName = 'BIKBANK'
      Origin = 'SBANK.BIKBANK'
      Size = 9
    end
    object TableGORBANK: TIBStringField
      FieldName = 'GORBANK'
      Origin = 'SBANK.GORBANK'
    end
    object TableKSBANK: TIBStringField
      FieldName = 'KSBANK'
      Origin = 'SBANK.KSBANK'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
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
    Left = 224
    Top = 64
  end
  object Element: TIBDataSet
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from SBSCHET'
      'where'
      '  IDBSCHET = :OLD_IDBSCHET')
    InsertSQL.Strings = (
      'insert into SBSCHET'
      '  (IDBSCHET, NAMEBSCHET, NUMBSCHET, IDBANKBSCHET, IDFIRMBSCHET)'
      'values'
      
        '  (:IDBSCHET, :NAMEBSCHET, :NUMBSCHET, :IDBANKBSCHET, :IDFIRMBSC' +
        'HET)')
    RefreshSQL.Strings = (
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where IDBSCHET=:ID')
    SelectSQL.Strings = (
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where IDBSCHET=:ID')
    ModifySQL.Strings = (
      'update SBSCHET'
      'set'
      '  IDBSCHET = :IDBSCHET,'
      '  NAMEBSCHET = :NAMEBSCHET,'
      '  NUMBSCHET = :NUMBSCHET,'
      '  IDBANKBSCHET = :IDBANKBSCHET,'
      '  IDFIRMBSCHET = :IDFIRMBSCHET'
      'where'
      '  IDBSCHET = :OLD_IDBSCHET')
    GeneratorField.Field = 'IDBSCHET'
    GeneratorField.Generator = 'GEN_SBSCHET_ID'
    Left = 160
    Top = 96
    object ElementIDBSCHET: TIntegerField
      FieldName = 'IDBSCHET'
      Origin = 'SBSCHET.IDBSCHET'
      Required = True
    end
    object ElementNAMEBSCHET: TIBStringField
      FieldName = 'NAMEBSCHET'
      Origin = 'SBSCHET.NAMEBSCHET'
      Size = 30
    end
    object ElementNUMBSCHET: TIBStringField
      FieldName = 'NUMBSCHET'
      Origin = 'SBSCHET.NUMBSCHET'
    end
    object ElementIDBANKBSCHET: TIntegerField
      FieldName = 'IDBANKBSCHET'
      Origin = 'SBSCHET.IDBANKBSCHET'
    end
    object ElementIDFIRMBSCHET: TIntegerField
      FieldName = 'IDFIRMBSCHET'
      Origin = 'SBSCHET.IDFIRMBSCHET'
    end
    object ElementNAMEBANK: TIBStringField
      FieldName = 'NAMEBANK'
      Origin = 'SBANK.NAMEBANK'
      Size = 100
    end
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DSourceIBDSSBSchet: TDataSource
    DataSet = Element
    Left = 48
    Top = 96
  end
end
