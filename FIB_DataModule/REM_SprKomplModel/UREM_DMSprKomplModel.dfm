object REM_DMSprKomplModel: TREM_DMSprKomplModel
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
      '        REM_SKOMPLMODEL.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from REM_SKOMPLMODEL'
      
        'left outer join rem_stypuslov on REM_SKOMPLMODEL.idtypusla_rem_s' +
        'komplmodel=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on REM_SKOMPLMODEL.idnom_rem_skomplmodel=sn' +
        'om.idnom'
      
        'left outer join sprnom on REM_SKOMPLMODEL.idprnom_rem_skomplmode' +
        'l=sprnom.id_sprnom'
      'where REM_SKOMPLMODEL.IDMODEL_REM_SKOMPLMODEL=:PARAM_IDMODEL'
      'order by REM_SKOMPLMODEL.name_rem_skomplmodel')
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
    object TableID_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SKOMPLMODEL'
    end
    object TableGID_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SKOMPLMODEL'
      Size = 10
    end
    object TableIDMODEL_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SKOMPLMODEL'
    end
    object TableNAME_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SKOMPLMODEL'
      Size = 200
    end
    object TableKOL_REM_SKOMPLMODEL: TFIBBCDField
      FieldName = 'KOL_REM_SKOMPLMODEL'
      Size = 3
      RoundByScale = True
    end
    object TableNEISP_REM_SKOMPLMODEL: TFIBSmallIntField
      FieldName = 'NEISP_REM_SKOMPLMODEL'
    end
    object TableOSN_REM_SKOMPLMODEL: TFIBSmallIntField
      FieldName = 'OSN_REM_SKOMPLMODEL'
    end
    object TableIDBASE_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SKOMPLMODEL'
    end
    object TableIDTYPUSLA_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_SKOMPLMODEL'
    end
    object TablePARTNUM_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SKOMPLMODEL'
    end
    object TableDESCR_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SKOMPLMODEL'
      Size = 150
    end
    object TableIDNOM_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SKOMPLMODEL'
    end
    object TableIDPRNOM_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_SKOMPLMODEL'
    end
    object TableNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object TableART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
    end
    object TableNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SKOMPLMODEL'
      'SET '
      '    GID_REM_SKOMPLMODEL = :GID_REM_SKOMPLMODEL,'
      '    IDMODEL_REM_SKOMPLMODEL = :IDMODEL_REM_SKOMPLMODEL,'
      '    NAME_REM_SKOMPLMODEL = :NAME_REM_SKOMPLMODEL,'
      '    KOL_REM_SKOMPLMODEL = :KOL_REM_SKOMPLMODEL,'
      '    NEISP_REM_SKOMPLMODEL = :NEISP_REM_SKOMPLMODEL,'
      '    OSN_REM_SKOMPLMODEL = :OSN_REM_SKOMPLMODEL,'
      '    IDBASE_REM_SKOMPLMODEL = :IDBASE_REM_SKOMPLMODEL,'
      '    IDTYPUSLA_REM_SKOMPLMODEL = :IDTYPUSLA_REM_SKOMPLMODEL,'
      '    PARTNUM_REM_SKOMPLMODEL = :PARTNUM_REM_SKOMPLMODEL,'
      '    DESCR_REM_SKOMPLMODEL = :DESCR_REM_SKOMPLMODEL,'
      '    IDNOM_REM_SKOMPLMODEL = :IDNOM_REM_SKOMPLMODEL,'
      '    IDPRNOM_REM_SKOMPLMODEL = :IDPRNOM_REM_SKOMPLMODEL'
      'WHERE'
      '    ID_REM_SKOMPLMODEL = :OLD_ID_REM_SKOMPLMODEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SKOMPLMODEL'
      'WHERE'
      '        ID_REM_SKOMPLMODEL = :OLD_ID_REM_SKOMPLMODEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SKOMPLMODEL('
      '    ID_REM_SKOMPLMODEL,'
      '    GID_REM_SKOMPLMODEL,'
      '    IDMODEL_REM_SKOMPLMODEL,'
      '    NAME_REM_SKOMPLMODEL,'
      '    KOL_REM_SKOMPLMODEL,'
      '    NEISP_REM_SKOMPLMODEL,'
      '    OSN_REM_SKOMPLMODEL,'
      '    IDBASE_REM_SKOMPLMODEL,'
      '    IDTYPUSLA_REM_SKOMPLMODEL,'
      '    PARTNUM_REM_SKOMPLMODEL,'
      '    DESCR_REM_SKOMPLMODEL,'
      '    IDNOM_REM_SKOMPLMODEL,'
      '    IDPRNOM_REM_SKOMPLMODEL'
      ')'
      'VALUES('
      '    :ID_REM_SKOMPLMODEL,'
      '    :GID_REM_SKOMPLMODEL,'
      '    :IDMODEL_REM_SKOMPLMODEL,'
      '    :NAME_REM_SKOMPLMODEL,'
      '    :KOL_REM_SKOMPLMODEL,'
      '    :NEISP_REM_SKOMPLMODEL,'
      '    :OSN_REM_SKOMPLMODEL,'
      '    :IDBASE_REM_SKOMPLMODEL,'
      '    :IDTYPUSLA_REM_SKOMPLMODEL,'
      '    :PARTNUM_REM_SKOMPLMODEL,'
      '    :DESCR_REM_SKOMPLMODEL,'
      '    :IDNOM_REM_SKOMPLMODEL,'
      '    :IDPRNOM_REM_SKOMPLMODEL'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        REM_SKOMPLMODEL.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from REM_SKOMPLMODEL'
      
        'left outer join rem_stypuslov on REM_SKOMPLMODEL.idtypusla_rem_s' +
        'komplmodel=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on REM_SKOMPLMODEL.idnom_rem_skomplmodel=sn' +
        'om.idnom'
      
        'left outer join sprnom on REM_SKOMPLMODEL.idprnom_rem_skomplmode' +
        'l=sprnom.id_sprnom'
      'where(  REM_SKOMPLMODEL.ID_REM_SKOMPLMODEL=:PARAM_ID'
      
        '     ) and (     REM_SKOMPLMODEL.ID_REM_SKOMPLMODEL = :OLD_ID_RE' +
        'M_SKOMPLMODEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        REM_SKOMPLMODEL.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from REM_SKOMPLMODEL'
      
        'left outer join rem_stypuslov on REM_SKOMPLMODEL.idtypusla_rem_s' +
        'komplmodel=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on REM_SKOMPLMODEL.idnom_rem_skomplmodel=sn' +
        'om.idnom'
      
        'left outer join sprnom on REM_SKOMPLMODEL.idprnom_rem_skomplmode' +
        'l=sprnom.id_sprnom'
      'where REM_SKOMPLMODEL.ID_REM_SKOMPLMODEL=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SKOMPLMODEL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SKOMPLMODEL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SKOMPLMODEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SKOMPLMODEL'
    end
    object ElementGID_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SKOMPLMODEL'
      Size = 10
    end
    object ElementIDMODEL_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SKOMPLMODEL'
    end
    object ElementNAME_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SKOMPLMODEL'
      Size = 200
    end
    object ElementKOL_REM_SKOMPLMODEL: TFIBBCDField
      FieldName = 'KOL_REM_SKOMPLMODEL'
      Size = 3
      RoundByScale = True
    end
    object ElementNEISP_REM_SKOMPLMODEL: TFIBSmallIntField
      FieldName = 'NEISP_REM_SKOMPLMODEL'
    end
    object ElementOSN_REM_SKOMPLMODEL: TFIBSmallIntField
      FieldName = 'OSN_REM_SKOMPLMODEL'
    end
    object ElementIDBASE_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SKOMPLMODEL'
    end
    object ElementIDTYPUSLA_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_SKOMPLMODEL'
    end
    object ElementPARTNUM_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SKOMPLMODEL'
    end
    object ElementDESCR_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'DESCR_REM_SKOMPLMODEL'
      Size = 150
    end
    object ElementIDNOM_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SKOMPLMODEL'
    end
    object ElementIDPRNOM_REM_SKOMPLMODEL: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_SKOMPLMODEL'
    end
    object ElementNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object ElementART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
    end
    object ElementNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
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
