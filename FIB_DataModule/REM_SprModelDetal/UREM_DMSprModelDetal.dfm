object REM_DMSprModelDetal: TREM_DMSprModelDetal
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
      '        rem_smodel_detal.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from rem_smodel_detal'
      
        'left outer join rem_stypuslov on rem_smodel_detal.idtypusla_rem_' +
        'smodel_detal=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on rem_smodel_detal.idnom_rem_smodel_detal=' +
        'snom.idnom'
      
        'left outer join sprnom on rem_smodel_detal.idprnom_rem_smodel_de' +
        'tal=sprnom.id_sprnom'
      'where rem_smodel_detal.idmodel_rem_smodel_detal=:PARAM_IDMODEL'
      'order by rem_smodel_detal.name_rem_smodel_detal')
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
    object TableID_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_DETAL'
    end
    object TableGID_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_DETAL'
      Size = 10
    end
    object TableIDBASE_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_DETAL'
    end
    object TableIDMODEL_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_DETAL'
    end
    object TableIDTYPUSLA_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_SMODEL_DETAL'
    end
    object TableIDNOM_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SMODEL_DETAL'
    end
    object TableIDPRNOM_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_SMODEL_DETAL'
    end
    object TableNAME_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL_DETAL'
      Size = 200
    end
    object TablePARTNUM_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SMODEL_DETAL'
    end
    object TableDESCR_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'DESCR_REM_SMODEL_DETAL'
      Size = 150
    end
    object TableKOL_REM_SMODEL_DETAL: TFIBBCDField
      FieldName = 'KOL_REM_SMODEL_DETAL'
      Size = 3
      RoundByScale = True
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
      'UPDATE REM_SMODEL_DETAL'
      'SET '
      '    GID_REM_SMODEL_DETAL = :GID_REM_SMODEL_DETAL,'
      '    IDBASE_REM_SMODEL_DETAL = :IDBASE_REM_SMODEL_DETAL,'
      '    IDMODEL_REM_SMODEL_DETAL = :IDMODEL_REM_SMODEL_DETAL,'
      '    IDTYPUSLA_REM_SMODEL_DETAL = :IDTYPUSLA_REM_SMODEL_DETAL,'
      '    IDNOM_REM_SMODEL_DETAL = :IDNOM_REM_SMODEL_DETAL,'
      '    IDPRNOM_REM_SMODEL_DETAL = :IDPRNOM_REM_SMODEL_DETAL,'
      '    NAME_REM_SMODEL_DETAL = :NAME_REM_SMODEL_DETAL,'
      '    PARTNUM_REM_SMODEL_DETAL = :PARTNUM_REM_SMODEL_DETAL,'
      '    DESCR_REM_SMODEL_DETAL = :DESCR_REM_SMODEL_DETAL,'
      '    KOL_REM_SMODEL_DETAL = :KOL_REM_SMODEL_DETAL'
      'WHERE'
      '    ID_REM_SMODEL_DETAL = :OLD_ID_REM_SMODEL_DETAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL_DETAL'
      'WHERE'
      '        ID_REM_SMODEL_DETAL = :OLD_ID_REM_SMODEL_DETAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL_DETAL('
      '    ID_REM_SMODEL_DETAL,'
      '    GID_REM_SMODEL_DETAL,'
      '    IDBASE_REM_SMODEL_DETAL,'
      '    IDMODEL_REM_SMODEL_DETAL,'
      '    IDTYPUSLA_REM_SMODEL_DETAL,'
      '    IDNOM_REM_SMODEL_DETAL,'
      '    IDPRNOM_REM_SMODEL_DETAL,'
      '    NAME_REM_SMODEL_DETAL,'
      '    PARTNUM_REM_SMODEL_DETAL,'
      '    DESCR_REM_SMODEL_DETAL,'
      '    KOL_REM_SMODEL_DETAL'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL_DETAL,'
      '    :GID_REM_SMODEL_DETAL,'
      '    :IDBASE_REM_SMODEL_DETAL,'
      '    :IDMODEL_REM_SMODEL_DETAL,'
      '    :IDTYPUSLA_REM_SMODEL_DETAL,'
      '    :IDNOM_REM_SMODEL_DETAL,'
      '    :IDPRNOM_REM_SMODEL_DETAL,'
      '    :NAME_REM_SMODEL_DETAL,'
      '    :PARTNUM_REM_SMODEL_DETAL,'
      '    :DESCR_REM_SMODEL_DETAL,'
      '    :KOL_REM_SMODEL_DETAL'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        rem_smodel_detal.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from rem_smodel_detal'
      
        'left outer join rem_stypuslov on rem_smodel_detal.idtypusla_rem_' +
        'smodel_detal=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on rem_smodel_detal.idnom_rem_smodel_detal=' +
        'snom.idnom'
      
        'left outer join sprnom on rem_smodel_detal.idprnom_rem_smodel_de' +
        'tal=sprnom.id_sprnom'
      'where(  rem_smodel_detal.id_rem_smodel_detal=:PARAM_ID'
      
        '     ) and (     REM_SMODEL_DETAL.ID_REM_SMODEL_DETAL = :OLD_ID_' +
        'REM_SMODEL_DETAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        rem_smodel_detal.*,'
      '        rem_stypuslov.name_rem_stypuslov,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      '        sprnom.name_sprnom'
      'from rem_smodel_detal'
      
        'left outer join rem_stypuslov on rem_smodel_detal.idtypusla_rem_' +
        'smodel_detal=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join snom on rem_smodel_detal.idnom_rem_smodel_detal=' +
        'snom.idnom'
      
        'left outer join sprnom on rem_smodel_detal.idprnom_rem_smodel_de' +
        'tal=sprnom.id_sprnom'
      'where rem_smodel_detal.id_rem_smodel_detal=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL_DETAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL_DETAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL_DETAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL_DETAL'
    end
    object ElementGID_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL_DETAL'
      Size = 10
    end
    object ElementIDBASE_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL_DETAL'
    end
    object ElementIDMODEL_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL_DETAL'
    end
    object ElementIDTYPUSLA_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_SMODEL_DETAL'
    end
    object ElementIDNOM_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SMODEL_DETAL'
    end
    object ElementIDPRNOM_REM_SMODEL_DETAL: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_SMODEL_DETAL'
    end
    object ElementNAME_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL_DETAL'
      Size = 200
    end
    object ElementPARTNUM_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SMODEL_DETAL'
    end
    object ElementDESCR_REM_SMODEL_DETAL: TFIBWideStringField
      FieldName = 'DESCR_REM_SMODEL_DETAL'
      Size = 150
    end
    object ElementKOL_REM_SMODEL_DETAL: TFIBBCDField
      FieldName = 'KOL_REM_SMODEL_DETAL'
      Size = 3
      RoundByScale = True
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
