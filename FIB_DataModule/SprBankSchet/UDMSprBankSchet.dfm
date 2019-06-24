object DMSprBankSchet: TDMSprBankSchet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 262
  Width = 306
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
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where IDFIRMBSCHET=:IDFIRM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDBSCHET: TFIBBCDField
      FieldName = 'IDBSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableIDBANKBSCHET: TFIBBCDField
      FieldName = 'IDBANKBSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRMBSCHET: TFIBBCDField
      FieldName = 'IDFIRMBSCHET'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object TableNUMBSCHET: TFIBWideStringField
      FieldName = 'NUMBSCHET'
    end
    object TableGID_SBSCHET: TFIBWideStringField
      FieldName = 'GID_SBSCHET'
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
      'UPDATE SBSCHET'
      'SET '
      '    NAMEBSCHET = :NAMEBSCHET,'
      '    NUMBSCHET = :NUMBSCHET,'
      '    IDBANKBSCHET = :IDBANKBSCHET,'
      '    IDFIRMBSCHET = :IDFIRMBSCHET,'
      '    GID_SBSCHET = :GID_SBSCHET,'
      '    IDBASE_SBSCHET = :IDBASE_SBSCHET,'
      '    PREFIKS_NUM_SBSCHET = :PREFIKS_NUM_SBSCHET'
      'WHERE'
      '    IDBSCHET = :OLD_IDBSCHET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBSCHET'
      'WHERE'
      '        IDBSCHET = :OLD_IDBSCHET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBSCHET('
      '    IDBSCHET,'
      '    NAMEBSCHET,'
      '    NUMBSCHET,'
      '    IDBANKBSCHET,'
      '    IDFIRMBSCHET,'
      '    GID_SBSCHET,'
      '    IDBASE_SBSCHET,'
      '    PREFIKS_NUM_SBSCHET'
      ')'
      'VALUES('
      '    :IDBSCHET,'
      '    :NAMEBSCHET,'
      '    :NUMBSCHET,'
      '    :IDBANKBSCHET,'
      '    :IDFIRMBSCHET,'
      '    :GID_SBSCHET,'
      '    :IDBASE_SBSCHET,'
      '    :PREFIKS_NUM_SBSCHET'
      ')')
    RefreshSQL.Strings = (
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where(  IDBSCHET=:ID'
      '     ) and (     SBSCHET.IDBSCHET = :OLD_IDBSCHET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SBSCHET.* , SBANK.*'
      'from SBSCHET left outer join SBANK'
      'on  IDBANKBSCHET=IDBANK'
      'where IDBSCHET=:ID')
    AutoUpdateOptions.UpdateTableName = 'SBSCHET'
    AutoUpdateOptions.KeyFields = 'IDBSCHET'
    AutoUpdateOptions.GeneratorName = 'GEN_SBSCHET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementIDBSCHET: TFIBBCDField
      FieldName = 'IDBSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBANKBSCHET: TFIBBCDField
      FieldName = 'IDBANKBSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDFIRMBSCHET: TFIBBCDField
      FieldName = 'IDFIRMBSCHET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBANK: TFIBBCDField
      FieldName = 'IDBANK'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 200
    end
    object ElementNUMBSCHET: TFIBWideStringField
      FieldName = 'NUMBSCHET'
    end
    object ElementGID_SBSCHET: TFIBWideStringField
      FieldName = 'GID_SBSCHET'
      Size = 10
    end
    object ElementNAMEBANK: TFIBWideStringField
      FieldName = 'NAMEBANK'
      Size = 200
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
    object ElementPREFIKS_NUM_SBSCHET: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_SBSCHET'
      Size = 3
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
    Left = 232
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 96
  end
end
