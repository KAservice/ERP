object DMDocRepKKM: TDMDocRepKKM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 412
  Width = 482
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 129
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
      
        'select GALLDOC.*, FNAME_USER, NAME_SDOG , NAMEKLIENT, NAMEFIRM, ' +
        'NAMESKLAD, NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:PARAM_ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER, NAME_SDOG , NAMEKLIENT, NAMEFIRM, ' +
        'NAMESKLAD, NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:PARAM_ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
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
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
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
    object DocAllNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
    end
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
      'UPDATE DREPKKM'
      'SET '
      '    GID_DREPKKM = :GID_DREPKKM,'
      '    IDDOC_DREPKKM = :IDDOC_DREPKKM,'
      '    IDKKM_DREPKKM = :IDKKM_DREPKKM,'
      '    PRIM_DREPKKM = :PRIM_DREPKKM,'
      '    OPLNAL_DREPKKM = :OPLNAL_DREPKKM,'
      '    OPLPC_DREPKKM = :OPLPC_DREPKKM,'
      '    NKL_DREPKKM = :NKL_DREPKKM,'
      '    SK_DREPKKM = :SK_DREPKKM,'
      '    NAD_DREPKKM = :NAD_DREPKKM,'
      '    DVREG_DREPKKM = :DVREG_DREPKKM,'
      '    IDTPRICE_DREPKKM = :IDTPRICE_DREPKKM,'
      '    IDBASE_DREPKKM = :IDBASE_DREPKKM,'
      '    IDBSCHET_DREPKKM = :IDBSCHET_DREPKKM'
      'WHERE'
      '    ID_DREPKKM = :OLD_ID_DREPKKM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREPKKM'
      'WHERE'
      '        ID_DREPKKM = :OLD_ID_DREPKKM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREPKKM('
      '    ID_DREPKKM,'
      '    GID_DREPKKM,'
      '    IDDOC_DREPKKM,'
      '    IDKKM_DREPKKM,'
      '    PRIM_DREPKKM,'
      '    OPLNAL_DREPKKM,'
      '    OPLPC_DREPKKM,'
      '    NKL_DREPKKM,'
      '    SK_DREPKKM,'
      '    NAD_DREPKKM,'
      '    DVREG_DREPKKM,'
      '    IDTPRICE_DREPKKM,'
      '    IDBASE_DREPKKM,'
      '    IDBSCHET_DREPKKM'
      ')'
      'VALUES('
      '    :ID_DREPKKM,'
      '    :GID_DREPKKM,'
      '    :IDDOC_DREPKKM,'
      '    :IDKKM_DREPKKM,'
      '    :PRIM_DREPKKM,'
      '    :OPLNAL_DREPKKM,'
      '    :OPLPC_DREPKKM,'
      '    :NKL_DREPKKM,'
      '    :SK_DREPKKM,'
      '    :NAD_DREPKKM,'
      '    :DVREG_DREPKKM,'
      '    :IDTPRICE_DREPKKM,'
      '    :IDBASE_DREPKKM,'
      '    :IDBSCHET_DREPKKM'
      ')')
    RefreshSQL.Strings = (
      'select '
      '    DREPKKM.*,'
      '    NAMEKKM,'
      '    NAME_TPRICE,'
      '    NAMEBSCHET '
      'from  DREPKKM'
      'left outer join SKKM on IDKKM_DREPKKM=IDKKM'
      'left outer join STPRICE on IDTPRICE_DREPKKM=ID_TPRICE'
      'left outer join SBSCHET on IDBSCHET_DREPKKM=IDBSCHET'
      'where(  IDDOC_DREPKKM=:PARAM_IDDOC'
      '     ) and (     DREPKKM.ID_DREPKKM = :OLD_ID_DREPKKM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '    DREPKKM.*,'
      '    NAMEKKM,'
      '    NAME_TPRICE,'
      '    NAMEBSCHET '
      'from  DREPKKM'
      'left outer join SKKM on IDKKM_DREPKKM=IDKKM'
      'left outer join STPRICE on IDTPRICE_DREPKKM=ID_TPRICE'
      'left outer join SBSCHET on IDBSCHET_DREPKKM=IDBSCHET'
      'where IDDOC_DREPKKM=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DREPKKM'
    AutoUpdateOptions.KeyFields = 'ID_DREPKKM'
    AutoUpdateOptions.GeneratorName = 'GEN_DREPKKM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 72
    poUseLargeIntField = True
    object DocOPLNAL_DREPKKM: TFIBBCDField
      FieldName = 'OPLNAL_DREPKKM'
      Size = 2
      RoundByScale = True
    end
    object DocOPLPC_DREPKKM: TFIBBCDField
      FieldName = 'OPLPC_DREPKKM'
      Size = 2
      RoundByScale = True
    end
    object DocNKL_DREPKKM: TFIBIntegerField
      FieldName = 'NKL_DREPKKM'
    end
    object DocSK_DREPKKM: TFIBBCDField
      FieldName = 'SK_DREPKKM'
      Size = 2
      RoundByScale = True
    end
    object DocNAD_DREPKKM: TFIBBCDField
      FieldName = 'NAD_DREPKKM'
      Size = 2
      RoundByScale = True
    end
    object DocDVREG_DREPKKM: TFIBSmallIntField
      FieldName = 'DVREG_DREPKKM'
    end
    object DocID_DREPKKM: TFIBLargeIntField
      FieldName = 'ID_DREPKKM'
    end
    object DocGID_DREPKKM: TFIBWideStringField
      FieldName = 'GID_DREPKKM'
      Size = 10
    end
    object DocIDDOC_DREPKKM: TFIBLargeIntField
      FieldName = 'IDDOC_DREPKKM'
    end
    object DocIDKKM_DREPKKM: TFIBLargeIntField
      FieldName = 'IDKKM_DREPKKM'
      OnChange = DocIDKKM_DREPKKMChange
    end
    object DocPRIM_DREPKKM: TFIBWideStringField
      FieldName = 'PRIM_DREPKKM'
      Size = 100
    end
    object DocIDTPRICE_DREPKKM: TFIBLargeIntField
      FieldName = 'IDTPRICE_DREPKKM'
    end
    object DocIDBASE_DREPKKM: TFIBLargeIntField
      FieldName = 'IDBASE_DREPKKM'
    end
    object DocIDBSCHET_DREPKKM: TFIBLargeIntField
      FieldName = 'IDBSCHET_DREPKKM'
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREPKKMT'
      'SET '
      '    GID_DREPKKMT = :GID_DREPKKMT,'
      '    IDDOC_DREPKKMT = :IDDOC_DREPKKMT,'
      '    IDNOM_DREPKKMT = :IDNOM_DREPKKMT,'
      '    IDED_DREPKKMT = :IDED_DREPKKMT,'
      '    PRICE_DREPKKMT = :PRICE_DREPKKMT,'
      '    KOL_DREPKKMT = :KOL_DREPKKMT,'
      '    KF_DREPKKMT = :KF_DREPKKMT,'
      '    SUM_DREPKKMT = :SUM_DREPKKMT,'
      '    SK_DREPKKMT = :SK_DREPKKMT,'
      '    NAD_DREPKKMT = :NAD_DREPKKMT,'
      '    PRICEFULL_DREPKKMT = :PRICEFULL_DREPKKMT,'
      '    IDBASE_DREPKKMT = :IDBASE_DREPKKMT,'
      '    NDS_DREPKKMT = :NDS_DREPKKMT,'
      '    SUMNDS_DREPKKMT = :SUMNDS_DREPKKMT'
      'WHERE'
      '    ID_DREPKKMT = :OLD_ID_DREPKKMT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREPKKMT'
      'WHERE'
      '        ID_DREPKKMT = :OLD_ID_DREPKKMT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREPKKMT('
      '    ID_DREPKKMT,'
      '    GID_DREPKKMT,'
      '    IDDOC_DREPKKMT,'
      '    IDNOM_DREPKKMT,'
      '    IDED_DREPKKMT,'
      '    PRICE_DREPKKMT,'
      '    KOL_DREPKKMT,'
      '    KF_DREPKKMT,'
      '    SUM_DREPKKMT,'
      '    SK_DREPKKMT,'
      '    NAD_DREPKKMT,'
      '    PRICEFULL_DREPKKMT,'
      '    IDBASE_DREPKKMT,'
      '    NDS_DREPKKMT,'
      '    SUMNDS_DREPKKMT'
      ')'
      'VALUES('
      '    :ID_DREPKKMT,'
      '    :GID_DREPKKMT,'
      '    :IDDOC_DREPKKMT,'
      '    :IDNOM_DREPKKMT,'
      '    :IDED_DREPKKMT,'
      '    :PRICE_DREPKKMT,'
      '    :KOL_DREPKKMT,'
      '    :KF_DREPKKMT,'
      '    :SUM_DREPKKMT,'
      '    :SK_DREPKKMT,'
      '    :NAD_DREPKKMT,'
      '    :PRICEFULL_DREPKKMT,'
      '    :IDBASE_DREPKKMT,'
      '    :NDS_DREPKKMT,'
      '    :SUMNDS_DREPKKMT'
      ')')
    RefreshSQL.Strings = (
      'select DREPKKMT.*,  KRNAMENOM, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREPKKMT LEFT OUTER JOIN SNOM  ON IDNOM_DREPKKMT=IDNOM '
      'left outer join SED  on  IDED_DREPKKMT=IDED'
      ''
      'where(  IDDOC_DREPKKMT=:PARAM_IDDOC'
      '     ) and (     DREPKKMT.ID_DREPKKMT = :OLD_ID_DREPKKMT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREPKKMT.*,  KRNAMENOM, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREPKKMT LEFT OUTER JOIN SNOM  ON IDNOM_DREPKKMT=IDNOM '
      'left outer join SED  on  IDED_DREPKKMT=IDED'
      ''
      'where IDDOC_DREPKKMT=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DREPKKMT'
    AutoUpdateOptions.KeyFields = 'ID_DREPKKMT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREPKKMT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 120
    poUseLargeIntField = True
    object DocTPRICE_DREPKKMT: TFIBBCDField
      FieldName = 'PRICE_DREPKKMT'
      OnChange = DocTPRICE_DREPKKMTChange
      Size = 2
      RoundByScale = True
    end
    object DocTKOL_DREPKKMT: TFIBBCDField
      FieldName = 'KOL_DREPKKMT'
      OnChange = DocTKOL_DREPKKMTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DREPKKMT: TFIBBCDField
      FieldName = 'KF_DREPKKMT'
      OnChange = DocTKF_DREPKKMTChange
      Size = 3
      RoundByScale = True
    end
    object DocTSUM_DREPKKMT: TFIBBCDField
      FieldName = 'SUM_DREPKKMT'
      Size = 2
      RoundByScale = True
    end
    object DocTSK_DREPKKMT: TFIBBCDField
      FieldName = 'SK_DREPKKMT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAD_DREPKKMT: TFIBBCDField
      FieldName = 'NAD_DREPKKMT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICEFULL_DREPKKMT: TFIBBCDField
      FieldName = 'PRICEFULL_DREPKKMT'
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
    object DocTID_DREPKKMT: TFIBLargeIntField
      FieldName = 'ID_DREPKKMT'
    end
    object DocTGID_DREPKKMT: TFIBWideStringField
      FieldName = 'GID_DREPKKMT'
      Size = 10
    end
    object DocTIDDOC_DREPKKMT: TFIBLargeIntField
      FieldName = 'IDDOC_DREPKKMT'
    end
    object DocTIDNOM_DREPKKMT: TFIBLargeIntField
      FieldName = 'IDNOM_DREPKKMT'
    end
    object DocTIDED_DREPKKMT: TFIBLargeIntField
      FieldName = 'IDED_DREPKKMT'
    end
    object DocTIDBASE_DREPKKMT: TFIBLargeIntField
      FieldName = 'IDBASE_DREPKKMT'
    end
    object DocTNDS_DREPKKMT: TFIBIntegerField
      FieldName = 'NDS_DREPKKMT'
    end
    object DocTSUMNDS_DREPKKMT: TFIBBCDField
      FieldName = 'SUMNDS_DREPKKMT'
      Size = 2
      RoundByScale = True
    end
    object DocTKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
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
    Left = 312
    Top = 128
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_REPKKM_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PA' +
        'RAM_IDSKLAD,:PARAM_IDKASSA)'
      '')
    Transaction = IBTr
    Left = 344
    Top = 16
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 272
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
    Left = 272
    Top = 72
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  IDNOM, NAMENOM, IDED, NAMEED, SUM(SUMCHKT)  AS SUMMA, SU' +
        'M(KFCHKT*KOLCHKT)  AS SUMKOL'
      ' from  DCHKT '
      'left outer join DCHK on IDDOCCHKT=IDDOCCHK'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SED on IDBASEDNOM=IDED'
      ' left outer join GALLDOC on IDDOCCHKT=IDDOC'
      'where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)'
      'and  IDKKMCHK=1'
      ' and  IDSKLDOC=16'
      ' and  IDFIRMDOC=2'
      'and  NKLCHK=380'
      ''
      ' group by IDNOM, NAMENOM, IDED, NAMEED ')
    Transaction = IBTr
    Left = 408
    Top = 112
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REPKKM_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REPKKM_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
  object TableDoc: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select  IDNOM, NAMENOM, IDED, NAMEED, SUM(SUMCHKT)  AS SUMMA, SU' +
        'M(KFCHKT*KOLCHKT)  AS SUMKOL,'
      'SUM(SKCHKT)  AS SUMSK, SUM(NADCHKT)  AS SUMNAD '
      'from  DCHKT '
      'left outer join DCHK on IDDOCCHKT=IDDOCCHK'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SED on IDBASEDNOM=IDED'
      'left outer join GALLDOC on IDDOCCHKT=IDDOC'
      'where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)'
      ' and  (OPERCHK=0 or OPERCHK=2)'
      ''
      ''
      'group by IDNOM, NAMENOM, IDED, NAMEED')
    Transaction = IBTr
    Left = 392
    Top = 216
    poUseLargeIntField = True
    object TableDocSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object TableDocSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
    object TableDocSUMSK: TFIBBCDField
      FieldName = 'SUMSK'
      Size = 2
      RoundByScale = True
    end
    object TableDocSUMNAD: TFIBBCDField
      FieldName = 'SUMNAD'
      Size = 2
      RoundByScale = True
    end
    object TableDocIDNOM: TFIBLargeIntField
      FieldName = 'IDNOM'
    end
    object TableDocNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object TableDocIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object TableDocNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object PayDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SUM(OPLNALCHK)  AS OPLATANAL, SUM(OPLPCCHK)  AS OPLATAPC'
      ' from  DCHK '
      'left outer join GALLDOC on IDDOCCHK=IDDOC'
      ' where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON) and'
      ' (OPERCHK=0 or OPERCHK=2)')
    Transaction = IBTr
    Left = 392
    Top = 280
    object PayDocOPLATANAL: TFIBBCDField
      FieldName = 'OPLATANAL'
      Size = 2
      RoundByScale = True
    end
    object PayDocOPLATAPC: TFIBBCDField
      FieldName = 'OPLATAPC'
      Size = 2
      RoundByScale = True
    end
  end
end
