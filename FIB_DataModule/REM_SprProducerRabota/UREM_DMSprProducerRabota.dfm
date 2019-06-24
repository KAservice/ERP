object REM_DMSprProducerRabota: TREM_DMSprProducerRabota
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 276
  Width = 398
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select  rem_sprrabota.*,'
      '        snom.namenom'
      'from rem_sprrabota'
      
        'left outer join snom on rem_sprrabota.idnom_rem_sprrabota=snom.i' +
        'dnom'
      'where '
      
        '    rem_sprrabota.idpr_rem_sprrabota=:PARAM_ID_GROUP_ELEMENT and' +
        ' rem_sprrabota.idgrp_rem_sprrabota=:PARAM_IDGRP'
      'order by rem_sprrabota.name_rem_sprrabota')
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
    object TableID_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'ID_REM_SPRRABOTA'
    end
    object TableIDBASE_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRRABOTA'
    end
    object TableGID_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'GID_REM_SPRRABOTA'
      Size = 10
    end
    object TableIDPR_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRRABOTA'
    end
    object TableIDGRP_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRRABOTA'
    end
    object TableNAME_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_REM_SPRRABOTA'
      Size = 200
    end
    object TableNAME_ENG_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRRABOTA'
      Size = 200
    end
    object TableCODE_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'CODE_REM_SPRRABOTA'
    end
    object TableLEVEL_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'LEVEL_REM_SPRRABOTA'
    end
    object TableTYPECLIENT_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'TYPECLIENT_REM_SPRRABOTA'
    end
    object TableTYPEPRODUCT_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'TYPEPRODUCT_REM_SPRRABOTA'
    end
    object TableLEVEL_STR_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'LEVEL_STR_REM_SPRRABOTA'
    end
    object TableIDNOM_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SPRRABOTA'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
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
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SPRRABOTA'
      'SET '
      '    IDBASE_REM_SPRRABOTA = :IDBASE_REM_SPRRABOTA,'
      '    GID_REM_SPRRABOTA = :GID_REM_SPRRABOTA,'
      '    IDPR_REM_SPRRABOTA = :IDPR_REM_SPRRABOTA,'
      '    IDGRP_REM_SPRRABOTA = :IDGRP_REM_SPRRABOTA,'
      '    NAME_REM_SPRRABOTA = :NAME_REM_SPRRABOTA,'
      '    NAME_ENG_REM_SPRRABOTA = :NAME_ENG_REM_SPRRABOTA,'
      '    CODE_REM_SPRRABOTA = :CODE_REM_SPRRABOTA,'
      '    LEVEL_REM_SPRRABOTA = :LEVEL_REM_SPRRABOTA,'
      '    TYPECLIENT_REM_SPRRABOTA = :TYPECLIENT_REM_SPRRABOTA,'
      '    TYPEPRODUCT_REM_SPRRABOTA = :TYPEPRODUCT_REM_SPRRABOTA,'
      '    LEVEL_STR_REM_SPRRABOTA = :LEVEL_STR_REM_SPRRABOTA,'
      '    IDNOM_REM_SPRRABOTA = :IDNOM_REM_SPRRABOTA'
      'WHERE'
      '    ID_REM_SPRRABOTA = :OLD_ID_REM_SPRRABOTA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRRABOTA'
      'WHERE'
      '        ID_REM_SPRRABOTA = :OLD_ID_REM_SPRRABOTA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRRABOTA('
      '    ID_REM_SPRRABOTA,'
      '    IDBASE_REM_SPRRABOTA,'
      '    GID_REM_SPRRABOTA,'
      '    IDPR_REM_SPRRABOTA,'
      '    IDGRP_REM_SPRRABOTA,'
      '    NAME_REM_SPRRABOTA,'
      '    NAME_ENG_REM_SPRRABOTA,'
      '    CODE_REM_SPRRABOTA,'
      '    LEVEL_REM_SPRRABOTA,'
      '    TYPECLIENT_REM_SPRRABOTA,'
      '    TYPEPRODUCT_REM_SPRRABOTA,'
      '    LEVEL_STR_REM_SPRRABOTA,'
      '    IDNOM_REM_SPRRABOTA'
      ')'
      'VALUES('
      '    :ID_REM_SPRRABOTA,'
      '    :IDBASE_REM_SPRRABOTA,'
      '    :GID_REM_SPRRABOTA,'
      '    :IDPR_REM_SPRRABOTA,'
      '    :IDGRP_REM_SPRRABOTA,'
      '    :NAME_REM_SPRRABOTA,'
      '    :NAME_ENG_REM_SPRRABOTA,'
      '    :CODE_REM_SPRRABOTA,'
      '    :LEVEL_REM_SPRRABOTA,'
      '    :TYPECLIENT_REM_SPRRABOTA,'
      '    :TYPEPRODUCT_REM_SPRRABOTA,'
      '    :LEVEL_STR_REM_SPRRABOTA,'
      '    :IDNOM_REM_SPRRABOTA'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprrabota.*,'
      '        snom.namenom'
      'from rem_sprrabota'
      
        'left outer join snom on rem_sprrabota.idnom_rem_sprrabota=snom.i' +
        'dnom'
      'where(  rem_sprrabota.id_rem_sprrabota=:PARAM_ID'
      
        '     ) and (     REM_SPRRABOTA.ID_REM_SPRRABOTA = :OLD_ID_REM_SP' +
        'RRABOTA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprrabota.*,'
      '        snom.namenom'
      'from rem_sprrabota'
      
        'left outer join snom on rem_sprrabota.idnom_rem_sprrabota=snom.i' +
        'dnom'
      'where rem_sprrabota.id_rem_sprrabota=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRRABOTA'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRRABOTA'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRRABOTA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'ID_REM_SPRRABOTA'
    end
    object ElementIDBASE_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRRABOTA'
    end
    object ElementGID_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'GID_REM_SPRRABOTA'
      Size = 10
    end
    object ElementIDPR_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRRABOTA'
    end
    object ElementIDGRP_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRRABOTA'
    end
    object ElementNAME_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_REM_SPRRABOTA'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRRABOTA'
      Size = 200
    end
    object ElementCODE_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'CODE_REM_SPRRABOTA'
    end
    object ElementLEVEL_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'LEVEL_REM_SPRRABOTA'
    end
    object ElementTYPECLIENT_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'TYPECLIENT_REM_SPRRABOTA'
    end
    object ElementTYPEPRODUCT_REM_SPRRABOTA: TFIBIntegerField
      FieldName = 'TYPEPRODUCT_REM_SPRRABOTA'
    end
    object ElementLEVEL_STR_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'LEVEL_STR_REM_SPRRABOTA'
    end
    object ElementIDNOM_REM_SPRRABOTA: TFIBLargeIntField
      FieldName = 'IDNOM_REM_SPRRABOTA'
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 136
    Top = 152
    qoStartTransaction = True
  end
end
