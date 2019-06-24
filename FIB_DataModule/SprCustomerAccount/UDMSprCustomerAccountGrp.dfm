object DMSprCustomerAccountGrp: TDMSprCustomerAccountGrp
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
      '  cust_account_grp'
      'order by cust_account_grp.idgrp_cust_account_grp')
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_ACCOUNT_GRP'
    end
    object TableIDBASE_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_ACCOUNT_GRP'
    end
    object TableGID_CUST_ACCOUNT_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_ACCOUNT_GRP'
      Size = 10
    end
    object TableIDGRP_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_ACCOUNT_GRP'
    end
    object TableNAME_CUST_ACCOUNT_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_ACCOUNT_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_ACCOUNT_GRP'
      'SET '
      '    IDBASE_CUST_ACCOUNT_GRP = :IDBASE_CUST_ACCOUNT_GRP,'
      '    GID_CUST_ACCOUNT_GRP = :GID_CUST_ACCOUNT_GRP,'
      '    IDGRP_CUST_ACCOUNT_GRP = :IDGRP_CUST_ACCOUNT_GRP,'
      '    NAME_CUST_ACCOUNT_GRP = :NAME_CUST_ACCOUNT_GRP'
      'WHERE'
      '    ID_CUST_ACCOUNT_GRP = :OLD_ID_CUST_ACCOUNT_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_ACCOUNT_GRP'
      'WHERE'
      '        ID_CUST_ACCOUNT_GRP = :OLD_ID_CUST_ACCOUNT_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_ACCOUNT_GRP('
      '    ID_CUST_ACCOUNT_GRP,'
      '    IDBASE_CUST_ACCOUNT_GRP,'
      '    GID_CUST_ACCOUNT_GRP,'
      '    IDGRP_CUST_ACCOUNT_GRP,'
      '    NAME_CUST_ACCOUNT_GRP'
      ')'
      'VALUES('
      '    :ID_CUST_ACCOUNT_GRP,'
      '    :IDBASE_CUST_ACCOUNT_GRP,'
      '    :GID_CUST_ACCOUNT_GRP,'
      '    :IDGRP_CUST_ACCOUNT_GRP,'
      '    :NAME_CUST_ACCOUNT_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  cust_account_grp'
      'where(  cust_account_grp.id_cust_account_grp=:PARAM_ID'
      
        '     ) and (     CUST_ACCOUNT_GRP.ID_CUST_ACCOUNT_GRP = :OLD_ID_' +
        'CUST_ACCOUNT_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  cust_account_grp'
      'where cust_account_grp.id_cust_account_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_ACCOUNT_GRP'
    AutoUpdateOptions.KeyFields = 'ID_CUST_ACCOUNT_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_ACCOUNT_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_ACCOUNT_GRP'
    end
    object ElementIDBASE_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_ACCOUNT_GRP'
    end
    object ElementGID_CUST_ACCOUNT_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_ACCOUNT_GRP'
      Size = 10
    end
    object ElementIDGRP_CUST_ACCOUNT_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_ACCOUNT_GRP'
    end
    object ElementNAME_CUST_ACCOUNT_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_ACCOUNT_GRP'
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
