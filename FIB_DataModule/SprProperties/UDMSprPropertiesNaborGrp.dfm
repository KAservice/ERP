object DMSprPropertiesNaborGrp: TDMSprPropertiesNaborGrp
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
      '  spropnabor_grp'
      'order by spropnabor_grp.idgrp_spropnabor_grp')
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
    object TableID_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR_GRP'
    end
    object TableIDBASE_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR_GRP'
    end
    object TableGID_SPROPNABOR_GRP: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR_GRP'
      Size = 10
    end
    object TableIDGRP_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROPNABOR_GRP'
    end
    object TableNAME_SPROPNABOR_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROPNABOR_GRP'
      'SET '
      '    IDBASE_SPROPNABOR_GRP = :IDBASE_SPROPNABOR_GRP,'
      '    GID_SPROPNABOR_GRP = :GID_SPROPNABOR_GRP,'
      '    IDGRP_SPROPNABOR_GRP = :IDGRP_SPROPNABOR_GRP,'
      '    NAME_SPROPNABOR_GRP = :NAME_SPROPNABOR_GRP'
      'WHERE'
      '    ID_SPROPNABOR_GRP = :OLD_ID_SPROPNABOR_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROPNABOR_GRP'
      'WHERE'
      '        ID_SPROPNABOR_GRP = :OLD_ID_SPROPNABOR_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROPNABOR_GRP('
      '    ID_SPROPNABOR_GRP,'
      '    IDBASE_SPROPNABOR_GRP,'
      '    GID_SPROPNABOR_GRP,'
      '    IDGRP_SPROPNABOR_GRP,'
      '    NAME_SPROPNABOR_GRP'
      ')'
      'VALUES('
      '    :ID_SPROPNABOR_GRP,'
      '    :IDBASE_SPROPNABOR_GRP,'
      '    :GID_SPROPNABOR_GRP,'
      '    :IDGRP_SPROPNABOR_GRP,'
      '    :NAME_SPROPNABOR_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  spropnabor_grp'
      'where(  spropnabor_grp.id_spropnabor_grp=:PARAM_ID'
      
        '     ) and (     SPROPNABOR_GRP.ID_SPROPNABOR_GRP = :OLD_ID_SPRO' +
        'PNABOR_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  spropnabor_grp'
      'where spropnabor_grp.id_spropnabor_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROPNABOR_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SPROPNABOR_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROPNABOR_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR_GRP'
    end
    object ElementIDBASE_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR_GRP'
    end
    object ElementGID_SPROPNABOR_GRP: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR_GRP'
      Size = 10
    end
    object ElementIDGRP_SPROPNABOR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROPNABOR_GRP'
    end
    object ElementNAME_SPROPNABOR_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR_GRP'
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
