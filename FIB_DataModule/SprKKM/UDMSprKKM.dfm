object DMSprKKM: TDMSprKKM
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 248
  Width = 290
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
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
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SKKM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDKKM: TFIBBCDField
      FieldName = 'IDKKM'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object TableGID_SKKM: TFIBWideStringField
      FieldName = 'GID_SKKM'
      Size = 10
    end
    object TableCATOBMKKM: TFIBWideStringField
      FieldName = 'CATOBMKKM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SKKM'
      'SET '
      '    NAMEKKM = :NAMEKKM,'
      '    GID_SKKM = :GID_SKKM,'
      '    CATOBMKKM = :CATOBMKKM,'
      '    IDBASE_SKKM = :IDBASE_SKKM,'
      '    PREFIKS_NUM_SKKM = :PREFIKS_NUM_SKKM'
      'WHERE'
      '    IDKKM = :OLD_IDKKM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SKKM'
      'WHERE'
      '        IDKKM = :OLD_IDKKM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SKKM('
      '    IDKKM,'
      '    NAMEKKM,'
      '    GID_SKKM,'
      '    CATOBMKKM,'
      '    IDBASE_SKKM,'
      '    PREFIKS_NUM_SKKM'
      ')'
      'VALUES('
      '    :IDKKM,'
      '    :NAMEKKM,'
      '    :GID_SKKM,'
      '    :CATOBMKKM,'
      '    :IDBASE_SKKM,'
      '    :PREFIKS_NUM_SKKM'
      ')')
    RefreshSQL.Strings = (
      'select SKKM.*'
      'from '
      '  SKKM '
      ''
      'where(  '
      '  IDKKM=:ID'
      '     ) and (     SKKM.IDKKM = :OLD_IDKKM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SKKM.*'
      'from '
      '  SKKM '
      ''
      'where '
      '  IDKKM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SKKM'
    AutoUpdateOptions.KeyFields = 'IDKKM'
    AutoUpdateOptions.GeneratorName = 'GEN_SKKM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    object ElementIDKKM: TFIBBCDField
      FieldName = 'IDKKM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object ElementGID_SKKM: TFIBWideStringField
      FieldName = 'GID_SKKM'
      Size = 10
    end
    object ElementCATOBMKKM: TFIBWideStringField
      FieldName = 'CATOBMKKM'
      Size = 200
    end
    object ElementPREFIKS_NUM_SKKM: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_SKKM'
      Size = 3
    end
  end
end
