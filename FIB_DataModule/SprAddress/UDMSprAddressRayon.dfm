object DMSprAddressRayon: TDMSprAddressRayon
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
      'select *'
      'from sadr_rayon'
      'where sadr_rayon.idregion_sadr_rayon=:PARAM_IDOWNER'
      'order by sadr_rayon.name_sadr_rayon')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SADR_RAYON: TFIBLargeIntField
      FieldName = 'ID_SADR_RAYON'
    end
    object TableIDBASE_SADR_RAYON: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_RAYON'
    end
    object TableIDREGION_SADR_RAYON: TFIBLargeIntField
      FieldName = 'IDREGION_SADR_RAYON'
    end
    object TableNAME_SADR_RAYON: TFIBWideStringField
      FieldName = 'NAME_SADR_RAYON'
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
      'UPDATE SADR_RAYON'
      'SET '
      '    IDBASE_SADR_RAYON = :IDBASE_SADR_RAYON,'
      '    IDREGION_SADR_RAYON = :IDREGION_SADR_RAYON,'
      '    NAME_SADR_RAYON = :NAME_SADR_RAYON'
      'WHERE'
      '    ID_SADR_RAYON = :OLD_ID_SADR_RAYON'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SADR_RAYON'
      'WHERE'
      '        ID_SADR_RAYON = :OLD_ID_SADR_RAYON'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SADR_RAYON('
      '    ID_SADR_RAYON,'
      '    IDBASE_SADR_RAYON,'
      '    IDREGION_SADR_RAYON,'
      '    NAME_SADR_RAYON'
      ')'
      'VALUES('
      '    :ID_SADR_RAYON,'
      '    :IDBASE_SADR_RAYON,'
      '    :IDREGION_SADR_RAYON,'
      '    :NAME_SADR_RAYON'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where(  sadr_rayon.id_sadr_rayon=:PARAM_ID'
      '     ) and (     SADR_RAYON.ID_SADR_RAYON = :OLD_ID_SADR_RAYON'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where sadr_rayon.id_sadr_rayon=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SADR_RAYON'
    AutoUpdateOptions.KeyFields = 'ID_SADR_RAYON'
    AutoUpdateOptions.GeneratorName = 'GEN_SADR_RAYON_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SADR_RAYON: TFIBLargeIntField
      FieldName = 'ID_SADR_RAYON'
    end
    object ElementIDBASE_SADR_RAYON: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_RAYON'
    end
    object ElementIDREGION_SADR_RAYON: TFIBLargeIntField
      FieldName = 'IDREGION_SADR_RAYON'
    end
    object ElementNAME_SADR_RAYON: TFIBWideStringField
      FieldName = 'NAME_SADR_RAYON'
      Size = 200
    end
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
