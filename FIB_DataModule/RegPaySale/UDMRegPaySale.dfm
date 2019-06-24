object DMRegPaySale: TDMRegPaySale
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 149
  Width = 248
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGPAYSALE_DV'
      'SET '
      '    POS_RGPAYSALE_DV = :POS_RGPAYSALE_DV,'
      '    IDDOC_RGPAYSALE_DV = :IDDOC_RGPAYSALE_DV,'
      '    TDV_RGPAYSALE_DV = :TDV_RGPAYSALE_DV,'
      '    IDFIRM_RGPAYSALE_DV = :IDFIRM_RGPAYSALE_DV,'
      '    IDKLIENT_RGPAYSALE_DV = :IDKLIENT_RGPAYSALE_DV,'
      '    IDDOG_RGPAYSALE_DV = :IDDOG_RGPAYSALE_DV,'
      '    IDDOCSALE_RGPAYSALE_DV = :IDDOCSALE_RGPAYSALE_DV,'
      '    DATE_RGPAYSALE_DV = :DATE_RGPAYSALE_DV,'
      '    SUM_RGPAYSALE_DV = :SUM_RGPAYSALE_DV'
      'WHERE'
      '    ID_RGPAYSALE_DV = :OLD_ID_RGPAYSALE_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGPAYSALE_DV'
      'WHERE'
      '        ID_RGPAYSALE_DV = :OLD_ID_RGPAYSALE_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGPAYSALE_DV('
      '    ID_RGPAYSALE_DV,'
      '    POS_RGPAYSALE_DV,'
      '    IDDOC_RGPAYSALE_DV,'
      '    TDV_RGPAYSALE_DV,'
      '    IDFIRM_RGPAYSALE_DV,'
      '    IDKLIENT_RGPAYSALE_DV,'
      '    IDDOG_RGPAYSALE_DV,'
      '    IDDOCSALE_RGPAYSALE_DV,'
      '    DATE_RGPAYSALE_DV,'
      '    SUM_RGPAYSALE_DV'
      ')'
      'VALUES('
      '    :ID_RGPAYSALE_DV,'
      '    :POS_RGPAYSALE_DV,'
      '    :IDDOC_RGPAYSALE_DV,'
      '    :TDV_RGPAYSALE_DV,'
      '    :IDFIRM_RGPAYSALE_DV,'
      '    :IDKLIENT_RGPAYSALE_DV,'
      '    :IDDOG_RGPAYSALE_DV,'
      '    :IDDOCSALE_RGPAYSALE_DV,'
      '    :DATE_RGPAYSALE_DV,'
      '    :SUM_RGPAYSALE_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGPAYSALE_DV'
      'where(  IDDOC_RGPAYSALE_DV=:IDDOC'
      
        '     ) and (     RGPAYSALE_DV.ID_RGPAYSALE_DV = :OLD_ID_RGPAYSAL' +
        'E_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGPAYSALE_DV'
      'where IDDOC_RGPAYSALE_DV=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGPAYSALE_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGPAYSALE_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGPAYSALE_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 24
    object DvRegOstPOS_RGPAYSALE_DV: TFIBDateTimeField
      FieldName = 'POS_RGPAYSALE_DV'
    end
    object DvRegOstTDV_RGPAYSALE_DV: TFIBIntegerField
      FieldName = 'TDV_RGPAYSALE_DV'
    end
    object DvRegOstDATE_RGPAYSALE_DV: TFIBDateField
      FieldName = 'DATE_RGPAYSALE_DV'
    end
    object DvRegOstSUM_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'SUM_RGPAYSALE_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'ID_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'IDDOC_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDKLIENT_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'IDKLIENT_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOG_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'IDDOG_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOCSALE_RGPAYSALE_DV: TFIBBCDField
      FieldName = 'IDDOCSALE_RGPAYSALE_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGPAYSALE'
      'SET '
      '    IDFIRM_RGPAYSALE = :IDFIRM_RGPAYSALE,'
      '    IDKLIENT_RGPAYSALE = :IDKLIENT_RGPAYSALE,'
      '    IDDOG_RGPAYSALE = :IDDOG_RGPAYSALE,'
      '    IDDOCSALE_RGPAYSALE = :IDDOCSALE_RGPAYSALE,'
      '    DATE_RGPAYSALE = :DATE_RGPAYSALE,'
      '    SUM_RGPAYSALE = :SUM_RGPAYSALE'
      'WHERE'
      '    ID_RGPAYSALE = :OLD_ID_RGPAYSALE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGPAYSALE'
      'WHERE'
      '        ID_RGPAYSALE = :OLD_ID_RGPAYSALE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGPAYSALE('
      '    ID_RGPAYSALE,'
      '    IDFIRM_RGPAYSALE,'
      '    IDKLIENT_RGPAYSALE,'
      '    IDDOG_RGPAYSALE,'
      '    IDDOCSALE_RGPAYSALE,'
      '    DATE_RGPAYSALE,'
      '    SUM_RGPAYSALE'
      ')'
      'VALUES('
      '    :ID_RGPAYSALE,'
      '    :IDFIRM_RGPAYSALE,'
      '    :IDKLIENT_RGPAYSALE,'
      '    :IDDOG_RGPAYSALE,'
      '    :IDDOCSALE_RGPAYSALE,'
      '    :DATE_RGPAYSALE,'
      '    :SUM_RGPAYSALE'
      ')')
    RefreshSQL.Strings = (
      'select * from RGPAYSALE'
      'where( '
      'IDFIRM_RGPAYSALE=:PARAM_IDFIRM  and'
      'IDKLIENT_RGPAYSALE=:PARAM_IDKLIENT  and'
      'IDDOG_RGPAYSALE=:PARAM_IDDOG and'
      'IDDOCSALE_RGPAYSALE=:PARAM_IDDOCSALE and'
      'DATE_RGPAYSALE=:PARAM_DATE'
      '     ) and (     RGPAYSALE.ID_RGPAYSALE = :OLD_ID_RGPAYSALE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from RGPAYSALE'
      'where'
      'IDFIRM_RGPAYSALE=:PARAM_IDFIRM  and'
      'IDKLIENT_RGPAYSALE=:PARAM_IDKLIENT  and'
      'IDDOG_RGPAYSALE=:PARAM_IDDOG and'
      'IDDOCSALE_RGPAYSALE=:PARAM_IDDOCSALE and'
      'DATE_RGPAYSALE=:PARAM_DATE')
    AutoUpdateOptions.UpdateTableName = 'RGPAYSALE'
    AutoUpdateOptions.KeyFields = 'ID_RGPAYSALE'
    AutoUpdateOptions.GeneratorName = 'GEN_RGPAYSALE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 72
    object RegOstDATE_RGPAYSALE: TFIBDateField
      FieldName = 'DATE_RGPAYSALE'
    end
    object RegOstSUM_RGPAYSALE: TFIBBCDField
      FieldName = 'SUM_RGPAYSALE'
      Size = 2
      RoundByScale = True
    end
    object RegOstID_RGPAYSALE: TFIBBCDField
      FieldName = 'ID_RGPAYSALE'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_RGPAYSALE: TFIBBCDField
      FieldName = 'IDFIRM_RGPAYSALE'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDKLIENT_RGPAYSALE: TFIBBCDField
      FieldName = 'IDKLIENT_RGPAYSALE'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDDOG_RGPAYSALE: TFIBBCDField
      FieldName = 'IDDOG_RGPAYSALE'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDDOCSALE_RGPAYSALE: TFIBBCDField
      FieldName = 'IDDOCSALE_RGPAYSALE'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 136
    Top = 24
  end
end
