object DMDocOtchetPost: TDMDocOtchetPost
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 453
  Width = 611
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
      'UPDATE DOTCHPOST'
      'SET '
      '    IDBASE_DOTCHPOST = :IDBASE_DOTCHPOST,'
      '    GID_DOTCHPOST = :GID_DOTCHPOST,'
      '    PRIM_DOTCHPOST = :PRIM_DOTCHPOST,'
      '    IDDOC_DOTCHPOST = :IDDOC_DOTCHPOST,'
      '    IDTPRICE_DOTCHPOST = :IDTPRICE_DOTCHPOST'
      'WHERE'
      '    ID_DOTCHPOST = :OLD_ID_DOTCHPOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DOTCHPOST'
      'WHERE'
      '        ID_DOTCHPOST = :OLD_ID_DOTCHPOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DOTCHPOST('
      '    ID_DOTCHPOST,'
      '    IDBASE_DOTCHPOST,'
      '    GID_DOTCHPOST,'
      '    PRIM_DOTCHPOST,'
      '    IDDOC_DOTCHPOST,'
      '    IDTPRICE_DOTCHPOST'
      ')'
      'VALUES('
      '    :ID_DOTCHPOST,'
      '    :IDBASE_DOTCHPOST,'
      '    :GID_DOTCHPOST,'
      '    :PRIM_DOTCHPOST,'
      '    :IDDOC_DOTCHPOST,'
      '    :IDTPRICE_DOTCHPOST'
      ')')
    RefreshSQL.Strings = (
      'select dotchpost.*,'
      '    stprice.name_tprice'
      'from  dotchpost'
      
        'left outer join stprice on dotchpost.idtprice_dotchpost=stprice.' +
        'id_tprice'
      'where(  dotchpost.iddoc_dotchpost=:ID'
      '     ) and (     DOTCHPOST.ID_DOTCHPOST = :OLD_ID_DOTCHPOST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dotchpost.*,'
      '    stprice.name_tprice'
      'from  dotchpost'
      
        'left outer join stprice on dotchpost.idtprice_dotchpost=stprice.' +
        'id_tprice'
      'where dotchpost.iddoc_dotchpost=:ID')
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
    object DocID_DOTCHPOST: TFIBLargeIntField
      FieldName = 'ID_DOTCHPOST'
    end
    object DocIDBASE_DOTCHPOST: TFIBLargeIntField
      FieldName = 'IDBASE_DOTCHPOST'
    end
    object DocGID_DOTCHPOST: TFIBWideStringField
      FieldName = 'GID_DOTCHPOST'
      Size = 10
    end
    object DocPRIM_DOTCHPOST: TFIBWideStringField
      FieldName = 'PRIM_DOTCHPOST'
      Size = 100
    end
    object DocIDDOC_DOTCHPOST: TFIBLargeIntField
      FieldName = 'IDDOC_DOTCHPOST'
    end
    object DocIDTPRICE_DOTCHPOST: TFIBLargeIntField
      FieldName = 'IDTPRICE_DOTCHPOST'
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DOTCHPOSTT'
      'SET '
      '    IDBASE_DOTCHPOSTT = :IDBASE_DOTCHPOSTT,'
      '    GID_DOTCHPOSTT = :GID_DOTCHPOSTT,'
      '    IDDOC_DOTCHPOSTT = :IDDOC_DOTCHPOSTT,'
      '    IDNOM_DOTCHPOSTT = :IDNOM_DOTCHPOSTT,'
      '    IDED_DOTCHPOSTT = :IDED_DOTCHPOSTT,'
      '    KOL_DOTCHPOSTT = :KOL_DOTCHPOSTT,'
      '    KF_DOTCHPOSTT = :KF_DOTCHPOSTT,'
      '    PRICE_DOTCHPOSTT = :PRICE_DOTCHPOSTT,'
      '    SUM_DOTCHPOSTT = :SUM_DOTCHPOSTT'
      'WHERE'
      '    ID_DOTCHPOSTT = :OLD_ID_DOTCHPOSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DOTCHPOSTT'
      'WHERE'
      '        ID_DOTCHPOSTT = :OLD_ID_DOTCHPOSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DOTCHPOSTT('
      '    ID_DOTCHPOSTT,'
      '    IDBASE_DOTCHPOSTT,'
      '    GID_DOTCHPOSTT,'
      '    IDDOC_DOTCHPOSTT,'
      '    IDNOM_DOTCHPOSTT,'
      '    IDED_DOTCHPOSTT,'
      '    KOL_DOTCHPOSTT,'
      '    KF_DOTCHPOSTT,'
      '    PRICE_DOTCHPOSTT,'
      '    SUM_DOTCHPOSTT'
      ')'
      'VALUES('
      '    :ID_DOTCHPOSTT,'
      '    :IDBASE_DOTCHPOSTT,'
      '    :GID_DOTCHPOSTT,'
      '    :IDDOC_DOTCHPOSTT,'
      '    :IDNOM_DOTCHPOSTT,'
      '    :IDED_DOTCHPOSTT,'
      '    :KOL_DOTCHPOSTT,'
      '    :KF_DOTCHPOSTT,'
      '    :PRICE_DOTCHPOSTT,'
      '    :SUM_DOTCHPOSTT'
      ')')
    RefreshSQL.Strings = (
      'select dotchpostt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.tnom,'
      ''
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.shed'
      'from  dotchpostt'
      'LEFT OUTER JOIN SNOM  ON dotchpostt.idnom_dotchpostt=snom.idnom'
      'left outer join SED  on  dotchpostt.ided_dotchpostt=sed.ided'
      ''
      'where(  dotchpostt.iddoc_dotchpostt=:ID'
      '     ) and (     DOTCHPOSTT.ID_DOTCHPOSTT = :OLD_ID_DOTCHPOSTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dotchpostt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.tnom,'
      ''
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.shed'
      'from  dotchpostt'
      'LEFT OUTER JOIN SNOM  ON dotchpostt.idnom_dotchpostt=snom.idnom'
      'left outer join SED  on  dotchpostt.ided_dotchpostt=sed.ided'
      ''
      'where dotchpostt.iddoc_dotchpostt=:ID')
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_DOTCHPOSTT: TFIBLargeIntField
      FieldName = 'ID_DOTCHPOSTT'
    end
    object DocTIDBASE_DOTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDBASE_DOTCHPOSTT'
    end
    object DocTGID_DOTCHPOSTT: TFIBWideStringField
      FieldName = 'GID_DOTCHPOSTT'
      Size = 10
    end
    object DocTIDDOC_DOTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDDOC_DOTCHPOSTT'
    end
    object DocTIDNOM_DOTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDNOM_DOTCHPOSTT'
    end
    object DocTIDED_DOTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDED_DOTCHPOSTT'
    end
    object DocTKOL_DOTCHPOSTT: TFIBBCDField
      FieldName = 'KOL_DOTCHPOSTT'
      OnChange = DocTKOL_DOTCHPOSTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DOTCHPOSTT: TFIBBCDField
      FieldName = 'KF_DOTCHPOSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_DOTCHPOSTT: TFIBBCDField
      FieldName = 'PRICE_DOTCHPOSTT'
      OnChange = DocTPRICE_DOTCHPOSTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_DOTCHPOSTT: TFIBBCDField
      FieldName = 'SUM_DOTCHPOSTT'
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
      
        'from DOC_OTCHPOST_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:' +
        'PARAM_IDSKLAD)')
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
      'EXECUTE PROCEDURE DOC_OTCHPOST_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_OTCHPOST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
