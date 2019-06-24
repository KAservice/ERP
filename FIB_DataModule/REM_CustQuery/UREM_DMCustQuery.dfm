object REM_DMCustQuery: TREM_DMCustQuery
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 424
  Width = 609
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 72
  end
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 16
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_CQUERY'
      'SET '
      '    GID_REM_CQUERY = :GID_REM_CQUERY,'
      '    IDBASE_REM_CQUERY = :IDBASE_REM_CQUERY,'
      '    POS_REM_CQUERY = :POS_REM_CQUERY,'
      '    NUM_REM_CQUERY = :NUM_REM_CQUERY,'
      '    IDFIRM_REM_CQUERY = :IDFIRM_REM_CQUERY,'
      '    IDSKLAD_REM_CQUERY = :IDSKLAD_REM_CQUERY,'
      '    IDUSER_REM_CQUERY = :IDUSER_REM_CQUERY,'
      '    IDKLIENT_REM_CQUERY = :IDKLIENT_REM_CQUERY,'
      '    KLIENT_NAME_REM_CQUERY = :KLIENT_NAME_REM_CQUERY,'
      '    KLIENT_ADR_REM_CQUERY = :KLIENT_ADR_REM_CQUERY,'
      '    KLIENT_PHONE_REM_CQUERY = :KLIENT_PHONE_REM_CQUERY,'
      '    COMMENTS_REM_CQUERY = :COMMENTS_REM_CQUERY,'
      '    RUN_REM_CQUERY = :RUN_REM_CQUERY,'
      '    DO_SUM_REM_CQUERY = :DO_SUM_REM_CQUERY,'
      '    TEC_SUM_REM_CQUERY = :TEC_SUM_REM_CQUERY,'
      '    SOGL_SUM_REM_CQUERY = :SOGL_SUM_REM_CQUERY,'
      '    IDZ_REM_CQUERY = :IDZ_REM_CQUERY,'
      '    IDMODEL_REM_CQUERY = :IDMODEL_REM_CQUERY,'
      '    NAME_MODEL_REM_CQUERY = :NAME_MODEL_REM_CQUERY,'
      '    IDBRAND_REM_CQUERY = :IDBRAND_REM_CQUERY,'
      '    IDPRODUCER_REM_CQUERY = :IDPRODUCER_REM_CQUERY,'
      
        '    FL_KLIENT_UVEDOML_REM_CQUERY = :FL_KLIENT_UVEDOML_REM_CQUERY' +
        ','
      '    NUM_ZAKAZA_REM_CQUERY = :NUM_ZAKAZA_REM_CQUERY,'
      '    DATE_ZAKAZA_REM_CQUERY = :DATE_ZAKAZA_REM_CQUERY,'
      '    IDHW_REM_CQUERY = :IDHW_REM_CQUERY,'
      '    TYPE_REM_CQUERY = :TYPE_REM_CQUERY,'
      '    IDPRMODEL_REM_CQUERY = :IDPRMODEL_REM_CQUERY,'
      '    POSTUPILO_REM_CQUERY = :POSTUPILO_REM_CQUERY,'
      '    PLAN_POSTAVKI_REM_CQUERY = :PLAN_POSTAVKI_REM_CQUERY,'
      '    ZAKAZANO_REM_CQUERY = :ZAKAZANO_REM_CQUERY,'
      '    OTPRAVLENO_REM_CQUERY = :OTPRAVLENO_REM_CQUERY,'
      '    NAME_REM_CQUERY = :NAME_REM_CQUERY,'
      '    NUM_STR_ZAK_POST_REM_CQUERY = :NUM_STR_ZAK_POST_REM_CQUERY,'
      '    POS_ZAK_POST_REM_CQUERY = :POS_ZAK_POST_REM_CQUERY,'
      
        '    NUM_STR_ZAK_SPROV_REM_CQUERY = :NUM_STR_ZAK_SPROV_REM_CQUERY' +
        ','
      '    POS_ZAK_SPROV_REM_CQUERY = :POS_ZAK_SPROV_REM_CQUERY,'
      
        '    NUM_DOC_OTPR_POST_REM_CQUERY = :NUM_DOC_OTPR_POST_REM_CQUERY' +
        ','
      
        '    POS_DOC_OTPR_POST_REM_CQUERY = :POS_DOC_OTPR_POST_REM_CQUERY' +
        ','
      '    NUMDOCTK_REM_CQUERY = :NUMDOCTK_REM_CQUERY,'
      '    TK_REM_CQUERY = :TK_REM_CQUERY,'
      '    IDPRODAVEC_REM_CQUERY = :IDPRODAVEC_REM_CQUERY'
      'WHERE'
      '    ID_REM_CQUERY = :OLD_ID_REM_CQUERY'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_CQUERY'
      'WHERE'
      '        ID_REM_CQUERY = :OLD_ID_REM_CQUERY'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_CQUERY('
      '    ID_REM_CQUERY,'
      '    GID_REM_CQUERY,'
      '    IDBASE_REM_CQUERY,'
      '    POS_REM_CQUERY,'
      '    NUM_REM_CQUERY,'
      '    IDFIRM_REM_CQUERY,'
      '    IDSKLAD_REM_CQUERY,'
      '    IDUSER_REM_CQUERY,'
      '    IDKLIENT_REM_CQUERY,'
      '    KLIENT_NAME_REM_CQUERY,'
      '    KLIENT_ADR_REM_CQUERY,'
      '    KLIENT_PHONE_REM_CQUERY,'
      '    COMMENTS_REM_CQUERY,'
      '    RUN_REM_CQUERY,'
      '    DO_SUM_REM_CQUERY,'
      '    TEC_SUM_REM_CQUERY,'
      '    SOGL_SUM_REM_CQUERY,'
      '    IDZ_REM_CQUERY,'
      '    IDMODEL_REM_CQUERY,'
      '    NAME_MODEL_REM_CQUERY,'
      '    IDBRAND_REM_CQUERY,'
      '    IDPRODUCER_REM_CQUERY,'
      '    FL_KLIENT_UVEDOML_REM_CQUERY,'
      '    NUM_ZAKAZA_REM_CQUERY,'
      '    DATE_ZAKAZA_REM_CQUERY,'
      '    IDHW_REM_CQUERY,'
      '    TYPE_REM_CQUERY,'
      '    IDPRMODEL_REM_CQUERY,'
      '    POSTUPILO_REM_CQUERY,'
      '    PLAN_POSTAVKI_REM_CQUERY,'
      '    ZAKAZANO_REM_CQUERY,'
      '    OTPRAVLENO_REM_CQUERY,'
      '    NAME_REM_CQUERY,'
      '    NUM_STR_ZAK_POST_REM_CQUERY,'
      '    POS_ZAK_POST_REM_CQUERY,'
      '    NUM_STR_ZAK_SPROV_REM_CQUERY,'
      '    POS_ZAK_SPROV_REM_CQUERY,'
      '    NUM_DOC_OTPR_POST_REM_CQUERY,'
      '    POS_DOC_OTPR_POST_REM_CQUERY,'
      '    NUMDOCTK_REM_CQUERY,'
      '    TK_REM_CQUERY,'
      '    IDPRODAVEC_REM_CQUERY'
      ')'
      'VALUES('
      '    :ID_REM_CQUERY,'
      '    :GID_REM_CQUERY,'
      '    :IDBASE_REM_CQUERY,'
      '    :POS_REM_CQUERY,'
      '    :NUM_REM_CQUERY,'
      '    :IDFIRM_REM_CQUERY,'
      '    :IDSKLAD_REM_CQUERY,'
      '    :IDUSER_REM_CQUERY,'
      '    :IDKLIENT_REM_CQUERY,'
      '    :KLIENT_NAME_REM_CQUERY,'
      '    :KLIENT_ADR_REM_CQUERY,'
      '    :KLIENT_PHONE_REM_CQUERY,'
      '    :COMMENTS_REM_CQUERY,'
      '    :RUN_REM_CQUERY,'
      '    :DO_SUM_REM_CQUERY,'
      '    :TEC_SUM_REM_CQUERY,'
      '    :SOGL_SUM_REM_CQUERY,'
      '    :IDZ_REM_CQUERY,'
      '    :IDMODEL_REM_CQUERY,'
      '    :NAME_MODEL_REM_CQUERY,'
      '    :IDBRAND_REM_CQUERY,'
      '    :IDPRODUCER_REM_CQUERY,'
      '    :FL_KLIENT_UVEDOML_REM_CQUERY,'
      '    :NUM_ZAKAZA_REM_CQUERY,'
      '    :DATE_ZAKAZA_REM_CQUERY,'
      '    :IDHW_REM_CQUERY,'
      '    :TYPE_REM_CQUERY,'
      '    :IDPRMODEL_REM_CQUERY,'
      '    :POSTUPILO_REM_CQUERY,'
      '    :PLAN_POSTAVKI_REM_CQUERY,'
      '    :ZAKAZANO_REM_CQUERY,'
      '    :OTPRAVLENO_REM_CQUERY,'
      '    :NAME_REM_CQUERY,'
      '    :NUM_STR_ZAK_POST_REM_CQUERY,'
      '    :POS_ZAK_POST_REM_CQUERY,'
      '    :NUM_STR_ZAK_SPROV_REM_CQUERY,'
      '    :POS_ZAK_SPROV_REM_CQUERY,'
      '    :NUM_DOC_OTPR_POST_REM_CQUERY,'
      '    :POS_DOC_OTPR_POST_REM_CQUERY,'
      '    :NUMDOCTK_REM_CQUERY,'
      '    :TK_REM_CQUERY,'
      '    :IDPRODAVEC_REM_CQUERY'
      ')')
    RefreshSQL.Strings = (
      'select rem_cquery.*,'
      '    sfirm.namefirm,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_smodel.name_rem_smodel,'
      '    rem_smodel.code_rem_smodel,'
      '    ssklad.namesklad,'
      '    klient.nameklient,'
      '    rem_z.name_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.klient_name_rem_z,'
      '    rem_z.model_rem_z,'
      '    suser.name_user,'
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_sprmodel.name_rem_sprmodel,'
      '    rem_sprmodel.code_rem_sprmodel,'
      '    prodavec.nameklient'
      'from rem_cquery'
      
        'left outer join sfirm on sfirm.idfirm=rem_cquery.idfirm_rem_cque' +
        'ry'
      
        'left outer join SINFBASE_OBMEN on SINFBASE_OBMEN.id_sinfbase_obm' +
        'en=rem_cquery.idbase_rem_cquery'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_cquer' +
        'y.idmodel_rem_cquery'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_cquery.idprmodel_rem_cquery'
      
        'left outer join ssklad  on ssklad.idsklad=rem_cquery.idsklad_rem' +
        '_cquery'
      
        'left outer join sklient as klient on klient.idklient=rem_cquery.' +
        'idklient_rem_cquery'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_cquery.idz_rem_cquer' +
        'y'
      
        'left outer join suser on suser.id_user=rem_cquery.iduser_rem_cqu' +
        'ery'
      
        'left outer join sbrand on rem_cquery.idbrand_rem_cquery=sbrand.i' +
        'd_sbrand'
      
        'left outer join sproducer on rem_cquery.idproducer_rem_cquery=sp' +
        'roducer.id_sproducer'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_cquery.idhw_rem_cquery'
      
        'left outer join sklient as prodavec on prodavec.idklient=rem_cqu' +
        'ery.idprodavec_rem_cquery'
      'where(  rem_cquery.id_rem_cquery=:PARAM_ID'
      '     ) and (     REM_CQUERY.ID_REM_CQUERY = :OLD_ID_REM_CQUERY'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_cquery.*,'
      '    sfirm.namefirm,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_smodel.name_rem_smodel,'
      '    rem_smodel.code_rem_smodel,'
      '    ssklad.namesklad,'
      '    klient.nameklient,'
      '    rem_z.name_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.klient_name_rem_z,'
      '    rem_z.model_rem_z,'
      '    suser.name_user,'
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_sprmodel.name_rem_sprmodel,'
      '    rem_sprmodel.code_rem_sprmodel,'
      '    prodavec.nameklient  as prodavec_name'
      'from rem_cquery'
      
        'left outer join sfirm on sfirm.idfirm=rem_cquery.idfirm_rem_cque' +
        'ry'
      
        'left outer join SINFBASE_OBMEN on SINFBASE_OBMEN.id_sinfbase_obm' +
        'en=rem_cquery.idbase_rem_cquery'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_cquer' +
        'y.idmodel_rem_cquery'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_cquery.idprmodel_rem_cquery'
      
        'left outer join ssklad  on ssklad.idsklad=rem_cquery.idsklad_rem' +
        '_cquery'
      
        'left outer join sklient as klient on klient.idklient=rem_cquery.' +
        'idklient_rem_cquery'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_cquery.idz_rem_cquer' +
        'y'
      
        'left outer join suser on suser.id_user=rem_cquery.iduser_rem_cqu' +
        'ery'
      
        'left outer join sbrand on rem_cquery.idbrand_rem_cquery=sbrand.i' +
        'd_sbrand'
      
        'left outer join sproducer on rem_cquery.idproducer_rem_cquery=sp' +
        'roducer.id_sproducer'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_cquery.idhw_rem_cquery'
      
        'left outer join sklient as prodavec on prodavec.idklient=rem_cqu' +
        'ery.idprodavec_rem_cquery'
      'where rem_cquery.id_rem_cquery=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_CQUERY'
    AutoUpdateOptions.KeyFields = 'ID_REM_CQUERY'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_CQUERY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocID_REM_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERY'
    end
    object DocGID_REM_CQUERY: TFIBWideStringField
      FieldName = 'GID_REM_CQUERY'
      Size = 10
    end
    object DocIDBASE_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_CQUERY'
      OnChange = DocIDBASE_REM_CQUERYChange
    end
    object DocPOS_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object DocNUM_REM_CQUERY: TFIBIntegerField
      FieldName = 'NUM_REM_CQUERY'
    end
    object DocIDFIRM_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_CQUERY'
    end
    object DocIDSKLAD_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_CQUERY'
    end
    object DocIDUSER_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDUSER_REM_CQUERY'
    end
    object DocIDKLIENT_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_CQUERY'
    end
    object DocKLIENT_NAME_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_CQUERY'
      Size = 200
    end
    object DocKLIENT_ADR_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_CQUERY'
      Size = 200
    end
    object DocKLIENT_PHONE_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_CQUERY'
      Size = 40
    end
    object DocCOMMENTS_REM_CQUERY: TFIBWideStringField
      FieldName = 'COMMENTS_REM_CQUERY'
      Size = 250
    end
    object DocRUN_REM_CQUERY: TFIBSmallIntField
      FieldName = 'RUN_REM_CQUERY'
    end
    object DocDO_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'DO_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object DocTEC_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'TEC_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object DocSOGL_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'SOGL_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object DocIDZ_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDZ_REM_CQUERY'
    end
    object DocIDMODEL_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_CQUERY'
    end
    object DocNAME_MODEL_REM_CQUERY: TFIBWideStringField
      FieldName = 'NAME_MODEL_REM_CQUERY'
      Size = 40
    end
    object DocNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object DocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object DocIDBRAND_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_CQUERY'
    end
    object DocIDPRODUCER_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_CQUERY'
    end
    object DocFL_KLIENT_UVEDOML_REM_CQUERY: TFIBSmallIntField
      FieldName = 'FL_KLIENT_UVEDOML_REM_CQUERY'
    end
    object DocNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object DocNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object DocNUM_ZAKAZA_REM_CQUERY: TFIBIntegerField
      FieldName = 'NUM_ZAKAZA_REM_CQUERY'
    end
    object DocDATE_ZAKAZA_REM_CQUERY: TFIBDateField
      FieldName = 'DATE_ZAKAZA_REM_CQUERY'
    end
    object DocIDHW_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDHW_REM_CQUERY'
    end
    object DocTYPE_REM_CQUERY: TFIBIntegerField
      FieldName = 'TYPE_REM_CQUERY'
    end
    object DocNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object DocIDPRMODEL_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_CQUERY'
    end
    object DocPOSTUPILO_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POSTUPILO_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object DocCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object DocNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object DocPLAN_POSTAVKI_REM_CQUERY: TFIBDateField
      FieldName = 'PLAN_POSTAVKI_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object DocZAKAZANO_REM_CQUERY: TFIBDateTimeField
      FieldName = 'ZAKAZANO_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object DocOTPRAVLENO_REM_CQUERY: TFIBDateTimeField
      FieldName = 'OTPRAVLENO_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object DocNAME_REM_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_CQUERY'
      Size = 200
    end
    object DocNUM_STR_ZAK_POST_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_STR_ZAK_POST_REM_CQUERY'
    end
    object DocPOS_ZAK_POST_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_ZAK_POST_REM_CQUERY'
    end
    object DocNUM_STR_ZAK_SPROV_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_STR_ZAK_SPROV_REM_CQUERY'
    end
    object DocPOS_ZAK_SPROV_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_ZAK_SPROV_REM_CQUERY'
    end
    object DocNUM_DOC_OTPR_POST_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_DOC_OTPR_POST_REM_CQUERY'
    end
    object DocPOS_DOC_OTPR_POST_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_DOC_OTPR_POST_REM_CQUERY'
    end
    object DocNUMDOCTK_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUMDOCTK_REM_CQUERY'
      Size = 40
    end
    object DocTK_REM_CQUERY: TFIBWideStringField
      FieldName = 'TK_REM_CQUERY'
    end
    object DocIDPRODAVEC_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDPRODAVEC_REM_CQUERY'
    end
    object DocPRODAVEC_NAME: TFIBWideStringField
      FieldName = 'PRODAVEC_NAME'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_CQUERYT'
      'SET '
      '    GID_REM_CQUERYT = :GID_REM_CQUERYT,'
      '    IDBASE_REM_CQUERYT = :IDBASE_REM_CQUERYT,'
      '    IDCQ_REM_CQUERYT = :IDCQ_REM_CQUERYT,'
      '    IDNOM_REM_CQUERYT = :IDNOM_REM_CQUERYT,'
      '    IDED_REM_CQUERYT = :IDED_REM_CQUERYT,'
      '    IDSOST_REM_CQUERYT = :IDSOST_REM_CQUERYT,'
      '    NAMENOM_REM_CQUERYT = :NAMENOM_REM_CQUERYT,'
      '    KOL_REM_CQUERYT = :KOL_REM_CQUERYT,'
      '    KF_REM_CQUERYT = :KF_REM_CQUERYT,'
      '    PRICE_REM_CQUERYT = :PRICE_REM_CQUERYT,'
      '    SUM_REM_CQUERYT = :SUM_REM_CQUERYT,'
      '    PRICE_DO_REM_CQUERYT = :PRICE_DO_REM_CQUERYT,'
      '    PRICE_TEC_REM_CQUERYT = :PRICE_TEC_REM_CQUERYT,'
      '    PRICE_SOGL_REM_CQUERYT = :PRICE_SOGL_REM_CQUERYT,'
      '    SROK_POST_REM_CQUERYT = :SROK_POST_REM_CQUERYT,'
      '    POS_POST_REM_CQUERYT = :POS_POST_REM_CQUERYT,'
      '    RUN_REM_CQUERYT = :RUN_REM_CQUERYT,'
      '    COMMENTS_REM_CQUERYT = :COMMENTS_REM_CQUERYT,'
      '    ACT_REM_CQUERYT = :ACT_REM_CQUERYT,'
      '    IDPRNOM_REM_CQUERYT = :IDPRNOM_REM_CQUERYT,'
      '    ART_REM_CQUERYT = :ART_REM_CQUERYT,'
      '    SER_NUM_REM_CQUERYT = :SER_NUM_REM_CQUERYT,'
      '    UCH_SER_NUM_REM_CQUERYT = :UCH_SER_NUM_REM_CQUERYT,'
      '    REF_REM_CQUERYT = :REF_REM_CQUERYT'
      'WHERE'
      '    ID_REM_CQUERYT = :OLD_ID_REM_CQUERYT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_CQUERYT'
      'WHERE'
      '        ID_REM_CQUERYT = :OLD_ID_REM_CQUERYT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_CQUERYT('
      '    ID_REM_CQUERYT,'
      '    GID_REM_CQUERYT,'
      '    IDBASE_REM_CQUERYT,'
      '    IDCQ_REM_CQUERYT,'
      '    IDNOM_REM_CQUERYT,'
      '    IDED_REM_CQUERYT,'
      '    IDSOST_REM_CQUERYT,'
      '    NAMENOM_REM_CQUERYT,'
      '    KOL_REM_CQUERYT,'
      '    KF_REM_CQUERYT,'
      '    PRICE_REM_CQUERYT,'
      '    SUM_REM_CQUERYT,'
      '    PRICE_DO_REM_CQUERYT,'
      '    PRICE_TEC_REM_CQUERYT,'
      '    PRICE_SOGL_REM_CQUERYT,'
      '    SROK_POST_REM_CQUERYT,'
      '    POS_POST_REM_CQUERYT,'
      '    RUN_REM_CQUERYT,'
      '    COMMENTS_REM_CQUERYT,'
      '    ACT_REM_CQUERYT,'
      '    IDPRNOM_REM_CQUERYT,'
      '    ART_REM_CQUERYT,'
      '    SER_NUM_REM_CQUERYT,'
      '    UCH_SER_NUM_REM_CQUERYT,'
      '    REF_REM_CQUERYT'
      ')'
      'VALUES('
      '    :ID_REM_CQUERYT,'
      '    :GID_REM_CQUERYT,'
      '    :IDBASE_REM_CQUERYT,'
      '    :IDCQ_REM_CQUERYT,'
      '    :IDNOM_REM_CQUERYT,'
      '    :IDED_REM_CQUERYT,'
      '    :IDSOST_REM_CQUERYT,'
      '    :NAMENOM_REM_CQUERYT,'
      '    :KOL_REM_CQUERYT,'
      '    :KF_REM_CQUERYT,'
      '    :PRICE_REM_CQUERYT,'
      '    :SUM_REM_CQUERYT,'
      '    :PRICE_DO_REM_CQUERYT,'
      '    :PRICE_TEC_REM_CQUERYT,'
      '    :PRICE_SOGL_REM_CQUERYT,'
      '    :SROK_POST_REM_CQUERYT,'
      '    :POS_POST_REM_CQUERYT,'
      '    :RUN_REM_CQUERYT,'
      '    :COMMENTS_REM_CQUERYT,'
      '    :ACT_REM_CQUERYT,'
      '    :IDPRNOM_REM_CQUERYT,'
      '    :ART_REM_CQUERYT,'
      '    :SER_NUM_REM_CQUERYT,'
      '    :UCH_SER_NUM_REM_CQUERYT,'
      '    :REF_REM_CQUERYT'
      ')')
    RefreshSQL.Strings = (
      'select rem_cqueryt.*,'
      '        snom.namenom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.fl_add_in_soborud_snom,'
      '        sed.nameed,'
      '        sed.shed,'
      '        rem_ssost_cquery.name_rem_ssost_cquery,'
      '        sprnom.art_sprnom,'
      '        sprnom.code_sprnom,'
      '        sprnom.name_sprnom'
      'from  rem_cqueryt'
      'left outer join snom on snom.idnom=rem_cqueryt.idnom_rem_cqueryt'
      'left outer join sed on sed.ided=rem_cqueryt.ided_rem_cqueryt'
      
        'left outer join rem_ssost_cquery on rem_ssost_cquery.id_rem_ssos' +
        't_cquery=rem_cqueryt.idsost_rem_cqueryt'
      
        'left outer join sprnom on rem_cqueryt.idprnom_rem_cqueryt=sprnom' +
        '.id_sprnom'
      'where(  rem_cqueryt.idcq_rem_cqueryt=:PARAM_IDCQ'
      
        '     ) and (     REM_CQUERYT.ID_REM_CQUERYT = :OLD_ID_REM_CQUERY' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_cqueryt.*,'
      '        snom.namenom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.fl_add_in_soborud_snom,'
      '        sed.nameed,'
      '        sed.shed,'
      '        rem_ssost_cquery.name_rem_ssost_cquery,'
      '        sprnom.art_sprnom,'
      '        sprnom.code_sprnom,'
      '        sprnom.name_sprnom'
      'from  rem_cqueryt'
      'left outer join snom on snom.idnom=rem_cqueryt.idnom_rem_cqueryt'
      'left outer join sed on sed.ided=rem_cqueryt.ided_rem_cqueryt'
      
        'left outer join rem_ssost_cquery on rem_ssost_cquery.id_rem_ssos' +
        't_cquery=rem_cqueryt.idsost_rem_cqueryt'
      
        'left outer join sprnom on rem_cqueryt.idprnom_rem_cqueryt=sprnom' +
        '.id_sprnom'
      'where rem_cqueryt.idcq_rem_cqueryt=:PARAM_IDCQ')
    AutoUpdateOptions.UpdateTableName = 'REM_CQUERYT'
    AutoUpdateOptions.KeyFields = 'ID_REM_CQUERYT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_CQUERYT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocTID_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERYT'
    end
    object DocTGID_REM_CQUERYT: TFIBWideStringField
      FieldName = 'GID_REM_CQUERYT'
      Size = 10
    end
    object DocTIDBASE_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_CQUERYT'
    end
    object DocTIDCQ_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDCQ_REM_CQUERYT'
    end
    object DocTIDNOM_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_CQUERYT'
    end
    object DocTIDED_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDED_REM_CQUERYT'
    end
    object DocTIDSOST_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDSOST_REM_CQUERYT'
      OnChange = DocTIDSOST_REM_CQUERYTChange
    end
    object DocTNAMENOM_REM_CQUERYT: TFIBWideStringField
      FieldName = 'NAMENOM_REM_CQUERYT'
      Size = 200
    end
    object DocTKOL_REM_CQUERYT: TFIBBCDField
      FieldName = 'KOL_REM_CQUERYT'
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_CQUERYT: TFIBBCDField
      FieldName = 'KF_REM_CQUERYT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_CQUERYT: TFIBBCDField
      FieldName = 'PRICE_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_CQUERYT: TFIBBCDField
      FieldName = 'SUM_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICE_DO_REM_CQUERYT: TFIBBCDField
      FieldName = 'PRICE_DO_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICE_TEC_REM_CQUERYT: TFIBBCDField
      FieldName = 'PRICE_TEC_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICE_SOGL_REM_CQUERYT: TFIBBCDField
      FieldName = 'PRICE_SOGL_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object DocTSROK_POST_REM_CQUERYT: TFIBIntegerField
      FieldName = 'SROK_POST_REM_CQUERYT'
      OnChange = DocTSROK_POST_REM_CQUERYTChange
    end
    object DocTPOS_POST_REM_CQUERYT: TFIBDateTimeField
      FieldName = 'POS_POST_REM_CQUERYT'
      DisplayFormat = 'c'
    end
    object DocTRUN_REM_CQUERYT: TFIBSmallIntField
      FieldName = 'RUN_REM_CQUERYT'
      OnChange = DocTRUN_REM_CQUERYTChange
    end
    object DocTCOMMENTS_REM_CQUERYT: TFIBWideStringField
      FieldName = 'COMMENTS_REM_CQUERYT'
      Size = 250
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTNAME_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_SSOST_CQUERY'
      Size = 200
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTACT_REM_CQUERYT: TFIBSmallIntField
      FieldName = 'ACT_REM_CQUERYT'
      OnChange = DocTACT_REM_CQUERYTChange
    end
    object DocTIDPRNOM_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'IDPRNOM_REM_CQUERYT'
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
    object DocTART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
      Size = 40
    end
    object DocTCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object DocTNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
    object DocTART_REM_CQUERYT: TFIBWideStringField
      FieldName = 'ART_REM_CQUERYT'
      Size = 40
    end
    object DocTFL_ADD_IN_SOBORUD_SNOM: TFIBSmallIntField
      FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
    end
    object DocTSER_NUM_REM_CQUERYT: TFIBWideStringField
      FieldName = 'SER_NUM_REM_CQUERYT'
      Size = 50
    end
    object DocTUCH_SER_NUM_REM_CQUERYT: TFIBWideStringField
      FieldName = 'UCH_SER_NUM_REM_CQUERYT'
      Size = 50
    end
    object DocTREF_REM_CQUERYT: TFIBWideStringField
      FieldName = 'REF_REM_CQUERYT'
      Size = 255
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
      
        'select max(rem_cquery.num_rem_cquery) AS MAXNUMBER from  rem_cqu' +
        'ery'
      '')
    Transaction = IBTr
    Left = 368
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
end
