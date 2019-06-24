object DMSprCustomerAccount: TDMSprCustomerAccount
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 476
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
      'select cust_account.*,'
      '        suser.name_user,'
      '        suser.idgrp_user,'
      '        sgrpuser.name_sgrpuser'
      ''
      'from cust_account'
      
        'left outer join suser on suser.id_user=cust_account.iduser_cust_' +
        'account'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_use' +
        'r'
      'where cust_account.idgrp_cust_account=:PARAM_IDGRP')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'ID_CUST_ACCOUNT'
    end
    object TableIDBASE_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_ACCOUNT'
    end
    object TableGID_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'GID_CUST_ACCOUNT'
      Size = 10
    end
    object TableIDGRP_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_ACCOUNT'
    end
    object TableNAME_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'NAME_CUST_ACCOUNT'
      Size = 200
    end
    object TableDESCR_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'DESCR_CUST_ACCOUNT'
      Size = 200
    end
    object TableIDUSER_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDUSER_CUST_ACCOUNT'
    end
    object TablePASSWORD_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'PASSWORD_CUST_ACCOUNT'
    end
    object TableLOGIN_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'LOGIN_CUST_ACCOUNT'
      Size = 40
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 200
    end
    object TableIDGRP_USER: TFIBLargeIntField
      FieldName = 'IDGRP_USER'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_ACCOUNT'
      'SET '
      '    IDBASE_CUST_ACCOUNT = :IDBASE_CUST_ACCOUNT,'
      '    GID_CUST_ACCOUNT = :GID_CUST_ACCOUNT,'
      '    IDGRP_CUST_ACCOUNT = :IDGRP_CUST_ACCOUNT,'
      '    NAME_CUST_ACCOUNT = :NAME_CUST_ACCOUNT,'
      '    DESCR_CUST_ACCOUNT = :DESCR_CUST_ACCOUNT,'
      '    IDUSER_CUST_ACCOUNT = :IDUSER_CUST_ACCOUNT,'
      '    PASSWORD_CUST_ACCOUNT = :PASSWORD_CUST_ACCOUNT,'
      '    LOGIN_CUST_ACCOUNT = :LOGIN_CUST_ACCOUNT'
      'WHERE'
      '    ID_CUST_ACCOUNT = :OLD_ID_CUST_ACCOUNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_ACCOUNT'
      'WHERE'
      '        ID_CUST_ACCOUNT = :OLD_ID_CUST_ACCOUNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_ACCOUNT('
      '    ID_CUST_ACCOUNT,'
      '    IDBASE_CUST_ACCOUNT,'
      '    GID_CUST_ACCOUNT,'
      '    IDGRP_CUST_ACCOUNT,'
      '    NAME_CUST_ACCOUNT,'
      '    DESCR_CUST_ACCOUNT,'
      '    IDUSER_CUST_ACCOUNT,'
      '    PASSWORD_CUST_ACCOUNT,'
      '    LOGIN_CUST_ACCOUNT'
      ')'
      'VALUES('
      '    :ID_CUST_ACCOUNT,'
      '    :IDBASE_CUST_ACCOUNT,'
      '    :GID_CUST_ACCOUNT,'
      '    :IDGRP_CUST_ACCOUNT,'
      '    :NAME_CUST_ACCOUNT,'
      '    :DESCR_CUST_ACCOUNT,'
      '    :IDUSER_CUST_ACCOUNT,'
      '    :PASSWORD_CUST_ACCOUNT,'
      '    :LOGIN_CUST_ACCOUNT'
      ')')
    RefreshSQL.Strings = (
      'select cust_account.*,'
      '        suser.name_user,'
      '        suser.idgrp_user,'
      '        sgrpuser.name_sgrpuser'
      ''
      'from cust_account'
      
        'left outer join suser on suser.id_user=cust_account.iduser_cust_' +
        'account'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_use' +
        'r'
      'where(  cust_account.id_cust_account=:PARAM_ID'
      
        '     ) and (     CUST_ACCOUNT.ID_CUST_ACCOUNT = :OLD_ID_CUST_ACC' +
        'OUNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select cust_account.*,'
      '        suser.name_user,'
      '        suser.idgrp_user,'
      '        sgrpuser.name_sgrpuser'
      ''
      'from cust_account'
      
        'left outer join suser on suser.id_user=cust_account.iduser_cust_' +
        'account'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_use' +
        'r'
      'where cust_account.id_cust_account=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_ACCOUNT'
    AutoUpdateOptions.KeyFields = 'ID_CUST_ACCOUNT'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_ACCOUNT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'ID_CUST_ACCOUNT'
    end
    object ElementIDBASE_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_ACCOUNT'
    end
    object ElementGID_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'GID_CUST_ACCOUNT'
      Size = 10
    end
    object ElementIDGRP_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_ACCOUNT'
    end
    object ElementNAME_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'NAME_CUST_ACCOUNT'
      Size = 200
    end
    object ElementDESCR_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'DESCR_CUST_ACCOUNT'
      Size = 200
    end
    object ElementIDUSER_CUST_ACCOUNT: TFIBLargeIntField
      FieldName = 'IDUSER_CUST_ACCOUNT'
    end
    object ElementPASSWORD_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'PASSWORD_CUST_ACCOUNT'
    end
    object ElementLOGIN_CUST_ACCOUNT: TFIBWideStringField
      FieldName = 'LOGIN_CUST_ACCOUNT'
      Size = 40
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object ElementIDGRP_USER: TFIBLargeIntField
      FieldName = 'IDGRP_USER'
    end
    object ElementNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
