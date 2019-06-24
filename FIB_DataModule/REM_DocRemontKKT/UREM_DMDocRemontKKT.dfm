object REM_DMDocRemontKKT: TREM_DMDocRemontKKT
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 370
  Width = 729
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
      'UPDATE REM_GALLDOC'
      'SET '
      '    IDBASE_REM_GALLDOC = :IDBASE_REM_GALLDOC,'
      '    IDFIRM_REM_GALLDOC = :IDFIRM_REM_GALLDOC,'
      '    IDSKLAD_REM_GALLDOC = :IDSKLAD_REM_GALLDOC,'
      '    IDKLIENT_REM_GALLDOC = :IDKLIENT_REM_GALLDOC,'
      '    IDUSER_REM_GALLDOC = :IDUSER_REM_GALLDOC,'
      '    POS_REM_GALLDOC = :POS_REM_GALLDOC,'
      '    NUM_REM_GALLDOC = :NUM_REM_GALLDOC,'
      '    PR_REM_GALLDOC = :PR_REM_GALLDOC,'
      '    TDOC_REM_GALLDOC = :TDOC_REM_GALLDOC,'
      '    IDDOCOSN_REM_GALLDOC = :IDDOCOSN_REM_GALLDOC,'
      '    TYPEEXTDOC_REM_GALLDOC = :TYPEEXTDOC_REM_GALLDOC,'
      '    IDEXTDOC_REM_GALLDOC = :IDEXTDOC_REM_GALLDOC,'
      '    SUM_REM_GALLDOC = :SUM_REM_GALLDOC,'
      '    IDPROJECT_REM_GALLDOC = :IDPROJECT_REM_GALLDOC,'
      '    IDBUSINOP_REM_GALLDOC = :IDBUSINOP_REM_GALLDOC,'
      '    PREFIKS_NUM_REM_GALLDOC = :PREFIKS_NUM_REM_GALLDOC'
      'WHERE'
      '    ID_REM_GALLDOC = :OLD_ID_REM_GALLDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_GALLDOC'
      'WHERE'
      '        ID_REM_GALLDOC = :OLD_ID_REM_GALLDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_GALLDOC('
      '    ID_REM_GALLDOC,'
      '    IDBASE_REM_GALLDOC,'
      '    IDFIRM_REM_GALLDOC,'
      '    IDSKLAD_REM_GALLDOC,'
      '    IDKLIENT_REM_GALLDOC,'
      '    IDUSER_REM_GALLDOC,'
      '    POS_REM_GALLDOC,'
      '    NUM_REM_GALLDOC,'
      '    PR_REM_GALLDOC,'
      '    TDOC_REM_GALLDOC,'
      '    IDDOCOSN_REM_GALLDOC,'
      '    TYPEEXTDOC_REM_GALLDOC,'
      '    IDEXTDOC_REM_GALLDOC,'
      '    SUM_REM_GALLDOC,'
      '    IDPROJECT_REM_GALLDOC,'
      '    IDBUSINOP_REM_GALLDOC,'
      '    PREFIKS_NUM_REM_GALLDOC'
      ')'
      'VALUES('
      '    :ID_REM_GALLDOC,'
      '    :IDBASE_REM_GALLDOC,'
      '    :IDFIRM_REM_GALLDOC,'
      '    :IDSKLAD_REM_GALLDOC,'
      '    :IDKLIENT_REM_GALLDOC,'
      '    :IDUSER_REM_GALLDOC,'
      '    :POS_REM_GALLDOC,'
      '    :NUM_REM_GALLDOC,'
      '    :PR_REM_GALLDOC,'
      '    :TDOC_REM_GALLDOC,'
      '    :IDDOCOSN_REM_GALLDOC,'
      '    :TYPEEXTDOC_REM_GALLDOC,'
      '    :IDEXTDOC_REM_GALLDOC,'
      '    :SUM_REM_GALLDOC,'
      '    :IDPROJECT_REM_GALLDOC,'
      '    :IDBUSINOP_REM_GALLDOC,'
      '    :PREFIKS_NUM_REM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  rem_galldoc'
      
        'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id' +
        '_user'
      
        'left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_galldoc.idbase_rem_galldoc'
      
        'left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.id' +
        'firm'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad' +
        '.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      'where(  '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC'
      
        '     ) and (     REM_GALLDOC.ID_REM_GALLDOC = :OLD_ID_REM_GALLDO' +
        'C'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  rem_galldoc'
      
        'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id' +
        '_user'
      
        'left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_galldoc.idbase_rem_galldoc'
      
        'left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.id' +
        'firm'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad' +
        '.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      'where '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_GALLDOC'
    AutoUpdateOptions.KeyFields = 'ID_REM_GALLDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllID_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'ID_REM_GALLDOC'
    end
    object DocAllIDBASE_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GALLDOC'
      OnChange = DocAllIDBASE_REM_GALLDOCChange
    end
    object DocAllIDFIRM_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_GALLDOC'
    end
    object DocAllIDSKLAD_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_GALLDOC'
    end
    object DocAllIDKLIENT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_GALLDOC'
    end
    object DocAllIDUSER_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GALLDOC'
    end
    object DocAllPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
      OnChange = DocAllPOS_REM_GALLDOCChange
      DisplayFormat = 'c'
    end
    object DocAllNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocAllPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object DocAllTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 10
    end
    object DocAllIDDOCOSN_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSN_REM_GALLDOC'
    end
    object DocAllTYPEEXTDOC_REM_GALLDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC_REM_GALLDOC'
    end
    object DocAllIDEXTDOC_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC_REM_GALLDOC'
    end
    object DocAllSUM_REM_GALLDOC: TFIBBCDField
      FieldName = 'SUM_REM_GALLDOC'
      Size = 2
      RoundByScale = True
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
    object DocAllIDPROJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_REM_GALLDOC'
    end
    object DocAllIDBUSINOP_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_REM_GALLDOC'
    end
    object DocAllPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DREMONTKKT'
      'SET '
      '    IDBASE_REM_DREMONTKKT = :IDBASE_REM_DREMONTKKT,'
      '    IDDOC_REM_DREMONTKKT = :IDDOC_REM_DREMONTKKT,'
      '    IDKKT_REM_DREMONTKKT = :IDKKT_REM_DREMONTKKT,'
      '    IDTPRICE_REM_DREMONTKKT = :IDTPRICE_REM_DREMONTKKT,'
      '    PRIM_REM_DREMONTKKT = :PRIM_REM_DREMONTKKT'
      'WHERE'
      '    ID_REM_DREMONTKKT = :OLD_ID_REM_DREMONTKKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONTKKT'
      'WHERE'
      '        ID_REM_DREMONTKKT = :OLD_ID_REM_DREMONTKKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONTKKT('
      '    ID_REM_DREMONTKKT,'
      '    IDBASE_REM_DREMONTKKT,'
      '    IDDOC_REM_DREMONTKKT,'
      '    IDKKT_REM_DREMONTKKT,'
      '    IDTPRICE_REM_DREMONTKKT,'
      '    PRIM_REM_DREMONTKKT'
      ')'
      'VALUES('
      '    :ID_REM_DREMONTKKT,'
      '    :IDBASE_REM_DREMONTKKT,'
      '    :IDDOC_REM_DREMONTKKT,'
      '    :IDKKT_REM_DREMONTKKT,'
      '    :IDTPRICE_REM_DREMONTKKT,'
      '    :PRIM_REM_DREMONTKKT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremontkkt.*,'
      '     rem_skkt.name_rem_skkt'
      'from  rem_dremontkkt'
      
        'left outer join rem_skkt on rem_dremontkkt.idkkt_rem_dremontkkt=' +
        'rem_skkt.id_rem_skkt'
      'where(  rem_dremontkkt.iddoc_rem_dremontkkt=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONTKKT.ID_REM_DREMONTKKT = :OLD_ID_REM_' +
        'DREMONTKKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremontkkt.*,'
      '     rem_skkt.name_rem_skkt'
      'from  rem_dremontkkt'
      
        'left outer join rem_skkt on rem_dremontkkt.idkkt_rem_dremontkkt=' +
        'rem_skkt.id_rem_skkt'
      'where rem_dremontkkt.iddoc_rem_dremontkkt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONTKKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONTKKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONTKKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DREMONTKKT: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONTKKT'
    end
    object DocIDBASE_REM_DREMONTKKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONTKKT'
    end
    object DocIDDOC_REM_DREMONTKKT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONTKKT'
    end
    object DocIDKKT_REM_DREMONTKKT: TFIBLargeIntField
      FieldName = 'IDKKT_REM_DREMONTKKT'
    end
    object DocIDTPRICE_REM_DREMONTKKT: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DREMONTKKT'
    end
    object DocPRIM_REM_DREMONTKKT: TFIBWideStringField
      FieldName = 'PRIM_REM_DREMONTKKT'
      Size = 100
    end
    object DocNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DREMONTKKTT'
      'SET '
      '    IDBASE_REM_DREMONTKKTT = :IDBASE_REM_DREMONTKKTT,'
      '    IDDOC_REM_DREMONTKKTT = :IDDOC_REM_DREMONTKKTT,'
      '    IDNOM_REM_DREMONTKKTT = :IDNOM_REM_DREMONTKKTT,'
      '    IDED_REM_DREMONTKKTT = :IDED_REM_DREMONTKKTT,'
      '    KOL_REM_DREMONTKKTT = :KOL_REM_DREMONTKKTT,'
      '    KF_REM_DREMONTKKTT = :KF_REM_DREMONTKKTT,'
      '    PRICE_REM_DREMONTKKTT = :PRICE_REM_DREMONTKKTT,'
      '    SUM_REM_DREMONTKKTT = :SUM_REM_DREMONTKKTT,'
      '    PRICEMEX_REM_DREMONTKKTT = :PRICEMEX_REM_DREMONTKKTT,'
      '    SUMMEX_REM_DREMONTKKTT = :SUMMEX_REM_DREMONTKKTT'
      'WHERE'
      '    ID_REM_DREMONTKKTT = :OLD_ID_REM_DREMONTKKTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONTKKTT'
      'WHERE'
      '        ID_REM_DREMONTKKTT = :OLD_ID_REM_DREMONTKKTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONTKKTT('
      '    ID_REM_DREMONTKKTT,'
      '    IDBASE_REM_DREMONTKKTT,'
      '    IDDOC_REM_DREMONTKKTT,'
      '    IDNOM_REM_DREMONTKKTT,'
      '    IDED_REM_DREMONTKKTT,'
      '    KOL_REM_DREMONTKKTT,'
      '    KF_REM_DREMONTKKTT,'
      '    PRICE_REM_DREMONTKKTT,'
      '    SUM_REM_DREMONTKKTT,'
      '    PRICEMEX_REM_DREMONTKKTT,'
      '    SUMMEX_REM_DREMONTKKTT'
      ')'
      'VALUES('
      '    :ID_REM_DREMONTKKTT,'
      '    :IDBASE_REM_DREMONTKKTT,'
      '    :IDDOC_REM_DREMONTKKTT,'
      '    :IDNOM_REM_DREMONTKKTT,'
      '    :IDED_REM_DREMONTKKTT,'
      '    :KOL_REM_DREMONTKKTT,'
      '    :KF_REM_DREMONTKKTT,'
      '    :PRICE_REM_DREMONTKKTT,'
      '    :SUM_REM_DREMONTKKTT,'
      '    :PRICEMEX_REM_DREMONTKKTT,'
      '    :SUMMEX_REM_DREMONTKKTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremontkktt.*,'
      '     snom.namenom,'
      '     sed.nameed'
      'from  rem_dremontkktt'
      
        'left outer join snom on rem_dremontkktt.idnom_rem_dremontkktt=sn' +
        'om.idnom'
      
        'left outer join sed on rem_dremontkktt.ided_rem_dremontkktt=sed.' +
        'ided'
      'where(  rem_dremontkktt.iddoc_rem_dremontkktt=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONTKKTT.ID_REM_DREMONTKKTT = :OLD_ID_RE' +
        'M_DREMONTKKTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremontkktt.*,'
      '     snom.namenom,'
      '     sed.nameed'
      'from  rem_dremontkktt'
      
        'left outer join snom on rem_dremontkktt.idnom_rem_dremontkktt=sn' +
        'om.idnom'
      
        'left outer join sed on rem_dremontkktt.ided_rem_dremontkktt=sed.' +
        'ided'
      'where rem_dremontkktt.iddoc_rem_dremontkktt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONTKKTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONTKKTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONTKKTT_ID'
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
    object DocTKOL_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'KOL_REM_DREMONTKKTT'
      OnChange = DocTKOL_REM_DREMONTKKTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'KF_REM_DREMONTKKTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'PRICE_REM_DREMONTKKTT'
      OnChange = DocTPRICE_REM_DREMONTKKTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'SUM_REM_DREMONTKKTT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICEMEX_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'PRICEMEX_REM_DREMONTKKTT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMMEX_REM_DREMONTKKTT: TFIBBCDField
      FieldName = 'SUMMEX_REM_DREMONTKKTT'
      Size = 2
      RoundByScale = True
    end
    object DocTID_REM_DREMONTKKTT: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONTKKTT'
    end
    object DocTIDBASE_REM_DREMONTKKTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONTKKTT'
    end
    object DocTIDDOC_REM_DREMONTKKTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONTKKTT'
    end
    object DocTIDNOM_REM_DREMONTKKTT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DREMONTKKTT'
    end
    object DocTIDED_REM_DREMONTKKTT: TFIBLargeIntField
      FieldName = 'IDED_REM_DREMONTKKTT'
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
    Left = 24
    Top = 272
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUM_REM_GALLDOC) AS MAXNUMBER from  REM_GALLDOC'
      
        'where TDOC_REM_GALLDOC='#39'REMONTKKT'#39' and POS_REM_GALLDOC > :PARAM_' +
        'POS')
    Transaction = IBTr
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE REM_DOC_REMONTKKT_CANCEL_DVREG(:PARAM_IDDOC,0,' +
        '0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_REMONTKKT_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
