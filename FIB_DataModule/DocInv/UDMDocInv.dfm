object DMDocInv: TDMDocInv
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 414
  Width = 496
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
      'select GALLDOC.*,'
      ' FNAME_USER,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' FNAMEFIRM,'
      ' INNFIRM,'
      ' PADRFIRM,'
      ' NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN= IDBASE_GALL' +
        'DOC'
      
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
      'select GALLDOC.*,'
      ' FNAME_USER,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' FNAMEFIRM,'
      ' INNFIRM,'
      ' PADRFIRM,'
      ' NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN= IDBASE_GALL' +
        'DOC'
      
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
      DisplayFormat = 'c'
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
    object DocAllFNAMEFIRM: TFIBWideStringField
      FieldName = 'FNAMEFIRM'
      Size = 200
    end
    object DocAllINNFIRM: TFIBWideStringField
      FieldName = 'INNFIRM'
      Size = 12
    end
    object DocAllPADRFIRM: TFIBWideStringField
      FieldName = 'PADRFIRM'
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
      'UPDATE DINV'
      'SET '
      '    IDDOC_INV = :IDDOC_INV,'
      '    PRIM_INV = :PRIM_INV,'
      '    GID_INV = :GID_INV,'
      '    IDTPRICE_INV = :IDTPRICE_INV,'
      '    IDINV_INV = :IDINV_INV,'
      '    TYPE_INV = :TYPE_INV,'
      '    IDBASE_DINV = :IDBASE_DINV'
      'WHERE'
      '    ID_INV = :OLD_ID_INV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DINV'
      'WHERE'
      '        ID_INV = :OLD_ID_INV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DINV('
      '    ID_INV,'
      '    IDDOC_INV,'
      '    PRIM_INV,'
      '    GID_INV,'
      '    IDTPRICE_INV,'
      '    IDINV_INV,'
      '    TYPE_INV,'
      '    IDBASE_DINV'
      ')'
      'VALUES('
      '    :ID_INV,'
      '    :IDDOC_INV,'
      '    :PRIM_INV,'
      '    :GID_INV,'
      '    :IDTPRICE_INV,'
      '    :IDINV_INV,'
      '    :TYPE_INV,'
      '    :IDBASE_DINV'
      ')')
    RefreshSQL.Strings = (
      'select DINV.*, NAME_SINV '
      'from  DINV'
      'left outer join SINV on IDINV_INV=ID_SINV'
      'where(  IDDOC_INV=:PARAM_IDDOC'
      '     ) and (     DINV.ID_INV = :OLD_ID_INV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DINV.*, NAME_SINV '
      'from  DINV'
      'left outer join SINV on IDINV_INV=ID_SINV'
      'where IDDOC_INV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DINV'
    AutoUpdateOptions.KeyFields = 'ID_INV'
    AutoUpdateOptions.GeneratorName = 'GEN_DINV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 64
    poUseLargeIntField = True
    object DocID_INV: TFIBLargeIntField
      FieldName = 'ID_INV'
    end
    object DocIDDOC_INV: TFIBLargeIntField
      FieldName = 'IDDOC_INV'
    end
    object DocPRIM_INV: TFIBWideStringField
      FieldName = 'PRIM_INV'
      Size = 100
    end
    object DocGID_INV: TFIBWideStringField
      FieldName = 'GID_INV'
      Size = 10
    end
    object DocIDTPRICE_INV: TFIBLargeIntField
      FieldName = 'IDTPRICE_INV'
    end
    object DocIDINV_INV: TFIBLargeIntField
      FieldName = 'IDINV_INV'
    end
    object DocTYPE_INV: TFIBIntegerField
      FieldName = 'TYPE_INV'
    end
    object DocIDBASE_DINV: TFIBLargeIntField
      FieldName = 'IDBASE_DINV'
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
      'UPDATE DINVT'
      'SET '
      '    IDDOC_INVT = :IDDOC_INVT,'
      '    IDNOM_INVT = :IDNOM_INVT,'
      '    IDED_INVT = :IDED_INVT,'
      '    KF_INVT = :KF_INVT,'
      '    KOLUCH_INVT = :KOLUCH_INVT,'
      '    KOLFAKT_INVT = :KOLFAKT_INVT,'
      '    GID_INVT = :GID_INVT,'
      '    PRICE_INVT = :PRICE_INVT,'
      '    SUMF_INVT = :SUMF_INVT,'
      '    IDBASE_DINVT = :IDBASE_DINVT'
      'WHERE'
      '    ID_INVT = :OLD_ID_INVT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DINVT'
      'WHERE'
      '        ID_INVT = :OLD_ID_INVT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DINVT('
      '    ID_INVT,'
      '    IDDOC_INVT,'
      '    IDNOM_INVT,'
      '    IDED_INVT,'
      '    KF_INVT,'
      '    KOLUCH_INVT,'
      '    KOLFAKT_INVT,'
      '    GID_INVT,'
      '    PRICE_INVT,'
      '    SUMF_INVT,'
      '    IDBASE_DINVT'
      ')'
      'VALUES('
      '    :ID_INVT,'
      '    :IDDOC_INVT,'
      '    :IDNOM_INVT,'
      '    :IDED_INVT,'
      '    :KF_INVT,'
      '    :KOLUCH_INVT,'
      '    :KOLFAKT_INVT,'
      '    :GID_INVT,'
      '    :PRICE_INVT,'
      '    :SUMF_INVT,'
      '    :IDBASE_DINVT'
      ')')
    RefreshSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, DINVT.*, NAMEED'
      'from '
      'DINVT LEFT OUTER JOIN SNOM  ON IDNOM_INVT=IDNOM '
      'left outer join SED  on  IDED_INVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where(  IDDOC_INVT=:PARAM_IDDOC'
      '     ) and (     DINVT.ID_INVT = :OLD_ID_INVT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sgrpnom.namegn, sgrpnom.idgn,'
      '        snom.namenom,'
      '        snom.tnom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '    DINVT.*,'
      '    sed.nameed,'
      '    sed.shed'
      'from '
      'DINVT LEFT OUTER JOIN SNOM  ON IDNOM_INVT=IDNOM '
      'left outer join SED  on  IDED_INVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_INVT=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DINVT'
    AutoUpdateOptions.KeyFields = 'ID_INVT'
    AutoUpdateOptions.GeneratorName = 'GEN_DINVT_ID'
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
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTKF_INVT: TFIBBCDField
      FieldName = 'KF_INVT'
      Size = 3
      RoundByScale = True
    end
    object DocTKOLUCH_INVT: TFIBBCDField
      FieldName = 'KOLUCH_INVT'
      Size = 3
      RoundByScale = True
    end
    object DocTKOLFAKT_INVT: TFIBBCDField
      FieldName = 'KOLFAKT_INVT'
      OnChange = DocTKOLFAKT_INVTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_INVT: TFIBBCDField
      FieldName = 'PRICE_INVT'
      OnChange = DocTPRICE_INVTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMF_INVT: TFIBBCDField
      FieldName = 'SUMF_INVT'
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
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTID_INVT: TFIBLargeIntField
      FieldName = 'ID_INVT'
    end
    object DocTIDDOC_INVT: TFIBLargeIntField
      FieldName = 'IDDOC_INVT'
    end
    object DocTIDNOM_INVT: TFIBLargeIntField
      FieldName = 'IDNOM_INVT'
    end
    object DocTIDED_INVT: TFIBLargeIntField
      FieldName = 'IDED_INVT'
    end
    object DocTGID_INVT: TFIBWideStringField
      FieldName = 'GID_INVT'
      Size = 10
    end
    object DocTIDBASE_DINVT: TFIBLargeIntField
      FieldName = 'IDBASE_DINVT'
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
      
        'from DOC_INV_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 336
    Top = 16
  end
  object IBQPoGrp: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.tnom, sn' +
        'om.codenom, DINVT.*, NAMEED'
      'from DINVT'
      'LEFT OUTER JOIN SNOM  ON IDNOM_INVT=IDNOM '
      'left outer join SED  on  IDED_INVT=IDED'
      'left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom'
      'where IDDOC_INVT=:PARAM_IDDOC'
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
    object IBQPoGrpKF_INVT: TFIBBCDField
      FieldName = 'KF_INVT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpKOLUCH_INVT: TFIBBCDField
      FieldName = 'KOLUCH_INVT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpKOLFAKT_INVT: TFIBBCDField
      FieldName = 'KOLFAKT_INVT'
      Size = 3
      RoundByScale = True
    end
    object IBQPoGrpPRICE_INVT: TFIBBCDField
      FieldName = 'PRICE_INVT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpSUMF_INVT: TFIBBCDField
      FieldName = 'SUMF_INVT'
      Size = 2
      RoundByScale = True
    end
    object IBQPoGrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpID_INVT: TFIBBCDField
      FieldName = 'ID_INVT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDDOC_INVT: TFIBBCDField
      FieldName = 'IDDOC_INVT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDNOM_INVT: TFIBBCDField
      FieldName = 'IDNOM_INVT'
      Size = 0
      RoundByScale = True
    end
    object IBQPoGrpIDED_INVT: TFIBBCDField
      FieldName = 'IDED_INVT'
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
  object GoodsDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select drevt.idnom_drevt,snom.namenom,snom.codenom, drevt.ided_d' +
        'revt, sed.nameed,'
      
        '        SUM(drevt.kol_drevt*drevt.kf_drevt) as SUMKOL, SUM(drevt' +
        '.rsum_drevt ) as RSUM'
      'from drevt'
      'left outer join galldoc on drevt.iddoc_drevt=galldoc.iddoc'
      'left outer join drev on drev.iddoc_drev=drevt.iddoc_drevt'
      'left outer join snom on drevt.idnom_drevt=snom.idnom'
      'left outer join sed on drevt.ided_drevt=sed.ided'
      'where drev.idinv_drev=:PARAM_IDINV'
      
        'group by drevt.idnom_drevt,snom.namenom,snom.codenom, drevt.ided' +
        '_drevt, sed.nameed')
    Transaction = IBTr
    Left = 336
    Top = 176
    object GoodsDataSetSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
    object GoodsDataSetRSUM: TFIBBCDField
      FieldName = 'RSUM'
      Size = 2
      RoundByScale = True
    end
    object GoodsDataSetCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object GoodsDataSetIDNOM_DREVT: TFIBBCDField
      FieldName = 'IDNOM_DREVT'
      Size = 0
      RoundByScale = True
    end
    object GoodsDataSetIDED_DREVT: TFIBBCDField
      FieldName = 'IDED_DREVT'
      Size = 0
      RoundByScale = True
    end
    object GoodsDataSetNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object GoodsDataSetNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object OstatkiDataSet: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      
        ' select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, sum(rgostno' +
        'm.kolostnom) as SUMKOL'
      ' from rgostnom'
      ' left outer join SNOM on IDNOM=rgostnom.idnomostnom'
      ' left outer join sed on sed.ided=snom.idbasednom'
      ' where rgostnom.idsklostnom=:PARAM_IDSKLAD'
      ' and rgostnom.idfirmostnom=:PARAM_IDFIRM'
      ' group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED')
    Transaction = IBTr
    Left = 336
    Top = 224
    object OstatkiDataSetCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object OstatkiDataSetKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object OstatkiDataSetSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object OstatkiDataSetIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object OstatkiDataSetIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object OstatkiDataSetNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object OstatkiDataSetNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 288
    Top = 120
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_INV_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_INV_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
