object REM_DMSprProducerModel: TREM_DMSprProducerModel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 302
  Width = 541
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select  rem_sprmodel.id_rem_sprmodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_sprmodel.idpr_rem_sprmodel,'
      '        rem_sprmodel.idgrp_rem_sprmodel,'
      '        rem_smodel.name_rem_smodel,'
      '        sbrand.name_sbrand,'
      '        sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from rem_sprmodel'
      
        'left outer join rem_smodel on rem_sprmodel.idmodel_rem_sprmodel=' +
        'rem_smodel.id_rem_smodel'
      
        'left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbra' +
        'nd.id_sbrand'
      
        'left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=spro' +
        'ducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_sprmodel.idactcategory_r' +
        'em_sprmodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem' +
        '_sprmodel=rem_stypedevice.id_rem_stypedevice'
      'where '
      
        '    rem_sprmodel.idpr_rem_sprmodel=:PARAM_ID_GROUP_ELEMENT and r' +
        'em_sprmodel.idgrp_rem_sprmodel=:PARAM_IDGRP'
      'order by rem_sprmodel.name_rem_sprmodel'
      '')
    AutoUpdateOptions.GeneratorName = 'GEN__ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL'
    end
    object TableCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object TableNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object TableIDPR_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRMODEL'
    end
    object TableIDGRP_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRMODEL'
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object TableNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object TableNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
    object TableNAME_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'NAME_REM_STYPEDEVICE'
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
    Left = 224
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 224
    Top = 72
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE REM_SPRMODEL'
      'SET '
      '    IDBASE_REM_SPRMODEL = :IDBASE_REM_SPRMODEL,'
      '    GID_REM_SPRMODEL = :GID_REM_SPRMODEL,'
      '    IDPR_REM_SPRMODEL = :IDPR_REM_SPRMODEL,'
      '    IDGRP_REM_SPRMODEL = :IDGRP_REM_SPRMODEL,'
      '    IDMODEL_REM_SPRMODEL = :IDMODEL_REM_SPRMODEL,'
      '    CODE_REM_SPRMODEL = :CODE_REM_SPRMODEL,'
      '    NAME_REM_SPRMODEL = :NAME_REM_SPRMODEL,'
      '    IDBRAND_REM_SPRMODEL = :IDBRAND_REM_SPRMODEL,'
      '    IDACTCATEGORY_REM_SPRMODEL = :IDACTCATEGORY_REM_SPRMODEL,'
      '    IDTYPEDEVICE_REM_SPRMODEL = :IDTYPEDEVICE_REM_SPRMODEL'
      'WHERE'
      '    ID_REM_SPRMODEL = :OLD_ID_REM_SPRMODEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRMODEL'
      'WHERE'
      '        ID_REM_SPRMODEL = :OLD_ID_REM_SPRMODEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRMODEL('
      '    ID_REM_SPRMODEL,'
      '    IDBASE_REM_SPRMODEL,'
      '    GID_REM_SPRMODEL,'
      '    IDPR_REM_SPRMODEL,'
      '    IDGRP_REM_SPRMODEL,'
      '    IDMODEL_REM_SPRMODEL,'
      '    CODE_REM_SPRMODEL,'
      '    NAME_REM_SPRMODEL,'
      '    IDBRAND_REM_SPRMODEL,'
      '    IDACTCATEGORY_REM_SPRMODEL,'
      '    IDTYPEDEVICE_REM_SPRMODEL'
      ')'
      'VALUES('
      '    :ID_REM_SPRMODEL,'
      '    :IDBASE_REM_SPRMODEL,'
      '    :GID_REM_SPRMODEL,'
      '    :IDPR_REM_SPRMODEL,'
      '    :IDGRP_REM_SPRMODEL,'
      '    :IDMODEL_REM_SPRMODEL,'
      '    :CODE_REM_SPRMODEL,'
      '    :NAME_REM_SPRMODEL,'
      '    :IDBRAND_REM_SPRMODEL,'
      '    :IDACTCATEGORY_REM_SPRMODEL,'
      '    :IDTYPEDEVICE_REM_SPRMODEL'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprmodel.*,'
      '        rem_smodel.name_rem_smodel,'
      '        sbrand.name_sbrand,'
      '        sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from rem_sprmodel'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_sprmo' +
        'del.idmodel_rem_sprmodel'
      
        'left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbra' +
        'nd.id_sbrand'
      
        'left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=spro' +
        'ducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_sprmodel.idactcategory_r' +
        'em_sprmodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem' +
        '_sprmodel=rem_stypedevice.id_rem_stypedevice'
      'where(  rem_sprmodel.id_rem_sprmodel=:PARAM_ID'
      
        '     ) and (     REM_SPRMODEL.ID_REM_SPRMODEL = :OLD_ID_REM_SPRM' +
        'ODEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprmodel.*,'
      '        rem_smodel.name_rem_smodel,'
      '        sbrand.name_sbrand,'
      '        sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from rem_sprmodel'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_sprmo' +
        'del.idmodel_rem_sprmodel'
      
        'left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbra' +
        'nd.id_sbrand'
      
        'left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=spro' +
        'ducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_sprmodel.idactcategory_r' +
        'em_sprmodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem' +
        '_sprmodel=rem_stypedevice.id_rem_stypedevice'
      'where rem_sprmodel.id_rem_sprmodel=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMODEL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMODEL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMODEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL'
    end
    object ElementIDBASE_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMODEL'
    end
    object ElementGID_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SPRMODEL'
      Size = 10
    end
    object ElementIDPR_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRMODEL'
    end
    object ElementIDGRP_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRMODEL'
    end
    object ElementIDMODEL_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SPRMODEL'
    end
    object ElementCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object ElementNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object ElementIDBRAND_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_SPRMODEL'
    end
    object ElementIDACTCATEGORY_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_REM_SPRMODEL'
    end
    object ElementIDTYPEDEVICE_REM_SPRMODEL: TFIBLargeIntField
      FieldName = 'IDTYPEDEVICE_REM_SPRMODEL'
    end
    object ElementNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object ElementNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object ElementNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
    object ElementNAME_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'NAME_REM_STYPEDEVICE'
      Size = 200
    end
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
end
