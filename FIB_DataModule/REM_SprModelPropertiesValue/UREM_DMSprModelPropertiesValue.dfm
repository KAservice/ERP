object REM_DMSprModelPropertiesValue: TREM_DMSprModelPropertiesValue
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
      'select rem_smodel_propval.*,'
      '        sprop.name_sprop,'
      '        sprop.name_for_print_sprop,'
      '        spropvaluelist.name_spropvaluelist,'
      '        sprop_grp.name_sprop_grp,'
      '        sprop_grp.name_for_print_sprop_grp'
      'from rem_smodel_propval'
      
        'left outer join sprop on rem_smodel_propval.idprop_rem_smodel_pr' +
        'opval=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_smodel_propval.idpvl_rem_s' +
        'model_propval=spropvaluelist.id_spropvaluelist'
      
        'left outer join sprop_grp on sprop_grp.id_sprop_grp=sprop.idgrp_' +
        'sprop'
      
        'where rem_smodel_propval.idmodel_rem_smodel_propval=:PARAM_IDOWN' +
        'ER'
      'order by rem_smodel_propval.ism_rem_smodel_propval')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_PROPVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_PROPVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_PROPVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_PROPVAL'
    end
    object TableIDBASE_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_PROPVAL'
    end
    object TableGID_REM_SMODEL_PROPVAL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_PROPVAL'
      Size = 10
    end
    object TableIDMODEL_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_PROPVAL'
    end
    object TableIDPROP_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDPROP_REM_SMODEL_PROPVAL'
    end
    object TableIDPVL_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDPVL_REM_SMODEL_PROPVAL'
    end
    object TableVALTEXT_REM_SMODEL_PROPVAL: TFIBWideStringField
      FieldName = 'VALTEXT_REM_SMODEL_PROPVAL'
      Size = 250
    end
    object TableISM_REM_SMODEL_PROPVAL: TFIBDateTimeField
      FieldName = 'ISM_REM_SMODEL_PROPVAL'
    end
    object TableNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object TableNAME_FOR_PRINT_SPROP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP'
      Size = 200
    end
    object TableNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
      Size = 200
    end
    object TableNAME_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROP_GRP'
      Size = 200
    end
    object TableNAME_FOR_PRINT_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP_GRP'
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
      'UPDATE REM_SMODEL_PROPVAL'
      'SET '
      '    IDBASE_REM_SMODEL_PROPVAL = :IDBASE_REM_SMODEL_PROPVAL,'
      '    GID_REM_SMODEL_PROPVAL = :GID_REM_SMODEL_PROPVAL,'
      '    IDMODEL_REM_SMODEL_PROPVAL = :IDMODEL_REM_SMODEL_PROPVAL,'
      '    IDPROP_REM_SMODEL_PROPVAL = :IDPROP_REM_SMODEL_PROPVAL,'
      '    IDPVL_REM_SMODEL_PROPVAL = :IDPVL_REM_SMODEL_PROPVAL,'
      '    VALTEXT_REM_SMODEL_PROPVAL = :VALTEXT_REM_SMODEL_PROPVAL,'
      '    ISM_REM_SMODEL_PROPVAL = :ISM_REM_SMODEL_PROPVAL'
      'WHERE'
      '    ID_REM_SMODEL_PROPVAL = :OLD_ID_REM_SMODEL_PROPVAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL_PROPVAL'
      'WHERE'
      '        ID_REM_SMODEL_PROPVAL = :OLD_ID_REM_SMODEL_PROPVAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL_PROPVAL('
      '    ID_REM_SMODEL_PROPVAL,'
      '    IDBASE_REM_SMODEL_PROPVAL,'
      '    GID_REM_SMODEL_PROPVAL,'
      '    IDMODEL_REM_SMODEL_PROPVAL,'
      '    IDPROP_REM_SMODEL_PROPVAL,'
      '    IDPVL_REM_SMODEL_PROPVAL,'
      '    VALTEXT_REM_SMODEL_PROPVAL,'
      '    ISM_REM_SMODEL_PROPVAL'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL_PROPVAL,'
      '    :IDBASE_REM_SMODEL_PROPVAL,'
      '    :GID_REM_SMODEL_PROPVAL,'
      '    :IDMODEL_REM_SMODEL_PROPVAL,'
      '    :IDPROP_REM_SMODEL_PROPVAL,'
      '    :IDPVL_REM_SMODEL_PROPVAL,'
      '    :VALTEXT_REM_SMODEL_PROPVAL,'
      '    :ISM_REM_SMODEL_PROPVAL'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel_propval.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from rem_smodel_propval'
      
        'left outer join sprop on rem_smodel_propval.idprop_rem_smodel_pr' +
        'opval=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_smodel_propval.idpvl_rem_s' +
        'model_propval=spropvaluelist.id_spropvaluelist'
      'where(  rem_smodel_propval.id_rem_smodel_propval=:PARAM_ID'
      
        '     ) and (     REM_SMODEL_PROPVAL.ID_REM_SMODEL_PROPVAL = :OLD' +
        '_ID_REM_SMODEL_PROPVAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel_propval.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from rem_smodel_propval'
      
        'left outer join sprop on rem_smodel_propval.idprop_rem_smodel_pr' +
        'opval=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_smodel_propval.idpvl_rem_s' +
        'model_propval=spropvaluelist.id_spropvaluelist'
      'where rem_smodel_propval.id_rem_smodel_propval=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_PROPVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_PROPVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_PROPVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_PROPVAL'
    end
    object ElementIDBASE_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_PROPVAL'
    end
    object ElementGID_REM_SMODEL_PROPVAL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_PROPVAL'
      Size = 10
    end
    object ElementIDMODEL_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_PROPVAL'
    end
    object ElementIDPROP_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDPROP_REM_SMODEL_PROPVAL'
    end
    object ElementIDPVL_REM_SMODEL_PROPVAL: TFIBLargeIntField
      FieldName = 'IDPVL_REM_SMODEL_PROPVAL'
    end
    object ElementVALTEXT_REM_SMODEL_PROPVAL: TFIBWideStringField
      FieldName = 'VALTEXT_REM_SMODEL_PROPVAL'
      Size = 250
    end
    object ElementISM_REM_SMODEL_PROPVAL: TFIBDateTimeField
      FieldName = 'ISM_REM_SMODEL_PROPVAL'
    end
    object ElementNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object ElementNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
      Size = 200
    end
  end
  object Query: TpFIBQuery
    Left = 312
    Top = 160
  end
end
