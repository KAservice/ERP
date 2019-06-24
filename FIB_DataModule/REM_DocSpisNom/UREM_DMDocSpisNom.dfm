object REM_DMDocSpisNom: TREM_DMDocSpisNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 439
  Width = 667
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
      'UPDATE REM_DSPN'
      'SET '
      '    IDBASE_REM_DSPN = :IDBASE_REM_DSPN,'
      '    IDDOC_REM_DSPN = :IDDOC_REM_DSPN,'
      '    GID_REM_DSPN = :GID_REM_DSPN,'
      '    IDRTPRICE_REM_DSPN = :IDRTPRICE_REM_DSPN,'
      '    RSUM_REM_DSPN = :RSUM_REM_DSPN,'
      '    PRIM_REM_DSPN = :PRIM_REM_DSPN'
      'WHERE'
      '    ID_REM_DSPN = :OLD_ID_REM_DSPN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSPN'
      'WHERE'
      '        ID_REM_DSPN = :OLD_ID_REM_DSPN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSPN('
      '    ID_REM_DSPN,'
      '    IDBASE_REM_DSPN,'
      '    IDDOC_REM_DSPN,'
      '    GID_REM_DSPN,'
      '    IDRTPRICE_REM_DSPN,'
      '    RSUM_REM_DSPN,'
      '    PRIM_REM_DSPN'
      ')'
      'VALUES('
      '    :ID_REM_DSPN,'
      '    :IDBASE_REM_DSPN,'
      '    :IDDOC_REM_DSPN,'
      '    :GID_REM_DSPN,'
      '    :IDRTPRICE_REM_DSPN,'
      '    :RSUM_REM_DSPN,'
      '    :PRIM_REM_DSPN'
      ')')
    RefreshSQL.Strings = (
      'select rem_dspn.*,'
      '    stprice.name_tprice'
      'from  rem_dspn'
      
        'left outer join stprice on rem_dspn.idrtprice_rem_dspn=stprice.i' +
        'd_tprice'
      'where(  rem_dspn.iddoc_rem_dspn=:PARAM_IDDOC'
      '     ) and (     REM_DSPN.ID_REM_DSPN = :OLD_ID_REM_DSPN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dspn.*,'
      '    stprice.name_tprice'
      'from  rem_dspn'
      
        'left outer join stprice on rem_dspn.idrtprice_rem_dspn=stprice.i' +
        'd_tprice'
      'where rem_dspn.iddoc_rem_dspn=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSPN'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSPN'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSPN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DSPN: TFIBLargeIntField
      FieldName = 'ID_REM_DSPN'
    end
    object DocIDBASE_REM_DSPN: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSPN'
    end
    object DocIDDOC_REM_DSPN: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSPN'
    end
    object DocGID_REM_DSPN: TFIBWideStringField
      FieldName = 'GID_REM_DSPN'
      Size = 10
    end
    object DocIDRTPRICE_REM_DSPN: TFIBLargeIntField
      FieldName = 'IDRTPRICE_REM_DSPN'
    end
    object DocRSUM_REM_DSPN: TFIBBCDField
      FieldName = 'RSUM_REM_DSPN'
      Size = 2
      RoundByScale = True
    end
    object DocPRIM_REM_DSPN: TFIBWideStringField
      FieldName = 'PRIM_REM_DSPN'
      Size = 100
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DSPNT'
      'SET '
      '    IDBASE_REM_DSPNT = :IDBASE_REM_DSPNT,'
      '    IDDOC_REM_DSPNT = :IDDOC_REM_DSPNT,'
      '    GID_REM_DSPNT = :GID_REM_DSPNT,'
      '    IDNOM_REM_DSPNT = :IDNOM_REM_DSPNT,'
      '    IDED_REM_DSPNT = :IDED_REM_DSPNT,'
      '    IDHW_REM_DSPNT = :IDHW_REM_DSPNT,'
      '    KOL_REM_DSPNT = :KOL_REM_DSPNT,'
      '    KF_REM_DSPNT = :KF_REM_DSPNT,'
      '    PRICE_REM_DSPNT = :PRICE_REM_DSPNT,'
      '    SUM_REM_DSPNT = :SUM_REM_DSPNT,'
      '    RPRICE_REM_DSPNT = :RPRICE_REM_DSPNT,'
      '    RSUM_REM_DSPNT = :RSUM_REM_DSPNT,'
      '    DVREG_REM_DSPNT = :DVREG_REM_DSPNT,'
      '    IDTNOM_REM_DSPNT = :IDTNOM_REM_DSPNT,'
      '    IDMHRAN_REM_DSPNT = :IDMHRAN_REM_DSPNT'
      'WHERE'
      '    ID_REM_DSPNT = :OLD_ID_REM_DSPNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSPNT'
      'WHERE'
      '        ID_REM_DSPNT = :OLD_ID_REM_DSPNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSPNT('
      '    ID_REM_DSPNT,'
      '    IDBASE_REM_DSPNT,'
      '    IDDOC_REM_DSPNT,'
      '    GID_REM_DSPNT,'
      '    IDNOM_REM_DSPNT,'
      '    IDED_REM_DSPNT,'
      '    IDHW_REM_DSPNT,'
      '    KOL_REM_DSPNT,'
      '    KF_REM_DSPNT,'
      '    PRICE_REM_DSPNT,'
      '    SUM_REM_DSPNT,'
      '    RPRICE_REM_DSPNT,'
      '    RSUM_REM_DSPNT,'
      '    DVREG_REM_DSPNT,'
      '    IDTNOM_REM_DSPNT,'
      '    IDMHRAN_REM_DSPNT'
      ')'
      'VALUES('
      '    :ID_REM_DSPNT,'
      '    :IDBASE_REM_DSPNT,'
      '    :IDDOC_REM_DSPNT,'
      '    :GID_REM_DSPNT,'
      '    :IDNOM_REM_DSPNT,'
      '    :IDED_REM_DSPNT,'
      '    :IDHW_REM_DSPNT,'
      '    :KOL_REM_DSPNT,'
      '    :KF_REM_DSPNT,'
      '    :PRICE_REM_DSPNT,'
      '    :SUM_REM_DSPNT,'
      '    :RPRICE_REM_DSPNT,'
      '    :RSUM_REM_DSPNT,'
      '    :DVREG_REM_DSPNT,'
      '    :IDTNOM_REM_DSPNT,'
      '    :IDMHRAN_REM_DSPNT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dspnt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' smhran.name_smhran,'
      ' stnom.name_stnom'
      'from  rem_dspnt'
      'left outer join snom on rem_dspnt.idnom_rem_dspnt=snom.idnom'
      'left outer join sed on rem_dspnt.ided_rem_dspnt=sed.ided'
      
        'left outer join rem_shardware on rem_dspnt.idhw_rem_dspnt=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran on rem_dspnt.idmhran_rem_dspnt=smhran.id_' +
        'smhran'
      
        'left outer join stnom on rem_dspnt.idtnom_rem_dspnt=stnom.id_stn' +
        'om'
      'where(  rem_dspnt.iddoc_rem_dspnt=:PARAM_IDDOC'
      '     ) and (     REM_DSPNT.ID_REM_DSPNT = :OLD_ID_REM_DSPNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dspnt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' smhran.name_smhran,'
      ' stnom.name_stnom'
      'from  rem_dspnt'
      'left outer join snom on rem_dspnt.idnom_rem_dspnt=snom.idnom'
      'left outer join sed on rem_dspnt.ided_rem_dspnt=sed.ided'
      
        'left outer join rem_shardware on rem_dspnt.idhw_rem_dspnt=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran on rem_dspnt.idmhran_rem_dspnt=smhran.id_' +
        'smhran'
      
        'left outer join stnom on rem_dspnt.idtnom_rem_dspnt=stnom.id_stn' +
        'om'
      'where rem_dspnt.iddoc_rem_dspnt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSPNT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSPNT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSPNT_ID'
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
    object DocTID_REM_DSPNT: TFIBLargeIntField
      FieldName = 'ID_REM_DSPNT'
    end
    object DocTIDBASE_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSPNT'
    end
    object DocTIDDOC_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSPNT'
    end
    object DocTGID_REM_DSPNT: TFIBWideStringField
      FieldName = 'GID_REM_DSPNT'
      Size = 10
    end
    object DocTIDNOM_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DSPNT'
    end
    object DocTIDED_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDED_REM_DSPNT'
    end
    object DocTIDHW_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DSPNT'
    end
    object DocTKOL_REM_DSPNT: TFIBBCDField
      FieldName = 'KOL_REM_DSPNT'
      OnChange = DocTKOL_REM_DSPNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DSPNT: TFIBBCDField
      FieldName = 'KF_REM_DSPNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DSPNT: TFIBBCDField
      FieldName = 'PRICE_REM_DSPNT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DSPNT: TFIBBCDField
      FieldName = 'SUM_REM_DSPNT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_REM_DSPNT: TFIBBCDField
      FieldName = 'RPRICE_REM_DSPNT'
      OnChange = DocTRPRICE_REM_DSPNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_REM_DSPNT: TFIBBCDField
      FieldName = 'RSUM_REM_DSPNT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DSPNT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DSPNT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
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
    object DocTIDTNOM_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DSPNT'
    end
    object DocTIDMHRAN_REM_DSPNT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DSPNT'
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
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
      'where TDOC_REM_GALLDOC='#39'REMSPN'#39' and POS_REM_GALLDOC > :PARAM_POS')
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object pFIBQ: TpFIBQuery
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_SPN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_SPN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
