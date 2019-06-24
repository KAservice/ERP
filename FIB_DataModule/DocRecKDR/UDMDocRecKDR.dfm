object DMDocRecKDR: TDMDocRecKDR
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 206
  Width = 365
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 40
    Top = 72
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 40
    Top = 16
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE GALLDOC'
      'SET '
      '    POSDOC = :POSDOC,'
      '    PRDOC = :PRDOC,'
      '    TDOC = :TDOC,'
      '    NUMDOC = :NUMDOC,'
      '    IDFIRMDOC = :IDFIRMDOC,'
      '    IDSKLDOC = :IDSKLDOC,'
      '    IDKLDOC = :IDKLDOC,'
      '    IDDOGDOC = :IDDOGDOC,'
      '    SUMDOC = :SUMDOC,'
      '    IDUSERDOC = :IDUSERDOC,'
      '    GID_DOC = :GID_DOC,'
      '    PREFIKSDOC = :PREFIKSDOC,'
      '    IDDOCOSNDOC = :IDDOCOSNDOC'
      'WHERE'
      '    IDDOC = :OLD_IDDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GALLDOC'
      'WHERE'
      '        IDDOC = :OLD_IDDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GALLDOC('
      '    IDDOC,'
      '    POSDOC,'
      '    PRDOC,'
      '    TDOC,'
      '    NUMDOC,'
      '    IDFIRMDOC,'
      '    IDSKLDOC,'
      '    IDKLDOC,'
      '    IDDOGDOC,'
      '    SUMDOC,'
      '    IDUSERDOC,'
      '    GID_DOC,'
      '    PREFIKSDOC,'
      '    IDDOCOSNDOC'
      ')'
      'VALUES('
      '    :IDDOC,'
      '    :POSDOC,'
      '    :PRDOC,'
      '    :TDOC,'
      '    :NUMDOC,'
      '    :IDFIRMDOC,'
      '    :IDSKLDOC,'
      '    :IDKLDOC,'
      '    :IDDOGDOC,'
      '    :SUMDOC,'
      '    :IDUSERDOC,'
      '    :GID_DOC,'
      '    :PREFIKSDOC,'
      '    :IDDOCOSNDOC'
      ')')
    RefreshSQL.Strings = (
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN= PREFIK' +
        'SDOC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'where(  IDDOC=:PARAM_ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN= PREFIK' +
        'SDOC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'where IDDOC=:PARAM_ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocAllNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 16
    object DocAllIDDOC: TFIBIntegerField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBStringField
      FieldName = 'TDOC'
      Size = 10
      EmptyStrToNull = True
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllIDFIRMDOC: TFIBIntegerField
      FieldName = 'IDFIRMDOC'
    end
    object DocAllIDSKLDOC: TFIBIntegerField
      FieldName = 'IDSKLDOC'
    end
    object DocAllIDKLDOC: TFIBIntegerField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBIntegerField
      FieldName = 'IDDOGDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBIntegerField
      FieldName = 'IDUSERDOC'
    end
    object DocAllGID_DOC: TFIBStringField
      FieldName = 'GID_DOC'
      Size = 10
      EmptyStrToNull = True
    end
    object DocAllPREFIKSDOC: TFIBStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
      EmptyStrToNull = True
    end
    object DocAllIDDOCOSNDOC: TFIBIntegerField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllFNAME_USER: TFIBStringField
      FieldName = 'FNAME_USER'
      Size = 30
      EmptyStrToNull = True
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      OnGetText = DocAllNAME_SINFBASE_OBMENGetText
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREC_KDR'
      'SET '
      '    GID_DREC_KDR = :GID_DREC_KDR,'
      '    IDDOC_DREC_KDR = :IDDOC_DREC_KDR,'
      '    OPERATION_DREC_KDR = :OPERATION_DREC_KDR,'
      '    DOHOD_DREC_KDR = :DOHOD_DREC_KDR,'
      '    RASHOD_DREC_KDR = :RASHOD_DREC_KDR'
      'WHERE'
      '    ID_DREC_KDR = :OLD_ID_DREC_KDR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREC_KDR'
      'WHERE'
      '        ID_DREC_KDR = :OLD_ID_DREC_KDR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREC_KDR('
      '    ID_DREC_KDR,'
      '    GID_DREC_KDR,'
      '    IDDOC_DREC_KDR,'
      '    OPERATION_DREC_KDR,'
      '    DOHOD_DREC_KDR,'
      '    RASHOD_DREC_KDR'
      ')'
      'VALUES('
      '    :ID_DREC_KDR,'
      '    :GID_DREC_KDR,'
      '    :IDDOC_DREC_KDR,'
      '    :OPERATION_DREC_KDR,'
      '    :DOHOD_DREC_KDR,'
      '    :RASHOD_DREC_KDR'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DREC_KDR'
      'where(  IDDOC_DREC_KDR=:PARAM_IDDOC'
      '     ) and (     DREC_KDR.ID_DREC_KDR = :OLD_ID_DREC_KDR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DREC_KDR'
      'where IDDOC_DREC_KDR=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DREC_KDR'
    AutoUpdateOptions.KeyFields = 'ID_DREC_KDR'
    AutoUpdateOptions.GeneratorName = 'GEN_DREC_KDR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 72
    object DocID_DREC_KDR: TFIBIntegerField
      FieldName = 'ID_DREC_KDR'
    end
    object DocGID_DREC_KDR: TFIBStringField
      FieldName = 'GID_DREC_KDR'
      Size = 10
      EmptyStrToNull = True
    end
    object DocIDDOC_DREC_KDR: TFIBIntegerField
      FieldName = 'IDDOC_DREC_KDR'
    end
    object DocOPERATION_DREC_KDR: TFIBStringField
      FieldName = 'OPERATION_DREC_KDR'
      Size = 100
      EmptyStrToNull = True
    end
    object DocDOHOD_DREC_KDR: TFIBBCDField
      FieldName = 'DOHOD_DREC_KDR'
      Size = 2
      RoundByScale = True
    end
    object DocRASHOD_DREC_KDR: TFIBBCDField
      FieldName = 'RASHOD_DREC_KDR'
      Size = 2
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
    Left = 232
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
    Left = 232
    Top = 72
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUMDOC) AS MAXNUMBER from  GALLDOC'
      'where TDOC='#39'REC_KDR'#39' and POSDOC>:PARAM_POS')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object Doc2: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE GALLDOC'
      'SET '
      '    PRDOC = :PRDOC'
      'WHERE'
      '    IDDOC = :OLD_IDDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GALLDOC'
      'WHERE'
      '        IDDOC = :OLD_IDDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GALLDOC('
      '    IDDOC,'
      '    PRDOC'
      ')'
      'VALUES('
      '    :IDDOC,'
      '    :PRDOC'
      ')')
    RefreshSQL.Strings = (
      'select IDDOC,PRDOC from GALLDOC WHERE(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select IDDOC,PRDOC from GALLDOC WHERE IDDOC=:ID')
    Transaction = IBTrDvReg
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 56
    Top = 136
    object Doc2IDDOC: TFIBIntegerField
      FieldName = 'IDDOC'
    end
    object Doc2PRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
  end
  object IBTrDvReg: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 104
    Top = 136
  end
end
