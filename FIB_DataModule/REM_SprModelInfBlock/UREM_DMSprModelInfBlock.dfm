object REM_DMSprModelInfBlock: TREM_DMSprModelInfBlock
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
      'select rem_smodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_smodel_inf'
      
        'left outer join art_ib on rem_smodel_inf.idib_rem_smodel_inf=art' +
        '_ib.id_art_ib'
      'where rem_smodel_inf.idmodel_rem_smodel_inf=:PARAM_IDOWNER'
      'order by rem_smodel_inf.ism_rem_smodel_inf')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_INF'
    end
    object TableIDBASE_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_INF'
    end
    object TableGID_REM_SMODEL_INF: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_INF'
      Size = 10
    end
    object TableIDMODEL_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_INF'
    end
    object TableIDIB_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDIB_REM_SMODEL_INF'
    end
    object TableISM_REM_SMODEL_INF: TFIBDateTimeField
      FieldName = 'ISM_REM_SMODEL_INF'
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
      'UPDATE REM_SMODEL_INF'
      'SET '
      '    IDBASE_REM_SMODEL_INF = :IDBASE_REM_SMODEL_INF,'
      '    GID_REM_SMODEL_INF = :GID_REM_SMODEL_INF,'
      '    IDMODEL_REM_SMODEL_INF = :IDMODEL_REM_SMODEL_INF,'
      '    IDIB_REM_SMODEL_INF = :IDIB_REM_SMODEL_INF,'
      '    ISM_REM_SMODEL_INF = :ISM_REM_SMODEL_INF'
      'WHERE'
      '    ID_REM_SMODEL_INF = :OLD_ID_REM_SMODEL_INF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL_INF'
      'WHERE'
      '        ID_REM_SMODEL_INF = :OLD_ID_REM_SMODEL_INF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL_INF('
      '    ID_REM_SMODEL_INF,'
      '    IDBASE_REM_SMODEL_INF,'
      '    GID_REM_SMODEL_INF,'
      '    IDMODEL_REM_SMODEL_INF,'
      '    IDIB_REM_SMODEL_INF,'
      '    ISM_REM_SMODEL_INF'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL_INF,'
      '    :IDBASE_REM_SMODEL_INF,'
      '    :GID_REM_SMODEL_INF,'
      '    :IDMODEL_REM_SMODEL_INF,'
      '    :IDIB_REM_SMODEL_INF,'
      '    :ISM_REM_SMODEL_INF'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_smodel_inf'
      
        'left outer join art_ib on rem_smodel_inf.idib_rem_smodel_inf=art' +
        '_ib.id_art_ib'
      'where(  rem_smodel_inf.id_rem_smodel_inf=:PARAM_ID'
      
        '     ) and (     REM_SMODEL_INF.ID_REM_SMODEL_INF = :OLD_ID_REM_' +
        'SMODEL_INF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel_inf.*,'
      '        art_ib.name_art_ib,'
      '        art_ib.descr_art_ib'
      'from rem_smodel_inf'
      
        'left outer join art_ib on rem_smodel_inf.idib_rem_smodel_inf=art' +
        '_ib.id_art_ib'
      'where rem_smodel_inf.id_rem_smodel_inf=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_INF'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_INF'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_INF_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_INF'
    end
    object ElementIDBASE_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_INF'
    end
    object ElementGID_REM_SMODEL_INF: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_INF'
      Size = 10
    end
    object ElementIDMODEL_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_INF'
    end
    object ElementIDIB_REM_SMODEL_INF: TFIBLargeIntField
      FieldName = 'IDIB_REM_SMODEL_INF'
    end
    object ElementISM_REM_SMODEL_INF: TFIBDateTimeField
      FieldName = 'ISM_REM_SMODEL_INF'
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
