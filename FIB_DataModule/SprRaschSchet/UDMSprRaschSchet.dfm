object DMSprRaschSchet: TDMSprRaschSchet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 166
  Width = 297
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select SRSCHET.* , SBANK.*'
      'from SRSCHET left outer join SBANK'
      'on  IDBANKRSCHET=IDBANK'
      'where IDKLRSCHET=:IDKLIENT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDRSCHET: TFIBBCDField
      FieldName = 'IDRSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLRSCHET: TFIBBCDField
      FieldName = 'IDKLRSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableIDBANKRSCHET: TFIBBCDField
      FieldName = 'IDBANKRSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableIDBANK: TFIBBCDField
      FieldName = 'IDBANK'
      Size = 0
      RoundByScale = True
    end
    object TableNAMERSCHET: TFIBWideStringField
      FieldName = 'NAMERSCHET'
      Size = 100
    end
    object TableNUMRSCHET: TFIBWideStringField
      FieldName = 'NUMRSCHET'
    end
    object TableGID_SRSCHET: TFIBWideStringField
      FieldName = 'GID_SRSCHET'
      Size = 10
    end
    object TableNAMEBANK: TFIBWideStringField
      FieldName = 'NAMEBANK'
      Size = 100
    end
    object TableBIKBANK: TFIBWideStringField
      FieldName = 'BIKBANK'
      Size = 9
    end
    object TableGORBANK: TFIBWideStringField
      FieldName = 'GORBANK'
    end
    object TableKSBANK: TFIBWideStringField
      FieldName = 'KSBANK'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SRSCHET'
      'SET '
      '    IDKLRSCHET = :IDKLRSCHET,'
      '    IDBANKRSCHET = :IDBANKRSCHET,'
      '    NAMERSCHET = :NAMERSCHET,'
      '    NUMRSCHET = :NUMRSCHET,'
      '    GID_SRSCHET = :GID_SRSCHET'
      'WHERE'
      '    IDRSCHET = :OLD_IDRSCHET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SRSCHET'
      'WHERE'
      '        IDRSCHET = :OLD_IDRSCHET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SRSCHET('
      '    IDRSCHET,'
      '    IDKLRSCHET,'
      '    IDBANKRSCHET,'
      '    NAMERSCHET,'
      '    NUMRSCHET,'
      '    GID_SRSCHET'
      ')'
      'VALUES('
      '    :IDRSCHET,'
      '    :IDKLRSCHET,'
      '    :IDBANKRSCHET,'
      '    :NAMERSCHET,'
      '    :NUMRSCHET,'
      '    :GID_SRSCHET'
      ')')
    RefreshSQL.Strings = (
      'select SRSCHET.* , SBANK.*'
      'from SRSCHET left outer join SBANK'
      'on  IDBANKRSCHET=IDBANK'
      'where(  IDRSCHET=:ID'
      '     ) and (     SRSCHET.IDRSCHET = :OLD_IDRSCHET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SRSCHET.* , SBANK.*'
      'from SRSCHET left outer join SBANK'
      'on  IDBANKRSCHET=IDBANK'
      'where IDRSCHET=:ID')
    AutoUpdateOptions.UpdateTableName = 'SRSCHET'
    AutoUpdateOptions.KeyFields = 'IDRSCHET'
    AutoUpdateOptions.GeneratorName = 'GEN_SRSCHET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 96
    object ElementIDRSCHET: TFIBBCDField
      FieldName = 'IDRSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLRSCHET: TFIBBCDField
      FieldName = 'IDKLRSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBANKRSCHET: TFIBBCDField
      FieldName = 'IDBANKRSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBANK: TFIBBCDField
      FieldName = 'IDBANK'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMERSCHET: TFIBWideStringField
      FieldName = 'NAMERSCHET'
      Size = 100
    end
    object ElementNUMRSCHET: TFIBWideStringField
      FieldName = 'NUMRSCHET'
    end
    object ElementGID_SRSCHET: TFIBWideStringField
      FieldName = 'GID_SRSCHET'
      Size = 10
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
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 216
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
    Left = 216
    Top = 96
  end
end
