object DMSprObmenTypePrice: TDMSprObmenTypePrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 142
  Width = 287
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE STYPEPRICE_OBMEN'
      'SET '
      '    GID_STYPEPRICE_OBMEN = :GID_STYPEPRICE_OBMEN,'
      '    IDBASE_STYPEPRICE_OBMEN = :IDBASE_STYPEPRICE_OBMEN,'
      '    IDTPRICE_STYPEPRICE_OBMEN = :IDTPRICE_STYPEPRICE_OBMEN'
      'WHERE'
      '    ID_STYPEPRICE_OBMEN = :OLD_ID_STYPEPRICE_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STYPEPRICE_OBMEN'
      'WHERE'
      '        ID_STYPEPRICE_OBMEN = :OLD_ID_STYPEPRICE_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STYPEPRICE_OBMEN('
      '    ID_STYPEPRICE_OBMEN,'
      '    GID_STYPEPRICE_OBMEN,'
      '    IDBASE_STYPEPRICE_OBMEN,'
      '    IDTPRICE_STYPEPRICE_OBMEN'
      ')'
      'VALUES('
      '    :ID_STYPEPRICE_OBMEN,'
      '    :GID_STYPEPRICE_OBMEN,'
      '    :IDBASE_STYPEPRICE_OBMEN,'
      '    :IDTPRICE_STYPEPRICE_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select  STYPEPRICE_OBMEN.*,  NAME_TPRICE'
      'from STYPEPRICE_OBMEN'
      'left outer join STPRICE on  ID_TPRICE=IDTPRICE_STYPEPRICE_OBMEN '
      'where(  IDBASE_STYPEPRICE_OBMEN=:PARAM_IDBASE'
      
        '     ) and (     STYPEPRICE_OBMEN.ID_STYPEPRICE_OBMEN = :OLD_ID_' +
        'STYPEPRICE_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  STYPEPRICE_OBMEN.*,  NAME_TPRICE'
      'from STYPEPRICE_OBMEN'
      'left outer join STPRICE on  ID_TPRICE=IDTPRICE_STYPEPRICE_OBMEN '
      'where IDBASE_STYPEPRICE_OBMEN=:PARAM_IDBASE')
    AutoUpdateOptions.UpdateTableName = 'STYPEPRICE_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_STYPEPRICE_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPEPRICE_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 120
    Top = 16
    object TableNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'ID_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE_STYPEPRICE_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_STYPEPRICE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableGID_STYPEPRICE_OBMEN: TFIBStringField
      FieldName = 'GID_STYPEPRICE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 208
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 208
    Top = 72
  end
end
