object DMSprBusinessOper: TDMSprBusinessOper
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 327
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from sbusiness_oper'
      'where sbusiness_oper.idgrp_sbusiness_oper=:PARAM_IDGRP')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'ID_SBUSINESS_OPER'
    end
    object TableGID_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'GID_SBUSINESS_OPER'
      Size = 10
    end
    object TableIDBASE_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'IDBASE_SBUSINESS_OPER'
    end
    object TableNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object TableIDGRP_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'IDGRP_SBUSINESS_OPER'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SBUSINESS_OPER'
      'SET '
      '    GID_SBUSINESS_OPER = :GID_SBUSINESS_OPER,'
      '    IDBASE_SBUSINESS_OPER = :IDBASE_SBUSINESS_OPER,'
      '    NAME_SBUSINESS_OPER = :NAME_SBUSINESS_OPER,'
      '    IDGRP_SBUSINESS_OPER = :IDGRP_SBUSINESS_OPER'
      'WHERE'
      '    ID_SBUSINESS_OPER = :OLD_ID_SBUSINESS_OPER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBUSINESS_OPER'
      'WHERE'
      '        ID_SBUSINESS_OPER = :OLD_ID_SBUSINESS_OPER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBUSINESS_OPER('
      '    ID_SBUSINESS_OPER,'
      '    GID_SBUSINESS_OPER,'
      '    IDBASE_SBUSINESS_OPER,'
      '    NAME_SBUSINESS_OPER,'
      '    IDGRP_SBUSINESS_OPER'
      ')'
      'VALUES('
      '    :ID_SBUSINESS_OPER,'
      '    :GID_SBUSINESS_OPER,'
      '    :IDBASE_SBUSINESS_OPER,'
      '    :NAME_SBUSINESS_OPER,'
      '    :IDGRP_SBUSINESS_OPER'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sbusiness_oper'
      'where(  sbusiness_oper.id_sbusiness_oper=:PARAM_ID'
      
        '     ) and (     SBUSINESS_OPER.ID_SBUSINESS_OPER = :OLD_ID_SBUS' +
        'INESS_OPER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sbusiness_oper'
      'where sbusiness_oper.id_sbusiness_oper=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SBUSINESS_OPER'
    AutoUpdateOptions.KeyFields = 'ID_SBUSINESS_OPER'
    AutoUpdateOptions.GeneratorName = 'GEN_SBUSINESS_OPER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'ID_SBUSINESS_OPER'
    end
    object ElementGID_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'GID_SBUSINESS_OPER'
      Size = 10
    end
    object ElementIDBASE_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'IDBASE_SBUSINESS_OPER'
    end
    object ElementNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object ElementIDGRP_SBUSINESS_OPER: TFIBLargeIntField
      FieldName = 'IDGRP_SBUSINESS_OPER'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
end
