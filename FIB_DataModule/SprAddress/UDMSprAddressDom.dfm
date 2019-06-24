object DMSprAddressDom: TDMSprAddressDom
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
      'from sadr_dom'
      'where sadr_dom.idstreet_sadr_dom=:PARAM_IDOWNER'
      'order by sadr_dom.name_sadr_dom')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SADR_DOM: TFIBLargeIntField
      FieldName = 'ID_SADR_DOM'
    end
    object TableIDBASE_SADR_DOM: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_DOM'
    end
    object TableIDSTREET_SADR_DOM: TFIBLargeIntField
      FieldName = 'IDSTREET_SADR_DOM'
    end
    object TableNAME_SADR_DOM: TFIBWideStringField
      FieldName = 'NAME_SADR_DOM'
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
      'UPDATE SADR_DOM'
      'SET '
      '    IDBASE_SADR_DOM = :IDBASE_SADR_DOM,'
      '    IDSTREET_SADR_DOM = :IDSTREET_SADR_DOM,'
      '    NAME_SADR_DOM = :NAME_SADR_DOM'
      'WHERE'
      '    ID_SADR_DOM = :OLD_ID_SADR_DOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SADR_DOM'
      'WHERE'
      '        ID_SADR_DOM = :OLD_ID_SADR_DOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SADR_DOM('
      '    ID_SADR_DOM,'
      '    IDBASE_SADR_DOM,'
      '    IDSTREET_SADR_DOM,'
      '    NAME_SADR_DOM'
      ')'
      'VALUES('
      '    :ID_SADR_DOM,'
      '    :IDBASE_SADR_DOM,'
      '    :IDSTREET_SADR_DOM,'
      '    :NAME_SADR_DOM'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sadr_dom'
      
        'left outer join sadr_street on sadr_dom.idstreet_sadr_dom=sadr_s' +
        'treet.id_sadr_street'
      
        'left outer join sadr_naspunkt on sadr_street.idnaspunkt_sadr_str' +
        'eet=sadr_naspunkt.id_sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where(  sadr_rayon.id_sadr_rayon=:PARAM_ID'
      '     ) and (     SADR_DOM.ID_SADR_DOM = :OLD_ID_SADR_DOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sadr_dom'
      
        'left outer join sadr_street on sadr_dom.idstreet_sadr_dom=sadr_s' +
        'treet.id_sadr_street'
      
        'left outer join sadr_naspunkt on sadr_street.idnaspunkt_sadr_str' +
        'eet=sadr_naspunkt.id_sadr_naspunkt'
      
        'left outer join sadr_rayon on sadr_naspunkt.idrayon_sadr_naspunk' +
        't=sadr_rayon.id_sadr_rayon'
      
        'left outer join sadr_region on sadr_rayon.idregion_sadr_rayon=sa' +
        'dr_region.id_sadr_region'
      'where sadr_rayon.id_sadr_rayon=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SADR_DOM'
    AutoUpdateOptions.KeyFields = 'ID_SADR_DOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SADR_DOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SADR_DOM: TFIBLargeIntField
      FieldName = 'ID_SADR_DOM'
    end
    object ElementIDBASE_SADR_DOM: TFIBLargeIntField
      FieldName = 'IDBASE_SADR_DOM'
    end
    object ElementIDSTREET_SADR_DOM: TFIBLargeIntField
      FieldName = 'IDSTREET_SADR_DOM'
    end
    object ElementNAME_SADR_DOM: TFIBWideStringField
      FieldName = 'NAME_SADR_DOM'
    end
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
