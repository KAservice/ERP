object REM_DMSprGrpModel: TREM_DMSprGrpModel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 206
  Width = 351
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
      '  REM_SGRPMODEL'
      'order by ID_REM_SGRPMODEL')
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
    object TableID_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPMODEL'
    end
    object TableGID_REM_SGRPMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SGRPMODEL'
      Size = 10
    end
    object TableIDGRP_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPMODEL'
    end
    object TableNAME_REM_SGRPMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPMODEL'
      Size = 100
    end
    object TableIDBASE_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPMODEL'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
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
      'from REM_SGRPMODEL '
      'where(  ID_REM_SGRPMODEL=:PARAM_ID'
      
        '     ) and (     REM_SGRPMODEL.ID_REM_SGRPMODEL = :OLD_ID_REM_SG' +
        'RPMODEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from REM_SGRPMODEL '
      'where ID_REM_SGRPMODEL=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SGRPMODEL'
    AutoUpdateOptions.KeyFields = 'ID_REM_SGRPMODEL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SGRPMODEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPMODEL'
    end
    object ElementGID_REM_SGRPMODEL: TFIBWideStringField
      FieldName = 'GID_REM_SGRPMODEL'
      Size = 10
    end
    object ElementIDGRP_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPMODEL'
    end
    object ElementNAME_REM_SGRPMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPMODEL'
      Size = 100
    end
    object ElementIDBASE_REM_SGRPMODEL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPMODEL'
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
