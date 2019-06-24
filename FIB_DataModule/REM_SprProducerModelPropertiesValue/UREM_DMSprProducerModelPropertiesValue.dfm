object REM_DMSprProducerModelPropertiesValue: TREM_DMSprProducerModelPropertiesValue
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
      'select rem_sprmod_prval.*,'
      '        sprop.name_sprop,'
      '        sprop.name_for_print_sprop,'
      '        spropvaluelist.name_spropvaluelist,'
      '        sprop_grp.name_sprop_grp,'
      '        sprop_grp.name_for_print_sprop_grp'
      'from rem_sprmod_prval'
      
        'left outer join sprop on rem_sprmod_prval.idprop_rem_sprmod_prva' +
        'l=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_sprmod_prval.idpvl_rem_spr' +
        'mod_prval=spropvaluelist.id_spropvaluelist'
      
        'left outer join sprop_grp on sprop_grp.id_sprop_grp=sprop.idgrp_' +
        'sprop'
      'where rem_sprmod_prval.idprmodel_rem_sprmod_prval=:PARAM_IDOWNER'
      'order by rem_sprmod_prval.ism_rem_sprmod_prval')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMOD_PRVAL'
    end
    object TableIDBASE_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMOD_PRVAL'
    end
    object TableGID_REM_SPRMOD_PRVAL: TFIBWideStringField
      FieldName = 'GID_REM_SPRMOD_PRVAL'
      Size = 10
    end
    object TableIDPRMODEL_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SPRMOD_PRVAL'
    end
    object TableIDPROP_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPROP_REM_SPRMOD_PRVAL'
    end
    object TableIDPVL_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPVL_REM_SPRMOD_PRVAL'
    end
    object TableVALTEXT_REM_SPRMOD_PRVAL: TFIBWideStringField
      FieldName = 'VALTEXT_REM_SPRMOD_PRVAL'
      Size = 250
    end
    object TableISM_REM_SPRMOD_PRVAL: TFIBDateTimeField
      FieldName = 'ISM_REM_SPRMOD_PRVAL'
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
      'UPDATE REM_SPRMOD_PRVAL'
      'SET '
      '    IDBASE_REM_SPRMOD_PRVAL = :IDBASE_REM_SPRMOD_PRVAL,'
      '    GID_REM_SPRMOD_PRVAL = :GID_REM_SPRMOD_PRVAL,'
      '    IDPRMODEL_REM_SPRMOD_PRVAL = :IDPRMODEL_REM_SPRMOD_PRVAL,'
      '    IDPROP_REM_SPRMOD_PRVAL = :IDPROP_REM_SPRMOD_PRVAL,'
      '    IDPVL_REM_SPRMOD_PRVAL = :IDPVL_REM_SPRMOD_PRVAL,'
      '    VALTEXT_REM_SPRMOD_PRVAL = :VALTEXT_REM_SPRMOD_PRVAL,'
      '    ISM_REM_SPRMOD_PRVAL = :ISM_REM_SPRMOD_PRVAL'
      'WHERE'
      '    ID_REM_SPRMOD_PRVAL = :OLD_ID_REM_SPRMOD_PRVAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRMOD_PRVAL'
      'WHERE'
      '        ID_REM_SPRMOD_PRVAL = :OLD_ID_REM_SPRMOD_PRVAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRMOD_PRVAL('
      '    ID_REM_SPRMOD_PRVAL,'
      '    IDBASE_REM_SPRMOD_PRVAL,'
      '    GID_REM_SPRMOD_PRVAL,'
      '    IDPRMODEL_REM_SPRMOD_PRVAL,'
      '    IDPROP_REM_SPRMOD_PRVAL,'
      '    IDPVL_REM_SPRMOD_PRVAL,'
      '    VALTEXT_REM_SPRMOD_PRVAL,'
      '    ISM_REM_SPRMOD_PRVAL'
      ')'
      'VALUES('
      '    :ID_REM_SPRMOD_PRVAL,'
      '    :IDBASE_REM_SPRMOD_PRVAL,'
      '    :GID_REM_SPRMOD_PRVAL,'
      '    :IDPRMODEL_REM_SPRMOD_PRVAL,'
      '    :IDPROP_REM_SPRMOD_PRVAL,'
      '    :IDPVL_REM_SPRMOD_PRVAL,'
      '    :VALTEXT_REM_SPRMOD_PRVAL,'
      '    :ISM_REM_SPRMOD_PRVAL'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprmod_prval.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from rem_sprmod_prval'
      
        'left outer join sprop on rem_sprmod_prval.idprop_rem_sprmod_prva' +
        'l=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_sprmod_prval.idpvl_rem_spr' +
        'mod_prval=spropvaluelist.id_spropvaluelist'
      'where(  rem_sprmod_prval.id_rem_sprmod_prval=:PARAM_ID'
      
        '     ) and (     REM_SPRMOD_PRVAL.ID_REM_SPRMOD_PRVAL = :OLD_ID_' +
        'REM_SPRMOD_PRVAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprmod_prval.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from rem_sprmod_prval'
      
        'left outer join sprop on rem_sprmod_prval.idprop_rem_sprmod_prva' +
        'l=sprop.id_sprop'
      
        'left outer join spropvaluelist on rem_sprmod_prval.idpvl_rem_spr' +
        'mod_prval=spropvaluelist.id_spropvaluelist'
      'where rem_sprmod_prval.id_rem_sprmod_prval=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMOD_PRVAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMOD_PRVAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMOD_PRVAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMOD_PRVAL'
    end
    object ElementIDBASE_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMOD_PRVAL'
    end
    object ElementGID_REM_SPRMOD_PRVAL: TFIBWideStringField
      FieldName = 'GID_REM_SPRMOD_PRVAL'
      Size = 10
    end
    object ElementIDPRMODEL_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SPRMOD_PRVAL'
    end
    object ElementIDPROP_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPROP_REM_SPRMOD_PRVAL'
    end
    object ElementIDPVL_REM_SPRMOD_PRVAL: TFIBLargeIntField
      FieldName = 'IDPVL_REM_SPRMOD_PRVAL'
    end
    object ElementVALTEXT_REM_SPRMOD_PRVAL: TFIBWideStringField
      FieldName = 'VALTEXT_REM_SPRMOD_PRVAL'
      Size = 250
    end
    object ElementISM_REM_SPRMOD_PRVAL: TFIBDateTimeField
      FieldName = 'ISM_REM_SPRMOD_PRVAL'
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
