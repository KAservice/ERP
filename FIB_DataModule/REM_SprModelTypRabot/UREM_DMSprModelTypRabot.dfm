object REM_DMSprModelTypRabot: TREM_DMSprModelTypRabot
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
      'select rem_smodel_trab.*,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_smodel_trab'
      
        'left outer join rem_styprabot on rem_smodel_trab.idtr_rem_smodel' +
        '_trab=rem_styprabot.id_rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'where rem_smodel_trab.idmodel_rem_smodel_trab=:PARAM_IDOWNER'
      'order by rem_styprabot.name_rem_styprabot')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_PROPVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_PROPVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_PROPVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_TRAB'
    end
    object TableIDBASE_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_TRAB'
    end
    object TableIDTR_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDTR_REM_SMODEL_TRAB'
    end
    object TableIDMODEL_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_TRAB'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
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
      'UPDATE REM_SMODEL_TRAB'
      'SET '
      '    IDBASE_REM_SMODEL_TRAB = :IDBASE_REM_SMODEL_TRAB,'
      '    IDTR_REM_SMODEL_TRAB = :IDTR_REM_SMODEL_TRAB,'
      '    IDMODEL_REM_SMODEL_TRAB = :IDMODEL_REM_SMODEL_TRAB'
      'WHERE'
      '    ID_REM_SMODEL_TRAB = :OLD_ID_REM_SMODEL_TRAB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL_TRAB'
      'WHERE'
      '        ID_REM_SMODEL_TRAB = :OLD_ID_REM_SMODEL_TRAB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL_TRAB('
      '    ID_REM_SMODEL_TRAB,'
      '    IDBASE_REM_SMODEL_TRAB,'
      '    IDTR_REM_SMODEL_TRAB,'
      '    IDMODEL_REM_SMODEL_TRAB'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL_TRAB,'
      '    :IDBASE_REM_SMODEL_TRAB,'
      '    :IDTR_REM_SMODEL_TRAB,'
      '    :IDMODEL_REM_SMODEL_TRAB'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel_trab.*,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_smodel_trab'
      
        'left outer join rem_styprabot on rem_smodel_trab.idtr_rem_smodel' +
        '_trab=rem_styprabot.id_rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'where(  rem_smodel_trab.id_rem_smodel_trab=:PARAM_ID'
      
        '     ) and (     REM_SMODEL_TRAB.ID_REM_SMODEL_TRAB = :OLD_ID_RE' +
        'M_SMODEL_TRAB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel_trab.*,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_smodel_trab'
      
        'left outer join rem_styprabot on rem_smodel_trab.idtr_rem_smodel' +
        '_trab=rem_styprabot.id_rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'where rem_smodel_trab.id_rem_smodel_trab=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_TRAB'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_TRAB'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_TRAB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_TRAB'
    end
    object ElementIDBASE_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_TRAB'
    end
    object ElementIDTR_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDTR_REM_SMODEL_TRAB'
    end
    object ElementIDMODEL_REM_SMODEL_TRAB: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_TRAB'
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
      Size = 200
    end
  end
  object Query: TpFIBQuery
    Left = 312
    Top = 160
  end
end
