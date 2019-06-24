object REM_DMSprProducerSection: TREM_DMSprProducerSection
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
      'select  rem_sprsection.*'
      'from rem_sprsection'
      'where'
      
        '    rem_sprsection.idpr_rem_sprsection=:PARAM_ID_GROUP_ELEMENT a' +
        'nd rem_sprsection.idgrp_rem_sprsection=:PARAM_IDGRP'
      'order by rem_sprsection.name_rem_sprsection')
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
    object TableID_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'ID_REM_SPRSECTION'
    end
    object TableIDBASE_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRSECTION'
    end
    object TableIDGRP_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRSECTION'
    end
    object TableIDPR_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRSECTION'
    end
    object TableCODE_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRSECTION'
      Size = 10
    end
    object TableNAME_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRSECTION'
      Size = 200
    end
    object TableNAME_ENG_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRSECTION'
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
      'UPDATE REM_SPRSECTION'
      'SET '
      '    IDBASE_REM_SPRSECTION = :IDBASE_REM_SPRSECTION,'
      '    IDGRP_REM_SPRSECTION = :IDGRP_REM_SPRSECTION,'
      '    IDPR_REM_SPRSECTION = :IDPR_REM_SPRSECTION,'
      '    CODE_REM_SPRSECTION = :CODE_REM_SPRSECTION,'
      '    NAME_REM_SPRSECTION = :NAME_REM_SPRSECTION,'
      '    NAME_ENG_REM_SPRSECTION = :NAME_ENG_REM_SPRSECTION'
      'WHERE'
      '    ID_REM_SPRSECTION = :OLD_ID_REM_SPRSECTION'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRSECTION'
      'WHERE'
      '        ID_REM_SPRSECTION = :OLD_ID_REM_SPRSECTION'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRSECTION('
      '    ID_REM_SPRSECTION,'
      '    IDBASE_REM_SPRSECTION,'
      '    IDGRP_REM_SPRSECTION,'
      '    IDPR_REM_SPRSECTION,'
      '    CODE_REM_SPRSECTION,'
      '    NAME_REM_SPRSECTION,'
      '    NAME_ENG_REM_SPRSECTION'
      ')'
      'VALUES('
      '    :ID_REM_SPRSECTION,'
      '    :IDBASE_REM_SPRSECTION,'
      '    :IDGRP_REM_SPRSECTION,'
      '    :IDPR_REM_SPRSECTION,'
      '    :CODE_REM_SPRSECTION,'
      '    :NAME_REM_SPRSECTION,'
      '    :NAME_ENG_REM_SPRSECTION'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprsection.*'
      'from rem_sprsection'
      'where(  rem_sprsection.id_rem_sprsection=:PARAM_ID'
      
        '     ) and (     REM_SPRSECTION.ID_REM_SPRSECTION = :OLD_ID_REM_' +
        'SPRSECTION'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprsection.*'
      'from rem_sprsection'
      'where rem_sprsection.id_rem_sprsection=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRSECTION'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRSECTION'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRSECTION_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'ID_REM_SPRSECTION'
    end
    object ElementIDBASE_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRSECTION'
    end
    object ElementIDGRP_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRSECTION'
    end
    object ElementIDPR_REM_SPRSECTION: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRSECTION'
    end
    object ElementCODE_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRSECTION'
      Size = 10
    end
    object ElementNAME_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRSECTION'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRSECTION'
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
