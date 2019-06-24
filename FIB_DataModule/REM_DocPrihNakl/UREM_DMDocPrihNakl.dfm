object REM_DMDocPrihNakl: TREM_DMDocPrihNakl
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 453
  Width = 648
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
      '  rem_galldoc.id_rem_galldoc=:PARAM_ID'
      
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
      '  rem_galldoc.id_rem_galldoc=:PARAM_ID')
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
      OnChange = DocAllIDSKLAD_REM_GALLDOCChange
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
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DPRN'
      'SET '
      '    IDBASE_REM_DPRN = :IDBASE_REM_DPRN,'
      '    IDDOC_REM_DPRN = :IDDOC_REM_DPRN,'
      '    GID_REM_DPRN = :GID_REM_DPRN,'
      '    IDTPRICE_REM_DPRN = :IDTPRICE_REM_DPRN,'
      '    IDRTPRICE_REM_DPRN = :IDRTPRICE_REM_DPRN,'
      '    RSUM_REM_DPRN = :RSUM_REM_DPRN,'
      '    PRIM_REM_DPRN = :PRIM_REM_DPRN,'
      '    NUMDOCPOST_REM_DPRN = :NUMDOCPOST_REM_DPRN,'
      '    POSDOCPOST_REM_DPRN = :POSDOCPOST_REM_DPRN,'
      '    FL_TREB_OTCHET_REM_DPRN = :FL_TREB_OTCHET_REM_DPRN,'
      '    FL_OTV_HRAN_REM_DPRN = :FL_OTV_HRAN_REM_DPRN'
      'WHERE'
      '    ID_REM_DPRN = :OLD_ID_REM_DPRN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DPRN'
      'WHERE'
      '        ID_REM_DPRN = :OLD_ID_REM_DPRN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DPRN('
      '    ID_REM_DPRN,'
      '    IDBASE_REM_DPRN,'
      '    IDDOC_REM_DPRN,'
      '    GID_REM_DPRN,'
      '    IDTPRICE_REM_DPRN,'
      '    IDRTPRICE_REM_DPRN,'
      '    RSUM_REM_DPRN,'
      '    PRIM_REM_DPRN,'
      '    NUMDOCPOST_REM_DPRN,'
      '    POSDOCPOST_REM_DPRN,'
      '    FL_TREB_OTCHET_REM_DPRN,'
      '    FL_OTV_HRAN_REM_DPRN'
      ')'
      'VALUES('
      '    :ID_REM_DPRN,'
      '    :IDBASE_REM_DPRN,'
      '    :IDDOC_REM_DPRN,'
      '    :GID_REM_DPRN,'
      '    :IDTPRICE_REM_DPRN,'
      '    :IDRTPRICE_REM_DPRN,'
      '    :RSUM_REM_DPRN,'
      '    :PRIM_REM_DPRN,'
      '    :NUMDOCPOST_REM_DPRN,'
      '    :POSDOCPOST_REM_DPRN,'
      '    :FL_TREB_OTCHET_REM_DPRN,'
      '    :FL_OTV_HRAN_REM_DPRN'
      ')')
    RefreshSQL.Strings = (
      'select rem_dprn.*'
      'from  rem_dprn'
      'where(  rem_dprn.iddoc_rem_dprn=:PARAM_IDDOC'
      '     ) and (     REM_DPRN.ID_REM_DPRN = :OLD_ID_REM_DPRN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dprn.*'
      'from  rem_dprn'
      'where rem_dprn.iddoc_rem_dprn=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DPRN'
    AutoUpdateOptions.KeyFields = 'ID_REM_DPRN'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DPRN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DPRN: TFIBLargeIntField
      FieldName = 'ID_REM_DPRN'
    end
    object DocIDBASE_REM_DPRN: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DPRN'
    end
    object DocIDDOC_REM_DPRN: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DPRN'
    end
    object DocGID_REM_DPRN: TFIBWideStringField
      FieldName = 'GID_REM_DPRN'
      Size = 10
    end
    object DocIDTPRICE_REM_DPRN: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DPRN'
    end
    object DocIDRTPRICE_REM_DPRN: TFIBLargeIntField
      FieldName = 'IDRTPRICE_REM_DPRN'
    end
    object DocRSUM_REM_DPRN: TFIBBCDField
      FieldName = 'RSUM_REM_DPRN'
      Size = 2
      RoundByScale = True
    end
    object DocPRIM_REM_DPRN: TFIBWideStringField
      FieldName = 'PRIM_REM_DPRN'
      Size = 100
    end
    object DocNUMDOCPOST_REM_DPRN: TFIBWideStringField
      FieldName = 'NUMDOCPOST_REM_DPRN'
      Size = 100
    end
    object DocPOSDOCPOST_REM_DPRN: TFIBDateTimeField
      FieldName = 'POSDOCPOST_REM_DPRN'
    end
    object DocFL_TREB_OTCHET_REM_DPRN: TFIBSmallIntField
      FieldName = 'FL_TREB_OTCHET_REM_DPRN'
    end
    object DocFL_OTV_HRAN_REM_DPRN: TFIBSmallIntField
      FieldName = 'FL_OTV_HRAN_REM_DPRN'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DPRNT'
      'SET '
      '    IDBASE_REM_DPRNT = :IDBASE_REM_DPRNT,'
      '    IDDOC_REM_DPRNT = :IDDOC_REM_DPRNT,'
      '    GID_REM_DPRNT = :GID_REM_DPRNT,'
      '    IDNOM_REM_DPRNT = :IDNOM_REM_DPRNT,'
      '    IDED_REM_DPRNT = :IDED_REM_DPRNT,'
      '    IDHW_REM_DPRNT = :IDHW_REM_DPRNT,'
      '    KOL_REM_DPRNT = :KOL_REM_DPRNT,'
      '    KF_REM_DPRNT = :KF_REM_DPRNT,'
      '    PRICE_REM_DPRNT = :PRICE_REM_DPRNT,'
      '    SUM_REM_DPRNT = :SUM_REM_DPRNT,'
      '    NAC_REM_DPRNT = :NAC_REM_DPRNT,'
      '    RPRICE_REM_DPRNT = :RPRICE_REM_DPRNT,'
      '    RSUM_REM_DPRNT = :RSUM_REM_DPRNT,'
      '    NDS_REM_DPRNT = :NDS_REM_DPRNT,'
      '    SUMNDS_REM_DPRNT = :SUMNDS_REM_DPRNT,'
      '    DVREG_REM_DPRNT = :DVREG_REM_DPRNT,'
      '    IDCQT_REM_DPRNT = :IDCQT_REM_DPRNT,'
      '    IDTNOM_REM_DPRNT = :IDTNOM_REM_DPRNT,'
      '    IDMHRAN_REM_DPRNT = :IDMHRAN_REM_DPRNT'
      'WHERE'
      '    ID_REM_DPRNT = :OLD_ID_REM_DPRNT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DPRNT'
      'WHERE'
      '        ID_REM_DPRNT = :OLD_ID_REM_DPRNT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DPRNT('
      '    ID_REM_DPRNT,'
      '    IDBASE_REM_DPRNT,'
      '    IDDOC_REM_DPRNT,'
      '    GID_REM_DPRNT,'
      '    IDNOM_REM_DPRNT,'
      '    IDED_REM_DPRNT,'
      '    IDHW_REM_DPRNT,'
      '    KOL_REM_DPRNT,'
      '    KF_REM_DPRNT,'
      '    PRICE_REM_DPRNT,'
      '    SUM_REM_DPRNT,'
      '    NAC_REM_DPRNT,'
      '    RPRICE_REM_DPRNT,'
      '    RSUM_REM_DPRNT,'
      '    NDS_REM_DPRNT,'
      '    SUMNDS_REM_DPRNT,'
      '    DVREG_REM_DPRNT,'
      '    IDCQT_REM_DPRNT,'
      '    IDTNOM_REM_DPRNT,'
      '    IDMHRAN_REM_DPRNT'
      ')'
      'VALUES('
      '    :ID_REM_DPRNT,'
      '    :IDBASE_REM_DPRNT,'
      '    :IDDOC_REM_DPRNT,'
      '    :GID_REM_DPRNT,'
      '    :IDNOM_REM_DPRNT,'
      '    :IDED_REM_DPRNT,'
      '    :IDHW_REM_DPRNT,'
      '    :KOL_REM_DPRNT,'
      '    :KF_REM_DPRNT,'
      '    :PRICE_REM_DPRNT,'
      '    :SUM_REM_DPRNT,'
      '    :NAC_REM_DPRNT,'
      '    :RPRICE_REM_DPRNT,'
      '    :RSUM_REM_DPRNT,'
      '    :NDS_REM_DPRNT,'
      '    :SUMNDS_REM_DPRNT,'
      '    :DVREG_REM_DPRNT,'
      '    :IDCQT_REM_DPRNT,'
      '    :IDTNOM_REM_DPRNT,'
      '    :IDMHRAN_REM_DPRNT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dprnt.*,'
      '    snom.namenom,'
      '    snom.fl_add_in_soborud_snom,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.nameed ,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_cquery.id_rem_cquery,'
      '    rem_cquery.name_rem_cquery,'
      '    rem_cquery.num_rem_cquery,'
      '    rem_cquery.pos_rem_cquery,'
      '    rem_cquery.klient_name_rem_cquery,'
      '    rem_cquery.name_model_rem_cquery,'
      '    rem_cquery.num_str_zak_post_rem_cquery,'
      '    rem_z.id_rem_z,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_z.sernum2_rem_z,'
      '    rem_z_1.str_code_vigr_rem_z_1,'
      '    smhran.name_smhran,'
      '    Stnom.name_stnom'
      'from rem_dprnt'
      'left outer join SNOM  on rem_dprnt.idnom_rem_dprnt=snom.idnom'
      'left outer join SED  on  rem_dprnt.ided_rem_dprnt=sed.ided'
      
        'left outer join rem_shardware on rem_dprnt.idhw_rem_dprnt=rem_sh' +
        'ardware.id_rem_shardware'
      ''
      
        'left outer join rem_cqueryt on rem_dprnt.idcqt_rem_dprnt=rem_cqu' +
        'eryt.id_rem_cqueryt'
      
        'left outer join rem_cquery on rem_cqueryt.idcq_rem_cqueryt=rem_c' +
        'query.id_rem_cquery'
      
        'left outer join rem_z on rem_cquery.idz_rem_cquery=rem_z.id_rem_' +
        'z'
      'left outer join rem_z_1 on rem_z_1.idz_rem_z_1=rem_z.id_rem_z'
      
        'left outer join rem_sprmodel on rem_cquery.idprmodel_rem_cquery=' +
        'rem_sprmodel.id_rem_sprmodel'
      ''
      
        'left outer join smhran  on rem_dprnt.idmhran_rem_dprnt=smhran.id' +
        '_smhran'
      
        'left outer join stnom  on rem_dprnt.idtnom_rem_dprnt=stnom.id_st' +
        'nom'
      'where(  rem_dprnt.iddoc_rem_dprnt=:PARAM_IDDOC'
      '     ) and (     REM_DPRNT.ID_REM_DPRNT = :OLD_ID_REM_DPRNT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dprnt.*,'
      '    snom.namenom,'
      '    snom.fl_add_in_soborud_snom,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.nameed ,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_cquery.id_rem_cquery,'
      '    rem_cquery.name_rem_cquery,'
      '    rem_cquery.num_rem_cquery,'
      '    rem_cquery.pos_rem_cquery,'
      '    rem_cquery.klient_name_rem_cquery,'
      '    rem_cquery.name_model_rem_cquery,'
      '    rem_cquery.num_str_zak_post_rem_cquery,'
      '    rem_z.id_rem_z,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_z.sernum2_rem_z,'
      '    rem_z_1.str_code_vigr_rem_z_1,'
      '    smhran.name_smhran,'
      '    Stnom.name_stnom'
      'from rem_dprnt'
      'left outer join SNOM  on rem_dprnt.idnom_rem_dprnt=snom.idnom'
      'left outer join SED  on  rem_dprnt.ided_rem_dprnt=sed.ided'
      
        'left outer join rem_shardware on rem_dprnt.idhw_rem_dprnt=rem_sh' +
        'ardware.id_rem_shardware'
      ''
      
        'left outer join rem_cqueryt on rem_dprnt.idcqt_rem_dprnt=rem_cqu' +
        'eryt.id_rem_cqueryt'
      
        'left outer join rem_cquery on rem_cqueryt.idcq_rem_cqueryt=rem_c' +
        'query.id_rem_cquery'
      
        'left outer join rem_z on rem_cquery.idz_rem_cquery=rem_z.id_rem_' +
        'z'
      'left outer join rem_z_1 on rem_z_1.idz_rem_z_1=rem_z.id_rem_z'
      
        'left outer join rem_sprmodel on rem_cquery.idprmodel_rem_cquery=' +
        'rem_sprmodel.id_rem_sprmodel'
      ''
      
        'left outer join smhran  on rem_dprnt.idmhran_rem_dprnt=smhran.id' +
        '_smhran'
      
        'left outer join stnom  on rem_dprnt.idtnom_rem_dprnt=stnom.id_st' +
        'nom'
      'where rem_dprnt.iddoc_rem_dprnt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DPRNT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DPRNT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DPRNT_ID'
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
    object DocTID_REM_DPRNT: TFIBLargeIntField
      FieldName = 'ID_REM_DPRNT'
    end
    object DocTIDBASE_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DPRNT'
    end
    object DocTIDDOC_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DPRNT'
    end
    object DocTGID_REM_DPRNT: TFIBWideStringField
      FieldName = 'GID_REM_DPRNT'
      Size = 10
    end
    object DocTIDNOM_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DPRNT'
    end
    object DocTIDED_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDED_REM_DPRNT'
    end
    object DocTIDHW_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DPRNT'
    end
    object DocTKOL_REM_DPRNT: TFIBBCDField
      FieldName = 'KOL_REM_DPRNT'
      OnChange = DocTKOL_REM_DPRNTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DPRNT: TFIBBCDField
      FieldName = 'KF_REM_DPRNT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DPRNT: TFIBBCDField
      FieldName = 'PRICE_REM_DPRNT'
      OnChange = DocTPRICE_REM_DPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DPRNT: TFIBBCDField
      FieldName = 'SUM_REM_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_REM_DPRNT: TFIBBCDField
      FieldName = 'NAC_REM_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_REM_DPRNT: TFIBBCDField
      FieldName = 'RPRICE_REM_DPRNT'
      OnChange = DocTRPRICE_REM_DPRNTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_REM_DPRNT: TFIBBCDField
      FieldName = 'RSUM_REM_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_REM_DPRNT: TFIBIntegerField
      FieldName = 'NDS_REM_DPRNT'
    end
    object DocTSUMNDS_REM_DPRNT: TFIBBCDField
      FieldName = 'SUMNDS_REM_DPRNT'
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
    object DocTNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTDVREG_REM_DPRNT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DPRNT'
    end
    object DocTIDCQT_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDCQT_REM_DPRNT'
    end
    object DocTFL_ADD_IN_SOBORUD_SNOM: TFIBSmallIntField
      FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
    end
    object DocTID_REM_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERY'
    end
    object DocTNAME_REM_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_CQUERY'
      OnGetText = DocTNAME_REM_CQUERYGetText
      Size = 200
    end
    object DocTNUM_REM_CQUERY: TFIBIntegerField
      FieldName = 'NUM_REM_CQUERY'
    end
    object DocTPOS_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_REM_CQUERY'
    end
    object DocTKLIENT_NAME_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_CQUERY'
      Size = 200
    end
    object DocTNAME_MODEL_REM_CQUERY: TFIBWideStringField
      FieldName = 'NAME_MODEL_REM_CQUERY'
      Size = 40
    end
    object DocTNUM_STR_ZAK_POST_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_STR_ZAK_POST_REM_CQUERY'
    end
    object DocTID_REM_Z: TFIBLargeIntField
      FieldName = 'ID_REM_Z'
    end
    object DocTNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      OnGetText = DocTNAME_REM_ZGetText
      Size = 200
    end
    object DocTPREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object DocTNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocTPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocTMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocTSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocTSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocTSTR_CODE_VIGR_REM_Z_1: TFIBWideStringField
      FieldName = 'STR_CODE_VIGR_REM_Z_1'
      Size = 40
    end
    object DocTIDTNOM_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DPRNT'
    end
    object DocTIDMHRAN_REM_DPRNT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DPRNT'
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
    Left = 304
    Top = 296
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select max(rem_galldoc.num_rem_galldoc) AS MAXNUMBER from  rem_g' +
        'alldoc'
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMPRN'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
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
      'EXECUTE PROCEDURE REM_DOC_PRN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_PRN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
