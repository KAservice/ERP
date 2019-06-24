object DMDocRev: TDMDocRev
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 401
  Width = 726
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
      
        'select GALLDOC.*, SUSER.* , SFIRM.*, SSKLAD.*, NAME_SINFBASE_OBM' +
        'EN, '
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
      
        'select GALLDOC.*, SUSER.* , SFIRM.*, SSKLAD.*, NAME_SINFBASE_OBM' +
        'EN, '
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
    object DocAllNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
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
    object DocAllFNAMEFIRM: TFIBWideStringField
      FieldName = 'FNAMEFIRM'
      Size = 200
    end
    object DocAllPADRFIRM: TFIBWideStringField
      FieldName = 'PADRFIRM'
      Size = 200
    end
    object DocAllINNFIRM: TFIBWideStringField
      FieldName = 'INNFIRM'
      Size = 12
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
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
      'UPDATE DREV'
      'SET '
      '    GID_DREV = :GID_DREV,'
      '    IDDOC_DREV = :IDDOC_DREV,'
      '    IDINV_DREV = :IDINV_DREV,'
      '    DESCR_DREV = :DESCR_DREV,'
      '    IDRTPRICE_DREV = :IDRTPRICE_DREV,'
      '    IDBASE_DREV = :IDBASE_DREV'
      'WHERE'
      '    ID_DREV = :OLD_ID_DREV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREV'
      'WHERE'
      '        ID_DREV = :OLD_ID_DREV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREV('
      '    ID_DREV,'
      '    GID_DREV,'
      '    IDDOC_DREV,'
      '    IDINV_DREV,'
      '    DESCR_DREV,'
      '    IDRTPRICE_DREV,'
      '    IDBASE_DREV'
      ')'
      'VALUES('
      '    :ID_DREV,'
      '    :GID_DREV,'
      '    :IDDOC_DREV,'
      '    :IDINV_DREV,'
      '    :DESCR_DREV,'
      '    :IDRTPRICE_DREV,'
      '    :IDBASE_DREV'
      ')')
    RefreshSQL.Strings = (
      'select DREV.*, NAME_SINV '
      'from  DREV'
      'left outer join SINV on IDINV_DREV=ID_SINV'
      'where(  IDDOC_DREV=:PARAM_IDDOC'
      '     ) and (     DREV.ID_DREV = :OLD_ID_DREV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREV.*, NAME_SINV '
      'from  DREV'
      'left outer join SINV on IDINV_DREV=ID_SINV'
      'where IDDOC_DREV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DREV'
    AutoUpdateOptions.KeyFields = 'ID_DREV'
    AutoUpdateOptions.GeneratorName = 'GEN_DREV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 64
    poUseLargeIntField = True
    object DocID_DREV: TFIBLargeIntField
      FieldName = 'ID_DREV'
    end
    object DocGID_DREV: TFIBWideStringField
      FieldName = 'GID_DREV'
      Size = 10
    end
    object DocIDDOC_DREV: TFIBLargeIntField
      FieldName = 'IDDOC_DREV'
    end
    object DocIDINV_DREV: TFIBLargeIntField
      FieldName = 'IDINV_DREV'
    end
    object DocDESCR_DREV: TFIBWideStringField
      FieldName = 'DESCR_DREV'
      Size = 100
    end
    object DocIDRTPRICE_DREV: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DREV'
    end
    object DocIDBASE_DREV: TFIBLargeIntField
      FieldName = 'IDBASE_DREV'
    end
    object DocNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
      Size = 100
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
    Top = 64
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREVT'
      'SET '
      '    GID_DREVT = :GID_DREVT,'
      '    IDDOC_DREVT = :IDDOC_DREVT,'
      '    IDNOM_DREVT = :IDNOM_DREVT,'
      '    IDED_DREVT = :IDED_DREVT,'
      '    KOL_DREVT = :KOL_DREVT,'
      '    KF_DREVT = :KF_DREVT,'
      '    RPRICE_DREVT = :RPRICE_DREVT,'
      '    RSUM_DREVT = :RSUM_DREVT,'
      '    IDBASE_DREVT = :IDBASE_DREVT,'
      '    UCH_KOL_DREVT = :UCH_KOL_DREVT,'
      '    UCH_RSUM_DREVT = :UCH_RSUM_DREVT,'
      '    UCH_SUM_DREVT = :UCH_SUM_DREVT'
      'WHERE'
      '    ID_DREVT = :OLD_ID_DREVT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREVT'
      'WHERE'
      '        ID_DREVT = :OLD_ID_DREVT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREVT('
      '    ID_DREVT,'
      '    GID_DREVT,'
      '    IDDOC_DREVT,'
      '    IDNOM_DREVT,'
      '    IDED_DREVT,'
      '    KOL_DREVT,'
      '    KF_DREVT,'
      '    RPRICE_DREVT,'
      '    RSUM_DREVT,'
      '    IDBASE_DREVT,'
      '    UCH_KOL_DREVT,'
      '    UCH_RSUM_DREVT,'
      '    UCH_SUM_DREVT'
      ')'
      'VALUES('
      '    :ID_DREVT,'
      '    :GID_DREVT,'
      '    :IDDOC_DREVT,'
      '    :IDNOM_DREVT,'
      '    :IDED_DREVT,'
      '    :KOL_DREVT,'
      '    :KF_DREVT,'
      '    :RPRICE_DREVT,'
      '    :RSUM_DREVT,'
      '    :IDBASE_DREVT,'
      '    :UCH_KOL_DREVT,'
      '    :UCH_RSUM_DREVT,'
      '    :UCH_SUM_DREVT'
      ')')
    RefreshSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, DREVT.*, NAMEED'
      'from '
      'DREVT LEFT OUTER JOIN SNOM  ON IDNOM_DREVT=IDNOM '
      'left outer join SED  on  IDED_DREVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where(  IDDOC_DREVT=:PARAM_IDDOC'
      '     ) and (     DREVT.ID_DREVT = :OLD_ID_DREVT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, DREVT.*, NAMEED'
      'from '
      'DREVT LEFT OUTER JOIN SNOM  ON IDNOM_DREVT=IDNOM '
      'left outer join SED  on  IDED_DREVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_DREVT=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DREVT'
    AutoUpdateOptions.KeyFields = 'ID_DREVT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREVT_ID'
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
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTKOL_DREVT: TFIBBCDField
      FieldName = 'KOL_DREVT'
      OnChange = DocTKOL_DREVTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DREVT: TFIBBCDField
      FieldName = 'KF_DREVT'
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_DREVT: TFIBBCDField
      FieldName = 'RPRICE_DREVT'
      OnChange = DocTRPRICE_DREVTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DREVT: TFIBBCDField
      FieldName = 'RSUM_DREVT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object DocTIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTID_DREVT: TFIBLargeIntField
      FieldName = 'ID_DREVT'
    end
    object DocTGID_DREVT: TFIBWideStringField
      FieldName = 'GID_DREVT'
      Size = 10
    end
    object DocTIDDOC_DREVT: TFIBLargeIntField
      FieldName = 'IDDOC_DREVT'
    end
    object DocTIDNOM_DREVT: TFIBLargeIntField
      FieldName = 'IDNOM_DREVT'
    end
    object DocTIDED_DREVT: TFIBLargeIntField
      FieldName = 'IDED_DREVT'
    end
    object DocTIDBASE_DREVT: TFIBLargeIntField
      FieldName = 'IDBASE_DREVT'
    end
    object DocTIDEXT_DOUT_DREVT: TFIBLargeIntField
      FieldName = 'IDEXT_DOUT_DREVT'
    end
    object DocTIDEXT_BASE_DREVT: TFIBLargeIntField
      FieldName = 'IDEXT_BASE_DREVT'
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTUCH_KOL_DREVT: TFIBBCDField
      FieldName = 'UCH_KOL_DREVT'
      Size = 3
      RoundByScale = True
    end
    object DocTUCH_RSUM_DREVT: TFIBBCDField
      FieldName = 'UCH_RSUM_DREVT'
      Size = 2
      RoundByScale = True
    end
    object DocTUCH_SUM_DREVT: TFIBBCDField
      FieldName = 'UCH_SUM_DREVT'
      Size = 2
      RoundByScale = True
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
      
        'from DOC_REV_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 336
    Top = 16
  end
  object IBQPoGrp: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, DREVT.*, NAMEED'
      'from DREVT'
      'LEFT OUTER JOIN SNOM  ON IDNOM_DREVT=IDNOM '
      'left outer join SED  on  IDED_DREVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_DREVT=:PARAM_IDDOC'
      'order by sgrpnom.namegn, snom.namenom')
    Transaction = IBTr
    Left = 264
    Top = 200
    poUseLargeIntField = True
    object IBQPoGrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object IBQPoGrpIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object IBQPoGrpNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQPoGrpTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object IBQPoGrpCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object IBQPoGrpID_DREVT: TFIBLargeIntField
      FieldName = 'ID_DREVT'
    end
    object IBQPoGrpIDDOC_DREVT: TFIBLargeIntField
      FieldName = 'IDDOC_DREVT'
    end
    object IBQPoGrpIDNOM_DREVT: TFIBLargeIntField
      FieldName = 'IDNOM_DREVT'
    end
    object IBQPoGrpIDED_DREVT: TFIBLargeIntField
      FieldName = 'IDED_DREVT'
    end
    object IBQPoGrpKOL_DREVT: TFIBBCDField
      FieldName = 'KOL_DREVT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpKF_DREVT: TFIBBCDField
      FieldName = 'KF_DREVT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpRPRICE_DREVT: TFIBBCDField
      FieldName = 'RPRICE_DREVT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpRSUM_DREVT: TFIBBCDField
      FieldName = 'RSUM_DREVT'
      Size = 2
      RoundByScale = True
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
      'EXECUTE PROCEDURE DOC_REV_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REV_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
  object Ostatki: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, sum(rgostnom' +
        '.kolostnom)'
      ' from rgostnom'
      'left outer join SNOM on IDNOM=rgostnom.idnomostnom'
      'left outer join sed on sed.ided=snom.idbasednom'
      'where rgostnom.idsklostnom=:PARAM_IDSKLAD'
      '  and rgostnom.idfirmostnom=:PARAM_IDFIRM'
      'group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED'
      'order by NAMENOM')
    Transaction = IBTr
    Left = 352
    Top = 192
    poUseLargeIntField = True
    object OstatkiKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object OstatkiSUM: TFIBBCDField
      FieldName = 'SUM'
      Size = 3
      RoundByScale = True
    end
    object OstatkiIDNOM: TFIBLargeIntField
      FieldName = 'IDNOM'
    end
    object OstatkiCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object OstatkiNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object OstatkiIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object OstatkiNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
end
