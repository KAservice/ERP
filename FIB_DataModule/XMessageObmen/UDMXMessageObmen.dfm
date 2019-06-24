object DMXMessageObmen: TDMXMessageObmen
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 238
  Width = 449
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from  XMESSAGE_OBMEN   '
      
        'left outer join SINFBASE_OBMEN on IDBASE_XMESSAGE_OBMEN= ID_SINF' +
        'BASE_OBMEN'
      
        'where POS_XMESSAGE_OBMEN between  :PARAM_DATE_NACH and :PARAM_DA' +
        'TE_CON'
      'ORDER BY POS_XMESSAGE_OBMEN'
      '')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 24
    object TableOUT_XMESSAGE_OBMEN: TFIBIntegerField
      FieldName = 'OUT_XMESSAGE_OBMEN'
    end
    object TableKOLERR_XMESSAGE_OBMEN: TFIBIntegerField
      FieldName = 'KOLERR_XMESSAGE_OBMEN'
    end
    object TablePOS_XMESSAGE_OBMEN: TFIBDateTimeField
      FieldName = 'POS_XMESSAGE_OBMEN'
      DisplayFormat = 'c'
    end
    object TableGID_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object TableNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 50
      EmptyStrToNull = True
    end
    object TableINPATCH_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'INPATCH_SINFBASE_OBMEN'
      Size = 50
      EmptyStrToNull = True
    end
    object TableOUTPATCH_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'OUTPATCH_SINFBASE_OBMEN'
      Size = 50
      EmptyStrToNull = True
    end
    object TablePREFIKS_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'PREFIKS_SINFBASE_OBMEN'
      Size = 2
      EmptyStrToNull = True
    end
    object TablePREFDOC_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'PREFDOC_SINFBASE_OBMEN'
      Size = 50
      EmptyStrToNull = True
    end
    object TableALLDOC_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'ALLDOC_SINFBASE_OBMEN'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableOUTNAC_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_SINFBASE_OBMEN'
    end
    object TableOUTZPRICE_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_SINFBASE_OBMEN'
    end
    object TableGID_XMESSAGE_OBMEN: TFIBStringField
      FieldName = 'GID_XMESSAGE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object TableID_XMESSAGE_OBMEN: TFIBBCDField
      FieldName = 'ID_XMESSAGE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object TableIDBASE_XMESSAGE_OBMEN: TFIBIntegerField
      FieldName = 'IDBASE_XMESSAGE_OBMEN'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XMESSAGE_OBMEN'
      'SET '
      '    GID_XMESSAGE_OBMEN = :GID_XMESSAGE_OBMEN,'
      '    OUT_XMESSAGE_OBMEN = :OUT_XMESSAGE_OBMEN,'
      '    KOLERR_XMESSAGE_OBMEN = :KOLERR_XMESSAGE_OBMEN,'
      '    IDBASE_XMESSAGE_OBMEN = :IDBASE_XMESSAGE_OBMEN,'
      '    POS_XMESSAGE_OBMEN = :POS_XMESSAGE_OBMEN'
      'WHERE'
      '    ID_XMESSAGE_OBMEN = :OLD_ID_XMESSAGE_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XMESSAGE_OBMEN'
      'WHERE'
      '        ID_XMESSAGE_OBMEN = :OLD_ID_XMESSAGE_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XMESSAGE_OBMEN('
      '    ID_XMESSAGE_OBMEN,'
      '    GID_XMESSAGE_OBMEN,'
      '    OUT_XMESSAGE_OBMEN,'
      '    KOLERR_XMESSAGE_OBMEN,'
      '    IDBASE_XMESSAGE_OBMEN,'
      '    POS_XMESSAGE_OBMEN'
      ')'
      'VALUES('
      '    :ID_XMESSAGE_OBMEN,'
      '    :GID_XMESSAGE_OBMEN,'
      '    :OUT_XMESSAGE_OBMEN,'
      '    :KOLERR_XMESSAGE_OBMEN,'
      '    :IDBASE_XMESSAGE_OBMEN,'
      '    :POS_XMESSAGE_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  XMESSAGE_OBMEN '
      'where(  ID_XMESSAGE_OBMEN=:PARAM_ID'
      
        '     ) and (     XMESSAGE_OBMEN.ID_XMESSAGE_OBMEN = :OLD_ID_XMES' +
        'SAGE_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  XMESSAGE_OBMEN '
      'where ID_XMESSAGE_OBMEN=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'XMESSAGE_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_XMESSAGE_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_XMESSAGE_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = ElementCalcFields
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 80
    object ElementOUT_XMESSAGE_OBMEN: TFIBIntegerField
      FieldName = 'OUT_XMESSAGE_OBMEN'
    end
    object ElementKOLERR_XMESSAGE_OBMEN: TFIBIntegerField
      FieldName = 'KOLERR_XMESSAGE_OBMEN'
    end
    object ElementPOS_XMESSAGE_OBMEN: TFIBDateTimeField
      FieldName = 'POS_XMESSAGE_OBMEN'
    end
    object ElementGID_XMESSAGE_OBMEN: TFIBStringField
      FieldName = 'GID_XMESSAGE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementID_XMESSAGE_OBMEN: TFIBBCDField
      FieldName = 'ID_XMESSAGE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_XMESSAGE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XMESSAGE_OBMEN'
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
    Left = 240
    Top = 24
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
    Left = 240
    Top = 80
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 232
    Top = 136
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 328
    Top = 104
    qoStartTransaction = True
  end
end
