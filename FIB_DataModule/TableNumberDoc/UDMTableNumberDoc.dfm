object DMTableNumberDoc: TDMTableNumberDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 165
  Width = 300
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 192
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
    Left = 192
    Top = 64
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE TNUM_DOC'
      'SET '
      '    GID_TNUM_DOC = :GID_TNUM_DOC,'
      '    DOC_TNUM_DOC = :DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC = :TYPE_TNUM_DOC'
      'WHERE'
      '    ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    TNUM_DOC'
      'WHERE'
      '        ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO TNUM_DOC('
      '    ID_TNUM_DOC,'
      '    GID_TNUM_DOC,'
      '    DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC'
      ')'
      'VALUES('
      '    :ID_TNUM_DOC,'
      '    :GID_TNUM_DOC,'
      '    :DOC_TNUM_DOC,'
      '    :TYPE_TNUM_DOC'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    ID_TNUM_DOC,'
      '    GID_TNUM_DOC,'
      '    DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC'
      'FROM'
      '    TNUM_DOC '
      ''
      ' WHERE '
      '        TNUM_DOC.ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    ID_TNUM_DOC,'
      '    GID_TNUM_DOC,'
      '    DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC'
      'FROM'
      '    TNUM_DOC ')
    AutoUpdateOptions.UpdateTableName = 'TNUM_DOC'
    AutoUpdateOptions.KeyFields = 'ID_TNUM_DOC'
    AutoUpdateOptions.GeneratorName = 'GEN_TNUM_DOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 128
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_TNUM_DOC: TFIBBCDField
      FieldName = 'ID_TNUM_DOC'
      Size = 0
      RoundByScale = True
    end
    object TableGID_TNUM_DOC: TFIBWideStringField
      FieldName = 'GID_TNUM_DOC'
      Size = 10
    end
    object TableDOC_TNUM_DOC: TFIBWideStringField
      FieldName = 'DOC_TNUM_DOC'
      Size = 10
    end
    object TableTYPE_TNUM_DOC: TFIBSmallIntField
      FieldName = 'TYPE_TNUM_DOC'
    end
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE TNUM_DOC'
      'SET '
      '    GID_TNUM_DOC = :GID_TNUM_DOC,'
      '    DOC_TNUM_DOC = :DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC = :TYPE_TNUM_DOC'
      'WHERE'
      '    ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    TNUM_DOC'
      'WHERE'
      '        ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO TNUM_DOC('
      '    ID_TNUM_DOC,'
      '    GID_TNUM_DOC,'
      '    DOC_TNUM_DOC,'
      '    TYPE_TNUM_DOC'
      ')'
      'VALUES('
      '    :ID_TNUM_DOC,'
      '    :GID_TNUM_DOC,'
      '    :DOC_TNUM_DOC,'
      '    :TYPE_TNUM_DOC'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from TNUM_DOC'
      'where(  ID_TNUM_DOC=:PARAM_ID'
      '     ) and (     TNUM_DOC.ID_TNUM_DOC = :OLD_ID_TNUM_DOC'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from TNUM_DOC'
      'where ID_TNUM_DOC=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'TNUM_DOC'
    AutoUpdateOptions.KeyFields = 'ID_TNUM_DOC'
    AutoUpdateOptions.GeneratorName = 'GEN_TNUM_DOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 128
    Top = 64
    object ElementID_TNUM_DOC: TFIBBCDField
      FieldName = 'ID_TNUM_DOC'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_TNUM_DOC: TFIBWideStringField
      FieldName = 'GID_TNUM_DOC'
      Size = 10
    end
    object ElementDOC_TNUM_DOC: TFIBWideStringField
      FieldName = 'DOC_TNUM_DOC'
      Size = 10
    end
    object ElementTYPE_TNUM_DOC: TFIBSmallIntField
      FieldName = 'TYPE_TNUM_DOC'
    end
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 128
    Top = 112
    qoStartTransaction = True
  end
end
