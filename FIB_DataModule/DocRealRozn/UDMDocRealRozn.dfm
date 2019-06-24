object DMDocRealRozn: TDMDocRealRozn
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 435
  Width = 722
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
  object DataSourcePay: TDataSource
    DataSet = Pay
    Left = 72
    Top = 176
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
      'select GALLDOC. *, '
      'NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMESKLAD,'
      ' NAMEKLIENT,'
      ' FNAME_USER,'
      ' NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC. *, '
      'NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMESKLAD,'
      ' NAMEKLIENT,'
      ' FNAME_USER,'
      ' NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where IDDOC=:ID ')
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
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
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
      'UPDATE DREALROZN'
      'SET '
      '    IDDOC_DREALROZN = :IDDOC_DREALROZN,'
      '    GID_DREALROZN = :GID_DREALROZN,'
      '    IDTPRICE_DREALROZN = :IDTPRICE_DREALROZN,'
      '    PRIM_DREALROZN = :PRIM_DREALROZN,'
      '    IDKKM_DREALROZN = :IDKKM_DREALROZN,'
      '    FIRSTSUM_DREALROZN = :FIRSTSUM_DREALROZN,'
      '    IDDCARD_DREALROZN = :IDDCARD_DREALROZN,'
      '    IDBASE_DREALROZN = :IDBASE_DREALROZN'
      'WHERE'
      '    ID_DREALROZN = :OLD_ID_DREALROZN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREALROZN'
      'WHERE'
      '        ID_DREALROZN = :OLD_ID_DREALROZN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREALROZN('
      '    ID_DREALROZN,'
      '    IDDOC_DREALROZN,'
      '    GID_DREALROZN,'
      '    IDTPRICE_DREALROZN,'
      '    PRIM_DREALROZN,'
      '    IDKKM_DREALROZN,'
      '    FIRSTSUM_DREALROZN,'
      '    IDDCARD_DREALROZN,'
      '    IDBASE_DREALROZN'
      ')'
      'VALUES('
      '    :ID_DREALROZN,'
      '    :IDDOC_DREALROZN,'
      '    :GID_DREALROZN,'
      '    :IDTPRICE_DREALROZN,'
      '    :PRIM_DREALROZN,'
      '    :IDKKM_DREALROZN,'
      '    :FIRSTSUM_DREALROZN,'
      '    :IDDCARD_DREALROZN,'
      '    :IDBASE_DREALROZN'
      ')')
    RefreshSQL.Strings = (
      'select DREALROZN.* , NAME_TPRICE, NAMEKKM'
      'from  DREALROZN'
      'left outer join STPRICE  on IDTPRICE_DREALROZN=ID_TPRICE'
      'left outer join SKKM on IDKKM_DREALROZN=IDKKM'
      'where(  IDDOC_DREALROZN=:ID'
      '     ) and (     DREALROZN.ID_DREALROZN = :OLD_ID_DREALROZN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREALROZN.* , NAME_TPRICE, NAMEKKM'
      'from  DREALROZN'
      'left outer join STPRICE  on IDTPRICE_DREALROZN=ID_TPRICE'
      'left outer join SKKM on IDKKM_DREALROZN=IDKKM'
      'where IDDOC_DREALROZN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREALROZN'
    AutoUpdateOptions.KeyFields = 'ID_DREALROZN'
    AutoUpdateOptions.GeneratorName = 'GEN_DREALROZN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocFIRSTSUM_DREALROZN: TFIBBCDField
      FieldName = 'FIRSTSUM_DREALROZN'
      Size = 2
      RoundByScale = True
    end
    object DocID_DREALROZN: TFIBLargeIntField
      FieldName = 'ID_DREALROZN'
    end
    object DocIDDOC_DREALROZN: TFIBLargeIntField
      FieldName = 'IDDOC_DREALROZN'
    end
    object DocGID_DREALROZN: TFIBWideStringField
      FieldName = 'GID_DREALROZN'
      Size = 10
    end
    object DocIDTPRICE_DREALROZN: TFIBLargeIntField
      FieldName = 'IDTPRICE_DREALROZN'
    end
    object DocPRIM_DREALROZN: TFIBWideStringField
      FieldName = 'PRIM_DREALROZN'
      Size = 100
    end
    object DocIDKKM_DREALROZN: TFIBLargeIntField
      FieldName = 'IDKKM_DREALROZN'
    end
    object DocIDDCARD_DREALROZN: TFIBLargeIntField
      FieldName = 'IDDCARD_DREALROZN'
    end
    object DocIDBASE_DREALROZN: TFIBLargeIntField
      FieldName = 'IDBASE_DREALROZN'
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREALROZNT'
      'SET '
      '    IDDOC_DREALROZNT = :IDDOC_DREALROZNT,'
      '    GID_DREALROZNT = :GID_DREALROZNT,'
      '    IDNOM_DREALROZNT = :IDNOM_DREALROZNT,'
      '    IDED_DREALROZNT = :IDED_DREALROZNT,'
      '    KOL_DREALROZNT = :KOL_DREALROZNT,'
      '    KF_DREALROZNT = :KF_DREALROZNT,'
      '    PRICE_DREALROZNT = :PRICE_DREALROZNT,'
      '    SUM_DREALROZNT = :SUM_DREALROZNT,'
      '    PRICEFULL_DREALROZNT = :PRICEFULL_DREALROZNT,'
      '    PRSK_DREALROZNT = :PRSK_DREALROZNT,'
      '    SUMSK_DREALROZNT = :SUMSK_DREALROZNT,'
      '    PRNAD_DREALROZNT = :PRNAD_DREALROZNT,'
      '    SUMNAD_DREALROZNT = :SUMNAD_DREALROZNT,'
      '    IDBASE_DREALROZNT = :IDBASE_DREALROZNT,'
      '    NDS_DREALROZNT = :NDS_DREALROZNT,'
      '    SUMNDS_DREALROZNT = :SUMNDS_DREALROZNT'
      'WHERE'
      '    ID_DREALROZNT = :OLD_ID_DREALROZNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREALROZNT'
      'WHERE'
      '        ID_DREALROZNT = :OLD_ID_DREALROZNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREALROZNT('
      '    ID_DREALROZNT,'
      '    IDDOC_DREALROZNT,'
      '    GID_DREALROZNT,'
      '    IDNOM_DREALROZNT,'
      '    IDED_DREALROZNT,'
      '    KOL_DREALROZNT,'
      '    KF_DREALROZNT,'
      '    PRICE_DREALROZNT,'
      '    SUM_DREALROZNT,'
      '    PRICEFULL_DREALROZNT,'
      '    PRSK_DREALROZNT,'
      '    SUMSK_DREALROZNT,'
      '    PRNAD_DREALROZNT,'
      '    SUMNAD_DREALROZNT,'
      '    IDBASE_DREALROZNT,'
      '    NDS_DREALROZNT,'
      '    SUMNDS_DREALROZNT'
      ')'
      'VALUES('
      '    :ID_DREALROZNT,'
      '    :IDDOC_DREALROZNT,'
      '    :GID_DREALROZNT,'
      '    :IDNOM_DREALROZNT,'
      '    :IDED_DREALROZNT,'
      '    :KOL_DREALROZNT,'
      '    :KF_DREALROZNT,'
      '    :PRICE_DREALROZNT,'
      '    :SUM_DREALROZNT,'
      '    :PRICEFULL_DREALROZNT,'
      '    :PRSK_DREALROZNT,'
      '    :SUMSK_DREALROZNT,'
      '    :PRNAD_DREALROZNT,'
      '    :SUMNAD_DREALROZNT,'
      '    :IDBASE_DREALROZNT,'
      '    :NDS_DREALROZNT,'
      '    :SUMNDS_DREALROZNT'
      ')')
    RefreshSQL.Strings = (
      'select DREALROZNT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREALROZNT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DREALROZNT=IDNOM '
      'left outer join SED  on  IDED_DREALROZNT=IDED'
      'where(  IDDOC_DREALROZNT=:ID'
      '     ) and (     DREALROZNT.ID_DREALROZNT = :OLD_ID_DREALROZNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREALROZNT.*,'
      ' NAMENOM,'
      ' NAMEED ,'
      ' TNOM,'
      ' snom.artnom, '
      ' snom.codenom,'
      ' sed.shed'
      'from '
      'DREALROZNT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DREALROZNT=IDNOM '
      'left outer join SED  on  IDED_DREALROZNT=IDED'
      'where IDDOC_DREALROZNT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREALROZNT'
    AutoUpdateOptions.KeyFields = 'ID_DREALROZNT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREALROZNT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 120
    poUseLargeIntField = True
    object DocTKOL_DREALROZNT: TFIBBCDField
      FieldName = 'KOL_DREALROZNT'
      OnChange = DocTKOL_DREALROZNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DREALROZNT: TFIBBCDField
      FieldName = 'KF_DREALROZNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_DREALROZNT: TFIBBCDField
      FieldName = 'PRICE_DREALROZNT'
      OnChange = DocTPRICE_DREALROZNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_DREALROZNT: TFIBBCDField
      FieldName = 'SUM_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTPRICEFULL_DREALROZNT: TFIBBCDField
      FieldName = 'PRICEFULL_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_DREALROZNT: TFIBBCDField
      FieldName = 'PRSK_DREALROZNT'
      OnChange = DocTPRSK_DREALROZNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSK_DREALROZNT: TFIBBCDField
      FieldName = 'SUMSK_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRNAD_DREALROZNT: TFIBBCDField
      FieldName = 'PRNAD_DREALROZNT'
      OnChange = DocTPRNAD_DREALROZNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMNAD_DREALROZNT: TFIBBCDField
      FieldName = 'SUMNAD_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_DREALROZNT: TFIBIntegerField
      FieldName = 'NDS_DREALROZNT'
    end
    object DocTSUMNDS_DREALROZNT: TFIBBCDField
      FieldName = 'SUMNDS_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTID_DREALROZNT: TFIBLargeIntField
      FieldName = 'ID_DREALROZNT'
    end
    object DocTIDDOC_DREALROZNT: TFIBLargeIntField
      FieldName = 'IDDOC_DREALROZNT'
    end
    object DocTGID_DREALROZNT: TFIBWideStringField
      FieldName = 'GID_DREALROZNT'
      Size = 10
    end
    object DocTIDNOM_DREALROZNT: TFIBLargeIntField
      FieldName = 'IDNOM_DREALROZNT'
    end
    object DocTIDED_DREALROZNT: TFIBLargeIntField
      FieldName = 'IDED_DREALROZNT'
    end
    object DocTIDBASE_DREALROZNT: TFIBLargeIntField
      FieldName = 'IDBASE_DREALROZNT'
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
    object DocTPRSK_CARD_DREALROZNT: TFIBBCDField
      FieldName = 'PRSK_CARD_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_DREALROZNT: TFIBBCDField
      FieldName = 'PRSK_AUTO_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_HAND_DREALROZNT: TFIBBCDField
      FieldName = 'PRSK_HAND_DREALROZNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_DREALROZNT: TFIBSmallIntField
      FieldName = 'NO_SK_DREALROZNT'
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
  object Pay: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREALROZN_PAY'
      'SET '
      '    IDDOC_DREALROZN_PAY = :IDDOC_DREALROZN_PAY,'
      '    GID_DREALROZN_PAY = :GID_DREALROZN_PAY,'
      '    DO_DREALROZN_PAY = :DO_DREALROZN_PAY,'
      '    SUM_DREALROZN_PAY = :SUM_DREALROZN_PAY,'
      '    IDBASE_DREALROZN_PAY = :IDBASE_DREALROZN_PAY'
      'WHERE'
      '    ID_DREALROZN_PAY = :OLD_ID_DREALROZN_PAY'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREALROZN_PAY'
      'WHERE'
      '        ID_DREALROZN_PAY = :OLD_ID_DREALROZN_PAY'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREALROZN_PAY('
      '    ID_DREALROZN_PAY,'
      '    IDDOC_DREALROZN_PAY,'
      '    GID_DREALROZN_PAY,'
      '    DO_DREALROZN_PAY,'
      '    SUM_DREALROZN_PAY,'
      '    IDBASE_DREALROZN_PAY'
      ')'
      'VALUES('
      '    :ID_DREALROZN_PAY,'
      '    :IDDOC_DREALROZN_PAY,'
      '    :GID_DREALROZN_PAY,'
      '    :DO_DREALROZN_PAY,'
      '    :SUM_DREALROZN_PAY,'
      '    :IDBASE_DREALROZN_PAY'
      ')')
    RefreshSQL.Strings = (
      'select  DREALROZN_PAY.*'
      'from DREALROZN_PAY'
      'where(  IDDOC_DREALROZN_PAY=:PARAM_IDDOC'
      
        '     ) and (     DREALROZN_PAY.ID_DREALROZN_PAY = :OLD_ID_DREALR' +
        'OZN_PAY'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select  DREALROZN_PAY.*'
      'from DREALROZN_PAY'
      'where IDDOC_DREALROZN_PAY=:PARAM_IDDOC'
      '')
    AutoUpdateOptions.UpdateTableName = 'DREALROZN_PAY'
    AutoUpdateOptions.KeyFields = 'ID_DREALROZN_PAY'
    AutoUpdateOptions.GeneratorName = 'GEN_DREALROZN_PAY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = PayCalcFields
    OnNewRecord = PayNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 176
    poUseLargeIntField = True
    object PayDO_DREALROZN_PAY: TFIBDateField
      FieldName = 'DO_DREALROZN_PAY'
    end
    object PaySUM_DREALROZN_PAY: TFIBBCDField
      FieldName = 'SUM_DREALROZN_PAY'
      Size = 2
      RoundByScale = True
    end
    object PayRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object PayID_DREALROZN_PAY: TFIBLargeIntField
      FieldName = 'ID_DREALROZN_PAY'
    end
    object PayIDDOC_DREALROZN_PAY: TFIBLargeIntField
      FieldName = 'IDDOC_DREALROZN_PAY'
    end
    object PayGID_DREALROZN_PAY: TFIBWideStringField
      FieldName = 'GID_DREALROZN_PAY'
      Size = 10
    end
    object PayIDBASE_DREALROZN_PAY: TFIBLargeIntField
      FieldName = 'IDBASE_DREALROZN_PAY'
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
    Top = 72
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_REALROZN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:' +
        'PARAM_IDSKLAD)')
    Transaction = IBTr
    Left = 336
    Top = 16
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 160
    Top = 264
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REALROZN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REALROZN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
