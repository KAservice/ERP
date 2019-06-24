object REM_DMDocOtprPost: TREM_DMDocOtprPost
  OldCreateOrder = False
  OnCreate = DataModuleCreate
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
      'UPDATE REM_DOTPRPOST'
      'SET '
      '    IDBASE_REM_DOTPRPOST = :IDBASE_REM_DOTPRPOST,'
      '    IDEXT_BASE_REM_DOTPRPOST = :IDEXT_BASE_REM_DOTPRPOST,'
      '    IDEXT_DOUT_REM_DOTPRPOST = :IDEXT_DOUT_REM_DOTPRPOST,'
      '    TYPE_TBL_REM_DOTPRPOST = :TYPE_TBL_REM_DOTPRPOST,'
      '    IDDOC_REM_DOTPRPOST = :IDDOC_REM_DOTPRPOST,'
      '    IDTPRICE_REM_DOTPRPOST = :IDTPRICE_REM_DOTPRPOST,'
      '    IDBRAND_REM_DOTPRPOST = :IDBRAND_REM_DOTPRPOST,'
      '    IDPRODUCER_REM_DOTPRPOST = :IDPRODUCER_REM_DOTPRPOST,'
      '    TK_REM_DOTPRPOST = :TK_REM_DOTPRPOST,'
      '    NUMDOCTK_REM_DOTPRPOST = :NUMDOCTK_REM_DOTPRPOST,'
      '    PLANDOSTAVKI_REM_DOTPRPOST = :PLANDOSTAVKI_REM_DOTPRPOST'
      'WHERE'
      '    ID_REM_DOTPRPOST = :OLD_ID_REM_DOTPRPOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DOTPRPOST'
      'WHERE'
      '        ID_REM_DOTPRPOST = :OLD_ID_REM_DOTPRPOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DOTPRPOST('
      '    ID_REM_DOTPRPOST,'
      '    IDBASE_REM_DOTPRPOST,'
      '    IDEXT_BASE_REM_DOTPRPOST,'
      '    IDEXT_DOUT_REM_DOTPRPOST,'
      '    TYPE_TBL_REM_DOTPRPOST,'
      '    IDDOC_REM_DOTPRPOST,'
      '    IDTPRICE_REM_DOTPRPOST,'
      '    IDBRAND_REM_DOTPRPOST,'
      '    IDPRODUCER_REM_DOTPRPOST,'
      '    TK_REM_DOTPRPOST,'
      '    NUMDOCTK_REM_DOTPRPOST,'
      '    PLANDOSTAVKI_REM_DOTPRPOST'
      ')'
      'VALUES('
      '    :ID_REM_DOTPRPOST,'
      '    :IDBASE_REM_DOTPRPOST,'
      '    :IDEXT_BASE_REM_DOTPRPOST,'
      '    :IDEXT_DOUT_REM_DOTPRPOST,'
      '    :TYPE_TBL_REM_DOTPRPOST,'
      '    :IDDOC_REM_DOTPRPOST,'
      '    :IDTPRICE_REM_DOTPRPOST,'
      '    :IDBRAND_REM_DOTPRPOST,'
      '    :IDPRODUCER_REM_DOTPRPOST,'
      '    :TK_REM_DOTPRPOST,'
      '    :NUMDOCTK_REM_DOTPRPOST,'
      '    :PLANDOSTAVKI_REM_DOTPRPOST'
      ')')
    RefreshSQL.Strings = (
      'select rem_dotprpost.*,'
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer'
      '    '
      'from  rem_dotprpost'
      
        'left outer join sbrand on rem_dotprpost.idbrand_rem_dotprpost=sb' +
        'rand.id_sbrand'
      
        'left outer join sproducer on rem_dotprpost.idproducer_rem_dotprp' +
        'ost=sproducer.id_sproducer'
      'where(  rem_dotprpost.iddoc_rem_dotprpost=:PARAM_IDDOC'
      
        '     ) and (     REM_DOTPRPOST.ID_REM_DOTPRPOST = :OLD_ID_REM_DO' +
        'TPRPOST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dotprpost.*,'
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer'
      '    '
      'from  rem_dotprpost'
      
        'left outer join sbrand on rem_dotprpost.idbrand_rem_dotprpost=sb' +
        'rand.id_sbrand'
      
        'left outer join sproducer on rem_dotprpost.idproducer_rem_dotprp' +
        'ost=sproducer.id_sproducer'
      'where rem_dotprpost.iddoc_rem_dotprpost=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DOTPRPOST'
    AutoUpdateOptions.KeyFields = 'ID_REM_DOTPRPOST'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DOTPRPOST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'ID_REM_DOTPRPOST'
    end
    object DocIDBASE_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DOTPRPOST'
    end
    object DocIDDOC_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DOTPRPOST'
    end
    object DocIDTPRICE_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DOTPRPOST'
    end
    object DocIDBRAND_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_DOTPRPOST'
    end
    object DocIDPRODUCER_REM_DOTPRPOST: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_DOTPRPOST'
    end
    object DocTK_REM_DOTPRPOST: TFIBWideStringField
      FieldName = 'TK_REM_DOTPRPOST'
    end
    object DocNUMDOCTK_REM_DOTPRPOST: TFIBWideStringField
      FieldName = 'NUMDOCTK_REM_DOTPRPOST'
      Size = 40
    end
    object DocPLANDOSTAVKI_REM_DOTPRPOST: TFIBDateField
      FieldName = 'PLANDOSTAVKI_REM_DOTPRPOST'
    end
    object DocNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object DocNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DOTPRPOSTT'
      'SET '
      '    IDBASE_REM_DOTPRPOSTT = :IDBASE_REM_DOTPRPOSTT,'
      '    IDDOC_REM_DOTPRPOSTT = :IDDOC_REM_DOTPRPOSTT,'
      '    IDNOM_REM_DOTPRPOSTT = :IDNOM_REM_DOTPRPOSTT,'
      '    IDED_REM_DOTPRPOSTT = :IDED_REM_DOTPRPOSTT,'
      '    KOL_REM_DOTPRPOSTT = :KOL_REM_DOTPRPOSTT,'
      '    KF_REM_DOTPRPOSTT = :KF_REM_DOTPRPOSTT,'
      '    PRICE_REM_DOTPRPOSTT = :PRICE_REM_DOTPRPOSTT,'
      '    SUM_REM_DOTPRPOSTT = :SUM_REM_DOTPRPOSTT,'
      '    IDCQT_REM_DOTPRPOSTT = :IDCQT_REM_DOTPRPOSTT,'
      '    IDPRNOM_REM_DOTPRPOSTT = :IDPRNOM_REM_DOTPRPOSTT'
      'WHERE'
      '    ID_REM_DOTPRPOSTT = :OLD_ID_REM_DOTPRPOSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DOTPRPOSTT'
      'WHERE'
      '        ID_REM_DOTPRPOSTT = :OLD_ID_REM_DOTPRPOSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DOTPRPOSTT('
      '    ID_REM_DOTPRPOSTT,'
      '    IDBASE_REM_DOTPRPOSTT,'
      '    IDDOC_REM_DOTPRPOSTT,'
      '    IDNOM_REM_DOTPRPOSTT,'
      '    IDED_REM_DOTPRPOSTT,'
      '    KOL_REM_DOTPRPOSTT,'
      '    KF_REM_DOTPRPOSTT,'
      '    PRICE_REM_DOTPRPOSTT,'
      '    SUM_REM_DOTPRPOSTT,'
      '    IDCQT_REM_DOTPRPOSTT,'
      '    IDPRNOM_REM_DOTPRPOSTT'
      ')'
      'VALUES('
      '    :ID_REM_DOTPRPOSTT,'
      '    :IDBASE_REM_DOTPRPOSTT,'
      '    :IDDOC_REM_DOTPRPOSTT,'
      '    :IDNOM_REM_DOTPRPOSTT,'
      '    :IDED_REM_DOTPRPOSTT,'
      '    :KOL_REM_DOTPRPOSTT,'
      '    :KF_REM_DOTPRPOSTT,'
      '    :PRICE_REM_DOTPRPOSTT,'
      '    :SUM_REM_DOTPRPOSTT,'
      '    :IDCQT_REM_DOTPRPOSTT,'
      '    :IDPRNOM_REM_DOTPRPOSTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dotprpostt.*,'
      '    snom.namenom,'
      '    snom.fl_add_in_soborud_snom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
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
      '    rem_sprmodel.name_rem_sprmodel,'
      '    sprnom.art_sprnom,'
      '    sprnom.name_sprnom,'
      '    sprnom.fl_dostupno_sprnom,'
      '    sprnom.model_str_sprnom,'
      '    rem_cqueryt.art_rem_cqueryt,'
      '    rem_cqueryt.namenom_rem_cqueryt'
      ''
      ''
      'from rem_dotprpostt'
      
        'left outer join SNOM  on rem_dotprpostt.idnom_rem_dotprpostt=sno' +
        'm.idnom'
      
        'left outer join SED  on  rem_dotprpostt.ided_rem_dotprpostt=sed.' +
        'ided'
      ''
      
        'left outer join rem_cqueryt on rem_dotprpostt.idcqt_rem_dotprpos' +
        'tt=rem_cqueryt.id_rem_cqueryt'
      
        'left outer join rem_cquery on rem_cqueryt.idcq_rem_cqueryt=rem_c' +
        'query.id_rem_cquery'
      
        'left outer join rem_z on rem_cquery.idz_rem_cquery=rem_z.id_rem_' +
        'z'
      'left outer join rem_z_1 on rem_z_1.idz_rem_z_1=rem_z.id_rem_z'
      
        'left outer join rem_sprmodel on rem_cquery.idprmodel_rem_cquery=' +
        'rem_sprmodel.id_rem_sprmodel'
      
        'left outer join sprnom on rem_dotprpostt.idprnom_rem_dotprpostt=' +
        'sprnom.id_sprnom'
      'where(  rem_dotprpostt.iddoc_rem_dotprpostt=:PARAM_IDDOC'
      
        '     ) and (     REM_DOTPRPOSTT.ID_REM_DOTPRPOSTT = :OLD_ID_REM_' +
        'DOTPRPOSTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dotprpostt.*,'
      '    snom.namenom,'
      '    snom.fl_add_in_soborud_snom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
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
      '    rem_sprmodel.name_rem_sprmodel,'
      '    sprnom.art_sprnom,'
      '    sprnom.name_sprnom,'
      '    sprnom.fl_dostupno_sprnom,'
      '    sprnom.model_str_sprnom,'
      '    rem_cqueryt.art_rem_cqueryt,'
      '    rem_cqueryt.namenom_rem_cqueryt'
      ''
      ''
      'from rem_dotprpostt'
      
        'left outer join SNOM  on rem_dotprpostt.idnom_rem_dotprpostt=sno' +
        'm.idnom'
      
        'left outer join SED  on  rem_dotprpostt.ided_rem_dotprpostt=sed.' +
        'ided'
      ''
      
        'left outer join rem_cqueryt on rem_dotprpostt.idcqt_rem_dotprpos' +
        'tt=rem_cqueryt.id_rem_cqueryt'
      
        'left outer join rem_cquery on rem_cqueryt.idcq_rem_cqueryt=rem_c' +
        'query.id_rem_cquery'
      
        'left outer join rem_z on rem_cquery.idz_rem_cquery=rem_z.id_rem_' +
        'z'
      'left outer join rem_z_1 on rem_z_1.idz_rem_z_1=rem_z.id_rem_z'
      
        'left outer join rem_sprmodel on rem_cquery.idprmodel_rem_cquery=' +
        'rem_sprmodel.id_rem_sprmodel'
      
        'left outer join sprnom on rem_dotprpostt.idprnom_rem_dotprpostt=' +
        'sprnom.id_sprnom'
      'where rem_dotprpostt.iddoc_rem_dotprpostt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZAKPOSTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZAKPOSTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZAKPOSTT_ID'
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
    object DocTID_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'ID_REM_DOTPRPOSTT'
    end
    object DocTIDBASE_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DOTPRPOSTT'
    end
    object DocTIDDOC_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DOTPRPOSTT'
    end
    object DocTIDNOM_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DOTPRPOSTT'
    end
    object DocTIDED_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDED_REM_DOTPRPOSTT'
    end
    object DocTKOL_REM_DOTPRPOSTT: TFIBBCDField
      FieldName = 'KOL_REM_DOTPRPOSTT'
      OnChange = DocTKOL_REM_DOTPRPOSTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DOTPRPOSTT: TFIBBCDField
      FieldName = 'KF_REM_DOTPRPOSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DOTPRPOSTT: TFIBBCDField
      FieldName = 'PRICE_REM_DOTPRPOSTT'
      OnChange = DocTPRICE_REM_DOTPRPOSTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DOTPRPOSTT: TFIBBCDField
      FieldName = 'SUM_REM_DOTPRPOSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTIDCQT_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDCQT_REM_DOTPRPOSTT'
    end
    object DocTIDPRNOM_REM_DOTPRPOSTT: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_DOTPRPOSTT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTFL_ADD_IN_SOBORUD_SNOM: TFIBSmallIntField
      FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
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
    object DocTNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocTART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
      Size = 40
    end
    object DocTNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
    object DocTFL_DOSTUPNO_SPRNOM: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SPRNOM'
    end
    object DocTMODEL_STR_SPRNOM: TFIBWideStringField
      FieldName = 'MODEL_STR_SPRNOM'
      Size = 30
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTART_REM_CQUERYT: TFIBWideStringField
      FieldName = 'ART_REM_CQUERYT'
      Size = 40
    end
    object DocTNAMENOM_REM_CQUERYT: TFIBWideStringField
      FieldName = 'NAMENOM_REM_CQUERYT'
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
      'select *'
      'from REM_DOC_OTPRPOST_GET_NUM_DOC (:PARAM_IDBASE)')
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
      
        'EXECUTE PROCEDURE REM_DOC_OTPRPOST_CANCEL_DVREG(:PARAM_IDDOC,0,0' +
        ',0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_OTPRPOST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
