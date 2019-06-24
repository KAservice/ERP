object DMDocSpOtrOst: TDMDocSpOtrOst
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 393
  Width = 385
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
      'select GALLDOC.*, '
      ' SUSER.NAME_USER ,SUSER.FNAME_USER ,'
      ' SFIRM.NAMEFIRM, '
      ' SSKLAD.NAMESKLAD,'
      ' NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:PARAM_IDDOC'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*, '
      ' SUSER.NAME_USER ,SUSER.FNAME_USER ,'
      ' SFIRM.NAMEFIRM, '
      ' SSKLAD.NAMESKLAD,'
      ' NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:PARAM_IDDOC ')
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
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
    end
    object DocAllNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
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
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
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
      'UPDATE DSPOTROST'
      'SET '
      '    IDDOC_DSPOTROST = :IDDOC_DSPOTROST,'
      '    GID_DSPOTROST = :GID_DSPOTROST,'
      '    DESCR_DSPOTROST = :DESCR_DSPOTROST,'
      '    IDRTPRICE_DSPOTROST = :IDRTPRICE_DSPOTROST,'
      '    RSUM_DSPOTROST = :RSUM_DSPOTROST,'
      '    IDBASE_DSPOTROST = :IDBASE_DSPOTROST'
      'WHERE'
      '    ID_DSPOTROST = :OLD_ID_DSPOTROST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSPOTROST'
      'WHERE'
      '        ID_DSPOTROST = :OLD_ID_DSPOTROST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSPOTROST('
      '    ID_DSPOTROST,'
      '    IDDOC_DSPOTROST,'
      '    GID_DSPOTROST,'
      '    DESCR_DSPOTROST,'
      '    IDRTPRICE_DSPOTROST,'
      '    RSUM_DSPOTROST,'
      '    IDBASE_DSPOTROST'
      ')'
      'VALUES('
      '    :ID_DSPOTROST,'
      '    :IDDOC_DSPOTROST,'
      '    :GID_DSPOTROST,'
      '    :DESCR_DSPOTROST,'
      '    :IDRTPRICE_DSPOTROST,'
      '    :RSUM_DSPOTROST,'
      '    :IDBASE_DSPOTROST'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DSPOTROST'
      'where(  IDDOC_DSPOTROST=:PARAM_IDDOC'
      '     ) and (     DSPOTROST.ID_DSPOTROST = :OLD_ID_DSPOTROST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DSPOTROST'
      'where IDDOC_DSPOTROST=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DSPOTROST'
    AutoUpdateOptions.KeyFields = 'ID_DSPOTROST'
    AutoUpdateOptions.GeneratorName = 'GEN_DSPOTROST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 64
    poUseLargeIntField = True
    object DocID_DSPOTROST: TFIBLargeIntField
      FieldName = 'ID_DSPOTROST'
    end
    object DocIDDOC_DSPOTROST: TFIBLargeIntField
      FieldName = 'IDDOC_DSPOTROST'
    end
    object DocGID_DSPOTROST: TFIBWideStringField
      FieldName = 'GID_DSPOTROST'
      Size = 10
    end
    object DocDESCR_DSPOTROST: TFIBWideStringField
      FieldName = 'DESCR_DSPOTROST'
      Size = 150
    end
    object DocIDRTPRICE_DSPOTROST: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DSPOTROST'
    end
    object DocRSUM_DSPOTROST: TFIBBCDField
      FieldName = 'RSUM_DSPOTROST'
      Size = 2
      RoundByScale = True
    end
    object DocIDBASE_DSPOTROST: TFIBLargeIntField
      FieldName = 'IDBASE_DSPOTROST'
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
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 264
    Top = 64
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DSPOTROSTT'
      'SET '
      '    IDDOC_DSPOTROSTT = :IDDOC_DSPOTROSTT,'
      '    GID_DSPOTROSTT = :GID_DSPOTROSTT,'
      '    IDNOM_DSPOTROSTT = :IDNOM_DSPOTROSTT,'
      '    IDED_DSPOTROSTT = :IDED_DSPOTROSTT,'
      '    IDPART_DSPOTROSTT = :IDPART_DSPOTROSTT,'
      '    KOL_DSPOTROSTT = :KOL_DSPOTROSTT,'
      '    KF_DSPOTROSTT = :KF_DSPOTROSTT,'
      '    PRICE_DSPOTROSTT = :PRICE_DSPOTROSTT,'
      '    SUM_DSPOTROSTT = :SUM_DSPOTROSTT,'
      '    RPRICE_DSPOTROSTT = :RPRICE_DSPOTROSTT,'
      '    RSUM_DSPOTROSTT = :RSUM_DSPOTROSTT,'
      '    IDBASE_DSPOTROSTT = :IDBASE_DSPOTROSTT'
      'WHERE'
      '    ID_DSPOTROSTT = :OLD_ID_DSPOTROSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSPOTROSTT'
      'WHERE'
      '        ID_DSPOTROSTT = :OLD_ID_DSPOTROSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSPOTROSTT('
      '    ID_DSPOTROSTT,'
      '    IDDOC_DSPOTROSTT,'
      '    GID_DSPOTROSTT,'
      '    IDNOM_DSPOTROSTT,'
      '    IDED_DSPOTROSTT,'
      '    IDPART_DSPOTROSTT,'
      '    KOL_DSPOTROSTT,'
      '    KF_DSPOTROSTT,'
      '    PRICE_DSPOTROSTT,'
      '    SUM_DSPOTROSTT,'
      '    RPRICE_DSPOTROSTT,'
      '    RSUM_DSPOTROSTT,'
      '    IDBASE_DSPOTROSTT'
      ')'
      'VALUES('
      '    :ID_DSPOTROSTT,'
      '    :IDDOC_DSPOTROSTT,'
      '    :GID_DSPOTROSTT,'
      '    :IDNOM_DSPOTROSTT,'
      '    :IDED_DSPOTROSTT,'
      '    :IDPART_DSPOTROSTT,'
      '    :KOL_DSPOTROSTT,'
      '    :KF_DSPOTROSTT,'
      '    :PRICE_DSPOTROSTT,'
      '    :SUM_DSPOTROSTT,'
      '    :RPRICE_DSPOTROSTT,'
      '    :RSUM_DSPOTROSTT,'
      '    :IDBASE_DSPOTROSTT'
      ')')
    RefreshSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, '
      'DSPOTROSTT.*, NAMEED'
      'from '
      'DSPOTROSTT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DSPOTROSTT=IDNOM '
      'left outer join SED  on  IDED_DSPOTROSTT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where(  IDDOC_DSPOTROSTT=:PARAM_IDDOC'
      '     ) and (     DSPOTROSTT.ID_DSPOTROSTT = :OLD_ID_DSPOTROSTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, '
      'DSPOTROSTT.*, NAMEED'
      'from '
      'DSPOTROSTT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DSPOTROSTT=IDNOM '
      'left outer join SED  on  IDED_DSPOTROSTT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_DSPOTROSTT=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DSPOTROSTT'
    AutoUpdateOptions.KeyFields = 'ID_DSPOTROSTT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSPOTROSTT_ID'
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTID_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'ID_DSPOTROSTT'
    end
    object DocTIDDOC_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'IDDOC_DSPOTROSTT'
    end
    object DocTGID_DSPOTROSTT: TFIBWideStringField
      FieldName = 'GID_DSPOTROSTT'
      Size = 10
    end
    object DocTIDNOM_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'IDNOM_DSPOTROSTT'
    end
    object DocTIDED_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'IDED_DSPOTROSTT'
    end
    object DocTIDPART_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'IDPART_DSPOTROSTT'
    end
    object DocTKOL_DSPOTROSTT: TFIBBCDField
      FieldName = 'KOL_DSPOTROSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DSPOTROSTT: TFIBBCDField
      FieldName = 'KF_DSPOTROSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_DSPOTROSTT: TFIBBCDField
      FieldName = 'PRICE_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_DSPOTROSTT: TFIBBCDField
      FieldName = 'SUM_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_DSPOTROSTT: TFIBBCDField
      FieldName = 'RPRICE_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DSPOTROSTT: TFIBBCDField
      FieldName = 'RSUM_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTIDBASE_DSPOTROSTT: TFIBLargeIntField
      FieldName = 'IDBASE_DSPOTROSTT'
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
    Left = 168
    Top = 200
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_SPOTROST_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:' +
        'PARAM_IDSKLAD)')
    Transaction = IBTr
    Left = 336
    Top = 16
  end
  object IBQPoGrp: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom,'
      'DSPOTROSTT.*, NAMEED'
      'from DSPOTROSTT'
      'LEFT OUTER JOIN SNOM  ON IDNOM_DSPOTROSTT=IDNOM '
      'left outer join SED  on  IDED_DSPOTROSTT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_DSPOTROSTT=:PARAM_IDDOC'
      'order by sgrpnom.namegn, snom.namenom')
    Transaction = IBTr
    Left = 264
    Top = 200
    object IBQPoGrpTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object IBQPoGrpCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object IBQPoGrpKOL_DSPOTROSTT: TFIBBCDField
      FieldName = 'KOL_DSPOTROSTT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpKF_DSPOTROSTT: TFIBBCDField
      FieldName = 'KF_DSPOTROSTT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpPRICE_DSPOTROSTT: TFIBBCDField
      FieldName = 'PRICE_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpSUM_DSPOTROSTT: TFIBBCDField
      FieldName = 'SUM_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpRPRICE_DSPOTROSTT: TFIBBCDField
      FieldName = 'RPRICE_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpRSUM_DSPOTROSTT: TFIBBCDField
      FieldName = 'RSUM_DSPOTROSTT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpID_DSPOTROSTT: TFIBBCDField
      FieldName = 'ID_DSPOTROSTT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDDOC_DSPOTROSTT: TFIBBCDField
      FieldName = 'IDDOC_DSPOTROSTT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDNOM_DSPOTROSTT: TFIBBCDField
      FieldName = 'IDNOM_DSPOTROSTT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDED_DSPOTROSTT: TFIBBCDField
      FieldName = 'IDED_DSPOTROSTT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDPART_DSPOTROSTT: TFIBBCDField
      FieldName = 'IDPART_DSPOTROSTT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object IBQPoGrpNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQPoGrpNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 336
    Top = 120
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SPOTROST_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SPOTROST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
