object REM_DMSprProducerNeispr: TREM_DMSprProducerNeispr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 276
  Width = 541
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select  rem_sprneispr.*,'
      '        rem_sneispr.name_rem_sneispr'
      'from rem_sprneispr'
      
        'left outer join rem_sneispr on rem_sprneispr.idneispr_rem_sprnei' +
        'spr=rem_sneispr.id_rem_sneispr'
      'where '
      
        '    rem_sprneispr.idpr_rem_sprneispr=:PARAM_ID_GROUP_ELEMENT and' +
        ' rem_sprneispr.idgrp_rem_sprneispr=:PARAM_IDGRP'
      'order by rem_sprneispr.name_rem_sprneispr')
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
    object TableID_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SPRNEISPR'
    end
    object TableCODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object TableNAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      Size = 200
    end
    object TableNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object TableIDPR_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRNEISPR'
    end
    object TableIDGRP_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRNEISPR'
    end
    object TableIDNEISPR_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_SPRNEISPR'
    end
    object TableNAME_ENG_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR'
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
      'UPDATE REM_SPRNEISPR'
      'SET '
      '    IDBASE_REM_SPRNEISPR = :IDBASE_REM_SPRNEISPR,'
      '    GID_REM_SPRNEISPR = :GID_REM_SPRNEISPR,'
      '    IDPR_REM_SPRNEISPR = :IDPR_REM_SPRNEISPR,'
      '    IDGRP_REM_SPRNEISPR = :IDGRP_REM_SPRNEISPR,'
      '    IDNEISPR_REM_SPRNEISPR = :IDNEISPR_REM_SPRNEISPR,'
      '    CODE_REM_SPRNEISPR = :CODE_REM_SPRNEISPR,'
      '    NAME_REM_SPRNEISPR = :NAME_REM_SPRNEISPR,'
      '    NAME_ENG_REM_SPRNEISPR = :NAME_ENG_REM_SPRNEISPR'
      'WHERE'
      '    ID_REM_SPRNEISPR = :OLD_ID_REM_SPRNEISPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRNEISPR'
      'WHERE'
      '        ID_REM_SPRNEISPR = :OLD_ID_REM_SPRNEISPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRNEISPR('
      '    ID_REM_SPRNEISPR,'
      '    IDBASE_REM_SPRNEISPR,'
      '    GID_REM_SPRNEISPR,'
      '    IDPR_REM_SPRNEISPR,'
      '    IDGRP_REM_SPRNEISPR,'
      '    IDNEISPR_REM_SPRNEISPR,'
      '    CODE_REM_SPRNEISPR,'
      '    NAME_REM_SPRNEISPR,'
      '    NAME_ENG_REM_SPRNEISPR'
      ')'
      'VALUES('
      '    :ID_REM_SPRNEISPR,'
      '    :IDBASE_REM_SPRNEISPR,'
      '    :GID_REM_SPRNEISPR,'
      '    :IDPR_REM_SPRNEISPR,'
      '    :IDGRP_REM_SPRNEISPR,'
      '    :IDNEISPR_REM_SPRNEISPR,'
      '    :CODE_REM_SPRNEISPR,'
      '    :NAME_REM_SPRNEISPR,'
      '    :NAME_ENG_REM_SPRNEISPR'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprneispr.*,'
      '        rem_sneispr.name_rem_sneispr'
      'from rem_sprneispr'
      
        'left outer join rem_sneispr on rem_sneispr.id_rem_sneispr=rem_sp' +
        'rneispr.idneispr_rem_sprneispr'
      'where(  rem_sprneispr.id_rem_sprneispr=:PARAM_ID'
      
        '     ) and (     REM_SPRNEISPR.ID_REM_SPRNEISPR = :OLD_ID_REM_SP' +
        'RNEISPR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprneispr.*,'
      '        rem_sneispr.name_rem_sneispr'
      'from rem_sprneispr'
      
        'left outer join rem_sneispr on rem_sneispr.id_rem_sneispr=rem_sp' +
        'rneispr.idneispr_rem_sprneispr'
      'where rem_sprneispr.id_rem_sprneispr=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRNEISPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRNEISPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRNEISPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SPRNEISPR'
    end
    object ElementIDBASE_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRNEISPR'
    end
    object ElementGID_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_SPRNEISPR'
      Size = 10
    end
    object ElementIDPR_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRNEISPR'
    end
    object ElementIDGRP_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRNEISPR'
    end
    object ElementIDNEISPR_REM_SPRNEISPR: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_SPRNEISPR'
    end
    object ElementCODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object ElementNAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      Size = 200
    end
    object ElementNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR'
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
