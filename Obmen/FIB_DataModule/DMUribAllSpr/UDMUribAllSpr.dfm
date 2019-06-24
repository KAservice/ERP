object DMUribAllSpr: TDMUribAllSpr
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 225
  Width = 391
  object BaseForObmen: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XSETUP_OBMEN '
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE_FOR_OBMEN')
    Transaction = Transaction
    Database = DM.Database
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
    object BaseForObmenALLDOC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'ALLDOC_XSETUP_OBMEN'
    end
    object BaseForObmenOUTNAC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_XSETUP_OBMEN'
    end
    object BaseForObmenOUTZPRICE_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_XSETUP_OBMEN'
    end
    object BaseForObmenNOEDIT_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'NOEDIT_XSETUP_OBMEN'
    end
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
    Database = DM.Database
    Left = 88
    Top = 88
  end
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = DM.Database
    Left = 312
    Top = 168
    qoStartTransaction = True
  end
  object TableTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XTPRICE_FOR_OBMEN '
      'where IDBASE_OBMEN_XTPRICE_FOR_OBMEN=:PARAM_IDBASE')
    Transaction = Transaction
    Database = DM.Database
    Left = 312
    Top = 72
    object TableTypePriceID_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDBASE_OBMEN_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 88
    Top = 24
  end
  object FieldsTable: TpFIBDataSet
    SelectSQL.Strings = (
      'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME,'
      ' RDB$FIELD_TYPE AS FIELD_TYPE,'
      ' RDB$FIELD_SCALE AS FIELD_SCALE'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:TABLE_NAME')
    Transaction = Transaction
    Database = DM.Database
    Left = 88
    Top = 160
  end
end
