object DMDocPrihNakl: TDMDocPrihNakl
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 453
  Width = 420
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 64
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 112
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM,NAM' +
        'ESKLAD, NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM,NAM' +
        'ESKLAD, NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
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
    Left = 160
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
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
      'UPDATE DPRN'
      'SET '
      '    IDDOCPRN = :IDDOCPRN,'
      '    PRIMDOC = :PRIMDOC,'
      '    IDTPRICE = :IDTPRICE,'
      '    GID_DPRN = :GID_DPRN,'
      '    IDRTPRICE_DPRN = :IDRTPRICE_DPRN,'
      '    RSUM_DPRN = :RSUM_DPRN,'
      '    IDBASE_DPRN = :IDBASE_DPRN,'
      '    NUMDOCPOST_DPRN = :NUMDOCPOST_DPRN,'
      '    POSDOCPOST_DPRN = :POSDOCPOST_DPRN,'
      '    FL_TREB_OTCHET_DPRN = :FL_TREB_OTCHET_DPRN,'
      '    FL_OTV_HRAN_DPRN = :FL_OTV_HRAN_DPRN'
      'WHERE'
      '    IDPRN = :OLD_IDPRN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPRN'
      'WHERE'
      '        IDPRN = :OLD_IDPRN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPRN('
      '    IDPRN,'
      '    IDDOCPRN,'
      '    PRIMDOC,'
      '    IDTPRICE,'
      '    GID_DPRN,'
      '    IDRTPRICE_DPRN,'
      '    RSUM_DPRN,'
      '    IDBASE_DPRN,'
      '    NUMDOCPOST_DPRN,'
      '    POSDOCPOST_DPRN,'
      '    FL_TREB_OTCHET_DPRN,'
      '    FL_OTV_HRAN_DPRN'
      ')'
      'VALUES('
      '    :IDPRN,'
      '    :IDDOCPRN,'
      '    :PRIMDOC,'
      '    :IDTPRICE,'
      '    :GID_DPRN,'
      '    :IDRTPRICE_DPRN,'
      '    :RSUM_DPRN,'
      '    :IDBASE_DPRN,'
      '    :NUMDOCPOST_DPRN,'
      '    :POSDOCPOST_DPRN,'
      '    :FL_TREB_OTCHET_DPRN,'
      '    :FL_OTV_HRAN_DPRN'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DPRN'
      'where(  IDDOCPRN=:ID'
      '     ) and (     DPRN.IDPRN = :OLD_IDPRN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DPRN'
      'where IDDOCPRN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPRN'
    AutoUpdateOptions.KeyFields = 'IDPRN'
    AutoUpdateOptions.GeneratorName = 'GEN_DPRN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocRSUM_DPRN: TFIBBCDField
      FieldName = 'RSUM_DPRN'
      Size = 2
      RoundByScale = True
    end
    object DocPOSDOCPOST_DPRN: TFIBDateTimeField
      FieldName = 'POSDOCPOST_DPRN'
      DisplayFormat = 'c'
    end
    object DocIDPRN: TFIBLargeIntField
      FieldName = 'IDPRN'
    end
    object DocIDDOCPRN: TFIBLargeIntField
      FieldName = 'IDDOCPRN'
    end
    object DocPRIMDOC: TFIBWideStringField
      FieldName = 'PRIMDOC'
      Size = 200
    end
    object DocIDTPRICE: TFIBLargeIntField
      FieldName = 'IDTPRICE'
    end
    object DocGID_DPRN: TFIBWideStringField
      FieldName = 'GID_DPRN'
      Size = 10
    end
    object DocIDRTPRICE_DPRN: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DPRN'
    end
    object DocIDBASE_DPRN: TFIBLargeIntField
      FieldName = 'IDBASE_DPRN'
    end
    object DocNUMDOCPOST_DPRN: TFIBWideStringField
      FieldName = 'NUMDOCPOST_DPRN'
      Size = 100
    end
    object DocFL_TREB_OTCHET_DPRN: TFIBSmallIntField
      FieldName = 'FL_TREB_OTCHET_DPRN'
    end
    object DocFL_OTV_HRAN_DPRN: TFIBSmallIntField
      FieldName = 'FL_OTV_HRAN_DPRN'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DPRNT'
      'SET '
      '    IDDOCPRNT = :IDDOCPRNT,'
      '    IDNOMPRNT = :IDNOMPRNT,'
      '    IDEDPRNT = :IDEDPRNT,'
      '    IDPARTPRNT = :IDPARTPRNT,'
      '    KOLPRNT = :KOLPRNT,'
      '    KFPRNT = :KFPRNT,'
      '    PRICEPRNT = :PRICEPRNT,'
      '    SUMPRNT = :SUMPRNT,'
      '    GID_DPRNT = :GID_DPRNT,'
      '    NAC_DPRNT = :NAC_DPRNT,'
      '    RPRICE_DPRNT = :RPRICE_DPRNT,'
      '    RSUM_DPRNT = :RSUM_DPRNT,'
      '    IDBASE_DPRNT = :IDBASE_DPRNT,'
      '    NDS_DPRNT = :NDS_DPRNT,'
      '    SUMNDS_DPRNT = :SUMNDS_DPRNT'
      'WHERE'
      '    IDPRNT = :OLD_IDPRNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPRNT'
      'WHERE'
      '        IDPRNT = :OLD_IDPRNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPRNT('
      '    IDPRNT,'
      '    IDDOCPRNT,'
      '    IDNOMPRNT,'
      '    IDEDPRNT,'
      '    IDPARTPRNT,'
      '    KOLPRNT,'
      '    KFPRNT,'
      '    PRICEPRNT,'
      '    SUMPRNT,'
      '    GID_DPRNT,'
      '    NAC_DPRNT,'
      '    RPRICE_DPRNT,'
      '    RSUM_DPRNT,'
      '    IDBASE_DPRNT,'
      '    NDS_DPRNT,'
      '    SUMNDS_DPRNT'
      ')'
      'VALUES('
      '    :IDPRNT,'
      '    :IDDOCPRNT,'
      '    :IDNOMPRNT,'
      '    :IDEDPRNT,'
      '    :IDPARTPRNT,'
      '    :KOLPRNT,'
      '    :KFPRNT,'
      '    :PRICEPRNT,'
      '    :SUMPRNT,'
      '    :GID_DPRNT,'
      '    :NAC_DPRNT,'
      '    :RPRICE_DPRNT,'
      '    :RSUM_DPRNT,'
      '    :IDBASE_DPRNT,'
      '    :NDS_DPRNT,'
      '    :SUMNDS_DPRNT'
      ')')
    RefreshSQL.Strings = (
      'select DPRNT.*, NAMENOM, NAMEED ,TNOM,'
      '  SPART.GTDPART,'
      '  SPART.SERTPART,'
      '  SPART.SRGODNPART,'
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.shed'
      'from '
      'DPRNT LEFT OUTER JOIN SNOM  ON IDNOMPRNT=IDNOM '
      'left outer join SED  on  IDEDPRNT=IDED'
      'left outer join SPART on IDPARTPRNT=IDPART'
      'where(  IDDOCPRNT=:ID'
      '     ) and (     DPRNT.IDPRNT = :OLD_IDPRNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPRNT.*, NAMENOM, NAMEED ,TNOM,'
      '  SPART.GTDPART,'
      '  SPART.SERTPART,'
      '  SPART.SRGODNPART,'
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.shed'
      'from '
      'DPRNT LEFT OUTER JOIN SNOM  ON IDNOMPRNT=IDNOM '
      'left outer join SED  on  IDEDPRNT=IDED'
      'left outer join SPART on IDPARTPRNT=IDPART'
      'where IDDOCPRNT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPRNT'
    AutoUpdateOptions.KeyFields = 'IDPRNT'
    AutoUpdateOptions.GeneratorName = 'GEN_DPRNT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTKOLPRNT: TFIBBCDField
      FieldName = 'KOLPRNT'
      OnChange = DocTKOLPRNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFPRNT: TFIBBCDField
      FieldName = 'KFPRNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEPRNT: TFIBBCDField
      FieldName = 'PRICEPRNT'
      OnChange = DocTPRICEPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMPRNT: TFIBBCDField
      FieldName = 'SUMPRNT'
      OnChange = DocTSUMPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTNAC_DPRNT: TFIBBCDField
      FieldName = 'NAC_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_DPRNT: TFIBBCDField
      FieldName = 'RPRICE_DPRNT'
      OnChange = DocTRPRICE_DPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DPRNT: TFIBBCDField
      FieldName = 'RSUM_DPRNT'
      OnChange = DocTRSUM_DPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTIDPRNT: TFIBLargeIntField
      FieldName = 'IDPRNT'
    end
    object DocTIDDOCPRNT: TFIBLargeIntField
      FieldName = 'IDDOCPRNT'
    end
    object DocTIDNOMPRNT: TFIBLargeIntField
      FieldName = 'IDNOMPRNT'
    end
    object DocTIDEDPRNT: TFIBLargeIntField
      FieldName = 'IDEDPRNT'
    end
    object DocTIDPARTPRNT: TFIBLargeIntField
      FieldName = 'IDPARTPRNT'
    end
    object DocTGID_DPRNT: TFIBWideStringField
      FieldName = 'GID_DPRNT'
      Size = 10
    end
    object DocTIDBASE_DPRNT: TFIBLargeIntField
      FieldName = 'IDBASE_DPRNT'
    end
    object DocTNDS_DPRNT: TFIBIntegerField
      FieldName = 'NDS_DPRNT'
    end
    object DocTSUMNDS_DPRNT: TFIBBCDField
      FieldName = 'SUMNDS_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTGTDPART: TFIBWideStringField
      FieldName = 'GTDPART'
      Size = 200
    end
    object DocTSERTPART: TFIBWideStringField
      FieldName = 'SERTPART'
      Size = 11
    end
    object DocTSRGODNPART: TFIBDateTimeField
      FieldName = 'SRGODNPART'
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTNAC_SUM_ED: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM_ED'
      Size = 0
      RoundByScale = True
      Calculated = True
    end
    object DocTNAC_SUM: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM'
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
    Left = 240
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
    Left = 240
    Top = 64
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 304
    Top = 296
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PRN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 192
    Top = 192
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PRN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PRN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
