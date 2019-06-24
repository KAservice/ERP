object DMDocReal: TDMDocReal
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 408
  Width = 439
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 120
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
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
    Left = 216
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
    Left = 216
    Top = 72
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
      '    IDDOCOSNDOC = :IDDOCOSNDOC,'
      '    IDEXTDOC = :IDEXTDOC,'
      '    TYPEEXTDOC = :TYPEEXTDOC,'
      '    IDBASE_GALLDOC = :IDBASE_GALLDOC'
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
      '    IDDOCOSNDOC,'
      '    IDEXTDOC,'
      '    TYPEEXTDOC,'
      '    IDBASE_GALLDOC'
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
      '    :IDDOCOSNDOC,'
      '    :IDEXTDOC,'
      '    :TYPEEXTDOC,'
      '    :IDBASE_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      ''
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      ''
      'where IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 16
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
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
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
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
    object DocAllNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllFNAME_USER: TFIBStringField
      FieldName = 'FNAME_USER'
      Size = 30
      EmptyStrToNull = True
    end
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllGID_DOC: TFIBStringField
      FieldName = 'GID_DOC'
      Size = 10
      EmptyStrToNull = True
    end
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
      Size = 0
      RoundByScale = True
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREA'
      'SET '
      '    IDDOCREA = :IDDOCREA,'
      '    PRIMREA = :PRIMREA,'
      '    GID_DREA = :GID_DREA,'
      '    IDTPRICEREA = :IDTPRICEREA,'
      '    IDGRPOLREA = :IDGRPOLREA,'
      '    IDBSCHETREA = :IDBSCHETREA,'
      '    IDBASE_DREA = :IDBASE_DREA'
      'WHERE'
      '    IDREA = :OLD_IDREA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREA'
      'WHERE'
      '        IDREA = :OLD_IDREA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREA('
      '    IDREA,'
      '    IDDOCREA,'
      '    PRIMREA,'
      '    GID_DREA,'
      '    IDTPRICEREA,'
      '    IDGRPOLREA,'
      '    IDBSCHETREA,'
      '    IDBASE_DREA'
      ')'
      'VALUES('
      '    :IDREA,'
      '    :IDDOCREA,'
      '    :PRIMREA,'
      '    :GID_DREA,'
      '    :IDTPRICEREA,'
      '    :IDGRPOLREA,'
      '    :IDBSCHETREA,'
      '    :IDBASE_DREA'
      ')')
    RefreshSQL.Strings = (
      'select DREA.* , NAME_TPRICE, NAMEKLIENT, NAMEBSCHET'
      'from  DREA'
      'left outer join STPRICE  on IDTPRICEREA=ID_TPRICE'
      'left outer join SKLIENT on IDGRPOLREA=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=IDBSCHETREA'
      'where(  IDDOCREA=:ID'
      '     ) and (     DREA.IDREA = :OLD_IDREA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREA.* , NAME_TPRICE, NAMEKLIENT, NAMEBSCHET'
      'from  DREA'
      'left outer join STPRICE  on IDTPRICEREA=ID_TPRICE'
      'left outer join SKLIENT on IDGRPOLREA=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=IDBSCHETREA'
      'where IDDOCREA=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREA'
    AutoUpdateOptions.KeyFields = 'IDREA'
    AutoUpdateOptions.GeneratorName = 'GEN_DREA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 72
    object DocPRIMREA: TFIBStringField
      FieldName = 'PRIMREA'
      Size = 100
      EmptyStrToNull = True
    end
    object DocNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object DocNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object DocNAMEBSCHET: TFIBStringField
      FieldName = 'NAMEBSCHET'
      Size = 30
      EmptyStrToNull = True
    end
    object DocIDREA: TFIBBCDField
      FieldName = 'IDREA'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOCREA: TFIBBCDField
      FieldName = 'IDDOCREA'
      Size = 0
      RoundByScale = True
    end
    object DocIDTPRICEREA: TFIBBCDField
      FieldName = 'IDTPRICEREA'
      Size = 0
      RoundByScale = True
    end
    object DocIDGRPOLREA: TFIBBCDField
      FieldName = 'IDGRPOLREA'
      Size = 0
      RoundByScale = True
    end
    object DocIDBSCHETREA: TFIBBCDField
      FieldName = 'IDBSCHETREA'
      Size = 0
      RoundByScale = True
    end
    object DocGID_DREA: TFIBStringField
      FieldName = 'GID_DREA'
      Size = 10
      EmptyStrToNull = True
    end
    object DocIDBASE_DREA: TFIBBCDField
      FieldName = 'IDBASE_DREA'
      Size = 0
      RoundByScale = True
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREAT'
      'SET '
      '    IDDOCREAT = :IDDOCREAT,'
      '    IDNOMREAT = :IDNOMREAT,'
      '    IDEDREAT = :IDEDREAT,'
      '    KOLREAT = :KOLREAT,'
      '    KFREAT = :KFREAT,'
      '    PRICEREAT = :PRICEREAT,'
      '    SUMREAT = :SUMREAT,'
      '    GID_DREAT = :GID_DREAT,'
      '    IDBASE_DREAT = :IDBASE_DREAT,'
      '    NDS_DREAT = :NDS_DREAT,'
      '    SUMNDS_DREAT = :SUMNDS_DREAT'
      'WHERE'
      '    IDREAT = :OLD_IDREAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREAT'
      'WHERE'
      '        IDREAT = :OLD_IDREAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREAT('
      '    IDREAT,'
      '    IDDOCREAT,'
      '    IDNOMREAT,'
      '    IDEDREAT,'
      '    KOLREAT,'
      '    KFREAT,'
      '    PRICEREAT,'
      '    SUMREAT,'
      '    GID_DREAT,'
      '    IDBASE_DREAT,'
      '    NDS_DREAT,'
      '    SUMNDS_DREAT'
      ')'
      'VALUES('
      '    :IDREAT,'
      '    :IDDOCREAT,'
      '    :IDNOMREAT,'
      '    :IDEDREAT,'
      '    :KOLREAT,'
      '    :KFREAT,'
      '    :PRICEREAT,'
      '    :SUMREAT,'
      '    :GID_DREAT,'
      '    :IDBASE_DREAT,'
      '    :NDS_DREAT,'
      '    :SUMNDS_DREAT'
      ')')
    RefreshSQL.Strings = (
      'select DREAT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREAT LEFT OUTER JOIN SNOM  ON IDNOMREAT=IDNOM '
      'left outer join SED  on  IDEDREAT=IDED'
      'where(  IDDOCREAT=:ID'
      '     ) and (     DREAT.IDREAT = :OLD_IDREAT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREAT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREAT LEFT OUTER JOIN SNOM  ON IDNOMREAT=IDNOM '
      'left outer join SED  on  IDEDREAT=IDED'
      'where IDDOCREAT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREAT'
    AutoUpdateOptions.KeyFields = 'IDREAT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 128
    object DocTKOLREAT: TFIBBCDField
      FieldName = 'KOLREAT'
      OnChange = DocTKOLREATChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFREAT: TFIBBCDField
      FieldName = 'KFREAT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEREAT: TFIBBCDField
      FieldName = 'PRICEREAT'
      OnChange = DocTPRICEREATChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMREAT: TFIBBCDField
      FieldName = 'SUMREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object DocTNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTIDREAT: TFIBBCDField
      FieldName = 'IDREAT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOCREAT: TFIBBCDField
      FieldName = 'IDDOCREAT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOMREAT: TFIBBCDField
      FieldName = 'IDNOMREAT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDEDREAT: TFIBBCDField
      FieldName = 'IDEDREAT'
      Size = 0
      RoundByScale = True
    end
    object DocTGID_DREAT: TFIBStringField
      FieldName = 'GID_DREAT'
      Size = 10
      EmptyStrToNull = True
    end
    object DocTIDBASE_DREAT: TFIBBCDField
      FieldName = 'IDBASE_DREAT'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTrDvReg: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    Left = 360
    Top = 192
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 200
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    Database = DM.pFIBData
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REA_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    Database = DM.pFIBData
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REA_DVREG (:PARAM_IDDOC,0,0,0)')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUMDOC) AS MAXNUMBER from  GALLDOC'
      'where TDOC='#39'REA'#39' and POSDOC>:PARAM_POS')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    DefaultFormats.DateTimeDisplayFormat = 'c'
    Left = 296
    Top = 16
  end
end
