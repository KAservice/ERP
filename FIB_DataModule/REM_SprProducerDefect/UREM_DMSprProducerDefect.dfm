object REM_DMSprProducerDefect: TREM_DMSprProducerDefect
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
    UpdateSQL.Strings = (
      'UPDATE REM_SPRDEFECT'
      'SET '
      '    CODE_REM_SPRDEFECT = :CODE_REM_SPRDEFECT,'
      '    NAME_REM_SPRDEFECT = :NAME_REM_SPRDEFECT,'
      '    IDPR_REM_SPRDEFECT = :IDPR_REM_SPRDEFECT,'
      '    IDGRP_REM_SPRDEFECT = :IDGRP_REM_SPRDEFECT'
      'WHERE'
      '    ID_REM_SPRDEFECT = :OLD_ID_REM_SPRDEFECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRDEFECT'
      'WHERE'
      '        ID_REM_SPRDEFECT = :OLD_ID_REM_SPRDEFECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRDEFECT('
      '    ID_REM_SPRDEFECT,'
      '    CODE_REM_SPRDEFECT,'
      '    NAME_REM_SPRDEFECT,'
      '    IDPR_REM_SPRDEFECT,'
      '    IDGRP_REM_SPRDEFECT'
      ')'
      'VALUES('
      '    :ID_REM_SPRDEFECT,'
      '    :CODE_REM_SPRDEFECT,'
      '    :NAME_REM_SPRDEFECT,'
      '    :IDPR_REM_SPRDEFECT,'
      '    :IDGRP_REM_SPRDEFECT'
      ')')
    RefreshSQL.Strings = (
      'select  rem_sprdefect.id_rem_sprdefect,'
      '        rem_sprdefect.code_rem_sprdefect,'
      '        rem_sprdefect.name_rem_sprdefect,'
      '        rem_sprdefect.idpr_rem_sprdefect,'
      '        rem_sprdefect.idgrp_rem_sprdefect'
      'from rem_sprdefect'
      'where(  '
      
        '    rem_sprdefect.idpr_rem_sprdefect=:PARAM_ID_GROUP_ELEMENT and' +
        ' rem_sprdefect.idgrp_rem_sprdefect=:PARAM_IDGRP'
      
        '     ) and (     REM_SPRDEFECT.ID_REM_SPRDEFECT = :OLD_ID_REM_SP' +
        'RDEFECT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  rem_sprdefect.*'
      'from rem_sprdefect'
      'where '
      
        '    rem_sprdefect.idpr_rem_sprdefect=:PARAM_ID_GROUP_ELEMENT and' +
        ' rem_sprdefect.idgrp_rem_sprdefect=:PARAM_IDGRP'
      'order by rem_sprdefect.name_rem_sprdefect')
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
    object TableID_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'ID_REM_SPRDEFECT'
    end
    object TableCODE_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_SPRDEFECT'
    end
    object TableNAME_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_SPRDEFECT'
      Size = 200
    end
    object TableIDPR_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRDEFECT'
    end
    object TableIDGRP_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRDEFECT'
    end
    object TableNAME_ENG_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRDEFECT'
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
      'UPDATE REM_SPRDEFECT'
      'SET '
      '    IDBASE_REM_SPRDEFECT = :IDBASE_REM_SPRDEFECT,'
      '    GID_REM_SPRDEFECT = :GID_REM_SPRDEFECT,'
      '    IDPR_REM_SPRDEFECT = :IDPR_REM_SPRDEFECT,'
      '    IDGRP_REM_SPRDEFECT = :IDGRP_REM_SPRDEFECT,'
      '    CODE_REM_SPRDEFECT = :CODE_REM_SPRDEFECT,'
      '    NAME_REM_SPRDEFECT = :NAME_REM_SPRDEFECT,'
      '    NAME_ENG_REM_SPRDEFECT = :NAME_ENG_REM_SPRDEFECT'
      'WHERE'
      '    ID_REM_SPRDEFECT = :OLD_ID_REM_SPRDEFECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRDEFECT'
      'WHERE'
      '        ID_REM_SPRDEFECT = :OLD_ID_REM_SPRDEFECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRDEFECT('
      '    ID_REM_SPRDEFECT,'
      '    IDBASE_REM_SPRDEFECT,'
      '    GID_REM_SPRDEFECT,'
      '    IDPR_REM_SPRDEFECT,'
      '    IDGRP_REM_SPRDEFECT,'
      '    CODE_REM_SPRDEFECT,'
      '    NAME_REM_SPRDEFECT,'
      '    NAME_ENG_REM_SPRDEFECT'
      ')'
      'VALUES('
      '    :ID_REM_SPRDEFECT,'
      '    :IDBASE_REM_SPRDEFECT,'
      '    :GID_REM_SPRDEFECT,'
      '    :IDPR_REM_SPRDEFECT,'
      '    :IDGRP_REM_SPRDEFECT,'
      '    :CODE_REM_SPRDEFECT,'
      '    :NAME_REM_SPRDEFECT,'
      '    :NAME_ENG_REM_SPRDEFECT'
      ')')
    RefreshSQL.Strings = (
      'select rem_sprdefect.*'
      'from rem_sprdefect'
      'where(  rem_sprdefect.id_rem_sprdefect=:PARAM_ID'
      
        '     ) and (     REM_SPRDEFECT.ID_REM_SPRDEFECT = :OLD_ID_REM_SP' +
        'RDEFECT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_sprdefect.*'
      'from rem_sprdefect'
      'where rem_sprdefect.id_rem_sprdefect=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRDEFECT'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRDEFECT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRDEFECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 72
    poUseLargeIntField = True
    object ElementID_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'ID_REM_SPRDEFECT'
    end
    object ElementIDBASE_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRDEFECT'
    end
    object ElementGID_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'GID_REM_SPRDEFECT'
      Size = 10
    end
    object ElementIDPR_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRDEFECT'
    end
    object ElementIDGRP_REM_SPRDEFECT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRDEFECT'
    end
    object ElementCODE_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_SPRDEFECT'
    end
    object ElementNAME_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_SPRDEFECT'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRDEFECT'
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
