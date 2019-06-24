object REM_DMSprGrpTypDefect: TREM_DMSprGrpTypDefect
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
      'select rem_stypdefect_grp.*'
      'from '
      '  rem_stypdefect_grp'
      'order by rem_stypdefect_grp.idgrp_rem_stypdefect_grp')
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
    object TableID_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPDEFECT_GRP'
    end
    object TableIDBASE_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPDEFECT_GRP'
    end
    object TableNAME_REM_STYPDEFECT_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT_GRP'
      Size = 200
    end
    object TableIDGRP_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPDEFECT_GRP'
    end
    object TableGID_REM_STYPDEFECT_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPDEFECT_GRP'
      Size = 10
    end
    object TableNAME_ENG_REM_STYPDEFECT_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPDEFECT_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPDEFECT_GRP'
      'SET '
      '    IDBASE_REM_STYPDEFECT_GRP = :IDBASE_REM_STYPDEFECT_GRP,'
      '    NAME_REM_STYPDEFECT_GRP = :NAME_REM_STYPDEFECT_GRP,'
      '    IDGRP_REM_STYPDEFECT_GRP = :IDGRP_REM_STYPDEFECT_GRP,'
      '    GID_REM_STYPDEFECT_GRP = :GID_REM_STYPDEFECT_GRP,'
      '    NAME_ENG_REM_STYPDEFECT_GRP = :NAME_ENG_REM_STYPDEFECT_GRP'
      'WHERE'
      '    ID_REM_STYPDEFECT_GRP = :OLD_ID_REM_STYPDEFECT_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPDEFECT_GRP'
      'WHERE'
      '        ID_REM_STYPDEFECT_GRP = :OLD_ID_REM_STYPDEFECT_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPDEFECT_GRP('
      '    ID_REM_STYPDEFECT_GRP,'
      '    IDBASE_REM_STYPDEFECT_GRP,'
      '    NAME_REM_STYPDEFECT_GRP,'
      '    IDGRP_REM_STYPDEFECT_GRP,'
      '    GID_REM_STYPDEFECT_GRP,'
      '    NAME_ENG_REM_STYPDEFECT_GRP'
      ')'
      'VALUES('
      '    :ID_REM_STYPDEFECT_GRP,'
      '    :IDBASE_REM_STYPDEFECT_GRP,'
      '    :NAME_REM_STYPDEFECT_GRP,'
      '    :IDGRP_REM_STYPDEFECT_GRP,'
      '    :GID_REM_STYPDEFECT_GRP,'
      '    :NAME_ENG_REM_STYPDEFECT_GRP'
      ')')
    RefreshSQL.Strings = (
      'select rem_stypdefect_grp.*'
      'from rem_stypdefect_grp'
      'where(  rem_stypdefect_grp.id_rem_stypdefect_grp=:PARAM_ID'
      
        '     ) and (     REM_STYPDEFECT_GRP.ID_REM_STYPDEFECT_GRP = :OLD' +
        '_ID_REM_STYPDEFECT_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_stypdefect_grp.*'
      'from rem_stypdefect_grp'
      'where rem_stypdefect_grp.id_rem_stypdefect_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPDEFECT_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPDEFECT_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPDEFECT_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPDEFECT_GRP'
    end
    object ElementIDBASE_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPDEFECT_GRP'
    end
    object ElementNAME_REM_STYPDEFECT_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT_GRP'
      Size = 200
    end
    object ElementIDGRP_REM_STYPDEFECT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPDEFECT_GRP'
    end
    object ElementGID_REM_STYPDEFECT_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPDEFECT_GRP'
      Size = 10
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
