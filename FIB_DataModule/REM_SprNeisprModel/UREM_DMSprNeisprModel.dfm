object REM_DMSprNeisprModel: TREM_DMSprNeisprModel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 301
  Width = 491
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        rem_sneispmodel.*,'
      '        rem_sneispr.name_rem_sneispr ,'
      '        rem_smodel.name_rem_smodel'
      'from rem_sneispmodel'
      
        'left outer join rem_sneispr on rem_sneispmodel.idneispr_rem_snei' +
        'spmodel=rem_sneispr.id_rem_sneispr'
      
        'left outer join rem_smodel on  rem_sneispmodel.idmodelneispr_rem' +
        '_sneispmodel=rem_smodel.id_rem_smodel'
      'where rem_sneispmodel.idmodel_rem_sneispmodel=:PARAM_IDMODEL'
      'order by rem_sneispmodel.name_rem_sneispmodel')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SNEISPMODEL'
    end
    object TableGID_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SNEISPMODEL'
      Size = 10
    end
    object TableIDBASE_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SNEISPMODEL'
    end
    object TableDESCR_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SNEISPMODEL'
      Size = 150
    end
    object TableIDMODEL_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SNEISPMODEL'
    end
    object TableIDNEISPR_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_SNEISPMODEL'
    end
    object TableNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object TableNAME_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPMODEL'
      Size = 200
    end
    object TableIDMODELNEISPR_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDMODELNEISPR_REM_SNEISPMODEL'
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SNEISPMODEL'
      'SET '
      '    GID_REM_SNEISPMODEL = :GID_REM_SNEISPMODEL,'
      '    IDBASE_REM_SNEISPMODEL = :IDBASE_REM_SNEISPMODEL,'
      '    NAME_REM_SNEISPMODEL = :NAME_REM_SNEISPMODEL,'
      '    DESCR_REM_SNEISPMODEL = :DESCR_REM_SNEISPMODEL,'
      '    IDMODEL_REM_SNEISPMODEL = :IDMODEL_REM_SNEISPMODEL,'
      '    IDNEISPR_REM_SNEISPMODEL = :IDNEISPR_REM_SNEISPMODEL,'
      
        '    IDMODELNEISPR_REM_SNEISPMODEL = :IDMODELNEISPR_REM_SNEISPMOD' +
        'EL'
      'WHERE'
      '    ID_REM_SNEISPMODEL = :OLD_ID_REM_SNEISPMODEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SNEISPMODEL'
      'WHERE'
      '        ID_REM_SNEISPMODEL = :OLD_ID_REM_SNEISPMODEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SNEISPMODEL('
      '    ID_REM_SNEISPMODEL,'
      '    GID_REM_SNEISPMODEL,'
      '    IDBASE_REM_SNEISPMODEL,'
      '    NAME_REM_SNEISPMODEL,'
      '    DESCR_REM_SNEISPMODEL,'
      '    IDMODEL_REM_SNEISPMODEL,'
      '    IDNEISPR_REM_SNEISPMODEL,'
      '    IDMODELNEISPR_REM_SNEISPMODEL'
      ')'
      'VALUES('
      '    :ID_REM_SNEISPMODEL,'
      '    :GID_REM_SNEISPMODEL,'
      '    :IDBASE_REM_SNEISPMODEL,'
      '    :NAME_REM_SNEISPMODEL,'
      '    :DESCR_REM_SNEISPMODEL,'
      '    :IDMODEL_REM_SNEISPMODEL,'
      '    :IDNEISPR_REM_SNEISPMODEL,'
      '    :IDMODELNEISPR_REM_SNEISPMODEL'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        rem_sneispmodel.*,'
      '        rem_sneispr.name_rem_sneispr,'
      '        rem_smodel.name_rem_smodel'
      'from rem_sneispmodel'
      
        'left outer join rem_sneispr on rem_sneispmodel.idneispr_rem_snei' +
        'spmodel=rem_sneispr.id_rem_sneispr'
      
        'left outer join rem_smodel on  rem_sneispmodel.idmodelneispr_rem' +
        '_sneispmodel=rem_smodel.id_rem_smodel'
      'where(  rem_sneispmodel.id_rem_sneispmodel=:PARAM_ID'
      
        '     ) and (     REM_SNEISPMODEL.ID_REM_SNEISPMODEL = :OLD_ID_RE' +
        'M_SNEISPMODEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        rem_sneispmodel.*,'
      '        rem_sneispr.name_rem_sneispr,'
      '        rem_smodel.name_rem_smodel'
      'from rem_sneispmodel'
      
        'left outer join rem_sneispr on rem_sneispmodel.idneispr_rem_snei' +
        'spmodel=rem_sneispr.id_rem_sneispr'
      
        'left outer join rem_smodel on  rem_sneispmodel.idmodelneispr_rem' +
        '_sneispmodel=rem_smodel.id_rem_smodel'
      'where rem_sneispmodel.id_rem_sneispmodel=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SNEISPMODEL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SNEISPMODEL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SNEISPMODEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SNEISPMODEL'
    end
    object ElementGID_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SNEISPMODEL'
      Size = 10
    end
    object ElementIDBASE_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SNEISPMODEL'
    end
    object ElementDESCR_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SNEISPMODEL'
      Size = 150
    end
    object ElementIDMODEL_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SNEISPMODEL'
    end
    object ElementIDNEISPR_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_SNEISPMODEL'
    end
    object ElementNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object ElementNAME_REM_SNEISPMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPMODEL'
      Size = 200
    end
    object ElementIDMODELNEISPR_REM_SNEISPMODEL: TFIBLargeIntField
      FieldName = 'IDMODELNEISPR_REM_SNEISPMODEL'
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
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
    Left = 264
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
    Left = 264
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 80
    qoStartTransaction = True
  end
end
