object REM_DMSprModel2Grp: TREM_DMSprModel2Grp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 329
  Width = 603
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
      'select rem_smodel2_grp.*'
      'from  rem_smodel2_grp'
      
        'where rem_smodel2_grp.idtypedev_rem_smodel2_grp=:PARAM_ID_GROUP_' +
        'ELEMENT'
      'order by rem_smodel2_grp.idgrp_rem_smodel2_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL2_GRP'
    end
    object TableGID_REM_SMODEL2_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL2_GRP'
      Size = 10
    end
    object TableIDBASE_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL2_GRP'
    end
    object TableIDGRP_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL2_GRP'
    end
    object TableNAME_REM_SMODEL2_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL2_GRP'
      Size = 200
    end
    object TableIDTYPEDEV_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDTYPEDEV_REM_SMODEL2_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SMODEL2_GRP'
      'SET '
      '    GID_REM_SMODEL2_GRP = :GID_REM_SMODEL2_GRP,'
      '    IDBASE_REM_SMODEL2_GRP = :IDBASE_REM_SMODEL2_GRP,'
      '    IDGRP_REM_SMODEL2_GRP = :IDGRP_REM_SMODEL2_GRP,'
      '    NAME_REM_SMODEL2_GRP = :NAME_REM_SMODEL2_GRP,'
      '    IDTYPEDEV_REM_SMODEL2_GRP = :IDTYPEDEV_REM_SMODEL2_GRP'
      'WHERE'
      '    ID_REM_SMODEL2_GRP = :OLD_ID_REM_SMODEL2_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL2_GRP'
      'WHERE'
      '        ID_REM_SMODEL2_GRP = :OLD_ID_REM_SMODEL2_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL2_GRP('
      '    ID_REM_SMODEL2_GRP,'
      '    GID_REM_SMODEL2_GRP,'
      '    IDBASE_REM_SMODEL2_GRP,'
      '    IDGRP_REM_SMODEL2_GRP,'
      '    NAME_REM_SMODEL2_GRP,'
      '    IDTYPEDEV_REM_SMODEL2_GRP'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL2_GRP,'
      '    :GID_REM_SMODEL2_GRP,'
      '    :IDBASE_REM_SMODEL2_GRP,'
      '    :IDGRP_REM_SMODEL2_GRP,'
      '    :NAME_REM_SMODEL2_GRP,'
      '    :IDTYPEDEV_REM_SMODEL2_GRP'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel2_grp.*'
      'from  rem_smodel2_grp'
      'where(  rem_smodel2_grp.id_rem_smodel2_grp=:PARAM_ID'
      
        '     ) and (     REM_SMODEL2_GRP.ID_REM_SMODEL2_GRP = :OLD_ID_RE' +
        'M_SMODEL2_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel2_grp.*'
      'from  rem_smodel2_grp'
      'where rem_smodel2_grp.id_rem_smodel2_grp=:PARAM_ID'
      'order by rem_smodel2_grp.idgrp_rem_smodel2_grp')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL2_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL2_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL2_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL2_GRP'
    end
    object ElementGID_REM_SMODEL2_GRP: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL2_GRP'
      Size = 10
    end
    object ElementIDBASE_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL2_GRP'
    end
    object ElementIDGRP_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL2_GRP'
    end
    object ElementNAME_REM_SMODEL2_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL2_GRP'
      Size = 200
    end
    object ElementIDTYPEDEV_REM_SMODEL2_GRP: TFIBLargeIntField
      FieldName = 'IDTYPEDEV_REM_SMODEL2_GRP'
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
