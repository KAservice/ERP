object DMSprAddressNasPunkt: TDMSprAddressNasPunkt
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
      'from sadr_naspunkt'
      'where sadr_naspunkt.idrayon_sadr_naspunkt=:PARAM_IDOWNER'
      'order by sadr_naspunkt.name_sadr_naspunkt')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'ID_SADR_NASPUNKT'
    end
    object TableIDBASE_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_NASPUNKT'
    end
    object TableIDRAYON_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'IDRAYON_SADR_NASPUNKT'
    end
    object TableNAME_SADR_NASPUNKT: TFIBWideStringField
      FieldName = 'NAME_SADR_NASPUNKT'
      Size = 200
    end
    object TableFL_GOROD_SADR_NASPUNKT: TFIBIntegerField
      FieldName = 'FL_GOROD_SADR_NASPUNKT'
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
      'UPDATE SADR_NASPUNKT'
      'SET '
      '    IDBASE_SADR_NASPUNKT = :IDBASE_SADR_NASPUNKT,'
      '    IDRAYON_SADR_NASPUNKT = :IDRAYON_SADR_NASPUNKT,'
      '    NAME_SADR_NASPUNKT = :NAME_SADR_NASPUNKT,'
      '    FL_GOROD_SADR_NASPUNKT = :FL_GOROD_SADR_NASPUNKT'
      'WHERE'
      '    ID_SADR_NASPUNKT = :OLD_ID_SADR_NASPUNKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SADR_NASPUNKT'
      'WHERE'
      '        ID_SADR_NASPUNKT = :OLD_ID_SADR_NASPUNKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SADR_NASPUNKT('
      '    ID_SADR_NASPUNKT,'
      '    IDBASE_SADR_NASPUNKT,'
      '    IDRAYON_SADR_NASPUNKT,'
      '    NAME_SADR_NASPUNKT,'
      '    FL_GOROD_SADR_NASPUNKT'
      ')'
      'VALUES('
      '    :ID_SADR_NASPUNKT,'
      '    :IDBASE_SADR_NASPUNKT,'
      '    :IDRAYON_SADR_NASPUNKT,'
      '    :NAME_SADR_NASPUNKT,'
      '    :FL_GOROD_SADR_NASPUNKT'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where(  sadr_rayon.id_sadr_rayon=:PARAM_ID'
      
        '     ) and (     SADR_NASPUNKT.ID_SADR_NASPUNKT = :OLD_ID_SADR_N' +
        'ASPUNKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where sadr_rayon.id_sadr_rayon=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SADR_NASPUNKT'
    AutoUpdateOptions.KeyFields = 'ID_SADR_NASPUNKT'
    AutoUpdateOptions.GeneratorName = 'GEN_SADR_NASPUNKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'ID_SADR_NASPUNKT'
    end
    object ElementIDBASE_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_NASPUNKT'
    end
    object ElementIDRAYON_SADR_NASPUNKT: TFIBLargeIntField
      FieldName = 'IDRAYON_SADR_NASPUNKT'
    end
    object ElementNAME_SADR_NASPUNKT: TFIBWideStringField
      FieldName = 'NAME_SADR_NASPUNKT'
      Size = 200
    end
    object ElementFL_GOROD_SADR_NASPUNKT: TFIBIntegerField
      FieldName = 'FL_GOROD_SADR_NASPUNKT'
    end
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
