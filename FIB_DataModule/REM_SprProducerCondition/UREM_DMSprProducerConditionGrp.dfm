object REM_DMSprProducerConditionGrp: TREM_DMSprProducerConditionGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 372
  Width = 612
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE REM_SPRCOND_GRP'
      'SET '
      '    IDBASE_REM_SPRCOND_GRP = :IDBASE_REM_SPRCOND_GRP,'
      '    GID_REM_SPRCOND_GRP = :GID_REM_SPRCOND_GRP,'
      '    IDPR_REM_SPRCOND_GRP = :IDPR_REM_SPRCOND_GRP,'
      '    IDGRP_REM_SPRCOND_GRP = :IDGRP_REM_SPRCOND_GRP,'
      '    CODE_REM_SPRCOND_GRP = :CODE_REM_SPRCOND_GRP,'
      '    NAME_REM_SPRCOND_GRP = :NAME_REM_SPRCOND_GRP,'
      '    NAME_ENG_REM_SPRCOND_GRP = :NAME_ENG_REM_SPRCOND_GRP'
      'WHERE'
      '    ID_REM_SPRCOND_GRP = :OLD_ID_REM_SPRCOND_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRCOND_GRP'
      'WHERE'
      '        ID_REM_SPRCOND_GRP = :OLD_ID_REM_SPRCOND_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRCOND_GRP('
      '    ID_REM_SPRCOND_GRP,'
      '    IDBASE_REM_SPRCOND_GRP,'
      '    GID_REM_SPRCOND_GRP,'
      '    IDPR_REM_SPRCOND_GRP,'
      '    IDGRP_REM_SPRCOND_GRP,'
      '    CODE_REM_SPRCOND_GRP,'
      '    NAME_REM_SPRCOND_GRP,'
      '    NAME_ENG_REM_SPRCOND_GRP'
      ')'
      'VALUES('
      '    :ID_REM_SPRCOND_GRP,'
      '    :IDBASE_REM_SPRCOND_GRP,'
      '    :GID_REM_SPRCOND_GRP,'
      '    :IDPR_REM_SPRCOND_GRP,'
      '    :IDGRP_REM_SPRCOND_GRP,'
      '    :CODE_REM_SPRCOND_GRP,'
      '    :NAME_REM_SPRCOND_GRP,'
      '    :NAME_ENG_REM_SPRCOND_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  rem_sprcond_grp'
      
        'where(  rem_sprcond_grp.idpr_rem_sprcond_grp=:PARAM_ID_GROUP_ELE' +
        'MENT'
      
        '     ) and (     REM_SPRCOND_GRP.ID_REM_SPRCOND_GRP = :OLD_ID_RE' +
        'M_SPRCOND_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  rem_sprcond_grp'
      
        'where rem_sprcond_grp.idpr_rem_sprcond_grp=:PARAM_ID_GROUP_ELEME' +
        'NT'
      'order by rem_sprcond_grp.idgrp_rem_sprcond_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 176
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRCOND_GRP'
    end
    object TableIDBASE_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRCOND_GRP'
    end
    object TableGID_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRCOND_GRP'
      Size = 10
    end
    object TableIDPR_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRCOND_GRP'
    end
    object TableIDGRP_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRCOND_GRP'
    end
    object TableCODE_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCOND_GRP'
      Size = 10
    end
    object TableNAME_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCOND_GRP'
      Size = 200
    end
    object TableNAME_ENG_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCOND_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SPRCOND_GRP'
      'SET '
      '    IDBASE_REM_SPRCOND_GRP = :IDBASE_REM_SPRCOND_GRP,'
      '    GID_REM_SPRCOND_GRP = :GID_REM_SPRCOND_GRP,'
      '    IDPR_REM_SPRCOND_GRP = :IDPR_REM_SPRCOND_GRP,'
      '    IDGRP_REM_SPRCOND_GRP = :IDGRP_REM_SPRCOND_GRP,'
      '    CODE_REM_SPRCOND_GRP = :CODE_REM_SPRCOND_GRP,'
      '    NAME_REM_SPRCOND_GRP = :NAME_REM_SPRCOND_GRP,'
      '    NAME_ENG_REM_SPRCOND_GRP = :NAME_ENG_REM_SPRCOND_GRP'
      'WHERE'
      '    ID_REM_SPRCOND_GRP = :OLD_ID_REM_SPRCOND_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRCOND_GRP'
      'WHERE'
      '        ID_REM_SPRCOND_GRP = :OLD_ID_REM_SPRCOND_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRCOND_GRP('
      '    ID_REM_SPRCOND_GRP,'
      '    IDBASE_REM_SPRCOND_GRP,'
      '    GID_REM_SPRCOND_GRP,'
      '    IDPR_REM_SPRCOND_GRP,'
      '    IDGRP_REM_SPRCOND_GRP,'
      '    CODE_REM_SPRCOND_GRP,'
      '    NAME_REM_SPRCOND_GRP,'
      '    NAME_ENG_REM_SPRCOND_GRP'
      ')'
      'VALUES('
      '    :ID_REM_SPRCOND_GRP,'
      '    :IDBASE_REM_SPRCOND_GRP,'
      '    :GID_REM_SPRCOND_GRP,'
      '    :IDPR_REM_SPRCOND_GRP,'
      '    :IDGRP_REM_SPRCOND_GRP,'
      '    :CODE_REM_SPRCOND_GRP,'
      '    :NAME_REM_SPRCOND_GRP,'
      '    :NAME_ENG_REM_SPRCOND_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  rem_sprcond_grp'
      'where(  rem_sprcond_grp.id_rem_sprcond_grp=:PARAM_ID'
      
        '     ) and (     REM_SPRCOND_GRP.ID_REM_SPRCOND_GRP = :OLD_ID_RE' +
        'M_SPRCOND_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  rem_sprcond_grp'
      'where rem_sprcond_grp.id_rem_sprcond_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRCOND_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRCOND_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRCOND_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRCOND_GRP'
    end
    object ElementIDBASE_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRCOND_GRP'
    end
    object ElementGID_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRCOND_GRP'
      Size = 10
    end
    object ElementIDPR_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRCOND_GRP'
    end
    object ElementIDGRP_REM_SPRCOND_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRCOND_GRP'
    end
    object ElementCODE_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCOND_GRP'
      Size = 10
    end
    object ElementNAME_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCOND_GRP'
      Size = 200
    end
    object ElementNAME_ENG_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCOND_GRP'
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
    Top = 24
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
end
