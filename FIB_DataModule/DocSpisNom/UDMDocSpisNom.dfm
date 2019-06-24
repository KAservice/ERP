object DMDocSpisNom: TDMDocSpisNom
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 399
  Width = 751
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD, '
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD, '
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
    Left = 168
    Top = 16
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
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
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
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
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
    object DocAllIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBBCDField
      FieldName = 'IDBUSINOP_GALLDOC'
      Size = 0
      RoundByScale = True
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
      'UPDATE DSPN'
      'SET '
      '    IDDOCSPN = :IDDOCSPN,'
      '    PRIMSPN = :PRIMSPN,'
      '    GID_DSPN = :GID_DSPN,'
      '    IDRTPRICE_DSPN = :IDRTPRICE_DSPN,'
      '    RSUM_DSPN = :RSUM_DSPN,'
      '    IDBASE_DSPN = :IDBASE_DSPN'
      'WHERE'
      '    IDSPN = :OLD_IDSPN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSPN'
      'WHERE'
      '        IDSPN = :OLD_IDSPN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSPN('
      '    IDSPN,'
      '    IDDOCSPN,'
      '    PRIMSPN,'
      '    GID_DSPN,'
      '    IDRTPRICE_DSPN,'
      '    RSUM_DSPN,'
      '    IDBASE_DSPN'
      ')'
      'VALUES('
      '    :IDSPN,'
      '    :IDDOCSPN,'
      '    :PRIMSPN,'
      '    :GID_DSPN,'
      '    :IDRTPRICE_DSPN,'
      '    :RSUM_DSPN,'
      '    :IDBASE_DSPN'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DSPN'
      'where(  IDDOCSPN=:ID'
      '     ) and (     DSPN.IDSPN = :OLD_IDSPN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DSPN'
      'where IDDOCSPN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DSPN'
    AutoUpdateOptions.KeyFields = 'IDSPN'
    AutoUpdateOptions.GeneratorName = 'GEN_DSPN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    object DocRSUM_DSPN: TFIBBCDField
      FieldName = 'RSUM_DSPN'
      Size = 2
      RoundByScale = True
    end
    object DocIDSPN: TFIBBCDField
      FieldName = 'IDSPN'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOCSPN: TFIBBCDField
      FieldName = 'IDDOCSPN'
      Size = 0
      RoundByScale = True
    end
    object DocIDRTPRICE_DSPN: TFIBBCDField
      FieldName = 'IDRTPRICE_DSPN'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DSPN: TFIBBCDField
      FieldName = 'IDBASE_DSPN'
      Size = 0
      RoundByScale = True
    end
    object DocPRIMSPN: TFIBWideStringField
      FieldName = 'PRIMSPN'
      Size = 100
    end
    object DocGID_DSPN: TFIBWideStringField
      FieldName = 'GID_DSPN'
      Size = 10
    end
    object DocOPER_DSPN: TFIBIntegerField
      FieldName = 'OPER_DSPN'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DSPNT'
      'SET '
      '    IDDOCSPNT = :IDDOCSPNT,'
      '    IDNOMSPNT = :IDNOMSPNT,'
      '    IDEDSPNT = :IDEDSPNT,'
      '    KOLSPNT = :KOLSPNT,'
      '    KFSPNT = :KFSPNT,'
      '    PRICESPNT = :PRICESPNT,'
      '    SUMSPNT = :SUMSPNT,'
      '    GID_DSPNT = :GID_DSPNT,'
      '    RPRICE_DSPNT = :RPRICE_DSPNT,'
      '    RSUM_DSPNT = :RSUM_DSPNT,'
      '    IDBASE_DSPNT = :IDBASE_DSPNT'
      'WHERE'
      '    IDSPNT = :OLD_IDSPNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSPNT'
      'WHERE'
      '        IDSPNT = :OLD_IDSPNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSPNT('
      '    IDSPNT,'
      '    IDDOCSPNT,'
      '    IDNOMSPNT,'
      '    IDEDSPNT,'
      '    KOLSPNT,'
      '    KFSPNT,'
      '    PRICESPNT,'
      '    SUMSPNT,'
      '    GID_DSPNT,'
      '    RPRICE_DSPNT,'
      '    RSUM_DSPNT,'
      '    IDBASE_DSPNT'
      ')'
      'VALUES('
      '    :IDSPNT,'
      '    :IDDOCSPNT,'
      '    :IDNOMSPNT,'
      '    :IDEDSPNT,'
      '    :KOLSPNT,'
      '    :KFSPNT,'
      '    :PRICESPNT,'
      '    :SUMSPNT,'
      '    :GID_DSPNT,'
      '    :RPRICE_DSPNT,'
      '    :RSUM_DSPNT,'
      '    :IDBASE_DSPNT'
      ')')
    RefreshSQL.Strings = (
      'select DSPNT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DSPNT LEFT OUTER JOIN SNOM  ON IDNOMSPNT=IDNOM '
      'left outer join SED  on  IDEDSPNT=IDED'
      'where(  IDDOCSPNT=:ID'
      '     ) and (     DSPNT.IDSPNT = :OLD_IDSPNT'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select DSPNT.*,'
      ' NAMENOM,'
      ' NAMEED ,'
      ' TNOM,'
      ' snom.artnom,'
      ' snom.codenom, '
      ' sed.shed'
      'from '
      'DSPNT LEFT OUTER JOIN SNOM  ON IDNOMSPNT=IDNOM '
      'left outer join SED  on  IDEDSPNT=IDED'
      'where IDDOCSPNT=:ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'DSPNT'
    AutoUpdateOptions.KeyFields = 'IDSPNT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSPNT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 120
    object DocTKOLSPNT: TFIBBCDField
      FieldName = 'KOLSPNT'
      OnChange = DocTKOLSPNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFSPNT: TFIBBCDField
      FieldName = 'KFSPNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICESPNT: TFIBBCDField
      FieldName = 'PRICESPNT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSPNT: TFIBBCDField
      FieldName = 'SUMSPNT'
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
    object DocTRPRICE_DSPNT: TFIBBCDField
      FieldName = 'RPRICE_DSPNT'
      OnChange = DocTRPRICE_DSPNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DSPNT: TFIBBCDField
      FieldName = 'RSUM_DSPNT'
      Size = 2
      RoundByScale = True
    end
    object DocTIDSPNT: TFIBBCDField
      FieldName = 'IDSPNT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOCSPNT: TFIBBCDField
      FieldName = 'IDDOCSPNT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOMSPNT: TFIBBCDField
      FieldName = 'IDNOMSPNT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDEDSPNT: TFIBBCDField
      FieldName = 'IDEDSPNT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DSPNT: TFIBBCDField
      FieldName = 'IDBASE_DSPNT'
      Size = 0
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
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    Left = 256
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
    Left = 256
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
    Left = 144
    Top = 184
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_SPN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 328
    Top = 16
  end
  object Grp: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMEGN, IDGN,SUM(SUMSPNT)  AS SUMMA'
      ''
      'from '
      '  DSPNT'
      'left outer join SNOM on IDNOMSPNT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'where IDDOCSPNT=:PARAM_IDDOC'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Left = 216
    Top = 184
    object GrpSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object GrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object GrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
  end
  object El: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMENOM, NAMEED, SUM(SUMSPNT)  AS SUMMA, SUM(KFSPNT*KOLS' +
        'PNT)  AS SUMKOL'
      'from '
      '  DSPNT'
      'left outer join SNOM on IDNOMSPNT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      'where IDDOCSPNT=:PARAM_IDDOC'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED')
    Transaction = IBTr
    Left = 248
    Top = 184
    object ElSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object ElSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
    object ElNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object ElNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object DocOsn: TpFIBDataSet
    SelectSQL.Strings = (
      'select TDOC, NUMDOC, POSDOC from GALLDOC'
      'where IDDOC=:PARAM_IDDOC')
    Transaction = IBTr
    Left = 328
    Top = 72
    object DocOsnNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocOsnPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object DocOsnTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 328
    Top = 184
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SPN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SPN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
