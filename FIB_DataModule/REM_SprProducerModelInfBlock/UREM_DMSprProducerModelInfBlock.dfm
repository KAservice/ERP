object REM_DMSprProducerModelInfBlock: TREM_DMSprProducerModelInfBlock
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
      'select rem_sprmodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_sprmodel_inf'
      
        'left outer join art_ib on rem_sprmodel_inf.idib_rem_sprmodel_inf' +
        '=art_ib.id_art_ib'
      'where rem_sprmodel_inf.idprmodel_rem_sprmodel_inf=:PARAM_IDOWNER'
      'order by rem_sprmodel_inf.ism_rem_sprmodel_inf')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL_INF'
    end
    object TableIDBASE_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMODEL_INF'
    end
    object TableGID_REM_SPRMODEL_INF: TFIBWideStringField
      FieldName = 'GID_REM_SPRMODEL_INF'
      Size = 10
    end
    object TableIDPRMODEL_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SPRMODEL_INF'
    end
    object TableIDIB_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDIB_REM_SPRMODEL_INF'
    end
    object TableISM_REM_SPRMODEL_INF: TFIBDateTimeField
      FieldName = 'ISM_REM_SPRMODEL_INF'
    end
    object TableNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
      Size = 200
    end
    object TableDESCR_ART_IB: TFIBWideStringField
      FieldName = 'DESCR_ART_IB'
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
      'UPDATE REM_SPRMODEL_INF'
      'SET '
      '    IDBASE_REM_SPRMODEL_INF = :IDBASE_REM_SPRMODEL_INF,'
      '    GID_REM_SPRMODEL_INF = :GID_REM_SPRMODEL_INF,'
      '    IDPRMODEL_REM_SPRMODEL_INF = :IDPRMODEL_REM_SPRMODEL_INF,'
      '    IDIB_REM_SPRMODEL_INF = :IDIB_REM_SPRMODEL_INF,'
      '    ISM_REM_SPRMODEL_INF = :ISM_REM_SPRMODEL_INF'
      'WHERE'
      '    ID_REM_SPRMODEL_INF = :OLD_ID_REM_SPRMODEL_INF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRMODEL_INF'
      'WHERE'
      '        ID_REM_SPRMODEL_INF = :OLD_ID_REM_SPRMODEL_INF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRMODEL_INF('
      '    ID_REM_SPRMODEL_INF,'
      '    IDBASE_REM_SPRMODEL_INF,'
      '    GID_REM_SPRMODEL_INF,'
      '    IDPRMODEL_REM_SPRMODEL_INF,'
      '    IDIB_REM_SPRMODEL_INF,'
      '    ISM_REM_SPRMODEL_INF'
      ')'
      'VALUES('
      '    :ID_REM_SPRMODEL_INF,'
      '    :IDBASE_REM_SPRMODEL_INF,'
      '    :GID_REM_SPRMODEL_INF,'
      '    :IDPRMODEL_REM_SPRMODEL_INF,'
      '    :IDIB_REM_SPRMODEL_INF,'
      '    :ISM_REM_SPRMODEL_INF'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprmodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_sprmodel_inf'
      
        'left outer join art_ib on rem_sprmodel_inf.idib_rem_sprmodel_inf' +
        '=art_ib.id_art_ib'
      'where(  rem_sprmodel_inf.id_rem_sprmodel_inf=:PARAM_ID'
      
        '     ) and (     REM_SPRMODEL_INF.ID_REM_SPRMODEL_INF = :OLD_ID_' +
        'REM_SPRMODEL_INF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprmodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_sprmodel_inf'
      
        'left outer join art_ib on rem_sprmodel_inf.idib_rem_sprmodel_inf' +
        '=art_ib.id_art_ib'
      'where rem_sprmodel_inf.id_rem_sprmodel_inf=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMODEL_INF'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMODEL_INF'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMODEL_INF_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL_INF'
    end
    object ElementIDBASE_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMODEL_INF'
    end
    object ElementGID_REM_SPRMODEL_INF: TFIBWideStringField
      FieldName = 'GID_REM_SPRMODEL_INF'
      Size = 10
    end
    object ElementIDPRMODEL_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SPRMODEL_INF'
    end
    object ElementIDIB_REM_SPRMODEL_INF: TFIBLargeIntField
      FieldName = 'IDIB_REM_SPRMODEL_INF'
    end
    object ElementISM_REM_SPRMODEL_INF: TFIBDateTimeField
      FieldName = 'ISM_REM_SPRMODEL_INF'
    end
    object ElementNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
      Size = 200
    end
    object ElementDESCR_ART_IB: TFIBWideStringField
      FieldName = 'DESCR_ART_IB'
      Size = 200
    end
  end
  object Query: TpFIBQuery
    Left = 312
    Top = 160
  end
end
