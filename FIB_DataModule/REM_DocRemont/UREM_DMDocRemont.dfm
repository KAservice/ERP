object REM_DMDocRemont: TREM_DMDocRemont
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
      ' sklient.nameklient,'
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
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
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
      ' sklient.nameklient,'
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
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
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
      'UPDATE REM_DREMONT'
      'SET '
      '    IDDOC_REM_DREMONT = :IDDOC_REM_DREMONT,'
      '    PRIM_REM_DREMONT = :PRIM_REM_DREMONT,'
      '    IDBASE_REM_DREMONT = :IDBASE_REM_DREMONT,'
      '    IDZ_REM_DREMONT = :IDZ_REM_DREMONT,'
      '    IDTPRICE_REM_DREMONT = :IDTPRICE_REM_DREMONT,'
      '    IDHW_REM_DREMONT = :IDHW_REM_DREMONT,'
      '    IDKKT_REM_DREMONT = :IDKKT_REM_DREMONT,'
      '    TYPE_REMONT_REM_DREMONT = :TYPE_REMONT_REM_DREMONT'
      'WHERE'
      '    ID_REM_DREMONT = :OLD_ID_REM_DREMONT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONT'
      'WHERE'
      '        ID_REM_DREMONT = :OLD_ID_REM_DREMONT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONT('
      '    ID_REM_DREMONT,'
      '    IDDOC_REM_DREMONT,'
      '    PRIM_REM_DREMONT,'
      '    IDBASE_REM_DREMONT,'
      '    IDZ_REM_DREMONT,'
      '    IDTPRICE_REM_DREMONT,'
      '    IDHW_REM_DREMONT,'
      '    IDKKT_REM_DREMONT,'
      '    TYPE_REMONT_REM_DREMONT'
      ')'
      'VALUES('
      '    :ID_REM_DREMONT,'
      '    :IDDOC_REM_DREMONT,'
      '    :PRIM_REM_DREMONT,'
      '    :IDBASE_REM_DREMONT,'
      '    :IDZ_REM_DREMONT,'
      '    :IDTPRICE_REM_DREMONT,'
      '    :IDHW_REM_DREMONT,'
      '    :IDKKT_REM_DREMONT,'
      '    :TYPE_REMONT_REM_DREMONT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremont.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_skkt.name_rem_skkt,'
      '        rem_skkt.sernum_rem_skkt'
      'from  rem_dremont'
      
        'left outer join rem_z on rem_dremont.idz_rem_dremont=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join rem_shardware on rem_dremont.idhw_rem_dremont=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_skkt on rem_dremont.idkkt_rem_dremont=rem_sk' +
        'kt.id_rem_skkt'
      'where(  rem_dremont.iddoc_rem_dremont=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONT.ID_REM_DREMONT = :OLD_ID_REM_DREMON' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremont.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_skkt.name_rem_skkt,'
      '        rem_skkt.sernum_rem_skkt'
      'from  rem_dremont'
      
        'left outer join rem_z on rem_dremont.idz_rem_dremont=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join rem_shardware on rem_dremont.idhw_rem_dremont=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_skkt on rem_dremont.idkkt_rem_dremont=rem_sk' +
        'kt.id_rem_skkt'
      'where rem_dremont.iddoc_rem_dremont=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DREMONT: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONT'
    end
    object DocIDDOC_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONT'
    end
    object DocPRIM_REM_DREMONT: TFIBWideStringField
      FieldName = 'PRIM_REM_DREMONT'
      Size = 100
    end
    object DocIDBASE_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONT'
    end
    object DocIDZ_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDZ_REM_DREMONT'
    end
    object DocIDTPRICE_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DREMONT'
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
    object DocSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocIDHW_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DREMONT'
    end
    object DocIDKKT_REM_DREMONT: TFIBLargeIntField
      FieldName = 'IDKKT_REM_DREMONT'
    end
    object DocTYPE_REMONT_REM_DREMONT: TFIBIntegerField
      FieldName = 'TYPE_REMONT_REM_DREMONT'
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
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
    object DocNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 200
    end
    object DocSERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'SERNUM_REM_SKKT'
      Size = 15
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DREMONTT'
      'SET '
      '    IDDOC_REM_DREMONTT = :IDDOC_REM_DREMONTT,'
      '    IDBASE_REM_DREMONTT = :IDBASE_REM_DREMONTT,'
      '    IDNOM_REM_DREMONTT = :IDNOM_REM_DREMONTT,'
      '    IDED_REM_DREMONTT = :IDED_REM_DREMONTT,'
      '    KOL_REM_DREMONTT = :KOL_REM_DREMONTT,'
      '    KF_REM_DREMONTT = :KF_REM_DREMONTT,'
      '    PRICE_REM_DREMONTT = :PRICE_REM_DREMONTT,'
      '    SUM_REM_DREMONTT = :SUM_REM_DREMONTT,'
      '    SUMMEX_REM_DREMONTT = :SUMMEX_REM_DREMONTT,'
      '    PRICEMEX_REM_DREMONTT = :PRICEMEX_REM_DREMONTT,'
      '    IDHW_REM_DREMONTT = :IDHW_REM_DREMONTT,'
      '    DVREG_REM_DREMONTT = :DVREG_REM_DREMONTT,'
      '    VD_REM_DREMONTT = :VD_REM_DREMONTT,'
      '    REP_PRODUCER_REM_DREMONTT = :REP_PRODUCER_REM_DREMONTT,'
      '    IDHWOLD_REM_DREMONTT = :IDHWOLD_REM_DREMONTT,'
      '    IDTNOM_REM_DREMONTT = :IDTNOM_REM_DREMONTT,'
      '    IDHW_DONOR_REM_DREMONTT = :IDHW_DONOR_REM_DREMONTT,'
      '    IDTYP_USEL_REM_DREMONTT = :IDTYP_USEL_REM_DREMONTT,'
      '    DESCR_REM_DREMONTT = :DESCR_REM_DREMONTT,'
      '    IDMHRAN_REM_DREMONTT = :IDMHRAN_REM_DREMONTT'
      'WHERE'
      '    ID_REM_DREMONTT = :OLD_ID_REM_DREMONTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONTT'
      'WHERE'
      '        ID_REM_DREMONTT = :OLD_ID_REM_DREMONTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONTT('
      '    ID_REM_DREMONTT,'
      '    IDDOC_REM_DREMONTT,'
      '    IDBASE_REM_DREMONTT,'
      '    IDNOM_REM_DREMONTT,'
      '    IDED_REM_DREMONTT,'
      '    KOL_REM_DREMONTT,'
      '    KF_REM_DREMONTT,'
      '    PRICE_REM_DREMONTT,'
      '    SUM_REM_DREMONTT,'
      '    SUMMEX_REM_DREMONTT,'
      '    PRICEMEX_REM_DREMONTT,'
      '    IDHW_REM_DREMONTT,'
      '    DVREG_REM_DREMONTT,'
      '    VD_REM_DREMONTT,'
      '    REP_PRODUCER_REM_DREMONTT,'
      '    IDHWOLD_REM_DREMONTT,'
      '    IDTNOM_REM_DREMONTT,'
      '    IDHW_DONOR_REM_DREMONTT,'
      '    IDTYP_USEL_REM_DREMONTT,'
      '    DESCR_REM_DREMONTT,'
      '    IDMHRAN_REM_DREMONTT'
      ')'
      'VALUES('
      '    :ID_REM_DREMONTT,'
      '    :IDDOC_REM_DREMONTT,'
      '    :IDBASE_REM_DREMONTT,'
      '    :IDNOM_REM_DREMONTT,'
      '    :IDED_REM_DREMONTT,'
      '    :KOL_REM_DREMONTT,'
      '    :KF_REM_DREMONTT,'
      '    :PRICE_REM_DREMONTT,'
      '    :SUM_REM_DREMONTT,'
      '    :SUMMEX_REM_DREMONTT,'
      '    :PRICEMEX_REM_DREMONTT,'
      '    :IDHW_REM_DREMONTT,'
      '    :DVREG_REM_DREMONTT,'
      '    :VD_REM_DREMONTT,'
      '    :REP_PRODUCER_REM_DREMONTT,'
      '    :IDHWOLD_REM_DREMONTT,'
      '    :IDTNOM_REM_DREMONTT,'
      '    :IDHW_DONOR_REM_DREMONTT,'
      '    :IDTYP_USEL_REM_DREMONTT,'
      '    :DESCR_REM_DREMONTT,'
      '    :IDMHRAN_REM_DREMONTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremontt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' old_rem_shardware.name_rem_shardware as old_name_rem_shardware,'
      ' old_rem_shardware.code_rem_shardware as old_code_rem_shardware,'
      
        ' old_rem_shardware.sernum_rem_shardware as old_sernum_rem_shardw' +
        'are,'
      ' donor.name_rem_shardware as donor_name_rem_shardware,'
      ' donor.code_rem_shardware as donor_code_rem_shardware,'
      ' donor.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' rem_stypuslov.name_rem_stypuslov,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran'
      'from  rem_dremontt'
      
        'left outer join snom on rem_dremontt.idnom_rem_dremontt=snom.idn' +
        'om'
      'left outer join sed on rem_dremontt.ided_rem_dremontt=sed.ided'
      
        'left outer join rem_shardware on rem_dremontt.idhw_rem_dremontt=' +
        'rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_rem_shardware  on rem_dremo' +
        'ntt.idhwold_rem_dremontt=old_rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as donor  on rem_dremontt.idhw_don' +
        'or_rem_dremontt=donor.id_rem_shardware'
      
        'left outer join rem_stypuslov on rem_dremontt.idtyp_usel_rem_dre' +
        'montt=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join stnom on rem_dremontt.idtnom_rem_dremontt=stnom.' +
        'id_stnom'
      
        'left outer join smhran on rem_dremontt.idmhran_rem_dremontt=smhr' +
        'an.id_smhran'
      'where(  rem_dremontt.iddoc_rem_dremontt=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONTT.ID_REM_DREMONTT = :OLD_ID_REM_DREM' +
        'ONTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremontt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' old_rem_shardware.name_rem_shardware as old_name_rem_shardware,'
      ' old_rem_shardware.code_rem_shardware as old_code_rem_shardware,'
      
        ' old_rem_shardware.sernum_rem_shardware as old_sernum_rem_shardw' +
        'are,'
      ' donor.name_rem_shardware as donor_name_rem_shardware,'
      ' donor.code_rem_shardware as donor_code_rem_shardware,'
      ' donor.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' rem_stypuslov.name_rem_stypuslov,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran'
      'from  rem_dremontt'
      
        'left outer join snom on rem_dremontt.idnom_rem_dremontt=snom.idn' +
        'om'
      'left outer join sed on rem_dremontt.ided_rem_dremontt=sed.ided'
      
        'left outer join rem_shardware on rem_dremontt.idhw_rem_dremontt=' +
        'rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_rem_shardware  on rem_dremo' +
        'ntt.idhwold_rem_dremontt=old_rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as donor  on rem_dremontt.idhw_don' +
        'or_rem_dremontt=donor.id_rem_shardware'
      
        'left outer join rem_stypuslov on rem_dremontt.idtyp_usel_rem_dre' +
        'montt=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join stnom on rem_dremontt.idtnom_rem_dremontt=stnom.' +
        'id_stnom'
      
        'left outer join smhran on rem_dremontt.idmhran_rem_dremontt=smhr' +
        'an.id_smhran'
      'where rem_dremontt.iddoc_rem_dremontt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONTT_ID'
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
    object DocTID_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONTT'
    end
    object DocTIDDOC_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONTT'
    end
    object DocTIDBASE_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONTT'
    end
    object DocTIDNOM_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DREMONTT'
    end
    object DocTIDED_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDED_REM_DREMONTT'
    end
    object DocTKOL_REM_DREMONTT: TFIBBCDField
      FieldName = 'KOL_REM_DREMONTT'
      OnChange = DocTKOL_REM_DREMONTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DREMONTT: TFIBBCDField
      FieldName = 'KF_REM_DREMONTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DREMONTT: TFIBBCDField
      FieldName = 'PRICE_REM_DREMONTT'
      OnChange = DocTPRICE_REM_DREMONTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DREMONTT: TFIBBCDField
      FieldName = 'SUM_REM_DREMONTT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMMEX_REM_DREMONTT: TFIBBCDField
      FieldName = 'SUMMEX_REM_DREMONTT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICEMEX_REM_DREMONTT: TFIBBCDField
      FieldName = 'PRICEMEX_REM_DREMONTT'
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
    object DocTIDHW_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DREMONTT'
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
    object DocTDVREG_REM_DREMONTT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DREMONTT'
    end
    object DocTVD_REM_DREMONTT: TFIBSmallIntField
      FieldName = 'VD_REM_DREMONTT'
    end
    object DocTREP_PRODUCER_REM_DREMONTT: TFIBSmallIntField
      FieldName = 'REP_PRODUCER_REM_DREMONTT'
    end
    object DocTIDHWOLD_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDHWOLD_REM_DREMONTT'
    end
    object DocTIDTNOM_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DREMONTT'
    end
    object DocTIDHW_DONOR_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDHW_DONOR_REM_DREMONTT'
    end
    object DocTIDTYP_USEL_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDTYP_USEL_REM_DREMONTT'
    end
    object DocTDESCR_REM_DREMONTT: TFIBWideStringField
      FieldName = 'DESCR_REM_DREMONTT'
      Size = 150
    end
    object DocTOLD_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTOLD_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'OLD_CODE_REM_SHARDWARE'
    end
    object DocTOLD_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTDONOR_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTDONOR_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'DONOR_CODE_REM_SHARDWARE'
    end
    object DocTDONOR_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_TYPE_NOM_LOOCUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NOM_LOOCUP'
      LookupDataSet = TypeNom
      LookupKeyFields = 'ID_STNOM'
      LookupResultField = 'NAME_STNOM'
      KeyFields = 'IDTNOM_REM_DREMONTT'
      Size = 30
      Lookup = True
    end
    object DocTIDMHRAN_REM_DREMONTT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DREMONTT'
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
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
      'where TDOC_REM_GALLDOC='#39'REMONT'#39' and POS_REM_GALLDOC > :PARAM_POS')
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
      
        'EXECUTE PROCEDURE REM_DOC_REMONT_CANCEL_DVREG(:PARAM_IDDOC,0,0,0' +
        ')')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_REMONT_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
  object TypeNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnom.id_stnom,'
      '       stnom.name_stnom'
      'from stnom'
      'order by stnom.name_stnom')
    Transaction = IBTr
    Left = 256
    Top = 136
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
