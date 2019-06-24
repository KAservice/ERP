object DMDocOstNom: TDMDocOstNom
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 381
  Width = 633
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
      '    PREFIKS_NUM_GALLDOC = :PREFIKS_NUM_GALLDOC,'
      '    IDOBJECT_GALLDOC = :IDOBJECT_GALLDOC'
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
      '    PREFIKS_NUM_GALLDOC,'
      '    IDOBJECT_GALLDOC'
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
      '    :PREFIKS_NUM_GALLDOC,'
      '    :IDOBJECT_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join sobject on galldoc.idobject_galldoc=sobject.id_s' +
        'object'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join sobject on galldoc.idobject_galldoc=sobject.id_s' +
        'object'
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
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 15
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
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
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
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
    object DocAllIDOBJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDOBJECT_GALLDOC'
    end
    object DocAllNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DOSN'
      'SET '
      '    IDDOCOSN = :IDDOCOSN,'
      '    PRIMOSN = :PRIMOSN,'
      '    IDTPRICEOSN = :IDTPRICEOSN,'
      '    GID_DOSN = :GID_DOSN,'
      '    IDRTPRICE_DOSN = :IDRTPRICE_DOSN,'
      '    RSUM_DOSN = :RSUM_DOSN,'
      '    IDBASE_DOSN = :IDBASE_DOSN'
      'WHERE'
      '    IDOSN = :OLD_IDOSN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DOSN'
      'WHERE'
      '        IDOSN = :OLD_IDOSN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DOSN('
      '    IDOSN,'
      '    IDDOCOSN,'
      '    PRIMOSN,'
      '    IDTPRICEOSN,'
      '    GID_DOSN,'
      '    IDRTPRICE_DOSN,'
      '    RSUM_DOSN,'
      '    IDBASE_DOSN'
      ')'
      'VALUES('
      '    :IDOSN,'
      '    :IDDOCOSN,'
      '    :PRIMOSN,'
      '    :IDTPRICEOSN,'
      '    :GID_DOSN,'
      '    :IDRTPRICE_DOSN,'
      '    :RSUM_DOSN,'
      '    :IDBASE_DOSN'
      ')')
    RefreshSQL.Strings = (
      'select DOSN.*, NAME_TPRICE '
      ' from DOSN'
      'left outer join STPRICE on IDTPRICEOSN=ID_TPRICE'
      'where(  IDDOCOSN=:ID'
      '     ) and (     DOSN.IDOSN = :OLD_IDOSN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DOSN.*, NAME_TPRICE '
      ' from DOSN'
      'left outer join STPRICE on IDTPRICEOSN=ID_TPRICE'
      'where IDDOCOSN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DOSN'
    AutoUpdateOptions.KeyFields = 'IDOSN'
    AutoUpdateOptions.GeneratorName = 'GEN_DOSN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 64
    poUseLargeIntField = True
    object DocRSUM_DOSN: TFIBBCDField
      FieldName = 'RSUM_DOSN'
      Size = 2
      RoundByScale = True
    end
    object DocIDOSN: TFIBLargeIntField
      FieldName = 'IDOSN'
    end
    object DocIDDOCOSN: TFIBLargeIntField
      FieldName = 'IDDOCOSN'
    end
    object DocPRIMOSN: TFIBWideStringField
      FieldName = 'PRIMOSN'
      Size = 100
    end
    object DocIDTPRICEOSN: TFIBLargeIntField
      FieldName = 'IDTPRICEOSN'
    end
    object DocGID_DOSN: TFIBWideStringField
      FieldName = 'GID_DOSN'
      Size = 10
    end
    object DocIDRTPRICE_DOSN: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DOSN'
    end
    object DocIDBASE_DOSN: TFIBLargeIntField
      FieldName = 'IDBASE_DOSN'
    end
    object DocOPER_DOSN: TFIBIntegerField
      FieldName = 'OPER_DOSN'
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
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
    Top = 168
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
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
    Left = 248
    Top = 64
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DOSNT'
      'SET '
      '    IDDOCOSNT = :IDDOCOSNT,'
      '    IDNOMOSNT = :IDNOMOSNT,'
      '    IDEDOSNT = :IDEDOSNT,'
      '    IDPARTOSNT = :IDPARTOSNT,'
      '    KOLOSNT = :KOLOSNT,'
      '    KFOSNT = :KFOSNT,'
      '    PRICEOSNT = :PRICEOSNT,'
      '    SUMOSNT = :SUMOSNT,'
      '    GID_DOSNT = :GID_DOSNT,'
      '    RPRICE_DOSNT = :RPRICE_DOSNT,'
      '    RSUM_DOSNT = :RSUM_DOSNT,'
      '    NAC_DOSNT = :NAC_DOSNT,'
      '    IDBASE_DOSNT = :IDBASE_DOSNT,'
      '    NDS_DOSNT = :NDS_DOSNT,'
      '    SUMNDS_DOSNT = :SUMNDS_DOSNT,'
      '    IDTNOM_DOSNT = :IDTNOM_DOSNT'
      'WHERE'
      '    IDOSNT = :OLD_IDOSNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DOSNT'
      'WHERE'
      '        IDOSNT = :OLD_IDOSNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DOSNT('
      '    IDOSNT,'
      '    IDDOCOSNT,'
      '    IDNOMOSNT,'
      '    IDEDOSNT,'
      '    IDPARTOSNT,'
      '    KOLOSNT,'
      '    KFOSNT,'
      '    PRICEOSNT,'
      '    SUMOSNT,'
      '    GID_DOSNT,'
      '    RPRICE_DOSNT,'
      '    RSUM_DOSNT,'
      '    NAC_DOSNT,'
      '    IDBASE_DOSNT,'
      '    NDS_DOSNT,'
      '    SUMNDS_DOSNT,'
      '    IDTNOM_DOSNT'
      ')'
      'VALUES('
      '    :IDOSNT,'
      '    :IDDOCOSNT,'
      '    :IDNOMOSNT,'
      '    :IDEDOSNT,'
      '    :IDPARTOSNT,'
      '    :KOLOSNT,'
      '    :KFOSNT,'
      '    :PRICEOSNT,'
      '    :SUMOSNT,'
      '    :GID_DOSNT,'
      '    :RPRICE_DOSNT,'
      '    :RSUM_DOSNT,'
      '    :NAC_DOSNT,'
      '    :IDBASE_DOSNT,'
      '    :NDS_DOSNT,'
      '    :SUMNDS_DOSNT,'
      '    :IDTNOM_DOSNT'
      ')')
    RefreshSQL.Strings = (
      'select DOSNT.*,'
      '    NAMENOM,'
      '    NAMEED ,'
      '    TNOM,'
      '  SPART.GTDPART,'
      '  SPART.SERTPART,'
      '  SPART.SRGODNPART,'
      '  snom.artnom,'
      '  snom.codenom, '
      '  sed.shed'
      'from '
      'DOSNT LEFT OUTER JOIN SNOM  ON IDNOMOSNT=IDNOM '
      'left outer join SED  on  IDEDOSNT=IDED'
      'left outer join SPART on IDPARTOSNT=IDPART'
      'where(  IDDOCOSNT=:ID'
      '     ) and (     DOSNT.IDOSNT = :OLD_IDOSNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DOSNT.*,'
      '    NAMENOM,'
      '    NAMEED ,'
      '    TNOM,'
      '  SPART.GTDPART,'
      '  SPART.SERTPART,'
      '  SPART.SRGODNPART,'
      '  snom.artnom,'
      '  snom.codenom, '
      '  sed.shed'
      'from '
      'DOSNT LEFT OUTER JOIN SNOM  ON IDNOMOSNT=IDNOM '
      'left outer join SED  on  IDEDOSNT=IDED'
      'left outer join SPART on IDPARTOSNT=IDPART'
      'where IDDOCOSNT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DOSNT'
    AutoUpdateOptions.KeyFields = 'IDOSNT'
    AutoUpdateOptions.GeneratorName = 'GEN_DOSNT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 112
    poUseLargeIntField = True
    object DocTKOLOSNT: TFIBBCDField
      FieldName = 'KOLOSNT'
      OnChange = DocTKOLOSNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFOSNT: TFIBBCDField
      FieldName = 'KFOSNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEOSNT: TFIBBCDField
      FieldName = 'PRICEOSNT'
      OnChange = DocTPRICEOSNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMOSNT: TFIBBCDField
      FieldName = 'SUMOSNT'
      OnChange = DocTSUMOSNTChange
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
    object DocTRPRICE_DOSNT: TFIBBCDField
      FieldName = 'RPRICE_DOSNT'
      OnChange = DocTRPRICE_DOSNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DOSNT: TFIBBCDField
      FieldName = 'RSUM_DOSNT'
      OnChange = DocTRSUM_DOSNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_DOSNT: TFIBBCDField
      FieldName = 'NAC_DOSNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_DOSNT: TFIBIntegerField
      FieldName = 'NDS_DOSNT'
    end
    object DocTSUMNDS_DOSNT: TFIBBCDField
      FieldName = 'SUMNDS_DOSNT'
      Size = 2
      RoundByScale = True
    end
    object DocTSRGODNPART: TFIBDateTimeField
      FieldName = 'SRGODNPART'
      DisplayFormat = 'c'
    end
    object DocTIDOSNT: TFIBLargeIntField
      FieldName = 'IDOSNT'
    end
    object DocTIDDOCOSNT: TFIBLargeIntField
      FieldName = 'IDDOCOSNT'
    end
    object DocTIDNOMOSNT: TFIBLargeIntField
      FieldName = 'IDNOMOSNT'
    end
    object DocTIDEDOSNT: TFIBLargeIntField
      FieldName = 'IDEDOSNT'
    end
    object DocTIDPARTOSNT: TFIBLargeIntField
      FieldName = 'IDPARTOSNT'
    end
    object DocTGID_DOSNT: TFIBWideStringField
      FieldName = 'GID_DOSNT'
      Size = 10
    end
    object DocTIDBASE_DOSNT: TFIBLargeIntField
      FieldName = 'IDBASE_DOSNT'
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
    object DocTIDTNOM_DOSNT: TFIBLargeIntField
      FieldName = 'IDTNOM_DOSNT'
    end
    object DocTNAME_TYPE_NOM: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NOM_LOOCUP'
      LookupDataSet = TypeNom
      LookupKeyFields = 'ID_STNOM'
      LookupResultField = 'NAME_STNOM'
      KeyFields = 'IDTNOM_DOSNT'
      Size = 50
      Lookup = True
    end
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_OSN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 304
    Top = 16
  end
  object Grp: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMEGN, IDGN,SUM(SUMOSNT)  AS SUMMA'
      ''
      'from '
      '  DOSNT'
      'left outer join SNOM on IDNOMOSNT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'where IDDOCOSNT=:PARAM_IDDOC'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Left = 48
    Top = 208
    poUseLargeIntField = True
    object GrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object GrpIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object GrpSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
  end
  object El: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  NAMENOM, NAMEED, SUM(SUMOSNT)  AS SUMMA, SUM(KFOSNT*KOLO' +
        'SNT)  AS SUMKOL'
      'from '
      '  DOSNT'
      'left outer join SNOM on IDNOMOSNT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      'where IDDOCOSNT=:PARAM_IDDOC'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED')
    Transaction = IBTr
    Left = 104
    Top = 208
    poUseLargeIntField = True
    object ElNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object ElNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object ElSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object ElSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 352
    Top = 160
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 392
    Top = 160
    qoStartTransaction = True
  end
  object DocOsn: TpFIBDataSet
    SelectSQL.Strings = (
      'select TDOC, NUMDOC, POSDOC from GALLDOC'
      'where IDDOC=:PARAM_IDDOC')
    Transaction = IBTr
    Left = 360
    Top = 88
    poUseLargeIntField = True
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
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_OSN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_OSN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
  object TypeNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnom.id_stnom,'
      '       stnom.name_stnom'
      'from stnom'
      'order by stnom.name_stnom')
    Transaction = IBTr
    Left = 360
    Top = 232
    poUseLargeIntField = True
    object TypeNomID_STNOM: TFIBLargeIntField
      FieldName = 'ID_STNOM'
    end
    object TypeNomNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
  end
end
