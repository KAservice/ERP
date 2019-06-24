object DMDocPer: TDMDocPer
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 440
  Width = 635
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
      '    IDBASE_GALLDOC = :IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC = :IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC = :IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC = :PREFIKS_NUM_GALLDOC'
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
      '    IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC'
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
      '    :IDBASE_GALLDOC,'
      '    :IDPROJECT_GALLDOC,'
      '    :IDBUSINOP_GALLDOC,'
      '    :PREFIKS_NUM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select GALLDOC.*,'
      '     FNAME_USER ,'
      '     NAME_SINFBASE_OBMEN,'
      '     NAMEFIRM,'
      '     NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*,'
      '     FNAME_USER ,'
      '     NAME_SINFBASE_OBMEN,'
      '     NAMEFIRM,'
      '     NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 16
    poUseLargeIntField = True
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
    end
    object DocAllIDUSERDOC: TFIBLargeIntField
      FieldName = 'IDUSERDOC'
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object DocAllIDDOCOSNDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllIDEXTDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC'
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocAllNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocAllNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllPREFIKS_NUM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_GALLDOC'
      Size = 12
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DPER'
      'SET '
      '    IDDOCPER = :IDDOCPER,'
      '    IDSKLPOLPER = :IDSKLPOLPER,'
      '    PRIMPER = :PRIMPER,'
      '    GID_DPER = :GID_DPER,'
      '    IDRTPRICE_DPER = :IDRTPRICE_DPER,'
      '    IDBASE_DPER = :IDBASE_DPER'
      'WHERE'
      '    IDPER = :OLD_IDPER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPER'
      'WHERE'
      '        IDPER = :OLD_IDPER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPER('
      '    IDPER,'
      '    IDDOCPER,'
      '    IDSKLPOLPER,'
      '    PRIMPER,'
      '    GID_DPER,'
      '    IDRTPRICE_DPER,'
      '    IDBASE_DPER'
      ')'
      'VALUES('
      '    :IDPER,'
      '    :IDDOCPER,'
      '    :IDSKLPOLPER,'
      '    :PRIMPER,'
      '    :GID_DPER,'
      '    :IDRTPRICE_DPER,'
      '    :IDBASE_DPER'
      ')')
    RefreshSQL.Strings = (
      'select DPER.*,'
      '   NAMESKLAD '
      'from  DPER'
      'left outer join SSKLAD on IDSKLPOLPER=IDSKLAD'
      'where(  IDDOCPER=:ID'
      '     ) and (     DPER.IDPER = :OLD_IDPER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPER.*,'
      '   NAMESKLAD '
      'from  DPER'
      'left outer join SSKLAD on IDSKLPOLPER=IDSKLAD'
      'where IDDOCPER=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPER'
    AutoUpdateOptions.KeyFields = 'IDPER'
    AutoUpdateOptions.GeneratorName = 'GEN_DPER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 72
    poUseLargeIntField = True
    object DocIDPER: TFIBLargeIntField
      FieldName = 'IDPER'
    end
    object DocIDDOCPER: TFIBLargeIntField
      FieldName = 'IDDOCPER'
    end
    object DocIDSKLPOLPER: TFIBLargeIntField
      FieldName = 'IDSKLPOLPER'
      OnChange = DocIDSKLPOLPERChange
    end
    object DocPRIMPER: TFIBWideStringField
      FieldName = 'PRIMPER'
      Size = 100
    end
    object DocGID_DPER: TFIBWideStringField
      FieldName = 'GID_DPER'
      Size = 10
    end
    object DocIDRTPRICE_DPER: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DPER'
    end
    object DocIDBASE_DPER: TFIBLargeIntField
      FieldName = 'IDBASE_DPER'
    end
    object DocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DPERT'
      'SET '
      '    IDDOCPERT = :IDDOCPERT,'
      '    IDNOMPERT = :IDNOMPERT,'
      '    IDEDPERT = :IDEDPERT,'
      '    KOLPERT = :KOLPERT,'
      '    KFPERT = :KFPERT,'
      '    PRICEPERT = :PRICEPERT,'
      '    SUMPERT = :SUMPERT,'
      '    GID_DPERT = :GID_DPERT,'
      '    NAC_DPERT = :NAC_DPERT,'
      '    IDBASE_DPERT = :IDBASE_DPERT,'
      '    NDS_DPERT = :NDS_DPERT,'
      '    SUMNDS_DPERT = :SUMNDS_DPERT,'
      '    SEB_PRICE_DPERT = :SEB_PRICE_DPERT,'
      '    SEB_SUM_DPERT = :SEB_SUM_DPERT'
      'WHERE'
      '    IDPERT = :OLD_IDPERT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPERT'
      'WHERE'
      '        IDPERT = :OLD_IDPERT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPERT('
      '    IDPERT,'
      '    IDDOCPERT,'
      '    IDNOMPERT,'
      '    IDEDPERT,'
      '    KOLPERT,'
      '    KFPERT,'
      '    PRICEPERT,'
      '    SUMPERT,'
      '    GID_DPERT,'
      '    NAC_DPERT,'
      '    IDBASE_DPERT,'
      '    NDS_DPERT,'
      '    SUMNDS_DPERT,'
      '    SEB_PRICE_DPERT,'
      '    SEB_SUM_DPERT'
      ')'
      'VALUES('
      '    :IDPERT,'
      '    :IDDOCPERT,'
      '    :IDNOMPERT,'
      '    :IDEDPERT,'
      '    :KOLPERT,'
      '    :KFPERT,'
      '    :PRICEPERT,'
      '    :SUMPERT,'
      '    :GID_DPERT,'
      '    :NAC_DPERT,'
      '    :IDBASE_DPERT,'
      '    :NDS_DPERT,'
      '    :SUMNDS_DPERT,'
      '    :SEB_PRICE_DPERT,'
      '    :SEB_SUM_DPERT'
      ')')
    RefreshSQL.Strings = (
      'select DPERT.*, NAMENOM, NAMEED ,TNOM ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed'
      'from '
      'DPERT LEFT OUTER JOIN SNOM  ON IDNOMPERT=IDNOM '
      'left outer join SED  on  IDEDPERT=IDED'
      'where(  IDDOCPERT=:ID'
      '     ) and (     DPERT.IDPERT = :OLD_IDPERT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPERT.*, NAMENOM, NAMEED ,TNOM ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed'
      'from '
      'DPERT LEFT OUTER JOIN SNOM  ON IDNOMPERT=IDNOM '
      'left outer join SED  on  IDEDPERT=IDED'
      'where IDDOCPERT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPERT'
    AutoUpdateOptions.KeyFields = 'IDPERT'
    AutoUpdateOptions.GeneratorName = 'GEN_DPERT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 120
    poUseLargeIntField = True
    object DocTKOLPERT: TFIBBCDField
      FieldName = 'KOLPERT'
      OnChange = DocTKOLPERTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFPERT: TFIBBCDField
      FieldName = 'KFPERT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEPERT: TFIBBCDField
      FieldName = 'PRICEPERT'
      OnChange = DocTPRICEPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMPERT: TFIBBCDField
      FieldName = 'SUMPERT'
      OnChange = DocTSUMPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTNAC_DPERT: TFIBBCDField
      FieldName = 'NAC_DPERT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_DPERT: TFIBIntegerField
      FieldName = 'NDS_DPERT'
    end
    object DocTSUMNDS_DPERT: TFIBBCDField
      FieldName = 'SUMNDS_DPERT'
      Size = 2
      RoundByScale = True
    end
    object DocTIDPERT: TFIBLargeIntField
      FieldName = 'IDPERT'
    end
    object DocTIDDOCPERT: TFIBLargeIntField
      FieldName = 'IDDOCPERT'
    end
    object DocTIDNOMPERT: TFIBLargeIntField
      FieldName = 'IDNOMPERT'
    end
    object DocTIDEDPERT: TFIBLargeIntField
      FieldName = 'IDEDPERT'
    end
    object DocTGID_DPERT: TFIBWideStringField
      FieldName = 'GID_DPERT'
      Size = 10
    end
    object DocTIDBASE_DPERT: TFIBLargeIntField
      FieldName = 'IDBASE_DPERT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTSEB_PRICE_DPERT: TFIBBCDField
      FieldName = 'SEB_PRICE_DPERT'
      OnChange = DocTSEB_PRICE_DPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSEB_SUM_DPERT: TFIBBCDField
      FieldName = 'SEB_SUM_DPERT'
      OnChange = DocTSEB_SUM_DPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_SUM_ED: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM_ED'
      Size = 2
      RoundByScale = True
      Calculated = True
    end
    object DocTNAC_SUM: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM'
      Size = 2
      RoundByScale = True
      Calculated = True
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
    Left = 264
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 264
    Top = 72
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 192
    Top = 192
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PER_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 320
    Top = 16
  end
  object Firma: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SFIRM where IDFIRM=:ID')
    Transaction = IBTr
    Left = 384
    Top = 16
    poUseLargeIntField = True
  end
  object Sklad: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SSKLAD where IDSKLAD=:ID')
    Transaction = IBTr
    Left = 384
    Top = 72
    poUseLargeIntField = True
  end
  object SkladPol: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SSKLAD where IDSKLAD=:ID')
    Transaction = IBTr
    Left = 384
    Top = 128
    poUseLargeIntField = True
    object SkladPolIDSKLAD: TFIBLargeIntField
      FieldName = 'IDSKLAD'
    end
    object SkladPolNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object SkladPolMOLSKLAD: TFIBWideStringField
      FieldName = 'MOLSKLAD'
    end
    object SkladPolADRSKLAD: TFIBWideStringField
      FieldName = 'ADRSKLAD'
      Size = 100
    end
    object SkladPolTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object SkladPolGID_SSKLAD: TFIBWideStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 280
    Top = 160
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PER_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PER_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
