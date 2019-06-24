object REM_DMDocOstNom: TREM_DMDocOstNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 457
  Width = 637
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
      '    PREFIKS_NUM_REM_GALLDOC = :PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC = :IDOBJECT_REM_GALLDOC'
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
      '    PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC'
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
      '    :PREFIKS_NUM_REM_GALLDOC,'
      '    :IDOBJECT_REM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
      ''
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
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
      ''
      'where '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_GALLDOC'
    AutoUpdateOptions.KeyFields = 'ID_REM_GALLDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
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
    end
    object DocAllNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocAllPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object DocAllTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 15
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
    object DocAllIDPROJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_REM_GALLDOC'
    end
    object DocAllIDBUSINOP_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_REM_GALLDOC'
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
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocAllIDOBJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDOBJECT_REM_GALLDOC'
    end
    object DocAllNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DOSN'
      'SET '
      '    IDBASE_REM_DOSN = :IDBASE_REM_DOSN,'
      '    IDDOC_REM_DOSN = :IDDOC_REM_DOSN,'
      '    GID_REM_DOSN = :GID_REM_DOSN,'
      '    IDTPRICE_REM_DOSN = :IDTPRICE_REM_DOSN,'
      '    IDRTPRICE_REM_DOSN = :IDRTPRICE_REM_DOSN,'
      '    RSUM_REM_DOSN = :RSUM_REM_DOSN,'
      '    PRIM_REM_DOSN = :PRIM_REM_DOSN'
      'WHERE'
      '    ID_REM_DOSN = :OLD_ID_REM_DOSN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DOSN'
      'WHERE'
      '        ID_REM_DOSN = :OLD_ID_REM_DOSN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DOSN('
      '    ID_REM_DOSN,'
      '    IDBASE_REM_DOSN,'
      '    IDDOC_REM_DOSN,'
      '    GID_REM_DOSN,'
      '    IDTPRICE_REM_DOSN,'
      '    IDRTPRICE_REM_DOSN,'
      '    RSUM_REM_DOSN,'
      '    PRIM_REM_DOSN'
      ')'
      'VALUES('
      '    :ID_REM_DOSN,'
      '    :IDBASE_REM_DOSN,'
      '    :IDDOC_REM_DOSN,'
      '    :GID_REM_DOSN,'
      '    :IDTPRICE_REM_DOSN,'
      '    :IDRTPRICE_REM_DOSN,'
      '    :RSUM_REM_DOSN,'
      '    :PRIM_REM_DOSN'
      ')')
    RefreshSQL.Strings = (
      'select rem_dosn.*'
      'from  rem_dosn'
      'where(  rem_dosn.iddoc_rem_dosn=:PARAM_IDDOC'
      '     ) and (     REM_DOSN.ID_REM_DOSN = :OLD_ID_REM_DOSN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dosn.*'
      'from  rem_dosn'
      'where rem_dosn.iddoc_rem_dosn=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DOSN'
    AutoUpdateOptions.KeyFields = 'ID_REM_DOSN'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DOSN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DOSN: TFIBLargeIntField
      FieldName = 'ID_REM_DOSN'
    end
    object DocIDBASE_REM_DOSN: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DOSN'
    end
    object DocIDDOC_REM_DOSN: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DOSN'
    end
    object DocGID_REM_DOSN: TFIBWideStringField
      FieldName = 'GID_REM_DOSN'
      Size = 10
    end
    object DocIDTPRICE_REM_DOSN: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DOSN'
    end
    object DocIDRTPRICE_REM_DOSN: TFIBLargeIntField
      FieldName = 'IDRTPRICE_REM_DOSN'
    end
    object DocRSUM_REM_DOSN: TFIBBCDField
      FieldName = 'RSUM_REM_DOSN'
      Size = 2
      RoundByScale = True
    end
    object DocPRIM_REM_DOSN: TFIBWideStringField
      FieldName = 'PRIM_REM_DOSN'
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
    Left = 240
    Top = 296
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
      'UPDATE REM_DOSNT'
      'SET '
      '    IDBASE_REM_DOSNT = :IDBASE_REM_DOSNT,'
      '    IDDOC_REM_DOSNT = :IDDOC_REM_DOSNT,'
      '    GID_REM_DOSNT = :GID_REM_DOSNT,'
      '    IDNOM_REM_DOSNT = :IDNOM_REM_DOSNT,'
      '    IDED_REM_DOSNT = :IDED_REM_DOSNT,'
      '    IDHW_REM_DOSNT = :IDHW_REM_DOSNT,'
      '    KOL_REM_DOSNT = :KOL_REM_DOSNT,'
      '    KF_REM_DOSNT = :KF_REM_DOSNT,'
      '    PRICE_REM_DOSNT = :PRICE_REM_DOSNT,'
      '    SUM_REM_DOSNT = :SUM_REM_DOSNT,'
      '    RPRICE_REM_DOSNT = :RPRICE_REM_DOSNT,'
      '    RSUM_REM_DOSNT = :RSUM_REM_DOSNT,'
      '    NDS_REM_DOSNT = :NDS_REM_DOSNT,'
      '    SUMNDS_REM_DOSNT = :SUMNDS_REM_DOSNT,'
      '    DVREG_REM_DOSNT = :DVREG_REM_DOSNT,'
      '    IDTNOM_REM_DOSNT = :IDTNOM_REM_DOSNT,'
      '    IDMHRAN_REM_DOSNT = :IDMHRAN_REM_DOSNT'
      'WHERE'
      '    ID_REM_DOSNT = :OLD_ID_REM_DOSNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DOSNT'
      'WHERE'
      '        ID_REM_DOSNT = :OLD_ID_REM_DOSNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DOSNT('
      '    ID_REM_DOSNT,'
      '    IDBASE_REM_DOSNT,'
      '    IDDOC_REM_DOSNT,'
      '    GID_REM_DOSNT,'
      '    IDNOM_REM_DOSNT,'
      '    IDED_REM_DOSNT,'
      '    IDHW_REM_DOSNT,'
      '    KOL_REM_DOSNT,'
      '    KF_REM_DOSNT,'
      '    PRICE_REM_DOSNT,'
      '    SUM_REM_DOSNT,'
      '    RPRICE_REM_DOSNT,'
      '    RSUM_REM_DOSNT,'
      '    NDS_REM_DOSNT,'
      '    SUMNDS_REM_DOSNT,'
      '    DVREG_REM_DOSNT,'
      '    IDTNOM_REM_DOSNT,'
      '    IDMHRAN_REM_DOSNT'
      ')'
      'VALUES('
      '    :ID_REM_DOSNT,'
      '    :IDBASE_REM_DOSNT,'
      '    :IDDOC_REM_DOSNT,'
      '    :GID_REM_DOSNT,'
      '    :IDNOM_REM_DOSNT,'
      '    :IDED_REM_DOSNT,'
      '    :IDHW_REM_DOSNT,'
      '    :KOL_REM_DOSNT,'
      '    :KF_REM_DOSNT,'
      '    :PRICE_REM_DOSNT,'
      '    :SUM_REM_DOSNT,'
      '    :RPRICE_REM_DOSNT,'
      '    :RSUM_REM_DOSNT,'
      '    :NDS_REM_DOSNT,'
      '    :SUMNDS_REM_DOSNT,'
      '    :DVREG_REM_DOSNT,'
      '    :IDTNOM_REM_DOSNT,'
      '    :IDMHRAN_REM_DOSNT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dosnt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    smhran.name_smhran'
      'from rem_dosnt'
      'left outer join SNOM  on rem_dosnt.idnom_rem_dosnt=snom.idnom'
      'left outer join SED  on  rem_dosnt.ided_rem_dosnt=sed.ided'
      
        'left outer join rem_shardware on rem_dosnt.idhw_rem_dosnt=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran on rem_dosnt.idmhran_rem_dosnt=smhran.id_' +
        'smhran'
      'where(  rem_dosnt.iddoc_rem_dosnt=:PARAM_IDDOC'
      '     ) and (     REM_DOSNT.ID_REM_DOSNT = :OLD_ID_REM_DOSNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dosnt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    smhran.name_smhran'
      'from rem_dosnt'
      'left outer join SNOM  on rem_dosnt.idnom_rem_dosnt=snom.idnom'
      'left outer join SED  on  rem_dosnt.ided_rem_dosnt=sed.ided'
      
        'left outer join rem_shardware on rem_dosnt.idhw_rem_dosnt=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran on rem_dosnt.idmhran_rem_dosnt=smhran.id_' +
        'smhran'
      'where rem_dosnt.iddoc_rem_dosnt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DOSNT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DOSNT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DOSNT_ID'
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
    object DocTID_REM_DOSNT: TFIBLargeIntField
      FieldName = 'ID_REM_DOSNT'
    end
    object DocTIDBASE_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DOSNT'
    end
    object DocTIDDOC_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DOSNT'
    end
    object DocTGID_REM_DOSNT: TFIBWideStringField
      FieldName = 'GID_REM_DOSNT'
      Size = 10
    end
    object DocTIDNOM_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DOSNT'
    end
    object DocTIDED_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDED_REM_DOSNT'
    end
    object DocTIDHW_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DOSNT'
    end
    object DocTKOL_REM_DOSNT: TFIBBCDField
      FieldName = 'KOL_REM_DOSNT'
      OnChange = DocTKOL_REM_DOSNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DOSNT: TFIBBCDField
      FieldName = 'KF_REM_DOSNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DOSNT: TFIBBCDField
      FieldName = 'PRICE_REM_DOSNT'
      OnChange = DocTPRICE_REM_DOSNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DOSNT: TFIBBCDField
      FieldName = 'SUM_REM_DOSNT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_REM_DOSNT: TFIBBCDField
      FieldName = 'RPRICE_REM_DOSNT'
      OnChange = DocTRPRICE_REM_DOSNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_REM_DOSNT: TFIBBCDField
      FieldName = 'RSUM_REM_DOSNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_REM_DOSNT: TFIBIntegerField
      FieldName = 'NDS_REM_DOSNT'
    end
    object DocTSUMNDS_REM_DOSNT: TFIBBCDField
      FieldName = 'SUMNDS_REM_DOSNT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DOSNT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DOSNT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
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
    object DocTNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTIDTNOM_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DOSNT'
    end
    object DocTNAME_TYPE_NOM_LOOCUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NOM_LOOCUP'
      LookupDataSet = TypeNom
      LookupKeyFields = 'ID_STNOM'
      LookupResultField = 'NAME_STNOM'
      KeyFields = 'IDTNOM_REM_DOSNT'
      Size = 50
      Lookup = True
    end
    object DocTIDMHRAN_REM_DOSNT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DOSNT'
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select max(rem_galldoc.num_rem_galldoc) AS MAXNUMBER from  rem_g' +
        'alldoc'
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMOSN'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
    Transaction = IBTr
    Left = 328
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object DocOsn: TpFIBDataSet
    SelectSQL.Strings = (
      'select rem_galldoc.tdoc_rem_galldoc,'
      '        rem_galldoc.num_rem_galldoc,'
      '        rem_galldoc.pos_rem_galldoc'
      'from rem_galldoc'
      'where rem_galldoc.id_rem_galldoc=:PARAM_IDDOC_OSN')
    Transaction = IBTr
    Left = 168
    Top = 176
    poUseLargeIntField = True
    object DocOsnTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 10
    end
    object DocOsnNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocOsnPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_OSN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 136
    Top = 336
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_OSN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 136
    Top = 272
    qoStartTransaction = True
  end
  object DataSourceDocOsn: TDataSource
    DataSet = DocOsn
    Left = 64
    Top = 176
  end
  object TypeNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnom.id_stnom,'
      '       stnom.name_stnom'
      'from stnom'
      'order by stnom.name_stnom')
    Left = 512
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
