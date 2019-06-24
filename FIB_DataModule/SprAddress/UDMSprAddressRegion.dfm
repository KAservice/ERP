object DMSprAddressRegion: TDMSprAddressRegion
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select sadr_region.*'
      'from sadr_region'
      'order by sadr_region.name_sadr_region')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SADR_REGION: TFIBLargeIntField
      FieldName = 'ID_SADR_REGION'
    end
    object TableIDBASE_SADR_REGION: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_REGION'
    end
    object TableNAME_SADR_REGION: TFIBWideStringField
      FieldName = 'NAME_SADR_REGION'
      Size = 200
    end
    object TableCODE_SADR_REGION: TFIBWideStringField
      FieldName = 'CODE_SADR_REGION'
      Size = 5
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SADR_REGION'
      'SET '
      '    IDBASE_SADR_REGION = :IDBASE_SADR_REGION,'
      '    NAME_SADR_REGION = :NAME_SADR_REGION,'
      '    CODE_SADR_REGION = :CODE_SADR_REGION'
      'WHERE'
      '    ID_SADR_REGION = :OLD_ID_SADR_REGION'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SADR_REGION'
      'WHERE'
      '        ID_SADR_REGION = :OLD_ID_SADR_REGION'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SADR_REGION('
      '    ID_SADR_REGION,'
      '    IDBASE_SADR_REGION,'
      '    NAME_SADR_REGION,'
      '    CODE_SADR_REGION'
      ')'
      'VALUES('
      '    :ID_SADR_REGION,'
      '    :IDBASE_SADR_REGION,'
      '    :NAME_SADR_REGION,'
      '    :CODE_SADR_REGION'
      ')')
    RefreshSQL.Strings = (
      'select sadr_region.*'
      'from sadr_region'
      'where(  sadr_region.id_sadr_region=:PARAM_ID'
      
        '     ) and (     SADR_REGION.ID_SADR_REGION = :OLD_ID_SADR_REGIO' +
        'N'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sadr_region.*'
      'from sadr_region'
      'where sadr_region.id_sadr_region=:PARAM_ID'
      'order by sadr_region.name_sadr_region')
    AutoUpdateOptions.UpdateTableName = 'SADR_REGION'
    AutoUpdateOptions.KeyFields = 'ID_SADR_REGION'
    AutoUpdateOptions.GeneratorName = 'GEN_SADR_REGION_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SADR_REGION: TFIBLargeIntField
      FieldName = 'ID_SADR_REGION'
    end
    object ElementIDBASE_SADR_REGION: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_REGION'
    end
    object ElementNAME_SADR_REGION: TFIBWideStringField
      FieldName = 'NAME_SADR_REGION'
      Size = 200
    end
    object ElementCODE_SADR_REGION: TFIBWideStringField
      FieldName = 'CODE_SADR_REGION'
      Size = 5
    end
  end
  object Query: TpFIBQuery
    Left = 312
    Top = 160
  end
end
