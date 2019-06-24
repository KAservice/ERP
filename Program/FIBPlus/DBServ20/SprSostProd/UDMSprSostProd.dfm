object DMSprSostProd: TDMSprSostProd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 144
  Width = 326
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSPROD'
      'SET '
      '    IDNOMREST_SPROD = :IDNOMREST_SPROD,'
      '    NKOL_SPROD = :NKOL_SPROD,'
      '    BKOL_SPROD = :BKOL_SPROD,'
      '    KFPRICE_SPROD = :KFPRICE_SPROD,'
      '    IDKOMPL_SPROD = :IDKOMPL_SPROD,'
      '    SPIS_SPROD = :SPIS_SPROD,'
      '    IDED_SPROD = :IDED_SPROD,'
      '    KF_SPROD = :KF_SPROD,'
      '    GID_SSPROD = :GID_SSPROD'
      'WHERE'
      '    ID_SPROD = :OLD_ID_SPROD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSPROD'
      'WHERE'
      '        ID_SPROD = :OLD_ID_SPROD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSPROD('
      '    ID_SPROD,'
      '    IDNOMREST_SPROD,'
      '    NKOL_SPROD,'
      '    BKOL_SPROD,'
      '    KFPRICE_SPROD,'
      '    IDKOMPL_SPROD,'
      '    SPIS_SPROD,'
      '    IDED_SPROD,'
      '    KF_SPROD,'
      '    GID_SSPROD'
      ')'
      'VALUES('
      '    :ID_SPROD,'
      '    :IDNOMREST_SPROD,'
      '    :NKOL_SPROD,'
      '    :BKOL_SPROD,'
      '    :KFPRICE_SPROD,'
      '    :IDKOMPL_SPROD,'
      '    :SPIS_SPROD,'
      '    :IDED_SPROD,'
      '    :KF_SPROD,'
      '    :GID_SSPROD'
      ')')
    RefreshSQL.Strings = (
      
        'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  VALUE_SS' +
        'EZKF_SPROD'
      'from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SED on IDED_SPROD=IDED'
      ''
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      'where(  IDNOMREST_SPROD=:PARAM_IDNOMREST'
      '     ) and (     SSPROD.ID_SPROD = :OLD_ID_SPROD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  VALUE_SS' +
        'EZKF_SPROD'
      'from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SED on IDED_SPROD=IDED'
      ''
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      'where IDNOMREST_SPROD=:PARAM_IDNOMREST')
    AutoUpdateOptions.UpdateTableName = 'SSPROD'
    AutoUpdateOptions.KeyFields = 'ID_SPROD'
    AutoUpdateOptions.GeneratorName = 'GEN_SSPROD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 120
    Top = 16
    object TableNKOL_SPROD: TFIBBCDField
      FieldName = 'NKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableBKOL_SPROD: TFIBBCDField
      FieldName = 'BKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableKFPRICE_SPROD: TFIBBCDField
      FieldName = 'KFPRICE_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableSPIS_SPROD: TFIBSmallIntField
      FieldName = 'SPIS_SPROD'
      OnGetText = TableSPIS_SPRODGetText
      OnSetText = TableSPIS_SPRODSetText
    end
    object TableKF_SPROD: TFIBBCDField
      FieldName = 'KF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object TableTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object TableNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object TableVALUE_SSEZKF: TFIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Size = 3
      RoundByScale = True
    end
    object TableVALUE_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNABASED: TFloatField
      FieldKind = fkCalculated
      FieldName = 'NABASED'
      Calculated = True
    end
    object TableNNABASED: TFloatField
      FieldKind = fkCalculated
      FieldName = 'NNABASED'
      Calculated = True
    end
    object TableSEZKF: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF'
      Calculated = True
    end
    object TableSEZKF_SPROD: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF_SPROD'
      Calculated = True
    end
    object TableID_SPROD: TFIBBCDField
      FieldName = 'ID_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMREST_SPROD: TFIBBCDField
      FieldName = 'IDNOMREST_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDKOMPL_SPROD: TFIBBCDField
      FieldName = 'IDKOMPL_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDED_SPROD: TFIBBCDField
      FieldName = 'IDED_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSPROD: TFIBStringField
      FieldName = 'GID_SSPROD'
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
    Left = 192
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
    Left = 192
    Top = 72
  end
end
