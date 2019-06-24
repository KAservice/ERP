object DMRegAdvanceCustomer: TDMRegAdvanceCustomer
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 161
  Width = 250
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGADVCUST_DV'
      'SET '
      '    POS_RGADVCUST_DV = :POS_RGADVCUST_DV,'
      '    TDV_RGADVCUST_DV = :TDV_RGADVCUST_DV,'
      '    IDDOC_RGADVCUST_DV = :IDDOC_RGADVCUST_DV,'
      '    IDFIRM_RGADVCUST_DV = :IDFIRM_RGADVCUST_DV,'
      '    IDKLIENT_RGADVCUST_DV = :IDKLIENT_RGADVCUST_DV,'
      '    SUM_RGADVCUST_DV = :SUM_RGADVCUST_DV'
      'WHERE'
      '    ID_RGADVCUST_DV = :OLD_ID_RGADVCUST_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGADVCUST_DV'
      'WHERE'
      '        ID_RGADVCUST_DV = :OLD_ID_RGADVCUST_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGADVCUST_DV('
      '    ID_RGADVCUST_DV,'
      '    POS_RGADVCUST_DV,'
      '    TDV_RGADVCUST_DV,'
      '    IDDOC_RGADVCUST_DV,'
      '    IDFIRM_RGADVCUST_DV,'
      '    IDKLIENT_RGADVCUST_DV,'
      '    SUM_RGADVCUST_DV'
      ')'
      'VALUES('
      '    :ID_RGADVCUST_DV,'
      '    :POS_RGADVCUST_DV,'
      '    :TDV_RGADVCUST_DV,'
      '    :IDDOC_RGADVCUST_DV,'
      '    :IDFIRM_RGADVCUST_DV,'
      '    :IDKLIENT_RGADVCUST_DV,'
      '    :SUM_RGADVCUST_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGADVCUST_DV'
      'where(  IDDOC_RGADVCUST_DV=:IDDOC'
      
        '     ) and (     RGADVCUST_DV.ID_RGADVCUST_DV = :OLD_ID_RGADVCUS' +
        'T_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGADVCUST_DV'
      'where IDDOC_RGADVCUST_DV=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGADVCUST_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGADVCUST_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGADVCUST_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 48
    Top = 32
    object DvRegOstPOS_RGADVCUST_DV: TFIBDateTimeField
      FieldName = 'POS_RGADVCUST_DV'
    end
    object DvRegOstTDV_RGADVCUST_DV: TFIBIntegerField
      FieldName = 'TDV_RGADVCUST_DV'
    end
    object DvRegOstSUM_RGADVCUST_DV: TFIBBCDField
      FieldName = 'SUM_RGADVCUST_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_RGADVCUST_DV: TFIBBCDField
      FieldName = 'ID_RGADVCUST_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGADVCUST_DV: TFIBBCDField
      FieldName = 'IDDOC_RGADVCUST_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGADVCUST_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGADVCUST_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDKLIENT_RGADVCUST_DV: TFIBBCDField
      FieldName = 'IDKLIENT_RGADVCUST_DV'
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
    Left = 128
    Top = 32
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGADVCUST'
      'SET '
      '    IDFIRM_RGADVCUST = :IDFIRM_RGADVCUST,'
      '    IDKLIENT_RGADVCUST = :IDKLIENT_RGADVCUST,'
      '    SUM_RGADVCUST = :SUM_RGADVCUST'
      'WHERE'
      '    ID_RGADVCUST = :OLD_ID_RGADVCUST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGADVCUST'
      'WHERE'
      '        ID_RGADVCUST = :OLD_ID_RGADVCUST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGADVCUST('
      '    ID_RGADVCUST,'
      '    IDFIRM_RGADVCUST,'
      '    IDKLIENT_RGADVCUST,'
      '    SUM_RGADVCUST'
      ')'
      'VALUES('
      '    :ID_RGADVCUST,'
      '    :IDFIRM_RGADVCUST,'
      '    :IDKLIENT_RGADVCUST,'
      '    :SUM_RGADVCUST'
      ')')
    RefreshSQL.Strings = (
      'select * from RGADVCUST'
      'where( '
      'IDFIRM_RGADVCUST=:PARAM_IDFIRM  and'
      'IDKLIENT_RGADVCUST=:PARAM_IDKLIENT'
      '     ) and (     RGADVCUST.ID_RGADVCUST = :OLD_ID_RGADVCUST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from RGADVCUST'
      'where'
      'IDFIRM_RGADVCUST=:PARAM_IDFIRM  and'
      'IDKLIENT_RGADVCUST=:PARAM_IDKLIENT')
    AutoUpdateOptions.UpdateTableName = 'RGADVCUST'
    AutoUpdateOptions.KeyFields = 'ID_RGADVCUST'
    AutoUpdateOptions.GeneratorName = 'GEN_RGADVCUST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 48
    Top = 88
    object RegOstSUM_RGADVCUST: TFIBBCDField
      FieldName = 'SUM_RGADVCUST'
      Size = 2
      RoundByScale = True
    end
    object RegOstID_RGADVCUST: TFIBBCDField
      FieldName = 'ID_RGADVCUST'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_RGADVCUST: TFIBBCDField
      FieldName = 'IDFIRM_RGADVCUST'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDKLIENT_RGADVCUST: TFIBBCDField
      FieldName = 'IDKLIENT_RGADVCUST'
      Size = 0
      RoundByScale = True
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
    Left = 128
    Top = 88
  end
end
