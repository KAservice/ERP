object HOT_DMSprPrOsnUslug_Dv: THOT_DMSprPrOsnUslug_Dv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  HOT_SNF.*, NAME_HOT_SOBJECT, NAME_HOT_SCATNOM'
      'from HOT_SNF'
      'left outer join HOT_SOBJECT on ID_HOT_SOBJECT=IDOB_HOT_SNF'
      'left outer join HOT_SCATNOM on ID_HOT_SCATNOM=IDCAT_HOT_SNF')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_HOT_SNF: TFIBStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 50
      EmptyStrToNull = True
    end
    object TableKOLM_HOT_SNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SNF'
    end
    object TablePOSIN_HOT_SNF: TFIBDateTimeField
      FieldName = 'POSIN_HOT_SNF'
      DisplayFormat = 'c'
    end
    object TablePOSOUT_HOT_SNF: TFIBDateTimeField
      FieldName = 'POSOUT_HOT_SNF'
      DisplayFormat = 'c'
    end
    object TableNAME_HOT_SOBJECT: TFIBStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 50
      EmptyStrToNull = True
    end
    object TableNAME_HOT_SCATNOM: TFIBStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object TableID_HOT_SNF: TFIBBCDField
      FieldName = 'ID_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDOB_HOT_SNF: TFIBBCDField
      FieldName = 'IDOB_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDCAT_HOT_SNF: TFIBBCDField
      FieldName = 'IDCAT_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SNF'
      'SET '
      '    GID_HOT_SNF = :GID_HOT_SNF,'
      '    NAME_HOT_SNF = :NAME_HOT_SNF,'
      '    IDOB_HOT_SNF = :IDOB_HOT_SNF,'
      '    IDCAT_HOT_SNF = :IDCAT_HOT_SNF,'
      '    KOLM_HOT_SNF = :KOLM_HOT_SNF,'
      '    POSIN_HOT_SNF = :POSIN_HOT_SNF,'
      '    POSOUT_HOT_SNF = :POSOUT_HOT_SNF'
      'WHERE'
      '    ID_HOT_SNF = :OLD_ID_HOT_SNF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SNF'
      'WHERE'
      '        ID_HOT_SNF = :OLD_ID_HOT_SNF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SNF('
      '    ID_HOT_SNF,'
      '    GID_HOT_SNF,'
      '    NAME_HOT_SNF,'
      '    IDOB_HOT_SNF,'
      '    IDCAT_HOT_SNF,'
      '    KOLM_HOT_SNF,'
      '    POSIN_HOT_SNF,'
      '    POSOUT_HOT_SNF'
      ')'
      'VALUES('
      '    :ID_HOT_SNF,'
      '    :GID_HOT_SNF,'
      '    :NAME_HOT_SNF,'
      '    :IDOB_HOT_SNF,'
      '    :IDCAT_HOT_SNF,'
      '    :KOLM_HOT_SNF,'
      '    :POSIN_HOT_SNF,'
      '    :POSOUT_HOT_SNF'
      ')')
    RefreshSQL.Strings = (
      'select  HOT_SNF.*, NAME_HOT_SOBJECT, NAME_HOT_SCATNOM'
      'from HOT_SNF'
      'left outer join HOT_SOBJECT on ID_HOT_SOBJECT=IDOB_HOT_SNF'
      'left outer join HOT_SCATNOM on ID_HOT_SCATNOM=IDCAT_HOT_SNF'
      'where(  ID_HOT_SNF=:PARAM_ID'
      '     ) and (     HOT_SNF.ID_HOT_SNF = :OLD_ID_HOT_SNF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  HOT_SNF.*, NAME_HOT_SOBJECT, NAME_HOT_SCATNOM'
      'from HOT_SNF'
      'left outer join HOT_SOBJECT on ID_HOT_SOBJECT=IDOB_HOT_SNF'
      'left outer join HOT_SCATNOM on ID_HOT_SCATNOM=IDCAT_HOT_SNF'
      'where ID_HOT_SNF=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SOBJECT'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SOBJECT'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SOBJECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 72
    object ElementNAME_HOT_SNF: TFIBStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementKOLM_HOT_SNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SNF'
    end
    object ElementPOSIN_HOT_SNF: TFIBDateTimeField
      FieldName = 'POSIN_HOT_SNF'
      DisplayFormat = 'c'
    end
    object ElementPOSOUT_HOT_SNF: TFIBDateTimeField
      FieldName = 'POSOUT_HOT_SNF'
      DisplayFormat = 'c'
    end
    object ElementNAME_HOT_SOBJECT: TFIBStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementNAME_HOT_SCATNOM: TFIBStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementID_HOT_SNF: TFIBBCDField
      FieldName = 'ID_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDOB_HOT_SNF: TFIBBCDField
      FieldName = 'IDOB_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCAT_HOT_SNF: TFIBBCDField
      FieldName = 'IDCAT_HOT_SNF'
      Size = 0
      RoundByScale = True
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
    Left = 264
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
    Left = 264
    Top = 72
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 160
    qoStartTransaction = True
  end
end
