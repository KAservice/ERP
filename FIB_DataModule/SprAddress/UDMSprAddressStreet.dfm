object DMSprAddressStreet: TDMSprAddressStreet
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
      'from sadr_street'
      'where sadr_street.idnaspunkt_sadr_street=:PARAM_IDOWNER'
      'order by sadr_street.name_sadr_street')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SADR_STREET: TFIBLargeIntField
      FieldName = 'ID_SADR_STREET'
    end
    object TableIDBASE_SADR_STREET: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_STREET'
    end
    object TableNAME_SADR_STREET: TFIBWideStringField
      FieldName = 'NAME_SADR_STREET'
      Size = 200
    end
    object TablePOSTCODE_SADR_STREET: TFIBWideStringField
      FieldName = 'POSTCODE_SADR_STREET'
      Size = 7
    end
    object TableIDNASPUNKT_SADR_STREET: TFIBLargeIntField
      FieldName = 'IDNASPUNKT_SADR_STREET'
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
      'UPDATE SADR_STREET'
      'SET '
      '    IDBASE_SADR_STREET = :IDBASE_SADR_STREET,'
      '    IDEXT_BASE_SADR_STREET = :IDEXT_BASE_SADR_STREET,'
      '    IDEXT_DOUT_SADR_STREET = :IDEXT_DOUT_SADR_STREET,'
      '    TYPE_TBL_SADR_STREET = :TYPE_TBL_SADR_STREET,'
      '    NAME_SADR_STREET = :NAME_SADR_STREET,'
      '    POSTCODE_SADR_STREET = :POSTCODE_SADR_STREET,'
      '    IDNASPUNKT_SADR_STREET = :IDNASPUNKT_SADR_STREET'
      'WHERE'
      '    ID_SADR_STREET = :OLD_ID_SADR_STREET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SADR_STREET'
      'WHERE'
      '        ID_SADR_STREET = :OLD_ID_SADR_STREET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SADR_STREET('
      '    ID_SADR_STREET,'
      '    IDBASE_SADR_STREET,'
      '    IDEXT_BASE_SADR_STREET,'
      '    IDEXT_DOUT_SADR_STREET,'
      '    TYPE_TBL_SADR_STREET,'
      '    NAME_SADR_STREET,'
      '    POSTCODE_SADR_STREET,'
      '    IDNASPUNKT_SADR_STREET'
      ')'
      'VALUES('
      '    :ID_SADR_STREET,'
      '    :IDBASE_SADR_STREET,'
      '    :IDEXT_BASE_SADR_STREET,'
      '    :IDEXT_DOUT_SADR_STREET,'
      '    :TYPE_TBL_SADR_STREET,'
      '    :NAME_SADR_STREET,'
      '    :POSTCODE_SADR_STREET,'
      '    :IDNASPUNKT_SADR_STREET'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sadr_street'
      
        'left outer join sadr_naspunkt on sadr_street.idnaspunkt_sadr_str' +
        'eet=sadr_naspunkt.id_sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where(  sadr_rayon.id_sadr_rayon=:PARAM_ID'
      
        '     ) and (     SADR_STREET.ID_SADR_STREET = :OLD_ID_SADR_STREE' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sadr_street'
      
        'left outer join sadr_naspunkt on sadr_street.idnaspunkt_sadr_str' +
        'eet=sadr_naspunkt.id_sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where sadr_street.id_sadr_street=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SADR_STREET'
    AutoUpdateOptions.KeyFields = 'ID_SADR_STREET'
    AutoUpdateOptions.GeneratorName = 'GEN_SADR_STREET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SADR_STREET: TFIBLargeIntField
      FieldName = 'ID_SADR_STREET'
    end
    object ElementIDBASE_SADR_STREET: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_STREET'
    end
    object ElementNAME_SADR_STREET: TFIBWideStringField
      FieldName = 'NAME_SADR_STREET'
      Size = 200
    end
    object ElementPOSTCODE_SADR_STREET: TFIBWideStringField
      FieldName = 'POSTCODE_SADR_STREET'
      Size = 7
    end
    object ElementIDNASPUNKT_SADR_STREET: TFIBLargeIntField
      FieldName = 'IDNASPUNKT_SADR_STREET'
    end
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
