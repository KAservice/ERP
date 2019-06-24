object DMSprGrpKlient: TDMSprGrpKlient
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 149
  Width = 295
  object DataSourceTable: TDataSource
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SGRPKL   ORDER BY IDGRPKL')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDGRPKL: TFIBBCDField
      FieldName = 'IDGRPKL'
      Size = 0
      RoundByScale = True
    end
    object TableGRPKL: TFIBBCDField
      FieldName = 'GRPKL'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEGRPKL: TFIBWideStringField
      FieldName = 'NAMEGRPKL'
      Size = 100
    end
    object TableGID_SGRPKL: TFIBWideStringField
      FieldName = 'GID_SGRPKL'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPKL'
      'SET '
      '    NAMEGRPKL = :NAMEGRPKL,'
      '    GRPKL = :GRPKL,'
      '    GID_SGRPKL = :GID_SGRPKL'
      'WHERE'
      '    IDGRPKL = :OLD_IDGRPKL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPKL'
      'WHERE'
      '        IDGRPKL = :OLD_IDGRPKL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPKL('
      '    IDGRPKL,'
      '    NAMEGRPKL,'
      '    GRPKL,'
      '    GID_SGRPKL'
      ')'
      'VALUES('
      '    :IDGRPKL,'
      '    :NAMEGRPKL,'
      '    :GRPKL,'
      '    :GID_SGRPKL'
      ')')
    RefreshSQL.Strings = (
      'select * from SGRPKL where(  IDGRPKL=:ID'
      '     ) and (     SGRPKL.IDGRPKL = :OLD_IDGRPKL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SGRPKL where IDGRPKL=:ID')
    AutoUpdateOptions.UpdateTableName = 'SGRPKL'
    AutoUpdateOptions.KeyFields = 'IDGRPKL'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPKL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 72
    object ElementIDGRPKL: TFIBBCDField
      FieldName = 'IDGRPKL'
      Size = 0
      RoundByScale = True
    end
    object ElementGRPKL: TFIBBCDField
      FieldName = 'GRPKL'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEGRPKL: TFIBWideStringField
      FieldName = 'NAMEGRPKL'
      Size = 100
    end
    object ElementGID_SGRPKL: TFIBWideStringField
      FieldName = 'GID_SGRPKL'
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
