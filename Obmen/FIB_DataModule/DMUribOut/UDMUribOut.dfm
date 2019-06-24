object DMUribOut: TDMUribOut
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 398
  Width = 391
  object Transaction: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 24
    Top = 16
  end
  object XSetupObmen: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XSETUP_OBMEN'
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE')
    Transaction = Transaction
    Database = DM.Database
    Left = 48
    Top = 136
    object XSetupObmenID_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'ID_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDBASE_OBMEN_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDTISM_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDTISM_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenALLDOC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'ALLDOC_XSETUP_OBMEN'
    end
    object XSetupObmenOUTNAC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_XSETUP_OBMEN'
    end
    object XSetupObmenOUTZPRICE_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_XSETUP_OBMEN'
    end
    object XSetupObmenNOEDIT_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'NOEDIT_XSETUP_OBMEN'
    end
  end
  object TableTypePriceForObmen: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from XTPRICE_FOR_OBMEN where IDBASE_OBMEN_XTPRICE_FOR_O' +
        'BMEN=:PARAM_IDBASE')
    Transaction = Transaction
    Database = DM.Database
    Left = 48
    Top = 192
    object TableTypePriceForObmenID_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object Price: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDTYPE_PRICE from SPRICE'
      'where ID_PRICE=:PARAM_ID')
    Transaction = Transaction
    Database = DM.Database
    Left = 176
    Top = 240
    object PriceIDTYPE_PRICE: TFIBBCDField
      FieldName = 'IDTYPE_PRICE'
      Size = 0
      RoundByScale = True
    end
  end
  object TableBaseForObmen: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from XBASE_FOR_OBMEN where IDBASE_OBMEN_XBASE_FOR_OBMEN' +
        '=:PARAM_IDBASE')
    Transaction = Transaction
    Database = DM.Database
    Left = 48
    Top = 248
    object TableBaseForObmenID_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableBaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBJECT_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object TableIsmFields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XTISM_FIELDS'
      'where IDXTISM_XTISM_FIELDS=:PARAM_IDXTISM')
    Transaction = Transaction
    Database = DM.Database
    Left = 200
    Top = 16
    object TableIsmFieldsID_XTISM_FIELDS: TFIBBCDField
      FieldName = 'ID_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object TableIsmFieldsIDXTISM_XTISM_FIELDS: TFIBBCDField
      FieldName = 'IDXTISM_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object TableIsmFieldsFIELD_NAME_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'FIELD_NAME_XTISM_FIELDS'
      Size = 40
    end
    object TableIsmFieldsOLD_VALUE_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'OLD_VALUE_XTISM_FIELDS'
      Size = 255
    end
    object TableIsmFieldsNEW_VALUE_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'NEW_VALUE_XTISM_FIELDS'
      Size = 255
    end
    object TableIsmFieldsTYPE_XTISM_FIELDS: TFIBSmallIntField
      FieldName = 'TYPE_XTISM_FIELDS'
    end
  end
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = DM.Database
    Left = 176
    Top = 168
    qoStartTransaction = True
  end
  object TrUpdate: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 320
    Top = 328
  end
  object KvitanSetOK: TpFIBQuery
    Transaction = TrUpdate
    Database = DM.Database
    SQL.Strings = (
      'update xdata_out set RESULT_XDATA_OUT=1'
      'where TYPE_XDATA_OUT=2 and IDBASE_XDATA_OUT=:PARAM_IDBASE')
    Left = 216
    Top = 328
    qoStartTransaction = True
  end
  object TableKvitan: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from XDATA_OUT'
      'left outer join XTISM on IDTISM_XDATA_OUT=ID_XTISM'
      'where  ID_XDATA_OUT>=:PARAM_IDFIRST_DATAOUT'
      'and IDBASE_XDATA_OUT=:PARAM_IDBASE')
    Transaction = Transaction
    Database = DM.Database
    Left = 288
    Top = 16
    object TableKvitanID_XDATA_OUT: TFIBBCDField
      FieldName = 'ID_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableKvitanIDTISM_XDATA_OUT: TFIBBCDField
      FieldName = 'IDTISM_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableKvitanIDBASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDBASE_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableKvitanTYPE_XDATA_OUT: TFIBSmallIntField
      FieldName = 'TYPE_XDATA_OUT'
    end
    object TableKvitanRESULT_XDATA_OUT: TFIBSmallIntField
      FieldName = 'RESULT_XDATA_OUT'
    end
    object TableKvitanIDEXT_DOUT_XDATA_OUT: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableKvitanIDEXT_BASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDEXT_BASE_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableKvitanIDEXT_DATAOUT_XTISM: TFIBBCDField
      FieldName = 'IDEXT_DATAOUT_XTISM'
      Size = 0
      RoundByScale = True
    end
  end
  object SetFirstId: TpFIBQuery
    Transaction = TrUpdate
    Database = DM.Database
    SQL.Strings = (
      'update XSETUP_OBMEN set IDFIRST_DO_XSETUP_OBMEN=:PARAM_IDFIRST'
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE')
    Left = 272
    Top = 328
    qoStartTransaction = True
  end
  object TableDataOut: TpFIBQuery
    Transaction = Transaction
    Database = DM.Database
    SQL.Strings = (
      'select * '
      'from XDATA_OUT'
      'left outer join XTISM on IDTISM_XDATA_OUT=ID_XTISM'
      'where  (RESULT_XDATA_OUT is null or RESULT_XDATA_OUT<>1) '
      'and IDBASE_XDATA_OUT=:PARAM_IDBASE')
    Left = 280
    Top = 88
    qoStartTransaction = True
  end
  object TableIsm: TpFIBQuery
    Transaction = Transaction
    Database = DM.Database
    SQL.Strings = (
      'select * from  XTISM where  ID_XTISM > :PARAM_IDMAX')
    Left = 120
    Top = 16
    qoStartTransaction = True
  end
end
