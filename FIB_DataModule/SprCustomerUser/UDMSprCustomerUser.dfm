object DMSprCustomerUser: TDMSprCustomerUser
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 294
  Width = 518
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_USER'
      'SET '
      '    IDBASE_CUST_USER = :IDBASE_CUST_USER,'
      '    GID_CUST_USER = :GID_CUST_USER,'
      '    IDACCOUNT_CUST_USER = :IDACCOUNT_CUST_USER,'
      '    IDGRP_CUST_USER = :IDGRP_CUST_USER,'
      '    NAME_CUST_USER = :NAME_CUST_USER,'
      '    LOGIN_CUST_USER = :LOGIN_CUST_USER,'
      '    PASSWORD_CUST_USER = :PASSWORD_CUST_USER'
      'WHERE'
      '    ID_CUST_USER = :OLD_ID_CUST_USER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_USER'
      'WHERE'
      '        ID_CUST_USER = :OLD_ID_CUST_USER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_USER('
      '    ID_CUST_USER,'
      '    IDBASE_CUST_USER,'
      '    GID_CUST_USER,'
      '    IDACCOUNT_CUST_USER,'
      '    IDGRP_CUST_USER,'
      '    NAME_CUST_USER,'
      '    LOGIN_CUST_USER,'
      '    PASSWORD_CUST_USER'
      ')'
      'VALUES('
      '    :ID_CUST_USER,'
      '    :IDBASE_CUST_USER,'
      '    :GID_CUST_USER,'
      '    :IDACCOUNT_CUST_USER,'
      '    :IDGRP_CUST_USER,'
      '    :NAME_CUST_USER,'
      '    :LOGIN_CUST_USER,'
      '    :PASSWORD_CUST_USER'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from cust_user'
      'where(  cust_user.id_cust_user=:PARAM_ID'
      '     ) and (     CUST_USER.ID_CUST_USER = :OLD_ID_CUST_USER'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select *'
      'from cust_user'
      'where cust_user.id_cust_user=:PARAM_ID'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'CUST_USER'
    AutoUpdateOptions.KeyFields = 'ID_CUST_USER'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_USER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 72
    poUseLargeIntField = True
    object ElementID_CUST_USER: TFIBLargeIntField
      FieldName = 'ID_CUST_USER'
    end
    object ElementIDBASE_CUST_USER: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_USER'
    end
    object ElementGID_CUST_USER: TFIBWideStringField
      FieldName = 'GID_CUST_USER'
      Size = 10
    end
    object ElementIDACCOUNT_CUST_USER: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_USER'
    end
    object ElementIDGRP_CUST_USER: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_USER'
    end
    object ElementNAME_CUST_USER: TFIBWideStringField
      FieldName = 'NAME_CUST_USER'
      Size = 200
    end
    object ElementLOGIN_CUST_USER: TFIBWideStringField
      FieldName = 'LOGIN_CUST_USER'
      Size = 40
    end
    object ElementPASSWORD_CUST_USER: TFIBWideStringField
      FieldName = 'PASSWORD_CUST_USER'
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 152
    Top = 144
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'concurrency')
    TPBMode = tpbDefault
    Left = 232
    Top = 144
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE CUST_USER'
      'SET '
      '    IDBASE_CUST_USER = :IDBASE_CUST_USER,'
      '    GID_CUST_USER = :GID_CUST_USER,'
      '    IDACCOUNT_CUST_USER = :IDACCOUNT_CUST_USER,'
      '    IDGRP_CUST_USER = :IDGRP_CUST_USER,'
      '    NAME_CUST_USER = :NAME_CUST_USER,'
      '    LOGIN_CUST_USER = :LOGIN_CUST_USER,'
      '    PASSWORD_CUST_USER = :PASSWORD_CUST_USER'
      'WHERE'
      '    ID_CUST_USER = :OLD_ID_CUST_USER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_USER'
      'WHERE'
      '        ID_CUST_USER = :OLD_ID_CUST_USER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_USER('
      '    ID_CUST_USER,'
      '    IDBASE_CUST_USER,'
      '    GID_CUST_USER,'
      '    IDACCOUNT_CUST_USER,'
      '    IDGRP_CUST_USER,'
      '    NAME_CUST_USER,'
      '    LOGIN_CUST_USER,'
      '    PASSWORD_CUST_USER'
      ')'
      'VALUES('
      '    :ID_CUST_USER,'
      '    :IDBASE_CUST_USER,'
      '    :GID_CUST_USER,'
      '    :IDACCOUNT_CUST_USER,'
      '    :IDGRP_CUST_USER,'
      '    :NAME_CUST_USER,'
      '    :LOGIN_CUST_USER,'
      '    :PASSWORD_CUST_USER'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from cust_user'
      'where(  cust_user.idaccount_cust_user=:PARAM_IDACCOUNT'
      '        and cust_user.idgrp_cust_user=:PARAM_IDGRP'
      '     ) and (     CUST_USER.ID_CUST_USER = :OLD_ID_CUST_USER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from cust_user'
      'where cust_user.idaccount_cust_user=:PARAM_IDACCOUNT'
      '        and cust_user.idgrp_cust_user=:PARAM_IDGRP'
      'ORDER BY cust_user.name_cust_user')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_CUST_USER: TFIBLargeIntField
      FieldName = 'ID_CUST_USER'
    end
    object TableIDBASE_CUST_USER: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_USER'
    end
    object TableGID_CUST_USER: TFIBWideStringField
      FieldName = 'GID_CUST_USER'
      Size = 10
    end
    object TableIDACCOUNT_CUST_USER: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_USER'
    end
    object TableIDGRP_CUST_USER: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_USER'
    end
    object TableNAME_CUST_USER: TFIBWideStringField
      FieldName = 'NAME_CUST_USER'
      Size = 200
    end
    object TableLOGIN_CUST_USER: TFIBWideStringField
      FieldName = 'LOGIN_CUST_USER'
      Size = 40
    end
    object TablePASSWORD_CUST_USER: TFIBWideStringField
      FieldName = 'PASSWORD_CUST_USER'
    end
  end
  object pFIBQ: TpFIBQuery
    Left = 232
    Top = 16
    qoStartTransaction = True
  end
end
