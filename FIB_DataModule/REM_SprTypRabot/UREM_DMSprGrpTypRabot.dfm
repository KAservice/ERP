object REM_DMSprGrpTypRabot: TREM_DMSprGrpTypRabot
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 367
  Width = 539
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
      'UPDATE REM_SGRPMODEL'
      'SET '
      '    GID_REM_SGRPMODEL = :GID_REM_SGRPMODEL,'
      '    IDGRP_REM_SGRPMODEL = :IDGRP_REM_SGRPMODEL,'
      '    NAME_REM_SGRPMODEL = :NAME_REM_SGRPMODEL'
      'WHERE'
      '    ID_REM_SGRPMODEL = :OLD_ID_REM_SGRPMODEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SGRPMODEL'
      'WHERE'
      '        ID_REM_SGRPMODEL = :OLD_ID_REM_SGRPMODEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SGRPMODEL('
      '    ID_REM_SGRPMODEL,'
      '    GID_REM_SGRPMODEL,'
      '    IDGRP_REM_SGRPMODEL,'
      '    NAME_REM_SGRPMODEL'
      ')'
      'VALUES('
      '    :ID_REM_SGRPMODEL,'
      '    :GID_REM_SGRPMODEL,'
      '    :IDGRP_REM_SGRPMODEL,'
      '    :NAME_REM_SGRPMODEL'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  REM_SGRPMODEL'
      ''
      ' WHERE '
      '        REM_SGRPMODEL.ID_REM_SGRPMODEL = :OLD_ID_REM_SGRPMODEL'
      '    ')
    SelectSQL.Strings = (
      'select rem_styprabot_grp.*'
      'from '
      '  rem_styprabot_grp'
      'order by rem_styprabot_grp.idgrp_rem_styprabot_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPRABOT_GRP'
    end
    object TableGID_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPRABOT_GRP'
      Size = 10
    end
    object TableIDBASE_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPRABOT_GRP'
    end
    object TableIDGRP_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPRABOT_GRP'
    end
    object TableNAME_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT_GRP'
      Size = 200
    end
    object TableNAME_ENG_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPRABOT_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPRABOT_GRP'
      'SET '
      '    GID_REM_STYPRABOT_GRP = :GID_REM_STYPRABOT_GRP,'
      '    IDBASE_REM_STYPRABOT_GRP = :IDBASE_REM_STYPRABOT_GRP,'
      '    IDGRP_REM_STYPRABOT_GRP = :IDGRP_REM_STYPRABOT_GRP,'
      '    NAME_REM_STYPRABOT_GRP = :NAME_REM_STYPRABOT_GRP,'
      '    NAME_ENG_REM_STYPRABOT_GRP = :NAME_ENG_REM_STYPRABOT_GRP'
      'WHERE'
      '    ID_REM_STYPRABOT_GRP = :OLD_ID_REM_STYPRABOT_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPRABOT_GRP'
      'WHERE'
      '        ID_REM_STYPRABOT_GRP = :OLD_ID_REM_STYPRABOT_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPRABOT_GRP('
      '    ID_REM_STYPRABOT_GRP,'
      '    GID_REM_STYPRABOT_GRP,'
      '    IDBASE_REM_STYPRABOT_GRP,'
      '    IDGRP_REM_STYPRABOT_GRP,'
      '    NAME_REM_STYPRABOT_GRP,'
      '    NAME_ENG_REM_STYPRABOT_GRP'
      ')'
      'VALUES('
      '    :ID_REM_STYPRABOT_GRP,'
      '    :GID_REM_STYPRABOT_GRP,'
      '    :IDBASE_REM_STYPRABOT_GRP,'
      '    :IDGRP_REM_STYPRABOT_GRP,'
      '    :NAME_REM_STYPRABOT_GRP,'
      '    :NAME_ENG_REM_STYPRABOT_GRP'
      ')')
    RefreshSQL.Strings = (
      'select rem_styprabot_grp.*'
      'from rem_styprabot_grp'
      'where(  rem_styprabot_grp.id_rem_styprabot_grp=:PARAM_ID'
      
        '     ) and (     REM_STYPRABOT_GRP.ID_REM_STYPRABOT_GRP = :OLD_I' +
        'D_REM_STYPRABOT_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_styprabot_grp.*'
      'from rem_styprabot_grp'
      'where rem_styprabot_grp.id_rem_styprabot_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPRABOT_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPRABOT_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPRABOT_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPRABOT_GRP'
    end
    object ElementGID_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPRABOT_GRP'
      Size = 10
    end
    object ElementIDBASE_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPRABOT_GRP'
    end
    object ElementIDGRP_REM_STYPRABOT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPRABOT_GRP'
    end
    object ElementNAME_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT_GRP'
      Size = 200
    end
    object ElementNAME_ENG_REM_STYPRABOT_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPRABOT_GRP'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
