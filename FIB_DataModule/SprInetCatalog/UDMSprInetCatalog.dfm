object DMSprInetCatalog: TDMSprInetCatalog
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 327
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from sinetcatalog')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SINETCATALOG: TFIBLargeIntField
      FieldName = 'ID_SINETCATALOG'
    end
    object TableIDBASE_SINETCATALOG: TFIBLargeIntField
      FieldName = 'IDBASE_SINETCATALOG'
    end
    object TableGID_SINETCATALOG: TFIBWideStringField
      FieldName = 'GID_SINETCATALOG'
      Size = 10
    end
    object TableNAME_SINETCATALOG: TFIBWideStringField
      FieldName = 'NAME_SINETCATALOG'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SINETCATALOG'
      'SET '
      '    IDBASE_SINETCATALOG = :IDBASE_SINETCATALOG,'
      '    GID_SINETCATALOG = :GID_SINETCATALOG,'
      '    NAME_SINETCATALOG = :NAME_SINETCATALOG'
      'WHERE'
      '    ID_SINETCATALOG = :OLD_ID_SINETCATALOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SINETCATALOG'
      'WHERE'
      '        ID_SINETCATALOG = :OLD_ID_SINETCATALOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SINETCATALOG('
      '    ID_SINETCATALOG,'
      '    IDBASE_SINETCATALOG,'
      '    GID_SINETCATALOG,'
      '    NAME_SINETCATALOG'
      ')'
      'VALUES('
      '    :ID_SINETCATALOG,'
      '    :IDBASE_SINETCATALOG,'
      '    :GID_SINETCATALOG,'
      '    :NAME_SINETCATALOG'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sinetcatalog'
      'where(  sinetcatalog.id_sinetcatalog=:PARAM_ID'
      
        '     ) and (     SINETCATALOG.ID_SINETCATALOG = :OLD_ID_SINETCAT' +
        'ALOG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sinetcatalog'
      'where sinetcatalog.id_sinetcatalog=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SINETCATALOG'
    AutoUpdateOptions.KeyFields = 'ID_SINETCATALOG'
    AutoUpdateOptions.GeneratorName = 'GEN_SINETCATALOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SINETCATALOG: TFIBLargeIntField
      FieldName = 'ID_SINETCATALOG'
    end
    object ElementIDBASE_SINETCATALOG: TFIBLargeIntField
      FieldName = 'IDBASE_SINETCATALOG'
    end
    object ElementGID_SINETCATALOG: TFIBWideStringField
      FieldName = 'GID_SINETCATALOG'
      Size = 10
    end
    object ElementNAME_SINETCATALOG: TFIBWideStringField
      FieldName = 'NAME_SINETCATALOG'
      Size = 200
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
    Left = 256
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
    Left = 256
    Top = 64
  end
end
