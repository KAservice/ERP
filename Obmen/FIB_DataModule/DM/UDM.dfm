object DM: TDM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 361
  Width = 462
  object Database: TpFIBDatabase
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=UTF8')
    DefaultTransaction = Transaction
    DefaultUpdateTransaction = Transaction
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 120
    Top = 24
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 120
    Top = 80
  end
  object TableTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from STYPEPRICE_OBMEN where IDBASE_STYPEPRICE_OBMEN=:PA' +
        'RAM_IDBASE')
    Transaction = Transaction
    Database = Database
    Left = 312
    Top = 72
    object TableTypePriceID_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'ID_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDBASE_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDTPRICE_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = Database
    Left = 312
    Top = 136
    qoStartTransaction = True
  end
  object TablesBase: TpFIBDataSet
    SelectSQL.Strings = (
      'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME,'
      ' RDB$RELATION_FIELDS.RDB$RELATION_NAME AS TABLE_NAME'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0  and'
      'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE='#39'DOMAIN_IDTABLE'#39'  '
      'ORDER BY TABLE_NAME')
    Transaction = Transaction
    Database = Database
    Left = 120
    Top = 136
  end
  object BaseForObmen: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XSETUP_OBMEN '
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE_FOR_OBMEN')
    Transaction = Transaction
    Database = Database
    Left = 312
    Top = 16
    object BaseForObmenID_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'ID_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDBASE_OBMEN_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDTISM_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDTISM_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDBASE_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDFIRST_DO_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDFIRST_DO_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object TableGenerators: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from    rdb$generators where (rdb$generators.rdb$system' +
        '_flag is null)'
      '        or (rdb$generators.rdb$system_flag=0)')
    Transaction = Transaction
    Database = Database
    Left = 112
    Top = 256
  end
  object QueryUpdate: TpFIBQuery
    Transaction = TrUpdate
    Database = Database
    Left = 312
    Top = 224
    qoStartTransaction = True
  end
  object TrUpdate: TpFIBTransaction
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 312
    Top = 280
  end
end
