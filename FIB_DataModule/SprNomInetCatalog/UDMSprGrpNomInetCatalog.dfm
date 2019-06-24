object DMSprGrpNomInetCatalog: TDMSprGrpNomInetCatalog
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 351
  Width = 479
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
      'select * from  snominetcat_grp'
      
        'where snominetcat_grp.idinetcat_snominetcat_grp=:PARAM_IDINETCAT' +
        'ALOG'
      'order by snominetcat_grp.idgrp_snominetcat_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableID_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'ID_SNOMINETCAT_GRP'
    end
    object TableIDBASE_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMINETCAT_GRP'
    end
    object TableGID_SNOMINETCAT_GRP: TFIBWideStringField
      FieldName = 'GID_SNOMINETCAT_GRP'
      Size = 10
    end
    object TableIDGRP_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SNOMINETCAT_GRP'
    end
    object TableIDINETCAT_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDINETCAT_SNOMINETCAT_GRP'
    end
    object TableNAME_SNOMINETCAT_GRP: TFIBWideStringField
      FieldName = 'NAME_SNOMINETCAT_GRP'
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
      'UPDATE SNOMINETCAT_GRP'
      'SET '
      '    IDBASE_SNOMINETCAT_GRP = :IDBASE_SNOMINETCAT_GRP,'
      '    GID_SNOMINETCAT_GRP = :GID_SNOMINETCAT_GRP,'
      '    IDGRP_SNOMINETCAT_GRP = :IDGRP_SNOMINETCAT_GRP,'
      '    IDINETCAT_SNOMINETCAT_GRP = :IDINETCAT_SNOMINETCAT_GRP,'
      '    NAME_SNOMINETCAT_GRP = :NAME_SNOMINETCAT_GRP'
      'WHERE'
      '    ID_SNOMINETCAT_GRP = :OLD_ID_SNOMINETCAT_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMINETCAT_GRP'
      'WHERE'
      '        ID_SNOMINETCAT_GRP = :OLD_ID_SNOMINETCAT_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMINETCAT_GRP('
      '    ID_SNOMINETCAT_GRP,'
      '    IDBASE_SNOMINETCAT_GRP,'
      '    GID_SNOMINETCAT_GRP,'
      '    IDGRP_SNOMINETCAT_GRP,'
      '    IDINETCAT_SNOMINETCAT_GRP,'
      '    NAME_SNOMINETCAT_GRP'
      ')'
      'VALUES('
      '    :ID_SNOMINETCAT_GRP,'
      '    :IDBASE_SNOMINETCAT_GRP,'
      '    :GID_SNOMINETCAT_GRP,'
      '    :IDGRP_SNOMINETCAT_GRP,'
      '    :IDINETCAT_SNOMINETCAT_GRP,'
      '    :NAME_SNOMINETCAT_GRP'
      ')')
    RefreshSQL.Strings = (
      
        'select * from  snominetcat_grp where(  snominetcat_grp.id_snomin' +
        'etcat_grp=:PARAM_ID'
      
        '     ) and (     SNOMINETCAT_GRP.ID_SNOMINETCAT_GRP = :OLD_ID_SN' +
        'OMINETCAT_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select * from  snominetcat_grp where snominetcat_grp.id_snominet' +
        'cat_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMINETCAT_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SNOMINETCAT_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMINETCAT_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'ID_SNOMINETCAT_GRP'
    end
    object ElementIDBASE_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMINETCAT_GRP'
    end
    object ElementGID_SNOMINETCAT_GRP: TFIBWideStringField
      FieldName = 'GID_SNOMINETCAT_GRP'
      Size = 10
    end
    object ElementIDGRP_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SNOMINETCAT_GRP'
    end
    object ElementIDINETCAT_SNOMINETCAT_GRP: TFIBLargeIntField
      FieldName = 'IDINETCAT_SNOMINETCAT_GRP'
    end
    object ElementNAME_SNOMINETCAT_GRP: TFIBWideStringField
      FieldName = 'NAME_SNOMINETCAT_GRP'
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
