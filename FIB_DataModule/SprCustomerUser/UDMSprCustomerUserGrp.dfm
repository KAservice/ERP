object DMSprCustomerUserGrp: TDMSprCustomerUserGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 275
  Width = 462
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
      'select *'
      'from '
      '  cust_user_grp'
      'where cust_user_grp.idaccount_cust_user_grp=:PARAM_IDACCOUNT'
      'order by  cust_user_grp.idgrp_cust_user_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_USER_GRP'
    end
    object TableIDBASE_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_USER_GRP'
    end
    object TableGID_CUST_USER_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_USER_GRP'
      Size = 10
    end
    object TableIDGRP_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_USER_GRP'
    end
    object TableIDACCOUNT_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_USER_GRP'
    end
    object TableNAME_CUST_USER_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_USER_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_USER_GRP'
      'SET '
      '    IDBASE_CUST_USER_GRP = :IDBASE_CUST_USER_GRP,'
      '    GID_CUST_USER_GRP = :GID_CUST_USER_GRP,'
      '    IDGRP_CUST_USER_GRP = :IDGRP_CUST_USER_GRP,'
      '    IDACCOUNT_CUST_USER_GRP = :IDACCOUNT_CUST_USER_GRP,'
      '    NAME_CUST_USER_GRP = :NAME_CUST_USER_GRP'
      'WHERE'
      '    ID_CUST_USER_GRP = :OLD_ID_CUST_USER_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_USER_GRP'
      'WHERE'
      '        ID_CUST_USER_GRP = :OLD_ID_CUST_USER_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_USER_GRP('
      '    ID_CUST_USER_GRP,'
      '    IDBASE_CUST_USER_GRP,'
      '    GID_CUST_USER_GRP,'
      '    IDGRP_CUST_USER_GRP,'
      '    IDACCOUNT_CUST_USER_GRP,'
      '    NAME_CUST_USER_GRP'
      ')'
      'VALUES('
      '    :ID_CUST_USER_GRP,'
      '    :IDBASE_CUST_USER_GRP,'
      '    :GID_CUST_USER_GRP,'
      '    :IDGRP_CUST_USER_GRP,'
      '    :IDACCOUNT_CUST_USER_GRP,'
      '    :NAME_CUST_USER_GRP'
      ')')
    RefreshSQL.Strings = (
      
        'select * from cust_user_grp where(  cust_user_grp.id_cust_user_g' +
        'rp=:ID'
      
        '     ) and (     CUST_USER_GRP.ID_CUST_USER_GRP = :OLD_ID_CUST_U' +
        'SER_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select * from cust_user_grp where cust_user_grp.id_cust_user_grp' +
        '=:ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_USER_GRP'
    AutoUpdateOptions.KeyFields = 'ID_CUST_USER_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_USER_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_USER_GRP'
    end
    object ElementIDBASE_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_USER_GRP'
    end
    object ElementGID_CUST_USER_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_USER_GRP'
      Size = 10
    end
    object ElementIDGRP_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_USER_GRP'
    end
    object ElementIDACCOUNT_CUST_USER_GRP: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_USER_GRP'
    end
    object ElementNAME_CUST_USER_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_USER_GRP'
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
end
