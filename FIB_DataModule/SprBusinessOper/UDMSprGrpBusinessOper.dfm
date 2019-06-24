object DMSprGrpBusinessOper: TDMSprGrpBusinessOper
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
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
      '  sbusiness_oper_grp'
      'order by sbusiness_oper_grp.idgrp_sbusiness_oper_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'ID_SBUSINESS_OPER_GRP'
    end
    object TableGID_SBUSINESS_OPER_GRP: TFIBWideStringField
      FieldName = 'GID_SBUSINESS_OPER_GRP'
      Size = 10
    end
    object TableIDBASE_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SBUSINESS_OPER_GRP'
    end
    object TableIDGRP_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SBUSINESS_OPER_GRP'
    end
    object TableNAME_SBUSINESS_OPER_GRP: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SBUSINESS_OPER_GRP'
      'SET '
      '    GID_SBUSINESS_OPER_GRP = :GID_SBUSINESS_OPER_GRP,'
      '    IDBASE_SBUSINESS_OPER_GRP = :IDBASE_SBUSINESS_OPER_GRP,'
      '    IDGRP_SBUSINESS_OPER_GRP = :IDGRP_SBUSINESS_OPER_GRP,'
      '    NAME_SBUSINESS_OPER_GRP = :NAME_SBUSINESS_OPER_GRP'
      'WHERE'
      '    ID_SBUSINESS_OPER_GRP = :OLD_ID_SBUSINESS_OPER_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBUSINESS_OPER_GRP'
      'WHERE'
      '        ID_SBUSINESS_OPER_GRP = :OLD_ID_SBUSINESS_OPER_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBUSINESS_OPER_GRP('
      '    ID_SBUSINESS_OPER_GRP,'
      '    GID_SBUSINESS_OPER_GRP,'
      '    IDBASE_SBUSINESS_OPER_GRP,'
      '    IDGRP_SBUSINESS_OPER_GRP,'
      '    NAME_SBUSINESS_OPER_GRP'
      ')'
      'VALUES('
      '    :ID_SBUSINESS_OPER_GRP,'
      '    :GID_SBUSINESS_OPER_GRP,'
      '    :IDBASE_SBUSINESS_OPER_GRP,'
      '    :IDGRP_SBUSINESS_OPER_GRP,'
      '    :NAME_SBUSINESS_OPER_GRP'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sbusiness_oper_grp'
      'where(  sbusiness_oper_grp.id_sbusiness_oper_grp=:PARAM_ID'
      
        '     ) and (     SBUSINESS_OPER_GRP.ID_SBUSINESS_OPER_GRP = :OLD' +
        '_ID_SBUSINESS_OPER_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sbusiness_oper_grp'
      'where sbusiness_oper_grp.id_sbusiness_oper_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SBUSINESS_OPER_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SBUSINESS_OPER_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SBUSINESS_OPER_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'ID_SBUSINESS_OPER_GRP'
    end
    object ElementGID_SBUSINESS_OPER_GRP: TFIBWideStringField
      FieldName = 'GID_SBUSINESS_OPER_GRP'
      Size = 10
    end
    object ElementIDBASE_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SBUSINESS_OPER_GRP'
    end
    object ElementIDGRP_SBUSINESS_OPER_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SBUSINESS_OPER_GRP'
    end
    object ElementNAME_SBUSINESS_OPER_GRP: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER_GRP'
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
    Left = 288
    Top = 56
    qoStartTransaction = True
  end
end
