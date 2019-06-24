object DMSprTypeNachisl: TDMSprTypeNachisl
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 195
  Width = 489
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
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STNACHISL')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STNACHISL: TFIBBCDField
      FieldName = 'ID_STNACHISL'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_STNACHISL: TFIBBCDField
      FieldName = 'IDBASE_STNACHISL'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_STNACHISL: TFIBWideStringField
      FieldName = 'NAME_STNACHISL'
      Size = 200
    end
    object TableGID_STNACHISL: TFIBWideStringField
      FieldName = 'GID_STNACHISL'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE STNACHISL'
      'SET '
      '    IDBASE_STNACHISL = :IDBASE_STNACHISL,'
      '    NAME_STNACHISL = :NAME_STNACHISL,'
      '    GID_STNACHISL = :GID_STNACHISL'
      'WHERE'
      '    ID_STNACHISL = :OLD_ID_STNACHISL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STNACHISL'
      'WHERE'
      '        ID_STNACHISL = :OLD_ID_STNACHISL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STNACHISL('
      '    ID_STNACHISL,'
      '    IDBASE_STNACHISL,'
      '    NAME_STNACHISL,'
      '    GID_STNACHISL'
      ')'
      'VALUES('
      '    :ID_STNACHISL,'
      '    :IDBASE_STNACHISL,'
      '    :NAME_STNACHISL,'
      '    :GID_STNACHISL'
      ')')
    RefreshSQL.Strings = (
      'select * from STNACHISL where(  ID_STNACHISL=:ID'
      '     ) and (     STNACHISL.ID_STNACHISL = :OLD_ID_STNACHISL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from STNACHISL where ID_STNACHISL=:ID')
    AutoUpdateOptions.UpdateTableName = 'STNACHISL'
    AutoUpdateOptions.KeyFields = 'ID_STNACHISL'
    AutoUpdateOptions.GeneratorName = 'GEN_STNACHISL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementID_STNACHISL: TFIBBCDField
      FieldName = 'ID_STNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_STNACHISL: TFIBBCDField
      FieldName = 'IDBASE_STNACHISL'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_STNACHISL: TFIBWideStringField
      FieldName = 'NAME_STNACHISL'
      Size = 200
    end
    object ElementGID_STNACHISL: TFIBWideStringField
      FieldName = 'GID_STNACHISL'
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
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 280
    Top = 56
    qoStartTransaction = True
  end
end
