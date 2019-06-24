object REM_DMSprModel2: TREM_DMSprModel2
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 304
  Width = 551
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourcePodr: TDataSource
    AutoEdit = False
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SMODEL2'
      'SET '
      '    GID_REM_SMODEL2 = :GID_REM_SMODEL2,'
      '    IDBASE_REM_SMODEL2 = :IDBASE_REM_SMODEL2,'
      '    NAME_REM_SMODEL2 = :NAME_REM_SMODEL2,'
      '    IDTYPEDEV_REM_SMODEL2 = :IDTYPEDEV_REM_SMODEL2,'
      '    IDMODEL_REM_SMODEL2 = :IDMODEL_REM_SMODEL2,'
      '    IDGRP_REM_SMODEL2 = :IDGRP_REM_SMODEL2'
      'WHERE'
      '    ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL2'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL2'
      'WHERE'
      '        ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL2'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL2('
      '    ID_REM_SMODEL2,'
      '    GID_REM_SMODEL2,'
      '    IDBASE_REM_SMODEL2,'
      '    NAME_REM_SMODEL2,'
      '    IDTYPEDEV_REM_SMODEL2,'
      '    IDMODEL_REM_SMODEL2,'
      '    IDGRP_REM_SMODEL2'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL2,'
      '    :GID_REM_SMODEL2,'
      '    :IDBASE_REM_SMODEL2,'
      '    :NAME_REM_SMODEL2,'
      '    :IDTYPEDEV_REM_SMODEL2,'
      '    :IDMODEL_REM_SMODEL2,'
      '    :IDGRP_REM_SMODEL2'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel2.*,'
      '       rem_smodel.strcode_rem_smodel,'
      '       rem_smodel.name_rem_smodel'
      'from rem_smodel2'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smode' +
        'l2.idmodel_rem_smodel2'
      'where( '
      
        '        rem_smodel2.idtypedev_rem_smodel2=:PARAM_ID_GROUP_ELEMEN' +
        'T'
      ' AND rem_smodel2.idgrp_rem_smodel2=:PARAM_IDGRP'
      
        '     ) and (     REM_SMODEL2.ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL' +
        '2'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel2.*,'
      '       rem_smodel.strcode_rem_smodel,'
      '       rem_smodel.name_rem_smodel'
      'from rem_smodel2'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smode' +
        'l2.idmodel_rem_smodel2'
      'where'
      
        '        rem_smodel2.idtypedev_rem_smodel2=:PARAM_ID_GROUP_ELEMEN' +
        'T'
      ' AND rem_smodel2.idgrp_rem_smodel2=:PARAM_IDGRP'
      'order by rem_smodel2.name_rem_smodel2')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL2'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL2'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL2_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL2'
    end
    object TableGID_REM_SMODEL2: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL2'
      Size = 10
    end
    object TableIDBASE_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL2'
    end
    object TableNAME_REM_SMODEL2: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL2'
      Size = 200
    end
    object TableIDTYPEDEV_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDTYPEDEV_REM_SMODEL2'
    end
    object TableIDMODEL_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL2'
    end
    object TableIDGRP_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL2'
    end
    object TableSTRCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'STRCODE_REM_SMODEL'
      Size = 30
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
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
    Left = 272
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
    Left = 272
    Top = 72
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE REM_SMODEL2'
      'SET '
      '    GID_REM_SMODEL2 = :GID_REM_SMODEL2,'
      '    IDBASE_REM_SMODEL2 = :IDBASE_REM_SMODEL2,'
      '    NAME_REM_SMODEL2 = :NAME_REM_SMODEL2,'
      '    IDTYPEDEV_REM_SMODEL2 = :IDTYPEDEV_REM_SMODEL2,'
      '    IDMODEL_REM_SMODEL2 = :IDMODEL_REM_SMODEL2,'
      '    IDGRP_REM_SMODEL2 = :IDGRP_REM_SMODEL2'
      'WHERE'
      '    ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL2'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SMODEL2'
      'WHERE'
      '        ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL2'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SMODEL2('
      '    ID_REM_SMODEL2,'
      '    GID_REM_SMODEL2,'
      '    IDBASE_REM_SMODEL2,'
      '    NAME_REM_SMODEL2,'
      '    IDTYPEDEV_REM_SMODEL2,'
      '    IDMODEL_REM_SMODEL2,'
      '    IDGRP_REM_SMODEL2'
      ')'
      'VALUES('
      '    :ID_REM_SMODEL2,'
      '    :GID_REM_SMODEL2,'
      '    :IDBASE_REM_SMODEL2,'
      '    :NAME_REM_SMODEL2,'
      '    :IDTYPEDEV_REM_SMODEL2,'
      '    :IDMODEL_REM_SMODEL2,'
      '    :IDGRP_REM_SMODEL2'
      ')')
    RefreshSQL.Strings = (
      'select rem_smodel2.*,'
      '       rem_smodel.strcode_rem_smodel,'
      '       rem_smodel.name_rem_smodel'
      'from rem_smodel2'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smode' +
        'l2.idmodel_rem_smodel2'
      'where(  rem_smodel2.id_rem_smodel2=:PARAM_ID'
      
        '     ) and (     REM_SMODEL2.ID_REM_SMODEL2 = :OLD_ID_REM_SMODEL' +
        '2'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_smodel2.*,'
      '       rem_smodel.strcode_rem_smodel,'
      '       rem_smodel.name_rem_smodel'
      'from rem_smodel2'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smode' +
        'l2.idmodel_rem_smodel2'
      'where rem_smodel2.id_rem_smodel2=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SMODEL2'
    AutoUpdateOptions.KeyFields = 'ID_REM_SMODEL2'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SMODEL2_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'ID_REM_SMODEL2'
    end
    object ElementGID_REM_SMODEL2: TFIBWideStringField
      FieldName = 'GID_REM_SMODEL2'
      Size = 10
    end
    object ElementIDBASE_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SMODEL2'
    end
    object ElementNAME_REM_SMODEL2: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL2'
      Size = 200
    end
    object ElementIDTYPEDEV_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDTYPEDEV_REM_SMODEL2'
    end
    object ElementIDMODEL_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SMODEL2'
    end
    object ElementIDGRP_REM_SMODEL2: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SMODEL2'
    end
    object ElementSTRCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'STRCODE_REM_SMODEL'
      Size = 30
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
  end
end
