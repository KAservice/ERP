object DMSprCustomerKlient: TDMSprCustomerKlient
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_KLIENT'
      'SET '
      '    IDBASE_CUST_KLIENT = :IDBASE_CUST_KLIENT,'
      '    GID_CUST_KLIENT = :GID_CUST_KLIENT,'
      '    IDACCOUNT_CUST_KLIENT = :IDACCOUNT_CUST_KLIENT,'
      '    IDKLIENT_CUST_KLIENT = :IDKLIENT_CUST_KLIENT'
      'WHERE'
      '    ID_CUST_KLIENT = :OLD_ID_CUST_KLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_KLIENT'
      'WHERE'
      '        ID_CUST_KLIENT = :OLD_ID_CUST_KLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_KLIENT('
      '    ID_CUST_KLIENT,'
      '    IDBASE_CUST_KLIENT,'
      '    GID_CUST_KLIENT,'
      '    IDACCOUNT_CUST_KLIENT,'
      '    IDKLIENT_CUST_KLIENT'
      ')'
      'VALUES('
      '    :ID_CUST_KLIENT,'
      '    :IDBASE_CUST_KLIENT,'
      '    :GID_CUST_KLIENT,'
      '    :IDACCOUNT_CUST_KLIENT,'
      '    :IDKLIENT_CUST_KLIENT'
      ')')
    RefreshSQL.Strings = (
      'select cust_klient.*,'
      '    sklient.nameklient'
      'from cust_klient'
      
        'left outer join sklient on sklient.idklient=cust_klient.idklient' +
        '_cust_klient'
      'where(  cust_klient.idaccount_cust_klient=:PARAM_IDACCOUNT'
      
        '     ) and (     CUST_KLIENT.ID_CUST_KLIENT = :OLD_ID_CUST_KLIEN' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select cust_klient.*,'
      '    sklient.nameklient'
      'from cust_klient'
      
        'left outer join sklient on sklient.idklient=cust_klient.idklient' +
        '_cust_klient'
      'where cust_klient.idaccount_cust_klient=:PARAM_IDACCOUNT'
      'order by sklient.nameklient')
    AutoUpdateOptions.UpdateTableName = 'CUST_KLIENT'
    AutoUpdateOptions.KeyFields = 'ID_CUST_KLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_KLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'ID_CUST_KLIENT'
    end
    object TableIDBASE_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_KLIENT'
    end
    object TableGID_CUST_KLIENT: TFIBWideStringField
      FieldName = 'GID_CUST_KLIENT'
      Size = 10
    end
    object TableIDACCOUNT_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_KLIENT'
    end
    object TableIDKLIENT_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDKLIENT_CUST_KLIENT'
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_KLIENT'
      'SET '
      '    IDBASE_CUST_KLIENT = :IDBASE_CUST_KLIENT,'
      '    GID_CUST_KLIENT = :GID_CUST_KLIENT,'
      '    IDACCOUNT_CUST_KLIENT = :IDACCOUNT_CUST_KLIENT,'
      '    IDKLIENT_CUST_KLIENT = :IDKLIENT_CUST_KLIENT'
      'WHERE'
      '    ID_CUST_KLIENT = :OLD_ID_CUST_KLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_KLIENT'
      'WHERE'
      '        ID_CUST_KLIENT = :OLD_ID_CUST_KLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_KLIENT('
      '    ID_CUST_KLIENT,'
      '    IDBASE_CUST_KLIENT,'
      '    GID_CUST_KLIENT,'
      '    IDACCOUNT_CUST_KLIENT,'
      '    IDKLIENT_CUST_KLIENT'
      ')'
      'VALUES('
      '    :ID_CUST_KLIENT,'
      '    :IDBASE_CUST_KLIENT,'
      '    :GID_CUST_KLIENT,'
      '    :IDACCOUNT_CUST_KLIENT,'
      '    :IDKLIENT_CUST_KLIENT'
      ')')
    RefreshSQL.Strings = (
      'select cust_klient.*,'
      '    sklient.nameklient'
      'from cust_klient'
      
        'left outer join sklient on sklient.idklient = cust_klient.idklie' +
        'nt_cust_klient'
      'where(  cust_klient.id_cust_klient=:PARAM_ID'
      
        '     ) and (     CUST_KLIENT.ID_CUST_KLIENT = :OLD_ID_CUST_KLIEN' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select cust_klient.*,'
      '    sklient.nameklient'
      'from cust_klient'
      
        'left outer join sklient on sklient.idklient = cust_klient.idklie' +
        'nt_cust_klient'
      'where cust_klient.id_cust_klient=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_KLIENT'
    AutoUpdateOptions.KeyFields = 'ID_CUST_KLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_KLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'ID_CUST_KLIENT'
    end
    object ElementIDBASE_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_KLIENT'
    end
    object ElementGID_CUST_KLIENT: TFIBWideStringField
      FieldName = 'GID_CUST_KLIENT'
      Size = 10
    end
    object ElementIDACCOUNT_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_KLIENT'
    end
    object ElementIDKLIENT_CUST_KLIENT: TFIBLargeIntField
      FieldName = 'IDKLIENT_CUST_KLIENT'
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
  end
end
