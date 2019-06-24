object REM_DMSprProducerModelGrp: TREM_DMSprProducerModelGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 193
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
      'from  rem_sprmodel_grp'
      
        'where rem_sprmodel_grp.idpr_rem_sprmodel_grp=:PARAM_ID_GROUP_ELE' +
        'MENT'
      'order by rem_sprmodel_grp.idgrp_rem_sprmodel_grp')
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
    object TableID_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL_GRP'
    end
    object TableIDBASE_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMODEL_GRP'
    end
    object TableGID_REM_SPRMODEL_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRMODEL_GRP'
      Size = 10
    end
    object TableIDPR_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRMODEL_GRP'
    end
    object TableIDGRP_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRMODEL_GRP'
    end
    object TableNAME_REM_SPRMODEL_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SPRMODEL_GRP'
      'SET '
      '    IDBASE_REM_SPRMODEL_GRP = :IDBASE_REM_SPRMODEL_GRP,'
      '    GID_REM_SPRMODEL_GRP = :GID_REM_SPRMODEL_GRP,'
      '    IDPR_REM_SPRMODEL_GRP = :IDPR_REM_SPRMODEL_GRP,'
      '    IDGRP_REM_SPRMODEL_GRP = :IDGRP_REM_SPRMODEL_GRP,'
      '    NAME_REM_SPRMODEL_GRP = :NAME_REM_SPRMODEL_GRP'
      'WHERE'
      '    ID_REM_SPRMODEL_GRP = :OLD_ID_REM_SPRMODEL_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SPRMODEL_GRP'
      'WHERE'
      '        ID_REM_SPRMODEL_GRP = :OLD_ID_REM_SPRMODEL_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SPRMODEL_GRP('
      '    ID_REM_SPRMODEL_GRP,'
      '    IDBASE_REM_SPRMODEL_GRP,'
      '    GID_REM_SPRMODEL_GRP,'
      '    IDPR_REM_SPRMODEL_GRP,'
      '    IDGRP_REM_SPRMODEL_GRP,'
      '    NAME_REM_SPRMODEL_GRP'
      ')'
      'VALUES('
      '    :ID_REM_SPRMODEL_GRP,'
      '    :IDBASE_REM_SPRMODEL_GRP,'
      '    :GID_REM_SPRMODEL_GRP,'
      '    :IDPR_REM_SPRMODEL_GRP,'
      '    :IDGRP_REM_SPRMODEL_GRP,'
      '    :NAME_REM_SPRMODEL_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  rem_sprmodel_grp'
      'where(  rem_sprmodel_grp.id_rem_sprmodel_grp=:PARAM_ID'
      
        '     ) and (     REM_SPRMODEL_GRP.ID_REM_SPRMODEL_GRP = :OLD_ID_' +
        'REM_SPRMODEL_GRP'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select * '
      'from  rem_sprmodel_grp'
      'where rem_sprmodel_grp.id_rem_sprmodel_grp=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_SPRMODEL_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_SPRMODEL_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SPRMODEL_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SPRMODEL_GRP'
    end
    object ElementIDBASE_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SPRMODEL_GRP'
    end
    object ElementGID_REM_SPRMODEL_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SPRMODEL_GRP'
      Size = 10
    end
    object ElementIDPR_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDPR_REM_SPRMODEL_GRP'
    end
    object ElementIDGRP_REM_SPRMODEL_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SPRMODEL_GRP'
    end
    object ElementNAME_REM_SPRMODEL_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL_GRP'
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
    Left = 248
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
    Left = 248
    Top = 80
  end
end
