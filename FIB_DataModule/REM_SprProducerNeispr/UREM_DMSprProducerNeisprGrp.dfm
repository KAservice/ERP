object REM_DMSprProducerNeisprGrp: TREM_DMSprProducerNeisprGrp
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
    SelectSQL.Strings = (
      'select * '
      'from  rem_sprneispr_grp'
      
        'where rem_sprneispr_grp.idpr_rem_sprneispr_grp=:PARAM_ID_GROUP_E' +
        'LEMENT'
      'order by rem_sprneispr_grp.idgrp_rem_sprneispr_grp')
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
    object TableID_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRNEISPR_GRP'
    end
    object TableIDBASE_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRNEISPR_GRP'
    end
    object TableGID_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRNEISPR_GRP'
      Size = 10
    end
    object TableIDPR_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRNEISPR_GRP'
    end
    object TableNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object TableIDGRP_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRNEISPR_GRP'
    end
    object TableNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SPRNEISPR_GRP'
      'SET '
      '    IDBASE_REM_SPRNEISPR_GRP = :IDBASE_REM_SPRNEISPR_GRP,'
      '    GID_REM_SPRNEISPR_GRP = :GID_REM_SPRNEISPR_GRP,'
      '    IDPR_REM_SPRNEISPR_GRP = :IDPR_REM_SPRNEISPR_GRP,'
      '    NAME_REM_SPRNEISPR_GRP = :NAME_REM_SPRNEISPR_GRP,'
      '    IDGRP_REM_SPRNEISPR_GRP = :IDGRP_REM_SPRNEISPR_GRP,'
      '    NAME_ENG_REM_SPRNEISPR_GRP = :NAME_ENG_REM_SPRNEISPR_GRP'
      'WHERE'
      '    ID_REM_SPRNEISPR_GRP = :OLD_ID_REM_SPRNEISPR_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRNEISPR_GRP'
      'WHERE'
      '        ID_REM_SPRNEISPR_GRP = :OLD_ID_REM_SPRNEISPR_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRNEISPR_GRP('
      '    ID_REM_SPRNEISPR_GRP,'
      '    IDBASE_REM_SPRNEISPR_GRP,'
      '    GID_REM_SPRNEISPR_GRP,'
      '    IDPR_REM_SPRNEISPR_GRP,'
      '    NAME_REM_SPRNEISPR_GRP,'
      '    IDGRP_REM_SPRNEISPR_GRP,'
      '    NAME_ENG_REM_SPRNEISPR_GRP'
      ')'
      'VALUES('
      '    :ID_REM_SPRNEISPR_GRP,'
      '    :IDBASE_REM_SPRNEISPR_GRP,'
      '    :GID_REM_SPRNEISPR_GRP,'
      '    :IDPR_REM_SPRNEISPR_GRP,'
      '    :NAME_REM_SPRNEISPR_GRP,'
      '    :IDGRP_REM_SPRNEISPR_GRP,'
      '    :NAME_ENG_REM_SPRNEISPR_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  rem_sprneispr_grp'
      'where(  rem_sprneispr_grp.id_rem_sprneispr_grp=:PARAM_ID'
      
        '     ) and (     REM_SPRNEISPR_GRP.ID_REM_SPRNEISPR_GRP = :OLD_I' +
        'D_REM_SPRNEISPR_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  rem_sprneispr_grp'
      'where rem_sprneispr_grp.id_rem_sprneispr_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRNEISPR_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRNEISPR_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRNEISPR_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRNEISPR_GRP'
    end
    object ElementIDBASE_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRNEISPR_GRP'
    end
    object ElementGID_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRNEISPR_GRP'
      Size = 10
    end
    object ElementIDPR_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRNEISPR_GRP'
    end
    object ElementNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object ElementIDGRP_REM_SPRNEISPR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRNEISPR_GRP'
    end
    object ElementNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
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
