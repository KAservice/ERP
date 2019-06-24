object REM_DMSprProducerCondition: TREM_DMSprProducerCondition
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
      'select  rem_sprcondition.*'
      'from rem_sprcondition'
      'where'
      
        '    rem_sprcondition.idpr_rem_sprcondition=:PARAM_ID_GROUP_ELEME' +
        'NT and rem_sprcondition.idgrp_rem_sprcondition=:PARAM_IDGRP'
      'order by rem_sprcondition.name_rem_sprcondition')
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
    object TableID_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'ID_REM_SPRCONDITION'
    end
    object TableIDBASE_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRCONDITION'
    end
    object TableGID_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'GID_REM_SPRCONDITION'
      Size = 10
    end
    object TableIDPR_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRCONDITION'
    end
    object TableIDGRP_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRCONDITION'
    end
    object TableCODE_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCONDITION'
      Size = 10
    end
    object TableNAME_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCONDITION'
      Size = 200
    end
    object TableNAME_ENG_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCONDITION'
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
      'UPDATE REM_SPRCONDITION'
      'SET '
      '    IDBASE_REM_SPRCONDITION = :IDBASE_REM_SPRCONDITION,'
      '    GID_REM_SPRCONDITION = :GID_REM_SPRCONDITION,'
      '    IDPR_REM_SPRCONDITION = :IDPR_REM_SPRCONDITION,'
      '    IDGRP_REM_SPRCONDITION = :IDGRP_REM_SPRCONDITION,'
      '    CODE_REM_SPRCONDITION = :CODE_REM_SPRCONDITION,'
      '    NAME_REM_SPRCONDITION = :NAME_REM_SPRCONDITION,'
      '    NAME_ENG_REM_SPRCONDITION = :NAME_ENG_REM_SPRCONDITION'
      'WHERE'
      '    ID_REM_SPRCONDITION = :OLD_ID_REM_SPRCONDITION'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRCONDITION'
      'WHERE'
      '        ID_REM_SPRCONDITION = :OLD_ID_REM_SPRCONDITION'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRCONDITION('
      '    ID_REM_SPRCONDITION,'
      '    IDBASE_REM_SPRCONDITION,'
      '    GID_REM_SPRCONDITION,'
      '    IDPR_REM_SPRCONDITION,'
      '    IDGRP_REM_SPRCONDITION,'
      '    CODE_REM_SPRCONDITION,'
      '    NAME_REM_SPRCONDITION,'
      '    NAME_ENG_REM_SPRCONDITION'
      ')'
      'VALUES('
      '    :ID_REM_SPRCONDITION,'
      '    :IDBASE_REM_SPRCONDITION,'
      '    :GID_REM_SPRCONDITION,'
      '    :IDPR_REM_SPRCONDITION,'
      '    :IDGRP_REM_SPRCONDITION,'
      '    :CODE_REM_SPRCONDITION,'
      '    :NAME_REM_SPRCONDITION,'
      '    :NAME_ENG_REM_SPRCONDITION'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprcondition.*'
      'from rem_sprcondition'
      'where(  rem_sprcondition.id_rem_sprcondition=:PARAM_ID'
      
        '     ) and (     REM_SPRCONDITION.ID_REM_SPRCONDITION = :OLD_ID_' +
        'REM_SPRCONDITION'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprcondition.*'
      'from rem_sprcondition'
      'where rem_sprcondition.id_rem_sprcondition=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRCONDITION'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRCONDITION'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRCONDITION_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'ID_REM_SPRCONDITION'
    end
    object ElementIDBASE_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRCONDITION'
    end
    object ElementGID_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'GID_REM_SPRCONDITION'
      Size = 10
    end
    object ElementIDPR_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRCONDITION'
    end
    object ElementIDGRP_REM_SPRCONDITION: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRCONDITION'
    end
    object ElementCODE_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCONDITION'
      Size = 10
    end
    object ElementNAME_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCONDITION'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCONDITION'
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
