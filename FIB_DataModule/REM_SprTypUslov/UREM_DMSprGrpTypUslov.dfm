object REM_DMSprGrpTypUslov: TREM_DMSprGrpTypUslov
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 308
  Width = 488
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
      'select * '
      'from '
      '  rem_stypuslov_grp'
      'order by  rem_stypuslov_grp.idgrp_rem_stypuslov_grp')
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
    object TableID_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPUSLOV_GRP'
    end
    object TableGID_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPUSLOV_GRP'
      Size = 10
    end
    object TableIDBASE_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPUSLOV_GRP'
    end
    object TableIDGRP_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPUSLOV_GRP'
    end
    object TableNAME_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV_GRP'
      Size = 200
    end
    object TableNAME_ENG_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPUSLOV_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPUSLOV_GRP'
      'SET '
      '    GID_REM_STYPUSLOV_GRP = :GID_REM_STYPUSLOV_GRP,'
      '    IDBASE_REM_STYPUSLOV_GRP = :IDBASE_REM_STYPUSLOV_GRP,'
      '    IDGRP_REM_STYPUSLOV_GRP = :IDGRP_REM_STYPUSLOV_GRP,'
      '    NAME_REM_STYPUSLOV_GRP = :NAME_REM_STYPUSLOV_GRP,'
      '    NAME_ENG_REM_STYPUSLOV_GRP = :NAME_ENG_REM_STYPUSLOV_GRP'
      'WHERE'
      '    ID_REM_STYPUSLOV_GRP = :OLD_ID_REM_STYPUSLOV_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPUSLOV_GRP'
      'WHERE'
      '        ID_REM_STYPUSLOV_GRP = :OLD_ID_REM_STYPUSLOV_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPUSLOV_GRP('
      '    ID_REM_STYPUSLOV_GRP,'
      '    GID_REM_STYPUSLOV_GRP,'
      '    IDBASE_REM_STYPUSLOV_GRP,'
      '    IDGRP_REM_STYPUSLOV_GRP,'
      '    NAME_REM_STYPUSLOV_GRP,'
      '    NAME_ENG_REM_STYPUSLOV_GRP'
      ')'
      'VALUES('
      '    :ID_REM_STYPUSLOV_GRP,'
      '    :GID_REM_STYPUSLOV_GRP,'
      '    :IDBASE_REM_STYPUSLOV_GRP,'
      '    :IDGRP_REM_STYPUSLOV_GRP,'
      '    :NAME_REM_STYPUSLOV_GRP,'
      '    :NAME_ENG_REM_STYPUSLOV_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from rem_stypuslov_grp'
      'where(  rem_stypuslov_grp.id_rem_stypuslov_grp=:PARAM_ID'
      
        '     ) and (     REM_STYPUSLOV_GRP.ID_REM_STYPUSLOV_GRP = :OLD_I' +
        'D_REM_STYPUSLOV_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from rem_stypuslov_grp'
      'where rem_stypuslov_grp.id_rem_stypuslov_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPUSLOV_GRP'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPUSLOV_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPUSLOV_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'ID_REM_STYPUSLOV_GRP'
    end
    object ElementGID_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'GID_REM_STYPUSLOV_GRP'
      Size = 10
    end
    object ElementIDBASE_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPUSLOV_GRP'
    end
    object ElementIDGRP_REM_STYPUSLOV_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPUSLOV_GRP'
    end
    object ElementNAME_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV_GRP'
      Size = 200
    end
    object ElementNAME_ENG_REM_STYPUSLOV_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPUSLOV_GRP'
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
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
