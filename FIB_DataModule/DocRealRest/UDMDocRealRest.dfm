object DMDocRealRest: TDMDocRealRest
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 262
  Width = 442
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 128
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
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
      'select '
      
        '  GALLDOC.*, SFIRM.*,  SKLIENT.*,  NAMESKLAD,  NAME_USER, NAME_S' +
        'INFBASE_OBMEN'
      'from '
      '  GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join  SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join  SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      
        '  GALLDOC.*, SFIRM.*,  SKLIENT.*,  NAMESKLAD,  NAME_USER, NAME_S' +
        'INFBASE_OBMEN'
      'from '
      '  GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join  SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join  SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'where '
      '  IDDOC=:ID')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 16
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
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
    object DocAllGID_DOC: TFIBStringField
      FieldName = 'GID_DOC'
      Size = 10
      EmptyStrToNull = True
    end
    object DocAllNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object DocAllNAME_USER: TFIBStringField
      FieldName = 'NAME_USER'
      EmptyStrToNull = True
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      OnGetText = DocAllNAME_SINFBASE_OBMENGetText
      Size = 50
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
    object DocAllIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREALREST'
      'SET '
      '    IDDOC_REALREST = :IDDOC_REALREST,'
      '    IDPOK_REALREST = :IDPOK_REALREST,'
      '    IDTPRICE_REALREST = :IDTPRICE_REALREST,'
      '    PRIM_REALREST = :PRIM_REALREST,'
      '    GID_DREALREST = :GID_DREALREST'
      'WHERE'
      '    ID_REALREST = :OLD_ID_REALREST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREALREST'
      'WHERE'
      '        ID_REALREST = :OLD_ID_REALREST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREALREST('
      '    ID_REALREST,'
      '    IDDOC_REALREST,'
      '    IDPOK_REALREST,'
      '    IDTPRICE_REALREST,'
      '    PRIM_REALREST,'
      '    GID_DREALREST'
      ')'
      'VALUES('
      '    :ID_REALREST,'
      '    :IDDOC_REALREST,'
      '    :IDPOK_REALREST,'
      '    :IDTPRICE_REALREST,'
      '    :PRIM_REALREST,'
      '    :GID_DREALREST'
      ')')
    RefreshSQL.Strings = (
      'select DREALREST.*,  NAMEKLIENT, NAME_TPRICE'
      'from  '
      '  DREALREST'
      'left outer join SKLIENT  on IDPOK_REALREST=IDKLIENT'
      'left outer join STPRICE  on IDTPRICE_REALREST=ID_TPRICE'
      'where(  '
      '  IDDOC_REALREST=:ID'
      '     ) and (     DREALREST.ID_REALREST = :OLD_ID_REALREST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREALREST.*,  NAMEKLIENT, NAME_TPRICE'
      'from  '
      '  DREALREST'
      'left outer join SKLIENT  on IDPOK_REALREST=IDKLIENT'
      'left outer join STPRICE  on IDTPRICE_REALREST=ID_TPRICE'
      'where '
      '  IDDOC_REALREST=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREALREST'
    AutoUpdateOptions.KeyFields = 'ID_REALREST'
    AutoUpdateOptions.GeneratorName = 'GEN_DREALREST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocAfterDelete
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 72
    object DocPRIM_REALREST: TFIBStringField
      FieldName = 'PRIM_REALREST'
      Size = 50
      EmptyStrToNull = True
    end
    object DocGID_DREALREST: TFIBStringField
      FieldName = 'GID_DREALREST'
      Size = 10
      EmptyStrToNull = True
    end
    object DocNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object DocNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object DocID_REALREST: TFIBBCDField
      FieldName = 'ID_REALREST'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOC_REALREST: TFIBBCDField
      FieldName = 'IDDOC_REALREST'
      Size = 0
      RoundByScale = True
    end
    object DocIDPOK_REALREST: TFIBBCDField
      FieldName = 'IDPOK_REALREST'
      Size = 0
      RoundByScale = True
    end
    object DocIDTPRICE_REALREST: TFIBBCDField
      FieldName = 'IDTPRICE_REALREST'
      Size = 0
      RoundByScale = True
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREALRESTT'
      'SET '
      '    IDDOC_REALRESTT = :IDDOC_REALRESTT,'
      '    IDNOM_REALRESTT = :IDNOM_REALRESTT,'
      '    IDED_REALRESTT = :IDED_REALRESTT,'
      '    KOL_REALRESTT = :KOL_REALRESTT,'
      '    KF_REALRESTT = :KF_REALRESTT,'
      '    PRICE_REALRESTT = :PRICE_REALRESTT,'
      '    SUM_REALRESTT = :SUM_REALRESTT,'
      '    GID_DREALRESTT = :GID_DREALRESTT'
      'WHERE'
      '    ID_REALRESTT = :OLD_ID_REALRESTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREALRESTT'
      'WHERE'
      '        ID_REALRESTT = :OLD_ID_REALRESTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREALRESTT('
      '    ID_REALRESTT,'
      '    IDDOC_REALRESTT,'
      '    IDNOM_REALRESTT,'
      '    IDED_REALRESTT,'
      '    KOL_REALRESTT,'
      '    KF_REALRESTT,'
      '    PRICE_REALRESTT,'
      '    SUM_REALRESTT,'
      '    GID_DREALRESTT'
      ')'
      'VALUES('
      '    :ID_REALRESTT,'
      '    :IDDOC_REALRESTT,'
      '    :IDNOM_REALRESTT,'
      '    :IDED_REALRESTT,'
      '    :KOL_REALRESTT,'
      '    :KF_REALRESTT,'
      '    :PRICE_REALRESTT,'
      '    :SUM_REALRESTT,'
      '    :GID_DREALRESTT'
      ')')
    RefreshSQL.Strings = (
      
        'select DREALRESTT.*,  KRNAMENOM, NAMENOM, NAMEED ,TNOM,  ZNACH_P' +
        'RICE'
      'from '
      'DREALRESTT LEFT OUTER JOIN SNOM  ON IDNOM_REALRESTT=IDNOM '
      'left outer join SED  on  IDED_REALRESTT=IDED'
      
        'left outer join SPRICE on IDNOM=IDNOM_PRICE AND IDTYPE_PRICE=:PA' +
        'RAM_ID_TYPE_PRICE'
      'where(  IDDOC_REALRESTT=:ID'
      '     ) and (     DREALRESTT.ID_REALRESTT = :OLD_ID_REALRESTT'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      
        'select DREALRESTT.*,  KRNAMENOM, NAMENOM, NAMEED ,TNOM,  ZNACH_P' +
        'RICE'
      'from '
      'DREALRESTT LEFT OUTER JOIN SNOM  ON IDNOM_REALRESTT=IDNOM '
      'left outer join SED  on  IDED_REALRESTT=IDED'
      
        'left outer join SPRICE on IDNOM=IDNOM_PRICE AND IDTYPE_PRICE=:PA' +
        'RAM_ID_TYPE_PRICE'
      'where IDDOC_REALRESTT=:ID'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'DREALRESTT'
    AutoUpdateOptions.KeyFields = 'ID_REALRESTT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREALRESTT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 128
    object DocTKOL_REALRESTT: TFIBBCDField
      FieldName = 'KOL_REALRESTT'
      OnChange = DocTKOL_REALRESTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REALRESTT: TFIBBCDField
      FieldName = 'KF_REALRESTT'
      OnChange = DocTKF_REALRESTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REALRESTT: TFIBBCDField
      FieldName = 'PRICE_REALRESTT'
      OnChange = DocTPRICE_REALRESTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REALRESTT: TFIBBCDField
      FieldName = 'SUM_REALRESTT'
      Size = 2
      RoundByScale = True
    end
    object DocTGID_DREALRESTT: TFIBStringField
      FieldName = 'GID_DREALRESTT'
      Size = 10
      EmptyStrToNull = True
    end
    object DocTKRNAMENOM: TFIBStringField
      FieldName = 'KRNAMENOM'
      Size = 40
      EmptyStrToNull = True
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
    object DocTZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_REALRESTT: TFIBBCDField
      FieldName = 'ID_REALRESTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOC_REALRESTT: TFIBBCDField
      FieldName = 'IDDOC_REALRESTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOM_REALRESTT: TFIBBCDField
      FieldName = 'IDNOM_REALRESTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDED_REALRESTT: TFIBBCDField
      FieldName = 'IDED_REALRESTT'
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
    Left = 256
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
    Left = 256
    Top = 72
  end
  object Firma: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SFIRM where IDFIRM=:ID')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 328
    Top = 16
    object FirmaNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object FirmaFNAMEFIRM: TFIBStringField
      FieldName = 'FNAMEFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object FirmaPADRFIRM: TFIBStringField
      FieldName = 'PADRFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object FirmaUADRFIRM: TFIBStringField
      FieldName = 'UADRFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object FirmaINNFIRM: TFIBStringField
      FieldName = 'INNFIRM'
      Size = 12
      EmptyStrToNull = True
    end
    object FirmaKPPFIRM: TFIBStringField
      FieldName = 'KPPFIRM'
      Size = 9
      EmptyStrToNull = True
    end
    object FirmaDIRFIRM: TFIBStringField
      FieldName = 'DIRFIRM'
      EmptyStrToNull = True
    end
    object FirmaBUHFIRM: TFIBStringField
      FieldName = 'BUHFIRM'
      EmptyStrToNull = True
    end
    object FirmaKASFIRM: TFIBStringField
      FieldName = 'KASFIRM'
      EmptyStrToNull = True
    end
    object FirmaGID_SFIRM: TFIBStringField
      FieldName = 'GID_SFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object FirmaNUMDOCREGFIRM: TFIBStringField
      FieldName = 'NUMDOCREGFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object FirmaDATEDOCREGFIRM: TFIBStringField
      FieldName = 'DATEDOCREGFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object FirmaTYPEFIRM: TFIBSmallIntField
      FieldName = 'TYPEFIRM'
    end
    object FirmaOKPOSFIRM: TFIBStringField
      FieldName = 'OKPOSFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object FirmaOKDPSFIRM: TFIBStringField
      FieldName = 'OKDPSFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object FirmaTELFIRM: TFIBStringField
      FieldName = 'TELFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object FirmaIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
  end
  object Klient: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SKLIENT where IDKLIENT=:ID')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 328
    Top = 64
    object KlientNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object KlientFNAME: TFIBStringField
      FieldName = 'FNAME'
      Size = 100
      EmptyStrToNull = True
    end
    object KlientADRKLIENT: TFIBStringField
      FieldName = 'ADRKLIENT'
      Size = 100
      EmptyStrToNull = True
    end
    object KlientTELKLIENT: TFIBStringField
      FieldName = 'TELKLIENT'
      Size = 30
      EmptyStrToNull = True
    end
    object KlientINNKLIENT: TFIBStringField
      FieldName = 'INNKLIENT'
      Size = 12
      EmptyStrToNull = True
    end
    object KlientKPPKLIENT: TFIBStringField
      FieldName = 'KPPKLIENT'
      Size = 9
      EmptyStrToNull = True
    end
    object KlientTKLIENT: TFIBIntegerField
      FieldName = 'TKLIENT'
    end
    object KlientGID_SKLIENT: TFIBStringField
      FieldName = 'GID_SKLIENT'
      Size = 10
      EmptyStrToNull = True
    end
    object KlientOKPOKLIENT: TFIBStringField
      FieldName = 'OKPOKLIENT'
      Size = 10
      EmptyStrToNull = True
    end
    object KlientIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object KlientIDTPRICEKLIENT: TFIBBCDField
      FieldName = 'IDTPRICEKLIENT'
      Size = 0
      RoundByScale = True
    end
    object KlientIDGRPKLIENT: TFIBBCDField
      FieldName = 'IDGRPKLIENT'
      Size = 0
      RoundByScale = True
    end
    object KlientIDVIDKLIENT: TFIBBCDField
      FieldName = 'IDVIDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object KlientIDCOUNTRYKLIENT: TFIBBCDField
      FieldName = 'IDCOUNTRYKLIENT'
      Size = 0
      RoundByScale = True
    end
  end
  object Sklad: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SSKLAD where IDSKLAD=:ID')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 328
    Top = 112
    object SkladNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object SkladMOLSKLAD: TFIBStringField
      FieldName = 'MOLSKLAD'
      EmptyStrToNull = True
    end
    object SkladADRSKLAD: TFIBStringField
      FieldName = 'ADRSKLAD'
      Size = 100
      EmptyStrToNull = True
    end
    object SkladTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object SkladGID_SSKLAD: TFIBStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
      EmptyStrToNull = True
    end
    object SkladIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
  end
  object SpisokTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 328
    Top = 168
    object SpisokTypePriceNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object SpisokTypePriceGID_STPRICE: TFIBStringField
      FieldName = 'GID_STPRICE'
      Size = 10
      EmptyStrToNull = True
    end
    object SpisokTypePriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUMDOC) AS MAXNUMBER from  GALLDOC'
      'where TDOC='#39'REAL_REST'#39)
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 392
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object TablePart: TpFIBDataSet
    SelectSQL.Strings = (
      'select RGOSTNOM.*, POSDOC'
      'from RGOSTNOM'
      'left outer join SPART on IDPART=IDPARTOSTNOM'
      'left outer join GALLDOC on IDDOCPART=IDDOC'
      'where'
      'IDFIRMOSTNOM=:IDFIRM  AND'
      'IDNOMOSTNOM=:IDNOM   AND'
      'IDSKLOSTNOM=:IDSKL   AND'
      'KOLOSTNOM>0'
      ''
      'order by POSDOC')
    Transaction = IBTrDvReg
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 232
    Top = 192
    object TablePartSUMOSTNOM: TFIBBCDField
      FieldName = 'SUMOSTNOM'
      Size = 2
      RoundByScale = True
    end
    object TablePartKOLOSTNOM: TFIBBCDField
      FieldName = 'KOLOSTNOM'
      Size = 3
      RoundByScale = True
    end
    object TablePartPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object TablePartIDOSTNOM: TFIBBCDField
      FieldName = 'IDOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object TablePartIDFIRMOSTNOM: TFIBBCDField
      FieldName = 'IDFIRMOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object TablePartIDSKLOSTNOM: TFIBBCDField
      FieldName = 'IDSKLOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object TablePartIDNOMOSTNOM: TFIBBCDField
      FieldName = 'IDNOMOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object TablePartIDPARTOSTNOM: TFIBBCDField
      FieldName = 'IDPARTOSTNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTrDvReg: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'isc_tpb_nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 168
    Top = 192
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
    Left = 72
    Top = 192
    object Doc2PRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object Doc2IDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
  end
end
