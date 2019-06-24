object DMSprVidImageGrp: TDMSprVidImageGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 332
  Width = 372
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
      'from '
      '  svidimage_grp'
      'order by svidimage_grp.idgrp_svidimage_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_SVIDIMAGE_GRP'
    end
    object TableIDBASE_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SVIDIMAGE_GRP'
    end
    object TableGID_SVIDIMAGE_GRP: TFIBWideStringField
      FieldName = 'GID_SVIDIMAGE_GRP'
      Size = 10
    end
    object TableIDGRP_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SVIDIMAGE_GRP'
    end
    object TableNAME_SVIDIMAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE_GRP'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVIDIMAGE_GRP'
      'SET '
      '    IDBASE_SVIDIMAGE_GRP = :IDBASE_SVIDIMAGE_GRP,'
      '    GID_SVIDIMAGE_GRP = :GID_SVIDIMAGE_GRP,'
      '    IDGRP_SVIDIMAGE_GRP = :IDGRP_SVIDIMAGE_GRP,'
      '    NAME_SVIDIMAGE_GRP = :NAME_SVIDIMAGE_GRP'
      'WHERE'
      '    ID_SVIDIMAGE_GRP = :OLD_ID_SVIDIMAGE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDIMAGE_GRP'
      'WHERE'
      '        ID_SVIDIMAGE_GRP = :OLD_ID_SVIDIMAGE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDIMAGE_GRP('
      '    ID_SVIDIMAGE_GRP,'
      '    IDBASE_SVIDIMAGE_GRP,'
      '    GID_SVIDIMAGE_GRP,'
      '    IDGRP_SVIDIMAGE_GRP,'
      '    NAME_SVIDIMAGE_GRP'
      ')'
      'VALUES('
      '    :ID_SVIDIMAGE_GRP,'
      '    :IDBASE_SVIDIMAGE_GRP,'
      '    :GID_SVIDIMAGE_GRP,'
      '    :IDGRP_SVIDIMAGE_GRP,'
      '    :NAME_SVIDIMAGE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  svidimage_grp'
      'where(  svidimage_grp.id_svidimage_grp=:PARAM_ID'
      
        '     ) and (     SVIDIMAGE_GRP.ID_SVIDIMAGE_GRP = :OLD_ID_SVIDIM' +
        'AGE_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  svidimage_grp'
      'where svidimage_grp.id_svidimage_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVIDIMAGE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SVIDIMAGE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDIMAGE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_SVIDIMAGE_GRP'
    end
    object ElementIDBASE_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SVIDIMAGE_GRP'
    end
    object ElementGID_SVIDIMAGE_GRP: TFIBWideStringField
      FieldName = 'GID_SVIDIMAGE_GRP'
      Size = 10
    end
    object ElementIDGRP_SVIDIMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SVIDIMAGE_GRP'
    end
    object ElementNAME_SVIDIMAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE_GRP'
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
