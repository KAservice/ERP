object REM_DMSprModel: TREM_DMSprModel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 393
  Width = 335
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    REM_SMODEL.*,'
      '    rem_sprmodel.name_rem_sprmodel,'
      '    sbrand.name_sbrand,'
      '    snom.namenom ,'
      
        '    REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NEISPR' +
        ','
      '            sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from REM_SMODEL'
      
        'left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=' +
        'rem_sprmodel.id_rem_sprmodel'
      
        'left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.i' +
        'd_sbrand'
      'left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom'
      
        'left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.id' +
        'modelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel'
      
        'left outer join sproducer on rem_smodel.idproducer_rem_smodel=sp' +
        'roducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_smodel.idactcategory_rem' +
        '_smodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_s' +
        'model=rem_stypedevice.id_rem_stypedevice'
      'ORDER BY rem_smodel.name_rem_smodel')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL'
    end
    object TableGID_REM_SMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL'
      Size = 10
    end
    object TableIDGRP_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL'
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object TableIDBASE_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL'
    end
    object TableSTRCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'STRCODE_REM_SMODEL'
      Size = 30
    end
    object TableIDBRAND_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_SMODEL'
    end
    object TableIDPRMODEL_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SMODEL'
    end
    object TableDESCR_REM_SMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SMODEL'
      Size = 150
    end
    object TableNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object TableIDNOM_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SMODEL'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object TableIDMODELNEISPR_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDMODELNEISPR_REM_SMODEL'
    end
    object TableNAME_REM_SMODEL_NEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL_NEISPR'
      Size = 200
    end
    object TableIDPRODUCER_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_SMODEL'
    end
    object TableIDACTCATEGORY_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_REM_SMODEL'
    end
    object TableIDTYPEDEVICE_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDTYPEDEVICE_REM_SMODEL'
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
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SMODEL'
      'SET '
      '    GID_REM_SMODEL = :GID_REM_SMODEL,'
      '    IDGRP_REM_SMODEL = :IDGRP_REM_SMODEL,'
      '    NAME_REM_SMODEL = :NAME_REM_SMODEL,'
      '    IDBASE_REM_SMODEL = :IDBASE_REM_SMODEL,'
      '    IDNOM_REM_SMODEL = :IDNOM_REM_SMODEL,'
      '    STRCODE_REM_SMODEL = :STRCODE_REM_SMODEL,'
      '    IDBRAND_REM_SMODEL = :IDBRAND_REM_SMODEL,'
      '    IDPRMODEL_REM_SMODEL = :IDPRMODEL_REM_SMODEL,'
      '    DESCR_REM_SMODEL = :DESCR_REM_SMODEL,'
      '    CODE_REM_SMODEL = :CODE_REM_SMODEL,'
      '    IDMODELNEISPR_REM_SMODEL = :IDMODELNEISPR_REM_SMODEL,'
      '    IDPRODUCER_REM_SMODEL = :IDPRODUCER_REM_SMODEL,'
      '    IDACTCATEGORY_REM_SMODEL = :IDACTCATEGORY_REM_SMODEL,'
      '    IDTYPEDEVICE_REM_SMODEL = :IDTYPEDEVICE_REM_SMODEL'
      'WHERE'
      '    ID_REM_SMODEL = :OLD_ID_REM_SMODEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL'
      'WHERE'
      '        ID_REM_SMODEL = :OLD_ID_REM_SMODEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL('
      '    ID_REM_SMODEL,'
      '    GID_REM_SMODEL,'
      '    IDGRP_REM_SMODEL,'
      '    NAME_REM_SMODEL,'
      '    IDBASE_REM_SMODEL,'
      '    IDNOM_REM_SMODEL,'
      '    STRCODE_REM_SMODEL,'
      '    IDBRAND_REM_SMODEL,'
      '    IDPRMODEL_REM_SMODEL,'
      '    DESCR_REM_SMODEL,'
      '    CODE_REM_SMODEL,'
      '    IDMODELNEISPR_REM_SMODEL,'
      '    IDPRODUCER_REM_SMODEL,'
      '    IDACTCATEGORY_REM_SMODEL,'
      '    IDTYPEDEVICE_REM_SMODEL'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL,'
      '    :GID_REM_SMODEL,'
      '    :IDGRP_REM_SMODEL,'
      '    :NAME_REM_SMODEL,'
      '    :IDBASE_REM_SMODEL,'
      '    :IDNOM_REM_SMODEL,'
      '    :STRCODE_REM_SMODEL,'
      '    :IDBRAND_REM_SMODEL,'
      '    :IDPRMODEL_REM_SMODEL,'
      '    :DESCR_REM_SMODEL,'
      '    :CODE_REM_SMODEL,'
      '    :IDMODELNEISPR_REM_SMODEL,'
      '    :IDPRODUCER_REM_SMODEL,'
      '    :IDACTCATEGORY_REM_SMODEL,'
      '    :IDTYPEDEVICE_REM_SMODEL'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel.*,'
      '        snom.namenom,'
      '        sbrand.name_sbrand,'
      '        rem_sprmodel.name_rem_sprmodel,'
      
        '        REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NE' +
        'ISPR,'
      '        sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from REM_SMODEL'
      'left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom'
      
        'left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.i' +
        'd_sbrand'
      
        'left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=' +
        'rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.id' +
        'modelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel'
      
        'left outer join sproducer on rem_smodel.idproducer_rem_smodel=sp' +
        'roducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_smodel.idactcategory_rem' +
        '_smodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_s' +
        'model=rem_stypedevice.id_rem_stypedevice'
      'where(  rem_smodel.id_rem_smodel=:PARAM_ID'
      '     ) and (     REM_SMODEL.ID_REM_SMODEL = :OLD_ID_REM_SMODEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel.*,'
      '        snom.namenom,'
      '        sbrand.name_sbrand,'
      '        rem_sprmodel.name_rem_sprmodel,'
      
        '        REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NE' +
        'ISPR,'
      '        sproducer.name_sproducer,'
      '        rem_sactcategory.name_rem_sactcategory,'
      '        rem_stypedevice.name_rem_stypedevice'
      'from REM_SMODEL'
      'left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom'
      
        'left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.i' +
        'd_sbrand'
      
        'left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=' +
        'rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.id' +
        'modelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel'
      
        'left outer join sproducer on rem_smodel.idproducer_rem_smodel=sp' +
        'roducer.id_sproducer'
      
        'left outer join rem_sactcategory on rem_smodel.idactcategory_rem' +
        '_smodel=rem_sactcategory.id_rem_sactcategory'
      
        'left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_s' +
        'model=rem_stypedevice.id_rem_stypedevice'
      'where rem_smodel.id_rem_smodel=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_SMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL'
    end
    object ElementGID_REM_SMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL'
      Size = 10
    end
    object ElementIDGRP_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL'
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object ElementIDBASE_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL'
    end
    object ElementIDNOM_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SMODEL'
    end
    object ElementSTRCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'STRCODE_REM_SMODEL'
      Size = 30
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementIDBRAND_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_SMODEL'
    end
    object ElementNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object ElementIDPRMODEL_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SMODEL'
    end
    object ElementDESCR_REM_SMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SMODEL'
      Size = 150
    end
    object ElementCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object ElementNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object ElementIDMODELNEISPR_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDMODELNEISPR_REM_SMODEL'
    end
    object ElementNAME_REM_SMODEL_NEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL_NEISPR'
      Size = 200
    end
    object ElementIDPRODUCER_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_SMODEL'
    end
    object ElementIDACTCATEGORY_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_REM_SMODEL'
    end
    object ElementIDTYPEDEVICE_REM_SMODEL: TFIBLargeIntField
      FieldName = 'IDTYPEDEVICE_REM_SMODEL'
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
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 256
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
    Left = 256
    Top = 64
  end
  object pFIBQuery: TpFIBQuery
    Transaction = IBTr
    Left = 256
    Top = 128
    qoStartTransaction = True
  end
end
